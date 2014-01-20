/* deri2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal fdumy[45150], scalar[45150];
} fokmat_;

#define fokmat_1 fokmat_

struct {
    doublereal diag[22575];
} nvomat_;

#define nvomat_1 nvomat_

struct {
    doublereal dijkl[180600];
} work3_;

#define work3_1 work3_

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

struct {
    doublereal vectci[64], babinv[512], bcoef[3585];
} civect_;

#define civect_1 civect_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    doublereal bab[3600]	/* was [60][60] */, dumy[1584];
} work2_;

#define work2_1 work2_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static doublereal c_b3 = 8.;
static doublereal c_b4 = 3.;
static integer c__1 = 1;
static integer c__9 = 9;
static integer c__5 = 5;
static integer c__8 = 8;

/* Subroutine */ int deri2_(doublereal *c__, doublereal *e, integer *norbs, 
	integer *minear, doublereal *f, doublereal *fd, doublereal *fci, 
	integer *ninear, integer *nvar, doublereal *work, doublereal *b, 
	integer *nw2, doublereal *grad, doublereal *ab, integer *nw3, 
	doublereal *fb, doublereal *throld)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer c_dim1, c_offset, work_dim1, work_offset, f_dim1, f_offset, 
	    fd_dim1, fd_offset, fci_dim1, fci_offset, b_dim1, b_offset, 
	    ab_dim1, ab_offset, fb_dim1, fb_offset, i__1, i__2, i__3, i__4, 
	    i__5, i__6, i__7, i__8, i__9;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *), sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ll;
    static doublereal gse;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);
    static logical lbab;
    static integer nadd;
    static logical fail;
    static integer ivar, nres;
    static doublereal test;
    extern /* Subroutine */ int mtxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *), mxmt_(doublereal *, integer *
	    , doublereal *, integer *, doublereal *, integer *);
    static doublereal time1, time2, test2;
    extern /* Subroutine */ int mecid_(doublereal *, doublereal *, doublereal 
	    *, doublereal *), mecih_(doublereal *, doublereal *, integer *, 
	    integer *);
    static logical debug;
    extern /* Subroutine */ int deri21_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, integer *), 
	    deri22_(doublereal *, doublereal *, doublereal *, integer *, 
	    doublereal *, doublereal *, integer *, doublereal *), deri23_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *);
    static doublereal deter;
    static logical lconv[60];
    static integer nlast, nbsze;
    extern /* Subroutine */ int scopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *), osinv_(doublereal *, integer *, 
	    doublereal *), dijkl2_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *, integer *);
    extern doublereal second_(void);
    static integer maxite, nbsize, nfirst;
    extern /* Subroutine */ int supdot_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 6, 0, "(' THE BAB MATRIX OF ORDER',I3,     "
	    "                   ' IS SINGULAR IN DERI2'/                     "
	    "                   ' THE RELAXATION IS STOPPED AT THIS POINT.')", 
	    0 };
    static cilist io___20 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, "(' RELAXATION ENDED IN DERI2 AFTER',"
	    "I3,                ' CYCLES'/' REQUIRED CONVERGENCE THRESHOLD ON"
	    " RESIDUALS ='    ,F12.9/' HIGHEST RESIDUAL ON',I3,' GRADIENT COM"
	    "PONENTS = '    ,F12.9)", 0 };
    static cilist io___24 = { 0, 6, 0, "(A)", 0 };
    static cilist io___25 = { 0, 6, 0, "(A)", 0 };
    static cilist io___27 = { 0, 6, 0, "(' ELAPSED TIME IN RELAXATION',F15.3"
	    ",' SECOND')                 ", 0 };
    static cilist io___28 = { 0, 6, 0, "(A)", 0 };
    static cilist io___29 = { 0, 6, 0, "(A)", 0 };
    static cilist io___30 = { 0, 6, 0, "(' * * * GRADIENT COMPONENT NUMBER',"
	    "I4)", 0 };
    static cilist io___31 = { 0, 6, 0, "(' C.I-ACTIVE M.O. DERIVATIVES IN M."
	    "O BASIS',                    ', IN ROW.')", 0 };
    static cilist io___32 = { 0, 6, 0, "(8F10.4)", 0 };
    static cilist io___34 = { 0, 6, 0, "(' C.I-ACTIVE FOCK EIGENVALUES RELAX"
	    "ATION (E.V.)'               )", 0 };
    static cilist io___35 = { 0, 6, 0, "(8F10.4)", 0 };
    static cilist io___36 = { 0, 6, 0, "(' 2-ELECTRON INTEGRALS RELAXATION ("
	    "E.V.)'/      '    I    J    K    L       d<I(1)J(1)|K(2)L(2)> RE"
	    "LAXATION ONLY')                                                 "
	    "               ", 0 };
    static cilist io___38 = { 0, 6, 0, "(4I5,F20.10)", 0 };
    static cilist io___40 = { 0, 6, 0, "(' RELAXATION OF THE GRADIENT COMPON"
	    "ENT',F10.4,  ' KCAL/MOLE')", 0 };
    static cilist io___41 = { 0, 6, 0, "(' ELAPSED TIME IN C.I-ENERGY RELAXA"
	    "TION',F15.3,                    ' SECOND')", 0 };


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
/* ******************************************************************** */

