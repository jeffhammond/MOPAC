/* xyzint.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer igeook;
} geook_;

#define geook_1 geook_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Subroutine */ int xyzint_(doublereal *xyz, integer *numat, integer *na, 
	integer *nb, integer *nc, doublereal *degree, doublereal *geo)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k;
    static doublereal r__;
    static integer im1;
    static doublereal sum;
    extern /* Subroutine */ int dihed_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *), bangle_(doublereal *, 
	    integer *, integer *, integer *, doublereal *), xyzgeo_(
	    doublereal *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *);

/* ********************************************************************** */

/* XYZINT WORKS OUT THE INTERNAL COORDINATES OF A MOLECULE. */
/*        THE "RULES" FOR THE CONNECTIVITY ARE AS FOLLOWS: */
/*        ATOM I IS DEFINED AS BEING AT A DISTANCE FROM THE NEAREST */
/*        ATOM J, ATOM J ALREADY HAVING BEEN DEFINED. */
/*        ATOM I MAKES AN ANGLE WITH ATOM J AND THE ATOM K, WHICH HAS */
/*        ALREADY BEEN DEFINED, AND IS THE NEAREST ATOM TO J */
/*        ATOM I MAKES A DIHEDRAL ANGLE WITH ATOMS J, K, AND L. L HAVING */
/*        BEEN DEFINED AND IS THE NEAREST ATOM TO K, AND J, K AND L */
/*        HAVE A CONTAINED ANGLE IN THE RANGE 15 TO 165 DEGREES, */
/*        IF POSSIBLE. */

/*        IF(NA(2).EQ.-1 OR -2 THEN THE ORIGINAL CONNECTIVITY IS USED. */

/*        NOTE THAT GEO AND XYZ MUST NOT BE THE SAME IN THE CALL. */

/*   ON INPUT XYZ    = CARTESIAN ARRAY OF NUMAT ATOMS */
/*            DEGREE = 1 IF ANGLES ARE TO BE IN RADIANS */
/*            DEGREE = 57.29578 IF ANGLES ARE TO BE IN DEGREES */

/* ********************************************************************** */
    /* Parameter adjustments */
    geo -= 4;
    --nc;
    --nb;
    --na;
    xyz -= 4;

    /* Function Body */
    geook_1.igeook = 99;
    if (! (icalcn != numcal_1.numcal) && na[2] == -1 || na[2] == -2) {
	na[2] = 1;
	i__1 = *numat;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    j = na[i__];
	    if (i__ > 3) {
		dihed_(&xyz[4], &i__, &j, &nb[i__], &nc[i__], &geo[i__ * 3 + 
			3]);
	    }
	    if (i__ > 2) {
		bangle_(&xyz[4], &i__, &j, &nb[i__], &geo[i__ * 3 + 2]);
	    }
/* Computing 2nd power */
	    d__1 = xyz[i__ * 3 + 1] - xyz[j * 3 + 1];
/* Computing 2nd power */
	    d__2 = xyz[i__ * 3 + 2] - xyz[j * 3 + 2];
/* Computing 2nd power */
	    d__3 = xyz[i__ * 3 + 3] - xyz[j * 3 + 3];
	    geo[i__ * 3 + 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* L10: */
	}
    } else {
	if (na[2] == -1) {
	    icalcn = numcal_1.numcal;
	}
	i__1 = *numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    na[i__] = 2;
	    nb[i__] = 3;
	    nc[i__] = 4;
	    im1 = i__ - 1;
	    if (im1 == 0) {
		goto L30;
	    }
	    sum = 1e30;
	    i__2 = im1;
	    for (j = 1; j <= i__2; ++j) {
/* Computing 2nd power */
		d__1 = xyz[i__ * 3 + 1] - xyz[j * 3 + 1];
/* Computing 2nd power */
		d__2 = xyz[i__ * 3 + 2] - xyz[j * 3 + 2];
/* Computing 2nd power */
		d__3 = xyz[i__ * 3 + 3] - xyz[j * 3 + 3];
		r__ = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		if (r__ < sum && na[j] != j && nb[j] != j) {
		    sum = r__;
		    k = j;
		}
/* L20: */
	    }

/*   ATOM I IS NEAREST TO ATOM K */

	    na[i__] = k;
	    if (i__ > 2) {
		nb[i__] = na[k];
	    }
	    if (i__ > 3) {
		nc[i__] = nb[k];
	    }

/*   FIND ANY ATOM TO RELATE TO NA(I) */

L30:
	    ;
	}
    }
    na[1] = 0;
    nb[1] = 0;
    nc[1] = 0;
    nb[2] = 0;
    nc[2] = 0;
    nc[3] = 0;
    xyzgeo_(&xyz[4], numat, &na[1], &nb[1], &nc[1], degree, &geo[4]);
    return 0;
} /* xyzint_ */

