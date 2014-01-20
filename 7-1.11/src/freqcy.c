/* freqcy.f -- translated by f2c (version 20020621).
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
    doublereal fmat2d[259200];
    complex vec[129600];
} nllcom_;

#define nllcom_1 nllcom_

struct {
    doublereal r__[1680]	/* was [14][120] */;
    integer nsym, ipo[14400]	/* was [120][120] */, nent;
} symops_;

#define symops_1 symops_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal oldf[129600];
} scrach_;

#define scrach_1 scrach_

struct {
    doublereal dummy1[180600], dummy2[90300], dummy3[90300], alband[586950];
} work1_;

#define work1_1 work1_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int freqcy_(doublereal *fmatrx, doublereal *freq, doublereal 
	*cnorml, doublereal *redmas, doublereal *travel, logical *eorc, 
	doublereal *deldip)
{
    /* Initialized data */

    static doublereal fact = 6.023e23;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l, n3, ii, ij, jj, il, jl, iu, ju, im1;
#define sec ((complex *)&scrach_1)
    static integer jii;
    static doublereal sum;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal c2pi, sum1;
    extern /* Subroutine */ int syma_(doublereal *, doublereal *);
    static doublereal step;
    extern /* Subroutine */ int symt_(doublereal *, doublereal *);
    static integer mono3;
    extern doublereal reada_(char *, integer *, ftnlen);
    extern /* Subroutine */ int frame_(doublereal *, integer *, integer *, 
	    doublereal *);
    static doublereal shift[6];
    static integer linear;
    static doublereal weight;
    extern /* Subroutine */ int vecprt_(doublereal *, integer *), brlzon_(
	    doublereal *, doublereal *, integer *, complex *, complex *, 
	    doublereal *, integer *, doublereal *, integer *);
    static doublereal wtmass[360];

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, "(A)", 0 };


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

/*  FRCE CALCULATES THE FORCE CONSTANTS AND VIBRATIONAL FREQUENCIES */
/*       FOR A MOLECULE.  IT USES THE ISOTOPIC MASSES TO WEIGHT THE */
/*       FORCE MATRIX */

/* ON INPUT   FMATRX   =  FORCE MATRIX, OF SIZE NUMAT*3*(NUMAT*3+1)/2. */

/* ******************************************************************** */
    /* Parameter adjustments */
    deldip -= 4;
    --travel;
    --redmas;
    --cnorml;
    --freq;
    --fmatrx;

    /* Function Body */

/*    CONVERSION FACTOR FOR SPEED OF LIGHT AND 2 PI. */

    c2pi = 5.3087039056530876e-12;
/* NOW TO CALCULATE THE VIBRATIONAL FREQUENCIES */

