/* rsp.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int rsp_(doublereal *a, integer *n, integer *matz, 
	doublereal *w, doublereal *z__)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    integer z_dim1, z_offset, i__1, i__2;

    /* Local variables */
    static integer i__, j, nm, nv;
    static doublereal fv1[420], fv2[420], eta, eps;
    extern /* Subroutine */ int tql2_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *);
    static integer ierr;
    extern /* Subroutine */ int tred3_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), trbak3_(integer *, integer *, integer *, 
	    doublereal *, integer *, doublereal *), epseta_(doublereal *, 
	    doublereal *), tqlrat_(integer *, doublereal *, doublereal *, 
	    integer *, doublereal *);

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
/* ****************************************************************** */

/*   EISPACK DIAGONALIZATION ROUTINES: TO FIND THE EIGENVALUES AND */
/*           EIGENVECTORS (IF DESIRED) OF A REAL SYMMETRIC PACKED MATRIX. */
/* ON INPUT-      N  IS THE ORDER OF THE MATRIX  A, */
/*                A  CONTAINS THE LOWER TRIANGLE OF THE REAL SYMMETRIC */
/*                   PACKED MATRIX STORED ROW-WISE, */
/*             MATZ  IS AN INTEGER VARIABLE SET EQUAL TO ZERO IF ONLY */
/*                   EIGENVALUES ARE DESIRED,  OTHERWISE IT IS SET TO */
/*                   ANY NON-ZERO INTEGER FOR BOTH EIGENVALUES AND */
/*                   EIGENVECTORS. */
/* ON OUTPUT-     W  CONTAINS THE EIGENVALUES IN ASCENDING ORDER, */
/*                Z  CONTAINS THE EIGENVECTORS IF MATZ IS NOT ZERO, */

/* ****************************************************************** */
/* THIS SUBROUTINE WAS CHOSEN AS BEING THE MOST RELIABLE. (JJPS) */
/*     QUESTIONS AND COMMENTS SHOULD BE DIRECTED TO B. S. GARBOW, */
/*     APPLIED MATHEMATICS DIVISION, ARGONNE NATIONAL LABORATORY */

/*     ------------------------------------------------------------------ */

    /* Parameter adjustments */
    --a;
    z_dim1 = *n;
    z_offset = 1 + z_dim1 * 1;
    z__ -= z_offset;
    --w;

    /* Function Body */
    if (first) {
	first = FALSE_;
	epseta_(&eps, &eta);
    }
    nv = *n * (*n + 1) / 2;
    nm = *n;
    tred3_(n, &nv, &a[1], &w[1], fv1, fv2, &eps, &eps);
    if (*matz != 0) {
	goto L10;
    }
/*     ********** FIND EIGENVALUES ONLY ********** */
    tqlrat_(n, &w[1], fv2, &ierr, &eps);
    goto L40;
/*     ********** FIND BOTH EIGENVALUES AND EIGENVECTORS ********** */
L10:
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {

	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    z__[j + i__ * z_dim1] = 0.;
/* L20: */
	}

	z__[i__ + i__ * z_dim1] = 1.;
/* L30: */
    }

    tql2_(&nm, n, &w[1], fv1, &z__[z_offset], &ierr, &eps);
    if (ierr != 0) {
	goto L40;
    }
    trbak3_(&nm, n, &nv, &a[1], n, &z__[z_offset]);
/*     ********** LAST CARD OF RSP ********** */
L40:
    return 0;
} /* rsp_ */

/* Subroutine */ int epseta_(doublereal *eps, doublereal *eta)
{

/*     COMPUTE AND RETURN ETA, THE SMALLEST REPRESENTABLE NUMBER, */
/*     AND EPS IS THE SMALLEST NUMBER FOR WHICH 1+EPS.NE.1. */


    *eta = 1.;
L10:
    if (*eta / 2. == 0.) {
	goto L20;
    }
    if (*eta < 1e-38) {
	goto L20;
    }
    *eta /= 2.;
    goto L10;
L20:
    *eps = 1.;
L30:
    if (*eps / 2. + 1. == 1.) {
	goto L40;
    }
    if (*eps < 1e-17) {
	goto L40;
    }
    *eps /= 2.;
    goto L30;
L40:
    return 0;
} /* epseta_ */

