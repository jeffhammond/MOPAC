/* mopac7app.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    logical isok;
} okmany_;

#define okmany_1 okmany_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    integer iflepo, iscf;
} mesage_;

#define mesage_1 mesage_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    doublereal eisol[107], eheat[107];
} atomic_;

#define atomic_1 atomic_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    logical iseps, useps, upda;
} iseps_;

#define iseps_1 iseps_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__0 = 0;
static logical c_true = TRUE_;

/* Main program */ int MAIN__(void)
{
    /* System generated locals */
    integer i__1;
    logical L__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    extern /* Subroutine */ int ef_(doublereal *, integer *, doublereal *);
    static integer ii, ni;
    extern /* Subroutine */ int drc_(doublereal *, doublereal *);
    static doublereal eat;
    extern /* Subroutine */ int esp_(void);
    static doublereal tim, escf;
    extern /* Subroutine */ int grid_(void), datin_(void), force_(void), 
	    flepo_(doublereal *, integer *, doublereal *), pathk_(void), 
	    polar_(void), paths_(void), geout_(integer *), nllsq_(doublereal *
	    , integer *), powsq_(doublereal *, integer *, doublereal *), 
	    react1_(doublereal *), getdat_(void);
    extern doublereal second_(void);
    extern /* Subroutine */ int readmo_(void), geoutg_(integer *), moldat_(
	    integer *);
    static integer indeps;
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), writmo_(doublereal *, 
	    doublereal *), wrttxt_(integer *);

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, "(10X,' MOPAC - A GENERAL MOLECULAR OR"
	    "BITAL PACKAGE',/         ,10X,'   ORIGINAL VERSION WRITTEN IN 19"
	    "83')", 0 };
    static cilist io___2 = { 0, 6, 0, "(10X,'     BY JAMES J. P. STEWART AT "
	    "THE',/                  ,10X,'     UNIVERSITY OF TEXAS AT AUSTIN"
	    "',/                     ,10X,'          AUSTIN, TEXAS, 78712')", 
	    0 };
    static cilist io___3 = { 0, 6, 0, "(10X,'  MODIFIED TO DO ESP CALCULATIO"
	    "NS BY'                   ,10X,'    BRENT H. BESLER AND K. M. MER"
	    "Z JR. 1989')", 0 };
    static cilist io___4 = { 0, 6, 0, "(A)", 0 };
    static cilist io___5 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___10 = { 0, 6, 0, "(//,10X,A)", 0 };
    static cilist io___11 = { 0, 6, 0, "(   10X,A)", 0 };
    static cilist io___15 = { 0, 6, 0, "(A)", 0 };
    static cilist io___16 = { 0, 6, 0, "(A)", 0 };
    static cilist io___17 = { 0, 6, 0, "(A)", 0 };
    static cilist io___19 = { 0, 6, 0, "(///,' TOTAL CPU TIME: ',F16.2,' SEC"
	    "ONDS')", 0 };
    static cilist io___20 = { 0, 6, 0, "(/,' == MOPAC DONE ==')", 0 };



/*         Notice of Public Domain nature of MOPAC */

/*      'This computer program is a work of the United States */
/*       Government and as such is not subject to protection by */
/*       copyright (17 U.S.C. # 105.)  Any person who fraudulently */
/*       places a copyright notice or does any other act contrary */
/*       to the provisions of 17 U.S. Code 506(c) shall be subject */
/*       to the penalties provided therein.  This notice shall not */
/*       be altered or removed from this software and is to be on */
/*       all reproductions.' */


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
/*     COMMON /TIME  / TIME0 */
/* ***************************** at 1994-05-25 ***** */
/* COSMO change */
/* end of COSMO change */
    getdat_();

/*   CLOSE UNIT 6 IN CASE IT WAS ALREADY PRE-ASSIGNED */

/* *** don't open unit 6; the output is done to STDOUT instead of file... */
/*          CLOSE (6) */
/*          OPEN(UNIT=6,FILE=GETNAM('FOR006'),STATUS='NEW') */
/*          REWIND 6 */
/* #      CALL TIMER('FIRST LINE') */
    numcal_1.numcal = 0;
    okmany_1.isok = TRUE_;
L10:
    ++numcal_1.numcal;

    timec_1.time0 = second_();

/* READ AND CHECK INPUT FILE, EXIT IF NECESSARY. */
/*     WRITE INPUT FILE TO UNIT 6 AS FEEDBACK TO USER */

/* L20: */
    readmo_();
    scftyp_1.emin = 0.;
/* #      CALL TIMER('AFTER READ') */
    if (geokst_1.natoms == 0) {
	goto L50;
    }
    if (i_indx(keywrd_1.keywrd, "AUTHOR", (ftnlen)241, (ftnlen)6) != 0) {
	s_wsfe(&io___1);
	e_wsfe();
	s_wsfe(&io___2);
	e_wsfe();
	s_wsfe(&io___3);
	e_wsfe();
    }

