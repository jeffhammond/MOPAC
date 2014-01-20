/* interp.f -- translated by f2c (version 20020621).
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

union {
    struct {
	integer npnts, idum2;
	doublereal xlow, xhigh, xmin, emin, demin, x[12], f[12], df[12];
    } _1;
    struct {
	integer n, idum2;
	doublereal xlow, xhigh, xmin, fmin, dfmin, x[12], f[12], df[12];
    } _2;
} fit_;

#define fit_1 (fit_._1)
#define fit_2 (fit_._2)

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b131 = 0.;
static doublereal c_b132 = -1.;

/* Subroutine */ int interp_(integer *n, integer *np, integer *nq, integer *
	mode, doublereal *e, doublereal *fp, doublereal *cp, doublereal *vec, 
	doublereal *fock, doublereal *p, doublereal *h__, doublereal *vecl)
{
    /* Initialized data */

    static integer icalcn = 0;
    static doublereal zero = 0.;
    static doublereal ff = .9;
    static doublereal radmax = 1.5708;

    /* Format strings */
    static char fmt_600[] = "(/14x,\002 X \002,10x,\002 F(X) \002,9x,\002 DF"
	    "/DX \002,\002   ROTATION (DEGREES)\002,/\002      OLD \002,f10.5"
	    ",3f15.10,/\002  CURRENT \002,f10.5,3f15.10,/\002 PREDICTED\002,f"
	    "10.5,3f15.10/)";
    static char fmt_610[] = "(\002  K\002,\002     X(K) \002,\002       F(K)"
	    "    \002,\002     DF(K)\002)";
    static char fmt_620[] = "(i3,f10.5,2f15.10)";
    static char fmt_630[] = "(10x)";

    /* System generated locals */
    integer cp_dim1, cp_offset, vec_dim1, vec_offset, fock_dim1, fock_offset, 
	    p_dim1, p_offset, i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double sqrt(doublereal), asin(doublereal), cos(doublereal), sin(
	    doublereal);

    /* Local variables */
    static integer i__, j, k, i1, j1, k1, k2;
    static doublereal ck;
    static integer ii, ik, ij, il;
    static doublereal sk;
    static integer np1, np2;
    static doublereal dum, eold, dedx, rold, rmin, xold, enow, rnow, xnow;
    static logical debug;
    static doublereal deold, theta[300];
    extern /* Subroutine */ int hqrii_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal denow;
    static integer minpq;
    extern /* Subroutine */ int schmib_(doublereal *, integer *, integer *), 
	    schmit_(doublereal *, integer *, integer *), spline_(void);
    static integer ipoint;

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 6, 0, "('   INTERPOLATED ENERGY:',F13.6)", 0 
	    };
    static cilist io___33 = { 0, 6, 0, "(' ROTATION ANGLE:',F12.4)", 0 };
    static cilist io___37 = { 0, 6, 0, fmt_600, 0 };
    static cilist io___38 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___39 = { 0, 6, 0, fmt_620, 0 };
    static cilist io___40 = { 0, 6, 0, fmt_630, 0 };


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

/* INTERP: AN INTERPOLATION PROCEDURE FOR FORCING SCF CONVERGANCE */
/*         ORIGINAL THEORY AND FORTRAN WRITTEN BY R.N. CAMP AND */
/*         H.F. KING, J. CHEM. PHYS. 75, 268 (1981) */
/* ********************************************************************* */

/* ON INPUT N     = NUMBER OF ORBITALS */
/*          NP    = NUMBER OF FILLED LEVELS */
/*          NQ    = NUMBER OF EMPTY LEVELS */
/*          MODE  = 1, DO NOT RESET. */
/*          E     = ENERGY */
/*          FP    = FOCK MATRIX, AS LOWER HALF TRIANGLE, PACKED */
/*          CP    = EIGENVECTORS OF FOCK MATRIX OF ITERATION -1 */
/*                  AS PACKED ARRAY OF N*N COEFFICIENTS */

/* ON OUTPUT CP   = BEST GUESSED SET OF EIGENVECTORS */
/*           MODE = 2 OR 3 - USED BY CALLING PROGRAM */
/* ********************************************************************* */
    /* Parameter adjustments */
    --vecl;
    --h__;
    p_dim1 = *n;
    p_offset = 1 + p_dim1 * 1;
    p -= p_offset;
    fock_dim1 = *n;
    fock_offset = 1 + fock_dim1 * 1;
    fock -= fock_offset;
    vec_dim1 = *n;
    vec_offset = 1 + vec_dim1 * 1;
    vec -= vec_offset;
    cp_dim1 = *n;
    cp_offset = 1 + cp_dim1 * 1;
    cp -= cp_offset;
    --fp;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	debug = i_indx(keywrd_1.keywrd, "INTERP", (ftnlen)241, (ftnlen)6) != 
		0;
	icalcn = numcal_1.numcal;
    }

/*     RADMAX=MAXIMUM ROTATION ANGLE (RADIANS).  1.5708 = 90 DEGREES. */
/*         FF=FACTOR FOR CONVERGENCE TEST FOR 1D SEARCH. */

    minpq = min(*np,*nq);
    np1 = *np + 1;
