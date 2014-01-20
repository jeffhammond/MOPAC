/* polar.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal x1[90000]	/* was [300][300] */, x2[90000]	/* was [300][
	    300] */, x3[90000]	/* was [300][300] */, x4[90000]	/* was [300][
	    300] */, x5[90000]	/* was [300][300] */, x6[90000]	/* was [300][
	    300] */, x7[90000]	/* was [300][300] */, x8[90000]	/* was [300][
	    300] */, x9[90000]	/* was [300][300] */, x10[90000]	/* 
	    was [300][300] */, xdumy[48150];
} work1_;

#define work1_1 work1_

struct {
    doublereal x11[90000]	/* was [300][300] */, x12[90000]	/* 
	    was [300][300] */, xdumy1[600];
} work3_;

#define work3_1 work3_

struct {
    doublereal x13[90000]	/* was [300][300] */, xdumy2[39600];
} scrach_;

#define scrach_1 scrach_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

struct {
    doublereal polvol[107];
} polvol_;

#define polvol_1 polvol_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

struct {
    doublereal time0;
} timcom_;

#define timcom_1 timcom_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    doublereal geo[360]	/* was [3][120] */, coord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer idtvec;
} euler_;

#define euler_1 euler_

struct {
    doublereal omega;
} omval_;

#define omval_1 omval_

struct {
    integer ifiles[30];
} chanel_;

#define chanel_1 chanel_

struct {
    doublereal c__[90000], eigs[300], ca[90000], dumy[300];
} vector_;

#define vector_1 vector_

struct {
    doublereal w[429540];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    integer idaf, irecln, irecst, ifilen[145], ioda[145];
} iodaf_;

#define iodaf_1 iodaf_

struct {
    doublereal fn1[107], fn2[107];
} gauss_;

#define gauss_1 gauss_

struct {
    doublereal uspd[300], dumy[300];
} molorb_;

#define molorb_1 molorb_

struct {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
} twoele_;

#define twoele_1 twoele_

struct {
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

struct {
    char jobnam[80];
} jobnam_;

#define jobnam_1 jobnam_

/* Table of constant values */

static integer c__1 = 1;
static logical c_true = TRUE_;
static logical c_false = FALSE_;
static integer c__0 = 0;
static integer c__2 = 2;
static doublereal c_b176 = .5;
static integer c__145 = 145;
static integer c__8 = 8;
static integer c__9 = 9;
static integer c__10 = 10;
static integer c__11 = 11;
static integer c__12 = 12;
static integer c__13 = 13;
static integer c__14 = 14;
static integer c__15 = 15;
static integer c__16 = 16;
static integer c__17 = 17;
static integer c__18 = 18;
static integer c__19 = 19;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__5 = 5;
static integer c__6 = 6;
static integer c__7 = 7;

/* Subroutine */ int polar_(void)
{
    /* Format strings */
    static char fmt_10[] = "(\0021\002,20(\002*\002),\002 TDHF POLARIZABILIT"
	    "IES \002,20(\002*\002),//)";
    static char fmt_20[] = "(/\002 ROTATION MATRIX FOR ORIENTATION OF MOLECU"
	    "LE:\002/)";
    static char fmt_30[] = "(5x,3f12.6)";
    static char fmt_160[] = "(/\002 NEW TRANSLATION VECTOR:\002/,\002 \002,3"
	    "(3f15.5))";
    static char fmt_200[] = "(//\002 ENERGY OF \"REORIENTED\" SYSTEM WITHOUT"
	    " FIELD:\002,f20.10)";
    static char fmt_240[] = "(//\002  NFREQ=\002,i3,\002  IWFLB=\002,i3,\002"
	    "  IBET=\002,i3,\002  IGAM=\002,i3)";
    static char fmt_250[] = "(\002  ATOL=\002,d12.5,\002  BTOL=\002,d12.5"
	    ",\002    MAXITU=\002,i5,\002    MAXITA=\002i5)";
    static char fmt_260[] = "(//,\002 \002,65(\002*\002),/,\002 CALCULATION "
	    "OF STATIC FIELD QUANTITIES\002,/,\002 \002,65(\002*\002))";
    static char fmt_270[] = "(//,\002 \002,70(\002*\002),/\002 CALCULATION F"
	    "OR A FREQUENCY OF \002,f10.5,\002 EV  =\002,f14.5,\002 A.U. \002"
	    "/18x,\002WAVELENGTH OF \002,f10.2,\002 NM  =\002,f14.5,\002 CM(-"
	    "1)\002,/,\002 \002,70(\002*\002))";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen), s_rsfe(cilist *), 
	    e_rsfe(void);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j, k, l;
#define ir ((integer *)&chanel_1 + 4)
#define iw ((integer *)&chanel_1 + 5)
    static logical let;
    static doublereal sum, grad[360];
    static integer igam, ibet;
    static char line[80];
    static doublereal atol, btol;
    static integer mass;
    extern /* Subroutine */ int axis_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static char type__[7];
    static doublereal sumw, sumx, sumy, sumz, heat0;
    extern /* Subroutine */ int betaf_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    static integer iwfla, iwflb;
    extern /* Subroutine */ int ngoke_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static integer nfreq;
    static doublereal value[40], atpol, tempv[9]	/* was [3][3] */;
    extern /* Subroutine */ int nonor_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), alphaf_(integer *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal dataev[10];
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), nuchar_(char *, doublereal *
	    , integer *, ftnlen);
    static integer maxita, nvalue;
    extern /* Subroutine */ int openda_(integer *);
    static doublereal rotvec[9]	/* was [3][3] */;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);
    static doublereal summax;
    static integer maxitu;
    static doublereal omegau, wavlen;
    extern /* Subroutine */ int nonope_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), nonbet_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), beopor_(integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *), ngamtg_(integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *), ngefis_(
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), ngidri_(integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___12 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___18 = { 0, 6, 0, "(//10X,'CARTESIAN COORDINATES ',/)", 
	    0 };
    static cilist io___19 = { 0, 6, 0, "(4X,'NO.',7X,'ATOM',9X,'X',         "
	    "              9X,'Y',9X,'Z',/)", 0 };
    static cilist io___21 = { 0, 6, 0, "(I6,8X,A2,4X,3F10.4)", 0 };
    static cilist io___23 = { 0, 6, 0, fmt_160, 0 };
    static cilist io___31 = { 0, 6, 0, fmt_200, 0 };
    static cilist io___32 = { 0, 5, 0, "(A)", 0 };
    static cilist io___45 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___46 = { 0, 6, 0, fmt_250, 0 };
    static cilist io___50 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___51 = { 0, 6, 0, fmt_270, 0 };
    static cilist io___52 = { 0, 6, 0, "(' DATA FOR POLAR CALCULATION EITHER"
	    "',                 ' MISSING OR FAULTY')", 0 };


/* .. 6/13/91 */
/* ********************************************************************** */

/*   POLAR SETS UP THE CALCULATION OF THE MOLECULAR ELECTRIC RESPONSE */
/*   PROPERTIES BY FFHPOL. */

/* ********************************************************************** */
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
/* .. */
    scftyp_1.limscf = FALSE_;
    s_copy(type__, " MNDO  ", (ftnlen)7, (ftnlen)7);
    let = i_indx(keywrd_1.keywrd, "LET", (ftnlen)241, (ftnlen)3) != 0;
    if (i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0) {
	s_copy(type__, "MINDO/3", (ftnlen)7, (ftnlen)7);
    }
    if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0) {
	s_copy(type__, "  AM1  ", (ftnlen)7, (ftnlen)7);
    }
    s_wsfe(&io___5);
    e_wsfe();
    gmetry_(geom_1.geo, geom_1.coord);

/*  ORIENT THE MOLECULE WITH THE MOMENTS OF INERTIA. */
/*  THIS IS DONE TO ENSURE A UNIQUE, REPRODUCEABLE SET OF DIRECTIONS. */
/*  IF LET IS SPECIFIED, THE INPUT ORIENTATION WILL BE USED. */

    if (! let) {
	mass = 1;
	axis_(geom_1.coord, &molkst_1.numat, &a, &b, &c__, &sumw, &mass, 
		rotvec);
	s_wsfe(&io___12);
	e_wsfe();
	for (i__ = 1; i__ <= 3; ++i__) {
	    s_wsfe(&io___14);
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&rotvec[i__ + j * 3 - 4], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
/* L40: */
	}

/*  ROTATE ATOMS */

	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		sum = 0.;
		for (k = 1; k <= 3; ++k) {
		    sum += geom_1.coord[k + i__ * 3 - 4] * rotvec[k + j * 3 - 
			    4];
/* L50: */
		}
		geom_1.geo[j + i__ * 3 - 4] = sum;
/* L60: */
	    }
/* L70: */
	}
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		geom_1.coord[j + i__ * 3 - 4] = geom_1.geo[j + i__ * 3 - 4];
/* L80: */
	    }
/* L90: */
	}
	s_wsfe(&io___18);
	e_wsfe();
	s_wsfe(&io___19);
	e_wsfe();
	l = 0;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (molkst_1.nat[i__ - 1] == 99 || molkst_1.nat[i__ - 1] == 107) {
		goto L100;
	    }
	    ++l;
	    s_wsfe(&io___21);
	    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 1 << 1), 
		    (ftnlen)2);
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&geom_1.coord[j + l * 3 - 4], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
L100:
	    ;
	}

/*  IF POLYMER, ROTATE TVEC */
/*  (BEWARE:  THE POLYMER SECTIONS MAY NOT WORK YET) */

	if (euler_1.idtvec > 0) {
	    i__1 = euler_1.idtvec;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    sum = 0.;
		    for (k = 1; k <= 3; ++k) {
			sum += euler_1.tvec[k + i__ * 3 - 4] * rotvec[k + j * 
				3 - 4];
/* L110: */
		    }
		    tempv[j + i__ * 3 - 4] = sum;
/* L120: */
		}
/* L130: */
	    }
	    for (i__ = 1; i__ <= 3; ++i__) {
		i__1 = euler_1.idtvec;
		for (j = 1; j <= i__1; ++j) {
		    euler_1.tvec[i__ + j * 3 - 4] = tempv[i__ + j * 3 - 4];
/* L140: */
		}
/* L150: */
	    }
	    s_wsfe(&io___23);
	    i__1 = euler_1.idtvec;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    do_fio(&c__1, (char *)&euler_1.tvec[j + i__ * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		}
	    }
	    e_wsfe();
	}
    }

    last_1.last = 1;
    geokst_1.na[0] = 99;

/*  SET UP THE VARIABLES IN XPARAM AND LOC, THESE ARE IN CARTESIAN */
/*  COORDINATES. */

    geosym_1.ndep = 0;
    molkst_1.numat = 0;
    sumx = 0.;
    sumy = 0.;
    sumz = 0.;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] != 99 && geokst_1.labels[i__ - 1] != 107)
		 {
	    ++molkst_1.numat;
	    geokst_1.labels[molkst_1.numat - 1] = geokst_1.labels[i__ - 1];
	    sumx += geom_1.coord[molkst_1.numat * 3 - 3];
	    sumy += geom_1.coord[molkst_1.numat * 3 - 2];
	    sumz += geom_1.coord[molkst_1.numat * 3 - 1];
	    for (j = 1; j <= 3; ++j) {
/* L170: */
		geom_1.geo[j + molkst_1.numat * 3 - 4] = geom_1.coord[j + 
			molkst_1.numat * 3 - 4];
	    }
	}
/* L180: */
    }
    sumx /= molkst_1.numat;
    sumy /= molkst_1.numat;
    sumz /= molkst_1.numat;
    summax = 0.;
    atpol = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] != 107) {
	    atpol += polvol_1.polvol[geokst_1.labels[i__ - 1] - 1];
	}
	geom_1.geo[i__ * 3 - 3] -= sumx;
	if (summax < (d__1 = geom_1.geo[i__ * 3 - 3], abs(d__1))) {
	    summax = (d__2 = geom_1.geo[i__ * 3 - 3], abs(d__2));
	}
	geom_1.geo[i__ * 3 - 2] -= sumy;
	if (summax < (d__1 = geom_1.geo[i__ * 3 - 2], abs(d__1))) {
	    summax = (d__2 = geom_1.geo[i__ * 3 - 2], abs(d__2));
	}
	geom_1.geo[i__ * 3 - 1] -= sumz;
	if (summax < (d__1 = geom_1.geo[i__ * 3 - 1], abs(d__1))) {
	    summax = (d__2 = geom_1.geo[i__ * 3 - 1], abs(d__2));
	}
/* L190: */
    }

    geovar_1.nvar = 0;
    geokst_1.natoms = molkst_1.numat;
    compfg_(geom_1.geo, &c_true, &heat0, &c_true, grad, &c_false);
    s_wsfe(&io___31);
    do_fio(&c__1, (char *)&heat0, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* ............................................................... */

/*  VARIABLES USED FOR TIME-DEPENDENT CALCULATIONS */

/*    OMEGA .........  FREQUENCY OF LIGHT (ACTUALLY INPUT AS ENERGY */
/*                     IN EV'S. */
/*    IWFLA .........  TYPE OF ALPHA CALCULATION FOR STORING MATRICES */
/*                     0 = STATIC */
/*                     1 = OMEGA */
/*                     2 = 2*OMEGA */
/*                     3 = 3*OMEGA */
/*    IWFLB .........  TYPE OF BETA CALCULATION FOR STORING MATRICES */
/*                     0 = (0,0) */
/*                     1 = (W,W) (SHG) */
/*                     2 = (0,W) (EOPE) */
/*                     3 = (W,-W) (OR) */

/*  INPUT NUMBER OF FREQENCIES TO RUN */

/*     IBET = 0  NO BETA CALC */
/*            1  ITERATIVE BETA */
/*           -1  NONITER BETA (SHG) */
/*           -2  NONITER EOPE */
/*           -3  NONITER OR */

/*     IGAM = 0  NO GAMMA CALC */
/*            1 THIRD HARMONIC GENERATION INPUT N,0,1,1 */
/*            2 DC-EFISHG INPUT N,0,1,2 */
/*            3 IDRI N,0,1,3 */
/*            4 OKE N,0,1,4 */
/*            5 DC EFIOR (NOT AVAILABLE) */

    s_rsfe(&io___32);
    do_fio(&c__1, line, (ftnlen)80);
    e_rsfe();
    nuchar_(line, value, &nvalue, (ftnlen)80);
    iwflb = (integer) value[0];
    ibet = (integer) value[1];
    igam = (integer) value[2];
    atol = value[3];
    maxitu = (integer) value[4];
    maxita = (integer) value[5];
    btol = value[6];
    for (i__ = 1; i__ <= 3; ++i__) {
/* L220: */
	dataev[i__ - 1] = (i__ - 1) * .25;
    }
    nfreq = 3;
/* L230: */
    if (igam != 0) {
	ibet = 1;
    }
    s_wsfe(&io___45);
    do_fio(&c__1, (char *)&nfreq, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&iwflb, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ibet, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&igam, (ftnlen)sizeof(integer));
    e_wsfe();

/* ATOL IS THE MAXIMUM TOLERANCE IN MAKEUF AND BTOL IS THAT IN BMAKUF */
/* MAXITU IS THE MAXIMUM ITERATION IN BETAF AND MAXITA IS THE MAXIMUM */
/* ITERATION IN ALPHAF */

/* #      READ(IR,*,END=99,ERR=99) ATOL,MAXITU,MAXITA,BTOL */
    s_wsfe(&io___46);
    do_fio(&c__1, (char *)&atol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&btol, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&maxitu, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&maxita, (ftnlen)sizeof(integer));
    e_wsfe();

/* SET UP DIRECT ACCESS FILE FOR T-D MATRICES */
    openda_(&c__0);

/* CALCULATE ALPHA AT STATIC VALUES */

    if (iwflb == 2 || igam == 2 || igam == 4 || ibet <= -2) {
	iwfla = 0;
	omval_1.omega = 0.;
	alphaf_(&iwfla, &atol, &maxita, work1_1.x1, work1_1.x2, work1_1.x3, 
		work1_1.x4, work1_1.x5, work1_1.x6, work1_1.x7);
    }
    if (igam == 4) {
	iwflb = 0;
	betaf_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, work1_1.x3, 
		work1_1.x4, work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		work1_1.x9, work1_1.x10, work3_1.x11, work3_1.x12, 
		scrach_1.x13);
    }

/* CALCULATE FREQUENCY DEPENDENT VALUES */

    i__1 = nfreq;
    for (i__ = 1; i__ <= i__1; ++i__) {

/*  READ IN FREQ:  ACTUALLY READ IN AS ENERGY IN EV. */

	omval_1.omega = dataev[i__ - 1];
	omegau = omval_1.omega / 27.2113961;
	if (omval_1.omega < 1e-8) {
	    wavlen = 999999.99;
/* #           WRITE(6,401) OMEGA */
	    s_wsfe(&io___50);
	    e_wsfe();
	} else {
	    s_wsfe(&io___51);
	    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&omegau, (ftnlen)sizeof(doublereal));
	    d__1 = 1239.8424 / omval_1.omega;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = omval_1.omega * 8065.541;
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

/*  CALCULATE ALPHA(W) */

	iwfla = 1;
	alphaf_(&iwfla, &atol, &maxita, work1_1.x1, work1_1.x2, work1_1.x3, 
		work1_1.x4, work1_1.x5, work1_1.x6, work1_1.x7);

/*  PERFORM NONITERATIVE BETA CALCULATIONS */

/*   OPTICAL RECTIFICATION */
	if (ibet == -3) {
	    nonor_(work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, work1_1.x5,
		     work1_1.x6, work1_1.x7, work1_1.x8, work1_1.x9, 
		    work1_1.x10, work3_1.x11, work3_1.x12);
	}
/*   ELECTROPTIC POCKELS EFFECT */
	if (ibet == -2) {
	    nonope_(work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, 
		    work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		    work1_1.x9, work1_1.x10, work3_1.x11, work3_1.x12);
	}
/*   SECOND HARMONIC GENERATION */
	if (ibet == -1) {
	    iwfla = 2;
	    omval_1.omega *= 2.;
	    alphaf_(&iwfla, &atol, &maxita, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7);
	    omval_1.omega /= 2.;
	    nonbet_(work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, 
		    work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		    work1_1.x9, work1_1.x10, work3_1.x11, work3_1.x12);
	}

/*  PERFORM ITERATIVE BETA (SHG AND STATIC)CALCULATIONS */

/*         IF ((IBET.GT.0) .AND.(IGAM .EQ. 0)) THEN */
	if (ibet == 1 && iwflb <= 1 && igam == 0) {
	    betaf_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, work1_1.x3,
		     work1_1.x4, work1_1.x5, work1_1.x6, work1_1.x7, 
		    work1_1.x8, work1_1.x9, work1_1.x10, work3_1.x11, 
		    work3_1.x12, scrach_1.x13);

/* PERFORM ITERATIVE BETA (EOPE AND OR) CALCULATIONS */

	} else if (ibet == 1 && iwflb > 1 && igam == 0) {
	    beopor_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7, work1_1.x8, work1_1.x9, work1_1.x10, 
		    work3_1.x11, work3_1.x12, scrach_1.x13);
	}
/* ....................................................................... */
/* CALCULATE GAMMA VALUES */
/* ....................................................................... */
	if (ibet > 0 && igam <= 3 && igam != 0) {
	    iwflb = 1;
	    betaf_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, work1_1.x3,
		     work1_1.x4, work1_1.x5, work1_1.x6, work1_1.x7, 
		    work1_1.x8, work1_1.x9, work1_1.x10, work3_1.x11, 
		    work3_1.x12, scrach_1.x13);
	}
/* THIRD HARMONIC GENRATION */
	if (igam == 1) {
	    iwfla = 3;
	    omval_1.omega *= 3.;
	    alphaf_(&iwfla, &atol, &maxita, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7);
	    omval_1.omega /= 3.;
	    ngamtg_(&igam, work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, 
		    work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		    work1_1.x9);
	}
/* DC-EFISHG */
	if (igam == 2) {
	    iwfla = 2;
	    omval_1.omega *= 2.;
	    alphaf_(&iwfla, &atol, &maxita, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7);
	    omval_1.omega /= 2.;
	    iwflb = 2;
	    beopor_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7, work1_1.x8, work1_1.x9, work1_1.x10, 
		    work3_1.x11, work3_1.x12, scrach_1.x13);
	    ngefis_(&igam, work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, 
		    work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		    work1_1.x9);
	}
/* IDRI */
	if (igam == 3) {
	    iwflb = 3;
	    beopor_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7, work1_1.x8, work1_1.x9, work1_1.x10, 
		    work3_1.x11, work3_1.x12, scrach_1.x13);
	    ngidri_(&igam, work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, 
		    work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		    work1_1.x9);
	}
/* OKE */
	if (igam == 4) {
	    iwflb = 2;
	    beopor_(&iwflb, &maxitu, &btol, work1_1.x1, work1_1.x2, 
		    work1_1.x3, work1_1.x4, work1_1.x5, work1_1.x6, 
		    work1_1.x7, work1_1.x8, work1_1.x9, work1_1.x10, 
		    work3_1.x11, work3_1.x12, scrach_1.x13);
	    ngoke_(&igam, work1_1.x1, work1_1.x2, work1_1.x3, work1_1.x4, 
		    work1_1.x5, work1_1.x6, work1_1.x7, work1_1.x8, 
		    work1_1.x9);
	}
/* L280: */
    }

    return 0;
/* L290: */
    s_wsfe(&io___52);
    e_wsfe();
    return 0;
} /* polar_ */

#undef iw
#undef ir



/* ======================================================================= */

