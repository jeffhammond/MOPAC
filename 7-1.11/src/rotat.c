/* rotat.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal ds[16], dg[22], dr[100], tdx[3], tdy[3], tdz[3];
} derivs_;

#define derivs_1 derivs_

struct {
    doublereal g[22], tx[3], ty[3], tz[3];
} extra_;

#define extra_1 extra_

/* Table of constant values */

static doublereal c_b3 = 1.;

/* Subroutine */ int rotat_(doublereal *coord, integer *i__, integer *j, 
	integer *ix, doublereal *rij, doublereal *del1, integer *idx)
{
    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal xd, yd, zd;
    static integer ijk;
    static doublereal rxy, rzx, ryz, term;

    /* Parameter adjustments */
    coord -= 4;

    /* Function Body */
    xd = coord[*i__ * 3 + 1] - coord[*j * 3 + 1];
    yd = coord[*i__ * 3 + 2] - coord[*j * 3 + 2];
    zd = coord[*i__ * 3 + 3] - coord[*j * 3 + 3];
    rxy = sqrt(xd * xd + yd * yd);
    ryz = sqrt(yd * yd + zd * zd);
    rzx = sqrt(zd * zd + xd * xd);
    for (ijk = 1; ijk <= 3; ++ijk) {
	extra_1.tx[ijk - 1] = 0.;
	extra_1.ty[ijk - 1] = 0.;
	extra_1.tz[ijk - 1] = 0.;
	derivs_1.tdx[ijk - 1] = 0.;
	derivs_1.tdy[ijk - 1] = 0.;
	derivs_1.tdz[ijk - 1] = 0.;
/* L10: */
    }
    if (rxy < 1e-4) {
/*   MOLECULAR Z AXIS IS PARALLEL TO DIATOMIC Z AXIS */
	extra_1.tx[2] = 1.;
	if (zd < 0.) {
	    extra_1.tx[2] = -1.;
	}
	extra_1.ty[1] = 1.;
	extra_1.tz[0] = extra_1.tx[2];
	if (*idx == 1) {
	    return 0;
	}
	if (*ix == 1) {
	    derivs_1.tdx[0] = 1. / *rij;
	}
	if (*ix == 2) {
	    derivs_1.tdx[1] = 1. / *rij;
	}
	if (*ix == 1) {
	    derivs_1.tdz[2] = -1. / *rij;
	}
	if (*ix == 2) {
	    derivs_1.tdy[2] = -extra_1.tx[2] / *rij;
	}
    } else if (ryz < 1e-4) {
/*   MOLECULAR X AXIS IS PARALLEL TO DIATOMIC Z AXIS */
	extra_1.tx[0] = 1.;
	if (xd < 0.) {
	    extra_1.tx[0] = -1.;
	}
	extra_1.ty[1] = extra_1.tx[0];
	extra_1.tz[2] = 1.;
	if (*idx == 1) {
	    return 0;
	}
	if (*ix == 2) {
	    derivs_1.tdx[1] = 1. / *rij;
	}
	if (*ix == 3) {
	    derivs_1.tdx[2] = 1. / *rij;
	}
	if (*ix == 2) {
	    derivs_1.tdy[0] = -1. / *rij;
	}
	if (*ix == 3) {
	    derivs_1.tdz[0] = -extra_1.tx[0] / *rij;
	}
    } else if (rzx < 1e-4) {
/*   MOLECULAR Y AXIS IS PARALLEL TO DIATOMIC Z AXIS */
	extra_1.tx[1] = 1.;
	if (yd < 0.) {
	    extra_1.tx[1] = -1.;
	}
	extra_1.ty[0] = -extra_1.tx[1];
	extra_1.tz[2] = 1.;
	if (*idx == 1) {
	    return 0;
	}
	if (*ix == 1) {
	    derivs_1.tdx[0] = 1. / *rij;
	}
	if (*ix == 3) {
	    derivs_1.tdx[2] = 1. / *rij;
	}
	if (*ix == 1) {
	    derivs_1.tdy[1] = 1. / *rij;
	}
	if (*ix == 3) {
	    derivs_1.tdz[1] = -extra_1.tx[1] / *rij;
	}
    } else {
	extra_1.tx[0] = xd / *rij;
	extra_1.tx[1] = yd / *rij;
	extra_1.tx[2] = zd / *rij;
	extra_1.tz[2] = rxy / *rij;
	extra_1.ty[0] = -extra_1.tx[1] * d_sign(&c_b3, extra_1.tx) / 
		extra_1.tz[2];
	extra_1.ty[1] = (d__1 = extra_1.tx[0] / extra_1.tz[2], abs(d__1));
	extra_1.ty[2] = 0.;
	extra_1.tz[0] = -extra_1.tx[0] * extra_1.tx[2] / extra_1.tz[2];
	extra_1.tz[1] = -extra_1.tx[1] * extra_1.tx[2] / extra_1.tz[2];
	if (*idx == 1) {
	    return 0;
	}
	term = *del1 / (*rij * *rij);
	if (*ix == 1) {
	    derivs_1.tdx[0] = 1. / *rij - extra_1.tx[0] * term;
	    derivs_1.tdx[1] = -extra_1.tx[1] * term;
	    derivs_1.tdx[2] = -extra_1.tx[2] * term;
	    derivs_1.tdz[2] = extra_1.tx[0] / rxy - extra_1.tz[2] * term;
	} else if (*ix == 2) {
	    derivs_1.tdx[0] = -extra_1.tx[0] * term;
	    derivs_1.tdx[1] = 1. / *rij - extra_1.tx[1] * term;
	    derivs_1.tdx[2] = -extra_1.tx[2] * term;
	    derivs_1.tdz[2] = extra_1.tx[1] / rxy - extra_1.tz[2] * term;
	} else if (*ix == 3) {
	    derivs_1.tdx[0] = -extra_1.tx[0] * term;
	    derivs_1.tdx[1] = -extra_1.tx[1] * term;
	    derivs_1.tdx[2] = 1. / *rij - extra_1.tx[2] * term;
	    derivs_1.tdz[2] = -extra_1.tz[2] * term;
	}
/* Computing 2nd power */
	d__1 = extra_1.tz[2];
	derivs_1.tdy[0] = -derivs_1.tdx[1] / extra_1.tz[2] + extra_1.tx[1] * 
		derivs_1.tdz[2] / (d__1 * d__1);
	if (extra_1.tx[0] < 0.) {
	    derivs_1.tdy[0] = -derivs_1.tdy[0];
	}
/* Computing 2nd power */
	d__1 = extra_1.tz[2];
	derivs_1.tdy[1] = derivs_1.tdx[0] / extra_1.tz[2] - extra_1.tx[0] * 
		derivs_1.tdz[2] / (d__1 * d__1);
	if (extra_1.tx[0] < 0.) {
	    derivs_1.tdy[1] = -derivs_1.tdy[1];
	}
	derivs_1.tdy[2] = 0.;
/* Computing 2nd power */
	d__1 = extra_1.tz[2];
	derivs_1.tdz[0] = -extra_1.tx[2] * derivs_1.tdx[0] / extra_1.tz[2] - 
		extra_1.tx[0] * derivs_1.tdx[2] / extra_1.tz[2] + extra_1.tx[
		0] * extra_1.tx[2] * derivs_1.tdz[2] / (d__1 * d__1);
/* Computing 2nd power */
	d__1 = extra_1.tz[2];
	derivs_1.tdz[1] = -extra_1.tx[2] * derivs_1.tdx[1] / extra_1.tz[2] - 
		extra_1.tx[1] * derivs_1.tdx[2] / extra_1.tz[2] + extra_1.tx[
		1] * extra_1.tx[2] * derivs_1.tdz[2] / (d__1 * d__1);
    }
    return 0;
} /* rotat_ */

