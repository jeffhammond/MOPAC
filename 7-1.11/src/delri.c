/* delri.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal dd[107], qq[107], bdd[321]	/* was [107][3] */;
} multip_;

#define multip_1 multip_

struct {
    doublereal f03[107];
} twoel3_;

#define twoel3_1 twoel3_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

struct {
    doublereal alp3[153];
} alpha3_;

#define alpha3_1 alpha3_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Subroutine */ int delri_(doublereal *dg, integer *ni, integer *nj, 
	doublereal *rr, doublereal *del1)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4, d__5, d__6, d__7, d__8, d__9, d__10, 
	    d__11, d__12, d__13, d__14, d__15, d__16, d__17, d__18, d__19, 
	    d__20, d__21, d__22, d__23, d__24;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a0, da, db, ee, qa, qb, add, aee, ade, aed, adq, aqe, 
	    aeq, aqd, dze, edz, aqq, term, dxdx, dzdz, qxxe, eqxx, qzze, eqzz,
	     dzqxx, qxxdz, dxqxz, qxzdx, dzqzz, qzzdz, qxxqxx, qxxqyy, qxxqzz,
	     qzzqxx, qxzqxz, qzzqzz;

/* *********************************************************************** */
/*                                                                      * */
/*    ON INPUT NI = ATOMIC NUMBER OF FIRST ATOM                         * */
/*             NJ = ATOMIC NUMBER OF SECOND ATOM                        * */
/*             RR = INTERATOMIC DISTANCE IN BOHRS                       * */
/*                                                                      * */
/* *********************************************************************** */
    /* Parameter adjustments */
    --dg;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
    }
    a0 = .529167;
    term = *del1 * 27.21 / (*rr * a0 * a0);
    da = multip_1.dd[*ni - 1];
    db = multip_1.dd[*nj - 1];
    qa = multip_1.qq[*ni - 1];
    qb = multip_1.qq[*nj - 1];
/*   HYDROGEN-HYDROGEN */
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni - 1] + 1. / multip_1.bdd[*nj - 1];
    aee = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__2 = *rr;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + aee);
    ee = -(*rr) / (d__1 * (d__1 * d__1));
    dg[1] = term * ee;
    if (natorb_1.natorb[*ni - 1] <= 2 && natorb_1.natorb[*nj - 1] <= 2) {
	return 0;
    }
    if (natorb_1.natorb[*ni - 1] <= 2) {
	goto L10;
    }
/*   HEAVY ATOM-HYDROGEN */
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni + 106] + 1. / multip_1.bdd[*nj - 1];
    ade = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni + 213] + 1. / multip_1.bdd[*nj - 1];
    aqe = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__2 = *rr + da;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + ade);
/* Computing 2nd power */
    d__4 = *rr - da;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + ade);
    dze = (*rr + da) / (d__1 * (d__1 * d__1)) - (*rr - da) / (d__3 * (d__3 * 
	    d__3));
/* Computing 2nd power */
    d__2 = *rr + qa * 2.;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + aqe);
/* Computing 2nd power */
    d__4 = *rr - qa * 2.;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + aqe);
/* Computing 2nd power */
    d__6 = *rr;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + aqe);
    qzze = -(*rr + qa * 2.) / (d__1 * (d__1 * d__1)) - (*rr - qa * 2.) / (
	    d__3 * (d__3 * d__3)) + *rr * 2. / (d__5 * (d__5 * d__5));
/* Computing 2nd power */
    d__2 = *rr;
/* Computing 2nd power */
    d__3 = qa;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + aqe);
/* Computing 2nd power */
    d__5 = *rr;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + aqe);
    qxxe = -(*rr * 2.) / (d__1 * (d__1 * d__1)) + *rr * 2. / (d__4 * (d__4 * 
	    d__4));
    dg[2] = -(term * dze) / 2.;
    dg[3] = term * (ee + qzze / 4.);
    dg[4] = term * (ee + qxxe / 4.);
    if (natorb_1.natorb[*nj - 1] <= 2) {
	return 0;
    }
