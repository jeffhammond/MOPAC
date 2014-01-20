/* dernvo.f -- translated by f2c (version 20020621).
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
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal c__[90000], eigs[300], cbeta[90000], eigb[300];
} vector_;

#define vector_1 vector_

struct {
    doublereal fdumy[45150], scalar[45150];
} fokmat_;

#define fokmat_1 fokmat_

struct {
    doublereal diag[22575];
} nvomat_;

#define nvomat_1 nvomat_

struct {
    doublereal fmooff[180600], fmoon[180600], work2[406350], work3[180600];
} work1_;

#define work1_1 work1_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__0 = 0;

/* Subroutine */ int dernvo_(doublereal *coord, doublereal *dxyz)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void), s_wsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l, ll;
    static doublereal sum;
    static logical dcar;
    static doublereal fbwo[1800];
    static integer nvax;
    static doublereal sumx, sumy, sumz;
    extern /* Subroutine */ int deri0_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *), deri1_(doublereal *, 
	    integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *), deri2_(doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, doublereal *, doublereal *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *);
    static doublereal eigbb[2160];
    static char blank[60];
    static logical debug, large, force;
    static integer ilast;
    static doublereal dxyzr[360];
    static integer minear;
    static logical relaxd;
    static integer ninear;
    static doublereal throld;
    static integer ifirst;

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 6, 0, 0, 0 };
    static cilist io___19 = { 0, 6, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, "(7X,I3,5I12)", 0 };
    static cilist io___21 = { 0, 6, 0, "(I3,6F12.6)", 0 };
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 6, 0, "(7X,I3,5I12)", 0 };
    static cilist io___24 = { 0, 6, 0, "(I3,6F12.6)", 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static cilist io___26 = { 0, 6, 0, "(7X,I3,4I12)", 0 };
    static cilist io___27 = { 0, 6, 0, "(I3,6F12.6)", 0 };
    static cilist io___28 = { 0, 6, 0, 0, 0 };
    static cilist io___32 = { 0, 6, 0, "(A,5F12.6)", 0 };
    static cilist io___38 = { 0, 6, 0, 0, 0 };
    static cilist io___39 = { 0, 6, 0, "(' ATOM    X           Y           Z"
	    "')", 0 };
    static cilist io___40 = { 0, 6, 0, "(I4,3F12.7)", 0 };
    static cilist io___41 = { 0, 6, 0, "(/10X,'RESIDUAL ERROR')", 0 };
    static cilist io___42 = { 0, 6, 0, "(4X,3F12.7)", 0 };
    static cilist io___43 = { 0, 6, 0, 0, 0 };
    static cilist io___44 = { 0, 6, 0, 0, 0 };
    static cilist io___45 = { 0, 6, 0, "(' ATOM    X           Y           Z"
	    "')", 0 };
    static cilist io___46 = { 0, 6, 0, "(I4,3F12.7)", 0 };
    static cilist io___47 = { 0, 6, 0, "(/10X,'RESIDUAL ERROR')", 0 };
    static cilist io___48 = { 0, 6, 0, "(4X,3F12.7)", 0 };
    static cilist io___49 = { 0, 6, 0, 0, 0 };
    static cilist io___50 = { 0, 6, 0, 0, 0 };
    static cilist io___51 = { 0, 6, 0, "(' ATOM    X           Y           Z"
	    "')", 0 };
    static cilist io___52 = { 0, 6, 0, "(I4,3F12.7)", 0 };
    static cilist io___53 = { 0, 6, 0, "(/10X,'RESIDUAL ERROR')", 0 };
    static cilist io___54 = { 0, 6, 0, "(4X,3F12.7)", 0 };
    static cilist io___55 = { 0, 6, 0, 0, 0 };


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

/*    IMPLEMENTATION OF ANALYTICAL FORMULATION FOR OPEN SHELL OR CI, */
/*                      VARIABLES FINITE DIFFERENCE METHODS, */
/*                      STATISTICAL ESTIMATE OF THE ERRORS, */
/*                   BY D. LIOTARD */
/*                      LABORATOIRE DE CHIMIE STRUCTURALE */
/*                      UNIVERSITE DE PAU ET DES PAYS DE L'ADOUR */
/*                      AVENUE DE L'UNIVERSITE, 64000, PAU (FRANCE) */


/*   MODIFIED BY JJPS TO CONFORM TO MOPAC CONVENTIONS */
/*   (NOTE BY JJPS:  PROF. LIOTARD'S TECHNIQUE WORKS.  IF THIS */
/*   IMPLEMENTATION DOES NOT WORK, THE REASON IS A FAULT INTRODUCED */
/*   BY JJPS, AND DOES NOT REFLECT ON PROF. LIOTARD'S ABILITY) */


/*    AS THE WAVE FUNCTION IS NOT VARIATIONALLY OPTIMIZED, I.E. */
/*    HALF-ELECTRON OR CI, THE DERIVATIVES OF THE 1 AND 2-ELECTRON */
/*    INTEGRALS IN A.O. BASIS ARE EVALUATED IN CARTESIAN COORDINATES */
/*    BY A 1 OR 2 POINTS FINITE DIFFERENCE FORMULA AND STORED. */
/*    THUS ONE GETS THE NON-RELAXED (I.E. FROZEN ELECTRONIC CLOUD) */
/*    CONTRIBUTION TO THE FOCK EIGENVALUES AND 2-ELECTRON INTEGRALS IN */
/*    AN M.O. BASIS.  THE NON-RELAXED GRADIENT COMES FROM THE */
/*    NON-RELAXED C.I. MATRIX DERIVATIVE (SUBROUTINE DERI1). */
/*    THE DERIVATIVES OF THE M.O. COEFFICIENTS ARE THEN WORKED OUT */
/*    ITERATIVELY (OK FOR BOTH CLOSED SHELLS AND HALF-ELECTRON CASES) */
/*    AND STORED. THUS ONE GETS THE ELECTRONIC RELAXATION CONTRIBUTION TO */
/*    THE FOCK EIGENVALUES AND 2-ELECTRON INTEGRALS IN M.O. BASIS. */
/*    FINALLY THE RELAXATION CONTRIBUTION TO THE C.I. MATRIX DERIVATIVE */
/*    GIVES THE RELAXATION CONTRIBUTION TO THE GRADIENT (ROUTINE DERI2). */


/*        COORD  HOLDS THE CARTESIAN COORDINATES. */
/*    INPUT */
/*        DXYZ   NOT DEFINED. */
/*    EXIT */
/*        DXYZ   DERIVATIVES OF ENERGY W.R.T CARTESIAN COORDINATES, */
/*               IN KCAL/MOL/ANGSTROM (3 * NUMAT OF THESE) */

/* ********************************************************************** */

/*    NW2 and NW3 should be set to *something*, probably sizes of WORK2 */
/*    and WORK3 arrays? Since the code works with NW2 and NW3 set to zero */
/*    by implicit initialization, we can as well do it explicitly.... -P.S. */

    /* Parameter adjustments */
    --dxyz;
    coord -= 4;

    /* Function Body */

/*     SELECT THE REQUIRED OPTION AND READ KEYWORDS */
/*     -------------------------------------------- */

    if (icalcn != numcal_1.numcal) {
	throld = .08;
	debug = i_indx(keywrd_1.keywrd, "DERNVO", (ftnlen)241, (ftnlen)6) != 
		0;
	large = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5) != 0;
	force = i_indx(keywrd_1.keywrd, "FORC", (ftnlen)241, (ftnlen)4) != 0;
	dcar = i_indx(keywrd_1.keywrd, "FORC", (ftnlen)241, (ftnlen)4) + 
		i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0;
	if (dcar) {
	    throld = .004;
	}
	i__1 = nvax;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L11: */
	    dxyzr[i__ - 1] = 0.;
	}
