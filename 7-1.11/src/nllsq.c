/* nllsq.f -- translated by f2c (version 20020621).
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
    integer iflepo, iiter;
} mesage_;

#define mesage_1 mesage_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    integer ncount;
} nllsqi_;

#define nllsqi_1 nllsqi_

struct {
    integer nscf;
} numscf_;

#define numscf_1 numscf_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

struct {
    doublereal q[129600]	/* was [360][360] */, r__[259200]	/* 
	    was [360][720] */;
} nllcom_;

#define nllcom_1 nllcom_

struct {
    doublereal dddum[6], efslst[360], xlast[360];
    integer iiium[7];
} nllco2_;

#define nllco2_1 nllco2_

/* Table of constant values */

static integer c__1 = 1;
static integer c__0 = 0;
static logical c_true = TRUE_;
static integer c__2 = 2;

/* Subroutine */ int nllsq_(doublereal *x, integer *n)
{
    /* Initialized data */

    static integer ixso = 0;

    /* Format strings */
    static char fmt_600[] = "(\002  RESTART FILE WRITTEN,  TIME LEFT:\002,f9"
	    ".1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g14.7)";
    static char fmt_610[] = "(\002 CYCLE:\002,i5,\002 TIME:\002,f6.1,\002 TI"
	    "ME LEFT:\002,f9.1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g14.7)";
    static char fmt_760[] = "(\0020TEST ON X SATISFIED, NUMBER OF FUNCTION C"
	    "ALLS = \002,i5)";
    static char fmt_770[] = "(\0020TEST ON SSQ SATISFIED, NUMBER OF FUNCTION"
	    " CALLS = \002,i5)";
    static char fmt_680[] = "(\002 \002,5x,\002ATTEMPT TO GO DOWNHILL IS UNS"
	    "UCCESSFUL AFTER\002,i5,5x,\002ORTHOGONAL SEARCHES\002)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3, d__4;
    cllist cl__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void), f_clos(cllist *);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, m;
    static doublereal p[360], t, y[360];
    static integer i1, j1, ii, jj;
#define pn ((doublereal *)&nllco2_1 + 3)
    static doublereal yn;
    static integer np1, np2;
    static doublereal pn2;
#define alf ((doublereal *)&nllco2_1 + 1)
    static doublereal bet, efs[360];
    static logical log__;
    static doublereal cos__;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal eps, sin__;
    static integer nto;
    static doublereal tmp, prt;
#define ssq ((doublereal *)&nllco2_1 + 2)
    static doublereal tol2, escf;
    static integer jend;
#define icyc ((integer *)&nllco2_1 + 1453)
    static integer ierr;
    static doublereal temp;
#define irst ((integer *)&nllco2_1 + 1454)
#define jrst ((integer *)&nllco2_1 + 1455)
    static doublereal work, ttmp;
    static integer nrst, nsst;
    static doublereal tolx, time1, time2, tols1, tols2, tols5, tols6;
    extern doublereal reada_(char *, integer *, ftnlen);
    static integer ifrtl;
    static doublereal ytail, efsss;
    extern /* Subroutine */ int geout_(integer *);
    static doublereal const__, tlast;
    static logical middle;
    extern doublereal second_(void);
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), locmin_(integer *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, integer *, doublereal *);
    static doublereal tcycle;
    static logical resfil;
    extern /* Subroutine */ int parsav_(integer *, integer *, integer *);
    static doublereal pnlast;
    static logical minprt;
    static doublereal ssqlst;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 6, 0, "(/,A)", 0 };
    static cilist io___48 = { 0, 6, 0, "(' SYSTEM DOES NOT APPEAR TO BE OPTI"
	    "MIZABLE.',/     ,' THIS CAN HAPPEN IF (A) IT WAS OPTIMIZED TO BE"
	    "GIN WITH',/     ,' OR                 (B) IT IS NEITHER A GROUND"
	    " NOR A',        ' TRANSITION STATE')", 0 };
    static cilist io___61 = { 0, 6, 0, fmt_600, 0 };
    static cilist io___62 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___63 = { 0, 11, 0, fmt_610, 0 };
    static cilist io___64 = { 0, 6, 0, fmt_760, 0 };
    static cilist io___65 = { 0, 6, 0, fmt_770, 0 };
    static cilist io___66 = { 0, 6, 0, fmt_680, 0 };


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

