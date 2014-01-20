/* frame.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal coord[360]	/* was [3][120] */;
} coord_;

#define coord_1 coord_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

/* Subroutine */ int frame_(doublereal *fmat, integer *numat, integer *mode, 
	doublereal *shift)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static integer i__, j, k, l;
    static doublereal x, y, z__;
    static integer n3;
    static doublereal vib[2160]	/* was [6][360] */, rot[9]	/* was [3][3] 
	    */, sum, sum1, sum2, sum3, sum4, sum5, sum6;
    extern /* Subroutine */ int axis_(doublereal *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static doublereal sumw, coord1[360]	/* was [3][120] */, wtmass;

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

/*   FRAME APPLIES AN RIGID ORIENTATION TO THE MOLECULE IN A FORCE */
/*         CALCULATION. THE TRANSLATIONS ARE GIVEN A 'FORCE CONSTANT' */
/*         OF T(X)=500 MILLIDYNES/ANGSTROM */
/*            T(Y)=600 MILLIDYNES/ANGSTROM */
/*            T(Z)=700 MILLIDYNES/ANGSTROM */
/*         AND THE ROTATIONS ARE GIVEN A 'FORCE CONSTANT' OF */
/*            R(X)=800 MILLIDYNES/ANGSTROM */
/*            R(Y)=900 MILLIDYNES/ANGSTROM */
/*            R(Z)=1000 MILLIDYNES/ANGSTROM, */
/*    THE ROTATIONS ARE MADE ABOUT AXES DETERMINED BY THE MOMENTS */
/*    OF INERTIA, WHICH IN TURN DEPEND ON THE ISOTOPIC MASSES. FOR */
/*    THE NORMAL FREQUENCY CALCULATION THESE ARE THE REAL MASSES, */
/*    FOR THE FORCE CALCULATION THEY ARE ALL UNITY. */
/* ********************************************************************** */
    /* Parameter adjustments */
    --shift;
    --fmat;

    /* Function Body */
    axis_(coord_1.coord, numat, &a, &b, &c__, &sumw, mode, rot);
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    sum = 0.;
	    for (k = 1; k <= 3; ++k) {
/* L10: */
		sum += coord_1.coord[k + i__ * 3 - 4] * rot[k + j * 3 - 4];
	    }
/* L20: */
	    coord1[j + i__ * 3 - 4] = sum;
	}
    }
    n3 = *numat * 3;
    j = 0;
    wtmass = 1.;
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*mode == 1) {
	    wtmass = sqrt(atmass_1.atmass[i__ - 1]);
	}
	++j;
	vib[j * 6 - 6] = wtmass;
	vib[j * 6 - 5] = 0.;
	vib[j * 6 - 4] = 0.;
	vib[j * 6 - 3] = 0.;
	vib[j * 6 - 2] = coord1[i__ * 3 - 1] * wtmass;
	vib[j * 6 - 1] = coord1[i__ * 3 - 2] * wtmass;
	++j;
	vib[j * 6 - 6] = 0.;
	vib[j * 6 - 5] = wtmass;
	vib[j * 6 - 4] = 0.;
	vib[j * 6 - 3] = coord1[i__ * 3 - 1] * wtmass;
	vib[j * 6 - 2] = 0.;
	vib[j * 6 - 1] = -coord1[i__ * 3 - 3] * wtmass;
	++j;
	vib[j * 6 - 6] = 0.;
	vib[j * 6 - 5] = 0.;
	vib[j * 6 - 4] = wtmass;
	vib[j * 6 - 3] = -coord1[i__ * 3 - 2] * wtmass;
	vib[j * 6 - 2] = -coord1[i__ * 3 - 3] * wtmass;
	vib[j * 6 - 1] = 0.;
/* L30: */
    }
    j = 1;
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (k = 4; k <= 6; ++k) {
	    x = vib[k + j * 6 - 7];
	    y = vib[k + (j + 1) * 6 - 7];
	    z__ = vib[k + (j + 2) * 6 - 7];
	    vib[k + j * 6 - 7] = x * rot[0] + y * rot[3] + z__ * rot[6];
	    vib[k + (j + 1) * 6 - 7] = x * rot[1] + y * rot[4] + z__ * rot[7];
	    vib[k + (j + 2) * 6 - 7] = x * rot[2] + y * rot[5] + z__ * rot[8];
/* L40: */
	}
	j += 3;
/* L50: */
    }
    sum1 = 0.;
    sum2 = 0.;
    sum3 = 0.;
    sum4 = 0.;
    sum5 = 0.;
    sum6 = 0.;
    i__1 = n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	d__1 = vib[i__ * 6 - 6];
	sum1 += d__1 * d__1;
/* Computing 2nd power */
	d__1 = vib[i__ * 6 - 5];
	sum2 += d__1 * d__1;
/* Computing 2nd power */
	d__1 = vib[i__ * 6 - 4];
	sum3 += d__1 * d__1;
/* Computing 2nd power */
	d__1 = vib[i__ * 6 - 3];
	sum4 += d__1 * d__1;
/* Computing 2nd power */
	d__1 = vib[i__ * 6 - 2];
	sum5 += d__1 * d__1;
/* L60: */
/* Computing 2nd power */
	d__1 = vib[i__ * 6 - 1];
	sum6 += d__1 * d__1;
    }
    if (sum1 > 1e-5) {
	sum1 = sqrt(1. / sum1);
    }
    if (sum2 > 1e-5) {
	sum2 = sqrt(1. / sum2);
    }
    if (sum3 > 1e-5) {
	sum3 = sqrt(1. / sum3);
    }
    if (sum4 > 1e-5) {
	sum4 = sqrt(1. / sum4);
    }
    if (sum5 > 1e-5) {
	sum5 = sqrt(1. / sum5);
    }
    if (sum6 > 1e-5) {
	sum6 = sqrt(1. / sum6);
    }
    if (euler_1.id != 0) {
	sum4 = 0.;
	sum5 = 0.;
	sum6 = 0.;
    }
    i__1 = n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	vib[i__ * 6 - 6] *= sum1;
	vib[i__ * 6 - 5] *= sum2;
	vib[i__ * 6 - 4] *= sum3;
	vib[i__ * 6 - 3] *= sum4;
	vib[i__ * 6 - 2] *= sum5;
/* L70: */
	vib[i__ * 6 - 1] *= sum6;
    }
    for (i__ = 1; i__ <= 6; ++i__) {
/* L80: */
	shift[i__] = i__ * 100. + 400.;
    }
    l = 0;
    i__1 = n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
	    sum1 = 0.;
	    for (k = 1; k <= 6; ++k) {
/* L90: */
		sum1 += vib[k + i__ * 6 - 7] * shift[k] * vib[k + j * 6 - 7];
	    }
/* L100: */
	    fmat[l] += sum1;
	}
    }
    return 0;
} /* frame_ */

