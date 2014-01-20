/* moldat.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal htype[4];
    integer nhco[80]	/* was [4][20] */, nnhco, itype;
} molmec_;

#define molmec_1 molmec_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct {
    doublereal uspd[300], pspd[300];
} molorb_;

#define molorb_1 molorb_

struct {
    doublereal vs[107], vp[107], vd[107];
} vsips_;

#define vsips_1 vsips_

struct {
    doublereal uss[107], upp[107], udd[107];
} onelec_;

#define onelec_1 onelec_

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    doublereal polvol[107];
} polvol_;

#define polvol_1 polvol_

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
    doublereal guesa1[1070]	/* was [107][10] */, guesa2[1070]	/* 
	    was [107][10] */, guesa3[1070]	/* was [107][10] */;
} ideaa_;

#define ideaa_1 ideaa_

struct {
    doublereal guess1[1070]	/* was [107][10] */, guess2[1070]	/* 
	    was [107][10] */, guess3[1070]	/* was [107][10] */;
} ideas_;

#define ideas_1 ideas_

struct {
    doublereal guesp1[1070]	/* was [107][10] */, guesp2[1070]	/* 
	    was [107][10] */, guesp3[1070]	/* was [107][10] */;
} ideap_;

#define ideap_1 ideap_

struct {
    doublereal alp[107];
} alpha_;

#define alpha_1 alpha_

struct {
    char allref[34240]	/* was [107][4] */;
} refs_;

#define refs_1 refs_

struct {
    doublereal ussm[107], uppm[107], uddm[107], zsm[107], zpm[107], zdm[107], 
	    betasm[107], betapm[107], betadm[107], alpm[107], eisolm[107], 
	    ddm[107], qqm[107], amm[107], adm[107], aqm[107], gssm[107], gspm[
	    107], gppm[107], gp2m[107], hspm[107], polvom[107];
} mndo_;

#define mndo_1 mndo_

struct {
    doublereal usspm3[107], upppm3[107], uddpm3[107], zspm3[107], zppm3[107], 
	    zdpm3[107], betasp[107], betapp[107], betadp[107], alppm3[107], 
	    eisolp[107], ddpm3[107], qqpm3[107], ampm3[107], adpm3[107], 
	    aqpm3[107], gsspm3[107], gsppm3[107], gpppm3[107], gp2pm3[107], 
	    hsppm3[107], polvop[107];
} pm3_;

#define pm3_1 pm3_

struct {
    doublereal ussam1[107], uppam1[107], uddam1[107], zsam1[107], zpam1[107], 
	    zdam1[107], betasa[107], betapa[107], betada[107], alpam1[107], 
	    eisola[107], ddam1[107], qqam1[107], amam1[107], adam1[107], 
	    aqam1[107], gssam1[107], gspam1[107], gppam1[107], gp2am1[107], 
	    hspam1[107], polvoa[107];
} am1blo_;

#define am1blo_1 am1blo_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal rxyz[45150], xdumy[84450];
} scrach_;

#define scrach_1 scrach_

struct {
    doublereal uss3[18], upp3[18];
} onele3_;

#define onele3_1 onele3_

struct {
    doublereal eisol3[18], eheat3[18];
} atomi3_;

#define atomi3_1 atomi3_

struct {
    doublereal zs3[18], zp3[18];
} expon3_;

#define expon3_1 expon3_

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    doublereal eisol[107], eheat[107];
} atomic_;

#define atomic_1 atomic_

/* Table of constant values */

static integer c__1 = 1;
static integer c__300 = 300;
static integer c_b39 = 214770;

