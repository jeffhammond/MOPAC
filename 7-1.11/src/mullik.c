/* mullik.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbx, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* Subroutine */ int mullik_(doublereal *c__, doublereal *h__, doublereal *f, 
	integer *norbs, doublereal *vecs, doublereal *store)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    char ch__1[80];
    olist o__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer f_open(olist *), s_wsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wsue(void);

    /* Local variables */
    static integer i__, j, k;
    static doublereal bi, bj;
    static integer if__, jf, ii, ij, jj, il, jl, im1;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sum, xyz[360]	/* was [3][120] */, eigs[300];
    extern /* Subroutine */ int mult_(doublereal *, doublereal *, doublereal *
	    , integer *);
    static doublereal summ;
    static integer ifact[300];
    static logical graph;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer linear;
    extern /* Subroutine */ int densit_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, integer *), 
	    vecprt_(doublereal *, integer *), gmetry_(doublereal *, 
	    doublereal *);

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 13, 0, 0, 0 };
    static cilist io___20 = { 0, 13, 0, 0, 0 };
    static cilist io___21 = { 0, 13, 0, 0, 0 };
    static cilist io___23 = { 0, 13, 0, 0, 0 };
    static cilist io___24 = { 0, 13, 0, 0, 0 };


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

/*  MULLIK DOES A MULLIKEN POPULATION ANALYSIS */
/* ON INPUT     C      =  SQUARE ARRAY OF EIGENVECTORS. */
/*              H      =  PACKED ARRAY OF ONE-ELECTRON MATRIX */
/*              F      =  WORKSTORE OF SIZE AT LEAST NORBS*NORBS */
/*              VECS   =  WORKSTORE OF SIZE AT LEAST NORBS*NORBS */
/*              STORE  =  WORKSTORE OF SIZE AT LEAST (NORBS*(NORBS+1))/2 */

/* ********************************************************************* */
/* ********************************************************************* */

/*  FIRST, RE-CALCULATE THE OVERLAP MATRIX */

/* ********************************************************************* */
    /* Parameter adjustments */
    --store;
    --vecs;
    --f;
    --h__;
    --c__;

    /* Function Body */
    graph = i_indx(keywrd_1.keywrd, "GRAPH", (ftnlen)241, (ftnlen)5) != 0;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	ifact[i__ - 1] = i__ * (i__ - 1) / 2;
    }
    ifact[*norbs] = *norbs * (*norbs + 1) / 2;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if__ = molkst_1.nfirst[i__ - 1];
	il = molkst_1.nlast[i__ - 1];
	im1 = i__ - 1;
	bi = betas_1.betas[molkst_1.nat[i__ - 1] - 1];
	i__2 = il;
	for (k = if__; k <= i__2; ++k) {
	    ii = k * (k - 1) / 2;
	    i__3 = im1;
	    for (j = 1; j <= i__3; ++j) {
		jf = molkst_1.nfirst[j - 1];
		jl = molkst_1.nlast[j - 1];
		bj = betas_1.betas[molkst_1.nat[j - 1] - 1];
		i__4 = jl;
		for (jj = jf; jj <= i__4; ++jj) {
		    ij = ii + jj;
		    h__[ij] = h__[ij] * 2. / (bi + bj) + 1e-14;
/*  THE  +1.D-14 IS TO PREVENT POSSIBLE ERRORS IN THE DIAGONALIZATION. */
		    store[ij] = h__[ij];
/* L20: */
		    bj = betas_1.betap[molkst_1.nat[j - 1] - 1];
		}
/* L30: */
	    }
	    i__3 = k;
	    for (jj = if__; jj <= i__3; ++jj) {
		ij = ii + jj;
		store[ij] = 0.;
/* L40: */
		h__[ij] = 0.;
	    }
/* L50: */
	    bi = betas_1.betap[molkst_1.nat[i__ - 1] - 1];
	}
    }
    i__2 = *norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	store[ifact[i__]] = 1.;
