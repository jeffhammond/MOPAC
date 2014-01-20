/* meci.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal rjkab[64]	/* was [8][8] */, rjkaa[64]	/* was [8][8] 
	    */;
} rjks_;

#define rjks_1 rjks_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, ndummy[2], nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    integer ispqr[512]	/* was [64][8] */, is, i__, k;
} spqr_;

#define spqr_1 spqr_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal cimat[4096], eig[64], diag[1024];
} work2_;

#define work2_1 work2_

struct {
    doublereal occa[8];
} baseoc_;

#define baseoc_1 baseoc_

struct {
    doublereal dijkl[180600];
} work3_;

#define work3_1 work3_

struct {
    doublereal vectci[64], conf[4097];
} civect_;

#define civect_1 civect_

struct {
    integer nalpha[64];
} nalmat_;

#define nalmat_1 nalmat_

struct {
    integer microa[2048]	/* was [8][256] */, microb[2048]	/* 
	    was [8][256] */;
} micros_;

#define micros_1 micros_

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;
static integer c__8 = 8;
static integer c__9 = 9;

doublereal meci_(doublereal *eigs, doublereal *coeff)
{
    /* Initialized data */

    static integer icalcn = 0;
    static char tspin[8*7] = "SINGLET " "DOUBLET " "TRIPLET " "QUARTET " 
	    "QUINTET " "SEXTET  " "SEPTET  ";

    /* Format strings */
    static char fmt_110[] = "(/,5x,\002EIGENVALUES AFTER REMOVAL OF INTER-EL"
	    "ECTRONIC INTERACTIONS\002,/)";
    static char fmt_220[] = "(10x,\002COMPONENT OF SPIN  = \002,f4.1)";
    static char fmt_230[] = "(//10x,\002 NO OF CONFIGURATIONS CONSIDERED ="
	    " \002,i4)";
    static char fmt_380[] = "(///,\002 STATE ENERGIES \002,\002 EXPECTATION "
	    "VALUE OF S**2  S FROM S**2=S(S+1)\002,//)";
    static char fmt_460[] = "(i5,f12.6,3x,a8,f15.5,f10.5)";

    /* System generated locals */
    integer coeff_dim1, coeff_offset, i__1, i__2, i__3, i__4, i__5;
    doublereal ret_val, d__1, d__2;
    alist al__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_rew(alist *), s_rsfe(cilist *), e_rsfe(void), s_cmp(char *, 
	    char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer i_dnnt(doublereal *), s_wsle(cilist *), e_wsle(void), do_lio(
	    integer *, integer *, char *, ftnlen);

    /* Local variables */
    static integer j, l;
    static doublereal x, y;
    static integer i1, j1, ii, ne, ji, li, il, in, iu;
    static doublereal xx;
    static integer nfa[16];
    static doublereal gse, ams;
    static integer iuj;
    static doublereal sum, eiga[8];
    static integer lima, limb;
    static char line[80];
    static logical doub;
    static integer mdim;
    extern /* Subroutine */ int ijkl_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *);
    static logical sing;
    extern /* Subroutine */ int perm_(integer *, integer *, integer *, 
	    integer *, integer *);
    static logical quar;
    static doublereal spin[64];
    static logical quin, trip;
    static doublereal summ;
    static integer nupp;
    static logical prnt, sext;
    static integer ntot;
    static logical prnt2;
    extern doublereal reada_(char *, integer *, ftnlen), diagi_(integer *, 
	    integer *, doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int mecih_(doublereal *, doublereal *, integer *, 
	    integer *);
    static logical debug, large, geook;
    static integer msdel;
    extern /* Subroutine */ int hqrii_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static logical lspin;
    static integer ndown, izero, lroot, kroot, iroot;
    static doublereal smult;
    static logical lspin1, first1;
    static integer nperma[384]	/* was [8][48] */, npermb[384]	/* was [8][48]
	     */;
    static logical bigprt;
    static integer ndoubl, labsiz, maxvec, iofset, natoms;
    extern /* Subroutine */ int vecprt_(doublereal *, integer *), matout_(
	    doublereal *, doublereal *, integer *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___30 = { 0, 6, 0, "('  INITIAL EIGENVALUES')", 0 };
    static cilist io___31 = { 0, 6, 0, "(5F12.6)", 0 };
    static cilist io___32 = { 0, 6, 0, "(//10X,'NUMBER OF ELECTRONS IN C.I. "
	    "=',F5.1)", 0 };
    static cilist io___33 = { 0, 6, 0, "(///10X,A)", 0 };
    static cilist io___34 = { 0, 6, 0, "(10X,A)", 0 };
    static cilist io___35 = { 0, 6, 0, "(10X,A)", 0 };
    static cilist io___36 = { 0, 6, 0, "(10X,A)", 0 };
    static cilist io___37 = { 0, 6, 0, "(10X,A)", 0 };
    static cilist io___38 = { 0, 6, 0, "(//10X,'EIGENVECTORS',/)", 0 };
    static cilist io___39 = { 0, 6, 0, "(6F12.6)", 0 };
    static cilist io___41 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___42 = { 0, 6, 0, "(6F12.6)", 0 };
    static cilist io___43 = { 0, 6, 0, "(///10X,'TWO-ELECTRON J-INTEGRALS',/)"
	    , 0 };
    static cilist io___45 = { 0, 6, 0, "(10F10.4)", 0 };
    static cilist io___47 = { 0, 6, 0, "(///10X,'TWO-ELECTRON K-INTEGRALS',/)"
	    , 0 };
    static cilist io___48 = { 0, 6, 0, "(10F10.4)", 0 };
    static cilist io___50 = { 0, 6, 0, "('    MICROSTATES READ IN')", 0 };
    static cilist io___52 = { 0, 5, 0, "(A)", 0 };
    static cilist io___54 = { 0, 5, 0, "(A)", 0 };
    static cilist io___55 = { 0, 5, 0, "(A)", 0 };
    static cilist io___57 = { 0, 6, 0, "(20I6)", 0 };
    static cilist io___58 = { 0, 6, 0, "(/,'NUMBER OF ELECTRONS IN C.I. REDE"
	    "FINED TO:',I4,/)", 0 };
    static cilist io___62 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___63 = { 0, 6, 0, "(/10X,'IMPOSSIBLE VALUE OF DELTA S')",
	     0 };
    static cilist io___66 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___71 = { 0, 6, 0, "(//10X,'C.I. IS OF SIZE LESS THAN RO"
	    "OT SPECIFIED')", 0 };
    static cilist io___72 = { 0, 6, 0, "(10X,'MODIFY SIZE OF C.I. OR ROOT NU"
	    "MBER')", 0 };
    static cilist io___73 = { 0, 6, 0, "(A,I4,A,I4)", 0 };
    static cilist io___74 = { 0, 6, 0, "(/,' CONFIGURATIONS CONSIDERED IN C."
	    "I.      ',/               ' M.O. NUMBER :      ',10I4)", 0 };
    static cilist io___75 = { 0, 6, 0, "('          ENERGY')", 0 };
    static cilist io___76 = { 0, 6, 0, "(/10X,I4,6X,10I4)", 0 };
    static cilist io___77 = { 0, 6, 0, "(6X,F10.4,4X,10I4)", 0 };
    static cilist io___78 = { 0, 6, 0, "(//,' C.I. MATRIX')", 0 };
    static cilist io___79 = { 0, 6, 0, "('   (OUTPUT HAS BEEN TRUNCATED)')", 
	    0 };
    static cilist io___80 = { 0, 6, 0, "(//,' DIAGONAL OF C.I. MATRIX')", 0 };
    static cilist io___81 = { 0, 6, 0, "(5F13.6)", 0 };
    static cilist io___84 = { 0, 6, 0, "(//20X,'STATE VECTORS',//)", 0 };
    static cilist io___85 = { 0, 6, 0, fmt_380, 0 };
    static cilist io___91 = { 0, 6, 0, fmt_460, 0 };
    static cilist io___92 = { 0, 6, 0, "(//10X,'THE STATE REQUIRED IS NOT PR"
	    "ESENT IN THE')", 0 };
    static cilist io___93 = { 0, 6, 0, "(10X,  '    SET OF CONFIGURATIONS AV"
	    "AILABLE')", 0 };
    static cilist io___94 = { 0, 6, 0, "(/ 4X,'NUMBER OF STATES ACCESSIBLE U"
	    "SING CURRENT KEY-WORDS',/)", 0 };
    static cilist io___95 = { 0, 6, 0, "((24X,A8,I4))", 0 };
    static cilist io___97 = { 0, 6, 0, "('   ESR SPECIFIED FOR AN EVEN-ELECT"
	    "RON SYSTEM')", 0 };
    static cilist io___100 = { 0, 6, 0, "(//,'      MICROSTATE CONTRIBUTIONS"
	    " TO ',           'STATE EIGENFUNCTION',I3)", 0 };
    static cilist io___101 = { 0, 6, 0, "(5F13.6)", 0 };
    static cilist io___103 = { 0, 6, 0, "(/,'    SPIN DENSITIES FROM EACH M."
	    "O., ENERGY:'     ,F7.3)", 0 };
    static cilist io___104 = { 0, 6, 0, "(5F12.6)", 0 };
    static cilist io___105 = { 0, 6, 0, 0, 0 };
    static cilist io___106 = { 0, 6, 0, 0, 0 };
    static cilist io___107 = { 0, 6, 0, 0, 0 };
    static cilist io___111 = { 0, 6, 0, "('  ATOM',I4,'    SPIN DENSITY  ',5"
	    "F10.7)", 0 };
    static cilist io___112 = { 0, 6, 0, "('  ATOM',I4,'    SPIN DENSITY  ',F"
	    "10.7,30X,F10.7)", 0 };


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
/* ********************************************************************** */

/*                 PROGRAM MECI */

/*   A MULTI-ELECTRON CONFIGURATION INTERACTION CALCULATION */

/*   WRITTEN BY JAMES J. P. STEWART, AT THE */
/*              FRANK J. SEILER RESEARCH LABORATORY */
/*              USAFA, COLORADO SPRINGS, CO 80840 */

/*              1985 */

/* ********************************************************************** */


/*   MATRICES FOR PERMUTATION WORK */


/*   MATRICES FOR ONE AND TWO ELECTRON INTEGRALS */


/*   SPIN MATRICES */


/*   MATRICES FOR SEC.DET., VECTORS, AND EIGENVALUES. */

    /* Parameter adjustments */
    coeff_dim1 = molkst_1.norbs;
    coeff_offset = 1 + coeff_dim1 * 1;
    coeff -= coeff_offset;
    --eigs;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	first1 = TRUE_;
	mdim = 64;
	geook = i_indx(keywrd_1.keywrd, "GEO-OK", (ftnlen)241, (ftnlen)6) != 
		0;
	lspin1 = i_indx(keywrd_1.keywrd, "ESR", (ftnlen)241, (ftnlen)3) != 0;
	debug = i_indx(keywrd_1.keywrd, "DEBUG", (ftnlen)241, (ftnlen)5) != 0;
	prnt2 = i_indx(keywrd_1.keywrd, "MECI", (ftnlen)241, (ftnlen)4) != 0;
	debug = debug && prnt2;
	large = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5) != 0;
	ndoubl = 99;
	if (i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) 
		    + 7;
	    ndoubl = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) 
		    + 5;
	    cibits_1.nmos = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)
		    241);
	} else if (i_indx(keywrd_1.keywrd, "C.I.=", (ftnlen)241, (ftnlen)5) !=
		 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "C.I.=", (ftnlen)241, (ftnlen)5) + 
		    5;
	    cibits_1.nmos = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)
		    241);
	} else {
	    cibits_1.nmos = molkst_1.nopen - molkst_1.nclose;
	}
	lroot = 1;
	if (i_indx(keywrd_1.keywrd, "EXCI", (ftnlen)241, (ftnlen)4) != 0) {
	    lroot = 2;
	}
	spqr_1.i__ = i_indx(keywrd_1.keywrd, "ROOT", (ftnlen)241, (ftnlen)4);
	if (spqr_1.i__ != 0) {
	    lroot = (integer) reada_(keywrd_1.keywrd, &spqr_1.i__, (ftnlen)
		    241);
	}
	if (ndoubl == 99) {
/* Computing MAX */
/* Computing MIN */
	    i__2 = (molkst_1.nclose + molkst_1.nopen + 1) / 2 - (
		    cibits_1.nmos - 1) / 2, i__3 = molkst_1.norbs - 
		    cibits_1.nmos + 1;
	    i__1 = min(i__2,i__3);
	    j = max(i__1,1);
	} else {
	    j = molkst_1.nclose - ndoubl + 1;
	    if (molkst_1.fract > 1.99) {
		++j;
	    }
	}
	l = 0;
	i__1 = molkst_1.nclose;
	for (spqr_1.i__ = j; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    ++l;
/* L10: */
	    baseoc_1.occa[l - 1] = 1.;
	}
	i__1 = molkst_1.nopen;
	for (spqr_1.i__ = molkst_1.nclose + 1; spqr_1.i__ <= i__1; 
		++spqr_1.i__) {
	    ++l;
/* L20: */
	    baseoc_1.occa[l - 1] = molkst_1.fract * .5;
	}
	i__1 = j + cibits_1.nmos - 1;
	for (spqr_1.i__ = molkst_1.nopen + 1; spqr_1.i__ <= i__1; 
		++spqr_1.i__) {
	    ++l;
/* L30: */
	    baseoc_1.occa[l - 1] = 0.;
	}
