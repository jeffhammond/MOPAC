/* dtrmv.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dtrmv_(char *uplo, char *trans, char *diag, integer *n, 
	doublereal *a, integer *lda, doublereal *x, integer *incx, ftnlen 
	uplo_len, ftnlen trans_len, ftnlen diag_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, ix, jx, kx, info;
    static doublereal temp;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen);
    static logical nounit;

/*     .. SCALAR ARGUMENTS .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DTRMV  PERFORMS ONE OF THE MATRIX-VECTOR OPERATIONS */

/*     X := A*X,   OR   X := A'*X, */

/*  WHERE X IS AN N ELEMENT VECTOR AND  A IS AN N BY N UNIT, OR NON-UNIT, */
/*  UPPER OR LOWER TRIANGULAR MATRIX. */

/*  PARAMETERS */
/*  ========== */

/*  UPLO   - CHARACTER*1. */
/*           ON ENTRY, UPLO SPECIFIES WHETHER THE MATRIX IS AN UPPER OR */
/*           LOWER TRIANGULAR MATRIX AS FOLLOWS: */

/*              UPLO = 'U' OR 'U'   A IS AN UPPER TRIANGULAR MATRIX. */

/*              UPLO = 'L' OR 'L'   A IS A LOWER TRIANGULAR MATRIX. */

/*           UNCHANGED ON EXIT. */

/*  TRANS  - CHARACTER*1. */
/*           ON ENTRY, TRANS SPECIFIES THE OPERATION TO BE PERFORMED AS */
/*           FOLLOWS: */

/*              TRANS = 'N' OR 'N'   X := A*X. */

/*              TRANS = 'T' OR 'T'   X := A'*X. */

/*              TRANS = 'C' OR 'C'   X := A'*X. */

/*           UNCHANGED ON EXIT. */

/*  DIAG   - CHARACTER*1. */
/*           ON ENTRY, DIAG SPECIFIES WHETHER OR NOT A IS UNIT */
/*           TRIANGULAR AS FOLLOWS: */

/*              DIAG = 'U' OR 'U'   A IS ASSUMED TO BE UNIT TRIANGULAR. */

/*              DIAG = 'N' OR 'N'   A IS NOT ASSUMED TO BE UNIT */
/*                                  TRIANGULAR. */

/*           UNCHANGED ON EXIT. */

/*  N      - INTEGER. */
/*           ON ENTRY, N SPECIFIES THE ORDER OF THE MATRIX A. */
/*           N MUST BE AT LEAST ZERO. */
/*           UNCHANGED ON EXIT. */

/*  A      - DOUBLE PRECISION ARRAY OF DIMENSION ( LDA, N ). */
/*           BEFORE ENTRY WITH  UPLO = 'U' OR 'U', THE LEADING N BY N */
/*           UPPER TRIANGULAR PART OF THE ARRAY A MUST CONTAIN THE UPPER */
/*           TRIANGULAR MATRIX AND THE STRICTLY LOWER TRIANGULAR PART OF */
/*           A IS NOT REFERENCED. */
/*           BEFORE ENTRY WITH UPLO = 'L' OR 'L', THE LEADING N BY N */
/*           LOWER TRIANGULAR PART OF THE ARRAY A MUST CONTAIN THE LOWER */
/*           TRIANGULAR MATRIX AND THE STRICTLY UPPER TRIANGULAR PART OF */
/*           A IS NOT REFERENCED. */
/*           NOTE THAT WHEN  DIAG = 'U' OR 'U', THE DIAGONAL ELEMENTS OF */
/*           A ARE NOT REFERENCED EITHER, BUT ARE ASSUMED TO BE UNITY. */
/*           UNCHANGED ON EXIT. */

/*  LDA    - INTEGER. */
/*           ON ENTRY, LDA SPECIFIES THE FIRST DIMENSION OF A AS DECLARED */
/*           IN THE CALLING (SUB) PROGRAM. LDA MUST BE AT LEAST */
/*           MAX( 1, N ). */
/*           UNCHANGED ON EXIT. */