/* Subroutine */ int moldat_(integer *mode)
{
    /* Initialized data */

    static doublereal estore[107] = { 0. };

    /* Format strings */
    static char fmt_230[] = "(//,\002   ATOMS\002,i3,\002 AND\002,i3,\002 AR"
	    "E SEPARATED BY\002,f8.4,\002 ANGSTROMS.\002,/\002   TO CONTINUE "
	    "CALCULATION SPECIFY \"GEO-OK\"\002)";
    static char fmt_240[] = "(\002   NUMBER OF REAL ATOMS:\002,i4,/,\002   N"
	    "UMBER OF ORBITALS:  \002,i4,/,\002   NUMBER OF D ORBITALS:\002,i"
	    "4,/,\002   TOTAL NO. OF ATOMS:  \002,i4)";
    static char fmt_250[] = "(\002   ONE-ELECTRON DIAGONAL TERMS\002,/,10(/,"
	    "10f8.3))";
    static char fmt_260[] = "(\002   INITIAL P FOR ALL ATOMIC ORBITALS\002,/"
	    ",10(/,10f8.3))";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer do_fio(integer *, char *, ftnlen), s_wsle(cilist *), e_wsle(void);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal w;
    static integer k1, ia, ib, ic, ii, ne, ij, ji, ni, jk, kj, kl, lk, mk, km;
    static doublereal xx, yy;
    static logical am1;
    static doublereal eat;
    static logical uhf;
    static integer n2el;
    static logical lpm3;
    static char olde[6*20];
    static logical exci;
    static doublereal rmin;
    static integer nmos;
    static logical trip;
    static integer nupp;
    static logical slow;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical halfe, birad;
    static integer ielec;
    static logical debug;
    static doublereal elecs;
    extern /* Subroutine */ int refer_(void);
    static integer msdel;
    static doublereal coord[360]	/* was [3][120] */;
    static logical lmndo;
    static integer iminr, jminr, iswap[40]	/* was [2][20] */, ndown;
    static logical mindo3;
    static integer kharge, newele, ndorbs, nheavy, nlight, ilevel, ndoubl;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *), vecprt_(
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 6, 0, "('  THE HAMILTONIAN REQUESTED IS NOT"
	    " AVAILABLE IN'  ,' THIS PROGRAM')", 0 };
    static cilist io___25 = { 0, 6, 0, "(///,A)", 0 };
    static cilist io___26 = { 0, 6, 0, "(//10X,'**** MAX. NUMBER OF ORBITALS"
	    ":',I4,/                     10X,'NUMBER OF ORBITALS IN SYSTEM:',"
	    "I4)", 0 };
    static cilist io___29 = { 0, 6, 0, "(//10X,'**** MAX. NUMBER OF TWO-ELEC"
	    "TRON INTEGRALS:',I8,/                                           "
	    "                              10X,'NUMBER OF TWO ELECTRON INTEGR"
	    "ALS IN SYSTEM:',  I8)", 0 };
    static cilist io___33 = { 0, 6, 0, "(//10X,'C.I. NOT ALLOWED WITH UHF ')",
	     0 };
    static cilist io___34 = { 0, 6, 0, "(//10X,'TRIPLET SPECIFIED WITH ODD N"
	    "UMBER',               ' OF ELECTRONS, CORRECT FAULT ')", 0 };
    static cilist io___35 = { 0, 6, 0, "(//' TRIPLET STATE CALCULATION')", 0 }
	    ;
    static cilist io___36 = { 0, 6, 0, "(//10X,'QUARTET SPECIFIED WITH EVEN "
	    "NUMBER',              ' OF ELECTRONS, CORRECT FAULT ')", 0 };
    static cilist io___37 = { 0, 6, 0, "(//' QUARTET STATE CALCULATION')", 0 }
	    ;
    static cilist io___38 = { 0, 6, 0, "(//10X,'QUINTET SPECIFIED WITH ODD N"
	    "UMBER',               ' OF ELECTRONS, CORRECT FAULT ')", 0 };
    static cilist io___39 = { 0, 6, 0, "(//' QUINTET STATE CALCULATION')", 0 }
	    ;
    static cilist io___40 = { 0, 6, 0, "(//10X,'SEXTET SPECIFIED WITH EVEN N"
	    "UMBER',               ' OF ELECTRONS, CORRECT FAULT ')", 0 };
    static cilist io___41 = { 0, 6, 0, "(//' SEXTET STATE CALCULATION')", 0 };
    static cilist io___42 = { 0, 6, 0, "(//10X,'UHF CALCULATION, NO. OF ALPH"
	    "A ELECTRONS =',I   3,/27X,'NO. OF BETA  ELECTRONS =',I3)", 0 };
    static cilist io___45 = { 0, 6, 0, "(//10X,'SYSTEM SPECIFIED WITH ODD NU"
	    "MBER',                ' OF ELECTRONS, CORRECT FAULT ')", 0 };
    static cilist io___46 = { 0, 6, 0, "(//' SYSTEM IS A BIRADICAL')", 0 };
    static cilist io___47 = { 0, 6, 0, "(//' TRIPLET STATE CALCULATION')", 0 }
	    ;
    static cilist io___48 = { 0, 6, 0, "(//' EXCITED STATE CALCULATION')", 0 }
	    ;
    static cilist io___49 = { 0, 6, 0, "(//' QUARTET STATE CALCULATION')", 0 }
	    ;
    static cilist io___50 = { 0, 6, 0, "(//' QUINTET STATE CALCULATION')", 0 }
	    ;
    static cilist io___51 = { 0, 6, 0, "(//' SEXTET STATE CALCULATION')", 0 };
    static cilist io___52 = { 0, 6, 0, "(' IMPOSSIBLE NUMBER OF OPEN SHELL E"
	    "LECTR      ONS')", 0 };
    static cilist io___53 = { 0, 6, 0, "(A)", 0 };
    static cilist io___54 = { 0, 6, 0, "(A)", 0 };
    static cilist io___55 = { 0, 6, 0, "(' THERE ARE',I3,' DOUBLY FILLED LEV"
	    "ELS')", 0 };
    static cilist io___56 = { 0, 6, 0, "(//10X,'RHF CALCULATION, NO. OF ',  "
	    "   'DOUBLY OCCUPIED LEVELS =',I3)", 0 };
    static cilist io___57 = { 0, 6, 0, "(/27X,'NO. OF SINGLY OCCUPIED LEVELS"
	    " =',I3)", 0 };
    static cilist io___58 = { 0, 6, 0, "(/27X,'NO. OF LEVELS WITH OCCUPANCY'"
	    ",F6.3,'  =',I3)", 0 };
    static cilist io___59 = { 0, 6, 0, "(//,' NUMBER OF OPEN-SHELLS ALLOWED "
	    "IN C.I. IS LESS '            /'    THAN THAT SPECIFIED BY OTHER "
	    "KEYWORDS')", 0 };
    static cilist io___66 = { 0, 6, 0, "(A)", 0 };
    static cilist io___69 = { 0, 6, 0, 0, 0 };
    static cilist io___70 = { 0, 6, 0, "(A)", 0 };
    static cilist io___89 = { 0, 6, 0, "(A)", 0 };
    static cilist io___90 = { 0, 6, 0, "(A,I2,2A)", 0 };
    static cilist io___91 = { 0, 6, 0, "(A)", 0 };
    static cilist io___92 = { 0, 6, 0, "(A)", 0 };
    static cilist io___93 = { 0, 6, 0, "(A)", 0 };
    static cilist io___94 = { 0, 6, 0, "(//10X,'  INTERATOMIC DISTANCES')", 0 
	    };
    static cilist io___95 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___96 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___97 = { 0, 6, 0, fmt_250, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___99 = { 0, 6, 0, "(//10X,' MAXIMUM NUMBER OF ATOMIC OR"
	    "BITALS EXCEEDED')", 0 };
    static cilist io___100 = { 0, 6, 0, "(  10X,' MAXIMUM ALLOWED =',I4)", 0 }
	    ;


/* COMDECK SIZES */
/* *********************************************************************** */
/*   THIS FILE CONTAINS ALL THE ARRAY SIZES FOR USE IN MOPAC. */

/*     THERE ARE ONLY 5 PARAMETERS THAT THE PROGRAMMER NEED SET: */
/*     MAXHEV = MAXIMUM NUMBER OF HEAVY ATOMS (HEAVY: NON-HYDROGEN ATOMS) */
/*     MAXLIT = MAXIMUM NUMBER OF HYDROGEN ATOMS. */
/*     MAXTIM = DEFAULT TIME FOR A JOB. (SECONDS) */
/*     MAXDMP = DEFAULT TIME FOR AUTOMATIC RESTART FILE GENERATION (SECS) */
/*     ISYBYL = 1 IF MOPAC IS TO BE USED IN THE SYBYL PACKAGE, =0 OTHERWISE */
/*     SEE ALSO NMECI, NPULAY AND MESP AT THE END OF THIS FILE */


/* *********************************************************************** */

/*   THE FOLLOWING CODE DOES NOT NEED TO BE ALTERED BY THE PROGRAMMER */

/* *********************************************************************** */

/*    ALL OTHER PARAMETERS ARE DERIVED FUNCTIONS OF THESE TWO PARAMETERS */

/*      NAME                   DEFINITION */
/*     NUMATM         MAXIMUM NUMBER OF ATOMS ALLOWED. */
/*     MAXORB         MAXIMUM NUMBER OF ORBITALS ALLOWED. */
/*     MAXPAR         MAXIMUM NUMBER OF PARAMETERS FOR OPTIMISATION. */
/*     N2ELEC         MAXIMUM NUMBER OF TWO ELECTRON INTEGRALS ALLOWED. */
/*     MPACK          AREA OF LOWER HALF TRIANGLE OF DENSITY MATRIX. */
/*     MORB2          SQUARE OF THE MAXIMUM NUMBER OF ORBITALS ALLOWED. */
/*     MAXHES         AREA OF HESSIAN MATRIX */
/*     MAXALL         LARGER THAN MAXORB OR MAXPAR. */
/* *********************************************************************** */

/* *********************************************************************** */
/* DECK MOPAC */

/*  COMMON BLOCKS FOR MINDO/3 */


/*  END OF MINDO/3 COMMON BLOCKS */

    if (estore[0] == 0.) {
	for (i__ = 1; i__ <= 107; ++i__) {
/* L9: */
	    estore[i__ - 1] = atomic_1.eheat[i__ - 1];
	}
    }
    for (i__ = 1; i__ <= 107; ++i__) {
/* L8: */
	atomic_1.eheat[i__ - 1] = estore[i__ - 1];
    }
    debug = i_indx(keywrd_1.keywrd, "MOLDAT", (ftnlen)241, (ftnlen)6) != 0;
    lpm3 = i_indx(keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0;
    mindo3 = i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0;
    uhf = i_indx(keywrd_1.keywrd, "UHF", (ftnlen)241, (ftnlen)3) != 0;
    am1 = i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0;
    lmndo = ! am1 && ! lpm3;
    kharge = 0;
    i__ = i_indx(keywrd_1.keywrd, "CHARGE", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	kharge = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    elecs = (doublereal) (-kharge);
    ndorbs = 0;
    atheat_1.atheat = 0.;
    eat = 0.;
    molkst_1.numat = 0;
    if (*mode == 1) {
	goto L80;
    }
    if (lmndo) {

/*    SWITCH IN MNDO PARAMETERS */


/*       ZERO OUT GAUSSIAN 1 FOR CARBON.  THIS WILL BE USED IN */
/*       ROTATE TO DECIDE WHETHER OR NOT TO USE AM1-TYPE GAUSSIANS */

	ideas_1.guess1[5] = 0.;
	for (i__ = 1; i__ <= 107; ++i__) {
	    if (! mindo3) {
		polvol_1.polvol[i__ - 1] = mndo_1.polvom[i__ - 1];
	    }
	    expont_1.zs[i__ - 1] = mndo_1.zsm[i__ - 1];
	    expont_1.zp[i__ - 1] = mndo_1.zpm[i__ - 1];
	    expont_1.zd[i__ - 1] = mndo_1.zdm[i__ - 1];
	    onelec_1.uss[i__ - 1] = mndo_1.ussm[i__ - 1];
	    onelec_1.upp[i__ - 1] = mndo_1.uppm[i__ - 1];
	    onelec_1.udd[i__ - 1] = mndo_1.uddm[i__ - 1];
	    betas_1.betas[i__ - 1] = mndo_1.betasm[i__ - 1];
	    betas_1.betap[i__ - 1] = mndo_1.betapm[i__ - 1];
	    betas_1.betad[i__ - 1] = mndo_1.betadm[i__ - 1];
	    alpha_1.alp[i__ - 1] = mndo_1.alpm[i__ - 1];
	    atomic_1.eisol[i__ - 1] = mndo_1.eisolm[i__ - 1];
	    multip_1.dd[i__ - 1] = mndo_1.ddm[i__ - 1];
	    multip_1.qq[i__ - 1] = mndo_1.qqm[i__ - 1];
	    multip_1.am[i__ - 1] = mndo_1.amm[i__ - 1];
	    multip_1.ad[i__ - 1] = mndo_1.adm[i__ - 1];
	    multip_1.aq[i__ - 1] = mndo_1.aqm[i__ - 1];
	    twoele_1.gss[i__ - 1] = mndo_1.gssm[i__ - 1];
	    twoele_1.gpp[i__ - 1] = mndo_1.gppm[i__ - 1];
	    twoele_1.gsp[i__ - 1] = mndo_1.gspm[i__ - 1];
	    twoele_1.gp2[i__ - 1] = mndo_1.gp2m[i__ - 1];
	    twoele_1.hsp[i__ - 1] = mndo_1.hspm[i__ - 1];
/* L10: */
	}
    } else if (lpm3) {

/*    SWITCH IN MNDO-PM3 PARAMETERS */

	for (i__ = 1; i__ <= 107; ++i__) {
	    for (j = 1; j <= 10; ++j) {
		ideas_1.guess1[i__ + j * 107 - 108] = ideap_1.guesp1[i__ + j *
			 107 - 108];
		ideas_1.guess2[i__ + j * 107 - 108] = ideap_1.guesp2[i__ + j *
			 107 - 108];
/* L20: */
		ideas_1.guess3[i__ + j * 107 - 108] = ideap_1.guesp3[i__ + j *
			 107 - 108];
	    }
	    polvol_1.polvol[i__ - 1] = pm3_1.polvop[i__ - 1];
	    expont_1.zs[i__ - 1] = pm3_1.zspm3[i__ - 1];
	    expont_1.zp[i__ - 1] = pm3_1.zppm3[i__ - 1];
	    expont_1.zd[i__ - 1] = pm3_1.zdpm3[i__ - 1];
	    onelec_1.uss[i__ - 1] = pm3_1.usspm3[i__ - 1];
	    onelec_1.upp[i__ - 1] = pm3_1.upppm3[i__ - 1];
	    onelec_1.udd[i__ - 1] = pm3_1.uddpm3[i__ - 1];
	    betas_1.betas[i__ - 1] = pm3_1.betasp[i__ - 1];
	    betas_1.betap[i__ - 1] = pm3_1.betapp[i__ - 1];
	    betas_1.betad[i__ - 1] = pm3_1.betadp[i__ - 1];
	    alpha_1.alp[i__ - 1] = pm3_1.alppm3[i__ - 1];
	    atomic_1.eisol[i__ - 1] = pm3_1.eisolp[i__ - 1];
	    multip_1.dd[i__ - 1] = pm3_1.ddpm3[i__ - 1];
	    multip_1.qq[i__ - 1] = pm3_1.qqpm3[i__ - 1];
	    multip_1.am[i__ - 1] = pm3_1.ampm3[i__ - 1];
	    multip_1.ad[i__ - 1] = pm3_1.adpm3[i__ - 1];
	    multip_1.aq[i__ - 1] = pm3_1.aqpm3[i__ - 1];
	    twoele_1.gss[i__ - 1] = pm3_1.gsspm3[i__ - 1];
	    twoele_1.gpp[i__ - 1] = pm3_1.gpppm3[i__ - 1];
	    twoele_1.gsp[i__ - 1] = pm3_1.gsppm3[i__ - 1];
	    twoele_1.gp2[i__ - 1] = pm3_1.gp2pm3[i__ - 1];
	    twoele_1.hsp[i__ - 1] = pm3_1.hsppm3[i__ - 1];
/* L30: */
	}
    } else {

/*    SWITCH IN AM1 PARAMETERS */

	for (i__ = 1; i__ <= 107; ++i__) {
	    for (j = 1; j <= 10; ++j) {
		ideas_1.guess1[i__ + j * 107 - 108] = ideaa_1.guesa1[i__ + j *
			 107 - 108];
		ideas_1.guess2[i__ + j * 107 - 108] = ideaa_1.guesa2[i__ + j *
			 107 - 108];
/* L40: */
		ideas_1.guess3[i__ + j * 107 - 108] = ideaa_1.guesa3[i__ + j *
			 107 - 108];
	    }
	    polvol_1.polvol[i__ - 1] = am1blo_1.polvoa[i__ - 1];
	    expont_1.zs[i__ - 1] = am1blo_1.zsam1[i__ - 1];
	    expont_1.zp[i__ - 1] = am1blo_1.zpam1[i__ - 1];
	    expont_1.zd[i__ - 1] = am1blo_1.zdam1[i__ - 1];
	    onelec_1.uss[i__ - 1] = am1blo_1.ussam1[i__ - 1];
	    onelec_1.upp[i__ - 1] = am1blo_1.uppam1[i__ - 1];
	    onelec_1.udd[i__ - 1] = am1blo_1.uddam1[i__ - 1];
	    betas_1.betas[i__ - 1] = am1blo_1.betasa[i__ - 1];
	    betas_1.betap[i__ - 1] = am1blo_1.betapa[i__ - 1];
	    betas_1.betad[i__ - 1] = am1blo_1.betada[i__ - 1];
	    alpha_1.alp[i__ - 1] = am1blo_1.alpam1[i__ - 1];
	    atomic_1.eisol[i__ - 1] = am1blo_1.eisola[i__ - 1];
	    multip_1.dd[i__ - 1] = am1blo_1.ddam1[i__ - 1];
	    multip_1.qq[i__ - 1] = am1blo_1.qqam1[i__ - 1];
	    multip_1.am[i__ - 1] = am1blo_1.amam1[i__ - 1];
	    multip_1.ad[i__ - 1] = am1blo_1.adam1[i__ - 1];
	    multip_1.aq[i__ - 1] = am1blo_1.aqam1[i__ - 1];
	    twoele_1.gss[i__ - 1] = am1blo_1.gssam1[i__ - 1];
	    twoele_1.gpp[i__ - 1] = am1blo_1.gppam1[i__ - 1];
	    twoele_1.gsp[i__ - 1] = am1blo_1.gspam1[i__ - 1];
	    twoele_1.gp2[i__ - 1] = am1blo_1.gp2am1[i__ - 1];
	    twoele_1.hsp[i__ - 1] = am1blo_1.hspam1[i__ - 1];
/* L50: */
	}
    }

/*        SWAP IN OLD PARAMETERS FOR ELEMENTS.  OLDE CONTAINS THE */
/*        CHARACTER NAME OF THE ELEMENT, AND ISWAP(1,1:NEWELE) CONTAINS */
/*        THE ATOMIC NUMBER OF THE ELEMENT. ISWAP(2,1:NEWELE) CONTAINS */
/*        THE STORAGE ADDRESS OF THE OLD SET OF PARAMETERS. */

    newele = 2;
    s_copy(olde, " S1978", (ftnlen)6, (ftnlen)6);
    iswap[0] = 16;
    iswap[1] = 91;
    s_copy(olde + 6, "SI1978", (ftnlen)6, (ftnlen)6);
    iswap[2] = 14;
    iswap[3] = 90;
/* $DOIT ASIS */
    i__1 = newele;
    for (k = 1; k <= i__1; ++k) {
	if (i_indx(keywrd_1.keywrd, olde + (k - 1) * 6, (ftnlen)241, (ftnlen)
		6) != 0) {
	    i__ = iswap[(k << 1) - 2];
	    j = iswap[(k << 1) - 1];
	    s_copy(refs_1.allref + (i__ + 213) * 80, refs_1.allref + (j - 1) *
		     80, (ftnlen)80, (ftnlen)80);
	    s_copy(refs_1.allref + (i__ - 1) * 80, refs_1.allref + (j - 1) * 
		    80, (ftnlen)80, (ftnlen)80);
	    expont_1.zs[i__ - 1] = expont_1.zs[j - 1];
	    expont_1.zp[i__ - 1] = expont_1.zp[j - 1];
	    expont_1.zd[i__ - 1] = expont_1.zd[j - 1];
	    onelec_1.uss[i__ - 1] = onelec_1.uss[j - 1];
	    onelec_1.upp[i__ - 1] = onelec_1.upp[j - 1];
	    onelec_1.udd[i__ - 1] = onelec_1.udd[j - 1];
	    betas_1.betas[i__ - 1] = betas_1.betas[j - 1];
	    betas_1.betap[i__ - 1] = betas_1.betap[j - 1];
	    betas_1.betad[i__ - 1] = betas_1.betad[j - 1];
	    alpha_1.alp[i__ - 1] = alpha_1.alp[j - 1];
	    atomic_1.eisol[i__ - 1] = atomic_1.eisol[j - 1];
	    multip_1.dd[i__ - 1] = multip_1.dd[j - 1];
	    multip_1.qq[i__ - 1] = multip_1.qq[j - 1];
	    multip_1.am[i__ - 1] = multip_1.am[j - 1];
	    multip_1.ad[i__ - 1] = multip_1.ad[j - 1];
	    multip_1.aq[i__ - 1] = multip_1.aq[j - 1];
	    if (twoele_1.gss[j - 1] != 0.) {
		twoele_1.gss[i__ - 1] = twoele_1.gss[j - 1];
	    }
	    if (twoele_1.gpp[j - 1] != 0.) {
		twoele_1.gpp[i__ - 1] = twoele_1.gpp[j - 1];
	    }
	    if (twoele_1.gsp[j - 1] != 0.) {
		twoele_1.gsp[i__ - 1] = twoele_1.gsp[j - 1];
	    }
	    if (twoele_1.gp2[j - 1] != 0.) {
		twoele_1.gp2[i__ - 1] = twoele_1.gp2[j - 1];
	    }
	    if (twoele_1.hsp[j - 1] != 0.) {
		twoele_1.hsp[i__ - 1] = twoele_1.hsp[j - 1];
	    }
	}
/* L60: */
    }
    if (mindo3) {
	for (i__ = 1; i__ <= 17; ++i__) {
	    if (i__ != 2 && i__ != 10) {
		onelec_1.uss[i__ - 1] = onele3_1.uss3[i__ - 1];
		onelec_1.upp[i__ - 1] = onele3_1.upp3[i__ - 1];
		atomic_1.eisol[i__ - 1] = atomi3_1.eisol3[i__ - 1];
		atomic_1.eheat[i__ - 1] = atomi3_1.eheat3[i__ - 1];
		expont_1.zs[i__ - 1] = expon3_1.zs3[i__ - 1];
		expont_1.zp[i__ - 1] = expon3_1.zp3[i__ - 1];
		twoele_1.gss[i__ - 1] = mndo_1.gssm[i__ - 1];
		twoele_1.gpp[i__ - 1] = mndo_1.gppm[i__ - 1];
		twoele_1.gsp[i__ - 1] = mndo_1.gspm[i__ - 1];
		twoele_1.gp2[i__ - 1] = mndo_1.gp2m[i__ - 1];
		twoele_1.hsp[i__ - 1] = mndo_1.hspm[i__ - 1];
	    }
/* L70: */
	}
    }
L80:
    if (onelec_1.uss[0] > -1.) {
	s_wsfe(&io___18);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    ia = 1;
    ib = 0;
    nheavy = 0;
    i__1 = geokst_1.natoms;
    for (ii = 1; ii <= i__1; ++ii) {
	if (geokst_1.labels[ii - 1] == 99 || geokst_1.labels[ii - 1] == 107) {
	    goto L130;
	}
	++molkst_1.numat;
	molkst_1.nat[molkst_1.numat - 1] = geokst_1.labels[ii - 1];
	molkst_1.nfirst[molkst_1.numat - 1] = ia;
	ni = molkst_1.nat[molkst_1.numat - 1];
	atheat_1.atheat += atomic_1.eheat[ni - 1];
	eat += atomic_1.eisol[ni - 1];
	elecs += core_1.core[ni - 1];
	ib = ia + natorb_1.natorb[ni - 1] - 1;
	molkst_1.nmidle[molkst_1.numat - 1] = ib;
	if (natorb_1.natorb[ni - 1] == 9) {
	    ndorbs += 5;
	}
	if (natorb_1.natorb[ni - 1] == 9) {
	    molkst_1.nmidle[molkst_1.numat - 1] = ia + 3;
	}
	molkst_1.nlast[molkst_1.numat - 1] = ib;
	if (ia > 300) {
	    goto L270;
	}
	molorb_1.uspd[ia - 1] = onelec_1.uss[ni - 1];
	if (ia == ib) {
	    goto L120;
	}
	k = ia + 1;
	k1 = ia + 3;
/* $DOIT ASIS */
	i__2 = k1;
	for (j = k; j <= i__2; ++j) {
	    if (j > 300) {
		goto L270;
	    }
	    molorb_1.uspd[j - 1] = onelec_1.upp[ni - 1];
/* L90: */
	}
	++nheavy;
/* L100: */
	if (k1 == ib) {
	    goto L120;
	}
	k = k1 + 1;
/* $DOIT ASIS */
	i__2 = ib;
	for (j = k; j <= i__2; ++j) {
/* L110: */
	    molorb_1.uspd[j - 1] = onelec_1.udd[ni - 1];
	}
L120:
L130:
	ia = ib + 1;
    }
    if (molkst_1.numat == 1) {
	if (i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0) {
	    s_wsfe(&io___25);
	    do_fio(&c__1, "      A SINGLE ATOM HAS NO VIBRATIONAL MODES", (
		    ftnlen)44);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
    if (*mode != 1) {
	refer_();
    }
    atheat_1.atheat -= eat * 23.061;
    molkst_1.norbs = molkst_1.nlast[molkst_1.numat - 1];
    if (molkst_1.norbs > 300) {
	s_wsfe(&io___26);
	do_fio(&c__1, (char *)&c__300, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&molkst_1.norbs, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    nlight = molkst_1.numat - nheavy;
    n2el = nheavy * 50 * (nheavy - 1) + nheavy * 10 * nlight + nlight * (
	    nlight - 1) / 2;
    if (n2el > 214770) {
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&c_b39, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&n2el, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*   NOW TO CALCULATE THE NUMBER OF LEVELS OCCUPIED */
    trip = i_indx(keywrd_1.keywrd, "TRIP", (ftnlen)241, (ftnlen)4) != 0;
    exci = i_indx(keywrd_1.keywrd, "EXCI", (ftnlen)241, (ftnlen)4) != 0;
    birad = exci || i_indx(keywrd_1.keywrd, "BIRAD", (ftnlen)241, (ftnlen)5) 
	    != 0;
    if (i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)241, (ftnlen)4) != 0 && uhf) {
	s_wsfe(&io___33);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/* NOW TO WORK OUT HOW MANY ELECTRONS ARE IN EACH TYPE OF SHELL */

    molkst_1.nalpha = 0;
    molkst_1.nbeta = 0;

/*      PROTECT DUMB USERS FROM DUMB ERRORS! */

/* Computing MAX */
    d__1 = elecs + .5;
    molkst_1.nelecs = (integer) max(d__1,0.);
/* Computing MIN */
    i__1 = molkst_1.norbs << 1;
    molkst_1.nelecs = min(i__1,molkst_1.nelecs);
    molkst_1.nclose = 0;
    molkst_1.nopen = 0;
    if (uhf) {
	molkst_1.fract = 1.;
	molkst_1.nbeta = molkst_1.nelecs / 2;
	if (trip) {
	    if (molkst_1.nbeta << 1 != molkst_1.nelecs) {
		s_wsfe(&io___34);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    } else {
		if (*mode != 1) {
		    s_wsfe(&io___35);
		    e_wsfe();
		}
		--molkst_1.nbeta;
	    }
	}
	if (i_indx(keywrd_1.keywrd, "QUAR", (ftnlen)241, (ftnlen)4) != 0) {
	    if (molkst_1.nbeta << 1 == molkst_1.nelecs) {
		s_wsfe(&io___36);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    } else {
		if (*mode != 1) {
		    s_wsfe(&io___37);
		    e_wsfe();
		}
		--molkst_1.nbeta;
	    }
	}
	if (i_indx(keywrd_1.keywrd, "QUIN", (ftnlen)241, (ftnlen)4) != 0) {
	    if (molkst_1.nbeta << 1 != molkst_1.nelecs) {
		s_wsfe(&io___38);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    } else {
		if (*mode != 1) {
		    s_wsfe(&io___39);
		    e_wsfe();
		}
		molkst_1.nbeta += -2;
	    }
	}
	if (i_indx(keywrd_1.keywrd, "SEXT", (ftnlen)241, (ftnlen)4) != 0) {
	    if (molkst_1.nbeta << 1 == molkst_1.nelecs) {
		s_wsfe(&io___40);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    } else {
		if (*mode != 1) {
		    s_wsfe(&io___41);
		    e_wsfe();
		}
		molkst_1.nbeta += -2;
	    }
	}
	molkst_1.nalpha = molkst_1.nelecs - molkst_1.nbeta;
	if (*mode != 1) {
	    s_wsfe(&io___42);
	    do_fio(&c__1, (char *)&molkst_1.nalpha, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nbeta, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    } else {

/*   NOW TO DETERMINE OPEN AND CLOSED SHELLS */

	ielec = 0;
	ilevel = 0;
	if (trip || exci || birad) {
	    if (molkst_1.nelecs / 2 << 1 != molkst_1.nelecs) {
		s_wsfe(&io___45);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    if (*mode != 1) {
		if (birad) {
		    s_wsfe(&io___46);
		    e_wsfe();
		}
		if (trip) {
		    s_wsfe(&io___47);
		    e_wsfe();
		}
		if (exci) {
		    s_wsfe(&io___48);
		    e_wsfe();
		}
	    }
	    ielec = 2;
	    ilevel = 2;
	} else if (molkst_1.nelecs / 2 << 1 != molkst_1.nelecs) {
	    ielec = 1;
	    ilevel = 1;
	}
	if (i_indx(keywrd_1.keywrd, "QUAR", (ftnlen)241, (ftnlen)4) != 0) {
	    if (*mode != 1) {
		s_wsfe(&io___49);
		e_wsfe();
	    }
	    ielec = 3;
	    ilevel = 3;
	}
	if (i_indx(keywrd_1.keywrd, "QUIN", (ftnlen)241, (ftnlen)4) != 0) {
	    if (*mode != 1) {
		s_wsfe(&io___50);
		e_wsfe();
	    }
	    ielec = 4;
	    ilevel = 4;
	}
	if (i_indx(keywrd_1.keywrd, "SEXT", (ftnlen)241, (ftnlen)4) != 0) {
	    if (*mode != 1) {
		s_wsfe(&io___51);
		e_wsfe();
	    }
	    ielec = 5;
	    ilevel = 5;
	}
	i__ = i_indx(keywrd_1.keywrd, "OPEN(", (ftnlen)241, (ftnlen)5);
	if (i__ != 0) {
	    ielec = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
	    i__1 = i__ + 7;
	    ilevel = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	}
	molkst_1.nclose = molkst_1.nelecs / 2;
	molkst_1.nopen = molkst_1.nelecs - (molkst_1.nclose << 1);
	if (ielec != 0) {
	    if (molkst_1.nelecs / 2 << 1 == molkst_1.nelecs != (ielec / 2 << 
		    1 == ielec)) {
		s_wsfe(&io___52);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    molkst_1.nclose -= ielec / 2;
	    molkst_1.nopen = ilevel;
	    if (molkst_1.nclose + molkst_1.nopen > molkst_1.norbs) {
		s_wsfe(&io___53);
		do_fio(&c__1, " NUMBER OF DOUBLY FILLED PLUS PARTLY FILLED L"
			"EVELS", (ftnlen)50);
		e_wsfe();
		s_wsfe(&io___54);
		do_fio(&c__1, " GREATER THAN TOTAL NUMBER OF ORBITALS.", (
			ftnlen)39);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    molkst_1.fract = ielec * 1. / ilevel;
	    if (*mode != 1) {
		s_wsfe(&io___55);
		do_fio(&c__1, (char *)&molkst_1.nclose, (ftnlen)sizeof(
			integer));
		e_wsfe();
	    }
	}
	if (*mode != 1) {
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&molkst_1.nclose, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*mode != 1 && molkst_1.nopen != 0 && (d__1 = molkst_1.fract - 1., 
		abs(d__1)) < 1e-4) {
	    s_wsfe(&io___57);
	    do_fio(&c__1, (char *)&molkst_1.nopen, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (*mode != 1 && molkst_1.nopen != 0 && (d__1 = molkst_1.fract - 1., 
		abs(d__1)) > 1e-4) {
	    s_wsfe(&io___58);
	    do_fio(&c__1, (char *)&molkst_1.fract, (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, (char *)&molkst_1.nopen, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) 
		    + 5;
	    i__2 = i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) 
		    + 7;
	    i__ = (integer) (reada_(keywrd_1.keywrd, &i__1, (ftnlen)241) - 
		    reada_(keywrd_1.keywrd, &i__2, (ftnlen)241));
	    if (molkst_1.nopen > i__) {
		s_wsfe(&io___59);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	}
	if (i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)241, (ftnlen)4) != 0 && 
		molkst_1.nopen == 0) {
	    molkst_1.nopen = 1;
	    --molkst_1.nclose;
	    molkst_1.fract = 2.;
	}
	molkst_1.nopen += molkst_1.nclose;
    }

/*  WORK OUT IF DEFINED SPIN-STATE ALLOWED */

    msdel = i_indx(keywrd_1.keywrd, " MS", (ftnlen)241, (ftnlen)3);
    if (msdel != 0) {
	i__1 = i_indx(keywrd_1.keywrd, " MS", (ftnlen)241, (ftnlen)3);
	msdel = (integer) (reada_(keywrd_1.keywrd, &i__1, (ftnlen)241) * 
		1.0001);
    } else {
	if (i_indx(keywrd_1.keywrd, "TRIP", (ftnlen)241, (ftnlen)4) + i_indx(
		keywrd_1.keywrd, "QUAR", (ftnlen)241, (ftnlen)4) > 0) {
	    msdel = 1;
	}
	if (i_indx(keywrd_1.keywrd, "QUIN", (ftnlen)241, (ftnlen)4) + i_indx(
		keywrd_1.keywrd, "SEXT", (ftnlen)241, (ftnlen)4) > 0) {
	    msdel = 2;
	}
    }
    if (msdel != 0 && ! uhf) {

/*   MSDEL = NUMBER OF ALPHA ELECTRONS - NUMBER OF BETA ELECTRONS */

	ndoubl = 99;
	if (i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) 
		    + 7;
	    ndoubl = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) 
		    + 5;
	    nmos = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	} else if (i_indx(keywrd_1.keywrd, "C.I.=", (ftnlen)241, (ftnlen)5) !=
		 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=", (ftnlen)241, (ftnlen)5) + 
		    5;
	    nmos = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	} else {
	    nmos = molkst_1.nopen - molkst_1.nclose;
	}
	if (ndoubl == 99) {
/* Computing MAX */
/* Computing MIN */
	    i__2 = (molkst_1.nclose + molkst_1.nopen + 1) / 2 - (nmos - 1) / 
		    2, i__3 = molkst_1.norbs - nmos + 1;
	    i__1 = min(i__2,i__3);
	    j = max(i__1,1);
	} else {
	    j = molkst_1.nclose - ndoubl + 1;
	}
/* Computing MAX */
	d__1 = 0., d__2 = molkst_1.nclose - j + 1.;
/* Computing MAX */
	d__3 = 0., d__4 = (molkst_1.nopen - molkst_1.nclose) * molkst_1.fract;
	ne = (integer) (max(d__1,d__2) * 2. + max(d__3,d__4) + .5);
	nupp = (ne + 1) / 2 + msdel;
	ndown = ne - nupp;

/*  NUPP  = NUMBER OF ALPHA ELECTRONS IN ACTIVE SPACE */
/*  NDOWN = NUMBER OF BETA  ELECTRONS IN ACTIVE SPACE */

	if (nupp * ndown < 0 || nupp > nmos || ndown > nmos) {
	    s_wsfe(&io___66);
	    do_fio(&c__1, " SPECIFIED SPIN COMPONENT NOT SPANNED BY ACTIVE S"
		    "PACE", (ftnlen)53);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
/* #      WRITE(6,'(''  NOPEN,NCLOSE,NALPHA,NBETA,FRACT'',4I4,F12.5)') */
/* #     1 NOPEN, NCLOSE, NLAPHA, NBETA, FRACT */

/*   MAKE SURE ANALYT IS NOT USED WITH ANALYTICAL C.I. DERIVATIVES */

    halfe = molkst_1.nopen > molkst_1.nclose && molkst_1.fract != 2. && 
	    molkst_1.fract != 0. || i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)
	    241, (ftnlen)4) != 0;
    slow = i_indx(keywrd_1.keywrd, "EXCI", (ftnlen)241, (ftnlen)4) != 0 || 
	    i_indx(keywrd_1.keywrd, "ROOT", (ftnlen)241, (ftnlen)4) != 0 && 
	    i_indx(keywrd_1.keywrd, "ROOT=1", (ftnlen)241, (ftnlen)6) == 0;
    if (halfe) {
	halfe = ! slow;
    }
    if (i_indx(keywrd_1.keywrd, "NOANCI", (ftnlen)241, (ftnlen)6) == 0 && 
	    i_indx(keywrd_1.keywrd, "ANALYT", (ftnlen)241, (ftnlen)6) != 0 && 
	    halfe) {
	s_wsle(&io___69);
	e_wsle();
	s_wsfe(&io___70);
	do_fio(&c__1, " KEYWORD 'ANALYT' CANNOT BE USED HERE: ", (ftnlen)39);
	do_fio(&c__1, " ANALYICAL C.I. DERIVATIVES MUST USE FINITE DIFFERENC"
		"ES", (ftnlen)55);
	do_fio(&c__1, " TO CORRECT, REMOVE KEYWORD 'ANALYT' OR ADD 'NOANCI'", 
		(ftnlen)52);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    yy = (real) kharge / (molkst_1.norbs + 1e-10);
    l = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ni = molkst_1.nat[i__ - 1];
	xx = 1. / (molkst_1.nlast[i__ - 1] - molkst_1.nfirst[i__ - 1] + 1 + 
		1e-10);
	w = core_1.core[ni - 1] * xx - yy;
	ia = molkst_1.nfirst[i__ - 1];
	ic = molkst_1.nmidle[i__ - 1];
	ib = molkst_1.nlast[i__ - 1];
/* $DOIT ASIS */
	i__2 = ic;
	for (j = ia; j <= i__2; ++j) {
	    ++l;
/* L140: */
	    molorb_1.pspd[l - 1] = w;
	}
/* $DOIT ASIS */
	i__2 = ib;
	for (j = ic + 1; j <= i__2; ++j) {
	    ++l;
/* L150: */
	    molorb_1.pspd[l - 1] = 0.;
	}
/* L160: */
    }

/*   WRITE OUT THE INTERATOMIC DISTANCES */

    gmetry_(geom_1.geo, coord);
    rmin = 100.;
    l = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
/* Computing 2nd power */
	    d__1 = coord[i__ * 3 - 3] - coord[j * 3 - 3];
/* Computing 2nd power */
	    d__2 = coord[i__ * 3 - 2] - coord[j * 3 - 2];
/* Computing 2nd power */
	    d__3 = coord[i__ * 3 - 1] - coord[j * 3 - 1];
	    scrach_1.rxyz[l - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * 
		    d__3);
	    if (rmin > scrach_1.rxyz[l - 1] && i__ != j && (molkst_1.nat[i__ 
		    - 1] < 103 || molkst_1.nat[j - 1] < 103)) {
		iminr = i__;
		jminr = j;
		rmin = scrach_1.rxyz[l - 1];
	    }
/* L170: */
	}
    }
    molmec_1.nnhco = 0;

/*   SET UP MOLECULAR-MECHANICS CORRECTION TO -(C=O)-(NH)- LINKAGE */
/*   THIS WILL BE USED IF MMOK HAS BEEN SPECIFIED. */

    molmec_1.itype = 1;
    if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0) {
	molmec_1.itype = 2;
    }
    if (i_indx(keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0) {
	molmec_1.itype = 3;
    }
    if (i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0) {
	molmec_1.itype = 4;
    }

/*   IDENTIFY O=C-N-H SYSTEMS VIA THE INTERATOMIC DISTANCES MATRIX */
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	if (molkst_1.nat[i__ - 1] != 8) {
	    goto L220;
	}
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    if (molkst_1.nat[j - 1] != 6) {
		goto L210;
	    }
	    ij = max(i__,j);
	    ji = i__ + j - ij;
	    if (scrach_1.rxyz[ij * (ij - 1) / 2 + ji - 1] > 1.3f) {
		goto L210;
	    }
	    i__3 = molkst_1.numat;
	    for (k = 1; k <= i__3; ++k) {
		if (molkst_1.nat[k - 1] != 7) {
		    goto L200;
		}
		jk = max(j,k);
		kj = j + k - jk;
		if (scrach_1.rxyz[jk * (jk - 1) / 2 + kj - 1] > 1.6f) {
		    goto L200;
		}
		i__4 = molkst_1.numat;
		for (l = 1; l <= i__4; ++l) {
		    if (molkst_1.nat[l - 1] != 1) {
			goto L190;
		    }
		    kl = max(k,l);
		    lk = k + l - kl;
		    if (scrach_1.rxyz[kl * (kl - 1) / 2 + lk - 1] > 1.3f) {
			goto L190;
		    }

/*   WE HAVE A H-N-C=O SYSTEM.  THE ATOM NUMBERS ARE L-K-J-I */
/*   NOW SEARCH OUT ATOM ATTACHED TO NITROGEN, THIS SPECIFIES */
/*   THE SYSTEM X-N-C=O */

		    i__5 = molkst_1.numat;
		    for (m = 1; m <= i__5; ++m) {
			if (m == k || m == l || m == j) {
			    goto L180;
			}
			mk = max(m,k);
			km = m + k - mk;
			if (scrach_1.rxyz[mk * (mk - 1) / 2 + km - 1] > 1.7f) 
				{
			    goto L180;
			}
			++molmec_1.nnhco;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 4] = i__;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 3] = j;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 2] = k;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 1] = m;
			++molmec_1.nnhco;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 4] = i__;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 3] = j;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 2] = k;
			molmec_1.nhco[(molmec_1.nnhco << 2) - 1] = l;
			goto L190;
L180:
			;
		    }
L190:
		    ;
		}
L200:
		;
	    }
L210:
	    ;
	}
L220:
	;
    }
    if (*mode != 1 && molmec_1.nnhco != 0) {
	if (i_indx(keywrd_1.keywrd, "MMOK", (ftnlen)241, (ftnlen)4) != 0) {
	    s_wsfe(&io___89);
	    do_fio(&c__1, " MOLECULAR MECHANICS CORRECTION APPLIED TO PEPTID"
		    "ELINKAGE", (ftnlen)57);
	    e_wsfe();
	} else if (i_indx(keywrd_1.keywrd, "NOMM", (ftnlen)241, (ftnlen)4) != 
		0) {
	    s_wsfe(&io___90);
	    do_fio(&c__1, " THERE ARE ", (ftnlen)11);
	    i__2 = molmec_1.nnhco / 2;
	    do_fio(&c__1, (char *)&i__2, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " PEPTIDE LINKAGES", (ftnlen)17);
	    do_fio(&c__1, " IDENTIFIED IN THIS SYSTEM", (ftnlen)26);
	    e_wsfe();
	    s_wsfe(&io___91);
	    do_fio(&c__1, " IF YOU WANT MM CORRECTION TO THE CONH BARRIER, A"
		    "DD THE KEY-WORD \"MMOK\"", (ftnlen)71);
	    e_wsfe();
	    molmec_1.nnhco = 0;
	} else {
	    s_wsfe(&io___92);
	    do_fio(&c__1, " THIS SYSTEM CONTAINS -HNCO- GROUPS.", (ftnlen)36);
	    e_wsfe();
	    s_wsfe(&io___93);
	    do_fio(&c__1, " YOU MUST SPECIFY \"NOMM\" OR \"MMOK\" REGARDING "
		    "MOLECULAR MECHANICS CORRECTION", (ftnlen)75);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
    if (*mode != 1 && i_indx(keywrd_1.keywrd, "NOINTER", (ftnlen)241, (ftnlen)
	    7) == 0) {
	s_wsfe(&io___94);
	e_wsfe();
	vecprt_(scrach_1.rxyz, &molkst_1.numat);
    }
    if (rmin < .8 && i_indx(keywrd_1.keywrd, "GEO-OK", (ftnlen)241, (ftnlen)6)
	     == 0) {
	s_wsfe(&io___95);
	do_fio(&c__1, (char *)&iminr, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&jminr, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rmin, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (! debug) {
	return 0;
    }
    s_wsfe(&io___96);
    do_fio(&c__1, (char *)&molkst_1.numat, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&molkst_1.norbs, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ndorbs, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&geokst_1.natoms, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___97);
    i__2 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, (char *)&molorb_1.uspd[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    s_wsfe(&io___98);
    i__2 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, (char *)&molorb_1.pspd[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    return 0;
L270:
    s_wsfe(&io___99);
    e_wsfe();
    s_wsfe(&io___100);
    do_fio(&c__1, (char *)&c__300, (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* moldat_ */