/* Computing MAX */
    i__1 = 1, i__2 = *np / 2;
    np2 = max(i__1,i__2);
    if (*mode == 2) {
	goto L110;
    }

/*     (MODE=1 OR 3 ENTRY) */
/*     TRANSFORM FOCK MATRIX TO CURRENT MO BASIS. */
/*     ONLY THE OFF DIAGONAL OCC-VIRT BLOCK IS COMPUTED. */
/*     STORE IN FOCK ARRAY */

    ii = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i1 = i__ + 1;
	i__2 = *nq;
	for (j = 1; j <= i__2; ++j) {
	    dum = zero;
	    i__3 = i__;
	    for (k = 1; k <= i__3; ++k) {
/* L20: */
		dum += fp[ii + k] * cp[k + (j + *np) * cp_dim1];
	    }
	    if (i__ == *n) {
		goto L40;
	    }
	    ik = ii + i__ + i__;
	    i__3 = *n;
	    for (k = i1; k <= i__3; ++k) {
		dum += fp[ik] * cp[k + (j + *np) * cp_dim1];
/* L30: */
		ik += k;
	    }
L40:
	    p[i__ + j * p_dim1] = dum;
	}
/* L50: */
	ii += i__;
    }
    i__1 = *np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *nq;
	for (j = 1; j <= i__2; ++j) {
	    dum = zero;
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
/* L60: */
		dum += cp[k + i__ * cp_dim1] * p[k + j * p_dim1];
	    }
	    fock[i__ + j * fock_dim1] = dum;
/* L70: */
	}
/* L80: */
    }
    if (*mode == 3) {
	goto L100;
    }

/*     CURRENT POINT BECOMES OLD POINT (MODE=1 ENTRY) */

    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
/* L90: */
	    vec[i__ + j * vec_dim1] = cp[i__ + j * cp_dim1];
	}
    }
    eold = *e;
    xold = 1.;
    *mode = 2;
    return 0;

/*     (MODE=3 ENTRY) */
/*     FOCK CORRESPONDS TO CURRENT POINT IN CORRESPONDING REPRESENTATION. */
/*     VEC DOES NOT HOLD CURRENT VECTORS. VEC SET IN LAST MODE=2 ENTRY. */

L100:
    ++fit_1.npnts;
    if (debug) {
	s_wsfe(&io___18);
	d__1 = *e * 23.061;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    ipoint = fit_1.npnts;
    goto L500;

/*    (MODE=2 ENTRY) CALCULATE THETA, AND U, V, W MATRICES. */
/*                   U ROTATES CURRENT INTO OLD MO. */
/*                   V ROTATES CURRENT INTO CORRESPONDING CURRENT MO. */
/*                   W ROTATES OLD INTO CORRESPONDING OLD MO. */

L110:
    j1 = 1;
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	if (i__ == np1) {
	    j1 = np1;
	}
	i__1 = *n;
	for (j = j1; j <= i__1; ++j) {
	    p[i__ + j * p_dim1] = zero;
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
/* L120: */
		p[i__ + j * p_dim1] += cp[k + i__ * cp_dim1] * vec[k + j * 
			vec_dim1];
	    }
/* L130: */
	}
/* L140: */
    }

/*     U = CP(DAGGER)*VEC IS NOW IN P ARRAY. */
/*     VEC IS NOW AVAILABLE FOR TEMPORARY STORAGE. */

    ij = 0;
    i__2 = *np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++ij;
	    h__[ij] = 0.;
	    i__3 = *n;
	    for (k = np1; k <= i__3; ++k) {
/* L150: */
		h__[ij] += p[i__ + k * p_dim1] * p[j + k * p_dim1];
	    }
/* L160: */
	}
/* L170: */
    }
    hqrii_(&h__[1], np, np, theta, &vecl[1]);
    for (i__ = *np; i__ >= 1; --i__) {
	il = i__ * *np - *np;
	for (j = *np; j >= 1; --j) {
/* L180: */
	    vec[j + i__ * vec_dim1] = vecl[j + il];
	}
    }
    i__2 = np2;
    for (i__ = 1; i__ <= i__2; ++i__) {
	dum = theta[np1 - i__ - 1];
	theta[np1 - i__ - 1] = theta[i__ - 1];
	theta[i__ - 1] = dum;
	i__1 = *np;
	for (j = 1; j <= i__1; ++j) {
	    dum = vec[j + (np1 - i__) * vec_dim1];
	    vec[j + (np1 - i__) * vec_dim1] = vec[j + i__ * vec_dim1];
/* L190: */
	    vec[j + i__ * vec_dim1] = dum;
	}
/* L200: */
    }
    i__2 = minpq;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* Computing MAX */
	d__1 = theta[i__ - 1];
	theta[i__ - 1] = max(d__1,zero);
/* Computing MIN */
	d__1 = theta[i__ - 1];
	theta[i__ - 1] = min(d__1,1.);
/* L210: */
	theta[i__ - 1] = asin(sqrt(theta[i__ - 1]));
    }

