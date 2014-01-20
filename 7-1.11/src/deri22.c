/* deri22.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbd, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal wj[214770], wk[214770];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    doublereal pdumy[90300], dpa[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal fdumy[45150], scalar[45150];
} fokmat_;

#define fokmat_1 fokmat_

struct {
    doublereal diag[22575];
} nvomat_;

#define nvomat_1 nvomat_

struct {
    doublereal fdumy2[677250], dp[270900];
} work1_;

#define work1_1 work1_

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int deri22_(doublereal *c__, doublereal *b, doublereal *work,
	 integer *norbs, doublereal *foc2, doublereal *ab, integer *minear, 
	doublereal *fci)
{
    /* System generated locals */
    integer c_dim1, c_offset, work_dim1, work_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, l;
#define w ((doublereal *)&wmatrx_1)
    static integer n1, n2;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);
    static integer nend;
    extern doublereal sdot_(integer *, doublereal *, integer *, doublereal *, 
	    integer *);
    static integer loop;
    extern /* Subroutine */ int mxmt_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *), mtxm_(doublereal *, integer *
	    , doublereal *, integer *, doublereal *, integer *), fock1_(
	    doublereal *, doublereal *, doublereal *, doublereal *), fock2_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *);
    static integer ninit, linear;
    extern /* Subroutine */ int supdot_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);

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
/*  1) BUILD THE 2-ELECTRON FOCK MATRIX DEPENDING ON B AS FOLLOWS : */
/*     DP = C * SCALE*B * C' ...  DP DENSITY MATRIX 'DERIVATIVE', */
/*     FOC2 = 0.5 * TRACE ( DP * (2<J>-<K>) ) DONE IN FOCK2 & FOCK1. */
/*  2) HALF-TRANSFORM ONTO M.O. BASIS : DPT =  FOC2 * C */
/*     AND COMPUTE DIAGONAL BLOCKS ELEMENTS OF C' * FOC2, EXTRACTING */
/*     IN FCI ELEMENTS OVER C.I-ACTIVE M.O ONLY. */
/*  3) COMPUTE SUPERVECTOR AB = (DIAG + A) * B DEFINED BY THE MATRIX : */
/*     AB(I,J)= ( DIAG(I,J)*B(I,J)+DPT(I,J) )*SCALAR(I,J)  WITH I.GT.J, */
/*     DIAG(I,J)=(EIGS(I)-EIGS(J))/(O(J)-O(I)) >0, O OCCUPANCY NUMBERS, */
/*     EIGS EIGENVALUES OF FOCK OPERATOR WITH EIGENVECTORS C IN A.O. */

/*   INPUT */
/* C(NORBS,NORBS)   : M.O. EIGENVECTORS (COLUMNWISE). */
/* B(*)             : B SUPERVECTOR PACKED BY OFF-DIAGONAL BLOCKS, SCALED */
/* WORK(*)          : WORK AREA OF SIZE N*N. */
/* NORBS            : NUMBER OF M.O.S */
/* NELEC,NMOS       : LAST FROZEN CORE M.O. , C.I-ACTIVE BAND LENGTH. */
/*           IN COMMON */
/* DIAG,SCALAR AS DEFINED IN 'DERI0'. */
/*   OUTPUT */
/* FOC2(*)       : 2-ELECTRON FOCK MATRIX, PACKED CANONICAL. */
/* AB(*)         : ANTISYMMETRIC MATRIX PACKED IN SUPERVECTOR FORM WITH */
/*                 THE CONSECUTIVE FOLLOWING BLOCKS: */
/*              1) OPEN-CLOSED  I.E. B(IJ)=B(I,J) WITH I OPEN & J CLOSED */
/*                 AND I RUNNING FASTER THAN J, */
/*              2) VIRTUAL-CLOSED SAME RULE OF ORDERING, */
/*              3) VIRTUAL-OPEN   SAME RULE OF ORDERING. */
/* FCI(*)        : FOCK DIAGONAL BLOCKS ELEMENTS OVER C.I-ACTIVE M.O. */
/*            FOC2 CAN BE EQUIVALENCED WITH WORK IN THE CALLING SEQUENCE. */
/* *********************************************************************** */

