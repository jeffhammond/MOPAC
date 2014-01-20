/* force.f -- translated by f2c (version 20020621).
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
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal fmatrx[130681];
    integer idumy2[4];
} fmatrx_;

#define fmatrx_1 fmatrx_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    doublereal cnorml[129600], freq[360], dummy[50640];
} vector_;

#define vector_1 vector_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    integer iflepo, iscf;
} mesage_;

#define mesage_1 mesage_

struct {
    doublereal r__[1680]	/* was [14][120] */;
    integer nsym, ipo[14400]	/* was [120][120] */, nent;
} symops_;

#define symops_1 symops_

struct {
    char simbol[3600];
} simbol_;

#define simbol_1 simbol_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal coord[360]	/* was [3][120] */;
} coord_;

#define coord_1 coord_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

struct {
    doublereal store[129600];
} scrach_;

#define scrach_1 scrach_

/* Table of constant values */

static logical c_true = TRUE_;
static logical c_false = FALSE_;
static integer c__1 = 1;
static doublereal c_b45 = 1.;
static integer c__2 = 2;
static integer c__0 = 0;

/* Subroutine */ int force_(void)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j, k, l, ii, ij, jj, il, jl;
#define gr ((doublereal *)&gradnt_1)
    static integer iu, ju, im1;
    extern /* Subroutine */ int drc_(doublereal *, doublereal *);
    static integer nar[120], nbr[120], ncr[120];
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal rot[9]	/* was [3][3] */, sum;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sym, sum1;
    static integer nto6;
    static doublereal escf;
    extern /* Subroutine */ int fmat_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static integer ilim;
    static doublereal tscf, dipt[360], tder;
    extern /* Subroutine */ int axis_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static integer nvib;
