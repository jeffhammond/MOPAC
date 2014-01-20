/* addfck.f -- translated by f2c (version 20020621).
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
	    was [3][1082] */, bh[400];
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

/* Subroutine */ int addfck_(doublereal *f, doublereal *p, integer *numat, 
	integer *nat, integer *nfirst, integer *nlast)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;

    /* Local variables */
    static integer i__, j, i0, i1, ia, ic, id, ja, jc, jd, im, jm;
    static doublereal fim;
    static integer idel, jdel, iden, jden, kden;

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
/*      COMMON /MOLKST/ NUMAT,NAT(NUMATM),NFIRST(NUMATM),NMIDLE(NUMATM), */
/*     1                NLAST(NUMATM), NORBS, NELECS,NALPHA,NBETA, */
/*     2                NCLOSE,NOPEN,NDUMY,FRACT */
    /* Parameter adjustments */
    --nlast;
    --nfirst;
    --nat;
    --p;
    --f;

    /* Function Body */
    i0 = solv_1.nps2 + solv_1.nden * solv_1.nps;
    iden = 0;
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = nfirst[i__];
	idel = nlast[i__] - ia;
	im = ia * (ia + 1) / 2 - 1;
	i__2 = idel;
	for (ic = 0; ic <= i__2; ++ic) {
	    i__3 = ic;
	    for (id = 0; id <= i__3; ++id) {
		++im;
		++iden;
		fim = 0.;
		jden = 0;
		i__4 = *numat;
		for (j = 1; j <= i__4; ++j) {
		    ja = nfirst[j];
		    jdel = nlast[j] - ja;
		    jm = ja * (ja + 1) / 2 - 1;
		    i__5 = jdel;
		    for (jc = 0; jc <= i__5; ++jc) {
			i__6 = jc;
			for (jd = 0; jd <= i__6; ++jd) {
			    ++jm;
			    ++jden;
			    kden = max(iden,jden);
			    i1 = kden * (kden - 3) / 2 + iden + jden + i0;
			    fim += solv_1.abcmat[i1 - 1] * p[jm];
/* L10: */
			}
			jm = jm + ja - 1;
/* L20: */
		    }
/* L30: */
		}
		f[im] += fim * 2;
/* L40: */
	    }
	    f[im] += fim * 2;
	    im = im + ia - 1;
/* L50: */
	}
/* L60: */
    }
    return 0;
} /* addfck_ */

