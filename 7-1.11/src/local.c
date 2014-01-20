/* local.f -- translated by f2c (version 20020621).
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
    doublereal cold[90000]	/* was [300][300] */, xdumy[39600];
} scrach_;

#define scrach_1 scrach_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int local_(doublereal *c__, integer *mdim, integer *nocc, 
	doublereal *eig)
{
    /* Initialized data */

    static char elemnt[2*99] = "H " "HE" "LI" "BE" "B " "C " "N " "O " "F " 
	    "NE" "NA" "MG" "AL" "SI" "P " "S " "CL" "AR" "K " "CA" "SC" "TI" 
	    "V " "CR" "MN" "FE" "CO" "NI" "CU" "ZN" "GA" "GE" "AS" "SE" "BR" 
	    "KR" "RB" "SR" "Y " "ZR" "NB" "MO" "TC" "RU" "RH" "PD" "AG" "CD" 
	    "IN" "SN" "SB" "TE" "I " "XE" "CS" "BA" "LA" "CE" "PR" "ND" "PM" 
	    "SM" "EU" "GD" "TB" "DY" "HO" "ER" "TM" "YB" "LU" "HF" "TA" "W " 
	    "RE" "OS" "IR" "PT" "AU" "HG" "TL" "PB" "BI" "PO" "AT" "RN" "FR" 
	    "RA" "AC" "TH" "PA" "U " "NP" "PU" "AM" "CM" "BK" "CF" "XX";

    /* Format strings */
    static char fmt_110[] = "(/10x,\002NUMBER OF ITERATIONS =\002,i4/10x,"
	    "\002LOCALISATION VALUE =\002,f14.9,/)";
    static char fmt_120[] = "(3x,\002NUMBER OF CENTERS\002,14x,\002(COMPOSIT"
	    "ION OF ORBITALS)\002//)";
    static char fmt_240[] = "(f10.4,4(5(3x,a2,i3,f6.2),/10x))";
    static char fmt_260[] = "(//20x,\002 LOCALIZED ORBITALS \002,//)";

    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3, i__4;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k;
    static doublereal x;
    static integer i1, k1;
    static doublereal ca, co;
    static integer ii;
    static doublereal sa;
    static integer il, kl, iu, ku;
    static doublereal aij, cii[300], dij, dii, djj;
    static integer iel[20];
    static doublereal bij, eps, sum, eig1[300], psi1[300], psi2[300], sum1;
    static integer iter;
    static doublereal xiiii, xjiii, xijij, xijjj, xjjjj;
    static integer niter;
    static doublereal xiijj, refeig[300];
    extern /* Subroutine */ int matout_(doublereal *, doublereal *, integer *,
	     integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___32 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___33 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___40 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___41 = { 0, 6, 0, fmt_260, 0 };


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

/*   LOCALISATION SUBROUTINE */
/* ON INPUT */
/*        C = EIGENVECTORS IN AN MDIM*MDIM MATRIX */
/*        NOCC = NUMBER OF FILLED LEVELS */
/*        NORBS = NUMBER OF ORBITALS */
/*        NUMAT = NUMBER OF ATOMS */
/*        NLAST   = INTEGER ARRAY OF ATOM ORBITAL COUNTERS */
/*        NFIRST   = INTEGER ARRAY OF ATOM ORBITAL COUNTERS */

/*       SUBROUTINE MAXIMIZES (PSI)**4 */
/*       REFERENCE_ */
/*       A NEW RAPID METHOD FOR ORBITAL LOCALISATION, P.G. PERKINS AND */
/*       J.J.P. STEWART, J.C.S. FARADAY (II) 77, 000, (1981). */

/*       MODIFIED AND CORRECTED TO AVOID SIGMA-PI ORBITAL MIXING BY */
/*       JUAN CARLOS PANIAGUA, UNIVERSITY OF BARCELONA, MAY 1983. */

/* ********************************************************************** */
    /* Parameter adjustments */
    c_dim1 = *mdim;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;
    --eig;

    /* Function Body */
    niter = 100;
    eps = 1e-7;
    i__1 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	refeig[i__ - 1] = eig[i__];
	i__2 = molkst_1.norbs;
	for (j = 1; j <= i__2; ++j) {
/* L10: */
	    scrach_1.cold[i__ + j * 300 - 301] = c__[i__ + j * c_dim1];
	}
    }
    iter = 0;
L20:
    sum = 0.;
    ++iter;
    i__2 = *nocc;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nocc;
	for (j = 1; j <= i__1; ++j) {
	    if (j == i__) {
		goto L70;
	    }
	    xijjj = 0.;
	    xjiii = 0.;
	    xiiii = 0.;
	    xjjjj = 0.;
	    xijij = 0.;
	    xiijj = 0.;
	    i__3 = molkst_1.norbs;
	    for (k = 1; k <= i__3; ++k) {
		psi1[k - 1] = c__[k + i__ * c_dim1];
/* L30: */
		psi2[k - 1] = c__[k + j * c_dim1];
	    }
/* NOW FOLLOWS THE RATE-DETERMINING STEP FOR THE CALCULATION */
	    i__3 = molkst_1.numat;
	    for (k1 = 1; k1 <= i__3; ++k1) {
		kl = molkst_1.nfirst[k1 - 1];
		ku = molkst_1.nlast[k1 - 1];
		dij = 0.;
		dii = 0.;
		djj = 0.;
/* $DOIT ASIS */
		i__4 = ku;
		for (k = kl; k <= i__4; ++k) {
		    dij += psi1[k - 1] * psi2[k - 1];
		    dii += psi1[k - 1] * psi1[k - 1];
		    djj += psi2[k - 1] * psi2[k - 1];
/* L40: */
		}
		xijjj += dij * djj;
		xjiii += dij * dii;
		xiiii += dii * dii;
		xjjjj += djj * djj;
		xijij += dij * dij;
		xiijj += dii * djj;
/* L50: */
	    }
	    aij = xijij - (xiiii + xjjjj - xiijj * 2.) / 4.;
	    bij = xjiii - xijjj;
	    ca = sqrt(aij * aij + bij * bij);
	    sa = aij + ca;
	    if (sa < 1e-14) {
		goto L70;
	    }
	    sum += sa;
	    ca = -aij / ca;
	    ca = (sqrt((ca + 1.) / 2.) + 1.) / 2.;
	    if ((ca * 2. - 1.) * bij < 0.) {
		ca = 1. - ca;
	    }
	    sa = sqrt(1. - ca);
	    ca = sqrt(ca);
	    i__3 = molkst_1.norbs;
	    for (k = 1; k <= i__3; ++k) {
		c__[k + i__ * c_dim1] = ca * psi1[k - 1] + sa * psi2[k - 1];
/* L60: */
		c__[k + j * c_dim1] = -sa * psi1[k - 1] + ca * psi2[k - 1];
	    }
L70:
	    ;
	}
/* L80: */
    }
    sum1 = 0.;
    i__2 = *nocc;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    il = molkst_1.nfirst[j - 1];
	    iu = molkst_1.nlast[j - 1];
	    x = 0.;
