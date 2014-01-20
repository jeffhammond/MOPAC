/* mecih.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ispqr[512]	/* was [64][8] */, is, i__, k;
} spqr_;

#define spqr_1 spqr_

struct {
    integer nalpha[64];
} nalmat_;

#define nalmat_1 nalmat_

struct {
    integer microa[2048]	/* was [8][256] */, microb[2048]	/* 
	    was [8][256] */;
} micros_;

#define micros_1 micros_

/* Subroutine */ int mecih_(doublereal *diag, doublereal *cimat, integer *
	nmos, integer *lab)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer j, ik, ix, iy;
    extern doublereal aababc_(integer *, integer *, integer *, integer *), 
	    aabacd_(integer *, integer *, integer *, integer *, integer *), 
	    aabbcd_(integer *, integer *, integer *, integer *, integer *), 
	    babbcd_(integer *, integer *, integer *, integer *, integer *), 
	    babbbc_(integer *, integer *, integer *, integer *);

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

/*     BUILD THE C.I. MATRIX 'CIMAT' IN PACKED CANONICAL FORM. */


    /* Parameter adjustments */
    --cimat;
    --diag;

    /* Function Body */
    ik = 0;

/*     OUTER LOOP TO FILL C.I. MATRIX. */
    i__1 = *lab;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	spqr_1.is = 2;

/*     INNER LOOP. */
	i__2 = spqr_1.i__;
	for (spqr_1.k = 1; spqr_1.k <= i__2; ++spqr_1.k) {
	    ++ik;
	    cimat[ik] = 0.;
	    ix = 0;
	    iy = 0;
	    i__3 = *nmos;
	    for (j = 1; j <= i__3; ++j) {
		ix += (i__4 = micros_1.microa[j + (spqr_1.i__ << 3) - 9] - 
			micros_1.microa[j + (spqr_1.k << 3) - 9], abs(i__4));
/* L10: */
		iy += (i__4 = micros_1.microb[j + (spqr_1.i__ << 3) - 9] - 
			micros_1.microb[j + (spqr_1.k << 3) - 9], abs(i__4));
	    }

/*                              CHECK IF MATRIX ELEMENT HAS TO BE ZERO */

	    if (ix + iy > 4 || nalmat_1.nalpha[spqr_1.i__ - 1] != 
		    nalmat_1.nalpha[spqr_1.k - 1]) {
		goto L20;
	    }
	    if (ix + iy == 4) {
		if (ix == 0) {
		    cimat[ik] = babbcd_(&micros_1.microa[(spqr_1.i__ << 3) - 
			    8], &micros_1.microb[(spqr_1.i__ << 3) - 8], &
			    micros_1.microa[(spqr_1.k << 3) - 8], &
			    micros_1.microb[(spqr_1.k << 3) - 8], nmos);
		} else if (ix == 2) {
		    cimat[ik] = aabbcd_(&micros_1.microa[(spqr_1.i__ << 3) - 
			    8], &micros_1.microb[(spqr_1.i__ << 3) - 8], &
			    micros_1.microa[(spqr_1.k << 3) - 8], &
			    micros_1.microb[(spqr_1.k << 3) - 8], nmos);
		} else {
		    cimat[ik] = aabacd_(&micros_1.microa[(spqr_1.i__ << 3) - 
			    8], &micros_1.microb[(spqr_1.i__ << 3) - 8], &
			    micros_1.microa[(spqr_1.k << 3) - 8], &
			    micros_1.microb[(spqr_1.k << 3) - 8], nmos);
		}
	    } else if (ix == 2) {
		cimat[ik] = aababc_(&micros_1.microa[(spqr_1.i__ << 3) - 8], &
			micros_1.microb[(spqr_1.i__ << 3) - 8], &
			micros_1.microa[(spqr_1.k << 3) - 8], nmos);
	    } else if (iy == 2) {
		cimat[ik] = babbbc_(&micros_1.microa[(spqr_1.i__ << 3) - 8], &
			micros_1.microb[(spqr_1.i__ << 3) - 8], &
			micros_1.microb[(spqr_1.k << 3) - 8], nmos);
	    } else {
		cimat[ik] = diag[spqr_1.i__];
	    }
L20:
	    ;
	}
/* L30: */
	spqr_1.ispqr[spqr_1.i__ - 1] = spqr_1.is - 1;
    }
    return 0;
} /* mecih_ */