/* Subroutine */ int tf_(doublereal *ua, doublereal *ga, doublereal *ub, 
	doublereal *gb, doublereal *t, integer *norbs, integer *nclose, 
	integer *iwflb)
{
    /* System generated locals */
    integer ua_dim1, ua_offset, ub_dim1, ub_offset, t_dim1, t_offset, ga_dim1,
	     ga_offset, gb_dim1, gb_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k;
    static doublereal sum1, sum2;
    extern /* Subroutine */ int zerom_(doublereal *, integer *);


/*  THIS SUBROUTINE CREATES THE NEW T MATRIX */


/*  ZERO MATRIX INITIALLY */

    /* Parameter adjustments */
    t_dim1 = *norbs;
    t_offset = 1 + t_dim1 * 1;
    t -= t_offset;
    gb_dim1 = *norbs;
    gb_offset = 1 + gb_dim1 * 1;
    gb -= gb_offset;
    ub_dim1 = *norbs;
    ub_offset = 1 + ub_dim1 * 1;
    ub -= ub_offset;
    ga_dim1 = *norbs;
    ga_offset = 1 + ga_dim1 * 1;
    ga -= ga_offset;
    ua_dim1 = *norbs;
    ua_offset = 1 + ua_dim1 * 1;
    ua -= ua_offset;

    /* Function Body */
    zerom_(&t[t_offset], norbs);

/* CALCULATE T (IJ)(W,W)= SUM(GA(IK)(W)*UB(KJ)(W)+ */
/* GB(IK)(W)*UA(KJ)(W)-UA(IK)(W)GB(KJ)(W)-UB(IK)(W)GA(KJ)(W) */

    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    sum1 = 0.;
	    sum2 = 0.;
	    i__3 = *norbs;
	    for (k = 1; k <= i__3; ++k) {
/* CALCULATE FOR (W,W), (0,W) VALUES */

		sum1 = sum1 + ga[i__ + k * ga_dim1] * ub[k + j * ub_dim1] + 
			gb[i__ + k * gb_dim1] * ua[k + j * ua_dim1] - ua[i__ 
			+ k * ua_dim1] * gb[k + j * gb_dim1] - ub[i__ + k * 
			ub_dim1] * ga[k + j * ga_dim1];
		sum2 = sum2 + ga[j + k * ga_dim1] * ub[k + i__ * ub_dim1] + 
			gb[j + k * gb_dim1] * ua[k + i__ * ua_dim1] - ua[j + 
			k * ua_dim1] * gb[k + i__ * gb_dim1] - ub[j + k * 
			ub_dim1] * ga[k + i__ * ga_dim1];
/* L10: */
	    }
	    t[i__ + j * t_dim1] = sum1;
	    t[j + i__ * t_dim1] = sum2;
/* L20: */
	}
/* L30: */
    }

    return 0;
} /* tf_ */

/* Subroutine */ int transf_(doublereal *f, doublereal *g, doublereal *c__, 
	integer *norb)
{
    /* System generated locals */
    integer c_dim1, c_offset, f_dim1, f_offset, g_dim1, g_offset, i__1, i__2, 
	    i__3, i__4;

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal term, term2;


/*  THIS SUBROUTINE FORMS THE G MATRIX BY TRANSFORMING F WITH C */


    /* Parameter adjustments */
    c_dim1 = *norb;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    g_dim1 = *norb;
    g_offset = 1 + g_dim1 * 1;
    g -= g_offset;
    f_dim1 = *norb;
    f_offset = 1 + f_dim1 * 1;
    f -= f_offset;

    /* Function Body */
    i__1 = *norb;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norb;
	for (j = 1; j <= i__2; ++j) {
/*            IJ = I*(I-1)/2 + J */
	    term2 = 0.;
	    i__3 = *norb;
	    for (k = 1; k <= i__3; ++k) {
		term = 0.;
		i__4 = *norb;
		for (l = 1; l <= i__4; ++l) {
/*                  KI = MAX0(K,L) */
/*                  LI = MIN0(K,L) */
/*                  KL = KI*(KI-1)/2 + LI */
		    term += f[k + l * f_dim1] * c__[l + j * c_dim1];
/* L10: */
		}
		term2 += term * c__[k + i__ * c_dim1];
/* L20: */
	    }
	    g[i__ + j * g_dim1] = term2;
/* L30: */
	}
/* L40: */
    }
    return 0;
} /* transf_ */

doublereal trsub_(doublereal *ul, doublereal *x, doublereal *ur, integer *l1, 
	integer *lm, integer *ndim)
{
    /* System generated locals */
    integer ul_dim1, ul_offset, x_dim1, x_offset, ur_dim1, ur_offset, i__1, 
	    i__2, i__3;
    doublereal ret_val;

    /* Local variables */
    static integer i__, k, l;
    static doublereal sum, suml;

/* THIS PROGRAM CALCULATES TRACES OF MATRICES */

    /* Parameter adjustments */
    ur_dim1 = *ndim;
    ur_offset = 1 + ur_dim1 * 1;
    ur -= ur_offset;
    x_dim1 = *ndim;
    x_offset = 1 + x_dim1 * 1;
    x -= x_offset;
    ul_dim1 = *ndim;
    ul_offset = 1 + ul_dim1 * 1;
    ul -= ul_offset;

    /* Function Body */
    sum = 0.;
    i__1 = *l1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *lm;
	for (k = 1; k <= i__2; ++k) {
	    suml = 0.;
	    i__3 = *lm;
	    for (l = 1; l <= i__3; ++l) {
		suml += x[k + l * x_dim1] * ur[l + i__ * ur_dim1];
/* L10: */
	    }
	    sum += suml * ul[i__ + k * ul_dim1];
/* L20: */
	}
/* L30: */
    }
    ret_val = sum * 2.;
    return ret_val;
} /* trsub_ */

doublereal trudgu_(doublereal *ul, doublereal *x, doublereal *ur, integer *l1,
	 integer *lm, integer *ndim)
{
    /* System generated locals */
    integer ul_dim1, ul_offset, x_dim1, x_offset, ur_dim1, ur_offset, i__1, 
	    i__2, i__3;
    doublereal ret_val;

    /* Local variables */
    static integer i__, k, l;
    static doublereal sum, suml;


    /* Parameter adjustments */
    ur_dim1 = *ndim;
    ur_offset = 1 + ur_dim1 * 1;
    ur -= ur_offset;
    x_dim1 = *ndim;
    x_offset = 1 + x_dim1 * 1;
    x -= x_offset;
    ul_dim1 = *ndim;
    ul_offset = 1 + ul_dim1 * 1;
    ul -= ul_offset;

    /* Function Body */
    sum = 0.;
    i__1 = *l1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *lm;
	for (k = 1; k <= i__2; ++k) {
	    suml = 0.;
	    i__3 = *lm;
	    for (l = 1; l <= i__3; ++l) {
		suml += x[k + l * x_dim1] * ur[l + i__ * ur_dim1];
/* L10: */
	    }
	    sum += suml * ul[k + i__ * ul_dim1];
/* L20: */
	}
/* L30: */
    }
    ret_val = sum * 2.;
    return ret_val;
} /* trudgu_ */

doublereal trugdu_(doublereal *ul, doublereal *x, doublereal *ur, integer *l1,
	 integer *lm, integer *ndim)
{
    /* System generated locals */
    integer ul_dim1, ul_offset, x_dim1, x_offset, ur_dim1, ur_offset, i__1, 
	    i__2, i__3;
    doublereal ret_val;

    /* Local variables */
    static integer i__, k, l;
    static doublereal sum, suml;


    /* Parameter adjustments */
    ur_dim1 = *ndim;
    ur_offset = 1 + ur_dim1 * 1;
    ur -= ur_offset;
    x_dim1 = *ndim;
    x_offset = 1 + x_dim1 * 1;
    x -= x_offset;
    ul_dim1 = *ndim;
    ul_offset = 1 + ul_dim1 * 1;
    ul -= ul_offset;

    /* Function Body */
    sum = 0.;
    i__1 = *l1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *lm;
	for (k = 1; k <= i__2; ++k) {
	    suml = 0.;
	    i__3 = *lm;
	    for (l = 1; l <= i__3; ++l) {
		suml += x[l + k * x_dim1] * ur[l + i__ * ur_dim1];
/* L10: */
	    }
	    sum += suml * ul[i__ + k * ul_dim1];
/* L20: */
	}
/* L30: */
    }
    ret_val = sum * 2.;
    return ret_val;
} /* trugdu_ */

doublereal trugud_(doublereal *ul, doublereal *x, doublereal *ur, integer *l1,
	 integer *lm, integer *ndim)
{
    /* System generated locals */
    integer ul_dim1, ul_offset, x_dim1, x_offset, ur_dim1, ur_offset, i__1, 
	    i__2, i__3;
    doublereal ret_val;

    /* Local variables */
    static integer i__, k, l;
    static doublereal sum, suml;


    /* Parameter adjustments */
    ur_dim1 = *ndim;
    ur_offset = 1 + ur_dim1 * 1;
    ur -= ur_offset;
    x_dim1 = *ndim;
    x_offset = 1 + x_dim1 * 1;
    x -= x_offset;
    ul_dim1 = *ndim;
    ul_offset = 1 + ul_dim1 * 1;
    ul -= ul_offset;

    /* Function Body */
    sum = 0.;
    i__1 = *l1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *lm;
	for (k = 1; k <= i__2; ++k) {
	    suml = 0.;
	    i__3 = *lm;
	    for (l = 1; l <= i__3; ++l) {
		suml += x[k + l * x_dim1] * ur[i__ + l * ur_dim1];
/* L10: */
	    }
	    sum += suml * ul[i__ + k * ul_dim1];
/* L20: */
	}
/* L30: */
    }
    ret_val = sum * 2.;
    return ret_val;
} /* trugud_ */

/* Subroutine */ int zerom_(doublereal *x, integer *m)
{
    /* System generated locals */
    integer x_dim1, x_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;


/*  ZEROM ZEROS THE MATRIX X */

    /* Parameter adjustments */
    x_dim1 = *m;
    x_offset = 1 + x_dim1 * 1;
    x -= x_offset;

    /* Function Body */
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    x[i__ + j * x_dim1] = 0.;
/* L10: */
	}
/* L20: */
    }
    return 0;
} /* zerom_ */

/* Subroutine */ int alphaf_(integer *iwfla, doublereal *atol, integer *
	maxita, doublereal *u, doublereal *f, doublereal *g, doublereal *uold,
	 doublereal *h1, doublereal *d__, doublereal *da)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";

    /* Format strings */
    static char fmt_10[] = "(/,\002 +++++ ALPHA AT \002,1f13.5,\002 EV.\002)";
    static char fmt_30[] = "(/\002 CONVERGED IN\002,i4,\002 ITERATIONS IN"
	    "\002,f10.2,\002 SECONDS\002,/\002           DENSITY CONVERG. TO"
	    " \002,1pd12.5,/\002             ALPHA CONVERG. TO \002,1pd12.5,/)"
	    ;
    static char fmt_40[] = "(\002      ALPHA(\002,a1,\002,\002,a1,\002) ="
	    " \002,1pd14.7)";
    static char fmt_50[] = "(\002      ALPHA(\002,a1,\002,\002,a1,\002) ="
	    " \002,1pd14.7)";
    static char fmt_80[] = "(/,\002  ISOTROPIC AVERAGE ALPHA = \002,1f13.5"
	    ",\002 A.U.\002)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer ic, id;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal dela, diff;
    extern doublereal aval_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int hmuf_(doublereal *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *, integer *);
    static logical last;
    static integer nsqr;
    extern /* Subroutine */ int densf_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, integer *, integer *);
    static integer nnorb, iposg;
    extern /* Subroutine */ int copym_(doublereal *, doublereal *, integer *),
	     zerom_(doublereal *, integer *);
    static integer iposu;
    extern /* Subroutine */ int ffreq1_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), ffreq2_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *);
    static doublereal allalp[9]	/* was [3][3] */, alpavg;
    extern doublereal second_(void);
    static doublereal alpold;
    extern /* Subroutine */ int makeuf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, logical *, integer *, integer *, 
	    integer *, doublereal *, doublereal *);
    static doublereal alphaw, cmptim;
    extern /* Subroutine */ int dawrit_(doublereal *, integer *, integer *), 
	    transf_(doublereal *, doublereal *, doublereal *, integer *);
    static integer icount;
    extern /* Subroutine */ int hplusf_(doublereal *, doublereal *, integer *)
	    ;

    /* Fortran I/O blocks */
    static cilist io___92 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___102 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___104 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___106 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___107 = { 0, 6, 0, fmt_80, 0 };



/*  SUBROUTINE FOR THE CALCULATION OF THE FREQUENCY DEPENDENT FIRST-ORDER */
/*  RESPONCE MATRICIES UA AND DENSITIES DA. */
/*  USED TO COMPUTE THE FREQUENCY DEPENDENT POLARIZABILITY AND FOR */
/*  SOLVING THE SECOND-ORDER PROBLEM. */


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

    /* Parameter adjustments */
    da -= 301;
    d__ -= 301;
    h1 -= 301;
    uold -= 301;
    g -= 301;
    f -= 301;
    u -= 301;

    /* Function Body */

    nsqr = molkst_1.norbs * molkst_1.norbs;
    alpavg = 0.;
/* COMPUTE OFFSETS FOR U AND G MATRICES */
    iposu = *iwfla * 6 + 1;
    iposg = *iwfla * 6 + 4;
    s_wsfe(&io___92);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  CHOOSE A  COMPONENT */
/*  X: ID=1   Y: ID=2   Z: ID=3 */

    for (id = 1; id <= 3; ++id) {
	cmptim = second_();
	last = FALSE_;

/*  CALCULATE THE DIPOLE MATRIX. */

	hmuf_(&h1[301], &id, geom_1.coord, molkst_1.nfirst, molkst_1.nlast, 
		molkst_1.nat, &molkst_1.norbs, &molkst_1.numat);
	copym_(&h1[301], &f[301], &molkst_1.norbs);

/*  INITIALIZE UOLD TO ZERO */

	zerom_(&uold[301], &molkst_1.norbs);
/* ................................................................. */
/*  LOOP STARTS HERE */
/* ................................................................. */
	icount = 0;
	alpold = 0.;
L20:
	++icount;
	if (icount > *maxita) {
	    last = TRUE_;
	}

/*  CREATE G MATRIX. */

	transf_(&f[301], &g[301], vector_1.c__, &molkst_1.norbs);

/*  FORM U MATRIX */

	makeuf_(&u[301], &uold[301], &g[301], vector_1.eigs, &last, &
		molkst_1.norbs, &nnorb, &molkst_1.nclose, &diff, atol);

/*  FORM NEW DENSITY MATRIX */

	densf_(&u[301], vector_1.c__, vector_1.ca, &d__[301], &da[301], &
		molkst_1.norbs, &molkst_1.nclose);

/* COMPUTE TEST ALPHA TO BE USED FOR A CONVERGENCE TEST */

	alphaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	dela = (d__1 = alpold - alphaw, abs(d__1));
	alpold = alphaw;
/* .      WRITE(6,1500) ALPHAW */
/* . 1500 FORMAT ('  TEST ALPHA = ',D12.5) */

/*  CREATE NEW FOCK MATRIX */

	zerom_(&f[301], &molkst_1.norbs);
	ffreq2_(&f[301], &d__[301], wmatrx_1.w, &molkst_1.numat, 
		molkst_1.nfirst, molkst_1.nlast, &molkst_1.norbs);
	ffreq1_(&f[301], &d__[301], &da[301], &da[301], &molkst_1.norbs);
	hplusf_(&f[301], &h1[301], &molkst_1.norbs);
/* .............................................................. */
	if (! last) {
	    goto L20;
	}
	cmptim = second_() - cmptim;
	s_wsfe(&io___102);
	do_fio(&c__1, (char *)&icount, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cmptim, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&diff, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dela, (ftnlen)sizeof(doublereal));
	e_wsfe();

/* COMPUTE ALPHA */

	alphaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	allalp[id + id * 3 - 4] = alphaw;
	s_wsfe(&io___104);
	do_fio(&c__1, alab + (id - 1), (ftnlen)1);
	do_fio(&c__1, alab + (id - 1), (ftnlen)1);
	do_fio(&c__1, (char *)&alphaw, (ftnlen)sizeof(doublereal));
	e_wsfe();
	alpavg += alphaw;

/*  WRITE OUT U AND G FOR FUTURE USE */

	i__1 = iposu + id;
	dawrit_(&u[301], &nsqr, &i__1);
	i__1 = iposg + id;
	dawrit_(&g[301], &nsqr, &i__1);

/*  COMPUTE OTHER COMPONENTS */

	for (ic = 1; ic <= 3; ++ic) {
	    if (ic != id) {
		hmuf_(&h1[301], &ic, geom_1.coord, molkst_1.nfirst, 
			molkst_1.nlast, molkst_1.nat, &molkst_1.norbs, &
			molkst_1.numat);
		alphaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
		allalp[ic + id * 3 - 4] = alphaw;
		s_wsfe(&io___106);
		do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
		do_fio(&c__1, alab + (id - 1), (ftnlen)1);
		do_fio(&c__1, (char *)&alphaw, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
/* L60: */
	}
/* L70: */
    }
    alpavg /= 3.;
    s_wsfe(&io___107);
    do_fio(&c__1, (char *)&alpavg, (ftnlen)sizeof(doublereal));
    e_wsfe();

    return 0;
} /* alphaf_ */

#undef iw


doublereal aval_(doublereal *h__, doublereal *d__, integer *norbs)
{
    /* System generated locals */
    integer h_dim1, h_offset, d_dim1, d_offset, i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j;
    static doublereal sum;

/* ................................................................. */
/*  COMPUTE POLARIZABILITY AS TRACE OF H*D */
/* ................................................................. */
    /* Parameter adjustments */
    d_dim1 = *norbs;
    d_offset = 1 + d_dim1 * 1;
    d__ -= d_offset;
    h_dim1 = *norbs;
    h_offset = 1 + h_dim1 * 1;
    h__ -= h_offset;

    /* Function Body */
    sum = 0.;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    sum += h__[i__ + j * h_dim1] * d__[j + i__ * d_dim1];
/* L10: */
	}
/* L20: */
    }
    ret_val = -sum;
    return ret_val;
} /* aval_ */

/* Subroutine */ int bdensf_(doublereal *ua, doublereal *ub, doublereal *uab, 
	doublereal *c__, doublereal *d__, doublereal *da, integer *norbs, 
	integer *nclose, integer *iwflb)
{
    /* System generated locals */
    integer c_dim1, c_offset, d_dim1, d_offset, ua_dim1, ua_offset, ub_dim1, 
	    ub_offset, da_dim1, da_offset, uab_dim1, uab_offset, i__1, i__2, 
	    i__3, i__4, i__5;

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal s1, s2, s3, s4;
#define iw ((integer *)&chanel_1 + 5)
    extern /* Subroutine */ int zerom_(doublereal *, integer *);


/*  THIS SUBROUTINE IS USED TO COMPUTE THE FIRST-ORDER DENSITY */


/* FORM DENSITY MATRIX */


    /* Parameter adjustments */
    da_dim1 = *norbs;
    da_offset = 1 + da_dim1 * 1;
    da -= da_offset;
    d_dim1 = *norbs;
    d_offset = 1 + d_dim1 * 1;
    d__ -= d_offset;
    c_dim1 = *norbs;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    uab_dim1 = *norbs;
    uab_offset = 1 + uab_dim1 * 1;
    uab -= uab_offset;
    ub_dim1 = *norbs;
    ub_offset = 1 + ub_dim1 * 1;
    ub -= ub_offset;
    ua_dim1 = *norbs;
    ua_offset = 1 + ua_dim1 * 1;
    ua -= ua_offset;

    /* Function Body */
    zerom_(&d__[d_offset], norbs);

/* CALCULATE */

    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    s1 = 0.;
	    s2 = 0.;
	    s3 = 0.;
	    s4 = 0.;
	    i__3 = *norbs;
	    for (k = 1; k <= i__3; ++k) {
		i__4 = *nclose;
		for (l = 1; l <= i__4; ++l) {
		    s1 += c__[i__ + k * c_dim1] * uab[k + l * uab_dim1] * c__[
			    j + l * c_dim1];
		    s2 += c__[i__ + l * c_dim1] * uab[l + k * uab_dim1] * c__[
			    j + k * c_dim1];
/* L10: */
		}
/* L20: */
	    }

	    i__3 = *nclose;
	    for (k = 1; k <= i__3; ++k) {
		i__4 = *norbs;
		for (l = *nclose + 1; l <= i__4; ++l) {
		    i__5 = *nclose;
		    for (m = 1; m <= i__5; ++m) {
			s3 += c__[i__ + k * c_dim1] * (ua[k + l * ua_dim1] * 
				ub[l + m * ub_dim1] + ub[k + l * ub_dim1] * 
				ua[l + m * ua_dim1]) * c__[j + m * c_dim1];
/* L30: */
		    }
/* L40: */
		}
/* L50: */
	    }

	    i__3 = *norbs;
	    for (k = *nclose + 1; k <= i__3; ++k) {
		i__4 = *nclose;
		for (l = 1; l <= i__4; ++l) {
		    i__5 = *norbs;
		    for (m = *nclose + 1; m <= i__5; ++m) {
			s4 += c__[i__ + k * c_dim1] * (ua[k + l * ua_dim1] * 
				ub[l + m * ub_dim1] + ub[k + l * ub_dim1] * 
				ua[l + m * ua_dim1]) * c__[j + m * c_dim1];
/* L60: */
		    }
/* L70: */
		}
/* L80: */
	    }
	    d__[i__ + j * d_dim1] = (s1 - s2 + s3 - s4) * 2.;
/* L90: */
	}
/* L100: */
    }
/*      WRITE(6,*) 'INITIAL DENSITY MATRIX FINAL FORM' */
/*      CALL MATOUT(D,EIGS,NORBS,NORBS,NORBS) */

/* CREATE DA */

    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    da[i__ + j * da_dim1] = d__[i__ + j * d_dim1] / 2.;
/* L110: */
	}
/* L120: */
    }

    return 0;
} /* bdensf_ */

#undef iw


/* Subroutine */ int beopor_(integer *iwflb, integer *maxitu, doublereal *
	btol, doublereal *ua, doublereal *ub, doublereal *f, doublereal *ga, 
	doublereal *gb, doublereal *t, doublereal *h1, doublereal *d__, 
	doublereal *da, doublereal *uab, doublereal *uold1, doublereal *g, 
	doublereal *x)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";
    static integer ida[9] = { 1,1,1,2,2,2,3,3,3 };
    static integer idb[9] = { 1,2,3,1,2,3,1,2,3 };

    /* Format strings */
    static char fmt_10[] = "(/,\002 +++++ BETA (STATIC) AT \002,1f15.5,\002 "
	    "EV.\002/)";
    static char fmt_20[] = "(/,\002 +++++ BETA (ELECTROOPTIC POCKELS EFFECT)"
	    " AT \002,1f15.5,\002 EV.\002/)";
    static char fmt_30[] = "(/,\002 +++++ BETA (OPTICAL RECTIFICATION) AT"
	    " \002,1f15.5,\002 EV.\002/)";
    static char fmt_50[] = "(/\002 CONVERGED IN\002,i4,\002 ITERATIONS IN"
	    "\002,f10.2,\002 SECONDS\002)";
    static char fmt_60[] = "(\002 MAXIMUM UAB ELEMENT =\002,1f15.5,\002,  MA"
	    "XIMUM DIFFERENCE =\002,1f15.5,/)";
    static char fmt_70[] = "(\002      BETA(\002,a1,\002,\002,a1,\002,\002"
	    "a1,\002) = \002,1f15.5)";
    static char fmt_100[] = "(//,\002 AVERAGE BETAX VALUE AT \002,f10.5,\002"
	    " EV = \002,1f15.5)";
    static char fmt_110[] = "(\002 AVERAGE BETAY VALUE AT \002,f10.5,\002 EV"
	    " = \002,1f15.5)";
    static char fmt_120[] = "(\002 AVERAGE BETAZ VALUE AT \002,f10.5,\002 EV"
	    " = \002,1f15.5)";
    static char fmt_130[] = "(//,\002  AVERAGE BETA VALUE AT \002,f10.5,\002"
	    " EV = \002,1f15.5,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer ia, ib, ic, id;
    extern /* Subroutine */ int tf_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
