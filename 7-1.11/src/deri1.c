/* deri1.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

union {
    struct {
	integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], ndumy1,
		 nelecs, nalpha, nbeta, nclose, nopen, ndumy;
	doublereal fract;
    } _1;
    struct {
	integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
		nelecs, nalpha, nbeta, nclose, nopen, ndumy;
	doublereal fract;
    } _2;
} molkst_;

#define molkst_1 (molkst_._1)
#define molkst_2 (molkst_._2)

struct {
    doublereal cdum[90000], eigs[300], wdum[90000], eigb[300];
} vector_;

#define vector_1 vector_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    integer nmos, lab, nelec, nbo[3];
} cibits_;

#define cibits_1 cibits_

struct {
    doublereal h__[45150];
} hmatrx_;

#define hmatrx_1 hmatrx_

struct {
    doublereal xy[4096]	/* was [8][8][8][8] */;
} xyijkl_;

#define xyijkl_1 xyijkl_

struct {
    doublereal conf[4161];
} civect_;

#define civect_1 civect_

struct {
    doublereal fdumy[45150], scalar[45150];
} fokmat_;

#define fokmat_1 fokmat_

struct {
    doublereal diag[22575];
} nvomat_;

#define nvomat_1 nvomat_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal uspd[300], dumy[300];
} molorb_;

#define molorb_1 molorb_

struct {
    doublereal wdummy[429540];
} wmatrx_;

#define wmatrx_1 wmatrx_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__5 = 5;

/* Subroutine */ int deri1_(doublereal *c__, integer *norbs, doublereal *
	coord, integer *number, doublereal *work, doublereal *grad, 
	doublereal *f, integer *minear, doublereal *fd, doublereal *wmat, 
	doublereal *hmat, doublereal *fmat)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer c_dim1, c_offset, work_dim1, work_offset, i__1, i__2, i__3, i__4, 
	    i__5, i__6, i__7, i__8;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsle(cilist *), do_lio(
	    integer *, integer *, char *, ftnlen), e_wsle(void), s_wsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, l, n1, n2, ll;
    static doublereal gse;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);
    static integer nend, nati, lcut, loop, natx;
    static doublereal step;
    static integer iprt;
    extern /* Subroutine */ int mtxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *), mecid_(doublereal *, 
	    doublereal *, doublereal *, doublereal *), mecih_(doublereal *, 
	    doublereal *, integer *, integer *);
    static logical debug;
    extern /* Subroutine */ int timer_(char *, ftnlen);
    static integer ninit;
    extern /* Subroutine */ int scopy_(integer *, doublereal *, integer *, 
	    doublereal *, integer *), dfock2_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *), dijkl1_(doublereal *, integer *, integer *,
	     doublereal *, doublereal *, doublereal *, doublereal *);
    static doublereal enucl2;
    extern /* Subroutine */ int dhcore_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, doublereal *);
    extern doublereal helect_(integer *, doublereal *, doublereal *, 
	    doublereal *);
    static integer linear;
    extern /* Subroutine */ int supdot_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 6, 0, 0, 0 };
    static cilist io___13 = { 0, 6, 0, "(5F12.6)", 0 };
    static cilist io___22 = { 0, 6, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, "(' * * * GRADIENT COMPONENT NUMBER',"
	    "I4)", 0 };
    static cilist io___24 = { 0, 0, 0, "(' NON-RELAXED C.I-ACTIVE FOCK EIGEN"
	    "VALUES ',                    'DERIVATIVES (E.V.)')", 0 };
    static cilist io___25 = { 0, 0, 0, "(8F10.4)", 0 };
    static cilist io___26 = { 0, 0, 0, "(' NON-RELAXED 2-ELECTRONS DERIVATIV"
	    "ES (E.V.)'/  '    I    J    K    L       d<I(1)J(1)|K(2)L(2)>')", 
	    0 };
    static cilist io___28 = { 0, 0, 0, "(4I5,F20.10)", 0 };
    static cilist io___29 = { 0, 0, 0, "(' NON-RELAXED GRADIENT COMPONENT',F"
	    "10.4,        ' KCAL/MOLE')", 0 };


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

/*     DERI1 COMPUTE THE NON-RELAXED DERIVATIVE OF THE NON-VARIATIONALLY */
/*     OPTIMIZED WAVEFUNCTION ENERGY WITH RESPECT TO ONE CARTESIAN */
/*     COORDINATE AT A TIME */
/*                             AND */
/*     COMPUTE THE NON-RELAXED FOCK MATRIX DERIVATIVE IN M.O BASIS AS */
/*     REQUIRED IN THE RELAXATION SECTION (ROUTINE 'DERI2'). */