/* L60: */
	h__[ifact[i__]] = 1.;
    }
    rsp_(&h__[1], norbs, norbs, eigs, &vecs[1]);
    i__2 = *norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L70: */
	eigs[i__ - 1] = 1. / sqrt((d__1 = eigs[i__ - 1], abs(d__1)));
    }
    ij = 0;
    i__2 = *norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++ij;
	    sum = 0.;
	    i__3 = *norbs;
	    for (k = 1; k <= i__3; ++k) {
/* L80: */
		sum += vecs[i__ + (k - 1) * *norbs] * eigs[k - 1] * vecs[j + (
			k - 1) * *norbs];
	    }
	    f[i__ + (j - 1) * *norbs] = sum;
/* L90: */
	    f[j + (i__ - 1) * *norbs] = sum;
	}
    }
    if (graph) {
	gmetry_(geom_1.geo, xyz);

/* WRITE TO DISK THE FOLLOWING DATA FOR GRAPHICS CALCULATION, IN ORDER: */

/*      NUMBER OF ATOMS, ORBITAL, ELECTRONS */
/*      ALL ATOMIC COORDINATES */
/*      ORBITAL COUNTERS */
/*      ORBITAL EXPONENTS, S, P, AND D, AND ATOMIC NUMBERS */
/*      EIGENVECTORS (M.O.S NOT RE-NORMALIZED) */
/*      INVERSE-SQUARE ROOT OF THE OVERLAP MATRIX. */

	o__1.oerr = 1;
	o__1.ounit = 13;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR013", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	i__1 = f_open(&o__1);
	if (i__1 != 0) {
	    goto L31;
	}
	goto L32;
L31:
	o__1.oerr = 0;
	o__1.ounit = 13;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR013", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	f_open(&o__1);
L32:
	s_wsue(&io___19);
	do_uio(&c__1, (char *)&molkst_1.numat, (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*norbs), (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&molkst_1.nelecs, (ftnlen)sizeof(integer));
	for (i__ = 1; i__ <= 3; ++i__) {
	    i__1 = molkst_1.numat;
	    for (j = 1; j <= i__1; ++j) {
		do_uio(&c__1, (char *)&xyz[i__ + j * 3 - 4], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	s_wsue(&io___20);
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&molkst_1.nlast[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_uio(&c__1, (char *)&molkst_1.nfirst[i__ - 1], (ftnlen)sizeof(
		    integer));
	}
	e_wsue();
	s_wsue(&io___21);
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&expont_1.zs[molkst_1.nat[i__ - 1] - 1], (
		    ftnlen)sizeof(doublereal));
	}
	i__2 = molkst_1.numat;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&expont_1.zp[molkst_1.nat[i__ - 1] - 1], (
		    ftnlen)sizeof(doublereal));
	}
	i__3 = molkst_1.numat;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    do_uio(&c__1, (char *)&expont_1.zd[molkst_1.nat[i__ - 1] - 1], (
		    ftnlen)sizeof(doublereal));
	}
	i__4 = molkst_1.numat;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    do_uio(&c__1, (char *)&molkst_1.nat[i__ - 1], (ftnlen)sizeof(
		    integer));
	}
	e_wsue();
	linear = *norbs * *norbs;
	s_wsue(&io___23);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&c__[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	s_wsue(&io___24);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&f[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	if (i_indx(keywrd_1.keywrd, "MULLIK", (ftnlen)241, (ftnlen)6) == 0) {
	    return 0;
	}
    }

/* OTHERWISE PERFORM MULLIKEN ANALYSIS */

    mult_(&c__[1], &f[1], &vecs[1], norbs);
    i__ = -1;
    densit_(&vecs[1], norbs, norbs, &molkst_1.nclose, &molkst_1.nopen, &
	    molkst_1.fract, &c__[1], &c__2);
    linear = *norbs * (*norbs + 1) / 2;
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
	c__[i__] *= store[i__];
    }
    summ = 0.;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
/* L110: */
	    sum += c__[ifact[i__ - 1] + j];
	}
	i__2 = *norbs;
	for (j = i__ + 1; j <= i__2; ++j) {
/* L120: */
	    sum += c__[ifact[j - 1] + i__];
	}
	summ += sum;
/* L130: */
	c__[ifact[i__]] = sum;
    }
    vecprt_(&c__[1], norbs);
    return 0;
} /* mullik_ */