#define iw ((integer *)&chanel_1 + 5)
    static integer jpg;
    static doublereal one;
    static integer jpu;
    static doublereal dela, diff, bvec;
    extern doublereal aval_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int hmuf_(doublereal *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *, integer *);
    static doublereal bavx, bavy;
    static logical last;
    static doublereal bavz, maxu;
    extern /* Subroutine */ int epsab_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
    static doublereal betaw;
    static integer ipose, iposg, maxsq;
    extern /* Subroutine */ int zerom_(doublereal *, integer *);
    static integer iposu;
    extern /* Subroutine */ int ffreq1_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), ffreq2_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *), daread_(doublereal *, integer *, integer *), bdensf_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    bmakuf_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, logical *, integer *, 
	    integer *, doublereal *, integer *, doublereal *, doublereal *);
    static doublereal betold;
    extern doublereal second_(void);
    extern /* Subroutine */ int fhpatn_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *);
    static doublereal cmptim;
    extern /* Subroutine */ int dawrit_(doublereal *, integer *, integer *), 
	    transf_(doublereal *, doublereal *, doublereal *, integer *), 
	    hplusf_(doublereal *, doublereal *, integer *);
    static integer icount, iposum;

    /* Fortran I/O blocks */
    static cilist io___132 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___133 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___134 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___150 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___151 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___153 = { 0, 6, 0, fmt_70, 0 };
    static cilist io___155 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___156 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___157 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___158 = { 0, 6, 0, fmt_130, 0 };



/* THIS SUBROUTINE CALCULATES ITERATIVE BETA VALUES FOR */
/* THE ELECTROOPTIC POCKELS EFFECT AND OPTICAL RECTIFICATION */


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

    /* Parameter adjustments */
    x -= 301;
    g -= 301;
    uold1 -= 301;
    uab -= 301;
    da -= 301;
    d__ -= 301;
    h1 -= 301;
    t -= 301;
    gb -= 301;
    ga -= 301;
    f -= 301;
    ub -= 301;
    ua -= 301;

    /* Function Body */
    one = 1.;
    betold = 0.;
    maxsq = molkst_1.norbs * molkst_1.norbs;
    if (*iwflb == 2) {
	iposu = 73;
    } else {
	iposu = 109;
    }
    iposg = iposu + 9;
    ipose = iposg + 9;
    iposum = ipose + 9;
    if (*iwflb == 0) {
	s_wsfe(&io___132);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else if (*iwflb == 2) {
	s_wsfe(&io___133);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	s_wsfe(&io___134);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/*  LOOP OVER COMPONENTS */

    bavx = 0.;
    bavy = 0.;
    bavz = 0.;
    for (id = 1; id <= 9; ++id) {
	cmptim = second_();
	ia = ida[id - 1];
	ib = idb[id - 1];
	last = FALSE_;

/*  CALCULATE THE DIPOLE MATRIX. */

	hmuf_(&h1[301], &ia, geom_1.coord, molkst_1.nfirst, molkst_1.nlast, 
		molkst_1.nat, &molkst_1.norbs, &molkst_1.numat);

/*  INITIALIZE ZERO ARRAYS */

	zerom_(&uold1[301], &molkst_1.norbs);
	zerom_(&uab[301], &molkst_1.norbs);
	zerom_(&f[301], &molkst_1.norbs);

/*  INPUT U AND GA FROM ALPHA CALCULATIONS */

	if (*iwflb == 2 || *iwflb == 0) {
/*  UA CONTAINS UA(0) */
	    jpu = ia + 1;
	    daread_(&ua[301], &maxsq, &jpu);
/*  GA CONTAINS GA(0) */
	    jpg = ia + 4;
	    daread_(&ga[301], &maxsq, &jpg);
	} else {
/*  UA CONTAINS UA(W) */
	    jpu = ia + 7;
	    daread_(&ua[301], &maxsq, &jpu);
/*  GA CONTAINS GA(W) */
	    jpg = ia + 10;
	    daread_(&ga[301], &maxsq, &jpg);
	}

/* READ VALUES FOR (W,-W) CALCULATION  :  OR */

	if (*iwflb == 3) {
/*  UB CONTAINS UB(-W) = -UB+(W) */
	    jpu = ib + 7;
	    daread_(&x[301], &maxsq, &jpu);
	    d__1 = -one;
	    fhpatn_(&ub[301], &x[301], &molkst_1.norbs, &c__2, &d__1);
/*  GB CONTAINS GB(-W) = GB+(W) */
	    jpg = ib + 10;
	    daread_(&x[301], &maxsq, &jpg);
	    fhpatn_(&gb[301], &x[301], &molkst_1.norbs, &c__2, &one);

/* READ VALUES FOR (0,W) CALCULATION  :  OKE */

	} else if (*iwflb == 0) {
/*  UB CONTAINS UB(0) */
	    jpu = ib + 1;
	    daread_(&ub[301], &maxsq, &jpu);
/*  GB CONTAINS GB(0) */
	    jpg = ib + 4;
	    daread_(&gb[301], &maxsq, &jpg);
	} else {
/*  UB CONTAINS UB(W) */
	    jpu = ib + 7;
	    daread_(&ub[301], &maxsq, &jpu);
/*  GB CONTAINS GB(W) */
	    jpg = ib + 10;
	    daread_(&gb[301], &maxsq, &jpg);
	}

/*  CONSTRUCT T-MATRIX ONE TIME */

	tf_(&ua[301], &ga[301], &ub[301], &gb[301], &t[301], &molkst_1.norbs, 
		&molkst_1.nclose, iwflb);

/*  CALCULATE INITIAL DENSITY AND BETA VALUE */

	bdensf_(&ua[301], &ub[301], &uab[301], vector_1.c__, &d__[301], &da[
		301], &molkst_1.norbs, &molkst_1.nclose, iwflb);
	betaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	dela = (d__1 = betold - betaw, abs(d__1));
	betold = betaw;

/* INITIALIZE FOCK MATRIX */

	ffreq2_(&f[301], &d__[301], wmatrx_1.w, &molkst_1.numat, 
		molkst_1.nfirst, molkst_1.nlast, &molkst_1.norbs);
	ffreq1_(&f[301], &d__[301], &da[301], &da[301], &molkst_1.norbs);
	zerom_(&da[301], &molkst_1.norbs);
	hplusf_(&f[301], &da[301], &molkst_1.norbs);
/* ................................................................. */
/*  LOOP STARTS HERE */
/* ................................................................. */
	icount = 0;
L40:
	++icount;
	if (icount >= *maxitu) {
	    last = TRUE_;
	}

/*  CREATE G MATRIX. */

	transf_(&f[301], &g[301], vector_1.c__, &molkst_1.norbs);

/*  FORM U MATRIX */

	bmakuf_(&ua[301], &ub[301], &uab[301], &t[301], &uold1[301], &g[301], 
		vector_1.eigs, &last, &molkst_1.norbs, &molkst_1.nclose, &
		diff, iwflb, &maxu, btol);

/*  FORM NEW DENSITY MATRIX */

	bdensf_(&ua[301], &ub[301], &uab[301], vector_1.c__, &d__[301], &da[
		301], &molkst_1.norbs, &molkst_1.nclose, iwflb);
/* ... */
/* COMPUTE TEST BETA */

	betaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	dela = (d__1 = betold - betaw, abs(d__1));
	betold = betaw;
/*         IF (LAST.OR.(ICOUNT.GT.(MAXITU-5))) THEN */
/*             WRITE(6,1500) ICOUNT,DELA,MAXU,DIFF */
/* 1500        FORMAT(' ',I4,'  DELTA BETA = ', D12.5, */
/*     X       ' MAXU = ', D12.5, '  UDIFF = ', D12.5) */
/*         ENDIF */

/*  CREATE NEW FOCK MATRIX */

	zerom_(&f[301], &molkst_1.norbs);
	ffreq2_(&f[301], &d__[301], wmatrx_1.w, &molkst_1.numat, 
		molkst_1.nfirst, molkst_1.nlast, &molkst_1.norbs);
	ffreq1_(&f[301], &d__[301], &da[301], &da[301], &molkst_1.norbs);
	zerom_(&da[301], &molkst_1.norbs);
	hplusf_(&f[301], &da[301], &molkst_1.norbs);
/* .............................................................. */
	if (! last) {
	    goto L40;
	}
	cmptim = second_() - cmptim;
	s_wsfe(&io___150);
	do_fio(&c__1, (char *)&icount, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cmptim, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___151);
	do_fio(&c__1, (char *)&maxu, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&diff, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*  COMPUTE OTHER COMPONENTS */

	for (ic = 1; ic <= 3; ++ic) {
	    hmuf_(&h1[301], &ic, geom_1.coord, molkst_1.nfirst, 
		    molkst_1.nlast, molkst_1.nat, &molkst_1.norbs, &
		    molkst_1.numat);
	    betaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	    s_wsfe(&io___153);
	    do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
	    do_fio(&c__1, alab + (ia - 1), (ftnlen)1);
	    do_fio(&c__1, alab + (ib - 1), (ftnlen)1);
	    do_fio(&c__1, (char *)&betaw, (ftnlen)sizeof(doublereal));
	    e_wsfe();
/* CALCULATES THE AVERAGE VALUE OF BETA */

	    if (id == 1 && ic == 1) {
		bavx += betaw * 3.;
	    } else if ((id == 5 || id == 9) && ic == 1) {
		bavx += betaw;
	    } else if ((id == 2 || id == 4) && ic == 2) {
		bavx += betaw;
	    } else if ((id == 3 || id == 7) && ic == 3) {
		bavx += betaw;
	    }
/* CALCULATES AVERAGE BETA IN Y-DIRECTION */

	    if (id == 5 && ic == 2) {
		bavy += betaw * 3.;
	    } else if ((id == 2 || id == 4) && ic == 1) {
		bavy += betaw;
	    } else if ((id == 1 || id == 9) && ic == 2) {
		bavy += betaw;
	    } else if ((id == 6 || id == 8) && ic == 3) {
		bavy += betaw;
	    }
/* CALCULATES AVERAGE BETA IN THE Z-DIRECTION */

	    if (id == 9 && ic == 3) {
		bavz += betaw * 3.;
	    } else if ((id == 3 || id == 7) && ic == 1) {
		bavz += betaw;
	    } else if ((id == 6 || id == 8) && ic == 2) {
		bavz += betaw;
	    } else if ((id == 1 || id == 5) && ic == 3) {
		bavz += betaw;
	    }
/* L80: */
	}

/* CALL SUBROUTINE TO CALCULATE EPSILON AND UMINUS OMEGA,OMEGA */
/*  EPSILON IN H1 AND UMINUS IN DA */
	epsab_(&h1[301], vector_1.eigs, &g[301], &ga[301], &gb[301], &ua[301],
		 &ub[301], &uab[301], &da[301], &molkst_1.norbs, &
		molkst_1.nclose, iwflb);
	i__1 = iposu + id;
	dawrit_(&uab[301], &maxsq, &i__1);
	i__1 = iposg + id;
	dawrit_(&g[301], &maxsq, &i__1);
	i__1 = ipose + id;
	dawrit_(&h1[301], &maxsq, &i__1);
	i__1 = iposum + id;
	dawrit_(&da[301], &maxsq, &i__1);
/* L90: */
    }
    bavx /= 5.;
    bavy /= 5.;
    bavz /= 5.;
    d__1 = bavx * bavx + bavy * bavy + bavz * bavz;
    bvec = pow_dd(&d__1, &c_b176);

    s_wsfe(&io___155);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavx, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___156);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavy, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___157);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavz, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___158);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bvec, (ftnlen)sizeof(doublereal));
    e_wsfe();

    return 0;
} /* beopor_ */

#undef iw


/* Subroutine */ int betaf_(integer *iwflb, integer *maxitu, doublereal *btol,
	 doublereal *ua, doublereal *ub, doublereal *f, doublereal *ga, 
	doublereal *gb, doublereal *t, doublereal *h1, doublereal *d__, 
	doublereal *da, doublereal *uab, doublereal *uold1, doublereal *g, 
	doublereal *x)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";
    static integer ida[6] = { 1,1,1,2,2,3 };
    static integer idb[6] = { 1,2,3,2,3,3 };

    /* Format strings */
    static char fmt_10[] = "(/,\002 +++++ BETA (STATIC) AT \002,1f15.5,\002 "
	    "EV.\002/)";
    static char fmt_20[] = "(/,\002 +++++ BETA\002,\002 (SECOND HARMONIC GEN"
	    "ERATION) AT \002,1f13.5,\002 EV.\002/)";
    static char fmt_40[] = "(/\002 CONVERGED IN\002,i4,\002 ITERATIONS IN"
	    "\002,f10.2,\002 SECONDS\002)";
    static char fmt_50[] = "(\002 MAXIMUM UAB ELEMENT =\002,1f15.5,\002,  MA"
	    "XIMUM DIFFERENCE =\002,1f15.5,/)";
    static char fmt_60[] = "(\002      BETA(\002,a1,\002,\002,a1,\002,\002"
	    "a1,\002) = \002,1f15.5)";
    static char fmt_90[] = "(//,\002 AVERAGE BETAX(SHG) VALUE AT\002,f10.5"
	    ",\002 EV = \002,1f11.5)";
    static char fmt_100[] = "(\002 AVERAGE BETAY(SHG) VALUE AT\002,f10.5,"
	    "\002 EV = \002,1f11.5)";
    static char fmt_110[] = "(\002 AVERAGE BETAZ(SHG) VALUE AT\002,f10.5,"
	    "\002 EV = \002,1f11.5)";
    static char fmt_120[] = "(//,\002 AVERAGE BETA (SHG) VALUE AT\002,f10.5"
	    ",\002 EV = \002,1f11.5,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer ia, ib, ic, id;
    extern /* Subroutine */ int tf_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
#define iw ((integer *)&chanel_1 + 5)
    static integer jpg;
    static doublereal one;
    static integer jpu;
    static doublereal dela, diff, bvec;
    extern doublereal aval_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int hmuf_(doublereal *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *, integer *);
    static doublereal bavx, bavy;
    static logical last;
    static doublereal bavz, maxu;
    extern /* Subroutine */ int epsab_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
    static doublereal betaw;
    static integer ipose, iposg, maxsq;
    extern /* Subroutine */ int zerom_(doublereal *, integer *);
    static integer iposu;
    extern /* Subroutine */ int ffreq1_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *), ffreq2_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *), daread_(doublereal *, integer *, integer *), bdensf_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *);
    static doublereal allbet[27]	/* was [3][3][3] */;
    extern /* Subroutine */ int bmakuf_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, logical *, integer *, integer *, doublereal *, 
	    integer *, doublereal *, doublereal *);
    static doublereal betold;
    extern doublereal second_(void);
    extern /* Subroutine */ int fhpatn_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *);
    static doublereal cmptim;
    extern /* Subroutine */ int dawrit_(doublereal *, integer *, integer *), 
	    transf_(doublereal *, doublereal *, doublereal *, integer *), 
	    hplusf_(doublereal *, doublereal *, integer *);
    static integer icount, iposum;

    /* Fortran I/O blocks */
    static cilist io___170 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___171 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___187 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___188 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___191 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___193 = { 0, 6, 0, fmt_90, 0 };
    static cilist io___194 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___195 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___196 = { 0, 6, 0, fmt_120, 0 };



/* THIS SUBROUTINE CALCULATES ITERATIVE BETA VALUES FOR SECOND HARMONIC */
/* GENERATION. */


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

    /* Parameter adjustments */
    x -= 301;
    g -= 301;
    uold1 -= 301;
    uab -= 301;
    da -= 301;
    d__ -= 301;
    h1 -= 301;
    t -= 301;
    gb -= 301;
    ga -= 301;
    f -= 301;
    ub -= 301;
    ua -= 301;

    /* Function Body */

    one = 1.;
    betold = 0.;
    maxsq = molkst_1.norbs * molkst_1.norbs;
    iposu = *iwflb * 24 + 25;
    iposg = iposu + 6;
    ipose = iposg + 6;
    iposum = ipose + 6;

    if (*iwflb == 0) {
	s_wsfe(&io___170);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	s_wsfe(&io___171);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/*  CHOOSE A  COMPONENT */
/*  X: ID=1   Y: ID=2   Z: ID=3 */

    bavx = 0.;
    bavy = 0.;
    bavz = 0.;
    for (id = 1; id <= 6; ++id) {
	cmptim = second_();
	ia = ida[id - 1];
	ib = idb[id - 1];
	last = FALSE_;

/*  CALCULATE THE DIPOLE MATRIX. */

	hmuf_(&h1[301], &ia, geom_1.coord, molkst_1.nfirst, molkst_1.nlast, 
		molkst_1.nat, &molkst_1.norbs, &molkst_1.numat);

/*  INITIALIZE ZERO ARRAYS */

	zerom_(&uold1[301], &molkst_1.norbs);
	zerom_(&uab[301], &molkst_1.norbs);
	zerom_(&f[301], &molkst_1.norbs);

/*  INPUT U AND GA FROM ALPHA CALCULATIONS */

	if (*iwflb == 2 || *iwflb == 0) {
	    jpu = ia + 1;
	    daread_(&ua[301], &maxsq, &jpu);
	    jpg = ia + 4;
	    daread_(&ga[301], &maxsq, &jpg);
	} else {
	    jpu = ia + 7;
	    daread_(&ua[301], &maxsq, &jpu);
	    jpg = ia + 10;
	    daread_(&ga[301], &maxsq, &jpg);
	}
/* READ VALUES FOR (W,-W) */
	if (*iwflb == 3) {
	    jpu = ib + 7;
	    daread_(&x[301], &maxsq, &jpu);
	    d__1 = -one;
	    fhpatn_(&ub[301], &x[301], &molkst_1.norbs, &c__2, &d__1);
	    jpg = ib + 10;
	    daread_(&x[301], &maxsq, &jpg);
	    fhpatn_(&gb[301], &x[301], &molkst_1.norbs, &c__2, &one);
/* READ VALUES FOR OKE */

	} else if (*iwflb == 0) {
	    jpu = ib + 1;
	    daread_(&ub[301], &maxsq, &jpu);
	    jpg = ib + 4;
	    daread_(&gb[301], &maxsq, &jpg);
	} else {
	    jpu = ib + 7;
	    daread_(&ub[301], &maxsq, &jpu);
	    jpg = ib + 10;
	    daread_(&gb[301], &maxsq, &jpg);
	}

/*  CONSTRUCT T-MATRIX ONE TIME */

	tf_(&ua[301], &ga[301], &ub[301], &gb[301], &t[301], &molkst_1.norbs, 
		&molkst_1.nclose, iwflb);

/*  CALCULATE INITIAL DENSITY AND BETA VALUE */

	bdensf_(&ua[301], &ub[301], &uab[301], vector_1.c__, &d__[301], &da[
		301], &molkst_1.norbs, &molkst_1.nclose, iwflb);
	betaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	dela = (d__1 = betold - betaw, abs(d__1));
	betold = betaw;

/* INITIALIZE FOCK MATRIX */

	ffreq2_(&f[301], &d__[301], wmatrx_1.w, &molkst_1.numat, 
		molkst_1.nfirst, molkst_1.nlast, &molkst_1.norbs);
	ffreq1_(&f[301], &d__[301], &da[301], &da[301], &molkst_1.norbs);
	zerom_(&da[301], &molkst_1.norbs);
	hplusf_(&f[301], &da[301], &molkst_1.norbs);
/* ................................................................. */
/*  LOOP STARTS HERE */
/* ................................................................. */
	icount = 0;
L30:
	++icount;
	if (icount >= *maxitu) {
	    last = TRUE_;
	}

/*  CREATE G MATRIX. */

	transf_(&f[301], &g[301], vector_1.c__, &molkst_1.norbs);

/*  FORM U MATRIX */

	bmakuf_(&ua[301], &ub[301], &uab[301], &t[301], &uold1[301], &g[301], 
		vector_1.eigs, &last, &molkst_1.norbs, &molkst_1.nclose, &
		diff, iwflb, &maxu, btol);

/*  FORM NEW DENSITY MATRIX */

	bdensf_(&ua[301], &ub[301], &uab[301], vector_1.c__, &d__[301], &da[
		301], &molkst_1.norbs, &molkst_1.nclose, iwflb);
/* ... */
/* COMPUTE TEST BETA */

	betaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	dela = (d__1 = betold - betaw, abs(d__1));
	betold = betaw;
/*         IF (LAST.OR.(ICOUNT.GT.(MAXITU-5))) THEN */
/*             WRITE(6,1500) ICOUNT,DELA,MAXU,DIFF */
/* 1500        FORMAT(' ',I4,'  DELTA BETA = ', D12.5, */
/*     X       ' MAXU = ', D12.5, '  UDIFF = ', D12.5) */
/*         ENDIF */

/*  CREATE NEW FOCK MATRIX */

	zerom_(&f[301], &molkst_1.norbs);
	ffreq2_(&f[301], &d__[301], wmatrx_1.w, &molkst_1.numat, 
		molkst_1.nfirst, molkst_1.nlast, &molkst_1.norbs);
	ffreq1_(&f[301], &d__[301], &da[301], &da[301], &molkst_1.norbs);
	zerom_(&da[301], &molkst_1.norbs);
	hplusf_(&f[301], &da[301], &molkst_1.norbs);
/* .............................................................. */
	if (! last) {
	    goto L30;
	}
	cmptim = second_() - cmptim;
	s_wsfe(&io___187);
	do_fio(&c__1, (char *)&icount, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&cmptim, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___188);
	do_fio(&c__1, (char *)&maxu, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&diff, (ftnlen)sizeof(doublereal));
	e_wsfe();

/* COMPUTE BETA */

/*        CALL HMUF(H1,ID,COORD,NFIRST,NLAST,NAT,NORBS,NUMAT) */
/*        BETAW = AVAL(H1,D,NORBS) */
/*        WRITE(6,2000) ALAB(ID),ALAB(ID),ALAB(ID),BETAW */
/* 2000    FORMAT('BETA(',A1,',',A1,','A1,') = ',D12.5) */

/*  COMPUTE OTHER COMPONENTS */

	for (ic = 1; ic <= 3; ++ic) {
	    hmuf_(&h1[301], &ic, geom_1.coord, molkst_1.nfirst, 
		    molkst_1.nlast, molkst_1.nat, &molkst_1.norbs, &
		    molkst_1.numat);
	    betaw = aval_(&h1[301], &d__[301], &molkst_1.norbs);
	    allbet[ic + (ia + ib * 3) * 3 - 13] = betaw;
	    s_wsfe(&io___191);
	    do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
	    do_fio(&c__1, alab + (ia - 1), (ftnlen)1);
	    do_fio(&c__1, alab + (ib - 1), (ftnlen)1);
	    do_fio(&c__1, (char *)&betaw, (ftnlen)sizeof(doublereal));
	    e_wsfe();

/* CALCULATE AVERAGE BETA IN THE X-DIRECTION */

	    if (id == 1 && ic == 1) {
		bavx += betaw * 3.;
	    } else if (id == 2 && ic == 2) {
		bavx += betaw * 2.;
	    } else if (id == 3 && ic == 3) {
		bavx += betaw * 2.;
	    } else if ((id == 4 || id == 6) && ic == 1) {
		bavx += betaw;
	    }
/* CALCULATES AVERAGE BETA IN THE Y-DIRECTION */
	    if (id == 4 && ic == 2) {
		bavy += betaw * 3.;
	    } else if (id == 2 && ic == 1) {
		bavy += betaw * 2.;
	    } else if (id == 5 && ic == 3) {
		bavy += betaw * 2.;
	    } else if ((id == 1 || id == 6) && ic == 2) {
		bavy += betaw;
	    }
/* CALCULATES AVERAGE BETA IN THE Z-DIRECTION */
	    if (id == 6 && ic == 3) {
		bavz += betaw * 3.;
	    } else if (id == 3 && ic == 1) {
		bavz += betaw * 2.;
	    } else if (id == 5 && ic == 2) {
		bavz += betaw * 2.;
	    } else if ((id == 4 || id == 1) && ic == 3) {
		bavz += betaw;
	    }
/* L70: */
	}


/* CALL SUBROUTINE TO CALCULATE EPSILON AND UMINUS OMEGA,OMEGA */
/*  EPSILON IN H1 AND UMINUS IN DA */
	epsab_(&h1[301], vector_1.eigs, &g[301], &ga[301], &gb[301], &ua[301],
		 &ub[301], &uab[301], &da[301], &molkst_1.norbs, &
		molkst_1.nclose, iwflb);
	i__1 = iposu + id;
	dawrit_(&uab[301], &maxsq, &i__1);
	i__1 = iposg + id;
	dawrit_(&g[301], &maxsq, &i__1);
	i__1 = ipose + id;
	dawrit_(&h1[301], &maxsq, &i__1);
	i__1 = iposum + id;
	dawrit_(&da[301], &maxsq, &i__1);
/* L80: */
    }

    bavx /= 5.;
    bavy /= 5.;
    bavz /= 5.;
/* CALCULATES AVERAGE BETA */
    d__1 = bavx * bavx + bavy * bavy + bavz * bavz;
    bvec = pow_dd(&d__1, &c_b176);

    s_wsfe(&io___193);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavx, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___194);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavy, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___195);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___196);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bvec, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* betaf_ */

