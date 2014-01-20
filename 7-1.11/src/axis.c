/* axis.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

/* Subroutine */ int axis_(doublereal *coord, integer *numat, doublereal *a, 
	doublereal *b, doublereal *c__, doublereal *sumw, integer *mass, 
	doublereal *evec)
{
    /* Initialized data */

    static doublereal t[6] = { 0.,0.,0.,0.,0.,0. };
    static integer icalcn = 0;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal x[120], y[120], z__[120], eig[3], rot[3];
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sum;
    static logical first;
    static doublereal sumwx, sumwy, sumwz, const1, const2, xyzmom[3];

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 6, 0, "(/10X,'MOLECULAR WEIGHT =',F8.2,/)", 
	    0 };
    static cilist io___15 = { 0, 6, 0, "(//10X,' PRINCIPAL MOMENTS OF INERTI"
	    "A IN CM(-1)',/)", 0 };
    static cilist io___18 = { 0, 6, 0, "(10X,'A =',F12.6,'   B =',F12.6,    "
	    "              '   C =',F12.6,/)", 0 };
    static cilist io___19 = { 0, 6, 0, "(//10X,' PRINCIPAL MOMENTS OF INERTI"
	    "A IN ',            'UNITS OF 10**(-40)*GRAM-CM**2',/)", 0 };
    static cilist io___20 = { 0, 6, 0, "(10X,'A =',F12.6,'   B =',F12.6,    "
	    "              '   C =',F12.6,/)", 0 };


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

/*  AXIS CALCULATES THE THREE MOMENTS OF INERTIA AND THE MOLECULAR */
/*       WEIGHT.  THE MOMENTS OF INERTIA ARE RETURNED IN A, B, AND C. */
/*       THE MOLECULAR WEIGHT IN SUMW. */
/*       THE UNITS OF INERTIA ARE 10**(-40)GRAM-CM**2, */
/*       AND MOL.WEIGHT IN ATOMIC-MASS-UNITS. (AMU'S) */
/* *********************************************************************** */
    /* Parameter adjustments */
    coord -= 4;
    evec -= 4;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	first = TRUE_;
    }
/* *********************************************************************** */
/*     CONST1 =  10**40/(N*A*A) */
/*               N = AVERGADRO'S NUMBER */
/*               A = CM IN AN ANGSTROM */
/*               10**40 IS TO ALLOW UNITS TO BE 10**(-40)GRAM-CM**2 */

/* *********************************************************************** */
    const1 = 1.66053;
/* *********************************************************************** */

/*     CONST2 = CONVERSION FACTOR FROM ANGSTROM-AMU TO CM**(-1) */

/*            = (PLANCK'S CONSTANT*N*10**16)/(8*PI*PI*C) */
/*            = 6.62618*10**(-27)[ERG-SEC]*6.02205*10**23*10**16/ */
/*              (8*(3.1415926535)**2*2.997925*10**10[CM/SEC]) */

/* *********************************************************************** */
    const2 = 16.8576522;
/*    FIRST WE CENTRE THE MOLECULE ABOUT THE CENTRE OF GRAVITY, */
/*    THIS DEPENDS ON THE ISOTOPIC MASSES, AND THE CARTESIAN GEOMETRY. */

    *sumw = 1e-20;
    sumwx = 0.;
    sumwy = 0.;
    sumwz = 0.;

    if (*mass > 0) {
	i__1 = *numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    *sumw += atmass_1.atmass[i__ - 1];
	    sumwx += atmass_1.atmass[i__ - 1] * coord[i__ * 3 + 1];
	    sumwy += atmass_1.atmass[i__ - 1] * coord[i__ * 3 + 2];
	    sumwz += atmass_1.atmass[i__ - 1] * coord[i__ * 3 + 3];
/* L10: */
	}
    } else {
	*sumw += (doublereal) (*numat);
	i__1 = *numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    sumwx += coord[i__ * 3 + 1];
	    sumwy += coord[i__ * 3 + 2];
	    sumwz += coord[i__ * 3 + 3];
/* L20: */
	}
    }

    if (*mass > 0 && first) {
	s_wsfe(&io___10);
	d__1 = min(99999.99,*sumw);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    sumwx /= *sumw;
    sumwy /= *sumw;
    sumwz /= *sumw;
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x[i__ - 1] = coord[i__ * 3 + 1] - sumwx;
	y[i__ - 1] = coord[i__ * 3 + 2] - sumwy;
/* L30: */
	z__[i__ - 1] = coord[i__ * 3 + 3] - sumwz;
    }
/* *********************************************************************** */

/*    MATRIX FOR MOMENTS OF INERTIA IS OF FORM */

