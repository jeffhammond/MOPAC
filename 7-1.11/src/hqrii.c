/* hqrii.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int hqrii_(doublereal *a, integer *n, integer *m, doublereal 
	*e, doublereal *v)
{
    /* System generated locals */
    integer v_dim1, v_offset, i__1, i__2, i__3;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);

    /* Local variables */
    static doublereal c__, h__;
    static integer i__, j, k, l;
    static doublereal r__, s, t, u, w[1800]	/* was [5][360] */, z__, ee, 
	    ff;
    static integer ig, ii;
    static doublereal ra;
    static integer kk, ll;
    static doublereal rn, vn, ww;
    static integer im1, ip1, nm1, nm2, kp1;
    static doublereal del, eps, sum, eps1, eps2, eps3;
    static integer iord, kpiv;
    static doublereal sinv, summ;
    static integer irank, jrank, krank, itere;
    static doublereal gersch, sorter;

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, "(////10X,'IN HQRII, N =',I4,' M =',I4)"
	    , 0 };


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
/* ************************************************************ */

/* HQRII IS A DIAGONALISATION ROUTINE, WRITTEN BY YOSHITAKA BEPPU OF */
/*       NAGOYA UNIVERSITY, JAPAN. */
/*       FOR DETAILS SEE 'COMPUTERS & CHEMISTRY' VOL.6 1982. PAGE 000. */

/* ON INPUT    A       = MATRIX TO BE DIAGONALISED (PACKED CANONICAL) */
/*             N       = SIZE OF MATRIX TO BE DIAGONALISED. */
/*             M       = NUMBER OF EIGENVECTORS NEEDED. */
/*             E       = ARRAY OF SIZE AT LEAST N */
/*             V       = ARRAY OF SIZE AT LEAST NMAX*M */

/* ON OUTPUT   E       = EIGENVALUES */
/*             V       = EIGENVECTORS IN ARRAY OF SIZE NMAX*M */

/* *********************************************************************** */
    /* Parameter adjustments */
    --a;
    --e;
    v_dim1 = *n;
    v_offset = 1 + v_dim1 * 1;
    v -= v_offset;

    /* Function Body */
    if (*n <= 1 || *m <= 1 || *m > *n) {
	if (*n == 1 && *m == 1) {
	    e[1] = a[1];
	    v[v_dim1 + 1] = 1.;
	    return 0;
	}
	s_wsfe(&io___1);
	do_fio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/* EPS3 AND EPS ARE MACHINE-PRECISION DEPENDENT */

    eps3 = 1e-30;
    ll = *n * (*n + 1) / 2 + 1;
    eps = 1e-8;
    iord = -1;
    nm1 = *n - 1;
    if (*n == 2) {
	goto L90;
    }
    nm2 = *n - 2;
    krank = 0;
/*     HOUSEHOLDER TRANSFORMATION */
    i__1 = nm2;
    for (k = 1; k <= i__1; ++k) {
	kp1 = k + 1;
	krank += k;
	w[k * 5 - 4] = a[krank];
	sum = 0.;
	jrank = krank;
	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    w[j * 5 - 4] = a[jrank + k];
	    jrank += j;
/* L10: */
/* Computing 2nd power */
	    d__1 = w[j * 5 - 4];
	    sum = d__1 * d__1 + sum;
	}
	d__1 = sqrt(sum);
	s = d_sign(&d__1, &w[kp1 * 5 - 4]);
	w[k * 5 - 5] = -s;
	w[kp1 * 5 - 4] += s;
	a[k + krank] = w[kp1 * 5 - 4];
	h__ = w[kp1 * 5 - 4] * s;
	if (abs(h__) < eps3) {
	    goto L80;
	}
	summ = 0.;
	irank = krank;
	i__2 = *n;
	for (i__ = kp1; i__ <= i__2; ++i__) {
	    sum = 0.;
	    i__3 = i__;
	    for (j = kp1; j <= i__3; ++j) {
/* L20: */
		sum += a[j + irank] * w[j * 5 - 4];
	    }
	    if (i__ >= *n) {
		goto L40;
	    }
	    ip1 = i__ + 1;
	    jrank = i__ * (i__ + 3) / 2;
	    i__3 = *n;
	    for (j = ip1; j <= i__3; ++j) {
		sum += a[jrank] * w[j * 5 - 4];
/* L30: */
		jrank += j;
	    }
L40:
	    w[i__ * 5 - 5] = sum / h__;
	    irank += i__;
/* L50: */
	    summ = w[i__ * 5 - 5] * w[i__ * 5 - 4] + summ;
	}
	u = summ * .5 / h__;
	jrank = krank;
	i__2 = *n;
	for (j = kp1; j <= i__2; ++j) {
	    w[j * 5 - 5] = w[j * 5 - 4] * u - w[j * 5 - 5];
	    i__3 = j;
	    for (i__ = kp1; i__ <= i__3; ++i__) {
/* L60: */
		a[i__ + jrank] = w[i__ * 5 - 5] * w[j * 5 - 4] + w[j * 5 - 5] 
			* w[i__ * 5 - 4] + a[i__ + jrank];
	    }
/* L70: */
	    jrank += j;
	}
L80:
	a[krank] = h__;
    }