/* INITIALIZE CALCULATION AND WRITE CALCULATION INDEPENDENT INFO */

    if (i_indx(keywrd_1.keywrd, "0SCF", (ftnlen)241, (ftnlen)4) != 0) {
	s_wsfe(&io___4);
	do_fio(&c__1, " GEOMETRY IN MOPAC Z-MATRIX FORMAT", (ftnlen)34);
	e_wsfe();
	geout_(&c__6);
	if (i_indx(keywrd_1.keywrd, " AIGOUT", (ftnlen)241, (ftnlen)7) != 0) {
	    s_wsfe(&io___5);
	    do_fio(&c__1, "  GEOMETRY IN GAUSSIAN Z-MATRIX FORMAT", (ftnlen)
		    38);
	    e_wsfe();
	    wrttxt_(&c__6);
	    geoutg_(&c__6);
	}
	goto L50;
    }
    moldat_(&c__0);
/* COSMO change */
/*  INITIALIZE SOLVATION */
    iseps_1.iseps = FALSE_;
    iseps_1.useps = FALSE_;
    iseps_1.upda = FALSE_;
    indeps = i_indx(keywrd_1.keywrd, "EPS=", (ftnlen)241, (ftnlen)4);
    if (indeps != 0) {
	iseps_1.iseps = TRUE_;
	iseps_1.useps = TRUE_;
	iseps_1.upda = TRUE_;
/*       CALL INITSV (INDEPS) */
    }
/* A.KLAMT 18.7.91 */
/* end of COSMO change */
    if (i_indx(keywrd_1.keywrd, "EXTERNAL", (ftnlen)241, (ftnlen)8) != 0) {
	datin_();

/*  RECALCULATE THE ATOMIC ENERGY */

	atheat_1.atheat = 0.;
	eat = 0.;
	i__1 = molkst_1.numat;
	for (ii = 1; ii <= i__1; ++ii) {
	    ni = molkst_1.nat[ii - 1];
	    atheat_1.atheat += atomic_1.eheat[ni - 1];
/* L30: */
	    eat += atomic_1.eisol[ni - 1];
	}
	atheat_1.atheat -= eat * 23.061;
    }
    if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) == 0) {
	if (i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0) {
	    if (path_1.latom != 0) {
		s_wsfe(&io___10);
		do_fio(&c__1, "1SCF SPECIFIED WITH PATH.  THIS PAIR OF", (
			ftnlen)39);
		e_wsfe();
		s_wsfe(&io___11);
		do_fio(&c__1, "OPTIONS IS NOT ALLOWED", (ftnlen)22);
		e_wsfe();
		goto L50;
	    }
	    mesage_1.iflepo = 1;
	    mesage_1.iscf = 1;
	    last_1.last = 1;
	    i__ = i_indx(keywrd_1.keywrd, "GRAD", (ftnlen)241, (ftnlen)4);
	    i__1 = geovar_1.nvar;
	    for (j = 1; j <= i__1; ++j) {
/* L39: */
		gradnt_1.grad[j - 1] = 0.;
	    }
	    L__1 = i__ != 0;
	    compfg_(geovar_1.xparam, &c_true, &escf, &c_true, gradnt_1.grad, &
		    L__1);
	    goto L40;
	}
    }

/* CALCULATE DYNAMIC REACTION COORDINATE. */


    if (i_indx(keywrd_1.keywrd, "SADDLE", (ftnlen)241, (ftnlen)6) != 0) {
	react1_(&escf);
	goto L50;
    }
    if (i_indx(keywrd_1.keywrd, "STEP1", (ftnlen)241, (ftnlen)5) != 0) {
	grid_();
	goto L50;
    }
    if (path_1.latom != 0) {

/*       DO PATH */

	if (i_indx(keywrd_1.keywrd, "STEP", (ftnlen)241, (ftnlen)4) == 0 || 
		i_indx(keywrd_1.keywrd, "POINT", (ftnlen)241, (ftnlen)5) == 0)
		 {
	    paths_();
	    goto L50;
	}
	pathk_();
	goto L50;
    }
    if (i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0 || 
	    i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) != 0 || 
	    i_indx(keywrd_1.keywrd, "THERM", (ftnlen)241, (ftnlen)5) != 0) {

/* FORCE CALCULATION IF DESIRED */

	force_();
	goto L50;
    }
    if (i_indx(keywrd_1.keywrd, " DRC", (ftnlen)241, (ftnlen)4) + i_indx(
	    keywrd_1.keywrd, " IRC", (ftnlen)241, (ftnlen)4) != 0) {

/*   IN THIS CONTEXT, "REACT" HOLDS INITIAL VELOCITY VECTOR COMPONENTS. */

	drc_(path_1.react, path_1.react);
	goto L50;
    }

    if (i_indx(keywrd_1.keywrd, "NLLSQ", (ftnlen)241, (ftnlen)5) != 0) {
	nllsq_(geovar_1.xparam, &geovar_1.nvar);
	compfg_(geovar_1.xparam, &c_true, &escf, &c_true, gradnt_1.grad, &
		c_true);
	goto L40;
    }

    if (i_indx(keywrd_1.keywrd, "SIGMA", (ftnlen)241, (ftnlen)5) != 0) {
	powsq_(geovar_1.xparam, &geovar_1.nvar, &escf);
	goto L40;
    }

