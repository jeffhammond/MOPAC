/* helect.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

doublereal helect_(integer *n, doublereal *p, doublereal *h__, doublereal *f)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k;
    static doublereal ed, ee;
    static integer jj, nn;

/* *********************************************************************** */

/*    SUBROUTINE CALCULATES THE ELECTRONIC ENERGY OF THE SYSTEM IN EV. */

/*    ON ENTRY N = NUMBER OF ATOMIC ORBITALS. */
/*             P = DENSITY MATRIX, PACKED, LOWER TRIANGLE. */
/*             H = ONE-ELECTRON MATRIX, PACKED, LOWER TRIANGLE. */
/*             F = TWO-ELECTRON MATRIX, PACKED, LOWER TRIANGLE. */
/*    ON EXIT */
/*        HELECT = ELECTRONIC ENERGY. */

/*    NO ARGUMENTS ARE CHANGED. */

/* *********************************************************************** */
    /* Parameter adjustments */
    --f;
    --h__;
    --p;

    /* Function Body */
    ed = 0.;
    ee = 0.;
    k = 0;
    nn = *n + 1;
    i__1 = nn;
    for (i__ = 2; i__ <= i__1; ++i__) {
	++k;
	jj = i__ - 1;
	ed += p[k] * (h__[k] + f[k]);
	if (i__ == nn) {
	    goto L20;
	}
	i__2 = jj;
	for (j = 1; j <= i__2; ++j) {
	    ++k;
/* L10: */
	    ee += p[k] * (h__[k] + f[k]);
	}
L20:
	;
    }
    ee += ed * .5;
    ret_val = ee;
    return ret_val;

} /* helect_ */