L90:
    w[nm1 * 5 - 4] = a[nm1 * (nm1 + 1) / 2];
    w[*n * 5 - 4] = a[*n * (*n + 1) / 2];
    w[nm1 * 5 - 5] = a[nm1 + *n * (*n - 1) / 2];
    w[*n * 5 - 5] = 0.;
    gersch = abs(w[1]) + abs(w[0]);
    i__1 = nm1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L100: */
/* Computing MAX */
	d__4 = (d__1 = w[(i__ + 1) * 5 - 4], abs(d__1)) + (d__2 = w[i__ * 5 - 
		5], abs(d__2)) + (d__3 = w[(i__ + 1) * 5 - 5], abs(d__3));
	gersch = max(d__4,gersch);
    }
    del = eps * gersch;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	w[i__ * 5 - 3] = w[i__ * 5 - 5];
	e[i__] = w[i__ * 5 - 4];
/* L110: */
	v[i__ + *m * v_dim1] = e[i__];
    }
    if (abs(del) < eps3) {
	goto L220;
    }
/*     QR-METHOD WITH ORIGIN SHIFT */
    k = *n;
L120:
    l = k;
L130:
    if ((d__1 = w[(l - 1) * 5 - 3], abs(d__1)) < del) {
	goto L140;
    }
    --l;
    if (l > 1) {
	goto L130;
    }
L140:
    if (l == k) {
	goto L170;
    }
    ww = (e[k - 1] + e[k]) * .5;
    r__ = e[k] - ww;
/* Computing 2nd power */
    d__2 = w[(k - 1) * 5 - 3];
    d__1 = sqrt(d__2 * d__2 + r__ * r__);
    z__ = d_sign(&d__1, &r__) + ww;
    ee = e[l] - z__;
    e[l] = ee;
    ff = w[l * 5 - 3];
    r__ = sqrt(ee * ee + ff * ff);
    j = l;
    goto L160;
L150:
/* Computing 2nd power */
    d__1 = e[j];
/* Computing 2nd power */
    d__2 = w[j * 5 - 3];
    r__ = sqrt(d__1 * d__1 + d__2 * d__2);
    w[(j - 1) * 5 - 3] = s * r__;
    ee = e[j] * c__;
    ff = w[j * 5 - 3] * c__;
L160:
    c__ = e[j] / r__;
    s = w[j * 5 - 3] / r__;
    ww = e[j + 1] - z__;
    e[j] = (ff * c__ + ww * s) * s + ee + z__;
    e[j + 1] = c__ * ww - s * ff;
    ++j;
    if (j < k) {
	goto L150;
    }
    w[(k - 1) * 5 - 3] = e[k] * s;
    e[k] = e[k] * c__ + z__;
    goto L120;
L170:
    --k;
    if (k > 1) {
	goto L120;
    }
/*    *    *    *    *    *    *    *    *    *    *    *    * */

/*   AT THIS POINT THE ARRAY 'E' CONTAINS THE UN-ORDERED EIGENVALUES */