#define keys ((char *)&keywrd_1)
    static doublereal summ;
    static logical prnt;
    static doublereal escf1;
    static integer iinc1, iinc2;
    static doublereal time1, time2, time3;
    static integer nrem6;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical debug, large;
    extern /* Subroutine */ int frame_(doublereal *, integer *, integer *, 
	    doublereal *), flepo_(doublereal *, integer *, doublereal *);
    static doublereal shift[6], trdip[1080]	/* was [3][360] */;
    static integer numat;
    static doublereal const__;
    extern /* Subroutine */ int nllsq_(doublereal *, integer *);
    static doublereal wtmol;
    extern /* Subroutine */ int anavib_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    static doublereal deldip[1080]	/* was [3][360] */, georef[360]	/* 
	    was [3][120] */;
    static logical linear;
    static doublereal redmas[360];
    static integer locold[720]	/* was [2][360] */;
    static logical bartel;
    static integer nvaold;
    static doublereal xparam[360], travel[360];
    static integer ndeold;
    extern doublereal second_(void);
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *), compfg_(
	    doublereal *, logical *, doublereal *, logical *, doublereal *, 
	    logical *), vecprt_(doublereal *, integer *), matout_(doublereal *
	    , doublereal *, integer *, integer *, integer *), freqcy_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, logical *, doublereal *), thermo_(doublereal *, 
	    doublereal *, doublereal *, logical *, doublereal *, doublereal *,
	     doublereal *, integer *, doublereal *), writmo_(doublereal *, 
	    doublereal *);
    static logical restrt;
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___21 = { 0, 6, 0, "(//10X,'HEAT OF FORMATION =',F12.6, "
	    "           ' KCALS/MOLE')", 0 };
    static cilist io___24 = { 0, 6, 0, "(//10X,'INTERNAL COORDINATE DERIVATI"
	    "VES',//3X, 'NUMBER  ATOM',2X,'BOND',9X,'  ANGLE',10X,'DIHEDRAL',"
	    "/)", 0 };
    static cilist io___28 = { 0, 6, 0, "(I6,4X,A2,F13.6,2F13.6)", 0 };
    static cilist io___29 = { 0, 6, 0, "(//10X,'GRADIENT NORM =',F10.5)", 0 };
    static cilist io___30 = { 0, 6, 0, "(///1X,'** GRADIENT IS VERY LARGE, B"
	    "UT SINCE \"LET\"',' IS USED, CALCULATION WILL CONTINUE')", 0 };
    static cilist io___31 = { 0, 6, 0, "(///1X,'** GRADIENT IS TOO LARGE TO "
	    "ALLOW ',               'FORCE MATRIX TO BE CALCULATED, (LIMIT=10"
	    ") **',//)", 0 };
    static cilist io___32 = { 0, 6, 0, "(//10X,' GEOMETRY WILL BE OPTIMIZED "
	    "FIRST')", 0 };
    static cilist io___33 = { 0, 6, 0, "(15X,'USING NLLSQ')", 0 };
    static cilist io___34 = { 0, 6, 0, "(15X,'USING FLEPO')", 0 };
    static cilist io___35 = { 0, 6, 0, "(//10X,'GRADIENT NORM =',F10.7)", 0 };
    static cilist io___40 = { 0, 6, 0, "(//30X,'**** WARNING ****',//       "
	    "                10X,' GRADIENT IS VERY LARGE FOR A THERMO CALCUL"
	    "ATION',/        10X,' RESULTS ARE LIKELY TO BE INACCURATE IF THE"
	    "RE ARE')", 0 };
    static cilist io___41 = { 0, 6, 0, "(10X,' ANY LOW-LYING VIBRATIONS (LES"
	    "S THAN ABOUT '  ,'400CM-1)')", 0 };
    static cilist io___42 = { 0, 6, 0, "(10X,' GRADIENT NORM SHOULD BE LESS "
	    "THAN ABOUT ',   '0.2 FOR THERMO',/10X,' TO GIVE ACCURATE RESULTS"
	    "')", 0 };
    static cilist io___43 = { 0, 6, 0, "(//10X,'TIME FOR SCF CALCULATION =',"
	    "F8.2)", 0 };
    static cilist io___44 = { 0, 6, 0, "(//10X,'TIME FOR DERIVATIVES     =',"
	    "F8.2)", 0 };
    static cilist io___45 = { 0, 6, 0, "(//10X,'SYMMETRY WAS SPECIFIED, BUT "
	    "',              'CANNOT BE USED HERE')", 0 };
    static cilist io___52 = { 0, 6, 0, "(/9X,'ORIENTATION OF MOLECULE IN FOR"
	    "CE CALCULATION')", 0 };
    static cilist io___53 = { 0, 6, 0, "(/,4X,'NO.',7X,'ATOM',9X,'X',       "
	    "            9X,'Y',9X,'Z',/)", 0 };
    static cilist io___54 = { 0, 6, 0, "(I6,7X,I3,4X,3F10.4)", 0 };
    static cilist io___63 = { 0, 6, 0, "(//10X,' FULL FORCE MATRIX, INVOKED "
	    "BY \"DFORCE\"')", 0 };
    static cilist io___64 = { 0, 6, 0, "(//10X,' FORCE MATRIX IN MILLIDYNES/"
	    "ANGSTROM')", 0 };
    static cilist io___65 = { 0, 6, 0, "(//10X,'HEAT OF FORMATION =',F12.6, "
	    "           ' KCALS/MOLE')", 0 };
    static cilist io___67 = { 0, 6, 0, "(//10X,'TRIVIAL VIBRATIONS, SHOULD B"
	    "E ZERO')", 0 };
    static cilist io___68 = { 0, 6, 0, "(/, F9.4,'=TX',F9.4,'=TY',F9.4,'=TZ'"
	    ",                     F9.4,'=RX',F9.4,'=RY',F9.4,'=RZ')", 0 };
    static cilist io___69 = { 0, 6, 0, "(//10X,'FORCE CONSTANTS IN MILLIDYNE"
	    "S/ANGSTROM'  ,' (= 10**5 DYNES/CM)',/)", 0 };
    static cilist io___70 = { 0, 6, 0, "(8F10.5)", 0 };
    static cilist io___71 = { 0, 6, 0, "(//10X,' ASSOCIATED EIGENVECTORS')", 
	    0 };
    static cilist io___75 = { 0, 6, 0, "(//10X,' ZERO POINT ENERGY'         "
	    "                   , F12.3,' KILOCALORIES PER MOLE')", 0 };
    static cilist io___81 = { 0, 6, 0, "(//3X,' THE LAST',I2,' VIBRATIONS AR"
	    "E THE',       ' TRANSLATION AND ROTATION MODES')", 0 };
    static cilist io___82 = { 0, 6, 0, "(3X,' THE FIRST THREE OF THESE BEING"
	    " TRANSLATIONS', ' IN X, Y, AND Z, RESPECTIVELY')", 0 };
    static cilist io___83 = { 0, 6, 0, "(//10X,' FREQUENCIES, REDUCED MASSES"
	    " AND ',         'VIBRATIONAL DIPOLES'/)", 0 };
    static cilist io___87 = { 0, 6, 0, "(/)", 0 };
    static cilist io___89 = { 0, 6, 0, "(3X,'I',10I10)", 0 };
    static cilist io___90 = { 0, 6, 0, "(' FREQ(I)',6F10.4,/)", 0 };
    static cilist io___91 = { 0, 6, 0, "(' MASS(I)',6F10.5,/)", 0 };
    static cilist io___92 = { 0, 6, 0, "(' DIPX(I)',6F10.5)", 0 };
    static cilist io___93 = { 0, 6, 0, "(' DIPY(I)',6F10.5)", 0 };
    static cilist io___94 = { 0, 6, 0, "(' DIPZ(I)',6F10.5,/)", 0 };
    static cilist io___95 = { 0, 6, 0, "(' DIPT(I)',6F10.5)", 0 };
    static cilist io___96 = { 0, 6, 0, "(/)", 0 };
    static cilist io___97 = { 0, 6, 0, "(3X,'I',10I10)", 0 };
    static cilist io___98 = { 0, 6, 0, "(' FREQ(I)',6F10.4)", 0 };
    static cilist io___99 = { 0, 6, 0, "(/,' MASS(I)',6F10.5)", 0 };
    static cilist io___100 = { 0, 6, 0, "(/,' DIPX(I)',6F10.5)", 0 };
    static cilist io___101 = { 0, 6, 0, "(' DIPY(I)',6F10.5)", 0 };
    static cilist io___102 = { 0, 6, 0, "(' DIPZ(I)',6F10.5)", 0 };
    static cilist io___103 = { 0, 6, 0, "(/,' DIPT(I)',6F10.5)", 0 };
    static cilist io___104 = { 0, 6, 0, "(//10X,' NORMAL COORDINATE ANALYSIS"
	    "')", 0 };
    static cilist io___105 = { 0, 6, 0, "(//10X,' MASS-WEIGHTED COORDINATE A"
	    "NALYSIS')", 0 };
    static cilist io___108 = { 0, 6, 0, "(//1X,'THE LOWEST',I3,' VIBRATIONS "
	    "ARE NOT',/,' TO BE USED IN THE THERMO CALCULATION')", 0 };
    static cilist io___109 = { 0, 6, 0, "(//10X,'SYSTEM IS A TRANSITION STAT"
	    "E')", 0 };
    static cilist io___110 = { 0, 6, 0, "(//10X,'SYSTEM IS A GROUND STATE')", 
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
/* ********************************************************************** */

/*   FORCE CALCULATES THE FORCE CONSTANTS FOR THE MOLECULE, AND THE */
/*         VIBRATIONAL FREQUENCIES.  ISOTOPIC SUBSTITUTION IS ALLOWED. */

/* ********************************************************************** */

/* TEST GEOMETRY TO SEE IF IT IS OPTIMIZED */
    time2 = -1e9;
    gmetry_(geom_1.geo, coord_1.coord);
    nvaold = geovar_1.nvar;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	locold[(i__ << 1) - 2] = geovar_1.loc[(i__ << 1) - 2];
/* L10: */
	locold[(i__ << 1) - 1] = geovar_1.loc[(i__ << 1) - 1];
    }
    geovar_1.nvar = 0;
    ndeold = geosym_1.ndep;
    geosym_1.ndep = 0;
    numat = 0;
    if (geokst_1.labels[0] != 99) {
	numat = 1;
    }
    i__1 = geokst_1.natoms;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] == 99) {
	    goto L30;
	}
	if (i__ == 2) {
	    ilim = 1;
	}
	if (i__ == 3) {
	    ilim = 2;
	}
	if (i__ > 3) {
	    ilim = 3;
	}

