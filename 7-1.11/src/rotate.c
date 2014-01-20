/* rotate.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal htype[4];
    integer nhco[80]	/* was [4][20] */, nnhco, itype;
} molmec_;

#define molmec_1 molmec_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

struct {
    doublereal f03[107];
} twoel3_;

#define twoel3_1 twoel3_

struct {
    doublereal alp3[153];
} alpha3_;

#define alpha3_1 alpha3_

struct {
    doublereal alp[107];
} alpha_;

#define alpha_1 alpha_

struct {
    doublereal tore[107];
} core_;

#define core_1 core_

struct {
    doublereal fn1[1070]	/* was [107][10] */, fn2[1070]	/* was [107][
	    10] */, fn3[1070]	/* was [107][10] */;
} ideas_;

#define ideas_1 ideas_

struct {
    doublereal alptm[30], emudtm[30];
} alptm_;

#define alptm_1 alptm_

struct {
    doublereal css1, csp1, cpps1, cppp1, css2, csp2, cpps2, cppp2;
} rotdum_;

#define rotdum_1 rotdum_

struct {
    doublereal x[3], y[3], z__[3];
} rotdu2_;

#define rotdu2_1 rotdu2_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b9 = 1.;

/* Subroutine */ int rotate_(integer *ni, integer *nj, doublereal *xi, 
	doublereal *xj, doublereal *w, integer *kr, doublereal *e1b, 
	doublereal *e2a, doublereal *enuc, doublereal *cutoff)
{
    /* Initialized data */

    static integer icalcn = 0;
    static doublereal boron1[12]	/* was [3][4] */ = { .182613,.118587,
	    -.07328,.412253,-.149917,0.,.261751,.050275,0.,.359244,.074729,0. 
	    };
    static doublereal boron2[12]	/* was [3][4] */ = { 6.,6.,5.,10.,6.,
	    0.,8.,5.,0.,9.,9.,0. };
    static doublereal boron3[12]	/* was [3][4] */ = { .727592,1.466639,
	    1.570975,.832586,1.18622,0.,1.063995,1.936492,0.,.819351,1.574414,
	    0. };

    /* System generated locals */
    doublereal d__1, d__2;
    olist o__1;
    alist al__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), f_open(olist *), f_rew(
	    alist *);
    double sqrt(doublereal), exp(doublereal);
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void);
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal a;
    static integer i__, l, ig, ii, ki, nk, nl;
    static doublereal ri[22];
    static logical si, sj;
    static doublereal ax;
    static integer nt;
    static doublereal gam, rij, xx11, xx21, xx22, sum, xx31, xx32, xx33, yy11,
	     yy21, yy22, zz11, zz21, zz22, zz31, zz32, zz33, xy11, xy21, xy22,
	     xy31, xy32, xz11, xz21, xz22, xz31, xz32, xz33, yz11, yz21, yz22,
	     yz31, yz32;
    extern /* Subroutine */ int repp_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
    static doublereal rijx, scale;
#define ccore ((doublereal *)&rotdum_1)
    static integer nbond;
    static doublereal yyzz11, yyzz21, yyzz22;
    static logical analyt;

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 2, 0, 0, 0 };


/* *********************************************************************** */

/* ..IMPROVED SCALAR VERSION */
/* ..WRITTEN BY ERNEST R. DAVIDSON, INDIANA UNIVERSITY. */


/*   ROTATE CALCULATES THE TWO-PARTICLE INTERACTIONS. */

/*   ON INPUT  NI     = ATOMIC NUMBER OF FIRST ATOM. */
/*             NJ     = ATOMIC NUMBER OF SECOND ATOM. */
/*             XI     = COORDINATE OF FIRST ATOM. */
/*             XJ     = COORDINATE OF SECOND ATOM. */

/* ON OUTPUT W      = ARRAY OF TWO-ELECTRON REPULSION INTEGRALS. */
/*           E1B,E2A= ARRAY OF ELECTRON-NUCLEAR ATTRACTION INTEGRALS, */
/*                    E1B = ELECTRON ON ATOM NI ATTRACTING NUCLEUS OF NJ. */
/*           ENUC   = NUCLEAR-NUCLEAR REPULSION TERM. */


/* *** THIS ROUTINE COMPUTES THE REPULSION AND NUCLEAR ATTRACTION */
/*     INTEGRALS OVER MOLECULAR-FRAME COORDINATES.  THE INTEGRALS OVER */
/*     LOCAL FRAME COORDINATES ARE EVALUATED BY SUBROUTINE REPP AND */
/*     STORED AS FOLLOWS (WHERE P-SIGMA = O,   AND P-PI = P AND P* ) */
/*     IN RI */
/*     (SS/SS)=1,   (SO/SS)=2,   (OO/SS)=3,   (PP/SS)=4,   (SS/OS)=5, */
/*     (SO/SO)=6,   (SP/SP)=7,   (OO/SO)=8,   (PP/SO)=9,   (PO/SP)=10, */
/*     (SS/OO)=11,  (SS/PP)=12,  (SO/OO)=13,  (SO/PP)=14,  (SP/OP)=15, */
/*     (OO/OO)=16,  (PP/OO)=17,  (OO/PP)=18,  (PP/PP)=19,  (PO/PO)=20, */
/*     (PP/P*P*)=21,   (P*P/P*P)=22. */

