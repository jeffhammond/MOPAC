/* diis.f -- translated by f2c (version 20020621).
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

static integer c__15 = 15;
static integer c__1 = 1;
static doublereal c_b37 = 10.;

/* Subroutine */ int diis_(doublereal *xp, doublereal *xparam, doublereal *gp,
	 doublereal *grad, doublereal *hp, doublereal *heat, doublereal *hs, 
	integer *nvar, logical *frst)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void);
    double sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen);
    double pow_di(doublereal *, integer *);

    /* Local variables */
    static doublereal b[256];
    static integer i__, j, k;
    static doublereal s;
    static integer ii, ij, jj;
    static doublereal bs[256];
    static integer kj, mm;
    static doublereal dx[360], det;
    static integer ink;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal err[5400], bst[256];
    static integer inv, jnv, ione;
    static doublereal eset[15], gset[5400];
    static integer mset;
    extern /* Subroutine */ int minv_(doublereal *, integer *, doublereal *);
    static doublereal xmax, xset[5400];
    static logical debug;
    extern /* Subroutine */ int space_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, logical *);
    static integer itera;
    static doublereal gsave[360];
    static integer ndiis;
    static doublereal thres;
    static logical print;
    static integer mplus;
    static doublereal xnorm;
    extern /* Subroutine */ int vecprt_(doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 6, 0, "(/,'      ***** BEGIN GDIIS ***** ')", 
	    0 };
    static cilist io___27 = { 0, 6, 0, "(/5X,' GDIIS MATRIX')", 0 };
    static cilist io___31 = { 0, 6, 0, "(/5X,' GDIIS MATRIX (SCALED)')", 0 };
    static cilist io___35 = { 0, 6, 0, "(/10X,'DEVIATION IN X ',F7.4,8X,'DET"
	    "ERMINANT ',   G9.3)", 0 };
    static cilist io___36 = { 0, 6, 0, "(10X,'GDIIS COEFFICIENTS')", 0 };
    static cilist io___37 = { 0, 6, 0, "(10X,5F12.5)", 0 };
    static cilist io___39 = { 0, 6, 0, "(10X,'THE DIIS MATRIX IS ILL CONDITI"
	    "ONED', /10X,' - PROBABLY, VECTORS ARE LINEARLY DEPENDENT - ',   "
	    "      /10X,'THE DIIS STEP WILL BE REPEATED WITH A SMALLER SPACE')"
	    , 0 };
    static cilist io___40 = { 0, 6, 0, "(10X,'NEWTON-RAPHSON STEP TAKEN')", 0 
	    };
    static cilist io___41 = { 0, 6, 0, "(/,'      ***** END GDIIS ***** ',/)",
	     0 };


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
/*                                                                      * */
/*     DIIS PERFORMS DIRECT INVERSION IN THE ITERATIVE SUBSPACE         * */
/*                                                                      * */
/*     THIS INVOLVES SOLVING FOR C IN XPARAM(NEW) = XPARAM' - HG'       * */
/*                                                                      * */
/*  WHERE XPARAM' = SUM(C(I)XPARAM(I), THE C COEFFICIENTES COMING FROM  * */
/*                                                                      * */
/*                   | B   1 | . | C | = | 0 |                          * */
/*                   | 1   0 |   |-L |   | 1 |                          * */
/*                                                                      * */
/* WHERE B(I,J) =GRAD(I)H(T)HGRAD(J)  GRAD(I) = GRADIENT ON CYCLE I     * */
/*                              H    = INVERSE HESSIAN                  * */
/*                                                                      * */
/*                          REFERENCE                                   * */
/*                                                                      * */
/*  P. CSASZAR, P. PULAY, J. MOL. STRUCT. (THEOCHEM), 114, 31 (1984)    * */
/*                                                                      * */
/* *********************************************************************** */
/* *********************************************************************** */
/*                                                                      * */
/*     GEOMETRY OPTIMIZATION USING THE METHOD OF DIRECT INVERSION IN    * */
/*     THE ITERATIVE SUBSPACE (GDIIS), COMBINED WITH THE BFGS OPTIMIZER * */
/*     (A VARIABLE METRIC METHOD)                                       * */
/*                                                                      * */
/*     WRITTEN BY PETER L. CUMMINS, UNIVERSITY OF SYDNEY, AUSTRALIA     * */
/*                                                                      * */
/*                              REFERENCE                               * */
/*                                                                      * */
/*      "COMPUTATIONAL STRATEGIES FOR THE OPTIMIZATION OF EQUILIBRIUM   * */
/*     GEOMETRIES AND TRANSITION-STATE STRUCTURES AT THE SEMIEMPIRICAL  * */
/*     LEVEL", PETER L. CUMMINS, JILL E. GREADY, J. COMP. CHEM., 10,    * */
/*     939-950 (1989).                                                  * */
/*                                                                      * */
/*     MODIFIED BY JJPS TO CONFORM TO EXISTING MOPAC CONVENTIONS        * */
/*                                                                      * */
/* *********************************************************************** */
    /* Parameter adjustments */
    --hs;
    --grad;
    --gp;
    --xparam;
    --xp;

    /* Function Body */
    debug = FALSE_;
    print = i_indx(keywrd_1.keywrd, " DIIS", (ftnlen)241, (ftnlen)5) != 0;
    if (print) {
	debug = i_indx(keywrd_1.keywrd, "DEBUG", (ftnlen)241, (ftnlen)5) != 0;
    }
    if (print) {
	s_wsfe(&io___3);
	e_wsfe();
    }