/*     DERI2 COMPUTE THE RELAXATION PART OF THE DERIVATIVES OF THE */
/*     NON-VARIATIONALLY OPTIMIZED ENERGY WITH RESPECT TO TWO */
/*     COORDINATES AT A TIME. THIS IS DONE IN THREE STEPS. */

/*     THE M.O DERIVATIVES ARE SOLUTION {X} OF A LINEAR SYSTEM */
/*                        (D-A) * X = F */
/*     WHERE D IS A DIAGONAL SUPER-MATRIX OF FOCK EIGENVALUE DIFFERENCES */
/*     AND A IS A SUPER-MATRIX OF 2-ELECTRONS INTEGRALS IN M.O BASIS. */
/*     SUCH A SYSTEM IS TOO LARGE TO BE INVERTED DIRECTLY THUS ONE MUST */
/*     USES A RELAXATION METHOD TO GET A REASONABLE ESTIMATE OF {X}. */
/*     THIS REQUIRES A BASIS SET {B} TO BE GENERATED ITERATIVELY, AFTER */
/*     WHICH WE SOLVE BY DIRECT INVERSION THE LINEAR SYSTEM PROJECTED */
/*     IN THIS BASIS {B}. IT WORKS QUICKLY BUT DOES REQUIRE A LARGE */
/*     CORE MEMORY. */

/*     USE A FORMALISM WITH FOCK OPERATOR THUS AVOIDING THE EXPLICIT */
/*     COMPUTATION (AND STORAGE) OF THE SUPER-MATRIX A. */
/*     THE SEMIEMPIRICAL METHODS DO NOT INVOLVE LARGE C.I CALCULATIONS. */
/*     THEREFORE FOR EACH GRADIENT COMPONENT WE BUILD THE C.I MATRIX */
/*     DERIVATIVE FROM THE M.O. INTEGRALS <IJ|KL> AND FOCK EIGENVALUES */
/*     DERIVATIVES, THUS PROVIDING THE RELAXATION CONTRIBUTION TO THE */
/*     GRADIENT WITHOUT COMPUTATION AND STORAGE OF THE 2ND ORDER DENSITY */
/*     MATRIX. */

/*   STEP 1) */
/*     USE THE PREVIOUS B AND THE NEW F VECTORS TO BUILD AN INITIAL */
/*     BASIS SET B. */
/*   STEP 2) */
/*     BECAUSE THE ELECTRONIC HESSIAN (D-A) IS THE SAME FOR EACH */
/*     DERIVATIVE, WE ONLY NEED TO ENLARGE ITERATIVELY THE ORTHONORMAL */
/*     BASIS SET {B} USED TO INVERT THE PROJECTED HESSIAN. */
/*     (DERIVED FROM THE LARGEST RESIDUAL VECTOR ). */
/*     THIS SECTION IS CARRIED OUT IN THE DIAGONAL METRIC 'SCALAR'. */
/*   STEP 3) ... LOOP ON THE GEOMETRIC VARIABLE : */
/* 3.1 FOR EACH GEOMETRIC VARIABLE, GET THE M.O DERIVATIVES IN A.O. */
/* 3.2 COMPUTE THE FOCK EIGENVALUES AND 2-ELECTRON INTEGRAL RELAXATION. */
/* 3.3 BUILD THE ELECTRONIC RELAXATION CONTRIBUTION TO THE C.I MATRIX */
/*     AND GET THE ASSOCIATED EIGENSTATE DERIVATIVE WITH RESPECT TO */
/*     THE GEOMETRIC VARIABLE. */

