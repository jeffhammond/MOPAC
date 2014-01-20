/* aababc.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

struct {
    doublereal occa[8];
} baseoc_;

#define baseoc_1 baseoc_

struct {
    integer ispqr[512]	/* was [64][8] */, is, iloop, jloop;
} spqr_;

#define spqr_1 spqr_


/*         Notice of Public Domain nature of this Program */

/*      'This computer program is a work of the United States */
/*       Government and as such is not subject to protection by */
/*       copyright (17 U.S.C. # 105.)  Any person who fraudulently */
/*       places a copyright notice or does any other act contrary */
/*       to the provisions of 17 U.S. Code 506(c) shall be subject */
/*       to the penalties provided therein.  This notice shall not */
/*       be altered or removed from this software and is to be on */
/*       all reproductions.' */

doublereal aababc_(integer *iocca1, integer *ioccb1, integer *iocca2, integer 
	*nmos)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, ij;
    static doublereal sum;

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
/* ********************************************************************** */

/* AABABC EVALUATES THE C.I. MATRIX ELEMENT FOR TWO MICROSTATES DIFFERING */
/*       BY BETA ELECTRON. THAT IS, ONE MICROSTATE HAS A BETA ELECTRON */
/*       IN PSI(I) WHICH, IN THE OTHER MICROSTATE IS IN PSI(J) */

/* ********************************************************************** */
    /* Parameter adjustments */
    --iocca2;
    --ioccb1;
    --iocca1;

    /* Function Body */
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	if (iocca1[i__] != iocca2[i__]) {
	    goto L20;
	}
    }
L20:
    ij = ioccb1[i__];
    i__1 = *nmos;
    for (j = i__ + 1; j <= i__1; ++j) {
	if (iocca1[j] != iocca2[j]) {
	    goto L40;
	}
/* L30: */
	ij = ij + iocca1[j] + ioccb1[j];
    }
L40:
    sum = 0.;
    i__1 = *nmos;
    for (k = 1; k <= i__1; ++k) {
/* L50: */
	sum = sum + (xyijkl_1.xy[i__ + (j + (k + (k << 3) << 3) << 3) - 585] 
		- xyijkl_1.xy[i__ + (k + (j + (k << 3) << 3) << 3) - 585]) * (
		iocca1[k] - baseoc_1.occa[k - 1]) + xyijkl_1.xy[i__ + (j + (k 
		+ (k << 3) << 3) << 3) - 585] * (ioccb1[k] - baseoc_1.occa[k 
		- 1]);
    }
    if (ij % 2 == 1) {
	sum = -sum;
    }
    ret_val = sum;
    return ret_val;
} /* aababc_ */

doublereal aabbcd_(integer *iocca1, integer *ioccb1, integer *iocca2, integer 
	*ioccb2, integer *nmos)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, l, m, ij;
    static doublereal xr;

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
/* ********************************************************************** */

/* AABBCD EVALUATES THE C.I. MATRIX ELEMENT FOR TWO MICROSTATES DIFFERING */
/*       BY TWO SETS OF M.O.S. ONE MICROSTATE HAS AN ALPHA ELECTRON */
/*       IN PSI(I) AND A BETA ELECTRON IN PSI(K) FOR WHICH THE OTHER */
/*       MICROSTATE HAS AN ALPHA ELECTRON IN PSI(J) AND A BETA ELECTRON */
/*       IN PSI(L) */

/* ********************************************************************** */
    /* Parameter adjustments */
    --ioccb2;
    --iocca2;
    --ioccb1;
    --iocca1;

    /* Function Body */
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	if (iocca1[i__] != iocca2[i__]) {
	    goto L20;
	}
    }
L20:
    i__1 = *nmos;
    for (j = i__ + 1; j <= i__1; ++j) {
/* L30: */
	if (iocca1[j] != iocca2[j]) {
	    goto L40;
	}
    }
L40:
    i__1 = *nmos;
    for (k = 1; k <= i__1; ++k) {
/* L50: */
	if (ioccb1[k] != ioccb2[k]) {
	    goto L60;
	}
    }
L60:
    i__1 = *nmos;
    for (l = k + 1; l <= i__1; ++l) {
/* L70: */
	if (ioccb1[l] != ioccb2[l]) {
	    goto L80;
	}
    }
