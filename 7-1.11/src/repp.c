/* repp.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal dd[107], qq[107], add[321]	/* was [107][3] */;
} multip_;

#define multip_1 multip_

struct {
    doublereal tore[107];
} core_;

#define core_1 core_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

/* Subroutine */ int repp_(integer *ni, integer *nj, doublereal *rij, 
	doublereal *ri, doublereal *core)
{
    /* Initialized data */

    static doublereal td = 2.;
    static doublereal pp = .5;
    static doublereal a0 = .529167;
    static doublereal ev = 27.21;
    static doublereal ev1 = 13.605;
    static doublereal ev2 = 6.8025;
    static doublereal ev3 = 3.40125;
    static doublereal ev4 = 1.700625;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal r__, da, db, ee, qa, qb;
    static logical si, sj;
    static doublereal ade, aee, aed, adq, aqe, aeq, aqd, arg[72], aqq, dze, 
	    edz, axx, sqr[72], rsq, www, xxx, yyy, zzz, dxdx, dzdz, qxxe, 
	    eqxx, qzze, eqzz, dzqxx, qxxdz, dxqxz, qxzdx, dzqzz, qzzdz, 
	    qxxqxx, qxxqyy, qxxqzz, qzzqxx, qxzqxz, qzzqzz;

/* *********************************************************************** */

/* ..VECTOR VERSION WRITTEN BY ERNEST R. DAVIDSON, INDIANA UNIVERSITY */


/*  REPP CALCULATES THE TWO-ELECTRON REPULSION INTEGRALS AND THE */
/*       NUCLEAR ATTRACTION INTEGRALS. */

/*     ON INPUT RIJ     = INTERATOMIC DISTANCE */
/*              NI      = ATOM NUMBER OF FIRST ATOM */
/*              NJ      = ATOM NUMBER OF SECOND ATOM */
/*    (REF)     ADD     = ARRAY OF GAMMA, OR TWO-ELECTRON ONE-CENTER, */
/*                        INTEGRALS. */
/*    (REF)     TORE    = ARRAY OF NUCLEAR CHARGES OF THE ELEMENTS */
/*    (REF)     DD      = ARRAY OF DIPOLE CHARGE SEPARATIONS */
/*    (REF)     QQ      = ARRAY OF QUADRUPOLE CHARGE SEPARATIONS */

/*     THE COMMON BLOCKS ARE INITIALIZED IN BLOCK-DATA, AND NEVER CHANGED */

/*    ON OUTPUT RI      = ARRAY OF TWO-ELECTRON REPULSION INTEGRALS */
/*              CORE    = 4 X 2 ARRAY OF ELECTRON-CORE ATTRACTION */
/*                        INTEGRALS */


/* *** THIS ROUTINE COMPUTES THE TWO-CENTRE REPULSION INTEGRALS AND THE */
/* *** NUCLEAR ATTRACTION INTEGRALS. */
/* *** THE TWO-CENTRE REPULSION INTEGRALS (OVER LOCAL COORDINATES) ARE */
/* *** STORED AS FOLLOWS (WHERE P-SIGMA = O,  AND P-PI = P AND P* ) */
/*     (SS/SS)=1,   (SO/SS)=2,   (OO/SS)=3,   (PP/SS)=4,   (SS/OS)=5, */
/*     (SO/SO)=6,   (SP/SP)=7,   (OO/SO)=8,   (PP/SO)=9,   (PO/SP)=10, */
/*     (SS/OO)=11,  (SS/PP)=12,  (SO/OO)=13,  (SO/PP)=14,  (SP/OP)=15, */
/*     (OO/OO)=16,  (PP/OO)=17,  (OO/PP)=18,  (PP/PP)=19,  (PO/PO)=20, */
/*     (PP/P*P*)=21,   (P*P/P*P)=22. */
/* *** THE STORAGE OF THE NUCLEAR ATTRACTION INTEGRALS  CORE(KL/IJ) IS */
/*     (SS/)=1,   (SO/)=2,   (OO/)=3,   (PP/)=4 */
/*     WHERE IJ=1 IF THE ORBITALS CENTRED ON ATOM I,  =2 IF ON ATOM J. */
/* *** NI AND NJ ARE THE ATOMIC NUMBERS OF THE TWO ELEMENTS. */

/* *********************************************************************** */
    /* Parameter adjustments */
    core -= 5;
    --ri;

    /* Function Body */

/*     ATOMIC UNITS ARE USED IN THE CALCULATION, */
/*     FINAL RESULTS ARE CONVERTED TO EV */

    r__ = *rij / a0;

    si = natorb_1.natorb[*ni - 1] >= 3;
    sj = natorb_1.natorb[*nj - 1] >= 3;

    if (! si && ! sj) {

/*     HYDROGEN - HYDROGEN  (SS/SS) */

	aee = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj - 1];
	aee *= aee;
	ri[1] = ev / sqrt(r__ * r__ + aee);
	core[5] = core_1.tore[*nj - 1] * ri[1];
	core[9] = core_1.tore[*ni - 1] * ri[1];

    } else if (si && ! sj) {

/*     HEAVY ATOM - HYDROGEN */

	aee = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj - 1];
	aee *= aee;
	da = multip_1.dd[*ni - 1];
	qa = multip_1.qq[*ni - 1] * td;
	ade = pp / multip_1.add[*ni + 106] + pp / multip_1.add[*nj - 1];
	ade *= ade;
	aqe = pp / multip_1.add[*ni + 213] + pp / multip_1.add[*nj - 1];
	aqe *= aqe;
	rsq = r__ * r__;
	arg[0] = rsq + aee;
	xxx = r__ + da;
	arg[1] = xxx * xxx + ade;
	xxx = r__ - da;
	arg[2] = xxx * xxx + ade;
	xxx = r__ + qa;
	arg[3] = xxx * xxx + aqe;
	xxx = r__ - qa;
	arg[4] = xxx * xxx + aqe;
	arg[5] = rsq + aqe;
	arg[6] = arg[5] + qa * qa;
