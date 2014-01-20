/* symtry.f -- translated by f2c (version 20020621).
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
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

/* Subroutine */ int symtry_(void)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, locn;
    static doublereal value;
    extern /* Subroutine */ int haddon_(doublereal *, integer *, integer *, 
	    integer *, doublereal *);

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

/*  SYMTRY COMPUTES THE BOND LENGTHS AND ANGLES THAT ARE FUNCTIONS OF */
/*         OTHER BOND LENGTHS AND ANGLES. */

/* ON INPUT GEO     = KNOWN INTERNAL COORDINATES */
/*          NDEP    = NUMBER OF DEPENDENCY FUNCTIONS. */
/*          IDEPFN  = ARRAY OF DEPENDENCY FUNCTIONS. */
/*          LOCDEP  = ARRAY OF LABELS OF DEPENDENT ATOMS. */
/*          LOCPAR  = ARRAY OF LABELS OF REFERENCE ATOMS. */

/*  ON OUTPUT THE ARRAY "GEO" IS FILLED */
/* *********************************************************************** */

/*     NOW COMPUTE THE DEPENDENT PARAMETERS. */

    i__1 = geosym_1.ndep;
    for (i__ = 1; i__ <= i__1; ++i__) {
	haddon_(&value, &locn, &geosym_1.idepfn[i__ - 1], &geosym_1.locpar[
		i__ - 1], geom_1.geo);
	j = geosym_1.locdep[i__ - 1];
/* L10: */
	geom_1.geo[locn + j * 3 - 4] = value;
    }
    return 0;
} /* symtry_ */

