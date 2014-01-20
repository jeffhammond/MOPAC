/* dot.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

doublereal dot_(doublereal *x, doublereal *y, integer *n)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__;

/* *********************************************************************** */

/*   DOT FORMS THE SCALAR PRODUCT OF TWO VECTORS. */

/*   ON INPUT     X   =    FIRST VECTOR, OF LENGTH N. */
/*                Y   =    SECOND VECTOR, OF LENGTH N. */

/*   ON RETURN    DOT =    DOT PRODUCT OF X AND Y. */

/* *********************************************************************** */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    ret_val = 0.;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	ret_val += x[i__] * y[i__];
    }
    return ret_val;
} /* dot_ */

