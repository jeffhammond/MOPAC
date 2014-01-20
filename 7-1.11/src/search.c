/* search.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal gnext, amin, anext;
} sigma1_;

#define sigma1_1 sigma1_

struct {
    doublereal gnext1[360], gmin1[360];
} sigma2_;

#define sigma2_1 sigma2_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static doublereal c_b4 = .2;
static integer c__1 = 1;
static doublereal c_b17 = 3.;
static logical c_true = TRUE_;

/* Subroutine */ int search_(doublereal *xparam, doublereal *alpha, 
	doublereal *sig, integer *nvar, doublereal *gmin, logical *okf, 
	doublereal *funct)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double d_sign(doublereal *, doublereal *);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static doublereal g;
    static integer i__;
    static doublereal ga, gb, ta, tb;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal sum, grad[360], gref[360], xref[360], gtot;
    static logical nopr;
    static doublereal tiny, xmin1[360];
    static logical debug;
    static doublereal gminn;
    static integer looks, itrys;
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *);
    static doublereal tolerg, gstore;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 6, 0, "(' SEARCH DIRECTION VECTOR')", 0 };
    static cilist io___13 = { 0, 6, 0, "(6F12.6)", 0 };
    static cilist io___14 = { 0, 6, 0, "(' INITIAL GRADIENT VECTOR')", 0 };
    static cilist io___15 = { 0, 6, 0, "(6F12.6)", 0 };
    static cilist io___17 = { 0, 6, 0, "(' GRADIENT AT START OF SEARCH:',F16"
	    ".6)", 0 };
    static cilist io___27 = { 0, 6, 0, "(' LOOKS',I3,' ALPHA =',F12.6,' GRAD"
	    "IENT',F12.3,   ' G  =',F16.6)", 0 };
    static cilist io___28 = { 0, 6, 0, "(' AT EXIT FROM SEARCH')", 0 };
    static cilist io___29 = { 0, 6, 0, "(' XPARAM',6F12.6)", 0 };
    static cilist io___30 = { 0, 6, 0, "(' GNEXT1',6F12.6)", 0 };
    static cilist io___31 = { 0, 6, 0, "(' GMIN1 ',6F12.6)", 0 };
    static cilist io___32 = { 0, 6, 0, "(' AMIN, ANEXT,GMIN',4F12.6)", 0 };


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

/* SEARCH PERFORMS A LINE SEARCH FOR POWSQ. IT MINIMIZES THE NORM OF */
/*        THE GRADIENT VECTOR IN THE DIRECTION SIG. */

/* ON INPUT  XPARAM = CURRENT POINT IN NVAR DIMENSIONAL SPACE. */
/*           ALPHA  = STEP SIZE (IN FACT ALPHA IS CALCULATED IN SEARCH). */
/*           SIG    = SEARCH DIRECTION VECTOR. */
/*           NVAR   = NUMBER OF PARAMETERS IN SIG (& XPARAM) */

/* ON OUTPUT XPARAM = PARAMETERS OF MINIMUM. */
/*           ALPHA  = DISTANCE TO MINIMUM. */
/*           GMIN   = GRADIENT NORM AT MINIMUM. */
/*           OKF    = FUNCTION WAS IMPROVED. */
/* *********************************************************************** */
    /* Parameter adjustments */
    --sig;
    --xparam;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;

/*    TOLG   = CRITERION FOR EXIT BY RELATIVE CHANGE IN GRADIENT. */

	debug = i_indx(keywrd_1.keywrd, "LINMIN", (ftnlen)241, (ftnlen)6) != 
		0;
	nopr = ! debug;
	looks = 0;
	*okf = TRUE_;
	tiny = .1;
	tolerg = .02;
	g = 100.;
	*alpha = .1;
    }
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	gref[i__ - 1] = sigma2_1.gmin1[i__ - 1];
	sigma2_1.gnext1[i__ - 1] = sigma2_1.gmin1[i__ - 1];
	xmin1[i__ - 1] = xparam[i__];
