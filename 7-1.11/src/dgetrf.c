/* dgetrf.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c_n1 = -1;
static doublereal c_b16 = 1.;
static doublereal c_b19 = -1.;

/* Subroutine */ int dgetrf_(integer *m, integer *n, doublereal *a, integer *
	lda, integer *ipiv, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4, i__5;

    /* Local variables */
    static integer i__, j, jb, nb;
    extern /* Subroutine */ int dgemm_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, ftnlen, ftnlen);
    static integer iinfo;
    extern /* Subroutine */ int dtrsm_(char *, char *, char *, char *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, ftnlen, ftnlen, ftnlen, ftnlen), dgetf2_(
	    integer *, integer *, doublereal *, integer *, integer *, integer 
	    *), xerbla_(char *, integer *, ftnlen);
    extern integer ilaenv_(integer *, char *, char *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    extern /* Subroutine */ int dlaswp_(integer *, doublereal *, integer *, 
	    integer *, integer *, integer *, integer *);


/*  -- LAPACK ROUTINE (VERSION 1.0B) -- */
/*     UNIV. OF TENNESSEE, UNIV. OF CALIFORNIA BERKELEY, NAG LTD., */
/*     COURANT INSTITUTE, ARGONNE NATIONAL LAB, AND RICE UNIVERSITY */
/*     FEBRUARY 29, 1992 */

/*     .. SCALAR ARGUMENTS .. */
/*     .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DGETRF COMPUTES AN LU FACTORIZATION OF A GENERAL M-BY-N MATRIX A */
/*  USING PARTIAL PIVOTING WITH ROW INTERCHANGES. */

/*  THE FACTORIZATION HAS THE FORM */
/*     A = P * L * U */
/*  WHERE P IS A PERMUTATION MATRIX, L IS LOWER TRIANGULAR WITH UNIT */
/*  DIAGONAL ELEMENTS (LOWER TRAPEZOIDAL IF M > N), AND U IS UPPER */
/*  TRIANGULAR (UPPER TRAPEZOIDAL IF M < N). */

/*  THIS IS THE RIGHT-LOOKING LEVEL 3 BLAS VERSION OF THE ALGORITHM. */

/*  ARGUMENTS */
/*  ========= */

/*  M       (INPUT) INTEGER */
/*          THE NUMBER OF ROWS OF THE MATRIX A.  M >= 0. */

/*  N       (INPUT) INTEGER */
/*          THE NUMBER OF COLUMNS OF THE MATRIX A.  N >= 0. */

/*  A       (INPUT/OUTPUT) DOUBLE PRECISION ARRAY, DIMENSION (LDA,N) */
/*          ON ENTRY, THE M BY N MATRIX TO BE FACTORED. */
/*          ON EXIT, THE FACTORS L AND U FROM THE FACTORIZATION */
/*          A = P*L*U; THE UNIT DIAGONAL ELEMENTS OF L ARE NOT STORED. */

/*  LDA     (INPUT) INTEGER */
/*          THE LEADING DIMENSION OF THE ARRAY A.  LDA >= MAX(1,M). */

/*  IPIV    (OUTPUT) INTEGER ARRAY, DIMENSION (MIN(M,N)) */
/*          THE PIVOT INDICES; FOR 1 <= I <= MIN(M,N), ROW I OF THE */
/*          MATRIX WAS INTERCHANGED WITH ROW IPIV(I). */

/*  INFO    (OUTPUT) INTEGER */
/*          = 0: SUCCESSFUL EXIT */
/*          < 0: IF INFO = -K, THE K-TH ARGUMENT HAD AN ILLEGAL VALUE */
/*          > 0: IF INFO = K, U(K,K) IS EXACTLY ZERO. THE FACTORIZATION */
/*               HAS BEEN COMPLETED, BUT THE FACTOR U IS EXACTLY */
/*               SINGULAR, AND DIVISION BY ZERO WILL OCCUR IF IT IS USED */
/*               TO SOLVE A SYSTEM OF EQUATIONS. */

/*  ===================================================================== */

/*     .. PARAMETERS .. */
/*     .. */
/*     .. LOCAL SCALARS .. */
/*     .. */
/*     .. EXTERNAL SUBROUTINES .. */
/*     .. */
/*     .. EXTERNAL FUNCTIONS .. */
/*     .. */
/*     .. INTRINSIC FUNCTIONS .. */
/*     .. */
/*     .. EXECUTABLE STATEMENTS .. */

/*     TEST THE INPUT PARAMETERS. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --ipiv;

    /* Function Body */
    *info = 0;
    if (*m < 0) {
	*info = -1;
    } else if (*n < 0) {
	*info = -2;
    } else if (*lda < max(1,*m)) {
	*info = -4;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("DGETRF", &i__1, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE */

    if (*m == 0 || *n == 0) {
	return 0;
    }

/*     DETERMINE THE BLOCK SIZE FOR THIS ENVIRONMENT. */

    nb = ilaenv_(&c__1, "DGETRF", " ", m, n, &c_n1, &c_n1, (ftnlen)6, (ftnlen)
	    1);
    if (nb <= 1 || nb >= min(*m,*n)) {

/*        USE UNBLOCKED CODE. */

	dgetf2_(m, n, &a[a_offset], lda, &ipiv[1], info);
    } else {

/*        USE BLOCKED CODE. */

	i__1 = min(*m,*n);
	i__2 = nb;
	for (j = 1; i__2 < 0 ? j >= i__1 : j <= i__1; j += i__2) {
/* Computing MIN */
	    i__3 = min(*m,*n) - j + 1;
	    jb = min(i__3,nb);

/*           FACTOR DIAGONAL AND SUBDIAGONAL BLOCKS AND TEST FOR EXACT */
/*           SINGULARITY. */

	    i__3 = *m - j + 1;
	    dgetf2_(&i__3, &jb, &a[j + j * a_dim1], lda, &ipiv[j], &iinfo);

/*           ADJUST INFO AND THE PIVOT INDICES. */

	    if (*info == 0 && iinfo > 0) {
		*info = iinfo + j - 1;
	    }
/* Computing MIN */
	    i__4 = *m, i__5 = j + jb - 1;
	    i__3 = min(i__4,i__5);
	    for (i__ = j; i__ <= i__3; ++i__) {
		ipiv[i__] = j - 1 + ipiv[i__];
/* L10: */
	    }

/*           APPLY INTERCHANGES TO COLUMNS 1:J-1. */

	    i__3 = j - 1;
	    i__4 = j + jb - 1;
	    dlaswp_(&i__3, &a[a_offset], lda, &j, &i__4, &ipiv[1], &c__1);

	    if (j + jb <= *n) {

/*              APPLY INTERCHANGES TO COLUMNS J+JB:N. */

		i__3 = *n - j - jb + 1;
		i__4 = j + jb - 1;
		dlaswp_(&i__3, &a[(j + jb) * a_dim1 + 1], lda, &j, &i__4, &
			ipiv[1], &c__1);

/*              COMPUTE BLOCK ROW OF U. */

		i__3 = *n - j - jb + 1;
		dtrsm_("LEFT", "LOWER", "NO TRANSPOSE", "UNIT", &jb, &i__3, &
			c_b16, &a[j + j * a_dim1], lda, &a[j + (j + jb) * 
			a_dim1], lda, (ftnlen)4, (ftnlen)5, (ftnlen)12, (
			ftnlen)4);
		if (j + jb <= *m) {

/*                 UPDATE TRAILING SUBMATRIX. */

		    i__3 = *m - j - jb + 1;
		    i__4 = *n - j - jb + 1;
		    dgemm_("NO TRANSPOSE", "NO TRANSPOSE", &i__3, &i__4, &jb, 
			    &c_b19, &a[j + jb + j * a_dim1], lda, &a[j + (j + 
			    jb) * a_dim1], lda, &c_b16, &a[j + jb + (j + jb) *
			     a_dim1], lda, (ftnlen)12, (ftnlen)12);
		}
	    }
/* L20: */
	}
    }
    return 0;

/*     END OF DGETRF */

} /* dgetrf_ */

