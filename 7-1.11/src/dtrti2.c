/* dtrti2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int dtrti2_(char *uplo, char *diag, integer *n, doublereal *
	a, integer *lda, integer *info, ftnlen uplo_len, ftnlen diag_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer j;
    static doublereal ajj;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *);
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static logical upper;
    extern /* Subroutine */ int dtrmv_(char *, char *, char *, integer *, 
	    doublereal *, integer *, doublereal *, integer *, ftnlen, ftnlen, 
	    ftnlen), xerbla_(char *, integer *, ftnlen);
    static logical nounit;


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

/*  DTRTI2 COMPUTES THE INVERSE OF A REAL UPPER OR LOWER TRIANGULAR */
/*  MATRIX. */

/*  THIS IS THE LEVEL 2 BLAS VERSION OF THE ALGORITHM. */

/*  ARGUMENTS */
/*  ========= */

/*  UPLO    (INPUT) CHARACTER*1 */
/*          SPECIFIES WHETHER THE MATRIX A IS UPPER OR LOWER TRIANGULAR. */
/*          = 'U':  UPPER TRIANGULAR */
/*          = 'L':  LOWER TRIANGULAR */

/*  DIAG    (INPUT) CHARACTER*1 */
/*          SPECIFIES WHETHER OR NOT THE MATRIX A IS UNIT TRIANGULAR. */
/*          = 'N':  NON-UNIT TRIANGULAR */
/*          = 'U':  UNIT TRIANGULAR */

/*  N       (INPUT) INTEGER */
/*          THE ORDER OF THE MATRIX A.  N >= 0. */

/*  A       (INPUT/OUTPUT) DOUBLE PRECISION ARRAY, DIMENSION (LDA,N) */
/*          ON ENTRY, THE TRIANGULAR MATRIX A.  IF UPLO = 'U', THE */
/*          LEADING N BY N UPPER TRIANGULAR PART OF THE ARRAY A CONTAINS */
/*          THE UPPER TRIANGULAR MATRIX, AND THE STRICTLY LOWER */
/*          TRIANGULAR PART OF A IS NOT REFERENCED.  IF UPLO = 'L', THE */
/*          LEADING N BY N LOWER TRIANGULAR PART OF THE ARRAY A CONTAINS */
/*          THE LOWER TRIANGULAR MATRIX, AND THE STRICTLY UPPER */
/*          TRIANGULAR PART OF A IS NOT REFERENCED.  IF DIAG = 'U', THE */
/*          DIAGONAL ELEMENTS OF A ARE ALSO NOT REFERENCED AND ARE */
/*          ASSUMED TO BE 1. */

/*          ON EXIT, THE (TRIANGULAR) INVERSE OF THE ORIGINAL MATRIX, IN */
/*          THE SAME STORAGE FORMAT. */

/*  LDA     (INPUT) INTEGER */
/*          THE LEADING DIMENSION OF THE ARRAY A.  LDA >= MAX(1,N). */

/*  INFO    (OUTPUT) INTEGER */
/*          = 0: SUCCESSFUL EXIT */
/*          < 0: IF INFO = -K, THE K-TH ARGUMENT HAD AN ILLEGAL VALUE */

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

    /* Function Body */
    *info = 0;
    upper = lsame_(uplo, "U", (ftnlen)1, (ftnlen)1);
    nounit = lsame_(diag, "N", (ftnlen)1, (ftnlen)1);
    if (! upper && ! lsame_(uplo, "L", (ftnlen)1, (ftnlen)1)) {
	*info = -1;
    } else if (! nounit && ! lsame_(diag, "U", (ftnlen)1, (ftnlen)1)) {
	*info = -2;
    } else if (*n < 0) {
	*info = -3;
    } else if (*lda < max(1,*n)) {
	*info = -5;
    }
    if (*info != 0) {
	i__1 = -(*info);
	xerbla_("DTRTI2", &i__1, (ftnlen)6);
	return 0;
    }

    if (upper) {

/*        COMPUTE INVERSE OF UPPER TRIANGULAR MATRIX. */

	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    if (nounit) {
		a[j + j * a_dim1] = 1. / a[j + j * a_dim1];
		ajj = -a[j + j * a_dim1];
	    } else {
		ajj = -1.;
	    }

/*           COMPUTE ELEMENTS 1:J-1 OF J-TH COLUMN. */

	    i__2 = j - 1;
	    dtrmv_("UPPER", "NO TRANSPOSE", diag, &i__2, &a[a_offset], lda, &
		    a[j * a_dim1 + 1], &c__1, (ftnlen)5, (ftnlen)12, (ftnlen)
		    1);
	    i__2 = j - 1;
	    dscal_(&i__2, &ajj, &a[j * a_dim1 + 1], &c__1);
/* L10: */
	}
    } else {

/*        COMPUTE INVERSE OF LOWER TRIANGULAR MATRIX. */

	for (j = *n; j >= 1; --j) {
	    if (nounit) {
		a[j + j * a_dim1] = 1. / a[j + j * a_dim1];
		ajj = -a[j + j * a_dim1];
	    } else {
		ajj = -1.;
	    }
	    if (j < *n) {

/*              COMPUTE ELEMENTS J+1:N OF J-TH COLUMN. */

		i__1 = *n - j;
		dtrmv_("LOWER", "NO TRANSPOSE", diag, &i__1, &a[j + 1 + (j + 
			1) * a_dim1], lda, &a[j + 1 + j * a_dim1], &c__1, (
			ftnlen)5, (ftnlen)12, (ftnlen)1);
		i__1 = *n - j;
		dscal_(&i__1, &ajj, &a[j + 1 + j * a_dim1], &c__1);
	    }
/* L20: */
	}
    }

    return 0;

/*     END OF DTRTI2 */

} /* dtrti2_ */

