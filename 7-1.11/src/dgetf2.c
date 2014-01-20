/* dgetf2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b6 = -1.;

/* Subroutine */ int dgetf2_(integer *m, integer *n, doublereal *a, integer *
	lda, integer *ipiv, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;
    doublereal d__1;

    /* Local variables */
    static integer j, jp;
    extern /* Subroutine */ int dger_(integer *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, integer *, doublereal *, 
	    integer *), dscal_(integer *, doublereal *, doublereal *, integer 
	    *), dswap_(integer *, doublereal *, integer *, doublereal *, 
	    integer *);
    extern integer idamax_(integer *, doublereal *, integer *);
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen);


/*  -- LAPACK ROUTINE (VERSION 1.0B) -- */
/*     UNIV. OF TENNESSEE, UNIV. OF CALIFORNIA BERKELEY, NAG LTD., */
/*     COURANT INSTITUTE, ARGONNE NATIONAL LAB, AND RICE UNIVERSITY */
/*     JUNE 30, 1992 */

/*     .. SCALAR ARGUMENTS .. */
/*     .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DGETF2 COMPUTES AN LU FACTORIZATION OF A GENERAL M-BY-N MATRIX A */
/*  USING PARTIAL PIVOTING WITH ROW INTERCHANGES. */

/*  THE FACTORIZATION HAS THE FORM */
/*     A = P * L * U */
/*  WHERE P IS A PERMUTATION MATRIX, L IS LOWER TRIANGULAR WITH UNIT */
/*  DIAGONAL ELEMENTS (LOWER TRAPEZOIDAL IF M > N), AND U IS UPPER */
/*  TRIANGULAR (UPPER TRAPEZOIDAL IF M < N). */

/*  THIS IS THE RIGHT-LOOKING LEVEL 2 BLAS VERSION OF THE ALGORITHM. */

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
/*     .. EXTERNAL FUNCTIONS .. */
/*     .. */
/*     .. EXTERNAL SUBROUTINES .. */
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
	xerbla_("DGETF2", &i__1, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE */

    if (*m == 0 || *n == 0) {
	return 0;
    }

    i__1 = min(*m,*n);
    for (j = 1; j <= i__1; ++j) {

/*        FIND PIVOT AND TEST FOR SINGULARITY. */

	i__2 = *m - j + 1;
	jp = j - 1 + idamax_(&i__2, &a[j + j * a_dim1], &c__1);
	ipiv[j] = jp;
	if (a[jp + j * a_dim1] != 0.) {

/*           APPLY THE INTERCHANGE TO COLUMNS 1:N. */

	    if (jp != j) {
		dswap_(n, &a[j + a_dim1], lda, &a[jp + a_dim1], lda);
	    }

/*           COMPUTE ELEMENTS J+1:M OF J-TH COLUMN. */

	    if (j < *m) {
		i__2 = *m - j;
		d__1 = 1. / a[j + j * a_dim1];
		dscal_(&i__2, &d__1, &a[j + 1 + j * a_dim1], &c__1);
	    }

	} else if (*info == 0) {

	    *info = j;
	}

	if (j < min(*m,*n)) {

/*           UPDATE TRAILING SUBMATRIX. */

	    i__2 = *m - j;
	    i__3 = *n - j;
	    dger_(&i__2, &i__3, &c_b6, &a[j + 1 + j * a_dim1], &c__1, &a[j + (
		    j + 1) * a_dim1], lda, &a[j + 1 + (j + 1) * a_dim1], lda);
	}
/* L10: */
    }
    return 0;

/*     END OF DGETF2 */

} /* dgetf2_ */