/*  NOTE: NORBS AND NORD ARE THE SAME ADDRESS.  THE NAME NORBD IS NOT */
/*        USED HERE. */

    /* Parameter adjustments */
    --b;
    work_dim1 = *norbs;
    work_offset = 1 + work_dim1 * 1;
    work -= work_offset;
    c_dim1 = *norbs;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    --foc2;
    --ab;
    --fci;

    /* Function Body */
    linear = *norbs * (*norbs + 1) / 2;

/*     DERIVATIVE OF THE DENSITY MATRIX IN DP (PACKED,CANONICAL). */
/*     ---------------------------------------------------------- */
/*     DP = C * B * C' . */

/*     STEP 0 : UNSCALE VECTOR B. */
    i__1 = *minear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	b[i__] *= fokmat_1.scalar[i__ - 1];
    }

/*     STEP 1 : WORK = C * B    .  DP TEMPORARY ARRAY. */
    l = 1;
    if (cibits_1.nbo[1] != 0 && cibits_1.nbo[0] != 0) {
/*        OPEN-CLOSED */
	mxm_(&c__[(cibits_1.nbo[0] + 1) * c_dim1 + 1], norbs, &b[l], &
		cibits_1.nbo[1], &work[work_offset], cibits_1.nbo);
/* 	 CLOSED-OPEN */
	mxmt_(&c__[c_offset], norbs, &b[l], cibits_1.nbo, &work[(cibits_1.nbo[
		0] + 1) * work_dim1 + 1], &cibits_1.nbo[1]);
	l += cibits_1.nbo[1] * cibits_1.nbo[0];
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[0] != 0) {
/* 	 VIRTUAL-CLOSED */
	if (l > 1) {
	    mxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], norbs, &b[l], &
		    cibits_1.nbo[2], work1_1.dp, cibits_1.nbo);
	    i__1 = *norbs * cibits_1.nbo[0];
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
		work[i__ + work_dim1] += work1_1.dp[i__ - 1];
	    }
	} else {
	    mxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], norbs, &b[l], &
		    cibits_1.nbo[2], &work[work_offset], cibits_1.nbo);
	}
/* 	 CLOSED-VIRTUAL */
	mxmt_(&c__[c_offset], norbs, &b[l], cibits_1.nbo, &work[(
		molkst_1.nopen + 1) * work_dim1 + 1], &cibits_1.nbo[2]);
	l += cibits_1.nbo[2] * cibits_1.nbo[0];
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[1] != 0) {
/* 	 VIRTUAL-OPEN */
	mxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], norbs, &b[l], &
		cibits_1.nbo[2], work1_1.dp, &cibits_1.nbo[1]);
	j = *norbs * cibits_1.nbo[0];
	i__1 = *norbs * cibits_1.nbo[1];
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	    work[j + i__ + work_dim1] += work1_1.dp[i__ - 1];
	}
/* 	 OPEN-VIRTUAL */
	mxmt_(&c__[(cibits_1.nbo[0] + 1) * c_dim1 + 1], norbs, &b[l], &
		cibits_1.nbo[1], work1_1.dp, &cibits_1.nbo[2]);
	j = *norbs * molkst_1.nopen;
	i__1 = *norbs * cibits_1.nbo[2];
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	    work[j + i__ + work_dim1] += work1_1.dp[i__ - 1];
	}
    }

/*     STEP 2 : DP= WORK * C'   WITH DP PACKED,CANONICAL. */
    l = 0;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
/* L50: */
	    work1_1.dp[l - 1] = sdot_(norbs, &work[i__ + work_dim1], norbs, &
		    c__[j + c_dim1], norbs);
	}
    }