/*   INPUT */
/*     C(NORBS,NORBS) : M.O. COEFFICIENTS, IN COLUMN. */
/*     E(NORBS)       : EIGENVALUES OF THE FOCK MATRIX. */
/*     MINEAR         : NUMBER OF NON REDUNDANT ROTATION OF THE M.O. */
/*     F(MINEAR,NVAR) : NON-RELAXED FOCK MATRICES DERIVATIVES */
/*                    IN M.O BASIS, OFF-DIAGONAL BLOCKS. */
/*     FD(NINEAR,NVAR): IDEM, DIAGONAL BLOCKS, C.I-ACTIVE ONLY. */
/*     WORK           : WORK ARRAY OF SIZE N*N. */
/*     B(MINEAR,NBSIZE) : INITIAL ORTHONORMALIZED BASIS SET {B}. */
/*     GRAD(NVAR)     : GRADIENT VECTOR BEFORE RELAXATION CORRECTION. */
/*     AB(MINEAR,*): STORAGE FOR THE (D-A) * B VECTORS. */
/*     FB(NVAR,*)  : STORAGE FOR THE MATRIX PRODUCT F' * B. */
/*   OUTPUT */
/*     GRAD   : DERIVATIVE OF THE HEAT OF FORMATION WITH RESPECT TO */
/*              THE NVAR OPTIMIZED VARIABLES. */

/* *********************************************************************** */
    /* Parameter adjustments */
    work_dim1 = *norbs;
    work_offset = 1 + work_dim1 * 1;
    work -= work_offset;
    --e;
    c_dim1 = *norbs;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    ab_dim1 = *minear;
    ab_offset = 1 + ab_dim1 * 1;
    ab -= ab_offset;
    b_dim1 = *minear;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    f_dim1 = *minear;
    f_offset = 1 + f_dim1 * 1;
    f -= f_offset;
    fci_dim1 = *ninear;
    fci_offset = 1 + fci_dim1 * 1;
    fci -= fci_offset;
    fd_dim1 = *ninear;
    fd_offset = 1 + fd_dim1 * 1;
    fd -= fd_offset;
    fb_dim1 = *nvar;
    fb_offset = 1 + fb_dim1 * 1;
    fb -= fb_offset;
    --grad;

    /* Function Body */

/*     * * * STEP 1 * * * */
/*     BUILD UP THE INITIAL ORTHONORMALIZED BASIS. */

    if (icalcn != numcal_1.numcal) {
	debug = i_indx(keywrd_1.keywrd, " DERI2", (ftnlen)241, (ftnlen)6) != 
		0;
	icalcn = numcal_1.numcal;
/* Computing MIN */
	i__1 = 60, i__2 = (integer) sqrt(pow_dd(&c_b3, &c_b4)), i__1 = min(
		i__1,i__2), i__2 = 90300 / *nvar;
	maxite = min(i__1,i__2);
/* Computing MIN */
	i__1 = maxite, i__2 = min(*nw2,*nw3) / max(*minear,*ninear);
	maxite = min(i__1,i__2);
/* Computing MIN */
	i__1 = *nvar, i__2 = maxite / 4 + 1;
	nfirst = min(i__1,i__2);
    }
    fail = FALSE_;
    nbsize = 0;
    time1 = second_();

