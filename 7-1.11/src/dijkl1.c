/* dijkl1.f -- translated by f2c (version 20020621).
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
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

/* Subroutine */ int dijkl1_(doublereal *c__, integer *n, integer *nati, 
	doublereal *w, doublereal *cij, doublereal *wcij, doublereal *ckl)
{
    /* Initialized data */

    static integer nb[9] = { 1,0,0,10,0,0,0,0,45 };

    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3, i__4, i__5, i__6, i__7;

    /* Local variables */
    static integer i__, j, k, l, na, ii, i77, ll, ip, iq, kr, js, nbi, nbj, 
	    ipq;
    static doublereal sum;
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
/* *********************************************************************** */

/*   DIJKL1 IS SIMILAR TO IJKL.  THE MAIN DIFFERENCES ARE THAT */
/*   THE ARRAY W CONTAINS THE TWO ELECTRON INTEGRALS BETWEEN */
/*   ONE ATOM (NATI) AND ALL THE OTHER ATOMS IN THE SYSTEM. */

/*           ON EXIT */

/*   THE ARRAY XY IS FILLED WITH THE DIFFERENTIALS OF THE */
/*   TWO-ELECTRON INTEGRALS OVER ACTIVE-SPACE M.O.S W.R.T. MOTION */
/*   OF THE ATOM NATI. */
/* *********************************************************************** */
    /* Parameter adjustments */
    c_dim1 = *n;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    --w;
    --cij;
    --wcij;
    --ckl;

    /* Function Body */
    na = cibits_1.nmos;
    i__1 = na;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ipq = 0;
	    i__3 = molkst_1.numat;
	    for (ii = 1; ii <= i__3; ++ii) {
		if (ii == *nati) {
		    goto L20;
		}
		i__4 = molkst_1.nlast[ii - 1];
		for (ip = molkst_1.nfirst[ii - 1]; ip <= i__4; ++ip) {
		    i__5 = ip;
		    for (iq = molkst_1.nfirst[ii - 1]; iq <= i__5; ++iq) {
			++ipq;
			cij[ipq] = c__[ip + i__ * c_dim1] * c__[iq + j * 
				c_dim1] + c__[ip + j * c_dim1] * c__[iq + i__ 
				* c_dim1];
/* L10: */
		    }
		}
L20:
		;
	    }
	    i77 = ipq + 1;
	    i__3 = molkst_1.nlast[*nati - 1];
	    for (ip = molkst_1.nfirst[*nati - 1]; ip <= i__3; ++ip) {
		i__5 = ip;
		for (iq = molkst_1.nfirst[*nati - 1]; iq <= i__5; ++iq) {
		    ++ipq;
		    cij[ipq] = c__[ip + i__ * c_dim1] * c__[iq + j * c_dim1] 
			    + c__[ip + j * c_dim1] * c__[iq + i__ * c_dim1];
/* L30: */
		}
	    }
	    i__5 = ipq;
	    for (ii = 1; ii <= i__5; ++ii) {
/* L40: */
		wcij[ii] = 0.;
	    }
	    kr = 1;
	    js = 1;
	    nbj = nb[molkst_1.nlast[*nati - 1] - molkst_1.nfirst[*nati - 1]];
	    i__5 = molkst_1.numat;
	    for (ii = 1; ii <= i__5; ++ii) {
		if (ii == *nati) {
		    goto L50;
		}
		nbi = nb[molkst_1.nlast[ii - 1] - molkst_1.nfirst[ii - 1]];
		formxy_(&w[kr], &kr, &wcij[i77], &wcij[js], &cij[i77], &nbj, &
			cij[js], &nbi);
		js += nbi;
L50:
		;
	    }
	    i__5 = i__;
	    for (k = 1; k <= i__5; ++k) {
		if (k == i__) {
		    ll = j;
		} else {
		    ll = k;
		}
		i__3 = ll;
		for (l = 1; l <= i__3; ++l) {
		    ipq = 0;
		    i__4 = molkst_1.numat;
		    for (ii = 1; ii <= i__4; ++ii) {
			if (ii == *nati) {
			    goto L70;
			}
			i__6 = molkst_1.nlast[ii - 1];
			for (ip = molkst_1.nfirst[ii - 1]; ip <= i__6; ++ip) {
			    i__7 = ip;
			    for (iq = molkst_1.nfirst[ii - 1]; iq <= i__7; 
				    ++iq) {
				++ipq;
				ckl[ipq] = c__[ip + k * c_dim1] * c__[iq + l *
					 c_dim1] + c__[ip + l * c_dim1] * c__[
					iq + k * c_dim1];
/* L60: */
			    }
			}
L70:
			;
		    }
		    i__4 = molkst_1.nlast[*nati - 1];
		    for (ip = molkst_1.nfirst[*nati - 1]; ip <= i__4; ++ip) {
			i__7 = ip;
			for (iq = molkst_1.nfirst[*nati - 1]; iq <= i__7; 
				++iq) {
			    ++ipq;
			    ckl[ipq] = c__[ip + k * c_dim1] * c__[iq + l * 
				    c_dim1] + c__[ip + l * c_dim1] * c__[iq + 
				    k * c_dim1];
/* L80: */
			}
		    }
		    sum = 0.;
		    i__7 = ipq;
		    for (ii = 1; ii <= i__7; ++ii) {
/* L90: */
			sum += ckl[ii] * wcij[ii];
		    }
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
		    xyijkl_1.xy[l + (k + (j + (i__ << 3) << 3) << 3) - 585] = 
			    sum;
/* L100: */
		}
	    }
/* L110: */
	}
    }
    return 0;
} /* dijkl1_ */

