/* dvfill.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__3 = 3;
static integer c__4 = 4;
static integer c__2 = 2;

/* Subroutine */ int dvfill_(integer *nppa, doublereal *dirvec)
{
    /* Initialized data */

    static integer kset[60]	/* was [2][30] */ = { 1,2,1,3,1,4,1,5,1,6,12,
	    11,12,10,12,9,12,8,12,7,2,3,3,4,4,5,5,6,6,2,7,8,8,9,9,10,10,11,11,
	    7,2,7,7,3,3,8,8,4,4,9,9,5,5,10,10,6,6,11,11,2 };
    static integer fset[60]	/* was [3][20] */ = { 1,2,3,1,3,4,1,4,5,1,5,6,
	    1,6,2,12,11,10,12,10,9,12,9,8,12,8,7,12,7,11,2,3,7,3,4,8,4,5,9,5,
	    6,10,6,2,11,7,8,3,8,9,4,9,10,5,10,11,6,11,7,2 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);
    integer pow_ii(integer *, integer *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal h__;
    static integer i__, j, k, l, m;
    static doublereal r__, t;
    static integer j1, j2, na, nb, nc, nd, kh, ix;
    static doublereal beta, dist;

/* 	FUELLEN DES FELDES DIRVEC */
    /* Parameter adjustments */
    dirvec -= 4;

    /* Function Body */
    dirvec[4] = -1.;
    dirvec[5] = 0.;
    dirvec[6] = 0.;
    nd = 1;
    r__ = sqrt(.8);
    h__ = sqrt(.2);
    for (i__ = -1; i__ <= 1; i__ += 2) {
	for (j = 1; j <= 5; ++j) {
	    ++nd;
	    beta = j * 1.25663706 + 1. + (i__ + 1) * .3141593;
	    dirvec[nd * 3 + 2] = r__ * cos(beta);
	    dirvec[nd * 3 + 3] = r__ * sin(beta);
	    dirvec[nd * 3 + 1] = i__ * h__;
/* L10: */
	}
    }
    dirvec[38] = 0.;
    dirvec[39] = 0.;
    dirvec[37] = 1.;
    nd = 12;
/*  NPPA=10*3**K*4**L+2 */
    m = (*nppa - 2) / 10;
    for (k = 0; k <= 10; ++k) {
	if (m / 3 * 3 != m) {
	    goto L30;
	}
/* L20: */
	m /= 3;
    }
L30:
    for (l = 0; l <= 10; ++l) {
	if (m / 4 << 2 != m) {
	    goto L50;
	}
/* L40: */
	m /= 4;
    }
L50:
    if (pow_ii(&c__3, &k) * 10 * pow_ii(&c__4, &l) + 2 != *nppa) {
	s_stop("VALUE OF NPPA NOT ALLOWED:      IT MUST BE 10*3**K*4**L+2", (
		ftnlen)57);
    }
    kh = k / 2;
    m = pow_ii(&c__2, &l) * pow_ii(&c__3, &kh);
/* CREATE ON EACH EDGE 2**L*3**KH-1 NEW POINTS */
    for (i__ = 1; i__ <= 30; ++i__) {
	na = kset[(i__ << 1) - 2];
	nb = kset[(i__ << 1) - 1];
	i__1 = m - 1;
	for (j = 1; j <= i__1; ++j) {
	    ++nd;
	    for (ix = 1; ix <= 3; ++ix) {
/* L60: */
		dirvec[ix + nd * 3] = dirvec[ix + na * 3] * (m - j) + dirvec[
			ix + nb * 3] * j;
	    }
/* L70: */
	}
    }
/* CREATE POINTS WITHIN EACH TRIANGLE */
    for (i__ = 1; i__ <= 20; ++i__) {
	na = fset[i__ * 3 - 3];
	nb = fset[i__ * 3 - 2];
	nc = fset[i__ * 3 - 1];
	i__1 = m - 1;
	for (j1 = 1; j1 <= i__1; ++j1) {
	    i__2 = m - j1 - 1;
	    for (j2 = 1; j2 <= i__2; ++j2) {
		++nd;
		for (ix = 1; ix <= 3; ++ix) {
/* L80: */
		    dirvec[ix + nd * 3] = dirvec[ix + na * 3] * (m - j1 - j2) 
			    + dirvec[ix + nb * 3] * j1 + dirvec[ix + nc * 3] *
			     j2;
		}
/* L90: */
	    }
	}
    }
    if (k == kh << 1) {
	goto L140;
    }
/* CREATE TO ADDITIONAL SUBGRIDS */
    t = .33333333333333331;
    for (i__ = 1; i__ <= 20; ++i__) {
	na = fset[i__ * 3 - 3];
	nb = fset[i__ * 3 - 2];
	nc = fset[i__ * 3 - 1];
	i__2 = m - 1;
	for (j1 = 0; j1 <= i__2; ++j1) {
	    i__1 = m - j1 - 1;
	    for (j2 = 0; j2 <= i__1; ++j2) {
		++nd;
		for (ix = 1; ix <= 3; ++ix) {
/* L100: */
		    dirvec[ix + nd * 3] = dirvec[ix + na * 3] * (m - j1 - j2 
			    - t * 2) + dirvec[ix + nb * 3] * (j1 + t) + 
			    dirvec[ix + nc * 3] * (j2 + t);
		}
/* L110: */
	    }
	}
    }
    t = .66666666666666663;
    for (i__ = 1; i__ <= 20; ++i__) {
	na = fset[i__ * 3 - 3];
	nb = fset[i__ * 3 - 2];
	nc = fset[i__ * 3 - 1];
	i__1 = m - 2;
	for (j1 = 0; j1 <= i__1; ++j1) {
	    i__2 = m - j1 - 2;
	    for (j2 = 0; j2 <= i__2; ++j2) {
		++nd;
		for (ix = 1; ix <= 3; ++ix) {
/* L120: */
		    dirvec[ix + nd * 3] = dirvec[ix + na * 3] * (m - j1 - j2 
			    - t * 2) + dirvec[ix + nb * 3] * (j1 + t) + 
			    dirvec[ix + nc * 3] * (j2 + t);
		}
/* L130: */
	    }
	}
    }
/* NORMALIZE ALL VECTORS */
L140:
    i__2 = *nppa;
    for (i__ = 1; i__ <= i__2; ++i__) {
	dist = 0.;
	for (ix = 1; ix <= 3; ++ix) {
/* L150: */
/* Computing 2nd power */
	    d__1 = dirvec[ix + i__ * 3];
	    dist += d__1 * d__1;
	}
	dist = 1. / sqrt(dist);
	for (ix = 1; ix <= 3; ++ix) {
/* L160: */
	    dirvec[ix + i__ * 3] *= dist;
	}
/* L170: */
    }
    return 0;
} /* dvfill_ */

