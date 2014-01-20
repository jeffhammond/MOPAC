/* brlzon.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static doublecomplex c_b6 = {-1.,0.};
static integer c__0 = 0;
static integer c__1 = 1;
static integer c__500 = 500;

/* Subroutine */ int brlzon_(doublereal *fmatrx, doublereal *fmat2d, integer *
	n3, complex *sec, complex *vec, doublereal *b, integer *mono3, 
	doublereal *step, integer *mode)
{
    /* System generated locals */
    integer fmat2d_dim1, fmat2d_offset, b_dim1, b_offset, sec_dim1, 
	    sec_offset, vec_dim1, vec_offset, i__1, i__2, i__3, i__4, i__5, 
	    i__6, i__7, i__8;
    doublereal d__1, d__2, d__3;
    doublecomplex z__1, z__2, z__3, z__4, z__5;

    /* Builtin functions */
    double acos(doublereal);
    void z_sqrt(doublecomplex *, doublecomplex *), z_exp(doublecomplex *, 
	    doublecomplex *);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static doublereal c__;
    static integer i__, j, k, m, ii, jj;
    static doublereal ri;
    static integer iii;
    static doublereal cay, top, fact;
    static real eigs[360];
    extern /* Subroutine */ int dofs_(doublereal *, integer *, integer *, 
	    doublereal *, integer *, doublereal *, doublereal *);
    static integer loop;
    extern /* Subroutine */ int cdiag_(complex *, real *, complex *, integer *
	    , integer *);
    static complex phase;
    static doublereal twopi;
    static integer ncells;
    static doublereal bottom;

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 6, 0, "(//,A,F6.3,/)", 0 };
    static cilist io___20 = { 0, 6, 0, "(/,A,I4,/)", 0 };
    static cilist io___21 = { 0, 6, 0, "(6(F6.3,F7.1))", 0 };
    static cilist io___22 = { 0, 6, 0, "(//,A,F6.3,/)", 0 };
    static cilist io___23 = { 0, 6, 0, "(A,/,A,I4,/,A)", 0 };
    static cilist io___24 = { 0, 6, 0, "(6(F6.3,F7.2))", 0 };


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

/*   IF MODE IS 1 THEN */
/*   BRLZON COMPUTES THE PHONON SPECTRUM OF A LINEAR POLYMER GIVEN */
/*   THE WEIGHTED HESSIAN MATRIX. */
/*   IF MODE IS 2 THEN */
/*   BRLZON COMPUTES THE ELECTRONIC ENERGY BAND STRUCTURE OF A LINEAR */
/*   POLYMER GIVEN THE FOCK MATRIX. */

/*                 ON INPUT */

/*   IF MODE IS 1 THEN */
/*         FMATRX IS THE MASS-WEIGHTED HESSIAN MATRIX, PACKED LOWER */
/*                   HALF TRIANGLE */
/*         N3     IS 3*(NUMBER OF ATOMS IN UNIT CELL) = SIZE OF FMATRX */
/*         MONO3  IS 3*(NUMBER OF ATOMS IN PRIMITIVE UNIT CELL) */
/*         FMAT2D, SEC, VEC ARE SCRATCH ARRAYS */
/*   IF MODE IS 2 THEN */
/*         FMATRX IS THE FOCK MATRIX, PACKED LOWER HALF TRIANGLE */
/*         N3     IS NUMBER OF ATOMIC ORBITALS IN SYSTEM = SIZE OF FMATRX */
/*         MONO3  IS NUMBER OF ATOMIC ORBITALS IN FUNDAMENTAL UNIT CELL */
/*         FMAT2D, SEC, VEC ARE SCRATCH ARRAYS */

/* ********************************************************************** */
    /* Parameter adjustments */
    fmat2d_dim1 = *n3;
    fmat2d_offset = 1 + fmat2d_dim1 * 1;
    fmat2d -= fmat2d_offset;
    --fmatrx;
    b_dim1 = *mono3;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    vec_dim1 = *mono3;
    vec_offset = 1 + vec_dim1 * 1;
    vec -= vec_offset;
    sec_dim1 = *mono3;
    sec_offset = 1 + sec_dim1 * 1;
    sec -= sec_offset;

    /* Function Body */
    fact = 6.023e23;
    c__ = 2.998e10;
    twopi = acos(-1.) * 2.;

/*  NCELLS IS THE NUMBER OF PRIMITIVE UNIT CELLS IN THE UNIT CELL */

    ncells = *n3 / *mono3;

/*  PUT THE ENERGY MATRIX INTO SQUARE MATRIX FORM */

    k = 0;
    i__1 = *n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++k;
/* L10: */
	    fmat2d[i__ + j * fmat2d_dim1] = fmatrx[k];
	}
    }