/*  EF OPTIMISATION */

    if (i_indx(keywrd_1.keywrd, " EF", (ftnlen)241, (ftnlen)3) != 0 || i_indx(
	    keywrd_1.keywrd, " TS", (ftnlen)241, (ftnlen)3) != 0) {
	if (i_indx(keywrd_1.keywrd, "GEO-OK", (ftnlen)241, (ftnlen)6) == 0 && 
		geovar_1.nvar > geokst_1.natoms * 3 - 6) {
	    s_wsfe(&io___15);
	    do_fio(&c__1, " EIGENVECTOR FOLLOWING IS NOT RECOMMENDED WHEN", (
		    ftnlen)46);
	    e_wsfe();
	    s_wsfe(&io___16);
	    do_fio(&c__1, " MORE THAN 3N-6 COORDINATES ARE TO BE OPTIMIZED", (
		    ftnlen)47);
	    e_wsfe();
	    s_wsfe(&io___17);
	    do_fio(&c__1, " TO CONTINUE, SPECIFY 'GEO-OK'", (ftnlen)30);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	ef_(geovar_1.xparam, &geovar_1.nvar, &escf);
	goto L40;
    }

/* ORDINARY GEOMETRY OPTIMISATION */


/* ORDINARY GEOMETRY OPTIMISATION */

/* #      CALL TIMER('BEFORE FLEPO') */
/* COSMO change 1/9/92 SJC */
    iseps_1.upda = FALSE_;
/* end of COSMO change */
    flepo_(geovar_1.xparam, &geovar_1.nvar, &escf);
L40:
    last_1.last = 1;
    if (mesage_1.iflepo >= 0) {
	writmo_(&timec_1.time0, &escf);
    }
    if (i_indx(keywrd_1.keywrd, "POLAR", (ftnlen)241, (ftnlen)5) != 0) {
	polar_();
    }
    if (i_indx(keywrd_1.keywrd, " ESP", (ftnlen)241, (ftnlen)4) != 0) {
/*  IF YOU WANT TO USE THE ESP PROGRAM, UNCOMMENT THE LINE */
/*  "C#      CALL ESP", ADD "ESP, " TO MOPAC.OPT, THEN COMPILE ESP AND */
/*  MNDO, AND RELINK. */
	esp_();
    }
L50:
    tim = second_() - timec_1.time0;
    scftyp_1.limscf = FALSE_;
    s_wsfe(&io___19);
    do_fio(&c__1, (char *)&tim, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___20);
    e_wsfe();
    if (okmany_1.isok) {
	goto L10;
    }
    return 0;
} /* MAIN__ */

/* Subroutine */ int getdat_(void)
{
    /* Initialized data */

    static integer i__ = 0;

    /* System generated locals */
    integer i__1;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_clos(cllist *), f_rew(alist *), s_rsfe(cilist *
	    ), do_fio(integer *, char *, ftnlen), e_rsfe(void), s_wsfe(cilist 
	    *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static char line[80];
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___22 = { 1, 2, 1, "(A80)", 0 };
    static cilist io___24 = { 0, 5, 0, "(A80)", 0 };
    static cilist io___25 = { 0, 6, 0, "(A)", 0 };


/* *********************************************************************** */

/*   GETDAT READS ALL THE DATA IN ON CHANNEL 2, AND WRITES IT TO SCRATCH */
/*   CHANNEL 5.  THIS WAY THE ORIGINAL DATA-SET IS FREED UP AS SOON AS */
/*   THE JOB STARTS. */

/* *********************************************************************** */
/* #      WRITE(6,*)GETNAM('FOR005') */
    o__1.oerr = 0;
    o__1.ounit = 2;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR005", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);

/*  CLOSE UNIT 5 IN CASE IT WAS ALREADY PRE-ASSIGNED. */

    cl__1.cerr = 0;
    cl__1.cunit = 5;
    cl__1.csta = 0;
    f_clos(&cl__1);
    o__1.oerr = 0;
    o__1.ounit = 5;
    o__1.ofnm = 0;
    o__1.orl = 0;
    o__1.osta = "SCRATCH";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 5;
    f_rew(&al__1);
    al__1.aerr = 0;
    al__1.aunit = 2;
    f_rew(&al__1);
L10:
    i__1 = s_rsfe(&io___22);
    if (i__1 != 0) {
	goto L20;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)80);
    if (i__1 != 0) {
	goto L20;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L20;
    }
    ++i__;
    s_wsfe(&io___24);
    do_fio(&c__1, line, (ftnlen)80);
    e_wsfe();
    goto L10;
L20:
    al__1.aerr = 0;
    al__1.aunit = 5;
    f_rew(&al__1);
    if (i__ < 3) {
	s_wsfe(&io___25);
	do_fio(&c__1, " INPUT FILE MISSING OR EMPTY", (ftnlen)28);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    cl__1.cerr = 0;
    cl__1.cunit = 2;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* getdat_ */

/* Main program alias */ int mopac_ () { MAIN__ (); return 0; }