/* Subroutine */ int tql2_(integer *nm, integer *n, doublereal *d__, 
	doublereal *e, doublereal *z__, integer *ierr, doublereal *eps)
{
    /* System generated locals */
    integer z_dim1, z_offset, i__1, i__2, i__3;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal b, c__, f, g, h__;
    static integer i__, j, k, l, m;
    static doublereal p, r__, s;
    static integer l1, ii, mml;

/*               ===== PROCESSED BY AUGMENT, VERSION 4N ===== */
/*     APPROVED FOR VAX 11/780 ON MAY 6,1980.  J.D.NEECE */
/*               ----- LOCAL VARIABLES ----- */
/*               ----- GLOBAL VARIABLES ----- */
/*               ----- SUPPORTING PACKAGE FUNCTIONS ----- */
/*               ===== TRANSLATED PROGRAM ===== */


/*     THIS SUBROUTINE IS A TRANSLATION OF THE ALGOL PROCEDURE TQL2, */
/*     NUM. MATH. 11, 293-306(1968) BY BOWDLER, MARTIN, REINSCH, AND */
/*     WILKINSON. */
/*     HANDBOOK FOR AUTO. COMP., VOL.II-LINEAR ALGEBRA, 227-240(1971). */

/*     THIS SUBROUTINE FINDS THE EIGENVALUES AND EIGENVECTORS */
/*     OF A SYMMETRIC TRIDIAGONAL MATRIX BY THE QL METHOD. */
/*     THE EIGENVECTORS OF A FULL SYMMETRIC MATRIX CAN ALSO */
/*     BE FOUND IF  TRED2  HAS BEEN USED TO REDUCE THIS */
/*     FULL MATRIX TO TRIDIAGONAL FORM. */

/*     ON INPUT- */

/*        NM MUST BE SET TO THE ROW DIMENSION OF TWO-DIMENSIONAL */
/*          ARRAY PARAMETERS AS DECLARED IN THE CALLING PROGRAM */
/*          DIMENSION STATEMENT, */

/*        N IS THE ORDER OF THE MATRIX, */

/*        D CONTAINS THE DIAGONAL ELEMENTS OF THE INPUT MATRIX, */

/*        E CONTAINS THE SUBDIAGONAL ELEMENTS OF THE INPUT MATRIX */
/*          IN ITS LAST N-1 POSITIONS.  E(1) IS ARBITRARY, */

/*        Z CONTAINS THE TRANSFORMATION MATRIX PRODUCED IN THE */
/*          REDUCTION BY  TRED2, IF PERFORMED.  IF THE EIGENVECTORS */
/*          OF THE TRIDIAGONAL MATRIX ARE DESIRED, Z MUST CONTAIN */
/*          THE IDENTITY MATRIX. */

/*      ON OUTPUT- */

/*        D CONTAINS THE EIGENVALUES IN ASCENDING ORDER.  IF AN */
/*          ERROR EXIT IS MADE, THE EIGENVALUES ARE CORRECT BUT */
/*          UNORDERED FOR INDICES 1,2,...,IERR-1, */

/*        E HAS BEEN DESTROYED, */

/*        Z CONTAINS ORTHONORMAL EIGENVECTORS OF THE SYMMETRIC */
/*          TRIDIAGONAL (OR FULL) MATRIX.  IF AN ERROR EXIT IS MADE, */
/*          Z CONTAINS THE EIGENVECTORS ASSOCIATED WITH THE STORED */
/*          EIGENVALUES, */

/*        IERR IS SET TO */
/*          ZERO       FOR NORMAL RETURN, */
/*          J          IF THE J-TH EIGENVALUE HAS NOT BEEN */
/*                     DETERMINED AFTER 30 ITERATIONS. */

/*     QUESTIONS AND COMMENTS SHOULD BE DIRECTED TO B. S. GARBOW, */
/*     APPLIED MATHEMATICS DIVISION, ARGONNE NATIONAL LABORATORY */

/*     ------------------------------------------------------------------ */


    /* Parameter adjustments */
    z_dim1 = *nm;
    z_offset = 1 + z_dim1 * 1;
    z__ -= z_offset;
    --e;
    --d__;

    /* Function Body */
    *ierr = 0;
    if (*n == 1) {
	goto L160;
    }

    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L10: */
	e[i__ - 1] = e[i__];
    }

    f = 0.;
    b = 0.;
    e[*n] = 0.;

    i__1 = *n;
    for (l = 1; l <= i__1; ++l) {
	j = 0;
	h__ = *eps * ((d__1 = d__[l], abs(d__1)) + (d__2 = e[l], abs(d__2)));
	if (b < h__) {
	    b = h__;
	}
/*     ********** LOOK FOR SMALL SUB-DIAGONAL ELEMENT ********** */
	i__2 = *n;
	for (m = l; m <= i__2; ++m) {
	    if ((d__1 = e[m], abs(d__1)) <= b) {
		goto L30;
	    }
/*     ********** E(N) IS ALWAYS ZERO, SO THERE IS NO EXIT */
/*                THROUGH THE BOTTOM OF THE LOOP ********** */
/* L20: */
	}

L30:
	if (m == l) {
	    goto L100;
	}
L40:
	if (j == 30) {
	    goto L150;
	}
	++j;
/*     ********** FORM SHIFT ********** */
	l1 = l + 1;
	g = d__[l];
	p = (d__[l1] - g) / (e[l] * 2.);
	r__ = sqrt(p * p + 1.);
	d__[l] = e[l] / (p + d_sign(&r__, &p));
	h__ = g - d__[l];

	i__2 = *n;
	for (i__ = l1; i__ <= i__2; ++i__) {
/* L50: */
	    d__[i__] -= h__;
	}

	f += h__;
/*     ********** QL TRANSFORMATION ********** */
	p = d__[m];
	c__ = 1.;
	s = 0.;
	mml = m - l;
/*     ********** FOR I=M-1 STEP -1 UNTIL L DO -- ********** */
	i__2 = mml;
	for (ii = 1; ii <= i__2; ++ii) {
	    i__ = m - ii;
	    g = c__ * e[i__];
	    h__ = c__ * p;
	    if (abs(p) < (d__1 = e[i__], abs(d__1))) {
		goto L60;
	    }
	    c__ = e[i__] / p;
	    r__ = sqrt(c__ * c__ + 1.);
	    e[i__ + 1] = s * p * r__;
	    s = c__ / r__;
	    c__ = 1. / r__;
	    goto L70;
L60:
	    c__ = p / e[i__];
	    r__ = sqrt(c__ * c__ + 1.);
	    e[i__ + 1] = s * e[i__] * r__;
	    s = 1. / r__;
	    c__ *= s;
L70:
	    p = c__ * d__[i__] - s * g;
	    d__[i__ + 1] = h__ + s * (c__ * g + s * d__[i__]);
/*     ********** FORM VECTOR ********** */
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
		h__ = z__[k + (i__ + 1) * z_dim1];
		z__[k + (i__ + 1) * z_dim1] = s * z__[k + i__ * z_dim1] + c__ 
			* h__;
		z__[k + i__ * z_dim1] = c__ * z__[k + i__ * z_dim1] - s * h__;
/* L80: */
	    }

/* L90: */
	}

	e[l] = s * p;
	d__[l] = c__ * p;
	if ((d__1 = e[l], abs(d__1)) > b) {
	    goto L40;
	}
