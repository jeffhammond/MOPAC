/* fock1.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

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
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Subroutine */ int fock1_(doublereal *f, doublereal *ptot, doublereal *pa, 
	doublereal *pb)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, l, m, ia, ib, ic, ka;
    static doublereal qa[120];
    static integer ii, ni, im1, icc;
    static doublereal sum, sum1, sum2, qtot[120];
    extern /* Subroutine */ int chrge_(doublereal *, doublereal *);
    static doublereal dapop, papop, dtpop;
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
    --pb;
    --pa;
    --ptot;
    --f;

    /* Function Body */
    chrge_(&ptot[1], qtot);
    chrge_(&pa[1], qa);
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
	    case 1:  goto L100;
	    case 2:  goto L40;
	    case 3:  goto L30;
	    case 4:  goto L30;
	    case 5:  goto L30;
	    case 6:  goto L20;
	    case 7:  goto L20;
	    case 8:  goto L20;
	    case 9:  goto L20;
	    case 10:  goto L20;
	}
L20:
	dtpop = ptot[ic * (ic + 1) / 2] + ptot[(ic - 1) * ic / 2] + ptot[(ic 
		- 2) * (ic - 1) / 2] + ptot[(ic - 3) * (ic - 2) / 2] + ptot[(
		ic - 4) * (ic - 3) / 2];
	dapop = pa[ic * (ic + 1) / 2] + pa[(ic - 1) * ic / 2] + pa[(ic - 2) * 
		(ic - 1) / 2] + pa[(ic - 3) * (ic - 2) / 2] + pa[(ic - 4) * (
		ic - 3) / 2];
L30:
	ptpop = ptot[ib * (ib + 1) / 2] + ptot[(ib - 1) * ib / 2] + ptot[(ib 
		- 2) * (ib - 1) / 2];
	papop = pa[ib * (ib + 1) / 2] + pa[(ib - 1) * ib / 2] + pa[(ib - 2) * 
		(ib - 1) / 2];
L40:
	if (ni == 1) {
	    sum = 0.;
	} else {
	    sum2 = 0.;
	    sum1 = 0.;
	    i__2 = ib;
	    for (i__ = ia; i__ <= i__2; ++i__) {
		im1 = i__ - 1;
		i__3 = im1;
		for (j = ia; j <= i__3; ++j) {
/* L50: */
/* Computing 2nd power */
		    d__1 = ptot[j + i__ * (i__ - 1) / 2];
		    sum1 += d__1 * d__1;
		}
/* L60: */
/* Computing 2nd power */
		d__1 = ptot[i__ * (i__ + 1) / 2];
		sum2 += d__1 * d__1;
	    }
	    sum = sum1 * 2. + sum2;
	    sum = sqrt(sum) - qtot[ii - 1] * .5;
	}
	sum *= gauss_1.fn1[ni - 1];

/*     F(S,S) */

	ka = ia * (ia + 1) / 2;
	f[ka] = f[ka] + pb[ka] * twoele_1.gss[ni - 1] + ptpop * twoele_1.gsp[
		ni - 1] - papop * twoele_1.hsp[ni - 1] + dtpop * twoele_1.gsd[
		ni - 1];
	if (ni < 3) {
	    goto L100;
	}
	iplus = ia + 1;
	l = ka;
	i__2 = ib;
	for (j = iplus; j <= i__2; ++j) {
	    m = l + ia;
	    l += j;

/*     F(P,P) */

	    f[l] = f[l] + ptot[ka] * twoele_1.gsp[ni - 1] - pa[ka] * 
		    twoele_1.hsp[ni - 1] + pb[l] * twoele_1.gpp[ni - 1] + (
		    ptpop - ptot[l]) * twoele_1.gp2[ni - 1] - (papop - pa[l]) 
		    * .5 * (twoele_1.gpp[ni - 1] - twoele_1.gp2[ni - 1]) + 
		    dtpop * twoele_1.gpd[ni - 1];

/*     F(S,P) */

/* L70: */
	    f[m] = f[m] + ptot[m] * 2. * twoele_1.hsp[ni - 1] - pa[m] * (
		    twoele_1.hsp[ni - 1] + twoele_1.gsp[ni - 1]);
	}

/*     F(P,P*) */

	iminus = ib - 1;
	i__2 = iminus;
	for (j = iplus; j <= i__2; ++j) {
	    icc = j + 1;
	    i__3 = ib;
	    for (l = icc; l <= i__3; ++l) {
		m = l * (l - 1) / 2 + j;
/* L80: */
		f[m] = f[m] + ptot[m] * (twoele_1.gpp[ni - 1] - twoele_1.gp2[
			ni - 1]) - pa[m] * .5 * (twoele_1.gpp[ni - 1] + 
			twoele_1.gp2[ni - 1]);
	    }
	}
	i__3 = ic;
	for (j = ib + 1; j <= i__3; ++j) {
	    m = j * (j + 1) / 2;
/* L90: */
	    f[m] = f[m] + ptot[ka] * twoele_1.gsd[ni - 1] + ptpop * 
		    twoele_1.gpd[ni - 1] + (dtpop - pa[m]) * twoele_1.gdd[ni 
		    - 1];
	}
L100:
	;
    }
    return 0;
} /* fock1_ */

