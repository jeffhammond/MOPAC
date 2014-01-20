/* diat2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

union {
    struct {
	doublereal a[7], b[7], sa, sb, factor;
	integer isp, ips;
    } _1;
    struct {
	doublereal a[7], b[7], sdum[3];
	integer idum[2];
    } _2;
} setc_;

#define setc_1 (setc_._1)
#define setc_2 (setc_._2)

/* Table of constant values */

static doublereal c_b22 = -1.;

/* Subroutine */ int diat2_(integer *na, doublereal *esa, doublereal *epa, 
	doublereal *r12, integer *nb, doublereal *esb, doublereal *epb, 
	doublereal *s)
{
    /* Initialized data */

    static integer inmb[17] = { 1,0,2,2,3,4,5,6,7,0,8,8,8,9,10,11,12 };
    static integer iii[78] = { 1,2,4,2,4,4,2,4,4,4,2,4,4,4,4,2,4,4,4,4,4,2,4,
	    4,4,4,4,4,3,5,5,5,5,5,5,6,3,5,5,5,5,5,5,6,6,3,5,5,5,5,5,5,6,6,6,3,
	    5,5,5,5,5,5,6,6,6,6,3,5,5,5,5,5,5,6,6,6,6,6 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal d__, e;
    static integer i__, j, k;
    static doublereal w, hd;
    static integer ii;
    static doublereal td, rt3, rab;
    extern /* Subroutine */ int set_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, integer *);
    static integer jmin, jmax;
    static doublereal sroot3;

/* *********************************************************************** */

/* OVERLP CALCULATES OVERLAPS BETWEEN ATOMIC ORBITALS FOR PAIRS OF ATOMS */
/*        IT CAN HANDLE THE ORBITALS 1S, 2S, 3S, 2P, AND 3P. */

/* *********************************************************************** */
    /* Parameter adjustments */
    s -= 13;

    /* Function Body */
/*     NUMBERING CORRESPONDS TO BOND TYPE MATRIX GIVEN ABOVE */
/*      THE CODE IS */

/*     III=1      FIRST - FIRST  ROW ELEMENTS */
/*        =2      FIRST - SECOND */
/*        =3      FIRST - THIRD */
/*        =4      SECOND - SECOND */
/*        =5      SECOND - THIRD */
/*        =6      THIRD - THIRD */

/*      ASSIGNS BOND NUMBER */

/* Computing MAX */
    i__1 = inmb[(0 + (0 + (*na - 1 << 2))) / 4], i__2 = inmb[(0 + (0 + (*nb - 
	    1 << 2))) / 4];
    jmax = max(i__1,i__2);
/* Computing MIN */
    i__1 = inmb[*na - 1], i__2 = inmb[*nb - 1];
    jmin = min(i__1,i__2);
    ii = iii[jmax * (jmax - 1) / 2 + jmin - 1];
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    for (k = 1; k <= 3; ++k) {
/* L10: */
		s[i__ + (j + k * 3) * 3] = 0.;
	    }
	}
    }
    rab = *r12 / .529167;
    switch (ii) {
	case 1:  goto L20;
	case 2:  goto L30;
	case 3:  goto L40;
	case 4:  goto L50;
	case 5:  goto L60;
	case 6:  goto L70;
    }

/*     ------------------------------------------------------------------ */
/* *** THE ORDERING OF THE ELEMENTS WITHIN S IS */
/* *** S(1,1,1)=(S(B)/S(A)) */
/* *** S(1,2,1)=(P-SIGMA(B)/S(A)) */
/* *** S(2,1,1)=(S(B)/P-SIGMA(A)) */
/* *** S(2,2,1)=(P-SIGMA(B)/P-SIGMA(A)) */
/* *** S(2,2,2)=(P-PI(B)/P-PI(A)) */
/*     ------------------------------------------------------------------ */
/* *** FIRST ROW - FIRST ROW OVERLAPS */

L20:
    set_(esa, esb, na, nb, &rab, &ii);
/* Computing 3rd power */
    d__1 = setc_1.sa * setc_1.sb * rab * rab;
    s[13] = sqrt(d__1 * (d__1 * d__1)) * .25 * (setc_1.a[2] * setc_1.b[0] - 
	    setc_1.b[2] * setc_1.a[0]);
    return 0;