L100:
	d__[l] += f;
/* L110: */
    }
/*     ********** ORDER EIGENVALUES AND EIGENVECTORS ********** */
    i__1 = *n;
    for (ii = 2; ii <= i__1; ++ii) {
	i__ = ii - 1;
	k = i__;
	p = d__[i__];

	i__2 = *n;
	for (j = ii; j <= i__2; ++j) {
	    if (d__[j] >= p) {
		goto L120;
	    }
	    k = j;
	    p = d__[j];
L120:
	    ;
	}

	if (k == i__) {
	    goto L140;
	}
	d__[k] = d__[i__];
	d__[i__] = p;

	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    p = z__[j + i__ * z_dim1];
	    z__[j + i__ * z_dim1] = z__[j + k * z_dim1];
	    z__[j + k * z_dim1] = p;
/* L130: */
	}

L140:
	;
    }

    goto L160;
/*     ********** SET ERROR -- NO CONVERGENCE TO AN */
/*                EIGENVALUE AFTER 30 ITERATIONS ********** */
L150:
    *ierr = l;
L160:
    return 0;
/*     ********** LAST CARD OF TQL2 ********** */
} /* tql2_ */

/* Subroutine */ int tqlrat_(integer *n, doublereal *d__, doublereal *e2, 
	integer *ierr, doublereal *eps)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal b, c__, f, g, h__;
    static integer i__, j, l, m;
    static doublereal p, r__, s;
    static integer l1, ii, mml;