/* #         WRITE(6,'('' INITIAL ORBITAL OCCUPANCIES'')') */
/* #         WRITE(6,'(6F12.6)')(OCCA(L),L=1,NMOS) */
	sing = i_indx(keywrd_1.keywrd, "SING", (ftnlen)241, (ftnlen)4) + 
		i_indx(keywrd_1.keywrd, "EXCI", (ftnlen)241, (ftnlen)4) + 
		i_indx(keywrd_1.keywrd, "BIRAD", (ftnlen)241, (ftnlen)5) != 0;
	doub = i_indx(keywrd_1.keywrd, "DOUB", (ftnlen)241, (ftnlen)4) != 0;
	trip = i_indx(keywrd_1.keywrd, "TRIP", (ftnlen)241, (ftnlen)4) != 0;
	quar = i_indx(keywrd_1.keywrd, "QUAR", (ftnlen)241, (ftnlen)4) != 0;
	quin = i_indx(keywrd_1.keywrd, "QUIN", (ftnlen)241, (ftnlen)4) != 0;
	sext = i_indx(keywrd_1.keywrd, "SEXT", (ftnlen)241, (ftnlen)4) != 0;

/*  DEFINE MAGNETIC COMPONENT OF SPIN */

	msdel = i_indx(keywrd_1.keywrd, " MS", (ftnlen)241, (ftnlen)3);
	if (msdel != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, " MS", (ftnlen)241, (ftnlen)3);
	    msdel = (integer) (reada_(keywrd_1.keywrd, &i__1, (ftnlen)241) * 
		    1.0001);
	} else {
	    if (trip || quar) {
		msdel = 1;
	    }
	    if (quin || sext) {
		msdel = 2;
	    }
	}
	smult = -.5;
	if (sing) {
	    smult = 0.;
	}
	if (doub) {
	    smult = .75;
	}
	if (trip) {
	    smult = 2.;
	}
	if (quar) {
	    smult = 3.75;
	}
	if (quin) {
	    smult = 6.;
	}
	if (sext) {
	    smult = 8.75;
	}
	x = 0.;
	i__1 = cibits_1.nmos;
	for (j = 1; j <= i__1; ++j) {
/* L40: */
	    x += baseoc_1.occa[j - 1];
	}
	xx = x + x;
	ne = (integer) (xx + .5);
	cibits_1.nelec = (molkst_1.nelecs - ne + 1) / 2;
    }
    prnt = debug || last_1.last == 3 && prnt2;
    bigprt = prnt && large;