/*   FIND CONVERSION CONSTANTS FOR MASS WEIGHTED SYSTEM */
    if (i_indx(keywrd_1.keywrd, " GROUP", (ftnlen)241, (ftnlen)6) != 0) {
	symt_(&fmatrx[1], &deldip[4]);
	if (i_indx(keywrd_1.keywrd, " FREQCY", (ftnlen)241, (ftnlen)7) != 0) {
	    s_wsfe(&io___4);
	    do_fio(&c__1, " SYMMETRIZED HESSIAN MATRIX", (ftnlen)27);
	    e_wsfe();
/* #         I=-N3 */
/* #         CALL VECPRT(FMATRX,I) */

/*   THE FORCE MATRIX IS PRINTED AS AN ATOM-ATOM MATRIX RATHER THAN */
/*   AS A 3N*3N MATRIX, AS THE 3N MATRIX IS VERY CONFUSING! */

	    ij = 0;
	    iu = 0;
	    i__1 = molkst_1.numat;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		il = iu + 1;
		iu = il + 2;
		im1 = i__ - 1;
		ju = 0;
		i__2 = im1;
		for (j = 1; j <= i__2; ++j) {
		    jl = ju + 1;
		    ju = jl + 2;
		    sum = 0.;
/* $DOIT ASIS */
		    i__3 = iu;
		    for (ii = il; ii <= i__3; ++ii) {
/* $DOIT ASIS */
			i__4 = ju;
			for (jj = jl; jj <= i__4; ++jj) {
/* L139: */
/* Computing 2nd power */
			    d__1 = fmatrx[ii * (ii - 1) / 2 + jj];
			    sum += d__1 * d__1;
			}
		    }
		    ++ij;
/* L149: */
		    cnorml[ij] = sqrt(sum);
		}
		++ij;
/* L159: */
/* Computing 2nd power */
		d__1 = fmatrx[il * (il + 1) / 2];
/* Computing 2nd power */
		d__2 = fmatrx[(il + 1) * (il + 2) / 2];
/* Computing 2nd power */
		d__3 = fmatrx[(il + 2) * (il + 3) / 2];
/* Computing 2nd power */
		d__4 = fmatrx[(il + 1) * (il + 2) / 2 - 1];
/* Computing 2nd power */
		d__5 = fmatrx[(il + 2) * (il + 3) / 2 - 2];
/* Computing 2nd power */
		d__6 = fmatrx[(il + 2) * (il + 3) / 2 - 1];
		cnorml[ij] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3 + (
			d__4 * d__4 + d__5 * d__5 + d__6 * d__6) * 2.);
	    }
	    i__ = -molkst_1.numat;
	    vecprt_(&cnorml[1], &i__);
	}
    }
    n3 = molkst_1.numat * 3;
    l = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	weight = 1.4142136 / sqrt(atmass_1.atmass[i__ - 1]);
	wtmass[l] = weight;
	wtmass[l + 1] = weight;
	wtmass[l + 2] = weight;
	l += 3;
/* L10: */
	wtmass[l - 1] = weight;
    }
/*    CONVERT TO MASS WEIGHTED FMATRX */
    linear = 0;
    i__1 = n3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++linear;
	    scrach_1.oldf[linear - 1] = fmatrx[linear] * 1e5;
/* L20: */
	    fmatrx[linear] = fmatrx[linear] * wtmass[i__ - 1] * wtmass[j - 1];
	}
    }

/*    1.D5 IS TO CONVERT FROM MILLIDYNES/ANGSTROM TO DYNES/CM. */

/*    DIAGONALIZE */
    i__ = i_indx(keywrd_1.keywrd, " K=", (ftnlen)241, (ftnlen)3);
    if (i__ != 0) {

/*  GO INTO BRILLOUIN ZONE MODE */

	step = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
	i__2 = i_indx(keywrd_1.keywrd + (i__ - 1), ",", 241 - (i__ - 1), (
		ftnlen)1);
	mono3 = (integer) (reada_(keywrd_1.keywrd + (i__ - 1), &i__2, 241 - (
		i__ - 1)) * 3);
	brlzon_(&fmatrx[1], nllcom_1.fmat2d, &n3, sec, nllcom_1.vec, 
		work1_1.alband, &mono3, &step, &c__1);
	return 0;
    }
    frame_(&fmatrx[1], &molkst_1.numat, &c__1, shift);
    rsp_(&fmatrx[1], &n3, &n3, &freq[1], &cnorml[1]);
    i__2 = n3;
    for (i__ = 1; i__ <= i__2; ++i__) {
	j = (integer) ((freq[i__] + 50.) * .01);
/* L30: */
	freq[i__] -= (doublereal) (j * 100);
    }
    i__2 = n3;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L40: */
	freq[i__] *= 1e5;
    }

