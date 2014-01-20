/* ijkl.f -- translated by f2c (version 20020621).
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
    doublereal dumy1[90300], cij[3000], wcij[3000], dumy[84300];
} vector_;

#define vector_1 vector_

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

/* Subroutine */ int ijkl_(doublereal *cp, doublereal *cf, integer *nelec, 
	integer *nmos, doublereal *dijkl)
{

    /* System generated locals */
    integer cp_dim1, cp_offset, cf_dim1, cf_offset, dijkl_dim1, dijkl_dim2, 
	    dijkl_offset, i__1, i__2, i__3, i__4, i__5, i__6, i__7;

    /* Local variables */
    static integer i__, j, k, l, ii, ij, kk, ip, iq;
#define ckl ((doublereal *)&vector_1 + 90300)
    static integer ipq;
    static doublereal sum;
    extern /* Subroutine */ int partxy_(doublereal *, doublereal *);

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

/*   IJKL FILLS THE XY ARRAY.  XY HOLDS THE TWO-ELECTRON INTEGRALS OVER */
/*        MOLECULAR ORBITALS IN THE ACTIVE SPACE. */
/*        XY(I,J,K,L) = <IJ|1/R(1,2)|KL> */

/*           ON INPUT */

/* CP     = M.O.'S OVER C.I. ACTIVE SPACE (NORMALLY 1 TO 5 M.O.S) */
/* CF     = ALL M.O.'S, INCLUDING THOSE IN CP */
/* NORBS  = NUMBER OF ATOMIC ORBITALS */
/* NELEC  = NUMBER OF OCCUPIED M.O.S NOT INVOLVED IN THE C.I. */
/* NMOS   = NUMBER OF M.O.S INVOLVED IN THE C.I. (NORMALLY 1 TO 5 M.O.S) */
/*          ALSO CALLED THE ACTIVE SPACE OF THE C.I. */

/*  NOTE: THIS SUBROUTINE IS UNUSUAL IN THAT ONE FUNCTION IS TO */
/*        FILL THE ARRAY XY WHICH IS NOT PASSED AS AN ARGUMENT, */
/*        INSTEAD IT IS PASSED VIA COMMON BLOCK XYIJKL. */

/* *********************************************************************** */
    /* Parameter adjustments */
    cf_dim1 = molkst_1.norbs;
    cf_offset = 1 + cf_dim1 * 1;
    cf -= cf_offset;
    dijkl_dim1 = molkst_1.norbs;
    dijkl_dim2 = *nmos;
    dijkl_offset = 1 + dijkl_dim1 * (1 + dijkl_dim2 * 1);
    dijkl -= dijkl_offset;
    cp_dim1 = molkst_1.norbs;
    cp_offset = 1 + cp_dim1 * 1;
    cp -= cp_offset;

    /* Function Body */

/*  CALCULATE TWO-ELECTRON INTEGRALS FOR THE SET DIJKL(K,L,IJ) */
/*  THE INDEX K RUNS OVER ALL M.O.'S, L OVER ACTIVE-SPACE M.O.'S, */
/*  AND IJ OVER LOWER-HALF TRIANGLE OF ACTIVE-SPACE M.O.'S, J FASTER THAN */
/*  I. */
/*  ALL ACTIVE-SPACE INTERACTIONS ARE COPIED INTO THE ARRAY XY */

    ij = 0;
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++ij;
	    ipq = 0;
	    i__3 = molkst_1.numat;
	    for (ii = 1; ii <= i__3; ++ii) {
		i__4 = molkst_1.nlast[ii - 1];
		for (ip = molkst_1.nfirst[ii - 1]; ip <= i__4; ++ip) {
		    i__5 = ip;
		    for (iq = molkst_1.nfirst[ii - 1]; iq <= i__5; ++iq) {
			++ipq;
/* L10: */
			vector_1.cij[ipq - 1] = cp[ip + i__ * cp_dim1] * cp[
				iq + j * cp_dim1] + cp[ip + j * cp_dim1] * cp[
				iq + i__ * cp_dim1];
		    }
		}
	    }

/*  CIJ HOLDS THE DENSITY DISTRIBUTION PSI(I)*PSI(J) OVER ATOMIC BASES */
/*  I AND J ARE M.O. INDICES WITHIN THE ACTIVE SPACE.  CIJ(M,N) IS FOR */
/*  THE ATOMIC BASES M AND N FOR M.O.'S I AND J. */

	    partxy_(vector_1.cij, vector_1.wcij);

/* WCIJ HOLDS THE KET PART OF THE INTEGRAL <K,L|1/R(1,2)|I,J> */
/* THAT IS, |1/R(1,2)|I,J>.  WCIJ(M,N) IS FOR THE ATOMIC BASES M AND N */
/* FOR M.O.'S K AND L. */

/* L20: */
	    i__5 = molkst_1.norbs;
	    for (k = 1; k <= i__5; ++k) {
		i__4 = *nmos;
		for (l = 1; l <= i__4; ++l) {

/*  ABOUT TO CALCULATE <I,J|1/R(1,2)|K,L> */

		    ipq = 0;
		    i__3 = molkst_1.numat;
		    for (ii = 1; ii <= i__3; ++ii) {
			i__6 = molkst_1.nlast[ii - 1];
			for (ip = molkst_1.nfirst[ii - 1]; ip <= i__6; ++ip) {
			    i__7 = ip;
			    for (iq = molkst_1.nfirst[ii - 1]; iq <= i__7; 
				    ++iq) {
				++ipq;
/* L30: */
				ckl[ipq - 1] = cf[ip + k * cf_dim1] * cp[iq + 
					l * cp_dim1] + cp[ip + l * cp_dim1] * 
					cf[iq + k * cf_dim1];
			    }
			}
		    }

/* CKL HOLDS THE DENSITY DISTRIBUTION PSI(K)*PSI(L) OVER ATOMIC BASES. */
/* K IS THE INDEX OF A M.O.; L IS AN INDEX OF A M.O. IN THE ACTIVE SPACE. */

		    sum = 0.;
		    i__7 = ipq;
		    for (ii = 1; ii <= i__7; ++ii) {
/* L40: */
			sum += ckl[ii - 1] * vector_1.wcij[ii - 1];
		    }

/*  SUM IS THE INTEGRAL <I,J|1/R(1,2)|K,L> */

		    dijkl[k + (l + ij * dijkl_dim2) * dijkl_dim1] = sum;
/* L50: */
		}
/* L60: */
	    }
/* L70: */
	}
    }

