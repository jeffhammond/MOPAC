/* deritr.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal dummy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer ndep, idumys[1080]	/* was [360][3] */;
} geosym_;

#define geosym_1 geosym_

struct {
    integer l1l, l2l, l3l, l1u, l2u, l3u;
} ucell_;

#define ucell_1 ucell_

struct {
    doublereal enuclr;
} enuclr_;

#define enuclr_1 enuclr_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal wj[214770], wk[214770];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    doublereal h__[45150];
} hmatrx_;

#define hmatrx_1 hmatrx_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static doublereal c_b3 = 10.;
static logical c_true = TRUE_;
static logical c_false = FALSE_;
static integer c__1 = 1;

/* Subroutine */ int deritr_(doublereal *errfn, doublereal *geo)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double pow_di(doublereal *, integer *);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
#define w ((doublereal *)&wmatrx_1)
    static doublereal aa, ee;
    static integer ij, ii, il, jl, kl, ll;
    extern /* Subroutine */ int iter_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, logical *, logical *);
    static doublereal xjuc[3];
    static logical debug;
    extern /* Subroutine */ int hcore_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *);
    static doublereal coord[360]	/* was [3][120] */, change[3];
    static integer idelta, linear;
    static doublereal xparam[360], xderiv[3];
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);
    static doublereal xstore;
    extern /* Subroutine */ int symtry_(void);

    /* Fortran I/O blocks */
    static cilist io___24 = { 0, 6, 0, "(' ERROR FUNCTION')", 0 };
    static cilist io___25 = { 0, 6, 0, "(10F8.3)", 0 };


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

/*    DERITR CALCULATES THE DERIVATIVES OF THE ENERGY WITH RESPECT TO THE */
/*          INTERNAL COORDINATES. THIS IS DONE BY FINITE DIFFERENCES */
/*          USING FULL SCF CALCULATIONS. */

/*          THIS IS VERY TIME-CONSUMING, AND SHOULD ONLY BE USED WHEN */
/*          NO OTHER DERIVATIVE CALCULATION WILL DO. */

/*    THE MAIN ARRAYS IN DERIV ARE: */
/*        LOC    INTEGER ARRAY, LOC(1,I) CONTAINS THE ADDRESS OF THE ATOM */
/*               INTERNAL COORDINATE LOC(2,I) IS TO BE USED IN THE */
/*               DERIVATIVE CALCULATION. */
/*        GEO    ARRAY \GEO\ HOLDS THE INTERNAL COORDINATES. */

/* *********************************************************************** */
    /* Parameter adjustments */
    geo -= 4;
    --errfn;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	debug = i_indx(keywrd_1.keywrd, "DERITR", (ftnlen)241, (ftnlen)6) != 
		0;
	icalcn = numcal_1.numcal;

/*   IDELTA IS A MACHINE-PRECISION DEPENDANT INTEGER */

	idelta = -3;
	change[0] = pow_di(&c_b3, &idelta);
	change[1] = pow_di(&c_b3, &idelta);
	change[2] = pow_di(&c_b3, &idelta);

/*    CHANGE(I) IS THE STEP SIZE USED IN CALCULATING THE DERIVATIVES. */
/*    BECAUSE FULL SCF CALCULATIONS ARE BEING DONE QUITE LARGE STEPS */
/*    ARE NEEDED.  ON THE OTHER HAND, THE STEP CANNOT BE VERY LARGE, */
/*    AS THE SECOND DERIVITIVE IN FLEPO IS CALCULATED FROM THE */
/*    DIFFERENCES OF TWO FIRST DERIVATIVES. CHANGE(1) IS FOR CHANGE IN */
/*    BOND LENGTH, (2) FOR ANGLE, AND (3) FOR DIHEDRAL. */

	xderiv[0] = .5 / change[0];
	xderiv[1] = .5 / change[1];
	xderiv[2] = .5 / change[2];
    }
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	xparam[i__ - 1] = geo[geovar_1.loc[(i__ << 1) - 1] + geovar_1.loc[(
		i__ << 1) - 2] * 3];
    }
    if (geosym_1.ndep != 0) {
	symtry_();
    }
    gmetry_(&geo[4], coord);

/*  ESTABLISH THE ENERGY AT THE CURRENT POINT */

    hcore_(coord, hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &enuclr_1.enuclr)
	    ;
    if (molkst_1.norbs * molkst_1.nelecs > 0) {
	iter_(hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &aa, &c_true, &
		c_false);
    } else {
	aa = 0.;
    }
    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;

/*  RESTORE THE DENSITY MATRIX (WHY?) */

    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	densty_1.p[i__ - 1] = densty_1.pa[i__ - 1] * 2.;
    }
    aa += enuclr_1.enuclr;
    ij = 0;
    i__1 = molkst_1.numat;
    for (ii = 1; ii <= i__1; ++ii) {
	i__2 = ucell_1.l1u;
	for (il = ucell_1.l1l; il <= i__2; ++il) {
	    i__3 = ucell_1.l2u;
	    for (jl = ucell_1.l2l; jl <= i__3; ++jl) {
		i__4 = ucell_1.l3u;
		for (kl = ucell_1.l3l; kl <= i__4; ++kl) {
		    for (ll = 1; ll <= 3; ++ll) {
/* L30: */
			xjuc[ll - 1] = coord[ll + ii * 3 - 4] + euler_1.tvec[
				ll - 1] * il + euler_1.tvec[ll + 2] * jl + 
				euler_1.tvec[ll + 5] * kl;
		    }
		    ++ij;
/* L50: */
		}
	    }
	}
/* L60: */
    }
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k = geovar_1.loc[(i__ << 1) - 2];
	l = geovar_1.loc[(i__ << 1) - 1];
	xstore = xparam[i__ - 1];
	i__4 = geovar_1.nvar;
	for (j = 1; j <= i__4; ++j) {
/* L70: */
	    geo[geovar_1.loc[(j << 1) - 1] + geovar_1.loc[(j << 1) - 2] * 3] =
		     xparam[j - 1];
	}
	geo[l + k * 3] = xstore - change[l - 1];
	if (geosym_1.ndep != 0) {
	    symtry_();
	}
	gmetry_(&geo[4], coord);

/*   IF NEEDED, CALCULATE "EXACT" DERIVITIVES. */

	hcore_(coord, hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &
		enuclr_1.enuclr);
	if (molkst_1.norbs * molkst_1.nelecs > 0) {
	    iter_(hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &ee, &c_true, &
		    c_false);
	} else {
	    ee = 0.;
	}
	i__4 = linear;
	for (ii = 1; ii <= i__4; ++ii) {
/* L80: */
	    densty_1.p[ii - 1] = densty_1.pa[ii - 1] * 2.;
	}
	ee += enuclr_1.enuclr;
	errfn[i__] = (aa - ee) * 23.061 * xderiv[l - 1] * 2.;
/* L90: */
    }
    if (debug) {
	s_wsfe(&io___24);
	e_wsfe();
	s_wsfe(&io___25);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&errfn[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    return 0;
} /* deritr_ */

#undef w


