/* mecip.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    integer nalpha[64];
} nalmat_;

#define nalmat_1 nalmat_

struct {
    doublereal occa[8];
} baseoc_;

#define baseoc_1 baseoc_

struct {
    doublereal vectci[64], conf[4097];
} civect_;

#define civect_1 civect_

struct {
    integer microa[2048]	/* was [8][256] */, microb[2048]	/* 
	    was [8][256] */;
} micros_;

#define micros_1 micros_

/* Subroutine */ int mecip_(doublereal *coeffs, integer *norbs, doublereal *
	deltap, doublereal *delta)
{
    /* System generated locals */
    integer coeffs_dim1, coeffs_offset, deltap_dim1, deltap_offset, 
	    delta_dim1, delta_offset, i__1, i__2, i__3, i__4;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, id, jd, ij, ix, iy;
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);
    static doublereal sum;

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

/*   MECIP WILL CORRECT THE TOTAL DENSITY MATRIX FOR THE EFFECT OF THE */
/*   C.I. */
/*              ON INPUT */

/*  COEFFS       : ALL M.O.'S (NORBS M.O.S) */
/*  NORBS        : NUMBER OF MOLECULAR ORBITALS = NUMBER OF A.O.'S */
/*  P            : TOTAL DENSITY MATRIX */
/*  NMOS         : NUMBER OF M.O.'S IN ACTIVE SPACE */
/*  VECTCI       : STATE VECTOR OF LENGTH LAB */
/*  MICROA(I,J)  : ALPHA OCCUPANCY OF M.O. 'I' IN MICROSTATE 'J' */
/*  MICROB(I,J)  : BETA  OCCUPANCY OF M.O. 'I' IN MICROSTATE 'J' */

/*  NOTE: THIS IS A MODIFICATION OF CODE ORIGINALLY WRITTEN BY */
/*        PROF. DANIEL LIOTARD */
/* *********************************************************************** */
/*     INITIALIZE WITH THE OPPOSITE OF THE 'SCF' DENSITY. */
    /* Parameter adjustments */
    delta_dim1 = *norbs;
    delta_offset = 1 + delta_dim1 * 1;
    delta -= delta_offset;
    coeffs_dim1 = *norbs;
    coeffs_offset = 1 + coeffs_dim1 * 1;
    coeffs -= coeffs_offset;
    deltap_dim1 = cibits_1.nmos;
    deltap_offset = 1 + deltap_dim1 * 1;
    deltap -= deltap_offset;

    /* Function Body */
    i__1 = cibits_1.nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	deltap[i__ + i__ * deltap_dim1] = -baseoc_1.occa[i__ - 1] * 2.;
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
/* L10: */
	    deltap[i__ + j * deltap_dim1] = 0.;
	}
    }

