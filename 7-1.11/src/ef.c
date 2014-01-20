/* ef.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer iflepo, iscf;
} mesage_;

#define mesage_1 mesage_

union {
    struct {
	integer ndum, loc[720]	/* was [2][360] */, idumy;
	doublereal xaram[360];
    } _1;
    struct {
	integer nvar, loc[720]	/* was [2][360] */, idumy;
	doublereal dumy[360];
    } _2;
} geovar_;

#define geovar_1 (geovar_._1)
#define geovar_2 (geovar_._2)

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    doublereal ams[107];
} istope_;

#define istope_1 istope_

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
    doublereal grad[360], gnfina;
} gradnt_;

#define gradnt_1 gradnt_

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
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

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
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

struct {
    doublereal oldf[360], d__[360], vmode[360], u[129600]	/* was [360][
	    360] */, dd, rmin, rmax, omin, xlamd, xlamd0, skal;
    integer mode, nstep, negreq, iprnt;
} optef_;

#define optef_1 optef_

struct {
    integer num_threads__;
} threads_;

#define threads_1 threads_

struct {
    integer nflush;
} flushc_;

#define flushc_1 flushc_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer locvar[720]	/* was [2][360] */;
} locvar_;

#define locvar_1 locvar_

struct {
    integer nscf;
} numscf_;

#define numscf_1 numscf_

struct {
    doublereal valvar[360];
    integer numvar;
} valvar_;

#define valvar_1 valvar_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal alparm[1080]	/* was [3][360] */, x0, x1, x2;
    integer jloop;
} alparm_;

#define alparm_1 alparm_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    doublereal time0;
} timex_;

#define timex_1 timex_

struct {
    doublereal pvec[129600];
} scrach_;

#define scrach_1 scrach_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

/* Table of constant values */

static integer c__6 = 6;
static integer c__1 = 1;
static integer c__11 = 11;
static integer c__9 = 9;
static logical c_true = TRUE_;
static logical c_false = FALSE_;
static integer c__3 = 3;
static integer c__5 = 5;
static integer c__0 = 0;

/* Subroutine */ int ef_(doublereal *xparam, integer *nvar, doublereal *funct)
{
    /* Initialized data */

    static doublereal three = 3.;
    static doublereal four = 4.;
    static doublereal pt5 = .5;
    static doublereal pt75 = .75;
    static doublereal demin = .02;
    static doublereal gmin = 5.;
    static integer icalcn = 0;
    static doublereal zero = 0.;
    static doublereal one = 1.;
    static doublereal two = 2.;
    static doublereal tmone = .1;
    static doublereal tmtwo = .01;
    static doublereal tmsix = 1e-6;

    /* Format strings */
    static char fmt_40[] = "(\002 CYCLE:\002,i4,\002 TIME:\002,f7.2,\002 TIM"
	    "E LEFT:\002,f9.1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g13.7)";
    static char fmt_50[] = "(\002 RESTART FILE WRITTEN,   TIME LEFT:\002,f9."
	    "1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g13.7)";
    static char fmt_70[] = "(1x,\002WARNING! EXACTLY 3N VARIABLES. EF ASSUME"
	    "S THIS IS A CARTESIAN OPTIMIZATION.\002,/,1x,\002IF THE OPTIMIZA"
	    "TION IS\002,\002 IN INTERNAL COORDINATES, EF WILL NOT WORK\002)";
    static char fmt_110[] = "(/,10x,\002HESSIAN HAS\002,i3,\002 NEGATIVE EIG"
	    "ENVALUE(S)\002,6f7.1,/)";
    static char fmt_170[] = "(5x,\002ACTUAL, PREDICTED ENERGY CHANGE, RATI"
	    "O\002,2f10.3,f10.5)";
    static char fmt_180[] = "(1x,\002energy raises \002,f10.4,\002 rejecting"
	    " step, \002,\002reducing dmax to\002,f7.4)";
    static char fmt_181[] = "(1x,\002gradient norm raises \002,f10.4,\002 re"
	    "jecting step, \002,\002reducing dmax to\002,f7.4)";
    static char fmt_190[] = "(1x,\002unacceptable ratio,\002,\002 rejecting "
	    "step, reducing dmax to\002,f7.4)";
    static char fmt_210[] = "(5x,\002STEPSIZE USED IS\002,f9.5)";
    static char fmt_220[] = "(5x,\002CURRENT TRUST RADIUS = \002,f7.5)";
    static char fmt_240[] = "(/,5x,\002TRUST RADIUS NOW LESS THAN \002,f7.5"
	    ",\002 OPTIMIZATION\002,\002 TERMINATING\002,/,5x,\002 GEOMETRY M"
	    "AY NOT BE COMPLETELY OPTIMIZED\002)";
    static char fmt_260[] = "(/,5x,\002RMS GRADIENT =\002,f9.5,\002  IS LESS"
	    " THAN CUTOFF =\002,f9.5,//)";
    static char fmt_290[] = "(/,5x,\002NOT ENOUGH TIME FOR ANOTHER CYCLE\002)"
	    ;
    static char fmt_300[] = "(/,5x,\002EXCESS NUMBER OF OPTIMIZATION CYCLE"
	    "S\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    static integer equiv_0[9];

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    double d_int(doublereal *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ij;
    static doublereal uc[129600], fx[360], ss, tt0, odd;
    static integer neg;
    static logical log__;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static logical lts;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal rmx;
    static logical scf1;
    static doublereal tol2, dmax__, dmin__, olde, svec[360], tvec[360], oldu[
	    129600]	/* was [360][360] */;
    static logical lupd, lrjk;
#define ipow (equiv_0)
    static logical donr;
    static integer iupd;
    static doublereal xtmp, time1, time2, deact, ddmax, depre;
    static integer imode;
    static doublereal oolde, ooldf[360], oldgn, hessc[64980];
    static logical gnmin;
#define ihess (equiv_0)
    static doublereal oldfx[360];
    static integer ntime;
    static logical lorjk;
    extern /* Subroutine */ int efstr_(doublereal *, doublereal *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, logical *, 
	    logical *, integer *, logical *, logical *, logical *, logical *);
    static integer iloop, ldump;
    static doublereal osmin;
    static integer itime;
    extern /* Subroutine */ int geout_(integer *);
    static doublereal tstep;
    extern /* Subroutine */ int flush_(integer *), prjfc_(doublereal *, 
	    doublereal *, integer *), formd_(doublereal *, doublereal *, 
	    integer *, doublereal *, doublereal *, logical *, logical *, 
	    logical *, logical *, logical *);
    static doublereal odmax, frodo, ratio;
    extern /* Subroutine */ int efsav_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     doublereal *, integer *);
    static integer ireclc;
    static doublereal oldeig[360], eigval[360];
    static integer igthes;
    static logical rrscal;
    static doublereal oldhss[129600]	/* was [360][360] */;
    extern /* Subroutine */ int gethes_(doublereal *, integer *, integer *, 
	    integer *, doublereal *);
    static doublereal totime;
    extern /* Subroutine */ int updhes_(doublereal *, doublereal *, integer *,
	     integer *);
    extern doublereal second_(void);
    extern /* Subroutine */ int prthes_(doublereal *, integer *), compfg_(
	    doublereal *, logical *, doublereal *, logical *, doublereal *, 
	    logical *);
    static doublereal gntest;
    static integer ittest, mxstep;
    extern /* Subroutine */ int symtry_(void);

    /* Fortran I/O blocks */
    static cilist io___53 = { 0, 6, 0, "(' XPARAM ')", 0 };
    static cilist io___54 = { 0, 6, 0, "(5(2I3,F10.4))", 0 };
    static cilist io___55 = { 0, 6, 0, "(' GRADIENTS')", 0 };
    static cilist io___56 = { 0, 6, 0, "(3X,8F9.3)", 0 };
    static cilist io___58 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___59 = { 0, 11, 0, fmt_40, 0 };
    static cilist io___60 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___61 = { 0, 11, 0, fmt_50, 0 };
    static cilist io___64 = { 0, 6, 0, fmt_70, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___71 = { 0, 6, 0, 0, 0 };
    static cilist io___77 = { 0, 6, 0, 0, 0 };
    static cilist io___86 = { 0, 6, 0, fmt_170, 0 };
    static cilist io___87 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___88 = { 0, 6, 0, fmt_181, 0 };
    static cilist io___89 = { 0, 6, 0, fmt_190, 0 };
    static cilist io___90 = { 0, 6, 0, fmt_210, 0 };
    static cilist io___91 = { 0, 6, 0, "(' CALCULATED STEP')", 0 };
    static cilist io___92 = { 0, 6, 0, "(3X,8F9.5)", 0 };
    static cilist io___93 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___94 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___97 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_290, 0 };
    static cilist io___99 = { 0, 6, 0, fmt_300, 0 };


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

/*   EF IS A QUASI NEWTON RAPHSON OPTIMIZATION ROUTINE BASED ON */
/*      Jacs Simons P-RFO algorithm as implemented by Jon Baker */
/*      (J.COMP.CHEM. 7, 385). Step scaling to keep length within */
/*      trust radius is taken from Culot et al. (Theo. Chim. Acta 82, 189) */
/*      The trust radius can be updated dynamically according to Fletcher. */
/*      Safeguards on valid step for TS searches based on actual/predicted */
/*      function change and change in TS mode are own modifications */

/*  ON ENTRY XPARAM = VALUES OF PARAMETERS TO BE OPTIMISED. */
/*           NVAR   = NUMBER OF PARAMETERS TO BE OPTIMISED. */

/*  ON EXIT  XPARAM = OPTIMISED PARAMETERS. */
/*           FUNCT  = HEAT OF FORMATION IN KCAL/MOL. */

/*  Current version implementing combined NR, P-RFO and QA algorithm */
/*      together with thrust radius update and step rejection was */
/*      made october 1992 by F.Jensen, Odense, DK */

/* ********************************************************************* */

/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /TIME  / TIME0 */
/* ***************************** at 1994-05-25 ***** */
/* ONVEX      COMMON /NLLCOM/ HESS(MAXPAR,MAXPAR),BMAT(MAXPAR,MAXPAR), */
/* ONVEX     1PMAT(MAXPAR*MAXPAR) */
/* ONVEX      COMMON /SCRACH/ PVEC */
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON/FLUSH/NFLUSH */
/* ***************************** at 1994-05-25 ***** */
    /* Parameter adjustments */
    --xparam;

    /* Function Body */
/*     GET ALL INITIALIZATION DATA */
    if (icalcn != numcal_1.numcal) {
	efstr_(&xparam[1], funct, ihess, &ntime, &iloop, &igthes, &mxstep, &
		ireclc, &iupd, &dmax__, &ddmax, &dmin__, &tol2, &totime, &
		time1, &time2, nvar, &scf1, &lupd, &ldump, &log__, &rrscal, &
		donr, &gnmin);
    }
    lts = FALSE_;
    if (optef_1.negreq == 1) {
	lts = TRUE_;
    }
    lorjk = FALSE_;
/*     osmin is smallest step for which a ts-mode overlap less than omin */
/*     will be rejected. for updated hessians there is little hope of */
/*     better overlap by reducing the step below 0.005. for exact hessian */
/*     the overlap should go toward one as the step become smaller, but */
/*     don't allow very small steps */
    osmin = .005;
    if (ireclc == 1) {
	osmin = .001;
    }
    if (scf1) {
	gradnt_1.gnfina = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
	mesage_1.iflepo = 1;
	return 0;
    }
/*     CHECK THAT GEOMETRY IS NOT ALREADY OPTIMIZED */
    rmx = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    if (rmx < tol2) {
	mesage_1.iflepo = 2;
	last_1.last = 1;
	return 0;
    }
/*     GET INITIAL HESSIAN. IF ILOOP IS .LE.0 THIS IS AN OPTIMIZATION RESTART */
/*     AND HESSIAN SHOULD ALREADY BE AVAILABLE */
    if (iloop > 0) {
	gethes_(&xparam[1], &igthes, nvar, &iloop, &totime);
    }
/*     START OF MAIN LOOP */
/*     WE NOW HAVE GRADIENTS AND A HESSIAN. IF THIS IS THE FIRST */
/*     TIME THROUGH DON'T UPDATE THE HESSIAN. FOR LATER LOOPS ALSO */
/*     CHECK IF WE NEED TO RECALCULATE THE HESSIAN */
    mesage_1.iflepo = 0;
    itime = 0;
L10:
/*     store various things for possibly omin rejection */
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	oldfx[i__ - 1] = fx[i__ - 1];
	ooldf[i__ - 1] = optef_1.oldf[i__ - 1];
	oldeig[i__ - 1] = eigval[i__ - 1];
	i__2 = *nvar;
	for (j = 1; j <= i__2; ++j) {
	    oldhss[i__ + j * 360 - 361] = nllcom_1.hess[i__ + j * 360 - 361];
	    oldu[i__ + j * 360 - 361] = optef_1.u[i__ + j * 360 - 361];
/* L20: */
	}
/* L30: */
    }
    if (*ihess >= ireclc && mesage_1.iflepo != 15) {
	iloop = 1;
	*ihess = 0;
	if (igthes != 3) {
	    igthes = 1;
	}
	gethes_(&xparam[1], &igthes, nvar, &iloop, &totime);
    }
    if (*ihess > 0) {
	updhes_(svec, tvec, nvar, &iupd);
    }
    if (optef_1.iprnt >= 2) {
	geout_(&c__6);
    }
    if (optef_1.iprnt >= 2) {
	s_wsfe(&io___53);
	e_wsfe();
	s_wsfe(&io___54);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&geovar_1.loc[(i__ << 1) - 2], (ftnlen)
		    sizeof(integer));
	    do_fio(&c__1, (char *)&geovar_1.loc[(i__ << 1) - 1], (ftnlen)
		    sizeof(integer));
	    do_fio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___55);
	e_wsfe();
	s_wsfe(&io___56);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }

/*        PRINT RESULTS IN CYCLE */
    gradnt_1.gnfina = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    time2 = second_();
    if (itime == 0) {
	time1 = timec_1.time0;
    }
    tstep = time2 - time1;
    if (tstep < zero) {
	tstep = zero;
    }
    timdmp_1.tleft -= tstep;
    time1 = time2;
    ++itime;
    if (timdmp_1.tleft < tstep * two) {
	goto L280;
    }
    if (ldump == 0) {
	s_wsfe(&io___58);
	i__1 = optef_1.nstep + 1;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	d__1 = min(tstep,9999.99);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	d__2 = min(timdmp_1.tleft,9999999.9);
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	d__3 = min(gradnt_1.gnfina,999999.999);
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (log__) {
	    s_wsfe(&io___59);
	    i__1 = optef_1.nstep + 1;
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    d__1 = min(tstep,9999.99);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    d__3 = min(gradnt_1.gnfina,999999.999);
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (flushc_1.nflush != 0) {
	    if ((optef_1.nstep + 1) % flushc_1.nflush == 0) {
		flush_(&c__6);
		flush_(&c__11);
	    }
	}
    } else {
	s_wsfe(&io___60);
	d__1 = min(timdmp_1.tleft,9999999.9);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	d__2 = min(gradnt_1.gnfina,999999.999);
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (log__) {
	    s_wsfe(&io___61);
	    d__1 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(gradnt_1.gnfina,999999.999);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (flushc_1.nflush != 0) {
	    if ((optef_1.nstep + 1) % flushc_1.nflush == 0) {
		flush_(&c__6);
		flush_(&c__11);
	    }
	}
    }
    ++(*ihess);
    ++optef_1.nstep;

/*        TEST FOR CONVERGENCE */

    rmx = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    if (rmx < tol2) {
	goto L250;
    }
    olde = *funct;
    oldgn = rmx;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	optef_1.oldf[i__ - 1] = gradnt_1.grad[i__ - 1];
/* L60: */
    }

/*     if the optimization is in cartesian coordinates, we should remove */
/*     translation and rotation modes. Possible problem if run is in */
/*     internal but with exactly 3*natoms variable (i.e. dummy atoms */
/*     are also optimized). */
    if (*nvar == molkst_1.numat * 3) {
	if (optef_1.nstep == 1) {
	    s_wsfe(&io___64);
	    e_wsfe();
	}
	prjfc_(nllcom_1.hess, &xparam[1], nvar);
    }
    ij = 0;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++ij;
	    hessc[ij - 1] = nllcom_1.hess[j + i__ * 360 - 361];
/* L80: */
	}
    }