/*  SPACE SIMPLY LOADS THE CURRENT VALUES OF XPARAM AND GNORM INTO */
/*  THE ARRAYS XSET AND GSET */

    space_(&c__15, &mset, &xparam[1], &grad[1], heat, nvar, xset, gset, eset, 
	    frst);

/*     INITIALIZE SOME VARIABLES AND CONSTANTS */

    ndiis = mset;
    mplus = mset + 1;
    mm = mplus * mplus;

/*     COMPUTE THE APPROXIMATE ERROR VECTORS */

    inv = -(*nvar);
    i__1 = mset;
    for (i__ = 1; i__ <= i__1; ++i__) {
	inv += *nvar;
	i__2 = *nvar;
	for (j = 1; j <= i__2; ++j) {
	    s = 0.;
	    kj = j * (j - 1) / 2;
	    i__3 = j;
	    for (k = 1; k <= i__3; ++k) {
		++kj;
/* L10: */
		s -= hs[kj] * gset[inv + k - 1];
	    }
	    i__3 = *nvar;
	    for (k = j + 1; k <= i__3; ++k) {
		kj = k * (k - 1) / 2 + j;
/* L20: */
		s -= hs[kj] * gset[inv + k - 1];
	    }
/* L30: */
	    err[inv + j - 1] = s;
	}
    }

/*     CONSTRUCT THE GDIIS MATRIX */

    i__2 = mm;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L40: */
	b[i__ - 1] = 1.;
    }
    jj = 0;
    inv = -(*nvar);
    i__2 = mset;
    for (i__ = 1; i__ <= i__2; ++i__) {
	inv += *nvar;
	jnv = -(*nvar);
	i__1 = mset;
	for (j = 1; j <= i__1; ++j) {
	    jnv += *nvar;
	    ++jj;
	    b[jj - 1] = 0.;
	    i__3 = *nvar;
	    for (k = 1; k <= i__3; ++k) {
/* L50: */
		b[jj - 1] += err[inv + k - 1] * err[jnv + k - 1];
	    }
	}
    }

    for (i__ = mset - 1; i__ >= 1; --i__) {
	for (j = mset; j >= 1; --j) {
/* L60: */
	    b[i__ * mset + j + i__ - 1] = b[i__ * mset + j - 1];
	}
    }
    i__3 = mplus;
    for (i__ = 1; i__ <= i__3; ++i__) {
	b[mplus * i__ - 1] = 1.;
/* L70: */
	b[mplus * mset + i__ - 1] = 1.;
    }
    b[mm - 1] = 0.;

