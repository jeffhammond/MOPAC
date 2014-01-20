/* mult.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int mult_(doublereal *c__, doublereal *s, doublereal *vecs, 
	integer *n)
{
    /* System generated locals */
    integer c_dim1, c_offset, s_dim1, s_offset, vecs_dim1, vecs_offset, i__1, 
	    i__2, i__3;

    /* Local variables */
    static integer i__, j, k;
    static doublereal sum;

/* ********************************************************************** */

/*   MULT IS USED IN THE MULLIKEN ANALYSIS ONLY. IT PERFORMS THE */
/*        OPERATION:- */
/*                                   VECS=BACK-TRANSFORMED EIGENVECTORS */
/*        VECS  =  C*S               C   =UN-BACK-TRANSFORMED VECTORS */
/*                                   S   =1/SQRT(OVERLAP MATRIX) */

/* ********************************************************************** */
    /* Parameter adjustments */
    vecs_dim1 = *n;
    vecs_offset = 1 + vecs_dim1 * 1;
    vecs -= vecs_offset;
    s_dim1 = *n;
    s_offset = 1 + s_dim1 * 1;
    s -= s_offset;
    c_dim1 = *n;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    sum = 0.;
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
/* L10: */
		sum += c__[k + i__ * c_dim1] * s[j + k * s_dim1];
	    }
/* L20: */
	    vecs[j + i__ * vecs_dim1] = sum;
	}
    }
    return 0;
} /* mult_ */

