/* locmin.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ncount;
} nllsqi_;

#define nllsqi_1 nllsqi_

struct {
    char contrl[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static logical c_true = TRUE_;
static integer c__1 = 1;

/* Subroutine */ int locmin_(integer *m, doublereal *x, integer *n, 
	doublereal *p, doublereal *ssq, doublereal *alf, doublereal *efs, 
	integer *itrap, doublereal *escf)
{
    /* Initialized data */

    static doublereal const__[360] = { 1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,
	    1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1.,1. };
    static integer icalcn = 0;

    /* Format strings */
    static char fmt_310[] = "(\002 ---LOCMIN\002/5x,\002LEFT   ...\002,2f19."
	    "6/5x,\002CENTER ...\002,2f19.6/5x,\002RIGHT  ...\002,2f19.6/\002 "
	    "\002)";
    static char fmt_320[] = "(5x,\002LEFT   ...\002,2f19.6/5x,\002CENTER .."
	    ".\002,2f19.6/5x,\002RIGHT  ...\002,2f19.6/5x,\002NEW    ...\002,"
	    "2f19.6/\002 \002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4, d__5;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal f;
    static integer i__;
    static doublereal s, t, vt[3], abg, fin, tee, phi[3];
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal eps, sum, sum2, beta, alfs;
    static integer left, ictr, mxct;
    static doublereal gamma, alpha;
    static logical debug;
    static doublereal scale, amdis, flast;
    static integer right;
    static logical lower;
    static doublereal xcrit, xmaxm, xminm, estor, tlast, gstor[360], xstor[
	    360];
    static integer mxcnt2;
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), exchng_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static integer center;
    static doublereal energy;
    static char keywrd[241];
    static integer iprint;
    static doublereal ymaxst, sqstor;

    /* Fortran I/O blocks */
    static cilist io___32 = { 0, 6, 0, fmt_310, 0 };
    static cilist io___41 = { 0, 6, 0, "(' EXIT DUE TO SMALL PROJECTED STEP')"
	    , 0 };
    static cilist io___42 = { 0, 6, 0, fmt_320, 0 };
    static cilist io___43 = { 0, 6, 0, "(' F/FLAST',F13.6)", 0 };
    static cilist io___44 = { 0, 6, 0, "(' EXIT AS STEP IS ABSOLUTELY SMALL "
	    "')", 0 };
    static cilist io___47 = { 0, 6, 0, "(' EXIT DUE TO HAVING REACHED BOTTOM"
	    "')", 0 };


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
    --efs;
    --p;
    --x;

    /* Function Body */
/* *********************************************************************** */

/*    LOCMIN IS CALLED BY NLLSQ ONLY. IT IS A LINE-SEARCH PROCEDURE FOR */
/*    LOCATING A MINIMUM IN THE FUNCTION SPACE OF COMPFG.  SEE NLLSQ */
/*    FOR MORE DETAILS */

/* *********************************************************************** */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	xmaxm = 1e9;
	scale = 1.;
	s_copy(keywrd, keywrd_1.contrl, (ftnlen)241, (ftnlen)241);

/* THE ABOVE LINE IS TO TRY TO PREVENT OVERFLOW IN NLLSQ */

	eps = 1e-5;
	debug = i_indx(keywrd, "LINMIN", (ftnlen)241, (ftnlen)6) != 0;
	tee = .01;
	ymaxst = .005;
	xcrit = 2e-4;
	mxcnt2 = 30;
	iprint = 0;
	if (debug) {
	    iprint = -1;
	}
    }
    xmaxm = 1e-11;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