/*  IS IT A POLYMER? */

	if (geokst_1.labels[i__ - 1] == 107) {
	    ilim = 1;
	} else {
	    ++numat;
	}
/* $DOIT ASIS */
	i__2 = ilim;
	for (j = 1; j <= i__2; ++j) {
	    ++geovar_1.nvar;
	    geovar_1.loc[(geovar_1.nvar << 1) - 2] = i__;
	    geovar_1.loc[(geovar_1.nvar << 1) - 1] = j;
/* L20: */
	    xparam[geovar_1.nvar - 1] = geom_1.geo[j + i__ * 3 - 4];
	}
L30:
	;
    }

/*   IF A RESTART, THEN TSCF AND TDER WILL BE FAULTY, THEREFORE SET TO -1 */

    tscf = -1.;
    tder = -1.;
    prnt = i_indx(keywrd_1.keywrd, "RC=", (ftnlen)241, (ftnlen)3) == 0;
    debug = i_indx(keywrd_1.keywrd, "DFORCE", (ftnlen)241, (ftnlen)6) != 0;
    large = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5) != 0;
    bartel = i_indx(keywrd_1.keywrd, "NLLSQ", (ftnlen)241, (ftnlen)5) != 0;
    restrt = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0;
    time1 = second_();
    if (restrt) {

/*   CHECK TO SEE IF CALCULATION IS IN NLLSQ OR FORCE. */

	if (bartel) {
	    goto L50;
	}

/*   CALCULATION IS IN FORCE */

	goto L90;
    }
    compfg_(xparam, &c_true, &escf, &c_true, gradnt_1.grad, &c_false);
    if (prnt) {
	s_wsfe(&io___21);
	do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    time2 = second_();
    tscf = time2 - time1;
    compfg_(xparam, &c_true, &escf1, &c_false, gradnt_1.grad, &c_true);
    time3 = second_();
    tder = time3 - time2;
    if (prnt) {
	s_wsfe(&io___24);
	e_wsfe();
    }
    l = 0;
    iu = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] == 99) {
	    goto L40;
	}
	++l;
	il = iu + 1;
	if (i__ == 1) {
	    iu = il - 1;
	}
	if (i__ == 2) {
	    iu = il;
	}
	if (i__ == 3) {
	    iu = il + 1;
	}
	if (i__ > 3) {
	    iu = il + 2;
	}
	if (geokst_1.labels[i__ - 1] == 107) {
	    iu = il;
	}
	if (prnt) {
	    s_wsfe(&io___28);
	    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (geokst_1.labels[i__ - 1] - 1 << 
		    1), (ftnlen)2);
	    i__2 = iu;
	    for (j = il; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&gradnt_1.grad[j - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
L40:
	;
    }
/*   TEST SUM OF GRADIENTS */
    gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, &geovar_1.nvar));
    if (prnt) {
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (gradnt_1.gnorm < 10.) {
	goto L70;
    }
    if (i_indx(keywrd_1.keywrd, " LET ", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___30);
	e_wsfe();
	goto L90;
    }
    s_wsfe(&io___31);
    e_wsfe();
L50:
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
	s_copy(simbol_1.simbol + (i__ - 1) * 10, "---", (ftnlen)10, (ftnlen)3)
		;
    }
    s_wsfe(&io___32);
    e_wsfe();
    if (bartel) {
	s_wsfe(&io___33);
	e_wsfe();
	nllsq_(xparam, &geovar_1.nvar);
    } else {
	s_wsfe(&io___34);
	e_wsfe();
	flepo_(xparam, &geovar_1.nvar, &escf);

/*  DID FLEPO USE ALL THE TIME ALLOWED? */

	if (mesage_1.iflepo == -1) {
	    return 0;
	}
    }
    scftyp_1.limscf = FALSE_;
    compfg_(xparam, &c_true, &escf, &c_true, gradnt_1.grad, &c_true);
    writmo_(&time1, &escf);
    s_wsfe(&io___35);
    do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
    e_wsfe();
    gmetry_(geom_1.geo, coord_1.coord);
