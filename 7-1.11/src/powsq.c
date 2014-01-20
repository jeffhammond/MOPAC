/* powsq.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer iflepo, iscf;
} mesage_;

#define mesage_1 mesage_

struct {
    integer ndum, loc[720]	/* was [2][360] */, idumy;
    doublereal xaram[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    integer nscf;
} numscf_;

#define numscf_1 numscf_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    doublereal grad[360], gnfina;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal gnext, amin, anext;
} sigma1_;

#define sigma1_1 sigma1_

struct {
    doublereal gnext1[360], gmin1[360];
} sigma2_;

#define sigma2_1 sigma2_

struct {
    doublereal hess[129600]	/* was [360][360] */, bmat[129600]	/* 
	    was [360][360] */, pmat[129600];
} nllcom_;

#define nllcom_1 nllcom_

struct {
    doublereal pvec[129600];
} scrach_;

#define scrach_1 scrach_

/* Table of constant values */

static integer c__1 = 1;
static logical c_true = TRUE_;

/* Subroutine */ int powsq_(doublereal *xparam, integer *nvar, doublereal *
	funct)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* Format strings */
    static char fmt_370[] = "(\002  RESTART FILE WRITTEN,  TIME LEFT:\002,f9"
	    ".1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g14.7)";
    static char fmt_380[] = "(\002 CYCLE:\002,i5,\002 TIME:\002,f6.1,\002 TI"
	    "ME LEFT:\002,f9.1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g14.7)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal p[360], q[360], e1[360], e2[360];
    static integer id, if__, ij, ik, il;
    static doublereal sk, rt;
    static integer ip1;
    static doublereal eig[360];
    static logical okf, log__;
    static doublereal sig[360];
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal rmu, sum;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal rmx;
    static logical scf1;
    static doublereal rho2, tol2;
    static integer icyc;
    static doublereal gmin, xinc;
    static integer ilpr;
    static doublereal pmax;
    static integer ipow[9];
    static doublereal work[360], time1, time2;
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal alpha;
    static logical debug, times;
    static doublereal tlast;
    static integer iloop;
    static doublereal tstep;
    extern doublereal second_(void);
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), search_(doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, logical *, 
	    doublereal *);
    static logical resfil;
    extern /* Subroutine */ int vecprt_(doublereal *, integer *), powsav_(
	    doublereal *, doublereal *, doublereal *, doublereal *, integer *,
	     doublereal *, integer *);
    static logical restrt;

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 6, 0, "(/,A)", 0 };
    static cilist io___19 = { 0, 6, 0, "(' XPARAM',6F10.6)", 0 };
    static cilist io___20 = { 0, 6, 0, "(//10X,' RESTARTING AT POINT',I3)", 0 
	    };
    static cilist io___21 = { 0, 6, 0, "(//10X,'RESTARTING IN OPTIMISATION',"
	    "                   ' ROUTINES')", 0 };
    static cilist io___22 = { 0, 6, 0, "(' XPARAM')", 0 };
    static cilist io___23 = { 0, 6, 0, "(5(2I3,F10.4))", 0 };
    static cilist io___24 = { 0, 6, 0, "(' STARTING GRADIENTS')", 0 };
    static cilist io___25 = { 0, 6, 0, "(3X,8F9.4)", 0 };
    static cilist io___28 = { 0, 6, 0, "(I3,12(8F9.4,/3X))", 0 };
    static cilist io___32 = { 0, 6, 0, "(' TIME FOR STEP:',F8.2,' LEFT',F8.2)"
	    , 0 };
    static cilist io___33 = { 0, 6, 0, "(//10X,'UN-NORMALIZED HESSIAN MATRIX"
	    "')", 0 };
    static cilist io___34 = { 0, 6, 0, "(8F10.4)", 0 };
    static cilist io___37 = { 0, 6, 0, "(//10X,'HESSIAN MATRIX')", 0 };
    static cilist io___38 = { 0, 6, 0, "(8F10.4)", 0 };
    static cilist io___43 = { 0, 6, 0, "(/10X,'P MATRIX IN POWSQ')", 0 };
    static cilist io___50 = { 0, 6, 0, "(' SEARCH VECTOR')", 0 };
    static cilist io___51 = { 0, 6, 0, "(8F10.5)", 0 };
    static cilist io___62 = { 0, 6, 0, fmt_370, 0 };
    static cilist io___63 = { 0, 11, 0, fmt_370, 0 };
    static cilist io___64 = { 0, 6, 0, fmt_380, 0 };
    static cilist io___65 = { 0, 11, 0, fmt_380, 0 };
    static cilist io___66 = { 0, 6, 0, "(' TIME FOR STEP:',F8.2,' LEFT',F8.2)"
	    , 0 };


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
/* ********************************************************************* */

