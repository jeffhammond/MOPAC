/* cnvg.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Subroutine */ int cnvg_(doublereal *pnew, doublereal *p, doublereal *p1, 
	integer *norbs, integer *niter, doublereal *pl)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal a;
    static integer i__, j, k, ie, ii;
    static doublereal sa, fac, sum, sum0, sum1, sum2, faca, facb, damp, 
	    rhfuhf;
    static logical extrap;

/* *********************************************************************** */

/*  CNVG IS A TWO-POINT INTERPOLATION ROUTINE FOR SPEEDING CONVERGENCE */
/*       OF THE DENSITY MATRIX. */

/* ON OUTPUT P      = NEW DENSITY MATRIX */
/*           P1     = DIAGONAL OF OLD DENSITY MATRIX */
/*           PL     = LARGEST DIFFERENCE BETWEEN OLD AND NEW DENSITY */
/*                    MATRIX DIAGONAL ELEMENTS */
/* *********************************************************************** */
    /* Parameter adjustments */
    --p1;
    --p;
    --pnew;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	if (i_indx(keywrd_1.keywrd, "UHF", (ftnlen)241, (ftnlen)3) != 0) {
	    rhfuhf = 1.;
	} else {
	    rhfuhf = 2.;
	}
    }
    *pl = 0.;
    faca = 0.;
    damp = 1e10;
    if (*niter > 3) {
	damp = .05;
    }
    facb = 0.;
    fac = 0.;
    ii = *niter % 3;
    extrap = ii != 0;
    sum1 = 0.;
    k = 0;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	k += i__;
	a = pnew[k];
	sum1 += a;
	sa = (d__1 = a - p[k], abs(d__1));
	if (sa > *pl) {
	    *pl = sa;
	}
	if (extrap) {
	    goto L10;
	}
/* Computing 2nd power */
	d__1 = sa;
	faca += d__1 * d__1;
/* Computing 2nd power */
	d__1 = a - p[k] * 2. + p1[i__];
	facb += d__1 * d__1;
L10:
	p1[i__] = p[k];
/* L20: */
	p[k] = a;
    }
    if (facb <= 0.) {
	goto L30;
    }
    if (faca < facb * 100.) {
	fac = sqrt(faca / facb);
    }
L30:
    ie = 0;
    sum2 = 0.;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = i__ - 1;
	i__2 = ii;
	for (j = 1; j <= i__2; ++j) {
	    ++ie;
	    a = pnew[ie];
	    p[ie] = a + fac * (a - p[ie]);
	    pnew[ie] = p[ie];
/* L40: */
	}
	++ie;
	if ((d__1 = p[ie] - p1[i__], abs(d__1)) > damp) {
	    d__1 = p[ie] - p1[i__];
	    p[ie] = p1[i__] + d_sign(&damp, &d__1);
	} else {
	    p[ie] += fac * (p[ie] - p1[i__]);
	}
/* Computing MIN */
/* Computing MAX */
	d__3 = p[ie];
	d__1 = rhfuhf, d__2 = max(d__3,0.);
	p[ie] = min(d__1,d__2);
	sum2 += p[ie];
/* L50: */
	pnew[ie] = p[ie];
    }

/*   RE-NORMALIZE IF ANY DENSITY MATRIX ELEMENTS HAVE BEEN TRUNCATED */

    sum0 = sum1;
L60:
    if (sum2 > .001) {
	sum = sum1 / sum2;
    } else {
	sum = 0.;
    }
    sum1 = sum0;
    if (sum2 > .001 && (d__1 = sum - 1., abs(d__1)) > 1e-5) {
/* #      WRITE(6,'(6F12.6)')(P((I*(I+1))/2),I=1,NORBS) */
	sum2 = 0.;
	i__1 = *norbs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    j = i__ * (i__ + 1) / 2;

/*   ADD ON A SMALL NUMBER IN CASE AN OCCUPANCY IS EXACTLY ZERO */

	    p[j] = p[j] * sum + 1e-20;
/* Computing MAX */
	    d__1 = p[j];
	    p[j] = max(d__1,0.);

/*  SET UP RENORMALIZATION OVER PARTLY OCCUPIED M.O.'S ONLY.  FULL M.O.'S */
/*  CAN'T BE FILLED ANY MORE */

	    if (p[j] > rhfuhf) {
		p[j] = rhfuhf;
		sum1 -= rhfuhf;
	    } else {
		sum2 += p[j];
	    }
/* L70: */
	    pnew[j] = p[j];
	}
	goto L60;
    }
    return 0;
} /* cnvg_ */

