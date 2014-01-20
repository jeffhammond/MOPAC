/* flepo.f -- translated by f2c (version 20020621).
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

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer nscf;
} numscf_;

#define numscf_1 numscf_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    doublereal cosine;
} gravec_;

#define gravec_1 gravec_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer iflepo, iscf;
} mesage_;

#define mesage_1 mesage_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    doublereal hesinv[130681];
    integer idumy[4];
} fmatrx_;

#define fmatrx_1 fmatrx_

struct {
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

struct {
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;
static logical c_true = TRUE_;
static logical c_false = FALSE_;

/* Subroutine */ int flepo_(doublereal *xparam, integer *nvar, doublereal *
	funct1)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* Format strings */
    static char fmt_100[] = "(\002 FUNCTION VALUE=\002,f13.7,\002  WILL NOT "
	    "BE REPLACED BY VALUE=\002,f13.7,/10x,\002CALCULATED BY RESTART P"
	    "ROCEDURE\002,/)";
    static char fmt_110[] = "(\002 FUNCTION VALUE=\002,f13.7,\002 IS BEING R"
	    "EPLACED BY VALUE=\002,f13.7,/10x,\002 FOUND IN RESTART PROCEDUR"
	    "E\002,/,6x,\002THE CORRESPONDING X VALUES AND GRADIENTS ARE ALSO"
	    " BEING REPLACED\002,/)";
    static char fmt_180[] = "(//,5x,\002SINCE COS=\002,f9.3,5x,\002THE PROGR"
	    "AM WILL GO TO RE\002,\002START SECTION\002,/)";
    static char fmt_200[] = "(\002 \002,\002AT THE BEGINNING OF CYCLE\002,"
	    "i5,\002  THE FUNCTION VA   LUE IS \002,f13.6/,\002  THE CURRENT "
	    "POINT IS ...\002)";
    static char fmt_210[] = "(\002  GRADIENT NORM = \002,f10.4/,\002  ANGLE "
	    "COSINE =\002,f10.4)";
    static char fmt_220[] = "(\002  THE CURRENT POINT IS ...\002)";
    static char fmt_230[] = "(\002 \002,3x,\002I\002,9x,i3,9(8x,i3))";
    static char fmt_240[] = "(\002 \002,1x,\002XPARAM(I)\002,1x,f9.4,2x,9(f9"
	    ".4,2x))";
    static char fmt_250[] = "(\002 \002,1x,\002GRAD  (I)\002,f10.4,1x,9(f10."
	    "4,1x))";
    static char fmt_260[] = "(\002 \002,1x,\002PVECT (I)\002,2x,f10.6,1x,9(f"
	    "10.6,1x))";
    static char fmt_280[] = "(\002 \002,\002 -ALPHA.P.G =\002,f18.6,/)";
    static char fmt_290[] = "(//,10x,\002HERBERTS TEST SATISFIED - GEOMETRY "
	    "OPTIMIZED\002)";
    static char fmt_340[] = "(\002 \002,//,20x,\002SINCE COS WAS JUST RESET,"
	    "THE SEARCH\002,\002 IS BEING ENDED\002)";
    static char fmt_350[] = "(\002 \002,20x,\002COS WILL BE RESET AND ANOTHE"
	    "R \002,\002ATTEMPT MADE\002)";
    static char fmt_360[] = "(/,\002           NUMBER OF COUNTS =\002,i6,"
	    "\002         COS    =\002,f11.4,/,\002  ABSOLUTE  CHANGE IN X   "
	    "  =\002,f13.6,\002  ALPHA  =\002,f11.4,/,\002  PREDICTED CHANGE "
	    "IN F     =  \002,g11.4,\002  ACTUAL =  \002,g11.4,/,\002  GRADIE"
	    "NT NORM             =  \002,g11.4,//)";
    static char fmt_370[] = "(\002 TEST ON X SATISFIED\002)";
    static char fmt_380[] = "(\002 HEAT OF FORMATION TEST SATISFIED\002)";
    static char fmt_390[] = "(\002 TEST ON GRADIENT SATISFIED\002)";
    static char fmt_420[] = "(20x,\002HOWEVER, A COMPONENT OF GRADIENT IS"
	    " \002,\002LARGER THAN\002,f6.2,/)";
    static char fmt_430[] = "(10x,\002 THERE HAVE BEEN\002,i2,\002 ATTEMPTS "
	    "TO REDUCE THE \002,\002 GRADIENT.\002,/10x,\002 DURING THESE ATT"
	    "EMPTS THE ENERGY DROPPED\002,\002 BY LESS THAN\002,f4.1,\002 KCA"
	    "L/MOLE\002,/10x,\002 FURTHER CALCULATION IS NOT JUSTIFIED AT THI"
	    "S TIME.\002,/10x,\002 TO CONTINUE, START AGAIN WITH THE WORD \"P"
	    "RECISE\"\002)";
    static char fmt_450[] = "(\002 PETERS TEST SATISFIED \002)";
    static char fmt_480[] = "(\002 RESTART FILE WRITTEN,   TIME LEFT:\002,f9"
	    ".1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g13.7)";
    static char fmt_490[] = "(\002 CYCLE:\002,i4,\002 TIME:\002,f7.2,\002 TI"
	    "ME LEFT:\002,f9.1,\002 GRAD.:\002,f10.3,\002 HEAT:\002,g13.7)";
    static char fmt_500[] = "(20x,\002THERE IS NOT ENOUGH TIME FOR ANOTHER C"
	    "YCLE\002,/,30x,\002NOW GOING TO FINAL\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    logical L__1;
    static integer equiv_3[9];
    static doublereal equiv_11[9];

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k;
    static doublereal gd[360];
    static integer ic;
    static doublereal gg[360];
    static integer i80, ii;
    static doublereal tf, xd[360], xn, sy, tx, tx1, tx2, ggd;
#define del (equiv_11 + 4)
    static doublereal ggi;
    static logical dfp, okf, log__;
#define cos__ (equiv_11 + 1)
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal rst, yhy;
    static integer igg1, nto6;
    static doublereal beta, einc, dell;