/*  X      - DOUBLE PRECISION ARRAY OF DIMENSION AT LEAST */
/*           ( 1 + ( N - 1 )*ABS( INCX ) ). */
/*           BEFORE ENTRY, THE INCREMENTED ARRAY X MUST CONTAIN THE N */
/*           ELEMENT VECTOR X. ON EXIT, X IS OVERWRITTEN WITH THE */
/*           TRANFORMED VECTOR X. */

/*  INCX   - INTEGER. */
/*           ON ENTRY, INCX SPECIFIES THE INCREMENT FOR THE ELEMENTS OF */
/*           X. INCX MUST NOT BE ZERO. */
/*           UNCHANGED ON EXIT. */


/*  LEVEL 2 BLAS ROUTINE. */

/*  -- WRITTEN ON 22-OCTOBER-1986. */
/*     JACK DONGARRA, ARGONNE NATIONAL LAB. */
/*     JEREMY DU CROZ, NAG CENTRAL OFFICE. */
/*     SVEN HAMMARLING, NAG CENTRAL OFFICE. */
/*     RICHARD HANSON, SANDIA NATIONAL LABS. */


/*     .. PARAMETERS .. */
/*     .. LOCAL SCALARS .. */
/*     .. EXTERNAL FUNCTIONS .. */
/*     .. EXTERNAL SUBROUTINES .. */
/*     .. INTRINSIC FUNCTIONS .. */
/*     .. */
/*     .. EXECUTABLE STATEMENTS .. */