/* ONVEX      CALL HQRII(HESSC,NVAR,NVAR,EIGVAL,UC) */
    rsp_(hessc, nvar, nvar, eigval, uc);
    ij = 0;
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
	if ((d__1 = eigval[i__ - 1], abs(d__1)) < tmsix) {
	    eigval[i__ - 1] = zero;
	}
	i__1 = *nvar;
	for (j = 1; j <= i__1; ++j) {
	    ++ij;
	    optef_1.u[j + i__ * 360 - 361] = uc[ij - 1];
/* L90: */
	}
    }
    if (optef_1.iprnt >= 3) {
	prthes_(eigval, nvar);
    }
    if (mxstep == 0) {
	optef_1.nstep = 0;
    }
    if (mxstep == 0) {
	goto L280;
    }
    neg = 0;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (eigval[i__ - 1] < zero) {
	    ++neg;
	}
/* L100: */
    }
    if (optef_1.iprnt >= 1) {
	s_wsfe(&io___69);
	do_fio(&c__1, (char *)&neg, (ftnlen)sizeof(integer));
	i__1 = neg;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&eigval[i__ - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_wsfe();
    }
/*     if an eigenvalue has been zero out it is probably one of the T,R modes */
/*     in a cartesian optimization. zero corresponding fx to allow formation */
/*     of step without these contributions. a more safe criteria for deciding */
/*     whether this actually is a cartesian optimization should be put in */
/*     some day... */
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fx[i__ - 1] = dot_(&optef_1.u[i__ * 360 - 360], gradnt_1.grad, nvar);
	if ((d__1 = eigval[i__ - 1], abs(d__1)) == zero) {
	    fx[i__ - 1] = zero;
	}
/* L120: */
    }
/*     form geometry step d */
L130:
    formd_(eigval, fx, nvar, &dmax__, &osmin, &lts, &lrjk, &lorjk, &rrscal, &
	    donr);
/*     if lorjk is true, then ts mode overlap is less than omin, reject prev step */
    if (lorjk) {
	if (optef_1.iprnt >= 1) {
	    s_wsle(&io___71);
	    do_lio(&c__9, &c__1, "      Now undoing previous step", (ftnlen)
		    31);
	    e_wsle();
	}
	dmax__ = odmax;
	optef_1.dd = odd;
	olde = oolde;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    fx[i__ - 1] = oldfx[i__ - 1];
	    optef_1.oldf[i__ - 1] = ooldf[i__ - 1];
	    eigval[i__ - 1] = oldeig[i__ - 1];
	    i__2 = *nvar;
	    for (j = 1; j <= i__2; ++j) {
		nllcom_1.hess[i__ + j * 360 - 361] = oldhss[i__ + j * 360 - 
			361];
		optef_1.u[i__ + j * 360 - 361] = oldu[i__ + j * 360 - 361];
	    }
	}
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xparam[i__] -= optef_1.d__[i__ - 1];
	    k = geovar_1.loc[(i__ << 1) - 2];
	    l = geovar_1.loc[(i__ << 1) - 1];
	    geom_1.geo[l + k * 3 - 4] = xparam[i__];
/* L140: */
	}
	if (geosym_1.ndep != 0) {
	    symtry_();
	}
	dmax__ = min(dmax__,optef_1.dd) / two;
	odmax = dmax__;
	odd = optef_1.dd;
	--optef_1.nstep;
	if (dmax__ < dmin__) {
	    goto L230;
	}
	if (optef_1.iprnt >= 1) {
	    s_wsle(&io___77);
	    do_lio(&c__9, &c__1, "      Finish undoing, now going for new st"
		    "ep", (ftnlen)44);
	    e_wsle();
	}
	goto L130;
    }

/*  FORM NEW TRIAL XPARAM AND GEO */

    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xparam[i__] += optef_1.d__[i__ - 1];
	k = geovar_1.loc[(i__ << 1) - 2];
	l = geovar_1.loc[(i__ << 1) - 1];
	geom_1.geo[l + k * 3 - 4] = xparam[i__];
/* L150: */
    }
    if (geosym_1.ndep != 0) {
	symtry_();
    }

/*     COMPARE PREDICTED E-CHANGE WITH ACTUAL */

    depre = zero;
    imode = 1;
    if (optef_1.mode != 0) {
	imode = optef_1.mode;
    }
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xtmp = optef_1.xlamd;
	if (lts && i__ == imode) {
	    xtmp = optef_1.xlamd0;
	}
	if ((d__1 = xtmp - eigval[i__ - 1], abs(d__1)) < tmtwo) {
	    ss = zero;
	} else {
	    ss = optef_1.skal * fx[i__ - 1] / (xtmp - eigval[i__ - 1]);
	}
	frodo = ss * fx[i__ - 1] + pt5 * ss * ss * eigval[i__ - 1];
/*        write(6,88)i,fx(i),ss,xtmp,eigval(i),frodo */
	depre += frodo;
/* L160: */
    }
/* 88   format(i3,f10.3,f10.6,f10.3,4f10.6) */