#define mdfp (equiv_3)
    static doublereal tdel;
#define jcyc (equiv_3)
    extern /* Subroutine */ int diis_(doublereal *, doublereal *, doublereal *
	    , doublereal *, doublereal *, doublereal *, doublereal *, integer 
	    *, logical *);
    static doublereal gvar[360];
#define xdfp (equiv_11)
#define drop (equiv_11 + 3)
    static doublereal dott, step;
    static logical frst;
    static integer iprt;
    static doublereal xvar[360];
    static integer nrst, iinc1, iinc2, itry1;
    extern doublereal reada_(char *, integer *, ftnlen);
#define alpha (equiv_11)
    static integer ihdim;
    static logical lgrad;
    static doublereal sfact, hdiis;
#define frepf (equiv_11 + 5)
    static logical geook, ldiis, thiel;
    static doublereal scrap, glast[360], gtemp[360], funct, pvect[360], 
	    const__;
#define cycmx (equiv_11 + 6)
    static doublereal xlast[360], xtemp[360];
    static logical print;
#define pnorm (equiv_11 + 2)
#define jnrst (equiv_3 + 1)
    static doublereal tlast, tolrg;
    extern /* Subroutine */ int scopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *), geout_(integer *);
    static doublereal xvari, smval, rootv, dropn, bsmvf, totim, funct2, 
	    cncadd;
    static logical saddle;
    static doublereal deltag, delhof, absmin;
    static logical resfil, diisok;
    static doublereal tolerf, tolerg;
    static integer irepet;
#define totime (equiv_11 + 7)
    extern doublereal second_(void);
#define ncount (equiv_3 + 2)
    static logical minprt;
    static doublereal tolerx;
    extern /* Subroutine */ int dfpsav_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
#define lnstop (equiv_3 + 3)
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *);
    static integer ireset;
    static doublereal gnormr;
    static logical restrt;
    static doublereal gdnorm, deltax, pmstep;
    extern /* Subroutine */ int supdot_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);
    static doublereal pnlast;
    extern /* Subroutine */ int linmin_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, logical *, integer *, 
	    doublereal *);
    static doublereal tcycle;

    /* Fortran I/O blocks */
    static cilist io___35 = { 0, 6, 0, "(/,A)", 0 };
    static cilist io___48 = { 0, 0, 0, "(//10X,'TOTAL TIME USED SO FAR:',   "
	    "              F13.2,' SECONDS')", 0 };
    static cilist io___56 = { 0, 0, 0, "(' GRADIENT CRITERION IN FLEPO =',F1"
	    "2.5)", 0 };
    static cilist io___65 = { 0, 0, 0, "(' GRADIENTS OF OLD GEOMETRY, GNORM="
	    "',F13.6)", 0 };
    static cilist io___66 = { 0, 0, 0, "(6F12.6)", 0 };
    static cilist io___68 = { 0, 0, 0, "(' GRADIENTS OF NEW GEOMETRY, GNORM="
	    "',F13.6)", 0 };
    static cilist io___69 = { 0, 0, 0, "(6F12.6)", 0 };
    static cilist io___70 = { 0, 0, 0, "(///20X,'CALCULATION ABANDONED AT TH"
	    "IS POINT!')", 0 };
    static cilist io___71 = { 0, 0, 0, "(//10X,' SMALL CHANGES IN INTERNAL C"
	    "OORDINATES ARE   ',/10X,' CAUSING A LARGE CHANGE IN THE DISTANCE"
	    " BETWEEN',/   10X,' CHEMICALLY-BOUND ATOMS. THE GEOMETRY OPTIMIZ"
	    "ATION',/     10X,' PROCEDURE WOULD LIKELY PRODUCE INCORRECT RESU"
	    "LTS')", 0 };
    static cilist io___77 = { 0, 0, 0, fmt_100, 0 };
    static cilist io___78 = { 0, 0, 0, fmt_110, 0 };
    static cilist io___90 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___91 = { 0, 0, 0, fmt_200, 0 };
    static cilist io___92 = { 0, 0, 0, fmt_210, 0 };
    static cilist io___93 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___96 = { 0, 6, 0, "(/)", 0 };
    static cilist io___98 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___99 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___100 = { 0, 6, 0, fmt_250, 0 };
    static cilist io___101 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___102 = { 0, 0, 0, fmt_280, 0 };
    static cilist io___103 = { 0, 0, 0, fmt_290, 0 };
    static cilist io___110 = { 0, 6, 0, "(' ONLY ONE VARIABLE, THEREFORE ENE"
	    "RGY A MINIMUM')", 0 };
    static cilist io___115 = { 0, 0, 0, "(/,20X, 'NO POINT LOWER IN ENERGY '"
	    ",      'THAN THE STARTING POINT ',/,20X,'COULD BE FOUND ',      "
	    "     'IN THE LINE MINIMIZATION')", 0 };
    static cilist io___116 = { 0, 0, 0, fmt_340, 0 };
    static cilist io___117 = { 0, 0, 0, fmt_350, 0 };
    static cilist io___121 = { 0, 6, 0, "(//,' HEAT OF FORMATION IS ESSENTIA"
	    "LLY STATIONARY')", 0 };
    static cilist io___122 = { 0, 6, 0, fmt_360, 0 };
    static cilist io___123 = { 0, 0, 0, fmt_370, 0 };
    static cilist io___124 = { 0, 0, 0, fmt_380, 0 };
    static cilist io___125 = { 0, 0, 0, fmt_390, 0 };
    static cilist io___126 = { 0, 0, 0, fmt_420, 0 };
    static cilist io___127 = { 0, 0, 0, fmt_430, 0 };
    static cilist io___128 = { 0, 0, 0, fmt_450, 0 };
    static cilist io___133 = { 0, 6, 0, fmt_480, 0 };
    static cilist io___134 = { 0, 6, 0, fmt_490, 0 };
    static cilist io___135 = { 0, 11, 0, fmt_490, 0 };
    static cilist io___136 = { 0, 0, 0, fmt_500, 0 };


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
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /TIME  / TIME0 */
/* ***************************** at 1994-05-25 ***** */