/*  NLLSQ IS A NON-DERIVATIVE, NONLINEAR LEAST-SQUARES MINIMIZER. IT USES */
/*        BARTEL'S PROCEDURE TO MINIMIZE A FUNCTION WHICH IS A SUM OF */
/*        SQUARES. */

/*    ON INPUT N    = NUMBER OF UNKNOWNS */
/*             X    = PARAMETERS OF FUNCTION TO BE MINIMIZED. */

/*    ON EXIT  X    = OPTIMIZED PARAMETERS. */

/*    THE FUNCTION TO BE MINIMIZED IS "COMPFG". COMPFG MUST HAVE THE */
/*    CALLING SEQUENCE */
/*                  CALL COMPFG(XPARAM,.TRUE.,ESCF,.TRUE.,EFS,.TRUE.) */
/*                  SSQ=DOT(EFS,EFS,N) */
/*    WHERE   EFS  IS A VECTOR WHICH  COMPFG  FILLS WITH THE N INDIVIDUAL */
/*                 COMPONENTS OF THE ERROR FUNCTION AT THE POINT X */
/*            SSQ IS THE VALUE OF THE SUM OF THE  EFS  SQUARED. */
/*    IN THIS FORMULATION OF NLLSQ M AND N ARE THE SAME. */
/*    THE PRECISE DEFINITIONS OF THESE TWO QUANTITIES IS: */

/*     N = NUMBER OF PARAMETERS TO BE OPTIMIZED. */
/*     M = NUMBER OF REFERENCE FUNCTIONS. M MUST BE GREATER THEN, OR */
/*         EQUAL TO, N */
/* *********************************************************************** */
/*     Q = ORTHOGONAL MATRIX   (M BY M) */
/*     R = RIGHT-TRIANGULAR MATRIX   (M BY N) */
/*     MXCNT(1) = MAX ALLOW OVERALL FUN EVALS */
/*     MXCNT(2) = MAX ALLOW NO OF FNC EVALS PER LIN SEARCH */
/*     TOLS1 = RELATIVE TOLERANCE ON X OVERALL */
/*     TOLS2 = ABSOLUTE TOLERANCE ON X OVERALL */
/*     TOLS5 = RELATIVE TOLERANCE ON X FOR LINEAR SEARCHES */
/*     TOLS6 = ABSOLUTE TOLERANCE ON X FOR LINEAR SEARCHES */
/*     NRST = NUMBER OF CYCLES BETWEEN SIDESTEPS */
/*     ********** */
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /TIME  / TIME0 */
/* ***************************** at 1994-05-25 ***** */
    /* Parameter adjustments */
    --x;

    /* Function Body */
    middle = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0;
    log__ = i_indx(keywrd_1.keywrd, "NOLOG", (ftnlen)241, (ftnlen)5) == 0;
    mesage_1.iflepo = 10;
/* * */
    m = *n;
/* * */
    tol2 = .4;
    if (i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5);
	tol2 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	if (tol2 < .01 && i_indx(keywrd_1.keywrd, " LET", (ftnlen)241, (
		ftnlen)4) == 0) {
	    s_wsfe(&io___12);
	    do_fio(&c__1, "  GNORM HAS BEEN SET TOO LOW, RESET TO 0   .01", (
		    ftnlen)46);
	    e_wsfe();
	    tol2 = .01;
	}
    }
    last_1.last = 0;
    tols1 = 1e-12;
    tols2 = 1e-10;
    tols5 = 1e-6;
    tols6 = .001;
    nrst = 4;
    tlast = timdmp_1.tleft;
    minprt = TRUE_;
    resfil = FALSE_;
    timdmp_1.tleft = timdmp_1.tleft - second_() + timec_1.time0;
