/* dgemv.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dgemv_(char *trans, integer *m, integer *n, doublereal *
	alpha, doublereal *a, integer *lda, doublereal *x, integer *incx, 
	doublereal *beta, doublereal *y, integer *incy, ftnlen trans_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, ix, iy, jx, jy, kx, ky, info;
    static doublereal temp;
    static integer lenx, leny;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen);

/*     .. SCALAR ARGUMENTS .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DGEMV  PERFORMS ONE OF THE MATRIX-VECTOR OPERATIONS */

/*     Y := ALPHA*A*X + BETA*Y,   OR   Y := ALPHA*A'*X + BETA*Y, */

/*  WHERE ALPHA AND BETA ARE SCALARS, X AND Y ARE VECTORS AND A IS AN */
/*  M BY N MATRIX. */

/*  PARAMETERS */
/*  ========== */

/*  TRANS  - CHARACTER*1. */
/*           ON ENTRY, TRANS SPECIFIES THE OPERATION TO BE PERFORMED AS */
/*           FOLLOWS: */

/*              TRANS = 'N' OR 'N'   Y := ALPHA*A*X + BETA*Y. */

/*              TRANS = 'T' OR 'T'   Y := ALPHA*A'*X + BETA*Y. */

/*              TRANS = 'C' OR 'C'   Y := ALPHA*A'*X + BETA*Y. */

/*           UNCHANGED ON EXIT. */

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

/*  A      - DOUBLE PRECISION ARRAY OF DIMENSION ( LDA, N ). */
/*           BEFORE ENTRY, THE LEADING M BY N PART OF THE ARRAY A MUST */
/*           CONTAIN THE MATRIX OF COEFFICIENTS. */
/*           UNCHANGED ON EXIT. */

/*  LDA    - INTEGER. */
/*           ON ENTRY, LDA SPECIFIES THE FIRST DIMENSION OF A AS DECLARED */
/*           IN THE CALLING (SUB) PROGRAM. LDA MUST BE AT LEAST */
/*           MAX( 1, M ). */
/*           UNCHANGED ON EXIT. */

/*  X      - DOUBLE PRECISION ARRAY OF DIMENSION AT LEAST */
/*           ( 1 + ( N - 1 )*ABS( INCX ) ) WHEN TRANS = 'N' OR 'N' */
/*           AND AT LEAST */
/*           ( 1 + ( M - 1 )*ABS( INCX ) ) OTHERWISE. */
/*           BEFORE ENTRY, THE INCREMENTED ARRAY X MUST CONTAIN THE */
/*           VECTOR X. */
/*           UNCHANGED ON EXIT. */

/*  INCX   - INTEGER. */
/*           ON ENTRY, INCX SPECIFIES THE INCREMENT FOR THE ELEMENTS OF */
/*           X. INCX MUST NOT BE ZERO. */
/*           UNCHANGED ON EXIT. */

/*  BETA   - DOUBLE PRECISION. */
/*           ON ENTRY, BETA SPECIFIES THE SCALAR BETA. WHEN BETA IS */
/*           SUPPLIED AS ZERO THEN Y NEED NOT BE SET ON INPUT. */
/*           UNCHANGED ON EXIT. */

/*  Y      - DOUBLE PRECISION ARRAY OF DIMENSION AT LEAST */
/*           ( 1 + ( M - 1 )*ABS( INCY ) ) WHEN TRANS = 'N' OR 'N' */
/*           AND AT LEAST */
/*           ( 1 + ( N - 1 )*ABS( INCY ) ) OTHERWISE. */
/*           BEFORE ENTRY WITH BETA NON-ZERO, THE INCREMENTED ARRAY Y */
/*           MUST CONTAIN THE VECTOR Y. ON EXIT, Y IS OVERWRITTEN BY THE */
/*           UPDATED VECTOR Y. */

