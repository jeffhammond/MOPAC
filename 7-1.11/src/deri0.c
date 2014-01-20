/* deri0.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int deri0_(doublereal *e, integer *n, doublereal *scalar, 
	doublereal *diag, doublereal *fract, integer *nbo)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, l;
    static doublereal shift;
    static integer nopen;
    static doublereal const__;


/*     COMPUTE THE DIAGONAL DOMINANT PART OF THE SUPER-MATRIX AND */
/*     DEFINE THE SCALAR COEFFICIENTS APPLIED ON EACH ROW OF THE */
/*     SUPER LINEAR SYSTEM IN ORDER TO REDUCE THE EIGENVALUE SPECTRUM OF */
/*     THE ELECTRONIC HESSIAN, */
/*     THUS SPEEDING CONVERGENCE OF RELAXATION PROCESS IN 'DERI2'. */
/*  INPUT */
/*     E(N)             : EIGENVALUES OF FOCK MATRIX. */
/*     N                : NUMBER OF M.O. */
/*     NBO(3)           : OCCUPANCY BOUNDARIES. */
/*     FRACT            : PARTIAL OCCUPANCY OF 'OPEN' SHELLS. */
/*     SCALAR(MINEAR)   : SCALE APPLIED ON EACH COLUMN AND ROW OF THE */
/*                        SYMMETRIC SUPER SYSTEM. */

    /* Parameter adjustments */
    --e;
    --scalar;
    --diag;
    --nbo;

    /* Function Body */
    shift = 2.36;

/*     DOMINANT DIAGONAL PART OF THE SUPER-MATRIX. */
/*     ------------------------------------------- */
    nopen = nbo[1] + nbo[2];
    const__ = .001;
    l = 1;
    if (nbo[2] > 0 && nbo[1] > 0) {
/*        OPEN-CLOSED */
	i__1 = nbo[1];
	for (j = 1; j <= i__1; ++j) {
	    i__2 = nopen;
	    for (i__ = nbo[1] + 1; i__ <= i__2; ++i__) {
		diag[l] = (e[i__] - e[j]) / (2. - *fract + const__);
/* L10: */
		++l;
	    }
	}
    }
    if (nbo[3] > 0 && nbo[1] > 0) {
/* 	 VIRTUAL-CLOSED */
	i__2 = nbo[1];
	for (j = 1; j <= i__2; ++j) {
	    i__1 = *n;
	    for (i__ = nopen + 1; i__ <= i__1; ++i__) {
		diag[l] = (e[i__] - e[j]) / 2.;
/* L20: */
		++l;
	    }
	}
    }
    if (nbo[3] != 0 && nbo[2] != 0) {
/*        VIRTUAL-OPEN */
	i__1 = nopen;
	for (j = nbo[1] + 1; j <= i__1; ++j) {
	    i__2 = *n;
	    for (i__ = nopen + 1; i__ <= i__2; ++i__) {
		diag[l] = (e[i__] - e[j]) / (*fract + const__);
/* L30: */
		++l;
	    }
	}
    }

/*     TAKE SCALE FACTORS AS (SHIFT-DIAG)**(-0.5) . */
/*     ------------------------------------------ */
    i__2 = l - 1;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L40: */
/* Computing MAX */
	d__1 = diag[i__] * .3, d__2 = diag[i__] - shift;
	scalar[i__] = sqrt(1. / max(d__1,d__2));
    }
    return 0;
} /* deri0_ */

