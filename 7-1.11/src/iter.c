/* iter.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal f[45150], fb[45150];
} fokmat_;

#define fokmat_1 fokmat_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal c__[90000], eigs[300], cbeta[90000], eigb[300];
} vector_;

#define vector_1 vector_

struct {
    doublereal dumy[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    integer iflepo, iiter;
} mesage_;

#define mesage_1 mesage_

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    doublereal enuclr;
} enuclr_;

#define enuclr_1 enuclr_

struct {
    doublereal xi, xj, xk;
} citerm_;

#define citerm_1 citerm_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal emin;
    logical limscf;
} scftyp_;

#define scftyp_1 scftyp_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    doublereal pold[45150], pold2[45150], pbold[45150], pbold2[45150];
} work3_;

#define work3_1 work3_

struct {
    doublereal ar1[90300], ar2[90300], ar3[90300], ar4[90300], br1[90300], 
	    br2[90300], br3[90300], br4[316050];
} work1_;

#define work1_1 work1_

struct {
    doublereal selcon;
} preci_;

#define preci_1 preci_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal dummy[300], pdiag[300];
} molorb_;

#define molorb_1 molorb_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer nscf;
} numscf_;

#define numscf_1 numscf_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static doublereal c_b113 = 9999.;
static integer c__45150 = 45150;

/* Subroutine */ int iter_(doublereal *h__, doublereal *w, doublereal *wj, 
	doublereal *wk, doublereal *ee, logical *fulscf, logical *rand)
{
    /* Initialized data */

    static integer icalcn = 0;
    static logical debug = FALSE_;
    static logical prtfok = FALSE_;
    static logical prteig = FALSE_;
    static logical prtden = FALSE_;
    static logical prt1el = FALSE_;
    static char abprt[5*3] = "     " "ALPHA" " BETA";

    /* Format strings */
    static char fmt_210[] = "(\002   FOCK MATRIX ON ITERATION\002,i3)";
    static char fmt_230[] = "(//10x,\002\"\"\"\"\"\"\"\"\"\"\"\"\"UNABLE TO "
	    "ACHIEVE SELF-CONSISTENCE\002,/)";
    static char fmt_240[] = "(//,10x,\002DELTAE= \002,e12.4,5x,\002DELTAP="
	    " \002,e12.4,///)";
    static char fmt_330[] = "(10x,a,\002  EIGENVALUES ON ITERATION\002,i3,/1"
	    "0(6g13.6,/))";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), f_open(olist *), f_rew(
	    alist *), s_rsue(cilist *), do_uio(integer *, char *, ftnlen), 
	    e_rsue(void), s_wsfe(cilist *), do_fio(integer *, char *, ftnlen),
	     e_wsfe(void);
    double sqrt(doublereal);
    integer s_wsle(cilist *), e_wsle(void), do_lio(integer *, integer *, char 
	    *, ftnlen);
    double d_sign(doublereal *, doublereal *);
    integer f_clos(cllist *);

    /* Local variables */
    static integer i__, j, l;
    static doublereal t0, t1, w1, w2;
    static logical ci;
    static doublereal pl, tf1, eta, plb;
    static logical uhf;
    static doublereal ten, eps, sum;
    static logical scf1;
    extern /* Subroutine */ int diag_(doublereal *, doublereal *, integer *, 
	    doublereal *, integer *, integer *);
    static doublereal diff;
    extern doublereal meci_(doublereal *, doublereal *);
    static doublereal escf, eold;
    static integer jalp, ialp, jbet, ibet;
    extern /* Subroutine */ int cnvg_(doublereal *, doublereal *, doublereal *
	    , integer *, integer *, doublereal *), swap_(doublereal *, 
	    integer *, integer *, integer *, integer *);
    static logical frst;
    static integer irrr;
    static doublereal escf0[10];
    static integer na2el, na1el, nb2el, nb1el;
    extern /* Subroutine */ int fock2_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *), fock1_(doublereal *, 
	    doublereal *, doublereal *, doublereal *);
    static doublereal pold3[700];
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical halfe, makea, makeb;
    static integer modea, modeb, ifill;
    static logical force;
    static integer iemin;
    static logical newdg, ready, capps;
    static integer iemax, ihomo;
    static doublereal shift;
    static logical bfrst, times;
    static integer iredy;
    static doublereal trans;
    static integer niter;
    static doublereal titer, shfto, scorr;
    extern /* Subroutine */ int pulay_(doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    integer *, logical *, doublereal *), hqrii_(doublereal *, integer 
	    *, integer *, doublereal *, doublereal *);
    static logical prtpl;
    static doublereal pbold3[700], titer0;
    static logical camkin;
    extern doublereal helect_(integer *, doublereal *, doublereal *, 
	    doublereal *);
    static integer linear;
    static doublereal scfcrt, bshift;
    static logical oknewd, prtvec;
    static integer itrmax;
    static logical minprt;
    static doublereal pltest;
    static logical allcon;
    static doublereal random;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static logical incitr, timitr, okpuly;
    static integer ihomob;
    extern /* Subroutine */ int epseta_(doublereal *, doublereal *);
    static doublereal shfmax, plchek;
    extern /* Subroutine */ int vecprt_(doublereal *, integer *);
    extern doublereal second_(void);
    static doublereal shiftb, tenold, shftbo;
    extern doublereal capcor_(integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sellim;
    extern /* Subroutine */ int interp_(integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *), matout_(
	    doublereal *, doublereal *, integer *, integer *, integer *), 
	    densit_(doublereal *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___47 = { 0, 10, 0, 0, 0 };
    static cilist io___48 = { 0, 10, 0, 0, 0 };
    static cilist io___53 = { 0, 6, 0, "('  SCF CRITERION =',G14.4)", 0 };
    static cilist io___54 = { 0, 6, 0, "(//2X,' THERE IS A RISK OF INFINITE "
	    "LOOPING WITH',    ' THE SCFCRT LESS THAN 1.D-12')", 0 };
    static cilist io___55 = { 0, 6, 0, "('  SCF CRITERION =',G14.4)", 0 };
    static cilist io___61 = { 0, 6, 0, "('  SELCON, PLTEST',3G16.7)", 0 };
    static cilist io___62 = { 0, 6, 0, "(//10X,'ONE-ELECTRON MATRIX AT ENTRA"
	    "NCE TO ITER')", 0 };
    static cilist io___71 = { 0, 6, 0, 0, 0 };
    static cilist io___72 = { 0, 6, 0, "(A,F7.2)", 0 };
    static cilist io___74 = { 0, 6, 0, "(//,' ALL CONVERGERS ARE NOW FORCED "
	    "ON',/                     ' SHIFT=10, PULAY ON, CAMP-KING ON',/ "
	    "                          ' AND ITERATION COUNTER RESET',//)", 0 }
	    ;
    static cilist io___82 = { 0, 6, 0, "(A,F7.2)", 0 };
    static cilist io___85 = { 0, 6, 0, "(2(A,F7.2))", 0 };
    static cilist io___86 = { 0, 6, 0, fmt_210, 0 };
    static cilist io___87 = { 0, 6, 0, "(' \"\"\"\"\"\"\"\"\"\"\"\"\"\"\"UNA"
	    "BLE TO ACHIEVE SELF-CONSISTENCE, JOB CONTINUING')", 0 };
    static cilist io___88 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___89 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___94 = { 0, 6, 0, 0, 0 };
    static cilist io___95 = { 0, 6, 0, 0, 0 };
    static cilist io___96 = { 0, 6, 0, "(' ITERATION',I3,' PLS=',2E10.3,' EN"
	    "ERGY  ',   F14.7,' DELTAE',F13.7)", 0 };
    static cilist io___98 = { 0, 6, 0, "(2(A,F7.2))", 0 };
    static cilist io___102 = { 0, 6, 0, "(2(A,F7.2))", 0 };
    static cilist io___103 = { 0, 6, 0, "(//10X,A,                          "
	    "                   ' EIGENVECTORS AND EIGENVALUES ON ITERATION',"
	    "I3)", 0 };
    static cilist io___104 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___108 = { 0, 6, 0, "(//10X,A,' EIGENVECTORS AND EIGENVA"
	    "LUES ON ',    'ITERATION',I3)", 0 };
    static cilist io___109 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___110 = { 0, 6, 0, "(' DENSITY MATRIX ON ITERATION',I4)",
	     0 };
    static cilist io___112 = { 0, 6, 0, "(27X,'AFTER MECI, ENERGY  ',F14.7)", 
	    0 };
    static cilist io___113 = { 0, 6, 0, "(' NO. OF ITERATIONS =',I6)", 0 };


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
/* *********************************************************************** */

/*     ITER GENERATES A SCF FIELD AND RETURNS THE ENERGY IN "ENERGY" */

/* THE MAIN ARRAYS USED IN ITER ARE: */
/*            P      ONLY EVER CONTAINS THE TOTAL DENSITY MATRIX */
/*            PA     ONLY EVER CONTAINS THE ALPHA DENSITY MATRIX */
/*            PB     ONLY EVER CONTAINS THE BETA DENSITY MATRIX */
/*            C      ONLY EVER CONTAINS THE EIGENVECTORS */
/*            H      ONLY EVER CONTAINS THE ONE-ELECTRON MATRIX */
/*            F      STARTS OFF CONTAINING THE ONE-ELECTRON MATRIX, */
/*                   AND IS USED TO HOLD THE FOCK MATRIX */
/*            W      ONLY EVER CONTAINS THE TWO-ELECTRON MATRIX */

/* THE MAIN INTEGERS CONSTANTS IN ITER ARE: */

/*            LINEAR SIZE OF PACKED TRIANGLE = NORBS*(NORBS+1)/2 */

/* THE MAIN INTEGER VARIABLES ARE */
/*            NITER  NUMBER OF ITERATIONS EXECUTED */

/*  PRINCIPAL REFERENCES: */

/*   ON MNDO: "GROUND STATES OF MOLECULES. 38. THE MNDO METHOD. */
/*             APPROXIMATIONS AND PARAMETERS." */
/*             DEWAR, M.J.S., THIEL,W., J. AM. CHEM. SOC.,99,4899,(1977). */
/*   ON SHIFT: "THE DYNAMIC 'LEVEL SHIFT' METHOD FOR IMPROVING THE */
/*             CONVERGENCE OF THE SCF PROCEDURE", A. V. MITIN, J. COMP. */
/*             CHEM. 9, 107-110 (1988) */
/*   ON HALF-ELECTRON: "MINDO/3 COMPARISON OF THE GENERALIZED S.C.F. */
/*             COUPLING OPERATOR AND "HALF-ELECTRON" METHODS FOR */
/*             CALCULATING THE ENERGIES AND GEOMETRIES OF OPEN SHELL */
/*             SYSTEMS" */
/*             DEWAR, M.J.S., OLIVELLA, S., J. CHEM. SOC. FARA. II, */
/*             75,829,(1979). */
/*   ON PULAY'S CONVERGER: "CONVERGANCE ACCELERATION OF ITERATIVE */
/*             SEQUENCES. THE CASE OF SCF ITERATION", PULAY, P., */
/*             CHEM. PHYS. LETT, 73, 393, (1980). */
/*   ON CNVG:  IT ENCORPORATES THE IMPROVED ITERATION SCHEME (IIS) BY */
/*             PIOTR BADZIAG & FRITZ SOLMS. ACCEPTED FOR PUBLISHING */
/*             IN COMPUTERS & CHEMISTRY */
/*   ON PSEUDODIAGONALISATION: "FAST SEMIEMPIRICAL CALCULATIONS", */
/*             STEWART. J.J.P., CSASZAR, P., PULAY, P., J. COMP. CHEM., */
/*             3, 227, (1982) */

/* *********************************************************************** */
/* *********************************************************************** */
/*                                                                      * */
/*   PACK ALL THE ARRAYS USED BY PULAY INTO A COMMON BLOCK SO THAT THEY * */
/*   CAN BE USED BY THE C.I. DERIVATIVE, IF NEEDED                      * */
/*                                                                      * */
/* *********************************************************************** */
    /* Parameter adjustments */
    --wk;
    --wj;
    --w;
    --h__;

    /* Function Body */

/*  INITIALIZE */

    ifill = 0;
/* Computing MAX */
    i__1 = 1, i__2 = molkst_1.nclose + molkst_1.nalpha;
    ihomo = max(i__1,i__2);
/* Computing MAX */
    i__1 = 1, i__2 = molkst_1.nclose + molkst_1.nbeta;
    ihomob = max(i__1,i__2);
    eold = 100.;
    ready = FALSE_;
    if (icalcn != numcal_1.numcal) {
	epseta_(&eps, &eta);

/*  ULTIMATE SCF CRITERION: HEAT OF FORMATION CONVERGED WITHIN A FACTOR */
/*  OF 10 OF THE LIMITING PRECISION OF THE COMPUTER */

	eps = eps * 23.061 * 10.;
	irrr = 5;
	shift = 0.;
	icalcn = numcal_1.numcal;
	shfmax = 20.;
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;

/*    DEBUG KEY-WORDS WORKED OUT */

	debug = i_indx(keywrd_1.keywrd, "DEBUG", (ftnlen)241, (ftnlen)5) != 0;
	minprt = i_indx(keywrd_1.keywrd, "SADDLE", (ftnlen)241, (ftnlen)6) + 
		path_1.latom == 0 || debug;
	prteig = i_indx(keywrd_1.keywrd, "EIGS", (ftnlen)241, (ftnlen)4) != 0;
	prtpl = i_indx(keywrd_1.keywrd, " PL ", (ftnlen)241, (ftnlen)4) != 0;
	prt1el = i_indx(keywrd_1.keywrd, "1ELE", (ftnlen)241, (ftnlen)4) != 0 
		&& debug;
	prtden = i_indx(keywrd_1.keywrd, " DENS", (ftnlen)241, (ftnlen)5) != 
		0 && debug;
	prtfok = i_indx(keywrd_1.keywrd, "FOCK", (ftnlen)241, (ftnlen)4) != 0 
		&& debug;
	prtvec = i_indx(keywrd_1.keywrd, "VECT", (ftnlen)241, (ftnlen)4) != 0 
		&& debug;
	debug = i_indx(keywrd_1.keywrd, "ITER", (ftnlen)241, (ftnlen)4) != 0;

/* INITIALIZE SOME LOGICALS AND CONSTANTS */

	newdg = FALSE_;
	plchek = .005;
	pl = 1.;
	bshift = 0.;
	shift = 1.;

/* SCFCRT IS MACHINE-PRECISION DEPENDENT */

	scfcrt = 1e-4;
	itrmax = 200;
	na2el = molkst_1.nclose;
	na1el = molkst_1.nalpha + molkst_1.nopen;
	nb2el = 0;
	nb1el = molkst_1.nbeta + molkst_1.nopen;

/*  USE KEY-WORDS TO ASSIGN VARIOUS CONSTANTS */

	if (i_indx(keywrd_1.keywrd, "FILL", (ftnlen)241, (ftnlen)4) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "FILL", (ftnlen)241, (ftnlen)4);
	    ifill = (integer) (-reada_(keywrd_1.keywrd, &i__1, (ftnlen)241));
	}
	if (i_indx(keywrd_1.keywrd, "SHIFT", (ftnlen)241, (ftnlen)5) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "SHIFT", (ftnlen)241, (ftnlen)5);
	    bshift = -reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	}
	if (bshift != 0.) {
	    ten = bshift;
	}
	if (i_indx(keywrd_1.keywrd, "ITRY", (ftnlen)241, (ftnlen)4) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "ITRY", (ftnlen)241, (ftnlen)4);
	    itrmax = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	}
	camkin = i_indx(keywrd_1.keywrd, "KING", (ftnlen)241, (ftnlen)4) + 
		i_indx(keywrd_1.keywrd, "CAMP", (ftnlen)241, (ftnlen)4) != 0;
	ci = i_indx(keywrd_1.keywrd, "MICROS", (ftnlen)241, (ftnlen)6) + 
		i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)241, (ftnlen)4) != 0;
	okpuly = FALSE_;
	okpuly = i_indx(keywrd_1.keywrd, "PULAY", (ftnlen)241, (ftnlen)5) != 
		0;
	uhf = i_indx(keywrd_1.keywrd, "UHF", (ftnlen)241, (ftnlen)3) != 0;
	scf1 = i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0;
	oknewd = abs(bshift) < .001;
	if (camkin && abs(bshift) > 1e-5) {
	    bshift = 4.44;
	}
	times = i_indx(keywrd_1.keywrd, "TIMES", (ftnlen)241, (ftnlen)5) != 0;
	timitr = times && debug;
	force = i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0;
	allcon = okpuly || camkin;