/* L10: */
	xref[i__ - 1] = xparam[i__];
    }
    if (abs(*alpha) > .2f) {
	*alpha = d_sign(&c_b4, alpha);
    }
    if (debug) {
	s_wsfe(&io___12);
	e_wsfe();
	s_wsfe(&io___13);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&sig[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___14);
	e_wsfe();
	s_wsfe(&io___15);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&sigma2_1.gmin1[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }
    gb = dot_(sigma2_1.gmin1, gref, nvar);
    if (debug) {
	s_wsfe(&io___17);
	d__1 = sqrt(gb);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    gstore = gb;
    sigma1_1.amin = 0.;
    gminn = 1e9;


    ta = 0.;
    ga = gb;
    gb = 1e9;
    itrys = 0;
    goto L30;
L20:
    sum = ga / (ga - gb);
    ++itrys;
    if (abs(sum) > 3.) {
	sum = d_sign(&c_b17, &sum);
    }
    *alpha = (tb - ta) * sum + ta;

/*         XPARAM IS THE GEOMETRY OF THE PREDICTED MINIMUM ALONG THE LINE */

L30:
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	xparam[i__] = xref[i__ - 1] + *alpha * sig[i__];
    }

/*         CALCULATE GRADIENT NORM AND GRADIENTS AT THE PREDICTED MINIMUM */

    if (itrys == 1) {
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	    grad[i__ - 1] = 0.;
	}
    }
    compfg_(&xparam[1], &c_true, funct, &c_true, grad, &c_true);
    ++looks;

/*          G IS THE PROJECTION OF THE GRADIENT ALONG SIG. */

    g = dot_(gref, grad, nvar);
    gtot = sqrt(dot_(grad, grad, nvar));
    if (! nopr) {
	s_wsfe(&io___27);
	do_fio(&c__1, (char *)&looks, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
	d__1 = sqrt(dot_(grad, grad, nvar));
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&g, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (gtot < gminn) {
	gminn = gtot;
	if ((d__1 = sigma1_1.amin - *alpha, abs(d__1)) > .01) {

/* WE CAN MOVE ANEXT TO A POINT NEAR, BUT NOT TOO NEAR, AMIN, SO THAT THE */
/* SECOND DERIVATIVESWILLBEREALISTIC(D2E/DX2=(GNEXT1-GMIN1)/(ANEXT-AMIN)) */

	    sigma1_1.anext = sigma1_1.amin;
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
		sigma2_1.gnext1[i__ - 1] = sigma2_1.gmin1[i__ - 1];
	    }
	}
	sigma1_1.amin = *alpha;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (gminn < *gmin) {
		xmin1[i__ - 1] = xparam[i__];
	    }
/* L70: */
	    sigma2_1.gmin1[i__ - 1] = grad[i__ - 1];
	}
	if (*gmin > gminn) {
	    *gmin = gminn;
	}
    }
    if (itrys > 8) {
	goto L80;
    }
    if ((d__1 = g / gstore, abs(d__1)) < tiny || abs(g) < tolerg) {
	goto L80;
    }
/* Computing MAX */
    d__1 = abs(ga), d__2 = abs(gb);
    if (abs(g) < max(d__1,d__2) || ga * gb > 0. && g * ga < 0.) {

/*   G IS AN IMPROVEMENT ON GA OR GB. */

	if (abs(gb) < abs(ga)) {
	    ta = *alpha;
	    ga = g;
	    goto L20;
	} else {
	    tb = *alpha;
	    gb = g;
	    goto L20;
	}
    } else {
/* #         WRITE(6,'(//10X,'' FAILED IN SEARCH, SEARCH CONTINUING'')') */
	goto L80;
    }
L80:
    gminn = sqrt(dot_(sigma2_1.gmin1, sigma2_1.gmin1, nvar));
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L90: */
	xparam[i__] = xmin1[i__ - 1];
    }
    if (debug) {
	s_wsfe(&io___28);
	e_wsfe();
	s_wsfe(&io___29);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___30);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&sigma2_1.gnext1[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___31);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&sigma2_1.gmin1[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___32);
	do_fio(&c__1, (char *)&sigma1_1.amin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sigma1_1.anext, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*gmin), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (gminn > *gmin) {
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	    xparam[i__] = xref[i__ - 1];
	}
    }
    return 0;

} /* search_ */

