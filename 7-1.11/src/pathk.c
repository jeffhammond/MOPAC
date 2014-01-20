/* pathk.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    doublereal cosine;
} gravec_;

#define gravec_1 gravec_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    doublereal currt;
} pparam_;

#define pparam_1 pparam_

struct {
    integer kloop;
} kloop_;

#define kloop_1 kloop_

struct {
    doublereal profil[200];
} profic_;

#define profic_1 profic_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__12 = 12;

/* Subroutine */ int pathk_(void)
{
    /* Format strings */
    static char fmt_30[] = "(\002 ARCHIVE FILE FOR PATH CALCULATION\002/\002"
	    "A PROFIL OF COORDINATES - HEATS\002/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;
    char ch__1[80];
    olist o__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void), f_open(olist *);

    /* Local variables */
    static integer i__, k, l, m;
    static doublereal c1, gd[360], cpu1, cpu2, cpu3, escf;
    static integer mdfp[20];
    static doublereal xdfp[20], step;
    static integer npts;
    extern doublereal reada_(char *, integer *, ftnlen);
    extern /* Subroutine */ int flepo_(doublereal *, integer *, doublereal *);
    static integer iloop;
    extern /* Subroutine */ int geout_(integer *);
    static doublereal xlast[360], degree;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    extern doublereal second_(void);
    extern /* Subroutine */ int dfpsav_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static doublereal cputot;
    extern /* Subroutine */ int wrttxt_(integer *);

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 6, 0, "(//10X,' RESTARTING AT POINT ',I3)", 
	    0 };
    static cilist io___16 = { 0, 6, 0, "(/'          VARIABLE        FUNCTIO"
	    "N')", 0 };
    static cilist io___17 = { 0, 6, 0, "(' :',F16.5,F16.6)", 0 };
    static cilist io___19 = { 0, 6, 0, "(/16X,'POINTS ON REACTION PATH ',   "
	    "                             /16X,'AND CORRESPONDING HEATS',//)", 
	    0 };
    static cilist io___20 = { 0, 12, 0, fmt_30, 0 };
    static cilist io___21 = { 0, 12, 0, "(/' TOTAL CPU TIME IN FLEPO : ',F10"
	    ".3/)", 0 };
    static cilist io___25 = { 0, 6, 0, "(8F7.2)", 0 };
    static cilist io___26 = { 0, 6, 0, "(8F7.2,/)", 0 };
    static cilist io___27 = { 0, 12, 0, "(8F7.2)", 0 };
    static cilist io___28 = { 0, 12, 0, "(8F7.2,/)", 0 };
    static cilist io___29 = { 0, 6, 0, "(8F7.2)", 0 };
    static cilist io___30 = { 0, 6, 0, "(8F7.2,/)", 0 };
    static cilist io___31 = { 0, 12, 0, "(8F7.2)", 0 };
    static cilist io___32 = { 0, 12, 0, "(8F7.2,/)", 0 };


/* *********************************************************************** */

/*  		Written by Manyin Yi, Aug 1989. */
/*       Restartable reaction_path calulation. */
/* 	The number of path_step and step value are read in through */
/*       keyword POINT and STEP. */
/* 	The reaction profile is archived. */

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
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /PROFIL/ PROFIL */
/* ***************************** at 1994-05-25 ***** */
    i__1 = i_indx(keywrd_1.keywrd, "STEP", (ftnlen)241, (ftnlen)4) + 5;
    step = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    i__1 = i_indx(keywrd_1.keywrd, "POINT", (ftnlen)241, (ftnlen)5) + 6;
    npts = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);

/*  THE SMALLEST VALUE IN THE PATH IS */
/*      REACT(1) DEGREE OR GEO(LPARAM,LATOM) RADIANS */

    degree = 57.29577951307855;
    if (path_1.lparam != 1) {
	step /= degree;
    }

/*  NOW TO SWEEP THROUGH THE PATH */

    if (path_1.lparam != 1) {
	c1 = degree;
    } else {
	c1 = 1.;
    }

    kloop_1.kloop = 1;
    cputot = 0.;
    pparam_1.currt = geom_1.geo[path_1.lparam + path_1.latom * 3 - 4];
    profic_1.profil[0] = 0.;
    if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0) {
	mdfp[8] = 0;
	dfpsav_(&cputot, geovar_1.xparam, gd, xlast, &escf, mdfp, xdfp);
	s_wsfe(&io___11);
	do_fio(&c__1, (char *)&kloop_1.kloop, (ftnlen)sizeof(integer));
	e_wsfe();
    }

    geom_1.geo[path_1.lparam + path_1.latom * 3 - 4] = pparam_1.currt;
    i__1 = npts;
    for (iloop = kloop_1.kloop; iloop <= i__1; ++iloop) {
	cpu1 = second_();
	pparam_1.currt = geom_1.geo[path_1.lparam + path_1.latom * 3 - 4];
	flepo_(geovar_1.xparam, &geovar_1.nvar, &escf);
	++kloop_1.kloop;
	cpu2 = second_();
	cpu3 = cpu2 - cpu1;
	cputot += cpu3;
	profic_1.profil[iloop - 1] = escf;
	s_wsfe(&io___16);
	e_wsfe();
	s_wsfe(&io___17);
	d__1 = geom_1.geo[path_1.lparam + path_1.latom * 3 - 4] * c1;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	e_wsfe();
	geout_(&c__6);
	geom_1.geo[path_1.lparam + path_1.latom * 3 - 4] += step;
/* L10: */
    }
    i__1 = npts;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L20: */
	path_1.react[i__ - 1] = path_1.react[i__ - 2] + step * c1;
    }
    s_wsfe(&io___19);
    e_wsfe();
    o__1.oerr = 0;
    o__1.ounit = 12;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR012", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    s_wsfe(&io___20);
    e_wsfe();
    wrttxt_(&c__12);
    s_wsfe(&io___21);
    do_fio(&c__1, (char *)&cputot, (ftnlen)sizeof(doublereal));
    e_wsfe();

    l = npts / 8;
    m = npts - (l << 3);
    if (l < 1) {
	goto L50;
    }
    i__1 = l - 1;
    for (k = 0; k <= i__1; ++k) {
	s_wsfe(&io___25);
	i__2 = (k << 3) + 8;
	for (i__ = (k << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&path_1.react[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___26);
	i__2 = (k << 3) + 8;
	for (i__ = (k << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&profic_1.profil[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___27);
	i__2 = (k << 3) + 8;
	for (i__ = (k << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&path_1.react[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
/* L40: */
	s_wsfe(&io___28);
	i__2 = (k << 3) + 8;
	for (i__ = (k << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&profic_1.profil[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }
L50:
    if (m > 0) {
	s_wsfe(&io___29);
	i__2 = (l << 3) + m;
	for (i__ = (l << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&path_1.react[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___30);
	i__2 = (l << 3) + m;
	for (i__ = (l << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&profic_1.profil[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___31);
	i__2 = (l << 3) + m;
	for (i__ = (l << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&path_1.react[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___32);
	i__2 = (l << 3) + m;
	for (i__ = (l << 3) + 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&profic_1.profil[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }
    return 0;
} /* pathk_ */