L70:
    i__1 = geokst_1.natoms;
    for (j = 1; j <= i__1; ++j) {
	nar[j - 1] = geokst_1.na[j - 1];
	nbr[j - 1] = geokst_1.nb[j - 1];
	ncr[j - 1] = geokst_1.nc[j - 1];
	for (i__ = 1; i__ <= 3; ++i__) {
/* L80: */
	    georef[i__ + j * 3 - 4] = geom_1.geo[i__ + j * 3 - 4];
	}
    }

/* NOW TO CALCULATE THE FORCE MATRIX */

/* CHECK OUT SYMMETRY */
L90:

/*   NEED TO ENSURE THAT XYZINT WILL WORK CORRECTLY BEFORE CALL */
/*   TO DRC. */

    l = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] != 99) {
	    ++l;
	    geokst_1.labels[l - 1] = geokst_1.labels[i__ - 1];
	}
/* L100: */
    }
    geokst_1.natoms = numat;
    xyzint_(coord_1.coord, &numat, geokst_1.na, geokst_1.nb, geokst_1.nc, &
	    c_b45, geom_1.geo);
    gmetry_(geom_1.geo, coord_1.coord);
    if (i_indx(keywrd_1.keywrd, "THERMO", (ftnlen)241, (ftnlen)6) != 0 && 
	    gradnt_1.gnorm > 1.) {
	s_wsfe(&io___40);
	e_wsfe();
	s_wsfe(&io___41);
	e_wsfe();
	s_wsfe(&io___42);
	e_wsfe();
    }
    if (tscf > 0.) {
	s_wsfe(&io___43);
	do_fio(&c__1, (char *)&tscf, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___44);
	do_fio(&c__1, (char *)&tder, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (geosym_1.ndep > 0) {
	s_wsfe(&io___45);
	e_wsfe();
	geosym_1.ndep = 0;
    }
    if (prnt) {
	axis_(coord_1.coord, &numat, &a, &b, &c__, &wtmol, &c__2, rot);
    }
    nvib = numat * 3 - 6;
    if (abs(c__) < 1e-20) {
	++nvib;
    }
    if (euler_1.id != 0) {
	nvib = numat * 3 - 3;
    }
    if (prnt) {
	s_wsfe(&io___52);
	e_wsfe();
	s_wsfe(&io___53);
	e_wsfe();
    }
    l = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] == 99) {
	    goto L110;
	}
	++l;
	if (prnt) {
	    s_wsfe(&io___54);
	    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&geokst_1.labels[i__ - 1], (ftnlen)sizeof(
		    integer));
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&coord_1.coord[j + l * 3 - 4], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
L110:
	;
    }
    fmat_(fmatrx_1.fmatrx, &nvib, &tscf, &tder, deldip, &escf);
    geokst_1.na[0] = 0;
    i__1 = geokst_1.natoms;
    for (j = 1; j <= i__1; ++j) {
	geokst_1.na[j - 1] = nar[j - 1];
	geokst_1.nb[j - 1] = nbr[j - 1];
	geokst_1.nc[j - 1] = ncr[j - 1];
	for (i__ = 1; i__ <= 3; ++i__) {
/* L120: */
	    geom_1.geo[i__ + j * 3 - 4] = georef[i__ + j * 3 - 4];
	}
    }
    if (nvib < 0) {
	geosym_1.ndep = ndeold;
	geovar_1.nvar = 0;
	return 0;
    }