/* *** FIRST ROW - SECOND ROW OVERLAPS */

L30:
    set_(esa, esb, na, nb, &rab, &ii);
/* Computing 3rd power */
    d__1 = setc_1.sa;
/* Computing 5th power */
    d__2 = setc_1.sb, d__3 = d__2, d__2 *= d__2;
/* Computing 4th power */
    d__4 = rab, d__4 *= d__4;
    w = sqrt(d__1 * (d__1 * d__1) * (d__3 * (d__2 * d__2))) * (d__4 * d__4) * 
	    .125;
    s[13] = sqrt(.33333333333333331);
    s[13] = w * s[13] * (setc_1.a[3] * setc_1.b[0] - setc_1.b[3] * setc_1.a[0]
	     + setc_1.a[2] * setc_1.b[1] - setc_1.b[2] * setc_1.a[1]);
    if (*na > 1) {
	set_(epa, esb, na, nb, &rab, &ii);
    }
    if (*nb > 1) {
	set_(esa, epb, na, nb, &rab, &ii);
    }
/* Computing 3rd power */
    d__1 = setc_1.sa;
/* Computing 5th power */
    d__2 = setc_1.sb, d__3 = d__2, d__2 *= d__2;
/* Computing 4th power */
    d__4 = rab, d__4 *= d__4;
    w = sqrt(d__1 * (d__1 * d__1) * (d__3 * (d__2 * d__2))) * (d__4 * d__4) * 
	    .125;
    s[setc_1.isp + (setc_1.ips + 3) * 3] = w * (setc_1.a[2] * setc_1.b[0] - 
	    setc_1.b[2] * setc_1.a[0] + setc_1.a[3] * setc_1.b[1] - setc_1.b[
	    3] * setc_1.a[1]);
    return 0;

/* *** FIRST ROW - THIRD ROW OVERLAPS */

L40:
    set_(esa, esb, na, nb, &rab, &ii);
/* Computing 3rd power */
    d__1 = setc_1.sa;
/* Computing 7th power */
    d__2 = setc_1.sb, d__3 = d__2, d__2 *= d__2, d__3 *= d__2;
/* Computing 5th power */
    d__4 = rab, d__5 = d__4, d__4 *= d__4;
    w = sqrt(d__1 * (d__1 * d__1) * (d__3 * (d__2 * d__2)) / 7.5) * (d__5 * (
	    d__4 * d__4)) * .0625;
    sroot3 = sqrt(3.);
    s[13] = w * (setc_1.a[4] * setc_1.b[0] - setc_1.b[4] * setc_1.a[0] + (
	    setc_1.a[3] * setc_1.b[1] - setc_1.b[3] * setc_1.a[1]) * 2.) / 
	    sroot3;
    if (*na > 1) {
	set_(epa, esb, na, nb, &rab, &ii);
    }
    if (*nb > 1) {
	set_(esa, epb, na, nb, &rab, &ii);
    }
/* Computing 3rd power */
    d__1 = setc_1.sa;
/* Computing 7th power */
    d__2 = setc_1.sb, d__3 = d__2, d__2 *= d__2, d__3 *= d__2;
/* Computing 5th power */
    d__4 = rab, d__5 = d__4, d__4 *= d__4;
    w = sqrt(d__1 * (d__1 * d__1) * (d__3 * (d__2 * d__2)) / 7.5) * (d__5 * (
	    d__4 * d__4)) * .0625;
    s[setc_1.isp + (setc_1.ips + 3) * 3] = w * (setc_1.a[3] * (setc_1.b[0] + 
	    setc_1.b[2]) - setc_1.b[3] * (setc_1.a[0] + setc_1.a[2]) + 
	    setc_1.b[1] * (setc_1.a[2] + setc_1.a[4]) - setc_1.a[1] * (
	    setc_1.b[2] + setc_1.b[4]));
    return 0;

/* *** SECOND ROW - SECOND ROW OVERLAPS */

L50:
    set_(esa, esb, na, nb, &rab, &ii);
/* Computing 5th power */
    d__1 = setc_1.sa * setc_1.sb, d__2 = d__1, d__1 *= d__1;