/*   INPUT */
/*     C(NORBS,NORBS) : M.O. COEFFICIENTS. */
/*     COORD  : CARTESIAN COORDINATES ARRAY. */
/*     NUMBER : LOCATION OF THE REQUIRED VARIABLE IN COORD. */
/*     WORK   : WORK ARRAY OF SIZE N*N. */
/*     WMAT     : WORK ARRAYS FOR d<PQ|RS> (2-CENTERS  A.O) */
/*   OUTPUT */
/*     C,COORD,NUMBER : NOT MODIFIED. */
/*     GRAD   : DERIVATIVE OF THE HEAT OF FORMATION WITH RESPECT TO */
/*              COORD(NUMBER), WITHOUT RELAXATION CORRECTION. */
/*     F(MINEAR) : NON-RELAXED FOCK MATRIX DERIVATIVE WITH RESPECT TO */
/*              COORD(NUMBER), EXPRESSED IN M.O BASIS, SCALED AND */
/*              PACKED, OFF-DIAGONAL BLOCKS ONLY. */
/*     FD     : IDEM BUT UNSCALED, DIAGONAL BLOCKS, C.I-ACTIVE ONLY. */

/* *********************************************************************** */
    /* Parameter adjustments */
    work_dim1 = *norbs;
    work_offset = 1 + work_dim1 * 1;
    work -= work_offset;
    c_dim1 = *norbs;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    --coord;
    --f;
    --fd;
    --wmat;
    --hmat;
    --fmat;

    /* Function Body */

    if (icalcn != numcal_1.numcal) {
	debug = i_indx(keywrd_1.keywrd, "DERI1", (ftnlen)241, (ftnlen)5) != 0;
	iprt = 6;
	linear = *norbs * (*norbs + 1) / 2;
	icalcn = numcal_1.numcal;
    }
    if (debug) {
	timer_("BEFORE DERI1", (ftnlen)12);
    }
    step = .001;

/*     2 POINTS FINITE DIFFERENCE TO GET THE INTEGRAL DERIVATIVES */
/*     ---------------------------------------------------------- */
/*     STORED IN HMAT AND WMAT, WITHOUT DIVIDING BY THE STEP SIZE. */

    nati = (*number - 1) / 3 + 1;
    natx = *number - (nati - 1) * 3;
    dhcore_(&coord[1], &hmat[1], &wmat[1], &enucl2, &nati, &natx, &step);

/* HMAT HOLDS THE ONE-ELECTRON DERIVATIVES OF ATOM NATI FOR DIRECTION */
/*      NATX W.R.T. ALL OTHER ATOMS */
/* WMAT HOLDS THE TWO-ELECTRON DERIVATIVES OF ATOM NATI FOR DIRECTION */
/*      NATX W.R.T. ALL OTHER ATOMS */
    step = .5 / step;

/*     NON-RELAXED FOCK MATRIX DERIVATIVE IN A.O BASIS. */
/*     ------------------------------------------------ */
/*     STORED IN FMAT, DIVIDED BY STEP. */

    scopy_(&linear, &hmat[1], &c__1, &fmat[1], &c__1);
    dfock2_(&fmat[1], densty_1.p, densty_1.pa, &wmat[1], &molkst_1.numat, 
	    molkst_1.nfirst, molkst_1.nmidle, molkst_1.nlast, &nati);

/*  FMAT HOLDS THE ONE PLUS TWO - ELECTRON DERIVATIVES OF ATOM NATI FOR */
/*       DIRECTION NATX W.R.T. ALL OTHER ATOMS */

/*       DERIVATIVE OF THE SCF-ONLY ENERGY (I.E BEFORE C.I CORRECTION) */

    *grad = (helect_(norbs, densty_1.p, &hmat[1], &fmat[1]) + enucl2) * step;
/*     TAKE STEP INTO ACCOUNT IN FMAT */
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	fmat[i__] *= step;
    }