/*     ********** */
/*     SET UP COUNTERS AND SWITCHES */
/*     ********** */
    nto = *n / 6;
    ifrtl = 0;
    nsst = 0;
    if (ixso == 0) {
	ixso = *n;
    }
    np1 = *n + 1;
    np2 = *n + 2;
    *icyc = 0;
    *irst = 0;
    *jrst = 1;
    eps = tols5;
    t = tols6;
/*     ********** */
/*     GET STARTING-POINT FUNCTION VALUE */
/*     SET UP ESTIMATE OF INITIAL LINE STEP */
/*     ********** */
    if (middle) {
	parsav_(&c__0, n, &m);
	numscf_1.nscf = nllco2_1.iiium[0];
	cl__1.cerr = 0;
	cl__1.cunit = 13;
	cl__1.csta = 0;
	f_clos(&cl__1);
	nllsqi_1.ncount = nllco2_1.iiium[4];
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	    x[i__] = nllco2_1.xlast[i__ - 1];
	}
	time1 = second_();
	if (i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0) {
	    mesage_1.iflepo = 13;
	    last_1.last = 1;
	    return 0;
	}
	goto L60;
    }
    compfg_(&x[1], &c_true, &escf, &c_true, nllco2_1.efslst, &c_true);
    *ssq = dot_(nllco2_1.efslst, nllco2_1.efslst, n);
    nllsqi_1.ncount = 1;
/* L20: */
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    nllcom_1.r__[i__ + j * 360 - 361] = 0.;
	    if (i__ == j) {
		nllcom_1.r__[i__ + j * 360 - 361] = 1.;
	    }
/* L30: */
	}
	i__2 = m;
	for (j = i__; j <= i__2; ++j) {
	    nllcom_1.q[i__ + j * 360 - 361] = 0.;
	    nllcom_1.q[j + i__ * 360 - 361] = 0.;
	    if (i__ == j) {
		nllcom_1.q[i__ + i__ * 360 - 361] = 1.;
	    }
/* L40: */
	}
    }
    temp = 0.;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L50: */
/* Computing 2nd power */
	d__1 = x[i__];
	temp += d__1 * d__1;
    }
    *alf = (eps * sqrt(temp) + t) * 100.;
/*     ********** */
/*     MAIN LOOP */
/*     ********** */
    time1 = second_();
L60:
/*     ********** */
/*     UPDATE COUNTERS AND TEST FOR PRINTING THIS CYCLE */
/*     ********** */
    ++ifrtl;
    ++(*icyc);
    ++(*irst);
/*     ********** */
/*     SET  PRT,  THE LEVENBERG-MARQUARDT PARAMETER. */
/*     ********** */
    prt = sqrt(*ssq);
/*     ********** */
/*     IF A SIDESTEP IS TO BE TAKEN, GO TO 31 */
/*     ********** */
    if (*irst >= nrst) {
	goto L210;
    }
/*     ********** */
/*     SOLVE THE SYSTEM    Q*R*P = -EFSLST    IN THE LEAST-SQUARES SENSE */
/*     ********** */
    nsst = 0;
    i__2 = m;
    for (i__ = 1; i__ <= i__2; ++i__) {
	temp = 0.;
	i__1 = m;
	for (j = 1; j <= i__1; ++j) {
/* L70: */
	    temp -= nllcom_1.q[j + i__ * 360 - 361] * nllco2_1.efslst[j - 1];
	}
/* L80: */
	efs[i__ - 1] = temp;
    }
    i__2 = *n;
    for (j = 1; j <= i__2; ++j) {
	jj = np1 - j;
	i__1 = j;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ii = np2 - i__;
/* L90: */
	    nllcom_1.r__[ii + jj * 360 - 361] = nllcom_1.r__[i__ + j * 360 - 
		    361];
	}
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i1 = i__ + 1;
	y[i__ - 1] = prt;
	efsss = 0.;
	if (i__ >= *n) {
	    goto L110;
	}
	i__2 = *n;
	for (j = i1; j <= i__2; ++j) {
/* L100: */
	    y[j - 1] = 0.;
	}