/* Computing 5th power */
    d__3 = rab, d__4 = d__3, d__3 *= d__3;
    w = sqrt(d__2 * (d__1 * d__1)) * (d__4 * (d__3 * d__3)) * .0625;
    rt3 = 1. / sqrt(3.);
    s[13] = w * (setc_1.a[4] * setc_1.b[0] + setc_1.b[4] * setc_1.a[0] - 
	    setc_1.a[2] * 2. * setc_1.b[2]) / 3.;
    set_(esa, epb, na, nb, &rab, &ii);
    if (*na > *nb) {
	set_(epa, esb, na, nb, &rab, &ii);
    }
/* Computing 5th power */
    d__1 = setc_1.sa * setc_1.sb, d__2 = d__1, d__1 *= d__1;
/* Computing 5th power */
    d__3 = rab, d__4 = d__3, d__3 *= d__3;
    w = sqrt(d__2 * (d__1 * d__1)) * (d__4 * (d__3 * d__3)) * .0625;
    d__ = setc_1.a[3] * (setc_1.b[0] - setc_1.b[2]) - setc_1.a[1] * (setc_1.b[
	    2] - setc_1.b[4]);
    e = setc_1.b[3] * (setc_1.a[0] - setc_1.a[2]) - setc_1.b[1] * (setc_1.a[2]
	     - setc_1.a[4]);
    s[setc_1.isp + (setc_1.ips + 3) * 3] = w * rt3 * (d__ + e);
    set_(epa, esb, na, nb, &rab, &ii);
    if (*na > *nb) {
	set_(esa, epb, na, nb, &rab, &ii);
    }
/* Computing 5th power */
    d__1 = setc_1.sa * setc_1.sb, d__2 = d__1, d__1 *= d__1;
/* Computing 5th power */
    d__3 = rab, d__4 = d__3, d__3 *= d__3;
    w = sqrt(d__2 * (d__1 * d__1)) * (d__4 * (d__3 * d__3)) * .0625;
    d__ = setc_1.a[3] * (setc_1.b[0] - setc_1.b[2]) - setc_1.a[1] * (setc_1.b[
	    2] - setc_1.b[4]);
    e = setc_1.b[3] * (setc_1.a[0] - setc_1.a[2]) - setc_1.b[1] * (setc_1.a[2]
	     - setc_1.a[4]);
    s[setc_1.ips + (setc_1.isp + 3) * 3] = -w * rt3 * (e - d__);
    set_(epa, epb, na, nb, &rab, &ii);
/* Computing 5th power */
    d__1 = setc_1.sa * setc_1.sb, d__2 = d__1, d__1 *= d__1;
/* Computing 5th power */
    d__3 = rab, d__4 = d__3, d__3 *= d__3;
    w = sqrt(d__2 * (d__1 * d__1)) * (d__4 * (d__3 * d__3)) * .0625;
    s[17] = -w * (setc_1.b[2] * (setc_1.a[4] + setc_1.a[0]) - setc_1.a[2] * (
	    setc_1.b[4] + setc_1.b[0]));
    hd = .5;
    s[26] = hd * w * (setc_1.a[4] * (setc_1.b[0] - setc_1.b[2]) - setc_1.b[4] 
	    * (setc_1.a[0] - setc_1.a[2]) - setc_1.a[2] * setc_1.b[0] + 
	    setc_1.b[2] * setc_1.a[0]);
    return 0;

/* *** SECOND ROW - THIRD ROW OVERLAPS */

L60:
    set_(esa, esb, na, nb, &rab, &ii);
/* Computing 5th power */
    d__1 = setc_1.sa, d__2 = d__1, d__1 *= d__1;
/* Computing 7th power */
    d__3 = setc_1.sb, d__4 = d__3, d__3 *= d__3, d__4 *= d__3;
/* Computing 6th power */
    d__5 = rab, d__5 *= d__5;
    w = sqrt(d__2 * (d__1 * d__1) * (d__4 * (d__3 * d__3)) / 7.5) * (d__5 * (
	    d__5 * d__5)) * .03125;
    rt3 = 1. / sqrt(3.);
    td = 2.;
    s[13] = w * (setc_1.a[5] * setc_1.b[0] + setc_1.a[4] * setc_1.b[1] - td * 
	    (setc_1.a[3] * setc_1.b[2] + setc_1.a[2] * setc_1.b[3]) + 
	    setc_1.a[1] * setc_1.b[4] + setc_1.a[0] * setc_1.b[5]) / 3.;
    set_(esa, epb, na, nb, &rab, &ii);
    if (*na > *nb) {
	set_(epa, esb, na, nb, &rab, &ii);
    }
