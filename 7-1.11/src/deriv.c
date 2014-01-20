/* deriv.f -- translated by f2c (version 20020621).
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
    logical isok;
} okmany_;

#define okmany_1 okmany_

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
    doublereal cosine;
} gravec_;

#define gravec_1 gravec_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    integer l1l, l2l, l3l, l1u, l2u, l3u;
} ucell_;

#define ucell_1 ucell_

struct {
    doublereal dxyz[1080];
} xyzgra_;

#define xyzgra_1 xyzgra_

struct {
    doublereal enuclr;
} enuclr_;

#define enuclr_1 enuclr_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal h__[45150];
} hmatrx_;

#define hmatrx_1 hmatrx_

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal errfn[360], aicorr[360];
} errfn_;

#define errfn_1 errfn_

struct {
    doublereal work2[180600];
} work3_;

#define work3_1 work3_

struct {
    doublereal coord[360]	/* was [3][120] */, cold[1080]	/* was [3][
	    360] */, gold[360], xparam[360];
} genral_;

#define genral_1 genral_

/* Table of constant values */

static integer c__1 = 1;
static integer c__5 = 5;
static doublereal c_b70 = 10.;
static integer c__9 = 9;
static integer c__6 = 6;

/* Subroutine */ int deriv_(doublereal *geo, doublereal *grad)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2;
    char ch__1[80];
    olist o__1;
    alist al__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), f_open(olist *), f_rew(
	    alist *), s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), 
	    e_rsfe(void), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_rsle(void);
    double pow_di(doublereal *, integer *), sqrt(doublereal);
    integer s_wsle(cilist *), e_wsle(void);

    /* Local variables */
    static integer i__, j;
    static logical ci;
    static integer ii, ij, il, jl, kl, ll, kk;
    static logical aic;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static logical int__;
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);
    static doublereal sum;
    static logical scf1;
    static char line[80];
    static integer ncol;
    static doublereal xjuc[3], step;
    static logical slow;
    static integer icapa;
    static logical halfe, debug;
    extern /* Subroutine */ int dcart_(doublereal *, doublereal *);
    static integer iline;
    static logical geook;
    static doublereal grlim;
    static integer ilowa;
    static doublereal gnorm;
    extern /* Subroutine */ int geout_(integer *);
    static integer ilowz;
    static doublereal change[3], aidref[360];
    static integer idelta;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static logical precis, noanci, aifrst;
    extern /* Subroutine */ int dernvo_(doublereal *, doublereal *), jcarin_(
	    doublereal *, doublereal *, doublereal *, logical *, doublereal *,
	     integer *), gmetry_(doublereal *, doublereal *), deritr_(
	    doublereal *, doublereal *), symtry_(void);

    /* Fortran I/O blocks */
    static cilist io___14 = { 0, 5, 0, "(A)", 0 };
    static cilist io___17 = { 1, 5, 1, "(A)", 0 };
    static cilist io___19 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___20 = { 0, 6, 0, "(A)", 0 };
    static cilist io___21 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___22 = { 0, 6, 0, "(A)", 0 };
    static cilist io___23 = { 0, 6, 0, "(6F12.6)", 0 };
    static cilist io___25 = { 1, 5, 1, 0, 0 };
    static cilist io___26 = { 0, 6, 0, "(/,A,/)", 0 };
    static cilist io___27 = { 0, 6, 0, "(5F12.6)", 0 };
    static cilist io___28 = { 0, 6, 0, "(/,A,/)", 0 };
    static cilist io___29 = { 0, 6, 0, "(5F12.6)", 0 };
    static cilist io___31 = { 0, 6, 0, "(/,A,/)", 0 };
    static cilist io___32 = { 0, 6, 0, "(5F12.6)", 0 };
    static cilist io___37 = { 0, 6, 0, "(' GEO AT START OF DERIV')", 0 };
    static cilist io___38 = { 0, 6, 0, "(F19.5,2F12.5)", 0 };
    static cilist io___42 = { 0, 6, 0, 0, 0 };
    static cilist io___43 = { 0, 6, 0, 0, 0 };
    static cilist io___54 = { 0, 6, 0, "(//,3(A,/),I3,A)", 0 };
    static cilist io___55 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___56 = { 0, 6, 0, 0, 0 };
    static cilist io___57 = { 0, 6, 0, "(' GRADIENTS')", 0 };
    static cilist io___58 = { 0, 6, 0, "(10F8.3)", 0 };
    static cilist io___59 = { 0, 6, 0, "(' ERROR FUNCTION')", 0 };
    static cilist io___60 = { 0, 6, 0, "(10F8.3)", 0 };
    static cilist io___61 = { 0, 6, 0, "(' COSINE OF SEARCH DIRECTION =',F30"
	    ".6)", 0 };


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