/*  NOW SPREAD THE INTEGRALS OVER THE XY ARRAY.  XY IS ENTIRELY */
/*  IN ACTIVE SPACE */

    i__2 = *nmos;
    for (k = 1; k <= i__2; ++k) {
	kk = *nelec + k;

/*  K IS A M.O. INDEX IN ACTIVE SPACE */
/* KK IS A M.O. INDEX */

	i__1 = *nmos;
	for (l = 1; l <= i__1; ++l) {
	    ij = 0;
	    i__5 = *nmos;
	    for (i__ = 1; i__ <= i__5; ++i__) {
		i__4 = i__;
		for (j = 1; j <= i__4; ++j) {
		    ++ij;
		    sum = dijkl[kk + (l + ij * dijkl_dim2) * dijkl_dim1];
		    xyijkl_1.xy[i__ + (j + (k + (l << 3) << 3) << 3) - 585] = 
			    sum;
		    xyijkl_1.xy[i__ + (j + (l + (k << 3) << 3) << 3) - 585] = 
			    sum;
		    xyijkl_1.xy[j + (i__ + (k + (l << 3) << 3) << 3) - 585] = 
			    sum;
		    xyijkl_1.xy[j + (i__ + (l + (k << 3) << 3) << 3) - 585] = 
			    sum;
		    xyijkl_1.xy[k + (l + (i__ + (j << 3) << 3) << 3) - 585] = 
			    sum;
		    xyijkl_1.xy[k + (l + (j + (i__ << 3) << 3) << 3) - 585] = 
			    sum;
		    xyijkl_1.xy[l + (k + (i__ + (j << 3) << 3) << 3) - 585] = 
			    sum;
/* L80: */
		}
	    }
	}
    }
    return 0;
} /* ijkl_ */

#undef ckl


