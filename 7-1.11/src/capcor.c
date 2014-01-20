/* capcor.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

doublereal capcor_(integer *nat, integer *nfirst, integer *nlast, integer *
	numat, doublereal *p, doublereal *h__)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, ii, il, jl, ni, kk, iu;
    static doublereal sum;

/* ***************************************************************** */

/*    CORRECTION TO ELECTRONIC ENERGY DUE TO CAPPED BONDS */

/* ***************************************************************** */
    /* Parameter adjustments */
    --nlast;
    --nfirst;
    --nat;
    --p;
    --h__;

    /* Function Body */
    sum = 0.;
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ni = nat[i__];
	il = nfirst[i__];
	iu = nlast[i__];
	if (ni == 102) {

/*   DO ENTIRE ROW - NO NEED TO CHECK FURTHER. */

	    j = nlast[i__] * (nlast[i__] + 1) / 2;
	    ii = iu - 1;
	    i__2 = ii;
	    for (k = 1; k <= i__2; ++k) {
		--j;
/* L10: */
		sum += p[j] * h__[j];
	    }
	} else {
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
		jl = nfirst[j];
		if (nat[j] == 102) {
		    i__3 = iu;
		    for (k = il; k <= i__3; ++k) {
			kk = k * (k - 1) / 2 + jl;
/* L20: */
			sum += p[kk] * h__[kk];
		    }
		}
/* L30: */
	    }
	}
/* L40: */
    }

/*   DOUBLE SUM SINCE WE ONLY CALCULATED LOWER HALF, AND CAPCOR */
/*   WILL APPEAR IN 1/2*P(H+F).  ONLY H PART OF F WILL BE USED. */
    ret_val = -sum * 2.;
    return ret_val;
} /* capcor_ */

