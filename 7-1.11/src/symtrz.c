/* symtrz.f -- translated by f2c (version 20020621).
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

union {
    struct {
	doublereal trans, rtr, sig;
	char name__[4], namo[1920];
	integer index[480];
	char ista[8];
    } _1;
    struct {
	doublereal trans, rtr, sig;
	integer name__, namo[480], index[480], ista[2];
    } _2;
    struct {
	doublereal trans, rtr, sig;
	char name__[4];
	integer namo[480], index[480];
	char ista[8];
    } _3;
} symres_;

#define symres_1 (symres_._1)
#define symres_2 (symres_._2)
#define symres_3 (symres_._3)

struct {
    integer ibase[24]	/* was [2][12] */, nbase, ivibro[24]	/* was [2][12]
	     */, ivib;
} syminf_;

#define syminf_1 syminf_

struct {
    doublereal cdum[90000], eigs[300], cbdum[90000], eigb[300];
} vector_;

#define vector_1 vector_

union {
    struct {
	integer nunum, nonorb, nadim, ncdim, iqual, ndorbs, ierror;
    } _1;
    struct {
	integer numat, norbs, nadim, ncdim, iqual, ndorbs, ierror;
    } _2;
} s00002_;

#define s00002_1 (s00002_._1)
#define s00002_2 (s00002_._2)

struct {
    doublereal shift[3], r__[9]	/* was [3][3] */, vect[960]	/* was [2][
	    480] */;
} s00004_;

#define s00004_1 s00004_

union {
    struct {
	doublereal t[144]	/* was [12][12] */;
	integer jx[84]	/* was [7][12] */, lina, i1, j1, j2;
    } _1;
    struct {
	doublereal t[144]	/* was [12][12] */;
	char jx[336]	/* was [7][12] */;
	integer lina, i1, j1, j2;
    } _2;
} s00001_;

#define s00001_1 (s00001_._1)
#define s00001_2 (s00001_._2)

struct {
    char nimm[3840]	/* was [2][480] */;
    integer nocc[2];
} s00020_;

#define s00020_1 s00020_

struct {
    integer ielem[20];
    doublereal elem[180]	/* was [3][3][20] */, cub[9]	/* was [3][3] 
	    */;
    integer jelem[2400]	/* was [20][120] */;
} s00003_;

#define s00003_1 s00003_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

/* Table of constant values */

static integer c__2 = 2;
static integer c__1 = 1;
static integer c__300 = 300;
static integer c__0 = 0;
static integer c__5 = 5;
static integer c_n1 = -1;
static integer c__3 = 3;
static integer c__9 = 9;
static integer c__17 = 17;
static integer c__8 = 8;
static doublereal c_b101 = .707106781186;
static integer c__15 = 15;




/* Subroutine */ int symtrz_(doublereal *coord, doublereal *c__, integer *
	norb, integer *nmos, logical *flag__, logical *flag2)
{

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static char nam[4];
    static doublereal rsav[9]	/* was [3][3] */, cotim[360]	/* was [3][
	    120] */;
    extern /* Subroutine */ int syman1_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *), syman2_(integer *, integer *, 
	    doublereal *, integer *, integer *, integer *);

/* ************************************************************** */
/*                                                             * */
/*     DETERMINE POINT GROUP & SYMMETRIZE ORBITALS             * */
/*                                                             * */
/* ************************************************************** */
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
/*     --------------------------------------------------------------- */
    /* Parameter adjustments */
    c__ -= 301;
    coord -= 4;

    /* Function Body */
    s00002_1.nunum = molkst_1.numat;
    s00002_1.nonorb = molkst_1.norbs;
    for (k = 1; k <= 3; ++k) {
	i__1 = molkst_1.numat;
	for (l = 1; l <= i__1; ++l) {
	    cotim[k + l * 3 - 4] = coord[k + l * 3];
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    rsav[i__ + j * 3 - 4] = s00004_1.r__[i__ + j * 3 - 4];
	}
    }
    s_copy(nam, symres_1.name__, (ftnlen)4, (ftnlen)4);
    syman1_(&molkst_1.numat, &c__2, &coord[4], molkst_1.nat, &c__1, &c__300);
    if (*flag2) {
	syman2_(&molkst_1.norbs, &molkst_1.norbs, &c__[301], &c__0, &c__1, &
		c__300);
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    s00004_1.r__[i__ + j * 3 - 4] = rsav[i__ + j * 3 - 4];
	}
    }
    for (k = 1; k <= 3; ++k) {
	i__1 = molkst_1.numat;
	for (l = 1; l <= i__1; ++l) {
	    coord[k + l * 3] = cotim[k + l * 3 - 4];
	}
    }
    return 0;
} /* symtrz_ */


/* ================================================================ */

/* Subroutine */ int syman1_(integer *num1, integer *num2, doublereal *array, 
	integer *linear, integer *jump, integer *idim)
{
    /* Initialized data */

    static char ifra[4] = "????";

    /* Format strings */
    static char fmt_600[] = "(\002 ILLEGAL SYMA - ARGUMENTS: NUM1 = \002,i"
	    "10,\002 NUM2 = \002,i10)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int r00001_(integer *, doublereal *), r00016_(
	    void), r00009_(integer *, doublereal *);
    static integer lcall;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 6, 0, fmt_600, 0 };


/* *************************************************************** */
/*                                                              * */
/*     SYMMETRY PACKAGE FROM UMNDO PROGRAM OF PETER BISCHOF     * */
/*     WAS REWRITTEN BY DAVID DANOVICH FOR MOPAC SYSTEM         * */
/*                                                              * */
/* *************************************************************** */
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
    /* Parameter adjustments */
    --linear;
    array -= 4;

    /* Function Body */
    if (*num1 < 2) {
	goto L12;
    }
    if (*num2 < 2) {
	goto L12;
    }
    if (*num1 > 480) {
	goto L12;
    }
/* **  MOLECULAR SYMMETRY */
/* L1: */
    s00002_2.ierror = 0;
    lcall = 0;
    syminf_1.ivib = 0;
    syminf_1.nbase = 0;
    s00002_2.numat = *num1;
    s_copy(symres_1.name__, ifra, (ftnlen)4, (ftnlen)4);
    s_copy(symres_1.ista, " ", (ftnlen)4, (ftnlen)1);
    s_copy(symres_1.ista + 4, ifra, (ftnlen)4, (ftnlen)4);
    for (i__ = 1; i__ <= 480; ++i__) {
/* L2: */
	s_copy(symres_1.namo + (i__ - 1 << 2), ifra, (ftnlen)4, (ftnlen)4);
    }
    r00001_(&linear[1], &array[4]);
    if (s00002_2.ierror < 1) {
	r00009_(&linear[1], &array[4]);
    }
    if (s00002_2.ierror < 1) {
	r00016_();
    }
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L3: */
	symres_1.index[i__ - 1] = linear[i__];
    }
    return 0;
L12:
    s00002_2.ierror = 1;
    s_wsfe(&io___12);
    do_fio(&c__1, (char *)&(*num1), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*num2), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* syman1_ */


/* ====================================================================== */

/* Subroutine */ int syman2_(integer *num1, integer *num2, doublereal *array, 
	integer *linear, integer *jump, integer *idim)
{

    /* Format strings */
    static char fmt_600[] = "(\002 ILLEGAL SYMA - ARGUMENTS: NUM1 = \002,i"
	    "10,\002 NUM2 = \002,i10)";

    /* System generated locals */
    integer array_dim1, array_offset, i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, jj, nqz;
    extern /* Subroutine */ int r00010_(doublereal *, integer *, integer *, 
	    integer *);
    static integer korb, nuss[480], lcall, ncdum, icount[12];

    /* Fortran I/O blocks */
    static cilist io___23 = { 0, 6, 0, fmt_600, 0 };


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
    /* Parameter adjustments */
    array_dim1 = *num1;
    array_offset = 1 + array_dim1 * 1;
    array -= array_offset;

    /* Function Body */
    if (*num1 < 2) {
	goto L12;
    }
    if (*num2 < 2) {
	goto L12;
    }
    if (*num1 > 480) {
	goto L12;
    }
/* **  ORBITAL SYMMETRY */
    if (s00002_2.ierror > 0) {
	return 0;
    }
    lcall = 0;
    if (*linear > 0) {
	goto L6;
    }
    if (lcall > 0) {
	goto L8;
    }
    korb = 0;
    nqz = 1;
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jj = 1;
	if (symres_1.index[i__ - 1] > 1) {
	    jj = 4;
	}
	i__2 = jj;
	for (j = 1; j <= i__2; ++j) {
	    ++korb;
	    nuss[korb - 1] = i__ * 100 + nqz * 10 + j - 1;
/* L5: */
	}
    }
    goto L8;
L6:
    i__2 = *num1;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L7: */
	nuss[i__ - 1] = *linear;
    }
L8:
    s00002_2.norbs = *num1;
    s00002_2.ncdim = *num2;
    ncdum = *num2;
    r00010_(&array[array_offset], nuss, icount, num1);
    if (s00002_2.ierror > 0) {
	return 0;
    }
    syminf_1.nbase = 0;
    i__2 = s00001_1.i1;
    for (i__ = 1; i__ <= i__2; ++i__) {
	if (icount[i__ - 1] < 1) {
	    goto L9;
	}
	++syminf_1.nbase;
	syminf_1.ibase[(syminf_1.nbase << 1) - 2] = icount[i__ - 1];
	syminf_1.ibase[(syminf_1.nbase << 1) - 1] = s00001_1.jx[i__ * 7 - 7];
L9:
	;
    }
    ++lcall;
    if (lcall > 2) {
	lcall = 1;
    }
    i__2 = s00002_2.norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	s_copy(s00020_1.nimm + (lcall + (i__ << 1) - 3 << 2), symres_1.namo + 
		(i__ - 1 << 2), (ftnlen)4, (ftnlen)4);
/* L10: */
	s_copy(s00020_1.nimm + ((i__ << 1) - 1 << 2), symres_1.namo + (i__ - 
		1 << 2), (ftnlen)4, (ftnlen)4);
    }
    return 0;
L12:
    s00002_2.ierror = 1;
    s_wsfe(&io___23);
    do_fio(&c__1, (char *)&(*num1), (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&(*num2), (ftnlen)sizeof(integer));
    e_wsfe();
    return 0;
} /* syman2_ */


/* ========================================================================== */

/* Subroutine */ int r00001_(integer *nat, doublereal *coord)
{
    /* Initialized data */

    static doublereal toler = .1;
    static doublereal big = 1e35;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double log(doublereal), sqrt(doublereal), sin(doublereal), cos(doublereal)
	    ;

    /* Local variables */
    static doublereal f[6];
    static integer i__, j, k, ij;
    static doublereal ew[3];
    static integer ix, iy, iz;
    extern /* Subroutine */ int r00002_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), r00003_(integer *, 
	    doublereal *, integer *), r00005_(doublereal *, integer *), 
	    r00006_(integer *, integer *), r00015_(doublereal *, doublereal *,
	     doublereal *), r00007_(integer *, doublereal *, integer *), 
	    r00008_(integer *, integer *);
    static doublereal buff;
    static integer icyc[6];
    static doublereal help[3], cosa, sina, dist;
    static logical axis;
    static doublereal term, wmol, buff1;
    static logical cubic;
    static integer ncode, jndex;
    static doublereal rhelp[9]	/* was [3][3] */;
    static integer naxes;
    static doublereal total;
    static integer iplus, iturn, icheck;
    static logical linear, planar;
    static integer jgroup;

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
    /* Parameter adjustments */
    coord -= 4;
    --nat;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L1: */
	    s00003_1.cub[i__ + j * 3 - 4] = 0.;
	}