#undef iw


/* Subroutine */ int betal1_(doublereal *u0a, doublereal *g0a, doublereal *
	u1b, doublereal *g1b, doublereal *u1c, doublereal *g1c, integer *
	nclose, integer *norbs, doublereal *term)
{
    /* System generated locals */
    integer u0a_dim1, u0a_offset, u1b_dim1, u1b_offset, u1c_dim1, u1c_offset, 
	    g0a_dim1, g0a_offset, g1b_dim1, g1b_offset, g1c_dim1, g1c_offset;

    /* Local variables */
    static doublereal t1a, t2a, t3a, t4a, t5a, t6a, t1b, t2b, t3b, t4b, t5b, 
	    t6b;
    extern doublereal trugud_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *), trudgu_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    trugdu_(doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, integer *);


/* THIS SUBROUTINE CALCULATES THE TRACE OF UGU MATRICES */

    /* Parameter adjustments */
    g1c_dim1 = *norbs;
    g1c_offset = 1 + g1c_dim1 * 1;
    g1c -= g1c_offset;
    u1c_dim1 = *norbs;
    u1c_offset = 1 + u1c_dim1 * 1;
    u1c -= u1c_offset;
    g1b_dim1 = *norbs;
    g1b_offset = 1 + g1b_dim1 * 1;
    g1b -= g1b_offset;
    u1b_dim1 = *norbs;
    u1b_offset = 1 + u1b_dim1 * 1;
    u1b -= u1b_offset;
    g0a_dim1 = *norbs;
    g0a_offset = 1 + g0a_dim1 * 1;
    g0a -= g0a_offset;
    u0a_dim1 = *norbs;
    u0a_offset = 1 + u0a_dim1 * 1;
    u0a -= u0a_offset;

    /* Function Body */
    t1a = trugud_(&u0a[u0a_offset], &g1b[g1b_offset], &u1c[u1c_offset], 
	    nclose, norbs, norbs);
    t2a = trudgu_(&u1c[u1c_offset], &g1b[g1b_offset], &u0a[u0a_offset], 
	    nclose, norbs, norbs);
    t3a = trugdu_(&u1b[u1b_offset], &g1c[g1c_offset], &u0a[u0a_offset], 
	    nclose, norbs, norbs);
    t4a = trugdu_(&u0a[u0a_offset], &g1c[g1c_offset], &u1b[u1b_offset], 
	    nclose, norbs, norbs);
    t5a = trudgu_(&u1c[u1c_offset], &g0a[g0a_offset], &u1b[u1b_offset], 
	    nclose, norbs, norbs);
    t6a = trugud_(&u1b[u1b_offset], &g0a[g0a_offset], &u1c[u1c_offset], 
	    nclose, norbs, norbs);
    t1b = trugud_(&u0a[u0a_offset], &g1b[g1b_offset], &u1c[u1c_offset], norbs,
	     nclose, norbs);
    t2b = trudgu_(&u1c[u1c_offset], &g1b[g1b_offset], &u0a[u0a_offset], norbs,
	     nclose, norbs);
    t3b = trugdu_(&u1b[u1b_offset], &g1c[g1c_offset], &u0a[u0a_offset], norbs,
	     nclose, norbs);
    t4b = trugdu_(&u0a[u0a_offset], &g1c[g1c_offset], &u1b[u1b_offset], norbs,
	     nclose, norbs);
    t5b = trudgu_(&u1c[u1c_offset], &g0a[g0a_offset], &u1b[u1b_offset], norbs,
	     nclose, norbs);
    t6b = trugud_(&u1b[u1b_offset], &g0a[g0a_offset], &u1c[u1c_offset], norbs,
	     nclose, norbs);
    *term = t1b - t1a + t2b - t2a + t3a - t3b + t4a - t4b + t5b - t5a + t6b - 
	    t6a;
    return 0;
} /* betal1_ */

/* Subroutine */ int betall_(doublereal *u2a, doublereal *g2a, doublereal *
	u1b, doublereal *g1b, doublereal *u1c, doublereal *g1c, integer *
	nclose, integer *norbs, doublereal *term)
{
    /* System generated locals */
    integer u2a_dim1, u2a_offset, u1b_dim1, u1b_offset, u1c_dim1, u1c_offset, 
	    g2a_dim1, g2a_offset, g1b_dim1, g1b_offset, g1c_dim1, g1c_offset;

    /* Local variables */
    static doublereal t1a, t2a, t3a, t4a, t5a, t6a, t1b, t2b, t3b, t4b, t5b, 
	    t6b;
    extern doublereal trudgu_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *), trugud_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    trugdu_(doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, integer *);


/* THIS SUBROUTINE CALCULATES TRACE OF UGU MATRICES */
/* WHEN A,B,C DIRECTIONS ARE DIFFERENT */

    /* Parameter adjustments */
    g1c_dim1 = *norbs;
    g1c_offset = 1 + g1c_dim1 * 1;
    g1c -= g1c_offset;
    u1c_dim1 = *norbs;
    u1c_offset = 1 + u1c_dim1 * 1;
    u1c -= u1c_offset;
    g1b_dim1 = *norbs;
    g1b_offset = 1 + g1b_dim1 * 1;
    g1b -= g1b_offset;
    u1b_dim1 = *norbs;
    u1b_offset = 1 + u1b_dim1 * 1;
    u1b -= u1b_offset;
    g2a_dim1 = *norbs;
    g2a_offset = 1 + g2a_dim1 * 1;
    g2a -= g2a_offset;
    u2a_dim1 = *norbs;
    u2a_offset = 1 + u2a_dim1 * 1;
    u2a -= u2a_offset;

    /* Function Body */
    t1a = trudgu_(&u2a[u2a_offset], &g1b[g1b_offset], &u1c[u1c_offset], 
	    nclose, norbs, norbs);
    t2a = trugud_(&u1c[u1c_offset], &g1b[g1b_offset], &u2a[u2a_offset], 
	    nclose, norbs, norbs);
    t3a = trugud_(&u1b[u1b_offset], &g1c[g1c_offset], &u2a[u2a_offset], 
	    nclose, norbs, norbs);
    t4a = trudgu_(&u2a[u2a_offset], &g1c[g1c_offset], &u1b[u1b_offset], 
	    nclose, norbs, norbs);
    t5a = trugdu_(&u1c[u1c_offset], &g2a[g2a_offset], &u1b[u1b_offset], 
	    nclose, norbs, norbs);
    t6a = trugdu_(&u1b[u1b_offset], &g2a[g2a_offset], &u1c[u1c_offset], 
	    nclose, norbs, norbs);
    t1b = trudgu_(&u2a[u2a_offset], &g1b[g1b_offset], &u1c[u1c_offset], norbs,
	     nclose, norbs);
    t2b = trugud_(&u1c[u1c_offset], &g1b[g1b_offset], &u2a[u2a_offset], norbs,
	     nclose, norbs);
    t3b = trugud_(&u1b[u1b_offset], &g1c[g1c_offset], &u2a[u2a_offset], norbs,
	     nclose, norbs);
    t4b = trudgu_(&u2a[u2a_offset], &g1c[g1c_offset], &u1b[u1b_offset], norbs,
	     nclose, norbs);
    t5b = trugdu_(&u1c[u1c_offset], &g2a[g2a_offset], &u1b[u1b_offset], norbs,
	     nclose, norbs);
    t6b = trugdu_(&u1b[u1b_offset], &g2a[g2a_offset], &u1c[u1c_offset], norbs,
	     nclose, norbs);
    *term = t1b - t1a + t2b - t2a + t3b - t3a + t4b - t4a + t5a - t5b + t6a - 
	    t6b;
    return 0;
} /* betall_ */

/* Subroutine */ int betcom_(doublereal *u1, doublereal *g1, doublereal *u2, 
	doublereal *g2, integer *nclose, integer *norbs, doublereal *term)
{
    /* System generated locals */
    integer u1_dim1, u1_offset, u2_dim1, u2_offset, g1_dim1, g1_offset, 
	    g2_dim1, g2_offset;

    /* Local variables */
    static doublereal t1a, t2a, t3a, t1b, t2b, t3b;
    extern doublereal trudgu_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *), trugud_(doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    trugdu_(doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, integer *);


/* THIS SUBROUTINE CALCULATES TRACE OF UGU MATRICES */

    /* Parameter adjustments */
    g2_dim1 = *norbs;
    g2_offset = 1 + g2_dim1 * 1;
    g2 -= g2_offset;
    u2_dim1 = *norbs;
    u2_offset = 1 + u2_dim1 * 1;
    u2 -= u2_offset;
    g1_dim1 = *norbs;
    g1_offset = 1 + g1_dim1 * 1;
    g1 -= g1_offset;
    u1_dim1 = *norbs;
    u1_offset = 1 + u1_dim1 * 1;
    u1 -= u1_offset;

    /* Function Body */
    t1a = trudgu_(&u2[u2_offset], &g1[g1_offset], &u1[u1_offset], nclose, 
	    norbs, norbs);
    t2a = trugud_(&u1[u1_offset], &g1[g1_offset], &u2[u2_offset], nclose, 
	    norbs, norbs);
    t3a = trugdu_(&u1[u1_offset], &g2[g2_offset], &u1[u1_offset], nclose, 
	    norbs, norbs);
    t1b = trudgu_(&u2[u2_offset], &g1[g1_offset], &u1[u1_offset], norbs, 
	    nclose, norbs);
    t2b = trugud_(&u1[u1_offset], &g1[g1_offset], &u2[u2_offset], norbs, 
	    nclose, norbs);
    t3b = trugdu_(&u1[u1_offset], &g2[g2_offset], &u1[u1_offset], norbs, 
	    nclose, norbs);
    *term = (t1b - t1a + t2b - t2a + t3a - t3b) * 2.;
    return 0;
} /* betcom_ */

/* Subroutine */ int bmakuf_(doublereal *ua, doublereal *ub, doublereal *uab, 
	doublereal *t, doublereal *uold1, doublereal *gab, doublereal *eigs, 
	logical *last, integer *norbs, integer *nclose, doublereal *diff, 
	integer *iwflb, doublereal *maxu, doublereal *btol)
{
    /* System generated locals */
    integer ua_dim1, ua_offset, uold1_dim1, uold1_offset, t_dim1, t_offset, 
	    gab_dim1, gab_offset, uab_dim1, uab_offset, ub_dim1, ub_offset, 
	    i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, kll, kul;
    static doublereal sum, udif;


/*  THIS SUBROUTINE CREATES THE NEW TRANSFORMATION MATRIX U */
/*  AND THEN CHECKS FOR CONVERGENCE */


/*  ZERO MATRIX INITIALLY */
/*      CALL ZEROM(UAB,NORBS) */

/*  CREATE DIAGONAL BLOCKS (OCC,OCC) AND (UNOCC,UNOCC) */

    /* Parameter adjustments */
    --eigs;
    gab_dim1 = *norbs;
    gab_offset = 1 + gab_dim1 * 1;
    gab -= gab_offset;
    uold1_dim1 = *norbs;
    uold1_offset = 1 + uold1_dim1 * 1;
    uold1 -= uold1_offset;
    t_dim1 = *norbs;
    t_offset = 1 + t_dim1 * 1;
    t -= t_offset;
    uab_dim1 = *norbs;
    uab_offset = 1 + uab_dim1 * 1;
    uab -= uab_offset;
    ub_dim1 = *norbs;
    ub_offset = 1 + ub_dim1 * 1;
    ub -= ub_offset;
    ua_dim1 = *norbs;
    ua_offset = 1 + ua_dim1 * 1;
    ua -= ua_offset;

    /* Function Body */
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    sum = 0.;
	    if (i__ <= *nclose) {
		kll = *nclose + 1;
		kul = *norbs;
	    } else if (i__ > *nclose && j > *nclose) {
		kll = 1;
		kul = *nclose;
	    }
	    i__3 = kul;
	    for (k = kll; k <= i__3; ++k) {
		sum = sum + ua[i__ + k * ua_dim1] * ub[k + j * ub_dim1] + ub[
			i__ + k * ub_dim1] * ua[k + j * ua_dim1];
/* L10: */
	    }
	    uab[i__ + j * uab_dim1] = sum * .5;
	    uab[j + i__ * uab_dim1] = sum * .5;
/* L20: */
	}
/* L30: */
    }

/*  CREATE OFF-DIAGONAL BLOCKS */

    i__1 = *norbs;
    for (k = *nclose + 1; k <= i__1; ++k) {
	i__2 = *nclose;
	for (l = 1; l <= i__2; ++l) {
	    switch (*iwflb) {
		case 1:  goto L40;
		case 2:  goto L50;
		case 3:  goto L60;
	    }
/* CALCULATE FOR (W,W) VALUES */

L40:
	    uab[k + l * uab_dim1] = (gab[k + l * gab_dim1] + t[k + l * t_dim1]
		    ) / (eigs[l] - eigs[k] - omval_1.omega * 2.) * 27.2113961;
	    uab[l + k * uab_dim1] = (gab[l + k * gab_dim1] + t[l + k * t_dim1]
		    ) / (eigs[k] - eigs[l] - omval_1.omega * 2.) * 27.2113961;
	    goto L70;
/* CALCULATE FOR (0,W) VALUES */

L50:
	    uab[k + l * uab_dim1] = (gab[k + l * gab_dim1] + t[k + l * t_dim1]
		    ) / (eigs[l] - eigs[k] - omval_1.omega) * 27.2113961;
	    uab[l + k * uab_dim1] = (gab[l + k * gab_dim1] + t[l + k * t_dim1]
		    ) / (eigs[k] - eigs[l] - omval_1.omega) * 27.2113961;
	    goto L70;
/* CALCULATE FOR (W,-W) VALUES */

L60:
	    uab[k + l * uab_dim1] = (gab[k + l * gab_dim1] + t[k + l * t_dim1]
		    ) / (eigs[l] - eigs[k]) * 27.2113961;
	    uab[l + k * uab_dim1] = (gab[l + k * gab_dim1] + t[l + k * t_dim1]
		    ) / (eigs[k] - eigs[l]) * 27.2113961;
L70:
	    ;
	}
/* L80: */
    }

/*  CHECK FOR CONVERGENCE */

    *diff = 0.;
    *maxu = -1e3;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    udif = uab[i__ + j * uab_dim1] - uold1[i__ + j * uold1_dim1];
	    if (*diff < abs(udif)) {
		*diff = abs(udif);
	    }
	    if (*maxu < uab[i__ + j * uab_dim1]) {
		*maxu = uab[i__ + j * uab_dim1];
	    }
/* L90: */
	}
/* L100: */
    }
    if (*diff < *btol) {
	*last = TRUE_;
    }

    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    uold1[i__ + j * uold1_dim1] = uab[i__ + j * uab_dim1];
/* L110: */
	}
/* L120: */
    }

    return 0;
} /* bmakuf_ */

/* Subroutine */ int copym_(doublereal *h__, doublereal *f, integer *m)
{
    /* System generated locals */
    integer f_dim1, f_offset, h_dim1, h_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;


/*  COPYM COPIES MATRIX H INTO F */

    /* Parameter adjustments */
    f_dim1 = *m;
    f_offset = 1 + f_dim1 * 1;
    f -= f_offset;
    h_dim1 = *m;
    h_offset = 1 + h_dim1 * 1;
    h__ -= h_offset;

    /* Function Body */
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    f[i__ + j * f_dim1] = h__[i__ + j * h_dim1];
/* L10: */
	}
/* L20: */
    }
    return 0;
} /* copym_ */

/* Subroutine */ int darea1_(doublereal *v, integer *len, integer *idaf, 
	integer *ns)
{
    /* System generated locals */
    integer v_dim1, i__1;

    /* Builtin functions */
    integer s_rdue(cilist *), do_uio(integer *, char *, ftnlen), e_rdue(void);

    /* Fortran I/O blocks */
    static cilist io___237 = { 0, 0, 0, 0, 0 };



/*       READ A PHYSICAL RECORD FROM THE DAF */

    /* Parameter adjustments */
    v_dim1 = *len;
    --v;

    /* Function Body */
    io___237.ciunit = *idaf;
    io___237.cirec = *ns;
    s_rdue(&io___237);
    i__1 = 1 * v_dim1;
    do_uio(&i__1, (char *)&v[1], (ftnlen)sizeof(doublereal));
    e_rdue();
    return 0;
} /* darea1_ */

/* Subroutine */ int daread_(doublereal *v, integer *len, integer *nrec)
{
    /* Format strings */
    static char fmt_30[] = "(1x,\002*** ERROR ***, ATTEMPT TO READ A DAF REC"
	    "ORD\002,\002 THAT WAS NEVER WRITTEN. NREC,LEN=\002,i5,i10)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer n, if__, is;
#define iw ((integer *)&chanel_1 + 5)
    static integer ns, nsp, lent, lenw;
    extern /* Subroutine */ int darea1_(doublereal *, integer *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___246 = { 0, 6, 0, fmt_30, 0 };




/*         READ A LOGICAL RECORD FROM THE DAF DICTIONARY FILE */
/*         A LOGICAL RECORD MAY SPAN SEVERAL PHYSICAL RECORDS. */

    /* Parameter adjustments */
    --v;

    /* Function Body */
    n = iodaf_1.ioda[*nrec - 1];
    if (n == -1) {
	goto L20;
    }
    is = -iodaf_1.irecln + 1;
    ns = n;
    lent = *len;
L10:
    is += iodaf_1.irecln;
    if__ = is + lent - 1;
    if (if__ - is + 1 > iodaf_1.irecln) {
	if__ = is + iodaf_1.irecln - 1;
    }
    nsp = ns;
    lenw = if__ - is + 1;
    darea1_(&v[is], &lenw, &iodaf_1.idaf, &nsp);
    lent -= iodaf_1.irecln;
    ++ns;
    n = ns;
    if (lent >= 1) {
	goto L10;
    }
    return 0;

L20:
    s_wsfe(&io___246);
    do_fio(&c__1, (char *)&(*nrec), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*len), (ftnlen)sizeof(integer));
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* daread_ */

#undef iw


/* Subroutine */ int dawrit_(doublereal *v, integer *len, integer *nrec)
{
    /* Format strings */
    static char fmt_40[] = "(1x,\002DAWRIT HAS REQUESTED A RECORD WITH LEN"
	    "GTH\002,1x,\002DIFFERENT THAN BEFORE - ABORT FORCED.\002/1x,\002"
	    "DAF RECORD \002,i5,\002 NEW LENGTH =\002,i5,\002 OLD LENGTH ="
	    "\002,i5)";

    /* Builtin functions */
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue(void),
	     s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void)
	    ;
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer n, if__, is;
#define iw ((integer *)&chanel_1 + 5)
    static integer ns, ipk, ist, nsp, lent, lenw;
    extern /* Subroutine */ int dawrt1_(doublereal *, integer *, integer *, 
	    integer *);
    static logical newrec;

    /* Fortran I/O blocks */
    static cilist io___256 = { 0, 0, 0, 0, 1 };
    static cilist io___259 = { 0, 6, 0, fmt_40, 0 };






/*         WRITE A LOGICAL RECORD ON THE DAF DICTIONARY FILE */
/*         A LOGICAL RECORD MAY SPAN SEVERAL PHYSICAL RECORDS */

    /* Parameter adjustments */
    --v;

    /* Function Body */
    n = iodaf_1.ioda[*nrec - 1];
    if (n > 0 && *len != iodaf_1.ifilen[*nrec - 1]) {
	goto L30;
    }
    newrec = FALSE_;
    if (n > 0) {
	goto L10;
    }
    iodaf_1.ioda[*nrec - 1] = iodaf_1.irecst;
    iodaf_1.ifilen[*nrec - 1] = *len;
    newrec = TRUE_;
    iodaf_1.irecst = iodaf_1.irecst + (*len - 1) / iodaf_1.irecln + 1;
    n = iodaf_1.ioda[*nrec - 1];
L10:
    ist = -iodaf_1.irecln + 1;
    ns = n;
    lent = *len;
L20:
    ist += iodaf_1.irecln;
    if__ = ist + lent - 1;
    if (if__ - ist + 1 > iodaf_1.irecln) {
	if__ = ist + iodaf_1.irecln - 1;
    }
    nsp = ns;
    lenw = if__ - ist + 1;
    dawrt1_(&v[ist], &lenw, &iodaf_1.idaf, &nsp);
    lent -= iodaf_1.irecln;
    ++ns;
    n = ns;
    if (lent >= 1) {
	goto L20;
    }
    if (newrec) {
	io___256.ciunit = iodaf_1.idaf;
	s_wdue(&io___256);
	do_uio(&c__1, (char *)&iodaf_1.irecst, (ftnlen)sizeof(integer));
	do_uio(&c__145, (char *)&iodaf_1.ioda[0], (ftnlen)sizeof(integer));
	do_uio(&c__145, (char *)&iodaf_1.ifilen[0], (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&is, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&ipk, (ftnlen)sizeof(integer));
	e_wdue();
    }

/*     THE CRAY/CTSS SYSTEM HAS A BUG IN IT!  THIS CALL TO DAWRIT */
/*     DOES NOT ALWAYS SUCCEED IN TRANFERRING DATA TO THE DISK, */
/*     LEAVING THE DATA ONLY IN THE BUFFER.  SUBSEQUENT CALLS */
/*     TO DAREAD FOR OTHER LOGICAL RECORDS WILL DESTROY THE */
/*     BUFFER RESIDENT DATA, AND THE DATA WILL BE LOST FOREVER. */
/*     THE FOLLOWING CALL QUARANTEES THE BUFFER IS FLUSHED */
/*     TO DISK.  IT SHOULD BE REMOVED IF THIS BUG IS EVER FIXED. */

/* CTS  CALL EMPTY(IDAF) */
    return 0;

L30:
    s_wsfe(&io___259);
    do_fio(&c__1, (char *)&(*nrec), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*len), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&iodaf_1.ifilen[*nrec - 1], (ftnlen)sizeof(integer))
	    ;
    e_wsfe();
    s_stop("", (ftnlen)0);

    return 0;
} /* dawrit_ */