/*     RIGHT-HAND SIDE SUPER-VECTOR F = C' FMAT C USED IN RELAXATION */
/*     ----------------------------------------------------------- */
/*     STORED IN NON-STANDARD PACKED FORM IN F(MINEAR) AND FD. */
/*     THE SUPERVECTOR IS THE NON-RELAXED FOCK MATRIX DERIVATIVE IN */
/*     M.O BASIS: F(IJ)= ( (C' * FOCK * C)(I,J) )   WITH I.GT.J . */
/*     F IS SCALED AND PACKED IN SUPERVECTOR FORM WITH */
/*                THE CONSECUTIVE FOLLOWING OFF-DIAGONAL BLOCKS: */
/*             1) OPEN-CLOSED  I.E. F(IJ)=F(I,J) WITH I OPEN & J CLOSED */
/*                                  AND I RUNNING FASTER THAN J, */
/*             2) VIRTUAL-CLOSED SAME RULE OF ORDERING, */
/*             3) VIRTUAL-OPEN   SAME RULE OF ORDERING. */
/*     FD IS PACKED OVER THE C.I-ACTIVE M.O WITH */
/*                THE CONSECUTIVE DIAGONAL BLOCKS: */
/*             1) CLOSED-CLOSED   IN CANONICAL ORDER, WITHOUT THE */
/*                                DIAGONAL ELEMENTS, */
/*             2) OPEN-OPEN       SAME RULE OF ORDERING, */
/*             3) VIRTUAL-VIRTUAL SAME RULE OF ORDERING. */

/*     PART 1 : WORK(N,N) = FMAT(N,N) * C(N,N) */
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	supdot_(&work[i__ * work_dim1 + 1], &fmat[1], &c__[i__ * c_dim1 + 1], 
		norbs, &c__1);
    }

/*     PART 2 : F(IJ) =  (C' * WORK)(I,J) ... OFF-DIAGONAL BLOCKS. */
    l = 1;
    if (cibits_1.nbo[1] != 0 && cibits_1.nbo[0] != 0) {
/*        OPEN-CLOSED */
	mtxm_(&c__[(cibits_1.nbo[0] + 1) * c_dim1 + 1], &cibits_1.nbo[1], &
		work[work_offset], norbs, &f[l], cibits_1.nbo);
	l += cibits_1.nbo[1] * cibits_1.nbo[0];
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[0] != 0) {
/*        VIRTUAL-CLOSED */
	mtxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], &cibits_1.nbo[2], &
		work[work_offset], norbs, &f[l], cibits_1.nbo);
	l += cibits_1.nbo[2] * cibits_1.nbo[0];
    }
    if (cibits_1.nbo[2] != 0 && cibits_1.nbo[1] != 0) {
/*        VIRTUAL-OPEN */
	mtxm_(&c__[(molkst_1.nopen + 1) * c_dim1 + 1], &cibits_1.nbo[2], &
		work[(cibits_1.nbo[0] + 1) * work_dim1 + 1], norbs, &f[l], &
		cibits_1.nbo[1]);
    }
/*     SCALE F ACCORDING TO THE DIAGONAL METRIC TENSOR 'SCALAR '. */
    i__1 = *minear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	f[i__] *= fokmat_1.scalar[i__ - 1];
    }
    if (debug) {
	s_wsle(&io___11);
	do_lio(&c__9, &c__1, " F IN DERI1", (ftnlen)11);
	e_wsle();
	j = min(20,*minear);
	s_wsfe(&io___13);
	i__1 = j;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&f[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }

/*     PART 3 : SUPER-VECTOR FD, C.I-ACTIVE DIAGONAL BLOCKS, UNSCALED. */
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
	    goto L50;
	}
	i__1 = n2;
	for (i__ = n1; i__ <= i__1; ++i__) {
	    if (i__ > ninit) {
		i__2 = i__ - ninit;
		mxm_(&c__[i__ * c_dim1 + 1], &c__1, &work[ninit * work_dim1 + 
			1], norbs, &fd[l], &i__2);
		l = l + i__ - ninit;
	    }
/* L40: */
	}
L50:
	;
    }

/*     NON-RELAXED C.I CORRECTION TO THE ENERGY DERIVATIVE. */
/*     ---------------------------------------------------- */

/*     C.I-ACTIVE FOCK EIGENVALUES DERIVATIVES, STORED IN FD(CONTINUED). */
    lcut = l;
    i__1 = cibits_1.nelec + cibits_1.nmos;
    for (i__ = cibits_1.nelec + 1; i__ <= i__1; ++i__) {
	fd[l] = dot_(&c__[i__ * c_dim1 + 1], &work[i__ * work_dim1 + 1], 
		norbs);
/* L60: */
	++l;
    }