/* Computing 5th power */
    d__1 = setc_1.sa, d__2 = d__1, d__1 *= d__1;
/* Computing 7th power */
    d__3 = setc_1.sb, d__4 = d__3, d__3 *= d__3, d__4 *= d__3;
/* Computing 6th power */
    d__5 = rab, d__5 *= d__5;
    w = sqrt(d__2 * (d__1 * d__1) * (d__4 * (d__3 * d__3)) / 7.5) * (d__5 * (
	    d__5 * d__5)) * .03125;
    td = 2.;
    s[setc_1.isp + (setc_1.ips + 3) * 3] = w * rt3 * (setc_1.a[5] * setc_1.b[
	    1] + setc_1.a[4] * setc_1.b[0] - td * (setc_1.a[3] * setc_1.b[3] 
	    + setc_1.a[2] * setc_1.b[2]) + setc_1.a[1] * setc_1.b[5] + 
	    setc_1.a[0] * setc_1.b[4]);
    set_(epa, esb, na, nb, &rab, &ii);
    if (*na > *nb) {
	set_(esa, epb, na, nb, &rab, &ii);
    }
/* Computing 5th power */
    d__1 = setc_1.sa, d__2 = d__1, d__1 *= d__1;
/* Computing 7th power */
    d__3 = setc_1.sb, d__4 = d__3, d__3 *= d__3, d__4 *= d__3;
/* Computing 6th power */
    d__5 = rab, d__5 *= d__5;
    w = sqrt(d__2 * (d__1 * d__1) * (d__4 * (d__3 * d__3)) / 7.5) * (d__5 * (
	    d__5 * d__5)) * .03125;
    td = 2.;
    s[setc_1.ips + (setc_1.isp + 3) * 3] = -w * rt3 * (setc_1.a[4] * (td * 
	    setc_1.b[2] - setc_1.b[0]) - setc_1.b[4] * (td * setc_1.a[2] - 
	    setc_1.a[0]) - setc_1.a[1] * (setc_1.b[5] - td * setc_1.b[3]) + 
	    setc_1.b[1] * (setc_1.a[5] - td * setc_1.a[3]));
    set_(epa, epb, na, nb, &rab, &ii);
/* Computing 5th power */
    d__1 = setc_1.sa, d__2 = d__1, d__1 *= d__1;
/* Computing 7th power */
    d__3 = setc_1.sb, d__4 = d__3, d__3 *= d__3, d__4 *= d__3;
/* Computing 6th power */
    d__5 = rab, d__5 *= d__5;
    w = sqrt(d__2 * (d__1 * d__1) * (d__4 * (d__3 * d__3)) / 7.5) * (d__5 * (
	    d__5 * d__5)) * .03125;
    s[17] = -w * (setc_1.b[3] * (setc_1.a[0] + setc_1.a[4]) - setc_1.a[3] * (
	    setc_1.b[0] + setc_1.b[4]) + setc_1.b[2] * (setc_1.a[1] + 
	    setc_1.a[5]) - setc_1.a[2] * (setc_1.b[1] + setc_1.b[5]));
    hd = .5;
    s[26] = hd * w * (setc_1.a[5] * (setc_1.b[0] - setc_1.b[2]) - setc_1.b[5] 
	    * (setc_1.a[0] - setc_1.a[2]) + setc_1.a[4] * (setc_1.b[1] - 
	    setc_1.b[3]) - setc_1.b[4] * (setc_1.a[1] - setc_1.a[3]) - 
	    setc_1.a[3] * setc_1.b[0] + setc_1.b[3] * setc_1.a[0] - setc_1.a[
	    2] * setc_1.b[1] + setc_1.b[2] * setc_1.a[1]);
    return 0;

/* *** THIRD ROW - THIRD ROW OVERLAPS */

L70:
    set_(esa, esb, na, nb, &rab, &ii);