/*   POWSQ OPTIMIZES THE GEOMETRY BY MINIMISING THE GRADIENT NORM. */
/*         THUS BOTH GROUND AND TRANSITION STATE GEOMETRIES CAN BE */
/*         CALCULATED. IT IS ROUGHLY EQUIVALENT TO FLEPO, FLEPO MINIMIZES */
/*         THE ENERGY, POWSQ MINIMIZES THE GRADIENT NORM. */

/*  ON ENTRY XPARAM = VALUES OF PARAMETERS TO BE OPTIMIZED. */
/*           NVAR   = NUMBER OF PARAMETERS TO BE OPTIMIZED. */

/*  ON EXIT  XPARAM = OPTIMIZED PARAMETERS. */
/*           FUNCT  = HEAT OF FORMATION IN KCALS. */

/* ********************************************************************* */
/*        *****  ROUTINE PERFORMS  A LEAST SQUARES MINIMIZATION  ***** */
/*        *****  OF A FUNCTION WHICH IS A SUM OF SQUARES.        ***** */
/*        *****  INITIALLY WRITTEN BY J.W. MCIVER JR. AT SUNY/   ***** */
/*        *****  BUFFALO, SUMMER 1971.  REWRITTEN AND MODIFIED   ***** */
/*        *****  BY A.K. AT SUNY BUFFALO AND THE UNIVERSITY OF   ***** */
/*        *****  TEXAS.  DECEMBER 1973                           ***** */

/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /TIME  / TIME0 */
/* ***************************** at 1994-05-25 ***** */
    /* Parameter adjustments */
    --xparam;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	restrt = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) !=
		 0;
	log__ = i_indx(keywrd_1.keywrd, "NOLOG", (ftnlen)241, (ftnlen)5) == 0;
	scf1 = i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0;
	time1 = second_();
	time2 = time1;
	icyc = 0;
	times = i_indx(keywrd_1.keywrd, "TIME", (ftnlen)241, (ftnlen)4) != 0;
	tlast = timdmp_1.tleft;
	resfil = FALSE_;
	last_1.last = 0;
	iloop = 1;
	xinc = .00529167;
	rho2 = 1e-4;
	tol2 = .4;
	if (i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0) {
	    tol2 = .01;
	}
	if (i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5);
	    tol2 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    if (tol2 < .01f && i_indx(keywrd_1.keywrd, " LET", (ftnlen)241, (
		    ftnlen)4) == 0) {
		s_wsfe(&io___15);
		do_fio(&c__1, "  GNORM HAS BEEN SET TOO LOW, RESET TO 0.01", (
			ftnlen)43);
		e_wsfe();
		tol2 = .01;
	    }
	}
	debug = i_indx(keywrd_1.keywrd, "POWSQ", (ftnlen)241, (ftnlen)5) != 0;
	if (restrt) {

/*   RESTORE STORED DATA */

	    ipow[8] = 0;
	    powsav_(nllcom_1.hess, sigma2_1.gmin1, &xparam[1], nllcom_1.pmat, 
		    &iloop, nllcom_1.bmat, ipow);
	    if (scf1) {
		goto L390;
	    }
	    numscf_1.nscf = ipow[7];
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		gradnt_1.grad[i__ - 1] = sigma2_1.gmin1[i__ - 1];
/* L10: */
		sigma2_1.gnext1[i__ - 1] = sigma2_1.gmin1[i__ - 1];
	    }
	    s_wsfe(&io___19);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_wsfe();
	    if (iloop > 0) {
/* #               ILOOP=ILOOP+1 */
		s_wsfe(&io___20);
		do_fio(&c__1, (char *)&iloop, (ftnlen)sizeof(integer));
		e_wsfe();
	    } else {
		s_wsfe(&io___21);
		e_wsfe();
	    }
	}

