/* update.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal ussm[107], uppm[107], uddm[107], zsm[107], zpm[107], zdm[107], 
	    betasm[107], betapm[107], betadm[107], alpm[107], eisolm[107], 
	    ddm[107], qqm[107], amm[107], adm[107], aqm[107], gssm[107], gspm[
	    107], gppm[107], gp2m[107], hspm[107], polvom[107];
} mndo_;

#define mndo_1 mndo_

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct {
    doublereal vs[107], vp[107], vd[107];
} vsips_;

#define vsips_1 vsips_

struct {
    doublereal uss[107], upp[107], udd[107];
} onelec_;

#define onelec_1 onelec_

struct {
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

struct {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
} twoele_;

#define twoele_1 twoele_

struct {
    doublereal alp[107];
} alpha_;

#define alpha_1 alpha_

struct {
    doublereal guess1[1070]	/* was [107][10] */, guess2[1070]	/* 
	    was [107][10] */, guess3[1070]	/* was [107][10] */;
} ideas_;

#define ideas_1 ideas_

struct {
    doublereal fn1[107], fn2[107];
} gauss_;

#define gauss_1 gauss_

/* Subroutine */ int update_(integer *iparam, integer *ielmnt, doublereal *
	param, integer *kfn)
{
    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, "(///10X,' UNACCEPTABLE VALUE FOR NO. "
	    "OF ORBITALS',  ' ON ATOM')", 0 };


/* *********************************************************************** */

/*  UPDATE UPDATES THE COMMON BLOCKS WHICH HOLD ALL THE PARAMETERS FOR */
/*         RUNNING MNDO. */
/*         IPARAM REFERS TO THE TYPE OF PARAMETER, */
/*         IELMNT REFERS TO THE ELEMENT, */
/*         PARAM IS THE VALUE OF THE PARAMETER, AND */

/* *********************************************************************** */
    switch (*iparam) {
	case 1:  goto L10;
	case 2:  goto L20;
	case 3:  goto L30;
	case 4:  goto L40;
	case 5:  goto L50;
	case 6:  goto L60;
	case 7:  goto L70;
	case 8:  goto L80;
	case 9:  goto L90;
	case 10:  goto L100;
	case 11:  goto L110;
	case 12:  goto L120;
	case 13:  goto L130;
	case 14:  goto L140;
	case 15:  goto L150;
	case 16:  goto L160;
	case 17:  goto L170;
	case 18:  goto L180;
	case 19:  goto L190;
	case 20:  goto L200;
	case 21:  goto L210;
	case 22:  goto L220;
	case 23:  goto L230;
	case 24:  goto L240;
	case 25:  goto L250;
    }
L10:
    onelec_1.uss[*ielmnt - 1] = *param;
    mndo_1.ussm[*ielmnt - 1] = *param;
    return 0;
L20:
    onelec_1.upp[*ielmnt - 1] = *param;
    mndo_1.uppm[*ielmnt - 1] = *param;
    return 0;
L30:
    onelec_1.udd[*ielmnt - 1] = *param;
    mndo_1.uddm[*ielmnt - 1] = *param;
    return 0;
L40:
    expont_1.zs[*ielmnt - 1] = *param;
    mndo_1.zsm[*ielmnt - 1] = *param;
    return 0;
L50:
    expont_1.zp[*ielmnt - 1] = *param;
    mndo_1.zpm[*ielmnt - 1] = *param;
    return 0;
L60:
    expont_1.zd[*ielmnt - 1] = *param;
    mndo_1.zdm[*ielmnt - 1] = *param;
    return 0;
L70:
    betas_1.betas[*ielmnt - 1] = *param;
    mndo_1.betasm[*ielmnt - 1] = *param;
    return 0;
L80:
    betas_1.betap[*ielmnt - 1] = *param;
    mndo_1.betapm[*ielmnt - 1] = *param;
    return 0;
L90:
    betas_1.betad[*ielmnt - 1] = *param;
    mndo_1.betadm[*ielmnt - 1] = *param;
    return 0;
L100:
    twoele_1.gss[*ielmnt - 1] = *param;
    mndo_1.gssm[*ielmnt - 1] = *param;
    return 0;
L110:
    twoele_1.gsp[*ielmnt - 1] = *param;
    mndo_1.gspm[*ielmnt - 1] = *param;
    return 0;
L120:
    twoele_1.gpp[*ielmnt - 1] = *param;
    mndo_1.gppm[*ielmnt - 1] = *param;
    return 0;
L130:
    twoele_1.gp2[*ielmnt - 1] = *param;
    mndo_1.gp2m[*ielmnt - 1] = *param;
    return 0;
L140:
    twoele_1.hsp[*ielmnt - 1] = *param;
    mndo_1.hspm[*ielmnt - 1] = *param;
    return 0;
L150:
    return 0;
L160:
    return 0;
L170:
    return 0;
L180:
    alpha_1.alp[*ielmnt - 1] = *param;
    mndo_1.alpm[*ielmnt - 1] = *param;
    return 0;
L190:
    return 0;
L200:
    return 0;
L210:
    return 0;
L220:
    ideas_1.guess1[*ielmnt + *kfn * 107 - 108] = *param;
    return 0;
L230:
    ideas_1.guess2[*ielmnt + *kfn * 107 - 108] = *param;
    return 0;
L240:
    ideas_1.guess3[*ielmnt + *kfn * 107 - 108] = *param;
    return 0;
L250:
    natorb_1.natorb[*ielmnt - 1] = (integer) (*param);
    i__ = (integer) (*param + .5);
    if (i__ != 9 && i__ != 4 && i__ != 1) {
	s_wsfe(&io___2);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    return 0;
} /* update_ */