/*   DO WE NEED A CAPPED ATOM CORRECTION? */

	j = 0;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	    if (molkst_1.nat[i__ - 1] == 102) {
		++j;
	    }
	}
	capps = j > 0;
	mesage_1.iiter = 1;
	trans = .1;
	if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) + 
		i_indx(keywrd_1.keywrd, "OLDENS", (ftnlen)241, (ftnlen)6) != 
		0) {
	    if (i_indx(keywrd_1.keywrd, "OLDENS", (ftnlen)241, (ftnlen)6) != 
		    0) {
		o__1.oerr = 0;
		o__1.ounit = 10;
		o__1.ofnmlen = 80;
		getnam_(ch__1, (ftnlen)80, "FOR010", (ftnlen)6);
		o__1.ofnm = ch__1;
		o__1.orl = 0;
		o__1.osta = "UNKNOWN";
		o__1.oacc = 0;
		o__1.ofm = "UNFORMATTED";
		o__1.oblnk = 0;
		f_open(&o__1);
	    }
	    al__1.aerr = 0;
	    al__1.aunit = 10;
	    f_rew(&al__1);
	    s_rsue(&io___47);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsue();
	    if (uhf) {
		s_rsue(&io___48);
		i__1 = linear;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_rsue();
		i__1 = linear;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    work3_1.pold[i__ - 1] = densty_1.pa[i__ - 1];
		    work3_1.pbold[i__ - 1] = densty_1.pb[i__ - 1];
/* L20: */
		    densty_1.p[i__ - 1] = densty_1.pa[i__ - 1] + densty_1.pb[
			    i__ - 1];
		}
	    } else {
		i__1 = linear;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    densty_1.pb[i__ - 1] = densty_1.pa[i__ - 1];
		    work3_1.pbold[i__ - 1] = densty_1.pa[i__ - 1];
		    work3_1.pold[i__ - 1] = densty_1.pa[i__ - 1];
/* L30: */
		    densty_1.p[i__ - 1] = densty_1.pa[i__ - 1] * 2.;
		}
	    }
	} else {
	    numscf_1.nscf = 0;
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		densty_1.p[i__ - 1] = 0.;
		densty_1.pa[i__ - 1] = 0.;
/* L40: */
		densty_1.pb[i__ - 1] = 0.;
	    }
	    w1 = na1el / (na1el + 1e-6 + nb1el);
	    w2 = 1. - w1;
	    if (w1 < 1e-6) {
		w1 = .5;
	    }
	    if (w2 < 1e-6) {
		w2 = .5;
	    }