/* Computing 7th power */
    d__1 = setc_1.sa * setc_1.sb * rab * rab, d__2 = d__1, d__1 *= d__1, d__2 
	    *= d__1;
    w = sqrt(d__2 * (d__1 * d__1)) / 480.;
    rt3 = 1. / sqrt(3.);
    s[13] = w * (setc_1.a[6] * setc_1.b[0] - (setc_1.a[4] * setc_1.b[2] - 
	    setc_1.a[2] * setc_1.b[4]) * 3. - setc_1.a[0] * setc_1.b[6]) / 3.;
    set_(esa, epb, na, nb, &rab, &ii);
    if (*na > *nb) {
	set_(epa, esb, na, nb, &rab, &ii);
    }
/* Computing 7th power */
    d__1 = setc_1.sa * setc_1.sb * rab * rab, d__2 = d__1, d__1 *= d__1, d__2 
	    *= d__1;
    w = sqrt(d__2 * (d__1 * d__1)) / 480.;
    d__ = setc_1.a[5] * (setc_1.b[0] - setc_1.b[2]) - setc_1.a[3] * 2. * (
	    setc_1.b[2] - setc_1.b[4]) + setc_1.a[1] * (setc_1.b[4] - 
	    setc_1.b[6]);
    e = setc_1.b[5] * (setc_1.a[0] - setc_1.a[2]) - setc_1.b[3] * 2. * (
	    setc_1.a[2] - setc_1.a[4]) + setc_1.b[1] * (setc_1.a[4] - 
	    setc_1.a[6]);
    s[setc_1.isp + (setc_1.ips + 3) * 3] = w * rt3 * (d__ - e);
    set_(epa, esb, na, nb, &rab, &ii);
    if (*na > *nb) {
	set_(esa, epb, na, nb, &rab, &ii);
    }
/* Computing 7th power */
    d__1 = setc_1.sa * setc_1.sb * rab * rab, d__2 = d__1, d__1 *= d__1, d__2 
	    *= d__1;
    w = sqrt(d__2 * (d__1 * d__1)) / 480.;
    d__ = setc_1.a[5] * (setc_1.b[0] - setc_1.b[2]) - setc_1.a[3] * 2. * (
	    setc_1.b[2] - setc_1.b[4]) + setc_1.a[1] * (setc_1.b[4] - 
	    setc_1.b[6]);
    e = setc_1.b[5] * (setc_1.a[0] - setc_1.a[2]) - setc_1.b[3] * 2. * (
	    setc_1.a[2] - setc_1.a[4]) + setc_1.b[1] * (setc_1.a[4] - 
	    setc_1.a[6]);
    s[setc_1.ips + (setc_1.isp + 3) * 3] = -w * rt3 * (-d__ - e);
    set_(epa, epb, na, nb, &rab, &ii);
/* Computing 7th power */
    d__1 = setc_1.sa * setc_1.sb * rab * rab, d__2 = d__1, d__1 *= d__1, d__2 
	    *= d__1;
    w = sqrt(d__2 * (d__1 * d__1)) / 480.;
    td = 2.;
    s[17] = -w * (setc_1.a[2] * (setc_1.b[6] + td * setc_1.b[2]) - setc_1.a[4]
	     * (setc_1.b[0] + td * setc_1.b[4]) - setc_1.b[4] * setc_1.a[0] + 
	    setc_1.a[6] * setc_1.b[2]);
    hd = .5;
    s[26] = hd * w * (setc_1.a[6] * (setc_1.b[0] - setc_1.b[2]) + setc_1.b[6] 
	    * (setc_1.a[0] - setc_1.a[2]) + setc_1.a[4] * (setc_1.b[4] - 
	    setc_1.b[2] - setc_1.b[0]) + setc_1.b[4] * (setc_1.a[4] - 
	    setc_1.a[2] - setc_1.a[0]) + setc_1.a[2] * 2. * setc_1.b[2]);
    return 0;

} /* diat2_ */

