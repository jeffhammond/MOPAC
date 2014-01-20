/* matpak.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* CCCCCCCCCCCCCCCCC     MATHEMATICAL PACKAGE     CCCCCCCCCCCCCCCCCCCCCCC */
/* CCCCCC    MOST OF THESE ROUTINE ARE FULLY VECTORIZED ON CRAY-1  CCCCCC */
/* CCCCCC    THEY ARE ROUGHLY RESPONSIBLE OF 70% OF THE CPU TIME   CCCCCC */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
doublereal sdot_(integer *n, doublereal *x, integer *ix, doublereal *y, 
	integer *iy)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j;

/*     SDOT=DOT PRODUCT OF VECTOR X, STEP IX, BY VECTOR Y, STEP IY, */
/*     N ELEMENTS. */
/*     SIMULATE ROUTINE ON CRAY (SAME NAME AND CALLING SEQUENCE). */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    j = 1;
    ret_val = 0.;
    i__1 = (*n - 1) * *ix + 1;
    i__2 = *ix;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	ret_val += x[i__] * y[j];
/* L10: */
	j += *iy;
    }
    return ret_val;
} /* sdot_ */

/* Subroutine */ int scopy_(integer *n, doublereal *x, integer *ix, 
	doublereal *y, integer *iy)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j;

/*     COPY VECTOR X, STEP IX ONTO VECTOR Y, STEP IY, N ELEMENTS. */
/*     SIMULATE ROUTINE ON CRAY (SAME NAME AND CALLING SEQUENCE). */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    i__ = 1;
    i__1 = *iy * (*n - 1) + 1;
    i__2 = *iy;
    for (j = 1; i__2 < 0 ? j >= i__1 : j <= i__1; j += i__2) {
	y[j] = x[i__];
/* L10: */
	i__ += *ix;
    }
    return 0;
} /* scopy_ */

/* Subroutine */ int saxpy_(integer *n, doublereal *a, doublereal *x, integer 
	*ix, doublereal *y, integer *iy)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j;

/*     VECTOR INCREMENT Y=Y+A*X WITH X & Y VECTORS OF LENGTH N, A SCALAR. */
/*     IX STEP OF X, IY STEP OF Y. */
/*     SIMULATE ROUTINE ON CRAY (SAME NAME AND CALLING SEQUENCE). */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    i__ = 1;
    i__1 = *iy * (*n - 1) + 1;
    i__2 = *iy;
    for (j = 1; i__2 < 0 ? j >= i__1 : j <= i__1; j += i__2) {
	y[j] += *a * x[i__];
/* L10: */
	i__ += *ix;
    }
    return 0;
} /* saxpy_ */

/* Subroutine */ int mxm_(doublereal *a, integer *nar, doublereal *b, integer 
	*nbr, doublereal *c__, integer *ncc)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Local variables */
    static integer i__, j, k;

/*     RECTANGULAR MATRIX PRODUCT C=A*B. */
/*     EACH MATRIX IS ENTIRELY FULLFILLED AND PACKED. */
/*     SIMULATE ROUTINE ON CRAY (SAME NAME AND CALLING SEQUENCE). */
    /* Parameter adjustments */
    a_dim1 = *nar;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    c_dim1 = *nar;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    b_dim1 = *nbr;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;

    /* Function Body */
    i__1 = *ncc;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    c__[i__ + j * c_dim1] = 0.;
	}
	i__2 = *nbr;
	for (k = 1; k <= i__2; ++k) {
	    i__3 = *nar;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L20: */
		c__[i__ + j * c_dim1] += a[i__ + k * a_dim1] * b[k + j * 
			b_dim1];
	    }
	}
    }
    return 0;
} /* mxm_ */

/* Subroutine */ int mxmt_(doublereal *a, integer *nar, doublereal *b, 
	integer *nbr, doublereal *c__, integer *ncc)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Local variables */
    static integer i__, j, k;