/*    *    *    *    *    *    *    *    *    *    *    *    * */
/*     STRAIGHT SELECTION SORT OF EIGENVALUES */
    sorter = 1.;
    if (iord < 0) {
	sorter = -1.;
    }
    j = *n;
L180:
    l = 1;
    ii = 1;
    ll = 1;
    i__1 = j;
    for (i__ = 2; i__ <= i__1; ++i__) {
	if ((e[i__] - e[l]) * sorter > 0.) {
	    goto L190;
	}
	l = i__;
	goto L200;
L190:
	ii = i__;
	ll = l;
L200:
	;
    }
    if (ii == ll) {
	goto L210;
    }
    ww = e[ll];
    e[ll] = e[ii];
    e[ii] = ww;
L210:
    j = ii - 1;
    if (j >= 2) {
	goto L180;
    }
L220:
    if (*m == 0) {
	return 0;
    }
/* ************** */
/*  ORDERING OF EIGENVALUES COMPLETE. */
/* ************** */
/*      INVERSE-ITERATION FOR EIGENVECTORS */
    eps1 = 1e-5;
    eps2 = .05;
    rn = 0.;
    ra = eps * .6180339887485;
/*    0.618... IS THE FIBONACCI NUMBER (-1+SQRT(5))/2. */
    ig = 1;
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	im1 = i__ - 1;
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    w[j * 5 - 3] = 0.;
	    w[j * 5 - 2] = w[j * 5 - 5];
	    w[j * 5 - 1] = v[j + *m * v_dim1] - e[i__];
	    rn += ra;
	    if (rn >= eps) {
		rn -= eps;
	    }
/* L230: */
	    v[j + i__ * v_dim1] = rn;
	}
	i__2 = nm1;
	for (j = 1; j <= i__2; ++j) {
	    if ((d__1 = w[j * 5 - 1], abs(d__1)) >= (d__2 = w[j * 5 - 5], abs(
		    d__2))) {
		goto L240;
	    }
	    w[j * 5 - 4] = -w[j * 5 - 1] / w[j * 5 - 5];
	    w[j * 5 - 1] = w[j * 5 - 5];
	    t = w[(j + 1) * 5 - 1];
	    w[(j + 1) * 5 - 1] = w[j * 5 - 2];
	    w[j * 5 - 2] = t;
	    w[j * 5 - 3] = w[(j + 1) * 5 - 2];
	    if ((d__1 = w[j * 5 - 3], abs(d__1)) < eps3) {
		w[j * 5 - 3] = del;
	    }
	    w[(j + 1) * 5 - 2] = 0.;
	    goto L250;
L240:
	    if ((d__1 = w[j * 5 - 1], abs(d__1)) < eps3) {
		w[j * 5 - 1] = del;
	    }
	    w[j * 5 - 4] = -w[j * 5 - 5] / w[j * 5 - 1];
L250:
	    w[(j + 1) * 5 - 2] = w[j * 5 - 3] * w[j * 5 - 4] + w[(j + 1) * 5 
		    - 2];
/* L260: */
	    w[(j + 1) * 5 - 1] = w[j * 5 - 2] * w[j * 5 - 4] + w[(j + 1) * 5 
		    - 1];
	}
	if ((d__1 = w[*n * 5 - 1], abs(d__1)) < eps3) {
	    w[*n * 5 - 1] = del;
	}
	for (itere = 1; itere <= 5; ++itere) {
	    if (itere == 1) {
		goto L280;
	    }
	    i__2 = nm1;
	    for (j = 1; j <= i__2; ++j) {
		if ((d__1 = w[j * 5 - 3], abs(d__1)) < eps3) {
		    goto L270;
		}
		t = v[j + i__ * v_dim1];
		v[j + i__ * v_dim1] = v[j + 1 + i__ * v_dim1];
		v[j + 1 + i__ * v_dim1] = t;
L270:
		v[j + 1 + i__ * v_dim1] = v[j + i__ * v_dim1] * w[j * 5 - 4] 
			+ v[j + 1 + i__ * v_dim1];
	    }
L280:
	    v[*n + i__ * v_dim1] /= w[*n * 5 - 1];
	    v[nm1 + i__ * v_dim1] = (v[nm1 + i__ * v_dim1] - v[*n + i__ * 
		    v_dim1] * w[nm1 * 5 - 2]) / w[nm1 * 5 - 1];
/* Computing MAX */
	    d__3 = (d__1 = v[*n + i__ * v_dim1], abs(d__1)), d__4 = (d__2 = v[
		    nm1 + i__ * v_dim1], abs(d__2)), d__3 = max(d__3,d__4);
	    vn = max(d__3,1e-20);
	    if (*n == 2) {
		goto L300;
	    }
	    k = nm2;
L290:
	    v[k + i__ * v_dim1] = (v[k + i__ * v_dim1] - v[k + 1 + i__ * 
		    v_dim1] * w[k * 5 - 2] - v[k + 2 + i__ * v_dim1] * w[k * 
		    5 - 3]) / w[k * 5 - 1];
/* Computing MAX */
	    d__2 = (d__1 = v[k + i__ * v_dim1], abs(d__1)), d__2 = max(d__2,
		    vn);
	    vn = max(d__2,1e-20);
	    --k;
	    if (k >= 1) {
		goto L290;
	    }
L300:
	    s = eps1 / vn;
	    i__2 = *n;
	    for (j = 1; j <= i__2; ++j) {
/* L310: */
		v[j + i__ * v_dim1] *= s;
	    }
	    if (itere > 1 && vn > 1.) {
		goto L330;
	    }
/* L320: */
	}