/*    DERIV CALCULATES THE DERIVATIVES OF THE ENERGY WITH RESPECT TO THE */
/*          INTERNAL COORDINATES. THIS IS DONE BY FINITE DIFFERENCES. */

/*    THE MAIN ARRAYS IN DERIV ARE: */
/*        LOC    INTEGER ARRAY, LOC(1,I) CONTAINS THE ADDRESS OF THE ATOM */
/*               INTERNAL COORDINATE LOC(2,I) IS TO BE USED IN THE */
/*               DERIVATIVE CALCULATION. */
/*        GEO    ARRAY \GEO\ HOLDS THE INTERNAL COORDINATES. */
/*        GRAD   ON EXIT, CONTAINS THE DERIVATIVES */

/* *********************************************************************** */
    /* Parameter adjustments */
    --grad;
    geo -= 4;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	aifrst = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) ==
		 0;
	debug = i_indx(keywrd_1.keywrd, "DERIV", (ftnlen)241, (ftnlen)5) != 0;
	precis = i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0;
	int__ = i_indx(keywrd_1.keywrd, " XYZ", (ftnlen)241, (ftnlen)4) == 0;
	geook = i_indx(keywrd_1.keywrd, "GEO-OK", (ftnlen)241, (ftnlen)6) != 
		0;
	ci = i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)241, (ftnlen)4) != 0;
	scf1 = i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0;
	aic = i_indx(keywrd_1.keywrd, "AIDER", (ftnlen)241, (ftnlen)5) != 0;
	icapa = 'A';
	ilowa = 'a';
	ilowz = 'z';
	if (aic && aifrst) {
	    o__1.oerr = 0;
	    o__1.ounit = 5;
	    o__1.ofnmlen = 80;
	    getnam_(ch__1, (ftnlen)80, "FOR005", (ftnlen)6);
	    o__1.ofnm = ch__1;
	    o__1.orl = 0;
	    o__1.osta = "OLD";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = "ZERO";
	    f_open(&o__1);
	    al__1.aerr = 0;
	    al__1.aunit = 5;
	    f_rew(&al__1);

/*  ISOK IS SET FALSE: ONLY ONE SYSTEM ALLOWED */

	    okmany_1.isok = FALSE_;
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L10: */
		s_rsfe(&io___14);
		do_fio(&c__1, line, (ftnlen)80);
		e_rsfe();
	    }
	    for (j = 1; j <= 1000; ++j) {
		i__1 = s_rsfe(&io___17);
		if (i__1 != 0) {
		    goto L40;
		}
		i__1 = do_fio(&c__1, line, (ftnlen)80);
		if (i__1 != 0) {
		    goto L40;
		}
		i__1 = e_rsfe();
		if (i__1 != 0) {
		    goto L40;
		}
/* *********************************************************************** */
		for (i__ = 1; i__ <= 80; ++i__) {
		    iline = *(unsigned char *)&line[i__ - 1];
		    if (iline >= ilowa && iline <= ilowz) {
			*(unsigned char *)&line[i__ - 1] = (char) (iline + 
				icapa - ilowa);
		    }
/* L20: */
		}
/* *********************************************************************** */
/* L30: */
		if (i_indx(line, "AIDER", (ftnlen)80, (ftnlen)5) != 0) {
		    goto L60;
		}
	    }
L40:
	    s_wsfe(&io___19);
	    do_fio(&c__1, " KEYWORD \"AIDER\" SPECIFIED, BUT NOT", (ftnlen)35)
		    ;
	    e_wsfe();
	    s_wsfe(&io___20);
	    do_fio(&c__1, " PRESENT AFTER Z-MATRIX.  JOB STOPPED", (ftnlen)37)
		    ;
	    e_wsfe();
	    s_stop("", (ftnlen)0);