/*     THETA MATRIX HAS NOW BEEN CALCULATED, ALSO UNITARY VP MATRIX */
/*     HAS BEEN CALCULATED AND STORED IN FIRST NP COLUMNS OF VEC MATRIX. */
/*     NOW COMPUTE WQ */

    i__2 = *nq;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = minpq;
	for (j = 1; j <= i__1; ++j) {
	    vec[i__ + (*np + j) * vec_dim1] = zero;
	    i__3 = *np;
	    for (k = 1; k <= i__3; ++k) {
/* L220: */
		vec[i__ + (*np + j) * vec_dim1] += p[k + (*np + i__) * p_dim1]
			 * vec[k + j * vec_dim1];
	    }
/* L230: */
	}
/* L240: */
    }
    schmit_(&vec[np1 * vec_dim1 + 1], nq, n);

/*     UNITARY WQ MATRIX NOW IN LAST NQ COLUMNS OF VEC MATRIX. */
/*     TRANSPOSE NP BY NP BLOCK OF U STORED IN P */

    i__2 = *np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    dum = p[i__ + j * p_dim1];
	    p[i__ + j * p_dim1] = p[j + i__ * p_dim1];
/* L250: */
	    p[j + i__ * p_dim1] = dum;
	}
/* L260: */
    }

/*     CALCULATE WP MATRIX AND HOLD IN FIRST NP COLUMNS OF P */

    i__2 = *np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *np;
	for (k = 1; k <= i__1; ++k) {
/* L270: */
	    h__[k] = p[i__ + k * p_dim1];
	}
	i__1 = *np;
	for (j = 1; j <= i__1; ++j) {
	    p[i__ + j * p_dim1] = zero;
	    i__3 = *np;
	    for (k = 1; k <= i__3; ++k) {
/* L280: */
		p[i__ + j * p_dim1] += h__[k] * vec[k + j * vec_dim1];
	    }
/* L290: */
	}
/* L300: */
    }
    schmib_(&p[p_offset], np, n);

/*     CALCULATE VQ MATRIX AND HOLD IN LAST NQ COLUMNS OF P MATRIX. */

    i__2 = *nq;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nq;
	for (k = 1; k <= i__1; ++k) {
/* L310: */
	    h__[k] = p[*np + i__ + (*np + k) * p_dim1];
	}
	i__1 = *n;
	for (j = np1; j <= i__1; ++j) {
	    p[i__ + j * p_dim1] = zero;
	    i__3 = *nq;
	    for (k = 1; k <= i__3; ++k) {
/* L320: */
		p[i__ + j * p_dim1] += h__[k] * vec[k + j * vec_dim1];
	    }
/* L330: */
	}
/* L340: */
    }
    schmib_(&p[np1 * p_dim1 + 1], nq, n);

/*     CALCULATE (DE/DX) AT OLD POINT */

    dedx = zero;
    i__2 = *np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nq;
	for (j = 1; j <= i__1; ++j) {
	    dum = zero;
	    i__3 = minpq;
	    for (k = 1; k <= i__3; ++k) {
/* L350: */
		dum += theta[k - 1] * p[i__ + k * p_dim1] * vec[j + (*np + k) 
			* vec_dim1];
	    }
/* L360: */
	    dedx += dum * fock[i__ + j * fock_dim1];
	}
/* L370: */
    }

/*     STORE OLD POINT INFORMATION FOR SPLINE FIT */

    deold = dedx * -4.;
    fit_1.x[1] = xold;
    fit_1.f[1] = eold;
    fit_1.df[1] = deold;

/*     MOVE VP OUT OF VEC ARRAY INTO FIRST NP COLUMNS OF P MATRIX. */

    i__2 = *np;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *np;
	for (j = 1; j <= i__1; ++j) {
/* L380: */
	    p[i__ + j * p_dim1] = vec[i__ + j * vec_dim1];
	}
    }
    k1 = 0;
    k2 = *np;
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	if (j == np1) {
	    k1 = *np;
	}
	if (j == np1) {
	    k2 = *nq;
	}
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    dum = zero;
	    i__3 = k2;
	    for (k = 1; k <= i__3; ++k) {
/* L390: */
		dum += cp[i__ + (k1 + k) * cp_dim1] * p[k + j * p_dim1];
	    }
/* L400: */
	    vec[i__ + j * vec_dim1] = dum;
	}
/* L410: */
    }

/*     CORRESPONDING CURRENT MO VECTORS NOW HELD IN VEC. */
/*     COMPUTE VEC(DAGGER)*FP*VEC */
/*     STORE OFF-DIAGONAL BLOCK IN FOCK ARRAY. */

/* L420: */
    ii = 0;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i1 = i__ + 1;
	i__2 = *nq;
	for (j = 1; j <= i__2; ++j) {
	    dum = zero;
	    i__3 = i__;
	    for (k = 1; k <= i__3; ++k) {
/* L430: */
		dum += fp[ii + k] * vec[k + (j + *np) * vec_dim1];
	    }
	    if (i__ == *n) {
		goto L450;
	    }
	    ik = ii + i__ + i__;
	    i__3 = *n;
	    for (k = i1; k <= i__3; ++k) {
		dum += fp[ik] * vec[k + (j + *np) * vec_dim1];
/* L440: */
		ik += k;
	    }
L450:
	    p[i__ + j * p_dim1] = dum;
	}
