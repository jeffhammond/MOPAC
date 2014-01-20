/* dtrtri.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static integer c_n1 = -1;
static integer c__2 = 2;
static doublereal c_b18 = 1.;
static doublereal c_b22 = -1.;

/* Subroutine */ int dtrtri_(char *uplo, char *diag, integer *n, doublereal *
	a, integer *lda, integer *info, ftnlen uplo_len, ftnlen diag_len)
{
    /* System generated locals */
    address a__1[2];
    integer a_dim1, a_offset, i__1, i__2[2], i__3, i__4, i__5;
    char ch__1[2];

    /* Builtin functions */
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer j, jb, nb, nn;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int dtrmm_(char *, char *, char *, char *, 
	    integer *, integer *, doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, ftnlen, ftnlen, ftnlen, ftnlen), dtrsm_(
	    char *, char *, char *, char *, integer *, integer *, doublereal *
	    , doublereal *, integer *, doublereal *, integer *, ftnlen, 
	    ftnlen, ftnlen, ftnlen);
    static logical upper;
    extern /* Subroutine */ int dtrti2_(char *, char *, integer *, doublereal 
	    *, integer *, integer *, ftnlen, ftnlen), xerbla_(char *, integer 
	    *, ftnlen);
    extern integer ilaenv_(integer *, char *, char *, integer *, integer *, 
	    integer *, integer *, ftnlen, ftnlen);
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

/*  DTRTRI COMPUTES THE INVERSE OF A REAL UPPER OR LOWER TRIANGULAR */
/*  MATRIX A. */

/*  THIS IS THE LEVEL 3 BLAS VERSION OF THE ALGORITHM. */

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
/*          > 0: IF INFO = K, A(K,K) IS EXACTLY ZERO.  THE TRIANGULAR */
/*               MATRIX IS SINGULAR AND ITS INVERSE CAN NOT BE COMPUTED. */
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
	xerbla_("DTRTRI", &i__1, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE */

    if (*n == 0) {
	return 0;
    }

/*     CHECK FOR SINGULARITY IF NON-UNIT. */

    if (nounit) {
	i__1 = *n;
	for (*info = 1; *info <= i__1; ++(*info)) {
	    if (a[*info + *info * a_dim1] == 0.) {
		return 0;
	    }
/* L10: */
	}
	*info = 0;
    }

/*     DETERMINE THE BLOCK SIZE FOR THIS ENVIRONMENT. */

/* Writing concatenation */
    i__2[0] = 1, a__1[0] = uplo;
    i__2[1] = 1, a__1[1] = diag;
    s_cat(ch__1, a__1, i__2, &c__2, (ftnlen)2);
    nb = ilaenv_(&c__1, "DTRTRI", ch__1, n, &c_n1, &c_n1, &c_n1, (ftnlen)6, (
	    ftnlen)2);
    if (nb <= 1 || nb >= *n) {

/*        USE UNBLOCKED CODE */

	dtrti2_(uplo, diag, n, &a[a_offset], lda, info, (ftnlen)1, (ftnlen)1);
    } else {

/*        USE BLOCKED CODE */

	if (upper) {

/*           COMPUTE INVERSE OF UPPER TRIANGULAR MATRIX */

	    i__1 = *n;
	    i__3 = nb;
	    for (j = 1; i__3 < 0 ? j >= i__1 : j <= i__1; j += i__3) {
/* Computing MIN */
		i__4 = nb, i__5 = *n - j + 1;
		jb = min(i__4,i__5);

/*              COMPUTE ROWS 1:J-1 OF CURRENT BLOCK COLUMN */

		i__4 = j - 1;
		dtrmm_("LEFT", "UPPER", "NO TRANSPOSE", diag, &i__4, &jb, &
			c_b18, &a[a_offset], lda, &a[j * a_dim1 + 1], lda, (
			ftnlen)4, (ftnlen)5, (ftnlen)12, (ftnlen)1);
		i__4 = j - 1;
		dtrsm_("RIGHT", "UPPER", "NO TRANSPOSE", diag, &i__4, &jb, &
			c_b22, &a[j + j * a_dim1], lda, &a[j * a_dim1 + 1], 
			lda, (ftnlen)5, (ftnlen)5, (ftnlen)12, (ftnlen)1);

/*              COMPUTE INVERSE OF CURRENT DIAGONAL BLOCK */

		dtrti2_("UPPER", diag, &jb, &a[j + j * a_dim1], lda, info, (
			ftnlen)5, (ftnlen)1);
/* L20: */
	    }
	} else {

/*           COMPUTE INVERSE OF LOWER TRIANGULAR MATRIX */

	    nn = (*n - 1) / nb * nb + 1;
	    i__3 = -nb;
	    for (j = nn; i__3 < 0 ? j >= 1 : j <= 1; j += i__3) {
/* Computing MIN */
		i__1 = nb, i__4 = *n - j + 1;
		jb = min(i__1,i__4);
		if (j + jb <= *n) {

/*                 COMPUTE ROWS J+JB:N OF CURRENT BLOCK COLUMN */

		    i__1 = *n - j - jb + 1;
		    dtrmm_("LEFT", "LOWER", "NO TRANSPOSE", diag, &i__1, &jb, 
			    &c_b18, &a[j + jb + (j + jb) * a_dim1], lda, &a[j 
			    + jb + j * a_dim1], lda, (ftnlen)4, (ftnlen)5, (
			    ftnlen)12, (ftnlen)1);
		    i__1 = *n - j - jb + 1;
		    dtrsm_("RIGHT", "LOWER", "NO TRANSPOSE", diag, &i__1, &jb,
			     &c_b22, &a[j + j * a_dim1], lda, &a[j + jb + j * 
			    a_dim1], lda, (ftnlen)5, (ftnlen)5, (ftnlen)12, (
			    ftnlen)1);
		}

/*              COMPUTE INVERSE OF CURRENT DIAGONAL BLOCK */

		dtrti2_("LOWER", diag, &jb, &a[j + j * a_dim1], lda, info, (
			ftnlen)5, (ftnlen)1);
/* L30: */
	    }
	}
    }

    return 0;

/*     END OF DTRTRI */

} /* dtrtri_ */

