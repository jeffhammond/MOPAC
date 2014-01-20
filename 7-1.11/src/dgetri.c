/* dgetri.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__2 = 2;
static doublereal c_b20 = -1.;
static doublereal c_b22 = 1.;

/* Subroutine */ int dgetri_(integer *n, doublereal *a, integer *lda, integer 
	*ipiv, doublereal *work, integer *lwork, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, jb, nb, jj, jp, nn, iws;
    extern /* Subroutine */ int dgemm_(char *, char *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *, integer *, ftnlen, ftnlen),
	     dgemv_(char *, integer *, integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    integer *, ftnlen);
    static integer nbmin;
    extern /* Subroutine */ int dswap_(integer *, doublereal *, integer *, 
	    doublereal *, integer *), dtrsm_(char *, char *, char *, char *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, ftnlen, ftnlen, ftnlen, ftnlen), xerbla_(
	    char *, integer *, ftnlen);
    extern integer ilaenv_(integer *, char *, char *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
    static integer ldwork;
    extern /* Subroutine */ int dtrtri_(char *, char *, integer *, doublereal 
	    *, integer *, integer *, ftnlen, ftnlen);


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

/*  DGETRI COMPUTES THE INVERSE OF A MATRIX USING THE LU FACTORIZATION */
/*  COMPUTED BY DGETRF. */

/*  THIS METHOD INVERTS U AND THEN COMPUTES INV(A) BY SOLVING THE SYSTEM */
/*  INV(A)*L = INV(U) FOR INV(A). */

/*  ARGUMENTS */
/*  ========= */

/*  N       (INPUT) INTEGER */
/*          THE ORDER OF THE MATRIX A.  N >= 0. */

/*  A       (INPUT/OUTPUT) DOUBLE PRECISION ARRAY, DIMENSION (LDA,N) */
/*          ON ENTRY, THE FACTORS L AND U FROM THE FACTORIZATION */
/*          A = P*L*U AS COMPUTED BY DGETRF. */
/*          ON EXIT, IF INFO = 0, THE INVERSE OF THE ORIGINAL MATRIX A. */

/*  LDA     (INPUT) INTEGER */
/*          THE LEADING DIMENSION OF THE ARRAY A.  LDA >= MAX(1,N). */

/*  IPIV    (INPUT) INTEGER ARRAY, DIMENSION (N) */
/*          THE PIVOT INDICES FROM DGETRF; FOR 1<=I<=N, ROW I OF THE */
/*          MATRIX WAS INTERCHANGED WITH ROW IPIV(I). */

/*  WORK    (WORKSPACE) DOUBLE PRECISION ARRAY, DIMENSION (LWORK) */
/*          IF INFO RETURNS 0, THEN WORK(1) RETURNS N*NB, THE MINIMUM */
/*          VALUE OF LWORK REQUIRED TO USE THE OPTIMAL BLOCKSIZE. */

/*  LWORK   (INPUT) INTEGER */
/*          THE DIMENSION OF THE ARRAY WORK.  LWORK >= MAX(1,N). */
/*          FOR OPTIMAL PERFORMANCE LWORK SHOULD BE AT LEAST N*NB, */
/*          WHERE NB IS THE OPTIMAL BLOCKSIZE RETURNED BY ILAENV. */

/*  INFO    (OUTPUT) INTEGER */
/*          = 0:  SUCCESSFUL EXIT */
/*          < 0: IF INFO = -K, THE K-TH ARGUMENT HAD AN ILLEGAL VALUE */
/*          > 0: IF INFO = K, U(K,K) IS EXACTLY ZERO; THE MATRIX IS */
/*               SINGULAR AND ITS INVERSE COULD NOT BE COMPUTED. */

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
    --work;

    /* Function Body */
    *info = 0;
    work[1] = (doublereal) max(*n,1);
    if (*n < 0) {
	*info = -1;
    } else if (*lda < max(1,*n)) {
	*info = -3;
    } else if (*lwork < max(1,*n)) {
	*info = -6;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("DGETRI", &i__1, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE */

    if (*n == 0) {
	return 0;
    }

/*     FORM INV(U).  IF INFO > 0 FROM DTRTRI, THEN U IS SINGULAR, */
/*     AND THE INVERSE IS NOT COMPUTED. */

    dtrtri_("UPPER", "NON-UNIT", n, &a[a_offset], lda, info, (ftnlen)5, (
	    ftnlen)8);
    if (*info > 0) {
	return 0;
    }

/*     DETERMINE THE BLOCK SIZE FOR THIS ENVIRONMENT. */

    nb = ilaenv_(&c__1, "DGETRI", " ", n, &c_n1, &c_n1, &c_n1, (ftnlen)6, (
	    ftnlen)1);
    nbmin = 2;
    ldwork = *n;
    if (nb > 1 && nb < *n) {
/* Computing MAX */
	i__1 = ldwork * nb;
	iws = max(i__1,1);
	if (*lwork < iws) {
	    nb = *lwork / ldwork;
/* Computing MAX */
	    i__1 = 2, i__2 = ilaenv_(&c__2, "DGETRI", " ", n, &c_n1, &c_n1, &
		    c_n1, (ftnlen)6, (ftnlen)1);
	    nbmin = max(i__1,i__2);
	}
    } else {
	iws = *n;
    }

/*     SOLVE THE EQUATION INV(A)*L = INV(U) FOR INV(A). */

    if (nb < nbmin || nb >= *n) {

/*        USE UNBLOCKED CODE. */

	for (j = *n; j >= 1; --j) {

/*           COPY CURRENT COLUMN OF L TO WORK AND REPLACE WITH ZEROS. */

	    i__1 = *n;
	    for (i__ = j + 1; i__ <= i__1; ++i__) {
		work[i__] = a[i__ + j * a_dim1];
		a[i__ + j * a_dim1] = 0.;
/* L10: */
	    }

/*           COMPUTE CURRENT COLUMN OF INV(A). */

	    if (j < *n) {
		i__1 = *n - j;
		dgemv_("NO TRANSPOSE", n, &i__1, &c_b20, &a[(j + 1) * a_dim1 
			+ 1], lda, &work[j + 1], &c__1, &c_b22, &a[j * a_dim1 
			+ 1], &c__1, (ftnlen)12);
	    }
/* L20: */
	}
    } else {

/*        USE BLOCKED CODE. */

	nn = (*n - 1) / nb * nb + 1;
	i__1 = -nb;
	for (j = nn; i__1 < 0 ? j >= 1 : j <= 1; j += i__1) {
/* Computing MIN */
	    i__2 = nb, i__3 = *n - j + 1;
	    jb = min(i__2,i__3);

/*           COPY CURRENT BLOCK COLUMN OF L TO WORK AND REPLACE WITH */
/*           ZEROS. */

	    i__2 = j + jb - 1;
	    for (jj = j; jj <= i__2; ++jj) {
		i__3 = *n;
		for (i__ = jj + 1; i__ <= i__3; ++i__) {
		    work[i__ + (jj - j) * ldwork] = a[i__ + jj * a_dim1];
		    a[i__ + jj * a_dim1] = 0.;
/* L30: */
		}
/* L40: */
	    }

/*           COMPUTE CURRENT BLOCK COLUMN OF INV(A). */

	    if (j + jb <= *n) {
		i__2 = *n - j - jb + 1;
		dgemm_("NO TRANSPOSE", "NO TRANSPOSE", n, &jb, &i__2, &c_b20, 
			&a[(j + jb) * a_dim1 + 1], lda, &work[j + jb], &
			ldwork, &c_b22, &a[j * a_dim1 + 1], lda, (ftnlen)12, (
			ftnlen)12);
	    }
	    dtrsm_("RIGHT", "LOWER", "NO TRANSPOSE", "UNIT", n, &jb, &c_b22, &
		    work[j], &ldwork, &a[j * a_dim1 + 1], lda, (ftnlen)5, (
		    ftnlen)5, (ftnlen)12, (ftnlen)4);
/* L50: */
	}
    }

/*     APPLY COLUMN INTERCHANGES. */

    for (j = *n - 1; j >= 1; --j) {
	jp = ipiv[j];
	if (jp != j) {
	    dswap_(n, &a[j * a_dim1 + 1], &c__1, &a[jp * a_dim1 + 1], &c__1);
	}
/* L60: */
    }

    work[1] = (doublereal) iws;
    return 0;

/*     END OF DGETRI */

} /* dgetri_ */

