/* mamult.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int mamult_(doublereal *a, doublereal *b, doublereal *c__, 
	integer *n, doublereal *one)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, ii, jj, kk;
    static doublereal sum;

/* *********************************************************************** */

/*   MAMULT MULTIPLIES A BY B AND PUTS THE RESULT IN C */

/* *********************************************************************** */
    /* Parameter adjustments */
    --c__;
    --b;
    --a;

    /* Function Body */
    l = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = (i__ - 1) * i__ / 2;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    jj = (j - 1) * j / 2;
	    ++l;
	    sum = 0.;
	    i__3 = j;
	    for (k = 1; k <= i__3; ++k) {
/* L10: */
		sum += a[ii + k] * b[jj + k];
	    }
	    i__3 = i__;
	    for (k = j + 1; k <= i__3; ++k) {
/* L20: */
		sum += a[ii + k] * b[(k - 1) * k / 2 + j];
	    }
	    i__3 = *n;
	    for (k = i__ + 1; k <= i__3; ++k) {
		kk = k * (k - 1) / 2;
/* L30: */
		sum += a[kk + i__] * b[kk + j];
	    }
/* L40: */
	    c__[l] = sum + *one * c__[l];
	}
    }
    return 0;
} /* mamult_ */