/*  SLIGHTLY PERTURB THE DENSITY MATRIX IN CASE THE SYSTEM IS */
/*  TRAPPED IN A S**2 = 0 STATE. */

	    random = 1.;
	    if (uhf && na1el == nb1el) {
		random = 1.1;
	    }
	    i__1 = molkst_1.norbs;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		j = i__ * (i__ + 1) / 2;
		densty_1.p[j - 1] = molorb_1.pdiag[i__ - 1];
		densty_1.pa[j - 1] = densty_1.p[j - 1] * w1 * random;
		random = 1. / random;
/* L50: */
		densty_1.pb[j - 1] = densty_1.p[j - 1] * w2 * random;
	    }
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		work3_1.pbold[i__ - 1] = densty_1.pb[i__ - 1];
/* L60: */
		work3_1.pold[i__ - 1] = densty_1.pa[i__ - 1];
	    }
	}
	halfe = molkst_1.nopen != molkst_1.nclose && molkst_1.fract != 2. && 
		molkst_1.fract != 0.;

/*   DETERMINE THE SELF-CONSISTENCY CRITERION */

	if (i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0) {
	    scfcrt *= .01;
	}
	if (i_indx(keywrd_1.keywrd, "POLAR", (ftnlen)241, (ftnlen)5) + i_indx(
		keywrd_1.keywrd, "NLLSQ", (ftnlen)241, (ftnlen)5) + i_indx(
		keywrd_1.keywrd, "SIGMA", (ftnlen)241, (ftnlen)5) != 0) {
	    scfcrt *= .001;
	}
	if (force) {
	    scfcrt *= 1e-4;
	}
	if (molkst_1.nopen - molkst_1.nclose > 4) {
	    scfcrt *= .1;
	}
	scfcrt = max(scfcrt,1e-12);
	if (i_indx(keywrd_1.keywrd, "POLAR", (ftnlen)241, (ftnlen)5) != 0) {
	    scfcrt = 1e-11;
	}