/*     * */
/*     THIS SUBROUTINE ATTEMPTS TO MINIMIZE A REAL-VALUED FUNCTION OF */
/*     THE N-COMPONENT REAL VECTOR XPARAM ACCORDING TO THE */
/*     BFGS FORMULA. RELEVANT REFERENCES ARE */

/*     BROYDEN, C.G., JOURNAL OF THE INSTITUTE FOR MATHEMATICS AND */
/*                     APPLICATIONS, VOL. 6 PP 222-231, 1970. */
/*     FLETCHER, R., COMPUTER JOURNAL, VOL. 13, PP 317-322, 1970. */

/*     GOLDFARB, D. MATHEMATICS OF COMPUTATION, VOL. 24, PP 23-26, 1970. */

/*     SHANNO, D.F. MATHEMATICS OF COMPUTATION, VOL. 24, PP 647-656 */
/*                    1970. */

/*   SEE ALSO SUMMARY IN */

/*    HEAD, J.D.; AND ZERNER, M.C., CHEMICAL PHYSICS LETTERS, VOL. 122, */
/*          264 (1985). */
/*    SHANNO, D.F., J. OF OPTIMIZATION THEORY AND APPLICATIONS */
/*          VOL.46, NO 1 PP 87-94 1985. */
/*     * */
/*     THE FUNCTION CAN ALSO BE MINIMIZED USING THE */
/*     DAVIDON-FLETCHER-POWELL ALGORITHM (COMPUTER JOURNAL, VOL. 6, */
/*     P. 163). */

/*     THE USER MUST SUPPLY THE SUBROUTINE */
/*     COMPFG(XPARAM,.TRUE.,FUNCT,.TRUE.,GRAD,LGRAD) */
/*     WHICH COMPUTES FUNCTION VALUES  FUNCT AT GIVEN VALUES FOR THE */
/*     VARIABLES XPARAM, AND THE GRADIENT GRAD IF LGRAD=.TRUE. */
/*     THE MINIMIZATION PROCEEDS BY A SEQUENCE OF ONE-DIMENSIONAL */
/*     MINIMIZATIONS.  THESE ARE CARRIED OUT WITHOUT GRADIENT COMPUTATION */
/*     BY THE SUBROUTINE LINMIN, WHICH SOLVES THE SUBPROBLEM OF */
/*     MINIMIZING THE FUNCTION FUNCT ALONG THE LINE XPARAM+ALPHA*PVECT, */
/*     WHERE XPARAM */
/*     IS THE VECTOR OF CURRENT VARIABLE VALUES,  ALPHA IS A SCALAR */
/*     VARIABLE, AND  PVECT  IS A SEARCH-DIRECTION VECTOR PROVIDED BY THE */
/*     BFGS OR DAVIDON-FLETCHER-POWELL ALGORITHM.  EACH ITERATION STEP CA */
/*     OUT BY FLEPO PROCEEDS BY LETTING LINMIN FIND A VALUE FOR ALPHA */
/*     WHICH MINIMIZES  FUNCT  ALONG  XPARAM+ALPHA*PVECT, BY */
/*     UPDATING THE VECTOR  XPARAM  BY THE AMOUNT ALPHA*PVECT, AND */
/*     FINALLY BY GENERATING A NEW VECTOR  PVECT.  UNDER */
/*     CERTAIN RESTRICTIONS (POWELL, J.INST.MATHS.APPLICS.(1971), */
/*     V.7,21-36)  A SEQUENCE OF FUNCT VALUES CONVERGING TO SOME */
/*     LOCAL MINIMUM VALUE AND A SEQUENCE OF */
/*     XPARAM VECTORS CONVERGING TO THE CORRESPONDING MINIMUM POINT */
/*     ARE PRODUCED. */
/*                          CONVERGENCE TESTS. */

/*     HERBERTS TEST: THE ESTIMATED DISTANCE FROM THE CURRENT POINT */
/*                    POINT TO THE MINIMUM IS LESS THAN TOLERA. */

/*                    "HERBERTS TEST SATISFIED - GEOMETRY OPTIMIZED" */

/*     GRADIENT TEST: THE GRADIENT NORM HAS BECOME LESS THAN TOLERG */
/*                    TIMES THE SQUARE ROOT OF THE NUMBER OF VARIABLES. */

/*                    "TEST ON GRADIENT SATISFIED". */

/*     XPARAM TEST:  THE RELATIVE CHANGE IN XPARAM, MEASURED BY ITS NORM, */
/*                   OVER ANY TWO SUCCESSIVE ITERATION STEPS DROPS BELOW */
/*                   TOLERX. */

/*                    "TEST ON XPARAM SATISFIED". */

/*     FUNCTION TEST: THE CALCULATED VALUE OF THE HEAT OF FORMATION */
/*                    BETWEEN ANY TWO CYCLES IS WITHIN TOLERF OF */
/*                    EACH OTHER. */

/*                    "HEAT OF FORMATION TEST SATISFIED" */

/*     FOR THE GRADIENT, FUNCTION, AND XPARAM TESTS A FURTHER CONDITION, */
/*     THAT NO INDIVIDUAL COMPONENT OF THE GRADIENT IS GREATER */
/*     THAN TOLERG, MUST BE SATISFIED, IN WHICH CASE THE */
/*     CALCULATION EXITS WITH THE MESSAGE */

/*                     "PETERS TEST SATISFIED" */

/*     WILL BE PRINTED, AND FUNCT AND XPARAM WILL CONTAIN THE LAST */
/*     FUNCTION VALUE CUM VARIABLE VALUES REACHED. */


/*     THE BROYDEN-FLETCHER-GOLDFARB-SHANNO AND DAVIDON-FLETCHER-POWELL */
/*     ALGORITHMS CHOOSE SEARCH DIRECTIONS */
/*     ON THE BASIS OF LOCAL PROPERTIES OF THE FUNCTION.  A MATRIX  H, */
/*     WHICH IN FLEPO IS PRESET WITH THE IDENTITY, IS MAINTAINED AND */
/*     UPDATED AT EACH ITERATION STEP.  THE MATRIX DESCRIBES A LOCAL */
/*     METRIC ON THE SURFACE OF FUNCTION VALUES ABOVE THE POINT XPARAM. */
/*     THE SEARCH-DIRECTION VECTOR  PVECT  IS SIMPLY A TRANSFORMATION */
/*     OF THE GRADIENT  GRAD  BY THE MATRIX H. */

    /* Parameter adjustments */
    --xparam;

    /* Function Body */