/*     C.I-ACTIVE 2-ELECTRONS INTEGRALS DERIVATIVES. STORED IN XY. */
/*   FMAT IS USED HERE AS SCRATCH SPACE */

    dijkl1_(&c__[(cibits_1.nelec + 1) * c_dim1 + 1], norbs, &nati, &wmat[1], &
	    fmat[1], &hmat[1], &fmat[1]);
    i__1 = cibits_1.nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = cibits_1.nmos;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = cibits_1.nmos;
	    for (k = 1; k <= i__3; ++k) {
		i__4 = cibits_1.nmos;
		for (l = 1; l <= i__4; ++l) {
/* L70: */
		    xyijkl_1.xy[i__ + (j + (k + (l << 3) << 3) << 3) - 585] *=
			     step;
		}
	    }
	}
    }

/*     BUILD THE C.I MATRIX DERIVATIVE, STORED IN WMAT. */
    mecid_(&fd[lcut - cibits_1.nelec], &gse, vector_1.eigb, &work[work_offset]
	    );
    if (debug) {
	s_wsle(&io___22);
	do_lio(&c__9, &c__1, " GSE:", (ftnlen)5);
	do_lio(&c__5, &c__1, (char *)&gse, (ftnlen)sizeof(doublereal));
	e_wsle();
/* #      WRITE(6,*)' EIGB:',(EIGB(I),I=1,10) */
/* #      WRITE(6,*)' WORK:',(WORK(I,1),I=1,10) */
    }
    mecih_(&work[work_offset], &wmat[1], &cibits_1.nmos, &cibits_1.lab);

/*     NON-RELAXED C.I CONTRIBUTION TO THE ENERGY DERIVATIVE. */
    supdot_(&work[work_offset], &wmat[1], civect_1.conf, &cibits_1.lab, &c__1)
	    ;
    *grad = (*grad + dot_(civect_1.conf, &work[work_offset], &cibits_1.lab)) *
	     23.061;
    if (debug) {
	io___23.ciunit = iprt;
	s_wsfe(&io___23);
	do_fio(&c__1, (char *)&(*number), (ftnlen)sizeof(integer));
	e_wsfe();
	io___24.ciunit = iprt;
	s_wsfe(&io___24);
	e_wsfe();
	io___25.ciunit = iprt;
	s_wsfe(&io___25);
	i__4 = cibits_1.nmos;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    do_fio(&c__1, (char *)&fd[lcut - 1 + i__], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	io___26.ciunit = iprt;
	s_wsfe(&io___26);
	e_wsfe();
	i__4 = cibits_1.nmos;
	for (i__ = 1; i__ <= i__4; ++i__) {
	    i__3 = i__;
	    for (j = 1; j <= i__3; ++j) {
		i__2 = i__;
		for (k = 1; k <= i__2; ++k) {
		    ll = k;
		    if (k == i__) {
			ll = j;
		    }
		    i__1 = ll;
		    for (l = 1; l <= i__1; ++l) {
/* L80: */
			io___28.ciunit = iprt;
			s_wsfe(&io___28);
			i__5 = cibits_1.nelec + i__;
			do_fio(&c__1, (char *)&i__5, (ftnlen)sizeof(integer));
			i__6 = cibits_1.nelec + j;
			do_fio(&c__1, (char *)&i__6, (ftnlen)sizeof(integer));
			i__7 = cibits_1.nelec + k;
			do_fio(&c__1, (char *)&i__7, (ftnlen)sizeof(integer));
			i__8 = cibits_1.nelec + l;
			do_fio(&c__1, (char *)&i__8, (ftnlen)sizeof(integer));
			do_fio(&c__1, (char *)&xyijkl_1.xy[i__ + (j + (k + (l 
				<< 3) << 3) << 3) - 585], (ftnlen)sizeof(
				doublereal));
			e_wsfe();
		    }
		}
	    }
	}
	io___29.ciunit = iprt;
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&(*grad), (ftnlen)sizeof(doublereal));
	e_wsfe();
	timer_("AFTER DERI1", (ftnlen)11);
    }
    return 0;
} /* deri1_ */

