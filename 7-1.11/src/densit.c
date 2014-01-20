/* densit.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int densit_(doublereal *c__, integer *mdim, integer *norbs, 
	integer *ndubl, integer *nsingl, doublereal *fract, doublereal *p, 
	integer *mode)
{
    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, nl1, nl2, nu1, nu2;
    static doublereal sum1, sum2, frac, sign, const__;
    static integer norbs2;

/* *********************************************************************** */

/*   DENSIT COMPUTES THE DENSITY MATRIX GIVEN THE EIGENVECTOR MATRIX, AND */
/*          INFORMATION ABOUT THE M.O. OCCUPANCY. */

/*  INPUT:  C     = SQUARE EIGENVECTOR MATRIX, C IS OF SIZE MDIM BY MDIM */
/*                  AND THE EIGENVECTORS ARE STORED IN THE TOP LEFT-HAND */
/*                  CORNER. */
/*          NORBS = NUMBER OF ORBITALS */
/*          NDUBL = NUMBER OF DOUBLY-OCCUPIED M.O.S ( =0 IF UHF) */
/*          NSINGL= NUMBER OF SINGLY OR FRACTIONALLY OCCUPIED M.O.S. */
/*          MODE  = 2 IF POSITRON EQUIVALENT IS NOT TO BE USED */

/*   ON EXIT: P   = DENSITY MATRIX */

/* *********************************************************************** */

/* SET UP LIMITS FOR SUMS */
/*  NL1 = BEGINING OF ONE ELECTRON SUM */
/*  NU1 = END OF SAME */
/*  NL2 = BEGINING OF TWO ELECTRON SUM */
/*  NU2 = END OF SAME */

    /* Parameter adjustments */
    c_dim1 = *mdim;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    --p;

    /* Function Body */
    norbs2 = *norbs / 2;
    *nsingl = max(*ndubl,*nsingl);
    if (*ndubl != 0 && *nsingl > norbs2 && *mode != 2) {

/*    TAKE POSITRON EQUIVALENT */

	sign = -1.;
	frac = 2. - *fract;
	const__ = 2.;
	nl2 = *nsingl + 1;
	nu2 = *norbs;
	nl1 = *ndubl + 1;
	nu1 = *nsingl;
    } else {

/*    TAKE ELECTRON EQUIVALENT */

	sign = 1.;
	frac = *fract;
	const__ = 0.;
	nl2 = 1;
	nu2 = *ndubl;
	nl1 = *ndubl + 1;
	nu1 = *nsingl;
    }
    l = 0;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
	    sum2 = 0.;
	    sum1 = 0.;
	    i__3 = nu2;
	    for (k = nl2; k <= i__3; ++k) {
/* L10: */
		sum2 += c__[i__ + k * c_dim1] * c__[j + k * c_dim1];
	    }
	    sum2 *= 2.;
	    i__3 = nu1;
	    for (k = nl1; k <= i__3; ++k) {
/* L20: */
		sum1 += c__[i__ + k * c_dim1] * c__[j + k * c_dim1];
	    }
/* L30: */
	    p[l] = (sum2 + sum1 * frac) * sign;
	}
/* L40: */
	p[l] = const__ + p[l];
    }
    return 0;
} /* densit_ */