/*  THE USER CAN STATE THE SCF CRITERION, IF DESIRED. */

	i__ = i_indx(keywrd_1.keywrd, "SCFCRT", (ftnlen)241, (ftnlen)6);
	if (i__ != 0) {
	    scfcrt = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
	    s_wsfe(&io___53);
	    do_fio(&c__1, (char *)&scfcrt, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (scfcrt < 1e-12) {
		s_wsfe(&io___54);
		e_wsfe();
	    }
	} else {
	    if (debug) {
		s_wsfe(&io___55);
		do_fio(&c__1, (char *)&scfcrt, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	}
	if (! scf1) {
	    last_1.last = 0;
	}

/*   END OF INITIALIZATION SECTION. */

    } else if (force && numscf_1.nscf > 0 && ! uhf) {

/*   RESET THE DENSITY MATRIX IF MECI HAS FORMED AN EXCITED STATE.  THIS */
/*   PREVENTS THE SCF GETTING TRAPPED ON AN EXCITED STATE, PARTICULARLY */
/*   IF THE PULAY CONVERGER IS USED. */

	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L70: */
	    densty_1.p[i__ - 1] = densty_1.pa[i__ - 1] * 2.;
	}
    }

/*   INITIALIZATION OPERATIONS DONE EVERY TIME ITER IS CALLED */

    makea = TRUE_;
    makeb = TRUE_;
    iemin = 0;
    iemax = 0;

/*  TURN OFF SHIFT IF NOT A FULL SCF. */

    if (! (*fulscf)) {
	shift = 0.;
    }
    if (newdg) {
	newdg = abs(bshift) < .001;
    }
    if (last_1.last == 1) {
	newdg = FALSE_;
    }

/*   SELF-CONSISTENCY CRITERIA: SELCON IS IN KCAL/MOL, PLTEST IS */
/*   A LESS IMPORTANT TEST TO MAKE SURE THAT THE SELCON TEST IS NOT */
/*   PASSED 'BY ACCIDENT' */
/*                              IF GNORM IS LARGE, MAKE SELCON BIGGER */

    preci_1.selcon = scfcrt;
    if (! force && ! halfe) {
	if (gradnt_1.gnorm > 5.) {
	    preci_1.selcon = scfcrt * gradnt_1.gnorm * .2;
	}
	if (gradnt_1.gnorm > 200.) {
	    preci_1.selcon = scfcrt * 40.;
	}
    }
    pltest = sqrt(preci_1.selcon) * .05;

/*  SOMETIMES HEAT GOES SCF BUT DENSITY IS STILL FLUCTUATING IN UHF */
/*  IN WHICH CASE PAY LESS ATTENTION TO DENSITY MATRIX */

    if (molkst_1.nalpha != molkst_1.nbeta && uhf) {
	pltest = .001;
    }
    if (debug) {
	s_wsfe(&io___61);
	do_fio(&c__1, (char *)&preci_1.selcon, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pltest, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (prt1el) {
	s_wsfe(&io___62);
	e_wsfe();
	vecprt_(&h__[1], &molkst_1.norbs);
    }
    iredy = 1;
L80:
    niter = 0;
    frst = TRUE_;
    if (camkin) {
	modea = 1;
	modeb = 1;
    } else {
	modea = 0;
	modeb = 0;
    }
    bfrst = TRUE_;
/* ********************************************************************* */
/*                                                                    * */
/*                                                                    * */
/*                START THE SCF LOOP HERE                             * */
/*                                                                    * */
/*                                                                    * */
/* ********************************************************************* */
    incitr = TRUE_;
L90:
    incitr = modea != 3 && modeb != 3;
    if (incitr) {
	++niter;
    }
    if (timitr) {
	titer = second_();
	s_wsle(&io___71);
	e_wsle();
	s_wsfe(&io___72);
	do_fio(&c__1, "     TIME FOR ITERATION:", (ftnlen)24);
	d__1 = titer - titer0;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	titer0 = titer;
    }
    if (niter > itrmax - 10 && ! allcon) {
/* *********************************************************************** */
/*                                                                      * */
/*                   SWITCH ON ALL CONVERGERS                           * */
/*                                                                      * */
/* *********************************************************************** */
	s_wsfe(&io___74);
	e_wsfe();
	allcon = TRUE_;
	bshift = 4.44;
	iredy = -4;
	eold = 100.;
	okpuly = TRUE_;
	newdg = FALSE_;
	camkin = ! halfe;
	goto L80;
    }
/* *********************************************************************** */
/*                                                                      * */
/*                        MAKE THE ALPHA FOCK MATRIX                    * */
/*                                                                      * */
/* *********************************************************************** */
    if (abs(shift) > 1e-10 && bshift != 0.) {
	l = 0;
	if (niter > 1) {
	    if (newdg && ! (halfe || camkin)) {

/*  SHIFT WILL APPLY TO THE VIRTUAL ENERGY LEVELS USED IN THE */
/*  PSEUDODIAGONALIIZATION. IF DIFF IS -VE, GOOD, THEN LOWER THE */
/*  HOMO-LUMO GAP BY 0.1EV, OTHERWISE INCREASE IT. */
		if (diff > 0.) {
		    shift = 1.;

/* IF THE PSEUDODIAGONALIZATION APPROXIMATION -- THAT THE WAVEFUNCTION */
/* IS ALMOST STABLE -- IS INVALID, TURN OFF NEWDG */
		    if (diff > 1.) {
			newdg = FALSE_;
		    }
		} else {
		    shift = -.1;
		}
	    } else {
		shift = ten + vector_1.eigs[ihomo] - vector_1.eigs[ihomo - 1] 
			+ shift;
	    }
	    if (diff > 0.) {
		if (shift > 4.) {
		    shfmax = 4.5;
		}
		if (shift > shfmax) {
/* Computing MAX */
		    d__1 = shfmax - .5;
		    shfmax = max(d__1,0.);
		}
	    }

/*   IF SYSTEM GOES UNSTABLE, LIMIT SHIFT TO THE RANGE -INFINITY - SHFMAX */
/*   BUT IF SYSTEM IS STABLE, LIMIT SHIFT TO THE RANGE -INFINITY - +20 */

/* Computing MAX */
	    d__1 = -20., d__2 = min(shfmax,shift);
	    shift = max(d__1,d__2);
	    if ((d__1 = shift - shfmax, abs(d__1)) < 1e-5) {
		shfmax += .01;
	    }

/*  THE CAMP-KING AND PULAY CONVERGES NEED A CONSTANT SHIFT. */
/*  IF THE SHIFT IS ALLOWED TO VARY, THESE CONVERGERS WILL NOT */
/*  WORK PROPERLY. */

	    if (okpuly || (d__1 = bshift - 4.44, abs(d__1)) < 1e-5) {
		shift = -8.;
		if (newdg) {
		    shift = 0.;
		}
	    }
	    if (uhf) {
		if (newdg && ! (halfe || camkin)) {
		    shiftb = ten - tenold;
		} else {
		    shiftb = ten + vector_1.eigs[ihomob] - vector_1.eigs[
			    ihomob - 1] + shiftb;
		}
		if (diff > 0.) {
		    shiftb = min(4.,shiftb);
		}
/* Computing MAX */
		d__1 = -20., d__2 = min(shfmax,shiftb);
		shiftb = max(d__1,d__2);
		if (okpuly || (d__1 = bshift - 4.44, abs(d__1)) < 1e-5) {
		    shiftb = -8.;
		    if (newdg) {
			shift = 0.;
		    }
		}
		i__1 = molkst_1.norbs;
		for (i__ = ihomob + 1; i__ <= i__1; ++i__) {
/* L100: */
		    vector_1.eigb[i__ - 1] += shiftb;
		}
	    } else {
	    }
	}
	tenold = ten;
	if (pl > plchek) {
	    shftbo = shiftb;
	    shfto = shift;
	} else {
	    shiftb = shftbo;
	    shift = shfto;
	}
	i__1 = molkst_1.norbs;
	for (i__ = ihomo + 1; i__ <= i__1; ++i__) {
/* L110: */
	    vector_1.eigs[i__ - 1] += shift;
	}
	i__1 = molkst_1.norbs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
		++l;
/* L120: */
		fokmat_1.f[l - 1] = h__[l] + shift * densty_1.pa[l - 1];
	    }
/* L130: */
	    fokmat_1.f[l - 1] -= shift;
	}
    } else if (i__ == 77 && last_1.last == 0 && niter < 2 && *fulscf) {

/*  SLIGHTLY PERTURB THE FOCK MATRIX IN CASE THE SYSTEM IS */
/*  TRAPPED IN A METASTABLE EXCITED ELECTRONIC STATE */

	random = .001;
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    random = -random;
/* L140: */
	    fokmat_1.f[i__ - 1] = h__[i__] + random;
	}
    } else {
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L150: */
	    fokmat_1.f[i__ - 1] = h__[i__];
	}
    }