/* $DOIT ASIS */
	    i__3 = iu;
	    for (k = il; k <= i__3; ++k) {
/* L90: */
/* Computing 2nd power */
		d__1 = c__[k + i__ * c_dim1];
		x += d__1 * d__1;
	    }
/* L100: */
	    sum1 += x * x;
	}
    }
    if (sum > eps && iter < niter) {
	goto L20;
    }
    s_wsfe(&io___32);
    do_fio(&c__1, (char *)&iter, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&sum1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___33);
    e_wsfe();
    i__1 = *nocc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	i__2 = *nocc;
	for (j = 1; j <= i__2; ++j) {
	    co = 0.;
	    i__3 = molkst_1.norbs;
	    for (k = 1; k <= i__3; ++k) {
/* L130: */
		co += scrach_1.cold[k + j * 300 - 301] * c__[k + i__ * c_dim1]
			;
	    }
/* L140: */
	    sum += co * co * eig[j];
	}
/* L150: */
	eig1[i__ - 1] = sum;
    }
    i__1 = *nocc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x = 100.;
	i__2 = *nocc;
	for (j = i__; j <= i__2; ++j) {
	    if (x < eig1[j - 1]) {
		goto L160;
	    }
	    x = eig1[j - 1];
	    i1 = j;
L160:
	    ;
	}
	eig[i__] = eig1[i1 - 1];
	x = eig1[i1 - 1];
	eig1[i1 - 1] = eig1[i__ - 1];
	eig1[i__ - 1] = x;
	i__2 = molkst_1.norbs;
	for (j = 1; j <= i__2; ++j) {
	    x = c__[j + i1 * c_dim1];
	    c__[j + i1 * c_dim1] = c__[j + i__ * c_dim1];
/* L170: */
	    c__[j + i__ * c_dim1] = x;
	}
/* L180: */
    }
    i__1 = *nocc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x = 0.;
	i__2 = molkst_1.numat;
	for (k1 = 1; k1 <= i__2; ++k1) {
	    kl = molkst_1.nfirst[k1 - 1];
	    ku = molkst_1.nlast[k1 - 1];
	    dii = 0.;
	    i__3 = ku;
	    for (k = kl; k <= i__3; ++k) {
/* L190: */
/* Computing 2nd power */
		d__1 = c__[k + i__ * c_dim1];
		dii += d__1 * d__1;
	    }
	    x += dii * dii;
/* L200: */
	    psi1[k1 - 1] = dii * 100.;
	}
	x = 1 / x;
	i__2 = molkst_1.numat;
	for (ii = 1; ii <= i__2; ++ii) {
	    sum = 0.;
	    i__3 = molkst_1.numat;
	    for (j = 1; j <= i__3; ++j) {
		if (psi1[j - 1] < sum) {
		    goto L210;
		}
		sum = psi1[j - 1];
		k = j;
L210:
		;
	    }
	    psi1[k - 1] = 0.;
	    cii[ii - 1] = sum;
	    iel[ii - 1] = k;
	    if (sum < 1.) {
		goto L230;
	    }
/* L220: */
	}
L230:
	--ii;
	s_wsfe(&io___40);
	do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
	i__2 = ii;
	for (k = 1; k <= i__2; ++k) {
	    do_fio(&c__1, elemnt + (molkst_1.nat[iel[k - 1] - 1] - 1 << 1), (
		    ftnlen)2);
	    do_fio(&c__1, (char *)&iel[k - 1], (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&cii[k - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
/* L250: */
    }
/* L260: */
    s_wsfe(&io___41);
    e_wsfe();
    matout_(&c__[c_offset], &eig[1], nocc, &molkst_1.norbs, mdim);
/* L270: */
    i__1 = *nocc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	eig[i__] = refeig[i__ - 1];
	i__2 = molkst_1.norbs;
	for (j = 1; j <= i__2; ++j) {
/* L280: */
	    c__[j + i__ * c_dim1] = scrach_1.cold[j + i__ * 300 - 301];
	}
    }
    return 0;
} /* local_ */