/*   HYDROGEN-HEAVY ATOM */
L10:
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni - 1] + 1. / multip_1.bdd[*nj + 106];
    aed = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni - 1] + 1. / multip_1.bdd[*nj + 213];
    aeq = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__2 = *rr - db;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + aed);
/* Computing 2nd power */
    d__4 = *rr + db;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + aed);
    edz = (*rr - db) / (d__1 * (d__1 * d__1)) - (*rr + db) / (d__3 * (d__3 * 
	    d__3));
/* Computing 2nd power */
    d__2 = *rr - qb * 2.;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + aeq);
/* Computing 2nd power */
    d__4 = *rr + qb * 2.;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + aeq);
/* Computing 2nd power */
    d__6 = *rr;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + aeq);
    eqzz = -(*rr - qb * 2.) / (d__1 * (d__1 * d__1)) - (*rr + qb * 2.) / (
	    d__3 * (d__3 * d__3)) + *rr * 2. / (d__5 * (d__5 * d__5));
/* Computing 2nd power */
    d__2 = *rr;
/* Computing 2nd power */
    d__3 = qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + aeq);
/* Computing 2nd power */
    d__5 = *rr;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + aeq);
    eqxx = -(*rr * 2.) / (d__1 * (d__1 * d__1)) + *rr * 2. / (d__4 * (d__4 * 
	    d__4));
    dg[5] = -(term * edz) / 2.;
    dg[11] = term * (ee + eqzz / 4.);
    dg[12] = term * (ee + eqxx / 4.);
    if (natorb_1.natorb[*ni - 1] <= 2) {
	return 0;
    }
/*   HEAVY ATOM-HEAVY ATOM */
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni + 106] + 1. / multip_1.bdd[*nj + 106];
    add = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni + 106] + 1. / multip_1.bdd[*nj + 213];
    adq = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni + 213] + 1. / multip_1.bdd[*nj + 106];
    aqd = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__1 = 1. / multip_1.bdd[*ni + 213] + 1. / multip_1.bdd[*nj + 213];
    aqq = d__1 * d__1 * .25;
/* Computing 2nd power */
    d__2 = *rr;
/* Computing 2nd power */
    d__3 = da - db;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 + add);
/* Computing 2nd power */
    d__5 = *rr;
/* Computing 2nd power */
    d__6 = da + db;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 + add);
    dxdx = -(*rr * 2.) / (d__1 * (d__1 * d__1)) + *rr * 2. / (d__4 * (d__4 * 
	    d__4));
/* Computing 2nd power */
    d__2 = *rr + da - db;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + add);
/* Computing 2nd power */
    d__4 = *rr - da + db;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + add);
/* Computing 2nd power */
    d__6 = *rr - da - db;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + add);
/* Computing 2nd power */
    d__8 = *rr + da + db;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + add);
    dzdz = -(*rr + da - db) / (d__1 * (d__1 * d__1)) - (*rr - da + db) / (
	    d__3 * (d__3 * d__3)) + (*rr - da - db) / (d__5 * (d__5 * d__5)) 
	    + (*rr + da + db) / (d__7 * (d__7 * d__7));
/* Computing 2nd power */
    d__2 = *rr + da;
/* Computing 2nd power */
    d__3 = qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + adq);
/* Computing 2nd power */
    d__5 = *rr - da;
/* Computing 2nd power */
    d__6 = qb;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 * 4. + adq);
/* Computing 2nd power */
    d__8 = *rr + da;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + adq);
/* Computing 2nd power */
    d__10 = *rr - da;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + adq);
    dzqxx = (*rr + da) * 2. / (d__1 * (d__1 * d__1)) - (*rr - da) * 2. / (
	    d__4 * (d__4 * d__4)) - (*rr + da) * 2. / (d__7 * (d__7 * d__7)) 
	    + (*rr - da) * 2. / (d__9 * (d__9 * d__9));
/* Computing 2nd power */
    d__2 = *rr - db;
/* Computing 2nd power */
    d__3 = qa;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + aqd);
/* Computing 2nd power */
    d__5 = *rr + db;
