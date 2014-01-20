/* solrot.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    integer l1l, l2l, l3l, l1u, l2u, l3u;
} ucell_;

#define ucell_1 ucell_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Subroutine */ int solrot_(integer *ni, integer *nj, doublereal *xi, 
	doublereal *xj, doublereal *wj, doublereal *wk, integer *kr, 
	doublereal *e1b, doublereal *e2a, doublereal *enuc, doublereal *
	cutoff)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer i__, j, k, l, kb, ii;
    static doublereal one;
#define lims ((integer *)&ucell_1)
    static doublereal xjuc[3], wmax[100], wsum[100], wbits[100], e1bits[10], 
	    e2bits[10], enubit;
    extern /* Subroutine */ int rotate_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *);

/* *********************************************************************** */

/*   SOLROT FORMS THE TWO-ELECTRON TWO-ATOM J AND K INTEGRAL STRINGS. */
/*          ON EXIT WJ = "J"-TYPE INTEGRALS */
/*                  WK = "K"-TYPE INTEGRALS */

/*      FOR MOLECULES, WJ = WK. */
/* *********************************************************************** */
    /* Parameter adjustments */
    --e2a;
    --e1b;
    --wk;
    --wj;
    --xj;
    --xi;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
/* $DOIT ASIS */
	i__1 = euler_1.id;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    lims[i__ - 1] = -1;
/* L10: */
	    lims[i__ + 2] = 1;
	}
/* $DOIT ASIS */
	for (i__ = euler_1.id + 1; i__ <= 3; ++i__) {
	    lims[i__ - 1] = 0;
/* L20: */
	    lims[i__ + 2] = 0;
	}
    }
    one = 1.;
    if (xi[1] == xj[1] && xi[2] == xj[2] && xi[3] == xj[3]) {
	one = .5;
    }
    for (i__ = 1; i__ <= 100; ++i__) {
	wmax[i__ - 1] = 0.;
	wsum[i__ - 1] = 0.;
/* L30: */
	wbits[i__ - 1] = 0.;
    }
    for (i__ = 1; i__ <= 10; ++i__) {
	e1b[i__] = 0.;
/* L40: */
	e2a[i__] = 0.;
    }
    *enuc = 0.;
    i__1 = ucell_1.l1u;
    for (i__ = ucell_1.l1l; i__ <= i__1; ++i__) {
	i__2 = ucell_1.l2u;
	for (j = ucell_1.l2l; j <= i__2; ++j) {
	    i__3 = ucell_1.l3u;
	    for (k = ucell_1.l3l; k <= i__3; ++k) {
/* $DOIT ASIS */
		for (l = 1; l <= 3; ++l) {
/* L50: */
		    xjuc[l - 1] = xj[l] + euler_1.tvec[l - 1] * i__ + 
			    euler_1.tvec[l + 2] * j + euler_1.tvec[l + 5] * k;
		}
		kb = 1;
		rotate_(ni, nj, &xi[1], xjuc, wbits, &kb, e1bits, e2bits, &
			enubit, cutoff);
		--kb;
		i__4 = kb;
		for (ii = 1; ii <= i__4; ++ii) {
/* L60: */
		    wsum[ii - 1] += wbits[ii - 1];
		}
		if (wmax[0] < wbits[0]) {
		    i__4 = kb;
		    for (ii = 1; ii <= i__4; ++ii) {
/* L70: */
			wmax[ii - 1] = wbits[ii - 1];
		    }
		}
		for (ii = 1; ii <= 10; ++ii) {
		    e1b[ii] += e1bits[ii - 1];
/* L80: */
		    e2a[ii] += e2bits[ii - 1];
		}
		*enuc += enubit * one;
/* L90: */
	    }
	}
    }
    if (one < .9) {
	i__3 = kb;
	for (i__ = 1; i__ <= i__3; ++i__) {
/* L100: */
	    wmax[i__ - 1] = 0.;
	}
    }
    i__3 = kb;
    for (i__ = 1; i__ <= i__3; ++i__) {
	wk[i__] = wmax[i__ - 1];
/* L110: */
	wj[i__] = wsum[i__ - 1];
    }
    *kr = kb + *kr;
    return 0;
} /* solrot_ */

#undef lims