/* $DOIT ASIS */
	for (i__ = 1; i__ <= 7; ++i__) {
	    sqr[i__ - 1] = sqrt(arg[i__ - 1]);
/* L10: */
	}
	ee = ev / sqr[0];
	ri[1] = ee;
	ri[2] = ev1 / sqr[1] - ev1 / sqr[2];
	ri[3] = ee + ev2 / sqr[3] + ev2 / sqr[4] - ev1 / sqr[5];
	ri[4] = ee + ev1 / sqr[6] - ev1 / sqr[5];
	core[5] = core_1.tore[*nj - 1] * ri[1];
	core[9] = core_1.tore[*ni - 1] * ri[1];
	core[6] = core_1.tore[*nj - 1] * ri[2];
	core[7] = core_1.tore[*nj - 1] * ri[3];
	core[8] = core_1.tore[*nj - 1] * ri[4];

    } else if (! si && sj) {

/*     HYDROGEN - HEAVY ATOM */

	aee = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj - 1];
	aee *= aee;
	db = multip_1.dd[*nj - 1];
	qb = multip_1.qq[*nj - 1] * td;
	aed = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj + 106];
	aed *= aed;
	aeq = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj + 213];
	aeq *= aeq;
	rsq = r__ * r__;
	arg[0] = rsq + aee;
	xxx = r__ - db;
	arg[1] = xxx * xxx + aed;
	xxx = r__ + db;
	arg[2] = xxx * xxx + aed;
	xxx = r__ - qb;
	arg[3] = xxx * xxx + aeq;
	xxx = r__ + qb;
	arg[4] = xxx * xxx + aeq;
	arg[5] = rsq + aeq;
	arg[6] = arg[5] + qb * qb;