/* L2: */
	s00003_1.cub[i__ + i__ * 3 - 4] = 1.;
    }
    for (i__ = 1; i__ <= 20; ++i__) {
	r00006_(&i__, &i__);
/* L3: */
	s00003_1.ielem[i__ - 1] = 0;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L4: */
	s00004_1.shift[i__ - 1] = 0.;
    }
    wmol = 0.;
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	wmol += atmass_1.atmass[i__ - 1];
	for (k = 1; k <= 3; ++k) {
/* L5: */
	    s00004_1.shift[k - 1] += atmass_1.atmass[i__ - 1] * coord[k + i__ 
		    * 3];
	}
    }
    ij = 0;
    for (i__ = 1; i__ <= 3; ++i__) {
	s00004_1.shift[i__ - 1] /= wmol;
	i__1 = s00002_2.numat;
	for (k = 1; k <= i__1; ++k) {
/* L6: */
	    coord[i__ + k * 3] -= s00004_1.shift[i__ - 1];
	}
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++ij;
	    f[ij - 1] = 0.;
	    i__2 = s00002_2.numat;
	    for (k = 1; k <= i__2; ++k) {
		term = atmass_1.atmass[k - 1] * coord[i__ + k * 3] * coord[j 
			+ k * 3];
/* L7: */
		f[ij - 1] += term;
	    }
	}
    }
    symres_1.trans = log(wmol) * 2.97975 + 25.98160821;
    r00015_(f, s00004_1.r__, ew);
    s00004_1.r__[6] = s00004_1.r__[1] * s00004_1.r__[5] - s00004_1.r__[2] * 
	    s00004_1.r__[4];
    s00004_1.r__[7] = s00004_1.r__[2] * s00004_1.r__[3] - s00004_1.r__[0] * 
	    s00004_1.r__[5];
    s00004_1.r__[8] = s00004_1.r__[0] * s00004_1.r__[4] - s00004_1.r__[1] * 
	    s00004_1.r__[3];
    planar = ew[0] < toler;
    linear = ew[1] < toler;
    cubic = ew[2] - ew[0] < toler;
    if (! linear) {
	goto L8;
    }
    r00005_(&coord[4], &c__1);
    s00003_1.ielem[19] = 1;
    goto L22;
L8:
    if (cubic || ew[2] - ew[1] > toler) {
	goto L10;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	buff = -s00004_1.r__[i__ - 1];
	s00004_1.r__[i__ - 1] = s00004_1.r__[i__ + 5];
/* L9: */
	s00004_1.r__[i__ + 5] = buff;
    }
    buff = ew[0];
    ew[0] = ew[2];
    ew[2] = buff;
L10:
    axis = (d__1 = ew[0] - ew[1], abs(d__1)) < toler;
    r00005_(&coord[4], &c__1);
    if (cubic) {
	r00003_(&nat[1], &coord[4], &c__1);
    }
    if (! axis) {
	goto L16;
    }
    iturn = 7;
    for (i__ = 8; i__ <= 18; ++i__) {
	r00007_(&nat[1], &coord[4], &i__);
	if (s00003_1.ielem[i__ - 1] == 1 && i__ < 14) {
	    iturn = i__;
	}
/* L11: */
    }
    iturn += -5;
    i__2 = s00002_2.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing 2nd power */
	d__1 = coord[i__ * 3 + 1];
/* Computing 2nd power */
	d__2 = coord[i__ * 3 + 2];
	dist = d__1 * d__1 + d__2 * d__2;
	if (dist < toler) {
	    goto L13;
	}
	buff1 = big;
	jndex = 0;
	iplus = i__ + 1;
	i__1 = s00002_2.numat;
	for (j = iplus; j <= i__1; ++j) {
/* Computing 2nd power */
	    d__1 = coord[j * 3 + 1];
/* Computing 2nd power */
	    d__2 = coord[j * 3 + 2];
	    buff = d__1 * d__1 + d__2 * d__2;
	    if ((d__1 = buff - dist, abs(d__1)) > toler) {
		goto L12;
	    }
/* Computing 2nd power */
	    d__1 = coord[i__ * 3 + 1] - coord[j * 3 + 1];
/* Computing 2nd power */
	    d__2 = coord[i__ * 3 + 2] - coord[j * 3 + 2];
	    buff = d__1 * d__1 + d__2 * d__2;
	    if (buff > buff1) {
		goto L12;
	    }
	    jndex = j;
	    buff1 = buff;
L12:
	    ;
	}
	goto L14;
L13:
	;
    }
L14:
    if (jndex < 1) {
	s00002_2.ierror = 1;
    }
    if (s00002_2.ierror > 0) {
	goto L25;
    }
    help[0] = coord[i__ * 3 + 1] + coord[jndex * 3 + 1];
    help[1] = coord[i__ * 3 + 2] + coord[jndex * 3 + 2];
/* Computing 2nd power */
    d__1 = help[0];
/* Computing 2nd power */
    d__2 = help[1];
    dist = sqrt(d__1 * d__1 + d__2 * d__2);
    sina = help[1] / dist;
    cosa = help[0] / dist;
    r00002_(&coord[4], &sina, &cosa, &c__1, &c__2);
    r00007_(&nat[1], &coord[4], &c__5);
    if (s00003_1.ielem[4] == 1) {
	goto L16;
    }
    r00007_(&nat[1], &coord[4], &c__1);
    if (s00003_1.ielem[0] == 0) {
	goto L16;
    }
    dist = 1.5707963268 / (real) iturn;
    sina = sin(dist);
    cosa = cos(dist);
    icheck = 0;
L15:
    r00002_(&coord[4], &sina, &cosa, &c__1, &c__2);
    if (icheck > 0) {
	goto L16;
    }
    r00007_(&nat[1], &coord[4], &c__5);
    if (s00003_1.ielem[4] > 0) {
	goto L16;
    }
    icheck = 1;
    sina = -sina;
    goto L15;
L16:
    if (cubic) {
	r00003_(&nat[1], &coord[4], &c__2);
    }
    if (axis) {
	goto L22;
    }
    for (i__ = 1; i__ <= 6; ++i__) {
	r00007_(&nat[1], &coord[4], &i__);
/* L17: */
	icyc[i__ - 1] = (s00002_2.iqual + 1) * s00003_1.ielem[i__ - 1];
    }
    naxes = s00003_1.ielem[0] + s00003_1.ielem[1] + s00003_1.ielem[2];
    if (naxes > 1) {
	goto L18;
    }
    iz = 1;
    if (s00003_1.ielem[0] == 1) {
	goto L19;
    }
    iz = 2;
    if (s00003_1.ielem[1] == 1) {
	goto L19;
    }
    iz = 3;
    if (s00003_1.ielem[2] == 1) {
	goto L19;
    }
    if (icyc[4] > icyc[3]) {
	iz = 2;
    }
    if (icyc[5] > icyc[7 - iz - 1]) {
	iz = 1;
    }
    goto L19;
L18:
    iz = 1;
    if (icyc[1] > icyc[0]) {
	iz = 2;
    }
    if (icyc[2] > icyc[iz - 1]) {
	iz = 3;
    }
L19:
    icyc[7 - iz - 1] = -1;
    ix = 1;
    if (icyc[4] > icyc[5]) {
	ix = 2;
    }
    if (icyc[3] > icyc[7 - ix - 1]) {
	ix = 3;
    }
    iy = 6 - ix - iz;
    for (i__ = 1; i__ <= 3; ++i__) {
	rhelp[i__ - 1] = s00004_1.r__[i__ + ix * 3 - 4];
/* L20: */
	rhelp[i__ + 2] = s00004_1.r__[i__ + iy * 3 - 4];
    }
    rhelp[6] = s00004_1.r__[ix * 3 - 2] * s00004_1.r__[iy * 3 - 1] - 
	    s00004_1.r__[ix * 3 - 1] * s00004_1.r__[iy * 3 - 2];
    rhelp[7] = s00004_1.r__[ix * 3 - 1] * s00004_1.r__[iy * 3 - 3] - 
	    s00004_1.r__[ix * 3 - 3] * s00004_1.r__[iy * 3 - 1];
    rhelp[8] = s00004_1.r__[ix * 3 - 3] * s00004_1.r__[iy * 3 - 2] - 
	    s00004_1.r__[ix * 3 - 2] * s00004_1.r__[iy * 3 - 3];
    r00005_(&coord[4], &c_n1);
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L21: */
	    s00004_1.r__[i__ + j * 3 - 4] = rhelp[i__ + j * 3 - 4];
	}
    }
    r00005_(&coord[4], &c__1);
L22:
    for (i__ = 1; i__ <= 7; ++i__) {
	r00007_(&nat[1], &coord[4], &i__);
/* L23: */
    }
    ncode = 0;
    j = 1;
    for (i__ = 1; i__ <= 20; ++i__) {
	ncode += s00003_1.ielem[i__ - 1] * j;
/* L24: */
	j <<= 1;
    }
L25:
    r00005_(&coord[4], &c_n1);
    total = ew[0] + ew[1] + ew[2];
    for (i__ = 1; i__ <= 3; ++i__) {
	ew[i__ - 1] = total - ew[i__ - 1];
	i__2 = s00002_2.numat;
	for (j = 1; j <= i__2; ++j) {
/* L26: */
	    coord[i__ + j * 3] += s00004_1.shift[i__ - 1];
	}
    }
    jgroup = 0;
    r00008_(&jgroup, &ncode);
    if (jgroup < 1) {
	s00002_2.ierror = 2;
    }
    total = ew[0] * ew[1] * ew[2] / (symres_1.sig * symres_1.sig);
    if (linear) {
	symres_1.rtr = log(ew[0] / symres_1.sig) * 1.9865 + 6.970686;
    }
    if (! linear) {
	symres_1.rtr = log(total) * .98325 + 11.592852;
    }
    return 0;
} /* r00001_ */


/* ================================================================== */

/* Subroutine */ int r00002_(doublereal *coord, doublereal *sina, doublereal *
	cosa, integer *i__, integer *j)
{
    static integer k;
    extern /* Subroutine */ int r00005_(doublereal *, integer *);
    static doublereal buff;

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
    /* Parameter adjustments */
    coord -= 4;

    /* Function Body */
    r00005_(&coord[4], &c_n1);
    for (k = 1; k <= 3; ++k) {
	buff = -(*sina) * s00004_1.r__[k + *i__ * 3 - 4] + *cosa * 
		s00004_1.r__[k + *j * 3 - 4];
	s00004_1.r__[k + *i__ * 3 - 4] = *cosa * s00004_1.r__[k + *i__ * 3 - 
		4] + *sina * s00004_1.r__[k + *j * 3 - 4];
/* L1: */
	s00004_1.r__[k + *j * 3 - 4] = buff;
    }
    r00005_(&coord[4], &c__1);
    return 0;
} /* r00002_ */


/* ==================================================================== */

/* Subroutine */ int r00003_(integer *nat, doublereal *coord, integer *jump)
{
    /* Initialized data */

    static doublereal big = 1e35;
    static doublereal toler = .1;
    static doublereal wink[2] = { .955316618125,.6523581398 };

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    static integer i__;
    extern /* Subroutine */ int r00002_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), r00004_(doublereal *, 
	    integer *), r00005_(doublereal *, integer *), r00007_(integer *, 
	    doublereal *, integer *);
    static doublereal buff, cosa, cosb, sina, sinb;
    static integer jota;
    static doublereal dist, xmin, buff1, wink2;
    static integer index;

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
    /* Parameter adjustments */
    coord -= 4;
    --nat;

    /* Function Body */
    switch (*jump) {
	case 1:  goto L1;
	case 2:  goto L5;
    }
L1:
    s00003_1.ielem[18] = 1;
    index = 0;
    xmin = big;
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	d__1 = coord[i__ * 3 + 1];
/* Computing 2nd power */
	d__2 = coord[i__ * 3 + 2];
/* Computing 2nd power */
	d__3 = coord[i__ * 3 + 3];
	dist = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	if (dist < toler) {
	    goto L2;
	}
	if (dist > xmin) {
	    goto L2;
	}
	index = i__;
	xmin = dist;
L2:
	;
    }
    dist = sqrt(xmin);
    r00005_(&coord[4], &c_n1);
    s00004_1.r__[6] = coord[index * 3 + 1] / dist;
    s00004_1.r__[7] = coord[index * 3 + 2] / dist;
    s00004_1.r__[8] = coord[index * 3 + 3] / dist;
/* Computing 2nd power */
    d__1 = s00004_1.r__[6];
/* Computing 2nd power */
    d__2 = s00004_1.r__[7];
    buff = sqrt(d__1 * d__1 + d__2 * d__2);
/* Computing 2nd power */
    d__1 = s00004_1.r__[6];
/* Computing 2nd power */
    d__2 = s00004_1.r__[8];
    buff1 = sqrt(d__1 * d__1 + d__2 * d__2);
    if (buff > buff1) {
	goto L3;
    }
    s00004_1.r__[0] = s00004_1.r__[8] / buff1;
    s00004_1.r__[1] = 0.;
    s00004_1.r__[2] = -s00004_1.r__[6] / buff1;
    goto L4;
L3:
    s00004_1.r__[0] = s00004_1.r__[7] / buff;
    s00004_1.r__[1] = -s00004_1.r__[6] / buff;
    s00004_1.r__[2] = 0.;
L4:
    s00004_1.r__[3] = s00004_1.r__[7] * s00004_1.r__[2] - s00004_1.r__[1] * 
	    s00004_1.r__[8];
    s00004_1.r__[4] = s00004_1.r__[8] * s00004_1.r__[0] - s00004_1.r__[2] * 
	    s00004_1.r__[6];
    s00004_1.r__[5] = s00004_1.r__[6] * s00004_1.r__[1] - s00004_1.r__[0] * 
	    s00004_1.r__[7];
    r00005_(&coord[4], &c__1);
    return 0;
