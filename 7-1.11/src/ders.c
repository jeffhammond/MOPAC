/* ders.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal ds[16], dg[22], dr[100], tdx[3], tdy[3], tdz[3];
} derivs_;

#define derivs_1 derivs_

struct {
    doublereal cg[360]	/* was [60][6] */, zg[360]	/* was [60][6] */;
} temp_;

#define temp_1 temp_

/* Subroutine */ int ders_(integer *m, integer *n, doublereal *rr, doublereal 
	*del1, doublereal *del2, doublereal *del3, integer *is, integer *iol)
{
    /* System generated locals */
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal), exp(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal a0, ss[36]	/* was [6][6] */, adb, amb, abn, apb, 
	    adr;

/* *********************************************************************** */
/*                                                                      * */
/*    ON INPUT M    = INDEX OF FIRST ATOMIC ORBITAL                     * */
/*             N    = INDEX OF SECOND ATOMIC ORBITAL                    * */
/*             RR   = SQUARE IF INTERATOMIC DIATANCE (IN BOHR)          * */
/*             DEL1 = CATERSIAN DISTANCE IN DERIVATIVE DIRECTION        * */
/*             DEL2 = CARTESIAN DISTANCE IN M A.O.'S DIRECTION          * */
/*             DEL3 = CARTESIAN DISTANCE IN N A.O.'S DIRECTION          * */
/*             IS   = INDICATES TYPE OF A.O.-A.O. INTERACTION           * */
/*                  = 1 S/S, 2 S/P', 3 S/P, 4 P'/S, 5 P/S, 6 P/P',      * */
/*                    7 P'/P", 8 P'P', 9 P/P                            * */
/*             IOL  = INDEX FOR STORING DERIVATIVES IN DS               * */
/*                                                                      * */
/* *********************************************************************** */
    a0 = .529167;
    for (i__ = 1; i__ <= 6; ++i__) {
	for (j = 1; j <= 6; ++j) {
	    ss[i__ + j * 6 - 7] = 0.;
	    apb = temp_1.zg[*m + i__ * 60 - 61] * temp_1.zg[*n + j * 60 - 61];
	    amb = temp_1.zg[*m + i__ * 60 - 61] + temp_1.zg[*n + j * 60 - 61];
	    adb = apb / amb;
/* Computing MIN */
	    d__1 = adb * *rr;
	    adr = min(d__1,35.);
	    switch (*is) {
		case 1:  goto L10;
		case 2:  goto L20;
		case 3:  goto L30;
		case 4:  goto L40;
		case 5:  goto L50;
		case 6:  goto L60;
		case 7:  goto L70;
		case 8:  goto L80;
		case 9:  goto L90;
	    }
L10:
/* Computing 2nd power */
	    d__1 = a0;
	    abn = adb * -2. * *del1 / (d__1 * d__1);
	    goto L100;
L20:
/* Computing 2nd power */
	    d__1 = adb;
/* Computing 3rd power */
	    d__2 = a0;
	    abn = d__1 * d__1 * -4. * *del1 * *del2 / (sqrt(temp_1.zg[*n + j *
		     60 - 61]) * (d__2 * (d__2 * d__2)));
	    goto L100;
L30:
/* Computing 2nd power */
	    d__1 = *del1;
/* Computing 2nd power */
	    d__2 = a0;
	    abn = adb * 2. / (sqrt(temp_1.zg[*n + j * 60 - 61]) * a0) * (1. - 
		    adb * 2. * (d__1 * d__1) / (d__2 * d__2));
	    goto L100;
L40:
/* Computing 2nd power */
	    d__1 = adb;
/* Computing 3rd power */
	    d__2 = a0;
	    abn = d__1 * d__1 * 4. * *del1 * *del2 / (sqrt(temp_1.zg[*m + i__ 
		    * 60 - 61]) * (d__2 * (d__2 * d__2)));
	    goto L100;
L50:
/* Computing 2nd power */
	    d__1 = *del1;
/* Computing 2nd power */
	    d__2 = a0;
	    abn = -(adb * 2. / (sqrt(temp_1.zg[*m + i__ * 60 - 61]) * a0)) * (
		    1. - adb * 2. * (d__1 * d__1) / (d__2 * d__2));
	    goto L100;
L60:
/* Computing 2nd power */
	    d__1 = adb;
/* Computing 2nd power */
	    d__2 = a0;
/* Computing 2nd power */
	    d__3 = *del1;
/* Computing 2nd power */
	    d__4 = a0;
	    abn = -(d__1 * d__1 * 4. * *del2 / (sqrt(apb) * (d__2 * d__2))) * 
		    (1. - adb * 2. * (d__3 * d__3) / (d__4 * d__4));
	    goto L100;
L70:
/* Computing 3rd power */
	    d__1 = adb;
/* Computing 4th power */
	    d__2 = a0, d__2 *= d__2;
	    abn = d__1 * (d__1 * d__1) * 8. * *del1 * *del2 * *del3 / (sqrt(
		    apb) * (d__2 * d__2));
	    goto L100;
L80:
/* Computing 2nd power */
	    d__1 = adb;
/* Computing 2nd power */
	    d__2 = a0;
/* Computing 2nd power */
	    d__3 = *del2;
/* Computing 2nd power */
	    d__4 = a0;
	    abn = -(d__1 * d__1 * 8. * *del1 / (sqrt(apb) * (d__2 * d__2))) * 
		    (.5 - adb * (d__3 * d__3) / (d__4 * d__4));
	    goto L100;
L90:
/* Computing 2nd power */
	    d__1 = adb;
/* Computing 2nd power */
	    d__2 = a0;
/* Computing 2nd power */
	    d__3 = *del1;
/* Computing 2nd power */
	    d__4 = a0;
	    abn = -(d__1 * d__1 * 8. * *del1 / (sqrt(apb) * (d__2 * d__2))) * 
		    (1.5 - adb * (d__3 * d__3) / (d__4 * d__4));
L100:
/* Computing 3rd power */
	    d__1 = sqrt(apb) * 2. / amb;
	    ss[i__ + j * 6 - 7] = sqrt(d__1 * (d__1 * d__1)) * exp(-adr) * 
		    abn;
/* L110: */
	}
    }
    for (i__ = 1; i__ <= 6; ++i__) {
	for (j = 1; j <= 6; ++j) {
	    derivs_1.ds[*iol - 1] += ss[i__ + j * 6 - 7] * temp_1.cg[*m + i__ 
		    * 60 - 61] * temp_1.cg[*n + j * 60 - 61];
/* L120: */
	}
    }
    return 0;
} /* ders_ */