/* Computing MAX */
	d__2 = xmaxm, d__3 = (d__1 = p[i__], abs(d__1));
	xmaxm = max(d__2,d__3);
    }
    xminm = xmaxm * scale;
    xmaxm = ymaxst / xmaxm / scale;
    fin = *ssq;
    lower = FALSE_;
    t = *alf;
    phi[0] = *ssq;
    vt[0] = 0.;
    vt[1] = t / 4.;
    if (vt[1] > xmaxm) {
	vt[1] = xmaxm;
    }
    t = vt[1];
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	x[i__] += t * p[i__] * const__[i__ - 1] * scale;
    }
    compfg_(&x[1], &c_true, escf, &c_true, &efs[1], &c_true);
    phi[1] = dot_(&efs[1], &efs[1], n);
    exchng_(&phi[1], &sqstor, &energy, &estor, &x[1], xstor, &t, &alfs, n);
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	gstor[i__ - 1] = efs[i__];
    }
    if (phi[0] <= phi[1]) {
	vt[2] = -vt[1];
	left = 3;
	center = 1;
	right = 2;
    } else {
	vt[2] = vt[1] * 2.;
	left = 1;
	center = 2;
	right = 3;
    }
    tlast = vt[2];
    t = tlast - t;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	x[i__] += t * p[i__] * const__[i__ - 1] * scale;
    }
    flast = phi[1];
    compfg_(&x[1], &c_true, escf, &c_true, &efs[1], &c_true);
    f = dot_(&efs[1], &efs[1], n);
    if (f < sqstor) {
	exchng_(&f, &sqstor, &energy, &estor, &x[1], xstor, &t, &alfs, n);
    }
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	gstor[i__ - 1] = efs[i__];
    }
    if (f < fin) {
	lower = TRUE_;
    }
    nllsqi_1.ncount += 2;
    phi[2] = f;
    if (iprint >= 0) {
	goto L70;
    } else {
	goto L60;
    }