/* Subroutine */ int dhcore_(doublereal *coord, doublereal *h__, doublereal *
	w, doublereal *enuclr, integer *nati, integer *natx, doublereal *step)
{
    /* Initialized data */

    static integer nb[9] = { 1,0,0,10,0,0,0,0,45 };
    static logical first = TRUE_;

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, i1, i2, j2, j1, j7, ia, ib, ic;
    static doublereal di[81]	/* was [9][9] */;
    static integer ja, jb, jc, ii, ij, ni, nj, kr;
    static doublereal e1b[10], e2a[10], ddi[81]	/* was [9][9] */, wjd[101];
    static integer kro;
    static doublereal de1b[10], de2a[10], dwjd[101], enuc;
    static integer nrow;
    static doublereal denuc, csave;
    static logical mindo;
    extern /* Subroutine */ int h1elec_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
    static integer nband2;
    static doublereal cutoff;
    extern /* Subroutine */ int rotate_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *);

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

/*  DHCORE GENERATES THE 1-ELECTRON  AND 2-ELECTRON INTEGRALS DERIVATIVES */
/*         WITH RESPECT TO THE CARTESIAN COORDINATE COORD (NATX,NATI). */

/*  INPUT */
/*      COORD     : CARTESIAN  COORDINATES OF THE MOLECULE. */
/*      NATI,NATX : INDICES OF THE MOVING COORDINATE. */
/*      STEP      : STEP SIZE OF THE 2-POINTS FINITE DIFFERENCE. */
/*  OUTPUT */
/*      H         : 1-ELECTRON INTEGRALS DERIVATIVES (PACKED CANONICAL). */
/*      W         : 2-ELECTRON INTEGRALS DERIVATIVES (ORDERED AS REQUIRED */
/*                             IN DFOCK2 AND DIJKL1). */
/*      ENUCLR    : NUCLEAR ENERGY DERIVATIVE. */

    /* Parameter adjustments */
    --w;
    --h__;
    coord -= 4;

    /* Function Body */
    if (first) {
	cutoff = 1e10;
	first = FALSE_;
	mindo = i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0;
    }
    i__1 = molkst_2.norbs * (molkst_2.norbs + 1) / 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	h__[i__] = 0.;
    }
    *enuclr = 0.;
    kr = 1;
    nrow = 0;
    i__ = *nati;
    csave = coord[*natx + *nati * 3];
    ia = molkst_2.nfirst[*nati - 1];
    ib = molkst_2.nlast[*nati - 1];
    ic = molkst_2.nmidle[*nati - 1];
    ni = molkst_2.nat[*nati - 1];
    nrow = -nb[ib - ia];
    i__1 = molkst_2.numat;
    for (j = 1; j <= i__1; ++j) {
/* L20: */
	nrow += nb[molkst_2.nlast[j - 1] - molkst_2.nfirst[j - 1]];
    }