/*   START OF ONCE-ONLY SECTION */

    scftyp_1.emin = 0.;
    if (icalcn != numcal_1.numcal) {

/*   THE FOLLOWING CONSTANTS SHOULD BE SET BY THE USER. */

	rst = .05;
	iprt = 6;
	tdel = .06;
	nrst = 30;
	sfact = 1.5;
	dell = .01;
	einc = .3;
	igg1 = 3;
	*del = dell;

/*    THESE CONSTANTS SHOULD BE SET BY THE PROGRAM. */

	restrt = i_indx(keywrd_1.keywrd, "RESTAR", (ftnlen)241, (ftnlen)6) != 
		0;
	thiel = i_indx(keywrd_1.keywrd, "NOTHIE", (ftnlen)241, (ftnlen)6) == 
		0;
	geook = i_indx(keywrd_1.keywrd, "GEO-OK", (ftnlen)241, (ftnlen)6) != 
		0;
	log__ = i_indx(keywrd_1.keywrd, "NOLOG", (ftnlen)241, (ftnlen)5) == 0;
	ldiis = i_indx(keywrd_1.keywrd, "NODIIS", (ftnlen)241, (ftnlen)6) == 
		0;
	saddle = i_indx(keywrd_1.keywrd, "SADDLE", (ftnlen)241, (ftnlen)6) != 
		0;
	minprt = ! saddle;
	const__ = 1.;

/*      THE DAVIDON-FLETCHER-POWELL METHOD IS NOT RECOMMENDED */
/*      BUT CAN BE INVOKED BY USING THE KEYWORD 'DFP' */

	dfp = i_indx(keywrd_1.keywrd, "DFP", (ftnlen)241, (ftnlen)3) != 0;

/*  ORDER OF PRECISION:   'GNORM' TAKES PRECEDENCE OVER 'FORCE', WHICH */
/*                        TAKES PRECEDENCE OVER 'PRECISE'. */
	tolerg = 1.;
	if (i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0) {
	    tolerg = .2;
	}
	if (i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0) {
	    tolerg = .1;
	}

/*      READ IN THE GRADIENT-NORM LIMIT, IF SPECIFIED */

	if (i_indx(keywrd_1.keywrd, "GNORM=", (ftnlen)241, (ftnlen)6) != 0) {
	    rootv = 1.;
	    const__ = 1e-20;
	    i__1 = i_indx(keywrd_1.keywrd, "GNORM=", (ftnlen)241, (ftnlen)6);
	    tolerg = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    if (i_indx(keywrd_1.keywrd, " LET", (ftnlen)241, (ftnlen)4) == 0 
		    && tolerg < .01) {
		s_wsfe(&io___35);
		do_fio(&c__1, "  GNORM HAS BEEN SET TOO LOW, RESET TO 0.01", (
			ftnlen)43);
		e_wsfe();
		tolerg = .01;
	    }
	} else {
	    rootv = sqrt(*nvar + 1e-5);
	}
	tolerx = const__ * 1e-4;
	delhof = const__ * .001;
	tolerf = const__ * .002;
	tolrg = tolerg;

/*  MINOR BOOK-KEEPING */

	tlast = timdmp_1.tleft;
	tx2 = second_();
	timdmp_1.tleft = timdmp_1.tleft - tx2 + timec_1.time0;
	print = i_indx(keywrd_1.keywrd, "FLEPO", (ftnlen)241, (ftnlen)5) != 0;

/*   THE FOLLOWING CONSTANTS SHOULD BE SET TO SOME ARBITARY LARGE VALUE. */

	*drop = 1e15;
	*frepf = 1e15;

/*     AND FINALLY, THE FOLLOWING CONSTANTS ARE CALCULATED. */

	ihdim = *nvar * (*nvar + 1) / 2;
	cncadd = 1. / rootv;
	if (cncadd > .15) {
	    cncadd = .15;
	}
	icalcn = numcal_1.numcal;
	if (restrt) {
	    *jnrst = 1;
	    mdfp[8] = 0;
	    dfpsav_(totime, &xparam[1], gd, xlast, funct1, mdfp, xdfp);
	    i__ = (integer) (*totime / 1e6);
	    *totime -= i__ * 1e6;
	    timec_1.time0 -= *totime;
	    numscf_1.nscf = mdfp[4];
	    io___48.ciunit = iprt;
	    s_wsfe(&io___48);
	    do_fio(&c__1, (char *)&(*totime), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0) 
		    {
		last_1.last = 1;
		lgrad = i_indx(keywrd_1.keywrd, "GRAD", (ftnlen)241, (ftnlen)
			4) != 0;
		compfg_(&xparam[1], &c_true, funct1, &c_true, gradnt_1.grad, &
			lgrad);
		mesage_1.iflepo = 13;
		scftyp_1.emin = 0.;
		return 0;
	    }
	}

/*   END OF ONCE-ONLY SETUP */

    }

