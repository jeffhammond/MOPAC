/* dger.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dger_(integer *m, integer *n, doublereal *alpha, 
	doublereal *x, integer *incx, doublereal *y, integer *incy, 
	doublereal *a, integer *lda)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, ix, jy, kx, info;
    static doublereal temp;
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen);

/*     .. SCALAR ARGUMENTS .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DGER   PERFORMS THE RANK 1 OPERATION */

/*     A := ALPHA*X*Y' + A, */

/*  WHERE ALPHA IS A SCALAR, X IS AN M ELEMENT VECTOR, Y IS AN N ELEMENT */
/*  VECTOR AND A IS AN M BY N MATRIX. */

/*  PARAMETERS */
/*  ========== */

/*  M      - INTEGER. */
/*           ON ENTRY, M SPECIFIES THE NUMBER OF ROWS OF THE MATRIX A. */
/*           M MUST BE AT LEAST ZERO. */
/*           UNCHANGED ON EXIT. */

/*  N      - INTEGER. */
/*           ON ENTRY, N SPECIFIES THE NUMBER OF COLUMNS OF THE MATRIX A. */
/*           N MUST BE AT LEAST ZERO. */
/*           UNCHANGED ON EXIT. */

/*  ALPHA  - DOUBLE PRECISION. */
/*           ON ENTRY, ALPHA SPECIFIES THE SCALAR ALPHA. */
/*           UNCHANGED ON EXIT. */

/*  X      - DOUBLE PRECISION ARRAY OF DIMENSION AT LEAST */
/*           ( 1 + ( M - 1 )*ABS( INCX ) ). */
/*           BEFORE ENTRY, THE INCREMENTED ARRAY X MUST CONTAIN THE M */
/*           ELEMENT VECTOR X. */
/*           UNCHANGED ON EXIT. */

/*  INCX   - INTEGER. */
/*           ON ENTRY, INCX SPECIFIES THE INCREMENT FOR THE ELEMENTS OF */
/*           X. INCX MUST NOT BE ZERO. */
/*           UNCHANGED ON EXIT. */

/*  Y      - DOUBLE PRECISION ARRAY OF DIMENSION AT LEAST */
/*           ( 1 + ( N - 1 )*ABS( INCY ) ). */
/*           BEFORE ENTRY, THE INCREMENTED ARRAY Y MUST CONTAIN THE N */
/*           ELEMENT VECTOR Y. */
/*           UNCHANGED ON EXIT. */

/*  INCY   - INTEGER. */
/*           ON ENTRY, INCY SPECIFIES THE INCREMENT FOR THE ELEMENTS OF */
/*           Y. INCY MUST NOT BE ZERO. */
/*           UNCHANGED ON EXIT. */

/*  A      - DOUBLE PRECISION ARRAY OF DIMENSION ( LDA, N ). */
/*           BEFORE ENTRY, THE LEADING M BY N PART OF THE ARRAY A MUST */
/*           CONTAIN THE MATRIX OF COEFFICIENTS. ON EXIT, A IS */
/*           OVERWRITTEN BY THE UPDATED MATRIX. */

/*  LDA    - INTEGER. */
/*           ON ENTRY, LDA SPECIFIES THE FIRST DIMENSION OF A AS DECLARED */
/*           IN THE CALLING (SUB) PROGRAM. LDA MUST BE AT LEAST */
/*           MAX( 1, M ). */
/*           UNCHANGED ON EXIT. */


/*  LEVEL 2 BLAS ROUTINE. */

/*  -- WRITTEN ON 22-OCTOBER-1986. */
/*     JACK DONGARRA, ARGONNE NATIONAL LAB. */
/*     JEREMY DU CROZ, NAG CENTRAL OFFICE. */
/*     SVEN HAMMARLING, NAG CENTRAL OFFICE. */
/*     RICHARD HANSON, SANDIA NATIONAL LABS. */


/*     .. PARAMETERS .. */
/*     .. LOCAL SCALARS .. */
/*     .. EXTERNAL SUBROUTINES .. */
/*     .. INTRINSIC FUNCTIONS .. */
/*     .. */
/*     .. EXECUTABLE STATEMENTS .. */

/*     TEST THE INPUT PARAMETERS. */

    /* Parameter adjustments */
    --x;
    --y;
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;

    /* Function Body */
    info = 0;
    if (*m < 0) {
	info = 1;
    } else if (*n < 0) {
	info = 2;
    } else if (*incx == 0) {
	info = 5;
    } else if (*incy == 0) {
	info = 7;
    } else if (*lda < max(1,*m)) {
	info = 9;
    }
    if (info != 0) {
	xerbla_("DGER  ", &info, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE. */

    if (*m == 0 || *n == 0 || *alpha == 0.) {
	return 0;
    }

/*     START THE OPERATIONS. IN THIS VERSION THE ELEMENTS OF A ARE */
/*     ACCESSED SEQUENTIALLY WITH ONE PASS THROUGH A. */

    if (*incy > 0) {
	jy = 1;
    } else {
	jy = 1 - (*n - 1) * *incy;
    }
    if (*incx == 1) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    if (y[jy] != 0.) {
		temp = *alpha * y[jy];
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    a[i__ + j * a_dim1] += x[i__] * temp;
/* L10: */
		}
	    }
	    jy += *incy;
/* L20: */
	}
    } else {
	if (*incx > 0) {
	    kx = 1;
	} else {
	    kx = 1 - (*m - 1) * *incx;
	}
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    if (y[jy] != 0.) {
		temp = *alpha * y[jy];
		ix = kx;
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    a[i__ + j * a_dim1] += x[ix] * temp;
		    ix += *incx;
/* L30: */
		}
	    }
	    jy += *incy;
/* L40: */
	}
    }

    return 0;

/*     END OF DGER  . */

} /* dger_ */

