/* h1elec.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct {
    doublereal htype[4];
    integer nhco[80]	/* was [4][20] */, nnhco, itype;
} molmec_;

#define molmec_1 molmec_

struct {
    doublereal beta3[153];
} beta3_;

#define beta3_1 beta3_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    doublereal vs[107], vp[107], vd[107];
} vsips_;

#define vsips_1 vsips_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    integer l1l, l2l, l3l, l1u, l2u, l3u;
} ucell_;

#define ucell_1 ucell_

/* Subroutine */ int h1elec_(integer *ni, integer *nj, doublereal *xi, 
	doublereal *xj, doublereal *smat)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal bi[9], bj[9];
    static integer ii;
    extern /* Subroutine */ int diat_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
#define lims ((integer *)&ucell_1)
    static doublereal xjuc[3];
    static integer nbond, norbi, norbj;
    static doublereal sbits[81]	/* was [9][9] */;

/* *********************************************************************** */

/*  H1ELEC FORMS THE ONE-ELECTRON MATRIX BETWEEN TWO ATOMS. */

/*   ON INPUT    NI   = ATOMIC NO. OF FIRST ATOM. */
/*               NJ   = ATOMIC NO. OF SECOND ATOM. */
/*               XI   = COORDINATES OF FIRST ATOM. */
/*               XJ   = COORDINATES OF SECOND ATOM. */

/*   ON OUTPUT   SMAT = MATRIX OF ONE-ELECTRON INTERACTIONS. */

/* *********************************************************************** */
    /* Parameter adjustments */
    smat -= 10;
    --xj;
    --xi;

    /* Function Body */
    if (*ni == 102 || *nj == 102) {
/* Computing 2nd power */
	d__1 = xi[1] - xj[1];
/* Computing 2nd power */
	d__2 = xi[2] - xj[2];
/* Computing 2nd power */
	d__3 = xi[3] - xj[3];
	if (sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) > 1.8f) {
	    for (i__ = 1; i__ <= 9; ++i__) {
		for (j = 1; j <= 9; ++j) {
/* L10: */
		    smat[i__ + j * 9] = 0.;
		}
	    }
	    return 0;
	}
    }
    if (euler_1.id == 0) {
	if (icalcn != numcal_1.numcal) {
	    icalcn = numcal_1.numcal;
	}
	diat_(ni, nj, &xi[1], &xj[1], &smat[10]);
    } else {
	if (icalcn != numcal_1.numcal) {
	    icalcn = numcal_1.numcal;
	    i__1 = euler_1.id;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		lims[i__ - 1] = -1;
/* L20: */
		lims[i__ + 2] = 1;
	    }
	    for (i__ = euler_1.id + 1; i__ <= 3; ++i__) {
		lims[i__ - 1] = 0;
/* L30: */
		lims[i__ + 2] = 0;
	    }
	}
	for (i__ = 1; i__ <= 9; ++i__) {
	    for (j = 1; j <= 9; ++j) {
/* L40: */
		smat[i__ + j * 9] = 0.;
	    }
	}
	i__1 = ucell_1.l1u;
	for (i__ = ucell_1.l1l; i__ <= i__1; ++i__) {
	    i__2 = ucell_1.l2u;
	    for (j = ucell_1.l2l; j <= i__2; ++j) {
		i__3 = ucell_1.l3u;
		for (k = ucell_1.l3l; k <= i__3; ++k) {
		    for (l = 1; l <= 3; ++l) {
/* L50: */
			xjuc[l - 1] = xj[l] + euler_1.tvec[l - 1] * i__ + 
				euler_1.tvec[l + 2] * j + euler_1.tvec[l + 5] 
				* k;
		    }
		    diat_(ni, nj, &xi[1], xjuc, sbits);
		    for (l = 1; l <= 9; ++l) {
			for (m = 1; m <= 9; ++m) {
/* L60: */
			    smat[l + m * 9] += sbits[l + m * 9 - 10];
			}
		    }
/* L70: */
		}
	    }
	}
    }
    if (molmec_1.itype != 4) {
	goto L80;
    }

/*     START OF MNDO, AM1, OR PM3 OPTION */

    ii = max(*ni,*nj);
    nbond = ii * (ii - 1) / 2 + *ni + *nj - ii;
    if (nbond > 153) {
	goto L90;
    }
    bi[0] = beta3_1.beta3[nbond - 1] * vsips_1.vs[*ni - 1];
    bi[1] = beta3_1.beta3[nbond - 1] * vsips_1.vp[*ni - 1];
    bi[2] = bi[1];
    bi[3] = bi[1];
    bj[0] = beta3_1.beta3[nbond - 1] * vsips_1.vs[*nj - 1];
    bj[1] = beta3_1.beta3[nbond - 1] * vsips_1.vp[*nj - 1];
    bj[2] = bj[1];
    bj[3] = bj[1];
    goto L90;
L80:
    bi[0] = betas_1.betas[*ni - 1] * .5;
    bi[1] = betas_1.betap[*ni - 1] * .5;
    bi[2] = bi[1];
    bi[3] = bi[1];
    bi[4] = betas_1.betad[*ni - 1] * .5;
    bi[5] = bi[4];
    bi[6] = bi[4];
    bi[7] = bi[4];
    bi[8] = bi[4];
    bj[0] = betas_1.betas[*nj - 1] * .5;
    bj[1] = betas_1.betap[*nj - 1] * .5;
    bj[2] = bj[1];
    bj[3] = bj[1];
    bj[4] = betas_1.betad[*nj - 1] * .5;
    bj[5] = bj[4];
    bj[6] = bj[4];
    bj[7] = bj[4];
    bj[8] = bj[4];
L90:
    norbi = natorb_1.natorb[*ni - 1];
    norbj = natorb_1.natorb[*nj - 1];
    if (norbi == 9 || norbj == 9) {

/*    IN THE CALCULATION OF THE ONE-ELECTRON TERMS THE GEOMETRIC MEAN */
/*    OF THE TWO BETA VALUES IS BEING USED IF ONE OF THE ATOMS */
/*    CONTAINS D-ORBITALS. */
	i__3 = norbj;
	for (j = 1; j <= i__3; ++j) {
	    i__2 = norbi;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L100: */
		smat[i__ + j * 9] = smat[i__ + j * 9] * -2. * sqrt(bi[i__ - 1]
			 * bj[j - 1]);
	    }
	}
    } else {
	i__2 = norbj;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = norbi;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L110: */
		smat[i__ + j * 9] *= bi[i__ - 1] + bj[j - 1];
	    }
	}
    }
    return 0;
} /* h1elec_ */

#undef lims