L50:
	    s_wsfe(&io___21);
	    do_fio(&c__1, "  FAULT IN READ OF AB INITIO DERIVATIVES", (ftnlen)
		    40);
	    e_wsfe();
	    s_wsfe(&io___22);
	    do_fio(&c__1, "  DERIVATIVES READ IN ARE AS FOLLOWS", (ftnlen)36);
	    e_wsfe();
	    s_wsfe(&io___23);
	    i__1 = i__;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&aidref[j - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_stop("", (ftnlen)0);
L60:
	    if (geokst_1.natoms > 2) {
		j = geokst_1.natoms * 3 - 6;
	    } else {
		j = 1;
	    }
	    i__1 = s_rsle(&io___25);
	    if (i__1 != 0) {
		goto L50;
	    }
	    i__2 = j;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__1 = do_lio(&c__5, &c__1, (char *)&aidref[i__ - 1], (ftnlen)
			sizeof(doublereal));
		if (i__1 != 0) {
		    goto L50;
		}
	    }
	    i__1 = e_rsle();
	    if (i__1 != 0) {
		goto L50;
	    }
	    s_wsfe(&io___26);
	    do_fio(&c__1, " AB-INITIO DERIVATIVES IN KCAL/MOL/(ANGSTROM OR R"
		    "ADIAN)", (ftnlen)55);
	    e_wsfe();
	    s_wsfe(&io___27);
	    i__1 = j;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&aidref[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (geovar_1.loc[(i__ << 1) - 2] > 3) {
		    j = geovar_1.loc[(i__ << 1) - 2] * 3 + geovar_1.loc[(i__ 
			    << 1) - 1] - 9;
		} else if (geovar_1.loc[(i__ << 1) - 2] == 3) {
		    j = geovar_1.loc[(i__ << 1) - 1] + 1;
		} else {
		    j = 1;
		}
/* L70: */
		aidref[i__ - 1] = aidref[j - 1];
	    }
	    s_wsfe(&io___28);
	    do_fio(&c__1, " AB-INITIO DERIVATIVES FOR VARIABLES", (ftnlen)36);
	    e_wsfe();
	    s_wsfe(&io___29);
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&aidref[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    if (geosym_1.ndep != 0) {
		i__1 = geovar_1.nvar;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    sum = aidref[i__ - 1];
		    i__2 = geosym_1.ndep;
		    for (j = 1; j <= i__2; ++j) {
			if (geovar_1.loc[(i__ << 1) - 2] == geosym_1.locpar[j 
				- 1] && (geovar_1.loc[(i__ << 1) - 1] == 
				geosym_1.idepfn[j - 1] || geovar_1.loc[(i__ <<
				 1) - 1] == 3 && geosym_1.idepfn[j - 1] == 14)
				) {
			    aidref[i__ - 1] += sum;
			}
/* L80: */
		    }
/* L90: */
		}
		s_wsfe(&io___31);
		do_fio(&c__1, " AB-INITIO DERIVATIVES AFTER SYMMETRY WEIGHTI"
			"NG", (ftnlen)47);
		e_wsfe();
		s_wsfe(&io___32);
		i__1 = geovar_1.nvar;
		for (j = 1; j <= i__1; ++j) {
		    do_fio(&c__1, (char *)&aidref[j - 1], (ftnlen)sizeof(
			    doublereal));
		}
		e_wsfe();
	    }
	}
	icalcn = numcal_1.numcal;
	if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) == 0) {
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
		errfn_1.errfn[i__ - 1] = 0.;
	    }
	}
	grlim = .01;
	if (precis) {
	    grlim = 1e-4;
	}
	halfe = molkst_1.nopen > molkst_1.nclose && molkst_1.fract != 2. && 
		molkst_1.fract != 0. || ci;
	idelta = -7;

/*   IDELTA IS A MACHINE-PRECISION DEPENDANT INTEGER */

	change[0] = pow_di(&c_b70, &idelta);
	change[1] = pow_di(&c_b70, &idelta);
	change[2] = pow_di(&c_b70, &idelta);

