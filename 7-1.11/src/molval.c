/* molval.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int molval_(doublereal *c__, doublereal *p, integer *nocc, 
	doublereal *rhfuhf)
{
    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3, i__4, i__5;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, l, l1, l2, jj, jl, kk, kl, ju, ku;
    static doublereal val[300], sum;

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 6, 0, "(10F8.4)", 0 };


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
    --p;
    c_dim1 = molkst_1.norbs;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;

    /* Function Body */
    i__1 = *nocc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	i__2 = molkst_1.numat;
	for (jj = 1; jj <= i__2; ++jj) {
	    jl = molkst_1.nfirst[jj - 1];
	    ju = molkst_1.nlast[jj - 1];
	    i__3 = ju;
	    for (j = jl; j <= i__3; ++j) {
		i__4 = molkst_1.numat;
		for (kk = 1; kk <= i__4; ++kk) {
		    if (kk == jj) {
			goto L20;
		    }
		    kl = molkst_1.nfirst[kk - 1];
		    ku = molkst_1.nlast[kk - 1];
		    i__5 = ku;
		    for (k = kl; k <= i__5; ++k) {
			l1 = max(j,k);
			l2 = j + k - l1;
			l = l1 * (l1 - 1) / 2 + l2;
			sum += c__[j + i__ * c_dim1] * c__[k + i__ * c_dim1] *
				 p[l];
/* L10: */
		    }
L20:
/* L30: */
		    ;
		}
	    }
	}
	val[i__ - 1] = sum * *rhfuhf;
/* L40: */
    }
    s_wsfe(&io___15);
    i__1 = *nocc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&val[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    return 0;
} /* molval_ */

