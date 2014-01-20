/* mopac7lib.f -- translated by f2c (version 20020621).
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

struct okmany_1_ {
    logical isok;
};

#define okmany_1 (*(struct okmany_1_ *) &okmany_)

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

struct numcal_1_ {
    integer numcal;
};

#define numcal_1 (*(struct numcal_1_ *) &numcal_)

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

/* Initialized data */

struct {
    integer e_1;
    } numcal_ = { 0 };

struct {
    logical e_1;
    } okmany_ = { TRUE_ };


/* Table of constant values */

static integer c__6 = 6;
static integer c__0 = 0;
static integer c__1 = 1;


/*         Notice of Public Domain nature of MOPAC */

/*      'This computer program is a work of the United States */
/*       Government and as such is not subject to protection by */
/*       copyright (17 U.S.C. # 105.)  Any person who fraudulently */
/*       places a copyright notice or does any other act contrary */
/*       to the provisions of 17 U.S. Code 506(c) shall be subject */
/*       to the penalties provided therein.  This notice shall not */
/*       be altered or removed from this software and is to be on */
/*       all reproductions.' */

/* Subroutine */ int lm7start_(void)
{
    extern /* Subroutine */ int geout_(integer *), getdat_(void);
    extern doublereal second_(void);
    extern /* Subroutine */ int readmo_(void), moldat_(integer *);

/* *** this is the original MOPAC main program. */
/* *** since we already have a main program, we have changed it into a subroutine. */
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
/* *** update logic for NUMCAL and ISOK is changed; initialized using DATA commands above. */
/*      NUMCAL=0 */
/*      ISOK=.TRUE. */
/* L10: */
    ++numcal_1.numcal;

    timec_1.time0 = second_();

/* READ AND CHECK INPUT FILE, EXIT IF NECESSARY. */
/*     WRITE INPUT FILE TO UNIT 6 AS FEEDBACK TO USER */

/* L20: */
    readmo_();
    scftyp_1.emin = 0.;
/* #      CALL TIMER('AFTER READ') */
/* *** text outputs and jumps in code are removed here... */
/*      IF(NATOMS.EQ.0) GOTO 50 */
/*      IF(INDEX(KEYWRD,'AUTHOR') .NE. 0) THEN */
/*         WRITE(6,'(10X,'' MOPAC - A GENERAL MOLECULAR ORBITAL PACKAGE'', */
/*     1/         ,10X,''   ORIGINAL VERSION WRITTEN IN 1983'')') */
/*         WRITE(6,'(10X,''     BY JAMES J. P. STEWART AT THE'',/ */
/*     1         ,10X,''     UNIVERSITY OF TEXAS AT AUSTIN'',/ */
/*     2         ,10X,''          AUSTIN, TEXAS, 78712'')') */
/*         WRITE(6,'(10X,''  MODIFIED TO DO ESP CALCULATIONS BY'' */
/*     1          ,10X,''    BRENT H. BESLER AND K. M. MERZ JR. 1989'')') */
/*      ENDIF */

/* INITIALIZE CALCULATION AND WRITE CALCULATION INDEPENDENT INFO */

/*      IF(INDEX(KEYWRD,'0SCF') .NE. 0) THEN */
/*         WRITE(6,'(A)')' GEOMETRY IN MOPAC Z-MATRIX FORMAT' */
    geout_(&c__6);
/*         IF(INDEX(KEYWRD,' AIGOUT').NE.0)THEN */
/*            WRITE(6,'(//,A)')'  GEOMETRY IN GAUSSIAN Z-MATRIX FORMAT' */
/*            CALL WRTTXT(6) */
/*            CALL GEOUTG(6) */
/*         ENDIF */
/*         GOTO 50 */
/*      ENDIF */
    moldat_(&c__0);
/* *** ok, initialization is now done, and we can stop here... */
    return 0;
} /* lm7start_ */

/* Subroutine */ int lm7stop_(void)
{
    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal tim;
    extern doublereal second_(void);

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, "(///,' TOTAL CPU TIME: ',F16.2,' SECO"
	    "NDS')", 0 };
    static cilist io___3 = { 0, 6, 0, "(/,' == MOPAC DONE ==')", 0 };


/* *** this is the end part of the original MOPAC main program. */
/* *** this is a subroutine that will run the mopac down... */
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
/* L40: */
    last_1.last = 1;
/*      IF(IFLEPO.GE.0)CALL WRITMO(TIME0, ESCF) */
/*      IF(INDEX(KEYWRD,'POLAR') .NE. 0) THEN */
/*         CALL POLAR */
/*      ENDIF */
/*      IF(INDEX(KEYWRD,' ESP') .NE. 0)THEN */
/*  IF YOU WANT TO USE THE ESP PROGRAM, UNCOMMENT THE LINE */
/*  "C#      CALL ESP", ADD "ESP, " TO MOPAC.OPT, THEN COMPILE ESP AND */
/*  MNDO, AND RELINK. */
/*          CALL ESP */
/*      ENDIF */
/* L50: */
    tim = second_() - timec_1.time0;
    scftyp_1.limscf = FALSE_;
    s_wsfe(&io___2);
    do_fio(&c__1, (char *)&tim, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___3);
    e_wsfe();
/*      IF(ISOK) GOTO 10 */
    return 0;
} /* lm7stop_ */

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
    static cilist io___5 = { 1, 2, 1, "(A80)", 0 };
    static cilist io___7 = { 0, 5, 0, "(A80)", 0 };
    static cilist io___8 = { 0, 6, 0, "(A)", 0 };


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
    i__1 = s_rsfe(&io___5);
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
    s_wsfe(&io___7);
    do_fio(&c__1, line, (ftnlen)80);
    e_wsfe();
    goto L10;
L20:
    al__1.aerr = 0;
    al__1.aunit = 5;
    f_rew(&al__1);
    if (i__ < 3) {
	s_wsfe(&io___8);
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