/*     FIRST, WE INITIALIZE THE VARIABLES. */

    diisok = FALSE_;
    ireset = 0;
    absmin = 1e6;
    frst = TRUE_;
    itry1 = 0;
    *jcyc = 0;
    *lnstop = 1;
    irepet = 1;
    scftyp_1.limscf = TRUE_;
    *alpha = 1.;
    *pnorm = 1.;
    *jnrst = 0;
    *cycmx = 0.;
    *cos__ = 0.;
    *totime = 0.;
    *ncount = 1;
    if (saddle) {

/*   WE DON'T NEED HIGH PRECISION DURING A SADDLE-POINT CALCULATION. */

	if (*nvar > 0) {
	    gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar)) - 
		    3.;
	}
	if (gradnt_1.gnorm > 10.) {
	    gradnt_1.gnorm = 10.;
	}
	if (gradnt_1.gnorm > 1.) {
	    tolerg = tolrg * gradnt_1.gnorm;
	}
	io___56.ciunit = iprt;
	s_wsfe(&io___56);
	do_fio(&c__1, (char *)&tolerg, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (*nvar == 1) {
	pvect[0] = .01;
	*alpha = 1.;
	goto L300;
    }
    *totime = 0.;

/* CALCULATE THE VALUE OF THE FUNCTION -> FUNCT1, AND GRADIENTS -> GRAD. */
/* NORMAL SET-UP OF FUNCT1 AND GRAD, DONE ONCE ONLY. */

    compfg_(&xparam[1], &c_true, funct1, &c_true, gradnt_1.grad, &c_true);
    scopy_(nvar, gradnt_1.grad, &c__1, gd, &c__1);
    if (*nvar != 0) {
	gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
	gnormr = gradnt_1.gnorm;
	if (*lnstop != 1 && *cos__ > rst && (*jnrst < nrst || ! dfp) && 
		restrt) {
	    scopy_(nvar, gd, &c__1, glast, &c__1);
	} else {
	    scopy_(nvar, gradnt_1.grad, &c__1, glast, &c__1);
	}
    }
    if (gradnt_1.gnorm < tolerg || *nvar == 0) {
	mesage_1.iflepo = 2;
	if (restrt) {
	    compfg_(&xparam[1], &c_true, funct1, &c_true, gradnt_1.grad, &
		    c_true);
	} else {
	    compfg_(&xparam[1], &c_true, funct1, &c_true, gradnt_1.grad, &
		    c_false);
	}
	scftyp_1.emin = 0.;
	return 0;
    }
    tx1 = second_();
    timdmp_1.tleft = timdmp_1.tleft - tx1 + tx2;
/*     * */
/*     START OF EACH ITERATION CYCLE ... */
/*     * */

    gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    if (gnormr < 1e-10) {
	gnormr = gradnt_1.gnorm;
    }
    goto L30;
L10:
    if (*cos__ < rst) {
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	    gd[i__ - 1] = .5;
	}
    }
L30:
    ++(*jcyc);
    ++(*jnrst);
    i80 = 0;
L40:
    if (i80 == 1 || *lnstop == 1 || *cos__ <= rst || *jnrst >= nrst && dfp) {

/*     * */
/*     RESTART SECTION */
/*     * */

	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {

/*  MAKE THE FIRST STEP A WEAK FUNCTION OF THE GRADIENT */

	    step = (d__1 = gradnt_1.grad[i__ - 1], abs(d__1)) * 2e-4;
/* Computing MAX */
	    d__1 = .01, d__2 = min(.04,step);
	    step = max(d__1,d__2);
/* #         XD(I)=XPARAM(I)-SIGN(STEP,GRAD(I)) */
	    xd[i__ - 1] = xparam[i__] - d_sign(del, &gradnt_1.grad[i__ - 1]);
/* L50: */
	}
/* #      WRITE(6,'(10F8.3)')(XD(I)-XPARAM(I),I=1,NVAR) */

/* THIS CALL OF COMPFG IS USED TO CALCULATE THE SECOND-ORDER MATRIX IN H */
/* IF THE NEW POINT HAPPENS TO IMPROVE THE RESULT, THEN IT IS KEPT. */
/* OTHERWISE IT IS SCRAPPED, BUT STILL THE SECOND-ORDER MATRIX IS O.K. */

/* #      WRITE(6,*)' RESET HESSIAN' */
	compfg_(xd, &c_true, &funct2, &c_true, gd, &c_true);
	if (! geook && sqrt(dot_(gd, gd, nvar)) / gradnt_1.gnorm > 10. && 
		gradnt_1.gnorm > 20. && *jcyc > 2) {

/*  THE GEOMETRY IS BADLY SPECIFIED IN THAT MINOR CHANGES IN INTERNAL */
/*  COORDINATES LEAD TO LARGE CHANGES IN CARTESIAN COORDINATES, AND THESE */
/*  LARGE CHANGES ARE BETWEEN PAIRS OF ATOMS THAT ARE CHEMICALLY BONDED */
/*  TOGETHER. */
	    io___65.ciunit = iprt;
	    s_wsfe(&io___65);
	    do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
	    io___66.ciunit = iprt;
	    s_wsfe(&io___66);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    gdnorm = sqrt(dot_(gd, gd, nvar));
	    io___68.ciunit = iprt;
	    s_wsfe(&io___68);
	    do_fio(&c__1, (char *)&gdnorm, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    io___69.ciunit = iprt;
	    s_wsfe(&io___69);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&gd[i__ - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_wsfe();
	    io___70.ciunit = iprt;
	    s_wsfe(&io___70);
	    e_wsfe();
	    io___71.ciunit = iprt;
	    s_wsfe(&io___71);
	    e_wsfe();
	    geout_(&c__1);
	    s_stop("", (ftnlen)0);
	}
	++(*ncount);
	i__1 = ihdim;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
	    fmatrx_1.hesinv[i__ - 1] = 0.;
	}
	ii = 0;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ii += i__;
	    deltag = gradnt_1.grad[i__ - 1] - gd[i__ - 1];
	    deltax = xparam[i__] - xd[i__ - 1];
	    if (abs(deltag) < 1e-12) {
		goto L70;
	    }
	    ggd = (d__1 = gradnt_1.grad[i__ - 1], abs(d__1));
	    if (funct2 < *funct1) {
		ggd = (d__1 = gd[i__ - 1], abs(d__1));
	    }
	    fmatrx_1.hesinv[ii - 1] = deltax / deltag;
	    if (fmatrx_1.hesinv[ii - 1] < 0. && ggd < 1e-12) {
		goto L70;
	    }
	    if (fmatrx_1.hesinv[ii - 1] < 0.) {
		fmatrx_1.hesinv[ii - 1] = tdel / ggd;
	    }
	    goto L80;
L70:
	    fmatrx_1.hesinv[ii - 1] = .01;
L80:
	    if (ggd < 1e-12) {
		ggd = 1e-12;
	    }
	    pmstep = (d__1 = .1 / ggd, abs(d__1));
	    if (fmatrx_1.hesinv[ii - 1] > pmstep) {
		fmatrx_1.hesinv[ii - 1] = pmstep;
	    }
/* L90: */
	}
	*jnrst = 0;
	if (*jcyc < 2) {
	    gravec_1.cosine = 1.;
	}
	if (funct2 >= *funct1) {
	    if (print) {
		io___77.ciunit = iprt;
		s_wsfe(&io___77);
		do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&funct2, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    gravec_1.cosine = 1.;
	} else {
	    if (print) {
		io___78.ciunit = iprt;
		s_wsfe(&io___78);
		do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&funct2, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    *funct1 = funct2;
	    scopy_(nvar, xd, &c__1, &xparam[1], &c__1);
	    scopy_(nvar, gd, &c__1, gradnt_1.grad, &c__1);
	    gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
	    if (gnormr < 1e-10) {
		gnormr = gradnt_1.gnorm;
	    }
	}
    } else {

/*     * */
/*     UPDATE VARIABLE-METRIC MATRIX */
/*     * */

	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xvar[i__ - 1] = xparam[i__] - xlast[i__ - 1];
/* L120: */
	    gvar[i__ - 1] = gradnt_1.grad[i__ - 1] - glast[i__ - 1];
	}
	supdot_(gg, fmatrx_1.hesinv, gvar, nvar, &c__1);
	yhy = dot_(gg, gvar, nvar);
	sy = dot_(xvar, gvar, nvar);
	k = 0;

/*    UPDATE ACCORDING TO DAVIDON-FLETCHER-POWELL */

	if (dfp) {
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		xvari = xvar[i__ - 1] / sy;
		ggi = gg[i__ - 1] / yhy;
		i__2 = i__;
		for (j = 1; j <= i__2; ++j) {
		    ++k;
/* L130: */
		    fmatrx_1.hesinv[k - 1] = fmatrx_1.hesinv[k - 1] + xvar[j 
			    - 1] * xvari - gg[j - 1] * ggi;
		}
	    }

/*     UPDATE USING THE BFGS FORMALISM */

	} else {
	    yhy = yhy / sy + 1.;
	    i__2 = *nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		xvari = xvar[i__ - 1] / sy;
		ggi = gg[i__ - 1] / sy;
		i__1 = i__;
		for (j = 1; j <= i__1; ++j) {
		    ++k;
/* L140: */
		    fmatrx_1.hesinv[k - 1] = fmatrx_1.hesinv[k - 1] - gg[j - 
			    1] * xvari - xvar[j - 1] * ggi + yhy * xvar[j - 1]
			     * xvari;
		}
	    }
	}
    }
