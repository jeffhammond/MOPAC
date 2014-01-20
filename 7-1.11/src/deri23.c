/* deri23.f -- translated by f2c (version 20020621).
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
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    integer ndumy[488];
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int deri23_(doublereal *f, doublereal *fd, doublereal *e, 
	doublereal *fci, doublereal *cmo, doublereal *emo, integer *norbs)
{
    /* System generated locals */
    integer cmo_dim1, cmo_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, l, n1, n2;
    static doublereal com, scal;
    static integer nend, loop;
    static doublereal diffe;
    static integer nopen, ninit;
    static doublereal const__;
    extern /* Subroutine */ int scopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);

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
/*  1) UNPACK THE C.I-ACTIVE M.O. DERIVATIVES IN M.O. BASIS, */
/*     DIAGONAL BLOCKS INCLUDED. */
/*  2) EXTRACT THE FOCK EIGENVALUES RELAXATION OVER C.I-ACTIVE M.O. */
/*   INPUT */
/*     F           : UNSCALED SOLUTIONS VECTOR IN M.O. BASIS, */
/*                   OFF-DIAGONAL BLOCKS PACKED AS DEFINED IN 'DERI21'. */
/*     FD          : DIAGONAL BLOCKS OF NON-RELAXED FOCK MATRIX */
/*                   AS DEFINED IN 'DERI1'. */
/*     E(NORBS)    : FOCK EIGENVALUES. */
/*     FCI         : DIAGONAL BLOCKS OF RELAXATION OF THE FOCK MATRIX. */
/*     NORBS       : NUMBER OF M.O */
/*     NELEC,NMOS  : # OF LAST FROZEN CORE M.O , C.I-ACTIVE BAND LENGTH. */
/*   OUTPUT */
/*     CMO(N,NELEC+1,...,NELEC+NMOS): C.I-ACTIVE M.O DERIVATIVES */
/*                                  IN M.O BASIS. */
/*     EMO(  NELEC+1,...,NELEC+NMOS): C.I-ACTIVE FOCK EIGENVALUE RELAXATI */

/* ********************************************************************** */

    /* Parameter adjustments */
    --f;
    --fd;
    --e;
    --fci;
    --emo;
    cmo_dim1 = *norbs;
    cmo_offset = 1 + cmo_dim1 * 1;
    cmo -= cmo_offset;

    /* Function Body */
    nopen = cibits_1.nbo[0] + cibits_1.nbo[1];
    const__ = .001;

/*     PART 1. */
/*     ------- */
/*     COMPUTE AND UNPACK DIAGONAL BLOCKS, DIAGONAL TERMS INCLUDED, */
/*     ACCORDING TO CMO(I,J) = (FD(I,J)-FCI(I,J))/(E(I)-E(J)) */
/*     AND TAKING   CMO(I,J)=0 IF E(I)=E(J) (THRESHOLD 1D-4 EV), */
/*                             I.E WHEN M.O. DEGENERACY OCCURS. */
    l = 1;
    nend = 0;
    for (loop = 1; loop <= 3; ++loop) {
	ninit = nend + 1;
	nend += cibits_1.nbo[loop - 1];
/* Computing MAX */
	i__1 = ninit, i__2 = cibits_1.nelec + 1;
	n1 = max(i__1,i__2);
/* Computing MIN */
	i__1 = nend, i__2 = cibits_1.nelec + cibits_1.nmos;
	n2 = min(i__1,i__2);
	if (n2 < n1) {
	    goto L30;
	}
	i__1 = n2;
	for (i__ = n1; i__ <= i__1; ++i__) {
	    if (i__ > ninit) {
		i__2 = i__ - 1;
		for (j = ninit; j <= i__2; ++j) {
		    diffe = e[i__] - e[j];
		    if (abs(diffe) > 1e-4) {
			com = (fd[l] - fci[l]) / diffe;
		    } else {
			com = 0.;
		    }
		    cmo[i__ + j * cmo_dim1] = -com;
		    cmo[j + i__ * cmo_dim1] = com;
/* L10: */
		    ++l;
		}
	    }
/* L20: */
	    cmo[i__ + i__ * cmo_dim1] = 0.;
	}
L30:
	;
    }

/*     C.I-ACTIVE EIGENVALUES RELAXATION. */
    scopy_(&cibits_1.nmos, &fci[l], &c__1, &emo[cibits_1.nelec + 1], &c__1);

/*     PART 2. */
/*     ------- */
/*     UNPACK THE ANTISYMMETRIC MATRIX F IN CMO, (OFF-DIAGONAL BLOCKS). */

    l = 1;
    if (cibits_1.nbo[1] > 0 && cibits_1.nbo[0] > 0) {
/*        OPEN-CLOSED */
	scal = 1. / (2. - molkst_1.fract + const__);
	i__1 = cibits_1.nbo[0];
	for (j = 1; j <= i__1; ++j) {
	    i__2 = nopen;
	    for (i__ = cibits_1.nbo[0] + 1; i__ <= i__2; ++i__) {
		com = f[l] * scal;
		cmo[i__ + j * cmo_dim1] = -com;
		cmo[j + i__ * cmo_dim1] = com;
/* L40: */
		++l;
	    }
	}
    }
    if (cibits_1.nbo[2] > 0 && cibits_1.nbo[0] > 0) {
/* 	 VIRTUAL-CLOSED */
	scal = .5;
	i__2 = cibits_1.nbo[0];
	for (j = 1; j <= i__2; ++j) {
	    i__1 = *norbs;
	    for (i__ = nopen + 1; i__ <= i__1; ++i__) {
		com = f[l] * scal;
		cmo[i__ + j * cmo_dim1] = -com;
		cmo[j + i__ * cmo_dim1] = com;
/* L50: */
		++l;
	    }
	}
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[1] != 0) {
/*        VIRTUAL-OPEN */
	scal = 1. / (molkst_1.fract + const__);
	i__1 = nopen;
	for (j = cibits_1.nbo[0] + 1; j <= i__1; ++j) {
	    i__2 = *norbs;
	    for (i__ = nopen + 1; i__ <= i__2; ++i__) {
		com = f[l] * scal;
		cmo[i__ + j * cmo_dim1] = -com;
		cmo[j + i__ * cmo_dim1] = com;
/* L60: */
		++l;
	    }
	}
    }
    return 0;
} /* deri23_ */