L5:
    wink2 = 0.;
    if (s00003_1.ielem[7] < 1) {
	goto L8;
    }
    for (i__ = 1; i__ <= 2; ++i__) {
	jota = 18 - (i__ << 2);
	wink2 = wink[i__ - 1];
	sina = sin(wink2);
	cosa = cos(wink2);
	r00002_(&coord[4], &sina, &cosa, &c__1, &c__3);
	r00007_(&nat[1], &coord[4], &jota);
	if (s00003_1.ielem[jota - 1] > 0) {
	    goto L7;
	}
	wink2 = -wink2;
	sinb = sin(wink2 * 2.);
	cosb = cos(wink2 * 2.);
	r00002_(&coord[4], &sinb, &cosb, &c__1, &c__3);
	r00007_(&nat[1], &coord[4], &jota);
	if (s00003_1.ielem[jota - 1] > 0) {
	    goto L7;
	}
	r00002_(&coord[4], &sina, &cosa, &c__1, &c__3);
/* L6: */
    }
L7:
    r00007_(&nat[1], &coord[4], &c__9);
    if (s00003_1.ielem[9] > 0) {
	r00007_(&nat[1], &coord[4], &c__17);
    }
    goto L10;
L8:
    wink2 = -wink[0];
    if (s00003_1.ielem[9] > 0) {
	wink2 = -wink[1];
    }
    sina = -sin(wink2);
    cosa = cos(wink2);
    r00002_(&coord[4], &sina, &cosa, &c__1, &c__3);
    r00007_(&nat[1], &coord[4], &c__8);
    d__1 = -sina;
    r00002_(&coord[4], &d__1, &cosa, &c__1, &c__3);
    if (s00003_1.ielem[7] > 0) {
	goto L10;
    }
    if (s00003_1.ielem[8] > 0) {
	goto L9;
    }
    wink2 = -wink2;
    goto L10;
L9:
    r00002_(&coord[4], &c_b101, &c_b101, &c__1, &c__2);
L10:
    s00003_1.cub[0] = cos(wink2);
    s00003_1.cub[8] = s00003_1.cub[0];
    s00003_1.cub[6] = sin(wink2);
    s00003_1.cub[2] = -s00003_1.cub[6];
    r00004_(s00003_1.cub, &c__8);
    r00004_(s00003_1.cub, &c__15);
    r00007_(&nat[1], &coord[4], &c__8);
    r00007_(&nat[1], &coord[4], &c__15);
    return 0;
} /* r00003_ */


/* ===================================================================== */

/* Subroutine */ int r00004_(doublereal *fmat, integer *iplace)
{
    static integer i__, j, k, l;
    static doublereal help[9]	/* was [3][3] */;

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
    /* Parameter adjustments */
    fmat -= 4;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    help[i__ + j * 3 - 4] = 0.;
	    for (k = 1; k <= 3; ++k) {
		for (l = 1; l <= 3; ++l) {
/* L1: */
		    help[i__ + j * 3 - 4] += fmat[i__ + l * 3] * fmat[j + k * 
			    3] * s00003_1.elem[l + (k + *iplace * 3) * 3 - 13]
			    ;
		}
	    }
	}
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L2: */
	    s00003_1.elem[i__ + (j + *iplace * 3) * 3 - 13] = help[i__ + j * 
		    3 - 4];
	}
    }
    return 0;
} /* r00004_ */


/* ========================================================================== */

/* Subroutine */ int r00005_(doublereal *coord, integer *jump)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k;
    static doublereal help[3];

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
    /* Parameter adjustments */
    coord -= 4;

    /* Function Body */
    if (*jump < 0) {
	goto L3;
    }
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L1: */
	    help[j - 1] = coord[j + i__ * 3];
	}
	for (j = 1; j <= 3; ++j) {
	    coord[j + i__ * 3] = 0.;
	    for (k = 1; k <= 3; ++k) {
/* L2: */
		coord[j + i__ * 3] += s00004_1.r__[k + j * 3 - 4] * help[k - 
			1];
	    }
	}
    }
    return 0;
L3:
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L4: */
	    help[j - 1] = coord[j + i__ * 3];
	}
	for (j = 1; j <= 3; ++j) {
	    coord[j + i__ * 3] = 0.;
	    for (k = 1; k <= 3; ++k) {
/* L5: */
		coord[j + i__ * 3] += s00004_1.r__[j + k * 3 - 4] * help[k - 
			1];
	    }
	}
    }
    return 0;
} /* r00005_ */


/* ======================================================================== */

/* Subroutine */ int r00006_(integer *ioper, integer *iplace)
{
    /* Initialized data */

    static integer j[60]	/* was [3][20] */ = { 1,-1,-1,-1,1,-1,-1,-1,1,
	    1,1,-1,1,-1,1,-1,1,1,-1,-1,-1,3,0,1,4,0,1,5,0,1,6,0,1,7,0,1,8,0,1,
	    4,0,-1,6,0,-1,8,0,-1,10,0,-1,12,0,-1,5,0,-1,0,0,-1 };
    static doublereal twopi = 6.283185308;

    /* Builtin functions */
    double cos(doublereal), sin(doublereal);

    /* Local variables */
    static integer i__, k;
    extern /* Subroutine */ int r00004_(doublereal *, integer *);
    static doublereal angle;

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
    for (i__ = 1; i__ <= 3; ++i__) {
	for (k = 1; k <= 3; ++k) {
/* L1: */
	    s00003_1.elem[i__ + (k + *iplace * 3) * 3 - 13] = 0.f;
	}
/* L2: */
	s00003_1.elem[i__ + (i__ + *iplace * 3) * 3 - 13] = (doublereal) j[
		i__ + *ioper * 3 - 4];
    }
    if (*ioper == 20) {
	goto L4;
    }
    if (j[*ioper * 3 - 3] < 2) {
	goto L3;
    }
    angle = twopi / (real) j[*ioper * 3 - 3];
    s00003_1.elem[(*iplace * 3 + 1) * 3 - 12] = cos(angle);
    s00003_1.elem[(*iplace * 3 + 2) * 3 - 11] = s00003_1.elem[(*iplace * 3 + 
	    1) * 3 - 12];
    s00003_1.elem[(*iplace * 3 + 1) * 3 - 11] = sin(angle);
    s00003_1.elem[(*iplace * 3 + 2) * 3 - 12] = -s00003_1.elem[(*iplace * 3 + 
	    1) * 3 - 11];
L3:
    if (*ioper == 8 || *ioper == 15) {
	r00004_(s00003_1.cub, iplace);
    }
    return 0;
L4:
    s00003_1.elem[(*iplace * 3 + 2) * 3 - 12] = 1.;
    s00003_1.elem[(*iplace * 3 + 1) * 3 - 11] = 1.;
    return 0;
} /* r00006_ */


/* ====================================================================== */

/* Subroutine */ int r00007_(integer *nat, doublereal *coord, integer *ioper)
{
    /* Initialized data */

    static doublereal toler = .01;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j;
    static doublereal help[3];
    static integer iresul;

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
    /* Parameter adjustments */
    coord -= 4;
    --nat;

    /* Function Body */
    iresul = 1;
    s00002_2.iqual = 0;
    i__1 = s00002_2.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	help[0] = coord[i__ * 3 + 1] * s00003_1.elem[(*ioper * 3 + 1) * 3 - 
		12] + coord[i__ * 3 + 2] * s00003_1.elem[(*ioper * 3 + 2) * 3 
		- 12] + coord[i__ * 3 + 3] * s00003_1.elem[(*ioper * 3 + 3) * 
		3 - 12];
	help[1] = coord[i__ * 3 + 1] * s00003_1.elem[(*ioper * 3 + 1) * 3 - 
		11] + coord[i__ * 3 + 2] * s00003_1.elem[(*ioper * 3 + 2) * 3 
		- 11] + coord[i__ * 3 + 3] * s00003_1.elem[(*ioper * 3 + 3) * 
		3 - 11];
	help[2] = coord[i__ * 3 + 1] * s00003_1.elem[(*ioper * 3 + 1) * 3 - 
		10] + coord[i__ * 3 + 2] * s00003_1.elem[(*ioper * 3 + 2) * 3 
		- 10] + coord[i__ * 3 + 3] * s00003_1.elem[(*ioper * 3 + 3) * 
		3 - 10];
	i__2 = s00002_2.numat;
	for (j = 1; j <= i__2; ++j) {
	    if (nat[i__] != nat[j]) {
		goto L1;
	    }
	    if ((d__1 = coord[j * 3 + 1] - help[0], abs(d__1)) > toler) {
		goto L1;
	    }
	    if ((d__1 = coord[j * 3 + 2] - help[1], abs(d__1)) > toler) {
		goto L1;
	    }
	    if ((d__1 = coord[j * 3 + 3] - help[2], abs(d__1)) > toler) {
		goto L1;
	    }
	    s00003_1.jelem[*ioper + i__ * 20 - 21] = j;
	    if (i__ == j) {
		++s00002_2.iqual;
	    }
	    goto L2;
L1:
	    ;
	}
	iresul = 0;
L2:
	;
    }
    s00003_1.ielem[*ioper - 1] = iresul;
    return 0;
} /* r00007_ */


/* ===================================================================== */