/*     2-ELECTRON FOCK MATRIX BUILD WITH THE DENSITY MATRIX DERIVATIVE. */
/*     ---------------------------------------------------------------- */
/*     RETURNED IN FOC2 (PACKED CANONICAL). */
    i__2 = linear;
    for (i__ = 1; i__ <= i__2; ++i__) {
	foc2[i__] = 0.;
/* L60: */
	densty_1.dpa[i__ - 1] = work1_1.dp[i__ - 1] * .5;
    }
    fock2_(&foc2[1], work1_1.dp, densty_1.dpa, w, wmatrx_1.wj, wmatrx_1.wk, &
	    molkst_1.numat, molkst_1.nat, molkst_1.nfirst, molkst_1.nmidle, 
	    molkst_1.nlast);
    fock1_(&foc2[1], work1_1.dp, densty_1.dpa, densty_1.dpa);

/*     BUILD DP AND EXTRACT FCI. */
/*     -------------------------- */

/*     DP(NORBS,NEND) = FOC2(NORBS,NORBS) * C(NORBS,NEND). */
/* Computing MAX */
    i__2 = molkst_1.nopen, i__1 = cibits_1.nelec + cibits_1.nmos;
    nend = max(i__2,i__1);
    l = 1;
    i__2 = molkst_1.nopen;
    for (i__ = 1; i__ <= i__2; ++i__) {
	supdot_(&work1_1.dp[l - 1], &foc2[1], &c__[i__ * c_dim1 + 1], norbs, &
		c__1);
/* L70: */
	l += *norbs;
    }
/*     EXTRACT FCI */
    l = 1;
    nend = 0;
    for (loop = 1; loop <= 3; ++loop) {
	ninit = nend + 1;
	nend += cibits_1.nbo[loop - 1];
/* Computing MAX */
	i__2 = ninit, i__1 = cibits_1.nelec + 1;
	n1 = max(i__2,i__1);
/* Computing MIN */
	i__2 = nend, i__1 = cibits_1.nelec + cibits_1.nmos;
	n2 = min(i__2,i__1);
	if (n2 < n1) {
	    goto L90;
	}
	i__2 = n2;
	for (i__ = n1; i__ <= i__2; ++i__) {
	    if (i__ > ninit) {
		i__1 = i__ - ninit;
		mxm_(&c__[i__ * c_dim1 + 1], &c__1, &work1_1.dp[*norbs * (
			ninit - 1)], norbs, &fci[l], &i__1);
		l = l + i__ - ninit;
	    }
/* L80: */
	}
L90:
	;
    }
    i__2 = cibits_1.nelec + cibits_1.nmos;
    for (i__ = cibits_1.nelec + 1; i__ <= i__2; ++i__) {
	fci[l] = -dot_(&c__[i__ * c_dim1 + 1], &work1_1.dp[*norbs * (i__ - 1)]
		, norbs);
/* L100: */
	++l;
    }

/*     NEW SUPERVECTOR AB = (DIAG + C'* FOC2 * C) * B , SCALED. */
/*     -------------------------------------------------------- */

/*     PART 1 : AB(I,J) = (C' * DP)(I,J) DONE BY BLOCKS. */
    l = 1;
    if (cibits_1.nbo[1] != 0 && cibits_1.nbo[0] != 0) {
	mtxm_(&c__[(cibits_1.nbo[0] + 1) * c_dim1 + 1], &cibits_1.nbo[1], 
		work1_1.dp, norbs, &ab[l], cibits_1.nbo);
	l += cibits_1.nbo[1] * cibits_1.nbo[0];
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[0] != 0) {
	mtxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], &cibits_1.nbo[2], 
		work1_1.dp, norbs, &ab[l], cibits_1.nbo);
	l += cibits_1.nbo[2] * cibits_1.nbo[0];
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[1] != 0) {
	mtxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], &cibits_1.nbo[2], &
		work1_1.dp[*norbs * cibits_1.nbo[0]], norbs, &ab[l], &
		cibits_1.nbo[1]);
    }

/*     PART 2 : AB = SCALE * (D * B + AB) AND RESCALE BASIS VECTOR B. */
    i__2 = *minear;
    for (i__ = 1; i__ <= i__2; ++i__) {
	ab[i__] = (nvomat_1.diag[i__ - 1] * b[i__] + ab[i__]) * 
		fokmat_1.scalar[i__ - 1];
/* L110: */
	b[i__] /= fokmat_1.scalar[i__ - 1];
    }
    return 0;
} /* deri22_ */

#undef w