/* #      DO 191 I=1,IHDIM */
/* #  191 HTEMP(I)=HESINV(I) */
/* #      CALL HQRII(HTEMP, NVAR, NVAR, XTEMP, VECTS) */
/* #      J=0 */
/* #      DO 193 I=1,NVAR */
/* #      IF(XTEMP(I).LT.0.0D0)THEN */
/* #      J=J+1 */
/* #      XTEMP(I)=0.00002D0 */
/* #      ENDIF */
/* #  193 CONTINUE */
/* #      IF(J.NE.0)THEN */
/* #      DO 194 I=1,IHDIM */
/* #  194 HTEMP(I)=HESINV(I) */
/* #      CALL HREFM(NVAR,VECTS,XTEMP,HESINV) */
/* #      WRITE(6,*)' ORIGINAL HESSIAN' */
/* #      CALL VECPRT(HTEMP,NVAR) */
/* #      WRITE(6,*)' REFORMED HESSIAN' */
/* #      CALL VECPRT(HESINV,NVAR) */
/* #      ENDIF */
/* #      WRITE(6,*)' EIGENVALUES OF HESSIAN MATRIX' */
/* #      WRITE(6,'(1X,5G12.6)')(6.951D-3/XTEMP(I),I=1,NVAR) */

/*     * */
/*     ESTABLISH NEW SEARCH DIRECTION */
/*     * */
    pnlast = *pnorm;
/* #      call vecprt(hesinv,nvar) */
    supdot_(pvect, fmatrx_1.hesinv, gradnt_1.grad, nvar, &c__1);
    *pnorm = sqrt(dot_(pvect, pvect, nvar));
    if (*pnorm > pnlast * 1.5) {

/*  TRIM PVECT BACK */

	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L150: */
	    pvect[i__ - 1] = pvect[i__ - 1] * 1.5 * pnlast / *pnorm;
	}
	*pnorm = pnlast * 1.5;
    }
    dott = -dot_(pvect, gradnt_1.grad, nvar);
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L160: */
	pvect[i__ - 1] = -pvect[i__ - 1];
    }
    *cos__ = -dott / (*pnorm * gradnt_1.gnorm);
    if (*jnrst == 0) {
	goto L190;
    }
    if (*cos__ <= cncadd && *drop > 1.) {
	goto L170;
    }
    if (*cos__ <= rst) {
	goto L170;
    }
    goto L190;