/*     TRANSFORMATION OF EIGENVECTORS */
L330:
	if (*n == 2) {
	    goto L380;
	}
	krank = nm2 * (*n + 1) / 2;
	kpiv = nm2 * nm1 / 2;
	for (k = nm2; k >= 1; --k) {
	    kp1 = k + 1;
	    if ((d__1 = a[kpiv], abs(d__1)) <= eps3) {
		goto L360;
	    }
	    sum = 0.;
	    i__2 = *n;
	    for (kk = kp1; kk <= i__2; ++kk) {
		sum += a[krank] * v[kk + i__ * v_dim1];
/* L340: */
		krank += kk;
	    }
	    s = -sum / a[kpiv];
	    i__2 = kp1;
	    for (kk = *n; kk >= i__2; --kk) {
		krank -= kk;
/* L350: */
		v[kk + i__ * v_dim1] = a[krank] * s + v[kk + i__ * v_dim1];
	    }
L360:
	    kpiv -= k;
/* L370: */
	    krank -= kp1;
	}
L380:
	i__2 = i__;
	for (j = ig; j <= i__2; ++j) {
	    if ((d__1 = e[j] - e[i__], abs(d__1)) < eps2) {
		goto L400;
	    }
/* L390: */
	}
	j = i__;
L400:
	ig = j;
	if (ig == i__) {
	    goto L430;
	}
/*     RE-ORTHOGONALISATION */
	i__2 = im1;
	for (k = ig; k <= i__2; ++k) {
	    sum = 0.;
	    i__3 = *n;
	    for (j = 1; j <= i__3; ++j) {
/* L410: */
		sum = v[j + k * v_dim1] * v[j + i__ * v_dim1] + sum;
	    }
	    s = -sum;
	    i__3 = *n;
	    for (j = 1; j <= i__3; ++j) {
/* L420: */
		v[j + i__ * v_dim1] = v[j + k * v_dim1] * s + v[j + i__ * 
			v_dim1];
	    }
	}
/*     NORMALISATION */
L430:
	sum = 1e-24;
	i__3 = *n;
	for (j = 1; j <= i__3; ++j) {
/* L440: */
/* Computing 2nd power */
	    d__1 = v[j + i__ * v_dim1];
	    sum += d__1 * d__1;
	}
	sinv = 1. / sqrt(sum);
	i__3 = *n;
	for (j = 1; j <= i__3; ++j) {
/* L450: */
	    v[j + i__ * v_dim1] *= sinv;
	}
    }
    return 0;
} /* hqrii_ */

