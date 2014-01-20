/* ffhpol.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], nors, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal coord[360]	/* was [3][120] */;
} coord_;

#define coord_1 coord_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal efield[3];
} field_;

#define field_1 field_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer idtvec;
} euler_;

#define euler_1 euler_

/* Table of constant values */

static integer c__1 = 1;
static logical c_true = TRUE_;
static logical c_false = FALSE_;

/* Subroutine */ int ffhpol_(doublereal *heat0, doublereal *atpol)
{
    /* Initialized data */

    static integer iptbd[6] = { 5,7,4,9,6,8 };
    static char axis[1*3] = "X" "Y" "Z";

    /* Format strings */
    static char fmt_10[] = "(//\002 APPLIED ELECTRIC FIELD MAGNITUDE: \002,f"
	    "15.5)";
    static char fmt_20[] = "(//\002 ATOMIC CONTRIBUTION TO THE POLARIZABILIT"
	    "Y: \002,f15.6,/,\002  (IT IS ONLY APPLIED TO THE E4 RESULT)\002)";
    static char fmt_30[] = "(//,\002 ****** FIELD IN \002,a1,\002 DIRECTION "
	    "*****\002,/)";
    static char fmt_60[] = "(\002 FIELDS OF: \002,5x,\002F\002,21x,\0022F"
	    "\002)";
    static char fmt_70[] = "(\002  ENERGY:\002/,\002   + \002,2(f20.10,3x)"
	    ",/,\002   - \002,2(f20.10,3x),/,\002  DIPOLE:\002/,\002   + \002"
	    ",2(f20.10,3x),/,\002   - \002,2(f20.10,3x))";
    static char fmt_110[] = "(/,\002 \002,12x,\002+,+\002,15x,\002+,-\002,15"
	    "x,\002-,+\002,15x,\002-,-\002)";
    static char fmt_120[] = "(\002  E \002,4f15.6)";
    static char fmt_130[] = "(\002 2E \002,4f15.6)";
    static char fmt_160[] = "(//,\002 \002,30(\002*\002),\002 DIPOLE \002,"
	    "30(\002*\002),//)";
    static char fmt_170[] = "(21x,\002E4\002,13x,\002DIP\002,/)";
    static char fmt_180[] = "(5x,a1,7x,2f15.6)";
    static char fmt_190[] = "(//\002 MAGNITUDE:  \002,2f15.6,\002  (A.U.)"
	    "\002,/,\002 \002,12x,2f15.6,\002  (DEBYE)\002)";
    static char fmt_200[] = "(//,\002 \002,22(\002*\002),\002 POLARIZABILITY"
	    " (ALPHA)\002,21(\002*\002),//)";
    static char fmt_210[] = "(\002  COMPONENT\002,12x,\002E4\002,13x,\002DI"
	    "P\002,/)";
    static char fmt_220[] = "(\002 \002,5x,a4,5x,2f15.6)";
    static char fmt_230[] = "(//,\002 AVERAGE POLARIZABILITY:\002,8x,\002E"
	    "4\002,13x,\002DIP\002,/,\002 \002,24x,2f15.6,\002  A.U.\002,/"
	    ",\002 \002,24x,2f15.6,\002  ANG.**3\002,/,\002 \002,24x,2(1pd15."
	    "6),\002  ESU\002)";
    static char fmt_240[] = "(//,\002 \002,30(\002*\002),\002 SECOND-ORDER ("
	    "BETA)\002,25(\002*\002),//)";
    static char fmt_250[] = "(\002  COMPONENT\002,2(12x,\002E4\002,10x,\002D"
	    "IP\002,2x),/)";
    static char fmt_260[] = "(\002 \002,5x,a4,2(5x,2f12.3))";
    static char fmt_270[] = "(//,\002 VECTOR COMPONENTS GIVEN BY:\002,/,\002"
	    "      BI = (2/5)*(BI11+BI22+BI33)\002/)";
    static char fmt_280[] = "(\002 \002,6x,a2,2(6x,2f12.3))";
    static char fmt_290[] = "(//\002  VALUE OF BETA ALONG THE DIPOLE MOMENT"
	    ":\002/)";
    static char fmt_300[] = "(\002 \002,4x,\002B(AU)\002,2(5x,2f12.3,2x),/"
	    ",\002 \002,4x,\002B(ESU)\002,4x,2f12.3,7x,2f12.3,\002 (X10-30"
	    ")\002)";
    static char fmt_310[] = "(//\002 \002,24(\002*\002),\002 THIRD-ORDER (GA"
	    "MMA)\002,24(\002*\002),//)";
    static char fmt_320[] = "(\002 \002,17x,\002E4\002,8x,\002DIP\002,16x"
	    ",\002E4\002,8x,\002DIP\002,/)";
    static char fmt_330[] = "(5x,a4,2f12.3,5x,2f12.3)";
    static char fmt_340[] = "(//\002 AVERAGE GAMMA GIVEN BY:\002,/,\002    ("
	    "1/5)*[GXXX + GYYY + GZZZ + 2.0*(GXXYY + GXXZZ + GYYZZ)]\002)";
    static char fmt_350[] = "(/\002 <GAMMA> \002,1pd12.5,1pd12.5,5x,1pd12.5,"
	    "1pd12.5,\002  A.U.\002/,\002 \002,8x,1pd12.5,1pd12.5,5x,1pd12.5,"
	    "1pd12.5,\002  ESU (X10-36)\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal ae, be, ge;
    static integer id, jd, kd;
    static doublereal bx4, by4, bz4;
    static integer nbd;
    static doublereal aki, aij, sfe, dmm, bxd, dpm, hmm, dpp, hpm, dmu, hmp, 
	    hpp, dmp, byd;
    static integer ivl;
    static doublereal bzd;
    static integer kvl, idm1;
    static doublereal h2mm, h2pm, h2mp, b4mu, h2pp, grad[360], bkii, bjii, 
	    bijj, diim, gdip;
    static integer idip;
    static doublereal diip, bdmu, hnuc, avga3, dipe4[3], dip1m[3], dip2m[3], 
	    dip1p[3], dip2p[3], b4esu;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical debug;
    static doublereal heate[6]	/* was [3][2] */;
    static integer nbdip;
    static doublereal efval, dipdp[3], giijj, bdesu;
    static integer nbcnt;
    static doublereal hnucj;
    static integer ngcnt;
    static doublereal aterm, bterm, eterm, gterm, betae4[9], avga3d, dipe4d, 
	    gamme4[6], heat1m, heat2m, heat1p, heat2p, apole4[6], avgpe4, 
	    dipe4t, betadp[9], gamdes, gamdip, dipdpd, gammdp[6];
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), dipind_(doublereal *);
    static doublereal apoldp[6], autodb, dipdpt, autokc, avgesu, avgpdp, 
	    avgesd, gamval, gamesu, autovm;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___31 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___32 = { 0, 6, 0, fmt_70, 0 };
    static cilist io___63 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___64 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___78 = { 0, 6, 0, fmt_160, 0 };
    static cilist io___83 = { 0, 6, 0, fmt_170, 0 };
    static cilist io___84 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___85 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___86 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___87 = { 0, 6, 0, fmt_190, 0 };
    static cilist io___88 = { 0, 6, 0, fmt_200, 0 };
    static cilist io___95 = { 0, 6, 0, fmt_210, 0 };
    static cilist io___96 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___97 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___109 = { 0, 6, 0, "(29X,A2,25X,A6)", 0 };
    static cilist io___110 = { 0, 6, 0, fmt_250, 0 };
    static cilist io___111 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___112 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___113 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___114 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___115 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___116 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___117 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___118 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___119 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___120 = { 0, 6, 0, fmt_270, 0 };
    static cilist io___121 = { 0, 6, 0, fmt_280, 0 };
    static cilist io___122 = { 0, 6, 0, fmt_280, 0 };
    static cilist io___123 = { 0, 6, 0, fmt_280, 0 };
    static cilist io___124 = { 0, 6, 0, fmt_290, 0 };
    static cilist io___125 = { 0, 6, 0, fmt_300, 0 };
    static cilist io___126 = { 0, 6, 0, fmt_310, 0 };
    static cilist io___131 = { 0, 6, 0, "(23X,A2,25X,A6)", 0 };
    static cilist io___132 = { 0, 6, 0, fmt_320, 0 };
    static cilist io___133 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___134 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___135 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___136 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___137 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___138 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___139 = { 0, 6, 0, fmt_340, 0 };
    static cilist io___140 = { 0, 6, 0, "(/,20X,A2,22X,A6)", 0 };
    static cilist io___141 = { 0, 6, 0, fmt_350, 0 };