L80:
    if (i__ == k && j == l && iocca1[i__] != ioccb1[i__]) {
	spqr_1.ispqr[spqr_1.iloop + (spqr_1.is << 6) - 65] = spqr_1.jloop;
	++spqr_1.is;
    }
    if (iocca1[i__] < iocca2[i__]) {
	m = i__;
	i__ = j;
	j = m;
    }
    if (ioccb1[k] < ioccb2[k]) {
	m = k;
	k = l;
	l = m;
    }
    xr = xyijkl_1.xy[i__ + (j + (k + (l << 3) << 3) << 3) - 585];
/* #      WRITE(6,'(4I5,F12.6)')I,J,K,L,XR */

/*   NOW UNTANGLE THE MICROSTATES */

    ij = 1;
    if (i__ > k && j > l || i__ <= k && j <= l) {
	ij = 0;
    }
    if (i__ > k) {
	ij = ij + iocca1[k] + ioccb1[i__];
    }
    if (j > l) {
	ij = ij + iocca2[l] + ioccb2[j];
    }
    if (i__ > k) {
	m = i__;
	i__ = k;
	k = m;
    }
    i__1 = k;
    for (m = i__; m <= i__1; ++m) {
/* L90: */
	ij = ij + ioccb1[m] + iocca1[m];
    }
    if (j > l) {
	m = j;
	j = l;
	l = m;
    }
    i__1 = l;
    for (m = j; m <= i__1; ++m) {
/* L100: */
	ij = ij + ioccb2[m] + iocca2[m];
    }

/*   IJ IN THE PERMUTATION NUMBER, .EQUIV. -1 IF IJ IS ODD. */

    if (ij % 2 == 1) {
	xr = -xr;
    }
    ret_val = xr;
    return ret_val;
} /* aabbcd_ */

doublereal aabacd_(integer *iocca1, integer *ioccb1, integer *iocca2, integer 
	*ioccb2, integer *nmos)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, l, ij;
    static doublereal sum;

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
/* ********************************************************************** */

/* AABACD EVALUATES THE C.I. MATRIX ELEMENT FOR TWO MICROSTATES DIFFERING */
/*       BY TWO ALPHA MOS. ONE MICROSTATE HAS ALPHA ELECTRONS IN */
/*       M.O.S PSI(I) AND PSI(J) FOR WHICH THE OTHER MICROSTATE HAS */
/*       ELECTRONS IN PSI(K) AND PSI(L) */

/* ********************************************************************** */
    /* Parameter adjustments */
    --ioccb2;
    --iocca2;
    --ioccb1;
    --iocca1;

    /* Function Body */
    ij = 0;
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	if (iocca1[i__] < iocca2[i__]) {
	    goto L20;
	}
    }
L20:
    i__1 = *nmos;
    for (j = i__ + 1; j <= i__1; ++j) {
	if (iocca1[j] < iocca2[j]) {
	    goto L40;
	}
/* L30: */
	ij = ij + iocca2[j] + ioccb2[j];
    }
L40:
    i__1 = *nmos;
    for (k = 1; k <= i__1; ++k) {
/* L50: */
	if (iocca1[k] > iocca2[k]) {
	    goto L60;
	}
    }
L60:
    i__1 = *nmos;
    for (l = k + 1; l <= i__1; ++l) {
	if (iocca1[l] > iocca2[l]) {
	    goto L80;
	}
/* L70: */
	ij = ij + iocca1[l] + ioccb1[l];
    }
L80:
    ij = ij + ioccb2[i__] + ioccb1[k];
    sum = xyijkl_1.xy[i__ + (k + (j + (l << 3) << 3) << 3) - 585] - 
	    xyijkl_1.xy[i__ + (l + (k + (j << 3) << 3) << 3) - 585];
    if (ij % 2 == 1) {
	sum = -sum;
    }
    ret_val = sum;
    return ret_val;
} /* aabacd_ */

doublereal babbbc_(integer *iocca1, integer *ioccb1, integer *ioccb2, integer 
	*nmos)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, ij;
    static doublereal sum;

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
/* ********************************************************************** */

/* BABBBC EVALUATES THE C.I. MATRIX ELEMENT FOR TWO MICROSTATES DIFFERING */
/*       BY ONE BETA ELECTRON. THAT IS, ONE MICROSTATE HAS A BETA */
/*       ELECTRON IN PSI(I) AND THE OTHER MICROSTATE HAS AN ELECTRON IN */
/*       PSI(J). */
/* ********************************************************************** */
    /* Parameter adjustments */
    --ioccb2;
    --ioccb1;
    --iocca1;

    /* Function Body */
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	if (ioccb1[i__] != ioccb2[i__]) {
	    goto L20;
	}
    }