/*   THE FORCE MATRIX IS PRINTED AS AN ATOM-ATOM MATRIX RATHER THAN */
/*   AS A 3N*3N MATRIX, AS THE 3N MATRIX IS VERY CONFUSING! */

    ij = 0;
    iu = 0;
    i__1 = numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	il = iu + 1;
	iu = il + 2;
	im1 = i__ - 1;
	ju = 0;
	i__2 = im1;
	for (j = 1; j <= i__2; ++j) {
	    jl = ju + 1;
	    ju = jl + 2;
	    sum = 0.;
/* $DOIT ASIS */
	    i__3 = iu;
	    for (ii = il; ii <= i__3; ++ii) {
/* $DOIT ASIS */
		i__4 = ju;
		for (jj = jl; jj <= i__4; ++jj) {
/* L130: */
/* Computing 2nd power */
		    d__1 = fmatrx_1.fmatrx[ii * (ii - 1) / 2 + jj - 1];
		    sum += d__1 * d__1;
		}
	    }
	    ++ij;
/* L140: */
	    scrach_1.store[ij - 1] = sqrt(sum);
	}
	++ij;
/* L150: */
/* Computing 2nd power */
	d__1 = fmatrx_1.fmatrx[il * (il + 1) / 2 - 1];
/* Computing 2nd power */
	d__2 = fmatrx_1.fmatrx[(il + 1) * (il + 2) / 2 - 1];