/*    CHANGE(I) IS THE STEP SIZE USED IN CALCULATING THE DERIVATIVES. */
/*    FOR "CARTESIAN" DERIVATIVES, CALCULATED USING DCART,AN */
/*    INFINITESIMAL STEP, HERE 0.000001, IS ACCEPTABLE. IN THE */
/*    HALF-ELECTRON METHOD A QUITE LARGE STEP IS NEEDED AS FULL SCF */
/*    CALCULATIONS ARE NEEDED, AND THE DIFFERENCE BETWEEN THE TOTAL */
/*    ENERGIES IS USED. THE STEP CANNOT BE VERY LARGE, AS THE SECOND */
/*    DERIVITIVE IN FLEPO IS CALCULATED FROM THE DIFFERENCES OF TWO */
/*    FIRST DERIVATIVES. CHANGE(1) IS FOR CHANGE IN BOND LENGTH, */
/*    (2) FOR ANGLE, AND (3) FOR DIHEDRAL. */

    }
    if (geovar_1.nvar == 0) {
	return 0;
    }
    if (debug) {
	s_wsfe(&io___37);
	e_wsfe();
	s_wsfe(&io___38);
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&geo[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    }
    gnorm = 0.;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	genral_1.gold[i__ - 1] = grad[i__];
	genral_1.xparam[i__ - 1] = geo[geovar_1.loc[(i__ << 1) - 1] + 
		geovar_1.loc[(i__ << 1) - 2] * 3];
/* L110: */
/* Computing 2nd power */
	d__1 = grad[i__];
	gnorm += d__1 * d__1;
    }
    gnorm = sqrt(gnorm);
    slow = FALSE_;
    noanci = FALSE_;
    if (halfe) {
	noanci = i_indx(keywrd_1.keywrd, "NOANCI", (ftnlen)241, (ftnlen)6) != 
		0 || molkst_1.nopen == molkst_1.norbs;
	slow = noanci && (gnorm < grlim || scf1);
    }
    if (geosym_1.ndep != 0) {
	symtry_();
    }
    gmetry_(&geo[4], genral_1.coord);

/*  COORD NOW HOLDS THE CARTESIAN COORDINATES */

    if (halfe && ! noanci) {
	if (debug) {
	    s_wsle(&io___42);
	    do_lio(&c__9, &c__1, "DOING ANALYTICAL C.I. DERIVATIVES", (ftnlen)
		    33);
	    e_wsle();
	}
	dernvo_(genral_1.coord, xyzgra_1.dxyz);
    } else {
	if (debug) {
	    s_wsle(&io___43);
	    do_lio(&c__9, &c__1, "DOING VARIATIONALLY OPIMIZED DERIVATIVES", (
		    ftnlen)40);
	    e_wsle();
	}
	dcart_(genral_1.coord, xyzgra_1.dxyz);
    }
    ij = 0;
    i__1 = molkst_1.numat;
    for (ii = 1; ii <= i__1; ++ii) {
	i__2 = ucell_1.l1u;
	for (il = ucell_1.l1l; il <= i__2; ++il) {
	    i__3 = ucell_1.l2u;
	    for (jl = ucell_1.l2l; jl <= i__3; ++jl) {
		i__4 = ucell_1.l3u;
		for (kl = ucell_1.l3l; kl <= i__4; ++kl) {
/* $DOIT ASIS */
		    for (ll = 1; ll <= 3; ++ll) {
/* L120: */
			xjuc[ll - 1] = genral_1.coord[ll + ii * 3 - 4] + 
				euler_1.tvec[ll - 1] * il + euler_1.tvec[ll + 
				2] * jl + euler_1.tvec[ll + 5] * kl;
		    }
		    ++ij;
/* $DOIT ASIS */
		    for (kk = 1; kk <= 3; ++kk) {
			genral_1.cold[kk + ij * 3 - 4] = xjuc[kk - 1];
/* L130: */
		    }
/* L140: */
		}
	    }
	}
/* L150: */
    }
    step = change[0];
    jcarin_(genral_1.coord, genral_1.xparam, &step, &precis, work3_1.work2, &
	    ncol);
    mxm_(work3_1.work2, &geovar_1.nvar, xyzgra_1.dxyz, &ncol, &grad[1], &c__1)
	    ;
    if (precis) {
	step = .5 / step;
    } else {
	step = 1. / step;
    }
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L160: */
	grad[i__] *= step;
    }