/* Subroutine */ int r00008_(integer *igroup, integer *ncode)
{
    /* Initialized data */

    static integer j[43] = { 1010001,2020004,2020011,2020018,3020025,4030034,
	    5030050,6040069,7040098,8050131,4040177,3030198,5050211,4040242,
	    6060263,4040306,3030327,5050340,4040371,6060392,4040435,6040456,
	    8060485,10060540,12080607,8080712,6060785,10100828,8080939,
	    12121012,5051169,6061200,7071243,8081300,9091373,4031464,6041480,
	    8051509,5051555,10101586,10101697,2031808,3061818 };
    static integer isigma[43] = { 1,1,1,2,3,4,5,6,7,8,4,6,8,10,12,2,3,4,5,6,2,
	    3,4,5,6,4,6,8,10,12,4,6,8,10,12,2,3,4,12,24,60,1,2 };
    static struct {
	char e_1[8];
	integer e_2;
	char e_3[8];
	integer e_4[2];
	char e_5[4];
	integer e_6[2];
	char e_7[8];
	integer e_8[2];
	char e_9[4];
	integer e_10[2];
	char e_11[8];
	integer e_12[2];
	char e_13[4];
	integer e_14[2];
	char e_15[8];
	integer e_16[3];
	char e_17[4];
	integer e_18[3];
	char e_19[8];
	integer e_20[4];
	char e_21[4];
	integer e_22[4];
	char e_23[4];
	integer e_24[4];
	char e_25[8];
	integer e_26[5];
	char e_27[4];
	integer e_28[5];
	char e_29[4];
	integer e_30[5];
	char e_31[8];
	integer e_32[6];
	char e_33[4];
	integer e_34[6];
	char e_35[4];
	integer e_36[6];
	char e_37[4];
	integer e_38[6];
	char e_39[8];
	integer e_40[7];
	char e_41[4];
	integer e_42[7];
	char e_43[4];
	integer e_44[7];
	char e_45[4];
	integer e_46[7];
	char e_47[8];
	integer e_48[8];
	char e_49[4];
	integer e_50[8];
	char e_51[4];
	integer e_52[8];
	char e_53[4];
	integer e_54[8];
	char e_55[4];
	integer e_56[8];
	char e_57[8];
	integer e_58[4];
	char e_59[4];
	integer e_60[4];
	char e_61[4];
	integer e_62[4];
	char e_63[4];
	integer e_64[4];
	char e_65[8];
	integer e_66[3];
	char e_67[4];
	integer e_68[3];
	char e_69[4];
	integer e_70[3];
	char e_71[8];
	integer e_72[5];
	char e_73[4];
	integer e_74[5];
	char e_75[4];
	integer e_76[5];
	char e_77[4];
	integer e_78[5];
	char e_79[4];
	integer e_80[5];
	char e_81[8];
	integer e_82[4];
	char e_83[4];
	integer e_84[4];
	char e_85[4];
	integer e_86[4];
	char e_87[4];
	integer e_88[4];
	char e_89[8];
	integer e_90[6];
	char e_91[4];
	integer e_92[6];
	char e_93[4];
	integer e_94[6];
	char e_95[4];
	integer e_96[6];
	char e_97[4];
	integer e_98[6];
	char e_99[4];
	integer e_100[6];
	char e_101[8];
	integer e_102[4];
	char e_103[4];
	integer e_104[4];
	char e_105[4];
	integer e_106[4];
	char e_107[4];
	integer e_108[4];
	char e_109[8];
	integer e_110[3];
	char e_111[4];
	integer e_112[3];
	char e_113[4];
	integer e_114[3];
	char e_115[8];
	integer e_116[5];
	char e_117[4];
	integer e_118[5];
	char e_119[4];
	integer e_120[5];
	char e_121[4];
	integer e_122[5];
	char e_123[4];
	integer e_124[5];
	char e_125[8];
	integer e_126[4];
	char e_127[4];
	integer e_128[4];
	char e_129[4];
	integer e_130[4];
	char e_131[4];
	integer e_132[4];
	char e_133[8];
	integer e_134[6];
	char e_135[4];
	integer e_136[6];
	char e_137[4];
	integer e_138[6];
	char e_139[4];
	integer e_140[6];
	char e_141[4];
	integer e_142[6];
	char e_143[4];
	integer e_144[6];
	char e_145[8];
	integer e_146[4];
	char e_147[4];
	integer e_148[4];
	char e_149[4];
	integer e_150[4];
	char e_151[4];
	integer e_152[4];
	char e_153[8];
	integer e_154[6];
	char e_155[4];
	integer e_156[6];
	char e_157[4];
	integer e_158[6];
	char e_159[4];
	integer e_160[6];
	char e_161[8];
	integer e_162[8];
	char e_163[4];
	integer e_164[8];
	char e_165[4];
	integer e_166[8];
	char e_167[4];
	integer e_168[8];
	char e_169[4];
	integer e_170[8];
	char e_171[4];
	integer e_172[8];
	char e_173[8];
	integer e_174[10];
	char e_175[4];
	integer e_176[10];
	char e_177[4];
	integer e_178[10];
	char e_179[4];
	integer e_180[10];
	char e_181[4];
	integer e_182[10];
	char e_183[4];
	integer e_184[10];
	char e_185[8];
	integer e_186[12];
	char e_187[4];
	integer e_188[12];
	char e_189[4];
	integer e_190[12];
	char e_191[4];
	integer e_192[12];
	char e_193[4];
	integer e_194[12];
	char e_195[4];
	integer e_196[12];
	char e_197[4];
	integer e_198[12];
	char e_199[4];
	integer e_200[12];
	char e_201[8];
	integer e_202[8];
	char e_203[4];
	integer e_204[8];
	char e_205[4];
	integer e_206[8];
	char e_207[4];
	integer e_208[8];
	char e_209[4];
	integer e_210[8];
	char e_211[4];
	integer e_212[8];
	char e_213[4];
	integer e_214[8];
	char e_215[4];
	integer e_216[8];
	char e_217[8];
	integer e_218[6];
	char e_219[4];
	integer e_220[6];
	char e_221[4];
	integer e_222[6];
	char e_223[4];
	integer e_224[6];
	char e_225[4];
	integer e_226[6];
	char e_227[4];
	integer e_228[6];
	char e_229[8];
	integer e_230[10];
	char e_231[4];
	integer e_232[10];
	char e_233[4];
	integer e_234[10];
	char e_235[4];
	integer e_236[10];
	char e_237[4];
	integer e_238[10];
	char e_239[4];
	integer e_240[10];
	char e_241[4];
	integer e_242[10];
	char e_243[4];
	integer e_244[10];
	char e_245[4];
	integer e_246[10];
	char e_247[4];
	integer e_248[10];
	char e_249[8];
	integer e_250[8];
	char e_251[4];
	integer e_252[8];
	char e_253[4];
	integer e_254[8];
	char e_255[4];
	integer e_256[8];
	char e_257[4];
	integer e_258[8];
	char e_259[4];
	integer e_260[8];
	char e_261[4];
	integer e_262[8];
	char e_263[4];
	integer e_264[8];
	char e_265[8];
	integer e_266[12];
	char e_267[4];
	integer e_268[12];
	char e_269[4];
	integer e_270[12];
	char e_271[4];
	integer e_272[12];
	char e_273[4];
	integer e_274[12];
	char e_275[4];
	integer e_276[12];
	char e_277[4];
	integer e_278[12];
	char e_279[4];
	integer e_280[12];
	char e_281[4];
	integer e_282[12];
	char e_283[4];
	integer e_284[12];
	char e_285[4];
	integer e_286[12];
	char e_287[4];
	integer e_288[12];
	char e_289[8];
	integer e_290[5];
	char e_291[4];
	integer e_292[5];
	char e_293[4];
	integer e_294[5];
	char e_295[4];
	integer e_296[5];
	char e_297[4];
	integer e_298[5];
	char e_299[8];
	integer e_300[6];
	char e_301[4];
	integer e_302[6];
	char e_303[4];
	integer e_304[6];
	char e_305[4];
	integer e_306[6];
	char e_307[4];
	integer e_308[6];
	char e_309[4];
	integer e_310[6];
	char e_311[8];
	integer e_312[7];
	char e_313[4];
	integer e_314[7];
	char e_315[4];
	integer e_316[7];
	char e_317[4];
	integer e_318[7];
	char e_319[4];
	integer e_320[7];
	char e_321[4];
	integer e_322[7];
	char e_323[4];
	integer e_324[7];
	char e_325[8];
	integer e_326[8];
	char e_327[4];
	integer e_328[8];
	char e_329[4];
	integer e_330[8];
	char e_331[4];
	integer e_332[8];
	char e_333[4];
	integer e_334[8];
	char e_335[4];
	integer e_336[8];
	char e_337[4];
	integer e_338[8];
	char e_339[4];
	integer e_340[8];
	char e_341[8];
	integer e_342[9];
	char e_343[4];
	integer e_344[9];
	char e_345[4];
	integer e_346[9];
	char e_347[4];
	integer e_348[9];
	char e_349[4];
	integer e_350[9];
	char e_351[4];
	integer e_352[9];
	char e_353[4];
	integer e_354[9];
	char e_355[4];
	integer e_356[9];
	char e_357[4];
	integer e_358[9];
	char e_359[8];
	integer e_360[4];
	char e_361[4];
	integer e_362[4];
	char e_363[4];
	integer e_364[4];
	char e_365[8];
	integer e_366[6];
	char e_367[4];
	integer e_368[6];
	char e_369[4];
	integer e_370[6];
	char e_371[4];
	integer e_372[6];
	char e_373[8];
	integer e_374[8];
	char e_375[4];
	integer e_376[8];
	char e_377[4];
	integer e_378[8];
	char e_379[4];
	integer e_380[8];
	char e_381[4];
	integer e_382[8];
	char e_383[8];
	integer e_384[5];
	char e_385[4];
	integer e_386[5];
	char e_387[4];
	integer e_388[5];
	char e_389[4];
	integer e_390[5];
	char e_391[4];
	integer e_392[5];
	char e_393[8];
	integer e_394[10];
	char e_395[4];
	integer e_396[10];
	char e_397[4];
	integer e_398[10];
	char e_399[4];
	integer e_400[10];
	char e_401[4];
	integer e_402[10];
	char e_403[4];
	integer e_404[10];
	char e_405[4];
	integer e_406[10];
	char e_407[4];
	integer e_408[10];
	char e_409[4];
	integer e_410[10];
	char e_411[4];
	integer e_412[10];
	char e_413[8];
	integer e_414[10];
	char e_415[4];
	integer e_416[10];
	char e_417[4];
	integer e_418[10];
	char e_419[4];
	integer e_420[10];
	char e_421[4];
	integer e_422[10];
	char e_423[4];
	integer e_424[10];
	char e_425[4];
	integer e_426[10];
	char e_427[4];
	integer e_428[10];
	char e_429[4];
	integer e_430[10];
	char e_431[4];
	integer e_432[10];
	char e_433[8];
	integer e_434[2];
	char e_435[4];
	integer e_436[2];
	char e_437[4];
	integer e_438[2];
	char e_439[8];
	integer e_440[3];
	char e_441[4];
	integer e_442[3];
	char e_443[4];
	integer e_444[3];
	char e_445[4];
	integer e_446[3];
	char e_447[4];
	integer e_448[3];
	char e_449[4];
	integer e_450[3];
	integer fill_451[2];
	} equiv_42 = { "C1  A   ", 0, "CS  A'  ", 8, 20104, "A\"  ", 1, -1, 
		"CI  AG  ", 64, 10107, "AU  ", 1, -1, "C2  A   ", 4, 2140103, 
		"B   ", 1, -1, "C3  A   ", 128, 3140108, 3240122, "E   ", 2, 
		-1, -1, "C4  A   ", 260, 4140109, 2140103, 4340123, "B   ", 1,
		 -1, 1, -1, "E   ", 2, 0, -2, 0, "C5  A   ", 512, 5140110, 
		5240122, 5340123, 5440124, "E1  ", 2, 51, 52, 52, 51, "E2  ", 
		2, 52, 51, 51, 52, "C6  A   ", 1156, 6140111, 3140108, 
		2140103, 3240133, 6540125, "B   ", 1, -1, 1, -1, 1, -1, "E1  "
		, 2, 1, -1, -2, -1, 1, "E2  ", 2, -1, -1, 2, -1, -1, "C7  A "
		"  ", 2048, 7140112, 7240122, 7340123, 7440124, 7540125, 
		7640126, "E1  ", 2, 71, 72, 73, 73, 72, 71, "E2  ", 2, 72, 73,
		 71, 71, 73, 72, "E3  ", 2, 73, 71, 72, 72, 71, 73, "C8  A   "
		, 4356, 8140113, 4140109, 2140103, 4340134, 8340123, 8540124, 
		8740125, "B   ", 1, -1, 1, 1, 1, -1, -1, -1, "E1  ", 2, 81, 0,
		 -2, 0, 83, 83, 81, "E2  ", 2, 0, -2, 2, -2, 0, 0, 0, "E3  ", 
		2, 83, 0, -2, 0, 81, 81, 83, "D2  A   ", 7, 2140103, 2140102, 
		2140101, "B1  ", 1, 1, -1, -1, "B2  ", 1, -1, 1, -1, "B3  ", 
		1, -1, -1, 1, "D3  A1  ", 129, 3140208, 2140301, "A2  ", 1, 1,
		 -1, "E   ", 2, -1, 0, "D4  A1  ", 263, 4140209, 2140103, 
		2140201, 2140220, "A2  ", 1, 1, 1, -1, -1, "B1  ", 1, -1, 1, 
		1, -1, "B2  ", 1, -1, 1, -1, 1, "E   ", 2, 0, -2, 0, 0, "D5 "
		" A1  ", 513, 5140210, 5240222, 2140501, "A2  ", 1, 1, 1, -1, 
		"E1  ", 2, 51, 52, 0, "E2  ", 2, 52, 51, 0, "D6  A1  ", 1159, 
		6140211, 3140208, 2140103, 2140301, 2140302, "A2  ", 1, 1, 1, 
		1, -1, -1, "B1  ", 1, -1, 1, -1, 1, -1, "B2  ", 1, -1, 1, -1, 
		-1, 1, "E1  ", 2, 1, -1, -2, 0, 0, "E2  ", 2, -1, -1, 2, 0, 0,
		 "C2V A1  ", 52, 2140103, 20105, 20106, "A2  ", 1, 1, -1, -1, 
		"B1  ", 1, -1, 1, -1, "B2  ", 1, -1, -1, 1, "C3V A1  ", 144, 
		3140208, 20305, "A2  ", 1, 1, -1, "E   ", 2, -1, 0, "C4V A1  "
		, 308, 4140209, 2140103, 20205, 20224, "A2  ", 1, 1, 1, -1, 
		-1, "B1  ", 1, -1, 1, 1, -1, "B2  ", 1, -1, 1, -1, 1, "E   ", 
		2, 0, -2, 0, 0, "C5V A1  ", 528, 5140210, 5240222, 20505, 
		"A2  ", 1, 1, 1, -1, "E1  ", 2, 51, 52, 0, "E2  ", 2, 52, 51, 
		0, "C6V A1  ", 1204, 6140211, 3140208, 2140103, 20305, 20306, 
		"A2  ", 1, 1, 1, 1, -1, -1, "B1  ", 1, -1, 1, -1, 1, -1, 
		"B2  ", 1, -1, 1, -1, -1, 1, "E1  ", 2, 1, -1, -2, 0, 0, 
		"E2  ", 2, -1, -1, 2, 0, 0, "C2H AG  ", 76, 2140103, 10107, 
		20104, "BG  ", 1, -1, 1, -1, "AU  ", 1, 1, -1, -1, "BU  ", 1, 
		-1, -1, 1, "C3H A'  ", 136, 3140108, 3240122, 20104, 3130124, 
		3530143, "E'  ", 2, -1, -1, 2, -1, -1, "A\"  ", 1, 1, 1, -1, 
		-1, -1, "E\"  ", 2, -1, -1, -2, 1, 1, "C4H AG  ", 8524, 
		4140109, 2140103, 4340123, 10107, 4330152, 20104, 4130114, 
		"BG  ", 1, -1, 1, -1, 1, -1, 1, -1, "EG  ", 2, 0, -2, 0, 2, 0,
		 -2, 0, "AU  ", 1, 1, 1, 1, -1, -1, -1, -1, "BU  ", 1, -1, 1, 
		-1, -1, 1, -1, 1, "EU  ", 2, 0, -2, 0, -2, 0, 2, 0, "C5H A'  "
		, 520, 5140110, 5240122, 5340123, 5440124, 20104, 5130119, 
		5730163, 5330164, 5930165, "E1' ", 2, 51, 52, 52, 51, 2, 51, 
		52, 52, 51, "E2' ", 2, 52, 51, 51, 52, 2, 52, 51, 51, 52, 
		"A\"  ", 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, "E1\" ", 2, 51, 
		52, 52, 51, -2, 103, 101, 101, 103, "E2\" ", 2, 52, 51, 51, 
		52, -2, 101, 103, 103, 101, "C6H AG  ", 17612, 6140111, 
		3140108, 2140103, 3240133, 6540125, 10107, 20104, 3530127, 
		6530137, 6130115, 3130183, "BG  ", 1, -1, 1, -1, 1, -1, 1, -1,
		 -1, 1, 1, -1, "E1G ", 2, 1, -1, -2, -1, 1, 2, -2, 1, -1, -1, 
		1, "E2G ", 2, -1, -1, 2, -1, -1, 2, 2, -1, -1, -1, -1, "AU  ",
		 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, "BU  ", 1, -1, 1, 
		-1, 1, -1, -1, 1, 1, -1, -1, 1, "E1U ", 2, 1, -1, -2, -1, 1, 
		-2, 2, -1, 1, 1, -1, "E2U ", 2, -1, -1, 2, -1, -1, -2, -2, 1, 
		1, 1, 1, "D2H AG  ", 127, 2140103, 2140102, 2140101, 10107, 
		20104, 20105, 20106, "B1G ", 1, 1, -1, -1, 1, 1, -1, -1, 
		"B2G ", 1, -1, 1, -1, 1, -1, 1, -1, "B3G ", 1, -1, -1, 1, 1, 
		-1, -1, 1, "AU  ", 1, 1, 1, 1, -1, -1, -1, -1, "B1U ", 1, 1, 
		-1, -1, -1, -1, 1, 1, "B2U ", 1, -1, 1, -1, -1, 1, -1, 1, 
		"B3U ", 1, -1, -1, 1, -1, 1, 1, -1, "D3H A1' ", 153, 3140208, 
		2140301, 20104, 3130224, 20305, "A2' ", 1, 1, -1, 1, 1, -1, 
		"E'  ", 2, -1, 0, 2, -1, 0, "A1\" ", 1, 1, 1, -1, -1, -1, 
		"A2\" ", 1, 1, -1, -1, -1, 1, "E\"  ", 2, -1, 0, -2, 1, 0, 
		"D4H A1G ", 8575, 4140209, 2140103, 2140201, 2140220, 10107, 
		4130214, 20104, 20205, 20229, "A2G ", 1, 1, 1, -1, -1, 1, 1, 
		1, -1, -1, "B1G ", 1, -1, 1, 1, -1, 1, -1, 1, 1, -1, "B2G ", 
		1, -1, 1, -1, 1, 1, -1, 1, -1, 1, "EG  ", 2, 0, -2, 0, 0, 2, 
		0, -2, 0, 0, "A1U ", 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, "A2U "
		, 1, 1, 1, -1, -1, -1, -1, -1, 1, 1, "B1U ", 1, -1, 1, 1, -1, 
		-1, 1, -1, -1, 1, "B2U ", 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 
		"EU  ", 2, 0, -2, 0, 0, -2, 0, 2, 0, 0, "D5H A1' ", 537, 
		5140210, 5240222, 2140501, 20104, 5130219, 5330263, 20505, 
		"A2' ", 1, 1, 1, -1, 1, 1, 1, -1, "E1' ", 2, 51, 52, 0, 2, 51,
		 52, 0, "E2' ", 2, 52, 51, 0, 2, 52, 51, 0, "A1\" ", 1, 1, 1, 
		1, -1, -1, -1, -1, "A2\" ", 1, 1, 1, -1, -1, -1, -1, 1, "E"
		"1\" ", 2, 51, 52, 0, -2, 103, 101, 0, "E2\" ", 2, 52, 51, 0, 
		-2, 101, 103, 0, "D6H A1G ", 17663, 6140211, 3140208, 2140103,
		 2140301, 2140302, 10107, 20104, 6130215, 3130238, 20306, 
		20305, "A2G ", 1, 1, 1, 1, -1, -1, 1, 1, 1, 1, -1, -1, "B1G ",
		 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, "B2G ", 1, -1, 1, 
		-1, -1, 1, 1, -1, 1, -1, -1, 1, "E1G ", 2, 1, -1, -2, 0, 0, 2,
		 -2, -1, 1, 0, 0, "E2G ", 2, -1, -1, 2, 0, 0, 2, 2, -1, -1, 0,
		 0, "A1U ", 1, 1, 1, 1, 1, 1, -1, -1, -1, -1, -1, -1, "A2U ", 
		1, 1, 1, 1, -1, -1, -1, -1, -1, -1, 1, 1, "B1U ", 1, -1, 1, 
		-1, 1, -1, -1, 1, -1, 1, -1, 1, "B2U ", 1, -1, 1, -1, -1, 1, 
		-1, 1, -1, 1, 1, -1, "E1U ", 2, 1, -1, -2, 0, 0, -2, 2, 1, -1,
		 0, 0, "E2U ", 2, -1, -1, 2, 0, 0, -2, -2, 1, 1, 0, 0, "D2D "
		"A1  ", 8244, 4130214, 2140103, 2140220, 20205, "A2  ", 1, 1, 
		1, -1, -1, "B1  ", 1, -1, 1, 1, -1, "B2  ", 1, -1, 1, -1, 1, 
		"E   ", 2, 0, -2, 0, 0, "D3D A1G ", 16594, 3140208, 2140302, 
		10107, 6130215, 20305, "A2G ", 1, 1, -1, 1, 1, -1, "EG  ", 2, 
		-1, 0, 2, -1, 0, "A1U ", 1, 1, 1, -1, -1, -1, "A2U ", 1, 1, 
		-1, -1, -1, 1, "EU  ", 2, -1, 0, -2, 1, 0, "D4D A1  ", 33076, 
		8130216, 4140209, 8330223, 2140103, 20405, 2140426, "A2  ", 1,
		 1, 1, 1, 1, -1, -1, "B1  ", 1, -1, 1, -1, 1, -1, 1, "B2  ", 
		1, -1, 1, -1, 1, 1, -1, "E1  ", 2, 81, 0, 83, -2, 0, 0, "E2  "
		, 2, 0, -2, 0, 2, 0, 0, "E3  ", 2, 83, 0, 81, -2, 0, 0, "D5D"
		" A1G ", 66130, 5140210, 5240222, 2140502, 10107, 10130217, 
		10330226, 20505, "A2G ", 1, 1, 1, -1, 1, 1, 1, -1, "E1G ", 2, 
		51, 52, 0, 2, 52, 51, 0, "E2G ", 2, 52, 51, 0, 2, 51, 52, 0, 
		"A1U ", 1, 1, 1, 1, -1, -1, -1, -1, "A2U ", 1, 1, 1, -1, -1, 
		-1, -1, 1, "E1U ", 2, 51, 52, 0, -2, 101, 103, 0, "E2U ", 2, 
		52, 51, 0, -2, 103, 101, 0, "D6D A1  ", 140468, 12130218, 
		6140211, 4130214, 3140208, 12530225, 2140103, 20605, 2140620, 
		"A2  ", 1, 1, 1, 1, 1, 1, 1, -1, -1, "B1  ", 1, -1, 1, -1, 1, 
		-1, 1, -1, 1, "B2  ", 1, -1, 1, -1, 1, -1, 1, 1, -1, "E1  ", 
		2, 121, 1, 0, -1, 125, -2, 0, 0, "E2  ", 2, 1, -1, -2, -1, 1, 
		2, 0, 0, "E3  ", 2, 0, -2, 0, 2, 0, -2, 0, 0, "E4  ", 2, -1, 
		-1, 2, -1, -1, 2, 0, 0, "E5  ", 2, 125, 1, 0, -1, 121, -2, 0, 
		0, "S4  A   ", 8196, 4130114, 2140103, 4330123, "B   ", 1, -1,
		 1, -1, "E   ", 2, 0, -2, 0, "S6  AG  ", 16576, 3140108, 
		3240122, 10107, 6530124, 6130115, "EG  ", 2, -1, -1, 2, -1, 
		-1, "AU  ", 1, 1, 1, -1, -1, -1, "EU  ", 2, -1, -1, -2, 1, 1, 
		"S8  A   ", 33028, 8130116, 4140109, 8330123, 2140103, 
		8530125, 4340135, 8730127, "B   ", 1, -1, 1, -1, 1, -1, 1, -1,
		 "E1  ", 2, 81, 0, 83, -2, 83, 0, 81, "E2  ", 2, 0, -2, 0, 2, 
		0, -2, 0, "E3  ", 2, 83, 0, 81, -2, 81, 0, 83, "TD  A1  ", 
		270516, 3140808, 2140303, 4130614, 20605, "A2  ", 1, 1, 1, -1,
		 -1, "E   ", 2, -1, 2, 0, 0, "T1  ", 3, 0, -1, 1, -1, "T2  ", 
		3, 0, -1, -1, 1, "OH  A1G ", 287231, 3140808, 2140601, 
		4140609, 2140303, 10107, 4130614, 6130815, 20304, 20605, 
		"A2G ", 1, 1, -1, -1, 1, 1, -1, 1, 1, -1, "EG  ", 2, -1, 0, 0,
		 2, 2, 0, -1, 2, 0, "T1G ", 3, 0, -1, 1, -1, 3, 1, 0, -1, -1, 
		"T2G ", 3, 0, 1, -1, -1, 3, -1, 0, -1, 1, "A1U ", 1, 1, 1, 1, 
		1, -1, -1, -1, -1, -1, "A2U ", 1, 1, -1, -1, 1, -1, 1, -1, -1,
		 1, "EU  ", 2, -1, 0, 0, 2, -2, 0, 1, -2, 0, "T1U ", 3, 0, -1,
		 1, -1, -3, -1, 0, 1, 1, "T2U ", 3, 0, 1, -1, -1, -3, 1, 0, 1,
		 -1, "IH  AG  ", 344786, 5141210, 5241222, 3142008, 2141502, 
		10107, 10131217, 10331227, 6132015, 21505, "T1G ", 3, 101, 
		103, 0, -1, 3, 103, 101, 0, -1, "T2G ", 3, 103, 101, 0, -1, 3,
		 101, 103, 0, -1, "GG  ", 4, -1, -1, 1, 0, 4, -1, -1, 1, 0, 
		"HG  ", 5, 0, 0, -1, 1, 5, 0, 0, -1, 1, "AU  ", 1, 1, 1, 1, 1,
		 -1, -1, -1, -1, -1, "T1U ", 3, 101, 103, 0, -1, -3, 51, 52, 
		0, 1, "T2U ", 3, 103, 101, 0, -1, -3, 52, 51, 0, 1, "GU  ", 4,
		 -1, -1, 1, 0, -4, 1, 1, -1, 0, "HU  ", 5, 0, 0, -1, 1, -5, 0,
		 0, 1, -1, "C*V SI  ", 524340, 4140109, "PI  ", 2, 0, "DE  ", 
		2, -2, "D*H SIG ", 524415, 4140109, 10107, "PIG ", 2, 0, 2, 
		"DEG ", 2, -2, 2, "SIU ", 1, 1, -1, "PIU ", 2, 0, -2, "DEU ", 
		2, -2, -2 };


    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double cos(doublereal);

    /* Local variables */
    static integer i__, k;
#define c1 ((integer *)&equiv_42)
#define c2 ((integer *)&equiv_42 + 17)
#define c3 ((integer *)&equiv_42 + 24)
#define c4 ((integer *)&equiv_42 + 33)
#define c5 ((integer *)&equiv_42 + 49)
#define c6 ((integer *)&equiv_42 + 68)
#define c7 ((integer *)&equiv_42 + 97)
#define c8 ((integer *)&equiv_42 + 130)
#define d2 ((integer *)&equiv_42 + 176)
#define d3 ((integer *)&equiv_42 + 197)
#define d4 ((integer *)&equiv_42 + 210)
#define d5 ((integer *)&equiv_42 + 241)
#define d6 ((integer *)&equiv_42 + 262)
#define s4 ((integer *)&equiv_42 + 1463)
#define s6 ((integer *)&equiv_42 + 1479)
#define s8 ((integer *)&equiv_42 + 1508)
#define ci ((integer *)&equiv_42 + 10)
#define dh ((integer *)&equiv_42 + 1817)
#define ih ((integer *)&equiv_42 + 1696)
    static doublereal fn;
#define cs ((integer *)&equiv_42 + 3)
#define oh ((integer *)&equiv_42 + 1585)
#define td ((integer *)&equiv_42 + 1554)
#define cv ((integer *)&equiv_42 + 1807)
    static doublereal fz;
    static integer nz;
#define d2d ((integer *)&equiv_42 + 1168)
#define d3d ((integer *)&equiv_42 + 1199)
#define d4d ((integer *)&equiv_42 + 1242)
#define c2h ((integer *)&equiv_42 + 434)
#define c3h ((integer *)&equiv_42 + 455)
#define c4h ((integer *)&equiv_42 + 484)
#define c5h ((integer *)&equiv_42 + 539)
#define c6h ((integer *)&equiv_42 + 606)
#define d2h ((integer *)&equiv_42 + 711)
#define d3h ((integer *)&equiv_42 + 784)
#define d4h ((integer *)&equiv_42 + 827)
#define d5h ((integer *)&equiv_42 + 938)
#define d6h ((integer *)&equiv_42 + 1011)
#define d5d ((integer *)&equiv_42 + 1299)
#define d6d ((integer *)&equiv_42 + 1372)
#define c2v ((integer *)&equiv_42 + 305)
#define c3v ((integer *)&equiv_42 + 326)
#define c4v ((integer *)&equiv_42 + 339)
#define c5v ((integer *)&equiv_42 + 370)
#define c6v ((integer *)&equiv_42 + 391)
    static integer nzz;
#define jtab ((integer *)&equiv_42)
    static integer kdim;
    static doublereal buff;
    static integer icheck, jgroup;

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
    symres_2.sig = 1.;
    i__ = *igroup;
    if (*ncode < 0) {
	goto L2;
    }
    *igroup = 0;
    for (i__ = 1; i__ <= 43; ++i__) {
	icheck = j[i__ - 1] / 10000;
	icheck = j[i__ - 1] - icheck * 10000 + 2;
	icheck = jtab[icheck - 1];
	if (icheck == *ncode) {
	    goto L2;
	}
/* L1: */
    }
    return 0;
L2:
    *igroup = i__;
    jgroup = j[*igroup - 1];
    s00001_1.j1 = jgroup / 1000000;
    kdim = jgroup - s00001_1.j1 * 1000000;
    s00001_1.i1 = kdim / 10000;
    jgroup = kdim - s00001_1.i1 * 10000;
    symres_2.name__ = jtab[jgroup - 1];
    symres_2.sig = (doublereal) isigma[*igroup - 1];
    s00001_1.j2 = 0;
    i__1 = s00001_1.i1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	++jgroup;
	s00001_1.jx[i__ * 7 - 7] = jtab[jgroup - 1];
	i__2 = s00001_1.j1;
	for (k = 1; k <= i__2; ++k) {
	    ++jgroup;
	    buff = (doublereal) jtab[jgroup - 1];
	    if (i__ > 1) {
		goto L3;
	    }
	    s00001_1.jx[k * 7 - 6] = jtab[jgroup - 1] / 100;
	    s00001_1.jx[k * 7 - 5] = jtab[jgroup - 1] - s00001_1.jx[k * 7 - 6]
		     * 100;
	    s00001_1.jx[k * 7 - 4] = s00001_1.jx[k * 7 - 6] / 100;
	    s00001_1.jx[k * 7 - 3] = s00001_1.jx[k * 7 - 6] - s00001_1.jx[k * 
		    7 - 4] * 100;
	    s00001_1.jx[k * 7 - 6] = s00001_1.jx[k * 7 - 3];
	    s00001_1.jx[k * 7 - 3] = s00001_1.jx[k * 7 - 4] / 10;
	    s00001_1.jx[k * 7 - 4] -= s00001_1.jx[k * 7 - 3] * 10;
	    s00001_1.jx[1] = 1;
	    s00001_1.jx[2] = 0;
	    s00001_1.j2 += s00001_1.jx[k * 7 - 6];
	    buff = 1.;
L3:
	    if (buff < 10.f) {
		goto L4;
	    }
	    nzz = jtab[jgroup - 1];
	    nz = nzz / 10;
	    fz = (doublereal) nz;
	    fn = (doublereal) (nzz - nz * 10);
	    buff = cos(fn * 6.283185307179 / fz) * 2.;
L4:
	    s00001_1.t[i__ + k * 12 - 13] = buff;
	}
    }
    s00001_1.lina = *igroup - 41;
    return 0;
} /* r00008_ */