/*     ELIMINATE ERROR VECTORS WITH THE LARGEST NORM */

L80:
    i__3 = mm;
    for (i__ = 1; i__ <= i__3; ++i__) {
/* L90: */
	bs[i__ - 1] = b[i__ - 1];
    }
    if (ndiis == mset) {
	goto L140;
    }
    i__3 = mset - ndiis;
    for (ii = 1; ii <= i__3; ++ii) {
	xmax = -1e10;
	itera = 0;
	i__1 = mset;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    xnorm = 0.;
	    inv = (i__ - 1) * mplus;
	    i__2 = mset;
	    for (j = 1; j <= i__2; ++j) {
/* L100: */
		xnorm += (d__1 = b[inv + j - 1], abs(d__1));
	    }
	    if (xmax < xnorm && xnorm != 1.) {
		xmax = xnorm;
		itera = i__;
		ione = inv + i__;
	    }
/* L110: */
	}
	i__1 = mplus;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    inv = (i__ - 1) * mplus;
	    i__2 = mplus;
	    for (j = 1; j <= i__2; ++j) {
		jnv = (j - 1) * mplus;
		if (j == itera) {
		    b[inv + j - 1] = 0.;
		}
		b[jnv + i__ - 1] = b[inv + j - 1];
/* L120: */
	    }
	}
	b[ione - 1] = 1.;
/* L130: */
    }
L140:

    if (debug) {

/*     OUTPUT THE GDIIS MATRIX */

	s_wsfe(&io___27);
	e_wsfe();
	ij = 0;
	i__3 = mplus;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
		++ij;
/* L150: */
		bst[ij - 1] = b[mplus * (j - 1) + i__ - 1];
	    }
	}
	vecprt_(bst, &mplus);
    }

/*     SCALE DIIS MATRIX BEFORE INVERSION */

    i__2 = mplus;
    for (i__ = 1; i__ <= i__2; ++i__) {
	ii = mplus * (i__ - 1) + i__;
/* L160: */
	gsave[i__ - 1] = 1. / sqrt((d__1 = b[ii - 1], abs(d__1)) + 1e-20);
    }
    gsave[mplus - 1] = 1.;
    i__2 = mplus;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__3 = mplus;
	for (j = 1; j <= i__3; ++j) {
	    ij = mplus * (i__ - 1) + j;
/* L170: */
	    b[ij - 1] = b[ij - 1] * gsave[i__ - 1] * gsave[j - 1];
	}
    }

    if (debug) {

/*     OUTPUT SCALED GDIIS MATRIX */

	s_wsfe(&io___31);
	e_wsfe();
	ij = 0;
	i__3 = mplus;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
		++ij;
/* L180: */
		bst[ij - 1] = b[mplus * (j - 1) + i__ - 1];
	    }
	}
	vecprt_(bst, &mplus);
    }

/*     INVERT THE GDIIS MATRIX */

    minv_(b, &mplus, &det);

    i__2 = mplus;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__3 = mplus;
	for (j = 1; j <= i__3; ++j) {
	    ij = mplus * (i__ - 1) + j;
/* L190: */
	    b[ij - 1] = b[ij - 1] * gsave[i__ - 1] * gsave[j - 1];
	}
    }

/*     COMPUTE THE INTERMEDIATE INTERPOLATED PARAMETER AND GRADIENT */
/*     VECTORS */

    i__3 = *nvar;
    for (k = 1; k <= i__3; ++k) {
	xp[k] = 0.;
	gp[k] = 0.;
	i__2 = mset;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ink = (i__ - 1) * *nvar + k;
	    xp[k] += b[mplus * mset + i__ - 1] * xset[ink - 1];
/* L200: */
	    gp[k] += b[mplus * mset + i__ - 1] * gset[ink - 1];
	}
    }
    *hp = 0.;
    i__2 = mset;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L210: */
	*hp += b[mplus * mset + i__ - 1] * eset[i__ - 1];
    }

    i__2 = *nvar;
    for (k = 1; k <= i__2; ++k) {
/* L220: */
	dx[k - 1] = xparam[k] - xp[k];
    }
    xnorm = sqrt(dot_(dx, dx, nvar));
    if (print) {
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&xnorm, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&det, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___36);
	e_wsfe();
	s_wsfe(&io___37);
	i__2 = mset;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&b[mplus * mset + i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
    }