/* L460: */
	ii += i__;
    }
    i__1 = *np;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *nq;
	for (j = 1; j <= i__2; ++j) {
	    dum = zero;
	    i__3 = *n;
	    for (k = 1; k <= i__3; ++k) {
/* L470: */
		dum += vec[k + i__ * vec_dim1] * p[k + j * p_dim1];
	    }
	    fock[i__ + j * fock_dim1] = dum;
/* L480: */
	}
/* L490: */
    }

/*     SET LIMITS ON RANGE OF 1-D SEARCH */

    fit_1.npnts = 2;
    ipoint = 1;
    xnow = zero;
    fit_1.xhigh = radmax / theta[0];
    fit_1.xlow = fit_1.xhigh * -.5;

/*     CALCULATE (DE/DX) AT CURRENT POINT AND */
/*     STORE INFORMATION FOR SPLINE FIT */
/*     ***** JUMP POINT FOR MODE=3 ENTRY ***** */

L500:
    dedx = zero;
    i__1 = minpq;
    for (k = 1; k <= i__1; ++k) {
/* L510: */
	dedx += theta[k - 1] * fock[k + k * fock_dim1];
    }
    denow = dedx * -4.;
    enow = *e;
    if (ipoint <= 12) {
	goto L530;
    }
/* L520: */

/*     PERFORM 1-D SEARCH AND DETERMINE EXIT MODE. */

L530:
    fit_1.x[ipoint - 1] = xnow;
    fit_1.f[ipoint - 1] = enow;
    fit_1.df[ipoint - 1] = denow;
    spline_();
    if (eold - enow > ff * (eold - fit_1.emin) || ipoint > 10) {
	goto L560;
    }

/*     (MODE=3 EXIT) RECOMPUTE CP VECTORS AT PREDICTED MINIMUM. */

    xnow = fit_1.xmin;
    i__1 = minpq;
    for (k = 1; k <= i__1; ++k) {
	ck = cos(xnow * theta[k - 1]);
	sk = sin(xnow * theta[k - 1]);
	if (debug) {
	    s_wsfe(&io___33);
	    d__1 = sk * 57.29578;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    cp[i__ + k * cp_dim1] = ck * vec[i__ + k * vec_dim1] - sk * vec[
		    i__ + (*np + k) * vec_dim1];
/* L540: */
	    cp[i__ + (*np + k) * cp_dim1] = sk * vec[i__ + k * vec_dim1] + ck 
		    * vec[i__ + (*np + k) * vec_dim1];
	}
/* L550: */
    }
    *mode = 3;
    return 0;

/*     (MODE=2 EXIT) CURRENT VECTORS GIVE SATISFACTORY ENERGY IMPROVEMENT */
/*     CURRENT POINT BECOMES OLD POINT FOR THE NEXT 1-D SEARCH. */

L560:
    if (*mode == 2) {
	goto L580;
    }
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
/* L570: */
	    vec[i__ + j * vec_dim1] = cp[i__ + j * cp_dim1];
	}
    }
    *mode = 2;