/*   DEFINITIONS:   NVAR   = NUMBER OF GEOMETRIC VARIABLES = 3*NUMAT-6 */

    }
    *nvar = abs(*nvar);
    if (debug) {
	s_wsfe(&io___22);
	e_wsfe();
	s_wsfe(&io___23);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&geovar_1.loc[(i__ << 1) - 2], (ftnlen)
		    sizeof(integer));
	    do_fio(&c__1, (char *)&geovar_1.loc[(i__ << 1) - 1], (ftnlen)
		    sizeof(integer));
	    do_fio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    if (! restrt) {
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	    gradnt_1.grad[i__ - 1] = 0.;
	}
	compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &c_true);
    }
    if (debug) {
	s_wsfe(&io___24);
	e_wsfe();
	s_wsfe(&io___25);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }
    gmin = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sigma2_1.gnext1[i__ - 1] = gradnt_1.grad[i__ - 1];
	sigma2_1.gmin1[i__ - 1] = sigma2_1.gnext1[i__ - 1];
/* L30: */
    }

/*    NOW TO CALCULATE THE HESSIAN MATRIX. */

    if (iloop < 0) {
	goto L140;
    }

/*   CHECK THAT HESSIAN HAS NOT ALREADY BEEN CALCULATED. */

    ilpr = iloop;
    i__1 = *nvar;
    for (iloop = ilpr; iloop <= i__1; ++iloop) {
	time1 = second_();
	xparam[iloop] += xinc;
	compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &c_true);
	if (scf1) {
	    goto L390;
	}
	if (debug) {
	    s_wsfe(&io___28);
	    do_fio(&c__1, (char *)&iloop, (ftnlen)sizeof(integer));
	    i__2 = *nvar;
	    for (if__ = 1; if__ <= i__2; ++if__) {
		do_fio(&c__1, (char *)&gradnt_1.grad[if__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
	gradnt_1.grad[iloop - 1] += 1e-5;
	xparam[iloop] -= xinc;
	i__2 = *nvar;
	for (j = 1; j <= i__2; ++j) {
/* L40: */
	    nllcom_1.hess[iloop + j * 360 - 361] = -(gradnt_1.grad[j - 1] - 
		    sigma2_1.gnext1[j - 1]) / xinc;
	}
	time2 = second_();
	tstep = time2 - time1;
	if (times) {
	    s_wsfe(&io___32);
	    do_fio(&c__1, (char *)&tstep, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
	}
	if (tlast - timdmp_1.tleft > timdmp_1.tdump) {
	    tlast = timdmp_1.tleft;
	    resfil = TRUE_;
	    ipow[8] = 2;
	    i__ = iloop;
	    ipow[7] = numscf_1.nscf;
	    powsav_(nllcom_1.hess, sigma2_1.gmin1, &xparam[1], nllcom_1.pmat, 
		    &i__, nllcom_1.bmat, ipow);
	}
	if (timdmp_1.tleft < tstep * 2.) {

/*  STORE RESULTS TO DATE. */

	    ipow[8] = 1;
	    i__ = iloop;
	    ipow[7] = numscf_1.nscf;
	    powsav_(nllcom_1.hess, sigma2_1.gmin1, &xparam[1], nllcom_1.pmat, 
		    &i__, nllcom_1.bmat, ipow);
	    s_stop("", (ftnlen)0);
	}
/* L50: */
    }
/*        *****  SCALE -HESSIAN- MATRIX                           ***** */
    if (debug) {
	s_wsfe(&io___33);
	e_wsfe();
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
	    s_wsfe(&io___34);
	    i__2 = *nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&nllcom_1.hess[j + i__ * 360 - 361], (
			ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
	sum = 0.;
	i__1 = *nvar;
	for (j = 1; j <= i__1; ++j) {
/* L70: */
/* Computing 2nd power */
	    d__1 = nllcom_1.hess[i__ + j * 360 - 361];
	    sum += d__1 * d__1;
	}
/* L80: */
	work[i__ - 1] = 1. / sqrt(sum);
    }
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nvar;
	for (j = 1; j <= i__1; ++j) {
/* L90: */
	    nllcom_1.hess[i__ + j * 360 - 361] *= work[i__ - 1];
	}
    }
    if (debug) {
	s_wsfe(&io___37);
	e_wsfe();
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	    s_wsfe(&io___38);
	    i__2 = *nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&nllcom_1.hess[j + i__ * 360 - 361], (
			ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
/*        *****  INITIALIZE B MATIRX                        ***** */
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nvar;
	for (j = 1; j <= i__1; ++j) {
/* L110: */
	    nllcom_1.bmat[i__ + j * 360 - 361] = 0.;
	}
/* L120: */
	nllcom_1.bmat[i__ + i__ * 360 - 361] = work[i__ - 1] * 2.;
    }
/* *********************************************************************** */

/*  THIS IS THE START OF THE BIG LOOP TO OPTIMIZE THE GEOMETRY */

/* *********************************************************************** */
    iloop = -99;
    tstep *= 4;
L130:
    if (tlast - timdmp_1.tleft > timdmp_1.tdump) {
	tlast = timdmp_1.tleft;
	resfil = TRUE_;
	ipow[8] = 2;
	i__ = iloop;
	ipow[7] = numscf_1.nscf;
	powsav_(nllcom_1.hess, sigma2_1.gmin1, &xparam[1], nllcom_1.pmat, &
		i__, nllcom_1.bmat, ipow);
    }
    if (timdmp_1.tleft < tstep * 2.) {

/*  STORE RESULTS TO DATE. */

	ipow[8] = 1;
	i__ = iloop;
	ipow[7] = numscf_1.nscf;
	powsav_(nllcom_1.hess, sigma2_1.gmin1, &xparam[1], nllcom_1.pmat, &
		i__, nllcom_1.bmat, ipow);
	mesage_1.iflepo = -1;
	return 0;
    }
L140:
/*        *****  FORM-A- DAGGER-A- IN PA SLONG WITH -P-     ***** */
    ij = 0;
    i__2 = *nvar;
    for (j = 1; j <= i__2; ++j) {
	i__1 = j;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ++ij;
	    sum = 0.;
	    i__3 = *nvar;
	    for (k = 1; k <= i__3; ++k) {
/* L150: */
		sum += nllcom_1.hess[i__ + k * 360 - 361] * nllcom_1.hess[j + 
			k * 360 - 361];
	    }
/* L160: */
	    nllcom_1.pmat[ij - 1] = sum;
	}
    }
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	i__2 = *nvar;
	for (k = 1; k <= i__2; ++k) {
/* L170: */
	    sum -= nllcom_1.hess[i__ + k * 360 - 361] * sigma2_1.gmin1[k - 1];
	}
/* L180: */
	p[i__ - 1] = -sum;
    }
    l = 0;
    if (debug) {
	s_wsfe(&io___43);
	e_wsfe();
	vecprt_(nllcom_1.pmat, nvar);
    }
    rsp_(nllcom_1.pmat, nvar, nvar, eig, scrach_1.pvec);
/*        *****  CHECK FOR ZERO EIGENVALUE                  ***** */
/* #      WRITE(6,'(''  EIGS IN POWSQ:'')') */
/* #      WRITE(6,'(6F13.8)')(EIG(I),I=1,NVAR) */
    if (eig[0] < rho2) {
	goto L240;
    }
/*        *****  IF MATRIX IS NOT SINGULAR FORM INVERSE     ***** */
/*        *****  BY BACK TRANSFORMING THE EIGENVECTORS      ***** */
    ij = 0;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++ij;
	    sum = 0.;
	    i__3 = *nvar;
	    for (k = 1; k <= i__3; ++k) {
/* L190: */
		sum += scrach_1.pvec[(k - 1) * *nvar + j - 1] * scrach_1.pvec[
			(k - 1) * *nvar + i__ - 1] / eig[k - 1];
	    }
/* L200: */
	    nllcom_1.pmat[ij - 1] = sum;
	}
    }
/*        *****  FIND -Q- VECTOR                            ***** */
    l = 0;
    il = l + 1;
    l = il + i__ - 1;
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
	sum = 0.;
	i__1 = i__;
	for (k = 1; k <= i__1; ++k) {
	    ik = i__ * (i__ - 1) / 2 + k;
/* L210: */
	    sum += nllcom_1.pmat[ik - 1] * p[k - 1];
	}
	ip1 = i__ + 1;
	i__1 = *nvar;
	for (k = ip1; k <= i__1; ++k) {
	    ik = k * (k - 1) / 2 + i__;
/* L220: */
	    sum += nllcom_1.pmat[ik - 1] * p[k - 1];
	}
/* L230: */
	q[i__ - 1] = sum;
    }
    goto L260;
