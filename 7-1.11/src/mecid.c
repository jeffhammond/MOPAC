/* mecid.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal occa[8];
} baseoc_;

#define baseoc_1 baseoc_

struct {
    integer microa[2048]	/* was [8][256] */, microb[2048]	/* 
	    was [8][256] */;
} micros_;

#define micros_1 micros_

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

/* Subroutine */ int mecid_(doublereal *eigs, doublereal *gse, doublereal *
	eiga, doublereal *diag)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j;
    static doublereal x;
    extern doublereal diagi_(integer *, integer *, doublereal *, doublereal *,
	     integer *);

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

/*   MECID CALCULATES THE EFFECT OF REMOVING THE ELECTRONS INVOLVED IN */
/*   THE C.I. FROM THE GROUND-STATE CONFIGURATION, AND CALCULATES THE */
/*   MICROSTATE ENERGIES OF THE MICROSTATES INVOLVED IN THE C.I. */

/*  THE QUANTITIES NMOS, NELEC, AND LAB, AND THE ARRAYS EIGS, OCCA, */
/*  MICROA, AND MICROB ARE USED, BUT UNCHANGED ON EXIT */

/*   ON EXIT, GSE IS THE ELECTRONIC ENERGY OF STABILIZATION DUE TO */
/*            REMOVAL OF THE ELECTRONS INVOLVED IN THE C.I. */

/*            EIGA HOLDS THE ONE-ELECTRON ENERGY LEVELS RESULTING FROM */
/*            REMOVAL OF THE ELECTRONS INVOLVED IN THE C.I. */

/*            DIAG HOLDS THE MICROSTATE ENERGIES OF ALL STATES INVOLVED */
/*            IN THE C.I.  THIS CAN BE USED AS THE DIAGONAL OF A C.I. */
/*            MATRIX */

/* *********************************************************************** */
    /* Parameter adjustments */
    --diag;
    --eiga;
    --eigs;

    /* Function Body */
    *gse = 0.;
    i__1 = cibits_1.nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x = 0.;
	i__2 = cibits_1.nmos;
	for (j = 1; j <= i__2; ++j) {
/* L10: */
	    x += (xyijkl_1.xy[i__ + (i__ + (j + (j << 3) << 3) << 3) - 585] * 
		    2. - xyijkl_1.xy[i__ + (j + (i__ + (j << 3) << 3) << 3) - 
		    585]) * baseoc_1.occa[j - 1];
	}
	eiga[i__] = eigs[i__ + cibits_1.nelec] - x;
	*gse += eiga[i__] * baseoc_1.occa[i__ - 1] * 2.;
	*gse += xyijkl_1.xy[i__ + (i__ + (i__ + (i__ << 3) << 3) << 3) - 585] 
		* baseoc_1.occa[i__ - 1] * baseoc_1.occa[i__ - 1];
	i__2 = cibits_1.nmos;
	for (j = i__ + 1; j <= i__2; ++j) {
/* L20: */
	    *gse += (xyijkl_1.xy[i__ + (i__ + (j + (j << 3) << 3) << 3) - 585]
		     * 2. - xyijkl_1.xy[i__ + (j + (i__ + (j << 3) << 3) << 3)
		     - 585]) * 2. * baseoc_1.occa[i__ - 1] * baseoc_1.occa[j 
		    - 1];
	}
    }
    i__2 = cibits_1.lab;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L30: */
	diag[i__] = diagi_(&micros_1.microa[(i__ << 3) - 8], &micros_1.microb[
		(i__ << 3) - 8], &eiga[1], xyijkl_1.xy, &cibits_1.nmos) - *
		gse;
    }
    return 0;
} /* mecid_ */