#undef jtab
#undef c6v
#undef c5v
#undef c4v
#undef c3v
#undef c2v
#undef d6d
#undef d5d
#undef d6h
#undef d5h
#undef d4h
#undef d3h
#undef d2h
#undef c6h
#undef c5h
#undef c4h
#undef c3h
#undef c2h
#undef d4d
#undef d3d
#undef d2d
#undef cv
#undef td
#undef oh
#undef cs
#undef ih
#undef dh
#undef ci
#undef s8
#undef s6
#undef s4
#undef d6
#undef d5
#undef d4
#undef d3
#undef d2
#undef c8
#undef c7
#undef c6
#undef c5
#undef c4
#undef c3
#undef c2
#undef c1



/* ================================================================ */

/* Subroutine */ int r00009_(integer *nat, doublereal *coord)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k, l, jot;
    extern /* Subroutine */ int r00005_(doublereal *, integer *), r00006_(
	    integer *, integer *), r00007_(integer *, doublereal *, integer *)
	    ;
    static doublereal help[9]	/* was [3][3] */;
    static integer jota, jotb;

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
    /* Parameter adjustments */
    coord -= 4;
    --nat;

    /* Function Body */
    for (i__ = 1; i__ <= 3; ++i__) {
	i__1 = s00002_2.numat;
	for (j = 1; j <= i__1; ++j) {
/* L1: */
	    coord[i__ + j * 3] -= s00004_1.shift[i__ - 1];
	}
    }
    r00005_(&coord[4], &c__1);
    if (s00001_1.j1 < 2) {
	return 0;
    }
    i__1 = s00001_1.j1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	jota = s00001_1.jx[i__ * 7 - 5];
	jot = 1;
	if (jota <= 20) {
	    goto L2;
	}
	jotb = jota / 10;
	jot = jota - jotb * 10;
	jota = s00001_1.jx[jotb * 7 - 5];