L240:
/*        *****  TAKE  -Q- VECTOR AS EIGENVECTOR OF ZERO     ***** */
/*        *****  EIGENVALUE                                 ***** */
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L250: */
	q[i__ - 1] = scrach_1.pvec[i__ - 1];
    }
L260:
/*        *****  FIND SEARCH DIRECTION                      ***** */
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
	sig[i__ - 1] = 0.;
	i__1 = *nvar;
	for (j = 1; j <= i__1; ++j) {
/* L270: */
	    sig[i__ - 1] += q[j - 1] * nllcom_1.bmat[i__ + j * 360 - 361];
	}
    }
/*        *****  DO A ONE DIMENSIONAL SEARCH                ***** */
    if (debug) {
	s_wsfe(&io___50);
	e_wsfe();
	s_wsfe(&io___51);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&sig[i__ - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    search_(&xparam[1], &alpha, sig, nvar, &gmin, &okf, funct);
    if (*nvar == 1) {
	goto L390;
    }

/*  FIRST WE ATTEMPT TO OPTIMIZE GEOMETRY USING SEARCH. */
/*  IF THIS DOES NOT WORK, THEN SWITCH TO LINMIN, WHICH ALWAYS WORKS, */
/*  BUT IS TWICE AS SLOW AS SEARCH. */

    rmx = 0.;
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
	rt = (d__1 = sigma2_1.gmin1[k - 1], abs(d__1));
	if (rt > rmx) {
	    rmx = rt;
	}
/* L280: */
    }
    if (rmx < tol2) {
	goto L390;
    }
/*        *****  TWO STEP ESTIMATION OF DERIVATIVES         ***** */
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L290: */
	e1[k - 1] = (sigma2_1.gmin1[k - 1] - sigma2_1.gnext1[k - 1]) / (
		sigma1_1.amin - sigma1_1.anext);
    }
    rmu = dot_(e1, sigma2_1.gmin1, nvar) / dot_(sigma2_1.gmin1, 
	    sigma2_1.gmin1, nvar);
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L300: */
	e2[k - 1] = e1[k - 1] - rmu * sigma2_1.gmin1[k - 1];
    }