/* *********************************************************************** */
/*  SUBROUTINE FOR THE FINITE FIELD CALCULATION OF ELECTRIC RESPONSE */
/*  PROPERTIES (DIPOLE MOMENT, POLARIZABILITY, AND 1ST AND 2ND */
/*  HYPERPOLARIZABILITY. */

/*  HENRY A. KURTZ, DEPARTMENT OF CHEMISTRY */
/*                  MEMPHIS STATE UNIVERSITY */
/*                  MEMPHIS, TN   38152 */

/* *********************************************************************** */
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


/*     DIPE4 AND DIPDP HOLD THE CALCULATED DIPOLE MOMENTS */

/*     APOLE4 AND APOLDP HOLD THE POLARIZABILITY TENSOR AS */
/*                                A PACKED ARRAY XX,XY,YY,XZ,YZ,ZZ */

/*     BETAE4 AND BETAEP HOLD THE FIRST HYPERPOLARIZABILITY */
/*                                1. XXX */
/*                                2. YYY     6. YXX */
/*                                3. ZZZ     7. YZZ */
/*                                4. XYY     8. ZXX */
/*                                5. XZZ     9. ZYY */

/* Energy: a.u. to kcal/mole */
    autokc = 627.50595269999997;
/* Dipole: a.u. to debye */
    autodb = 2.541563;