/* Computing 2nd power */
    d__6 = qa;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 * 4. + aqd);
/* Computing 2nd power */
    d__8 = *rr - db;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + aqd);
/* Computing 2nd power */
    d__10 = *rr + db;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + aqd);
    qxxdz = (*rr - db) * 2. / (d__1 * (d__1 * d__1)) - (*rr + db) * 2. / (
	    d__4 * (d__4 * d__4)) - (*rr - db) * 2. / (d__7 * (d__7 * d__7)) 
	    + (*rr + db) * 2. / (d__9 * (d__9 * d__9));
/* Computing 2nd power */
    d__2 = *rr + da - qb * 2.;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + adq);
/* Computing 2nd power */
    d__4 = *rr - da - qb * 2.;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + adq);
/* Computing 2nd power */
    d__6 = *rr + da + qb * 2.;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + adq);
/* Computing 2nd power */
    d__8 = *rr - da + qb * 2.;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + adq);
/* Computing 2nd power */
    d__10 = *rr - da;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + adq);
/* Computing 2nd power */
    d__12 = *rr + da;
/* Computing 3rd power */
    d__11 = sqrt(d__12 * d__12 + adq);
    dzqzz = (*rr + da - qb * 2.) / (d__1 * (d__1 * d__1)) - (*rr - da - qb * 
	    2.) / (d__3 * (d__3 * d__3)) + (*rr + da + qb * 2.) / (d__5 * (
	    d__5 * d__5)) - (*rr - da + qb * 2.) / (d__7 * (d__7 * d__7)) + (*
	    rr - da) * 2. / (d__9 * (d__9 * d__9)) - (*rr + da) * 2. / (d__11 
	    * (d__11 * d__11));
/* Computing 2nd power */
    d__2 = *rr + qa * 2. - db;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + aqd);
/* Computing 2nd power */
    d__4 = *rr + qa * 2. + db;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + aqd);
/* Computing 2nd power */
    d__6 = *rr - qa * 2. - db;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + aqd);
/* Computing 2nd power */
    d__8 = *rr - qa * 2. + db;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + aqd);
/* Computing 2nd power */
    d__10 = *rr - db;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + aqd);
/* Computing 2nd power */
    d__12 = *rr + db;
/* Computing 3rd power */
    d__11 = sqrt(d__12 * d__12 + aqd);
    qzzdz = (*rr + qa * 2. - db) / (d__1 * (d__1 * d__1)) - (*rr + qa * 2. + 
	    db) / (d__3 * (d__3 * d__3)) + (*rr - qa * 2. - db) / (d__5 * (
	    d__5 * d__5)) - (*rr - qa * 2. + db) / (d__7 * (d__7 * d__7)) - (*
	    rr - db) * 2. / (d__9 * (d__9 * d__9)) + (*rr + db) * 2. / (d__11 
	    * (d__11 * d__11));
/* Computing 2nd power */
    d__2 = *rr;
/* Computing 2nd power */
    d__3 = qa - qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + aqq);
/* Computing 2nd power */
    d__5 = *rr;
/* Computing 2nd power */
    d__6 = qa + qb;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 * 4. + aqq);
/* Computing 2nd power */
    d__8 = *rr;
/* Computing 2nd power */
    d__9 = qa;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + d__9 * d__9 * 4. + aqq);
/* Computing 2nd power */
    d__11 = *rr;
/* Computing 2nd power */
    d__12 = qb;
/* Computing 3rd power */
    d__10 = sqrt(d__11 * d__11 + d__12 * d__12 * 4. + aqq);
/* Computing 2nd power */
    d__14 = *rr;
/* Computing 3rd power */
    d__13 = sqrt(d__14 * d__14 + aqq);
    qxxqxx = -(*rr * 2.) / (d__1 * (d__1 * d__1)) - *rr * 2. / (d__4 * (d__4 *
	     d__4)) + *rr * 4. / (d__7 * (d__7 * d__7)) + *rr * 4. / (d__10 * 
	    (d__10 * d__10)) - *rr * 4. / (d__13 * (d__13 * d__13));