/* #      NCOL=NB(NLAST(NATI)-NFIRST(NATI)) */
    nband2 = 0;
    i__1 = molkst_2.numat;
    for (j = 1; j <= i__1; ++j) {
	if (j == *nati) {
	    goto L120;
	}
	ja = molkst_2.nfirst[j - 1];
	jb = molkst_2.nlast[j - 1];
	jc = molkst_2.nmidle[j - 1];
	nj = molkst_2.nat[j - 1];
	coord[*natx + *nati * 3] = csave + *step;
	h1elec_(&ni, &nj, &coord[*nati * 3 + 1], &coord[j * 3 + 1], di);

/*  THE FOLLOWING STYLE WAS NECESSARY TO GET ROUND A BUG IN THE */
/*  GOULD COMPILER */

	coord[*natx + *nati * 3] = csave + *step * -1.;
	h1elec_(&ni, &nj, &coord[*nati * 3 + 1], &coord[j * 3 + 1], ddi);

/*     FILL THE ATOM-OTHER ATOM ONE-ELECTRON MATRIX. */

	i2 = 0;
	if (ia > ja) {
	    i__2 = ib;
	    for (i1 = ia; i1 <= i__2; ++i1) {
		ij = i1 * (i1 - 1) / 2 + ja - 1;
		++i2;
		j2 = 0;
		i__3 = jb;
		for (j1 = ja; j1 <= i__3; ++j1) {
		    ++ij;
		    ++j2;
/* L30: */
		    h__[ij] += di[i2 + j2 * 9 - 10] - ddi[i2 + j2 * 9 - 10];
		}
	    }
	} else {
	    i__3 = jb;
	    for (i1 = ja; i1 <= i__3; ++i1) {
		ij = i1 * (i1 - 1) / 2 + ia - 1;
		++i2;
		j2 = 0;
		i__2 = ib;
		for (j1 = ia; j1 <= i__2; ++j1) {
		    ++ij;
		    ++j2;
/* L40: */
		    h__[ij] += di[j2 + i2 * 9 - 10] - ddi[j2 + i2 * 9 - 10];
		}
	    }
	}

/*     CALCULATE THE TWO-ELECTRON INTEGRALS, W; THE ELECTRON NUCLEAR TERM */
/*     E1B AND E2A; AND THE NUCLEAR-NUCLEAR TERM ENUC. */

	kro = kr;
	nband2 += nb[molkst_2.nlast[j - 1] - molkst_2.nfirst[j - 1]];
	if (mindo) {
	    coord[*natx + *nati * 3] = csave + *step;
	    rotate_(&ni, &nj, &coord[*nati * 3 + 1], &coord[j * 3 + 1], wjd, &
		    kr, e1b, e2a, &enuc, &cutoff);
	    kr = kro;
	    coord[*natx + *nati * 3] = csave + *step * -1.;
	    rotate_(&ni, &nj, &coord[*nati * 3 + 1], &coord[j * 3 + 1], dwjd, 
		    &kr, de1b, de2a, &denuc, &cutoff);
	    if (kr > kro) {
		i__2 = kr - kro + 1;
		for (k = 1; k <= i__2; ++k) {
/* L50: */
		    w[kro + k - 1] = wjd[k - 1] - dwjd[k - 1];
		}
	    }
	} else {
	    coord[*natx + *nati * 3] = csave + *step;
	    rotate_(&ni, &nj, &coord[*nati * 3 + 1], &coord[j * 3 + 1], wjd, &
		    kr, e1b, e2a, &enuc, &cutoff);
	    kr = kro;
	    coord[*natx + *nati * 3] = csave + *step * -1.;
	    rotate_(&ni, &nj, &coord[*nati * 3 + 1], &coord[j * 3 + 1], dwjd, 
		    &kr, de1b, de2a, &denuc, &cutoff);
	    if (kr > kro) {
		i__2 = kr - kro + 1;
		for (k = 1; k <= i__2; ++k) {
/* L60: */
		    wjd[k - 1] -= dwjd[k - 1];
		}
		j7 = 0;
		i__2 = kr;
		for (i1 = kro; i1 <= i__2; ++i1) {
		    ++j7;
/* L70: */
		    w[i1] = wjd[j7 - 1];
		}
	    }
	}
	coord[*natx + *nati * 3] = csave;
	*enuclr = *enuclr + enuc - denuc;

/*   ADD ON THE ELECTRON-NUCLEAR ATTRACTION TERM FOR ATOM I. */

	i2 = 0;
	i__2 = ic;
	for (i1 = ia; i1 <= i__2; ++i1) {
	    ii = i1 * (i1 - 1) / 2 + ia - 1;
	    i__3 = i1;
	    for (j1 = ia; j1 <= i__3; ++j1) {
		++ii;
		++i2;
/* L80: */
		h__[ii] = h__[ii] + e1b[i2 - 1] - de1b[i2 - 1];
	    }
	}
/*     CONTRIB D, CNDO. */
	i__3 = ib;
	for (i1 = ic + 1; i1 <= i__3; ++i1) {
	    ii = i1 * (i1 + 1) / 2;
/* L90: */
	    h__[ii] = h__[ii] + e1b[0] - de1b[0];
	}

/*   ADD ON THE ELECTRON-NUCLEAR ATTRACTION TERM FOR ATOM J. */

	i2 = 0;
	i__3 = jc;
	for (i1 = ja; i1 <= i__3; ++i1) {
	    ii = i1 * (i1 - 1) / 2 + ja - 1;
	    i__2 = i1;
	    for (j1 = ja; j1 <= i__2; ++j1) {
		++ii;
		++i2;
/* L100: */
		h__[ii] = h__[ii] + e2a[i2 - 1] - de2a[i2 - 1];
	    }
	}
/*     CONTRIB D, CNDO. */
	i__2 = jb;
	for (i1 = jc + 1; i1 <= i__2; ++i1) {
	    ii = i1 * (i1 + 1) / 2;
/* L110: */
	    h__[ii] = h__[ii] + e2a[0] - de2a[0];
	}
L120:
	;
    }

/*   'SIZE' OF H IS NROW * NCOL */

    return 0;
} /* dhcore_ */

