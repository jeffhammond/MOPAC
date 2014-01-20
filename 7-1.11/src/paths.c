/* paths.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal alparm[1080]	/* was [3][360] */, x0, x1, x2;
    integer iloop;
} alparm_;

#define alparm_1 alparm_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int paths_(void)
{
    /* Initialized data */

    static char type__[10*3] = "ANGSTROMS " "DEGREES   " "DEGREES   ";

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static doublereal c3, x3, gd[360], cb1, cc1, cc2, cb2;
    static integer lpr, mdfp[20];
    static doublereal xdfp[20], delf0, delf1;
    extern /* Subroutine */ int flepo_(doublereal *, integer *, doublereal *);
    static doublereal funct, rnord, xlast[360], funct1;
    extern doublereal second_(void);
    extern /* Subroutine */ int dfpsav_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static doublereal aconst, bconst, cconst, totime;
    extern /* Subroutine */ int writmo_(doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 6, 0, "(//10X,' RESTARTING AT POINT',I3)", 0 }
	    ;
    static cilist io___9 = { 0, 6, 0, "('  ABOUT TO ENTER FLEPO FROM PATH')", 
	    0 };
    static cilist io___11 = { 0, 6, 0, "('  OPTIMIZED VALUES OF PARAMETERS, "
	    "INITIAL POINT')", 0 };
    static cilist io___14 = { 0, 6, 0, "(1X,16('*****')//17X,'REACTION COORD"
	    "INATE = '        ,F12.4,2X,A10,19X//1X,16('*****'))", 0 };
    static cilist io___16 = { 0, 6, 0, "(1X,16('*****')//19X,'REACTION COORD"
	    "INATE = '     ,F12.4,2X,A10,19X//1X,16('*****'))", 0 };
    static cilist io___28 = { 0, 6, 0, "(' GEOMETRY TOO UNSTABLE FOR EXTRAPO"
	    "LATION TO BE USED'/ ,' - THE LAST GEOMETRY IS BEING USED TO STAR"
	    "T THE NEXT'     ,' CALCULATION')", 0 };


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
/* *********************************************************************** */

/*   PATH FOLLOWS A REACTION COORDINATE.   THE REACTION COORDINATE IS ON */
/*        ATOM LATOM, AND IS A DISTANCE IF LPARAM=1, */
/*                           AN ANGLE   IF LPARAM=2, */
/*                           AN DIHEDRALIF LPARAM=3. */

/* *********************************************************************** */
    alparm_1.iloop = 1;
    if (i_indx(keywrd_1.keywrd, "RESTAR", (ftnlen)241, (ftnlen)6) != 0) {
	mdfp[8] = 0;
	dfpsav_(&totime, geovar_1.xparam, gd, xlast, &funct1, mdfp, xdfp);
	s_wsfe(&io___8);
	do_fio(&c__1, (char *)&alparm_1.iloop, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (alparm_1.iloop > 1) {
	goto L10;
    }
    s_wsfe(&io___9);
    e_wsfe();
    timec_1.time0 = second_();
    flepo_(geovar_1.xparam, &geovar_1.nvar, &funct);
    s_wsfe(&io___11);
    e_wsfe();
    writmo_(&timec_1.time0, &funct);
    timec_1.time0 = second_();
L10:
    if (alparm_1.iloop > 2) {
	goto L40;
    }
    geom_1.geo[path_1.lparam + path_1.latom * 3 - 4] = path_1.react[1];
    if (alparm_1.iloop == 1) {
	alparm_1.x0 = path_1.react[0];
	alparm_1.x1 = alparm_1.x0;
	alparm_1.x2 = path_1.react[1];
	if (alparm_1.x2 < -100.) {
	    s_stop("", (ftnlen)0);
	}
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    alparm_1.alparm[i__ * 3 - 2] = geovar_1.xparam[i__ - 1];
/* L20: */
	    alparm_1.alparm[i__ * 3 - 3] = geovar_1.xparam[i__ - 1];
	}
	alparm_1.iloop = 2;
    }
    flepo_(geovar_1.xparam, &geovar_1.nvar, &funct);
    rnord = path_1.react[1];
    if (path_1.lparam > 1) {
	rnord *= 57.29577951;
    }
    s_wsfe(&io___14);
    do_fio(&c__1, (char *)&rnord, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, type__ + (path_1.lparam - 1) * 10, (ftnlen)10);
    e_wsfe();
    writmo_(&timec_1.time0, &funct);
    timec_1.time0 = second_();
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	alparm_1.alparm[i__ * 3 - 1] = geovar_1.xparam[i__ - 1];
    }

/*   NOW FOR THE MAIN INTERPOLATION ROUTE */

    if (alparm_1.iloop == 2) {
	alparm_1.iloop = 3;
    }
L40:
    lpr = alparm_1.iloop;
    for (alparm_1.iloop = lpr; alparm_1.iloop <= 100; ++alparm_1.iloop) {

	if (path_1.react[alparm_1.iloop - 1] < -100.) {
	    return 0;
	}

	rnord = path_1.react[alparm_1.iloop - 1];
	if (path_1.lparam > 1) {
	    rnord *= 57.29577951;
	}
	s_wsfe(&io___16);
	do_fio(&c__1, (char *)&rnord, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, type__ + (path_1.lparam - 1) * 10, (ftnlen)10);
	e_wsfe();

	x3 = path_1.react[alparm_1.iloop - 1];
/* Computing 2nd power */
	d__1 = alparm_1.x0;
/* Computing 2nd power */
	d__2 = alparm_1.x1;
/* Computing 2nd power */
	d__3 = alparm_1.x1;
/* Computing 2nd power */
	d__4 = alparm_1.x2;
	c3 = (d__1 * d__1 - d__2 * d__2) * (alparm_1.x1 - alparm_1.x2) - (
		d__3 * d__3 - d__4 * d__4) * (alparm_1.x0 - alparm_1.x1);
/*      WRITE(6,'(''   C3:'',F13.7)')C3 */
	if (abs(c3) < 1e-8) {

/*    WE USE A LINEAR INTERPOLATION */

	    cc1 = 0.;
	    cc2 = 0.;
	} else {
/*    WE DO A QUADRATIC INTERPOLATION */

	    cc1 = (alparm_1.x1 - alparm_1.x2) / c3;
	    cc2 = (alparm_1.x0 - alparm_1.x1) / c3;
	}
	cb1 = 1. / (alparm_1.x1 - alparm_1.x2);
/* Computing 2nd power */
	d__1 = alparm_1.x1;
/* Computing 2nd power */
	d__2 = alparm_1.x2;
	cb2 = (d__1 * d__1 - d__2 * d__2) * cb1;

/*    NOW TO CALCULATE THE INTERPOLATED COORDINATES */

	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    delf0 = alparm_1.alparm[i__ * 3 - 3] - alparm_1.alparm[i__ * 3 - 
		    2];
	    delf1 = alparm_1.alparm[i__ * 3 - 2] - alparm_1.alparm[i__ * 3 - 
		    1];
	    aconst = cc1 * delf0 - cc2 * delf1;
	    bconst = cb1 * delf1 - aconst * cb2;
/* Computing 2nd power */
	    d__1 = alparm_1.x2;
	    cconst = alparm_1.alparm[i__ * 3 - 1] - bconst * alparm_1.x2 - 
		    aconst * (d__1 * d__1);
/* Computing 2nd power */
	    d__1 = x3;
	    geovar_1.xparam[i__ - 1] = cconst + bconst * x3 + aconst * (d__1 *
		     d__1);
	    alparm_1.alparm[i__ * 3 - 3] = alparm_1.alparm[i__ * 3 - 2];
/* L50: */
	    alparm_1.alparm[i__ * 3 - 2] = alparm_1.alparm[i__ * 3 - 1];
	}

/*   NOW TO CHECK THAT THE GUESSED GEOMETRY IS NOT TOO ABSURD */

	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
	    if ((d__1 = geovar_1.xparam[i__ - 1] - alparm_1.alparm[i__ * 3 - 
		    1], abs(d__1)) > .2f) {
		goto L70;
	    }
	}
	goto L90;
L70:
	s_wsfe(&io___28);
	e_wsfe();
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L80: */
	    geovar_1.xparam[i__ - 1] = alparm_1.alparm[i__ * 3 - 1];
	}
L90:
	alparm_1.x0 = alparm_1.x1;
	alparm_1.x1 = alparm_1.x2;
	alparm_1.x2 = x3;
	geom_1.geo[path_1.lparam + path_1.latom * 3 - 4] = path_1.react[
		alparm_1.iloop - 1];
	flepo_(geovar_1.xparam, &geovar_1.nvar, &funct);
	writmo_(&timec_1.time0, &funct);
	timec_1.time0 = second_();
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	    alparm_1.alparm[i__ * 3 - 1] = geovar_1.xparam[i__ - 1];
	}
/* L110: */
    }
    return 0;
} /* paths_ */