/*        NORMAL CASE. USE F ONLY. */

    deri21_(&f[f_offset], nvar, minear, &nfirst, &work[work_offset], &work[*
	    nvar * *nvar + 1 + work_dim1], &b[b_offset], &nlast);
    lbab = FALSE_;
    nfirst = nbsize + 1;
    nlast = nbsize + nlast;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	lconv[i__ - 1] = FALSE_;
    }

/*     * * * STEP 2 * * * */
/*     RELAXATION METHOD WITH OPTIMUM INCREASE OF THE BASIS SET. */
/*     --------------------------------------------------------- */

/*     UPDATE AB ,FCI AND BAB. (BAB IS SYMMETRIC) */
L20:
    i__1 = nlast;
    for (j = nfirst; j <= i__1; ++j) {
	deri22_(&c__[c_offset], &b[j * b_dim1 + 1], &work[work_offset], norbs,
		 &work[work_offset], &ab[j * ab_dim1 + 1], minear, &fci[j * 
		fci_dim1 + 1]);
	mxm_(&ab[j * ab_dim1 + 1], &c__1, &b[b_offset], minear, &work2_1.bab[
		j * 60 - 60], &nlast);
	i__2 = nfirst - 1;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L30: */
	    work2_1.bab[j + i__ * 60 - 61] = work2_1.bab[i__ + j * 60 - 61];
	}
    }