/*     THE FOLLOWING TOLERENCES FOR XNORM AND DET ARE SOMEWHAT ARBITRARY! */

/* Computing MAX */
    i__2 = -(*nvar);
    d__1 = pow_di(&c_b37, &i__2);
    thres = max(d__1,1e-25);
    if (xnorm > 2. || abs(det) < thres) {
	if (print) {
	    s_wsfe(&io___39);
	    e_wsfe();
	}
	i__2 = mm;
	for (k = 1; k <= i__2; ++k) {
/* L230: */
	    b[k - 1] = bs[k - 1];
	}
	--ndiis;
	if (ndiis > 0) {
	    goto L80;
	}
	if (print) {
	    s_wsfe(&io___40);
	    e_wsfe();
	}
	i__2 = *nvar;
	for (k = 1; k <= i__2; ++k) {
	    xp[k] = xparam[k];
/* L240: */
	    gp[k] = grad[k];
	}

    }
    if (print) {
	s_wsfe(&io___41);
	e_wsfe();
    }

    return 0;
} /* diis_ */

/* Subroutine */ int space_(integer *mreset, integer *mset, doublereal *
	xparam, doublereal *grad, doublereal *heat, integer *nvar, doublereal 
	*xset, doublereal *gset, doublereal *eset, logical *frst)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer i__, k, mi, ni, nmk, nreset;

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

/*     UPDATE PARAMETER AND GRADIENT SUBSPACE */

    /* Parameter adjustments */
    --eset;
    --gset;
    --xset;
    --grad;
    --xparam;

    /* Function Body */
    if (*frst) {
/* Computing MIN */
	i__1 = *nvar / 2;
	nreset = min(i__1,*mreset);
	*frst = FALSE_;
	*mset = 0;
    }

    if (*mset == nreset) {
	i__1 = *mset - 1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    mi = *nvar * (i__ - 1);
	    ni = *nvar * i__;
	    eset[i__] = eset[i__ + 1];
	    i__2 = *nvar;
	    for (k = 1; k <= i__2; ++k) {
		xset[mi + k] = xset[ni + k];
/* L10: */
		gset[mi + k] = gset[ni + k];
	    }
	}
	*mset = nreset - 1;
    }

/*     STORE THE CURRENT POINT */

    i__2 = *nvar;
    for (k = 1; k <= i__2; ++k) {
	nmk = *nvar * *mset + k;
	xset[nmk] = xparam[k];
/* L20: */
	gset[nmk] = grad[k];
    }
    ++(*mset);
    eset[*mset] = *heat;

    return 0;
} /* space_ */

/* Subroutine */ int minv_(doublereal *a, integer *n, doublereal *d__)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Local variables */
    static integer i__, j, k, l[360], m[360], ij, ki, ji, kk, jk, ik, nk, jp, 
	    kj, jq, jr, iz;
    static doublereal biga, hold;

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

/*     INVERT A MATRIX USING GAUSS-JORDAN METHOD.  PART OF DIIS */
/*     A - INPUT MATRIX (MUST BE A GENERAL MATRIX), DESTROYED IN */
/*        COMPUTATION AND REPLACED BY RESULTANT INVERSE. */
/*     N - ORDER OF MATRIX A */
/*     D - RESULTANT DETERMINANT */

/* ********************************************************************* */