/*  NOW TO ENSURE THAT INTERNAL DERIVATIVES ACCURATELY REFLECT CARTESIAN */
/*  DERIVATIVES */

    if (int__ && ! geook && geovar_1.nvar >= molkst_1.numat * 3 - 6 && 
	    euler_1.id == 0) {

/*  NUMBER OF VARIABLES LOOKS O.K. */

	sum = dot_(&grad[1], &grad[1], &geovar_1.nvar);
	i__1 = molkst_1.numat * 3;
/* Computing MAX */
	d__1 = 4., d__2 = sum * 4.;
	if (sum < 2. && dot_(xyzgra_1.dxyz, xyzgra_1.dxyz, &i__1) > max(d__1,
		d__2)) {

/* OOPS, LOOKS LIKE AN ERROR. */

	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		j = (integer) (genral_1.xparam[i__ - 1] / 3.141);
		if (geovar_1.loc[(i__ << 1) - 1] == 2 && geovar_1.loc[(i__ << 
			1) - 2] > 3 && (d__1 = genral_1.xparam[i__ - 1] - j * 
			3.1415926, abs(d__1)) < .005) {

/*  ERROR LOCATED, BUT CANNOT CORRECT IN THIS RUN */

		    s_wsfe(&io___54);
		    do_fio(&c__1, " INTERNAL COORDINATE DERIVATIVES DO NOT R"
			    "EFLECT", (ftnlen)47);
		    do_fio(&c__1, " CARTESIAN COORDINATE DERIVATIVES", (
			    ftnlen)33);
		    do_fio(&c__1, " TO CORRECT ERROR, INCREASE DIHEDRAL OF A"
			    "TOM", (ftnlen)44);
		    do_fio(&c__1, (char *)&geovar_1.loc[(i__ << 1) - 2], (
			    ftnlen)sizeof(integer));
		    do_fio(&c__1, " BY 90 DEGREES", (ftnlen)14);
		    e_wsfe();
		    s_wsfe(&io___55);
		    do_fio(&c__1, "     CURRENT GEOMETRY", (ftnlen)21);
		    e_wsfe();
		    geout_(&c__6);
		    s_stop("", (ftnlen)0);
		}
/* L170: */
	    }
	}
    }

/*  THIS CODE IS ONLY USED IF THE KEYWORD NOANCI IS SPECIFIED */
    if (slow) {
	if (debug) {
	    s_wsle(&io___56);
	    do_lio(&c__9, &c__1, "DOING FULL SCF DERIVATIVES", (ftnlen)26);
	    e_wsle();
	}
	deritr_(errfn_1.errfn, &geo[4]);

/* THE ARRAY ERRFN HOLDS THE EXACT DERIVATIVES MINUS THE APPROXIMATE */
/* DERIVATIVES */
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L180: */
	    errfn_1.errfn[i__ - 1] -= grad[i__];
	}
    }
    gravec_1.cosine = dot_(&grad[1], genral_1.gold, &geovar_1.nvar) / sqrt(
	    dot_(&grad[1], &grad[1], &geovar_1.nvar) * dot_(genral_1.gold, 
	    genral_1.gold, &geovar_1.nvar) + 1e-20);
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L190: */
	grad[i__] += errfn_1.errfn[i__ - 1];
    }
    if (aic) {
	if (aifrst) {
	    aifrst = FALSE_;
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L200: */
		errfn_1.aicorr[i__ - 1] = -aidref[i__ - 1] - grad[i__];
	    }
	}
/* #         WRITE(6,'('' GRADIENTS BEFORE AI CORRECTION'')') */
/* #         WRITE(6,'(10F8.3)')(GRAD(I),I=1,NVAR) */
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L210: */
	    grad[i__] += errfn_1.aicorr[i__ - 1];
	}
    }
/* L220: */
    if (debug) {
	s_wsfe(&io___57);
	e_wsfe();
	s_wsfe(&io___58);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&grad[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	if (slow) {
	    s_wsfe(&io___59);
	    e_wsfe();
	    s_wsfe(&io___60);
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&errfn_1.errfn[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
    }
    if (debug) {
	s_wsfe(&io___61);
	do_fio(&c__1, (char *)&gravec_1.cosine, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* deriv_ */