/* Computing 2nd power */
	d__3 = fmatrx_1.fmatrx[(il + 2) * (il + 3) / 2 - 1];
/* Computing 2nd power */
	d__4 = fmatrx_1.fmatrx[(il + 1) * (il + 2) / 2 - 2];
/* Computing 2nd power */
	d__5 = fmatrx_1.fmatrx[(il + 2) * (il + 3) / 2 - 3];
/* Computing 2nd power */
	d__6 = fmatrx_1.fmatrx[(il + 2) * (il + 3) / 2 - 2];
	scrach_1.store[ij - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3 
		+ (d__4 * d__4 + d__5 * d__5 + d__6 * d__6) * 2.);
    }
    if (debug) {
	s_wsfe(&io___63);
	e_wsfe();
	i__ = -geovar_1.nvar;
	vecprt_(fmatrx_1.fmatrx, &i__);
    }
    if (prnt) {
	s_wsfe(&io___64);
	e_wsfe();
	vecprt_(scrach_1.store, &numat);
    }
    l = geovar_1.nvar * (geovar_1.nvar + 1) / 2;
    i__1 = l;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L160: */
	scrach_1.store[i__ - 1] = fmatrx_1.fmatrx[i__ - 1];
    }
    if (prnt) {
	axis_(coord_1.coord, &numat, &a, &b, &c__, &sum, &c__0, rot);
    }
    if (prnt) {
	s_wsfe(&io___65);
	do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (large) {
	frame_(scrach_1.store, &numat, &c__0, shift);
	rsp_(scrach_1.store, &geovar_1.nvar, &geovar_1.nvar, vector_1.freq, 
		vector_1.cnorml);
	i__1 = geovar_1.nvar;
	for (i__ = nvib + 1; i__ <= i__1; ++i__) {
	    j = (integer) ((vector_1.freq[i__ - 1] + 50.) * .01);
/* L170: */
	    vector_1.freq[i__ - 1] -= j * 100;
	}
	if (prnt) {
	    s_wsfe(&io___67);
	    e_wsfe();
	    s_wsfe(&io___68);
	    i__1 = geovar_1.nvar;
	    for (i__ = nvib + 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&vector_1.freq[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___69);
	    e_wsfe();
	    s_wsfe(&io___70);
	    i__1 = nvib;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&vector_1.freq[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
/* CONVERT TO WEIGHTED FMAT */
	    s_wsfe(&io___71);
	    e_wsfe();
	    i__ = -geovar_1.nvar;
	    matout_(vector_1.cnorml, vector_1.freq, &nvib, &i__, &
		    geovar_1.nvar);
	}
    }
    freqcy_(fmatrx_1.fmatrx, vector_1.freq, vector_1.cnorml, redmas, travel, &
	    c_true, deldip);

/*  CALCULATE ZERO POINT ENERGY */


/*  THESE CONSTANTS TAKEN FROM HANDBOOK OF CHEMISTRY AND PHYSICS 62ND ED. */
/*   N AVOGADRO'S NUMBER = 6.022045*10**23 */
/*   H PLANCK'S CONSTANT = 6.626176*10**(-34)JHZ */
/*   C SPEED OF LIGHT    = 2.99792458*10**10 CM/SEC */
/*   CONST=0.5*N*H*C/(1000*4.184) */
    const__ = .0014295718;
    sum = 0.;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L180: */
	sum += vector_1.freq[i__ - 1];
    }
    sum *= const__;
    if (prnt) {
	s_wsfe(&io___75);
	do_fio(&c__1, (char *)&sum, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    summ = 0.;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum1 = 1e-20;
/* $DOIT VBEST */
	i__2 = geovar_1.nvar;
	for (j = 1; j <= i__2; ++j) {
/* L190: */
/* Computing 2nd power */
	    d__1 = vector_1.cnorml[j + (i__ - 1) * geovar_1.nvar - 1];
	    sum1 += d__1 * d__1;
	}
	sum1 = 1. / sqrt(sum1);
/* $DOIT ASIS */
	for (k = 1; k <= 3; ++k) {
/* L200: */
	    gradnt_1.grad[k - 1] = 0.;
	}
/* $DOIT ASIS */
	for (k = 1; k <= 3; ++k) {
	    sum = 0.;
/* $DOIT VBEST */
	    i__2 = geovar_1.nvar;
	    for (j = 1; j <= i__2; ++j) {
/* L210: */
		sum += vector_1.cnorml[j + (i__ - 1) * geovar_1.nvar - 1] * 
			deldip[k + j * 3 - 4];
	    }
	    summ += abs(sum);
/* L220: */
	    trdip[k + i__ * 3 - 4] = sum * sum1;
	}
/* Computing 2nd power */
	d__1 = trdip[i__ * 3 - 3];
/* Computing 2nd power */
	d__2 = trdip[i__ * 3 - 2];
/* Computing 2nd power */
	d__3 = trdip[i__ * 3 - 1];
	dipt[i__ - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* L230: */
    }
    if (prnt) {
	s_wsfe(&io___81);
	i__1 = geovar_1.nvar - nvib;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___82);
	e_wsfe();
    }
    if (prnt && large) {
	s_wsfe(&io___83);
	e_wsfe();
	nto6 = geovar_1.nvar / 6;
	nrem6 = geovar_1.nvar - nto6 * 6;
	iinc1 = -5;
	if (nto6 < 1) {
	    goto L250;
	}
	i__1 = nto6;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_wsfe(&io___87);
	    e_wsfe();
	    iinc1 += 6;
	    iinc2 = iinc1 + 5;
	    s_wsfe(&io___89);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	    s_wsfe(&io___90);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&vector_1.freq[j - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___91);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&redmas[j - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___92);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&trdip[j * 3 - 3], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___93);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&trdip[j * 3 - 2], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___94);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&trdip[j * 3 - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___95);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&dipt[j - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_wsfe();
/* L240: */
	}
L250:
	if (nrem6 < 1) {
	    goto L260;
	}
	s_wsfe(&io___96);
	e_wsfe();
	iinc1 += 6;
	iinc2 = iinc1 + (nrem6 - 1);
	s_wsfe(&io___97);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	s_wsfe(&io___98);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&vector_1.freq[j - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___99);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&redmas[j - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___100);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&trdip[j * 3 - 3], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___101);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&trdip[j * 3 - 2], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___102);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&trdip[j * 3 - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___103);
	i__1 = iinc2;
	for (j = iinc1; j <= i__1; ++j) {
	    do_fio(&c__1, (char *)&dipt[j - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
L260:
	;
    }
    if (prnt) {
	s_wsfe(&io___104);
	e_wsfe();
	i__ = -geovar_1.nvar;
	matout_(vector_1.cnorml, vector_1.freq, &geovar_1.nvar, &i__, &
		geovar_1.nvar);
    }

/*   CARRY OUT IRC IF REQUESTED. */

    if (i_indx(keywrd_1.keywrd, "IRC", (ftnlen)241, (ftnlen)3) + i_indx(
	    keywrd_1.keywrd, "DRC", (ftnlen)241, (ftnlen)3) == 677) {
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    geovar_1.loc[(i__ << 1) - 2] = 0;
/* L270: */
	    geovar_1.loc[(i__ << 1) - 1] = 0;
	}
	geovar_1.nvar = nvaold;
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    geovar_1.loc[(i__ << 1) - 2] = locold[(i__ << 1) - 2];
/* L280: */
	    geovar_1.loc[(i__ << 1) - 1] = locold[(i__ << 1) - 1];
	}
	xyzint_(coord_1.coord, &numat, geokst_1.na, geokst_1.nb, geokst_1.nc, 
		&c_b45, geom_1.geo);
	last_1.last = 1;
	drc_(vector_1.cnorml, vector_1.freq);
	geokst_1.na[0] = 0;
	geosym_1.ndep = ndeold;
	geovar_1.nvar = 0;
	for (i__ = 1; i__ <= 3; ++i__) {
	    i__1 = geokst_1.natoms;
	    for (j = 1; j <= i__1; ++j) {
/* L290: */
		geom_1.geo[i__ + j * 3 - 4] = georef[i__ + j * 3 - 4];
	    }
	}
	return 0;
    }
    freqcy_(fmatrx_1.fmatrx, vector_1.freq, vector_1.cnorml, deldip, deldip, &
	    c_false, deldip);
    s_wsfe(&io___105);
    e_wsfe();
    i__ = -geovar_1.nvar;
    matout_(vector_1.cnorml, vector_1.freq, &geovar_1.nvar, &i__, &
	    geovar_1.nvar);
    anavib_(coord_1.coord, vector_1.freq, dipt, &geovar_1.nvar, 
	    vector_1.cnorml, scrach_1.store, fmatrx_1.fmatrx, travel, redmas);
    if (i_indx(keywrd_1.keywrd, "THERMO", (ftnlen)241, (ftnlen)6) != 0) {
	gmetry_(geom_1.geo, coord_1.coord);
	i__ = i_indx(keywrd_1.keywrd, " ROT", (ftnlen)241, (ftnlen)4);
	if (i__ != 0) {
	    sym = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
	} else {
	    sym = 1.;
	}
	linear = (d__1 = a * b * c__, abs(d__1)) < 1e-10;
	i__ = i_indx(keywrd_1.keywrd, " TRANS", (ftnlen)241, (ftnlen)6);

/*   "I" IS GOING TO MARK THE BEGINNING OF THE GENUINE VIBRATIONS. */

	if (i__ != 0) {
	    i__ = i_indx(keywrd_1.keywrd, " TRANS=", (ftnlen)241, (ftnlen)7);
	    if (i__ != 0) {
		i__ = (integer) (reada_(keywrd_1.keywrd, &i__, (ftnlen)241) + 
			1);
		j = nvib - i__ + 1;
		s_wsfe(&io___108);
		i__1 = i__ - 1;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		e_wsfe();
	    } else {
		s_wsfe(&io___109);
		e_wsfe();
		i__ = 2;
		j = nvib - 1;
	    }
	} else {
	    s_wsfe(&io___110);
	    e_wsfe();
	    i__ = 1;
	    j = nvib;
	}
	thermo_(&a, &b, &c__, &linear, &sym, &wtmol, &vector_1.freq[i__ - 1], 
		&j, &escf);
    }
    geokst_1.na[0] = 0;
    geovar_1.nvar = 0;
    geosym_1.ndep = ndeold;
    for (i__ = 1; i__ <= 3; ++i__) {
	i__1 = geokst_1.natoms;
	for (j = 1; j <= i__1; ++j) {
/* L300: */
	    geom_1.geo[i__ + j * 3 - 4] = georef[i__ + j * 3 - 4];
	}
    }
    return 0;
} /* force_ */

#undef keys
#undef gr