#undef iw


/* *MODULE IOLIB   *DECK DAWRT1 */
/* Subroutine */ int dawrt1_(doublereal *v, integer *len, integer *idaf, 
	integer *ns)
{
    /* System generated locals */
    integer v_dim1, i__1;

    /* Builtin functions */
    integer s_wdue(cilist *), do_uio(integer *, char *, ftnlen), e_wdue(void);

    /* Fortran I/O blocks */
    static cilist io___260 = { 0, 0, 0, 0, 0 };



/*     ----- WRITE A PHYSICAL RECORD ON THE DAF ----- */

    /* Parameter adjustments */
    v_dim1 = *len;
    --v;

    /* Function Body */
    io___260.ciunit = *idaf;
    io___260.cirec = *ns;
    s_wdue(&io___260);
    i__1 = 1 * v_dim1;
    do_uio(&i__1, (char *)&v[1], (ftnlen)sizeof(doublereal));
    e_wdue();
    return 0;
} /* dawrt1_ */

/* Subroutine */ int densf_(doublereal *u, doublereal *c__, doublereal *ca, 
	doublereal *d__, doublereal *da, integer *norbs, integer *nclose)
{
    /* System generated locals */
    integer c_dim1, c_offset, ca_dim1, ca_offset, d_dim1, d_offset, u_dim1, 
	    u_offset, da_dim1, da_offset, i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal sk1, sk2, sum;


/*  THIS SUBROUTINE IS USED TO COMPUTE THE FIRST-ORDER DENSITY */
/*  FROM CA = C*U */


/*  FORM DENSITY MATRIX      CA*N*C+ + C*N*CA+ */

    /* Parameter adjustments */
    da_dim1 = *norbs;
    da_offset = 1 + da_dim1 * 1;
    da -= da_offset;
    d_dim1 = *norbs;
    d_offset = 1 + d_dim1 * 1;
    d__ -= d_offset;
    ca_dim1 = *norbs;
    ca_offset = 1 + ca_dim1 * 1;
    ca -= ca_offset;
    c_dim1 = *norbs;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    u_dim1 = *norbs;
    u_offset = 1 + u_dim1 * 1;
    u -= u_offset;

    /* Function Body */
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    sum = 0.;
	    i__3 = *norbs;
	    for (k = 1; k <= i__3; ++k) {
		sk1 = 0.;
		sk2 = 0.;
		i__4 = *nclose;
		for (l = 1; l <= i__4; ++l) {
		    sk1 += u[k + l * u_dim1] * c__[j + l * c_dim1];
		    sk2 += c__[i__ + l * c_dim1] * u[l + k * u_dim1];
/* L10: */
		}
		sum = sum + c__[i__ + k * c_dim1] * sk1 - sk2 * c__[j + k * 
			c_dim1];
/* L20: */
	    }
	    d__[i__ + j * d_dim1] = sum * 2.;
	    da[i__ + j * da_dim1] = sum;
/* L30: */
	}
/* L40: */
    }

    return 0;
} /* densf_ */

/* Subroutine */ int epsab_(doublereal *eigsab, doublereal *eigs, doublereal *
	gab, doublereal *ga, doublereal *gb, doublereal *ua, doublereal *ub, 
	doublereal *uab, doublereal *udms, integer *norbs, integer *nclose, 
	integer *iwflb)
{
    /* System generated locals */
    integer eigsab_dim1, eigsab_offset, ga_dim1, ga_offset, gb_dim1, 
	    gb_offset, gab_dim1, gab_offset, uab_dim1, uab_offset, ua_dim1, 
	    ua_offset, ub_dim1, ub_offset, udms_dim1, udms_offset, i__1, i__2,
	     i__3;

    /* Local variables */
    static integer i__, j, k;
    static doublereal s1, s2, omval;
    extern /* Subroutine */ int zerom_(doublereal *, integer *);


/*  THIS SUBROUTINE CREATES THE NEW EPSILON MATRIX AND UDMS MATRIX */


/*  ZERO EPSILON OMEGA OMEGA MATRIX INITIALLY */

    /* Parameter adjustments */
    udms_dim1 = *norbs;
    udms_offset = 1 + udms_dim1 * 1;
    udms -= udms_offset;
    uab_dim1 = *norbs;
    uab_offset = 1 + uab_dim1 * 1;
    uab -= uab_offset;
    ub_dim1 = *norbs;
    ub_offset = 1 + ub_dim1 * 1;
    ub -= ub_offset;
    ua_dim1 = *norbs;
    ua_offset = 1 + ua_dim1 * 1;
    ua -= ua_offset;
    gb_dim1 = *norbs;
    gb_offset = 1 + gb_dim1 * 1;
    gb -= gb_offset;
    ga_dim1 = *norbs;
    ga_offset = 1 + ga_dim1 * 1;
    ga -= ga_offset;
    gab_dim1 = *norbs;
    gab_offset = 1 + gab_dim1 * 1;
    gab -= gab_offset;
    --eigs;
    eigsab_dim1 = *norbs;
    eigsab_offset = 1 + eigsab_dim1 * 1;
    eigsab -= eigsab_offset;

    /* Function Body */
    zerom_(&eigsab[eigsab_offset], norbs);

/*  ZERO UAB MINUS OMEGA,OMEGA MATRIX INITIALLY */

    zerom_(&udms[udms_offset], norbs);

    if (*iwflb == 0 || *iwflb == 1) {
	omval = omval_1.omega * 2.;
    } else if (*iwflb == 3) {
	omval = 0.;
    } else if (*iwflb == 2) {
	omval = omval_1.omega;
    }
    i__1 = *nclose;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *nclose;
	for (j = 1; j <= i__2; ++j) {
	    s1 = 0.;
	    i__3 = *norbs;
	    for (k = *nclose + 1; k <= i__3; ++k) {

/* CALCULATION FOR EPSAB */

		s1 = s1 + ga[i__ + k * ga_dim1] * ub[k + j * ub_dim1] + gb[
			i__ + k * gb_dim1] * ua[k + j * ua_dim1];

/* L10: */
	    }
	    eigsab[i__ + j * eigsab_dim1] = gab[i__ + j * gab_dim1] + s1 + 
		    uab[i__ + j * uab_dim1] * (eigs[i__] - eigs[j] + omval) / 
		    27.2113961;
/* L20: */
	}
/* L30: */
    }

/* CALCULATION FOR UMS */

    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    s2 = 0.;
	    i__3 = *norbs;
	    for (k = 1; k <= i__3; ++k) {
		s2 = s2 + ua[i__ + k * ua_dim1] * ub[k + j * ub_dim1] + ub[
			i__ + k * ub_dim1] * ua[k + j * ua_dim1];
/* L40: */
	    }

	    udms[i__ + j * udms_dim1] = s2 - uab[i__ + j * uab_dim1];
/* L50: */
	}
/* L60: */
    }

    return 0;
} /* epsab_ */

/* Subroutine */ int ffreq1_(doublereal *f, doublereal *ptot, doublereal *pa, 
	doublereal *pb, integer *ndim)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    integer f_dim1, f_offset, ptot_dim1, ptot_offset, pa_dim1, pa_offset, 
	    pb_dim1, pb_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer j, l, ia, ib, ic, ii, ni, icc;
    static doublereal dapop, dbpop, papop, dtpop;
    static integer iplus;
    static doublereal ptpop;
    static integer iminus;

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
/* ********************************************************************* */

/* *** COMPUTE THE REMAINING CONTRIBUTIONS TO THE ONE-CENTRE ELEMENTS. */

/* ********************************************************************* */
    /* Parameter adjustments */
    pb_dim1 = *ndim;
    pb_offset = 1 + pb_dim1 * 1;
    pb -= pb_offset;
    pa_dim1 = *ndim;
    pa_offset = 1 + pa_dim1 * 1;
    pa -= pa_offset;
    ptot_dim1 = *ndim;
    ptot_offset = 1 + ptot_dim1 * 1;
    ptot -= ptot_offset;
    f_dim1 = *ndim;
    f_offset = 1 + f_dim1 * 1;
    f -= f_offset;

    /* Function Body */
    if (first) {
	first = FALSE_;
    }
    i__1 = molkst_1.numat;
    for (ii = 1; ii <= i__1; ++ii) {
	ia = molkst_1.nfirst[ii - 1];
	ib = molkst_1.nmidle[ii - 1];
	ic = molkst_1.nlast[ii - 1];
	ni = molkst_1.nat[ii - 1];
	dtpop = 0.;
	dapop = 0.;
	ptpop = 0.;
	papop = 0.;
	switch (ic - ia + 2) {
	    case 1:  goto L60;
	    case 2:  goto L30;
	    case 3:  goto L20;
	    case 4:  goto L20;
	    case 5:  goto L20;
	    case 6:  goto L10;
	    case 7:  goto L10;
	    case 8:  goto L10;
	    case 9:  goto L10;
	    case 10:  goto L10;
	}
L10:
	dtpop = ptot[ic + ic * ptot_dim1] + ptot[ic - 1 + (ic - 1) * 
		ptot_dim1] + ptot[ic - 2 + (ic - 2) * ptot_dim1] + ptot[ic - 
		3 + (ic - 3) * ptot_dim1] + ptot[ic - 4 + (ic - 4) * 
		ptot_dim1];
	dapop = pa[ic + ic * pa_dim1] + pa[ic - 1 + (ic - 1) * pa_dim1] + pa[
		ic - 2 + (ic - 2) * pa_dim1] + pa[ic - 3 + (ic - 3) * pa_dim1]
		 + pa[ic - 4 + (ic - 4) * pa_dim1];
L20:
	ptpop = ptot[ib + ib * ptot_dim1] + ptot[ib - 1 + (ib - 1) * 
		ptot_dim1] + ptot[ib - 2 + (ib - 2) * ptot_dim1];
	papop = pa[ib + ib * pa_dim1] + pa[ib - 1 + (ib - 1) * pa_dim1] + pa[
		ib - 2 + (ib - 2) * pa_dim1];
L30:
	dbpop = dtpop - dapop;

/*     F(S,S) */

	f[ia + ia * f_dim1] = f[ia + ia * f_dim1] + pb[ia + ia * pb_dim1] * 
		twoele_1.gss[ni - 1] + ptpop * twoele_1.gsp[ni - 1] - papop * 
		twoele_1.hsp[ni - 1] + dtpop * twoele_1.gsd[ni - 1];
	if (ni < 3) {
	    goto L60;
	}
	iplus = ia + 1;
	i__2 = ib;
	for (j = iplus; j <= i__2; ++j) {

/*     F(P,P) */

	    f[j + j * f_dim1] = f[j + j * f_dim1] + ptot[ia + ia * ptot_dim1] 
		    * twoele_1.gsp[ni - 1] - pa[ia + ia * pa_dim1] * 
		    twoele_1.hsp[ni - 1] + pb[j + j * pb_dim1] * twoele_1.gpp[
		    ni - 1] + (ptpop - ptot[j + j * ptot_dim1]) * 
		    twoele_1.gp2[ni - 1] - (papop - pa[j + j * pa_dim1]) * .5 
		    * (twoele_1.gpp[ni - 1] - twoele_1.gp2[ni - 1]) + dtpop * 
		    twoele_1.gpd[ni - 1];

/*     F(S,P) */

	    f[ia + j * f_dim1] = f[ia + j * f_dim1] + ptot[ia + j * ptot_dim1]
		     * 2. * twoele_1.hsp[ni - 1] - pa[ia + j * pa_dim1] * (
		    twoele_1.hsp[ni - 1] + twoele_1.gsp[ni - 1]);
	    f[j + ia * f_dim1] = f[j + ia * f_dim1] + ptot[j + ia * ptot_dim1]
		     * 2. * twoele_1.hsp[ni - 1] - pa[j + ia * pa_dim1] * (
		    twoele_1.hsp[ni - 1] + twoele_1.gsp[ni - 1]);
/* L40: */
	}

/*     F(P,P*) */

	iminus = ib - 1;
	i__2 = iminus;
	for (j = iplus; j <= i__2; ++j) {
	    icc = j + 1;
	    i__3 = ib;
	    for (l = icc; l <= i__3; ++l) {
		f[j + l * f_dim1] = f[j + l * f_dim1] + ptot[j + l * 
			ptot_dim1] * (twoele_1.gpp[ni - 1] - twoele_1.gp2[ni 
			- 1]) - pa[j + l * pa_dim1] * .5 * (twoele_1.gpp[ni - 
			1] + twoele_1.gp2[ni - 1]);
		f[l + j * f_dim1] = f[l + j * f_dim1] + ptot[l + j * 
			ptot_dim1] * (twoele_1.gpp[ni - 1] - twoele_1.gp2[ni 
			- 1]) - pa[l + j * pa_dim1] * .5 * (twoele_1.gpp[ni - 
			1] + twoele_1.gp2[ni - 1]);
/* L50: */
	    }
	}
L60:
	;
    }
    return 0;
} /* ffreq1_ */

/* Subroutine */ int ffreq2_(doublereal *f, doublereal *ptot, doublereal *w, 
	integer *numat, integer *nfirst, integer *nlast, integer *norbs)
{
    /* System generated locals */
    integer f_dim1, f_offset, ptot_dim1, ptot_offset, i__1, i__2, i__3, i__4, 
	    i__5, i__6;

    /* Local variables */
    static doublereal a;
    static integer i__, j, k, l, ia, ib, ja, jb, ii, jj, kk;
    static doublereal fij, fkl;
    static integer iim1;
    static doublereal aint;

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
/* ******************************************************************* */

/*  TDHF FORMS TWO ELECTRON TWO CENTER REPULSION PART OF THE FOCK */
/*  MATRIX */
/* ON INPUT PTOT = TOTAL DENSITY MATRIX */
/*          P    = ALPHA OR BETA DENSITY MATRIX */
/*          W    = TWO ELECTRON INTEGRAL MATRIX */

/*  ON OUTPUT F = PARTIAL FOCK MATRIX */

/* ******************************************************************** */
    /* Parameter adjustments */
    --w;
    --nfirst;
    --nlast;
    ptot_dim1 = *norbs;
    ptot_offset = 1 + ptot_dim1 * 1;
    ptot -= ptot_offset;
    f_dim1 = *norbs;
    f_offset = 1 + f_dim1 * 1;
    f -= f_offset;

    /* Function Body */
/* L10: */
    kk = 0;

    i__1 = *numat;
    for (ii = 2; ii <= i__1; ++ii) {
	iim1 = ii - 1;
	ia = nfirst[ii];
	ib = nlast[ii];
	i__2 = iim1;
	for (jj = 1; jj <= i__2; ++jj) {
	    ja = nfirst[jj];
	    jb = nlast[jj];
	    i__3 = ib;
	    for (i__ = ia; i__ <= i__3; ++i__) {
		i__4 = i__;
		for (j = ia; j <= i__4; ++j) {
		    fij = 1.;
		    if (i__ == j) {
			fij = .5;
		    }
		    i__5 = jb;
		    for (k = ja; k <= i__5; ++k) {
			i__6 = k;
			for (l = ja; l <= i__6; ++l) {
			    fkl = 1.;
			    if (k == l) {
				fkl = .5;
			    }
			    ++kk;
			    a = w[kk];
			    aint = a * fkl * fij;
			    f[i__ + j * f_dim1] += aint * (ptot[k + l * 
				    ptot_dim1] + ptot[l + k * ptot_dim1]);
			    f[j + i__ * f_dim1] += aint * (ptot[k + l * 
				    ptot_dim1] + ptot[l + k * ptot_dim1]);
			    f[k + l * f_dim1] += aint * (ptot[i__ + j * 
				    ptot_dim1] + ptot[j + i__ * ptot_dim1]);
			    f[l + k * f_dim1] += aint * (ptot[i__ + j * 
				    ptot_dim1] + ptot[j + i__ * ptot_dim1]);
			    aint *= .5;
			    f[i__ + l * f_dim1] -= aint * ptot[j + k * 
				    ptot_dim1];
			    f[l + i__ * f_dim1] -= aint * ptot[k + j * 
				    ptot_dim1];
			    f[k + j * f_dim1] -= aint * ptot[l + i__ * 
				    ptot_dim1];
			    f[j + k * f_dim1] -= aint * ptot[i__ + l * 
				    ptot_dim1];
			    f[i__ + k * f_dim1] -= aint * ptot[j + l * 
				    ptot_dim1];
			    f[k + i__ * f_dim1] -= aint * ptot[l + j * 
				    ptot_dim1];
			    f[j + l * f_dim1] -= aint * ptot[i__ + k * 
				    ptot_dim1];
			    f[l + j * f_dim1] -= aint * ptot[k + i__ * 
				    ptot_dim1];
/* L20: */
			}
/* L30: */
		    }
/* L40: */
		}
/* L50: */
	    }
/* L60: */
	}
/* L70: */
    }
    return 0;
} /* ffreq2_ */

/* Subroutine */ int fhpatn_(doublereal *a, doublereal *b, integer *norbs, 
	integer *itw, doublereal *sign)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;


/* THIS SUBROUTINE CONVERTS THE MATRICES INTO ITS ADJOINTS */

    /* Parameter adjustments */
    b_dim1 = *norbs;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    a_dim1 = *norbs;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;

    /* Function Body */
    switch (*itw) {
	case 1:  goto L10;
	case 2:  goto L40;
	case 3:  goto L40;
	case 4:  goto L10;
    }
L10:
    i__1 = *norbs;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *norbs;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    a[i__ + j * a_dim1] = b[i__ + j * b_dim1];
/* L20: */
	}
/* L30: */
    }
    goto L70;
L40:
    i__1 = *norbs;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *norbs;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    a[i__ + j * a_dim1] = *sign * b[j + i__ * b_dim1];
/* L50: */
	}
/* L60: */
    }
L70:
    return 0;
} /* fhpatn_ */

/* Subroutine */ int hmuf_(doublereal *h1, integer *id, doublereal *coord, 
	integer *nfirst, integer *nlast, integer *nat, integer *norbs, 
	integer *numat)
{
    /* System generated locals */
    integer h1_dim1, h1_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, i1, j1, ia, ib, ni, io1, jo1;
    extern /* Subroutine */ int zerom_(doublereal *, integer *);


/*  FORM THE DIPOLE MOMENT MATRIX FOR COMPONENT ID */


/*  ZERO H1 MATRIX */

    /* Parameter adjustments */
    coord -= 4;
    h1_dim1 = *norbs;
    h1_offset = 1 + h1_dim1 * 1;
    h1 -= h1_offset;
    --nat;
    --nlast;
    --nfirst;

    /* Function Body */
    zerom_(&h1[h1_offset], norbs);

/*  FORM DIPOLE MATRIX */

    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = nfirst[i__];
	ib = nlast[i__];
	ni = nat[i__];
	i__2 = ib;
	for (i1 = ia; i1 <= i__2; ++i1) {
	    i__3 = i1;
	    for (j1 = ia; j1 <= i__3; ++j1) {
		h1[i1 + j1 * h1_dim1] = 0.;
		io1 = i1 - ia;
		jo1 = j1 - ia;
		if (*id == 1 && (jo1 == 0 && io1 == 1)) {
		    h1[i1 + j1 * h1_dim1] = multip_1.dd[ni - 1];
		    h1[j1 + i1 * h1_dim1] = multip_1.dd[ni - 1];
		}
		if (*id == 2 && (jo1 == 0 && io1 == 2)) {
		    h1[i1 + j1 * h1_dim1] = multip_1.dd[ni - 1];
		    h1[j1 + i1 * h1_dim1] = multip_1.dd[ni - 1];
		}
		if (*id == 3 && (jo1 == 0 && io1 == 3)) {
		    h1[i1 + j1 * h1_dim1] = multip_1.dd[ni - 1];
		    h1[j1 + i1 * h1_dim1] = multip_1.dd[ni - 1];
		}
/* L10: */
	    }
	    h1[i1 + i1 * h1_dim1] = 0.;
/* .. ADDED FOR TRANSLATION OF CENTER FROM ORIGIN */
	    h1[i1 + i1 * h1_dim1] += coord[*id + i__ * 3] * 1.8897262;
/* L20: */
	}
/* L30: */
    }

    return 0;
} /* hmuf_ */

/* Subroutine */ int hplusf_(doublereal *f, doublereal *h__, integer *norbs)
{
    /* System generated locals */
    integer f_dim1, f_offset, h_dim1, h_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j;
    static doublereal term;


/* HPLUSF ADDS THE 1 AND 2-ELECTRON PARTS OF THE FOCK MATRIX */

    /* Parameter adjustments */
    h_dim1 = *norbs;
    h_offset = 1 + h_dim1 * 1;
    h__ -= h_offset;
    f_dim1 = *norbs;
    f_offset = 1 + f_dim1 * 1;
    f -= f_offset;

    /* Function Body */
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    term = f[i__ + j * f_dim1] / 27.2113961;
	    f[i__ + j * f_dim1] = h__[i__ + j * h_dim1] + term;
/* L10: */
	}
/* L20: */
    }
    return 0;
} /* hplusf_ */