/* Computing 2nd power */
    d__2 = *rr;
/* Computing 2nd power */
    d__3 = qa;
/* Computing 2nd power */
    d__4 = qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + d__4 * d__4 * 4. + aqq);
/* Computing 2nd power */
    d__6 = *rr;
/* Computing 2nd power */
    d__7 = qa;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + d__7 * d__7 * 4. + aqq);
/* Computing 2nd power */
    d__9 = *rr;
/* Computing 2nd power */
    d__10 = qb;
/* Computing 3rd power */
    d__8 = sqrt(d__9 * d__9 + d__10 * d__10 * 4. + aqq);
/* Computing 2nd power */
    d__12 = *rr;
/* Computing 3rd power */
    d__11 = sqrt(d__12 * d__12 + aqq);
    qxxqyy = -(*rr * 4.) / (d__1 * (d__1 * d__1)) + *rr * 4. / (d__5 * (d__5 *
	     d__5)) + *rr * 4. / (d__8 * (d__8 * d__8)) - *rr * 4. / (d__11 * 
	    (d__11 * d__11));
/* Computing 2nd power */
    d__2 = *rr - qb * 2.;
/* Computing 2nd power */
    d__3 = qa;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + aqq);
/* Computing 2nd power */
    d__5 = *rr + qb * 2.;
/* Computing 2nd power */
    d__6 = qa;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 * 4. + aqq);
/* Computing 2nd power */
    d__8 = *rr - qb * 2.;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + aqq);
/* Computing 2nd power */
    d__10 = *rr + qb * 2.;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + aqq);
/* Computing 2nd power */
    d__12 = *rr;
/* Computing 2nd power */
    d__13 = qa;
/* Computing 3rd power */
    d__11 = sqrt(d__12 * d__12 + d__13 * d__13 * 4. + aqq);
/* Computing 2nd power */
    d__15 = *rr;
/* Computing 3rd power */
    d__14 = sqrt(d__15 * d__15 + aqq);
    qxxqzz = (*rr - qb * 2.) * -2. / (d__1 * (d__1 * d__1)) - (*rr + qb * 2.) 
	    * 2. / (d__4 * (d__4 * d__4)) + (*rr - qb * 2.) * 2. / (d__7 * (
	    d__7 * d__7)) + (*rr + qb * 2.) * 2. / (d__9 * (d__9 * d__9)) + *
	    rr * 4. / (d__11 * (d__11 * d__11)) - *rr * 4. / (d__14 * (d__14 *
	     d__14));
/* Computing 2nd power */
    d__2 = *rr + qa * 2.;
/* Computing 2nd power */
    d__3 = qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 * 4. + aqq);
/* Computing 2nd power */
    d__5 = *rr - qa * 2.;
/* Computing 2nd power */
    d__6 = qb;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 * 4. + aqq);
/* Computing 2nd power */
    d__8 = *rr + qa * 2.;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + aqq);
/* Computing 2nd power */
    d__10 = *rr - qa * 2.;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + aqq);
/* Computing 2nd power */
    d__12 = *rr;
/* Computing 2nd power */
    d__13 = qb;
/* Computing 3rd power */
    d__11 = sqrt(d__12 * d__12 + d__13 * d__13 * 4. + aqq);
/* Computing 2nd power */
    d__15 = *rr;
/* Computing 3rd power */
    d__14 = sqrt(d__15 * d__15 + aqq);
    qzzqxx = (*rr + qa * 2.) * -2. / (d__1 * (d__1 * d__1)) - (*rr - qa * 2.) 
	    * 2. / (d__4 * (d__4 * d__4)) + (*rr + qa * 2.) * 2. / (d__7 * (
	    d__7 * d__7)) + (*rr - qa * 2.) * 2. / (d__9 * (d__9 * d__9)) + *
	    rr * 4. / (d__11 * (d__11 * d__11)) - *rr * 4. / (d__14 * (d__14 *
	     d__14));
/* Computing 2nd power */
    d__2 = *rr + qa * 2. - qb * 2.;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + aqq);
/* Computing 2nd power */
    d__4 = *rr + qa * 2. + qb * 2.;