/* Subroutine */ int set_(doublereal *s1, doublereal *s2, integer *na, 
	integer *nb, doublereal *rab, integer *ii)
{
    static integer j;
    static doublereal beta, alpha;
    static integer jcall;
    extern /* Subroutine */ int aintgs_(doublereal *, integer *), bintgs_(
	    doublereal *, integer *);

/* *********************************************************************** */

/*     SET IS PART OF THE OVERLAP CALCULATION, CALLED BY OVERLP. */
/*         IT CALLS AINTGS AND BINTGS */

/* *********************************************************************** */
    if (*na > *nb) {
	goto L10;
    }
    setc_1.isp = 1;
    setc_1.ips = 2;
    setc_1.sa = *s1;
    setc_1.sb = *s2;
    goto L20;
L10:
    setc_1.isp = 2;
    setc_1.ips = 1;
    setc_1.sa = *s2;
    setc_1.sb = *s1;
L20:
    j = *ii + 2;
    if (*ii > 3) {
	--j;
    }
    alpha = *rab * .5 * (setc_1.sa + setc_1.sb);
    beta = *rab * .5 * (setc_1.sb - setc_1.sa);
    jcall = j - 1;
    aintgs_(&alpha, &jcall);
    bintgs_(&beta, &jcall);
    return 0;

} /* set_ */

/* Subroutine */ int aintgs_(doublereal *x, integer *k)
{
    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double exp(doublereal);

    /* Local variables */
    static doublereal c__;
    static integer i__;

/* *********************************************************************** */

/*    AINTGS FORMS THE "A" INTEGRALS FOR THE OVERLAP CALCULATION. */

/* *********************************************************************** */
    c__ = exp(-(*x));
    setc_2.a[0] = c__ / *x;
    i__1 = *k;
    for (i__ = 1; i__ <= i__1; ++i__) {
	setc_2.a[i__] = (setc_2.a[i__ - 1] * i__ + c__) / *x;
/* L10: */
    }
    return 0;

} /* aintgs_ */

/* Subroutine */ int bintgs_(doublereal *x, integer *k)
{
    /* Initialized data */

    static doublereal fact[17] = { 1.,2.,6.,24.,120.,720.,5040.,40320.,
	    362880.,3628800.,39916800.,479001600.,6227020800.,87178291200.,
	    1.307674368e12,2.092278989e13,3.556874281e14 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double exp(doublereal), pow_di(doublereal *, integer *);

    /* Local variables */
    static integer i__, m;
    static doublereal y;
    static integer io;
    static doublereal xf, absx;
    static integer last;
    static doublereal expx, expmx;

/* ********************************************************************** */

/*     BINTGS FORMS THE "B" INTEGRALS FOR THE OVERLAP CALCULATION. */

/* ********************************************************************** */
    io = 0;
    absx = abs(*x);
    if (absx > 3.) {
	goto L40;
    }
    if (absx <= 2.) {
	goto L10;
    }
    if (*k <= 10) {
	goto L40;
    }
    last = 15;
    goto L60;
L10:
    if (absx <= 1.) {
	goto L20;
    }
    if (*k <= 7) {
	goto L40;
    }
    last = 12;
    goto L60;
L20:
    if (absx <= .5) {
	goto L30;
    }
    if (*k <= 5) {
	goto L40;
    }
    last = 7;
    goto L60;
L30:
    if (absx <= 1e-6) {
	goto L90;
    }
    last = 6;
    goto L60;
L40:
    expx = exp(*x);
    expmx = 1. / expx;
    setc_2.b[0] = (expx - expmx) / *x;
    i__1 = *k;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	setc_2.b[i__] = (i__ * setc_2.b[i__ - 1] + pow_di(&c_b22, &i__) * 
		expx - expmx) / *x;
    }
    goto L110;
L60:
    i__1 = *k;
    for (i__ = io; i__ <= i__1; ++i__) {
	y = 0.;
	i__2 = last;
	for (m = io; m <= i__2; ++m) {
	    xf = 1.;
	    if (m != 0) {
		xf = fact[m - 1];
	    }
/* L70: */
	    d__1 = -(*x);
	    y += pow_di(&d__1, &m) * ((m + i__ + 1) % 2 << 1) / (xf * (m + 
		    i__ + 1));
	}
/* L80: */
	setc_2.b[i__] = y;
    }
    goto L110;
L90:
    i__1 = *k;
    for (i__ = io; i__ <= i__1; ++i__) {
/* L100: */
	setc_2.b[i__] = ((i__ + 1) % 2 << 1) / (i__ + 1.);
    }
L110:
    return 0;

} /* bintgs_ */