L580:
    rold = xold * theta[0] * 57.29578;
    rnow = xnow * theta[0] * 57.29578;
    rmin = fit_1.xmin * theta[0] * 57.29578;
    if (debug) {
	s_wsfe(&io___37);
	do_fio(&c__1, (char *)&xold, (ftnlen)sizeof(doublereal));
	d__1 = eold * 23.061;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&deold, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rold, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&xnow, (ftnlen)sizeof(doublereal));
	d__2 = enow * 23.061;
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&denow, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rnow, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fit_1.xmin, (ftnlen)sizeof(doublereal));
	d__3 = fit_1.emin * 23.061;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fit_1.demin, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&rmin, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    eold = enow;
    if (fit_1.npnts <= 200) {
	return 0;
    }
    s_wsfe(&io___38);
    e_wsfe();
    i__2 = fit_1.npnts;
    for (k = 1; k <= i__2; ++k) {
/* L590: */
	s_wsfe(&io___39);
	do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&fit_1.x[k - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fit_1.f[k - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fit_1.df[k - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    s_wsfe(&io___40);
    e_wsfe();
    return 0;
} /* interp_ */

/* Subroutine */ int spline_(void)
{
    /* Initialized data */

    static doublereal close = 1e-8;
    static doublereal big = 500.;
    static doublereal huge__ = 1e10;
    static doublereal ustep = 1.;
    static doublereal dstep = 2.;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static doublereal a, b, c__;
    static integer k;
    static doublereal r__;
    static integer n1;
    static doublereal x1, x2, bb, fm, dx, xk, ac3, dum, step;
    static logical skip1, skip2;
    static doublereal xstop, xstart;

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

/*     FIT F(X) BY A CUBIC SPLINE GIVEN VALUES OF THE FUNCTION */
/*     AND ITS FIRST DERIVATIVE AT N PNTS. */
/*     SUBROUTINE RETURNS VALUES OF XMIN,FMIN, AND DFMIN */
/*     AND MAY REORDER THE DATA. */
/*     CALLING PROGRAM SUPPLIES ALL OTHER VALUES IN THE */
/*     COMMON BLOCK. */
/*     XLOW AND XHIGH SET LIMITS ON THE INTERVAL WITHIN WHICH */
/*     TO SEARCH.  SUBROUTINE MAY FURTHER REDUCE THIS INTERVAL. */


/*     SUBROUTINE ASSUMES THAT THE FIRST N-1 DATA PNTS HAVE BEEN */
/*     PREVIOUSLY ORDERED,  X(I).LT.X(I+1) FOR I=1,2,...,N-2 */
/*     NOW MOVE NTH POINT TO ITS PROPER PLACE. */

    fit_2.xmin = fit_2.x[(48 + (0 + (fit_2.n - 1 << 3)) - 48) / 8];
    fit_2.fmin = fit_2.f[fit_2.n - 1];
    fit_2.dfmin = fit_2.df[fit_2.n - 1];
    n1 = fit_2.n - 1;
    k = n1;
L10:
    if (fit_2.x[k - 1] < fit_2.xmin) {
	goto L20;
    }
    fit_2.x[k] = fit_2.x[k - 1];
    fit_2.f[k] = fit_2.f[k - 1];
    fit_2.df[k] = fit_2.df[k - 1];
    --k;
    if (k > 0) {
	goto L10;
    }
L20:
    fit_2.x[k] = fit_2.xmin;
    fit_2.f[k] = fit_2.fmin;
    fit_2.df[k] = fit_2.dfmin;

/*     DEFINE THE INTERVAL WITHIN WHICH WE TRUST THE SPLINE FIT. */
/*     USTEP =  UP HILL STEP SIZE FACTOR */
/*     DSTEP = DOWN HILL STEP SIZE FACTOR */

    if (fit_2.df[0] > 0.f) {
	step = dstep;
    }
    if (fit_2.df[0] <= 0.f) {
	step = ustep;
    }
    xstart = fit_2.x[0] - step * (fit_2.x[1] - fit_2.x[0]);
    xstart = max(xstart,fit_2.xlow);
    if (fit_2.df[fit_2.n - 1] > 0.f) {
	step = ustep;
    }
    if (fit_2.df[fit_2.n - 1] <= 0.f) {
	step = dstep;
    }
    xstop = fit_2.x[fit_2.n - 1] + step * (fit_2.x[fit_2.n - 1] - fit_2.x[n1 
	    - 1]);
    xstop = min(xstop,fit_2.xhigh);

/*     SEARCH FOR MINIMUM */

    i__1 = n1;
    for (k = 1; k <= i__1; ++k) {
	skip1 = k != 1;
	skip2 = k != n1;
	if (fit_2.f[k - 1] >= fit_2.fmin) {
	    goto L30;
	}
	fit_2.xmin = fit_2.x[k - 1];
	fit_2.fmin = fit_2.f[k - 1];
	fit_2.dfmin = fit_2.df[k - 1];
L30:
	dx = fit_2.x[k] - fit_2.x[k - 1];

/*     SKIP INTERVAL IF PNTS ARE TOO CLOSE TOGETHER */

	if (dx <= close) {
	    goto L110;
	}
	x1 = 0.;
	if (k == 1) {
	    x1 = xstart - fit_2.x[0];
	}
	x2 = dx;
	if (k == n1) {
	    x2 = xstop - fit_2.x[n1 - 1];
	}

/*     (A,B,C)=COEF OF (CUBIC,QUADRATIC,LINEAR) TERMS */

	dum = (fit_2.f[k] - fit_2.f[k - 1]) / dx;
	a = (fit_2.df[k - 1] + fit_2.df[k] - dum - dum) / (dx * dx);
	b = (dum + dum + dum - fit_2.df[k - 1] - fit_2.df[k - 1] - fit_2.df[k]
		) / dx;
	c__ = fit_2.df[k - 1];

/*     XK = X-X(K) AT THE MINIMUM WITHIN THE KTH SUBINTERVAL */
/*     TEST FOR PATHOLOGICAL CASES. */

	bb = b * b;
	ac3 = (a + a + a) * c__;
	if (bb < ac3) {
	    goto L90;
	}
	if (b > 0.f) {
	    goto L40;
	}
	if (abs(b) > huge__ * abs(a)) {
	    goto L90;
	}
	goto L50;
L40:
	if (bb > big * abs(ac3)) {
	    goto L60;
	}

/*     WELL BEHAVED CUBIC */

L50:
	xk = (-b + sqrt(bb - ac3)) / (a + a + a);
	goto L70;

/*     CUBIC IS DOMINATED BY QUADRATIC TERM */

L60:
	r__ = ac3 / bb;
	xk = -(((r__ * .039063 + .0625) * r__ + .125) * r__ + .5) * c__ / b;
L70:
	if (xk < x1 || xk > x2) {
	    goto L90;
	}
L80:
	fm = ((a * xk + b) * xk + c__) * xk + fit_2.f[k - 1];
	if (fm > fit_2.fmin) {
	    goto L90;
	}
	fit_2.xmin = xk + fit_2.x[k - 1];
	fit_2.fmin = fm;
	fit_2.dfmin = ((a + a + a) * xk + b + b) * xk + c__;

/*     EXTRAPOLATE TO END OF INTERVAL IF K=1 AND/OR K=N1 */

L90:
	if (skip1) {
	    goto L100;
	}
	skip1 = TRUE_;
	xk = x1;
	goto L80;
L100:
	if (skip2) {
	    goto L110;
	}
	skip2 = TRUE_;
	xk = x2;
	goto L80;
L110:
	;
    }
    return 0;
} /* spline_ */

/* Subroutine */ int schmit_(doublereal *u, integer *n, integer *ndim)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal small = .01;
    static doublereal one = 1.;

    /* System generated locals */
    integer u_dim1, u_offset, i__1, i__2, i__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, k1, ii;
    static doublereal dot, scale;
    static integer npass;

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
    u_dim1 = *ndim;
    u_offset = 1 + u_dim1 * 1;
    u -= u_offset;

    /* Function Body */
    ii = 0;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	k1 = k - 1;

/*     NORMALIZE KTH COLUMN VECTOR */

	dot = zero;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    dot += u[i__ + k * u_dim1] * u[i__ + k * u_dim1];
	}
	if (dot == zero) {
	    goto L100;
	}
	scale = one / sqrt(dot);
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L20: */
	    u[i__ + k * u_dim1] = scale * u[i__ + k * u_dim1];
	}
L30:
	if (k1 == 0) {
	    goto L110;
	}
	npass = 0;

/*     PROJECT OUT K-1 PREVIOUS ORTHONORMAL VECTORS FROM KTH VECTOR */

L40:
	++npass;
	i__2 = k1;
	for (j = 1; j <= i__2; ++j) {
	    dot = zero;
	    i__3 = *n;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L50: */
		dot += u[i__ + j * u_dim1] * u[i__ + k * u_dim1];
	    }
	    i__3 = *n;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L60: */
		u[i__ + k * u_dim1] -= dot * u[i__ + j * u_dim1];
	    }