/* Computing 3rd power */
    d__3 = sqrt(d__4 * d__4 + aqq);
/* Computing 2nd power */
    d__6 = *rr - qa * 2. - qb * 2.;
/* Computing 3rd power */
    d__5 = sqrt(d__6 * d__6 + aqq);
/* Computing 2nd power */
    d__8 = *rr - qa * 2. + qb * 2.;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + aqq);
/* Computing 2nd power */
    d__10 = *rr - qa * 2.;
/* Computing 3rd power */
    d__9 = sqrt(d__10 * d__10 + aqq);
/* Computing 2nd power */
    d__12 = *rr + qa * 2.;
/* Computing 3rd power */
    d__11 = sqrt(d__12 * d__12 + aqq);
/* Computing 2nd power */
    d__14 = *rr - qb * 2.;
/* Computing 3rd power */
    d__13 = sqrt(d__14 * d__14 + aqq);
/* Computing 2nd power */
    d__16 = *rr + qb * 2.;
/* Computing 3rd power */
    d__15 = sqrt(d__16 * d__16 + aqq);
/* Computing 2nd power */
    d__18 = *rr;
/* Computing 3rd power */
    d__17 = sqrt(d__18 * d__18 + aqq);
    qzzqzz = -(*rr + qa * 2. - qb * 2.) / (d__1 * (d__1 * d__1)) - (*rr + qa *
	     2. + qb * 2.) / (d__3 * (d__3 * d__3)) - (*rr - qa * 2. - qb * 
	    2.) / (d__5 * (d__5 * d__5)) - (*rr - qa * 2. + qb * 2.) / (d__7 *
	     (d__7 * d__7)) + (*rr - qa * 2.) * 2. / (d__9 * (d__9 * d__9)) + 
	    (*rr + qa * 2.) * 2. / (d__11 * (d__11 * d__11)) + (*rr - qb * 2.)
	     * 2. / (d__13 * (d__13 * d__13)) + (*rr + qb * 2.) * 2. / (d__15 
	    * (d__15 * d__15)) - *rr * 4. / (d__17 * (d__17 * d__17));
/* Computing 2nd power */
    d__2 = *rr - qb;
/* Computing 2nd power */
    d__3 = da - qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 + adq);
/* Computing 2nd power */
    d__5 = *rr + qb;
/* Computing 2nd power */
    d__6 = da - qb;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 + adq);
/* Computing 2nd power */
    d__8 = *rr - qb;
/* Computing 2nd power */
    d__9 = da + qb;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + d__9 * d__9 + adq);
/* Computing 2nd power */
    d__11 = *rr + qb;
/* Computing 2nd power */
    d__12 = da + qb;
/* Computing 3rd power */
    d__10 = sqrt(d__11 * d__11 + d__12 * d__12 + adq);
    dxqxz = (*rr - qb) * 2. / (d__1 * (d__1 * d__1)) - (*rr + qb) * 2. / (
	    d__4 * (d__4 * d__4)) - (*rr - qb) * 2. / (d__7 * (d__7 * d__7)) 
	    + (*rr + qb) * 2. / (d__10 * (d__10 * d__10));
/* Computing 2nd power */
    d__2 = *rr + qa;
/* Computing 2nd power */
    d__3 = qa - db;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 + aqd);
/* Computing 2nd power */
    d__5 = *rr - qa;
/* Computing 2nd power */
    d__6 = qa - db;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 + aqd);
/* Computing 2nd power */
    d__8 = *rr + qa;
/* Computing 2nd power */
    d__9 = qa + db;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + d__9 * d__9 + aqd);
/* Computing 2nd power */
    d__11 = *rr - qa;
/* Computing 2nd power */
    d__12 = qa + db;
/* Computing 3rd power */
    d__10 = sqrt(d__11 * d__11 + d__12 * d__12 + aqd);
    qxzdx = (*rr + qa) * 2. / (d__1 * (d__1 * d__1)) - (*rr - qa) * 2. / (
	    d__4 * (d__4 * d__4)) - (*rr + qa) * 2. / (d__7 * (d__7 * d__7)) 
	    + (*rr - qa) * 2. / (d__10 * (d__10 * d__10));