/* Electric Field: a.u. to volt/meter */
    autovm = 51.4257;
    nbdip = 1;
    nbcnt = 4;
    ngcnt = 4;

    debug = i_indx(keywrd_1.keywrd, "DEBUG", (ftnlen)241, (ftnlen)5) != 0;

/*  FIELD STRENGTH IN A.U. */

    efval = .001;
    idip = 1;
/* modification for variable field strength */
    if (i_indx(keywrd_1.keywrd, "POLAR=", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "POLAR=", (ftnlen)241, (ftnlen)6);
	efval = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    }
    s_wsfe(&io___12);
    do_fio(&c__1, (char *)&efval, (ftnlen)sizeof(doublereal));
    e_wsfe();
    sfe = 1. / efval;
    s_wsfe(&io___14);
    d__1 = *atpol * 6.74834;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* ....................................................................... */
/*  CALCULATE THE POLARIZABILITY AND HYPERPOLARIZABILITIES ALONG */
/*  THE THREE PRINCIPLE AXES.  (THESE AXES DEPEND ON YOUR ARBITRARY */
/*  ORIENTATION AND MAY NOT BE THE TRUE PRINCIPLE AXES.) */
/* ....................................................................... */
    for (id = 1; id <= 3; ++id) {
	if (debug) {
	    s_wsfe(&io___16);
	    do_fio(&c__1, axis + (id - 1), (ftnlen)1);
	    e_wsfe();
	}

/* ZERO THE FIELD */

	for (i__ = 1; i__ <= 3; ++i__) {
	    field_1.efield[i__ - 1] = 0.;
/* L40: */
	}
	hnuc = 0.;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    hnuc += efval * geom_1.geo[id + i__ * 3 - 4] * core_1.core[
		    molkst_1.nat[i__ - 1] - 1] * autovm;
/* L50: */
	}
	hnuc *= 23.061;