L110:
	i__2 = *n;
	for (j = i__; j <= i__2; ++j) {
	    ii = np2 - j;
	    jj = np1 - j;
	    if ((d__1 = y[j - 1], abs(d__1)) < (d__2 = nllcom_1.r__[ii + jj * 
		    360 - 361], abs(d__2))) {
		goto L120;
	    }
/* Computing 2nd power */
	    d__1 = nllcom_1.r__[ii + jj * 360 - 361] / y[j - 1];
	    temp = y[j - 1] * sqrt(d__1 * d__1 + 1.);
	    goto L130;
L120:
/* Computing 2nd power */
	    d__1 = y[j - 1] / nllcom_1.r__[ii + jj * 360 - 361];
	    temp = nllcom_1.r__[ii + jj * 360 - 361] * sqrt(d__1 * d__1 + 1.);
L130:
	    sin__ = nllcom_1.r__[ii + jj * 360 - 361] / temp;
	    cos__ = y[j - 1] / temp;
	    nllcom_1.r__[ii + jj * 360 - 361] = temp;
	    temp = efs[j - 1];
	    efs[j - 1] = sin__ * temp + cos__ * efsss;
	    efsss = sin__ * efsss - cos__ * temp;
	    if (j >= *n) {
		goto L160;
	    }
	    j1 = j + 1;
	    i__3 = *n;
	    for (k = j1; k <= i__3; ++k) {
		jj = np1 - k;
		temp = nllcom_1.r__[ii + jj * 360 - 361];
		nllcom_1.r__[ii + jj * 360 - 361] = sin__ * temp + cos__ * y[
			k - 1];
/* L140: */
		y[k - 1] = sin__ * y[k - 1] - cos__ * temp;
	    }
/* L150: */
	}
L160:
	;
    }
    p[*n - 1] = efs[*n - 1] / nllcom_1.r__[1];
    i__ = *n;
L170:
    --i__;
    if (i__ <= 0) {
	goto L200;
    } else {
	goto L180;
    }
L180:
    temp = efs[i__ - 1];
    k = i__ + 1;
    ii = np2 - i__;
    i__1 = *n;
    for (j = k; j <= i__1; ++j) {
	jj = np1 - j;
/* L190: */
	temp -= nllcom_1.r__[ii + jj * 360 - 361] * p[j - 1];
    }
    jj = np1 - i__;
    p[i__ - 1] = temp / nllcom_1.r__[ii + jj * 360 - 361];
    goto L170;
L200:
    goto L230;
/*     ********** */
/*     SIDESTEP SECTION */
/*     ********** */
L210:
    ++(*jrst);
    ++nsst;
    if (nsst >= ixso) {
	goto L670;
    }
    if (*jrst > *n) {
	*jrst = 2;
    }
    *irst = 0;
/*     ********** */
/*     PRODUCTION OF A VECTOR ORTHOGONAL TO THE LAST P-VECTOR */
/*     ********** */
    work = *pn * (abs(p[0]) + *pn);
    temp = p[*jrst - 1];
    p[0] = temp * (p[0] + d_sign(pn, p));
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L220: */
	p[i__ - 1] = temp * p[i__ - 1];
    }
    p[*jrst - 1] -= work;
/*     ********** */
/*     COMPUTE NORM AND NORM-SQUARE OF THE P-VECTOR */
/*     ********** */
L230:
    pnlast = *pn;
    *pn = 0.;
    pn2 = 0.;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	*pn += (d__1 = p[i__ - 1], abs(d__1));