/*        ACTUAL SIZES FOR C.I. GRADIENT CALCULATION. */
	cibits_1.nbo[0] = molkst_1.nclose;
	cibits_1.nbo[1] = molkst_1.nopen - molkst_1.nclose;
	cibits_1.nbo[2] = molkst_1.norbs - molkst_1.nopen;
	minear = cibits_1.nbo[1] * cibits_1.nbo[0] + cibits_1.nbo[2] * 
		molkst_1.nopen;
	ninear = cibits_1.nmos * (cibits_1.nmos + 1) / 2 + 1;
	icalcn = numcal_1.numcal;
    }
/*        SCALING ROW FACTORS TO SPEED CV OF RELAXATION PROCEDURE. */
/* #      CALL TIMER('BEFORE DERI0') */
    deri0_(vector_1.eigs, &molkst_1.norbs, fokmat_1.scalar, nvomat_1.diag, &
	    molkst_1.fract, cibits_1.nbo);
/* #      CALL TIMER('AFTER DERI0') */
    nvax = molkst_1.numat * 3;

/*   BECAUSE DERI2 IS CPU INTENSIVE, AND THE CONTRIBUTION TO THE */
/*   DERVIATIVE DUE TO RELAXATION OF THE ELECTRON CLOUD IS RELATIVELY */
/*   INSENSITIVE TO CHANGES IN GEOMETRY, WHERE POSSIBLE ONLY CALCULATE */
/*   THE DERIVATIVE EVERY 2 CALLS TO DERNVO */

    sum = 0.;
    if (dcar) {
	i__1 = nvax;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	    dxyzr[i__ - 1] = 0.;
	}
	relaxd = FALSE_;
    }
    i__1 = nvax;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	sum += (d__1 = dxyzr[i__ - 1], abs(d__1));
    }
    relaxd = sum > 1e-7;