/*     TEST THE INPUT PARAMETERS. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --x;

    /* Function Body */
    info = 0;
    if (! lsame_(uplo, "U", (ftnlen)1, (ftnlen)1) && ! lsame_(uplo, "L", (
	    ftnlen)1, (ftnlen)1)) {
	info = 1;
    } else if (! lsame_(trans, "N", (ftnlen)1, (ftnlen)1) && ! lsame_(trans, 
	    "T", (ftnlen)1, (ftnlen)1) && ! lsame_(trans, "C", (ftnlen)1, (
	    ftnlen)1)) {
	info = 2;
    } else if (! lsame_(diag, "U", (ftnlen)1, (ftnlen)1) && ! lsame_(diag, 
	    "N", (ftnlen)1, (ftnlen)1)) {
	info = 3;
    } else if (*n < 0) {
	info = 4;
    } else if (*lda < max(1,*n)) {
	info = 6;
    } else if (*incx == 0) {
	info = 8;
    }
    if (info != 0) {
	xerbla_("DTRMV ", &info, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE. */

    if (*n == 0) {
	return 0;
    }

    nounit = lsame_(diag, "N", (ftnlen)1, (ftnlen)1);

/*     SET UP THE START POINT IN X IF THE INCREMENT IS NOT UNITY. THIS */
/*     WILL BE  ( N - 1 )*INCX  TOO SMALL FOR DESCENDING LOOPS. */

    if (*incx <= 0) {
	kx = 1 - (*n - 1) * *incx;
    } else if (*incx != 1) {
	kx = 1;
    }

/*     START THE OPERATIONS. IN THIS VERSION THE ELEMENTS OF A ARE */
/*     ACCESSED SEQUENTIALLY WITH ONE PASS THROUGH A. */

    if (lsame_(trans, "N", (ftnlen)1, (ftnlen)1)) {

/*        FORM  X := A*X. */

	if (lsame_(uplo, "U", (ftnlen)1, (ftnlen)1)) {
	    if (*incx == 1) {
		i__1 = *n;
		for (j = 1; j <= i__1; ++j) {
		    if (x[j] != 0.) {
			temp = x[j];
			i__2 = j - 1;
			for (i__ = 1; i__ <= i__2; ++i__) {
			    x[i__] += temp * a[i__ + j * a_dim1];
/* L10: */
			}
			if (nounit) {
			    x[j] *= a[j + j * a_dim1];
			}
		    }
/* L20: */
		}
	    } else {
		jx = kx;
		i__1 = *n;
		for (j = 1; j <= i__1; ++j) {
		    if (x[jx] != 0.) {
			temp = x[jx];
			ix = kx;
			i__2 = j - 1;
			for (i__ = 1; i__ <= i__2; ++i__) {
			    x[ix] += temp * a[i__ + j * a_dim1];
			    ix += *incx;
/* L30: */
			}
			if (nounit) {
			    x[jx] *= a[j + j * a_dim1];
			}
		    }
		    jx += *incx;
/* L40: */
		}
	    }
	} else {
	    if (*incx == 1) {
		for (j = *n; j >= 1; --j) {
		    if (x[j] != 0.) {
			temp = x[j];
			i__1 = j + 1;
			for (i__ = *n; i__ >= i__1; --i__) {
			    x[i__] += temp * a[i__ + j * a_dim1];
/* L50: */
			}
			if (nounit) {
			    x[j] *= a[j + j * a_dim1];
			}
		    }
/* L60: */
		}
	    } else {
		kx += (*n - 1) * *incx;
		jx = kx;
		for (j = *n; j >= 1; --j) {
		    if (x[jx] != 0.) {
			temp = x[jx];
			ix = kx;
			i__1 = j + 1;
			for (i__ = *n; i__ >= i__1; --i__) {
			    x[ix] += temp * a[i__ + j * a_dim1];
			    ix -= *incx;
/* L70: */
			}
			if (nounit) {
			    x[jx] *= a[j + j * a_dim1];
			}
		    }
		    jx -= *incx;
/* L80: */
		}
	    }
	}
    } else {

/*        FORM  X := A'*X. */

	if (lsame_(uplo, "U", (ftnlen)1, (ftnlen)1)) {
	    if (*incx == 1) {
		for (j = *n; j >= 1; --j) {
		    temp = x[j];
		    if (nounit) {
			temp *= a[j + j * a_dim1];
		    }
		    for (i__ = j - 1; i__ >= 1; --i__) {
			temp += a[i__ + j * a_dim1] * x[i__];
/* L90: */
		    }
		    x[j] = temp;
/* L100: */
		}
	    } else {
		jx = kx + (*n - 1) * *incx;
		for (j = *n; j >= 1; --j) {
		    temp = x[jx];
		    ix = jx;
		    if (nounit) {
			temp *= a[j + j * a_dim1];
		    }
		    for (i__ = j - 1; i__ >= 1; --i__) {
			ix -= *incx;
			temp += a[i__ + j * a_dim1] * x[ix];
/* L110: */
		    }
		    x[jx] = temp;
		    jx -= *incx;
/* L120: */
		}
	    }
	} else {
	    if (*incx == 1) {
		i__1 = *n;
		for (j = 1; j <= i__1; ++j) {
		    temp = x[j];
		    if (nounit) {
			temp *= a[j + j * a_dim1];
		    }
		    i__2 = *n;
		    for (i__ = j + 1; i__ <= i__2; ++i__) {
			temp += a[i__ + j * a_dim1] * x[i__];
/* L130: */
		    }
		    x[j] = temp;
/* L140: */
		}
	    } else {
		jx = kx;
		i__1 = *n;
		for (j = 1; j <= i__1; ++j) {
		    temp = x[jx];
		    ix = jx;
		    if (nounit) {
			temp *= a[j + j * a_dim1];
		    }
		    i__2 = *n;
		    for (i__ = j + 1; i__ <= i__2; ++i__) {
			ix += *incx;
			temp += a[i__ + j * a_dim1] * x[ix];
/* L150: */
		    }
		    x[jx] = temp;
		    jx += *incx;
/* L160: */
		}
	    }
	}
    }

    return 0;

/*     END OF DTRMV . */

} /* dtrmv_ */

