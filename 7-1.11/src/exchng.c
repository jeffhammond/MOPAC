/* exchng.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int exchng_(doublereal *a, doublereal *b, doublereal *c__, 
	doublereal *d__, doublereal *x, doublereal *y, doublereal *t, 
	doublereal *q, integer *n)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;

/* ******************************************************************** */

/* THE CONTENTS OF A, C, T, AND X ARE STORED IN B, D, Q, AND Y! */

/*   THIS IS A DEDICATED ROUTINE, IT IS CALLED BY LINMIN AND LOCMIN ONLY. */

/* ******************************************************************** */
    /* Parameter adjustments */
    --y;
    --x;

    /* Function Body */
    *b = *a;
    *d__ = *c__;
    *q = *t;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	y[i__] = x[i__];
/* L10: */
    }
    return 0;

} /* exchng_ */