/*     GET GRADIENT FOR NEW GEOMETRY */

    compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &c_true);
    if (gnmin) {
	gntest = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    }
    deact = *funct - olde;
    ratio = deact / depre;
    if (optef_1.iprnt >= 1) {
	s_wsfe(&io___86);
	do_fio(&c__1, (char *)&deact, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&depre, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ratio, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    lrjk = FALSE_;
/*     if this is a minimum search, don't allow the energy to raise */
    if (! lts && *funct > olde) {
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___87);
	    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	    d__1 = min(dmax__,optef_1.dd) / two;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	lrjk = TRUE_;
    }
    if (gnmin && gntest > oldgn) {
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___88);
	    do_fio(&c__1, (char *)&gntest, (ftnlen)sizeof(doublereal));
	    d__1 = min(dmax__,optef_1.dd) / two;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	lrjk = TRUE_;
    }
    if (lts && (ratio < optef_1.rmin || ratio > optef_1.rmax) && (abs(depre) 
	    > demin || abs(deact) > demin)) {
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___89);
	    d__1 = min(dmax__,optef_1.dd) / two;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	lrjk = TRUE_;
    }
    if (lrjk) {
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xparam[i__] -= optef_1.d__[i__ - 1];
	    k = geovar_1.loc[(i__ << 1) - 2];
	    l = geovar_1.loc[(i__ << 1) - 1];
	    geom_1.geo[l + k * 3 - 4] = xparam[i__];
/* L200: */
	}
	if (geosym_1.ndep != 0) {
	    symtry_();
	}
	dmax__ = min(dmax__,optef_1.dd) / two;
	if (dmax__ < dmin__) {
	    goto L230;
	}
	goto L130;
    }
    if (optef_1.iprnt >= 1) {
	s_wsfe(&io___90);
	do_fio(&c__1, (char *)&optef_1.dd, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (optef_1.iprnt >= 2) {
	s_wsfe(&io___91);
	e_wsfe();
	s_wsfe(&io___92);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&optef_1.d__[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }

/*     POSSIBLE USE DYNAMICAL TRUST RADIUS */
    odmax = dmax__;
    odd = optef_1.dd;
    oolde = olde;
    if (lupd && (rmx > gmin || (abs(depre) > demin || abs(deact) > demin))) {
/*     Fletcher recommend dmax=dmax/4 and dmax=dmax*2 */
/*     these are are a little more conservative since hessian is being updated */
/*     don't reduce trust radius due to ratio for min searches */
	if (lts && ratio <= tmone || ratio >= three) {
	    dmax__ = min(dmax__,optef_1.dd) / two;
	}
	if (lts && ratio >= pt75 && ratio <= four / three && optef_1.dd > 
		dmax__ - tmsix) {
	    dmax__ *= sqrt(two);
	}
/*     allow wider limits for increasing trust radius for min searches */
	if (! lts && ratio >= pt5 && optef_1.dd > dmax__ - tmsix) {
	    dmax__ *= sqrt(two);
	}
/*     be brave if  0.90 < ratio < 1.10 ... */
	if ((d__1 = ratio - one, abs(d__1)) < tmone) {
	    dmax__ *= sqrt(two);
	}
/* Computing MAX */
	d__1 = dmax__, d__2 = dmin__ - tmsix;
	dmax__ = max(d__1,d__2);
	dmax__ = min(dmax__,ddmax);
    }
/*     allow stepsize up to 0.1 in the end-game where changes are less */
/*     than demin and gradient is less than gmin */
    if (lupd && rmx < gmin && (abs(depre) < demin && abs(deact) < demin)) {
	dmax__ = max(dmax__,tmone);
    }
    if (optef_1.iprnt >= 1) {
	s_wsfe(&io___93);
	do_fio(&c__1, (char *)&dmax__, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
L230:
    if (dmax__ < dmin__) {
	s_wsfe(&io___94);
	do_fio(&c__1, (char *)&dmin__, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L270;
    }
/*     CHECK STEPS AND ENOUGH TIME FOR ANOTHER PASS */
    if (optef_1.nstep >= mxstep) {
	goto L280;
    }
/*     IN USER UNFRIENDLY ENVIROMENT, SAVE RESULTS EVERY 1 CPU HRS */
    d__1 = (time2 - timec_1.time0) / timdmp_1.tdump;
    ittest = (integer) d_int(&d__1);
    if (ittest > ntime) {
	ldump = 1;
/* Computing MAX */
	i__1 = ittest, i__2 = ntime + 1;
	ntime = max(i__1,i__2);
	ipow[8] = 2;
	tt0 = second_() - timec_1.time0;
	i__1 = -optef_1.nstep;
	efsav_(&tt0, nllcom_1.hess, funct, gradnt_1.grad, &xparam[1], 
		nllcom_1.pmat, &i__1, &optef_1.nstep, nllcom_1.bmat, ipow);
    } else {
	ldump = 0;
    }
/*     RETURN FOR ANOTHER CYCLE */
    goto L10;

/*     ****** OPTIMIZATION TERMINATION ****** */

L250:
    s_wsfe(&io___97);
    do_fio(&c__1, (char *)&rmx, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&tol2, (ftnlen)sizeof(doublereal));
    e_wsfe();
L270:
    mesage_1.iflepo = 15;
    last_1.last = 1;
/*     SAVE HESSIAN ON FILE 9 */
    ipow[8] = 2;
    tt0 = second_() - timec_1.time0;
    i__1 = -optef_1.nstep;
    efsav_(&tt0, nllcom_1.hess, funct, gradnt_1.grad, &xparam[1], 
	    nllcom_1.pmat, &i__1, &optef_1.nstep, nllcom_1.bmat, ipow);
/*     CALL COMPFG TO CALCULATE ENERGY FOR FIXING MO-VECTOR BUG */
    compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &c_false);
    return 0;
L280:
/*     WE RAN OUT OF TIME or too many iterations. DUMP RESULTS */
    if (timdmp_1.tleft < tstep * two) {
	s_wsfe(&io___98);
	e_wsfe();
    }
    if (optef_1.nstep >= mxstep) {
	s_wsfe(&io___99);
	e_wsfe();
    }
    ipow[8] = 1;
    tt0 = second_() - timec_1.time0;
    i__1 = -optef_1.nstep;
    efsav_(&tt0, nllcom_1.hess, funct, gradnt_1.grad, &xparam[1], 
	    nllcom_1.pmat, &i__1, &optef_1.nstep, nllcom_1.bmat, ipow);
    s_stop("", (ftnlen)0);
    return 0;
} /* ef_ */

#undef ihess
#undef ipow


/* Subroutine */ int efsav_(doublereal *tt0, doublereal *hess, doublereal *
	funct, doublereal *grad, doublereal *xparam, doublereal *pmat, 
	integer *il, integer *jl, doublereal *bmat, integer *ipow)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_rew(alist *);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void)
	    , f_clos(cllist *), s_rsue(cilist *), e_rsue(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, ir;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int geout_(integer *);
    static doublereal funct1;
    static integer linear;

    /* Fortran I/O blocks */
    static cilist io___102 = { 0, 6, 0, "(//10X,'CURRENT VALUE OF GRADIENT N"
	    "ORM ='          ,F12.6)", 0 };
    static cilist io___103 = { 0, 6, 0, "(/10X,'CURRENT VALUE OF GEOMETRY',/)"
	    , 0 };
    static cilist io___104 = { 0, 0, 0, 0, 0 };
    static cilist io___105 = { 0, 0, 0, 0, 0 };
    static cilist io___107 = { 0, 0, 0, 0, 0 };
    static cilist io___108 = { 0, 0, 0, 0, 0 };
    static cilist io___110 = { 0, 0, 0, 0, 0 };
    static cilist io___111 = { 0, 0, 0, 0, 0 };
    static cilist io___112 = { 0, 0, 0, 0, 0 };
    static cilist io___114 = { 0, 0, 0, 0, 0 };
    static cilist io___115 = { 0, 10, 0, 0, 0 };
    static cilist io___116 = { 0, 10, 0, 0, 0 };
    static cilist io___117 = { 0, 0, 0, 0, 0 };
    static cilist io___118 = { 0, 0, 0, 0, 0 };
    static cilist io___119 = { 1, 0, 1, 0, 0 };
    static cilist io___120 = { 0, 6, 0, "(//10X,'TOTAL TIME USED SO FAR:',  "
	    "                     F13.2,' SECONDS')", 0 };
    static cilist io___121 = { 0, 6, 0, "(  10X,'              FUNCTION:',F1"
	    "7.6)", 0 };
    static cilist io___122 = { 0, 0, 0, 0, 0 };
    static cilist io___123 = { 0, 0, 0, 0, 0 };
    static cilist io___124 = { 0, 0, 0, 0, 0 };
    static cilist io___125 = { 0, 0, 0, 0, 0 };
    static cilist io___126 = { 0, 0, 0, 0, 0 };
    static cilist io___127 = { 0, 0, 0, 0, 0 };
    static cilist io___128 = { 0, 0, 0, 0, 0 };
    static cilist io___129 = { 0, 10, 0, 0, 0 };
    static cilist io___130 = { 0, 10, 0, 0, 0 };
    static cilist io___131 = { 0, 0, 0, 0, 0 };
    static cilist io___132 = { 0, 0, 0, 0, 0 };
    static cilist io___133 = { 0, 6, 0, "(//10X,'NO RESTART FILE EXISTS!')", 
	    0 };


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

/* EFSAV STORES AND RETRIEVE DATA USED IN THE EF GEOMETRY */
/*        OPTIMISATION. VERY SIMILAR TO POWSAV. */

/*  ON INPUT HESS   = HESSIAN MATRIX, PARTIAL OR WHOLE. */
/*           GRAD   = GRADIENTS. */
/*           XPARAM = CURRENT STATE OF PARAMETERS. */
/*           IL     = INDEX OF HESSIAN, */
/*           JL     = CYCLE NUMBER REACHED SO-FAR. */
/*           BMAT   = "B" MATRIX! */
/*           IPOW   = INDICES AND FLAGS. */
/*           IPOW(9)= 0 FOR RESTORE, 1 FOR DUMP, 2 FOR SILENT DUMP */

/* ********************************************************************* */
    /* Parameter adjustments */
    --ipow;
    bmat -= 361;
    --pmat;
    --xparam;
    --grad;
    hess -= 361;

    /* Function Body */
    o__1.oerr = 0;
    o__1.ounit = 9;
    o__1.ofnmlen = 6;
    o__1.ofnm = "FOR009";
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 9;
    f_rew(&al__1);
    o__1.oerr = 0;
    o__1.ounit = 10;
    o__1.ofnmlen = 6;
    o__1.ofnm = "FOR010";
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 10;
    f_rew(&al__1);
    ir = 9;
    if (ipow[9] == 1 || ipow[9] == 2) {
	funct1 = sqrt(dot_(&grad[1], &grad[1], &geovar_2.nvar));
	if (ipow[9] == 1) {
	    s_wsfe(&io___102);
	    do_fio(&c__1, (char *)&funct1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___103);
	    e_wsfe();
	    geout_(&c__6);
	}

/*  IPOW(1) AND IPOW(9) ARE USED ALREADY, THE REST ARE FREE FOR USE */

	ipow[8] = numscf_1.nscf;
	io___104.ciunit = ir;
	s_wsue(&io___104);
	do_uio(&c__9, (char *)&ipow[1], (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*il), (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*jl), (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&(*tt0), (ftnlen)sizeof(doublereal));
	e_wsue();
	io___105.ciunit = ir;
	s_wsue(&io___105);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___107.ciunit = ir;
	s_wsue(&io___107);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&grad[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___108.ciunit = ir;
	s_wsue(&io___108);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = geovar_2.nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_uio(&c__1, (char *)&hess[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	io___110.ciunit = ir;
	s_wsue(&io___110);
	i__2 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = geovar_2.nvar;
	    for (j = 1; j <= i__1; ++j) {
		do_uio(&c__1, (char *)&bmat[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	io___111.ciunit = ir;
	s_wsue(&io___111);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&optef_1.oldf[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	i__2 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&optef_1.d__[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	i__3 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    do_uio(&c__1, (char *)&optef_1.vmode[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	io___112.ciunit = ir;
	s_wsue(&io___112);
	do_uio(&c__1, (char *)&optef_1.dd, (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&optef_1.mode, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&optef_1.nstep, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&optef_1.negreq, (ftnlen)sizeof(integer));
	e_wsue();
	linear = geovar_2.nvar * (geovar_2.nvar + 1) / 2;
	io___114.ciunit = ir;
	s_wsue(&io___114);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&pmat[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	s_wsue(&io___115);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	if (molkst_1.nalpha != 0) {
	    s_wsue(&io___116);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsue();
	}
	if (path_1.latom != 0) {
	    io___117.ciunit = ir;
	    s_wsue(&io___117);
	    i__1 = geovar_2.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    do_uio(&c__1, (char *)&alparm_1.alparm[j + i__ * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		}
	    }
	    e_wsue();
	    io___118.ciunit = ir;
	    s_wsue(&io___118);
	    do_uio(&c__1, (char *)&alparm_1.jloop, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&alparm_1.x0, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x2, (ftnlen)sizeof(doublereal));
	    e_wsue();
	}
	cl__1.cerr = 0;
	cl__1.cunit = 9;
	cl__1.csta = 0;
	f_clos(&cl__1);
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
	return 0;
    } else {
/* #         WRITE(6,'(//10X,'' READING DATA FROM DISK''/)') */
	io___119.ciunit = ir;
	i__1 = s_rsue(&io___119);
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = do_uio(&c__9, (char *)&ipow[1], (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = do_uio(&c__1, (char *)&(*il), (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = do_uio(&c__1, (char *)&(*jl), (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = do_uio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = do_uio(&c__1, (char *)&(*tt0), (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L10;
	}
	i__1 = e_rsue();
	if (i__1 != 0) {
	    goto L10;
	}
	numscf_1.nscf = ipow[8];
	i__ = (integer) (*tt0 / 1000000);
	*tt0 -= i__ * 1000000;
	s_wsfe(&io___120);
	do_fio(&c__1, (char *)&(*tt0), (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___121);
	do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___122.ciunit = ir;
	s_rsue(&io___122);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___123.ciunit = ir;
	s_rsue(&io___123);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&grad[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___124.ciunit = ir;
	s_rsue(&io___124);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = geovar_2.nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_uio(&c__1, (char *)&hess[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	io___125.ciunit = ir;
	s_rsue(&io___125);
	i__2 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = geovar_2.nvar;
	    for (j = 1; j <= i__1; ++j) {
		do_uio(&c__1, (char *)&bmat[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	io___126.ciunit = ir;
	s_rsue(&io___126);
	i__1 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&optef_1.oldf[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	i__2 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&optef_1.d__[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	i__3 = geovar_2.nvar;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    do_uio(&c__1, (char *)&optef_1.vmode[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
	io___127.ciunit = ir;
	s_rsue(&io___127);
	do_uio(&c__1, (char *)&optef_1.dd, (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&optef_1.mode, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&optef_1.nstep, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&optef_1.negreq, (ftnlen)sizeof(integer));
	e_rsue();
	linear = geovar_2.nvar * (geovar_2.nvar + 1) / 2;
	io___128.ciunit = ir;
	s_rsue(&io___128);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&pmat[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
/*        READ DENSITY MATRIX */
	s_rsue(&io___129);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
	if (molkst_1.nalpha != 0) {
	    s_rsue(&io___130);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsue();
	}
	if (path_1.latom != 0) {
	    io___131.ciunit = ir;
	    s_rsue(&io___131);
	    i__1 = geovar_2.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    do_uio(&c__1, (char *)&alparm_1.alparm[j + i__ * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		}
	    }
	    e_rsue();
	    io___132.ciunit = ir;
	    s_rsue(&io___132);
	    do_uio(&c__1, (char *)&alparm_1.jloop, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&alparm_1.x0, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x2, (ftnlen)sizeof(doublereal));
	    e_rsue();
	    ++(*il);
	}
	cl__1.cerr = 0;
	cl__1.cunit = 9;
	cl__1.csta = 0;
	f_clos(&cl__1);
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
	return 0;
L10:
	s_wsfe(&io___133);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    return 0;
} /* efsav_ */

/* Subroutine */ int efstr_(doublereal *xparam, doublereal *funct, integer *
	ihess, integer *ntime, integer *iloop, integer *igthes, integer *
	mxstep, integer *ireclc, integer *iupd, doublereal *dmax__, 
	doublereal *ddmax, doublereal *dmin__, doublereal *tol2, doublereal *
	totime, doublereal *time1, doublereal *time2, integer *nvar, logical *
	scf1, logical *lupd, integer *ldump, logical *log__, logical *rrscal, 
	logical *donr, logical *gnmin)
{
    /* Initialized data */

    static integer icalcn = 0;
    static doublereal zzero = 0.;

    /* Format strings */
    static char fmt_25[] = "(/,\002*** WARNING! MORE VARIABLES THAN DEGREES "
	    "OF FREEDOM\002,/)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void), s_wsle(cilist *), 
	    do_lio(integer *, integer *, char *, ftnlen), e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, ip;
    static doublereal tt0;
    static integer its, imin, mtmp, ipow[9];
    extern doublereal reada_(char *, integer *, ftnlen);
    extern /* Subroutine */ int efsav_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     doublereal *, integer *), compfg_(doublereal *, logical *, 
	    doublereal *, logical *, doublereal *, logical *);
    static logical restrt;

    /* Fortran I/O blocks */
    static cilist io___144 = { 0, 6, 0, "(/,A)", 0 };
    static cilist io___145 = { 0, 6, 0, fmt_25, 0 };
    static cilist io___146 = { 0, 6, 0, 0, 0 };
    static cilist io___147 = { 0, 6, 0, 0, 0 };
    static cilist io___148 = { 0, 6, 0, 0, 0 };
    static cilist io___149 = { 0, 6, 0, 0, 0 };
    static cilist io___155 = { 0, 6, 0, "(10X,'RESTARTING HESSIAN AT POINT',"
	    "I4)", 0 };
    static cilist io___156 = { 0, 6, 0, "(10X,'IN OPTIMIZATION STEP',I4)", 0 }
	    ;
    static cilist io___157 = { 0, 6, 0, "(//10X,'RESTARTING OPTIMIZATION AT "
	    "STEP',I4)", 0 };


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

/* ***** Added    by Jiro Toyoda at 1994-05-25 ***** */
/* ***************************** at 1994-05-25 ***** */
    /* Parameter adjustments */
    --xparam;

    /* Function Body */
/*     GET ALL INITIALIZATION DATA */
    *nvar = abs(*nvar);
    *ldump = 0;
    icalcn = numcal_1.numcal;
    *lupd = i_indx(keywrd_1.keywrd, " NOUPD", (ftnlen)241, (ftnlen)6) == 0;
    restrt = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0;
    *log__ = i_indx(keywrd_1.keywrd, "NOLOG", (ftnlen)241, (ftnlen)5) == 0;
    *scf1 = i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0;
    optef_1.nstep = 0;
    *ihess = 0;
    last_1.last = 0;
    *ntime = 0;
    *iloop = 1;
    imin = i_indx(keywrd_1.keywrd, " EF", (ftnlen)241, (ftnlen)3);
    if (imin != 0) {
	optef_1.mode = 0;
	*igthes = 0;
	*iupd = 2;
	optef_1.negreq = 0;
	*ddmax = .5;
    }
    scftyp_1.limscf = FALSE_;
    its = i_indx(keywrd_1.keywrd, " TS", (ftnlen)241, (ftnlen)3);
    if (its != 0) {
	optef_1.mode = 1;
	*igthes = 1;
	*iupd = 1;
	optef_1.negreq = 1;
	optef_1.rmin = 0.;
	optef_1.rmax = 4.;
	optef_1.omin = .8;
	*ddmax = .3;
    }
    *rrscal = FALSE_;
    i__ = i_indx(keywrd_1.keywrd, " RSCAL", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	*rrscal = TRUE_;
    }
    *donr = TRUE_;
    i__ = i_indx(keywrd_1.keywrd, " NONR", (ftnlen)241, (ftnlen)5);
    if (i__ != 0) {
	*donr = FALSE_;
    }
    *gnmin = FALSE_;
    i__ = i_indx(keywrd_1.keywrd, " GNMIN", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	*gnmin = TRUE_;
    }
    optef_1.iprnt = 0;
    ip = i_indx(keywrd_1.keywrd, " PRNT=", (ftnlen)241, (ftnlen)6);
    if (ip != 0) {
	optef_1.iprnt = (integer) reada_(keywrd_1.keywrd, &ip, (ftnlen)241);
    }
    if (optef_1.iprnt > 5) {
	optef_1.iprnt = 5;
    }
    if (optef_1.iprnt < 0) {
	optef_1.iprnt = 0;
    }
    *mxstep = 100;
    i__ = i_indx(keywrd_1.keywrd, " CYCLES=", (ftnlen)241, (ftnlen)8);
    if (i__ != 0) {
	*mxstep = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    if (i__ != 0 && *mxstep == 0 && ip == 0) {
	optef_1.iprnt = 3;
    }
    *ireclc = 999999;
    i__ = i_indx(keywrd_1.keywrd, " RECALC=", (ftnlen)241, (ftnlen)8);
    if (i__ != 0) {
	*ireclc = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    i__ = i_indx(keywrd_1.keywrd, " IUPD=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	*iupd = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    i__ = i_indx(keywrd_1.keywrd, " MODE=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	optef_1.mode = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    *dmin__ = .001;
    i__ = i_indx(keywrd_1.keywrd, " DDMIN=", (ftnlen)241, (ftnlen)7);
    if (i__ != 0) {
	*dmin__ = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    *dmax__ = .2;
    i__ = i_indx(keywrd_1.keywrd, " DMAX=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	*dmax__ = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    i__ = i_indx(keywrd_1.keywrd, " DDMAX=", (ftnlen)241, (ftnlen)7);
    if (i__ != 0) {
	*ddmax = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    *tol2 = 1.;
/* ------- modified by I. Cserny, June 21, 1995 ------- */
    if (i_indx(keywrd_1.keywrd, " PREC", (ftnlen)241, (ftnlen)5) != 0) {
	*tol2 = .01;
    }
/* ---------------------------------------------------- */
    i__ = i_indx(keywrd_1.keywrd, " GNORM=", (ftnlen)241, (ftnlen)7);
    if (i__ != 0) {
	*tol2 = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    if (i_indx(keywrd_1.keywrd, " LET", (ftnlen)241, (ftnlen)4) == 0 && *tol2 
	    < .01) {
	s_wsfe(&io___144);
	do_fio(&c__1, "  GNORM HAS BEEN SET TOO LOW, RESET TO 0   .01. SPECI"
		"FY LET AS KEYWORD TO ALLOW GNORM LESS THAN 0.01", (ftnlen)100)
		;
	e_wsfe();
	*tol2 = .01;
    }
    i__ = i_indx(keywrd_1.keywrd, " HESS=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	*igthes = (integer) reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    i__ = i_indx(keywrd_1.keywrd, " RMIN=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	optef_1.rmin = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    i__ = i_indx(keywrd_1.keywrd, " RMAX=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	optef_1.rmax = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    i__ = i_indx(keywrd_1.keywrd, " OMIN=", (ftnlen)241, (ftnlen)6);
    if (i__ != 0) {
	optef_1.omin = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    *time1 = timex_1.time0;
    *time2 = *time1;
/*   DONE WITH ALL INITIALIZING STUFF. */
/*   CHECK THAT OPTIONS REQUESTED ARE RESONABLE */
    if (*nvar > molkst_1.numat * 3 - 6 && molkst_1.numat >= 3) {
	s_wsfe(&io___145);
	e_wsfe();
    }
    if (its != 0 && *iupd == 2) {
	s_wsle(&io___146);
	do_lio(&c__9, &c__1, " TS SEARCH AND BFGS UPDATE WILL NOT WORK", (
		ftnlen)40);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    if (its != 0 && *igthes == 0) {
	s_wsle(&io___147);
	do_lio(&c__9, &c__1, " TS SEARCH REQUIRE BETTER THAN DIAGONAL HESSIAN"
		, (ftnlen)47);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    if (*igthes < 0 || *igthes > 3) {
	s_wsle(&io___148);
	do_lio(&c__9, &c__1, " UNRECOGNIZED HESS OPTION", (ftnlen)25);
	do_lio(&c__3, &c__1, (char *)&(*igthes), (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    if (optef_1.omin < 0. || optef_1.omin > 1.) {
	s_wsle(&io___149);
	do_lio(&c__9, &c__1, " OMIN MUST BE BETWEEN 0 AND 1", (ftnlen)29);
	do_lio(&c__5, &c__1, (char *)&optef_1.omin, (ftnlen)sizeof(doublereal)
		);
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    if (restrt) {

/*   RESTORE DATA. I INDICATES (HESSIAN RESTART OR OPTIMIZATION */
/*   RESTART). IF I .GT. 0 THEN HESSIAN RESTART AND I IS LAST */
/*   STEP CALCULATED IN THE HESSIAN. IF I .LE. 0 THEN J (NSTEP) */
/*   IN AN OPTIMIZATION HAS BEEN DONE. */

	ipow[8] = 0;
	mtmp = optef_1.mode;
	efsav_(&tt0, nllcom_1.hess, funct, gradnt_1.grad, &xparam[1], 
		nllcom_1.pmat, &i__, &j, nllcom_1.bmat, ipow);
	optef_1.mode = mtmp;
	k = (integer) (tt0 / 1e6);
	timex_1.time0 = timex_1.time0 - tt0 + k * 1e6;
	*iloop = i__;
	if (i__ > 0) {
	    *igthes = 4;
	    optef_1.nstep = j;
	    s_wsfe(&io___155);
	    do_fio(&c__1, (char *)&(*iloop), (ftnlen)sizeof(integer));
	    e_wsfe();
	    if (optef_1.nstep != 0) {
		s_wsfe(&io___156);
		do_fio(&c__1, (char *)&optef_1.nstep, (ftnlen)sizeof(integer))
			;
		e_wsfe();
	    }
	} else {
	    optef_1.nstep = j;
	    s_wsfe(&io___157);
	    do_fio(&c__1, (char *)&optef_1.nstep, (ftnlen)sizeof(integer));
	    e_wsfe();
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L26: */
		gradnt_1.grad[i__ - 1] = zzero;
	    }
	    compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &
		    c_true);
	}
    } else {
/*   NOT A RESTART, WE NEED TO GET THE GRADIENTS */
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	    gradnt_1.grad[i__ - 1] = zzero;
	}
	compfg_(&xparam[1], &c_true, funct, &c_true, gradnt_1.grad, &c_true);
    }
    return 0;
} /* efstr_ */

/* Subroutine */ int formd_(doublereal *eigval, doublereal *fx, integer *nvar,
	 doublereal *dmax__, doublereal *osmin, logical *ts, logical *lrjk, 
	logical *lorjk, logical *rrscal, logical *donr)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal half = .5;
    static doublereal toll = 1e-8;
    static doublereal step = .05;
    static doublereal ten = 10.;
    static doublereal one = 1.;
    static doublereal big = 1e3;
    static doublereal four = 4.;
    static doublereal tmtwo = .01;
    static doublereal tmsix = 1e-6;
    static doublereal sfix = 10.;
    static doublereal eps = 1e-12;

    /* Format strings */
    static char fmt_1000[] = "(5x,\002WARNING! MODE SWITCHING. WAS FOLLOWING"
	    " MODE \002,i3,\002 NOW FOLLOWING MODE \002,i3)";
    static char fmt_900[] = "(/,5x,\002TS MODE IS NUMBER\002,i3,\002 WITH EI"
	    "GENVALUE\002,f9.1,/,5x,\002AND COMPONENTS\002,/)";
    static char fmt_910[] = "(5x,8f9.4)";
    static char fmt_1030[] = "(1x,\002lamda that maximizes along ts modes = "
	    "  \002,f15.5)";
    static char fmt_1031[] = "(1x,\002lamda that minimizes along all modes ="
	    "  \002,f15.5)";
    static char fmt_777[] = "(1x,\002pure NR-step has length\002,f10.5)";
    static char fmt_778[] = "(1x,\002P-RFO-step   has length\002,f10.5)";
    static char fmt_170[] = "(5x,\002CALCULATED STEP SIZE TOO LARGE, SCALED "
	    "WITH\002,f9.5)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal bl, fl, fm, bu, fu;
    static integer it, jt;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal eone;
    static integer ncnt;
    static doublereal temp, d2max, lamda, eigit;
    static logical rscal;
    static integer maxit;
    static doublereal ssmin, ssmax;
    static integer numit;
    static doublereal lamda0, sstep;
    static logical frodo1, frodo2;
    static doublereal xlamda;
    static integer newmod;
    extern /* Subroutine */ int overlp_(doublereal *, doublereal *, integer *,
	     integer *, logical *);
    static doublereal sstoll;

    /* Fortran I/O blocks */
    static cilist io___177 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___179 = { 0, 6, 0, fmt_900, 0 };
    static cilist io___180 = { 0, 6, 0, fmt_910, 0 };
    static cilist io___191 = { 0, 6, 0, 0, 0 };
    static cilist io___192 = { 0, 6, 0, 0, 0 };
    static cilist io___193 = { 0, 6, 0, fmt_1030, 0 };
    static cilist io___199 = { 0, 6, 0, 0, 0 };
    static cilist io___200 = { 0, 6, 0, 0, 0 };
    static cilist io___204 = { 0, 6, 0, 0, 0 };
    static cilist io___205 = { 0, 6, 0, fmt_1031, 0 };
    static cilist io___207 = { 0, 6, 0, 0, 0 };
    static cilist io___209 = { 0, 6, 0, fmt_777, 0 };
    static cilist io___210 = { 0, 6, 0, fmt_778, 0 };
    static cilist io___211 = { 0, 6, 0, fmt_170, 0 };
    static cilist io___212 = { 0, 6, 0, 0, 0 };
    static cilist io___213 = { 0, 6, 0, 0, 0 };
    static cilist io___214 = { 0, 6, 0, 0, 0 };


/*     This version forms geometry step by either pure NR, P-RFO or QA */
/*     algorithm, under the condition that the steplength is less than dmax */
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
    --fx;
    --eigval;

    /* Function Body */

    maxit = 999;
    numit = 0;
    optef_1.skal = one;
    rscal = *rrscal;
    it = 0;
    jt = 1;
    if (*ts) {
	if (optef_1.mode != 0) {
	    overlp_(dmax__, osmin, &newmod, nvar, lorjk);
	    if (*lorjk) {
		return 0;
	    }

/*  ON RETURN FROM OVERLP, NEWMOD IS THE TS MODE */

	    if (newmod != optef_1.mode && optef_1.iprnt >= 1) {
		s_wsfe(&io___177);
		do_fio(&c__1, (char *)&optef_1.mode, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&newmod, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	    optef_1.mode = newmod;
	    it = optef_1.mode;
	} else {
	    it = 1;
	}
	eigit = eigval[it];
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___179);
	    do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&eigit, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___180);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&optef_1.u[i__ + it * 360 - 361], (
			ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    if (it == 1) {
	jt = 2;
    }
    eone = eigval[jt];
/* Computing MAX */
    d__1 = abs(eone) * eps, d__2 = ten * eps;
    ssmin = max(d__1,d__2);
/* Computing MAX */
    d__1 = big, d__2 = abs(eone);
    ssmax = max(d__1,d__2);
    ssmax *= big;
    sstoll = toll;
    d2max = *dmax__ * *dmax__;
/*     write(6,*)'from formd, eone, ssmin, ssmax, sstoll', */
/*    $eone,ssmin,ssmax,sstoll */
/*  SOLVE ITERATIVELY FOR LAMDA */
/*  INITIAL GUESS FOR LAMDA IS ZERO EXCEPT NOTE THAT */
/*  LAMDA SHOULD BE LESS THAN EIGVAL(1) */
/*  START BY BRACKETING ROOT, THEN HUNT IT DOWN WITH BRUTE FORCE BISECT. */

    frodo1 = FALSE_;
    frodo2 = FALSE_;
    lamda = zero;
    lamda0 = zero;
    if (*ts && eigit < zero && eone >= zero && *donr) {
	if (optef_1.iprnt >= 1) {
	    s_wsle(&io___191);
	    do_lio(&c__9, &c__1, " ts search, correct hessian, trying pure N"
		    "R step", (ftnlen)48);
	    e_wsle();
	}
	goto L776;
    }
    if (! (*ts) && eone >= zero && *donr) {
	if (optef_1.iprnt >= 1) {
	    s_wsle(&io___192);
	    do_lio(&c__9, &c__1, " min search, correct hessian, trying pure "
		    "NR step", (ftnlen)49);
	    e_wsle();
	}
	goto L776;
    }
L5:
    if (*ts) {
/* Computing 2nd power */
	d__1 = eigval[it];
/* Computing 2nd power */
	d__2 = fx[it];
	lamda0 = eigval[it] + sqrt(d__1 * d__1 + four * (d__2 * d__2));
	lamda0 *= half;
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___193);
	    do_fio(&c__1, (char *)&lamda0, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    sstep = step;
    if (eone <= zero) {
	lamda = eone - sstep;
    }
    if (eone > zero) {
	sstep = eone;
    }
    bl = lamda - sstep;
    bu = lamda + sstep * half;
L20:
    fl = zero;
    fu = zero;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == it) {
	    goto L30;
	}
	fl += fx[i__] * fx[i__] / (bl - eigval[i__]);
	fu += fx[i__] * fx[i__] / (bu - eigval[i__]);
L30:
	;
    }
    fl -= bl;
    fu -= bu;
/*        write(6,*)'bl,bu,fl,fu from brack' */
/*        write(6,668)bl,bu,fl,fu */
/* 668     format(6f20.15) */
    if (fl * fu < zero) {
	goto L40;
    }
    bl -= eone - bl;
    bu += half * (eone - bu);
    if (bl <= -ssmax) {
	bl = -ssmax;
	frodo1 = TRUE_;
    }
    if ((d__1 = eone - bu, abs(d__1)) <= ssmin) {
	bu = eone - ssmin;
	frodo2 = TRUE_;
    }
    if (frodo1 && frodo2) {
	s_wsle(&io___199);
	do_lio(&c__9, &c__1, "NUMERICAL PROBLEMS IN BRACKETING LAMDA", (
		ftnlen)38);
	do_lio(&c__5, &c__1, (char *)&eone, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&bl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&bu, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fu, (ftnlen)sizeof(doublereal));
	e_wsle();
	s_wsle(&io___200);
	do_lio(&c__9, &c__1, " going for fixed step size....", (ftnlen)30);
	e_wsle();
	goto L450;
    }
    goto L20;
L40:
    ncnt = 0;
    xlamda = zero;
L50:
    fl = zero;
    fu = zero;
    fm = zero;
    lamda = half * (bl + bu);
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == it) {
	    goto L60;
	}
	fl += fx[i__] * fx[i__] / (bl - eigval[i__]);
	fu += fx[i__] * fx[i__] / (bu - eigval[i__]);
	fm += fx[i__] * fx[i__] / (lamda - eigval[i__]);
L60:
	;
    }
    fl -= bl;
    fu -= bu;
    fm -= lamda;
/*        write(6,*)'bl,bu,lamda,fl,fu,fm from search' */
/*        write(6,668)bl,bu,lamda,fl,fu,fm */
    if ((d__1 = xlamda - lamda, abs(d__1)) < sstoll) {
	goto L776;
    }
    ++ncnt;
    if (ncnt > 1000) {
	s_wsle(&io___204);
	do_lio(&c__9, &c__1, "TOO MANY ITERATIONS IN LAMDA BISECT", (ftnlen)
		35);
	do_lio(&c__5, &c__1, (char *)&bl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&bu, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&lamda, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fu, (ftnlen)sizeof(doublereal));
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    xlamda = lamda;
    if (fm * fu < zero) {
	bl = lamda;
    }
    if (fm * fl < zero) {
	bu = lamda;
    }
    goto L50;

L776:
    if (optef_1.iprnt >= 1) {
	s_wsfe(&io___205);
	do_fio(&c__1, (char *)&lamda, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

/*  CALCULATE THE STEP */

    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	optef_1.d__[i__ - 1] = zero;
/* L310: */
    }
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (lamda == zero && (d__1 = eigval[i__], abs(d__1)) < tmtwo) {
	    temp = zero;
	} else {
	    temp = fx[i__] / (lamda - eigval[i__]);
	}
	if (i__ == it) {
	    temp = fx[it] / (lamda0 - eigval[it]);
	}
	if (optef_1.iprnt >= 5) {
	    s_wsle(&io___207);
	    do_lio(&c__9, &c__1, "formd, delta step", (ftnlen)17);
	    do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_lio(&c__5, &c__1, (char *)&temp, (ftnlen)sizeof(doublereal));
	    e_wsle();
	}
	i__2 = *nvar;
	for (j = 1; j <= i__2; ++j) {
	    optef_1.d__[j - 1] += temp * optef_1.u[j + i__ * 360 - 361];
/* L320: */
	}
/* L330: */
    }
    optef_1.dd = sqrt(dot_(optef_1.d__, optef_1.d__, nvar));
    if (lamda == zero && lamda0 == zero && optef_1.iprnt >= 1) {
	s_wsfe(&io___209);
	do_fio(&c__1, (char *)&optef_1.dd, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (lamda != zero && lamda0 != -lamda && optef_1.iprnt >= 1) {
	s_wsfe(&io___210);
	do_fio(&c__1, (char *)&optef_1.dd, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (optef_1.dd < *dmax__ + tmsix) {
	optef_1.xlamd = lamda;
	optef_1.xlamd0 = lamda0;
	return 0;
    }
    if (lamda == zero && lamda0 == zero) {
	goto L5;
    }
    if (rscal) {
	optef_1.skal = *dmax__ / optef_1.dd;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    optef_1.d__[i__ - 1] *= optef_1.skal;
/* L160: */
	}
	optef_1.dd = sqrt(dot_(optef_1.d__, optef_1.d__, nvar));
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___211);
	    do_fio(&c__1, (char *)&optef_1.skal, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	optef_1.xlamd = lamda;
	optef_1.xlamd0 = lamda0;
	return 0;
    }
L450:
    lamda = zero;
    frodo1 = FALSE_;
    frodo2 = FALSE_;
    sstep = step;
    if (eone <= zero) {
	lamda = eone - sstep;
    }
    if (*ts && -eigit < eone) {
	lamda = -eigit - sstep;
    }
    if (eone > zero) {
	sstep = eone;
    }
    bl = lamda - sstep;
    bu = lamda + sstep * half;
L520:
    fl = zero;
    fu = zero;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == it) {
	    goto L530;
	}
/* Computing 2nd power */
	d__1 = fx[i__] / (bl - eigval[i__]);
	fl += d__1 * d__1;
/* Computing 2nd power */
	d__1 = fx[i__] / (bu - eigval[i__]);
	fu += d__1 * d__1;
L530:
	;
    }
    if (*ts) {
/* Computing 2nd power */
	d__1 = fx[it] / (bl + eigval[it]);
	fl += d__1 * d__1;
/* Computing 2nd power */
	d__1 = fx[it] / (bu + eigval[it]);
	fu += d__1 * d__1;
    }
    fl -= d2max;
    fu -= d2max;
/*        write(6,*)'bl,bu,fl,fu from brack2' */
/*        write(6,668)bl,bu,fl,fu */
    if (fl * fu < zero) {
	goto L540;
    }
    bl -= eone - bl;
    bu += half * (eone - bu);
    if (bl <= -ssmax) {
	bl = -ssmax;
	frodo1 = TRUE_;
    }
    if ((d__1 = eone - bu, abs(d__1)) <= ssmin) {
	bu = eone - ssmin;
	frodo2 = TRUE_;
    }
    if (frodo1 && frodo2) {
	s_wsle(&io___212);
	do_lio(&c__9, &c__1, "NUMERICAL PROBLEMS IN BRACKETING LAMDA", (
		ftnlen)38);
	do_lio(&c__5, &c__1, (char *)&eone, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&bl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&bu, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fu, (ftnlen)sizeof(doublereal));
	e_wsle();
	s_wsle(&io___213);
	do_lio(&c__9, &c__1, " going for fixed level shifted NR step...", (
		ftnlen)41);
	e_wsle();
/*           both lamda searches failed, go for fixed level shifted nr */
/*           this is unlikely to produce anything useful, but maybe we're lucky */
	lamda = eone - sfix;
	lamda0 = eigit + sfix;
	rscal = TRUE_;
	goto L776;
    }
    goto L520;
L540:
    ncnt = 0;
    xlamda = zero;
L550:
    fl = zero;
    fu = zero;
    fm = zero;
    lamda = half * (bl + bu);
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (i__ == it) {
	    goto L560;
	}
/* Computing 2nd power */
	d__1 = fx[i__] / (bl - eigval[i__]);
	fl += d__1 * d__1;
/* Computing 2nd power */
	d__1 = fx[i__] / (bu - eigval[i__]);
	fu += d__1 * d__1;
/* Computing 2nd power */
	d__1 = fx[i__] / (lamda - eigval[i__]);
	fm += d__1 * d__1;
L560:
	;
    }
    if (*ts) {
/* Computing 2nd power */
	d__1 = fx[it] / (bl + eigval[it]);
	fl += d__1 * d__1;
/* Computing 2nd power */
	d__1 = fx[it] / (bu + eigval[it]);
	fu += d__1 * d__1;
/* Computing 2nd power */
	d__1 = fx[it] / (lamda + eigval[it]);
	fm += d__1 * d__1;
    }
    fl -= d2max;
    fu -= d2max;
    fm -= d2max;
/*        write(6,*)'bl,bu,lamda,fl,fu,fm from search2' */
/*        write(6,668)bl,bu,lamda,fl,fu,fm */
    if ((d__1 = xlamda - lamda, abs(d__1)) < sstoll) {
	goto L570;
    }
    ++ncnt;
    if (ncnt > 1000) {
	s_wsle(&io___214);
	do_lio(&c__9, &c__1, "TOO MANY ITERATIONS IN LAMDA BISECT", (ftnlen)
		35);
	do_lio(&c__5, &c__1, (char *)&bl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&bu, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&lamda, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fl, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&fu, (ftnlen)sizeof(doublereal));
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    xlamda = lamda;
    if (fm * fu < zero) {
	bl = lamda;
    }
    if (fm * fl < zero) {
	bu = lamda;
    }
    goto L550;

L570:
    lamda0 = -lamda;
    rscal = TRUE_;
    goto L776;

} /* formd_ */

/* Subroutine */ int gethes_(doublereal *xparam, integer *igthes, integer *
	nvar, integer *iloop, doublereal *totime)
{
    /* Initialized data */

    static doublereal zzero = 0.;
    static doublereal two = 2.;
    static doublereal dghss = 1e3;
    static doublereal dghsa = 500.;
    static doublereal dghsd = 200.;
    static doublereal xinc = .001;

    /* Format strings */
    static char fmt_60[] = "(/,10x,\002DIAGONAL MATRIX USED AS START HESSIA"
	    "N\002,/)";
    static char fmt_100[] = "(/,10x,\002HESSIAN READ FROM DISK\002,/)";
    static char fmt_190[] = "(/,10x,\002HESSIAN CALCULATED NUMERICALLY\002,/)"
	    ;
    static char fmt_191[] = "(/,10x,\002HESSIAN CALCULATED DOUBLE NUMERICA"
	    "LLY\002,/)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), s_wsle(cilist *), do_lio(integer *
	    , integer *, char *, ftnlen), e_wsle(void), do_fio(integer *, 
	    char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, if__, ij;
    static doublereal tt0, tdm, fdmy;
    static integer mtmp, ipow[9], nxxx;
    static doublereal time1, time2;
    extern /* Subroutine */ int efsav_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     doublereal *, integer *);
    static integer iidum;
    static doublereal funct, dummy, tstep;
    extern doublereal second_(void);
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *);
    static doublereal tstore;
    extern /* Subroutine */ int symtry_(void);

    /* Fortran I/O blocks */
    static cilist io___226 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___230 = { 0, 6, 0, 0, 0 };
    static cilist io___231 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___238 = { 0, 6, 0, fmt_190, 0 };
    static cilist io___239 = { 0, 6, 0, fmt_191, 0 };
    static cilist io___240 = { 0, 6, 0, "(I3,12(8F9.4,/3X))", 0 };
    static cilist io___245 = { 0, 6, 0, "(I3,12(8F9.4,/3X))", 0 };
    static cilist io___246 = { 0, 6, 0, "(I3,12(8F9.4,/3X))", 0 };
    static cilist io___249 = { 0, 6, 0, "(A)", 0 };
    static cilist io___250 = { 0, 6, 0, "(A,I4)", 0 };


/*     GET THE HESSIAN. DEPENDING ON IGTHES WE GET IT FROM : */

/*      0 : DIAGONAL MATRIX, DGHSX*I (DEFAULT FOR MIN-SEARCH) */
/*      1 : CALCULATE IT NUMERICALLY (DEFAULT FOR TS-SEARCH) */
/*      2 : READ IN FROM FTN009 */
/*      3 : CALCULATE IT BY DOUBLE NUMERICAL DIFFERENTIATION */
/*      4 : READ IN FROM FTN009 (DURING RESTART, PARTLY OR WHOLE, */
/*          ALREADY DONE AT THIS POINT) */
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
    --xparam;

    /* Function Body */

/*     DGHSX IS HESSIAN DIAGONAL FOR IGTHES=0 (STRETCHING, ANGLE, */
/*     DIHEDRAL).  THE VALUES SHOULD BE 'OPTIMUM' FOR CYCLOHEXANONE */
/*     XINC IS STEPSIZE FOR HESSIAN CALCULATION. TESTS SHOWS THAT IT SHOULD */
/*     BE IN THE RANGE 10(-2) TO 10(-4). 10(-3) APPEARS TO BE */
/*     A REASONABLE COMPROMISE BETWEEN ACCURACY AND NUMERICAL PROBLEMS */
    if (*igthes == 0) {
	s_wsfe(&io___226);
	e_wsfe();
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = *nvar;
	    for (j = 1; j <= i__2; ++j) {
		nllcom_1.hess[i__ + j * 360 - 361] = zzero;
/* L70: */
	    }
	}
	ij = 1;
	for (j = 1; j <= 120; ++j) {
	    for (i__ = 1; i__ <= 3; ++i__) {
		if (geovar_1.loc[(ij << 1) - 1] == i__ && geovar_1.loc[(ij << 
			1) - 2] == j) {
		    if (i__ == 1) {
			nllcom_1.hess[ij + ij * 360 - 361] = dghss;
		    }
		    if (i__ == 2) {
			nllcom_1.hess[ij + ij * 360 - 361] = dghsa;
		    }
		    if (i__ == 3) {
			nllcom_1.hess[ij + ij * 360 - 361] = dghsd;
		    }
		    ++ij;
		}
/* L80: */
	    }
	}
	--ij;
	if (ij != *nvar) {
	    s_wsle(&io___230);
	    do_lio(&c__9, &c__1, "ERROR IN IGTHES=0,IJ,NVAR", (ftnlen)25);
	    do_lio(&c__3, &c__1, (char *)&ij, (ftnlen)sizeof(integer));
	    do_lio(&c__3, &c__1, (char *)&(*nvar), (ftnlen)sizeof(integer));
	    e_wsle();
	}
    }

    if (*igthes == 2) {
	s_wsfe(&io___231);
	e_wsfe();
	ipow[8] = 0;
/*        USE DUMMY ARRAY FOR CALL EXCEPT FOR HESSIAN */
/*        TEMPORARY SET NALPHA = 0, THEN WE CAN READ HESSIAN FROM RHF */
/*        RUN FOR USE IN SAY UHF RUNS */
/*        ALSO SAVE MODE, TO ALLOW FOLLOWING A DIFFERENT MODE THAN THE ONE */
/*        CURRENTLY ON RESTART FILE */
	nxxx = molkst_1.nalpha;
	molkst_1.nalpha = 0;
	mtmp = optef_1.mode;
	efsav_(&tdm, nllcom_1.hess, &fdmy, sigma2_1.gnext1, sigma2_1.gmin1, 
		nllcom_1.pmat, &iidum, &j, nllcom_1.bmat, ipow);
	molkst_1.nalpha = nxxx;
	optef_1.mode = mtmp;
	optef_1.nstep = 0;
    }
    if (*igthes == 1 || *igthes == 3 || *igthes == 4) {
/*       IF IGTHES IS .EQ. 4, THEN THIS IS A HESSIAN RESTART. */
/*       USE GNEXT1 AND DUMMY FOR CALLS TO COMPFG DURING HESSIAN */
/*       CALCULATION */
	if (*igthes == 1) {
	    s_wsfe(&io___238);
	    e_wsfe();
	}
	if (*igthes == 3) {
	    s_wsfe(&io___239);
	    e_wsfe();
	}
	if (optef_1.iprnt >= 5) {
	    s_wsfe(&io___240);
	    do_fio(&c__1, (char *)&c__0, (ftnlen)sizeof(integer));
	    i__2 = *nvar;
	    for (if__ = 1; if__ <= i__2; ++if__) {
		do_fio(&c__1, (char *)&gradnt_1.grad[if__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
	time1 = second_();
	tstore = time1;
	i__2 = *nvar;
	for (i__ = *iloop; i__ <= i__2; ++i__) {
	    xparam[i__] += xinc;
	    compfg_(&xparam[1], &c_true, &dummy, &c_true, sigma2_1.gnext1, &
		    c_true);
	    if (optef_1.iprnt >= 5) {
		s_wsfe(&io___245);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		i__1 = *nvar;
		for (if__ = 1; if__ <= i__1; ++if__) {
		    do_fio(&c__1, (char *)&sigma2_1.gnext1[if__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
	    }
	    xparam[i__] -= xinc;
	    if (*igthes == 3) {
		xparam[i__] -= xinc;
		compfg_(&xparam[1], &c_true, &dummy, &c_true, sigma2_1.gmin1, 
			&c_true);
		if (optef_1.iprnt >= 5) {
		    s_wsfe(&io___246);
		    i__1 = -i__;
		    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		    i__3 = *nvar;
		    for (if__ = 1; if__ <= i__3; ++if__) {
			do_fio(&c__1, (char *)&sigma2_1.gmin1[if__ - 1], (
				ftnlen)sizeof(doublereal));
		    }
		    e_wsfe();
		}
		xparam[i__] += xinc;
		i__1 = *nvar;
		for (j = 1; j <= i__1; ++j) {
/* L199: */
		    nllcom_1.hess[i__ + j * 360 - 361] = (sigma2_1.gnext1[j - 
			    1] - sigma2_1.gmin1[j - 1]) / (xinc + xinc);
		}
	    } else {
		i__1 = *nvar;
		for (j = 1; j <= i__1; ++j) {
/* L200: */
		    nllcom_1.hess[i__ + j * 360 - 361] = (sigma2_1.gnext1[j - 
			    1] - gradnt_1.grad[j - 1]) / xinc;
		}
	    }
	    time2 = second_();
	    tstep = time2 - time1;
	    timdmp_1.tleft -= tstep;
	    time1 = time2;
	    if (timdmp_1.tleft < tstep * two) {

/*  STORE PARTIAL HESSIAN PATRIX */
/*  STORE GRADIENTS FOR GEOMETRY AND ILOOP AS POSITIVE */
		s_wsfe(&io___249);
		do_fio(&c__1, " NOT ENOUGH TIME TO COMPLETE HESSIAN", (ftnlen)
			36);
		e_wsfe();
		s_wsfe(&io___250);
		do_fio(&c__1, " STOPPING IN HESSIAN AT COORDINATE:", (ftnlen)
			35);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		e_wsfe();
		ipow[8] = 1;
		tt0 = second_() - timex_1.time0;
		efsav_(&tt0, nllcom_1.hess, &funct, gradnt_1.grad, &xparam[1],
			 nllcom_1.pmat, &i__, &optef_1.nstep, nllcom_1.bmat, 
			ipow);
		s_stop("", (ftnlen)0);
	    }
/* L210: */
	}
/*     fix last entry in geo array, this is currently at value-xinc */
	k = geovar_1.loc[(*nvar << 1) - 2];
	l = geovar_1.loc[(*nvar << 1) - 1];
	geom_1.geo[l + k * 3 - 4] = xparam[*nvar];
	if (geosym_1.ndep != 0) {
	    symtry_();
	}
/*        add all time used back to tleft, this will then be subtracted */
/*        again in main ef routine */
	time2 = second_();
	tstep = time2 - tstore;
	timdmp_1.tleft += tstep;
    }

/*     SYMMETRIZE HESSIAN */
    i__2 = *nvar;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* $DIR NO_RECURRENCE */
	i__1 = i__ - 1;
	for (j = 1; j <= i__1; ++j) {
	    nllcom_1.hess[i__ + j * 360 - 361] = (nllcom_1.hess[i__ + j * 360 
		    - 361] + nllcom_1.hess[j + i__ * 360 - 361]) / two;
	    nllcom_1.hess[j + i__ * 360 - 361] = nllcom_1.hess[i__ + j * 360 
		    - 361];
/* L220: */
	}
    }
    return 0;
} /* gethes_ */

/* *MODULE BLAS1   *DECK IDAMAX */
integer idamax_(integer *n, doublereal *dx, integer *incx)
{
    /* System generated locals */
    integer ret_val, i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__, ix;
    static doublereal rmax;


/*     FINDS THE INDEX OF ELEMENT HAVING MAX. ABSOLUTE VALUE. */
/*     JACK DONGARRA, LINPACK, 3/11/78. */

    /* Parameter adjustments */
    --dx;

    /* Function Body */
    ret_val = 0;
    if (*n < 1) {
	return ret_val;
    }
    ret_val = 1;
    if (*n == 1) {
	return ret_val;
    }
    if (*incx == 1) {
	goto L20;
    }

/*        CODE FOR INCREMENT NOT EQUAL TO 1 */

    ix = 1;
    rmax = abs(dx[1]);
    ix += *incx;
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if ((d__1 = dx[ix], abs(d__1)) <= rmax) {
	    goto L5;
	}
	ret_val = i__;
	rmax = (d__1 = dx[ix], abs(d__1));
L5:
	ix += *incx;
/* L10: */
    }
    return ret_val;

/*        CODE FOR INCREMENT EQUAL TO 1 */

L20:
    rmax = abs(dx[1]);
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if ((d__1 = dx[i__], abs(d__1)) <= rmax) {
	    goto L30;
	}
	ret_val = i__;
	rmax = (d__1 = dx[i__], abs(d__1));
L30:
	;
    }
    return ret_val;
} /* idamax_ */

/* Subroutine */ int overlp_(doublereal *dmax__, doublereal *osmin, integer *
	newmod, integer *nvar, logical *lorjk)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* Format strings */
    static char fmt_40[] = "(5x,\002HESSIAN MODE FOLLOWING SWITCHED ON\002"
	    "/\002     FOLLOWING MODE \002,i3)";
    static char fmt_30[] = "(5x,\002OVERLAP OF CURRENT MODE\002,i3,\002 WITH"
	    " PREVIOUS MODE IS \002,f6.3)";
    static char fmt_31[] = "(5x,\002OVERLAP LESS THAN OMIN\002,f6.3,\002 REJ"
	    "ECTING PREVIOUS STEP\002)";
    static char fmt_32[] = "(5x,\002OVERLAP LESS THAN OMIN\002,f6.3,\002 BUT"
	    " TRUST RADIUS\002,f6.3,\002 IS LESS THAN\002,f6.3,/,5x,\002 ACCE"
	    "PTING STEP\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, it, ix;
    static doublereal xo[360];
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal xxx, ovlp, tovlp;

    /* Fortran I/O blocks */
    static cilist io___259 = { 0, 6, 0, 0, 0 };
    static cilist io___261 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___269 = { 0, 6, 0, 0, 0 };
    static cilist io___270 = { 0, 6, 0, fmt_30, 0 };
    static cilist io___271 = { 0, 6, 0, fmt_31, 0 };
    static cilist io___272 = { 0, 6, 0, fmt_32, 0 };


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

/*  ON THE FIRST STEP SIMPLY DETERMINE WHICH MODE TO FOLLOW */

/*     IF(NSTEP.EQ.1) THEN */
    if (first) {
	first = FALSE_;
	if (optef_1.mode > *nvar) {
	    s_wsle(&io___259);
	    do_lio(&c__9, &c__1, "ERROR!! MODE IS LARGER THAN NVAR", (ftnlen)
		    32);
	    do_lio(&c__3, &c__1, (char *)&optef_1.mode, (ftnlen)sizeof(
		    integer));
	    e_wsle();
	    s_stop("", (ftnlen)0);
	}
	it = optef_1.mode;
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___261);
	    do_fio(&c__1, (char *)&optef_1.mode, (ftnlen)sizeof(integer));
	    e_wsfe();
	}

    } else {

/*  ON SUBSEQUENT STEPS DETERMINE WHICH HESSIAN EIGENVECTOR HAS */
/*  THE GREATEST OVERLAP WITH THE MODE WE ARE FOLLOWING */

	it = 1;
	*lorjk = FALSE_;
	tovlp = dot_(optef_1.u, optef_1.vmode, nvar);
	tovlp = abs(tovlp);
/*        xo(1)=tovlp */
	i__1 = *nvar;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    ovlp = dot_(&optef_1.u[i__ * 360 - 360], optef_1.vmode, nvar);
	    ovlp = abs(ovlp);
/*           xo(i)=ovlp */
	    if (ovlp > tovlp) {
		tovlp = ovlp;
		it = i__;
	    }
/* L10: */
	}

	if (optef_1.iprnt >= 5) {
	    for (j = 1; j <= 5; ++j) {
		xxx = 0.;
		i__1 = *nvar;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    if (xo[i__ - 1] > xxx) {
			ix = i__;
		    }
		    if (xo[i__ - 1] > xxx) {
			xxx = xo[i__ - 1];
		    }
		}
		xo[ix - 1] = 0.;
		s_wsle(&io___269);
		do_lio(&c__9, &c__1, "overlaps", (ftnlen)8);
		do_lio(&c__3, &c__1, (char *)&ix, (ftnlen)sizeof(integer));
		do_lio(&c__5, &c__1, (char *)&xxx, (ftnlen)sizeof(doublereal))
			;
		e_wsle();
	    }
	}
	if (optef_1.iprnt >= 1) {
	    s_wsfe(&io___270);
	    do_fio(&c__1, (char *)&it, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&tovlp, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (tovlp < optef_1.omin) {
	    if (*dmax__ > *osmin) {
		*lorjk = TRUE_;
		if (optef_1.iprnt >= 1) {
		    s_wsfe(&io___271);
		    do_fio(&c__1, (char *)&optef_1.omin, (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		}
		return 0;
	    } else {
		if (optef_1.iprnt >= 1) {
		    s_wsfe(&io___272);
		    do_fio(&c__1, (char *)&optef_1.omin, (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, (char *)&(*dmax__), (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, (char *)&(*osmin), (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		}
	    }
	}
    }

/*  SAVE THE EIGENVECTOR IN VMODE */

    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	optef_1.vmode[i__ - 1] = optef_1.u[i__ + it * 360 - 361];
/* L20: */
    }

    *newmod = it;
    return 0;

} /* overlp_ */

/* Subroutine */ int prjfc_(doublereal *f, doublereal *xparam, integer *nvar)
{
    /* Initialized data */

    static doublereal tens[27]	/* was [3][3][3] */ = { 0.,0.,0.,0.,0.,-1.,0.,
	    1.,0.,0.,0.,1.,0.,0.,0.,-1.,0.,0.,0.,-1.,0.,1.,0.,0.,0.,0.,0. };

    /* Format strings */
    static char fmt_14[] = "(1x,\002EVERY DIAGONAL ELEMENTS ARE ZERO ?\002,3"
	    "f20.10)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;
    static doublereal equiv_0[2];

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal p[129600]	/* was [360][360] */, x[360];
    static integer ia, ib, ic, jc, ja, jb, ii, ij, jj, ip, jp;
    static doublereal dx[360], rm[360];
    static integer nc1;
    static doublereal chk, cof[129600]	/* was [360][360] */;
#define det (equiv_0)
    static doublereal scr[9]	/* was [3][3] */, tmp, rot[9]	/* was [3][3] 
	    */, trp, sum;
    static integer jend, info, natm, iscr[6], indx, jndx;
#define detx (equiv_0)
    static doublereal totm;
    extern /* Subroutine */ int dgefa_(doublereal *, integer *, integer *, 
	    integer *, integer *), dgedi_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *);
    static doublereal cmass[3], coord[360]	/* was [3][120] */;

    /* Fortran I/O blocks */
    static cilist io___291 = { 0, 6, 0, fmt_14, 0 };



/*  CALCULATES PROJECTED FORCE CONSTANT MATRIX (F). */
/*  THIS ROUTINE CAME ORIGINALLY FROM POLYRATE. IT IS USED BY PERMISSION */
/*  OF D. TRUHLAR. THE CURRENT VERSION IS LIFTED FROM GAMESS AND */
/*  ADAPTED BY F.JENSEN, ODENSE, DK */
/*  IF WE ARE AT A STATIONARY POINT (STPT=.T.), I.E. GNORM .LT. 10, */
/*  THEN THE ROTATIONAL AND TRANSLATIONAL MODES ARE PROJECTED OUT */
/*  AND THEIR FREQUENCIES BECOME IDENTICAL ZERO. IF NOT AT A STATIONARY */
/*  POINT THEN THE MASS-WEIGHTED GRADIENT IS ALSO PROJECTED OUT AND */
/*  THE CORRESPONDING FREQUENCY BECOME ZERO. */
/* ************************************************ */
/*   X : MASS-WEIGHTED COORDINATE */
/*   DX: NORMALIZED MASS-WEIGHTED GRADIENT VECTOR */
/*   F : MASS-WEIGHTED FORCE CONSTANT MATRIX */
/*   RM: INVERSION OF SQUARE ROOT OF MASS */
/*   P, COF: BUFFER */

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

/* TOTALLY ASYMMETRIC CARTESIAN TENSOR. */
    /* Parameter adjustments */
    --xparam;
    f -= 361;

    /* Function Body */

    natm = *nvar / 3;
    nc1 = *nvar;
    ij = 1;
    i__1 = natm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	coord[i__ * 3 - 3] = xparam[ij];
	coord[i__ * 3 - 2] = xparam[ij + 1];
	coord[i__ * 3 - 1] = xparam[ij + 2];
	ij += 3;
/* L2: */
    }
/*     CALCULATE 1/SQRT(MASS) */
    l = 0;
    i__1 = natm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tmp = 1. / sqrt(atmass_1.atmass[i__ - 1]);
	for (j = 1; j <= 3; ++j) {
	    ++l;
/* L3: */
	    rm[l - 1] = tmp;
	}
    }
/*     PREPARE GRADIENT */
    i__1 = nc1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L4: */
	dx[i__ - 1] = 0.;
    }
/*     FIND CMS AND CALCULATED MASS WEIGHTED COORDINATES */
    totm = 0.;
    cmass[0] = 0.;
    cmass[1] = 0.;
    cmass[2] = 0.;
    i__1 = natm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	totm += atmass_1.atmass[i__ - 1];
	for (j = 1; j <= 3; ++j) {
	    cmass[j - 1] += atmass_1.atmass[i__ - 1] * coord[j + i__ * 3 - 4];
/* L6: */
	}
    }
    for (j = 1; j <= 3; ++j) {
/* L7: */
	cmass[j - 1] /= totm;
    }
    l = 0;
    i__1 = natm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    tmp = sqrt(atmass_1.atmass[i__ - 1]);
	    ++l;
	    x[l - 1] = tmp * (coord[j + i__ * 3 - 4] - cmass[j - 1]);
/* L8: */
	}
    }
/*     WRITE(6,9020) */
/*     CALL prsq(f,nc1,nc1,maxpar,1) */
/* 9020 FORMAT(/1X,'ENTER THE SUBROUTINE <PRJFC>'// */
/*    *        1X,'UNPROJECTED FORCE CONSTANT MATRIX (HARTREE/BOHR**2)') */
/*     WRITE(6,*)' MASS-WEIGHTED COORDINATES AND CORRESPONDING GRADIENT' */
/*     DO 9 I=1,NC1 */
/* 9       WRITE(6,*)X(I),DX(I) */

/* 2. COMPUTE INERTIA TENSOR. */
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L10: */
	    rot[i__ + j * 3 - 4] = 0.;
	}
    }
    i__1 = natm;
    for (i__ = 1; i__ <= i__1; ++i__) {
	l = (i__ - 1) * 3 + 1;
/* Computing 2nd power */
	d__1 = x[l];
/* Computing 2nd power */
	d__2 = x[l + 1];
	rot[0] = rot[0] + d__1 * d__1 + d__2 * d__2;
	rot[3] -= x[l - 1] * x[l];
	rot[6] -= x[l - 1] * x[l + 1];
/* Computing 2nd power */
	d__1 = x[l - 1];
/* Computing 2nd power */
	d__2 = x[l + 1];
	rot[4] = rot[4] + d__1 * d__1 + d__2 * d__2;
	rot[7] -= x[l] * x[l + 1];
/* L20: */
/* Computing 2nd power */
	d__1 = x[l - 1];
/* Computing 2nd power */
	d__2 = x[l];
	rot[8] = rot[8] + d__1 * d__1 + d__2 * d__2;
    }
    rot[1] = rot[3];
    rot[2] = rot[6];
    rot[5] = rot[7];

/* HECK THE INERTIA TENSOR. */
    chk = rot[0] * rot[4] * rot[8];
    if (abs(chk) > 1e-8) {
	goto L21;
    }
/*     WRITE(6,23) */
/*  23 FORMAT(/1X,'MATRIX OF INERTIA MOMENT') */
/*     CALL PRSQ(ROT,3,3,3,3) */
    if (abs(rot[0]) > 1e-8) {
	goto L11;
    }
/* X=0 */
    if (abs(rot[4]) > 1e-8) {
	goto L12;
    }
/* X,Y=0 */
    if (abs(rot[8]) > 1e-8) {
	goto L13;
    }
    s_wsfe(&io___291);
    do_fio(&c__1, (char *)&rot[0], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rot[4], (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&rot[8], (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;

/* * 1. X,Y=0 BUT Z.NE.0 */
L13:
    rot[8] = 1. / rot[8];
    goto L22;
/* Y.NE.0 */
L12:
    if (abs(rot[8]) > 1e-8) {
	goto L15;
    }
/* * 2. X,Z=0 BUT Y.NE.0 */
    rot[4] = 1. / rot[4];
    goto L22;
/* X.NE.0 */
L11:
    if (abs(rot[4]) > 1e-8) {
	goto L16;
    }
    if (abs(rot[8]) > 1e-8) {
	goto L17;
    }
/* * 3. Y,Z=0 BUT X.NE.0 */
    rot[0] = 1. / rot[0];
    goto L22;
/* * 4. X,Y.NE.0 BUT Z=0 */
L16:
    *det = rot[0] * rot[4] - rot[3] * rot[1];
    trp = rot[0];
    rot[0] = rot[4] / *det;
    rot[4] = trp / *det;
    rot[3] = -rot[3] / *det;
    rot[1] = -rot[1] / *det;
    goto L22;
/* * 5. X,Z.NE.0 BUT Y=0 */
L17:
    *det = rot[0] * rot[8] - rot[6] * rot[2];
    trp = rot[0];
    rot[0] = rot[8] / *det;
    rot[8] = trp / *det;
    rot[6] = -rot[6] / *det;
    rot[2] = -rot[2] / *det;
    goto L22;
/* * 6. Y,Z.NE.0 BUT X=0 */
L15:
    *det = rot[8] * rot[4] - rot[5] * rot[7];
    trp = rot[8];
    rot[8] = rot[4] / *det;
    rot[4] = trp / *det;
    rot[5] = -rot[5] / *det;
    rot[7] = -rot[7] / *det;
    goto L22;
L21:

/* .DEBUG. */
/*      CALL PRSQ(TENS(1,1,1),3,3,3,3) */
/*      CALL PRSQ(TENS(1,1,2),3,3,3,3) */
/*      CALL PRSQ(TENS(1,1,3),3,3,3,3) */
/*      CALL PRSQ(ROT,3,3,3,3) */

/* 4. COMPUTE INVERSION MATRIX OF ROT. */
/*     CALL MXLNEQ(ROT,3,3,DET,JRNK,EPS,SCR,+0) */
/*     IF(JRNK.LT.3) STOP 1 */
    info = 0;
    dgefa_(rot, &c__3, &c__3, iscr, &info);
    if (info != 0) {
	s_stop("", (ftnlen)0);
    }
    *det = 0.;
    dgedi_(rot, &c__3, &c__3, iscr, detx, scr, &c__1);

L22:
/*     WRITE (6,702) */
/* 702 FORMAT(/1X,'INVERSE MATRIX OF MOMENT OF INERTIA.') */
/*     CALL PRSQ(ROT,3,3,3,3) */

/* 5. TOTAL MASS ---> TOTM. */

/* 6. COMPUTE P MATRIX */
/*    ---------------- */
    i__1 = natm;
    for (ip = 1; ip <= i__1; ++ip) {
	indx = (ip - 1) * 3;
	i__2 = ip;
	for (jp = 1; jp <= i__2; ++jp) {
	    jndx = (jp - 1) * 3;
	    for (ic = 1; ic <= 3; ++ic) {
		jend = 3;
		if (jp == ip) {
		    jend = ic;
		}
		i__3 = jend;
		for (jc = 1; jc <= i__3; ++jc) {
		    sum = 0.;
		    for (ia = 1; ia <= 3; ++ia) {
			for (ib = 1; ib <= 3; ++ib) {
			    if (tens[ia + (ib + ic * 3) * 3 - 13] == 0.) {
				goto L50;
			    }
			    for (ja = 1; ja <= 3; ++ja) {
				for (jb = 1; jb <= 3; ++jb) {
				    if (tens[ja + (jb + jc * 3) * 3 - 13] == 
					    0.) {
					goto L30;
				    }
				    sum += tens[ia + (ib + ic * 3) * 3 - 13] *
					     tens[ja + (jb + jc * 3) * 3 - 13]
					     * rot[ia + ja * 3 - 4] * x[indx 
					    + ib - 1] * x[jndx + jb - 1];
L30:
				    ;
				}
			    }
L50:
			    ;
			}
		    }
		    ii = indx + ic;
		    jj = jndx + jc;
		    p[ii + jj * 360 - 361] = sum + dx[ii - 1] * dx[jj - 1];
		    if (ic == jc) {
			p[ii + jj * 360 - 361] += 1. / (rm[ii - 1] * rm[jj - 
				1] * totm);
		    }
/* L70: */
		}
	    }
/* L100: */
	}
    }

/* 7. COMPUTE DELTA(I,J)-P(I,J) */
    i__2 = nc1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    p[i__ + j * 360 - 361] = -p[i__ + j * 360 - 361];
	    if (i__ == j) {
		p[i__ + j * 360 - 361] += 1.;
	    }
/* L110: */
	}
    }

/* 8. NEGLECT SMALLER VALUES THAN 10**-8. */
    i__1 = nc1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    if ((d__1 = p[i__ + j * 360 - 361], abs(d__1)) < 1e-8) {
		p[i__ + j * 360 - 361] = 0.;
	    }
	    p[j + i__ * 360 - 361] = p[i__ + j * 360 - 361];
/* L120: */
	}
    }

/* .DEBUG. */
/*     WRITE(6,703) */
/* 703 FORMAT(/1X,'PROJECTION MATRIX') */
/*     CALL PRSQ(P,NC1,NC1,NC1) */
/*     CALL PRSQ(P,NC1,NC1,maxpar,3) */

/* 10. POST AND PREMULTIPLY F BY P. */
/*     USE COF FOR SCRATCH. */
    i__2 = nc1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = nc1;
	for (j = 1; j <= i__1; ++j) {
	    sum = 0.;
	    i__3 = nc1;
	    for (k = 1; k <= i__3; ++k) {
/* L140: */
		sum += f[i__ + k * 360] * p[k + j * 360 - 361];
	    }
/* L150: */
	    cof[i__ + j * 360 - 361] = sum;
	}
    }

/* 11. COMPUTE P*F*P. */
    i__1 = nc1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = nc1;
	for (j = 1; j <= i__2; ++j) {
	    sum = 0.;
	    i__3 = nc1;
	    for (k = 1; k <= i__3; ++k) {
/* L190: */
		sum += p[i__ + k * 360 - 361] * cof[k + j * 360 - 361];
	    }
/* L200: */
	    f[i__ + j * 360] = sum;
	}
    }

/*     WRITE(6,9030) */
/*     CALL prsq(f,nc1,nc1,maxpar,1) */
/* 9030 FORMAT(/1X,'LEAVE THE SUBROUTINE <PRJFC>'// */
/*    *        1X,'PROJECTED FORCE CONSTANT MATRIX (HARTREE/BOHR**2)') */
    return 0;
} /* prjfc_ */

#undef detx
#undef det


/* Subroutine */ int prthes_(doublereal *eigval, integer *nvar)
{
    /* Format strings */
    static char fmt_1000[] = "(/,3x,8i9)";
    static char fmt_1010[] = "(1x,i3,8f9.1)";
    static char fmt_1020[] = "(/,4x,8f9.1,/)";
    static char fmt_1030[] = "(1x,i3,8f9.4)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_wsfe(void);

    /* Local variables */
    static integer i__, j, low, nup;

    /* Fortran I/O blocks */
    static cilist io___313 = { 0, 6, 0, 0, 0 };
    static cilist io___314 = { 0, 6, 0, 0, 0 };
    static cilist io___317 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___319 = { 0, 6, 0, fmt_1010, 0 };
    static cilist io___321 = { 0, 6, 0, 0, 0 };
    static cilist io___322 = { 0, 6, 0, 0, 0 };
    static cilist io___323 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___324 = { 0, 6, 0, fmt_1020, 0 };
    static cilist io___325 = { 0, 6, 0, fmt_1030, 0 };


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
    --eigval;

    /* Function Body */
    if (optef_1.iprnt >= 4) {
	s_wsle(&io___313);
	do_lio(&c__9, &c__1, " ", (ftnlen)1);
	e_wsle();
	s_wsle(&io___314);
	do_lio(&c__9, &c__1, "              HESSIAN MATRIX", (ftnlen)28);
	e_wsle();
	low = 1;
	nup = 8;
L540:
	nup = min(nup,*nvar);
	s_wsfe(&io___317);
	i__1 = nup;
	for (i__ = low; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_wsfe(&io___319);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    i__2 = nup;
	    for (j = low; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&nllcom_1.hess[i__ + j * 360 - 361], (
			ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
/* L550: */
	}
	nup += 8;
	low += 8;
	if (low <= *nvar) {
	    goto L540;
	}
    }
    s_wsle(&io___321);
    do_lio(&c__9, &c__1, " ", (ftnlen)1);
    e_wsle();
    s_wsle(&io___322);
    do_lio(&c__9, &c__1, "              HESSIAN EIGENVALUES AND -VECTORS", (
	    ftnlen)46);
    e_wsle();
    low = 1;
    nup = 8;
L560:
    nup = min(nup,*nvar);
    s_wsfe(&io___323);
    i__1 = nup;
    for (i__ = low; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    s_wsfe(&io___324);
    i__1 = nup;
    for (i__ = low; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&eigval[i__], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_wsfe(&io___325);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	i__2 = nup;
	for (j = low; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&optef_1.u[i__ + j * 360 - 361], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
/* L570: */
    }
    nup += 8;
    low += 8;
    if (low <= *nvar) {
	goto L560;
    }
    return 0;
} /* prthes_ */

/* Subroutine */ int updhes_(doublereal *svec, doublereal *tvec, integer *
	nvar, integer *iupd)
{
    /* Initialized data */

    static doublereal zero = 0.;

    /* Format strings */
    static char fmt_90[] = "(/,5x,\002HESSIAN IS NOT BEING UPDATED\002,/)";
    static char fmt_80[] = "(/,5x,\002HESSIAN IS BEING UPDATED USING THE POW"
	    "ELL UPDATE\002,/)";
    static char fmt_120[] = "(/,5x,\002HESSIAN IS BEING UPDATED USING THE BF"
	    "GS UPDATE\002,/)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, j;
    static doublereal dds;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal ddtd, temp;
    static logical first;

    /* Fortran I/O blocks */
    static cilist io___328 = { 0, 6, 0, fmt_90, 0 };
    static cilist io___329 = { 0, 6, 0, fmt_80, 0 };
    static cilist io___330 = { 0, 6, 0, fmt_120, 0 };


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
/* ONVEX      COMMON /NLLCOM/ HESS(MAXPAR,MAXPAR*3) */

    /* Parameter adjustments */
    --tvec;
    --svec;

    /* Function Body */

/*  UPDATING OF THE HESSIAN */
/*  DEPENDS ON CURRENT GRADIENTS, OLD GRADIENTS AND THE */
/*  CORRECTION VECTOR USED ON THE LAST CYCLE */
/*  SVEC & TVEC ARE FOR TEMPORARY STORAGE */

/*  2 UPDATING PROCEDURES ARE POSSIBLE */
/*  (I)   THE POWELL UPDATE */
/*        THIS PRESERVES THE SYMMETRIC CHARACTER OF THE HESSIAN */
/*        WHILST ALLOWING ITS EIGENVALUE STRUCTURE TO CHANGE. */
/*        IT IS THE DEFAULT UPDATE FOR A TRANSITION STATE SEARCH */
/*  (II)  THE BFGS UPDATE */
/*        THIS UPDATE HAS THE IMPORTANT CHARACTERISTIC OF RETAINING */
/*        POSITIVE DEFINITENESS (NOTE: THIS IS NOT RIGOROUSLY */
/*        GUARANTEED, BUT CAN BE CHECKED FOR BY THE PROGRAM). */
/*        IT IS THE DEFAULT UPDATE FOR A MINIMUM SEARCH */

/*     SWITCH : IUPD */
/*       IUPD = 0  :  SKIP UPDATE */
/*       IUPD = 1  :  POWELL */
/*       IUPD = 2  :  BFGS */

    if (! first) {
	first = TRUE_;
	if (optef_1.iprnt >= 2) {
	    if (*iupd == 0) {
		s_wsfe(&io___328);
		e_wsfe();
	    }
	    if (*iupd == 1) {
		s_wsfe(&io___329);
		e_wsfe();
	    }
	    if (*iupd == 2) {
		s_wsfe(&io___330);
		e_wsfe();
	    }
	}
    }
    if (*iupd == 0) {
	return 0;
    }
/* ONVEX      DO 10 I=1,NVAR */
/* ONVEX         TVEC(I)=ZERO */
/* ONVEX         DO 10 J=1,NVAR */
/* ONVEX            TVEC(I)=TVEC(I) + HESS(I,J)*D(J) */
/* ONVEX   10 CONTINUE */
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tvec[i__] = zero;
/* L5: */
    }
    i__1 = *nvar;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    tvec[i__] += nllcom_1.hess[i__ + j * 360 - 361] * optef_1.d__[j - 
		    1];
/* L10: */
	}
    }

    if (*iupd == 1) {

/*   (I) POWELL UPDATE */

	i__2 = *nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    tvec[i__] = gradnt_1.grad[i__ - 1] - optef_1.oldf[i__ - 1] - tvec[
		    i__];
	    svec[i__] = gradnt_1.grad[i__ - 1] - optef_1.oldf[i__ - 1];
/* L20: */
	}
	dds = optef_1.dd * optef_1.dd;
	ddtd = dot_(&tvec[1], optef_1.d__, nvar);
	ddtd /= dds;

/* ONVEX         DO 40 I=1,NVAR */
/* ONVEX            DO 30 J=1,I */
/* ONVEX               TEMP=TVEC(I)*D(J) + D(I)*TVEC(J) - D(I)*DDTD*D(J) */
/* ONVEX               HESS(I,J)=HESS(I,J)+TEMP/DDS */
/* ONVEX               HESS(J,I)=HESS(I,J) */
/* ONVEX   30       CONTINUE */
/* ONVEX   40    CONTINUE */
	i__2 = *nvar;
	for (i__ = 2; i__ <= i__2; ++i__) {
/* $DIR NO_RECURRENCE */
	    i__1 = i__ - 1;
	    for (j = 1; j <= i__1; ++j) {
		temp = tvec[i__] * optef_1.d__[j - 1] + optef_1.d__[i__ - 1] *
			 tvec[j] - optef_1.d__[i__ - 1] * ddtd * optef_1.d__[
			j - 1];
		nllcom_1.hess[i__ + j * 360 - 361] += temp / dds;
		nllcom_1.hess[j + i__ * 360 - 361] = nllcom_1.hess[i__ + j * 
			360 - 361];
/* L30: */
	    }
/* L40: */
	}
	i__2 = *nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    temp = optef_1.d__[i__ - 1] * (tvec[i__] * 2. - optef_1.d__[i__ - 
		    1] * ddtd);
	    nllcom_1.hess[i__ + i__ * 360 - 361] += temp / dds;
/* L45: */
	}

    }
    if (*iupd == 2) {

/*  (II) BFGS UPDATE */

	i__2 = *nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    svec[i__] = gradnt_1.grad[i__ - 1] - optef_1.oldf[i__ - 1];
/* L50: */
	}
	dds = dot_(&svec[1], optef_1.d__, nvar);

/*  IF DDS IS NEGATIVE, RETENTION OF POSITIVE DEFINITENESS IS NOT */
/*  GUARANTEED. PRINT A WARNING AND SKIP UPDATE THIS CYCLE. */

/* frj With the current level shift technique I think the Hessian should */
/* frj be allowed to aquire negative eigenvalues. Without updating the */
/* frj optimization has the potential of stalling */
/* frj     IF(DDS.LT.ZERO) THEN */
/* frj        WRITE(6,100) */
/* frj        WRITE(6,110) */
/* frj        RETURN */
/* frj     ENDIF */

	ddtd = dot_(optef_1.d__, &tvec[1], nvar);

/* ONVEX         DO 70 I=1,NVAR */
/* ONVEX            DO 60 J=1,I */
/* ONVEX               TEMP= (SVEC(I)*SVEC(J))/DDS - (TVEC(I)*TVEC(J))/DDTD */
/* ONVEX               HESS(I,J)=HESS(I,J)+TEMP */
/* ONVEX               HESS(J,I)=HESS(I,J) */
/* ONVEX   60       CONTINUE */
/* ONVEX   70    CONTINUE */
	i__2 = *nvar;
	for (i__ = 2; i__ <= i__2; ++i__) {
/* $DIR NO_RECURRENCE */
	    i__1 = i__ - 1;
	    for (j = 1; j <= i__1; ++j) {
		temp = svec[i__] * svec[j] / dds - tvec[i__] * tvec[j] / ddtd;
		nllcom_1.hess[i__ + j * 360 - 361] += temp;
		nllcom_1.hess[j + i__ * 360 - 361] = nllcom_1.hess[i__ + j * 
			360 - 361];
/* L60: */
	    }
/* L70: */
	}
	i__2 = *nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    temp = svec[i__] * svec[i__] / dds - tvec[i__] * tvec[i__] / ddtd;
	    nllcom_1.hess[i__ + i__ * 360 - 361] += temp;
/* L75: */
	}
    }

    return 0;

/* 100 FORMAT(5X,'WARNING! HEREDITARY POSITIVE DEFINITENESS ENDANGERED') */
/* 110 FORMAT(5X,'UPDATE SKIPPED THIS CYCLE') */
} /* updhes_ */

/* *MODULE BLAS1   *DECK DAXPY */
/* Subroutine */ int daxpy_(integer *n, doublereal *da, doublereal *dx, 
	integer *incx, doublereal *dy, integer *incy)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, m, ix, iy, mp1;


/*     CONSTANT TIMES A VECTOR PLUS A VECTOR. */
/*           DY(I) = DY(I) + DA * DX(I) */
/*     USES UNROLLED LOOPS FOR INCREMENTS EQUAL TO ONE. */
/*     JACK DONGARRA, LINPACK, 3/11/78. */

    /* Parameter adjustments */
    --dy;
    --dx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if (*da == 0.) {
	return 0;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*        CODE FOR UNEQUAL INCREMENTS OR EQUAL INCREMENTS */
/*          NOT EQUAL TO 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dy[iy] += *da * dx[ix];
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return 0;

/*        CODE FOR BOTH INCREMENTS EQUAL TO 1 */


/*        CLEAN-UP LOOP */

L20:
    m = *n % 4;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dy[i__] += *da * dx[i__];
/* L30: */
    }
    if (*n < 4) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i__ = mp1; i__ <= i__1; i__ += 4) {
	dy[i__] += *da * dx[i__];
	dy[i__ + 1] += *da * dx[i__ + 1];
	dy[i__ + 2] += *da * dx[i__ + 2];
	dy[i__ + 3] += *da * dx[i__ + 3];
/* L50: */
    }
    return 0;
} /* daxpy_ */

/* *********************************************************************** */
/*     below are math routines needed for prjfc. they are basicly just */
/*     matrix diagonalization routines and should at some point be replaced */
/*     with the diagonalization routine used in the rest of the program. */
/*     the routines below have been lifted from GAMESS */
/* *********************************************************************** */
/* Subroutine */ int dgedi_(doublereal *a, integer *lda, integer *n, integer *
	ipvt, doublereal *det, doublereal *work, integer *job)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal t;
    static integer kb, kp1, nm1;
    static doublereal ten;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), dswap_(integer *, doublereal *, integer *, doublereal 
	    *, integer *), daxpy_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *, integer *);


/*     DGEDI COMPUTES THE DETERMINANT AND INVERSE OF A MATRIX */
/*     USING THE FACTORS COMPUTED BY DGECO OR DGEFA. */

/*     ON ENTRY */

/*        A       DOUBLE PRECISION(LDA, N) */
/*                THE OUTPUT FROM DGECO OR DGEFA. */

/*        LDA     INTEGER */
/*                THE LEADING DIMENSION OF THE ARRAY  A . */

/*        N       INTEGER */
/*                THE ORDER OF THE MATRIX  A . */

/*        IPVT    INTEGER(N) */
/*                THE PIVOT VECTOR FROM DGECO OR DGEFA. */

/*        WORK    DOUBLE PRECISION(N) */
/*                WORK VECTOR.  CONTENTS DESTROYED. */

/*        JOB     INTEGER */
/*                = 11   BOTH DETERMINANT AND INVERSE. */
/*                = 01   INVERSE ONLY. */
/*                = 10   DETERMINANT ONLY. */

/*     ON RETURN */

/*        A       INVERSE OF ORIGINAL MATRIX IF REQUESTED. */
/*                OTHERWISE UNCHANGED. */

/*        DET     DOUBLE PRECISION(2) */
/*                DETERMINANT OF ORIGINAL MATRIX IF REQUESTED. */
/*                OTHERWISE NOT REFERENCED. */
/*                DETERMINANT = DET(1) * 10.0**DET(2) */
/*                WITH  1.0 .LE. ABS(DET(1)) .LT. 10.0 */
/*                OR  DET(1) .EQ. 0.0 . */

/*     ERROR CONDITION */

/*        A DIVISION BY ZERO WILL OCCUR IF THE INPUT FACTOR CONTAINS */
/*        A ZERO ON THE DIAGONAL AND THE INVERSE IS REQUESTED. */
/*        IT WILL NOT OCCUR IF THE SUBROUTINES ARE CALLED CORRECTLY */
/*        AND IF DGECO HAS SET RCOND .GT. 0.0 OR DGEFA HAS SET */
/*        INFO .EQ. 0 . */

/*     LINPACK. THIS VERSION DATED 08/14/78 . */
/*     CLEVE MOLER, UNIVERSITY OF NEW MEXICO, ARGONNE NATIONAL LAB. */

/*     SUBROUTINES AND FUNCTIONS */

/*     BLAS DAXPY,DSCAL,DSWAP */
/*     FORTRAN ABS,MOD */

/*     COMPUTE DETERMINANT */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --ipvt;
    --det;
    --work;

    /* Function Body */
    if (*job / 10 == 0) {
	goto L70;
    }
    det[1] = 1.;
    det[2] = 0.;
    ten = 10.;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ipvt[i__] != i__) {
	    det[1] = -det[1];
	}
	det[1] = a[i__ + i__ * a_dim1] * det[1];
/*        ...EXIT */
	if (det[1] == 0.) {
	    goto L60;
	}
L10:
	if (abs(det[1]) >= 1.) {
	    goto L20;
	}
	det[1] = ten * det[1];
	det[2] += -1.;
	goto L10;
L20:
L30:
	if (abs(det[1]) < ten) {
	    goto L40;
	}
	det[1] /= ten;
	det[2] += 1.;
	goto L30;
L40:
/* L50: */
	;
    }
L60:
L70:

/*     COMPUTE INVERSE(U) */

    if (*job % 10 == 0) {
	goto L150;
    }
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	a[k + k * a_dim1] = 1. / a[k + k * a_dim1];
	t = -a[k + k * a_dim1];
	i__2 = k - 1;
	dscal_(&i__2, &t, &a[k * a_dim1 + 1], &c__1);
	kp1 = k + 1;
	if (*n < kp1) {
	    goto L90;
	}
	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    t = a[k + j * a_dim1];
	    a[k + j * a_dim1] = 0.;
	    daxpy_(&k, &t, &a[k * a_dim1 + 1], &c__1, &a[j * a_dim1 + 1], &
		    c__1);
/* L80: */
	}
L90:
/* L100: */
	;
    }

/*        FORM INVERSE(U)*INVERSE(L) */

    nm1 = *n - 1;
    if (nm1 < 1) {
	goto L140;
    }
    i__1 = nm1;
    for (kb = 1; kb <= i__1; ++kb) {
	k = *n - kb;
	kp1 = k + 1;
	i__2 = *n;
	for (i__ = kp1; i__ <= i__2; ++i__) {
	    work[i__] = a[i__ + k * a_dim1];
	    a[i__ + k * a_dim1] = 0.;
/* L110: */
	}
	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    t = work[j];
	    daxpy_(n, &t, &a[j * a_dim1 + 1], &c__1, &a[k * a_dim1 + 1], &
		    c__1);
/* L120: */
	}
	l = ipvt[k];
	if (l != k) {
	    dswap_(n, &a[k * a_dim1 + 1], &c__1, &a[l * a_dim1 + 1], &c__1);
	}
/* L130: */
    }
L140:
L150:
    return 0;
} /* dgedi_ */

/* Subroutine */ int dgefa_(doublereal *a, integer *lda, integer *n, integer *
	ipvt, integer *info)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer j, k, l;
    static doublereal t;
    static integer nm1, kp1;
    extern /* Subroutine */ int dscal_(integer *, doublereal *, doublereal *, 
	    integer *), daxpy_(integer *, doublereal *, doublereal *, integer 
	    *, doublereal *, integer *);
    extern integer idamax_(integer *, doublereal *, integer *);


/*     DGEFA FACTORS A DOUBLE PRECISION MATRIX BY GAUSSIAN ELIMINATION. */

/*     DGEFA IS USUALLY CALLED BY DGECO, BUT IT CAN BE CALLED */
/*     DIRECTLY WITH A SAVING IN TIME IF  RCOND  IS NOT NEEDED. */
/*     (TIME FOR DGECO) = (1 + 9/N)*(TIME FOR DGEFA) . */

/*     ON ENTRY */

/*        A       DOUBLE PRECISION(LDA, N) */
/*                THE MATRIX TO BE FACTORED. */

/*        LDA     INTEGER */
/*                THE LEADING DIMENSION OF THE ARRAY  A . */

/*        N       INTEGER */
/*                THE ORDER OF THE MATRIX  A . */

/*     ON RETURN */

/*        A       AN UPPER TRIANGULAR MATRIX AND THE MULTIPLIERS */
/*                WHICH WERE USED TO OBTAIN IT. */
/*                THE FACTORIZATION CAN BE WRITTEN  A = L*U  WHERE */
/*                L  IS A PRODUCT OF PERMUTATION AND UNIT LOWER */
/*                TRIANGULAR MATRICES AND  U  IS UPPER TRIANGULAR. */

/*        IPVT    INTEGER(N) */
/*                AN INTEGER VECTOR OF PIVOT INDICES. */

/*        INFO    INTEGER */
/*                = 0  NORMAL VALUE. */
/*                = K  IF  U(K,K) .EQ. 0.0 .  THIS IS NOT AN ERROR */
/*                     CONDITION FOR THIS SUBROUTINE, BUT IT DOES */
/*                     INDICATE THAT DGESL OR DGEDI WILL DIVIDE BY ZERO */
/*                     IF CALLED.  USE  RCOND  IN DGECO FOR A RELIABLE */
/*                     INDICATION OF SINGULARITY. */

/*     LINPACK. THIS VERSION DATED 08/14/78 . */
/*     CLEVE MOLER, UNIVERSITY OF NEW MEXICO, ARGONNE NATIONAL LAB. */

/*     SUBROUTINES AND FUNCTIONS */

/*     BLAS DAXPY,DSCAL,IDAMAX */

/*     GAUSSIAN ELIMINATION WITH PARTIAL PIVOTING */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --ipvt;

    /* Function Body */
    *info = 0;
    nm1 = *n - 1;
    if (nm1 < 1) {
	goto L70;
    }
    i__1 = nm1;
    for (k = 1; k <= i__1; ++k) {
	kp1 = k + 1;

/*        FIND L = PIVOT INDEX */

	i__2 = *n - k + 1;
	l = idamax_(&i__2, &a[k + k * a_dim1], &c__1) + k - 1;
	ipvt[k] = l;

/*        ZERO PIVOT IMPLIES THIS COLUMN ALREADY TRIANGULARIZED */

	if (a[l + k * a_dim1] == 0.) {
	    goto L40;
	}

/*           INTERCHANGE IF NECESSARY */

	if (l == k) {
	    goto L10;
	}
	t = a[l + k * a_dim1];
	a[l + k * a_dim1] = a[k + k * a_dim1];
	a[k + k * a_dim1] = t;
L10:

/*           COMPUTE MULTIPLIERS */

	t = -1. / a[k + k * a_dim1];
	i__2 = *n - k;
	dscal_(&i__2, &t, &a[k + 1 + k * a_dim1], &c__1);

/*           ROW ELIMINATION WITH COLUMN INDEXING */

	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    t = a[l + j * a_dim1];
	    if (l == k) {
		goto L20;
	    }
	    a[l + j * a_dim1] = a[k + j * a_dim1];
	    a[k + j * a_dim1] = t;
L20:
	    i__3 = *n - k;
	    daxpy_(&i__3, &t, &a[k + 1 + k * a_dim1], &c__1, &a[k + 1 + j * 
		    a_dim1], &c__1);
/* L30: */
	}
	goto L50;
L40:
	*info = k;
L50:
/* L60: */
	;
    }
L70:
    ipvt[*n] = *n;
    if (a[*n + *n * a_dim1] == 0.) {
	*info = *n;
    }
    return 0;
} /* dgefa_ */

/* *MODULE BLAS1   *DECK DSCAL */
/* Subroutine */ int dscal_(integer *n, doublereal *da, doublereal *dx, 
	integer *incx)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, m, mp1, nincx;


/*     SCALES A VECTOR BY A CONSTANT. */
/*           DX(I) = DA * DX(I) */
/*     USES UNROLLED LOOPS FOR INCREMENT EQUAL TO ONE. */
/*     JACK DONGARRA, LINPACK, 3/11/78. */

    /* Parameter adjustments */
    --dx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if (*incx == 1) {
	goto L20;
    }

/*        CODE FOR INCREMENT NOT EQUAL TO 1 */

    nincx = *n * *incx;
    i__1 = nincx;
    i__2 = *incx;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	dx[i__] = *da * dx[i__];
/* L10: */
    }
    return 0;

/*        CODE FOR INCREMENT EQUAL TO 1 */


/*        CLEAN-UP LOOP */

L20:
    m = *n % 5;
    if (m == 0) {
	goto L40;
    }
    i__2 = m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	dx[i__] = *da * dx[i__];
/* L30: */
    }
    if (*n < 5) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__2 = *n;
    for (i__ = mp1; i__ <= i__2; i__ += 5) {
	dx[i__] = *da * dx[i__];
	dx[i__ + 1] = *da * dx[i__ + 1];
	dx[i__ + 2] = *da * dx[i__ + 2];
	dx[i__ + 3] = *da * dx[i__ + 3];
	dx[i__ + 4] = *da * dx[i__ + 4];
/* L50: */
    }
    return 0;
} /* dscal_ */

/* *MODULE BLAS1   *DECK DSWAP */
/* Subroutine */ int dswap_(integer *n, doublereal *dx, integer *incx, 
	doublereal *dy, integer *incy)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, m, ix, iy, mp1;
    static doublereal dtemp;


/*     INTERCHANGES TWO VECTORS. */
/*           DX(I) <==> DY(I) */
/*     USES UNROLLED LOOPS FOR INCREMENTS EQUAL ONE. */
/*     JACK DONGARRA, LINPACK, 3/11/78. */

    /* Parameter adjustments */
    --dy;
    --dx;

    /* Function Body */
    if (*n <= 0) {
	return 0;
    }
    if (*incx == 1 && *incy == 1) {
	goto L20;
    }

/*       CODE FOR UNEQUAL INCREMENTS OR EQUAL INCREMENTS NOT EQUAL */
/*         TO 1 */

    ix = 1;
    iy = 1;
    if (*incx < 0) {
	ix = (-(*n) + 1) * *incx + 1;
    }
    if (*incy < 0) {
	iy = (-(*n) + 1) * *incy + 1;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dtemp = dx[ix];
	dx[ix] = dy[iy];
	dy[iy] = dtemp;
	ix += *incx;
	iy += *incy;
/* L10: */
    }
    return 0;

/*       CODE FOR BOTH INCREMENTS EQUAL TO 1 */


/*       CLEAN-UP LOOP */

L20:
    m = *n % 3;
    if (m == 0) {
	goto L40;
    }
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dtemp = dx[i__];
	dx[i__] = dy[i__];
	dy[i__] = dtemp;
/* L30: */
    }
    if (*n < 3) {
	return 0;
    }
L40:
    mp1 = m + 1;
    i__1 = *n;
    for (i__ = mp1; i__ <= i__1; i__ += 3) {
	dtemp = dx[i__];
	dx[i__] = dy[i__];
	dy[i__] = dtemp;
	dtemp = dx[i__ + 1];
	dx[i__ + 1] = dy[i__ + 1];
	dy[i__ + 1] = dtemp;
	dtemp = dx[i__ + 2];
	dx[i__ + 2] = dy[i__ + 2];
	dy[i__ + 2] = dtemp;
/* L50: */
    }
    return 0;
} /* dswap_ */