/* +E(ID) */
	field_1.efield[id - 1] = efval;
	compfg_(geom_1.geo, &c_true, &heat1p, &c_true, grad, &c_false);
	dipind_(dip1p);
	diip = dip1p[id - 1];
/* -E(ID) */
	field_1.efield[id - 1] = -efval;
	compfg_(geom_1.geo, &c_true, &heat1m, &c_true, grad, &c_false);
	dipind_(dip1m);
	diim = dip1m[id - 1];
/* +2E(ID) */
	field_1.efield[id - 1] = efval * 2.;
	compfg_(geom_1.geo, &c_true, &heat2p, &c_true, grad, &c_false);
	dipind_(dip2p);
/* -2E(ID) */
	field_1.efield[id - 1] = efval * -2.;
	compfg_(geom_1.geo, &c_true, &heat2m, &c_true, grad, &c_false);
	dipind_(dip2m);

/*  CORRECT FOR ELECTRIC FIELD - NUCLEAR INTERACTIONS */

	heat1p += hnuc;
	heate[id - 1] = heat1p;
	heat1m -= hnuc;
	heate[id + 2] = heat1m;
	heat2p += hnuc * 2.;
	heat2m -= hnuc * 2.;

	if (debug) {
	    s_wsfe(&io___31);
	    e_wsfe();
	    s_wsfe(&io___32);
	    do_fio(&c__1, (char *)&heat1p, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&heat2p, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&heat1m, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&heat2m, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&dip1p[id - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&dip2p[id - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&dip1m[id - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&dip2m[id - 1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

/* DIPOLE */

	eterm = (heat2p - heat2m) * .083333333333333329 - (heat1p - heat1m) * 
		.66666666666666663;
	dipe4[id - 1] = eterm * sfe / autokc;

/* ALPHA */

	ivl = id * (id + 1) / 2;
	eterm = *heat0 * 2.5 - (heat1p + heat1m) * 1.3333333333333333 + (
		heat2p + heat2m) * .083333333333333329;
	apole4[ivl - 1] = eterm * sfe * sfe / autokc + *atpol * 6.74834;

/* BETA */

	eterm = heat1p - heat1m - (heat2p - heat2m) * .5;
	betae4[id - 1] = eterm * sfe * sfe * sfe / autokc;

/* GAMMA */

	eterm = (heat1p + heat1m) * 4. - (heat2p + heat2m) - *heat0 * 6.;
	gamme4[id - 1] = eterm * sfe * sfe * sfe * sfe / autokc;

/* DIPOLE CALCULATIONS */

	dmu = (dip1p[id - 1] + dip1m[id - 1]) * .66666666666666663 - (dip2p[
		id - 1] + dip2m[id - 1]) * .16666666666666666;
	dipdp[id - 1] = dmu / autodb;
	ae = (dip1p[id - 1] - dip1m[id - 1]) * .66666666666666663 - (dip2p[id 
		- 1] - dip2m[id - 1]) * .083333333333333329;
	apoldp[ivl - 1] = ae * sfe / autodb;
	be = (dip2p[id - 1] + dip2m[id - 1] - dip1p[id - 1] - dip1m[id - 1]) *
		 .33333333333333331;
	betadp[id - 1] = be * sfe * sfe / autodb;
	ge = (dip2p[id - 1] - dip2m[id - 1]) * .5 - (dip1p[id - 1] - dip1m[id 
		- 1]);
	gammdp[id - 1] = ge * sfe * sfe * sfe / autodb;
	for (kd = 1; kd <= 3; ++kd) {
	    if (kd < id) {
		kvl = id * (id - 1) / 2 + kd;
		aki = (dip1p[kd - 1] - dip1m[kd - 1]) * .66666666666666663 - (
			dip2p[kd - 1] - dip2m[kd - 1]) * .083333333333333329;
		apoldp[kvl - 1] = aki * sfe / autodb;
	    }
	    if (kd != id) {
		bkii = (dip2p[kd - 1] + dip2m[kd - 1] - dip1p[kd - 1] - dip1m[
			kd - 1]) * .33333333333333331;
		nbd = iptbd[nbdip - 1];
		betadp[nbd - 1] = bkii * sfe * sfe / autodb;
		++nbdip;
	    }
/* L80: */
	}
/* ....................................................................... */

/*  NOW CALCULATE THE OFF AXIS RESULTS. */

/* ....................................................................... */
	idm1 = id - 1;
	i__1 = idm1;
	for (jd = 1; jd <= i__1; ++jd) {
	    hnucj = 0.;
	    i__2 = molkst_1.numat;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		hnucj += efval * geom_1.geo[jd + i__ * 3 - 4] * core_1.core[
			molkst_1.nat[i__ - 1] - 1] * 51.4257;
/* L90: */
	    }
	    hnucj *= 23.061;
	    for (i__ = 1; i__ <= 3; ++i__) {
		field_1.efield[i__ - 1] = 0.;
/* L100: */
	    }

/* DIAGONAL FIELDS WITH COMPONENTS EQUAL TO EFVAL */

	    field_1.efield[id - 1] = efval;
	    field_1.efield[jd - 1] = efval;
	    compfg_(geom_1.geo, &c_true, &hpp, &c_true, grad, &c_false);
	    dipind_(dip1p);
	    dpp = dip1p[id - 1];
	    field_1.efield[jd - 1] = -efval;
	    compfg_(geom_1.geo, &c_true, &hpm, &c_true, grad, &c_false);
	    dipind_(dip1p);
	    dpm = dip1p[id - 1];
	    field_1.efield[id - 1] = -efval;
	    compfg_(geom_1.geo, &c_true, &hmm, &c_true, grad, &c_false);
	    dipind_(dip1p);
	    dmm = dip1p[id - 1];
	    field_1.efield[jd - 1] = efval;
	    compfg_(geom_1.geo, &c_true, &hmp, &c_true, grad, &c_false);
	    dipind_(dip1p);
	    dmp = dip1p[id - 1];
	    hpp = hpp + hnuc + hnucj;
	    hpm = hpm + hnuc - hnucj;
	    hmm = hmm - hnuc - hnucj;
	    hmp = hmp - hnuc + hnucj;
	    if (debug) {
		s_wsfe(&io___63);
		e_wsfe();
		s_wsfe(&io___64);
		do_fio(&c__1, (char *)&hpp, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&hpm, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&hmp, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&hmm, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }

/*  DIAGONAL FIELDS WITH COMPONENTS EQUAL TO 2*EFVAL */

	    field_1.efield[id - 1] = efval * 2.;
	    field_1.efield[jd - 1] = efval * 2.;
	    compfg_(geom_1.geo, &c_true, &h2pp, &c_true, grad, &c_false);
	    field_1.efield[jd - 1] = -efval * 2.;
	    compfg_(geom_1.geo, &c_true, &h2pm, &c_true, grad, &c_false);
	    field_1.efield[id - 1] = -efval * 2.;
	    compfg_(geom_1.geo, &c_true, &h2mm, &c_true, grad, &c_false);
	    field_1.efield[jd - 1] = efval * 2.;
	    compfg_(geom_1.geo, &c_true, &h2mp, &c_true, grad, &c_false);
	    h2pp += (hnuc + hnucj) * 2.;
	    h2pm += (hnuc - hnucj) * 2.;
	    h2mm -= (hnuc + hnucj) * 2.;
	    h2mp -= (hnuc - hnucj) * 2.;
	    if (debug) {
		s_wsfe(&io___69);
		do_fio(&c__1, (char *)&h2pp, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&h2pm, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&h2mp, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&h2mm, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }

	    aterm = (h2pp - h2pm - h2mp + h2mm) * .020833333333333332 - (hpp 
		    - hpm - hmp + hmm) * .33333333333333331;
	    aij = aterm * sfe * sfe / autokc;
	    ivl = id * (id - 1) / 2 + jd;
	    apole4[ivl - 1] = aij;
	    bterm = (hmm - hpp + hpm - hmp) * .5 + heate[jd - 1] - heate[jd + 
		    2];
	    bjii = bterm * sfe * sfe * sfe / autokc;
	    betae4[nbcnt - 1] = bjii;
	    ++nbcnt;
	    bterm = (hmm - hpp + hmp - hpm) * .5 + heate[id - 1] - heate[id + 
		    2];
	    bijj = bterm * sfe * sfe * sfe / autokc;
	    betae4[nbcnt - 1] = bijj;
	    ++nbcnt;

	    gterm = -(hpp + hmm + hpm + hmp) - *heat0 * 4. + (heate[id - 1] + 
		    heate[id + 2]) * 2. + (heate[jd - 1] + heate[jd + 2]) * 
		    2.;
	    giijj = gterm * sfe * sfe * sfe * sfe / autokc;
	    gamme4[ngcnt - 1] = giijj;
	    gdip = (dpp - dmp + dpm - dmm) * .5 - (diip - diim);
	    gammdp[ngcnt - 1] = gdip * sfe * sfe * sfe / autodb;
	    ++ngcnt;
/* L140: */
	}

/* L150: */
    }
/* ----------------------------------------------------------------------- */
/*  SUMMARIZE THE RESULTS */
/* ----------------------------------------------------------------------- */
    s_wsfe(&io___78);
    e_wsfe();
    dipe4t = sqrt(dipe4[0] * dipe4[0] + dipe4[1] * dipe4[1] + dipe4[2] * 
	    dipe4[2]);
    dipe4d = dipe4t * autodb;
    dipdpt = sqrt(dipdp[0] * dipdp[0] + dipdp[1] * dipdp[1] + dipdp[2] * 
	    dipdp[2]);
    dipdpd = dipdpt * autodb;
    s_wsfe(&io___83);
    e_wsfe();
    s_wsfe(&io___84);
    do_fio(&c__1, "X", (ftnlen)1);
    do_fio(&c__1, (char *)&dipe4[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dipdp[0], (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___85);
    do_fio(&c__1, "Y", (ftnlen)1);
    do_fio(&c__1, (char *)&dipe4[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dipdp[1], (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___86);
    do_fio(&c__1, "Z", (ftnlen)1);
    do_fio(&c__1, (char *)&dipe4[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dipdp[2], (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___87);
    do_fio(&c__1, (char *)&dipe4t, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dipdpt, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dipe4d, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&dipdpd, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* FIND EIGENVALUES AND EIGENVECTORS OF POLARIZATION MATRIX. */

    s_wsfe(&io___88);
    e_wsfe();
    avgpe4 = (apole4[0] + apole4[2] + apole4[5]) / 3.;
    avga3 = avgpe4 * .14818;
    avgesu = avgpe4 * 2.96352e-25;
    avgpdp = (apoldp[0] + apoldp[2] + apoldp[5]) / 3.;
    avga3d = avgpdp * .14818;
    avgesd = avgpdp * 2.96352e-25;
    s_wsfe(&io___95);
    e_wsfe();
    s_wsfe(&io___96);
    do_fio(&c__1, "XX", (ftnlen)2);
    do_fio(&c__1, (char *)&apole4[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&apoldp[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, "YY", (ftnlen)2);
    do_fio(&c__1, (char *)&apole4[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&apoldp[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, "ZZ", (ftnlen)2);
    do_fio(&c__1, (char *)&apole4[5], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&apoldp[5], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, "XY", (ftnlen)2);
    do_fio(&c__1, (char *)&apole4[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&apoldp[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, "XZ", (ftnlen)2);
    do_fio(&c__1, (char *)&apole4[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&apoldp[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, "YZ", (ftnlen)2);
    do_fio(&c__1, (char *)&apole4[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&apoldp[4], (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___97);
    do_fio(&c__1, (char *)&avgpe4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avgpdp, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avga3, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avga3d, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avgesu, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&avgesd, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  CALCULATE "EXPERIMENTAL" HYPERPOLARIZABILITIES */

/*   8.65710D-33 is a.u. to e.s.u. conversion */
    s_wsfe(&io___98);
    e_wsfe();
    bx4 = (betae4[0] + betae4[3] + betae4[5]) * .6;
    by4 = (betae4[1] + betae4[4] + betae4[7]) * .6;
    bz4 = (betae4[2] + betae4[6] + betae4[8]) * .6;
    b4mu = (bx4 * dipe4[0] + by4 * dipe4[1] + bz4 * dipe4[2]) / dipe4t;
    b4esu = b4mu * .0086571;
    bxd = (betadp[0] + betadp[3] + betadp[5]) * .6;
    byd = (betadp[1] + betadp[4] + betadp[7]) * .6;
    bzd = (betadp[2] + betadp[6] + betadp[8]) * .6;
    bdmu = (bxd * dipdp[0] + byd * dipdp[1] + bzd * dipdp[2]) / dipdpt;
    bdesu = bdmu * .0086571;

    s_wsfe(&io___109);
    do_fio(&c__1, "1X", (ftnlen)2);
    do_fio(&c__1, "(1/2)X", (ftnlen)6);
    e_wsfe();
    s_wsfe(&io___110);
    e_wsfe();
    s_wsfe(&io___111);
    do_fio(&c__1, "XXX", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[0], (ftnlen)sizeof(doublereal));
    d__1 = betae4[0] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[0] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___112);
    do_fio(&c__1, "XYY", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[3], (ftnlen)sizeof(doublereal));
    d__1 = betae4[3] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[3] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___113);
    do_fio(&c__1, "XZZ", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[5], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[5], (ftnlen)sizeof(doublereal));
    d__1 = betae4[5] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[5] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___114);
    do_fio(&c__1, "YYY", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[1], (ftnlen)sizeof(doublereal));
    d__1 = betae4[1] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[1] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___115);
    do_fio(&c__1, "YXX", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[4], (ftnlen)sizeof(doublereal));
    d__1 = betae4[4] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[4] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___116);
    do_fio(&c__1, "YZZ", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[7], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[7], (ftnlen)sizeof(doublereal));
    d__1 = betae4[7] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[7] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___117);
    do_fio(&c__1, "ZZZ", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[2], (ftnlen)sizeof(doublereal));
    d__1 = betae4[2] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[2] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___118);
    do_fio(&c__1, "ZXX", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[6], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[6], (ftnlen)sizeof(doublereal));
    d__1 = betae4[6] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[6] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___119);
    do_fio(&c__1, "ZYY", (ftnlen)3);
    do_fio(&c__1, (char *)&betae4[8], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&betadp[8], (ftnlen)sizeof(doublereal));
    d__1 = betae4[8] / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = betadp[8] / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___120);
    e_wsfe();
    s_wsfe(&io___121);
    do_fio(&c__1, "BX", (ftnlen)2);
    do_fio(&c__1, (char *)&bx4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxd, (ftnlen)sizeof(doublereal));
    d__1 = bx4 / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = bxd / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___122);
    do_fio(&c__1, "BY", (ftnlen)2);
    do_fio(&c__1, (char *)&by4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byd, (ftnlen)sizeof(doublereal));
    d__1 = by4 / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = byd / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___123);
    do_fio(&c__1, "BZ", (ftnlen)2);
    do_fio(&c__1, (char *)&bz4, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzd, (ftnlen)sizeof(doublereal));
    d__1 = bz4 / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = bzd / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___124);
    e_wsfe();
    s_wsfe(&io___125);
    do_fio(&c__1, (char *)&b4mu, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bdmu, (ftnlen)sizeof(doublereal));
    d__1 = b4mu / 2;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = bdmu / 2;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&b4esu, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bdesu, (ftnlen)sizeof(doublereal));
    d__3 = b4esu / 2;
    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
    d__4 = bdesu / 2;
    do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___126);
    e_wsfe();
    gamval = gamme4[0] + gamme4[1] + gamme4[2];
    gamval += (gamme4[3] + gamme4[4] + gamme4[5]) * 2.;
    gamval /= 5.;
/*  5.05116D-40 is the a.u. to e.s.u. conversion */
    gamesu = gamval * 5.05116e-4;
    gamdip = gammdp[0] + gammdp[1] + gammdp[2];
    gamdip += (gammdp[3] + gammdp[4] + gammdp[5]) * 2.;
    gamdip /= 5.;
    gamdes = gamdip * 5.05116e-4;
    s_wsfe(&io___131);
    do_fio(&c__1, "1X", (ftnlen)2);
    do_fio(&c__1, "(1/6)X", (ftnlen)6);
    e_wsfe();
    s_wsfe(&io___132);
    e_wsfe();
    s_wsfe(&io___133);
    do_fio(&c__1, "XXXX", (ftnlen)4);
    do_fio(&c__1, (char *)&gamme4[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gammdp[0], (ftnlen)sizeof(doublereal));
    d__1 = gamme4[0] / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gammdp[0] / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___134);
    do_fio(&c__1, "YYYY", (ftnlen)4);
    do_fio(&c__1, (char *)&gamme4[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gammdp[1], (ftnlen)sizeof(doublereal));
    d__1 = gamme4[1] / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gammdp[1] / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___135);
    do_fio(&c__1, "ZZZZ", (ftnlen)4);
    do_fio(&c__1, (char *)&gamme4[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gammdp[2], (ftnlen)sizeof(doublereal));
    d__1 = gamme4[2] / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gammdp[2] / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___136);
    do_fio(&c__1, "XXYY", (ftnlen)4);
    do_fio(&c__1, (char *)&gamme4[3], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gammdp[3], (ftnlen)sizeof(doublereal));
    d__1 = gamme4[3] / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gammdp[3] / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___137);
    do_fio(&c__1, "XXZZ", (ftnlen)4);
    do_fio(&c__1, (char *)&gamme4[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gammdp[4], (ftnlen)sizeof(doublereal));
    d__1 = gamme4[4] / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gammdp[4] / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___138);
    do_fio(&c__1, "YYZZ", (ftnlen)4);
    do_fio(&c__1, (char *)&gamme4[5], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gammdp[5], (ftnlen)sizeof(doublereal));
    d__1 = gamme4[5] / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gammdp[5] / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___139);
    e_wsfe();
    s_wsfe(&io___140);
    do_fio(&c__1, "1X", (ftnlen)2);
    do_fio(&c__1, "(1/6)X", (ftnlen)6);
    e_wsfe();
    s_wsfe(&io___141);
    do_fio(&c__1, (char *)&gamval, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gamdip, (ftnlen)sizeof(doublereal));
    d__1 = gamval / 6;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    d__2 = gamdip / 6;
    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gamesu, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gamdes, (ftnlen)sizeof(doublereal));
    d__3 = gamesu / 6;
    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
    d__4 = gamdes / 6;
    do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
    e_wsfe();

    return 0;
} /* ffhpol_ */