/*    CALCULATE REDUCED MASSES, STORE IN REDMAS */

    i__2 = n3;
    for (i__ = 1; i__ <= i__2; ++i__) {
	ii = (i__ - 1) * n3;
	sum = 0.;
	i__1 = n3;
	for (j = 1; j <= i__1; ++j) {
	    jii = j + ii;
	    jj = j * (j - 1) / 2;
	    i__4 = j;
	    for (k = 1; k <= i__4; ++k) {
/* L50: */
		sum += cnorml[jii] * scrach_1.oldf[jj + k - 1] * cnorml[k + 
			ii];
	    }
	    i__4 = n3;
	    for (k = j + 1; k <= i__4; ++k) {
/* L60: */
		sum += cnorml[jii] * scrach_1.oldf[k * (k - 1) / 2 + j - 1] * 
			cnorml[k + ii];
	    }
/* L70: */
	}
	sum1 = sum * 2.;
	if ((d__1 = freq[i__], abs(d__1)) > abs(sum) * 1e-20) {
	    sum = sum * 1. / freq[i__];
	} else {
	    sum = 0.;
	}
	d__2 = sqrt(fact * (d__1 = freq[i__], abs(d__1))) * c2pi;
	freq[i__] = d_sign(&d__2, &freq[i__]);
	if ((d__1 = freq[i__], abs(d__1)) < abs(sum1) * 1e20) {
	    sum1 = sqrt((d__1 = freq[i__] / (sum1 * 1e-5), abs(d__1)));
	} else {
	    sum1 = 0.;
	}
	if (sum < 0. || sum > 100.) {
	    sum = 0.;
	}

/* 0.0063024=SQRT(2*A*B*C/N) WHERE */
/*         A=1.196D8 = CONVERSION OF CM**(-1) TO (ERGS = DYNE.ANGSTROMS) */
/*         B=1000.0  = MILLIDYNES TO DYNES */
/*         C=1.D8    = CENTIMETERS TO ANGSTROMS */
/*         N=6.02205D23 = AVOGADRO'S NUMBER */
	travel[i__] = sum1 * .0063024;
	if (travel[i__] > 1.) {
	    travel[i__] = 0.;
	}
/* #      WRITE(6,*)TRAVEL(I) */
/* L80: */
	redmas[i__] = sum;
    }
    if (i_indx(keywrd_1.keywrd, " GROUP", (ftnlen)241, (ftnlen)6) != 0) {
	syma_(&freq[1], &cnorml[1]);
    }
    if (*eorc) {

/*    CONVERT NORMAL VECTORS TO CARTESIAN COORDINATES */
/*    (DELETED) AND NORMALIZE SO THAT THE TOTAL MOVEMENT IS 1.0 ANGSTROM. */

	ij = 0;
	i__2 = n3;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    sum = 0.;
	    j = 0;
	    i__1 = molkst_1.numat;
	    for (jj = 1; jj <= i__1; ++jj) {
		sum1 = 0.;
		cnorml[ij + 1] *= wtmass[j];
/* Computing 2nd power */
		d__1 = cnorml[ij + 1];
		sum1 += d__1 * d__1;

		cnorml[ij + 2] *= wtmass[j + 1];
/* Computing 2nd power */
		d__1 = cnorml[ij + 2];
		sum1 += d__1 * d__1;

		cnorml[ij + 3] *= wtmass[j + 2];
/* Computing 2nd power */
		d__1 = cnorml[ij + 3];
		sum1 += d__1 * d__1;

		j += 3;
		ij += 3;
/* L90: */
		sum += sqrt(sum1);
	    }
	    sum = 1. / sqrt(sum);
	    ij -= n3;
	    i__1 = n3;
	    for (j = 1; j <= i__1; ++j) {
		++ij;
/* L100: */
		cnorml[ij] *= sum;
	    }
/* L110: */
	}

/*          RETURN HESSIAN IN MILLIDYNES/ANGSTROM IN FMATRX */

	i__2 = linear;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L120: */
	    fmatrx[i__] = scrach_1.oldf[i__ - 1] * 1e-5;
	}
    } else {

/*  RETURN HESSIAN AS MASS-WEIGHTED FMATRIX */
	linear = 0;

	i__2 = n3;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = i__;
	    for (j = 1; j <= i__1; ++j) {
		++linear;
/* L130: */
		fmatrx[linear] = scrach_1.oldf[linear - 1] * 1e-5 * wtmass[
			i__ - 1] * wtmass[j - 1];
	    }
	}
    }
    return 0;
} /* freqcy_ */

#undef sec


