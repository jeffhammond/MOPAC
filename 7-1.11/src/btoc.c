/* btoc.f -- translated by f2c (version 20020621).
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
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

/* Subroutine */ int btoc_(doublereal *coord)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l, i0, i1, ia;
    static doublereal xa[3], ri, rm;
    static integer ix;
    static doublereal xx[3];
    static integer kk2;
    static doublereal rm1, rm3, rm5, ddi, bhk, cij;
    static integer ips;
    static doublereal qqi2;
    static integer idel;
    static doublereal fact;
    static integer iden, nati;
    static doublereal dist;

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
    coord -= 4;

    /* Function Body */
    i__1 = solv_1.nps;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = solvi_1.iatsp[i__ - 1];
	ri = solv_1.srad[j - 1] - solv_1.rds;
	for (ix = 1; ix <= 3; ++ix) {
/* L10: */
	    solv_1.cosurf[ix + i__ * 3 - 4] = solv_1.cosurf[ix + i__ * 3 - 4] 
		    * ri + coord[ix + j * 3];
	}
    }
/* FILLING B-MATRIX */
    i0 = solv_1.nps2 - solv_1.nden;
    iden = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = molkst_1.nfirst[i__ - 1];
	idel = molkst_1.nlast[i__ - 1] - ia;
	nati = molkst_1.nat[i__ - 1];
	ddi = multip_1.dd[nati - 1] * 2 * .529177;
/* Computing 2nd power */
	d__1 = multip_1.qq[nati - 1] * .529177;
	qqi2 = d__1 * d__1;
	for (ix = 1; ix <= 3; ++ix) {
	    xx[ix - 1] = coord[ix + i__ * 3];
/* L20: */
	}
	i__2 = solv_1.nps;
	for (ips = 1; ips <= i__2; ++ips) {
	    i1 = i0 + ips * solv_1.nden;
	    dist = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
		xa[ix - 1] = solv_1.cosurf[ix + ips * 3 - 4] - xx[ix - 1];
/* Computing 2nd power */
		d__1 = xa[ix - 1];
		dist += d__1 * d__1;
/* L30: */
	    }
	    rm1 = 1. / sqrt(dist);
	    solv_1.abcmat[iden + 1 + i1 - 1] = rm1;
	    if (idel == 0) {
		goto L40;
	    }
/* Computing 3rd power */
	    d__1 = rm1;
	    rm3 = d__1 * (d__1 * d__1);
/* Computing 5th power */
	    d__1 = rm1, d__2 = d__1, d__1 *= d__1;
	    rm5 = d__2 * (d__1 * d__1);
/* Computing 2nd power */
	    d__1 = xa[0];
	    solv_1.abcmat[iden + 3 + i1 - 1] = rm1 + d__1 * d__1 * 3 * qqi2 * 
		    rm5 - qqi2 * rm3;
/* Computing 2nd power */
	    d__1 = xa[1];
	    solv_1.abcmat[iden + 6 + i1 - 1] = rm1 + d__1 * d__1 * 3 * qqi2 * 
		    rm5 - qqi2 * rm3;
/* Computing 2nd power */
	    d__1 = xa[2];
	    solv_1.abcmat[iden + 10 + i1 - 1] = rm1 + d__1 * d__1 * 3 * qqi2 *
		     rm5 - qqi2 * rm3;
	    solv_1.abcmat[iden + 2 + i1 - 1] = xa[0] * ddi * rm3;
	    solv_1.abcmat[iden + 4 + i1 - 1] = xa[1] * ddi * rm3;
	    solv_1.abcmat[iden + 7 + i1 - 1] = xa[2] * ddi * rm3;
	    solv_1.abcmat[iden + 5 + i1 - 1] = xa[0] * 6 * xa[1] * qqi2 * rm5;
	    solv_1.abcmat[iden + 8 + i1 - 1] = xa[0] * 6 * xa[2] * qqi2 * rm5;
	    solv_1.abcmat[iden + 9 + i1 - 1] = xa[2] * 6 * xa[1] * qqi2 * rm5;
L40:
	    ;
	}
/* L50: */
/* Computing 2nd power */
	i__2 = idel;
	iden = iden + 1 + i__2 * i__2;
    }
    i1 = solv_1.nps2 + solv_1.nden * solv_1.nps;
/*  FILLING C-MATRIX */
    fact = solv_1.fepsi * -7.2001893600000004;
    i__2 = solv_1.nden;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = solv_1.nps;
	for (k = 1; k <= i__1; ++k) {
	    bhk = 0.;
	    kk2 = k * (k - 1) / 2;
	    i__3 = k;
	    for (l = 1; l <= i__3; ++l) {
/* L60: */
		bhk += solv_1.abcmat[i__ + l * solv_1.nden + i0 - 1] * 
			solv_1.abcmat[kk2 + l - 1];
	    }
	    i__3 = solv_1.nps;
	    for (l = k + 1; l <= i__3; ++l) {
/* L70: */
		bhk += solv_1.abcmat[i__ + l * solv_1.nden + i0 - 1] * 
			solv_1.abcmat[l * (l - 1) / 2 + k - 1];
	    }
	    solv_1.bh[k - 1] = bhk;
/* L80: */
	}
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    cij = 0.;
	    i__3 = solv_1.nps;
	    for (k = 1; k <= i__3; ++k) {
/* L90: */
		cij += solv_1.bh[k - 1] * solv_1.abcmat[j + k * solv_1.nden + 
			i0 - 1];
	    }
	    ++i1;
	    solv_1.abcmat[i1 - 1] = fact * cij;
/* L100: */
	}
/* L110: */
    }
    i1 = solv_1.nps2 + solv_1.nden * solv_1.nps;
    i__2 = solv_1.nden;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L120: */
	i1 += i__;
    }
    i__2 = solv_1.nps;
    for (i__ = 1; i__ <= i__2; ++i__) {
	j = solvi_1.iatsp[i__ - 1];
	rm = solv_1.srad[j - 1] - solv_1.rds;
	for (ix = 1; ix <= 3; ++ix) {
/* L130: */
	    solv_1.cosurf[ix + i__ * 3 - 4] = (solv_1.cosurf[ix + i__ * 3 - 4]
		     - coord[ix + j * 3]) / rm;
	}
    }
/*      CALL DIELEN(EDIE) */
    return 0;
} /* btoc_ */