/* Subroutine */ int xyzgeo_(doublereal *xyz, integer *numat, integer *na, 
	integer *nb, integer *nc, doublereal *degree, doublereal *geo)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal r__;
    static integer i1, ii;
    static doublereal tol, sum, angl;
    extern /* Subroutine */ int dihed_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *), bangle_(doublereal *, 
	    integer *, integer *, integer *, doublereal *);

/* ********************************************************************** */

/*   XYZGEO CONVERTS COORDINATES FROM CARTESIAN TO INTERNAL. */

/*     ON INPUT XYZ  = ARRAY OF CARTESIAN COORDINATES */
/*              NUMAT= NUMBER OF ATOMS */
/*              NA   = NUMBERS OF ATOM TO WHICH ATOMS ARE RELATED */
/*                     BY DISTANCE */
/*              NB   = NUMBERS OF ATOM TO WHICH ATOMS ARE RELATED */
/*                     BY ANGLE */
/*              NC   = NUMBERS OF ATOM TO WHICH ATOMS ARE RELATED */
/*                     BY DIHEDRAL */

/*    ON OUTPUT GEO  = INTERNAL COORDINATES IN ANGSTROMS, RADIANS, */
/*                     AND RADIANS */

/* ********************************************************************** */
    /* Parameter adjustments */
    geo -= 4;
    --nc;
    --nb;
    --na;
    xyz -= 4;

    /* Function Body */
    i__1 = *numat;
    for (i__ = 2; i__ <= i__1; ++i__) {
	j = na[i__];
	k = nb[i__];
	l = nc[i__];
	if (i__ < 3) {
	    goto L30;
	}
	ii = i__;
	bangle_(&xyz[4], &ii, &j, &k, &geo[i__ * 3 + 2]);
	geo[i__ * 3 + 2] *= *degree;
	if (i__ < 4) {
	    goto L30;
	}

/*   MAKE SURE DIHEDRAL IS MEANINGLFUL */

	bangle_(&xyz[4], &j, &k, &l, &angl);
	tol = .2617994;
	if (angl > 3.1415926 - tol || angl < tol) {

/*  ANGLE IS UNSATISFACTORY, LET'S SEARCH FOR ANOTHER ATOM FOR */
/*  DEFINING THE DIHEDRAL. */
L10:
	    sum = 100.;
	    i__2 = ii - 1;
	    for (i1 = 1; i1 <= i__2; ++i1) {
/* Computing 2nd power */
		d__1 = xyz[i1 * 3 + 1] - xyz[k * 3 + 1];
/* Computing 2nd power */
		d__2 = xyz[i1 * 3 + 2] - xyz[k * 3 + 2];
/* Computing 2nd power */
		d__3 = xyz[i1 * 3 + 3] - xyz[k * 3 + 3];
		r__ = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
		if (r__ < sum && i1 != j && i1 != k) {
		    bangle_(&xyz[4], &j, &k, &i1, &angl);
		    if (angl < 3.1415926 - tol && angl > tol) {
			sum = r__;
			l = i1;
			nc[ii] = l;
		    }
		}
/* L20: */
	    }
	    if (sum > 99. && tol > .1) {

/* ANYTHING WITHIN 5 DEGREES? */

		tol = .087266;
		goto L10;
	    }
	}
	dihed_(&xyz[4], &ii, &j, &k, &l, &geo[i__ * 3 + 3]);
	geo[i__ * 3 + 3] *= *degree;
L30:
/* Computing 2nd power */
	d__1 = xyz[i__ * 3 + 1] - xyz[j * 3 + 1];
/* Computing 2nd power */
	d__2 = xyz[i__ * 3 + 2] - xyz[j * 3 + 2];
/* Computing 2nd power */
	d__3 = xyz[i__ * 3 + 3] - xyz[j * 3 + 3];
	geo[i__ * 3 + 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    }
    geo[4] = 0.;
    geo[5] = 0.;
    geo[6] = 0.;
    geo[8] = 0.;
    geo[9] = 0.;
    geo[12] = 0.;
    return 0;
} /* xyzgeo_ */