/* $DOIT ASIS */
	for (i__ = 1; i__ <= 7; ++i__) {
	    sqr[i__ - 1] = sqrt(arg[i__ - 1]);
/* L20: */
	}
	ee = ev / sqr[0];
	ri[1] = ee;
	ri[5] = ev1 / sqr[1] - ev1 / sqr[2];
	ri[11] = ee + ev2 / sqr[3] + ev2 / sqr[4] - ev1 / sqr[5];
	ri[12] = ee + ev1 / sqr[6] - ev1 / sqr[5];
	core[5] = core_1.tore[*nj - 1] * ri[1];
	core[9] = core_1.tore[*ni - 1] * ri[1];
	core[10] = core_1.tore[*ni - 1] * ri[5];
	core[11] = core_1.tore[*ni - 1] * ri[11];
	core[12] = core_1.tore[*ni - 1] * ri[12];

    } else {

/*     HEAVY ATOM - HEAVY ATOM */

/*     DEFINE CHARGE SEPARATIONS. */
	da = multip_1.dd[*ni - 1];
	db = multip_1.dd[*nj - 1];
	qa = multip_1.qq[*ni - 1] * td;
	qb = multip_1.qq[*nj - 1] * td;

	aee = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj - 1];
	aee *= aee;

	ade = pp / multip_1.add[*ni + 106] + pp / multip_1.add[*nj - 1];
	ade *= ade;
	aqe = pp / multip_1.add[*ni + 213] + pp / multip_1.add[*nj - 1];
	aqe *= aqe;
	aed = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj + 106];
	aed *= aed;
	aeq = pp / multip_1.add[*ni - 1] + pp / multip_1.add[*nj + 213];
	aeq *= aeq;
	axx = pp / multip_1.add[*ni + 106] + pp / multip_1.add[*nj + 106];
	axx *= axx;
	adq = pp / multip_1.add[*ni + 106] + pp / multip_1.add[*nj + 213];
	adq *= adq;
	aqd = pp / multip_1.add[*ni + 213] + pp / multip_1.add[*nj + 106];
	aqd *= aqd;
	aqq = pp / multip_1.add[*ni + 213] + pp / multip_1.add[*nj + 213];
	aqq *= aqq;
	rsq = r__ * r__;
	arg[0] = rsq + aee;
	xxx = r__ + da;
	arg[1] = xxx * xxx + ade;
	xxx = r__ - da;
	arg[2] = xxx * xxx + ade;
	xxx = r__ - qa;
	arg[3] = xxx * xxx + aqe;
	xxx = r__ + qa;
	arg[4] = xxx * xxx + aqe;
	arg[5] = rsq + aqe;
	arg[6] = arg[5] + qa * qa;
	xxx = r__ - db;
	arg[7] = xxx * xxx + aed;
	xxx = r__ + db;
	arg[8] = xxx * xxx + aed;
	xxx = r__ - qb;
	arg[9] = xxx * xxx + aeq;
	xxx = r__ + qb;
	arg[10] = xxx * xxx + aeq;
	arg[11] = rsq + aeq;
	arg[12] = arg[11] + qb * qb;
	xxx = da - db;
	arg[13] = rsq + axx + xxx * xxx;
	xxx = da + db;
	arg[14] = rsq + axx + xxx * xxx;
	xxx = r__ + da - db;
	arg[15] = xxx * xxx + axx;
	xxx = r__ - da + db;
	arg[16] = xxx * xxx + axx;
	xxx = r__ - da - db;
	arg[17] = xxx * xxx + axx;
	xxx = r__ + da + db;
	arg[18] = xxx * xxx + axx;
	xxx = r__ + da;
	arg[19] = xxx * xxx + adq;
	arg[20] = arg[19] + qb * qb;
	xxx = r__ - da;
	arg[21] = xxx * xxx + adq;
	arg[22] = arg[21] + qb * qb;
	xxx = r__ - db;
	arg[23] = xxx * xxx + aqd;
	arg[24] = arg[23] + qa * qa;
	xxx = r__ + db;
	arg[25] = xxx * xxx + aqd;
	arg[26] = arg[25] + qa * qa;
	xxx = r__ + da - qb;
	arg[27] = xxx * xxx + adq;
	xxx = r__ - da - qb;
	arg[28] = xxx * xxx + adq;
	xxx = r__ + da + qb;
	arg[29] = xxx * xxx + adq;
	xxx = r__ - da + qb;
	arg[30] = xxx * xxx + adq;
	xxx = r__ + qa - db;
	arg[31] = xxx * xxx + aqd;
	xxx = r__ + qa + db;
	arg[32] = xxx * xxx + aqd;
	xxx = r__ - qa - db;
	arg[33] = xxx * xxx + aqd;
	xxx = r__ - qa + db;
	arg[34] = xxx * xxx + aqd;
	arg[35] = rsq + aqq;
	xxx = qa - qb;
	arg[36] = arg[35] + xxx * xxx;
	xxx = qa + qb;
	arg[37] = arg[35] + xxx * xxx;
	arg[38] = arg[35] + qa * qa;
	arg[39] = arg[35] + qb * qb;
	arg[40] = arg[38] + qb * qb;
	xxx = r__ - qb;
	arg[41] = xxx * xxx + aqq;
	arg[42] = arg[41] + qa * qa;
	xxx = r__ + qb;
	arg[43] = xxx * xxx + aqq;
	arg[44] = arg[43] + qa * qa;
	xxx = r__ + qa;
	arg[45] = xxx * xxx + aqq;
	arg[46] = arg[45] + qb * qb;
	xxx = r__ - qa;
	arg[47] = xxx * xxx + aqq;
	arg[48] = arg[47] + qb * qb;
	xxx = r__ + qa - qb;
	arg[49] = xxx * xxx + aqq;
	xxx = r__ + qa + qb;
	arg[50] = xxx * xxx + aqq;
	xxx = r__ - qa - qb;
	arg[51] = xxx * xxx + aqq;
	xxx = r__ - qa + qb;
	arg[52] = xxx * xxx + aqq;
	qa = multip_1.qq[*ni - 1];
	qb = multip_1.qq[*nj - 1];
	xxx = da - qb;
	xxx *= xxx;
	yyy = r__ - qb;
	yyy *= yyy;
	zzz = da + qb;
	zzz *= zzz;
	www = r__ + qb;
	www *= www;
	arg[53] = xxx + yyy + adq;
	arg[54] = xxx + www + adq;
	arg[55] = zzz + yyy + adq;
	arg[56] = zzz + www + adq;
	xxx = qa - db;
	xxx *= xxx;
	yyy = qa + db;
	yyy *= yyy;
	zzz = r__ + qa;
	zzz *= zzz;
	www = r__ - qa;
	www *= www;
	arg[57] = zzz + xxx + aqd;
	arg[58] = www + xxx + aqd;
	arg[59] = zzz + yyy + aqd;
	arg[60] = www + yyy + aqd;
	xxx = qa - qb;
	xxx *= xxx;
	arg[61] = arg[35] + td * xxx;
	yyy = qa + qb;
	yyy *= yyy;
	arg[62] = arg[35] + td * yyy;
	arg[63] = arg[35] + td * (qa * qa + qb * qb);
	zzz = r__ + qa - qb;
	zzz *= zzz;
	arg[64] = zzz + xxx + aqq;
	arg[65] = zzz + yyy + aqq;
	zzz = r__ + qa + qb;
	zzz *= zzz;
	arg[66] = zzz + xxx + aqq;
	arg[67] = zzz + yyy + aqq;
	zzz = r__ - qa - qb;
	zzz *= zzz;
	arg[68] = zzz + xxx + aqq;
	arg[69] = zzz + yyy + aqq;
	zzz = r__ - qa + qb;
	zzz *= zzz;
	arg[70] = zzz + xxx + aqq;
	arg[71] = zzz + yyy + aqq;
	for (i__ = 1; i__ <= 72; ++i__) {
	    sqr[i__ - 1] = sqrt(arg[i__ - 1]);
/* L30: */
	}
	ee = ev / sqr[0];
	dze = -ev1 / sqr[1] + ev1 / sqr[2];
	qzze = ev2 / sqr[3] + ev2 / sqr[4] - ev1 / sqr[5];
	qxxe = ev1 / sqr[6] - ev1 / sqr[5];
	edz = -ev1 / sqr[7] + ev1 / sqr[8];
	eqzz = ev2 / sqr[9] + ev2 / sqr[10] - ev1 / sqr[11];
	eqxx = ev1 / sqr[12] - ev1 / sqr[11];
	dxdx = ev1 / sqr[13] - ev1 / sqr[14];
	dzdz = ev2 / sqr[15] + ev2 / sqr[16] - ev2 / sqr[17] - ev2 / sqr[18];
	dzqxx = ev2 / sqr[19] - ev2 / sqr[20] - ev2 / sqr[21] + ev2 / sqr[22];
	qxxdz = ev2 / sqr[23] - ev2 / sqr[24] - ev2 / sqr[25] + ev2 / sqr[26];
	dzqzz = -ev3 / sqr[27] + ev3 / sqr[28] - ev3 / sqr[29] + ev3 / sqr[30]
		 - ev2 / sqr[21] + ev2 / sqr[19];
	qzzdz = -ev3 / sqr[31] + ev3 / sqr[32] - ev3 / sqr[33] + ev3 / sqr[34]
		 + ev2 / sqr[23] - ev2 / sqr[25];
	qxxqxx = ev3 / sqr[36] + ev3 / sqr[37] - ev2 / sqr[38] - ev2 / sqr[39]
		 + ev2 / sqr[35];
	qxxqyy = ev2 / sqr[40] - ev2 / sqr[38] - ev2 / sqr[39] + ev2 / sqr[35]
		;
	qxxqzz = ev3 / sqr[42] + ev3 / sqr[44] - ev3 / sqr[41] - ev3 / sqr[43]
		 - ev2 / sqr[38] + ev2 / sqr[35];
	qzzqxx = ev3 / sqr[46] + ev3 / sqr[48] - ev3 / sqr[45] - ev3 / sqr[47]
		 - ev2 / sqr[39] + ev2 / sqr[35];
	qzzqzz = ev4 / sqr[49] + ev4 / sqr[50] + ev4 / sqr[51] + ev4 / sqr[52]
		 - ev3 / sqr[47] - ev3 / sqr[45] - ev3 / sqr[41] - ev3 / sqr[
		43] + ev2 / sqr[35];
	dxqxz = -ev2 / sqr[53] + ev2 / sqr[54] + ev2 / sqr[55] - ev2 / sqr[56]
		;
	qxzdx = -ev2 / sqr[57] + ev2 / sqr[58] + ev2 / sqr[59] - ev2 / sqr[60]
		;
	qxzqxz = ev3 / sqr[64] - ev3 / sqr[66] - ev3 / sqr[68] + ev3 / sqr[70]
		 - ev3 / sqr[65] + ev3 / sqr[67] + ev3 / sqr[69] - ev3 / sqr[
		71];
	ri[1] = ee;
	ri[2] = -dze;
	ri[3] = ee + qzze;
	ri[4] = ee + qxxe;
	ri[5] = -edz;
	ri[6] = dzdz;
	ri[7] = dxdx;
	ri[8] = -edz - qzzdz;
	ri[9] = -edz - qxxdz;
	ri[10] = -qxzdx;
	ri[11] = ee + eqzz;
	ri[12] = ee + eqxx;
	ri[13] = -dze - dzqzz;
	ri[14] = -dze - dzqxx;
	ri[15] = -dxqxz;
	ri[16] = ee + eqzz + qzze + qzzqzz;
	ri[17] = ee + eqzz + qxxe + qxxqzz;
	ri[18] = ee + eqxx + qzze + qzzqxx;
	ri[19] = ee + eqxx + qxxe + qxxqxx;
	ri[20] = qxzqxz;
	ri[21] = ee + eqxx + qxxe + qxxqyy;
	ri[22] = pp * (qxxqxx - qxxqyy);

/*     CALCULATE CORE-ELECTRON ATTRACTIONS. */

	core[5] = core_1.tore[*nj - 1] * ri[1];
	core[6] = core_1.tore[*nj - 1] * ri[2];
	core[7] = core_1.tore[*nj - 1] * ri[3];
	core[8] = core_1.tore[*nj - 1] * ri[4];
	core[9] = core_1.tore[*ni - 1] * ri[1];
	core[10] = core_1.tore[*ni - 1] * ri[5];
	core[11] = core_1.tore[*ni - 1] * ri[11];
	core[12] = core_1.tore[*ni - 1] * ri[12];

    }

    return 0;

} /* repp_ */