/*               ===== PROCESSED BY AUGMENT, VERSION 4N ===== */
/*     APPROVED FOR VAX 11/780 ON MAY 6,1980.  J.D.NEECE */
/*               ----- LOCAL VARIABLES ----- */
/*               ----- GLOBAL VARIABLES ----- */
/*               ----- SUPPORTING PACKAGE FUNCTIONS ----- */
/*               ===== TRANSLATED PROGRAM ===== */


/*     THIS SUBROUTINE IS A TRANSLATION OF THE ALGOL PROCEDURE TQLRAT, */
/*     ALGORITHM 464, COMM. ACM 16, 689(1973) BY REINSCH. */

/*     THIS SUBROUTINE FINDS THE EIGENVALUES OF A SYMMETRIC */
/*     TRIDIAGONAL MATRIX BY THE RATIONAL QL METHOD. */

/*     ON INPUT- */

/*        N IS THE ORDER OF THE MATRIX, */

/*        D CONTAINS THE DIAGONAL ELEMENTS OF THE INPUT MATRIX, */

/*        E2 CONTAINS THE SQUARES OF THE SUBDIAGONAL ELEMENTS OF THE */
/*          INPUT MATRIX IN ITS LAST N-1 POSITIONS.  E2(1) IS ARBITRARY. */

/*      ON OUTPUT- */

/*        D CONTAINS THE EIGENVALUES IN ASCENDING ORDER.  IF AN */
/*          ERROR EXIT IS MADE, THE EIGENVALUES ARE CORRECT AND */
/*          ORDERED FOR INDICES 1,2,...IERR-1, BUT MAY NOT BE */
/*          THE SMALLEST EIGENVALUES, */

/*        E2 HAS BEEN DESTROYED, */

/*        IERR IS SET TO */
/*          ZERO       FOR NORMAL RETURN, */
/*          J          IF THE J-TH EIGENVALUE HAS NOT BEEN */
/*                     DETERMINED AFTER 30 ITERATIONS. */

/*     QUESTIONS AND COMMENTS SHOULD BE DIRECTED TO B. S. GARBOW, */
/*     APPLIED MATHEMATICS DIVISION, ARGONNE NATIONAL LABORATORY */

