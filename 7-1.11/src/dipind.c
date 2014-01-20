/* dipind.f -- translated by f2c (version 20020621).
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
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal htype[4];
    integer nhco[80]	/* was [4][20] */, nnhco, itype;
} molmec_;

#define molmec_1 molmec_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal ams[107];
} istope_;

#define istope_1 istope_

struct {
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

/* Subroutine */ int dipind_(doublereal *dipvec)
{
    /* Initialized data */

    static struct {
	doublereal e_1;
	doublereal fill_2[106];
	doublereal e_3;
	doublereal fill_4[3];
	doublereal e_5[5];
	doublereal fill_6[4];
	doublereal e_7[4];
	doublereal fill_8[90];
	} equiv_18 = { 0., {0}, 0., {0}, 6.520587, 4.253676, 2.947501, 
		2.139793, 2.2210719, {0}, 6.663059, 5.657623, 6.345552, 
		2.522964 };

#define hyf ((doublereal *)&equiv_18)

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal q[300], q2[300];
    static integer ia, ni;
    static doublereal dip[12]	/* was [4][3] */, sum;
    extern /* Subroutine */ int chrge_(doublereal *, doublereal *);
    static doublereal coord[360]	/* was [3][120] */;
    static integer ktype;
    static doublereal wtmol;
    static logical chargd;
    static doublereal center[3];
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);

/* ............................................................... */
/*  MODIFICATION OF DIPOLE SUBROUTINE FOR USE IN THE CALCULATION */
/*  OF THE INDUCED DIPOLES FOR POLARIZABILITIES. */
/* ............................................................... */
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

/* *********************************************************************** */
/*     DIPOLE CALCULATES DIPOLE MOMENTS */

/*  ON INPUT P     = DENSITY MATRIX */
/*           Q     = TOTAL ATOMIC CHARGES, (NUCLEAR + ELECTRONIC) */
/*           NUMAT = NUMBER OF ATOMS IN MOLECULE */
/*           NAT   = ATOMIC NUMBERS OF ATOMS */
/*           NFIRST= START OF ATOM ORBITAL COUNTERS */
/*           COORD = COORDINATES OF ATOMS */

/*  OUTPUT  DIPOLE = DIPOLE MOMENT */
/* *********************************************************************** */

/*     IN THE ZDO APPROXIMATION, ONLY TWO TERMS ARE RETAINED IN THE */
/*     CALCULATION OF DIPOLE MOMENTS. */
/*     1. THE POINT CHARGE TERM (INDEPENDENT OF PARAMETERIZATION). */
/*     2. THE ONE-CENTER HYBRIDIZATION TERM, WHICH ARISES FROM MATRIX */
/*     ELEMENTS OF THE FORM <NS/R/NP>. THIS TERM IS A FUNCTION OF */
/*     THE SLATER EXPONENTS (ZS,ZP) AND IS THUS DEPENDENT ON PARAMETER- */
/*     IZATION. THE HYBRIDIZATION FACTORS (HYF(I)) USED IN THIS SUB- */
/*     ROUTINE ARE CALCULATED FROM THE FOLLOWING FORMULAE. */
/*     FOR SECOND ROW ELEMENTS <2S/R/2P> */
/*     HYF(I)= 469.56193322*(SQRT(((ZS(I)**5)*(ZP(I)**5)))/ */
/*           ((ZS(I) + ZP(I))**6)) */
/*     FOR THIRD ROW ELEMENTS <3S/R/3P> */
/*     HYF(I)=2629.107682607*(SQRT(((ZS(I)**7)*(ZP(I)**7)))/ */
/*           ((ZS(I) + ZP(I))**8)) */
/*     FOR FOURTH ROW ELEMENTS AND UP : */
/*     HYF(I)=2*(2.10716)*DD(I) */
/*     WHERE DD(I) IS THE CHARGE SEPARATION IN ATOMIC UNITS */


/*     REFERENCES: */
/*     J.A.POPLE & D.L.BEVERIDGE: APPROXIMATE M.O. THEORY */
/*     S.P.MCGLYNN, ET AL: APPLIED QUANTUM CHEMISTRY */

