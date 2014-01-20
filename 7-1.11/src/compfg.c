/* compfg.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal dumy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    doublereal wj[214770], wk[214770];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    doublereal enuclr;
} enuclr_;

#define enuclr_1 enuclr_

struct {
    integer nztype[107], mtype[30], ltype;
} natype_;

#define natype_1 natype_

struct {
    doublereal elect;
} elect_;

#define elect_1 elect_

struct {
    doublereal rxyz[45150], xdumy[84450];
} scrach_;

#define scrach_1 scrach_

struct {
    doublereal h__[45150];
} hmatrx_;

#define hmatrx_1 hmatrx_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal errfn[360], aicorr[360];
} errfn_;

#define errfn_1 errfn_

struct {
    doublereal c__[90000], eigs[300], cbeta[90000], eigb[300];
} vector_;

#define vector_1 vector_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

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
    logical iseps, useps, upda;
} iseps_;

#define iseps_1 iseps_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;
static logical c_true = TRUE_;

/* Subroutine */ int compfg_(doublereal *xparam, logical *int__, doublereal *
	escf, logical *fulscf, doublereal *grad, logical *lgrad)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;
    alist al__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void), f_rew(alist *);
    double sin(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
#define w ((doublereal *)&wmatrx_1)
    extern /* Subroutine */ int btoc_(doublereal *), iter_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, logical *,
	     logical *), dihed_(doublereal *, integer *, integer *, integer *,
	     integer *, doublereal *);
    static logical aider, debug;
    static doublereal angle;
    static logical large, force;
    static doublereal delta[2400];
    extern /* Subroutine */ int hcore_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *), mecip_(doublereal *,
	     integer *, doublereal *, doublereal *);
    static doublereal coord[360]	/* was [3][120] */;
    extern /* Subroutine */ int deriv_(doublereal *, doublereal *), timer_(
	    char *, ftnlen);
    static logical times, print;
    static doublereal degree[3];
    static logical usedci, analyt;
    static doublereal xparef[360], deltap[64];
    extern /* Subroutine */ int setupg_(void), gmetry_(doublereal *, 
	    doublereal *);
    static integer indeps;
    extern /* Subroutine */ int initsv_(integer *), consts_(doublereal *), 
	    symtry_(void);

    /* Fortran I/O blocks */
    static cilist io___17 = { 0, 6, 0, "(' INTERNAL COORDS',/100(/,3F12.6))", 
	    0 };
    static cilist io___19 = { 0, 6, 0, "(' CARTESIAN COORDS',/100(/,3F16.9))",
	     0 };
    static cilist io___22 = { 0, 6, 0, "(/10X,' HEAT OF FORMATION',G30.17)", 
	    0 };
    static cilist io___23 = { 0, 6, 0, "(' GRADIENT       ',8F8.2,(/10F8.2))",
	     0 };


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
/* COSMO change A. Klamt */
/* end of COSMO change */
/* *********************************************************************** */

/*   COMPFG CALCULATES (A) THE HEAT OF FORMATION OF THE SYSTEM, AND */
/*                     (B) THE GRADIENTS, IF LGRAD IS .TRUE. */

/*   ON INPUT  XPARAM = ARRAY OF PARAMETERS TO BE USED IN INTERNAL COORDS */
/*             LGRAD  = .TRUE. IF GRADIENTS ARE NEEDED, .FALSE. OTHERWISE */
/*             INT    = .TRUE. IF HEAT OF FORMATION IS TO BE CALCULATED */
/*             FULSCF = .TRUE. IF FULL SCF TO BE DONE, .FALSE. OTHERWISE. */

/*   ON OUTPUT ESCF  = HEAT OF FORMATION. */
/*             GRAD   = ARRAY OF GRADIENTS, IF LGRAD = .TRUE. */

/* *********************************************************************** */
    /* Parameter adjustments */
    --grad;
    --xparam;

    /* Function Body */