/* Subroutine */ int bangle_(doublereal *xyz, integer *i__, integer *j, 
	integer *k, doublereal *angle)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), acos(doublereal);

    /* Local variables */
    static doublereal xy, d2ij, d2ik, d2jk, temp;

/* ******************************************************************** */

/* BANGLE CALCULATES THE ANGLE BETWEEN ATOMS I,J, AND K. THE */
/*        CARTESIAN COORDINATES ARE IN XYZ. */

/* ******************************************************************** */
    /* Parameter adjustments */
    xyz -= 4;

    /* Function Body */
/* Computing 2nd power */
    d__1 = xyz[*i__ * 3 + 1] - xyz[*j * 3 + 1];
/* Computing 2nd power */
    d__2 = xyz[*i__ * 3 + 2] - xyz[*j * 3 + 2];
/* Computing 2nd power */
    d__3 = xyz[*i__ * 3 + 3] - xyz[*j * 3 + 3];
    d2ij = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* Computing 2nd power */
    d__1 = xyz[*j * 3 + 1] - xyz[*k * 3 + 1];
/* Computing 2nd power */
    d__2 = xyz[*j * 3 + 2] - xyz[*k * 3 + 2];
/* Computing 2nd power */
    d__3 = xyz[*j * 3 + 3] - xyz[*k * 3 + 3];
    d2jk = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* Computing 2nd power */
    d__1 = xyz[*i__ * 3 + 1] - xyz[*k * 3 + 1];
/* Computing 2nd power */
    d__2 = xyz[*i__ * 3 + 2] - xyz[*k * 3 + 2];
/* Computing 2nd power */
    d__3 = xyz[*i__ * 3 + 3] - xyz[*k * 3 + 3];
    d2ik = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    xy = sqrt(d2ij * d2jk);
    temp = (d2ij + d2jk - d2ik) * .5 / xy;
    if (temp > 1.) {
	temp = 1.;
    }
    if (temp < -1.) {
	temp = -1.;
    }
    *angle = acos(temp);
    return 0;
} /* bangle_ */

/* Subroutine */ int dihed_(doublereal *xyz, integer *i__, integer *j, 
	integer *k, integer *l, doublereal *angle)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), asin(doublereal);

    /* Local variables */
    static doublereal xi1, xj1, yi1, xl1, yj1, yl1, zi1, zj1, zl1, xi2, xl2, 
	    yi2, yl2, yj2, yi3, yl3, ddd;
    extern /* Subroutine */ int dang_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *);
    static doublereal cosa, dist, cosph, costh, sinph, sinth, yxdist;

/* ******************************************************************** */

/*      DIHED CALCULATES THE DIHEDRAL ANGLE BETWEEN ATOMS I, J, K, */
/*            AND L.  THE CARTESIAN COORDINATES OF THESE ATOMS */
/*            ARE IN ARRAY XYZ. */

/*     DIHED IS A MODIFIED VERSION OF A SUBROUTINE OF THE SAME NAME */
/*           WHICH WAS WRITTEN BY DR. W. THEIL IN 1973. */

/* ******************************************************************** */
    /* Parameter adjustments */
    xyz -= 4;

    /* Function Body */
    xi1 = xyz[*i__ * 3 + 1] - xyz[*k * 3 + 1];
    xj1 = xyz[*j * 3 + 1] - xyz[*k * 3 + 1];
    xl1 = xyz[*l * 3 + 1] - xyz[*k * 3 + 1];
    yi1 = xyz[*i__ * 3 + 2] - xyz[*k * 3 + 2];
    yj1 = xyz[*j * 3 + 2] - xyz[*k * 3 + 2];
    yl1 = xyz[*l * 3 + 2] - xyz[*k * 3 + 2];
    zi1 = xyz[*i__ * 3 + 3] - xyz[*k * 3 + 3];
    zj1 = xyz[*j * 3 + 3] - xyz[*k * 3 + 3];
    zl1 = xyz[*l * 3 + 3] - xyz[*k * 3 + 3];