/* L70: */
	}

/*     SECOND NORMALIZATION (AFTER PROJECTION) */
/*     IF KTH VECTOR IS SMALL BUT NOT ZERO THEN NORMALIZE */
/*     AND PROJECT AGAIN TO CONTROL ROUND-OFF ERRORS. */

	dot = zero;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L80: */
	    dot += u[i__ + k * u_dim1] * u[i__ + k * u_dim1];
	}
	if (dot == zero) {
	    goto L100;
	}
	if (dot < small && npass > 2) {
	    goto L100;
	}
	scale = one / sqrt(dot);
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L90: */
	    u[i__ + k * u_dim1] = scale * u[i__ + k * u_dim1];
	}
	if (dot < small) {
	    goto L40;
	}
	goto L110;

/*     REPLACE LINEARLY DEPENDENT KTH VECTOR BY A UNIT VECTOR. */

L100:
	++ii;
/*     IF(II.GT.N) STOP */
	u[ii + k * u_dim1] = one;
	goto L30;
L110:
	;
    }
    return 0;
} /* schmit_ */

/* Subroutine */ int schmib_(doublereal *u, integer *n, integer *ndim)
{
    /* Initialized data */

    static doublereal zero = 0.;
    static doublereal small = .01;
    static doublereal one = 1.;

    /* System generated locals */
    integer u_dim1, u_offset, i__1, i__2, i__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, k1, n1, ii;
    static doublereal dot, scale;
    static integer npass;


/*     SAME AS SCHMIDT BUT WORKS FROM RIGHT TO LEFT. */

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
    u_dim1 = *ndim;
    u_offset = 1 + u_dim1 * 1;
    u -= u_offset;

    /* Function Body */
    n1 = *n + 1;
    ii = 0;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	k1 = k - 1;

/*     NORMALIZE KTH COLUMN VECTOR */

	dot = zero;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    dot += u[i__ + (n1 - k) * u_dim1] * u[i__ + (n1 - k) * u_dim1];
	}
	if (dot == zero) {
	    goto L100;
	}
	scale = one / sqrt(dot);
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L20: */
	    u[i__ + (n1 - k) * u_dim1] = scale * u[i__ + (n1 - k) * u_dim1];
	}
L30:
	if (k1 == 0) {
	    goto L110;
	}
	npass = 0;

/*     PROJECT OUT K-1 PREVIOUS ORTHONORMAL VECTORS FROM KTH VECTOR */

L40:
	++npass;
	i__2 = k1;
	for (j = 1; j <= i__2; ++j) {
	    dot = zero;
	    i__3 = *n;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L50: */
		dot += u[i__ + (n1 - j) * u_dim1] * u[i__ + (n1 - k) * u_dim1]
			;
	    }
	    i__3 = *n;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* L60: */
		u[i__ + (n1 - k) * u_dim1] -= dot * u[i__ + (n1 - j) * u_dim1]
			;
	    }
/* L70: */
	}

/*     SECOND NORMALIZATION (AFTER PROJECTION) */
/*     IF KTH VECTOR IS SMALL BUT NOT ZERO THEN NORMALIZE */
/*     AND PROJECT AGAIN TO CONTROL ROUND-OFF ERRORS. */

	dot = zero;
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L80: */
	    dot += u[i__ + (n1 - k) * u_dim1] * u[i__ + (n1 - k) * u_dim1];
	}
	if (dot == zero) {
	    goto L100;
	}
	if (dot < small && npass > 2) {
	    goto L100;
	}
	scale = one / sqrt(dot);
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L90: */
	    u[i__ + (n1 - k) * u_dim1] = scale * u[i__ + (n1 - k) * u_dim1];
	}
	if (dot < small) {
	    goto L40;
	}
	goto L110;

