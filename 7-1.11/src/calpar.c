/* calpar.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal uss[107], upp[107], udd[107];
} onelec_;

#define onelec_1 onelec_

struct {
    doublereal eisol[107], eheat[107];
} atomic_;

#define atomic_1 atomic_

struct {
    doublereal alp[107];
} alpha_;

#define alpha_1 alpha_

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    doublereal fn1[107], fn2[107];
} gauss_;

#define gauss_1 gauss_

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
} twoele_;

#define twoele_1 twoele_

struct {
    doublereal guess1[1070]	/* was [107][10] */, guess2[1070]	/* 
	    was [107][10] */, guess3[1070]	/* was [107][10] */;
} ideas_;

#define ideas_1 ideas_

struct {
    doublereal ussm[107], uppm[107], uddm[107], zsm[107], zpm[107], zdm[107], 
	    betasm[107], betapm[107], betadm[107], alpm[107], eisolm[107], 
	    ddm[107], qqm[107], amm[107], adm[107], aqm[107], gssm[107], gspm[
	    107], gppm[107], gp2m[107], hspm[107], polvom[107];
} mndo_;

#define mndo_1 mndo_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

/* Table of constant values */

static doublereal c_b3 = .33333333333333331;
static doublereal c_b4 = .2;
static integer c__1 = 1;