/*      ROTATE AROUND Z AXIS TO PUT KJ ALONG Y AXIS */
/* Computing 2nd power */
    d__1 = xj1;
/* Computing 2nd power */
    d__2 = yj1;
/* Computing 2nd power */
    d__3 = zj1;
    dist = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    cosa = zj1 / dist;
    if (cosa > 1.) {
	cosa = 1.;
    }
    if (cosa < -1.) {
	cosa = -1.;
    }
/* Computing 2nd power */
    d__1 = cosa;
    ddd = 1. - d__1 * d__1;
    if (ddd <= 0.f) {
	goto L10;
    }
    yxdist = dist * sqrt(ddd);
    if (yxdist > 1e-6) {
	goto L20;
    }
L10:
    xi2 = xi1;
    xl2 = xl1;
    yi2 = yi1;
    yl2 = yl1;
    costh = cosa;
    sinth = 0.;
    goto L30;
L20:
    cosph = yj1 / yxdist;
    sinph = xj1 / yxdist;
    xi2 = xi1 * cosph - yi1 * sinph;
    xl2 = xl1 * cosph - yl1 * sinph;
    yi2 = xi1 * sinph + yi1 * cosph;
    yj2 = xj1 * sinph + yj1 * cosph;
    yl2 = xl1 * sinph + yl1 * cosph;
/*      ROTATE KJ AROUND THE X AXIS SO KJ LIES ALONG THE Z AXIS */
    costh = cosa;
    sinth = yj2 / dist;
L30:
    yi3 = yi2 * costh - zi1 * sinth;
    yl3 = yl2 * costh - zl1 * sinth;
    dang_(&xl2, &yl3, &xi2, &yi3, angle);
    if (*angle < 0.f) {
	*angle = asin(1.) * 4. + *angle;
    }
    if (*angle >= 6.2831853) {
	*angle = 0.;
    }
    return 0;
} /* dihed_ */

/* Subroutine */ int dang_(doublereal *a1, doublereal *a2, doublereal *b1, 
	doublereal *b2, doublereal *rcos)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), acos(doublereal), asin(doublereal);

    /* Local variables */
    static doublereal zero, anorm, bnorm, costh, sinth;

/* ********************************************************************* */

/*    DANG  DETERMINES THE ANGLE BETWEEN THE POINTS (A1,A2), (0,0), */
/*          AND (B1,B2).  THE RESULT IS PUT IN RCOS. */

/* ********************************************************************* */
    zero = 1e-6;
    if (abs(*a1) < zero && abs(*a2) < zero) {
	goto L10;
    }
    if (abs(*b1) < zero && abs(*b2) < zero) {
	goto L10;
    }
/* Computing 2nd power */
    d__1 = *a1;
/* Computing 2nd power */
    d__2 = *a2;
    anorm = 1. / sqrt(d__1 * d__1 + d__2 * d__2);
/* Computing 2nd power */
    d__1 = *b1;
/* Computing 2nd power */
    d__2 = *b2;
    bnorm = 1. / sqrt(d__1 * d__1 + d__2 * d__2);
    *a1 *= anorm;
    *a2 *= anorm;
    *b1 *= bnorm;
    *b2 *= bnorm;
    sinth = *a1 * *b2 - *a2 * *b1;
    costh = *a1 * *b1 + *a2 * *b2;
    if (costh > 1.) {
	costh = 1.;
    }
    if (costh < -1.) {
	costh = -1.;
    }
    *rcos = acos(costh);
    if (abs(*rcos) < 4e-4) {
	goto L10;
    }
    if (sinth > 0.) {
	*rcos = asin(1.) * 4. - *rcos;
    }
    *rcos = -(*rcos);
    return 0;
L10:
    *rcos = 0.;
    return 0;
} /* dang_ */