/*  IF DXYZR CONTAINS DATA, USE IT AND FLUSH AFTER USE. */

    ilast = 0;
L30:
    ifirst = ilast + 1;
    j = 2;
    if (0 / max(minear,ninear) < 10) {
	j = 1;
    }
/* Computing MIN */
    i__1 = nvax, i__2 = ilast + j;
    ilast = min(i__1,i__2);
    j = 1 - minear;
    k = 1 - ninear;
    i__1 = ilast;
    for (i__ = ifirst; i__ <= i__1; ++i__) {
	k += ninear;
	j += minear;

/*        NON-RELAXED CONTRIBUTION (FROZEN ELECTRONIC CLOUD) IN DXYZ */
/*        AND NON-RELAXED FOCK MATRICES IN FMOOFF AND FMOON. */
/*   CONTENTS OF F-MO-OFF: OPEN-CLOSED, VIRTUAL-CLOSED, AND VIRTUAL-OPEN */
/*   CONTENTS OF F-MO-ON:  CLOSED-CLOSED, OPEN-OPEN AND VIRTUAL-VIRTUAL */
/*   OVER M.O. INDICES */

/* #      CALL TIMER('BEFORE DERI1') */
	deri1_(vector_1.c__, &molkst_1.norbs, &coord[4], &i__, vector_1.cbeta,
		 &dxyz[i__], &work1_1.fmooff[j - 1], &minear, &work1_1.fmoon[
		k - 1], work1_1.work2, &work1_1.work2[270899], work1_1.work3);
/* #      CALL TIMER('AFTER DERI1') */
/* L40: */
    }
    if (debug) {
	if (ifirst == 1 && large) {
	    s_wsle(&io___18);
	    do_lio(&c__9, &c__1, " CONTENTS OF FMOOFF ", (ftnlen)20);
	    e_wsle();
	    s_wsle(&io___19);
	    do_lio(&c__9, &c__1, " OPEN-CLOSED", (ftnlen)12);
	    e_wsle();
	    s_wsfe(&io___20);
	    i__1 = molkst_1.nopen;
	    for (j = molkst_1.nclose + 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	    i__1 = molkst_1.nclose;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
		s_wsfe(&io___21);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		i__2 = i__ * cibits_1.nbo[1];
		for (j = (i__ - 1) * cibits_1.nbo[1] + 1; j <= i__2; ++j) {
		    do_fio(&c__1, (char *)&work1_1.fmooff[j - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
	    }


	    s_wsle(&io___22);
	    do_lio(&c__9, &c__1, " VIRTUAL-CLOSED", (ftnlen)15);
	    e_wsle();
	    k = molkst_1.nclose * cibits_1.nbo[1];
	    s_wsfe(&io___23);
/* Computing MIN */
	    i__1 = molkst_1.nopen + 6;
	    i__2 = min(i__1,molkst_1.norbs);
	    for (j = molkst_1.nopen + 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	    i__1 = molkst_1.nclose;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
		s_wsfe(&io___24);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
/* Computing MIN */
		i__3 = (i__ - 1) * cibits_1.nbo[2] + 6, i__4 = i__ * 
			cibits_1.nbo[2];
		i__2 = min(i__3,i__4);
		for (j = (i__ - 1) * cibits_1.nbo[2] + 1; j <= i__2; ++j) {
		    do_fio(&c__1, (char *)&work1_1.fmooff[j + k - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
	    }
	    k = molkst_1.nclose * cibits_1.nbo[1] + cibits_1.nbo[2] * 
		    molkst_1.nclose;


	    s_wsle(&io___25);
	    do_lio(&c__9, &c__1, " VIRTUAL-OPEN", (ftnlen)13);
	    e_wsle();
	    s_wsfe(&io___26);
	    i__3 = molkst_1.nopen;
	    for (j = molkst_1.nclose + 1; j <= i__3; ++j) {
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	    i__3 = min(6,cibits_1.nbo[2]);
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L70: */
		s_wsfe(&io___27);
		i__4 = i__ + molkst_1.nopen;
		do_fio(&c__1, (char *)&i__4, (ftnlen)sizeof(integer));
/* Computing MIN */
		i__1 = (i__ - 1) * cibits_1.nbo[1] + 6, i__5 = i__ * 
			cibits_1.nbo[1];
		i__2 = min(i__1,i__5);
		for (j = (i__ - 1) * cibits_1.nbo[1] + 1; j <= i__2; ++j) {
		    do_fio(&c__1, (char *)&work1_1.fmooff[j + k - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
	    }
	    s_wsle(&io___28);
	    do_lio(&c__9, &c__1, " CONTENTS OF FMOON (ACTIVE-SPACE -- ACTIVE"
		    " SPACE)", (ftnlen)49);
	    e_wsle();
	    k = cibits_1.nmos * (cibits_1.nmos - 1) / 2;
	    ll = 1;
	    s_copy(blank, " ", (ftnlen)60, (ftnlen)1);
	    i__4 = cibits_1.nmos;
	    for (i__ = 1; i__ <= i__4; ++i__) {
		l = ll + cibits_1.nmos - i__ - 1;
		s_wsfe(&io___32);
		do_fio(&c__1, blank, i__ * 12);
		i__1 = l;
		for (j = ll; j <= i__1; ++j) {
		    do_fio(&c__1, (char *)&work1_1.fmoon[j - 1], (ftnlen)
			    sizeof(doublereal));
		}
		do_fio(&c__1, (char *)&work1_1.fmoon[k + i__ - 1], (ftnlen)
			sizeof(doublereal));
		e_wsfe();
/* L80: */
		ll = l + 1;
	    }
	}
    }
/*        COMPUTE THE ELECTRONIC RELAXATION CONTRIBUTION. */

/*   DERNVO PROVIDES THE FOLLOWING SCRATCH AREAS TO DERI2: EIGB, WORK2, */
/*          WORK3, FBWO, CBETA.  THESE ARE DIMENSIONED ON ENTRY TO DERI2 */
/*          WHICH IS WHY THEY ARE NOT DECLARED THERE.  THEY ARE NOT USED */
/*          AT ALL IN DERNVO. */

/* #      CALL TIMER('BEFORE DERI2') */
    if (! relaxd) {
	i__4 = ilast - ifirst + 1;
	deri2_(vector_1.c__, vector_1.eigs, &molkst_1.norbs, &minear, 
		work1_1.fmooff, work1_1.fmoon, eigbb, &ninear, &i__4, 
		vector_1.cbeta, work1_1.work2, &c__0, &dxyzr[ifirst - 1], 
		work1_1.work3, &c__0, fbwo, &throld);
    }
/* #      CALL TIMER('AFTER DERI2') */
    if (ilast < nvax) {
	goto L30;
    }
    if (debug) {
	sumx = 0.;
	sumy = 0.;
	sumz = 0.;
	i__4 = molkst_1.numat;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    sumx += dxyz[i__ * 3 - 2];
	    sumy += dxyz[i__ * 3 - 1];
/* L90: */
	    sumz += dxyz[i__ * 3];
	}
	s_wsle(&io___38);
	do_lio(&c__9, &c__1, " CARTESIAN DERIVATIVES DUE TO FROZEN CORE", (
		ftnlen)41);
	e_wsle();
	s_wsfe(&io___39);
	e_wsfe();
	i__4 = molkst_1.numat;
	for (i__ = 1; i__ <= i__4; ++i__) {
/* L100: */
	    s_wsfe(&io___40);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&dxyz[i__ * 3 - 2], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&dxyz[i__ * 3 - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&dxyz[i__ * 3], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___41);
	e_wsfe();
	s_wsfe(&io___42);
	do_fio(&c__1, (char *)&sumx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sumy, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sumz, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsle(&io___43);
	e_wsle();
	sumx = 0.;
	sumy = 0.;
	sumz = 0.;
	i__4 = molkst_1.numat;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    sumx += dxyzr[i__ * 3 - 3];
	    sumy += dxyzr[i__ * 3 - 2];
/* L110: */
	    sumz += dxyzr[i__ * 3 - 1];
	}
	s_wsle(&io___44);
	do_lio(&c__9, &c__1, " CARTESIAN DERIVATIVES DUE TO RELAXING CORE", (
		ftnlen)43);
	e_wsle();
	s_wsfe(&io___45);
	e_wsfe();
	i__4 = molkst_1.numat;
	for (i__ = 1; i__ <= i__4; ++i__) {
/* L120: */
	    s_wsfe(&io___46);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&dxyzr[i__ * 3 - 3], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&dxyzr[i__ * 3 - 2], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&dxyzr[i__ * 3 - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___47);
	e_wsfe();
	s_wsfe(&io___48);
	do_fio(&c__1, (char *)&sumx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sumy, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sumz, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsle(&io___49);
	e_wsle();
    }
    i__4 = nvax;
    for (i__ = 1; i__ <= i__4; ++i__) {
/* L130: */
	dxyz[i__] += dxyzr[i__ - 1];
    }
    if (relaxd) {
	i__4 = nvax;
	for (i__ = 1; i__ <= i__4; ++i__) {
/* L140: */
	    dxyzr[i__ - 1] = 0.;
	}
    }
    sumx = 0.;
    sumy = 0.;
    sumz = 0.;
    i__4 = molkst_1.numat;
    for (i__ = 1; i__ <= i__4; ++i__) {
	sumx += dxyz[i__ * 3 - 2];
	sumy += dxyz[i__ * 3 - 1];
/* L150: */
	sumz += dxyz[i__ * 3];
    }
/* Computing MAX */
    d__1 = 1e-10, d__2 = abs(sumx) + abs(sumy) + abs(sumz);
    sum = max(d__1,d__2);

/*  HERE IS A ROUGH BUT SIMPLE METHOD FOR DEFINING THROLD FOR DERI2 */
/*  IT MAY NEED MORE WORK */

    if (! force && gradnt_1.gnorm > .001) {
	throld *= sqrt(gradnt_1.gnorm / (sum * 100.));
    }
/* Computing MIN */
    d__1 = 2., d__2 = max(.002,throld);
    throld = min(d__1,d__2);
    if (debug) {
	s_wsle(&io___50);
	do_lio(&c__9, &c__1, "CARTESIAN DERIVATIVES FROM ANALYTICAL C.I. CAL"
		"CULATION", (ftnlen)54);
	e_wsle();
	s_wsfe(&io___51);
	e_wsfe();
	i__4 = molkst_1.numat;
	for (i__ = 1; i__ <= i__4; ++i__) {
/* L160: */
	    s_wsfe(&io___52);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&dxyz[i__ * 3 - 2], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&dxyz[i__ * 3 - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&dxyz[i__ * 3], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___53);
	e_wsfe();
	s_wsfe(&io___54);
	do_fio(&c__1, (char *)&sumx, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sumy, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sumz, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsle(&io___55);
	e_wsle();
    }
    return 0;
} /* dernvo_ */

