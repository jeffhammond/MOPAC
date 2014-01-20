/* diegrd.f -- translated by f2c (version 20020621).
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
	    was [3][1082] */, qs[400];
} solv_;

#define solv_1 solv_

struct {
    integer iatsp[401], nar[400], nnx[240]	/* was [2][120] */;
} solvi_;

#define solvi_1 solvi_

struct {
    doublereal dirvec[3246]	/* was [3][1082] */;
    integer nn[360]	/* was [3][120] */;
} dirvec_;

#define dirvec_1 dirvec_

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

/* Table of constant values */

static doublereal c_b13 = -1.5;

/* Subroutine */ int diegrd_(doublereal *coord, doublereal *dxyz)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l, i0, i1, i2;
    static doublereal db[40]	/* was [4][10] */, ff, ri, dx, rm, xk[3], xl[
	    3];
    static integer ix;
    static doublereal xx[3], ff0, rm2, rm4, ddi;
    static integer iak, ial;
    static doublereal qsk, xxx, qqi2, fact;
    static integer idel, iden, nati;
    static doublereal posi, dist2;
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
    /* Parameter adjustments */
    dxyz -= 4;
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
    for (i__ = 1; i__ <= 10; ++i__) {
	for (ix = 1; ix <= 3; ++ix) {
/* L20: */
	    db[ix + (i__ << 2) - 4] = 0.;
	}
    }
    db[0] = 1.;
    cqden_();
    fact = solv_1.fepsi * -14.400378720000001 * 23.061;
    i__1 = solv_1.nps;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	solv_1.qs[i__ - 1] = 0.;
    }
    i0 = solv_1.nps2 - solv_1.nden;
    i__1 = solv_1.nps;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i2 = i__ * (i__ - 1) / 2;
	i1 = i0 + i__ * solv_1.nden;
	posi = 0.;
	i__2 = solv_1.nden;
	for (j = 1; j <= i__2; ++j) {
/* L40: */
	    posi += solv_1.qden[j - 1] * solv_1.abcmat[j + i1 - 1];
	}
	i__2 = i__;
	for (k = 1; k <= i__2; ++k) {
/* L50: */
	    solv_1.qs[k - 1] += posi * solv_1.abcmat[k + i2 - 1];
	}
	i__2 = solv_1.nps;
	for (k = i__ + 1; k <= i__2; ++k) {
/* L60: */
	    solv_1.qs[k - 1] += posi * solv_1.abcmat[i__ + k * (k - 1) / 2 - 
		    1];
	}
/* L70: */
    }
    i__1 = solv_1.nps;
    for (k = 1; k <= i__1; ++k) {
	iak = solvi_1.iatsp[k - 1];
	for (ix = 1; ix <= 3; ++ix) {
/* L80: */
	    xk[ix - 1] = solv_1.cosurf[ix + k * 3 - 4];
	}
	qsk = solv_1.qs[k - 1];
	i__2 = k - 1;
	for (l = 1; l <= i__2; ++l) {
	    ial = solvi_1.iatsp[l - 1];
	    if (ial == iak) {
		goto L110;
	    }
	    dist2 = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
		xxx = solv_1.cosurf[ix + l * 3 - 4] - xk[ix - 1];
		xl[ix - 1] = xxx;
		dist2 += xxx * xxx;
/* L90: */
	    }
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*           FF=QSK*QS(L)*FACT*DIST2**-1.5D0 */
	    ff = qsk * solv_1.qs[l - 1] * fact * pow_dd(&dist2, &c_b13);
/* ***************************** at 1994-05-25 ***** */
	    for (ix = 1; ix <= 3; ++ix) {
		dxyz[ix + iak * 3] -= xl[ix - 1] * ff;
		dxyz[ix + ial * 3] += xl[ix - 1] * ff;
/* L100: */
	    }
L110:
	    ;
	}