/*    TEST TO SEE IF THE SET OF ENERGY LEVELS USED IN MECI IS COMPLETE, */
/*    I.E., ALL COMPONENTS OF DEGENERATE IRREDUCIBLE REPRESENTATIONS */
/*    ARE USED.  IF NOT, THEN RESULTS WILL BE NONSENSE.  GIVE USERS A */
/*    CHANCE TO REALLY FOUL THINGS UP BY ALLOWING JOB TO CONTINUE IF */
/*    'GEO-OK' IS SPECIFIED. */

    i__1 = cibits_1.nmos;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	in = spqr_1.i__ + cibits_1.nelec;
/* L50: */
	eiga[spqr_1.i__ - 1] = eigs[in];
    }
    lspin = lspin1 && last_1.last == 3;
    if (bigprt) {
	s_wsfe(&io___30);
	e_wsfe();
	s_wsfe(&io___31);
	i__1 = cibits_1.nmos;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    do_fio(&c__1, (char *)&eiga[spqr_1.i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___32);
	do_fio(&c__1, (char *)&xx, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (! geook && cibits_1.nelec > 0) {
	if ((d__1 = eigs[cibits_1.nelec + 1] - eigs[cibits_1.nelec], abs(d__1)
		) < .1 || (d__2 = eigs[cibits_1.nelec + 1 + cibits_1.nmos] - 
		eigs[cibits_1.nelec + cibits_1.nmos], abs(d__2)) < .1) {
	    s_wsfe(&io___33);
	    do_fio(&c__1, "DEGENERATE ENERGY LEVELS DETECTED IN MECI", (
		    ftnlen)41);
	    e_wsfe();
	    s_wsfe(&io___34);
	    do_fio(&c__1, "SOME OF THESE LEVELS WOULD BE TREATED BY MECI,", (
		    ftnlen)46);
	    e_wsfe();
	    s_wsfe(&io___35);
	    do_fio(&c__1, "WHILE OTHERS WOULD NOT.  THIS WOULD RESULT IN", (
		    ftnlen)45);
	    e_wsfe();
	    s_wsfe(&io___36);
	    do_fio(&c__1, "NON-REPRODUCIBLE ELECTRONIC ENERGIES.", (ftnlen)37)
		    ;
	    e_wsfe();
	    s_wsfe(&io___37);
	    do_fio(&c__1, "  JOB STOPPED.  TO CONTINUE, SPECIFY \"GEO-OK\"", (
		    ftnlen)45);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
    if (bigprt) {
	s_wsfe(&io___38);
	e_wsfe();
	i__1 = molkst_1.norbs;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
/* L60: */
	    s_wsfe(&io___39);
	    i__2 = cibits_1.nmos;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&coeff[spqr_1.i__ + (j + cibits_1.nelec)
			 * coeff_dim1], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    nfa[1] = 1;
    nfa[0] = 1;
    for (spqr_1.i__ = 3; spqr_1.i__ <= 9; ++spqr_1.i__) {
/* L70: */
	nfa[spqr_1.i__ - 1] = nfa[spqr_1.i__ - 2] * (spqr_1.i__ - 1);
    }
    ijkl_(&coeff[(cibits_1.nelec + 1) * coeff_dim1 + 1], &coeff[coeff_offset],
	     &cibits_1.nelec, &cibits_1.nmos, work3_1.dijkl);
    i__2 = cibits_1.nmos;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__2; ++spqr_1.i__) {
	i__1 = cibits_1.nmos;
	for (j = 1; j <= i__1; ++j) {
	    rjks_1.rjkaa[spqr_1.i__ + (j << 3) - 9] = xyijkl_1.xy[spqr_1.i__ 
		    + (spqr_1.i__ + (j + (j << 3) << 3) << 3) - 585] - 
		    xyijkl_1.xy[spqr_1.i__ + (j + (spqr_1.i__ + (j << 3) << 3)
		     << 3) - 585];
/* L80: */
	    rjks_1.rjkab[spqr_1.i__ + (j << 3) - 9] = xyijkl_1.xy[spqr_1.i__ 
		    + (spqr_1.i__ + (j + (j << 3) << 3) << 3) - 585];
	}
    }
    i__1 = cibits_1.nmos;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	x = 0.;
	i__2 = cibits_1.nmos;
	for (j = 1; j <= i__2; ++j) {
	    x += (rjks_1.rjkaa[spqr_1.i__ + (j << 3) - 9] + rjks_1.rjkab[
		    spqr_1.i__ + (j << 3) - 9]) * baseoc_1.occa[j - 1];
/* L90: */
	}
	eiga[spqr_1.i__ - 1] -= x;
/* #      IF(ABS(OCCA(I)-0.5).LT.1.D-4)EIGA(I)=EIGA(I)+XY(I,I,I,I)*0.25D0 */
/* L100: */
    }
    if (bigprt) {
	s_wsfe(&io___41);
	e_wsfe();
	s_wsfe(&io___42);
	i__1 = cibits_1.nmos;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    do_fio(&c__1, (char *)&eiga[spqr_1.i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsfe(&io___43);
	e_wsfe();
	i__1 = cibits_1.nmos;
	for (i1 = 1; i1 <= i__1; ++i1) {
/* L120: */
	    s_wsfe(&io___45);
	    i__2 = cibits_1.nmos;
	    for (j1 = 1; j1 <= i__2; ++j1) {
		do_fio(&c__1, (char *)&rjks_1.rjkab[i1 + (j1 << 3) - 9], (
			ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
	s_wsfe(&io___47);
	e_wsfe();
	i__2 = cibits_1.nmos;
	for (i1 = 1; i1 <= i__2; ++i1) {
/* L130: */
	    s_wsfe(&io___48);
	    i__1 = cibits_1.nmos;
	    for (j1 = 1; j1 <= i__1; ++j1) {
		d__1 = rjks_1.rjkab[i1 + (j1 << 3) - 9] - rjks_1.rjkaa[i1 + (
			j1 << 3) - 9];
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    natoms = molkst_1.numat;
    i__1 = cibits_1.nmos;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	i__2 = cibits_1.nmos;
	for (j = 1; j <= i__2; ++j) {
	    rjks_1.rjkaa[spqr_1.i__ + (j << 3) - 9] *= .5;
/* L140: */
	}
    }
    if (first1) {
	spqr_1.i__ = i_indx(keywrd_1.keywrd, "MICROS", (ftnlen)241, (ftnlen)6)
		;
	if (spqr_1.i__ != 0) {
	    spqr_1.k = (integer) reada_(keywrd_1.keywrd, &spqr_1.i__, (ftnlen)
		    241);
	    cibits_1.lab = spqr_1.k;
	    if (prnt) {
		s_wsfe(&io___50);
		e_wsfe();
	    }
	    ntot = (integer) (xx + .5);
	    al__1.aerr = 0;
	    al__1.aunit = 5;
	    f_rew(&al__1);
	    for (spqr_1.i__ = 1; spqr_1.i__ <= 1000; ++spqr_1.i__) {
		s_rsfe(&io___52);
		do_fio(&c__1, line, (ftnlen)80);
		e_rsfe();
/* L150: */
		if (i_indx(line, "MICRO", (ftnlen)80, (ftnlen)5) != 0) {
		    goto L160;
		}
	    }
L160:
	    for (spqr_1.i__ = 1; spqr_1.i__ <= 1000; ++spqr_1.i__) {
		s_rsfe(&io___54);
		do_fio(&c__1, line, (ftnlen)80);
		e_rsfe();
/* L170: */
		if (i_indx(line, "MICRO", (ftnlen)80, (ftnlen)5) != 0) {
		    goto L180;
		}
	    }
L180:
	    i__2 = cibits_1.lab;
	    for (spqr_1.i__ = 1; spqr_1.i__ <= i__2; ++spqr_1.i__) {
		s_rsfe(&io___55);
		do_fio(&c__1, line, (ftnlen)80);
		e_rsfe();
/* Computing MAX */
/* Computing MIN */
		i__4 = i_indx(line, "0", (ftnlen)80, (ftnlen)1), i__5 = 
			i_indx(line, "1", (ftnlen)80, (ftnlen)1);
		i__1 = 0, i__3 = min(i__4,i__5) - 1;
		izero = max(i__1,i__3);
		i__1 = cibits_1.nmos;
		for (j = 1; j <= i__1; ++j) {
		    i__3 = j + izero - 1;
		    if (s_cmp(line + i__3, "1", j + izero - i__3, (ftnlen)1) 
			    != 0) {
			i__4 = j + izero - 1;
			s_copy(line + i__4, "0", j + izero - i__4, (ftnlen)1);
		    }
		    i__3 = j + cibits_1.nmos + izero - 1;
		    if (s_cmp(line + i__3, "1", j + cibits_1.nmos + izero - 
			    i__3, (ftnlen)1) != 0) {
			i__4 = j + cibits_1.nmos + izero - 1;
			s_copy(line + i__4, "0", j + cibits_1.nmos + izero - 
				i__4, (ftnlen)1);
		    }
		    i__3 = j + izero - 1;
		    micros_1.microa[j + (spqr_1.i__ << 3) - 9] = *(unsigned 
			    char *)&line[i__3] - '0';
		    i__3 = j + cibits_1.nmos + izero - 1;
		    micros_1.microb[j + (spqr_1.i__ << 3) - 9] = *(unsigned 
			    char *)&line[i__3] - '0';
/* L190: */
		}
		if (prnt) {
		    s_wsfe(&io___57);
		    i__1 = cibits_1.nmos;
		    for (j = 1; j <= i__1; ++j) {
			do_fio(&c__1, (char *)&micros_1.microa[j + (
				spqr_1.i__ << 3) - 9], (ftnlen)sizeof(integer)
				);
		    }
		    i__3 = cibits_1.nmos;
		    for (j = 1; j <= i__3; ++j) {
			do_fio(&c__1, (char *)&micros_1.microb[j + (
				spqr_1.i__ << 3) - 9], (ftnlen)sizeof(integer)
				);
		    }
		    e_wsfe();
		}
		spqr_1.k = 0;
		i__1 = cibits_1.nmos;
		for (j = 1; j <= i__1; ++j) {
/* L200: */
		    spqr_1.k = spqr_1.k + micros_1.microa[j + (spqr_1.i__ << 
			    3) - 9] + micros_1.microb[j + (spqr_1.i__ << 3) - 
			    9];
		}
		if (spqr_1.k != ntot) {
		    ntot = spqr_1.k;
		    xx = (doublereal) spqr_1.k;
		    s_wsfe(&io___58);
		    do_fio(&c__1, (char *)&spqr_1.k, (ftnlen)sizeof(integer));
		    e_wsfe();
		}
/* L210: */
	    }
	    first1 = FALSE_;
	    goto L260;
	}
	nupp = (ne + 1) / 2 + msdel;
	ndown = ne - nupp;
	ams = (nupp - ndown) * .5;
	if (prnt) {
	    s_wsfe(&io___62);
	    do_fio(&c__1, (char *)&ams, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (nupp * ndown < 0) {
	    s_wsfe(&io___63);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	lima = nfa[cibits_1.nmos] / (nfa[nupp] * nfa[cibits_1.nmos - nupp]);
	limb = nfa[cibits_1.nmos] / (nfa[ndown] * nfa[cibits_1.nmos - ndown]);
	cibits_1.lab = lima * limb;
	if (prnt) {
	    s_wsfe(&io___66);
	    do_fio(&c__1, (char *)&cibits_1.lab, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* #      IF(LAB.LT.101) GOTO 240 */
/* #      WRITE(6,230) */
/* #  230 FORMAT(10X,24H TOO MANY CONFIGURATIONS/) */
/* #      GOTO 160 */
/* #  240 CONTINUE */
	perm_(nperma, &nupp, &cibits_1.nmos, &c__8, &lima);
	perm_(npermb, &ndown, &cibits_1.nmos, &c__8, &limb);
	spqr_1.k = 0;
	i__2 = lima;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__2; ++spqr_1.i__) {
	    i__1 = limb;
	    for (j = 1; j <= i__1; ++j) {
		++spqr_1.k;
		i__3 = cibits_1.nmos;
		for (l = 1; l <= i__3; ++l) {
		    micros_1.microa[l + (spqr_1.k << 3) - 9] = nperma[l + (
			    spqr_1.i__ << 3) - 9];
/* L240: */
		    micros_1.microb[l + (spqr_1.k << 3) - 9] = npermb[l + (j 
			    << 3) - 9];
		}
	    }
	}
/* L250: */
L260:
	lima = cibits_1.lab;
	limb = cibits_1.lab;
    }
    gse = 0.;
    i__3 = cibits_1.nmos;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__3; ++spqr_1.i__) {
	gse += eiga[spqr_1.i__ - 1] * baseoc_1.occa[spqr_1.i__ - 1] * 2.;
	gse += xyijkl_1.xy[spqr_1.i__ + (spqr_1.i__ + (spqr_1.i__ + (
		spqr_1.i__ << 3) << 3) << 3) - 585] * baseoc_1.occa[
		spqr_1.i__ - 1] * baseoc_1.occa[spqr_1.i__ - 1];
	i__1 = cibits_1.nmos;
	for (j = spqr_1.i__ + 1; j <= i__1; ++j) {
/* L270: */
	    gse += (xyijkl_1.xy[spqr_1.i__ + (spqr_1.i__ + (j + (j << 3) << 3)
		     << 3) - 585] * 2. - xyijkl_1.xy[spqr_1.i__ + (j + (
		    spqr_1.i__ + (j << 3) << 3) << 3) - 585]) * 2. * 
		    baseoc_1.occa[spqr_1.i__ - 1] * baseoc_1.occa[j - 1];
	}
    }
    j = 0;
    i__1 = cibits_1.lab;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	work2_1.diag[spqr_1.i__ - 1] = diagi_(&micros_1.microa[(spqr_1.i__ << 
		3) - 8], &micros_1.microb[(spqr_1.i__ << 3) - 8], eiga, 
		xyijkl_1.xy, &cibits_1.nmos) - gse;
/* L280: */
    }
L290:
    if (cibits_1.lab <= mdim) {
	goto L330;
    }
    x = -100.;
    i__1 = cibits_1.lab;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	if (work2_1.diag[spqr_1.i__ - 1] > x) {
	    x = work2_1.diag[spqr_1.i__ - 1];
	    j = spqr_1.i__;
	}
/* L300: */
    }
    if (j != cibits_1.lab) {
	i__1 = cibits_1.lab;
	for (spqr_1.i__ = j; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    i1 = spqr_1.i__ + 1;
	    i__3 = cibits_1.nmos;
	    for (spqr_1.k = 1; spqr_1.k <= i__3; ++spqr_1.k) {
		micros_1.microa[spqr_1.k + (spqr_1.i__ << 3) - 9] = 
			micros_1.microa[spqr_1.k + (i1 << 3) - 9];
/* L310: */
		micros_1.microb[spqr_1.k + (spqr_1.i__ << 3) - 9] = 
			micros_1.microb[spqr_1.k + (i1 << 3) - 9];
	    }
/* L320: */
	    work2_1.diag[spqr_1.i__ - 1] = work2_1.diag[i1 - 1];
	}
    }
    --cibits_1.lab;
    goto L290;
L330:

/*     BUILD SPIN AND NUMBER OF ALPHA SPIN TABLES. */
/*     ------------------------------------------- */
    i__1 = cibits_1.lab;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	spqr_1.k = 0;
	x = 0.;
	i__3 = cibits_1.nmos;
	for (j = 1; j <= i__3; ++j) {
	    x += micros_1.microa[j + (spqr_1.i__ << 3) - 9] * micros_1.microb[
		    j + (spqr_1.i__ << 3) - 9];
/* L340: */
	    spqr_1.k += micros_1.microa[j + (spqr_1.i__ << 3) - 9];
	}
	nalmat_1.nalpha[spqr_1.i__ - 1] = spqr_1.k;
/* L350: */
/* Computing 2nd power */
	d__1 = xx - (nalmat_1.nalpha[spqr_1.i__ - 1] << 1);
	spin[spqr_1.i__ - 1] = x * 4. - d__1 * d__1;
    }

/*   BEFORE STARTING, CHECK THAT THE ROOT WANTED CAN EXIST */

    if (cibits_1.lab < lroot) {
	s_wsfe(&io___71);
	e_wsfe();
	s_wsfe(&io___72);
	e_wsfe();
	s_wsfe(&io___73);
	do_fio(&c__1, " SIZE OF C.I.:", (ftnlen)14);
	do_fio(&c__1, (char *)&cibits_1.lab, (ftnlen)sizeof(integer));
	do_fio(&c__1, " ROOT REQUIRED:", (ftnlen)15);
	do_fio(&c__1, (char *)&lroot, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (prnt) {
	s_wsfe(&io___74);
	i__1 = cibits_1.nelec + cibits_1.nmos;
	for (spqr_1.i__ = cibits_1.nelec + 1; spqr_1.i__ <= i__1; 
		++spqr_1.i__) {
	    do_fio(&c__1, (char *)&spqr_1.i__, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	s_wsfe(&io___75);
	e_wsfe();
	i__1 = cibits_1.lab;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    s_wsfe(&io___76);
	    do_fio(&c__1, (char *)&spqr_1.i__, (ftnlen)sizeof(integer));
	    i__3 = cibits_1.nmos;
	    for (spqr_1.k = 1; spqr_1.k <= i__3; ++spqr_1.k) {
		do_fio(&c__1, (char *)&micros_1.microa[spqr_1.k + (spqr_1.i__ 
			<< 3) - 9], (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
/* L360: */
	    s_wsfe(&io___77);
	    do_fio(&c__1, (char *)&work2_1.diag[spqr_1.i__ - 1], (ftnlen)
		    sizeof(doublereal));
	    i__3 = cibits_1.nmos;
	    for (spqr_1.k = 1; spqr_1.k <= i__3; ++spqr_1.k) {
		do_fio(&c__1, (char *)&micros_1.microb[spqr_1.k + (spqr_1.i__ 
			<< 3) - 9], (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	}
    }
    mecih_(work2_1.diag, work2_1.cimat, &cibits_1.nmos, &cibits_1.lab);
    if (bigprt) {
	s_wsfe(&io___78);
	e_wsfe();
	spqr_1.i__ = min(cibits_1.lab,300);
	if (spqr_1.i__ != cibits_1.lab) {
	    s_wsfe(&io___79);
	    e_wsfe();
	}
	i__3 = -spqr_1.i__;
	vecprt_(work2_1.cimat, &i__3);
    } else {
	if (prnt) {
	    s_wsfe(&io___80);
	    e_wsfe();
	}
	if (prnt) {
	    s_wsfe(&io___81);
	    i__3 = cibits_1.lab;
	    for (spqr_1.i__ = 1; spqr_1.i__ <= i__3; ++spqr_1.i__) {
		do_fio(&c__1, (char *)&work2_1.cimat[spqr_1.i__ * (spqr_1.i__ 
			+ 1) / 2 - 1], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
/* #       CALL TIMER('SEC. DET. CONSTRUCTED') */
/* Computing MIN */
    i__3 = cibits_1.lab, i__1 = lroot + 10;
    labsiz = min(i__3,i__1);
    hqrii_(work2_1.cimat, &cibits_1.lab, &labsiz, work2_1.eig, civect_1.conf);
/* #       CALL TIMER('DIAG. DONE') */

/*   DECIDE WHICH ROOT TO EXTRACT */

    kroot = 0;
    if (smult < -.1) {
	ret_val = work2_1.eig[lroot - 1];
	i__3 = cibits_1.lab;
	for (j = 1; j <= i__3; ++j) {
/* L370: */
	    civect_1.vectci[j - 1] = civect_1.conf[j + cibits_1.lab * (lroot 
		    - 1) - 1];
	}
	kroot = lroot;
    }
    if (bigprt) {
	s_wsfe(&io___84);
	e_wsfe();
	spqr_1.i__ = min(cibits_1.lab,molkst_1.norbs);
	j = min(labsiz,molkst_1.norbs);
	i__3 = -spqr_1.i__;
	matout_(civect_1.conf, work2_1.eig, &j, &i__3, &cibits_1.lab);
    }
    if (prnt) {
	s_wsfe(&io___85);
	e_wsfe();
    }
    iroot = 0;
    for (spqr_1.i__ = 1; spqr_1.i__ <= 9; ++spqr_1.i__) {
/* L390: */
	work2_1.cimat[spqr_1.i__ - 1] = .1;
    }
    i__3 = labsiz;
    for (spqr_1.i__ = 1; spqr_1.i__ <= i__3; ++spqr_1.i__) {
	x = xx * .5;
	ii = (spqr_1.i__ - 1) * cibits_1.lab;
	i__1 = cibits_1.lab;
	for (j = 1; j <= i__1; ++j) {
	    ji = j + ii;
	    x -= civect_1.conf[ji - 1] * civect_1.conf[ji - 1] * spin[j - 1] *
		     .25;
	    spqr_1.k = spqr_1.ispqr[j - 1];
	    if (spqr_1.k == 1) {
		goto L410;
	    }
	    i__2 = spqr_1.k;
	    for (l = 2; l <= i__2; ++l) {
		li = spqr_1.ispqr[j + (l << 6) - 65] + ii;
/* L400: */
		x += civect_1.conf[ji - 1] * civect_1.conf[li - 1] * 2.;
	    }
L410:
/* L420: */
	    ;
	}
	y = (sqrt(x * 4. + 1.) - 1.) * .5;
	if ((d__1 = smult - x, abs(d__1)) < .01f) {
	    ++iroot;
	    if (iroot == lroot) {
		kroot = spqr_1.i__;
		ret_val = work2_1.eig[spqr_1.i__ - 1];
		i__1 = cibits_1.lab;
		for (j = 1; j <= i__1; ++j) {
/* L430: */
		    civect_1.vectci[j - 1] = civect_1.conf[j + cibits_1.lab * 
			    (spqr_1.i__ - 1) - 1];
		}
	    }
	}
	j = (integer) (y * 2. + 1.5);
	work2_1.cimat[j - 1] += 1;
/* L440: */
	if (prnt) {
	    s_wsfe(&io___91);
	    do_fio(&c__1, (char *)&spqr_1.i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&work2_1.eig[spqr_1.i__ - 1], (ftnlen)
		    sizeof(doublereal));
	    do_fio(&c__1, tspin + (j - 1 << 3), (ftnlen)8);
	    do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&y, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    if (kroot == 0) {
	s_wsfe(&io___92);
	e_wsfe();
	s_wsfe(&io___93);
	e_wsfe();
	s_wsfe(&io___94);
	e_wsfe();
	for (spqr_1.i__ = 1; spqr_1.i__ <= 7; ++spqr_1.i__) {
/* L450: */
	    if (work2_1.cimat[spqr_1.i__ - 1] > .5) {
		s_wsfe(&io___95);
		do_fio(&c__1, tspin + (spqr_1.i__ - 1 << 3), (ftnlen)8);
		i__3 = i_dnnt(&work2_1.cimat[spqr_1.i__ - 1]);
		do_fio(&c__1, (char *)&i__3, (ftnlen)sizeof(integer));
		e_wsfe();
	    }
	}
	s_stop("", (ftnlen)0);
    }
/* L470: */
    maxvec = 0;
    if (lspin) {
	maxvec = min(4,cibits_1.lab);
    }
    if (lspin && ne / 2 << 1 == ne) {
	s_wsfe(&io___97);
	e_wsfe();
    }
/* #      DO 570 I=1,NMOS */
/* #         DO 570 J=1,NORBS */
/* #  570 COEFF(J,I+NELEC)=COEFF(J,I+NELEC)**2 */
    i__3 = maxvec;
    for (iuj = 1; iuj <= i__3; ++iuj) {
	iofset = (iuj - 1) * cibits_1.lab;
	s_wsfe(&io___100);
	do_fio(&c__1, (char *)&iuj, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___101);
	i__1 = cibits_1.lab;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    do_fio(&c__1, (char *)&civect_1.conf[spqr_1.i__ + iofset - 1], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	i__1 = cibits_1.lab;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
/* L480: */
/* Computing 2nd power */
	    d__1 = civect_1.vectci[spqr_1.i__ + iofset - 1];
	    civect_1.conf[spqr_1.i__ - 1] = d__1 * d__1;
	}
/*                                             SECOND VECTOR! */
	i__1 = cibits_1.nmos;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    sum = 0.;
	    i__2 = cibits_1.lab;
	    for (j = 1; j <= i__2; ++j) {
/* L490: */
		sum += (micros_1.microa[spqr_1.i__ + (j << 3) - 9] - 
			micros_1.microb[spqr_1.i__ + (j << 3) - 9]) * 
			civect_1.conf[j - 1];
	    }
/* L500: */
	    eiga[spqr_1.i__ - 1] = sum;
	}
	s_wsfe(&io___103);
	do_fio(&c__1, (char *)&work2_1.eig[iuj - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	s_wsfe(&io___104);
	i__1 = cibits_1.nmos;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    do_fio(&c__1, (char *)&eiga[spqr_1.i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	s_wsle(&io___105);
	e_wsle();
	s_wsle(&io___106);
	do_lio(&c__9, &c__1, "     SPIN DENSITIES FROM EACH ATOMIC ORBITAL", (
		ftnlen)44);
	e_wsle();
	s_wsle(&io___107);
	do_lio(&c__9, &c__1, "                              S        PX     "
		"   PY        PZ        TOTAL", (ftnlen)74);
	e_wsle();
	i__1 = natoms;
	for (spqr_1.i__ = 1; spqr_1.i__ <= i__1; ++spqr_1.i__) {
	    il = molkst_1.nfirst[spqr_1.i__ - 1];
	    iu = molkst_1.nlast[spqr_1.i__ - 1];
	    l = 0;
	    summ = 0.;
	    i__2 = iu;
	    for (spqr_1.k = il; spqr_1.k <= i__2; ++spqr_1.k) {
		++l;
		sum = 0.;
		i__4 = cibits_1.nmos;
		for (j = 1; j <= i__4; ++j) {
/* L510: */
/* Computing 2nd power */
		    d__1 = coeff[spqr_1.k + (j + cibits_1.nelec) * coeff_dim1]
			    ;
		    sum += d__1 * d__1 * eiga[j - 1];
		}
		summ += sum;
/* L520: */
		eigs[l] = sum;
	    }
	    if (l == 4) {
		s_wsfe(&io___111);
		do_fio(&c__1, (char *)&spqr_1.i__, (ftnlen)sizeof(integer));
		i__2 = l;
		for (spqr_1.k = 1; spqr_1.k <= i__2; ++spqr_1.k) {
		    do_fio(&c__1, (char *)&eigs[spqr_1.k], (ftnlen)sizeof(
			    doublereal));
		}
		do_fio(&c__1, (char *)&summ, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else {
		s_wsfe(&io___112);
		do_fio(&c__1, (char *)&spqr_1.i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&eigs[1], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&summ, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
/* L530: */
	}
/* L540: */
    }
    return ret_val;
} /* meci_ */