/*           |   Y**2+Z**2                         | */
/*           |    -Y*X       Z**2+X**2             | -I =0 */
/*           |    -Z*X        -Z*Y       X**2+Y**2 | */

/* *********************************************************************** */

/* $DOIT ASIS */
    for (i__ = 1; i__ <= 6; ++i__) {
/* L40: */
	t[i__ - 1] = (doublereal) i__ * 1e-10;
    }

    if (*mass > 0) {
	i__1 = *numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	    d__1 = y[i__ - 1];
/* Computing 2nd power */
	    d__2 = z__[i__ - 1];
	    t[0] += atmass_1.atmass[i__ - 1] * (d__1 * d__1 + d__2 * d__2);
	    t[1] -= atmass_1.atmass[i__ - 1] * x[i__ - 1] * y[i__ - 1];
/* Computing 2nd power */
	    d__1 = z__[i__ - 1];
/* Computing 2nd power */
	    d__2 = x[i__ - 1];
	    t[2] += atmass_1.atmass[i__ - 1] * (d__1 * d__1 + d__2 * d__2);
	    t[3] -= atmass_1.atmass[i__ - 1] * z__[i__ - 1] * x[i__ - 1];
	    t[4] -= atmass_1.atmass[i__ - 1] * y[i__ - 1] * z__[i__ - 1];
/* Computing 2nd power */
	    d__1 = x[i__ - 1];
/* Computing 2nd power */
	    d__2 = y[i__ - 1];
	    t[5] += atmass_1.atmass[i__ - 1] * (d__1 * d__1 + d__2 * d__2);
/* L50: */
	}
    } else {
	i__1 = *numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	    d__1 = y[i__ - 1];
/* Computing 2nd power */
	    d__2 = z__[i__ - 1];
	    t[0] += d__1 * d__1 + d__2 * d__2;
	    t[1] -= x[i__ - 1] * y[i__ - 1];
/* Computing 2nd power */
	    d__1 = z__[i__ - 1];
/* Computing 2nd power */
	    d__2 = x[i__ - 1];
	    t[2] += d__1 * d__1 + d__2 * d__2;
	    t[3] -= z__[i__ - 1] * x[i__ - 1];
	    t[4] -= y[i__ - 1] * z__[i__ - 1];
/* Computing 2nd power */
	    d__1 = x[i__ - 1];
/* Computing 2nd power */
	    d__2 = y[i__ - 1];
	    t[5] += d__1 * d__1 + d__2 * d__2;
/* L60: */
	}
    }

    rsp_(t, &c__3, &c__3, eig, &evec[4]);
    if (*mass > 0 && first && i_indx(keywrd_1.keywrd, "RC=", (ftnlen)241, (
	    ftnlen)3) == 0) {
	s_wsfe(&io___15);
	e_wsfe();
/* $DOIT ASIS */
	for (i__ = 1; i__ <= 3; ++i__) {
	    if (eig[i__ - 1] < 3e-4) {
		eig[i__ - 1] = 0.;
		rot[i__ - 1] = 0.;
	    } else {
		rot[i__ - 1] = const2 / eig[i__ - 1];
	    }
/* L70: */
	    xyzmom[i__ - 1] = eig[i__ - 1] * const1;
	}
	s_wsfe(&io___18);
	for (i__ = 1; i__ <= 3; ++i__) {
	    do_fio(&c__1, (char *)&rot[i__ - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	if (i_indx(keywrd_1.keywrd, "RC=", (ftnlen)241, (ftnlen)3) == 0) {
	    s_wsfe(&io___19);
	    e_wsfe();
	}
	s_wsfe(&io___20);
	for (i__ = 1; i__ <= 3; ++i__) {
	    do_fio(&c__1, (char *)&xyzmom[i__ - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_wsfe();
	*c__ = rot[0];
	*b = rot[1];
	*a = rot[2];
    }

/*   NOW TO ORIENT THE MOLECULE SO THE CHIRALITY IS PRESERVED */

    sum = evec[4] * (evec[8] * evec[12] - evec[9] * evec[11]) + evec[7] * (
	    evec[11] * evec[6] - evec[5] * evec[12]) + evec[10] * (evec[5] * 
	    evec[9] - evec[8] * evec[6]);
    if (sum < 0.) {
/* $DOIT ASIS */
	for (j = 1; j <= 3; ++j) {
/* L80: */
	    evec[j + 3] = -evec[j + 3];
	}
    }
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	coord[i__ * 3 + 1] = x[i__ - 1];
	coord[i__ * 3 + 2] = y[i__ - 1];
	coord[i__ * 3 + 3] = z__[i__ - 1];
/* L90: */
    }
    if (*mass > 0) {
	first = FALSE_;
    }
    return 0;
} /* axis_ */