/*     SEARCH FOR LARGEST ELEMENT */

    /* Parameter adjustments */
    --a;

    /* Function Body */
    *d__ = 1.;
    nk = -(*n);
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	nk += *n;
	l[k - 1] = k;
	m[k - 1] = k;
	kk = nk + k;
	biga = a[kk];
	i__2 = *n;
	for (j = k; j <= i__2; ++j) {
	    iz = *n * (j - 1);
	    i__3 = *n;
	    for (i__ = k; i__ <= i__3; ++i__) {
		ij = iz + i__;
/* L10: */
		if (abs(biga) < (d__1 = a[ij], abs(d__1))) {
		    biga = a[ij];
		    l[k - 1] = i__;
		    m[k - 1] = j;
		}
/* L20: */
	    }
	}

/*     INTERCHANGE ROWS */

	j = l[k - 1];
	if (j - k <= 0) {
	    goto L50;
	} else {
	    goto L30;
	}
L30:
	ki = k - *n;
	i__3 = *n;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    ki += *n;
	    hold = -a[ki];
	    ji = ki - k + j;
	    a[ki] = a[ji];
/* L40: */
	    a[ji] = hold;
	}

/*     INTERCHANGE COLUMNS */

L50:
	i__ = m[k - 1];
	if (i__ - k <= 0) {
	    goto L80;
	} else {
	    goto L60;
	}
L60:
	jp = *n * (i__ - 1);
	i__3 = *n;
	for (j = 1; j <= i__3; ++j) {
	    jk = nk + j;
	    ji = jp + j;
	    hold = -a[jk];
	    a[jk] = a[ji];
/* L70: */
	    a[ji] = hold;
	}

/*     DIVIDE COLUMN BY MINUS PIVOT (VALUE OF PIVOT ELEMENT IS */
/*     CONTAINED IN BIGA) */

L80:
	if (biga != 0.) {
	    goto L100;
	} else {
	    goto L90;
	}
L90:
	*d__ = 0.;
	return 0;
L100:
	i__3 = *n;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    if (i__ - k != 0) {
		goto L110;
	    } else {
		goto L120;
	    }
L110:
	    ik = nk + i__;
	    a[ik] /= -biga;
L120:
	    ;
	}
/*  REDUCE MATRIX */
	i__3 = *n;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    ik = nk + i__;
	    hold = a[ik];
	    ij = i__ - *n;
	    i__2 = *n;
	    for (j = 1; j <= i__2; ++j) {
		ij += *n;
		if (i__ - k != 0) {
		    goto L130;
		} else {
		    goto L150;
		}
L130:
		if (j - k != 0) {
		    goto L140;
		} else {
		    goto L150;
		}
L140:
		kj = ij - i__ + k;
		a[ij] = hold * a[kj] + a[ij];
L150:
		;
	    }
	}

/*     DIVIDE ROW BY PIVOT */

	kj = k - *n;
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    kj += *n;
	    if (j - k != 0) {
		goto L160;
	    } else {
		goto L170;
	    }
L160:
	    a[kj] /= biga;
L170:
	    ;
	}

/*     PRODUCT OF PIVOTS */

/* Computing MAX */
	d__1 = -1e25, d__2 = min(1e25,*d__);
	*d__ = max(d__1,d__2);
	*d__ *= biga;

/*     REPLACE PIVOT BY RECIPROCAL */

	a[kk] = 1. / biga;
/* L180: */
    }

/*     FINAL ROW AND COLUMN INTERCHANGE */

    k = *n;
L190:
    --k;
    if (k <= 0) {
	goto L260;
    } else {
	goto L200;
    }
L200:
    i__ = l[k - 1];
    if (i__ - k <= 0) {
	goto L230;
    } else {
	goto L210;
    }
L210:
    jq = *n * (k - 1);
    jr = *n * (i__ - 1);
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	jk = jq + j;
	hold = a[jk];
	ji = jr + j;
	a[jk] = -a[ji];
/* L220: */
	a[ji] = hold;
    }
L230:
    j = m[k - 1];
    if (j - k <= 0) {
	goto L190;
    } else {
	goto L240;
    }
L240:
    ki = k - *n;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ki += *n;
	hold = a[ki];
	ji = ki - k + j;
	a[ki] = -a[ji];
/* L250: */
	a[ji] = hold;
    }
    goto L190;
L260:
    return 0;
} /* minv_ */