L2:
	r00006_(&jota, &i__);
	if (jot == 1) {
	    goto L5;
	}
	for (j = 1; j <= 3; ++j) {
	    for (k = 1; k <= 3; ++k) {
		help[j + k * 3 - 4] = 0.;
		for (l = 1; l <= 3; ++l) {
/* L3: */
		    help[j + k * 3 - 4] += s00003_1.elem[j + (l + jot * 3) * 
			    3 - 13] * s00003_1.elem[l + (k + i__ * 3) * 3 - 
			    13];
		}
	    }
	}
	for (j = 1; j <= 3; ++j) {
	    for (k = 1; k <= 3; ++k) {
/* L4: */
		s00003_1.elem[j + (k + i__ * 3) * 3 - 13] = help[j + k * 3 - 
			4];
	    }
	}
L5:
	;
    }
    i__1 = s00001_1.j1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	r00007_(&nat[1], &coord[4], &i__);
	s00001_1.jx[i__ * 7 - 2] = s00002_2.iqual;
	if (s00003_1.ielem[i__ - 1] < 1) {
	    s00002_2.ierror = 5;
	}
/* L6: */
    }
    r00005_(&coord[4], &c_n1);
    for (i__ = 1; i__ <= 3; ++i__) {
	i__1 = s00002_2.numat;
	for (j = 1; j <= i__1; ++j) {
/* L7: */
	    coord[i__ + j * 3] += s00004_1.shift[i__ - 1];
	}
    }
    return 0;
} /* r00009_ */


/* =================================================================== */

/* Subroutine */ int r00010_(doublereal *coeff, integer *ntype, integer *
	icount, integer *ncdum)
{
    /* Initialized data */

    static doublereal toler = .1;
    static struct {
	char e_1[4];
	integer e_2;
	} equiv_167 = { "????", 0 };

#define ifra (*(integer *)&equiv_167)


    /* System generated locals */
    integer coeff_dim1, coeff_offset, i__1, i__2;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, ik;
    extern doublereal r00011_(doublereal *, integer *, integer *, integer *, 
	    integer *);
    static doublereal char__[12], check;
    static integer names, ifound;

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
    /* Parameter adjustments */
    --ntype;
    --icount;
    coeff_dim1 = *ncdum;
    coeff_offset = 1 + coeff_dim1 * 1;
    coeff -= coeff_offset;

    /* Function Body */

    s00002_2.ndorbs = 0;
    i__1 = s00001_1.i1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L1: */
	icount[i__] = 0;
    }
    names = ifra;
    if (s00001_1.j1 == 1) {
	names = s00001_1.jx[0];
    }
    i__1 = s00002_2.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	symres_3.index[i__ - 1] = i__;
/* L2: */
	symres_3.namo[i__ - 1] = names;
    }
    if (s00001_1.j1 == 1) {
	return 0;
    }
    if (s00002_2.ierror > 0) {
	return 0;
    }
    ifound = 0;
    i__ = 0;
L3:
    ik = i__ + 1;
    i__1 = s00001_1.j1;
    for (j = 1; j <= i__1; ++j) {
/* L4: */
	char__[j - 1] = 0.;
    }
L5:
    ++i__;
    if (i__ > s00002_2.norbs) {
	goto L10;
    }
    i__1 = s00001_1.j1;
    for (j = 1; j <= i__1; ++j) {
	char__[j - 1] += r00011_(&coeff[coeff_offset], &ntype[1], &i__, &j, 
		ncdum);
	if (char__[j - 1] > 10.f) {
	    goto L3;
	}
/* L6: */
    }
    i__1 = s00001_1.i1;
    for (k = 1; k <= i__1; ++k) {
	i__2 = s00001_1.j1;
	for (j = 1; j <= i__2; ++j) {
	    check = (d__1 = char__[j - 1] - s00001_1.t[k + j * 12 - 13], abs(
		    d__1));
	    if (check > toler) {
		goto L9;
	    }
/* L7: */
	}
	++icount[k];
	i__2 = i__;
	for (j = ik; j <= i__2; ++j) {
	    ++ifound;
	    symres_3.index[j - 1] = icount[k];
/* L8: */
	    symres_3.namo[j - 1] = s00001_1.jx[k * 7 - 7];
	}
	goto L3;
L9:
	;
    }
    goto L5;
L10:
    if (ifound != s00002_2.norbs) {
	s00002_2.ierror = 99;
    }
    return 0;
} /* r00010_ */

#undef ifra



/* ====================================================================== */

doublereal r00011_(doublereal *coeff, integer *ntype, integer *jorb, integer *
	ioper, integer *ncdum)
{
    /* System generated locals */
    integer coeff_dim1, coeff_offset, i__1, i__2;
    doublereal ret_val;

    /* Local variables */
    static doublereal d__[5];
#define e ((doublereal *)&s00003_1 + 10)
    static doublereal h__[5];
    static integer i__;
    static doublereal p[3], c1, c2;
    static integer id[10]	/* was [2][5] */, ii, ki, kj, jj, ip[6]	/* 
	    was [2][3] */, loc[100]	/* was [2][50] */;
    extern /* Subroutine */ int r00012_(doublereal *, doublereal *, integer *)
	    ;
    static integer nqzd, ilqz, inqz, nqzp, ibase, iatom, jatom, itest, minus, 
	    icheck, jcheck;

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
    /* Parameter adjustments */
    --ntype;
    coeff_dim1 = *ncdum;
    coeff_offset = 1 + coeff_dim1 * 1;
    coeff -= coeff_offset;

    /* Function Body */
    ret_val = 1.;
    if (*ioper == 1) {
	return ret_val;
    }
    i__1 = s00002_2.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s00004_1.vect[(i__ << 1) - 2] = 0.;
/* L1: */
	s00004_1.vect[(i__ << 1) - 1] = 0.;
    }
    i__1 = s00002_2.numat;
    for (iatom = 1; iatom <= i__1; ++iatom) {
	jatom = s00003_1.jelem[*ioper + iatom * 20 - 21];
	ki = 0;
	kj = 0;
	i__2 = s00002_2.norbs;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    icheck = ntype[i__] / 100;
	    if (icheck != iatom) {
		goto L2;
	    }
	    ++ki;
	    loc[(ki << 1) - 2] = i__;
L2:
	    if (icheck != jatom) {
		goto L3;
	    }
	    ++kj;
	    loc[(kj << 1) - 1] = i__;
L3:
	    ;
	}
	ibase = ki;
	i__2 = ibase;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    icheck = loc[(i__ << 1) - 2];
	    itest = ntype[icheck] - ntype[icheck] / 10 * 10;
	    if (itest > 0) {
		goto L4;
	    }
	    jcheck = loc[(i__ << 1) - 1];
	    loc[(i__ << 1) - 2] = 0;
	    --ki;
	    s00004_1.vect[(icheck << 1) - 2] = coeff[icheck + *jorb * 
		    coeff_dim1];
	    s00004_1.vect[(jcheck << 1) - 1] = coeff[icheck + *jorb * 
		    coeff_dim1];