/* Subroutine */ int makeuf_(doublereal *u, doublereal *uold, doublereal *g, 
	doublereal *eigs, logical *last, integer *norbs, integer *nnorbs, 
	integer *nclose, doublereal *diff, doublereal *atol)
{
    /* System generated locals */
    integer u_dim1, u_offset, uold_dim1, uold_offset, g_dim1, g_offset, i__1, 
	    i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal udif;
    extern /* Subroutine */ int zerom_(doublereal *, integer *);


/*  THIS SUBROUTINE CREATES THE NEW TRANSFORMATION MATRIX U */
/*  AND THEN CHECKS FOR CONVERGENCE */


/*  ZERO MATRIX INITIALLY */

    /* Parameter adjustments */
    --eigs;
    g_dim1 = *norbs;
    g_offset = 1 + g_dim1 * 1;
    g -= g_offset;
    uold_dim1 = *norbs;
    uold_offset = 1 + uold_dim1 * 1;
    uold -= uold_offset;
    u_dim1 = *norbs;
    u_offset = 1 + u_dim1 * 1;
    u -= u_offset;

    /* Function Body */
    zerom_(&u[u_offset], norbs);

/*  CREATE OFF-DIAGONAL BLOCKS */

    i__1 = *norbs;
    for (k = *nclose + 1; k <= i__1; ++k) {
	i__2 = *nclose;
	for (l = 1; l <= i__2; ++l) {
	    u[l + k * u_dim1] = g[l + k * g_dim1] * 27.2113961 / (eigs[k] - 
		    eigs[l] - omval_1.omega);
	    u[k + l * u_dim1] = g[k + l * g_dim1] * 27.2113961 / (eigs[l] - 
		    eigs[k] - omval_1.omega);
/* L10: */
	}
/* L20: */
    }

/*  CHECK FOR CONVERGENCE */

    *diff = 0.;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    udif = (d__1 = u[i__ + j * u_dim1] - uold[i__ + j * uold_dim1], 
		    abs(d__1));
	    if (*diff < udif) {
		*diff = udif;
	    }
/* L30: */
	}
/* L40: */
    }
    if (*diff < *atol) {
	*last = TRUE_;
    }

    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *norbs;
	for (j = 1; j <= i__2; ++j) {
	    uold[i__ + j * uold_dim1] = u[i__ + j * u_dim1];
/* L50: */
	}
/* L60: */
    }

    return 0;
} /* makeuf_ */

/* Subroutine */ int ngamtg_(integer *igam, doublereal *x, doublereal *gd3, 
	doublereal *ud3, doublereal *g1, doublereal *u1, doublereal *gs, 
	doublereal *usmd, doublereal *eps, doublereal *us)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";
    static integer ida[9] = { 1,2,3,1,1,2,2,3,3 };
    static integer idb[9] = { 1,2,3,1,1,2,2,3,3 };
    static integer idc[9] = { 1,2,3,2,3,1,3,1,2 };
    static integer idd[9] = { 1,2,3,2,3,1,3,1,2 };
    static integer ipair[9]	/* was [3][3] */ = { 1,2,3,2,4,5,3,5,6 };

    /* Format strings */
    static char fmt_20[] = "(//,\002 GAMMA (THIRD HARMONIC GENERATION) AT"
	    " \002,f10.5,\002 EV.\002//)";
    static char fmt_90[] = "(\002 GAMMA(\002,a1,\002,\002,a1,\002,\002,a1"
	    ",\002,\002,a1,\002) = \002,1f13.5)";
    static char fmt_110[] = "(//,\002 AVERAGE GAMMA VALUE AT \002,f10.5,\002"
	    " = \0021f13.5,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j2, ia, ib, ic, id, ie, j34;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal yy;
    static integer icd, ibd, ibc;
    static doublereal gav, one;
    static integer msq;
    static doublereal gave, gamma[9];
    static integer jgarc, jgrec, juarc, jurec, imove;
    extern doublereal trsub_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *);
    static integer jg2rec, ju2rec, ju2mrc;
    extern /* Subroutine */ int daread_(doublereal *, integer *, integer *);
    static integer jeprec;
    extern /* Subroutine */ int fhpatn_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___333 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___356 = { 0, 6, 0, fmt_90, 0 };
    static cilist io___358 = { 0, 6, 0, fmt_110, 0 };


/* ..................................................................... */
/*  CALCULATE GAMMA(THG) IN A NONITERATIVE FASHION */
/* ..................................................................... */
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
    /* Parameter adjustments */
    us -= 301;
    eps -= 301;
    usmd -= 301;
    gs -= 301;
    u1 -= 301;
    g1 -= 301;
    ud3 -= 301;
    gd3 -= 301;
    x -= 301;

    /* Function Body */
    one = 1.;
    msq = molkst_1.norbs * molkst_1.norbs;
/* L10: */
    s_wsfe(&io___333);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* IGAM=1 (THIRD HARMONIC GENERATION) */

    jgarc = 22;
    juarc = 19;
    jurec = 7;
    jgrec = 10;
    jg2rec = 55;
    ju2rec = 49;
    ju2mrc = 67;
    jeprec = 61;

