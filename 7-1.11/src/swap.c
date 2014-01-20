/* swap.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal psi[300], stdpsi[300];
} swap0_;

#define swap0_1 swap0_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int swap_(doublereal *c__, integer *n, integer *mdim, 
	integer *nocc, integer *ifill)
{
    /* Format strings */
    static char fmt_80[] = "(/,\002 CAUTION !!! SUM IN SWAP VERY SMALL, SUMM"
	    "AX =\002,f10.5,\002 JFILL=\002,i3)";

    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
    static doublereal x, sum;
    static integer jfill;
    static doublereal summax;

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, fmt_80, 0 };


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
/* ****************************************************************** */

/*        SWAP ENSURES THAT A NAMED MOLECULAR ORBITAL IFILL IS FILLED */
/* ON INPUT */
/*          C = EIGENVECTORS IN A MDIM*MDIM MATRIX */
/*          N = NUMBER OF ORBITALS */
/*          NOCC = NUMBER OF OCCUPIED ORBITALS */
/*          IFILL = FILLED ORBITAL */
/* ****************************************************************** */
    /* Parameter adjustments */
    c_dim1 = *mdim;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;

    /* Function Body */
    if (*ifill > 0) {
	goto L20;
    }

/*     WE NOW DEFINE THE FILLED ORBITAL */

    *ifill = -(*ifill);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	swap0_1.stdpsi[i__ - 1] = c__[i__ + *ifill * c_dim1];
/* L10: */
	swap0_1.psi[i__ - 1] = c__[i__ + *ifill * c_dim1];
    }
    return 0;
L20:

/*     FIRST FIND THE LOCATION OF IFILL */

    sum = 0.;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	sum += swap0_1.psi[i__ - 1] * c__[i__ + *ifill * c_dim1];
    }
    if (abs(sum) > .7071) {
	goto L90;
    }

/*     IFILL HAS MOVED! */

    summax = 0.;
    i__1 = *n;
    for (*ifill = 1; *ifill <= i__1; ++(*ifill)) {
	sum = 0.;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L40: */
	    sum += swap0_1.stdpsi[i__ - 1] * c__[i__ + *ifill * c_dim1];
	}
	sum = abs(sum);
	if (sum > summax) {
	    jfill = *ifill;
	}
	if (sum > summax) {
	    summax = sum;
	}
	if (sum > .7071) {
	    goto L90;
	}
/* L50: */
    }
    i__1 = *n;
    for (*ifill = 1; *ifill <= i__1; ++(*ifill)) {
	sum = 0.;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L60: */
	    sum += swap0_1.psi[i__ - 1] * c__[i__ + *ifill * c_dim1];
	}
	sum = abs(sum);
	if (sum > summax) {
	    jfill = *ifill;
	}
	if (sum > summax) {
	    summax = sum;
	}
	if (sum > .7071) {
	    goto L90;
	}
/* L70: */
    }
    s_wsfe(&io___5);
    do_fio(&c__1, (char *)&summax, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&jfill, (ftnlen)sizeof(integer));
    e_wsfe();
    *ifill = jfill;
L90:
    if (*ifill <= *nocc) {
	return 0;
    }

/*    ITS EMPTY, SO SWAP IT WITH THE HIGHEST FILLED */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x = c__[i__ + *nocc * c_dim1];
	c__[i__ + *nocc * c_dim1] = c__[i__ + *ifill * c_dim1];
	c__[i__ + *ifill * c_dim1] = x;
/* L100: */
    }
    return 0;
} /* swap_ */