L4:
	    ;
	}
	minus = iatom * 100;
L5:
	if (ki < 3) {
	    goto L13;
	}
	for (i__ = 1; i__ <= 3; ++i__) {
	    ip[(i__ << 1) - 2] = 0;
/* L6: */
	    id[(i__ << 1) - 2] = 0;
	}
	id[6] = 0;
	id[8] = 0;
	nqzp = -1;
	nqzd = -1;
	i__2 = ibase;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    if (loc[(i__ << 1) - 2] < 1) {
		goto L9;
	    }
	    icheck = loc[(i__ << 1) - 2];
	    itest = ntype[icheck];
	    inqz = (itest - minus) / 10;
	    ilqz = itest - itest / 10 * 10;
	    if (ilqz > 8) {
		goto L8;
	    }
	    if (ilqz > 3) {
		goto L7;
	    }
	    if (nqzp < 0) {
		nqzp = inqz;
	    }
	    if (inqz != nqzp) {
		goto L9;
	    }
	    p[ilqz - 1] = coeff[icheck + *jorb * coeff_dim1];
	    ip[(ilqz << 1) - 2] = loc[(i__ << 1) - 2];
	    ip[(ilqz << 1) - 1] = loc[(i__ << 1) - 1];
	    goto L8;
L7:
	    if (nqzd < 0) {
		nqzd = inqz;
	    }
	    if (inqz != nqzd) {
		goto L9;
	    }
	    ilqz += -3;
	    d__[ilqz - 1] = coeff[icheck + *jorb * coeff_dim1];
	    id[(ilqz << 1) - 2] = loc[(i__ << 1) - 2];
	    id[(ilqz << 1) - 1] = loc[(i__ << 1) - 1];
L8:
	    loc[(i__ << 1) - 2] = 0;
	    --ki;
L9:
	    ;
	}
	if (nqzp < 0) {
	    goto L11;
	}
	h__[0] = s00004_1.r__[0] * p[0] + s00004_1.r__[1] * p[1] + 
		s00004_1.r__[2] * p[2];
	h__[1] = s00004_1.r__[3] * p[0] + s00004_1.r__[4] * p[1] + 
		s00004_1.r__[5] * p[2];
	h__[2] = s00004_1.r__[6] * p[0] + s00004_1.r__[7] * p[1] + 
		s00004_1.r__[8] * p[2];
	p[0] = e[(*ioper * 3 + 1) * 3 - 12] * h__[0] + e[(*ioper * 3 + 2) * 3 
		- 12] * h__[1] + e[(*ioper * 3 + 3) * 3 - 12] * h__[2];
	p[1] = e[(*ioper * 3 + 1) * 3 - 11] * h__[0] + e[(*ioper * 3 + 2) * 3 
		- 11] * h__[1] + e[(*ioper * 3 + 3) * 3 - 11] * h__[2];
	p[2] = e[(*ioper * 3 + 1) * 3 - 10] * h__[0] + e[(*ioper * 3 + 2) * 3 
		- 10] * h__[1] + e[(*ioper * 3 + 3) * 3 - 10] * h__[2];
	for (i__ = 1; i__ <= 3; ++i__) {
	    if (ip[(i__ << 1) - 2] < 1) {
		goto L16;
	    }
	    ii = ip[(i__ << 1) - 2];
	    jj = ip[(i__ << 1) - 1];
	    s00004_1.vect[(ii << 1) - 2] = h__[i__ - 1];
/* L10: */
	    s00004_1.vect[(jj << 1) - 1] = p[i__ - 1];
	}
L11:
	if (nqzd < 0) {
	    goto L5;
	}
	r00012_(d__, h__, ioper);
	for (i__ = 1; i__ <= 5; ++i__) {
	    if (id[(i__ << 1) - 2] < 1) {
		goto L16;
	    }
	    ii = id[(i__ << 1) - 2];
	    jj = id[(i__ << 1) - 1];
	    s00004_1.vect[(ii << 1) - 2] = h__[i__ - 1];
/* L12: */
	    s00004_1.vect[(jj << 1) - 1] = d__[i__ - 1];
	}
	ki += -5;
	goto L5;
L13:
	;
    }
    c1 = 0.;
    c2 = 0.;
    i__1 = s00002_2.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	c1 += s00004_1.vect[(i__ << 1) - 2] * s00004_1.vect[(i__ << 1) - 2];
/* L14: */
	c2 += s00004_1.vect[(i__ << 1) - 2] * s00004_1.vect[(i__ << 1) - 1];
    }
    if (abs(c1) < 1e-5f) {
	goto L15;
    }
    ret_val = c2 / c1;
    return ret_val;
L15:
    ret_val = 100.;
    return ret_val;
L16:
    s00002_2.ierror = 98;
    return ret_val;
} /* r00011_ */

#undef e



/* ======================================================================= */

/* Subroutine */ int r00012_(doublereal *d__, doublereal *h__, integer *ioper)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j, k;
    static doublereal s[9]	/* was [3][3] */, t1[300]	/* was [5][5][
	    12] */;
    extern /* Subroutine */ int r00013_(doublereal *, doublereal *, integer *)
	    ;

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
    /* Parameter adjustments */
    --h__;
    --d__;

    /* Function Body */
    if (s00002_2.ndorbs > 0) {
	goto L4;
    }
    s00002_2.ndorbs = 1;
    for (i__ = 1; i__ <= 3; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L1: */
	    s[i__ + j * 3 - 4] = s00004_1.r__[i__ + j * 3 - 4];
	}
    }
    r00013_(s, t1, &c__1);
    i__1 = s00001_2.j1;
    for (k = 2; k <= i__1; ++k) {
	for (i__ = 1; i__ <= 3; ++i__) {
	    for (j = 1; j <= 3; ++j) {
/* L2: */
		s[i__ + j * 3 - 4] = s00003_1.elem[i__ + (j + k * 3) * 3 - 13]
			;
	    }
	}
	r00013_(s, t1, &k);
/* L3: */
    }
L4:
    for (i__ = 1; i__ <= 5; ++i__) {
	h__[i__] = 0.;
	for (j = 1; j <= 5; ++j) {
/* L5: */
	    h__[i__] += t1[i__ + (j + 5) * 5 - 31] * d__[j];
	}
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	d__[i__] = 0.;
	for (j = 1; j <= 5; ++j) {
/* L6: */
	    d__[i__] += t1[i__ + (j + *ioper * 5) * 5 - 31] * h__[j];
	}
    }
    return 0;
} /* r00012_ */


/* ================================================================= */

/* Subroutine */ int r00013_(doublereal *r__, doublereal *t, integer *ioper)
{
    /* Initialized data */

    static doublereal pi = 3.1415926536;
    static doublereal tol = .001;
    static doublereal s12 = 3.46410161513;
    static doublereal s3 = 1.73205080756;
    static doublereal one = 1.;

    /* System generated locals */
    doublereal d__1;

    /* Builtin functions */
    double d_sign(doublereal *, doublereal *), acos(doublereal), sqrt(
	    doublereal), asin(doublereal), sin(doublereal), cos(doublereal);

    /* Local variables */
    static doublereal a, b, f[8]	/* was [2][4] */, g;
    static integer i__;
    static doublereal e1, e2, e3, e4, r1, r2, r3, x1, x2, x3, x4, ta, tg, arg,
	     sina, check;
    static logical right;

    /* Parameter adjustments */
    t -= 31;
    r__ -= 4;

    /* Function Body */
    r1 = r__[5] * r__[9] - r__[6] * r__[8];
    r2 = r__[6] * r__[7] - r__[4] * r__[9];
    r3 = r__[4] * r__[8] - r__[5] * r__[7];
    check = r1 * r__[10] + r2 * r__[11] + r3 * r__[12];
    right = check > 0.f;
    r__[10] = r1;
    r__[11] = r2;
    r__[12] = r3;
    arg = r3;
    if (abs(arg) > one) {
	arg = d_sign(&one, &arg);
    }
    b = acos(arg);
    sina = sqrt(1. - arg * arg);
    if (sina < tol) {
	goto L1;
    }
    arg = r__[9] / sina;
    if (abs(arg) > one) {
	arg = d_sign(&one, &arg);
    }
    g = asin(arg);
    arg = r__[11] / sina;
    if (abs(arg) > one) {
	arg = d_sign(&one, &arg);
    }
    a = asin(arg);
    goto L2;
L1:
    arg = r__[7];
    if (abs(arg) > one) {
	arg = d_sign(&one, &arg);
    }
    g = asin(arg);
    a = 0.;
L2:
    f[0] = a;
    f[2] = a;
    f[4] = pi - a;
    f[6] = pi - a;
    f[1] = g;
    f[5] = g;
    f[3] = pi - g;
    f[7] = pi - g;
    for (i__ = 1; i__ <= 4; ++i__) {
	a = f[(i__ << 1) - 2];
	g = f[(i__ << 1) - 1];
	check = (d__1 = sin(b) * cos(a) + r__[10], abs(d__1));
	if (check > tol) {
	    goto L3;
	}
	check = -sin(g) * cos(b) * sin(a) + cos(g) * cos(a);
	if ((d__1 = check - r__[8], abs(d__1)) > tol) {
	    goto L3;
	}
	check = sin(a) * cos(g) + cos(a) * cos(b) * sin(g);
	if ((d__1 = check - r__[7], abs(d__1)) <= tol) {
	    goto L4;
	}
L3:
	;
    }
L4:
    g = -g;
    a = -a;
    b = -b;
    e1 = cos(b * .5);
    x1 = -sin(b * .5);
    e2 = e1 * e1;
    e3 = e1 * e2;
    e4 = e2 * e2;
    x2 = x1 * x1;
    x3 = x1 * x2;
    x4 = x2 * x2;
    ta = a * 2.;
    tg = g * 2.;
    t[(*ioper * 5 + 1) * 5 + 1] = e4 * cos(ta + tg) + x4 * cos(ta - tg);
    t[(*ioper * 5 + 2) * 5 + 1] = e3 * 2. * x1 * cos(a + tg) - e1 * 2. * x3 * 
	    cos(a - tg);
    t[(*ioper * 5 + 3) * 5 + 1] = s3 * 2. * e2 * x2 * cos(tg);
    t[(*ioper * 5 + 4) * 5 + 1] = e3 * 2. * x1 * sin(a + tg) - e1 * 2. * x3 * 
	    sin(a - tg);
    t[(*ioper * 5 + 5) * 5 + 1] = e4 * sin(ta + tg) + x4 * sin(ta - tg);
    t[(*ioper * 5 + 1) * 5 + 2] = e1 * 2. * x3 * cos(ta - g) - e3 * 2. * x1 * 
	    cos(ta + g);
    t[(*ioper * 5 + 2) * 5 + 2] = (e4 - e2 * 3. * x2) * cos(a + g) - (e2 * 3. 
	    * x2 - x4) * cos(a - g);
    t[(*ioper * 5 + 3) * 5 + 2] = s3 * 2. * (e3 * x1 - e1 * x3) * cos(g);
    t[(*ioper * 5 + 4) * 5 + 2] = (e4 - e2 * 3. * x2) * sin(a + g) - (e2 * 3. 
	    * x2 - x4) * sin(a - g);
    t[(*ioper * 5 + 5) * 5 + 2] = e3 * -2. * x1 * sin(ta + g) + e1 * 2. * x3 *
	     sin(ta - g);
    t[(*ioper * 5 + 1) * 5 + 3] = s12 * e2 * x2 * cos(ta);
    t[(*ioper * 5 + 2) * 5 + 3] = -s12 * (e3 * x1 - e1 * x3) * cos(a);
    t[(*ioper * 5 + 3) * 5 + 3] = e4 - e2 * 4. * x2 + x4;
    t[(*ioper * 5 + 4) * 5 + 3] = -s12 * (e3 * x1 - e1 * x3) * sin(a);
    t[(*ioper * 5 + 5) * 5 + 3] = s12 * e2 * x2 * sin(ta);
    t[(*ioper * 5 + 1) * 5 + 4] = e1 * 2. * x3 * sin(ta - g) + e3 * 2. * x1 * 
	    sin(ta + g);
    t[(*ioper * 5 + 2) * 5 + 4] = -(e4 - e2 * 3. * x2) * sin(a + g) - (e2 * 
	    3. * x2 - x4) * sin(a - g);
    t[(*ioper * 5 + 3) * 5 + 4] = s3 * -2. * (e3 * x1 - e1 * x3) * sin(g);
    t[(*ioper * 5 + 4) * 5 + 4] = (e4 - e2 * 3. * x2) * cos(a + g) + (e2 * 3. 
	    * x2 - x4) * cos(a - g);
    t[(*ioper * 5 + 5) * 5 + 4] = e3 * -2. * x1 * cos(ta + g) - e1 * 2. * x3 *
	     cos(ta - g);
    t[(*ioper * 5 + 1) * 5 + 5] = -e4 * sin(ta + tg) + x4 * sin(ta - tg);
    t[(*ioper * 5 + 2) * 5 + 5] = e3 * -2. * x1 * sin(a + tg) - e1 * 2. * x3 *
	     sin(a - tg);
    t[(*ioper * 5 + 3) * 5 + 5] = s3 * -2. * e2 * x2 * sin(tg);
    t[(*ioper * 5 + 4) * 5 + 5] = e3 * 2. * x1 * cos(a + tg) + e1 * 2. * x3 * 
	    cos(a - tg);
    t[(*ioper * 5 + 5) * 5 + 5] = e4 * cos(ta + tg) - x4 * cos(ta - tg);
    if (right) {
	return 0;
    }
    for (i__ = 1; i__ <= 5; ++i__) {
	t[(i__ + *ioper * 5) * 5 + 2] = -t[(i__ + *ioper * 5) * 5 + 2];
/* L5: */
	t[(i__ + *ioper * 5) * 5 + 4] = -t[(i__ + *ioper * 5) * 5 + 4];
    }
    return 0;
} /* r00013_ */