L60:
    s_wsfe(&io___32);
    do_fio(&c__1, (char *)&vt[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&phi[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&vt[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&phi[1], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&vt[2], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&phi[2], (ftnlen)sizeof(doublereal));
    e_wsfe();
L70:
    mxct = mxcnt2;
    i__1 = mxct;
    for (ictr = 3; ictr <= i__1; ++ictr) {
	xmaxm *= 3.;
	alpha = vt[1] - vt[2];
	beta = vt[2] - vt[0];
	gamma = vt[0] - vt[1];
	if (alpha == 0.) {
	    alpha = 1e-20;
	}
	if (beta == 0.) {
	    beta = 1e-20;
	}
	if (gamma == 0.) {
	    gamma = 1e-20;
	}
	abg = -(phi[0] * alpha + phi[1] * beta + phi[2] * gamma) / alpha;
	abg /= beta;
	abg /= gamma;
	alpha = abg;
	beta = (phi[0] - phi[1]) / gamma - alpha * (vt[0] + vt[1]);
	if (alpha <= 0.) {
	    goto L80;
	} else {
	    goto L110;
	}
L80:
	if (phi[right - 1] > phi[left - 1]) {
	    goto L90;
	}
	t = vt[right - 1] * 3. - vt[center - 1] * 2.;
	goto L100;
L90:
	t = vt[left - 1] * 3. - vt[center - 1] * 2.;
L100:
	s = t - tlast;
	t = s + tlast;
	goto L150;
L110:
	t = -beta / (alpha * 2.);
	s = t - tlast;
	if (s < 0.) {
	    goto L120;
	} else if (s == 0) {
	    goto L260;
	} else {
	    goto L130;
	}
L120:
	amdis = vt[left - 1] - tlast - xmaxm;
	goto L140;
L130:
	amdis = vt[right - 1] - tlast + xmaxm;
L140:
	if (abs(s) > abs(amdis)) {
	    s = amdis;
	}
	t = s + tlast;
L150:
	if (ictr > 3 && (d__1 = s * xminm, abs(d__1)) < xcrit) {
	    if (debug) {
		s_wsfe(&io___41);
		e_wsfe();
	    }
	    goto L260;
	}
	t = s + tlast;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L160: */
	    x[i__] += s * p[i__] * const__[i__ - 1] * scale;
	}
	flast = f;
	compfg_(&x[1], &c_true, escf, &c_true, &efs[1], &c_true);
	f = dot_(&efs[1], &efs[1], n);
	if (f < sqstor) {
	    exchng_(&f, &sqstor, &energy, &estor, &x[1], xstor, &t, &alfs, n);
	}
	i__2 = *m;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L170: */
	    gstor[i__ - 1] = efs[i__];
	}
	if (f < fin) {
	    lower = TRUE_;
	}
	++nllsqi_1.ncount;
	if (iprint >= 0) {
	    goto L190;
	} else {
	    goto L180;
	}
L180:
	s_wsfe(&io___42);
	do_fio(&c__1, (char *)&vt[left - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi[left - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vt[center - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi[center - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vt[right - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi[right - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&t, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&f, (ftnlen)sizeof(doublereal));
	e_wsfe();
L190:

/*    TEST FOR EXCITED STATES AND POTHOLES */

	*itrap = 0;
	if ((d__1 = vt[center - 1], abs(d__1)) > 1e-10) {
	    goto L200;
	}
	if (abs(t) / ((d__1 = vt[left - 1], abs(d__1)) + 1e-15) > .3333f) {
	    goto L200;
	}
	if (f * 2.5 - phi[right - 1] - phi[left - 1] < phi[center - 1] * .5) {
	    goto L200;
	}

/*   WE ARE STUCK ON A FALSE MINIMUM */

	*itrap = 1;
	goto L260;
L200:

/* NOW FOR THE MAIN STOPPING TESTS.  LOCMIN WILL STOP IF:- */
/*     THE ERROR FUNCTION HAS BEEN REDUCED, AND */
/*     THE RATE OF DROP OF THE ERROR FUNCTION IS LESS THAN 0.5% PER STEP */
/*     AND */
/*     (A) THE RATIO OF THE PROPOSED STEP TO THE TOTAL STEP IS LESS THAN */
/*         EPS,   OR */
/*     (B) THE LAST DROP IN ERROR FUNCTION WAS LESS THAN 5%OFTHETOTALDROP */
/*         DURING THIS CALL TO LOCMIN. */

	if (debug) {
	    s_wsfe(&io___43);
	    d__1 = f / flast;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (lower && f / flast > .995) {
	    if ((d__2 = t - tlast, abs(d__2)) <= eps * (d__1 = t + tlast, abs(
		    d__1)) + tee) {
		if (debug) {
		    s_wsfe(&io___44);
		    e_wsfe();
		}
		goto L260;
	    }
/* Computing MIN */
	    d__4 = (d__1 = f - phi[0], abs(d__1)), d__5 = (d__2 = f - phi[1], 
		    abs(d__2)), d__4 = min(d__4,d__5), d__5 = (d__3 = f - phi[
		    2], abs(d__3));
	    sum = min(d__4,d__5);
	    sum2 = (fin - sqstor) * .05;
	    if (sum < sum2) {
		if (debug) {
		    s_wsfe(&io___47);
		    e_wsfe();
		}
		goto L260;
	    }
	}
	tlast = t;
	if (t > vt[right - 1] || t > vt[center - 1] && f < phi[center - 1] || 
		t > vt[left - 1] && t < vt[center - 1] && f > phi[center - 1])
		 {
	    goto L210;
	}
	vt[right - 1] = t;
	phi[right - 1] = f;
	goto L220;
L210:
	vt[left - 1] = t;
	phi[left - 1] = f;
L220:
	if (vt[center - 1] < vt[right - 1]) {
	    goto L230;
	}
	i__ = center;
	center = right;
	right = i__;
L230:
	if (vt[left - 1] < vt[center - 1]) {
	    goto L240;
	}
	i__ = left;
	left = center;
	center = i__;
L240:
	if (vt[center - 1] < vt[right - 1]) {
	    goto L250;
	}
	i__ = center;
	center = right;
	right = i__;
L250:
	;
    }
L260:
    exchng_(&sqstor, &f, &estor, &energy, xstor, &x[1], &alfs, &t, n);
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L270: */
	efs[i__] = gstor[i__ - 1];
    }
    *ssq = f;
    *alf = t;
    if (t >= 0.) {
	goto L300;
    } else {
	goto L280;
    }
L280:
    t = -t;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L290: */
	p[i__] = -p[i__];
    }
L300:
    *alf = t;
    return 0;
} /* locmin_ */