/*     INVERT BAB, STORE IN BABINV. */
L40:
    l = 0;
    i__2 = nlast;
    for (j = 1; j <= i__2; ++j) {
	i__1 = nlast;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ++l;
/* L50: */
	    civect_1.babinv[l - 1] = work2_1.bab[i__ + j * 60 - 61];
	}
    }
    osinv_(civect_1.babinv, &nlast, &deter);
    if (deter == 0.) {
	if (nlast != 1) {
	    s_wsfe(&io___15);
	    do_fio(&c__1, (char *)&nlast, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	lbab = TRUE_;
	--nlast;
	goto L40;
    }
    if (! lbab) {
/*        UPDATE F * B' */
	i__1 = nlast - nfirst + 1;
	mtxm_(&f[f_offset], nvar, &b[nfirst * b_dim1 + 1], minear, &fb[nfirst 
		* fb_dim1 + 1], &i__1);
    }
/*     NEW SOLUTIONS IN BASIS B , STORED IN BCOEF(NVAR,*). */
/*     BCOEF = BABINV * FB' */
    if (nlast != 0) {
	mxmt_(civect_1.babinv, &nlast, &fb[fb_offset], &nlast, civect_1.bcoef,
		 nvar);
    }
    if (lbab) {
	goto L90;
    }

/*     SELECT THE NEXT BASIS VECTOR AS THE LARGEST RESIDUAL VECTOR. */
/*     AND TEST FOR CONVERGENCE ON THE LARGEST RESIDUE. */
    nres = 0;
    test2 = 0.;
    i__1 = *nvar;
    for (ivar = 1; ivar <= i__1; ++ivar) {
	if (lconv[ivar - 1]) {
	    goto L70;
	}
/*     GET ONE NOT-CONVERGED RESIDUAL VECTOR (# IVAR), */
/*     STORED IN WORK. */
	mxm_(&ab[ab_offset], minear, &civect_1.bcoef[nlast * (ivar - 1)], &
		nlast, &work[work_offset], &c__1);
	test = 0.;
	i__2 = *minear;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    work[i__ + work_dim1] = f[i__ + ivar * f_dim1] - work[i__ + 
		    work_dim1];
/* L60: */
/* Computing MAX */
	    d__2 = (d__1 = work[i__ + work_dim1], abs(d__1));
	    test = max(d__2,test);
	}
	if (debug) {
	    s_wsle(&io___20);
	    do_lio(&c__9, &c__1, " TEST:", (ftnlen)6);
	    do_lio(&c__5, &c__1, (char *)&test, (ftnlen)sizeof(doublereal));
	    e_wsle();
	}
	test2 = max(test2,test);
	if (test <= *throld) {
	    lconv[ivar - 1] = TRUE_;
	    if (*nvar == 1) {
		goto L90;
	    }
	    goto L70;
	} else if (nlast + nres == maxite - 1) {
/*        RUNNING OUT OF STORAGE */
/* Computing MAX */
	    d__1 = .01, d__2 = *throld * 2;
	    if (test <= max(d__1,d__2)) {
		lconv[ivar - 1] = TRUE_;
		goto L70;
	    }
	} else if (nlast + nres == maxite) {

/*   COMPLETELY OUT OF STORAGE */

	    fail = nres == 0;
	    goto L80;
	} else {
/*        STORE THE FOLLOWING RESIDUE IN AB(CONTINUED). */
	    ++nres;
	    scopy_(minear, &work[work_offset], &c__1, &ab[(nlast + nres) * 
		    ab_dim1 + 1], &c__1);
	}
L70:
	;
    }
L80:
    if (nres == 0) {
	goto L90;
    }
/*     FIND OPTIMUM FOLLOWING SUBSET, ADD TO B AND LOOP. */
    nfirst = nlast + 1;
    deri21_(&ab[nfirst * ab_dim1 + 1], &nres, minear, &nres, &work[
	    work_offset], &work[nres * nres + 1 + work_dim1], &b[nfirst * 
	    b_dim1 + 1], &nadd);
    nlast += nadd;
    goto L20;

/*     CONVERGENCE ACHIEVED OR HALTED. */
/*     ------------------------------- */

L90:
    nbsze = nbsize;
    if (debug || lbab) {
	s_wsfe(&io___23);
	i__1 = nlast - nbsze;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*throld), (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&(*nvar), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&test2, (ftnlen)sizeof(doublereal));
	e_wsfe();
	if (nlast - nbsze == 0) {
	    s_wsfe(&io___24);
	    do_fio(&c__1, " ANALYTIC C.I. DERIVATIVES DO NOT WORK FOR THIS S"
		    "YSTEM", (ftnlen)54);
	    e_wsfe();
	    s_wsfe(&io___25);
	    do_fio(&c__1, " ADD KEYWORD 'NOANCI' AND RESUBMIT", (ftnlen)34);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	time2 = second_();
	s_wsfe(&io___27);
	d__1 = time2 - time1;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (fail) {
	s_wsfe(&io___28);
	do_fio(&c__1, " ANALYTICAL DERIVATIVES TOO INACCURATE FOR THIS", (
		ftnlen)47);
	e_wsfe();
	s_wsfe(&io___29);
	do_fio(&c__1, " WORK.  JOB STOPPED HERE.  SEE MANUAL FOR IDEAS", (
		ftnlen)47);
	e_wsfe();
	s_stop("", (ftnlen)0);
    } else {
	nbsize = 0;
/*        UNSCALED SOLUTION SUPERVECTORS, STORED IN F. */
	if (nlast != 0) {
	    mxm_(&b[b_offset], minear, civect_1.bcoef, &nlast, &f[f_offset], 
		    nvar);
	}
	i__1 = *nvar;
	for (j = 1; j <= i__1; ++j) {
	    i__2 = *minear;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L100: */
		f[i__ + j * f_dim1] *= fokmat_1.scalar[i__ - 1];
	    }
	}
/*        FOCK MATRIX DIAGONAL BLOCKS OVER C.I-ACTIVE M.O. */
/*        STORED IN FB. */
	if (nlast != 0) {
	    mxm_(&fci[fci_offset], ninear, civect_1.bcoef, &nlast, &fb[
		    fb_offset], nvar);
	}
    }

/*     * * * STEP 3 * * * */
/*     FINAL LOOP (390) ON THE GEOMETRIC VARIABLES. */
/*     -------------------------------------------- */

    i__2 = *nvar;
    for (ivar = 1; ivar <= i__2; ++ivar) {

/*     C.I-ACTIVE M.O DERIVATIVES INTO THE M.O BASIS, */
/*         RETURNED IN AB (N,NELEC+1,...,NELEC+NMOS). */
/*     C.I-ACTIVE EIGENVALUES DERIVATIVES, */
/*         RETURNED IN BCOEF(NELEC+1,...,NELEC+NMOS). */
	deri23_(&f[ivar * f_dim1 + 1], &fd[ivar * fd_dim1 + 1], &e[1], &fb[*
		ninear * (ivar - 1) + 1 + fb_dim1], &ab[ab_offset], 
		civect_1.bcoef, norbs);

/*     DERIVATIVES OF THE 2-ELECTRONS INTEGRALS OVER C.I-ACTIVE M.O. */
/*     STORED IN /XYIJKL/. */
	dijkl2_(&ab[*norbs * cibits_1.nelec + 1 + ab_dim1], norbs, &
		cibits_1.nmos, work3_1.dijkl, xyijkl_1.xy, &c__8);
	if (debug) {
	    s_wsfe(&io___30);
	    do_fio(&c__1, (char *)&ivar, (ftnlen)sizeof(integer));
	    e_wsfe();
	    if (i_indx(keywrd_1.keywrd, "DEBU", (ftnlen)241, (ftnlen)4) != 0) 
		    {
		s_wsfe(&io___31);
		e_wsfe();
		l = *norbs * cibits_1.nelec + 1;
		i__1 = cibits_1.nelec + cibits_1.nmos;
		for (i__ = cibits_1.nelec + 1; i__ <= i__1; ++i__) {
		    s_wsfe(&io___32);
		    i__3 = l + *norbs - 1;
		    for (k = l; k <= i__3; ++k) {
			do_fio(&c__1, (char *)&ab[k + ab_dim1], (ftnlen)
				sizeof(doublereal));
		    }
		    e_wsfe();
/* L110: */
		    l += *norbs;
		}
	    }
	    s_wsfe(&io___34);
	    e_wsfe();
	    s_wsfe(&io___35);
	    i__1 = cibits_1.nelec + cibits_1.nmos;
	    for (i__ = cibits_1.nelec + 1; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&civect_1.bcoef[i__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___36);
	    e_wsfe();
	    i__1 = cibits_1.nmos;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		i__3 = i__;
		for (j = 1; j <= i__3; ++j) {
		    i__4 = i__;
		    for (k = 1; k <= i__4; ++k) {
			ll = k;
			if (k == i__) {
			    ll = j;
			}
			i__5 = ll;
			for (l = 1; l <= i__5; ++l) {
/* L120: */
			    s_wsfe(&io___38);
			    i__6 = cibits_1.nelec + i__;
			    do_fio(&c__1, (char *)&i__6, (ftnlen)sizeof(
				    integer));
			    i__7 = cibits_1.nelec + j;
			    do_fio(&c__1, (char *)&i__7, (ftnlen)sizeof(
				    integer));
			    i__8 = cibits_1.nelec + k;
			    do_fio(&c__1, (char *)&i__8, (ftnlen)sizeof(
				    integer));
			    i__9 = cibits_1.nelec + l;
			    do_fio(&c__1, (char *)&i__9, (ftnlen)sizeof(
				    integer));
			    do_fio(&c__1, (char *)&xyijkl_1.xy[i__ + (j + (k 
				    + (l << 3) << 3) << 3) - 585], (ftnlen)
				    sizeof(doublereal));
			    e_wsfe();
			}
		    }
		}
	    }
	}

/*     BUILD THE C.I MATRIX DERIVATIVE, STORED IN AB. */
	mecid_(civect_1.bcoef, &gse, &work[cibits_1.lab + 1 + work_dim1], &
		work[work_offset]);
	mecih_(&work[work_offset], &ab[ab_offset], &cibits_1.nmos, &
		cibits_1.lab);
/*     RELAXATION CORRECTION TO THE C.I ENERGY DERIVATIVE. */
	supdot_(&work[work_offset], &ab[ab_offset], civect_1.vectci, &
		cibits_1.lab, &c__1);
	grad[ivar] += dot_(civect_1.vectci, &work[work_offset], &cibits_1.lab)
		 * 23.061;
	if (debug) {
	    s_wsfe(&io___40);
	    d__1 = dot_(civect_1.vectci, &work[work_offset], &cibits_1.lab) * 
		    23.061;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

/*     THE END . */
/* L130: */
    }
    if (debug) {
	s_wsfe(&io___41);
	d__1 = second_() - time2;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* deri2_ */