/* L240: */
/* Computing 2nd power */
	d__1 = p[i__ - 1];
	pn2 += d__1 * d__1;
    }
    if (*pn < 1e-20) {
	s_wsfe(&io___48);
	e_wsfe();
	geout_(&c__1);
	s_stop("", (ftnlen)0);
    }
    if (pn2 < 1e-20) {
	pn2 = 1e-20;
    }
    *pn = sqrt(pn2);
    if (*alf > 1e20) {
	*alf = 1e20;
    }
    if (*icyc > 1) {
	*alf = *alf * 1e-20 * pnlast / *pn;
	if (*alf > 1e10) {
	    *alf = 1e10;
	}
	*alf *= 1e20;
    }
    ttmp = *alf * *pn;
    if (ttmp < 1e-4) {
	*alf = .001 / *pn;
    }
/*     ********** */
/*     PRINTING SECTION */
/*     ********** */
/* #      WRITE(6,501)TLEFT,ICYC,SSQ */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	efs[i__ - 1] = x[i__];
/* L250: */
    }
/*     ********** */
/*     PERFORM LINE-MINIMIZATION FROM POINT X IN DIRECTION P OR -P */
/*     ********** */
    ssqlst = *ssq;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	efs[i__ - 1] = 0.;
/* L260: */
	nllco2_1.xlast[i__ - 1] = x[i__];
    }
    locmin_(&m, &x[1], n, p, ssq, alf, efs, &ierr, &escf);
    if (ssqlst < *ssq) {
	if (ierr == 0) {
	    *ssq = ssqlst;
	}
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L270: */
	    x[i__] = nllco2_1.xlast[i__ - 1];
	}
	*irst = nrst;
	*pn = pnlast;
	time2 = time1;
	time1 = second_();
	tcycle = time1 - time2;
	timdmp_1.tleft -= tcycle;
	if (timdmp_1.tleft > tcycle * 2) {
	    goto L60;
	}
	goto L630;
    }
/*     ********** */
/*     PRODUCE THE VECTOR   R*P */
/*     ********** */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	temp = 0.;
	i__2 = *n;
	for (j = i__; j <= i__2; ++j) {
/* L280: */
	    temp += nllcom_1.r__[i__ + j * 360 - 361] * p[j - 1];
	}
/* L290: */
	y[i__ - 1] = temp;
    }
/*     ********** */
/*     PRODUCE THE VECTOR ... */
/*                  Y  =    (EFS-EFSLST-ALF*Q*R*P)/(ALF*(NORMSQUARE(P)) */
/*     COMPUTE NORM OF THIS VECTOR AS WELL */
/*     ********** */
    work = *alf * pn2;
    yn = 0.;
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	temp = 0.;
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
/* L300: */
	    temp += nllcom_1.q[i__ + j * 360 - 361] * y[j - 1];
	}
	temp = efs[i__ - 1] - nllco2_1.efslst[i__ - 1] - *alf * temp;
	nllco2_1.efslst[i__ - 1] = efs[i__ - 1];
/* Computing 2nd power */
	d__1 = temp;
	yn += d__1 * d__1;
/* L310: */
	efs[i__ - 1] = temp / work;
    }
    yn = sqrt(yn) / work;
/*     ********** */
/*     THE BROYDEN UPDATE   NEW MATRIX = OLD MATRIX + Y*(P-TRANS) */
/*     HAS BEEN FORMED.  IT IS NOW NECESSARY TO UPDATE THE  QR DECOMP. */
/*     FIRST LET    Y = (Q-TRANS)*Y. */
/*     ********** */
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	temp = 0.;
	i__2 = m;
	for (j = 1; j <= i__2; ++j) {
/* L320: */
	    temp += nllcom_1.q[j + i__ * 360 - 361] * efs[j - 1];
	}
/* L330: */
	y[i__ - 1] = temp;
    }