/* Subroutine */ int calpar_(void)
{
    /* Initialized data */

    static integer nspqn[107] = { 1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,4,4,4,4,
	    4,4,4,4,4,4,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,
	    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    static doublereal gsdc[107] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,2.,4.,6.,5.,10.,12.,14.,16.,10.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,2.,4.,4.,5.,6.,7.,8.,0.,10.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,2.,0.,0.,0.,0.,0.,0.,2.,0.,0.,0.,0.,0.,0.,2.,4.,6.,8.,10.,12.,
	    14.,9.,10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal gddc[107] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,1.,3.,10.,10.,15.,21.,28.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,1.,6.,10.,15.,21.,28.,45.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1.,3.,6.,10.,
	    15.,21.,36.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal ussc[107] = { 1.,0.,1.,2.,2.,2.,2.,2.,2.,0.,1.,2.,2.,2.,
	    2.,2.,2.,0.,1.,2.,2.,2.,2.,1.,2.,2.,2.,2.,1.,2.,2.,2.,2.,2.,2.,0.,
	    1.,2.,2.,2.,1.,1.,2.,1.,1.,0.,1.,2.,2.,2.,2.,2.,2.,0.,1.,2.,2.,2.,
	    2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,2.,1.,1.,2.,
	    2.,2.,2.,2.,2.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0. };
    static doublereal uppc[107] = { 0.,0.,0.,0.,1.,2.,3.,4.,5.,6.,0.,0.,1.,2.,
	    3.,4.,5.,6.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1.,2.,3.,4.,5.,6.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1.,2.,3.,4.,5.,6.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    1.,2.,3.,4.,5.,6.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0. };
    static doublereal uddc[107] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,1.,2.,3.,5.,5.,6.,7.,8.,10.,10.,0.,0.,0.,0.,0.,
	    0.,0.,0.,1.,2.,4.,5.,5.,7.,8.,10.,10.,10.,0.,0.,0.,0.,0.,0.,0.,0.,
	    1.,0.,0.,0.,0.,0.,0.,1.,0.,0.,0.,0.,0.,0.,1.,2.,3.,4.,5.,6.,7.,9.,
	    10.,10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal gssc[107] = { 0.,0.,0.,1.,1.,1.,1.,1.,1.,0.,0.,1.,1.,1.,
	    1.,1.,1.,0.,0.,1.,1.,1.,1.,0.,1.,1.,1.,1.,0.,1.,1.,1.,1.,1.,1.,0.,
	    0.,1.,1.,1.,0.,0.,0.,0.,0.,0.,0.,1.,1.,1.,1.,1.,1.,0.,0.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0. };
    static doublereal gspc[107] = { 0.,0.,0.,0.,2.,4.,6.,8.,10.,0.,0.,0.,2.,
	    4.,6.,8.,10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,2.,4.,6.,8.,
	    10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,2.,4.,6.,8.,10.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,2.,4.,6.,8.,10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal hspc[107] = { 0.,0.,0.,0.,-1.,-2.,-3.,-4.,-5.,0.,0.,0.,
	    -1.,-2.,-3.,-4.,-5.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,-1.,
	    -2.,-3.,-4.,-5.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,-1.,-2.,
	    -3.,-4.,-5.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,-1.,-2.,-3.,-4.,-5.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal gp2c[107] = { 0.,0.,0.,0.,0.,1.5,4.5,6.5,10.,0.,0.,0.,
	    0.,1.5,4.5,6.5,10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1.5,
	    4.5,6.5,10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,1.5,4.5,6.5,
	    10.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,1.5,4.5,6.5,10.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal gppc[107] = { 0.,0.,0.,0.,0.,-.5,-1.5,-.5,0.,0.,0.,0.,
	    0.,-.5,-1.5,-.5,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,-.5,
	    -1.5,-.5,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,-.5,-1.5,
	    -.5,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,-.5,-1.5,-.5,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };

    /* Format strings */
    static char fmt_50[] = "(\002 \002,1x,\002OUTPUT INCLUDES DEBUG INFORMAT"
	    "ION\002,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal p, d1, d2, d3, p2, q1, p4, q2, q3, df, qf, qn, hpp, gqq,
	     gdd1, hpp1, hpp2, hsp1, hsp2;
    static integer jmax;

    /* Fortran I/O blocks */
    static cilist io___34 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___35 = { 0, 6, 0, "('C',20X,'DATA FOR ELEMENT',I3)", 0 };
    static cilist io___36 = { 0, 6, 0, "(6X,'DATA USSPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___37 = { 0, 6, 0, "(6X,'DATA UPPPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___38 = { 0, 6, 0, "(6X,'DATA UDDPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___39 = { 0, 6, 0, "(6X,'DATA BETASP(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___40 = { 0, 6, 0, "(6X,'DATA BETAPP(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___41 = { 0, 6, 0, "(6X,'DATA BETADP(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___42 = { 0, 6, 0, "(6X,'DATA ZSPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___43 = { 0, 6, 0, "(6X,'DATA ZPPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___44 = { 0, 6, 0, "(6X,'DATA ZDPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___45 = { 0, 6, 0, "(6X,'DATA ALPPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___46 = { 0, 6, 0, "(6X,'DATA EISOLP(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___47 = { 0, 6, 0, "(6X,'DATA GSSPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___48 = { 0, 6, 0, "(6X,'DATA GSPPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___49 = { 0, 6, 0, "(6X,'DATA GPPPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___50 = { 0, 6, 0, "(6X,'DATA GP2PM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___51 = { 0, 6, 0, "(6X,'DATA HSPPM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___52 = { 0, 6, 0, "(6X,'DATA DDPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___53 = { 0, 6, 0, "(6X,'DATA QQPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___54 = { 0, 6, 0, "(6X,'DATA AMPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___55 = { 0, 6, 0, "(6X,'DATA ADPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___56 = { 0, 6, 0, "(6X,'DATA AQPM3 (',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___57 = { 0, 6, 0, "(6X,'DATA FN1PM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___58 = { 0, 6, 0, "(6X,'DATA FN2PM3(',I3,')/',F16.7,'D0"
	    "/')", 0 };
    static cilist io___59 = { 0, 6, 0, "(6X,'DATA GUESP1(',I3,',',I1,')/',  "
	    "         F16.7,'D0/')", 0 };
    static cilist io___60 = { 0, 6, 0, "(6X,'DATA GUESP2(',I3,',',I1,')/',  "
	    "         F16.7,'D0/')", 0 };
    static cilist io___61 = { 0, 6, 0, "(6X,'DATA GUESP3(',I3,',',I1,')/',  "
	    "         F16.7,'D0/')", 0 };



/* THE CONTINUATION LINES INDICATE THE PRINCIPAL QUANTUM NUMBER. */

/*  The DATA block shown above is derived from the ground-state atomic */
/*  configuration of the elements.  In checking it, pay careful attention */
/*  to the actual ground-state configuration. Note also that there are no */
/*  configurations which have both p and d electrons in the valence shell */

/*     SET SCALING PARAMETER. */
    p = 2.;
    p2 = p * p;
/* Computing 4th power */
    d__1 = p, d__1 *= d__1;
    p4 = d__1 * d__1;
    for (i__ = 2; i__ <= 98; ++i__) {
	if (expont_1.zp[i__ - 1] < 1e-4 && expont_1.zs[i__ - 1] < 1e-4) {
	    goto L30;
	}
/* ********************************************************************* */

/*   CONSTRAINTS ON THE POSSIBLE VALUES OF PARAMETERS */

/* ********************************************************************* */
	if (expont_1.zp[i__ - 1] < .3) {
	    expont_1.zp[i__ - 1] = .3;
	}
/*  PUT IN ANY CONSTRAINTS AT THIS POINT */
/* ********************************************************************* */
	hpp = (twoele_1.gpp[i__ - 1] - twoele_1.gp2[i__ - 1]) * .5;
	hpp = max(.1,hpp);
/* Computing MAX */
	d__1 = 1e-7, d__2 = twoele_1.hsp[i__ - 1];
	twoele_1.hsp[i__ - 1] = max(d__1,d__2);
	atomic_1.eisol[i__ - 1] = onelec_1.uss[i__ - 1] * ussc[i__ - 1] + 
		onelec_1.upp[i__ - 1] * uppc[i__ - 1] + onelec_1.udd[i__ - 1] 
		* uddc[i__ - 1] + twoele_1.gss[i__ - 1] * gssc[i__ - 1] + 
		twoele_1.gpp[i__ - 1] * gppc[i__ - 1] + twoele_1.gsp[i__ - 1] 
		* gspc[i__ - 1] + twoele_1.gp2[i__ - 1] * gp2c[i__ - 1] + 
		twoele_1.hsp[i__ - 1] * hspc[i__ - 1] + twoele_1.gsd[i__ - 1] 
		* gsdc[i__ - 1] + twoele_1.gdd[i__ - 1] * gddc[i__ - 1];
	qn = (doublereal) nspqn[i__ - 1];
	d__1 = expont_1.zs[i__ - 1] * 4. * expont_1.zp[i__ - 1];
	d__2 = qn + .5;
	d__3 = expont_1.zs[i__ - 1] + expont_1.zp[i__ - 1];
	d__4 = qn * 2. + 2;
	multip_1.dd[i__ - 1] = (qn * 2. + 1) * pow_dd(&d__1, &d__2) / pow_dd(&
		d__3, &d__4) / sqrt(3.);
	mndo_1.ddm[i__ - 1] = multip_1.dd[i__ - 1];
	multip_1.qq[i__ - 1] = sqrt((qn * 4. * qn + qn * 6. + 2.) / 20.) / 
		expont_1.zp[i__ - 1];
	mndo_1.qqm[i__ - 1] = multip_1.qq[i__ - 1];
/*     CALCULATE ADDITIVE TERMS, IN ATOMIC UNITS. */
	jmax = 5;
/* Computing 2nd power */
	d__2 = multip_1.dd[i__ - 1];
	d__1 = p2 * twoele_1.hsp[i__ - 1] / (d__2 * d__2 * 108.84);
	gdd1 = pow_dd(&d__1, &c_b3);
/* Computing 4th power */
	d__2 = multip_1.qq[i__ - 1], d__2 *= d__2;
	d__1 = p4 * hpp / (d__2 * d__2 * 1306.0799999999999);
	gqq = pow_dd(&d__1, &c_b4);
	d1 = gdd1;
	d2 = gdd1 + .04;
	q1 = gqq;
	q2 = gqq + .04;
	i__1 = jmax;
	for (j = 1; j <= i__1; ++j) {
	    df = d2 - d1;
/* Computing 2nd power */
	    d__1 = multip_1.dd[i__ - 1];
/* Computing 2nd power */
	    d__2 = d1;
	    hsp1 = d1 * 2. - 2. / sqrt(d__1 * d__1 * 4. + 1. / (d__2 * d__2));
/* Computing 2nd power */
	    d__1 = multip_1.dd[i__ - 1];
/* Computing 2nd power */
	    d__2 = d2;
	    hsp2 = d2 * 2. - 2. / sqrt(d__1 * d__1 * 4. + 1. / (d__2 * d__2));
	    hsp1 /= p2;
	    hsp2 /= p2;
	    d3 = d1 + df * (twoele_1.hsp[i__ - 1] / 27.21 - hsp1) / (hsp2 - 
		    hsp1);
	    d1 = d2;
	    d2 = d3;
/* L10: */
	}
	i__1 = jmax;
	for (j = 1; j <= i__1; ++j) {
	    qf = q2 - q1;
/* Computing 2nd power */
	    d__1 = multip_1.qq[i__ - 1];
/* Computing 2nd power */
	    d__2 = q1;
/* Computing 2nd power */
	    d__3 = multip_1.qq[i__ - 1];
/* Computing 2nd power */
	    d__4 = q1;
	    hpp1 = q1 * 4. - 8. / sqrt(d__1 * d__1 * 4. + 1. / (d__2 * d__2)) 
		    + 4. / sqrt(d__3 * d__3 * 8. + 1. / (d__4 * d__4));
/* Computing 2nd power */
	    d__1 = multip_1.qq[i__ - 1];
/* Computing 2nd power */
	    d__2 = q2;
/* Computing 2nd power */
	    d__3 = multip_1.qq[i__ - 1];
/* Computing 2nd power */
	    d__4 = q2;
	    hpp2 = q2 * 4. - 8. / sqrt(d__1 * d__1 * 4. + 1. / (d__2 * d__2)) 
		    + 4. / sqrt(d__3 * d__3 * 8. + 1. / (d__4 * d__4));
	    hpp1 /= p4;
	    hpp2 /= p4;
	    q3 = q1 + qf * (hpp / 27.21 - hpp1) / (hpp2 - hpp1);
	    q1 = q2;
	    q2 = q3;
/* L20: */
	}
	multip_1.am[i__ - 1] = twoele_1.gss[i__ - 1] / 27.21;
	multip_1.ad[i__ - 1] = d2;
	multip_1.aq[i__ - 1] = q2;
	mndo_1.amm[i__ - 1] = multip_1.am[i__ - 1];
	mndo_1.adm[i__ - 1] = multip_1.ad[i__ - 1];
	mndo_1.aqm[i__ - 1] = multip_1.aq[i__ - 1];
L30:
	;
    }
    atomic_1.eisol[0] = onelec_1.uss[0];
    multip_1.am[0] = twoele_1.gss[0] / 27.21;
    multip_1.ad[0] = multip_1.am[0];
    multip_1.aq[0] = multip_1.am[0];
    mndo_1.amm[0] = multip_1.am[0];
    mndo_1.adm[0] = multip_1.ad[0];
    mndo_1.aqm[0] = multip_1.aq[0];

/*     DEBUG PRINTING. */
/*     THIS IS FORMATTED FOR DIRECT INSERTION INTO 'PARAM' */

    if (i_indx(keywrd_1.keywrd, "DEP", (ftnlen)241, (ftnlen)3) == 0) {
	return 0;
    }
    s_wsfe(&io___34);
    e_wsfe();
    for (i__ = 1; i__ <= 107; ++i__) {
	if (expont_1.zs[i__ - 1] == 0.) {
	    goto L60;
	}
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___36);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&onelec_1.uss[i__ - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	if (onelec_1.upp[i__ - 1] != 0.) {
	    s_wsfe(&io___37);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&onelec_1.upp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (onelec_1.udd[i__ - 1] != 0.) {
	    s_wsfe(&io___38);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&onelec_1.udd[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (betas_1.betas[i__ - 1] != 0.) {
	    s_wsfe(&io___39);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&betas_1.betas[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (betas_1.betap[i__ - 1] != 0.) {
	    s_wsfe(&io___40);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&betas_1.betap[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (betas_1.betad[i__ - 1] != 0.) {
	    s_wsfe(&io___41);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&betas_1.betad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___42);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&expont_1.zs[i__ - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	if (expont_1.zp[i__ - 1] != 0.) {
	    s_wsfe(&io___43);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&expont_1.zp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (expont_1.zd[i__ - 1] != 0.) {
	    s_wsfe(&io___44);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&expont_1.zd[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___45);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&alpha_1.alp[i__ - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	s_wsfe(&io___46);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&atomic_1.eisol[i__ - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	if (twoele_1.gss[i__ - 1] != 0.) {
	    s_wsfe(&io___47);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&twoele_1.gss[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (twoele_1.gsp[i__ - 1] != 0.) {
	    s_wsfe(&io___48);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&twoele_1.gsp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (twoele_1.gpp[i__ - 1] != 0.) {
	    s_wsfe(&io___49);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&twoele_1.gpp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (twoele_1.gp2[i__ - 1] != 0.) {
	    s_wsfe(&io___50);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&twoele_1.gp2[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (twoele_1.hsp[i__ - 1] != 0.) {
	    s_wsfe(&io___51);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&twoele_1.hsp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (multip_1.dd[i__ - 1] != 0.) {
	    s_wsfe(&io___52);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&multip_1.dd[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (multip_1.qq[i__ - 1] != 0.) {
	    s_wsfe(&io___53);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&multip_1.qq[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___54);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&multip_1.am[i__ - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	if (multip_1.ad[i__ - 1] != 0.) {
	    s_wsfe(&io___55);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&multip_1.ad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (multip_1.aq[i__ - 1] != 0.) {
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&multip_1.aq[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (gauss_1.fn1[i__ - 1] != 0.) {
	    s_wsfe(&io___57);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&gauss_1.fn1[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	if (gauss_1.fn2[i__ - 1] != 0.) {
	    s_wsfe(&io___58);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&gauss_1.fn2[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	for (j = 1; j <= 10; ++j) {
	    if (ideas_1.guess1[i__ + j * 107 - 108] == 0.) {
		goto L40;
	    }
	    s_wsfe(&io___59);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ideas_1.guess1[i__ + j * 107 - 108], (
		    ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___60);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ideas_1.guess2[i__ + j * 107 - 108], (
		    ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___61);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ideas_1.guess3[i__ + j * 107 - 108], (
		    ftnlen)sizeof(doublereal));
	    e_wsfe();
L40:
	    ;
	}
L60:
	;
    }
    return 0;
} /* calpar_ */