/*     REPLACE LINEARLY DEPENDENT KTH VECTOR BY A UNIT VECTOR. */

L100:
	++ii;
/*     IF(II.GT.N) STOP */
	u[ii + (n1 - k) * u_dim1] = one;
	goto L30;
L110:
	;
    }
    return 0;
} /* schmib_ */

/* Subroutine */ int pulay_(doublereal *f, doublereal *p, integer *n, 
	doublereal *fppf, doublereal *fock, doublereal *emat, integer *lfock, 
	integer *nfock, integer *msize, logical *start, doublereal *pl)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal d__;
    static integer i__, j, l, ii, il;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal sum, evec[1000];
    static logical debug;
    static integer lbase, mfock;
    static doublereal const__;
    extern /* Subroutine */ int osinv_(doublereal *, integer *, doublereal *);
    static integer nfock1;
    static doublereal coeffs[20];
    static integer linear, maxlim;
    extern /* Subroutine */ int mamult_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___93 = { 0, 6, 0, "(' MAXIMUM SIZE:',I5)", 0 };
    static cilist io___99 = { 0, 6, 0, "(' EMAT')", 0 };
    static cilist io___100 = { 0, 6, 0, "(6E13.6)", 0 };
    static cilist io___106 = { 0, 6, 0, "(' EVEC')", 0 };
    static cilist io___107 = { 0, 6, 0, "(6F12.6)", 0 };
    static cilist io___108 = { 0, 6, 0, "('    LAGRANGIAN MULTIPLIER (ERROR)"
	    " ='                           ,F13.6)", 0 };


/* *********************************************************************** */

/*   PULAY USES DR. PETER PULAY'S METHOD FOR CONVERGENCE. */
/*         A MATHEMATICAL DESCRIPTION CAN BE FOUND IN */
/*         "P. PULAY, J. COMP. CHEM. 3, 556 (1982). */

/* ARGUMENTS:- */
/*         ON INPUT F      = FOCK MATRIX, PACKED, LOWER HALF TRIANGLE. */
/*                  P      = DENSITY MATRIX, PACKED, LOWER HALF TRIANGLE. */
/*                  N      = NUMBER OF ORBITALS. */
/*                  FPPF   = WORKSTORE OF SIZE MSIZE, CONTENTS WILL BE */
/*                           OVERWRITTEN. */
/*                  FOCK   =      "       "              "         " */
/*                  EMAT   = WORKSTORE OF AT LEAST 15**2 ELEMENTS. */
/*                  START  = LOGICAL, = TRUE TO START PULAY. */
/*                  PL     = UNDEFINED ELEMENT. */
/*      ON OUTPUT   F      = "BEST" FOCK MATRIX, = LINEAR COMBINATION */
/*                           OF KNOWN FOCK MATRICES. */
/*                  START  = FALSE */
/*                  PL     = MEASURE OF NON-SELF-CONSISTENCY */
/*                         = [F*P] = F*P - P*F. */

/* *********************************************************************** */
    /* Parameter adjustments */
    emat -= 21;
    --fock;
    --fppf;
    --p;
    --f;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	maxlim = 6;
	debug = i_indx(keywrd_1.keywrd, "DEBUGPULAY", (ftnlen)241, (ftnlen)10)
		 != 0;
    }
    if (*start) {
	linear = *n * (*n + 1) / 2;
	mfock = *msize / linear;
	if (mfock > maxlim) {
	    mfock = maxlim;
	}
	if (debug) {
	    s_wsfe(&io___93);
	    do_fio(&c__1, (char *)&mfock, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	*nfock = 1;
	*lfock = 1;
	*start = FALSE_;
    } else {
	if (*nfock < mfock) {
	    ++(*nfock);
	}
	if (*lfock != mfock) {
	    ++(*lfock);
	} else {
	    *lfock = 1;
	}
    }
    lbase = (*lfock - 1) * linear;

/*   FIRST, STORE FOCK MATRIX FOR FUTURE REFERENCE. */

    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	fock[(i__ - 1) * mfock + *lfock] = f[i__];
    }

/*   NOW FORM /FOCK*DENSITY-DENSITY*FOCK/, AND STORE THIS IN FPPF */

    mamult_(&p[1], &f[1], &fppf[lbase + 1], n, &c_b131);
    mamult_(&f[1], &p[1], &fppf[lbase + 1], n, &c_b132);

/*   FPPF NOW CONTAINS THE RESULT OF FP - PF. */

    nfock1 = *nfock + 1;
    i__1 = *nfock;
    for (i__ = 1; i__ <= i__1; ++i__) {
	emat[nfock1 + i__ * 20] = -1.;
	emat[i__ + nfock1 * 20] = -1.;
	emat[*lfock + i__ * 20] = dot_(&fppf[(i__ - 1) * linear + 1], &fppf[
		lbase + 1], &linear);
/* L20: */
	emat[i__ + *lfock * 20] = emat[*lfock + i__ * 20];
    }
    *pl = emat[*lfock + *lfock * 20] / linear;
    emat[nfock1 + nfock1 * 20] = 0.;
    const__ = 1. / emat[*lfock + *lfock * 20];
    i__1 = *nfock;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *nfock;
	for (j = 1; j <= i__2; ++j) {
/* L30: */
	    emat[i__ + j * 20] *= const__;
	}
    }
    if (debug) {
	s_wsfe(&io___99);
	e_wsfe();
	i__2 = nfock1;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L40: */
	    s_wsfe(&io___100);
	    i__1 = nfock1;
	    for (j = 1; j <= i__1; ++j) {
		do_fio(&c__1, (char *)&emat[j + i__ * 20], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
    }
    l = 0;
    i__1 = nfock1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = nfock1;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
/* L50: */
	    evec[l - 1] = emat[i__ + j * 20];
	}
    }
    const__ = 1. / const__;
    i__2 = *nfock;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *nfock;
	for (j = 1; j <= i__1; ++j) {
/* L60: */
	    emat[i__ + j * 20] *= const__;
	}
    }