/* L120: */
    }
    i__1 = solv_1.nps;
    for (k = 1; k <= i__1; ++k) {
	iak = solvi_1.iatsp[k - 1];
	for (ix = 1; ix <= 3; ++ix) {
/* L130: */
	    xk[ix - 1] = solv_1.cosurf[ix + k * 3 - 4];
	}
	qsk = solv_1.qs[k - 1];
	iden = 0;
	i__2 = molkst_1.numat;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    idel = molkst_1.nlast[i__ - 1] - molkst_1.nfirst[i__ - 1];
	    if (i__ == iak) {
		goto L180;
	    }
	    nati = molkst_1.nat[i__ - 1];
	    dist2 = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
		xxx = xk[ix - 1] - coord[ix + i__ * 3];
		xx[ix - 1] = xxx;
		dist2 += xxx * xxx;
/* L140: */
	    }
	    ddi = multip_1.dd[nati - 1] * 2 * .529177;
/* Computing 2nd power */
	    d__1 = multip_1.qq[nati - 1] * .529177;
	    qqi2 = d__1 * d__1;
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*           FF0=-QSK*FACT*DIST2**-1.5D0 */
	    ff0 = -qsk * fact * pow_dd(&dist2, &c_b13);
/* ***************************** at 1994-05-25 ***** */
	    if (idel == 0) {
		goto L150;
	    }
	    rm2 = 1. / dist2;
/* Computing 2nd power */
	    d__1 = rm2;
	    rm4 = d__1 * d__1;
	    db[4] = ddi * 3 * xx[0] * rm2;
	    db[12] = ddi * 3 * xx[1] * rm2;
	    db[24] = ddi * 3 * xx[2] * rm2;
/* Computing 2nd power */
	    d__1 = xx[0];
	    db[8] = qqi2 * (d__1 * d__1 * 15 * rm2 - 3.) * rm2 + 1.;
/* Computing 2nd power */
	    d__1 = xx[1];
	    db[20] = qqi2 * (d__1 * d__1 * 15 * rm2 - 3.) * rm2 + 1.;
/* Computing 2nd power */
	    d__1 = xx[2];
	    db[36] = qqi2 * (d__1 * d__1 * 15 * rm2 - 3.) * rm2 + 1.;
	    db[16] = qqi2 * 30 * xx[0] * xx[1] * rm4;
	    db[28] = qqi2 * 30 * xx[0] * xx[2] * rm4;
	    db[32] = qqi2 * 30 * xx[2] * xx[1] * rm4;
	    db[5] = ddi;
	    db[14] = db[5];
	    db[27] = db[5];
	    db[9] = qqi2 * 6 * xx[0] * rm2;
	    db[22] = qqi2 * 6 * xx[1] * rm2;
	    db[39] = qqi2 * 6 * xx[2] * rm2;
	    db[17] = db[22];
	    db[18] = db[9];
	    db[29] = db[39];
	    db[31] = db[9];
	    db[34] = db[39];
	    db[35] = db[22];
L150:
	    i__3 = idel * idel + 1;
	    for (j = 1; j <= i__3; ++j) {
		ff = ff0 * solv_1.qden[iden + j - 1];
		for (ix = 1; ix <= 3; ++ix) {
		    dx = (xx[ix - 1] * db[(j << 2) - 4] - db[ix + (j << 2) - 
			    4]) * ff;
		    dxyz[ix + iak * 3] += dx;
		    dxyz[ix + i__ * 3] -= dx;
/* L160: */
		}
/* L170: */
	    }
L180:
/* Computing 2nd power */
	    i__3 = idel;
	    iden = iden + 1 + i__3 * i__3;
	}
/* L190: */
    }
    i__1 = solv_1.nps;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = solvi_1.iatsp[i__ - 1];
	rm = solv_1.srad[j - 1] - solv_1.rds;
	for (ix = 1; ix <= 3; ++ix) {
/* L200: */
	    solv_1.cosurf[ix + i__ * 3 - 4] = (solv_1.cosurf[ix + i__ * 3 - 4]
		     - coord[ix + j * 3]) / rm;
	}
    }
    return 0;
} /* diegrd_ */