L160:
    if (timitr) {
	t0 = second_();
	s_wsfe(&io___82);
	do_fio(&c__1, " LOAD FOCK MAT. INTEGRAL", (ftnlen)24);
	d__1 = t0 - titer0;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* #      CALL TIMER('BEFORE FOCK2') */
    fock2_(fokmat_1.f, densty_1.p, densty_1.pa, &w[1], &wj[1], &wk[1], &
	    molkst_1.numat, molkst_1.nat, molkst_1.nfirst, molkst_1.nmidle, 
	    molkst_1.nlast);
/* #      CALL TIMER('AFTER FOCK2') */
/* #      CALL TIMER('BEFORE FOCK1') */
    fock1_(fokmat_1.f, densty_1.p, densty_1.pa, densty_1.pb);
/* #      CALL TIMER('AFTER FOCK1') */
    if (timitr) {
	t0 = second_();
	tf1 = tf1 + t0 - t1;
	s_wsfe(&io___85);
	do_fio(&c__1, "  FOCK1:", (ftnlen)8);
	d__1 = t0 - t1;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, "INTEGRAL:", (ftnlen)9);
	d__2 = t0 - titer0;
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* *********************************************************************** */
/*                                                                      * */
/*                        MAKE THE BETA FOCK MATRIX                     * */
/*                                                                      * */
/* *********************************************************************** */
    if (uhf) {
	if (shiftb != 0.) {
	    l = 0;
	    i__1 = molkst_1.norbs;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i__2 = i__;
		for (j = 1; j <= i__2; ++j) {
		    ++l;
/* L170: */
		    fokmat_1.fb[l - 1] = h__[l] + shiftb * densty_1.pb[l - 1];
		}
/* L180: */
		fokmat_1.fb[l - 1] -= shiftb;
	    }
	} else if (*rand && last_1.last == 0 && niter < 2 && *fulscf) {
	    random = .001;
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		random = -random;
/* L190: */
		fokmat_1.fb[i__ - 1] = h__[i__] + random;
	    }
	} else {
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L200: */
		fokmat_1.fb[i__ - 1] = h__[i__];
	    }
	}
	fock2_(fokmat_1.fb, densty_1.p, densty_1.pb, &w[1], &wj[1], &wk[1], &
		molkst_1.numat, molkst_1.nat, molkst_1.nfirst, 
		molkst_1.nmidle, molkst_1.nlast);
	fock1_(fokmat_1.fb, densty_1.p, densty_1.pb, densty_1.pa);
    }
    if (! (*fulscf)) {
	goto L380;
    }
    if (prtfok) {
	s_wsfe(&io___86);
	do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	e_wsfe();
	vecprt_(fokmat_1.f, &molkst_1.norbs);
    }

/*   CODE THE FOLLOWING LINE IN PROPERLY SOMETIME */
/*   THIS OPERATION IS BELIEVED TO GIVE RISE TO A BETTER FOCK MATRIX */
/*   THAN THE CONVENTIONAL GUESS. */

    if (irrr == 0) {
	i__1 = molkst_1.norbs;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L220: */
	    fokmat_1.f[i__ * (i__ + 1) / 2 - 1] *= .5;
	}
	irrr = 2;
    }
