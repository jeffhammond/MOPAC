/* addnuc.f -- translated by f2c (version 20020621).
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

struct {
    integer iatsp[401], nar[400], nn[240]	/* was [2][120] */;
} solvi_;

#define solvi_1 solvi_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

/* Subroutine */ int addnuc_(doublereal *enuclr)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, i0, i1, ia, ja, idel, jdel, iden;
    static doublereal corei, enclr;

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
    enclr = 0.;
    i0 = solv_1.nps2 + solv_1.nden * solv_1.nps;
    iden = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = molkst_1.nfirst[i__ - 1];
	idel = molkst_1.nlast[i__ - 1] - ia;
	i1 = i0 + iden * (iden + 1) / 2;
	corei = core_1.core[molkst_1.nat[i__ - 1] - 1];
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
	    ja = molkst_1.nfirst[j - 1];
	    jdel = molkst_1.nlast[j - 1] - ja;
	    ++i1;
	    enclr += corei * 2 * solv_1.abcmat[i1 - 1] * core_1.core[
		    molkst_1.nat[j - 1] - 1];
/* Computing 2nd power */
	    i__3 = jdel;
	    i1 += i__3 * i__3;
/* L10: */
	}
	++i1;
	enclr += corei * solv_1.abcmat[i1 - 1] * corei;
/* Computing 2nd power */
	i__2 = idel;
	iden = iden + 1 + i__2 * i__2;
/* L20: */
    }
    *enuclr += enclr;
    return 0;
} /* addnuc_ */