/*     ********** */
/*     REDUCE THE VECTOR Y TO A MULTIPLE OF THE FIRST UNIT VECTOR USING */
/*     A HOUSEHOLDER TRANSFORMATION FOR COMPONENTS N+1 THROUGH M AND */
/*     ELEMENTARY ROTATIONS FOR THE FIRST N+1 COMPONENTS.  APPLY ALL */
/*     TRANSFORMATIONS TRANSPOSED ON THE RIGHT TO THE MATRIX Q, AND */
/*     APPLY THE ROTATIONS ON THE LEFT TO THE MATRIX R. */
/*     THIS GIVES    (Q*(V-TRANS))*((V*R) + (V*Y)*(P-TRANS)),    WHERE */
/*     V IS THE COMPOSITE OF THE TRANSFORMATIONS.  THE MATRIX */
/*     ((V*R) + (V*Y)*(P-TRANS))    IS UPPER HESSENBERG. */
/*     ********** */
    if (m <= np1) {
	goto L390;
    }

/* THE NEXT THREE LINES WERE INSERTED TO TRY TO GET ROUND OVERFLOW BUGS. */

    const__ = 1e-12;
    i__1 = m;
    for (i__ = np1; i__ <= i__1; ++i__) {
/* L340: */
/* Computing MAX */
	d__2 = (d__1 = y[np1 - 1], abs(d__1));
	const__ = max(d__2,const__);
    }
    ytail = 0.;
    i__1 = m;
    for (i__ = np1; i__ <= i__1; ++i__) {
/* L350: */
/* Computing 2nd power */
	d__1 = y[i__ - 1] / const__;
	ytail += d__1 * d__1;
    }
    ytail = sqrt(ytail) * const__;
    bet = 1e25 / ytail / (ytail + (d__1 = y[np1 - 1], abs(d__1)));
    d__2 = ytail + (d__1 = y[np1 - 1], abs(d__1));
    y[np1 - 1] = d_sign(&d__2, &y[np1 - 1]);
    i__1 = m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	tmp = 0.;
	i__2 = m;
	for (j = np1; j <= i__2; ++j) {
/* L360: */
	    tmp += nllcom_1.q[i__ + j * 360 - 361] * y[j - 1] * 1e-25;
	}
	tmp = bet * tmp;
	i__2 = m;
	for (j = np1; j <= i__2; ++j) {
/* L370: */
	    nllcom_1.q[i__ + j * 360 - 361] -= tmp * y[j - 1];
	}
/* L380: */
    }
    y[np1 - 1] = ytail;
    i__ = np1;
    goto L400;
L390:
    i__ = m;
L400:
L410:
    j = i__;
    --i__;
    if (i__ <= 0) {
	goto L480;
    } else {
	goto L420;
    }
L420:
    if (y[j - 1] != 0.) {
	goto L430;
    } else {
	goto L410;
    }
L430:
    if ((d__1 = y[i__ - 1], abs(d__1)) < (d__2 = y[j - 1], abs(d__2))) {
	goto L440;
    }
/* Computing 2nd power */
    d__2 = y[j - 1] / y[i__ - 1];
    temp = (d__1 = y[i__ - 1], abs(d__1)) * sqrt(d__2 * d__2 + 1.);
    goto L450;
L440:
/* Computing 2nd power */
    d__2 = y[i__ - 1] / y[j - 1];
    temp = (d__1 = y[j - 1], abs(d__1)) * sqrt(d__2 * d__2 + 1.);