/*     MATRIX PRODUCT C(NAR,NCC) = A(NAR,NBR) * (B(NCC,NBR))' */
/*     ALL MATRICES RECTANGULAR , PACKED. */
    /* Parameter adjustments */
    a_dim1 = *nar;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    c_dim1 = *nar;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    b_dim1 = *ncc;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;

    /* Function Body */
    i__1 = *ncc;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    c__[i__ + j * c_dim1] = 0.;
	}
	i__2 = *nbr;
	for (k = 1; k <= i__2; ++k) {
	    i__3 = *nar;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L20: */
		c__[i__ + j * c_dim1] += a[i__ + k * a_dim1] * b[j + k * 
			b_dim1];
	    }
	}
    }
    return 0;
} /* mxmt_ */

/* Subroutine */ int mtxm_(doublereal *a, integer *nar, doublereal *b, 
	integer *nbr, doublereal *c__, integer *ncc)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Local variables */
    static integer i__, j, k;

/*     MATRIX PRODUCT C(NAR,NCC) = (A(NBR,NAR))' * B(NBR,NCC) */
/*     ALL MATRICES RECTANGULAR , PACKED. */
    /* Parameter adjustments */
    a_dim1 = *nbr;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    c_dim1 = *nar;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    b_dim1 = *nbr;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;

    /* Function Body */
    i__1 = *ncc;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    c__[i__ + j * c_dim1] = 0.;
	}
	i__2 = *nbr;
	for (k = 1; k <= i__2; ++k) {
	    i__3 = *nar;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L20: */
		c__[i__ + j * c_dim1] += a[k + i__ * a_dim1] * b[k + j * 
			b_dim1];
	    }
	}
    }
    return 0;
} /* mtxm_ */

/* Subroutine */ int mtxmc_(doublereal *a, integer *nar, doublereal *b, 
	integer *nbr, doublereal *c__)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1;

    /* Local variables */
    static integer i__, l;
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);

/*     MATRIX PRODUCT C(NAR,NAR) = (A(NBR,NAR))' * B(NBR,NAR) */
/*     A AND B RECTANGULAR , PACKED, */
/*     C LOWER LEFT TRIANGLE ONLY, PACKED IN CANONICAL ORDER. */
/*  NOTE ... THIS IS THE BEST VERSION ON CRAY 1. */
    /* Parameter adjustments */
    b_dim1 = *nbr;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    a_dim1 = *nbr;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --c__;

    /* Function Body */
    l = 1;
    i__1 = *nar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	mxm_(&a[i__ * a_dim1 + 1], &c__1, &b[b_offset], nbr, &c__[l], &i__);
/* L10: */
	l += i__;
    }
    return 0;
} /* mtxmc_ */

/* Subroutine */ int supdot_(doublereal *s, doublereal *h__, doublereal *g, 
	integer *n, integer *ig)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, k;
    static doublereal gi, sum;

/*     (S)=(H)*(G) WITH  H  IN PACKED FORM (CANONICAL ORDER). */
/*     IG IS THE INCREMENT FOR THE VECTOR G. */
/*     CRAY-1 VERSION */
/* CC      K=1 */
/* CC      L=1 */
/* CC      DO 10 I=1,N */
/* CC      S(I)=SDOT(I,H(K),1,G,IG,I) */
/* CC      IF(I.GT.1) THEN */
/* CC         L=L+IG */
/* CC         CALL SAXPY(I-1,G(L),H(K),1,S,1) */
/* CC      ENDIF */
/* CC   10 K=K+I */
/* CC      RETURN */
/* CC      END */
/*     SCALAR VERSION OK WITH IG=1 ONLY. */
    /* Parameter adjustments */
    --g;
    --h__;
    --s;

    /* Function Body */
    k = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
/* L10: */
	    sum += g[j] * h__[k + j];
	}
	s[i__] = sum;
/* L20: */
	k += i__;
    }
    if (*n == 1) {
	return 0;
    }
    k = 1;
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	gi = g[i__];
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
/* L30: */
	    s[j] += h__[k + j] * gi;
	}
/* L40: */
	k += i__;
    }
    return 0;
} /* supdot_ */