L170:
/* #      K=0 */
/* #      DO 222 I=1,NVAR */
/* #      DO 223 J=1,I-1 */
/* #      K=K+1 */
/* #  223 HESINV(K)=HESINV(K)*0.75D0 */
/* #      K=K+1 */
/* #  222 HESINV(K)=HESINV(K)+0.005D0 */
/* #      GOTO 241 */
    *pnorm = pnlast;
    if (print) {
	io___90.ciunit = iprt;
	s_wsfe(&io___90);
	do_fio(&c__1, (char *)&(*cos__), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    i80 = 1;
    goto L40;
L190:
    if (print) {
	io___91.ciunit = iprt;
	s_wsfe(&io___91);
	do_fio(&c__1, (char *)&(*jcyc), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (print) {
	io___92.ciunit = iprt;
	s_wsfe(&io___92);
	do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*cos__), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (print) {
	s_wsfe(&io___93);
	e_wsfe();
	nto6 = (*nvar - 1) / 6 + 1;
	iinc1 = -5;
	i__1 = nto6;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_wsfe(&io___96);
	    e_wsfe();
	    iinc1 += 6;
/* Computing MIN */
	    i__2 = iinc1 + 5;
	    iinc2 = min(i__2,*nvar);
	    s_wsfe(&io___98);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	    s_wsfe(&io___99);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&xparam[j], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___100);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&gradnt_1.grad[j - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___101);
	    i__2 = iinc2;
	    for (j = iinc1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&pvect[j - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
/* L270: */
	}
    }
    *lnstop = 0;
    *alpha = *alpha * pnlast / *pnorm;
    scopy_(nvar, gradnt_1.grad, &c__1, glast, &c__1);
    scopy_(nvar, &xparam[1], &c__1, xlast, &c__1);
    if (*jnrst == 0) {
	*alpha = 1.;
    }
    *drop = (d__1 = *alpha * dott, abs(d__1));
    if (print) {
	io___102.ciunit = iprt;
	s_wsfe(&io___102);
	do_fio(&c__1, (char *)&(*drop), (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (*jnrst != 0 && *drop < delhof) {

/*   HERBERT'S TEST: THE PREDICTED DROP IN ENERGY IS LESS THAN DELHOF */
/*   IF PASSED, CALL COMPFG TO GET A GOOD SET OF EIGENVECTORS, THEN EXIT */

	if (minprt) {
	    io___103.ciunit = iprt;
	    s_wsfe(&io___103);
	    e_wsfe();
	}

/*   FLEPO IS ENDING PROPERLY. THIS IS IMMEDIATELY BEFORE THE RETURN. */

	last_1.last = 1;
	compfg_(&xparam[1], &c_true, &funct, &c_true, gradnt_1.grad, &c_false)
		;
	mesage_1.iflepo = 3;
	timec_1.time0 -= *totime;
	scftyp_1.emin = 0.;
	return 0;
    }
    beta = *alpha;
    smval = *funct1;
    dropn = -(d__1 = *drop / *alpha, abs(d__1));

/*    UPDATE GEOMETRY USING THE G-DIIS PROCEDURE */

    if (diisok) {
	okf = TRUE_;
	ic = 1;
    } else {
	okf = FALSE_;
	ic = 2;
    }
L300:
    linmin_(&xparam[1], alpha, pvect, nvar, funct1, &okf, &ic, &dropn);
    if (*nvar == 1) {
	s_wsfe(&io___110);
	e_wsfe();
	last_1.last = 1;
	lgrad = i_indx(keywrd_1.keywrd, "GRAD", (ftnlen)241, (ftnlen)4) != 0;
	compfg_(&xparam[1], &c_true, &funct, &c_true, gradnt_1.grad, &lgrad);
	mesage_1.iflepo = 14;
	scftyp_1.emin = 0.;
	return 0;
    }
/*   WE WANT ACCURATE DERIVATIVES AT THIS POINT */

/*   LINMIN DOES NOT GENERATE ANY DERIVATIVES, THEREFORE COMPFG MUST BE */
/*   CALLED TO END THE LINE SEARCH */

/*  IF THE DERIVATIVES ARE TO BE CALCULATED USING FULL SCF'S, THEN CHECK */
/*  WHETHER TO DO FULL SCF'S (CRITERION FROM FLEPO: GRAD IS NULL). */

    if (ireset > 10 || gradnt_1.gnorm < 40. && gradnt_1.gnorm / gnormr < .33) 
	    {
	ireset = 0;
	gnormr = 0.;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L310: */
	    gradnt_1.grad[i__ - 1] = 0.;
	}
    }
    ++ireset;


/*     RESTORE TO STANDARD VALUE BEFORE COMPUTING THE GRADIENT */
    if (thiel) {
	L__1 = ic != 1;
	compfg_(&xparam[1], &L__1, &scrap, &c_true, gradnt_1.grad, &c_true);
    } else {
	compfg_(&xparam[1], &c_true, funct1, &c_true, gradnt_1.grad, &c_true);
    }
    if (ldiis) {

/*  UPDATE GEOMETRY AND GRADIENT AFTER MAKING A STEP USING LINMIN */

	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xtemp[i__ - 1] = xparam[i__];
/* L320: */
	    gtemp[i__ - 1] = gradnt_1.grad[i__ - 1];
	}
	diis_(xtemp, &xparam[1], gtemp, gradnt_1.grad, &hdiis, funct1, 
		fmatrx_1.hesinv, nvar, &frst);
	if (hdiis < *funct1 && sqrt(dot_(gtemp, gtemp, nvar)) < sqrt(dot_(
		gradnt_1.grad, gradnt_1.grad, nvar))) {
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		xparam[i__] = xtemp[i__ - 1];
/* L330: */
		gradnt_1.grad[i__ - 1] = gtemp[i__ - 1];
	    }
	    diisok = TRUE_;
	} else {
	    diisok = FALSE_;
	}
    }
    gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, nvar));
    if (gnormr < 1e-10) {
	gnormr = gradnt_1.gnorm;
    }
    ++(*ncount);
    if (! okf) {
	*lnstop = 1;
	if (minprt) {
	    io___115.ciunit = iprt;
	    s_wsfe(&io___115);
	    e_wsfe();
	}
	*funct1 = smval;
	*alpha = beta;
	scopy_(nvar, glast, &c__1, gradnt_1.grad, &c__1);
	scopy_(nvar, xlast, &c__1, &xparam[1], &c__1);
	if (*jnrst == 0) {
	    io___116.ciunit = iprt;
	    s_wsfe(&io___116);
	    e_wsfe();

/*           FLEPO IS ENDING BADLY. THIS IS IMMEDIATELY BEFORE THE RETURN */

	    last_1.last = 1;
	    compfg_(&xparam[1], &c_true, &funct, &c_true, gradnt_1.grad, &
		    c_true);
	    mesage_1.iflepo = 4;
	    timec_1.time0 -= *totime;
	    scftyp_1.emin = 0.;
	    return 0;
	}
	if (print) {
	    io___117.ciunit = iprt;
	    s_wsfe(&io___117);
	    e_wsfe();
	}
	*cos__ = 0.;
	goto L470;
    }
    xn = sqrt(dot_(&xparam[1], &xparam[1], nvar));
    tx = (d__1 = *alpha * *pnorm, abs(d__1));
    if (xn != 0.) {
	tx /= xn;
    }
    tf = (d__1 = smval - *funct1, abs(d__1));
    if (absmin - smval < 1e-7) {
	++itry1;
	if (itry1 > 10) {
	    s_wsfe(&io___121);
	    e_wsfe();
	    goto L460;
	}
    } else {
	itry1 = 0;
	absmin = smval;
    }
    if (print) {
	s_wsfe(&io___122);
	do_fio(&c__1, (char *)&(*ncount), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*cos__), (ftnlen)sizeof(doublereal));
	d__1 = tx * xn;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
	d__2 = -(*drop);
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	d__3 = -tf;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (tx <= tolerx) {
	if (minprt) {
	    io___123.ciunit = iprt;
	    s_wsfe(&io___123);
	    e_wsfe();
	}
	goto L400;
    }
    if (tf <= tolerf) {
/* #         WRITE(6,*)TF,TOLERF */
	if (minprt) {
	    io___124.ciunit = iprt;
	    s_wsfe(&io___124);
	    e_wsfe();
	}
	goto L400;
    }
    if (gradnt_1.gnorm <= tolerg * rootv) {
	if (minprt) {
	    io___125.ciunit = iprt;
	    s_wsfe(&io___125);
	    e_wsfe();
	}
	goto L400;
    }
    goto L470;
L400:
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if ((d__1 = gradnt_1.grad[i__ - 1], abs(d__1)) > tolerg) {
	    ++irepet;
	    if (irepet > 1) {
		goto L410;
	    }
	    *frepf = *funct1;
	    *cos__ = 0.;
L410:
	    if (minprt) {
		io___126.ciunit = iprt;
		s_wsfe(&io___126);
		do_fio(&c__1, (char *)&tolerg, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    if ((d__1 = *funct1 - *frepf, abs(d__1)) > einc) {
		irepet = 0;
	    }
	    if (irepet > igg1) {
		io___127.ciunit = iprt;
		s_wsfe(&io___127);
		do_fio(&c__1, (char *)&igg1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&einc, (ftnlen)sizeof(doublereal));
		e_wsfe();
		last_1.last = 1;
		compfg_(&xparam[1], &c_true, &funct, &c_true, gradnt_1.grad, &
			c_false);
		mesage_1.iflepo = 8;
		timec_1.time0 -= *totime;
		scftyp_1.emin = 0.;
		return 0;
	    } else {
		goto L470;
	    }
	}
/* L440: */
    }
    if (minprt) {
	io___128.ciunit = iprt;
	s_wsfe(&io___128);
	e_wsfe();
    }
L460:
    last_1.last = 1;
    compfg_(&xparam[1], &c_true, &funct, &c_true, gradnt_1.grad, &c_false);
    mesage_1.iflepo = 6;
    timec_1.time0 -= *totime;
    scftyp_1.emin = 0.;
    return 0;

/*   ALL TESTS HAVE FAILED, WE NEED TO DO ANOTHER CYCLE. */

L470:
    bsmvf = (d__1 = smval - *funct1, abs(d__1));
    if (bsmvf > 10.) {
	*cos__ = 0.;
    }
    *del = .002;
    if (bsmvf > 1.) {
	*del = dell / 2.;
    }
    if (bsmvf > 5.) {
	*del = dell;
    }
    tx2 = second_();
    tcycle = tx2 - tx1;
    tx1 = tx2;

/* END OF ITERATION LOOP, EVERYTHING IS STILL O.K. SO GO TO */
/* NEXT ITERATION, IF THERE IS ENOUGH TIME LEFT. */

    if (tcycle < 1e5) {
	*cycmx = max(*cycmx,tcycle);
    }
    timdmp_1.tleft -= tcycle;
    if (timdmp_1.tleft < 0.) {
	timdmp_1.tleft = -.1;
    }
    if (tcycle > 1e5) {
	tcycle = 0.;
    }
    if (tlast - timdmp_1.tleft > timdmp_1.tdump) {
	totim = *totime + second_() - timec_1.time0;
	tlast = timdmp_1.tleft;
	mdfp[8] = 2;
	resfil = TRUE_;
	mdfp[4] = numscf_1.nscf;
	dfpsav_(&totim, &xparam[1], gd, xlast, funct1, mdfp, xdfp);
    }
    if (resfil) {
	if (minprt) {
	    s_wsfe(&io___133);
	    d__1 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(gradnt_1.gnorm,999999.999);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	resfil = FALSE_;
    } else {
	if (minprt) {
	    s_wsfe(&io___134);
	    do_fio(&c__1, (char *)&(*jcyc), (ftnlen)sizeof(integer));
	    d__1 = min(tcycle,9999.99);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    d__3 = min(gradnt_1.gnorm,999999.999);
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (log__) {
	    s_wsfe(&io___135);
	    do_fio(&c__1, (char *)&(*jcyc), (ftnlen)sizeof(integer));
	    d__1 = min(tcycle,9999.99);
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = min(timdmp_1.tleft,9999999.9);
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    d__3 = min(gradnt_1.gnorm,999999.999);
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    if (timdmp_1.tleft > sfact * *cycmx) {
	goto L10;
    }
    io___136.ciunit = iprt;
    s_wsfe(&io___136);
    e_wsfe();
    totim = *totime + second_() - timec_1.time0;
    mdfp[8] = 1;
    mdfp[4] = numscf_1.nscf;
    dfpsav_(&totim, &xparam[1], gd, xlast, funct1, mdfp, xdfp);
    mesage_1.iflepo = -1;
    return 0;


} /* flepo_ */

#undef lnstop
#undef ncount
#undef totime
#undef jnrst
#undef pnorm
#undef cycmx
#undef frepf
#undef alpha
#undef drop
#undef xdfp
#undef jcyc
#undef mdfp
#undef cos__
#undef del