/*  INCY   - INTEGER. */
/*           ON ENTRY, INCY SPECIFIES THE INCREMENT FOR THE ELEMENTS OF */
/*           Y. INCY MUST NOT BE ZERO. */
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
    --y;

    /* Function Body */
    info = 0;
    if (! lsame_(trans, "N", (ftnlen)1, (ftnlen)1) && ! lsame_(trans, "T", (
	    ftnlen)1, (ftnlen)1) && ! lsame_(trans, "C", (ftnlen)1, (ftnlen)1)
	    ) {
	info = 1;
    } else if (*m < 0) {
	info = 2;
    } else if (*n < 0) {
	info = 3;
    } else if (*lda < max(1,*m)) {
	info = 6;
    } else if (*incx == 0) {
	info = 8;
    } else if (*incy == 0) {
	info = 11;
    }
    if (info != 0) {
	xerbla_("DGEMV ", &info, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE. */

    if (*m == 0 || *n == 0 || *alpha == 0. && *beta == 1.) {
	return 0;
    }

/*     SET  LENX  AND  LENY, THE LENGTHS OF THE VECTORS X AND Y, AND SET */
/*     UP THE START POINTS IN  X  AND  Y. */

    if (lsame_(trans, "N", (ftnlen)1, (ftnlen)1)) {
	lenx = *n;
	leny = *m;
    } else {
	lenx = *m;
	leny = *n;
    }
    if (*incx > 0) {
	kx = 1;
    } else {
	kx = 1 - (lenx - 1) * *incx;
    }
    if (*incy > 0) {
	ky = 1;
    } else {
	ky = 1 - (leny - 1) * *incy;
    }

/*     START THE OPERATIONS. IN THIS VERSION THE ELEMENTS OF A ARE */
/*     ACCESSED SEQUENTIALLY WITH ONE PASS THROUGH A. */

/*     FIRST FORM  Y := BETA*Y. */

    if (*beta != 1.) {
	if (*incy == 1) {
	    if (*beta == 0.) {
		i__1 = leny;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    y[i__] = 0.;
/* L10: */
		}
	    } else {
		i__1 = leny;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    y[i__] = *beta * y[i__];
/* L20: */
		}
	    }
	} else {
	    iy = ky;
	    if (*beta == 0.) {
		i__1 = leny;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    y[iy] = 0.;
		    iy += *incy;
/* L30: */
		}
	    } else {
		i__1 = leny;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    y[iy] = *beta * y[iy];
		    iy += *incy;
/* L40: */
		}
	    }
	}
    }
    if (*alpha == 0.) {
	return 0;
    }
    if (lsame_(trans, "N", (ftnlen)1, (ftnlen)1)) {

/*        FORM  Y := ALPHA*A*X + Y. */

	jx = kx;
	if (*incy == 1) {
	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		if (x[jx] != 0.) {
		    temp = *alpha * x[jx];
		    i__2 = *m;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			y[i__] += temp * a[i__ + j * a_dim1];
/* L50: */
		    }
		}
		jx += *incx;
/* L60: */
	    }
	} else {
	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		if (x[jx] != 0.) {
		    temp = *alpha * x[jx];
		    iy = ky;
		    i__2 = *m;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			y[iy] += temp * a[i__ + j * a_dim1];
			iy += *incy;
/* L70: */
		    }
		}
		jx += *incx;
/* L80: */
	    }
	}
    } else {

/*        FORM  Y := ALPHA*A'*X + Y. */

	jy = ky;
	if (*incx == 1) {
	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		temp = 0.;
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    temp += a[i__ + j * a_dim1] * x[i__];
/* L90: */
		}
		y[jy] += *alpha * temp;
		jy += *incy;
/* L100: */
	    }
	} else {
	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		temp = 0.;
		ix = kx;
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    temp += a[i__ + j * a_dim1] * x[ix];
		    ix += *incx;
/* L110: */
		}
		y[jy] += *alpha * temp;
		jy += *incy;
/* L120: */
	    }
	}
    }

    return 0;

/*     END OF DGEMV . */

} /* dgemv_ */