/*        *****  SCALE -E2- AND -SIG-                       ***** */
    sk = 1. / sqrt(dot_(e2, e2, nvar));
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L310: */
	sig[k - 1] = sk * sig[k - 1];
    }
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L320: */
	e2[k - 1] = sk * e2[k - 1];
    }
/*        *****  FIND INDEX OF REPLACEMENT DIRECTION        ***** */
    pmax = -1e20;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = p[i__ - 1] * q[i__ - 1], abs(d__1)) <= pmax) {
	    goto L330;
	}
	pmax = (d__1 = p[i__ - 1] * q[i__ - 1], abs(d__1));
	id = i__;
L330:
	;
    }
/*        *****  REPLACE APPROPRIATE DIRECTION AND DERIVATIVE *** */
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L340: */
	nllcom_1.hess[id + k * 360 - 361] = -e2[k - 1];
    }
/*        *****  REPLACE STARTING POINT                     ***** */
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L350: */
	nllcom_1.bmat[k + id * 360 - 361] = sig[k - 1] / .529167;
    }
    i__1 = *nvar;
    for (k = 1; k <= i__1; ++k) {
/* L360: */
	sigma2_1.gnext1[k - 1] = sigma2_1.gmin1[k - 1];
    }
    time1 = time2;
    time2 = second_();
    timdmp_1.tleft = timdmp_1.tleft - time2 + timec_1.time0;
    tstep = time2 - time1;
    ++icyc;
    if (resfil) {
	s_wsfe(&io___62);
	d__1 = min(timdmp_1.tleft,9999999.9);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	d__2 = min(gmin,999999.999);
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (log__) {
	    s_wsfe(&io___63);
	    d__1 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(gmin,999999.999);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	resfil = FALSE_;
    } else {
	s_wsfe(&io___64);
	do_fio(&c__1, (char *)&icyc, (ftnlen)sizeof(integer));
	d__1 = min(tstep,9999.99);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	d__2 = min(timdmp_1.tleft,9999999.9);
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	d__3 = min(gmin,999999.999);
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (log__) {
	    s_wsfe(&io___65);
	    do_fio(&c__1, (char *)&icyc, (ftnlen)sizeof(integer));
	    d__1 = min(tstep,9999.99);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    d__3 = min(gmin,999999.999);
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    if (times) {
	s_wsfe(&io___66);
	do_fio(&c__1, (char *)&tstep, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    goto L130;
L390:
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L400: */
	gradnt_1.grad[i__ - 1] = 0.;
    }
    last_1.last = 1;
    compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &c_true);
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L410: */
	gradnt_1.grad[i__ - 1] = sigma2_1.gmin1[i__ - 1];
    }
    gradnt_1.gnfina = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    mesage_1.iflepo = 11;
    if (scf1) {
	mesage_1.iflepo = 13;
    }
    return 0;
} /* powsq_ */