/* ====================================================================== */

/* Subroutine */ int r00015_(doublereal *f, doublereal *v, doublereal *ew)
{
    /* Initialized data */

    static doublereal toler = 1e-6;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static doublereal a[9]	/* was [3][3] */, c__, h__;
    static integer i__, j, l, n;
    static doublereal s, t;
    static integer i1, n1;
    static doublereal hc;
    static integer ig, ij, nt;
    static doublereal ss;
    static integer ilg, irg, jrg;
    static doublereal tau;
    static integer irs;
    static doublereal zeta, theta, buffer;

    /* Parameter adjustments */
    --ew;
    v -= 4;
    --f;

    /* Function Body */
    n = 3;
    ij = 0;
    i__1 = n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = j;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ++ij;
	    a[i__ + j * 3 - 4] = f[ij];
	    a[j + i__ * 3 - 4] = f[ij];
	    v[i__ + j * 3] = 0.;
/* L1: */
	    v[j + i__ * 3] = 0.;
	}
/* L2: */
	v[j + j * 3] = 1.;
    }
    n1 = n - 1;
    zeta = 10.;
L3:
    ss = 0.;
    i__1 = n1;
    for (j = 1; j <= i__1; ++j) {
	i__2 = n1;
	for (i__ = j; i__ <= i__2; ++i__) {
	    irg = i__ + 1;
/* L4: */
	    ss += (d__1 = a[irg + j * 3 - 4], abs(d__1));
	}
    }
    if (ss - toler <= 0.) {
	goto L21;
    } else {
	goto L5;
    }
L5:
    tau = 0.;
    i__2 = n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i1 = i__ + 1;
	if (n - i1 >= 0) {
	    goto L6;
	} else {
	    goto L20;
	}
L6:
	i__1 = n;
	for (j = i1; j <= i__1; ++j) {
	    if ((d__1 = a[j + i__ * 3 - 4], abs(d__1)) < 1e-30f) {
		goto L19;
	    }
	    theta = (a[j + j * 3 - 4] - a[i__ + i__ * 3 - 4]) * .5 / a[j + 
		    i__ * 3 - 4];
	    if (abs(theta) - zeta <= 0.) {
		goto L7;
	    } else {
		goto L19;
	    }
L7:
	    t = 1.;
	    if (theta >= 0.) {
		goto L9;
	    } else {
		goto L8;
	    }
L8:
	    t = -1.;
L9:
	    t = 1. / (theta + t * sqrt(theta * theta + 1.));
	    c__ = 1. / sqrt(t * t + 1.);
	    s = c__ * t;
	    h__ = a[j + i__ * 3 - 4] * 2.;
	    hc = s * h__ * (s * theta - c__);
	    a[i__ + i__ * 3 - 4] += hc;
	    a[j + j * 3 - 4] -= hc;
	    a[j + i__ * 3 - 4] = -h__ * c__ * (s * theta - (c__ - s * s / c__)
		     * .5);
	    tau += 1.;
	    if (i__ < 2) {
		goto L11;
	    }
	    i__3 = i__;
	    for (ig = 2; ig <= i__3; ++ig) {
		irs = ig - 1;
		h__ = c__ * a[i__ + irs * 3 - 4] - s * a[j + irs * 3 - 4];
		a[j + irs * 3 - 4] = s * a[i__ + irs * 3 - 4] + c__ * a[j + 
			irs * 3 - 4];
/* L10: */
		a[i__ + irs * 3 - 4] = h__;
	    }
L11:
	    l = j - 1;
	    if (l - i1 >= 0) {
		goto L12;
	    } else {
		goto L14;
	    }
L12:
	    i__3 = l;
	    for (ig = i1; ig <= i__3; ++ig) {
		h__ = c__ * a[ig + i__ * 3 - 4] - s * a[j + ig * 3 - 4];
		a[j + ig * 3 - 4] = s * a[ig + i__ * 3 - 4] + c__ * a[j + ig *
			 3 - 4];
/* L13: */
		a[ig + i__ * 3 - 4] = h__;
	    }
L14:
	    if (n1 - j >= 0) {
		goto L15;
	    } else {
		goto L17;
	    }
L15:
	    i__3 = n1;
	    for (ig = j; ig <= i__3; ++ig) {
		ilg = ig + 1;
		h__ = c__ * a[ilg + i__ * 3 - 4] - s * a[ilg + j * 3 - 4];
		a[ilg + j * 3 - 4] = s * a[ilg + i__ * 3 - 4] + c__ * a[ilg + 
			j * 3 - 4];
/* L16: */
		a[ilg + i__ * 3 - 4] = h__;
	    }
L17:
	    i__3 = n;
	    for (ig = 1; ig <= i__3; ++ig) {
		h__ = c__ * v[ig + i__ * 3] - s * v[ig + j * 3];
		v[ig + j * 3] = s * v[ig + i__ * 3] + c__ * v[ig + j * 3];
/* L18: */
		v[ig + i__ * 3] = h__;
	    }
L19:
	    ;
	}
L20:
	;
    }
    h__ = (real) (n * (n - 1)) * .5;
    d__1 = 2.5 - tau / h__;
    zeta = pow_dd(&zeta, &d__1);
    goto L3;
L21:
    i__2 = n;
    for (j = 1; j <= i__2; ++j) {
/* L22: */
	ew[j] = a[j + j * 3 - 4];
    }
    n1 = n - 1;
L23:
    nt = 0;
    i__2 = n1;
    for (j = 1; j <= i__2; ++j) {
	jrg = j + 1;
	if (ew[j] - ew[jrg] <= 0.) {
	    goto L26;
	} else {
	    goto L24;
	}
L24:
	buffer = ew[j];
	ew[j] = ew[jrg];
	ew[jrg] = buffer;
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    buffer = v[i__ + jrg * 3];
	    v[i__ + jrg * 3] = v[i__ + j * 3];
/* L25: */
	    v[i__ + j * 3] = buffer;
	}
	nt = 1;
L26:
	;
    }
    --n1;
    if (nt != 0) {
	goto L23;
    } else {
	goto L27;
    }
L27:
    return 0;
} /* r00015_ */


/* =================================================================== */

/* Subroutine */ int r00016_(void)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double cos(doublereal);

    /* Local variables */
    static integer i__, j, jk, jp;
    static doublereal char__[12];
    static integer jump;
    static doublereal coeff[12], angle;
    static integer icent;
    static doublereal order;
    static integer idegen, ivibra;

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
    ivibra = s00002_2.numat * 3 - 6;
    if (s00001_1.lina > 0) {
	goto L8;
    }
    char__[0] = (doublereal) ivibra;
    syminf_1.ivib = 0;
    if (s00001_1.j1 < 2) {
	return 0;
    }
    i__1 = s00001_1.j1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	jump = s00001_1.jx[i__ * 7 - 4];
	switch (jump) {
	    case 1:  goto L1;
	    case 2:  goto L2;
	    case 3:  goto L3;
	    case 4:  goto L4;
	}
L1:
	char__[i__ - 1] = (doublereal) (s00001_1.jx[i__ * 7 - 2] * -3);
	goto L5;
L2:
	char__[i__ - 1] = (doublereal) s00001_1.jx[i__ * 7 - 2];
	goto L5;
L3:
	jp = s00001_1.jx[i__ * 7 - 3] / 10;
	jk = s00001_1.jx[i__ * 7 - 3] - jp * 10;
	angle = cos((doublereal) jk * 6.283185308 / (doublereal) jp) * 2.;
	char__[i__ - 1] = (doublereal) s00001_1.jx[i__ * 7 - 2] * (angle - 1.)
		;
	goto L5;
L4:
	jp = s00001_1.jx[i__ * 7 - 3] / 10;
	jk = s00001_1.jx[i__ * 7 - 3] - jp * 10;
	angle = cos((doublereal) jk * 6.283185308 / (doublereal) jp) * 2.;
	char__[i__ - 1] = (doublereal) (s00001_1.jx[i__ * 7 - 2] - 2) * (
		angle + 1.);
L5:
	char__[i__ - 1] *= (doublereal) s00001_1.jx[i__ * 7 - 6];
    }
    order = (doublereal) s00001_1.j2;
    i__1 = s00001_1.i1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	coeff[i__ - 1] = .1;
	i__2 = s00001_1.j1;
	for (j = 1; j <= i__2; ++j) {
/* L6: */
	    coeff[i__ - 1] += char__[j - 1] * s00001_1.t[i__ + j * 12 - 13] / 
		    order;
	}
	if (coeff[i__ - 1] < 1.f) {
	    goto L7;
	}
	idegen = (integer) (s00001_1.t[i__ - 1] + .1);
	++syminf_1.ivib;
	syminf_1.ivibro[(syminf_1.ivib << 1) - 2] = (integer) coeff[i__ - 1];
	if (s00001_1.i1 != s00001_1.j1) {
	    syminf_1.ivibro[(syminf_1.ivib << 1) - 2] = (integer) (coeff[i__ 
		    - 1] / idegen);
	}
	syminf_1.ivibro[(syminf_1.ivib << 1) - 1] = s00001_1.jx[i__ * 7 - 7];
L7:
	;
    }
    return 0;
L8:
    ++ivibra;
    switch (s00001_1.lina) {
	case 1:  goto L9;
	case 2:  goto L10;
    }
L9:
    syminf_1.ivibro[0] = s00002_2.numat - 1;
    syminf_1.ivibro[1] = s00001_1.jx[0];
    syminf_1.ivibro[2] = s00002_2.numat - 2;
    syminf_1.ivibro[3] = s00001_1.jx[7];
    syminf_1.ivib = 2;
    if (s00002_2.numat < 3) {
	syminf_1.ivib = 1;
    }
    return 0;
L10:
    icent = s00001_1.jx[19];
    syminf_1.ivibro[0] = (s00002_2.numat - icent) / 2;
    syminf_1.ivibro[1] = s00001_1.jx[0];
    syminf_1.ivib = 2;
    syminf_1.ivibro[2] = (s00002_2.numat - 2 - icent) / 2;
    syminf_1.ivibro[3] = s00001_1.jx[7];
    if (syminf_1.ivibro[2] > 0) {
	syminf_1.ivib = 3;
    }
    syminf_1.ivibro[(syminf_1.ivib << 1) - 2] = (s00002_2.numat - 2 + icent) /
	     2;
    syminf_1.ivibro[(syminf_1.ivib << 1) - 1] = s00001_1.jx[21];
    if (syminf_1.ivibro[(syminf_1.ivib << 1) - 2] > 0) {
	++syminf_1.ivib;
    }
    syminf_1.ivibro[(syminf_1.ivib << 1) - 2] = (s00002_2.numat - 2 + icent) /
	     2;
    syminf_1.ivibro[(syminf_1.ivib << 1) - 1] = s00001_1.jx[28];
    if (syminf_1.ivibro[(syminf_1.ivib << 1) - 2] < 1) {
	--syminf_1.ivib;
    }
    return 0;
} /* r00016_ */