    /* Parameter adjustments */
    --dipvec;

    /* Function Body */

/*  SETUP FOR DIPOLE CALCULATION */

    chrge_(densty_1.p, q2);
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	q[i__ - 1] = core_1.core[molkst_1.nat[i__ - 1] - 1] - q2[i__ - 1];
/* L10: */
    }
    gmetry_(geom_1.geo, coord);

    if (icalcn != numcal_1.numcal) {
	for (i__ = 2; i__ <= 107; ++i__) {
/* L20: */
	    hyf[i__ - 1] = multip_1.dd[i__ - 1] * 5.0832;
	}
	wtmol = 0.;
	sum = 0.;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    wtmol += istope_1.ams[molkst_1.nat[i__ - 1] - 1];
/* L30: */
	    sum += q[i__ - 1];
	}
	chargd = abs(sum) > .5;
	icalcn = numcal_1.numcal;
	ktype = 1;
	if (molmec_1.itype == 4) {
	    ktype = 2;
	}
    }
    if (chargd) {

/*   NEED TO RESET ION'S POSITION SO THAT THE CENTER OF MASS IS AT THE */
/*   ORIGIN. */

/* $DOIT ASIS */
	for (i__ = 1; i__ <= 3; ++i__) {
/* L40: */
	    center[i__ - 1] = 0.;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* $DOIT VBEST */
	    i__1 = molkst_1.numat;
	    for (j = 1; j <= i__1; ++j) {
/* L50: */
		center[i__ - 1] += istope_1.ams[molkst_1.nat[j - 1] - 1] * 
			coord[i__ + j * 3 - 4];
	    }
	}
/* $DOIT ASIS */
	for (i__ = 1; i__ <= 3; ++i__) {
/* L60: */
	    center[i__ - 1] /= wtmol;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
/* $DOIT VBEST */
	    i__1 = molkst_1.numat;
	    for (j = 1; j <= i__1; ++j) {
/* L70: */
		coord[i__ + j * 3 - 4] -= center[i__ - 1];
	    }
	}
    }
/* $DOIT ASIS */
    for (i__ = 1; i__ <= 4; ++i__) {
/* $DOIT ASIS */
	for (j = 1; j <= 3; ++j) {
/* L80: */
	    dip[i__ + (j << 2) - 5] = 0.;
	}
    }
/* $DOIT ASIS */
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ni = molkst_1.nat[i__ - 1];
	ia = molkst_1.nfirst[i__ - 1];
	l = molkst_1.nlast[i__ - 1] - ia;
/* $DOIT ASIS */
	i__2 = l;
	for (j = 1; j <= i__2; ++j) {
	    k = (ia + j) * (ia + j - 1) / 2 + ia;
/* L90: */
	    dip[j + 3] -= hyf[ni + ktype * 107 - 108] * densty_1.p[k - 1];
	}
/* $DOIT ASIS */
	for (j = 1; j <= 3; ++j) {
/* L100: */
	    dip[j - 1] += q[i__ - 1] * 4.803 * coord[j + i__ * 3 - 4];
	}
    }
/* $DOIT ASIS */
    for (j = 1; j <= 3; ++j) {
/* L110: */
	dip[j + 7] = dip[j + 3] + dip[j - 1];
    }
/* $DOIT ASIS */
    for (j = 1; j <= 3; ++j) {
/* L120: */
/* Computing 2nd power */
	d__1 = dip[(j << 2) - 4];
/* Computing 2nd power */
	d__2 = dip[(j << 2) - 3];
/* Computing 2nd power */
	d__3 = dip[(j << 2) - 2];
	dip[(j << 2) - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
    }
    dipvec[1] = -dip[8];
    dipvec[2] = -dip[9];
    dipvec[3] = -dip[10];
/*      WRITE (6,60) ((DIP(I,J),I=1,4),J=1,3) */
/*   60 FORMAT (3(4F10.3)) */
    return 0;

} /* dipind_ */

#undef hyf