/*     ADD THE C.I. CORRECTION */
    i__2 = cibits_1.lab;
    for (id = 1; id <= i__2; ++id) {
	i__1 = id;
	for (jd = 1; jd <= i__1; ++jd) {
/*     CHECK SPIN AGREEMENT */
	    if (nalmat_1.nalpha[id - 1] != nalmat_1.nalpha[jd - 1]) {
		goto L120;
	    }
	    ix = 0;
	    iy = 0;
	    i__3 = cibits_1.nmos;
	    for (j = 1; j <= i__3; ++j) {
		ix += (i__4 = micros_1.microa[j + (id << 3) - 9] - 
			micros_1.microa[j + (jd << 3) - 9], abs(i__4));
/* L20: */
		iy += (i__4 = micros_1.microb[j + (id << 3) - 9] - 
			micros_1.microb[j + (jd << 3) - 9], abs(i__4));
	    }
/*     CHECK NUMBER OF DIFFERING M.O. */
	    if (ix + iy > 2) {
		goto L120;
	    }
	    if (ix == 2) {
/*        DETERMINANTS ID AND JD DIFFER BY M.O I IN ID AND M.O J IN JD: */
		i__4 = cibits_1.nmos;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L30: */
		    if (micros_1.microa[i__ + (id << 3) - 9] != 
			    micros_1.microa[i__ + (jd << 3) - 9]) {
			goto L40;
		    }
		}
L40:
		ij = micros_1.microb[i__ + (id << 3) - 9];
		i__4 = cibits_1.nmos;
		for (j = i__ + 1; j <= i__4; ++j) {
		    if (micros_1.microa[j + (id << 3) - 9] != micros_1.microa[
			    j + (jd << 3) - 9]) {
			goto L60;
		    }
/* L50: */
		    ij = ij + micros_1.microa[j + (id << 3) - 9] + 
			    micros_1.microb[j + (id << 3) - 9];
		}
/*        IJ GIVES THE SIGN OF THE PERMUTATION */
L60:
		deltap[j + i__ * deltap_dim1] += civect_1.vectci[id - 1] * 
			civect_1.vectci[jd - 1] * (real) (1 - (ij % 2 << 1));
	    } else if (iy == 2) {
/*        DETERMINANTS ID AND JD DIFFER BY M.O J IN ID AND M.O I IN JD: */
		i__4 = cibits_1.nmos;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L70: */
		    if (micros_1.microb[i__ + (id << 3) - 9] != 
			    micros_1.microb[i__ + (jd << 3) - 9]) {
			goto L80;
		    }
		}
L80:
		ij = 0;
		i__4 = cibits_1.nmos;
		for (j = i__ + 1; j <= i__4; ++j) {
		    if (micros_1.microb[j + (id << 3) - 9] != micros_1.microb[
			    j + (jd << 3) - 9]) {
			goto L100;
		    }
/* L90: */
		    ij = ij + micros_1.microa[j + (id << 3) - 9] + 
			    micros_1.microb[j + (id << 3) - 9];
		}
L100:
		ij += micros_1.microa[j + (id << 3) - 9];
		deltap[j + i__ * deltap_dim1] += civect_1.vectci[id - 1] * 
			civect_1.vectci[jd - 1] * (real) (1 - (ij % 2 << 1));
	    } else {
/*        DETERMINANTS ID AND JD ARE IDENTICAL: */
		i__4 = cibits_1.nmos;
		for (i__ = 1; i__ <= i__4; ++i__) {
/* L110: */
/* Computing 2nd power */
		    d__1 = civect_1.vectci[id - 1];
		    deltap[i__ + i__ * deltap_dim1] += (micros_1.microa[i__ + 
			    (id << 3) - 9] + micros_1.microb[i__ + (id << 3) 
			    - 9]) * (d__1 * d__1);
		}
	    }
L120:
	    ;
	}
    }

/*     BACK TRANSFORM INTO A.O. BASIS. */
/*     ------------------------------- */
/*     P(C.I.) = P(SCF) + C * DELTAP * C' */
    i__1 = cibits_1.nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* DIR$ IVDEP */
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
/* L130: */
	    deltap[j + i__ * deltap_dim1] = deltap[i__ + j * deltap_dim1];
	}
    }
/*     STEP 1: DELTAP = C * DELTAP */
    mxm_(&coeffs[(cibits_1.nelec + 1) * coeffs_dim1 + 1], norbs, &deltap[
	    deltap_offset], &cibits_1.nmos, &delta[delta_offset], &
	    cibits_1.nmos);
/*     STEP 2: P = P + DELTAP * C' */
    ij = 0;
    i__2 = *norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++ij;
	    sum = 0.;
	    i__4 = cibits_1.nmos;
	    for (k = 1; k <= i__4; ++k) {
/* L140: */
		sum += delta[i__ + k * delta_dim1] * coeffs[j + (
			cibits_1.nelec + k) * coeffs_dim1];
	    }
/* L150: */
	    densty_1.p[ij - 1] += sum;
	}
    }
/*     NOTE FROM D.L.: AT THIS POINT THE 'NATURAL ORBITALS' OF THIS STATE */
/*     CAN BE OBTAINED STRAIGHTWAY AS EIGENVECTORS OF THE DENSITY MATRIX. */
    return 0;
} /* mecip_ */