L450:
    cos__ = y[i__ - 1] / temp;
    sin__ = y[j - 1] / temp;
    y[i__ - 1] = temp;
    i__1 = m;
    for (k = 1; k <= i__1; ++k) {
	temp = cos__ * nllcom_1.q[k + i__ * 360 - 361] + sin__ * nllcom_1.q[k 
		+ j * 360 - 361];
	work = -sin__ * nllcom_1.q[k + i__ * 360 - 361] + cos__ * nllcom_1.q[
		k + j * 360 - 361];
	nllcom_1.q[k + i__ * 360 - 361] = temp;
/* L460: */
	nllcom_1.q[k + j * 360 - 361] = work;
    }
    if (i__ > *n) {
	goto L410;
    }
    nllcom_1.r__[j + i__ * 360 - 361] = -sin__ * nllcom_1.r__[i__ + i__ * 360 
	    - 361];
    nllcom_1.r__[i__ + i__ * 360 - 361] = cos__ * nllcom_1.r__[i__ + i__ * 
	    360 - 361];
    if (j > *n) {
	goto L410;
    }
    i__1 = *n;
    for (k = j; k <= i__1; ++k) {
	temp = cos__ * nllcom_1.r__[i__ + k * 360 - 361] + sin__ * 
		nllcom_1.r__[j + k * 360 - 361];
	work = -sin__ * nllcom_1.r__[i__ + k * 360 - 361] + cos__ * 
		nllcom_1.r__[j + k * 360 - 361];
	nllcom_1.r__[i__ + k * 360 - 361] = temp;
/* L470: */
	nllcom_1.r__[j + k * 360 - 361] = work;
    }
    goto L410;
L480:
/*     ********** */
/*     REDUCE THE UPPER-HESSENBERG MATRIX TO UPPER-TRIANGULAR FORM */
/*     USING ELEMENTARY ROTATIONS.  APPLY THE SAME ROTATIONS, TRANSPOSED, */
/*     ON THE RIGHT TO THE MATRIX  Q. */
/*     ********** */
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
/* L490: */
	nllcom_1.r__[k * 360 - 360] += yn * p[k - 1];
    }
    jend = np1;
    if (m == *n) {
	jend = *n;
    }
    i__1 = jend;
    for (j = 2; j <= i__1; ++j) {
	i__ = j - 1;
	if (nllcom_1.r__[j + i__ * 360 - 361] != 0.) {
	    goto L500;
	} else {
	    goto L560;
	}
L500:
	if ((d__1 = nllcom_1.r__[i__ + i__ * 360 - 361], abs(d__1)) < (d__2 = 
		nllcom_1.r__[j + i__ * 360 - 361], abs(d__2))) {
	    goto L510;
	}
/* Computing 2nd power */
	d__2 = nllcom_1.r__[j + i__ * 360 - 361] / nllcom_1.r__[i__ + i__ * 
		360 - 361];
	temp = (d__1 = nllcom_1.r__[i__ + i__ * 360 - 361], abs(d__1)) * sqrt(
		d__2 * d__2 + 1.);
	goto L520;
L510:
/* Computing 2nd power */
	d__2 = nllcom_1.r__[i__ + i__ * 360 - 361] / nllcom_1.r__[j + i__ * 
		360 - 361];
	temp = (d__1 = nllcom_1.r__[j + i__ * 360 - 361], abs(d__1)) * sqrt(
		d__2 * d__2 + 1.);
L520:
	cos__ = nllcom_1.r__[i__ + i__ * 360 - 361] / temp;
	sin__ = nllcom_1.r__[j + i__ * 360 - 361] / temp;
	nllcom_1.r__[i__ + i__ * 360 - 361] = temp;
	if (j > *n) {
	    goto L540;
	}
	i__2 = *n;
	for (k = j; k <= i__2; ++k) {
	    temp = cos__ * nllcom_1.r__[i__ + k * 360 - 361] + sin__ * 
		    nllcom_1.r__[j + k * 360 - 361];
	    work = -sin__ * nllcom_1.r__[i__ + k * 360 - 361] + cos__ * 
		    nllcom_1.r__[j + k * 360 - 361];
	    nllcom_1.r__[i__ + k * 360 - 361] = temp;
/* L530: */
	    nllcom_1.r__[j + k * 360 - 361] = work;
	}
L540:
	i__2 = m;
	for (k = 1; k <= i__2; ++k) {
	    temp = cos__ * nllcom_1.q[k + i__ * 360 - 361] + sin__ * 
		    nllcom_1.q[k + j * 360 - 361];
	    work = -sin__ * nllcom_1.q[k + i__ * 360 - 361] + cos__ * 
		    nllcom_1.q[k + j * 360 - 361];
	    nllcom_1.q[k + i__ * 360 - 361] = temp;
/* L550: */
	    nllcom_1.q[k + j * 360 - 361] = work;
	}
L560:
	;
    }
