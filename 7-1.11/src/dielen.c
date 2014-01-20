/* dielen.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal fepsi, rds, disex2;
    integer nspa, nps, nps2, nden;
    doublereal cosurf[1200]	/* was [3][400] */, srad[120], abcmat[162000],
	     tm[1080]	/* was [3][3][120] */, qden[660], dirtm[3246]	/* 
	    was [3][1082] */, bh[400];
} solv_;

#define solv_1 solv_

/* Subroutine */ int dielen_(doublereal *edie)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, j, i0;
    static doublereal qi;
    extern /* Subroutine */ int cqden_(void);

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
    cqden_();
    *edie = 0.;
    i0 = solv_1.nps2 + solv_1.nden * solv_1.nps;
    i__1 = solv_1.nden;
    for (i__ = 1; i__ <= i__1; ++i__) {
	qi = solv_1.qden[i__ - 1];
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
	    ++i0;
/* L10: */
	    *edie += qi * 2 * solv_1.abcmat[i0 - 1] * solv_1.qden[j - 1];
	}
	++i0;
	*edie += qi * solv_1.abcmat[i0 - 1] * qi;
/* L20: */
    }
    return 0;
} /* dielen_ */