/*     ------------------------------------------------------------------ */


    /* Parameter adjustments */
    --e2;
    --d__;

    /* Function Body */
    *ierr = 0;
    if (*n == 1) {
	goto L140;
    }

    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L10: */
	e2[i__ - 1] = e2[i__];
    }

    f = 0.;
    b = 0.;
    e2[*n] = 0.;

    i__1 = *n;
    for (l = 1; l <= i__1; ++l) {
	j = 0;
	h__ = *eps * ((d__1 = d__[l], abs(d__1)) + sqrt(e2[l]));
	if (b > h__) {
	    goto L20;
	}
	b = h__;
	c__ = b * b;
/*     ********** LOOK FOR SMALL SQUARED SUB-DIAGONAL ELEMENT ********** */
L20:
	i__2 = *n;
	for (m = l; m <= i__2; ++m) {
	    if (e2[m] <= c__) {
		goto L40;
	    }
/*     ********** E2(N) IS ALWAYS ZERO, SO THERE IS NO EXIT */
/*                THROUGH THE BOTTOM OF THE LOOP ********** */
/* L30: */
	}

L40:
	if (m == l) {
	    goto L80;
	}
L50:
	if (j == 30) {
	    goto L130;
	}
	++j;
/*     ********** FORM SHIFT ********** */
	l1 = l + 1;
	s = sqrt(e2[l]);
	g = d__[l];
	p = (d__[l1] - g) / (s * 2.);
	r__ = sqrt(p * p + 1.);
	d__[l] = s / (p + d_sign(&r__, &p));
	h__ = g - d__[l];

	i__2 = *n;
	for (i__ = l1; i__ <= i__2; ++i__) {
/* L60: */
	    d__[i__] -= h__;
	}

	f += h__;
/*     ********** RATIONAL QL TRANSFORMATION ********** */
	g = d__[m];
	if (g == 0.) {
	    g = b;
	}
	h__ = g;
	s = 0.;
	mml = m - l;
/*     ********** FOR I=M-1 STEP -1 UNTIL L DO -- ********** */
	i__2 = mml;
	for (ii = 1; ii <= i__2; ++ii) {
	    i__ = m - ii;
	    p = g * h__;
	    r__ = p + e2[i__];
	    e2[i__ + 1] = s * r__;
	    s = e2[i__] / r__;
	    d__[i__ + 1] = h__ + s * (h__ + d__[i__]);
	    g = d__[i__] - e2[i__] / g;
	    if (g == 0.) {
		g = b;
	    }
	    h__ = g * p / r__;
/* L70: */
	}

	e2[l] = s * g;
	d__[l] = h__;
/*     ********** GUARD AGAINST UNDERFLOW IN CONVERGENCE TEST ********** */
	if (h__ == 0.) {
	    goto L80;
	}
	if ((d__1 = e2[l], abs(d__1)) <= (d__2 = c__ / h__, abs(d__2))) {
	    goto L80;
	}
	e2[l] = h__ * e2[l];
	if (e2[l] != 0.) {
	    goto L50;
	}
L80:
	p = d__[l] + f;
/*     ********** ORDER EIGENVALUES ********** */
	if (l == 1) {
	    goto L100;
	}
/*     ********** FOR I=L STEP -1 UNTIL 2 DO -- ********** */
	i__2 = l;
	for (ii = 2; ii <= i__2; ++ii) {
	    i__ = l + 2 - ii;
	    if (p >= d__[i__ - 1]) {
		goto L110;
	    }
	    d__[i__] = d__[i__ - 1];
/* L90: */
	}

L100:
	i__ = 1;
L110:
	d__[i__] = p;
/* L120: */
    }

    goto L140;
/*     ********** SET ERROR -- NO CONVERGENCE TO AN */
/*                EIGENVALUE AFTER 30 ITERATIONS ********** */
L130:
    *ierr = l;
L140:
    return 0;
/*     ********** LAST CARD OF TQLRAT ********** */
} /* tqlrat_ */

