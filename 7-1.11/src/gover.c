/* gover.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nztype[107], mtype[30], ltype;
} natype_;

#define natype_1 natype_

struct {
    doublereal c__[360]	/* was [60][6] */, z__[360]	/* was [60][6] */;
} temp_;

#define temp_1 temp_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

/* Subroutine */ int gover_(integer *ni, integer *nj, doublereal *xi, 
	doublereal *xj, doublereal *r__, doublereal *sg)
{
    /* Initialized data */

    static integer ngauss = 6;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), exp(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal s[36]	/* was [6][6] */;
    static integer ka, kb, is;
    static doublereal adb;
    static integer ifa, ifb;
    static doublereal amb, apb, abn;
    static integer ila, ilb, nat, nbt;
    static doublereal tomb;

/* *********************************************************************** */
/*                                                                      * */
/*   GOVER CALCULATES THE OVERLAP INTEGRALS USING A GAUSSIAN EXPANSION  * */
/*         STO-6G BY R.F. STEWART, J. CHEM. PHYS., 52 431-438, 1970     * */
/*                                                                      * */
/*         ON INPUT   NI   =  ATOMIC NUMBER OF FIRST ATOM               * */
/*                    NJ   =  ATOMIC NUMBER OF SECOND ATOM              * */
/*                    R    =  INTERATOMIC DISTANCE IN ANGSTROMS         * */
/*         ON EXIT    S    =  9X9 ARRAY OF OVERLAPS, IN ORDER S,PX,PY,  * */
/*                            PZ                                        * */
/*                                                                      * */
/* *********************************************************************** */
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
    sg -= 10;
    --xj;
    --xi;

    /* Function Body */

/*    FIND START AND END OF GAUSSIAN */

    ifa = (natype_1.nztype[(0 + (0 + (*ni - 1 << 2))) / 4] << 2) - 3;
    if (temp_1.c__[ifa] != 0.) {
	ila = ifa + 3;
    } else {
	ila = ifa;
    }
    ifb = (natype_1.nztype[*nj - 1] << 2) - 3;
    if (temp_1.c__[ifb] != 0.) {
	ilb = ifb + 3;
    } else {
	ilb = ifb;
    }

/*  CONVERT R INTO AU */

    *r__ /= .529167;
/* Computing 2nd power */
    d__1 = *r__;
    *r__ = d__1 * d__1;
    ka = 0;
    i__1 = ila;
    for (i__ = ifa; i__ <= i__1; ++i__) {
	++ka;
	nat = ka - 1;
	kb = 0;
	i__2 = ilb;
	for (j = ifb; j <= i__2; ++j) {
	    ++kb;
	    nbt = kb - 1;

/*         DECIDE IS IT AN S-S, S-P, P-S, OR P-P OVERLAP */

	    if (nat > 0 && nbt > 0) {
/*    P-P */
		is = 4;
		tomb = (xi[nat] - xj[nat]) * (xi[nbt] - xj[nbt]) * 
			3.5711928576;
	    } else if (nat > 0) {
/*    P-S */
		is = 3;
		tomb = (xi[nat] - xj[nat]) * 1.88976;
	    } else if (nbt > 0) {
/*    S-P */
		is = 2;
		tomb = (xi[nbt] - xj[nbt]) * 1.88976;
	    } else {
/*    S-S */
		is = 1;
	    }
	    i__3 = ngauss;
	    for (k = 1; k <= i__3; ++k) {
		i__4 = ngauss;
		for (l = 1; l <= i__4; ++l) {
		    s[k + l * 6 - 7] = 0.;
		    amb = temp_1.z__[i__ + k * 60 - 61] + temp_1.z__[j + l * 
			    60 - 61];
		    apb = temp_1.z__[i__ + k * 60 - 61] * temp_1.z__[j + l * 
			    60 - 61];
		    adb = apb / amb;

/*           CHECK OF OVERLAP IS NON-ZERO BEFORE STARTING */

		    if (adb * *r__ < 90.) {
			abn = 1.;
			switch (is) {
			    case 1:  goto L50;
			    case 2:  goto L10;
			    case 3:  goto L20;
			    case 4:  goto L30;
			}
L10:
			abn = tomb * 2. * temp_1.z__[i__ + k * 60 - 61] * 
				sqrt(temp_1.z__[j + l * 60 - 61]) / amb;
			goto L50;
L20:
			abn = tomb * -2. * temp_1.z__[j + l * 60 - 61] * sqrt(
				temp_1.z__[i__ + k * 60 - 61]) / amb;
			goto L50;
L30:
			abn = -adb * tomb;
			if (nat == nbt) {
			    abn += .5;
			}
/* L40: */
			abn = abn * 4. * sqrt(apb) / amb;
L50:
/* Computing 3rd power */
			d__1 = sqrt(apb) * 2. / amb;
			s[k + l * 6 - 7] = sqrt(d__1 * (d__1 * d__1)) * exp(
				-adb * *r__) * abn;
		    }
/* L60: */
		}
	    }
	    sg[ka + kb * 9] = 0.;
	    i__4 = ngauss;
	    for (k = 1; k <= i__4; ++k) {
		i__3 = ngauss;
		for (l = 1; l <= i__3; ++l) {
/* L70: */
		    sg[ka + kb * 9] += s[k + l * 6 - 7] * temp_1.c__[i__ + k *
			     60 - 61] * temp_1.c__[j + l * 60 - 61];
		}
	    }
/* L80: */
	}
    }
    return 0;
} /* gover_ */