L20:
    ij = 0;
    i__1 = *nmos;
    for (j = i__ + 1; j <= i__1; ++j) {
	if (ioccb1[j] != ioccb2[j]) {
	    goto L40;
	}
/* L30: */
	ij = ij + iocca1[j] + ioccb1[j];
    }
L40:
    ij += iocca1[j];

/*   THE UNPAIRED M.O.S ARE I AND J */
    sum = 0.;
    i__1 = *nmos;
    for (k = 1; k <= i__1; ++k) {
/* L50: */
	sum = sum + (xyijkl_1.xy[i__ + (j + (k + (k << 3) << 3) << 3) - 585] 
		- xyijkl_1.xy[i__ + (k + (j + (k << 3) << 3) << 3) - 585]) * (
		ioccb1[k] - baseoc_1.occa[k - 1]) + xyijkl_1.xy[i__ + (j + (k 
		+ (k << 3) << 3) << 3) - 585] * (iocca1[k] - baseoc_1.occa[k 
		- 1]);
    }
    if (ij % 2 == 1) {
	sum = -sum;
    }
    ret_val = sum;
    return ret_val;
} /* babbbc_ */

doublereal babbcd_(integer *iocca1, integer *ioccb1, integer *iocca2, integer 
	*ioccb2, integer *nmos)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j, k, l, ij;
    static doublereal one;

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
/* ********************************************************************** */

/* BABBCD EVALUATES THE C.I. MATRIX ELEMENT FOR TWO MICROSTATES DIFFERING */
/*       BY TWO BETA MOS. ONE MICROSTATE HAS BETA ELECTRONS IN */
/*       M.O.S PSI(I) AND PSI(J) FOR WHICH THE OTHER MICROSTATE HAS */
/*       ELECTRONS IN PSI(K) AND PSI(L) */

/* ********************************************************************** */
    /* Parameter adjustments */
    --ioccb2;
    --iocca2;
    --ioccb1;
    --iocca1;

    /* Function Body */
    ij = 0;
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	if (ioccb1[i__] < ioccb2[i__]) {
	    goto L20;
	}
    }
L20:
    i__1 = *nmos;
    for (j = i__ + 1; j <= i__1; ++j) {
	if (ioccb1[j] < ioccb2[j]) {
	    goto L40;
	}
/* L30: */
	ij = ij + iocca2[j] + ioccb2[j];
    }
L40:
    ij += iocca2[j];
    i__1 = *nmos;
    for (k = 1; k <= i__1; ++k) {
/* L50: */
	if (ioccb1[k] > ioccb2[k]) {
	    goto L60;
	}
    }
L60:
    i__1 = *nmos;
    for (l = k + 1; l <= i__1; ++l) {
	if (ioccb1[l] > ioccb2[l]) {
	    goto L80;
	}
/* L70: */
	ij = ij + iocca1[l] + ioccb1[l];
    }
L80:
    ij += iocca1[l];
    if (ij / 2 << 1 == ij) {
	one = 1.;
    } else {
	one = -1.;
    }
    ret_val = (xyijkl_1.xy[i__ + (k + (j + (l << 3) << 3) << 3) - 585] - 
	    xyijkl_1.xy[i__ + (l + (j + (k << 3) << 3) << 3) - 585]) * one;
    return ret_val;
} /* babbcd_ */

doublereal diagi_(integer *ialpha, integer *ibeta, doublereal *eiga, 
	doublereal *xy, integer *nmos)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    static integer i__, j;
    static doublereal x;

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

/*  CALCULATES THE ENERGY OF A MICROSTATE DEFINED BY IALPHA AND IBETA */

/* *********************************************************************** */
    /* Parameter adjustments */
    --eiga;
    xy -= 585;
    --ibeta;
    --ialpha;

    /* Function Body */
    x = 0.;
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ialpha[i__] != 0) {
	    x += eiga[i__];
	    i__2 = *nmos;
	    for (j = 1; j <= i__2; ++j) {
		x += (xy[i__ + (i__ + (j + (j << 3) << 3) << 3)] - xy[i__ + (
			j + (i__ + (j << 3) << 3) << 3)]) * ialpha[j] * .5 + 
			xy[i__ + (i__ + (j + (j << 3) << 3) << 3)] * ibeta[j];
/* L10: */
	    }
	}
/* L20: */
    }
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ibeta[i__] != 0) {
	    x += eiga[i__];
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
/* L30: */
		x += (xy[i__ + (i__ + (j + (j << 3) << 3) << 3)] - xy[i__ + (
			j + (i__ + (j << 3) << 3) << 3)]) * ibeta[j];
	    }
	}
/* L40: */
    }
    ret_val = x;
    return ret_val;
} /* diagi_ */