/* LOOP BEGINS FOR THE CALCULATION OF GAMMA(ABCD) */

    gav = 0.;
    for (ie = 1; ie <= 9; ++ie) {

	ia = ida[ie - 1];
	ib = idb[ie - 1];
	ic = idc[ie - 1];
	id = idd[ie - 1];
	icd = ipair[ic + id * 3 - 4];
	ibd = ipair[ib + id * 3 - 4];
	ibc = ipair[ib + ic * 3 - 4];

/*  READ IN THE FIRST ORDER U3 OMEGA AND G3 OMEGA IN THE DIRECTION A */

/* MAKE GD3 OMEGA MATRIX FROM G3 MATRIX */

	i__1 = jgarc + ia;
	daread_(&x[301], &msq, &i__1);
	fhpatn_(&gd3[301], &x[301], &molkst_1.norbs, &c__2, &one);

/* MAKE UD3 OMEGA MATRIX FROM U3 OMEGA MATRIX */

	i__1 = juarc + ia;
	daread_(&x[301], &msq, &i__1);
	d__1 = -one;
	fhpatn_(&ud3[301], &x[301], &molkst_1.norbs, &c__2, &d__1);

	yy = 0.;
	imove = 1;
L30:

/* L40: */
	switch (imove) {
	    case 1:  goto L50;
	    case 2:  goto L60;
	    case 3:  goto L70;
	}

L50:
	j2 = ib;
	j34 = icd;
	goto L80;
L60:
	j2 = ic;
	j34 = ibd;
	goto L80;
L70:
	j2 = id;
	j34 = ibc;
L80:

/*  READ IN G1,U1,GS,US,UMS,EPS */

/*  GET  UB */
	i__1 = jurec + j2;
	daread_(&u1[301], &msq, &i__1);
/*  GET  GB */
	i__1 = jgrec + j2;
	daread_(&g1[301], &msq, &i__1);
/*  GET  GCD */
	i__1 = jg2rec + j34;
	daread_(&gs[301], &msq, &i__1);
/*  GET  UCD */
	i__1 = ju2rec + j34;
	daread_(&us[301], &msq, &i__1);
/*  GET  USMD */
	i__1 = ju2mrc + j34;
	daread_(&usmd[301], &msq, &i__1);
/*  GET  EPCD */
	i__1 = jeprec + j34;
	daread_(&eps[301], &msq, &i__1);


/* FIRST KIND */

	yy += trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* SECOND KIND */

	yy += trsub_(&ud3[301], &gs[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy += trsub_(&u1[301], &gs[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &eps[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &eps[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* THIRD KIND */

	yy += trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

	++imove;
	if (imove <= 3) {
	    goto L30;
	}

	gamma[ie - 1] = yy;

/* CALCULATE THE AVERAGE GAMMA VALUE */

	gav += yy;

/* WRITE GAMMA(ABCD) */

	s_wsfe(&io___356);
	do_fio(&c__1, alab + (ia - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ib - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
	do_fio(&c__1, alab + (id - 1), (ftnlen)1);
	do_fio(&c__1, (char *)&gamma[ie - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();

/* L100: */
    }
    gave = gav / 5.;
    s_wsfe(&io___358);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gave, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* ngamtg_ */

#undef iw


/* Subroutine */ int ngefis_(integer *igam, doublereal *x, doublereal *gd3, 
	doublereal *ud3, doublereal *g1, doublereal *u1, doublereal *gs, 
	doublereal *usmd, doublereal *eps, doublereal *us)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";
    static integer ida[15] = { 1,2,3,1,1,2,2,3,3,1,1,2,2,3,3 };
    static integer idb[15] = { 1,2,3,2,3,1,3,1,2,1,1,2,2,3,3 };
    static integer idc[15] = { 1,2,3,1,1,2,2,3,3,2,3,1,3,1,2 };
    static integer idd[15] = { 1,2,3,2,3,1,3,1,2,2,3,1,3,1,2 };
    static integer ip[9]	/* was [3][3] */ = { 1,2,3,2,4,5,3,5,6 };
    static integer ipair[9]	/* was [3][3] */ = { 1,4,7,2,5,8,3,6,9 };

    /* Format strings */
    static char fmt_10[] = "(//,\002 GAMMA (DC-EFISHG) AT \002,f10.5,\002 "
	    "EV.\002//)";
    static char fmt_80[] = "(\002 GAMMA(\002,a1,\002,\002,a1,\002,\002,a1"
	    ",\002,\002,a1,\002) = \002,1pd14.7)";
    static char fmt_100[] = "(//,\002 AVERAGE GAMMA VALUE AT \002,f10.5,\002"
	    " EV = \002,1pd14.7,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j2, ia, ib, ic, id, ie, j34;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal yy;
    static integer j3e, j3g, j3u, icd, ibd, ibc;
    static doublereal gav, one;
    static integer msq, j3um;
    static doublereal gave, gamma[15];
    static integer jgarc, jgrec, juarc, jurec, imove;
    extern doublereal trsub_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *);
    static integer jg2rec, ju2rec, ju2mrc;
    extern /* Subroutine */ int daread_(doublereal *, integer *, integer *);
    static integer jeprec;
    extern /* Subroutine */ int fhpatn_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___369 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___396 = { 0, 6, 0, fmt_80, 0 };
    static cilist io___398 = { 0, 6, 0, fmt_100, 0 };


/* ..................................................................... */
/*  CALCULATE GAMMA(DC-EFISHG) IN A NONITERATIVE FASHION */
/* ..................................................................... */
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
    /* Parameter adjustments */
    us -= 301;
    eps -= 301;
    usmd -= 301;
    gs -= 301;
    u1 -= 301;
    g1 -= 301;
    ud3 -= 301;
    gd3 -= 301;
    x -= 301;

    /* Function Body */

    one = 1.;
    msq = molkst_1.norbs * molkst_1.norbs;
    s_wsfe(&io___369);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* GET DATA FROM ALPHA  AND ITERATIVE BETA CALCULATIONS */

/*   REQUIRED RECORDS FROM POLARIZABILITY CALCULATIONS */
/*   ------------------------------------------------------- */
/*        0    W    2W    3W */

/*       -02- -08-  -14-  -20-  -U- MATRIX FOR -X- DIRECTION */
/*       -03- -09-  -15-  -21-  -U- MATRIX FOR -Y- DIRECTION */
/*       -04- -10-  -16-  -22-  -U- MATRIX FOR -Z- DIRECTION */
/*       -05- -11-  -17-  -23-  -G- MATRIX FOR -X- DIRECTION */
/*       -06- -12-  -18-  -24-  -G- MATRIX FOR -Y- DIRECTION */
/*       -07- -13-  -19-  -25-  -G- MATRIX FOR -Z- DIRECTION */
/*   ------------------------------------------------------- */
/*      (0,0)    (W,W)    (0,W)    (W,-W) */

/*      -26-     -50-     -74-     -110-   -U- MATRIX FOR -XX- DIRECTION */
/*      -27-     -51-     -75-     -111-   -U- MATRIX FOR -XY- DIRECTION */
/*      -28-     -52-     -76-     -112-   -U- MATRIX FOR -XZ- DIRECTION */
/*                        -77-     -113-   -U- MATRIX DOE -YX- DIRECTION */
/*      -29-     -53-     -78-     -114-   -U- MATRIX FOR -YY- DIRECTION */
/*      -30-     -54-     -79-     -115-   -U- MATRIX FOR -YZ- DIRECTION */
/*                        -80-     -116-   -U- MATRIX FOR -ZX- DIRECTION */
/*                        -81-     -117-   -U- MATRIX FOR -ZY- DIRECTION */
/*      -31-     -55-     -82-     -118-   -U- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/*      -32-     -56-     -83-     -119-   -G- MATRIX FOR -XX- DIRECTION */
/*      -33-     -57-     -84-     -120-   -G- MATRIX FOR -XY- DIRECTION */
/*      -34-     -58-     -85-     -121-   -G- MATRIX FOR -XZ- DIRECTION */
/*                        -86-     -122-   -G- MATRIX FOR -YX- DIRECTION */
/*      -35-     -59-     -87-     -123-   -G- MATRIX FOR -YY- DIRECTION */
/*      -36-     -60-     -88-     -124-   -G- MATRIX FOR -YZ- DIRECTION */
/*                        -89-     -125-   -G- MATRIX FOR -ZX- DIRECTION */
/*                        -90-     -126-   -G- MATRIX FOR -ZY- DIRECTION */
/*      -37-     -61-     -91-     -127-   -G- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/*      -38-     -62-     -92-     -128-   -E- MATRIX FOR -XX- DIRECTION */
/*      -39-     -63-     -93-     -129-   -E- MATRIX FOR -XY- DIRECTION */
/*      -40-     -64-     -94-     -130-   -E- MATRIX FOR -XZ- DIRECTION */
/*                        -95-     -131-   -E- MATRIX FOR -YX- DIRECTION */
/*      -41-     -65-     -96-     -132-   -E- MATRIX FOR -YY- DIRECTION */
/*      -42-     -66-     -97-     -133-   -E- MATRIX FOR -YZ- DIRECTION */
/*                        -98-     -134-   -E- MATRIX FOR -ZX- DIRECTION */
/*                        -99-     -135-   -E- MATRIX FOR -ZY- DIRECTION */
/*      -43-     -67-     -100-    -136-   -E- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/*      -44-     -68-     -101-    -137-   -UM- MATRIX FOR -XX- DIRECTION */
/*      -45-     -69-     -102-    -138-   -UM- MATRIX FOR -XY- DIRECTION */
/*      -46-     -70-     -103-    -139-   -UM- MATRIX FOR -XZ- DIRECTION */
/*                        -104-    -140-   -UM- MATRIX FOR -YX- DIRECTION */
/*      -47-     -71-     -105-    -141-   -UM- MATRIX FOR -YY- DIRECTION */
/*      -48-     -72-     -106-    -142-   -UM- MATRIX FOR -YZ- DIRECTION */
/*                        -107-    -143-   -UM- MATRIX FOR -ZX- DIRECTION */
/*                        -108-    -144-   -UM- MATRIX FOR -ZY- DIRECTION */
/*      -49-     -73-     -109-    -145-   -UM- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/* CALCULATION OF DIFFERENT GAMMA VALUES IN A NONITERATIVE METHOD. */

/* IGAM=2 (DC-ELECTIC FIELD INDUCED SECOND HARMONIC GENERATION) */

    jgarc = 16;
    juarc = 13;
    jurec = 1;
    jgrec = 4;
    jg2rec = 55;
    ju2rec = 49;
    ju2mrc = 67;
    jeprec = 61;
/* LOOP BEGINS FOR THE CALCULATION OF GAMMA(ABCD) */

    gav = 0.;
    for (ie = 1; ie <= 15; ++ie) {
	ia = ida[ie - 1];
	ib = idb[ie - 1];
	ic = idc[ie - 1];
	id = idd[ie - 1];
	icd = ip[ic + id * 3 - 4];
	ibd = ipair[ib + id * 3 - 4];
	ibc = ipair[ib + ic * 3 - 4];

/*  READ IN THE FIRST ORDER U3 OMEGA AND G3 OMEGA IN THE DIRECTION A */
/*  MAKE GD3 OMEGA MATRIX FROM G3 MATRIX */

	i__1 = jgarc + ia;
	daread_(&x[301], &msq, &i__1);
	fhpatn_(&gd3[301], &x[301], &molkst_1.norbs, &c__2, &one);

/* MAKE UD3 OMEGA MATRIX FROM U3 OMEGA MATRIX */

	i__1 = juarc + ia;
	daread_(&x[301], &msq, &i__1);
	d__1 = -one;
	fhpatn_(&ud3[301], &x[301], &molkst_1.norbs, &c__2, &d__1);
	yy = 0.;
	imove = 1;
L20:

/* DC EFISHG */

/* L30: */
	switch (imove) {
	    case 1:  goto L40;
	    case 2:  goto L50;
	    case 3:  goto L60;
	}
L40:
	j2 = ib;
	j34 = icd;
	goto L70;
L50:
	j2 = ic + 6;
/*                 J34=IBD+24 */
	j3u = ibd + 24;
	j3g = ibd + 27;
	j3e = ibd + 30;
	j3um = ibd + 33;
	goto L70;
L60:
	j2 = id + 6;
	j3u = ibc + 24;
	j3g = ibc + 27;
	j3e = ibc + 30;
	j3um = ibc + 33;
L70:

/*  READ IN G1,U1,GS,US,UMS,EPS */

/*  CALL UB */

	i__1 = jurec + j2;
	daread_(&u1[301], &msq, &i__1);
/*  CALL GB */
	i__1 = jgrec + j2;
	daread_(&g1[301], &msq, &i__1);
	if (imove == 1) {
/*  CALL GCD */
	    i__1 = jg2rec + j34;
	    daread_(&gs[301], &msq, &i__1);
/*  CALL UCD */
	    i__1 = ju2rec + j34;
	    daread_(&us[301], &msq, &i__1);
/*  CALL USMD */
	    i__1 = ju2mrc + j34;
	    daread_(&usmd[301], &msq, &i__1);
/*  CALL EPCD */
	    i__1 = jeprec + j34;
	    daread_(&eps[301], &msq, &i__1);

	} else {
/*  CALL GCD */
	    i__1 = jg2rec + j3g;
	    daread_(&gs[301], &msq, &i__1);
/*  CALL UCD */
	    i__1 = ju2rec + j3u;
	    daread_(&us[301], &msq, &i__1);
/*  CALL USMD */
	    i__1 = ju2mrc + j3um;
	    daread_(&usmd[301], &msq, &i__1);
/*  CALL EPCD */
	    i__1 = jeprec + j3e;
	    daread_(&eps[301], &msq, &i__1);
	}

/* FIRST KIND */

	yy += trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* SECOND KIND */

	yy += trsub_(&ud3[301], &gs[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy += trsub_(&u1[301], &gs[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &eps[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &eps[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* THIRD KIND */

	yy += trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

	++imove;
	if (imove <= 3) {
	    goto L20;
	}

	gamma[ie - 1] = yy;
/* CALCULATE THE AVERAGE GAMMA VALUE */
	if (ie <= 3) {
	    gav += yy * 3;
	} else if (ie > 9) {
	    gav += yy;
	} else {
	    gav += yy * 2;
	}

/* WRITE GAMMA(ABCD) */

	s_wsfe(&io___396);
	do_fio(&c__1, alab + (ia - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ib - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
	do_fio(&c__1, alab + (id - 1), (ftnlen)1);
	do_fio(&c__1, (char *)&gamma[ie - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();

/* L90: */
    }
    gave = gav / 15.;
    s_wsfe(&io___398);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gave, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* ngefis_ */

#undef iw


/* Subroutine */ int ngidri_(integer *igam, doublereal *x, doublereal *gd3, 
	doublereal *ud3, doublereal *g1, doublereal *u1, doublereal *gs, 
	doublereal *usmd, doublereal *eps, doublereal *us)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";
    static integer ida[15] = { 1,2,3,1,1,2,2,3,3,1,1,2,2,3,3 };
    static integer idb[15] = { 1,2,3,1,1,2,2,3,3,2,3,1,3,1,2 };
    static integer idc[15] = { 1,2,3,2,3,1,3,1,2,2,3,1,3,1,2 };
    static integer idd[15] = { 1,2,3,2,3,1,3,1,2,1,1,2,2,3,3 };
    static integer ip[9]	/* was [3][3] */ = { 1,2,3,2,4,5,3,5,6 };
    static integer ipair[9]	/* was [3][3] */ = { 1,4,7,2,5,8,3,6,9 };

    /* Format strings */
    static char fmt_10[] = "(//,\002 GAMMA (IDRI) AT \002,f10.5,\002 EV.\002"
	    "//)";
    static char fmt_70[] = "(\002 GAMMA(\002,a1,\002,\002,a1,\002,\002,a1"
	    ",\002,\002,a1,\002) = \002,1pd14.7)";
    static char fmt_90[] = "(//,\002  AVERAGE GAMMA VALUE AT \002f10.5,\002 "
	    "= \002,1pd14.7,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j2, ia, ib, ic, id, ie, j34;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal yy;
    static integer icd, ibd, ibc;
    static doublereal gav, one;
    static integer msq;
    static doublereal gave, gamma[15];
    static integer jgarc, jgrec, juarc, jurec, imove;
    extern doublereal trsub_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *);
    static integer jg2rec, ju2rec, ju2mrc;
    extern /* Subroutine */ int daread_(doublereal *, integer *, integer *), 
	    fhpatn_(doublereal *, doublereal *, integer *, integer *, 
	    doublereal *);
    static integer jeprec;

    /* Fortran I/O blocks */
    static cilist io___409 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___432 = { 0, 6, 0, fmt_70, 0 };
    static cilist io___434 = { 0, 6, 0, fmt_90, 0 };


/* ..................................................................... */
/*  CALCULATE GAMMA(IDRI) IN A NONITERATIVE FASHION */
/* ..................................................................... */
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
    /* Parameter adjustments */
    us -= 301;
    eps -= 301;
    usmd -= 301;
    gs -= 301;
    u1 -= 301;
    g1 -= 301;
    ud3 -= 301;
    gd3 -= 301;
    x -= 301;

    /* Function Body */

    one = 1.;
    msq = molkst_1.norbs * molkst_1.norbs;

    s_wsfe(&io___409);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    e_wsfe();

/* GET DATA FROM ALPHA  AND ITERATIVE BETA CALCULATIONS */


/* IGAM=3 (INTENSITY DEPENDENT REFRACTIVE INDEX OR DEGENERATED FOUR */
/* WAVE MIXING) */

    jgarc = 10;
    juarc = 7;
    jurec = 7;
    jgrec = 10;
/* LOOP BEGINS FOR THE CALCULATION OF GAMMA(ABCD) */

    gav = 0.;
    for (ie = 1; ie <= 15; ++ie) {
	ia = ida[ie - 1];
	ib = idb[ie - 1];
	ic = idc[ie - 1];
	id = idd[ie - 1];
	icd = ipair[ic + id * 3 - 4];
	ibd = ipair[ib + id * 3 - 4];
	ibc = ip[ib + ic * 3 - 4];

/*  READ IN THE FIRST ORDER U3 OMEGA AND G3 OMEGA IN THE DIRECTION A */

/* MAKE GD3 OMEGA MATRIX FROM G3 MATRIX */

	i__1 = jgarc + ia;
	daread_(&x[301], &msq, &i__1);
	fhpatn_(&gd3[301], &x[301], &molkst_1.norbs, &c__2, &one);

/* MAKE UD3 OMEGA MATRIX FROM U3 OMEGA MATRIX */

	i__1 = juarc + ia;
	daread_(&x[301], &msq, &i__1);
	d__1 = -one;
	fhpatn_(&ud3[301], &x[301], &molkst_1.norbs, &c__2, &d__1);

	yy = 0.;
	imove = 1;
L20:


/* IDRI */

	switch (imove) {
	    case 1:  goto L30;
	    case 2:  goto L40;
	    case 3:  goto L50;
	}
L30:
	j2 = ib;
	j34 = icd;
	jg2rec = 118;
	ju2rec = 109;
	ju2mrc = 136;
	jeprec = 127;
	goto L60;
L40:
	j2 = ic;
	j34 = ibd;
	jg2rec = 118;
	ju2rec = 109;
	ju2mrc = 136;
	jeprec = 127;
	goto L60;
L50:
	j2 = id;
	j34 = ibc;
	jg2rec = 55;
	ju2rec = 49;
	ju2mrc = 67;
	jeprec = 61;
L60:
/*  READ IN G1,U1,GS,US,UMS,EPS */

/*  CALL UB */
	if (imove == 3) {
	    i__1 = jurec + j2;
	    daread_(&x[301], &msq, &i__1);
	    d__1 = -one;
	    fhpatn_(&u1[301], &x[301], &molkst_1.norbs, &c__2, &d__1);
	} else {
	    i__1 = jurec + j2;
	    daread_(&u1[301], &msq, &i__1);
	}
/*  CALL GB */
	if (imove == 3) {
	    i__1 = jgrec + j2;
	    daread_(&x[301], &msq, &i__1);
	    fhpatn_(&g1[301], &x[301], &molkst_1.norbs, &c__2, &one);
	} else {
	    i__1 = jgrec + j2;
	    daread_(&g1[301], &msq, &i__1);
	}
/*  CALL GCD */
	i__1 = jg2rec + j34;
	daread_(&gs[301], &msq, &i__1);
/*  CALL UCD */
	i__1 = ju2rec + j34;
	daread_(&us[301], &msq, &i__1);
/*  CALL USMD */
	i__1 = ju2mrc + j34;
	daread_(&usmd[301], &msq, &i__1);
/*  CALL EPCD */
	i__1 = jeprec + j34;
	daread_(&eps[301], &msq, &i__1);

/* FIRST KIND */

	yy += trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* SECOND KIND */

	yy += trsub_(&ud3[301], &gs[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy += trsub_(&u1[301], &gs[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &eps[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &eps[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* THIRD KIND */

	yy += trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

	++imove;
	if (imove <= 3) {
	    goto L20;
	}

	gamma[ie - 1] = yy;

/* CALCULATE THE AVERAGE GAMMA VALUE */

	if (ie <= 3) {
	    gav += yy * 3.;
	} else if (ie > 9) {
	    gav += yy;
	} else {
	    gav += yy * 2.;
	}

/* WRITE GAMMA(ABCD) */

	s_wsfe(&io___432);
	do_fio(&c__1, alab + (ia - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ib - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
	do_fio(&c__1, alab + (id - 1), (ftnlen)1);
	do_fio(&c__1, (char *)&gamma[ie - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();

/* L80: */
    }
    gave = gav / 15.;
    s_wsfe(&io___434);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gave, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* ngidri_ */

#undef iw


/* Subroutine */ int ngoke_(integer *igam, doublereal *x, doublereal *gd3, 
	doublereal *ud3, doublereal *g1, doublereal *u1, doublereal *gs, 
	doublereal *usmd, doublereal *eps, doublereal *us)
{
    /* Initialized data */

    static char alab[1*3] = "X" "Y" "Z";
    static integer ida[15] = { 1,2,3,1,1,2,2,3,3,1,1,2,2,3,3 };
    static integer idb[15] = { 1,2,3,1,1,2,2,3,3,2,3,1,3,1,2 };
    static integer idc[15] = { 1,2,3,2,3,1,3,1,2,2,3,1,3,1,2 };
    static integer idd[15] = { 1,2,3,2,3,1,3,1,2,1,1,2,2,3,3 };
    static integer ip[9]	/* was [3][3] */ = { 1,2,3,2,4,5,3,5,6 };
    static integer ipair[9]	/* was [3][3] */ = { 1,4,7,2,5,8,3,6,9 };

    /* Format strings */
    static char fmt_10[] = "(//,\002 GAMMA (IDRI) AT \002,f10.5,\002 EV.\002"
	    "//)";
    static char fmt_20[] = "(//,\002 GAMMA (OKE) AT \002,f10.5,\002 EV.\002/"
	    "/)";
    static char fmt_80[] = "(\002 GAMMA(\002,a1,\002,\002,a1,\002,\002,a1"
	    ",\002,\002,a1,\002) = \002,1pd14.7)";
    static char fmt_100[] = "(//,\002  AVERAGE GAMMA VALUE AT \002f10.5,\002"
	    " = \002,1pd14.7,//)";

    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer j2, ia, ib, ic, id, ie, j34;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal yy;
    static integer icd, ibd, ibc;
    static doublereal gav, one;
    static integer msq;
    static doublereal gave, gamma[15];
    static integer jgarc, jgrec, juarc, jurec, imove;
    extern doublereal trsub_(doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, integer *);
    static integer jg2rec, ju2rec, ju2mrc;
    extern /* Subroutine */ int daread_(doublereal *, integer *, integer *);
    static integer jeprec;
    extern /* Subroutine */ int fhpatn_(doublereal *, doublereal *, integer *,
	     integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___445 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___446 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___469 = { 0, 6, 0, fmt_80, 0 };
    static cilist io___471 = { 0, 6, 0, fmt_100, 0 };


/* ..................................................................... */
/*  CALCULATE GAMMA(OKE) IN A NONITERATIVE FASHION */
/* ..................................................................... */
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
    /* Parameter adjustments */
    us -= 301;
    eps -= 301;
    usmd -= 301;
    gs -= 301;
    u1 -= 301;
    g1 -= 301;
    ud3 -= 301;
    gd3 -= 301;
    x -= 301;

    /* Function Body */

    one = 1.;
    msq = molkst_1.norbs * molkst_1.norbs;

    if (*igam == 3) {
	s_wsfe(&io___445);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	s_wsfe(&io___446);
	do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/* DATA INCLUDING YX, ZY, ZX DIRECTIONS */
/* GET DATA FROM ALPHA  AND ITERATIVE BETA CALCULATIONS */

/*   REQUIRED RECORDS FROM POLARIZABILITY CALCULATIONS */

/*   ------------------------------------------------------- */
/*        0    W    2W    3W */

/*       -02- -08-  -14-  -20-  -U- MATRIX FOR -X- DIRECTION */
/*       -03- -09-  -15-  -21-  -U- MATRIX FOR -Y- DIRECTION */
/*       -04- -10-  -16-  -22-  -U- MATRIX FOR -Z- DIRECTION */
/*       -05- -11-  -17-  -23-  -G- MATRIX FOR -X- DIRECTION */
/*       -06- -12-  -18-  -24-  -G- MATRIX FOR -Y- DIRECTION */
/*       -07- -13-  -19-  -25-  -G- MATRIX FOR -Z- DIRECTION */
/*   ------------------------------------------------------- */
/*      (0,0)    (W,W)    (0,W)    (W,-W) */

/*      -26-     -50-     -74-     -110-   -U- MATRIX FOR -XX- DIRECTION */
/*      -27-     -51-     -75-     -111-   -U- MATRIX FOR -XY- DIRECTION */
/*      -28-     -52-     -76-     -112-   -U- MATRIX FOR -XZ- DIRECTION */
/*                        -77-     -113-   -U- MATRIX DOE -YX- DIRECTION */
/*      -29-     -53-     -78-     -114-   -U- MATRIX FOR -YY- DIRECTION */
/*      -30-     -54-     -79-     -115-   -U- MATRIX FOR -YZ- DIRECTION */
/*                        -80-     -116-   -U- MATRIX FOR -ZX- DIRECTION */
/*                        -81-     -117-   -U- MATRIX FOR -ZY- DIRECTION */
/*      -31-     -55-     -82-     -118-   -U- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/*      -32-     -56-     -83-     -119-   -G- MATRIX FOR -XX- DIRECTION */
/*      -33-     -57-     -84-     -120-   -G- MATRIX FOR -XY- DIRECTION */
/*      -34-     -58-     -85-     -121-   -G- MATRIX FOR -XZ- DIRECTION */
/*                        -86-     -122-   -G- MATRIX FOR -YX- DIRECTION */
/*      -35-     -59-     -87-     -123-   -G- MATRIX FOR -YY- DIRECTION */
/*      -36-     -60-     -88-     -124-   -G- MATRIX FOR -YZ- DIRECTION */
/*                        -89-     -125-   -G- MATRIX FOR -ZX- DIRECTION */
/*                        -90-     -126-   -G- MATRIX FOR -ZY- DIRECTION */
/*      -37-     -61-     -91-     -127-   -G- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/*      -38-     -62-     -92-     -128-   -E- MATRIX FOR -XX- DIRECTION */
/*      -39-     -63-     -93-     -129-   -E- MATRIX FOR -XY- DIRECTION */
/*      -40-     -64-     -94-     -130-   -E- MATRIX FOR -XZ- DIRECTION */
/*                        -95-     -131-   -E- MATRIX FOR -YX- DIRECTION */
/*      -41-     -65-     -96-     -132-   -E- MATRIX FOR -YY- DIRECTION */
/*      -42-     -66-     -97-     -133-   -E- MATRIX FOR -YZ- DIRECTION */
/*                        -98-     -134-   -E- MATRIX FOR -ZX- DIRECTION */
/*                        -99-     -135-   -E- MATRIX FOR -ZY- DIRECTION */
/*      -43-     -67-     -100-    -136-   -E- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/*      -44-     -68-     -101-    -137-   -UM- MATRIX FOR -XX- DIRECTION */
/*      -45-     -69-     -102-    -138-   -UM- MATRIX FOR -XY- DIRECTION */
/*      -46-     -70-     -103-    -139-   -UM- MATRIX FOR -XZ- DIRECTION */
/*                        -104-    -140-   -UM- MATRIX FOR -YX- DIRECTION */
/*      -47-     -71-     -105-    -141-   -UM- MATRIX FOR -YY- DIRECTION */
/*      -48-     -72-     -106-    -142-   -UM- MATRIX FOR -YZ- DIRECTION */
/*                        -107-    -143-   -UM- MATRIX FOR -ZX- DIRECTION */
/*                        -108-    -144-   -UM- MATRIX FOR -ZY- DIRECTION */
/*      -49-     -73-     -109-    -145-   -UM- MATRIX FOR -ZZ- DIRECTION */
/*   ------------------------------------------------------------------ */

/* GET DATA FROM ALPHA  AND ITERATIVE BETA CALCULATIONS */


/* IGAM=4 (OPTICAL KERR EFFECT) */

    jgarc = 10;
    juarc = 7;
    jurec = 1;
    jgrec = 4;
/* LOOP BEGINS FOR THE CALCULATION OF GAMMA(ABCD) */

    gav = 0.;
    for (ie = 1; ie <= 15; ++ie) {
	ia = ida[ie - 1];
	ib = idb[ie - 1];
	ic = idc[ie - 1];
	id = idd[ie - 1];
	icd = ipair[ic + id * 3 - 4];
	ibd = ipair[ib + id * 3 - 4];
	ibc = ip[ib + ic * 3 - 4];

/*  READ IN THE FIRST ORDER U3 OMEGA AND G3 OMEGA IN THE DIRECTION A */

/* MAKE GD3 OMEGA MATRIX FROM G3 MATRIX */

	i__1 = jgarc + ia;
	daread_(&x[301], &msq, &i__1);
	fhpatn_(&gd3[301], &x[301], &molkst_1.norbs, &c__2, &one);

/* MAKE UD3 OMEGA MATRIX FROM U3 OMEGA MATRIX */

	i__1 = juarc + ia;
	daread_(&x[301], &msq, &i__1);
	d__1 = -one;
	fhpatn_(&ud3[301], &x[301], &molkst_1.norbs, &c__2, &d__1);

	yy = 0.;
	imove = 1;
L30:

/* OKE */
	switch (imove) {
	    case 1:  goto L40;
	    case 2:  goto L50;
	    case 3:  goto L60;
	}
L40:
	j2 = ib;
	j34 = icd;
	jg2rec = 82;
	ju2rec = 73;
	ju2mrc = 100;
	jeprec = 91;
	goto L70;
L50:
	j2 = ic;
	j34 = ibd;
	jg2rec = 82;
	ju2rec = 73;
	ju2mrc = 100;
	jeprec = 91;
	goto L70;
L60:
	j2 = id;
	j34 = ibc;
	jg2rec = 31;
	ju2rec = 25;
	ju2mrc = 43;
	jeprec = 37;
L70:
/*  READ IN G1,U1,GS,US,UMS,EPS */

/*  CALL UB */
	if (imove == 3) {
	    i__1 = juarc + j2;
	    daread_(&u1[301], &msq, &i__1);
	} else {
	    i__1 = jurec + j2;
	    daread_(&u1[301], &msq, &i__1);
	}
/*  CALL GB */
	if (imove == 3) {
	    i__1 = jgarc + j2;
	    daread_(&g1[301], &msq, &i__1);
	} else {
	    i__1 = jgrec + j2;
	    daread_(&g1[301], &msq, &i__1);
	}
/*  CALL GCD */
	i__1 = jg2rec + j34;
	daread_(&gs[301], &msq, &i__1);
/*  CALL UCD */
	i__1 = ju2rec + j34;
	daread_(&us[301], &msq, &i__1);
/*  CALL USMD */
	i__1 = ju2mrc + j34;
	daread_(&usmd[301], &msq, &i__1);
/*  CALL EPCD */
	i__1 = jeprec + j34;
	daread_(&eps[301], &msq, &i__1);

/* FIRST KIND */

	yy += trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &g1[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &g1[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* SECOND KIND */

	yy += trsub_(&ud3[301], &gs[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy += trsub_(&u1[301], &gs[301], &ud3[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&ud3[301], &eps[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &eps[301], &ud3[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

/* THIRD KIND */

	yy += trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.nclose, &
		molkst_1.norbs, &molkst_1.norbs);
	yy -= trsub_(&u1[301], &gd3[301], &us[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);
	yy += trsub_(&usmd[301], &gd3[301], &u1[301], &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.norbs);

	++imove;
	if (imove <= 3) {
	    goto L30;
	}

	gamma[ie - 1] = yy;

/* CALCULATE THE AVERAGE GAMMA VALUE */

	if (ie <= 3) {
	    gav += yy * 3.;
	} else if (ie > 9) {
	    gav += yy;
	} else {
	    gav += yy * 2.;
	}

/* WRITE GAMMA(ABCD) */

	s_wsfe(&io___469);
	do_fio(&c__1, alab + (ia - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ib - 1), (ftnlen)1);
	do_fio(&c__1, alab + (ic - 1), (ftnlen)1);
	do_fio(&c__1, alab + (id - 1), (ftnlen)1);
	do_fio(&c__1, (char *)&gamma[ie - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();

/* L90: */
    }
    gave = gav / 15.;
    s_wsfe(&io___471);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&gave, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* ngoke_ */

#undef iw


/* Subroutine */ int nonbet_(doublereal *u1x, doublereal *u1y, doublereal *
	u1z, doublereal *u2x, doublereal *u2y, doublereal *u2z, doublereal *
	g1x, doublereal *g1y, doublereal *g1z, doublereal *g2x, doublereal *
	g2y, doublereal *g2z)
{
    /* Format strings */
    static char fmt_10[] = "(//,\002 BETA (SECOND HARMONIC GENERATION)\002//)"
	    ;
    static char fmt_20[] = "(//,\002  BXXX  \002,d15.8,\002  BYXX \002,d15"
	    ".8,\002  BZXX \002,d15.8,/,\002  BXXY  \002,d15.8,\002  BYXY "
	    "\002,d15.8,\002  BZXY \002,d15.8,/,\002  BXXZ  \002,d15.8,\002  "
	    "BYXZ \002,d15.8,\002  BZXZ \002,d15.8,/,\002  BXYX  \002,d15.8"
	    ",\002  BYYX \002,d15.8,\002  BZYX \002,d15.8,/,\002  BXYY  \002,"
	    "d15.8,\002  BYYY \002,d15.8,\002  BZYY \002,d15.8,/,\002  BXYZ "
	    " \002,d15.8,\002  BYYZ \002,d15.8,\002  BZYZ \002,d15.8,/,\002  "
	    "BXZX  \002,d15.8,\002  BYZX \002,d15.8,\002  BZZX \002,d15.8,/"
	    ",\002  BXZY  \002,d15.8,\002  BYZY \002,d15.8,\002  BZZY \002,d1"
	    "5.8,/,\002  BXZZ  \002,d15.8,\002  BYZZ \002,d15.8,\002  BZZZ"
	    " \002,d15.8)";
    static char fmt_30[] = "(//,\002 AVERAGE BETAX(SHG) VALUE AT\002,f10.5"
	    ",\002EV = \002,1f15.5)";
    static char fmt_40[] = "(\002 AVERAGE BETAY(SHG) VALUE AT\002,f10.5,\002"
	    "EV = \002,1f15.5)";
    static char fmt_50[] = "(\002 AVERAGE BETAZ(SHG) VALUE AT\002,f10.5,\002"
	    "EV = \002,1f15.5,//)";
    static char fmt_60[] = "(//,\002 AVERAGE BETA (SHG) VALUE AT\002,f10.5"
	    ",\002EV = \002,1f15.5,//)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
#define iw ((integer *)&chanel_1 + 5)
    static doublereal bvec, bavx, bavy, bavz, bxxx, byxx, bzxx, bxxy, byxy, 
	    bzxy, bxxz, byxz, bzxz, bxyx, byyx, bzyx, bxyy, byyy, bzyy, bxyz, 
	    byyz, bzyz, bxzx, byzx, bzzx, bxzy, byzy, bzzy, bxzz, byzz, bzzz;
    static integer maxsq;
    extern /* Subroutine */ int daread_(doublereal *, integer *, integer *), 
	    betall_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *), 
	    betcom_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    integer *, integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___505 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___506 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___507 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___508 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___509 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___510 = { 0, 6, 0, fmt_60, 0 };



/* THIS SUBROUTINE CALCULATES SECOND HARMONIC GENERATION IN A */
/* NONITERATIVE WAY. */

/* ..................................................................... */
/*  CALCULATE BETA IN A NONITERATIVE FASHION */
/* ..................................................................... */
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

/* GET DATA FROM ALPHA CALCULATIONS */

    /* Parameter adjustments */
    g2z -= 301;
    g2y -= 301;
    g2x -= 301;
    g1z -= 301;
    g1y -= 301;
    g1x -= 301;
    u2z -= 301;
    u2y -= 301;
    u2x -= 301;
    u1z -= 301;
    u1y -= 301;
    u1x -= 301;

    /* Function Body */
    maxsq = molkst_1.norbs * molkst_1.norbs;
    bavx = 0.;
    bavy = 0.;
    bavz = 0.;
    daread_(&u1x[301], &maxsq, &c__8);
    daread_(&u1y[301], &maxsq, &c__9);
    daread_(&u1z[301], &maxsq, &c__10);
    daread_(&g1x[301], &maxsq, &c__11);
    daread_(&g1y[301], &maxsq, &c__12);
    daread_(&g1z[301], &maxsq, &c__13);
    daread_(&u2x[301], &maxsq, &c__14);
    daread_(&u2y[301], &maxsq, &c__15);
    daread_(&u2z[301], &maxsq, &c__16);
    daread_(&g2x[301], &maxsq, &c__17);
    daread_(&g2y[301], &maxsq, &c__18);
    daread_(&g2z[301], &maxsq, &c__19);
/* XXX */
    betcom_(&u1x[301], &g1x[301], &u2x[301], &g2x[301], &molkst_1.nclose, &
	    molkst_1.norbs, &bxxx);
    bavx += bxxx * 3.;
/* YXX */
    betcom_(&u1x[301], &g1x[301], &u2y[301], &g2y[301], &molkst_1.nclose, &
	    molkst_1.norbs, &byxx);
    bavy += byxx;
/* ZXX */
    betcom_(&u1x[301], &g1x[301], &u2z[301], &g2z[301], &molkst_1.nclose, &
	    molkst_1.norbs, &bzxx);
    bavz += bzxx;
/* XXY */
    betall_(&u2x[301], &g2x[301], &u1x[301], &g1x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxy);
    bavy += bxxy;
/* YXY */
    betall_(&u2y[301], &g2y[301], &u1x[301], &g1x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxy);
    bavx += byxy;
/* ZXY */
    betall_(&u2z[301], &g2z[301], &u1x[301], &g1x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxy);
/* XXZ */
    betall_(&u2x[301], &g2x[301], &u1x[301], &g1x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxz);
    bavz += bxxz;
/* YXZ */
    betall_(&u2y[301], &g2y[301], &u1x[301], &g1x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxz);
/* ZXZ */
    betall_(&u2z[301], &g2z[301], &u1x[301], &g1x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxz);
    bavx += bzxz;
/* XYX */
    betall_(&u2x[301], &g2x[301], &u1y[301], &g1y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyx);
    bavy += bxyx;
/* YYX */
    betall_(&u2y[301], &g2y[301], &u1y[301], &g1y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyx);
    bavx += byyx;
/* ZYX */
    betall_(&u2z[301], &g2z[301], &u1y[301], &g1y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyx);
/* XYY */
    betcom_(&u1y[301], &g1y[301], &u2x[301], &g2x[301], &molkst_1.nclose, &
	    molkst_1.norbs, &bxyy);
    bavx += bxyy;
/* YYY */
    betcom_(&u1y[301], &g1y[301], &u2y[301], &g2y[301], &molkst_1.nclose, &
	    molkst_1.norbs, &byyy);
    bavy += byyy * 3.;
/* ZYY */
    betcom_(&u1y[301], &g1y[301], &u2z[301], &g2z[301], &molkst_1.nclose, &
	    molkst_1.norbs, &bzyy);
    bavz += bzyy;
/* XYZ */
    betall_(&u2x[301], &g2x[301], &u1y[301], &g1y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyz);
/* YYZ */
    betall_(&u2y[301], &g2y[301], &u1y[301], &g1y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyz);
    bavz += byyz;
/* ZYZ */
    betall_(&u2z[301], &g2z[301], &u1y[301], &g1y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyz);
    bavy += bzyz;
/* XZX */
    betall_(&u2x[301], &g2x[301], &u1z[301], &g1z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzx);
    bavz += bxzx;
/* YZX */
    betall_(&u2y[301], &g2y[301], &u1z[301], &g1z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzx);
/* ZZX */
    betall_(&u2z[301], &g2z[301], &u1z[301], &g1z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzx);
    bavx += bzzx;
/* XZY */
    betall_(&u2x[301], &g2x[301], &u1z[301], &g1z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzy);
/* YZY */
    betall_(&u2y[301], &g2y[301], &u1z[301], &g1z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzy);
    bavz += byzy;
/* ZZY */
    betall_(&u2z[301], &g2z[301], &u1z[301], &g1z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzy);
    bavy += bzzy;
/* XZZ */
    betcom_(&u1z[301], &g1z[301], &u2x[301], &g2x[301], &molkst_1.nclose, &
	    molkst_1.norbs, &bxzz);
    bavx += bxzz;
/* YZZ */
    betcom_(&u1z[301], &g1z[301], &u2y[301], &g2y[301], &molkst_1.nclose, &
	    molkst_1.norbs, &byzz);
    bavy += byzz;
/* ZZZ */
    betcom_(&u1z[301], &g1z[301], &u2z[301], &g2z[301], &molkst_1.nclose, &
	    molkst_1.norbs, &bzzz);
    bavz += bzzz * 3.;

    bavx /= 5.;
    bavy /= 5.;
    bavz /= 5.;

    d__1 = bavx * bavx + bavy * bavy + bavz * bavz;
    bvec = pow_dd(&d__1, &c_b176);
    s_wsfe(&io___505);
    e_wsfe();
    s_wsfe(&io___506);
    do_fio(&c__1, (char *)&bxxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___507);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavx, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___508);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavy, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___509);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___510);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bvec, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* nonbet_ */

#undef iw


/* Subroutine */ int nonope_(doublereal *u0x, doublereal *u1y, doublereal *
	u1z, doublereal *u1x, doublereal *u0y, doublereal *u0z, doublereal *
	g0x, doublereal *g1y, doublereal *g1z, doublereal *g1x, doublereal *
	g0y, doublereal *g0z)
{
    /* Format strings */
    static char fmt_10[] = "(//,\002  BXXX  \002,d15.8,\002  BYXX \002,d15"
	    ".8,\002  BZXX \002,d15.8,/,\002  BXXY  \002,d15.8,\002  BYXY "
	    "\002,d15.8,\002  BZXY \002,d15.8,/,\002  BXXZ  \002,d15.8,\002  "
	    "BYXZ \002,d15.8,\002  BZXZ \002,d15.8,/,\002  BXYX  \002,d15.8"
	    ",\002  BYYX \002,d15.8,\002  BZYX \002,d15.8,/,\002  BXYY  \002,"
	    "d15.8,\002  BYYY \002,d15.8,\002  BZYY \002,d15.8,/,\002  BXYZ "
	    " \002,d15.8,\002  BYYZ \002,d15.8,\002  BZYZ \002,d15.8,/,\002  "
	    "BXZX  \002,d15.8,\002  BYZX \002,d15.8,\002  BZZX \002,d15.8,/"
	    ",\002  BXZY  \002,d15.8,\002  BYZY \002,d15.8,\002  BZZY \002,d1"
	    "5.8,/,\002  BXZZ  \002,d15.8,\002  BYZZ \002,d15.8,\002  BZZZ"
	    " \002,d15.8)";
    static char fmt_20[] = "(//,\002 AVERAGE BETAX VALUE AT\002,f10.5,\002EV"
	    " = \002,1f15.5)";
    static char fmt_30[] = "(\002 AVERAGE BETAY VALUE AT\002,f10.5,\002EV ="
	    " \002,1f15.5)";
    static char fmt_40[] = "(\002 AVERAGE BETAZ VALUE AT\002,f10.5,\002EV ="
	    " \002,1f15.5,//)";
    static char fmt_50[] = "(//,\002 AVERAGE BETA(EOPE) VALUE AT\002,f10.5"
	    ",\002EV = \002,1f15.5,//)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_wsfe(void);

    /* Local variables */
#define iw ((integer *)&chanel_1 + 5)
    static doublereal bvec, bavx, bavy, bavz, bxxx, byxx, bzxx, bxxy, byxy, 
	    bzxy, bxxz, byxz, bzxz, bxyx, byyx, bzyx, bxyy, byyy, bzyy, bxyz, 
	    byyz, bzyz, bxzx, byzx, bzzx, bxzy, byzy, bzzy, bxzz, byzz, bzzz;
    static integer maxsq;
    extern /* Subroutine */ int daread_(doublereal *, integer *, integer *), 
	    betall_(doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___544 = { 0, 6, 0, 0, 0 };
    static cilist io___545 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___546 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___547 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___548 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___549 = { 0, 6, 0, fmt_50, 0 };



/* THIS SUBROUTINE CALCULATES ELECTROOPTIC POCKEL'S EFFECT */
/* IN A NONITERATIVE WAY. */

/* ..................................................................... */
/*  CALCULATE BETA IN A NONITERATIVE FASHION */
/* ..................................................................... */
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

    /* Parameter adjustments */
    g0z -= 301;
    g0y -= 301;
    g1x -= 301;
    g1z -= 301;
    g1y -= 301;
    g0x -= 301;
    u0z -= 301;
    u0y -= 301;
    u1x -= 301;
    u1z -= 301;
    u1y -= 301;
    u0x -= 301;

    /* Function Body */
    maxsq = molkst_1.norbs * molkst_1.norbs;

/* READ DATA FROM ALPHA CALCULATION */

    bavx = 0.;
    bavy = 0.;
    bavz = 0.;

    daread_(&u0x[301], &maxsq, &c__2);
    daread_(&u0y[301], &maxsq, &c__3);
    daread_(&u0z[301], &maxsq, &c__4);
    daread_(&g0x[301], &maxsq, &c__5);
    daread_(&g0y[301], &maxsq, &c__6);
    daread_(&g0z[301], &maxsq, &c__7);
    daread_(&u1x[301], &maxsq, &c__8);
    daread_(&u1y[301], &maxsq, &c__9);
    daread_(&u1z[301], &maxsq, &c__10);
    daread_(&g1x[301], &maxsq, &c__11);
    daread_(&g1y[301], &maxsq, &c__12);
    daread_(&g1z[301], &maxsq, &c__13);
/* XXX */
    betall_(&u1x[301], &g1x[301], &u0x[301], &g0x[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxx);
    bavx += bxxx * 3.;
/* YXX */
    betall_(&u1y[301], &g1y[301], &u0x[301], &g0x[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxx);
    bavy += byxx;
/* ZXX */
    betall_(&u1z[301], &g1z[301], &u0x[301], &g0x[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxx);
    bavz += bzxx;
/* XXY */
    betall_(&u1x[301], &g1x[301], &u0x[301], &g0x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxy);
    bavy += bxxy;
/* YXY */
    betall_(&u1y[301], &g1y[301], &u0x[301], &g0x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxy);
    bavx += byxy;
/* ZXY */
    betall_(&u1z[301], &g1z[301], &u0x[301], &g0x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxy);
/* XXZ */
    betall_(&u1x[301], &g1x[301], &u0x[301], &g0x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxz);
    bavz += bxxz;
/* YXZ */
    betall_(&u1y[301], &g1y[301], &u0x[301], &g0x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxz);
/* ZXZ */
    betall_(&u1z[301], &g1z[301], &u0x[301], &g0x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxz);
    bavx += bzxz;
/* XYX */
    betall_(&u1x[301], &g1x[301], &u0y[301], &g0y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyx);
    bavy += bxyx;
/* YYX */
    betall_(&u1y[301], &g1y[301], &u0y[301], &g0y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyx);
    bavx += byyx;
/* ZYX */
    betall_(&u1z[301], &g1z[301], &u0y[301], &g0y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyx);
/* XYY */
    betall_(&u1x[301], &g1x[301], &u0y[301], &g0y[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyy);
    bavx += bxyy;
/* YYY */
    betall_(&u1y[301], &g1y[301], &u0y[301], &g0y[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyy);
    bavy += byyy * 3.;
/* ZYY */
    betall_(&u1z[301], &g1z[301], &u0y[301], &g0y[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyy);
    bavz += bzyy;
/* XYZ */
    betall_(&u1x[301], &g1x[301], &u0y[301], &g0y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyz);
/* YYZ */
    betall_(&u1y[301], &g1y[301], &u0y[301], &g0y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyz);
    bavz += byyz;
/* ZYZ */
    betall_(&u1z[301], &g1z[301], &u0y[301], &g0y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyz);
    bavy += bzyz;
/* XZX */
    betall_(&u1x[301], &g1x[301], &u0z[301], &g0z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzx);
    bavz += bxzx;
/* YZX */
    betall_(&u1y[301], &g1y[301], &u0z[301], &g0z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzx);
/* ZZX */
    betall_(&u1z[301], &g1z[301], &u0z[301], &g0z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzx);
    bavx += bzzx;
/* XZY */
    betall_(&u1x[301], &g1x[301], &u0z[301], &g0z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzy);
/* YZY */
    betall_(&u1y[301], &g1y[301], &u0z[301], &g0z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzy);
    bavz += byzy;
/* ZZY */
    betall_(&u1z[301], &g1z[301], &u0z[301], &g0z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzy);
    bavy += bzzy;
/* XZZ */
    betall_(&u1x[301], &g1x[301], &u0z[301], &g0z[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzz);
    bavx += bxzz;
/* YZZ */
    betall_(&u1y[301], &g1y[301], &u0z[301], &g0z[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzz);
    bavy += byzz;
/* ZZZ */
    betall_(&u1z[301], &g1z[301], &u0z[301], &g0z[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzz);
    bavz += bzzz * 3.;

    bavx /= 5.;
    bavy /= 5.;
    bavz /= 5.;

    d__1 = bavx * bavx + bavy * bavy + bavz * bavz;
    bvec = pow_dd(&d__1, &c_b176);
    s_wsle(&io___544);
    do_lio(&c__9, &c__1, "  BETA (ELECTOPTIC POCKELS EFFECT) ", (ftnlen)35);
    e_wsle();
    s_wsfe(&io___545);
    do_fio(&c__1, (char *)&bxxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___546);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavx, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___547);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavy, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___548);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___549);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bvec, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* nonope_ */

#undef iw


/* Subroutine */ int nonor_(doublereal *u0x, doublereal *u1y, doublereal *u1z,
	 doublereal *u1x, doublereal *u0y, doublereal *u0z, doublereal *g0x, 
	doublereal *g1y, doublereal *g1z, doublereal *g1x, doublereal *g0y, 
	doublereal *g0z)
{
    /* Format strings */
    static char fmt_10[] = "(//,\002 BETA (OPTICAL RECTIFICATION) \002)";
    static char fmt_20[] = "(//,\002  BXXX  \002,d15.8,\002  BYXX \002,d15"
	    ".8,\002  BZXX \002,d15.8,/,\002  BXXY  \002,d15.8,\002  BYXY "
	    "\002,d15.8,\002  BZXY \002,d15.8,/,\002  BXXZ  \002,d15.8,\002  "
	    "BYXZ \002,d15.8,\002  BZXZ \002,d15.8,/,\002  BXYX  \002,d15.8"
	    ",\002  BYYX \002,d15.8,\002  BZYX \002,d15.8,/,\002  BXYY  \002,"
	    "d15.8,\002  BYYY \002,d15.8,\002  BZYY \002,d15.8,/,\002  BXYZ "
	    " \002,d15.8,\002  BYYZ \002,d15.8,\002  BZYZ \002,d15.8,/,\002  "
	    "BXZX  \002,d15.8,\002  BYZX \002,d15.8,\002  BZZX \002,d15.8,/"
	    ",\002  BXZY  \002,d15.8,\002  BYZY \002,d15.8,\002  BZZY \002,d1"
	    "5.8,/,\002  BXZZ  \002,d15.8,\002  BYZZ \002,d15.8,\002  BZZZ"
	    " \002,d15.8)";
    static char fmt_30[] = "(//,\002 AVERAGE BETAX VALUE AT \002,f10.5,\002E"
	    "V = \002,1f15.5)";
    static char fmt_40[] = "(\002 AVERAGE BETAY VALUE AT \002,f10.5,\002EV"
	    " = \002,1f15.5)";
    static char fmt_50[] = "(\002 AVERAGE BETAZ VALUE AT \002,f10.5,\002EV"
	    " = \002,1f15.5,//)";
    static char fmt_60[] = "(//,\002 AVERAGE BETA(OR) VALUE AT \002,f10.5"
	    ",\002EV = \002,1f15.5,//)";

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
#define iw ((integer *)&chanel_1 + 5)
    static doublereal bvec, bavx, bavy, bavz, bxxx, byxx, bzxx, bxxy, byxy, 
	    bzxy, bxxz, byxz, bzxz, bxyx, byyx, bzyx, bxyy, byyy, bzyy, bxyz, 
	    byyz, bzyz, bxzx, byzx, bzzx, bxzy, byzy, bzzy, bxzz, byzz, bzzz;
    static integer maxsq;
    extern /* Subroutine */ int betal1_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     integer *, doublereal *), daread_(doublereal *, integer *, 
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___583 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___584 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___585 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___586 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___587 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___588 = { 0, 6, 0, fmt_60, 0 };



/* THIS SUBROUTINE CALCULATES OPTICAL RECTIFICATION IN A */
/* NONITERATIVE WAY */

/* ..................................................................... */
/*  CALCULATE BETA IN A NONITERATIVE FASHION */
/* ..................................................................... */
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
    /* Parameter adjustments */
    g0z -= 301;
    g0y -= 301;
    g1x -= 301;
    g1z -= 301;
    g1y -= 301;
    g0x -= 301;
    u0z -= 301;
    u0y -= 301;
    u1x -= 301;
    u1z -= 301;
    u1y -= 301;
    u0x -= 301;

    /* Function Body */
    maxsq = molkst_1.norbs * molkst_1.norbs;

/* READ DATA FROM ALPHA CALCULATION */

    bavx = 0.;
    bavy = 0.;
    bavz = 0.;

    daread_(&u0x[301], &maxsq, &c__2);
    daread_(&u0y[301], &maxsq, &c__3);
    daread_(&u0z[301], &maxsq, &c__4);
    daread_(&g0x[301], &maxsq, &c__5);
    daread_(&g0y[301], &maxsq, &c__6);
    daread_(&g0z[301], &maxsq, &c__7);
    daread_(&u1x[301], &maxsq, &c__8);
    daread_(&u1y[301], &maxsq, &c__9);
    daread_(&u1z[301], &maxsq, &c__10);
    daread_(&g1x[301], &maxsq, &c__11);
    daread_(&g1y[301], &maxsq, &c__12);
    daread_(&g1z[301], &maxsq, &c__13);

/* NONITERATIVE BETA CALCULATION */

/* XXX */
    betal1_(&u0x[301], &g0x[301], &u1x[301], &g1x[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxx);
    bavx += bxxx * 3.;
/* YXX */
    betal1_(&u0y[301], &g0y[301], &u1x[301], &g1x[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxx);
    bavy += byxx;
/* ZXX */
    betal1_(&u0z[301], &g0z[301], &u1x[301], &g1x[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxx);
    bavz += bzxx;
/* XXY */
    betal1_(&u0x[301], &g0x[301], &u1x[301], &g1x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxy);
    bavy += bxxy;
/* YXY */
    betal1_(&u0y[301], &g0y[301], &u1x[301], &g1x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxy);
    bavx += byxy;
/* ZXY */
    betal1_(&u0z[301], &g0z[301], &u1x[301], &g1x[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxy);
/* XXZ */
    betal1_(&u0x[301], &g0x[301], &u1x[301], &g1x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxxz);
    bavz += bxxz;
/* YXZ */
    betal1_(&u0y[301], &g0y[301], &u1x[301], &g1x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byxz);
/* ZXZ */
    betal1_(&u0z[301], &g0z[301], &u1x[301], &g1x[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzxz);
    bavx += bzxz;
/* XYX */
    betal1_(&u0x[301], &g0x[301], &u1y[301], &g1y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyx);
    bavy += bxyx;
/* YYX */
    betal1_(&u0y[301], &g0y[301], &u1y[301], &g1y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyx);
    bavx += byyx;
/* ZYX */
    betal1_(&u0z[301], &g0z[301], &u1y[301], &g1y[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyx);
/* XYY */
    betal1_(&u0x[301], &g0x[301], &u1y[301], &g1y[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyy);
    bavx += bxyy;
/* YYY */
    betal1_(&u0y[301], &g0y[301], &u1y[301], &g1y[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyy);
    bavy += byyy * 3.;
/* ZYY */
    betal1_(&u0z[301], &g0z[301], &u1y[301], &g1y[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyy);
    bavz += bzyy;
/* XYZ */
    betal1_(&u0x[301], &g0x[301], &u1y[301], &g1y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxyz);
/* YYZ */
    betal1_(&u0y[301], &g0y[301], &u1y[301], &g1y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byyz);
    bavz += byyz;
/* ZYZ */
    betal1_(&u0z[301], &g0z[301], &u1y[301], &g1y[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzyz);
    bavy += bzyz;
/* XZX */
    betal1_(&u0x[301], &g0x[301], &u1z[301], &g1z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzx);
    bavz += bxzx;
/* YZX */
    betal1_(&u0y[301], &g0y[301], &u1z[301], &g1z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzx);
/* ZZX */
    betal1_(&u0z[301], &g0z[301], &u1z[301], &g1z[301], &u1x[301], &g1x[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzx);
    bavx += bzzx;
/* XZY */
    betal1_(&u0x[301], &g0x[301], &u1z[301], &g1z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzy);
/* YZY */
    betal1_(&u0y[301], &g0y[301], &u1z[301], &g1z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzy);
    bavz += byzy;
/* ZZY */
    betal1_(&u0z[301], &g0z[301], &u1z[301], &g1z[301], &u1y[301], &g1y[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzy);
    bavy += bzzy;
/* XZZ */
    betal1_(&u0x[301], &g0x[301], &u1z[301], &g1z[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bxzz);
    bavx += bxzz;
/* YZZ */
    betal1_(&u0y[301], &g0y[301], &u1z[301], &g1z[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &byzz);
    bavy += byzz;
/* ZZZ */
    betal1_(&u0z[301], &g0z[301], &u1z[301], &g1z[301], &u1z[301], &g1z[301], 
	    &molkst_1.nclose, &molkst_1.norbs, &bzzz);
    bavz += bzzz * 3.;

    bavx /= 5.;
    bavy /= 5.;
    bavz /= 5.;

    d__1 = bavx * bavx + bavy * bavy + bavz * bavz;
    bvec = pow_dd(&d__1, &c_b176);
    s_wsfe(&io___583);
    e_wsfe();
    s_wsfe(&io___584);
    do_fio(&c__1, (char *)&bxxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzxz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzyz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzy, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bxzz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&byzz, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bzzz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___585);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavx, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___586);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavy, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___587);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bavz, (ftnlen)sizeof(doublereal));
    e_wsfe();

    s_wsfe(&io___588);
    do_fio(&c__1, (char *)&omval_1.omega, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&bvec, (ftnlen)sizeof(doublereal));
    e_wsfe();

    return 0;
} /* nonor_ */

#undef iw


/* Subroutine */ int openda_(integer *irest)
{
    /* System generated locals */
    olist o__1;

    /* Builtin functions */
    integer f_open(olist *), s_wdue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wdue(void), s_rdue(cilist *), e_rdue(void);

    /* Local variables */
    static integer i__, is;
#define iw ((integer *)&chanel_1 + 5)
    static integer ipk;

    /* Fortran I/O blocks */
    static cilist io___591 = { 0, 0, 0, 0, 1 };
    static cilist io___594 = { 0, 0, 0, 0, 1 };



/*     - - - - OPEN MASTER DICTIONARY FILE 10 - - - - */




    iodaf_1.idaf = 17;
/* VAX  IRECLN = 512 */
    iodaf_1.irecln = 1023;

/*             GET OPEN PARAMETERS FROM INPUT (OPTIONAL) */

/*           OBTAIN DICTNRY FILE NAME FROM RUN COMMAND LINE */

/* VAX      OPEN (UNIT=IDAF, FILE='DICTNRY', STATUS='UNKNOWN', */
/* VAX     *      ACCESS='DIRECT', FORM='UNFORMATTED', RECL=2*IRECLN) */

/* ---------- modified by I. Cserny,  June 21, 1995 ------------- */
/* -    I=INDEX(JOBNAM,' ')-1 */
/* -    OPEN(UNIT=IDAF, FILE=JOBNAM(:I)//'.POL', STATUS='UNKNOWN', */
/* -   1      ACCESS='DIRECT', FORM='UNFORMATTED', RECL=8*IRECLN) */
    o__1.oerr = 0;
    o__1.ounit = iodaf_1.idaf;
    o__1.ofnmlen = 7;
    o__1.ofnm = "DICTNRY";
    o__1.orl = iodaf_1.irecln << 3;
    o__1.osta = "UNKNOWN";
    o__1.oacc = "DIRECT";
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
/* -------------------------------------------------------------- */

/*     ----- IS THIS A NEW OR OLD DAF FILE ----- */

    if (*irest != 0) {
	goto L20;
    }

/*        ----- MARK THE NEW DAF RECORDS AS EMPTY ----- */

    iodaf_1.irecst = 1;
    for (i__ = 1; i__ <= 145; ++i__) {
	iodaf_1.ioda[i__ - 1] = -1;
/* L10: */
    }
    ++iodaf_1.irecst;
    io___591.ciunit = iodaf_1.idaf;
    s_wdue(&io___591);
    do_uio(&c__1, (char *)&iodaf_1.irecst, (ftnlen)sizeof(integer));
    do_uio(&c__145, (char *)&iodaf_1.ioda[0], (ftnlen)sizeof(integer));
    do_uio(&c__145, (char *)&iodaf_1.ifilen[0], (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&is, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&ipk, (ftnlen)sizeof(integer));
    e_wdue();
    return 0;

/*     ----- LOAD THE OLD DAF DIRECTORY ----- */

L20:
    io___594.ciunit = iodaf_1.idaf;
    s_rdue(&io___594);
    do_uio(&c__1, (char *)&iodaf_1.irecst, (ftnlen)sizeof(integer));
    do_uio(&c__145, (char *)&iodaf_1.ioda[0], (ftnlen)sizeof(integer));
    do_uio(&c__145, (char *)&iodaf_1.ifilen[0], (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&is, (ftnlen)sizeof(integer));
    do_uio(&c__1, (char *)&ipk, (ftnlen)sizeof(integer));
    e_rdue();
    return 0;
} /* openda_ */

#undef iw