/* ******************************************************************** */
/*   THE MATRIX EMAT SHOULD HAVE FORM */

/*      |<E(1)*E(1)>  <E(1)*E(2)> ...   -1.0| */
/*      |<E(2)*E(1)>  <E(2)*E(2)> ...   -1.0| */
/*      |<E(3)*E(1)>  <E(3)*E(2)> ...   -1.0| */
/*      |<E(4)*E(1)>  <E(4)*E(2)> ...   -1.0| */
/*      |     .            .      ...     . | */
/*      |   -1.0         -1.0     ...    0. | */

/*   WHERE <E(I)*E(J)> IS THE SCALAR PRODUCT OF [F*P] FOR ITERATION I */
/*   TIMES [F*P] FOR ITERATION J. */

/* ******************************************************************** */
    osinv_(evec, &nfock1, &d__);
    if (abs(d__) < 1e-6) {
	*start = TRUE_;
	return 0;
    }
    if (*nfock < 2) {
	return 0;
    }
    il = *nfock * nfock1;
    i__1 = *nfock;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L70: */
	coeffs[i__ - 1] = -evec[i__ + il - 1];
    }
    if (debug) {
	s_wsfe(&io___106);
	e_wsfe();
	s_wsfe(&io___107);
	i__1 = *nfock;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&coeffs[i__ - 1], (ftnlen)sizeof(doublereal)
		    );
	}
	e_wsfe();
	s_wsfe(&io___108);
	do_fio(&c__1, (char *)&evec[nfock1 * nfock1 - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
    }
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	l = 0;
	ii = (i__ - 1) * mfock;
	i__2 = *nfock;
	for (j = 1; j <= i__2; ++j) {
/* L80: */
	    sum += coeffs[j - 1] * fock[j + ii];
	}
/* L90: */
	f[i__] = sum;
    }
    return 0;
} /* pulay_ */

/* Subroutine */ int osinv_(doublereal *a, integer *n, doublereal *d__)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, l[300], m[300], ij, ki, ji, kk, jk, ik, nk, jp, 
	    kj, jq, jr, iz;
    static doublereal tol, biga, holo;

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

/*    OSINV INVERTS A GENERAL SQUARE MATRIX OF ORDER UP TO MAXORB. SEE */
/*          DIMENSION STATEMENTS BELOW. */

/*   ON INPUT       A = GENERAL SQUARE MATRIX STORED LINEARLY. */
/*                  N = DIMENSION OF MATRIX A. */
/*                  D = VARIABLE, NOT DEFINED ON INPUT. */

/*   ON OUTPUT      A = INVERSE OF ORIGINAL A. */
/*                  D = DETERMINANT OF ORIGINAL A, UNLESS A WAS SINGULAR, */
/*                      IN WHICH CASE D = 0.0 */

/* *********************************************************************** */
/* *********************************************************************** */

/*    IF THE VALUE OF TOL GIVEN HERE IS UNSUITABLE, IT CAN BE CHANGED. */
    /* Parameter adjustments */
    --a;

    /* Function Body */
    tol = 1e-8;


/* *********************************************************************** */
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

/*     10 FOLLOWS */

		if (abs(biga) - (d__1 = a[ij], abs(d__1)) >= 0.) {
		    goto L20;
		} else {
		    goto L10;
		}
L10:
		biga = a[ij];
		l[k - 1] = i__;
		m[k - 1] = j;
L20:
		;
	    }
	}
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
	    holo = -a[ki];
	    ji = ki - k + j;
	    a[ki] = a[ji];
/* L40: */
	    a[ji] = holo;
	}
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
	    holo = -a[jk];
	    a[jk] = a[ji];
/* L70: */
	    a[ji] = holo;
	}
L80:
	if (abs(biga) - tol >= 0.) {
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
	i__3 = *n;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    ik = nk + i__;
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
		a[ij] = a[ik] * a[kj] + a[ij];
L150:
		;
	    }
	}
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
/* Computing MIN */
	d__1 = *d__ * biga;
	*d__ = min(d__1,1e10);
	a[kk] = 1. / biga;
/* L180: */
    }
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
	holo = a[jk];
	ji = jr + j;
	a[jk] = -a[ji];
/* L220: */
	a[ji] = holo;
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
	holo = a[ki];
	ji = ki + j - k;
	a[ki] = -a[ji];
/* L250: */
	a[ji] = holo;
    }
    goto L190;
L260:
    return 0;

} /* osinv_ */