/*   STEP IS THE STEP SIZE IN THE BRILLOUIN ZONE (BOUNDARIES: 0.0 - 0.5), */
/*   THERE ARE M OF THESE. */
/*   MONO3 IS THE SIZE OF ONE MER (MONOMERIC UNIT) */

    m = (integer) (.5 / *step + 1);
    i__2 = m;
    for (loop = 1; loop <= i__2; ++loop) {
	i__1 = *mono3;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__3 = *mono3;
	    for (j = 1; j <= i__3; ++j) {
/* L20: */
		i__4 = i__ + j * sec_dim1;
		sec[i__4].r = 0.f, sec[i__4].i = 0.f;
	    }
	}
	cay = (loop - 1) * *step;
	i__4 = *n3;
	i__3 = *mono3;
	for (i__ = 1; i__3 < 0 ? i__ >= i__4 : i__ <= i__4; i__ += i__3) {
	    ri = (doublereal) ((i__ - 1) / *mono3);

/* IF THE PRIMITIVE UNIT CELL IS MORE THAN HALF WAY ACROSS THE UNIT CELL, */
/* CONSIDER IT AS BEING LESS THAN HALF WAY ACROSS, BUT IN THE OPPOSITE */
/* DIRECTION. */

	    if (ri > (doublereal) (ncells / 2)) {
		ri -= ncells;
	    }

/*  PHASE IS THE COMPLEX PHASE EXP(I.K.R(I)*(2PI)) */

	    z_sqrt(&z__5, &c_b6);
	    z__4.r = cay * z__5.r, z__4.i = cay * z__5.i;
	    z__3.r = ri * z__4.r, z__3.i = ri * z__4.i;
	    z__2.r = twopi * z__3.r, z__2.i = twopi * z__3.i;
	    z_exp(&z__1, &z__2);
	    phase.r = z__1.r, phase.i = z__1.i;
	    i__1 = *mono3;
	    for (ii = 1; ii <= i__1; ++ii) {
		iii = ii + i__ - 1;
		i__5 = ii;
		for (jj = 1; jj <= i__5; ++jj) {
/* L30: */
		    i__6 = ii + jj * sec_dim1;
		    i__7 = ii + jj * sec_dim1;
		    i__8 = iii + jj * fmat2d_dim1;
		    z__2.r = fmat2d[i__8] * phase.r, z__2.i = fmat2d[i__8] * 
			    phase.i;
		    z__1.r = sec[i__7].r + z__2.r, z__1.i = sec[i__7].i + 
			    z__2.i;
		    sec[i__6].r = z__1.r, sec[i__6].i = z__1.i;
		}
	    }
/* L40: */
	}
	cdiag_(&sec[sec_offset], eigs, &vec[vec_offset], mono3, &c__0);
	if (*mode == 1) {

/*  CONVERT INTO RECIPRICAL CENTIMETERS */

	    i__3 = *mono3;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L50: */
		d__2 = sqrt(fact * (d__1 = eigs[i__ - 1] * 1e5, abs(d__1))) / 
			(c__ * twopi);
		d__3 = (doublereal) eigs[i__ - 1];
		b[i__ + loop * b_dim1] = d_sign(&d__2, &d__3);
	    }
	} else {
	    i__3 = *mono3;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L60: */
		b[i__ + loop * b_dim1] = eigs[i__ - 1];
	    }
	}
/* L70: */
    }
    bottom = 1e6;
    top = -1e6;
    i__2 = *mono3;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__3 = m;
	for (j = 1; j <= i__3; ++j) {
/* Computing MIN */
	    d__1 = bottom, d__2 = b[i__ + j * b_dim1];
	    bottom = min(d__1,d__2);
/* L80: */
/* Computing MAX */
	    d__1 = top, d__2 = b[i__ + j * b_dim1];
	    top = max(d__1,d__2);
	}
    }
    if (*mode == 1) {
	s_wsfe(&io___19);
	do_fio(&c__1, " FREQUENCIES IN CM(-1) FOR PHONON SPECTRUM ACROSS BRI"
		"LLOUIN ZONE", (ftnlen)64);
	e_wsfe();
	i__3 = *mono3;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    s_wsfe(&io___20);
	    do_fio(&c__1, "  BAND:", (ftnlen)7);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
/* L90: */
	    s_wsfe(&io___21);
	    i__2 = m;
	    for (j = 1; j <= i__2; ++j) {
		d__1 = (j - 1) * *step;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&b[i__ + j * b_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
	s_stop("", (ftnlen)0);
    } else {
	s_wsfe(&io___22);
	do_fio(&c__1, " ENERGIES (IN EV) OF ELECTRONIC BANDS IN BAND STRUCTU"
		"RE", (ftnlen)55);
	e_wsfe();
	i__2 = *mono3;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    s_wsfe(&io___23);
	    do_fio(&c__1, "  .", (ftnlen)3);
	    do_fio(&c__1, "  CURVE", (ftnlen)7);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, "CURVE DATA ARE", (ftnlen)14);
	    e_wsfe();
/* L100: */
	    s_wsfe(&io___24);
	    i__3 = m;
	    for (j = 1; j <= i__3; ++j) {
		d__1 = (j - 1) * *step;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&b[i__ + j * b_dim1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
    }
    dofs_(&b[b_offset], mono3, &m, &fmat2d[fmat2d_offset], &c__500, &bottom, &
	    top);
    return 0;
} /* brlzon_ */

