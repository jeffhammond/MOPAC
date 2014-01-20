/* partxy.f -- translated by f2c (version 20020621).
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
    doublereal wj[214770], wk[214770];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
} twoele_;

#define twoele_1 twoele_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Subroutine */ int partxy_(doublereal *c34, doublereal *pq34)
{
    /* Initialized data */

    static integer ld[9] = { 0,2,5,9,14,20,27,35,44 };
    static integer nb[9] = { 1,0,0,10,0,0,0,0,45 };
    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__;
#define w ((doublereal *)&wmatrx_1)
    static integer ia, ib, ic, ii, ij, jj, kk, kr, js, ls;
    static doublereal pp;
    static integer lx, ly, lz;
    static doublereal hpp;
    static integer izn, indx[120];
    static doublereal ptot[120];
    static integer jband, nband, ijold, ipqrs;
    static doublereal gspss;
    extern /* Subroutine */ int formxy_(doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, integer *, doublereal *, integer *);

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
/* ------------------------------------------------------------------ */

/*    PARTXY WORKS OUT  IN MNDO FORMALISM THE FIRST 2-INDICES TRANSFO. */
/*          REQUIRED IN THE COMPUTATION OF 2-ELECTRONS REPULSION OVER M.O */
/*  INPUT */
/*     C34   : VECTOR OF THE CURRENT CHARGE DISTRIBUTION BETWEEN TWO M.O. */
/*  OUTPUT */
/*     PQ34(PQ) : <P(1),Q(1)|C3(2),C4(2)> WHERE P ,Q  ARE A.O. */
/*                                          AND C3,C4 ARE M.O. */
/*                P AND Q RUN IN CANONICAL ORDER OVER THE A.O BELONGING */
/*                TO AN ATOM 'A' ONLY (BASIC ASSUMPTION OF MNDO SCHEME) */
/*                AND 'A' RUNS OVER THE ATOMS OF THE SYSTEM. */
/*     D.L. (DEWAR GROUP) 1986 */
/* ---------------------------------------------------------------------- */
    /* Parameter adjustments */
    --pq34;
    --c34;

    /* Function Body */
    if (numcal_1.numcal != icalcn) {
	icalcn = numcal_1.numcal;
	indx[0] = 1;
	i__1 = molkst_1.numat;
	for (i__ = 2; i__ <= i__1; ++i__) {
/* L10: */
	    indx[i__ - 1] = indx[i__ - 2] + nb[molkst_1.nlast[i__ - 2] - 
		    molkst_1.nfirst[i__ - 2]];
	}
    }
/*     IJ    : POINTER OF CANONICAL PACKED LOCATION OF COUPLE IJ. */
/*     KK    : POINTER OF SUPPORTING ATOM, SPARKLES SKIPPED OUT. */
/*     IPQRS : CURRENT ENTRY POINT IN THE <PQ|RS> FILE. */
    kk = 0;
    ipqrs = 1;
    ij = 0;
    ijold = 0;

/*     LOOP OVER OUTER ATOM A, SPARKLES EXCLUDED. */
/*     ------------------------------------------ */
    nband = 1;
    kr = 1;
    ls = 0;
    i__1 = molkst_1.numat;
    for (ii = 1; ii <= i__1; ++ii) {
	ia = molkst_1.nfirst[ii - 1];
	ib = molkst_1.nmidle[ii - 1];
	ic = molkst_1.nlast[ii - 1];
	if (ic < ia) {
	    goto L30;
	}
	++kk;
	ls += nband;
	nband = nb[ic - ia];
	ij += nband;

/*     PQ34(IJ) = <IJ|KL> * C34(KL)  , 1-CENTRE CONTRIBUTIONS. */
	izn = molkst_1.nat[ii - 1];
/*     BLOCK SS */
	ptot[kk - 1] = c34[ls];
	pq34[ls] = c34[ls] * twoele_1.gss[izn - 1] * .25;
	if (ib > ia) {
/*        BLOCK SP AND PP */
	    hpp = (twoele_1.gpp[izn - 1] - twoele_1.gp2[izn - 1]) * .5;
	    lx = ls + ld[1];
	    ly = ls + ld[2];
	    lz = ls + ld[3];
	    pp = c34[lx] + c34[ly] + c34[lz];
	    pq34[ls + 1] = twoele_1.hsp[izn - 1] * c34[ls + 1];
	    pq34[lx] = twoele_1.gpp[izn - 1] * c34[lx] * .25;
	    pq34[ls + 3] = twoele_1.hsp[izn - 1] * c34[ls + 3];
	    pq34[ls + 4] = hpp * c34[ls + 4];
	    pq34[ly] = twoele_1.gpp[izn - 1] * c34[ly] * .25;
	    pq34[ls + 6] = twoele_1.hsp[izn - 1] * c34[ls + 6];
	    pq34[ls + 7] = hpp * c34[ls + 7];
	    pq34[ls + 8] = hpp * c34[ls + 8];
	    pq34[lz] = twoele_1.gpp[izn - 1] * c34[lz] * .25;
	    gspss = twoele_1.gsp[izn - 1] * c34[ls] * .25;
	    pq34[ls] += twoele_1.gsp[izn - 1] * pp * .25;
	    pq34[lx] = pq34[lx] + twoele_1.gp2[izn - 1] * (c34[ly] + c34[lz]) 
		    * .25 + gspss;
	    pq34[ly] = pq34[ly] + twoele_1.gp2[izn - 1] * (c34[lz] + c34[lx]) 
		    * .25 + gspss;
	    pq34[lz] = pq34[lz] + twoele_1.gp2[izn - 1] * (c34[lx] + c34[ly]) 
		    * .25 + gspss;
	    ptot[kk - 1] += pp;
	    if (ic > ib) {
/*           BLOCK SD, PD AND DD */
/*           --- WAITING FOR 'D' PARAMETERS --- */
/*               TAKE CARE : DIAGONAL ELEMENTS OF C34 ARE DOUBLED. */
	    }
	}
	if (kk > 1) {

/*        LOOP OVER CHARGE DISTRIBUTION OF INNER ATOMS  B < A . */
/*        ----------------------------------------------------- */
/*        PQ34(IJ)=<IJ|KL>*C34(KL) 2-CENTRES CONTRIBUTIONS. */

	    jband = 1;
	    js = 0;
	    i__2 = ii - 1;
	    for (jj = 1; jj <= i__2; ++jj) {
		js += jband;
		jband = nb[molkst_1.nlast[jj - 1] - molkst_1.nfirst[jj - 1]];

/*   NBAND AND JBAND ARE EITHER 1 OR 10 */

		formxy_(&w[kr - 1], &kr, &pq34[ls], &pq34[js], &c34[ls], &
			nband, &c34[js], &jband);
/* L20: */
		ipqrs += ijold;
	    }
	}
	ijold = ij;
L30:
	;
    }
    return 0;
} /* partxy_ */

#undef w