/*                 MNDO     AM1      PM3      MINDO/ */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	molmec_1.htype[0] = 6.1737;
	molmec_1.htype[1] = 3.3191;
	molmec_1.htype[2] = 7.1853;
	molmec_1.htype[3] = 1.7712;
	natype_1.ltype = 0;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (molkst_1.nat[i__ - 1] < 99) {
		i__2 = natype_1.ltype;
		for (j = 1; j <= i__2; ++j) {
/* L10: */
		    if (molkst_1.nat[i__ - 1] == natype_1.mtype[j - 1]) {
			goto L20;
		    }
		}
		++natype_1.ltype;
		natype_1.mtype[natype_1.ltype - 1] = molkst_1.nat[i__ - 1];
		natype_1.nztype[molkst_1.nat[i__ - 1] - 1] = natype_1.ltype;

/*       LTYPE = NUMBER OF TYPES OF REAL ATOM PRESENT */
/*       MTYPE = TYPES OF REAL ATOMS PRESENT */
		j = natype_1.ltype;
L20:
		;
	    }
/* L30: */
	}
	aider = i_indx(keywrd_1.keywrd, "AIDER", (ftnlen)241, (ftnlen)5) != 0;
	times = i_indx(keywrd_1.keywrd, "TIMES", (ftnlen)241, (ftnlen)5) != 0;
	analyt = i_indx(keywrd_1.keywrd, "ANALYT", (ftnlen)241, (ftnlen)6) != 
		0;
	if (*int__ && analyt) {
	    setupg_();
	}
	degree[0] = 1.;
	if (i_indx(keywrd_1.keywrd, " XYZ", (ftnlen)241, (ftnlen)4) != 0) {
	    degree[1] = 1.;
	} else {
	    degree[1] = 57.295779531334603;
	}
	degree[2] = degree[1];
	usedci = molkst_1.nclose != molkst_1.nopen && molkst_1.fract != 2. && 
		molkst_1.fract != 0. || i_indx(keywrd_1.keywrd, "C.I.", (
		ftnlen)241, (ftnlen)4) != 0;
	force = i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0;
	large = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5) != 0;
	print = i_indx(keywrd_1.keywrd, "COMPFG", (ftnlen)241, (ftnlen)6) != 
		0;
	debug = i_indx(keywrd_1.keywrd, "DEBUG", (ftnlen)241, (ftnlen)5) != 0 
		&& print;
	scftyp_1.emin = 0.;
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	    xparef[i__ - 1] = xparam[i__];
	}
    }

/* SET UP COORDINATES FOR CURRENT CALCULATION */

/*       PLACE THE NEW VALUES OF THE VARIABLES IN THE ARRAY GEO. */
/*       MAKE CHANGES IN THE GEOMETRY. */
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k = geovar_1.loc[(i__ << 1) - 2];
	l = geovar_1.loc[(i__ << 1) - 1];
/* L50: */
	geom_1.geo[l + k * 3 - 4] = xparam[i__];
    }
/*      IMPOSE THE SYMMETRY CONDITIONS + COMPUTE THE DEPENDENT-PARAMETERS */
    if (geosym_1.ndep != 0) {
	symtry_();
    }
/*      NOW COMPUTE THE ATOMIC COORDINATES. */
    if (debug) {
	if (large) {
	    k = geokst_1.natoms;
	} else {
	    k = min(5,geokst_1.natoms);
	}
	s_wsfe(&io___17);
	i__1 = k;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		d__1 = geom_1.geo[j + i__ * 3 - 4] * degree[j - 1];
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    }
	}
	e_wsfe();
    }
    gmetry_(geom_1.geo, coord);
    if (debug) {
	if (large) {
	    k = molkst_1.numat;
	} else {
	    k = min(5,molkst_1.numat);
	}
	s_wsfe(&io___19);
	i__1 = k;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&coord[j + i__ * 3 - 4], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    }
    if (*int__ && analyt) {
	al__1.aerr = 0;
	al__1.aunit = 2;
	f_rew(&al__1);
    }