/* Subroutine */ int trbak3_(integer *nm, integer *n, integer *nv, doublereal 
	*a, integer *m, doublereal *z__)
{
    /* System generated locals */
    integer z_dim1, z_offset, i__1, i__2, i__3;

    /* Local variables */
    static doublereal h__;
    static integer i__, j, k, l;
    static doublereal s;
    static integer ik, iz;

/*               ===== PROCESSED BY AUGMENT, VERSION 4N ===== */
/*     APPROVED FOR VAX 11/780 ON MAY 6,1980.  J.D.NEECE */
/*               ----- LOCAL VARIABLES ----- */
/*               ----- GLOBAL VARIABLES ----- */
/*               ===== TRANSLATED PROGRAM ===== */


/*     THIS SUBROUTINE IS A TRANSLATION OF THE ALGOL PROCEDURE TRBAK3, */
/*     NUM. MATH. 11, 181-195(1968) BY MARTIN, REINSCH, AND WILKINSON. */
/*     HANDBOOK FOR AUTO. COMP., VOL.II-LINEAR ALGEBRA, 212-226(1971). */

/*     THIS SUBROUTINE FORMS THE EIGENVECTORS OF A REAL SYMMETRIC */
/*     MATRIX BY BACK TRANSFORMING THOSE OF THE CORRESPONDING */
/*     SYMMETRIC TRIDIAGONAL MATRIX DETERMINED BY  TRED3. */

/*     ON INPUT- */

/*        NM MUST BE SET TO THE ROW DIMENSION OF TWO-DIMENSIONAL */
/*          ARRAY PARAMETERS AS DECLARED IN THE CALLING PROGRAM */
/*          DIMENSION STATEMENT, */

/*        N IS THE ORDER OF THE MATRIX, */

/*        NV MUST BE SET TO THE DIMENSION OF THE ARRAY PARAMETER A */
/*          AS DECLARED IN THE CALLING PROGRAM DIMENSION STATEMENT, */

/*        A CONTAINS INFORMATION ABOUT THE ORTHOGONAL TRANSFORMATIONS */
/*          USED IN THE REDUCTION BY  TRED3  IN ITS FIRST */
/*          N*(N+1)/2 POSITIONS, */

/*        M IS THE NUMBER OF EIGENVECTORS TO BE BACK TRANSFORMED, */

/*        Z CONTAINS THE EIGENVECTORS TO BE BACK TRANSFORMED */
/*          IN ITS FIRST M COLUMNS. */

/*     ON OUTPUT- */

/*        Z CONTAINS THE TRANSFORMED EIGENVECTORS */
/*          IN ITS FIRST M COLUMNS. */

/*     NOTE THAT TRBAK3 PRESERVES VECTOR EUCLIDEAN NORMS. */

/*     QUESTIONS AND COMMENTS SHOULD BE DIRECTED TO B. S. GARBOW, */
/*     APPLIED MATHEMATICS DIVISION, ARGONNE NATIONAL LABORATORY */

/*     ------------------------------------------------------------------ */

    /* Parameter adjustments */
    --a;
    z_dim1 = *nm;
    z_offset = 1 + z_dim1 * 1;
    z__ -= z_offset;

    /* Function Body */
    if (*m == 0) {
	goto L50;
    }
    if (*n == 1) {
	goto L50;
    }

    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	l = i__ - 1;
	iz = i__ * l / 2;
	ik = iz + i__;
	h__ = a[ik];
	if (h__ == 0.) {
	    goto L40;
	}

	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    s = 0.;
	    ik = iz;

	    i__3 = l;
	    for (k = 1; k <= i__3; ++k) {
		++ik;
		s += a[ik] * z__[k + j * z_dim1];
/* L10: */
	    }
/*     ********** DOUBLE DIVISION AVOIDS POSSIBLE UNDERFLOW ********** */
	    s = s / h__ / h__;
	    ik = iz;

	    i__3 = l;
	    for (k = 1; k <= i__3; ++k) {
		++ik;
		z__[k + j * z_dim1] -= s * a[ik];
/* L20: */
	    }

/* L30: */
	}

L40:
	;
    }

L50:
    return 0;
/*     ********** LAST CARD OF TRBAK3 ********** */
} /* trbak3_ */

/* Subroutine */ int tred3_(integer *n, integer *nv, doublereal *a, 
	doublereal *d__, doublereal *e, doublereal *e2, doublereal *eps, 
	doublereal *eta)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal f, g, h__;
    static integer i__, j, k, l;
    static doublereal hh;
    static integer ii, jk, iz;
    static doublereal scale;

/*               ===== PROCESSED BY AUGMENT, VERSION 4N ===== */
/*     APPROVED FOR VAX 11/780 ON MAY 6,1980.  J.D.NEECE */
/*               ----- LOCAL VARIABLES ----- */
/*               ----- GLOBAL VARIABLES ----- */
/*               ----- SUPPORTING PACKAGE FUNCTIONS ----- */
/*               ===== TRANSLATED PROGRAM ===== */


/*     THIS SUBROUTINE IS A TRANSLATION OF THE ALGOL PROCEDURE TRED3, */
/*     NUM. MATH. 11, 181-195(1968) BY MARTIN, REINSCH, AND WILKINSON. */
/*     HANDBOOK FOR AUTO. COMP., VOL.II-LINEAR ALGEBRA, 212-226(1971). */

/*     THIS SUBROUTINE REDUCES A REAL SYMMETRIC MATRIX, STORED AS */
/*     A ONE-DIMENSIONAL ARRAY, TO A SYMMETRIC TRIDIAGONAL MATRIX */
/*     USING ORTHOGONAL SIMILARITY TRANSFORMATIONS. */

/*     ON INPUT- */

/*        N IS THE ORDER OF THE MATRIX, */