/* *********************************************************************** */
    /* Parameter adjustments */
    --e2a;
    --e1b;
    --w;
    --xj;
    --xi;

    /* Function Body */

    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	analyt = i_indx(keywrd_1.keywrd, "ANALYT", (ftnlen)241, (ftnlen)6) != 
		0;
	if (analyt) {
	    o__1.oerr = 0;
	    o__1.ounit = 2;
	    o__1.ofnm = 0;
	    o__1.orl = 0;
	    o__1.osta = "SCRATCH";
	    o__1.oacc = 0;
	    o__1.ofm = "UNFORMATTED";
	    o__1.oblnk = 0;
	    f_open(&o__1);
	    al__1.aerr = 0;
	    al__1.aunit = 2;
	    f_rew(&al__1);
	}
    }

    rotdu2_1.x[0] = xi[1] - xj[1];
    rotdu2_1.x[1] = xi[2] - xj[2];
    rotdu2_1.x[2] = xi[3] - xj[3];
    rij = rotdu2_1.x[0] * rotdu2_1.x[0] + rotdu2_1.x[1] * rotdu2_1.x[1] + 
	    rotdu2_1.x[2] * rotdu2_1.x[2];
    if (rij < 2e-5) {

/*     SMALL RIJ CASE */

	for (i__ = 1; i__ <= 10; ++i__) {
	    e1b[i__] = 0.;
	    e2a[i__] = 0.;
/* L10: */
	}
	w[*kr] = 0.;
	*enuc = 0.;

    } else if (molmec_1.itype == 4) {

/*     MINDO CASE */

/* Computing 2nd power */
	d__1 = 7.1995 / twoel3_1.f03[*ni - 1] + 7.1995 / twoel3_1.f03[*nj - 1]
		;
	sum = 14.399 / sqrt(rij + d__1 * d__1);
	w[1] = sum;
	++(*kr);
	for (l = 1; l <= 10; ++l) {
	    e1b[l] = 0.;
	    e2a[l] = 0.;
/* L20: */
	}
	e1b[1] = -sum * core_1.tore[*nj - 1];
	e1b[3] = e1b[1];
	e1b[6] = e1b[1];
	e1b[10] = e1b[1];
	e2a[1] = -sum * core_1.tore[*ni - 1];
	e2a[3] = e2a[1];
	e2a[6] = e2a[1];
	e2a[10] = e2a[1];
	ii = max(*ni,*nj);
	nbond = ii * (ii - 1) / 2 + *ni + *nj - ii;
	rij = sqrt(rij);
	if (nbond < 154) {
	    if (nbond == 22 || nbond == 29) {
/*              NBOND = 22 IS C-H CASE */
/*              NBOND = 29 IS N-H CASE */
		scale = alpha3_1.alp3[nbond - 1] * exp(-rij);
	    } else {
/*              NBOND < 154  IS NI < 18 AND NJ < 18 CASE */
		scale = exp(-alpha3_1.alp3[nbond - 1] * rij);
	    }
	} else {
/*              NBOND > 154 INVOLVES NI OR NJ > 18 */
	    scale = 0.;
	    if (natorb_1.natorb[*ni - 1] == 0) {
		scale = exp(-alpha_1.alp[*ni - 1] * rij);
	    }
	    if (natorb_1.natorb[*nj - 1] == 0) {
		scale += exp(-alpha_1.alp[*ni - 1] * rij);
	    }
	}
	if ((d__1 = core_1.tore[*ni - 1], abs(d__1)) > 20. && (d__2 = 
		core_1.tore[*nj - 1], abs(d__2)) > 20.) {
	    *enuc = 0.;
	} else if (rij < 1. && natorb_1.natorb[*ni - 1] * natorb_1.natorb[*nj 
		- 1] == 0) {
	    *enuc = 0.;
	} else {
	    *enuc = core_1.tore[*ni - 1] * core_1.tore[*nj - 1] * sum + (d__1 
		    = core_1.tore[*ni - 1] * core_1.tore[*nj - 1] * (14.399 / 
		    rij - sum) * scale, abs(d__1));
	}

/*     MNDO AND AM1 CASES */

/* *** THE REPULSION INTEGRALS OVER MOLECULAR FRAME (W) ARE STORED IN THE */
/*     ORDER IN WHICH THEY WILL LATER BE USED.  IE.  (I,J/K,L) WHERE */
/*     J.LE.I  AND  L.LE.K     AND L VARIES MOST RAPIDLY AND I LEAST */
/*     RAPIDLY.  (ANTI-NORMAL COMPUTER STORAGE) */

    } else {

	rijx = sqrt(rij);
	rij = min(rijx,*cutoff);

/* *** COMPUTE INTEGRALS IN DIATOMIC FRAME */

	repp_(ni, nj, &rij, ri, ccore);
	if (analyt) {
	    s_wsue(&io___16);
	    for (i__ = 1; i__ <= 22; ++i__) {
		do_uio(&c__1, (char *)&ri[i__ - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_wsue();
	}

	gam = ri[0];
	a = 1. / rijx;
	rotdu2_1.x[0] *= a;
	rotdu2_1.x[1] *= a;
	rotdu2_1.x[2] *= a;
	if (abs(rotdu2_1.x[2]) > .99999999) {
	    rotdu2_1.x[2] = d_sign(&c_b9, &rotdu2_1.x[2]);
	    rotdu2_1.y[0] = 0.;
	    rotdu2_1.y[1] = 1.;
	    rotdu2_1.y[2] = 0.;
	    rotdu2_1.z__[0] = 1.;
	    rotdu2_1.z__[1] = 0.;
	    rotdu2_1.z__[2] = 0.;
	} else {
	    rotdu2_1.z__[2] = sqrt(1. - rotdu2_1.x[2] * rotdu2_1.x[2]);
	    a = 1. / rotdu2_1.z__[2];
	    rotdu2_1.y[0] = -a * rotdu2_1.x[1] * d_sign(&c_b9, rotdu2_1.x);
	    rotdu2_1.y[1] = (d__1 = a * rotdu2_1.x[0], abs(d__1));
	    rotdu2_1.y[2] = 0.;
	    rotdu2_1.z__[0] = -a * rotdu2_1.x[0] * rotdu2_1.x[2];
	    rotdu2_1.z__[1] = -a * rotdu2_1.x[1] * rotdu2_1.x[2];
	}
	si = natorb_1.natorb[*ni - 1] > 1;
	sj = natorb_1.natorb[*nj - 1] > 1;
	if (si || sj) {
	    xx11 = rotdu2_1.x[0] * rotdu2_1.x[0];
	    xx21 = rotdu2_1.x[1] * rotdu2_1.x[0];
	    xx22 = rotdu2_1.x[1] * rotdu2_1.x[1];
	    xx31 = rotdu2_1.x[2] * rotdu2_1.x[0];
	    xx32 = rotdu2_1.x[2] * rotdu2_1.x[1];
	    xx33 = rotdu2_1.x[2] * rotdu2_1.x[2];
	    yy11 = rotdu2_1.y[0] * rotdu2_1.y[0];
	    yy21 = rotdu2_1.y[1] * rotdu2_1.y[0];
	    yy22 = rotdu2_1.y[1] * rotdu2_1.y[1];
	    zz11 = rotdu2_1.z__[0] * rotdu2_1.z__[0];
	    zz21 = rotdu2_1.z__[1] * rotdu2_1.z__[0];
	    zz22 = rotdu2_1.z__[1] * rotdu2_1.z__[1];
	    zz31 = rotdu2_1.z__[2] * rotdu2_1.z__[0];
	    zz32 = rotdu2_1.z__[2] * rotdu2_1.z__[1];
	    zz33 = rotdu2_1.z__[2] * rotdu2_1.z__[2];
	    yyzz11 = yy11 + zz11;
	    yyzz21 = yy21 + zz21;
	    yyzz22 = yy22 + zz22;
	    xy11 = rotdu2_1.x[0] * 2. * rotdu2_1.y[0];
	    xy21 = rotdu2_1.x[0] * rotdu2_1.y[1] + rotdu2_1.x[1] * rotdu2_1.y[
		    0];
	    xy22 = rotdu2_1.x[1] * 2. * rotdu2_1.y[1];
	    xy31 = rotdu2_1.x[2] * rotdu2_1.y[0];
	    xy32 = rotdu2_1.x[2] * rotdu2_1.y[1];
	    xz11 = rotdu2_1.x[0] * 2. * rotdu2_1.z__[0];
	    xz21 = rotdu2_1.x[0] * rotdu2_1.z__[1] + rotdu2_1.x[1] * 
		    rotdu2_1.z__[0];
	    xz22 = rotdu2_1.x[1] * 2. * rotdu2_1.z__[1];
	    xz31 = rotdu2_1.x[0] * rotdu2_1.z__[2] + rotdu2_1.x[2] * 
		    rotdu2_1.z__[0];
	    xz32 = rotdu2_1.x[1] * rotdu2_1.z__[2] + rotdu2_1.x[2] * 
		    rotdu2_1.z__[1];
	    xz33 = rotdu2_1.x[2] * 2. * rotdu2_1.z__[2];
	    yz11 = rotdu2_1.y[0] * 2. * rotdu2_1.z__[0];
	    yz21 = rotdu2_1.y[0] * rotdu2_1.z__[1] + rotdu2_1.y[1] * 
		    rotdu2_1.z__[0];
	    yz22 = rotdu2_1.y[1] * 2. * rotdu2_1.z__[1];
	    yz31 = rotdu2_1.y[0] * rotdu2_1.z__[2];
	    yz32 = rotdu2_1.y[1] * rotdu2_1.z__[2];
	}

/*     (S S/S S) */
	w[1] = ri[0];
	ki = 1;
	if (sj) {
/*     (S S/PX S) */
	    w[2] = ri[4] * rotdu2_1.x[0];
/*     (S S/PX PX) */
	    w[3] = ri[10] * xx11 + ri[11] * yyzz11;
/*     (S S/PY S) */
	    w[4] = ri[4] * rotdu2_1.x[1];
/*     (S S/PY PX) */
	    w[5] = ri[10] * xx21 + ri[11] * yyzz21;
/*     (S S/PY PY) */
	    w[6] = ri[10] * xx22 + ri[11] * yyzz22;
/*     (S S/PZ S) */
	    w[7] = ri[4] * rotdu2_1.x[2];
/*     (S S/PZ PX) */
	    w[8] = ri[10] * xx31 + ri[11] * zz31;
/*     (S S/PZ PY) */
	    w[9] = ri[10] * xx32 + ri[11] * zz32;
/*     (S S/PZ PZ) */
	    w[10] = ri[10] * xx33 + ri[11] * zz33;
	    ki = 10;
	}

	if (si) {
/*     (PX S/S S) */
	    w[11] = ri[1] * rotdu2_1.x[0];
	    if (sj) {
/*     (PX S/PX S) */
		w[12] = ri[5] * xx11 + ri[6] * yyzz11;
/*     (PX S/PX PX) */
		w[13] = rotdu2_1.x[0] * (ri[12] * xx11 + ri[13] * yyzz11) + 
			ri[14] * (rotdu2_1.y[0] * xy11 + rotdu2_1.z__[0] * 
			xz11);
/*     (PX S/PY S) */
		w[14] = ri[5] * xx21 + ri[6] * yyzz21;
/*     (PX S/PY PX) */
		w[15] = rotdu2_1.x[0] * (ri[12] * xx21 + ri[13] * yyzz21) + 
			ri[14] * (rotdu2_1.y[0] * xy21 + rotdu2_1.z__[0] * 
			xz21);
/*     (PX S/PY PY) */
		w[16] = rotdu2_1.x[0] * (ri[12] * xx22 + ri[13] * yyzz22) + 
			ri[14] * (rotdu2_1.y[0] * xy22 + rotdu2_1.z__[0] * 
			xz22);
/*     (PX S/PZ S) */
		w[17] = ri[5] * xx31 + ri[6] * zz31;
/*     (PX S/PZ PX) */
		w[18] = rotdu2_1.x[0] * (ri[12] * xx31 + ri[13] * zz31) + ri[
			14] * (rotdu2_1.y[0] * xy31 + rotdu2_1.z__[0] * xz31);
/*     (PX S/PZ PY) */
		w[19] = rotdu2_1.x[0] * (ri[12] * xx32 + ri[13] * zz32) + ri[
			14] * (rotdu2_1.y[0] * xy32 + rotdu2_1.z__[0] * xz32);
/*     (PX S/PZ PZ) */
		w[20] = rotdu2_1.x[0] * (ri[12] * xx33 + ri[13] * zz33) + ri[
			14] * (rotdu2_1.z__[0] * xz33);
/*     (PX PX/S S) */
		w[21] = ri[2] * xx11 + ri[3] * yyzz11;
/*     (PX PX/PX S) */
		w[22] = rotdu2_1.x[0] * (ri[7] * xx11 + ri[8] * yyzz11) + ri[
			9] * (rotdu2_1.y[0] * xy11 + rotdu2_1.z__[0] * xz11);
/*     (PX PX/PX PX) */
		w[23] = (ri[15] * xx11 + ri[16] * yyzz11) * xx11 + ri[17] * 
			xx11 * yyzz11 + ri[18] * (yy11 * yy11 + zz11 * zz11) 
			+ ri[19] * (xy11 * xy11 + xz11 * xz11) + ri[20] * (
			yy11 * zz11 + zz11 * yy11) + ri[21] * yz11 * yz11;
/*     (PX PX/PY S) */
		w[24] = rotdu2_1.x[1] * (ri[7] * xx11 + ri[8] * yyzz11) + ri[
			9] * (rotdu2_1.y[1] * xy11 + rotdu2_1.z__[1] * xz11);
/*     (PX PX/PY PX) */
		w[25] = (ri[15] * xx11 + ri[16] * yyzz11) * xx21 + ri[17] * 
			xx11 * yyzz21 + ri[18] * (yy11 * yy21 + zz11 * zz21) 
			+ ri[19] * (xy11 * xy21 + xz11 * xz21) + ri[20] * (
			yy11 * zz21 + zz11 * yy21) + ri[21] * yz11 * yz21;
/*     (PX PX/PY PY) */
		w[26] = (ri[15] * xx11 + ri[16] * yyzz11) * xx22 + ri[17] * 
			xx11 * yyzz22 + ri[18] * (yy11 * yy22 + zz11 * zz22) 
			+ ri[19] * (xy11 * xy22 + xz11 * xz22) + ri[20] * (
			yy11 * zz22 + zz11 * yy22) + ri[21] * yz11 * yz22;
/*     (PX PX/PZ S) */
		w[27] = rotdu2_1.x[2] * (ri[7] * xx11 + ri[8] * yyzz11) + ri[
			9] * (rotdu2_1.z__[2] * xz11);
/*     (PX PX/PZ PX) */
		w[28] = (ri[15] * xx11 + ri[16] * yyzz11) * xx31 + (ri[17] * 
			xx11 + ri[18] * zz11 + ri[20] * yy11) * zz31 + ri[19] 
			* (xy11 * xy31 + xz11 * xz31) + ri[21] * yz11 * yz31;
/*     (PX PX/PZ PY) */
		w[29] = (ri[15] * xx11 + ri[16] * yyzz11) * xx32 + (ri[17] * 
			xx11 + ri[18] * zz11 + ri[20] * yy11) * zz32 + ri[19] 
			* (xy11 * xy32 + xz11 * xz32) + ri[21] * yz11 * yz32;
/*     (PX PX/PZ PZ) */
		w[30] = (ri[15] * xx11 + ri[16] * yyzz11) * xx33 + (ri[17] * 
			xx11 + ri[18] * zz11 + ri[20] * yy11) * zz33 + ri[19] 
			* xz11 * xz33;
/*     (PY S/S S) */
		w[31] = ri[1] * rotdu2_1.x[1];
/*     (PY S/PX S) */
		w[32] = ri[5] * xx21 + ri[6] * yyzz21;
/*     (PY S/PX PX) */
		w[33] = rotdu2_1.x[1] * (ri[12] * xx11 + ri[13] * yyzz11) + 
			ri[14] * (rotdu2_1.y[1] * xy11 + rotdu2_1.z__[1] * 
			xz11);
/*     (PY S/PY S) */
		w[34] = ri[5] * xx22 + ri[6] * yyzz22;
/*     (PY S/PY PX) */
		w[35] = rotdu2_1.x[1] * (ri[12] * xx21 + ri[13] * yyzz21) + 
			ri[14] * (rotdu2_1.y[1] * xy21 + rotdu2_1.z__[1] * 
			xz21);
/*     (PY S/PY PY) */
		w[36] = rotdu2_1.x[1] * (ri[12] * xx22 + ri[13] * yyzz22) + 
			ri[14] * (rotdu2_1.y[1] * xy22 + rotdu2_1.z__[1] * 
			xz22);
/*     (PY S/PZ S) */
		w[37] = ri[5] * xx32 + ri[6] * zz32;
/*     (PY S/PZ PX) */
		w[38] = rotdu2_1.x[1] * (ri[12] * xx31 + ri[13] * zz31) + ri[
			14] * (rotdu2_1.y[1] * xy31 + rotdu2_1.z__[1] * xz31);
/*     (PY S/PZ PY) */
		w[39] = rotdu2_1.x[1] * (ri[12] * xx32 + ri[13] * zz32) + ri[
			14] * (rotdu2_1.y[1] * xy32 + rotdu2_1.z__[1] * xz32);
/*     (PY S/PZ PZ) */
		w[40] = rotdu2_1.x[1] * (ri[12] * xx33 + ri[13] * zz33) + ri[
			14] * (rotdu2_1.z__[1] * xz33);
/*     (PY PX/S S) */
		w[41] = ri[2] * xx21 + ri[3] * yyzz21;
/*     (PY PX/PX S) */
		w[42] = rotdu2_1.x[0] * (ri[7] * xx21 + ri[8] * yyzz21) + ri[
			9] * (rotdu2_1.y[0] * xy21 + rotdu2_1.z__[0] * xz21);
/*     (PY PX/PX PX) */
		w[43] = (ri[15] * xx21 + ri[16] * yyzz21) * xx11 + ri[17] * 
			xx21 * yyzz11 + ri[18] * (yy21 * yy11 + zz21 * zz11) 
			+ ri[19] * (xy21 * xy11 + xz21 * xz11) + ri[20] * (
			yy21 * zz11 + zz21 * yy11) + ri[21] * yz21 * yz11;
/*     (PY PX/PY S) */
		w[44] = rotdu2_1.x[1] * (ri[7] * xx21 + ri[8] * yyzz21) + ri[
			9] * (rotdu2_1.y[1] * xy21 + rotdu2_1.z__[1] * xz21);
/*     (PY PX/PY PX) */
		w[45] = (ri[15] * xx21 + ri[16] * yyzz21) * xx21 + ri[17] * 
			xx21 * yyzz21 + ri[18] * (yy21 * yy21 + zz21 * zz21) 
			+ ri[19] * (xy21 * xy21 + xz21 * xz21) + ri[20] * (
			yy21 * zz21 + zz21 * yy21) + ri[21] * yz21 * yz21;
/*     (PY PX/PY PY) */
		w[46] = (ri[15] * xx21 + ri[16] * yyzz21) * xx22 + ri[17] * 
			xx21 * yyzz22 + ri[18] * (yy21 * yy22 + zz21 * zz22) 
			+ ri[19] * (xy21 * xy22 + xz21 * xz22) + ri[20] * (
			yy21 * zz22 + zz21 * yy22) + ri[21] * yz21 * yz22;
/*     (PY PX/PZ S) */
		w[47] = rotdu2_1.x[2] * (ri[7] * xx21 + ri[8] * yyzz21) + ri[
			9] * (rotdu2_1.z__[2] * xz21);
/*      (PY PX/PZ PX) */
		w[48] = (ri[15] * xx21 + ri[16] * yyzz21) * xx31 + (ri[17] * 
			xx21 + ri[18] * zz21 + ri[20] * yy21) * zz31 + ri[19] 
			* (xy21 * xy31 + xz21 * xz31) + ri[21] * yz21 * yz31;
/*      (PY PX/PZ PY) */
		w[49] = (ri[15] * xx21 + ri[16] * yyzz21) * xx32 + (ri[17] * 
			xx21 + ri[18] * zz21 + ri[20] * yy21) * zz32 + ri[19] 
			* (xy21 * xy32 + xz21 * xz32) + ri[21] * yz21 * yz32;
/*      (PY PX/PZ PZ) */
		w[50] = (ri[15] * xx21 + ri[16] * yyzz21) * xx33 + (ri[17] * 
			xx21 + ri[18] * zz21 + ri[20] * yy21) * zz33 + ri[19] 
			* xz21 * xz33;
/*     (PY PY/S S) */
		w[51] = ri[2] * xx22 + ri[3] * yyzz22;
/*     (PY PY/PX S) */
		w[52] = rotdu2_1.x[0] * (ri[7] * xx22 + ri[8] * yyzz22) + ri[
			9] * (rotdu2_1.y[0] * xy22 + rotdu2_1.z__[0] * xz22);
/*      (PY PY/PX PX) */
		w[53] = (ri[15] * xx22 + ri[16] * yyzz22) * xx11 + ri[17] * 
			xx22 * yyzz11 + ri[18] * (yy22 * yy11 + zz22 * zz11) 
			+ ri[19] * (xy22 * xy11 + xz22 * xz11) + ri[20] * (
			yy22 * zz11 + zz22 * yy11) + ri[21] * yz22 * yz11;
/*     (PY PY/PY S) */
		w[54] = rotdu2_1.x[1] * (ri[7] * xx22 + ri[8] * yyzz22) + ri[
			9] * (rotdu2_1.y[1] * xy22 + rotdu2_1.z__[1] * xz22);
/*      (PY PY/PY PX) */
		w[55] = (ri[15] * xx22 + ri[16] * yyzz22) * xx21 + ri[17] * 
			xx22 * yyzz21 + ri[18] * (yy22 * yy21 + zz22 * zz21) 
			+ ri[19] * (xy22 * xy21 + xz22 * xz21) + ri[20] * (
			yy22 * zz21 + zz22 * yy21) + ri[21] * yz22 * yz21;
/*      (PY PY/PY PY) */
		w[56] = (ri[15] * xx22 + ri[16] * yyzz22) * xx22 + ri[17] * 
			xx22 * yyzz22 + ri[18] * (yy22 * yy22 + zz22 * zz22) 
			+ ri[19] * (xy22 * xy22 + xz22 * xz22) + ri[20] * (
			yy22 * zz22 + zz22 * yy22) + ri[21] * yz22 * yz22;
/*     (PY PY/PZ S) */
		w[57] = rotdu2_1.x[2] * (ri[7] * xx22 + ri[8] * yyzz22) + ri[
			9] * (rotdu2_1.z__[2] * xz22);
/*      (PY PY/PZ PX) */
		w[58] = (ri[15] * xx22 + ri[16] * yyzz22) * xx31 + (ri[17] * 
			xx22 + ri[18] * zz22 + ri[20] * yy22) * zz31 + ri[19] 
			* (xy22 * xy31 + xz22 * xz31) + ri[21] * yz22 * yz31;
/*      (PY PY/PZ PY) */
		w[59] = (ri[15] * xx22 + ri[16] * yyzz22) * xx32 + (ri[17] * 
			xx22 + ri[18] * zz22 + ri[20] * yy22) * zz32 + ri[19] 
			* (xy22 * xy32 + xz22 * xz32) + ri[21] * yz22 * yz32;
/*      (PY PY/PZ PZ) */
		w[60] = (ri[15] * xx22 + ri[16] * yyzz22) * xx33 + (ri[17] * 
			xx22 + ri[18] * zz22 + ri[20] * yy22) * zz33 + ri[19] 
			* xz22 * xz33;
/*     (PZ S/SS) */
		w[61] = ri[1] * rotdu2_1.x[2];
/*     (PZ S/PX S) */
		w[62] = ri[5] * xx31 + ri[6] * zz31;
/*     (PZ S/PX PX) */
		w[63] = rotdu2_1.x[2] * (ri[12] * xx11 + ri[13] * yyzz11) + 
			ri[14] * (rotdu2_1.z__[2] * xz11);
/*     (PZ S/PY S) */
		w[64] = ri[5] * xx32 + ri[6] * zz32;
/*     (PZ S/PY PX) */
		w[65] = rotdu2_1.x[2] * (ri[12] * xx21 + ri[13] * yyzz21) + 
			ri[14] * (rotdu2_1.z__[2] * xz21);
/*     (PZ S/PY PY) */
		w[66] = rotdu2_1.x[2] * (ri[12] * xx22 + ri[13] * yyzz22) + 
			ri[14] * (rotdu2_1.z__[2] * xz22);
/*     (PZ S/PZ S) */
		w[67] = ri[5] * xx33 + ri[6] * zz33;
/*     (PZ S/PZ PX) */
		w[68] = rotdu2_1.x[2] * (ri[12] * xx31 + ri[13] * zz31) + ri[
			14] * (rotdu2_1.z__[2] * xz31);
/*     (PZ S/PZ PY) */
		w[69] = rotdu2_1.x[2] * (ri[12] * xx32 + ri[13] * zz32) + ri[
			14] * (rotdu2_1.z__[2] * xz32);
/*     (PZ S/PZ PZ) */
		w[70] = rotdu2_1.x[2] * (ri[12] * xx33 + ri[13] * zz33) + ri[
			14] * (rotdu2_1.z__[2] * xz33);
/*     (PZ PX/S S) */
		w[71] = ri[2] * xx31 + ri[3] * zz31;
/*     (PZ PX/PX S) */
		w[72] = rotdu2_1.x[0] * (ri[7] * xx31 + ri[8] * zz31) + ri[9] 
			* (rotdu2_1.y[0] * xy31 + rotdu2_1.z__[0] * xz31);
/*      (PZ PX/PX PX) */
		w[73] = (ri[15] * xx31 + ri[16] * zz31) * xx11 + ri[17] * 
			xx31 * yyzz11 + ri[18] * zz31 * zz11 + ri[19] * (xy31 
			* xy11 + xz31 * xz11) + ri[20] * zz31 * yy11 + ri[21] 
			* yz31 * yz11;
/*     (PZ PX/PY S) */
		w[74] = rotdu2_1.x[1] * (ri[7] * xx31 + ri[8] * zz31) + ri[9] 
			* (rotdu2_1.y[1] * xy31 + rotdu2_1.z__[1] * xz31);
/*      (PZ PX/PY PX) */
		w[75] = (ri[15] * xx31 + ri[16] * zz31) * xx21 + ri[17] * 
			xx31 * yyzz21 + ri[18] * zz31 * zz21 + ri[19] * (xy31 
			* xy21 + xz31 * xz21) + ri[20] * zz31 * yy21 + ri[21] 
			* yz31 * yz21;
/*      (PZ PX/PY PY) */
		w[76] = (ri[15] * xx31 + ri[16] * zz31) * xx22 + ri[17] * 
			xx31 * yyzz22 + ri[18] * zz31 * zz22 + ri[19] * (xy31 
			* xy22 + xz31 * xz22) + ri[20] * zz31 * yy22 + ri[21] 
			* yz31 * yz22;
/*     (PZ PX/PZ S) */
		w[77] = rotdu2_1.x[2] * (ri[7] * xx31 + ri[8] * zz31) + ri[9] 
			* (rotdu2_1.z__[2] * xz31);
/*     (PZ PX/PZ PX) */
		w[78] = (ri[15] * xx31 + ri[16] * zz31) * xx31 + (ri[17] * 
			xx31 + ri[18] * zz31) * zz31 + ri[19] * (xy31 * xy31 
			+ xz31 * xz31) + ri[21] * yz31 * yz31;
/*      (PZ PX/PZ PY) */
		w[79] = (ri[15] * xx31 + ri[16] * zz31) * xx32 + (ri[17] * 
			xx31 + ri[18] * zz31) * zz32 + ri[19] * (xy31 * xy32 
			+ xz31 * xz32) + ri[21] * yz31 * yz32;
/*      (PZ PX/PZ PZ) */
		w[80] = (ri[15] * xx31 + ri[16] * zz31) * xx33 + (ri[17] * 
			xx31 + ri[18] * zz31) * zz33 + ri[19] * xz31 * xz33;
/*     (PZ PY/S S) */
		w[81] = ri[2] * xx32 + ri[3] * zz32;
/*     (PZ PY/PX S) */
		w[82] = rotdu2_1.x[0] * (ri[7] * xx32 + ri[8] * zz32) + ri[9] 
			* (rotdu2_1.y[0] * xy32 + rotdu2_1.z__[0] * xz32);
/*      (PZ PY/PX PX) */
		w[83] = (ri[15] * xx32 + ri[16] * zz32) * xx11 + ri[17] * 
			xx32 * yyzz11 + ri[18] * zz32 * zz11 + ri[19] * (xy32 
			* xy11 + xz32 * xz11) + ri[20] * zz32 * yy11 + ri[21] 
			* yz32 * yz11;
/*     (PZ PY/PY S) */
		w[84] = rotdu2_1.x[1] * (ri[7] * xx32 + ri[8] * zz32) + ri[9] 
			* (rotdu2_1.y[1] * xy32 + rotdu2_1.z__[1] * xz32);
/*      (PZ PY/PY PX) */
		w[85] = (ri[15] * xx32 + ri[16] * zz32) * xx21 + ri[17] * 
			xx32 * yyzz21 + ri[18] * zz32 * zz21 + ri[19] * (xy32 
			* xy21 + xz32 * xz21) + ri[20] * zz32 * yy21 + ri[21] 
			* yz32 * yz21;
/*      (PZ PY/PY PY) */
		w[86] = (ri[15] * xx32 + ri[16] * zz32) * xx22 + ri[17] * 
			xx32 * yyzz22 + ri[18] * zz32 * zz22 + ri[19] * (xy32 
			* xy22 + xz32 * xz22) + ri[20] * zz32 * yy22 + ri[21] 
			* yz32 * yz22;
/*     (PZ PY/PZ S) */
		w[87] = rotdu2_1.x[2] * (ri[7] * xx32 + ri[8] * zz32) + ri[9] 
			* (rotdu2_1.z__[2] * xz32);
/*      (PZ PY/PZ PX) */
		w[88] = (ri[15] * xx32 + ri[16] * zz32) * xx31 + (ri[17] * 
			xx32 + ri[18] * zz32) * zz31 + ri[19] * (xy32 * xy31 
			+ xz32 * xz31) + ri[21] * yz32 * yz31;
/*      (PZ PY/PZ PY) */
		w[89] = (ri[15] * xx32 + ri[16] * zz32) * xx32 + (ri[17] * 
			xx32 + ri[18] * zz32) * zz32 + ri[19] * (xy32 * xy32 
			+ xz32 * xz32) + ri[21] * yz32 * yz32;
/*       (PZ PY/PZ PZ) */
		w[90] = (ri[15] * xx32 + ri[16] * zz32) * xx33 + (ri[17] * 
			xx32 + ri[18] * zz32) * zz33 + ri[19] * xz32 * xz33;
/*     (PZ PZ/S S) */
		w[91] = ri[2] * xx33 + ri[3] * zz33;
/*     (PZ PZ/PX S) */
		w[92] = rotdu2_1.x[0] * (ri[7] * xx33 + ri[8] * zz33) + ri[9] 
			* (rotdu2_1.z__[0] * xz33);
/*       (PZ PZ/PX PX) */
		w[93] = (ri[15] * xx33 + ri[16] * zz33) * xx11 + ri[17] * 
			xx33 * yyzz11 + ri[18] * zz33 * zz11 + ri[19] * xz33 *
			 xz11 + ri[20] * zz33 * yy11;
/*     (PZ PZ/PY S) */
		w[94] = rotdu2_1.x[1] * (ri[7] * xx33 + ri[8] * zz33) + ri[9] 
			* (rotdu2_1.z__[1] * xz33);
/*       (PZ PZ/PY PX) */
		w[95] = (ri[15] * xx33 + ri[16] * zz33) * xx21 + ri[17] * 
			xx33 * yyzz21 + ri[18] * zz33 * zz21 + ri[19] * xz33 *
			 xz21 + ri[20] * zz33 * yy21;
/*       (PZ PZ/PY PY) */
		w[96] = (ri[15] * xx33 + ri[16] * zz33) * xx22 + ri[17] * 
			xx33 * yyzz22 + ri[18] * zz33 * zz22 + ri[19] * xz33 *
			 xz22 + ri[20] * zz33 * yy22;
/*     (PZ PZ/PZ S) */
		w[97] = rotdu2_1.x[2] * (ri[7] * xx33 + ri[8] * zz33) + ri[9] 
			* (rotdu2_1.z__[2] * xz33);
/*       (PZ PZ/PZ PX) */
		w[98] = (ri[15] * xx33 + ri[16] * zz33) * xx31 + (ri[17] * 
			xx33 + ri[18] * zz33) * zz31 + ri[19] * xz33 * xz31;
/*       (PZ PZ/PZ PY) */
		w[99] = (ri[15] * xx33 + ri[16] * zz33) * xx32 + (ri[17] * 
			xx33 + ri[18] * zz33) * zz32 + ri[19] * xz33 * xz32;
/*       (PZ PZ/PZ PZ) */
		w[100] = (ri[15] * xx33 + ri[16] * zz33) * xx33 + (ri[17] * 
			xx33 + ri[18] * zz33) * zz33 + ri[19] * xz33 * xz33;
		ki = 100;
	    } else {
/*     (PX S/S S) */
		w[2] = ri[1] * rotdu2_1.x[0];
/*     (PX PX/S S) */
		w[3] = ri[2] * xx11 + ri[3] * yyzz11;
/*     (PY S/S S) */
		w[4] = ri[1] * rotdu2_1.x[1];
/*     (PY PX/S S) */
		w[5] = ri[2] * xx21 + ri[3] * yyzz21;
/*     (PY PY/S S) */
		w[6] = ri[2] * xx22 + ri[3] * yyzz22;
/*     (PZ S/SS) */
		w[7] = ri[1] * rotdu2_1.x[2];
/*     (PZ PX/S S) */
		w[8] = ri[2] * xx31 + ri[3] * zz31;
/*     (PZ PY/S S) */
		w[9] = ri[2] * xx32 + ri[3] * zz32;
/*     (PZ PZ/S S) */
		w[10] = ri[2] * xx33 + ri[3] * zz33;
		ki = 10;
	    }
	}

/* *** NOW ROTATE THE NUCLEAR ATTRACTION INTEGRALS. */
/* *** THE STORAGE OF THE NUCLEAR ATTRACTION INTEGRALS  CORE(KL/IJ) IS */
/*     (SS/)=1,   (SO/)=2,   (OO/)=3,   (PP/)=4 */

	e1b[1] = -rotdum_1.css1;
	if (natorb_1.natorb[*ni - 1] == 4) {
	    e1b[2] = -rotdum_1.csp1 * rotdu2_1.x[0];
	    e1b[3] = -rotdum_1.cpps1 * xx11 - rotdum_1.cppp1 * yyzz11;
	    e1b[4] = -rotdum_1.csp1 * rotdu2_1.x[1];
	    e1b[5] = -rotdum_1.cpps1 * xx21 - rotdum_1.cppp1 * yyzz21;
	    e1b[6] = -rotdum_1.cpps1 * xx22 - rotdum_1.cppp1 * yyzz22;
	    e1b[7] = -rotdum_1.csp1 * rotdu2_1.x[2];
	    e1b[8] = -rotdum_1.cpps1 * xx31 - rotdum_1.cppp1 * zz31;
	    e1b[9] = -rotdum_1.cpps1 * xx32 - rotdum_1.cppp1 * zz32;
	    e1b[10] = -rotdum_1.cpps1 * xx33 - rotdum_1.cppp1 * zz33;
	}
	e2a[1] = -rotdum_1.css2;
	if (natorb_1.natorb[*nj - 1] == 4) {
	    e2a[2] = -rotdum_1.csp2 * rotdu2_1.x[0];
	    e2a[3] = -rotdum_1.cpps2 * xx11 - rotdum_1.cppp2 * yyzz11;
	    e2a[4] = -rotdum_1.csp2 * rotdu2_1.x[1];
	    e2a[5] = -rotdum_1.cpps2 * xx21 - rotdum_1.cppp2 * yyzz21;
	    e2a[6] = -rotdum_1.cpps2 * xx22 - rotdum_1.cppp2 * yyzz22;
	    e2a[7] = -rotdum_1.csp2 * rotdu2_1.x[2];
	    e2a[8] = -rotdum_1.cpps2 * xx31 - rotdum_1.cppp2 * zz31;
	    e2a[9] = -rotdum_1.cpps2 * xx32 - rotdum_1.cppp2 * zz32;
	    e2a[10] = -rotdum_1.cpps2 * xx33 - rotdum_1.cppp2 * zz33;
	}
	if ((d__1 = core_1.tore[*ni - 1], abs(d__1)) > 20. && (d__2 = 
		core_1.tore[*nj - 1], abs(d__2)) > 20.) {
/* SPARKLE-SPARKLE INTERACTION */
	    *enuc = 0.;
	    return 0;
	} else if (rij < 1. && natorb_1.natorb[*ni - 1] * natorb_1.natorb[*nj 
		- 1] == 0) {
	    *enuc = 0.;
	    return 0;
	}
	scale = exp(-alpha_1.alp[*ni - 1] * rij) + exp(-alpha_1.alp[*nj - 1] *
		 rij);

	if (*ni == 24 && *nj == 24) {
	    scale = exp(-alptm_1.alptm[*ni - 1] * rij) + exp(-alptm_1.alptm[*
		    nj - 1] * rij);
	}

	nt = *ni + *nj;
	if (nt == 8 || nt == 9) {
	    if (*ni == 7 || *ni == 8) {
		scale += (rij - 1.) * exp(-alpha_1.alp[*ni - 1] * rij);
	    }
	    if (*nj == 7 || *nj == 8) {
		scale += (rij - 1.) * exp(-alpha_1.alp[*nj - 1] * rij);
	    }
	}
	*enuc = core_1.tore[*ni - 1] * core_1.tore[*nj - 1] * gam;
	scale = (d__1 = scale * *enuc, abs(d__1));
	if (molmec_1.itype == 2 && (*ni == 5 || *nj == 5)) {

/*   LOAD IN AM1 BORON GAUSSIANS */

	    nk = *ni + *nj - 5;
/*   NK IS THE ATOMIC NUMBER OF THE NON-BORON ATOM */
	    nl = 1;
	    if (nk == 1) {
		nl = 2;
	    }
	    if (nk == 6) {
		nl = 3;
	    }
	    if (nk == 9 || nk == 17 || nk == 35 || nk == 53) {
		nl = 4;
	    }
	    for (i__ = 1; i__ <= 3; ++i__) {
		ideas_1.fn1[i__ * 107 - 103] = boron1[i__ + nl * 3 - 4];
		ideas_1.fn2[i__ * 107 - 103] = boron2[i__ + nl * 3 - 4];
/* L30: */
		ideas_1.fn3[i__ * 107 - 103] = boron3[i__ + nl * 3 - 4];
	    }
	}
	if (molmec_1.itype == 2 || molmec_1.itype == 3) {
	    for (ig = 1; ig <= 10; ++ig) {
		if ((d__1 = ideas_1.fn1[*ni + ig * 107 - 108], abs(d__1)) > 
			0.) {
/* Computing 2nd power */
		    d__1 = rij - ideas_1.fn3[*ni + ig * 107 - 108];
		    ax = ideas_1.fn2[*ni + ig * 107 - 108] * (d__1 * d__1);
		    if (ax <= 25.) {
			scale += core_1.tore[*ni - 1] * core_1.tore[*nj - 1] /
				 rij * ideas_1.fn1[*ni + ig * 107 - 108] * 
				exp(-ax);
		    }
		}
		if ((d__1 = ideas_1.fn1[*nj + ig * 107 - 108], abs(d__1)) > 
			0.) {
/* Computing 2nd power */
		    d__1 = rij - ideas_1.fn3[*nj + ig * 107 - 108];
		    ax = ideas_1.fn2[*nj + ig * 107 - 108] * (d__1 * d__1);
		    if (ax <= 25.) {
			scale += core_1.tore[*ni - 1] * core_1.tore[*nj - 1] /
				 rij * ideas_1.fn1[*nj + ig * 107 - 108] * 
				exp(-ax);
		    }
		}
/* L40: */
	    }
	}
	*enuc += scale;

	if (natorb_1.natorb[*ni - 1] * natorb_1.natorb[*nj - 1] == 0) {
	    ki = 0;
	}
	*kr += ki;


    }
    return 0;
} /* rotate_ */

#undef ccore