/* COSMO change A. Klamt */
/*     IF (.NOT. USEPS) THEN */
    if (! iseps_1.iseps) {
/* end of COSMO change */
	if (times) {
	    timer_("BEFORE HCORE", (ftnlen)12);
	}
	if (*int__) {
	    hcore_(coord, hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &
		    enuclr_1.enuclr);
	}
	if (times) {
	    timer_("AFTER HCORE", (ftnlen)11);
	}

/* COMPUTE THE HEAT OF FORMATION. */

	if (molkst_1.norbs > 0 && molkst_1.nelecs > 0) {
	    if (times) {
		timer_("BEFORE ITER", (ftnlen)11);
	    }
	    if (*int__) {
		iter_(hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &
			elect_1.elect, fulscf, &c_true);
	    }
	    if (times) {
		timer_("AFTER ITER", (ftnlen)10);
	    }
	} else {
	    elect_1.elect = 0.;
	}
	*escf = (elect_1.elect + enuclr_1.enuclr) * 23.061 + atheat_1.atheat;
	if (*escf < scftyp_1.emin || scftyp_1.emin == 0.) {
	    scftyp_1.emin = *escf;
	}
	i__1 = molmec_1.nnhco;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    dihed_(coord, &molmec_1.nhco[(i__ << 2) - 4], &molmec_1.nhco[(i__ 
		    << 2) - 3], &molmec_1.nhco[(i__ << 2) - 2], &
		    molmec_1.nhco[(i__ << 2) - 1], &angle);
/* Computing 2nd power */
	    d__1 = sin(angle);
	    *escf += molmec_1.htype[molmec_1.itype - 1] * (d__1 * d__1);
/* L60: */
	}
/* COSMO change A. Klamt 18.7.91 */
    }
    if (iseps_1.iseps) {
	indeps = i_indx(keywrd_1.keywrd, "EPS=", (ftnlen)241, (ftnlen)4);
	initsv_(&indeps);
/* The following routine constructs the dielectric screening surface */
	consts_(coord);
/* The following routine constructs dielectric response matrix CCMAT */
	btoc_(coord);
/* A. Klamt 18.7.91 */
	iseps_1.useps = TRUE_;
	if (times) {
	    timer_("BEFORE HCORE", (ftnlen)12);
	}
	if (*int__) {
	    hcore_(coord, hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &
		    enuclr_1.enuclr);
	}
	if (times) {
	    timer_("AFTER HCORE", (ftnlen)11);
	}

/* COMPUTE THE HEAT OF FORMATION. */

	if (molkst_1.norbs > 0 && molkst_1.nelecs > 0) {
	    if (times) {
		timer_("BEFORE ITER", (ftnlen)11);
	    }
	    if (*int__) {
		iter_(hmatrx_1.h__, w, wmatrx_1.wj, wmatrx_1.wk, &
			elect_1.elect, fulscf, &c_true);
	    }
	    if (times) {
		timer_("AFTER ITER", (ftnlen)10);
	    }
	} else {
	    elect_1.elect = 0.;
	}
	*escf = (elect_1.elect + enuclr_1.enuclr) * 23.061 + atheat_1.atheat;
	if (*escf < scftyp_1.emin || scftyp_1.emin == 0.) {
	    scftyp_1.emin = *escf;
	}
	i__1 = molmec_1.nnhco;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    dihed_(coord, &molmec_1.nhco[(i__ << 2) - 4], &molmec_1.nhco[(i__ 
		    << 2) - 3], &molmec_1.nhco[(i__ << 2) - 2], &
		    molmec_1.nhco[(i__ << 2) - 1], &angle);
/* Computing 2nd power */
	    d__1 = sin(angle);
	    *escf += molmec_1.htype[molmec_1.itype - 1] * (d__1 * d__1);
/* L61: */
	}
    }
/* end of COSMO change */

/* FIND DERIVATIVES IF DESIRED */

    if (*lgrad) {
	if (times) {
	    timer_("BEFORE DERIV", (ftnlen)12);
	}
	deriv_(geom_1.geo, &grad[1]);
	if (times) {
	    timer_("AFTER DERIV", (ftnlen)11);
	}
    }
    if (aider) {

/*  ADD IN AB INITIO CORRECTION */

	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L70: */
	    *escf += (xparam[i__] - xparef[i__ - 1]) * errfn_1.aicorr[i__ - 1]
		    ;
	}
    }
    if (*int__ && print) {
	s_wsfe(&io___22);
	do_fio(&c__1, (char *)&(*escf), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (print && *lgrad) {
	s_wsfe(&io___23);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&grad[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }

/* REFORM DENSITY MATRIX, IF A C.I. DONE AND EITHER THE LAST SCF OR A */
/* FORCE CALCULATION */

    if (usedci && (last_1.last == 1 || force)) {
	mecip_(vector_1.c__, &molkst_1.norbs, deltap, delta);
    }
    return 0;
} /* compfg_ */

#undef w