/*     ********** */
/*     CHECK THE STOPPING CRITERIA */
/*     ********** */
    temp = 0.;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L570: */
/* Computing 2nd power */
	d__1 = x[i__];
	temp += d__1 * d__1;
    }
    tolx = tols1 * sqrt(temp) + tols2;
    if (sqrt(*alf * pn2) <= tolx) {
	goto L650;
    }
    if (*ssq >= *n * 2.) {
	goto L590;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* ***** */
/*     The stopping criterion is that no individual gradient be */
/*         greater than TOL2 */
/* ***** */
	if ((d__1 = nllco2_1.efslst[i__ - 1], abs(d__1)) >= tol2) {
	    goto L590;
	}
/* L580: */
    }
/* #      WRITE(6,730) SSQ */
    goto L660;
L590:
    time2 = time1;
    time1 = second_();
    tcycle = time1 - time2;
    timdmp_1.tleft -= tcycle;
    if (resfil) {
	s_wsfe(&io___61);
	do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal));
	d__1 = sqrt(*ssq);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	e_wsfe();
	resfil = FALSE_;
    } else {
	if (minprt) {
	    s_wsfe(&io___62);
	    do_fio(&c__1, (char *)&(*icyc), (ftnlen)sizeof(integer));
	    d__1 = min(tcycle,9999.99);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
/* Computing MIN */
	    d__4 = sqrt(*ssq);
	    d__3 = min(d__4,999999.999);
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (log__) {
	    s_wsfe(&io___63);
	    do_fio(&c__1, (char *)&(*icyc), (ftnlen)sizeof(integer));
	    d__1 = min(tcycle,9999.99);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
/* Computing MIN */
	    d__4 = sqrt(*ssq);
	    d__3 = min(d__4,999999.999);
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    if (tlast - timdmp_1.tleft > timdmp_1.tdump) {
	tlast = timdmp_1.tleft;
	resfil = TRUE_;
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L620: */
	    nllco2_1.xlast[i__ - 1] = x[i__];
	}
	nllco2_1.iiium[0] = numscf_1.nscf;
	parsav_(&c__2, n, &m);
    }
    if (timdmp_1.tleft > tcycle * 2) {
	goto L60;
    }
L630:
    nllco2_1.iiium[4] = nllsqi_1.ncount;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L640: */
	nllco2_1.xlast[i__ - 1] = x[i__];
    }
    nllco2_1.iiium[0] = numscf_1.nscf;
    parsav_(&c__1, n, &m);
    mesage_1.iflepo = -1;
    return 0;
L650:
    s_wsfe(&io___64);
    do_fio(&c__1, (char *)&nllsqi_1.ncount, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L870;
L660:
    s_wsfe(&io___65);
    do_fio(&c__1, (char *)&nllsqi_1.ncount, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L870;
L670:
    s_wsfe(&io___66);
    do_fio(&c__1, (char *)&ixso, (ftnlen)sizeof(integer));
    e_wsfe();
    goto L870;
/* #  730 FORMAT(1H ,'FINAL GRADIENT =',F15.7) */
/* L690: */
/* L700: */
/* L710: */
/* L720: */
/* L730: */
/* L740: */
/* L750: */
/* L780: */
/* L790: */
/* L800: */
/* L810: */
/* L820: */
/* L830: */
/* L840: */
/* L850: */
/* L860: */
L870:
    last_1.last = 1;
    return 0;
} /* nllsq_ */

#undef jrst
#undef irst
#undef icyc
#undef ssq
#undef alf
#undef pn