/*        NV MUST BE SET TO THE DIMENSION OF THE ARRAY PARAMETER A */
/*          AS DECLARED IN THE CALLING PROGRAM DIMENSION STATEMENT, */

/*        A CONTAINS THE LOWER TRIANGLE OF THE REAL SYMMETRIC */
/*          INPUT MATRIX, STORED ROW-WISE AS A ONE-DIMENSIONAL */
/*          ARRAY, IN ITS FIRST N*(N+1)/2 POSITIONS. */

/*     ON OUTPUT- */

/*        A CONTAINS INFORMATION ABOUT THE ORTHOGONAL */
/*          TRANSFORMATIONS USED IN THE REDUCTION, */

/*        D CONTAINS THE DIAGONAL ELEMENTS OF THE TRIDIAGONAL MATRIX, */

/*        E CONTAINS THE SUBDIAGONAL ELEMENTS OF THE TRIDIAGONAL */
/*          MATRIX IN ITS LAST N-1 POSITIONS.  E(1) IS SET TO ZERO, */

/*        E2 CONTAINS THE SQUARES OF THE CORRESPONDING ELEMENTS OF E. */
/*          E2 MAY COINCIDE WITH E IF THE SQUARES ARE NOT NEEDED. */

/*     QUESTIONS AND COMMENTS SHOULD BE DIRECTED TO B. S. GARBOW, */
/*     APPLIED MATHEMATICS DIVISION, ARGONNE NATIONAL LABORATORY */

/*     ------------------------------------------------------------------ */

/*     ********** FOR I=N STEP -1 UNTIL 1 DO -- ********** */
    /* Parameter adjustments */
    --e2;
    --e;
    --d__;
    --a;

    /* Function Body */
    i__1 = *n;
    for (ii = 1; ii <= i__1; ++ii) {
	i__ = *n + 1 - ii;
	l = i__ - 1;
	iz = i__ * l / 2;
	h__ = 0.;
	scale = 0.;
	i__2 = l;
	for (k = 1; k <= i__2; ++k) {
	    ++iz;
	    d__[k] = a[iz];
	    scale += (d__1 = d__[k], abs(d__1));
/* L10: */
	}

	if (scale != 0.) {
	    goto L20;
	}
	e[i__] = 0.;
	e2[i__] = 0.;
	goto L90;

L20:
	i__2 = l;
	for (k = 1; k <= i__2; ++k) {
	    d__[k] /= scale;
	    h__ += d__[k] * d__[k];
/* L30: */
	}

	e2[i__] = scale * scale * h__;
	f = d__[l];
	d__1 = sqrt(h__);
	g = -d_sign(&d__1, &f);
	e[i__] = scale * g;
	h__ -= f * g;
	d__[l] = f - g;
	a[iz] = scale * d__[l];
	if (l == 1) {
	    goto L90;
	}
	f = 0.;

	i__2 = l;
	for (j = 1; j <= i__2; ++j) {
	    g = 0.;
	    jk = j * (j - 1) / 2;
/*     ********** FORM ELEMENT OF A*U ********** */
	    k = 0;
L40:
	    ++k;
	    ++jk;
	    g += a[jk] * d__[k];
	    if (k < j) {
		goto L40;
	    }
	    if (k == l) {
		goto L60;
	    }
L50:
	    jk += k;
	    ++k;
	    g += a[jk] * d__[k];
	    if (k < l) {
		goto L50;
	    }
/*     ********** FORM ELEMENT OF P ********** */
L60:
	    e[j] = g / h__;
	    f += e[j] * d__[j];
/* L70: */
	}

	hh = f / (h__ + h__);
	jk = 0;
/*     ********** FORM REDUCED A ********** */
	i__2 = l;
	for (j = 1; j <= i__2; ++j) {
	    f = d__[j];
	    g = e[j] - hh * f;
	    e[j] = g;

	    i__3 = j;
	    for (k = 1; k <= i__3; ++k) {
		++jk;
		a[jk] = a[jk] - f * e[k] - g * d__[k];
/* L80: */
	    }
	}

L90:
	d__[i__] = a[iz + 1];
	a[iz + 1] = scale * sqrt(h__);
/* L100: */
    }

    return 0;
/*     ********** LAST CARD OF TRED3 ********** */
} /* tred3_ */