/* *********************************************************************** */
/*                                                                      * */
/*                        CALCULATE THE ENERGY IN KCAL/MOLE             * */
/*                                                                      * */
/* *********************************************************************** */
    if (niter >= itrmax) {
	if (diff < .001 && pl < 1e-4 && ! force) {
	    s_wsfe(&io___87);
	    e_wsfe();
	    goto L380;
	}
	if (minprt) {
	    s_wsfe(&io___88);
	    e_wsfe();
	}
	s_wsfe(&io___89);
	do_fio(&c__1, (char *)&diff, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pl, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* *** here we failed to calculate a valid energy, but we don't want to close the whole program either. */
/* *** instead of calling STOP, continue like in the above case where GOTO 380 is called... */
	goto L380;
/*         IFLEPO=9 */
/*         IITER=2 */
/*         CALL WRITMO(TIME0,ESCF) */
/*         STOP */
    }
    *ee = helect_(&molkst_1.norbs, densty_1.pa, &h__[1], fokmat_1.f);
    if (uhf) {
	*ee += helect_(&molkst_1.norbs, densty_1.pb, &h__[1], fokmat_1.fb);
    } else {
	*ee *= 2.;
    }
    if (capps) {
	*ee += capcor_(molkst_1.nat, molkst_1.nfirst, molkst_1.nlast, &
		molkst_1.numat, densty_1.p, &h__[1]);
    }
    if (bshift != 0.) {
	scorr = shift * (molkst_1.nopen - molkst_1.nclose) * 23.061 * .25 * (
		molkst_1.fract * (2. - molkst_1.fract));
    }
    escf = (*ee + enuclr_1.enuclr) * 23.061 + atheat_1.atheat + scorr;
    if (incitr) {
	diff = escf - eold;
	if (diff > 0.) {
	    ten += -1.;
	} else {
	    ten = ten * .975 + .05;
	}

/* MAKE SURE SELF-CONSISTENCY TEST IS NOT MORE STRINGENT THAN THE */
/* COMPUTER CAN HANDLE */

/* Computing MAX */
/* Computing MAX */
	d__3 = abs(*ee);
	d__1 = preci_1.selcon, d__2 = eps * max(d__3,1.);
	sellim = max(d__1,d__2);

/* SCF TEST:  CHANGE IN HEAT OF FORMATION IN KCAL/MOL SHOULD BE */
/*            LESS THAN SELLIM.  THE OTHER TESTS ARE SAFETY MEASURES */

	if (! (niter > 4 && (pl == 0. || pl < pltest && abs(diff) < sellim) &&
		 ready)) {
	    goto L270;
	}
/* *********************************************************************** */
/*                                                                      * */
/*          SELF-CONSISTENCY TEST, EXIT MODE FROM ITERATIONS            * */
/*                                                                      * */
/* *********************************************************************** */
L250:
	if (abs(shift) < 1e-10) {
	    goto L380;
	}
	shift = 0.;
	shiftb = 0.;
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L260: */
	    fokmat_1.f[i__ - 1] = h__[i__];
	}
	makea = TRUE_;
	makeb = TRUE_;
	goto L160;
L270:
/* ********************************************************************** */
/* ********************************************************************** */
	if (scftyp_1.limscf && scftyp_1.emin != 0. && ! (ci || halfe)) {

/*  THE FOLLOWING TESTS ARE INTENDED TO ALLOW A FAST EXIT FROM ITER */
/*  IF THE RESULT IS 'GOOD ENOUGH' FOR THE CURRENT STEP IN THE GEOMETRY */
/*  OPTIMIZATION */

	    if (escf < scftyp_1.emin) {

/*  THE ENERGY IS LOWER THAN THE PREVIOUS MINIMUM.  NOW CHECK THAT */
/*  IT IS CONSISTENTLY LOWER. */

		iemax = 0;
/* Computing MIN */
		i__1 = 5, i__2 = iemin + 1;
		iemin = min(i__1,i__2);
		i__1 = iemin;
		for (i__ = 2; i__ <= i__1; ++i__) {
/* L280: */
		    escf0[i__ - 2] = escf0[i__ - 1];
		}
		escf0[iemin - 1] = escf;

/*  IS THE DIFFERENCE IN ENERGY BETWEEN TWO ITERATIONS LESS THAN 5% */
/*  OF THE ENERGY GAIN FOR THIS GEOMETRY RELATIVE TO THE PREVIOUS */
/*  MINIMUM. */

		if (iemin > 3) {
		    i__1 = iemin;
		    for (i__ = 2; i__ <= i__1; ++i__) {
			if ((d__1 = escf0[i__ - 1] - escf0[i__ - 2], abs(d__1)
				) > (scftyp_1.emin - escf) * .05) {
			    goto L320;
			}
/* L290: */
		    }

/* IS GOOD ENOUGH -- RAPID EXIT */

		    if (debug) {
			s_wsle(&io___94);
			do_lio(&c__9, &c__1, " RAPID EXIT BECAUSE ENERGY IS "
				"CONSISTENTLY LOWER", (ftnlen)48);
			e_wsle();
		    }
		    goto L250;
		}
	    } else {

/*  THE ENERGY HAS RISEN ABOVE THAT OF THE PREVIOUS MINIMUM. */
/*  WE NEED TO CHECK WHETHER THIS IS A FLUKE OR IS THIS REALLY */
/*  A BAD GEOMETRY. */

		iemin = 0;
/* Computing MIN */
		i__1 = 5, i__2 = iemax + 1;
		iemax = min(i__1,i__2);
		i__1 = iemax;
		for (i__ = 2; i__ <= i__1; ++i__) {
/* L300: */
		    escf0[i__ - 2] = escf0[i__ - 1];
		}
		escf0[iemax - 1] = escf;

/*  IS THE DIFFERENCE IN ENERGY BETWEEN TWO ITERATIONS LESS THAN 5% */
/*  OF THE ENERGY LOST FOR THIS GEOMETRY RELATIVE TO THE PREVIOUS */
/*  MINIMUM. */

		if (iemax > 3) {
		    i__1 = iemax;
		    for (i__ = 2; i__ <= i__1; ++i__) {
			if ((d__1 = escf0[i__ - 1] - escf0[i__ - 2], abs(d__1)
				) > (escf - scftyp_1.emin) * .05) {
			    goto L320;
			}
/* L310: */
		    }

/* IS GOOD ENOUGH -- RAPID EXIT */

		    if (debug) {
			s_wsle(&io___95);
			do_lio(&c__9, &c__1, " RAPID EXIT BECAUSE ENERGY IS "
				"CONSISTENTLY HIGHER", (ftnlen)49);
			e_wsle();
		    }
		    goto L250;
		}
	    }
	}
L320:
	ready = iredy > 0 && (abs(diff) < sellim * 10. || pl == 0.);
	++iredy;
    }
    if (prtpl || debug && niter > itrmax - 20) {
	if (abs(escf) > 99999.) {
	    escf = d_sign(&c_b113, &escf);
	}
	if (abs(diff) > 9999.) {
	    diff = 0.;
	}
	if (incitr) {
	    s_wsfe(&io___96);
	    do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&pl, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&plb, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&diff, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	cl__1.cerr = 0;
	cl__1.cunit = 6;
	cl__1.csta = 0;
	f_clos(&cl__1);
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*      OPEN(UNIT=6,FILE=GETNAM('FOR006'),ACCESS='APPEND') */
/* *** exactly why do we want to open unit 6??? it's already open?!?!?! */
/* *** we also remove this because we want use STDOUT for output... */
/*      OPEN(UNIT=6,FILE=GETNAM('FOR006')) */
/* 9990 read (6,'()',end=9999) */
/*         goto 9990 */
/* 9999 continue */
/* ***************************** at 1994-05-25 ***** */
    }
    if (incitr) {
	eold = escf;
    }
/* *********************************************************************** */
/*                                                                      * */
/*                        INVOKE THE CAMP-KING CONVERGER                * */
/*                                                                      * */
/* *********************************************************************** */
    if (niter > 2 && camkin && makea) {
	i__1 = molkst_1.norbs - na1el;
	d__1 = escf / 23.061;
	interp_(&molkst_1.norbs, &na1el, &i__1, &modea, &d__1, fokmat_1.f, 
		vector_1.c__, work1_1.ar1, work1_1.ar2, work1_1.ar3, 
		work1_1.ar4, work1_1.ar1);
    }
    makeb = FALSE_;
    if (modea == 3) {
	goto L340;
    }
    makeb = TRUE_;
    if (timitr) {
	t0 = second_();
	s_wsfe(&io___98);
	do_fio(&c__1, " ADJUST DAMPER  INTEGRAL", (ftnlen)24);
	d__1 = t0 - titer0;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (newdg) {
/* *********************************************************************** */
/*                                                                      * */
/*                        INVOKE PULAY'S CONVERGER                      * */
/*                                                                      * */
/* *********************************************************************** */
	if (okpuly && makea && iredy > 1) {
	    pulay_(fokmat_1.f, densty_1.pa, &molkst_1.norbs, work3_1.pold, 
		    work3_1.pold2, pold3, &jalp, &ialp, &c__45150, &frst, &pl)
		    ;
	}
/* *********************************************************************** */
/*                                                                      * */
/*           DIAGONALIZE THE ALPHA OR RHF SECULAR DETERMINANT           * */
/* WHERE POSSIBLE, USE THE PULAY-STEWART METHOD, OTHERWISE USE BEPPU'S  * */
/*                                                                      * */
/* *********************************************************************** */
	if (halfe || camkin) {
	    hqrii_(fokmat_1.f, &molkst_1.norbs, &molkst_1.norbs, 
		    vector_1.eigs, vector_1.c__);
	} else {
/* #      CALL TIMER('BEFORE DIAG') */
	    diag_(fokmat_1.f, vector_1.c__, &na1el, vector_1.eigs, &
		    molkst_1.norbs, &molkst_1.norbs);
/* #      CALL TIMER('AFTER DIAG') */
	}
    } else {
/* #      CALL TIMER('BEFORE HQRII') */
	hqrii_(fokmat_1.f, &molkst_1.norbs, &molkst_1.norbs, vector_1.eigs, 
		vector_1.c__);
/* #      CALL TIMER('AFTER HQRII') */
	if (timitr) {
	    t1 = second_();
	    s_wsfe(&io___102);
	    do_fio(&c__1, "  HQRII:", (ftnlen)8);
	    d__1 = t1 - t0;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, " INTEGRAL", (ftnlen)9);
	    d__2 = t1 - titer0;
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    j = 1;
    if (prtvec) {
	j = 1;
	if (uhf) {
	    j = 2;
	}
	s_wsfe(&io___103);
	do_fio(&c__1, abprt + (j - 1) * 5, (ftnlen)5);
	do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	e_wsfe();
	matout_(vector_1.c__, vector_1.eigs, &molkst_1.norbs, &molkst_1.norbs,
		 &molkst_1.norbs);
    } else {
	if (prteig) {
	    s_wsfe(&io___104);
	    do_fio(&c__1, abprt + (j - 1) * 5, (ftnlen)5);
	    do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	    i__1 = molkst_1.norbs;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&vector_1.eigs[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
    }
L340:
    if (ifill != 0) {
	swap_(vector_1.c__, &molkst_1.norbs, &molkst_1.norbs, &na2el, &ifill);
    }
/* *********************************************************************** */
/*                                                                      * */
/*            CALCULATE THE ALPHA OR RHF DENSITY MATRIX                 * */
/*                                                                      * */
/* *********************************************************************** */
    if (uhf) {
	densit_(vector_1.c__, &molkst_1.norbs, &molkst_1.norbs, &na2el, &
		na1el, &molkst_1.fract, densty_1.pa, &c__1);
	if (modea != 3 && ! (newdg && okpuly)) {
	    cnvg_(densty_1.pa, work3_1.pold, work3_1.pold2, &molkst_1.norbs, &
		    niter, &pl);
	}
    } else {
/* #      CALL TIMER('BEFORE DENSIT') */
	densit_(vector_1.c__, &molkst_1.norbs, &molkst_1.norbs, &na2el, &
		na1el, &molkst_1.fract, densty_1.p, &c__1);
/* #      CALL TIMER('AFTER DENSIT') */
	if (modea != 3 && ! (newdg && okpuly)) {
/* #      CALL TIMER('BEFORE CNVG') */
	    cnvg_(densty_1.p, work3_1.pold, work3_1.pold2, &molkst_1.norbs, &
		    niter, &pl);
/* #      CALL TIMER('AFTER CNVG') */
	}
    }
/* *********************************************************************** */
/*                                                                      * */
/*                       UHF-SPECIFIC CODE                              * */
/*                                                                      * */
/* *********************************************************************** */
    if (uhf) {
/* *********************************************************************** */
/*                                                                      * */
/*                        INVOKE THE CAMP-KING CONVERGER                * */
/*                                                                      * */
/* *********************************************************************** */
	if (niter > 2 && camkin && makeb) {
	    i__1 = molkst_1.norbs - nb1el;
	    d__1 = escf / 23.061;
	    interp_(&molkst_1.norbs, &nb1el, &i__1, &modeb, &d__1, 
		    fokmat_1.fb, vector_1.cbeta, work1_1.br1, work1_1.br2, 
		    work1_1.br3, work1_1.br4, work1_1.br1);
	}
	makea = FALSE_;
	if (modeb == 3) {
	    goto L350;
	}
	makea = TRUE_;
	if (newdg) {
/* *********************************************************************** */
/*                                                                      * */
/*                        INVOKE PULAY'S CONVERGER                      * */
/*                                                                      * */
/* *********************************************************************** */
	    if (okpuly && makeb && iredy > 1) {
		pulay_(fokmat_1.fb, densty_1.pb, &molkst_1.norbs, 
			work3_1.pbold, work3_1.pbold2, pbold3, &jbet, &ibet, &
			c__45150, &bfrst, &plb);
	    }
/* *********************************************************************** */
/*                                                                      * */
/*           DIAGONALIZE THE ALPHA OR RHF SECULAR DETERMINANT           * */
/* WHERE POSSIBLE, USE THE PULAY-STEWART METHOD, OTHERWISE USE BEPPU'S  * */
/*                                                                      * */
/* *********************************************************************** */
	    if (halfe || camkin) {
		hqrii_(fokmat_1.fb, &molkst_1.norbs, &molkst_1.norbs, 
			vector_1.eigb, vector_1.cbeta);
	    } else {
		diag_(fokmat_1.fb, vector_1.cbeta, &nb1el, vector_1.eigb, &
			molkst_1.norbs, &molkst_1.norbs);
	    }
	} else {
	    hqrii_(fokmat_1.fb, &molkst_1.norbs, &molkst_1.norbs, 
		    vector_1.eigb, vector_1.cbeta);
	}
	if (prtvec) {
	    s_wsfe(&io___108);
	    do_fio(&c__1, abprt + 10, (ftnlen)5);
	    do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	    e_wsfe();
	    matout_(vector_1.cbeta, vector_1.eigb, &molkst_1.norbs, &
		    molkst_1.norbs, &molkst_1.norbs);
	} else {
	    if (prteig) {
		s_wsfe(&io___109);
		do_fio(&c__1, abprt + 10, (ftnlen)5);
		do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
		i__1 = molkst_1.norbs;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    do_fio(&c__1, (char *)&vector_1.eigb[i__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
	    }
	}
/* *********************************************************************** */
/*                                                                      * */
/*                CALCULATE THE BETA DENSITY MATRIX                     * */
/*                                                                      * */
/* *********************************************************************** */
L350:
	densit_(vector_1.cbeta, &molkst_1.norbs, &molkst_1.norbs, &nb2el, &
		nb1el, &molkst_1.fract, densty_1.pb, &c__1);
	if (! (newdg && okpuly)) {
	    cnvg_(densty_1.pb, work3_1.pbold, work3_1.pbold2, &molkst_1.norbs,
		     &niter, &plb);
	}
    }
/* *********************************************************************** */
/*                                                                      * */
/*                   CALCULATE THE TOTAL DENSITY MATRIX                 * */
/*                                                                      * */
/* *********************************************************************** */
    if (uhf) {
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L360: */
	    densty_1.p[i__ - 1] = densty_1.pa[i__ - 1] + densty_1.pb[i__ - 1];
	}
    } else {
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    densty_1.pa[i__ - 1] = densty_1.p[i__ - 1] * .5;
/* L370: */
	    densty_1.pb[i__ - 1] = densty_1.pa[i__ - 1];
	}
    }
    if (prtden) {
	s_wsfe(&io___110);
	do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	e_wsfe();
	vecprt_(densty_1.p, &molkst_1.norbs);
    }
    oknewd = pl < sellim || oknewd;
    newdg = pl < trans && oknewd || newdg;
    if (pl < trans * .3333) {
	oknewd = TRUE_;
    }
    goto L90;
/* ********************************************************************* */
/*                                                                    * */
/*                                                                    * */
/*                      END THE SCF LOOP HERE                         * */
/*                NOW CALCULATE THE ELECTRONIC ENERGY                 * */
/*                                                                    * */
/*                                                                    * */
/* ********************************************************************* */
/*          SELF-CONSISTENCE ACHEIVED. */

L380:
    *ee = helect_(&molkst_1.norbs, densty_1.pa, &h__[1], fokmat_1.f);
    if (uhf) {
	*ee += helect_(&molkst_1.norbs, densty_1.pb, &h__[1], fokmat_1.fb);
    } else {
	*ee = *ee * 2. + shift * (molkst_1.nopen - molkst_1.nclose) * 23.061 *
		 .25 * (molkst_1.fract * (2. - molkst_1.fract));
    }
    if (capps) {
	*ee += capcor_(molkst_1.nat, molkst_1.nfirst, molkst_1.nlast, &
		molkst_1.numat, densty_1.p, &h__[1]);
    }

/*   NORMALLY THE EIGENVALUES ARE INCORRECT BECAUSE THE */
/*   PSEUDODIAGONALIZATION HAS BEEN USED.  IF THIS */
/*   IS THE LAST SCF, THEN DO AN EXACT DIAGONALIZATION */
    if (numscf_1.nscf == 0 || last_1.last == 1 || ci || halfe) {

/*  PUT F AND FB INTO POLD IN ORDER TO NOT DESTROY F AND FB */
/*  AND DO EXACT DIAGONALISATIONS */
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L390: */
	    work3_1.pold[i__ - 1] = fokmat_1.f[i__ - 1];
	}
	hqrii_(work3_1.pold, &molkst_1.norbs, &molkst_1.norbs, vector_1.eigs, 
		vector_1.c__);
	if (uhf) {
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L400: */
		work3_1.pold[i__ - 1] = fokmat_1.fb[i__ - 1];
	    }
	    hqrii_(work3_1.pold, &molkst_1.norbs, &molkst_1.norbs, 
		    vector_1.eigb, vector_1.cbeta);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L410: */
		work3_1.pold[i__ - 1] = densty_1.pa[i__ - 1];
	    }
	} else {
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L420: */
		work3_1.pold[i__ - 1] = densty_1.p[i__ - 1];
	    }
	}
	if (ci || halfe) {
/* #        CALL TIMER('BEFORE MECI') */
	    sum = meci_(vector_1.eigs, vector_1.c__);
/* #        CALL TIMER('AFTER MECI') */
	    *ee += sum;
	    if (prtpl) {
		escf = (*ee + enuclr_1.enuclr) * 23.061 + atheat_1.atheat;
		s_wsfe(&io___112);
		do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	}
    }
    ++numscf_1.nscf;
    if (debug) {
	s_wsfe(&io___113);
	do_fio(&c__1, (char *)&niter, (ftnlen)sizeof(integer));
	e_wsfe();
    }
/*            IF(FORCE)  SCFCRT=1.D-5 */
    if (allcon && (d__1 = bshift - 4.44, abs(d__1)) < 1e-7) {
	camkin = FALSE_;
	allcon = FALSE_;
	newdg = FALSE_;
	bshift = -10.;
	okpuly = FALSE_;
    }
    shift = 1.;
    if (scftyp_1.emin == 0.) {
	scftyp_1.emin = escf;
    } else {
	scftyp_1.emin = min(scftyp_1.emin,escf);
    }
    return 0;
} /* iter_ */