/* Computing 2nd power */
    d__2 = *rr + qa - qb;
/* Computing 2nd power */
    d__3 = qa - qb;
/* Computing 3rd power */
    d__1 = sqrt(d__2 * d__2 + d__3 * d__3 + aqq);
/* Computing 2nd power */
    d__5 = *rr + qa + qb;
/* Computing 2nd power */
    d__6 = qa - qb;
/* Computing 3rd power */
    d__4 = sqrt(d__5 * d__5 + d__6 * d__6 + aqq);
/* Computing 2nd power */
    d__8 = *rr - qa - qb;
/* Computing 2nd power */
    d__9 = qa - qb;
/* Computing 3rd power */
    d__7 = sqrt(d__8 * d__8 + d__9 * d__9 + aqq);
/* Computing 2nd power */
    d__11 = *rr - qa + qb;
/* Computing 2nd power */
    d__12 = qa - qb;
/* Computing 3rd power */
    d__10 = sqrt(d__11 * d__11 + d__12 * d__12 + aqq);
/* Computing 2nd power */
    d__14 = *rr + qa - qb;
/* Computing 2nd power */
    d__15 = qa + qb;
/* Computing 3rd power */
    d__13 = sqrt(d__14 * d__14 + d__15 * d__15 + aqq);
/* Computing 2nd power */
    d__17 = *rr + qa + qb;
/* Computing 2nd power */
    d__18 = qa + qb;
/* Computing 3rd power */
    d__16 = sqrt(d__17 * d__17 + d__18 * d__18 + aqq);
/* Computing 2nd power */
    d__20 = *rr - qa - qb;
/* Computing 2nd power */
    d__21 = qa + qb;
/* Computing 3rd power */
    d__19 = sqrt(d__20 * d__20 + d__21 * d__21 + aqq);
/* Computing 2nd power */
    d__23 = *rr - qa + qb;
/* Computing 2nd power */
    d__24 = qa + qb;
/* Computing 3rd power */
    d__22 = sqrt(d__23 * d__23 + d__24 * d__24 + aqq);
    qxzqxz = (*rr + qa - qb) * -2. / (d__1 * (d__1 * d__1)) + (*rr + qa + qb) 
	    * 2. / (d__4 * (d__4 * d__4)) + (*rr - qa - qb) * 2. / (d__7 * (
	    d__7 * d__7)) - (*rr - qa + qb) * 2. / (d__10 * (d__10 * d__10)) 
	    + (*rr + qa - qb) * 2. / (d__13 * (d__13 * d__13)) - (*rr + qa + 
	    qb) * 2. / (d__16 * (d__16 * d__16)) - (*rr - qa - qb) * 2. / (
	    d__19 * (d__19 * d__19)) + (*rr - qa + qb) * 2. / (d__22 * (d__22 
	    * d__22));
    dg[6] = term * dzdz / 4.;
    dg[7] = term * dxdx / 4.;
    dg[8] = -term * (edz / 2. + qzzdz / 8.);
    dg[9] = -term * (edz / 2. + qxxdz / 8.);
    dg[10] = -(term * qxzdx) / 8.;
    dg[13] = -term * (dze / 2. + dzqzz / 8.);
    dg[14] = -term * (dze / 2. + dzqxx / 8.);
    dg[15] = -(term * dxqxz) / 8.;
    dg[16] = term * (ee + eqzz / 4. + qzze / 4. + qzzqzz / 16.);
    dg[17] = term * (ee + eqzz / 4. + qxxe / 4. + qxxqzz / 16.);
    dg[18] = term * (ee + eqxx / 4. + qzze / 4. + qzzqxx / 16.);
    dg[19] = term * (ee + eqxx / 4. + qxxe / 4. + qxxqxx / 16.);
    dg[20] = term * qxzqxz / 16.;
    dg[21] = term * (ee + eqxx / 4. + qxxe / 4. + qxxqyy / 16.);
    dg[22] = term * (qxxqxx - qxxqyy) / 32.;
    return 0;
} /* delri_ */

