/* cdiag.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static real c_b24 = 1.f;

/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/*     this subroutine is moved to the top of the */
/*     source file in order to resolve the mis- */
/*     matching parameter types later in code. */
/*     2005-10-11 Tommi Hassinen */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Subroutine */ int ec08c_(complex *a, complex *b, real *value, real *vec, 
	integer *n, integer *iv, real *w)
{
    /* Initialized data */

    static real one = 1.f;
    static real zero = 0.f;

    /* System generated locals */
    integer i__1, i__2, i__3;
    complex q__1, q__2, q__3;
    static complex equiv_0[1];

    /* Builtin functions */
    double c_abs(complex *);
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static integer i__, j, k, l, i1, n2;
    static complex dn;
    static integer il, iv2;
#define pck ((real *)equiv_0)
    extern /* Subroutine */ int ea08c_(real *, real *, real *, real *, 
	    integer *, integer *, real *);
#define upck (equiv_0)


/* TO FIND THE EIGENVALUES AND VECTORS OF A TRI-DIAGONAL */
/*  HERMITIAN MATRIX. */
/*  WE TREAT VEC AS IF IT IS DEFINED AS COMPLEX VEC(IV,N) */
/*  IN THE CALLING PROGRAM. */
    /* Parameter adjustments */
    --w;
    --vec;
    --value;
    --b;
    --a;

    /* Function Body */
    iv2 = *iv + *iv;
    n2 = *n + *n;
    il = iv2 * (*n - 1) + 1;
    w[1] = a[1].r;

/*  THE HERMITIAN FORM IS TRANSFORMED INTO A REAL FORM */
    if (*n - 1 <= 0) {
	goto L80;
    } else {
	goto L10;
    }
L10:
    i__1 = *n;
    for (i__ = 2; i__ <= i__1; ++i__) {
	i__2 = i__;
	i__3 = i__;
	w[i__2] = a[i__3].r;
/* L20: */
	w[i__ + *n] = c_abs(&b[i__]);
    }

/*  FIND THE EIGENVALUES AND VECTORS OF THE REAL FORM */
/* L30: */
    ea08c_(&w[1], &w[*n + 1], &value[1], &vec[1], n, &iv2, &w[n2 + 1]);

/* THE VECTORS IN VEC AT THIS POINT ARE REAL,WE NOW EXPAND THEM */
/* INTO VEC AS THOUGH THEY WERE COMPLEX. */
    i__1 = il;
    i__2 = iv2;
    for (i__ = 1; i__2 < 0 ? i__ >= i__1 : i__ <= i__1; i__ += i__2) {
	i__3 = *n;
	for (j = 1; j <= i__3; ++j) {
	    k = *n - j;
	    l = k + k;
/* L40: */
	    vec[i__ + l] = vec[i__ + k];
	}
/* L50: */
	vec[i__ + 1] = zero;
    }
    if (*n <= 1) {
	goto L80;
    }
    dn.r = one, dn.i = 0.f;
    k = 1;

/* TRANSFORM VECTORS OF REAL FORM TO THOSE OF COMPLEX FORM. */
    i__2 = n2;
    for (i__ = 4; i__ <= i__2; i__ += 2) {
	++k;
	upck->r = one, upck->i = 0.f;
	if (w[k + *n] != zero) {
	    r_cnjg(&q__3, &b[k]);
	    q__2.r = dn.r * q__3.r - dn.i * q__3.i, q__2.i = dn.r * q__3.i + 
		    dn.i * q__3.r;
	    i__1 = k + *n;
	    q__1.r = q__2.r / w[i__1], q__1.i = q__2.i / w[i__1];
	    upck->r = q__1.r, upck->i = q__1.i;
	}
	i1 = il - 1 + i__;
	i__1 = i1;
	i__3 = iv2;
	for (j = i__; i__3 < 0 ? j >= i__1 : j <= i__1; j += i__3) {
	    vec[j] = vec[j - 1] * pck[1];
/* L60: */
	    vec[j - 1] *= pck[0];
	}
/* L70: */
	dn.r = upck->r, dn.i = upck->i;
    }
L80:
    return 0;
} /* ec08c_ */

#undef upck
#undef pck


/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/*     this subroutine is moved to the top of the */
/*     source file in order to resolve the mis- */
/*     matching parameter types later in code. */
/*     2005-10-11 Tommi Hassinen */
/* CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC */
/* Subroutine */ int me08b_(real *a, real *q, real *b, integer *n, integer *
	ia)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1;

    /* Local variables */
    static integer i__;

    /* Parameter adjustments */
    q -= 3;
    b_dim1 = *ia;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    a_dim1 = *ia;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a[i__ * a_dim1 + 1] = a[i__ * a_dim1 + 1] - q[3] * b[i__ * b_dim1 + 1]
		 + q[4] * b[i__ * b_dim1 + 2] - q[(i__ << 1) + 1] * b[b_dim1 
		+ 1] + q[(i__ << 1) + 2] * b[b_dim1 + 2];
/* L10: */
	a[i__ * a_dim1 + 2] = a[i__ * a_dim1 + 2] - q[4] * b[i__ * b_dim1 + 1]
		 - q[3] * b[i__ * b_dim1 + 2] + q[(i__ << 1) + 2] * b[b_dim1 
		+ 1] + q[(i__ << 1) + 1] * b[b_dim1 + 2];
    }
    return 0;
} /* me08b_ */

/* Subroutine */ int cdiag_(complex *a, real *value, complex *vec, integer *n,
	 integer *need)
{
    /* System generated locals */
    integer a_dim1, a_offset, vec_dim1, vec_offset, i__1, i__2, i__3, i__4, 
	    i__5;
    complex q__1, q__2, q__3;

    /* Builtin functions */
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static real h__;
    static integer i__, k, l;
    static real s;
    static complex w[6000];
    static integer i1, ia, ii, iv;
    extern /* Subroutine */ int ec08c_(complex *, complex *, real *, real *, 
	    integer *, integer *, real *), me08a_(complex *, complex *, 
	    complex *, integer *, integer *, complex *), sort_(real *, 
	    complex *, integer *);
    extern /* Complex */ VOID fm06as_(complex *, integer *, complex *, 
	    integer *, complex *, integer *);


/* TO FIND THE EIGENVALUES AND EIGENVECTORS OF A HERMITIAN MATRIX. */
    /* Parameter adjustments */
    --value;
    vec_dim1 = *n;
    vec_offset = 1 + vec_dim1 * 1;
    vec -= vec_offset;
    a_dim1 = *n;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;

    /* Function Body */
    ia = *n;
    iv = *n;

/* REDUCE MATRIX TO A TRI-DIAGONAL HERMITIAN MATRIX. */
    me08a_(&a[a_offset], w, &w[*n], n, &ia, &w[*n * 2]);

/* FIND THE EIGENVALUES AND EIGENVECTORS OF THE TRI-DIAGONAL MATRIX */
    ec08c_(w, &w[*n], &value[1], (real*)&vec[vec_offset], n, &iv, (real*)&w[*
	    n * 2]);
    if (*need == 0) {
	goto L50;
    }
    if (*n < 2) {
	return 0;
    }

/* THE EIGENVECTORS OF THE ORIGINAL MATRIX ARE NOW FOUND BY */
/* BACK TRANSFORMATION USING INFORMATION STORE IN THE UPPER */
/* TRIANGLE OF MATRIX A (BY ME08) */
    i__1 = *n;
    for (ii = 3; ii <= i__1; ++ii) {
	i__ = *n - ii + 1;
	i__2 = *n + i__;
	r_cnjg(&q__2, &a[i__ + (i__ + 1) * a_dim1]);
	q__1.r = w[i__2].r * q__2.r - w[i__2].i * q__2.i, q__1.i = w[i__2].r *
		 q__2.i + w[i__2].i * q__2.r;
	h__ = q__1.r;
	if (h__ != 0.f) {
	    goto L10;
	} else {
	    goto L40;
	}
L10:
	i__2 = *n;
	for (l = 1; l <= i__2; ++l) {
	    i1 = i__ + 1;
	    i__3 = *n - i__;
	    fm06as_(&q__1, &i__3, &a[i__ + (i__ + 1) * a_dim1], &ia, &vec[i__ 
		    + 1 + l * vec_dim1], &c__1);
	    s = q__1.r;
	    s /= h__;
	    i__3 = *n;
	    for (k = i1; k <= i__3; ++k) {
/* L20: */
		i__4 = k + l * vec_dim1;
		i__5 = k + l * vec_dim1;
		r_cnjg(&q__3, &a[i__ + k * a_dim1]);
		q__2.r = s * q__3.r, q__2.i = s * q__3.i;
		q__1.r = vec[i__5].r + q__2.r, q__1.i = vec[i__5].i + q__2.i;
		vec[i__4].r = q__1.r, vec[i__4].i = q__1.i;
	    }
/* L30: */
	}
L40:
	;
    }
L50:
    sort_(&value[1], &vec[vec_offset], n);
    return 0;
} /* cdiag_ */

/* Subroutine */ int ea08c_(real *a, real *b, real *value, real *vec, integer 
	*m, integer *iv, real *w)
{
    /* Initialized data */

    static real eps = 1e-6f;
    static real a34 = 0.f;

    /* Format strings */
    static char fmt_90[] = "(\0021CYCLE DETECTED IN SUBROUTINE EA08 -STOPPIN"
	    "G NOW\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double r_sign(real *, real *), sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static real s;
    static integer j1, j2, n1, n2, n3;
    static real v1, v2, a11, bb, a22, cc, a12, a23, a13, a33, a21;
    static integer ii;
    static real co;
    static integer ki, jk, mi, ji, mn;
    static real si, xx;
    static integer mn2, n2m1;
    static real sml, xax;
    extern /* Subroutine */ int ea09c_(real *, real *, real *, integer *, 
	    real *);
    static integer iter;
    static real root;

    /* Fortran I/O blocks */
    static cilist io___61 = { 0, 6, 0, fmt_90, 0 };


/*  STANDARD FORTRAN 66 (A VERIFIED PFORT SUBROUTINE) */
    /* Parameter adjustments */
    --w;
    --vec;
    --value;
    --b;
    --a;

    /* Function Body */
/*     THIS USES QR ITERATION TO FIND THE EIGENVALUES AND EIGENVECTORS */
/*  OF THE SYMMETRIC TRIDIAGONAL MATRIX WHOSE DIAGONAL ELEMENTS ARE */
/*  A(I),I=1,M AND OFF-DIAGONAL ELEMENTS ARE B(I),I=2,M.  THE ARRAY */
/*  W IS USED FOR WORKSPACE AND MUST HAVE DIMENSION AT LEAST 2*M. */
/*  WE TREAT VEC AS IF IT HAD DIMENSIONS (IV,M). */
    sml = eps * (real) (*m);
    ea09c_(&a[1], &b[1], &w[*m + 1], m, &w[1]);
/*     SET VEC TO THE IDENTITY MATRIX. */
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	value[i__] = a[i__];
	w[i__] = b[i__];
	k = (i__ - 1) * *iv + 1;
	l = k + *m - 1;
	i__2 = l;
	for (j = k; j <= i__2; ++j) {
/* L10: */
	    vec[j] = 0.f;
	}
	ki = k + i__ - 1;
/* L20: */
	vec[ki] = 1.f;
    }
    k = 0;
    if (*m == 1) {
	return 0;
    }
    i__1 = *m;
    for (n3 = 2; n3 <= i__1; ++n3) {
	n2 = *m + 2 - n3;
/*     EACH QR ITERATION IS PERFORMED OF ROWS AND COLUMNS N1 TO N2 */
	mn2 = *m + n2;
	root = w[mn2];
	for (iter = 1; iter <= 20; ++iter) {
	    bb = (value[n2] - value[n2 - 1]) * .5f;
	    cc = w[n2] * w[n2];
	    a22 = value[n2];
	    if (cc != 0.f) {
		a22 += cc / (bb + r_sign(&c_b24, &bb) * sqrt(bb * bb + cc));
	    }
	    i__2 = n2;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		mi = *m + i__;
		if ((r__1 = root - a22, dabs(r__1)) <= (r__2 = w[mi] - a22, 
			dabs(r__2))) {
		    goto L30;
		}
		root = w[mi];
		mn = *m + n2;
		w[mi] = w[mn];
		w[mn] = root;
L30:
		;
	    }
	    i__2 = n2;
	    for (ii = 2; ii <= i__2; ++ii) {
		n1 = n2 + 2 - ii;
		if ((r__3 = w[n1], dabs(r__3)) <= ((r__1 = value[n1 - 1], 
			dabs(r__1)) + (r__2 = value[n1], dabs(r__2))) * sml) {
		    goto L50;
		}
/* L40: */
	    }
	    n1 = 1;
L50:
	    if (n2 == n1) {
		goto L100;
	    }
	    n2m1 = n2 - 1;
	    if (iter >= 3) {
		root = a22;
	    }
	    ++k;
	    a22 = value[n1];
	    a12 = a22 - root;
	    a23 = w[n1 + 1];
	    a13 = a23;
	    i__2 = n2m1;
	    for (i__ = n1; i__ <= i__2; ++i__) {
		a33 = value[i__ + 1];
		if (i__ != n2m1) {
		    a34 = w[i__ + 2];
		}
		r__1 = sqrt(a12 * a12 + a13 * a13);
		s = r_sign(&r__1, &a12);
		si = a13 / s;
		co = a12 / s;
		jk = i__ * *iv + 1;
		j1 = jk - *iv;
/* Computing MIN */
		i__3 = *m, i__4 = i__ + k;
		j2 = j1 + min(i__3,i__4) - 1;
		i__3 = j2;
		for (ji = j1; ji <= i__3; ++ji) {
		    v1 = vec[ji];
		    v2 = vec[jk];
		    vec[ji] = v1 * co + v2 * si;
		    vec[jk] = v2 * co - v1 * si;
/* L60: */
		    ++jk;
		}
		if (i__ != n1) {
		    w[i__] = s;
		}
		a11 = co * a22 + si * a23;
		a12 = co * a23 + si * a33;
		a13 = si * a34;
		a21 = co * a23 - si * a22;
		a22 = co * a33 - si * a23;
		a23 = co * a34;
		value[i__] = a11 * co + a12 * si;
		a12 = -a11 * si + a12 * co;
		w[i__ + 1] = a12;
/* L70: */
		a22 = a22 * co - a21 * si;
	    }
/* L80: */
	    value[n2] = a22;
	}
	s_wsfe(&io___61);
	e_wsfe();
	s_stop("", (ftnlen)0);
L100:
	;
    }
/*     RAYLEIGH QUOTIENT */
    i__1 = *m;
    for (j = 1; j <= i__1; ++j) {
	k = (j - 1) * *iv;
/* Computing 2nd power */
	r__1 = vec[k + 1];
	xx = r__1 * r__1;
	xax = xx * a[1];
	i__2 = *m;
	for (i__ = 2; i__ <= i__2; ++i__) {
	    ki = k + i__;
/* Computing 2nd power */
	    r__1 = vec[ki];
	    xx += r__1 * r__1;
/* L110: */
	    xax += vec[ki] * (b[i__] * 2.f * vec[ki - 1] + a[i__] * vec[ki]);
	}
/* L120: */
	value[j] = xax / xx;
    }
    return 0;
} /* ea08c_ */

/* Subroutine */ int ea09c_(real *a, real *b, real *value, integer *m, real *
	off)
{
    /* Initialized data */

    static real a34 = 0.f;
    static real eps = 1e-6f;

    /* Format strings */
    static char fmt_90[] = "(\0021LOOPING DETECTED IN EA09-STOPPING NOW \002)"
	    ;

    /* System generated locals */
    integer i__1, i__2, i__3;
    real r__1, r__2, r__3;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__;
    static real s;
    static integer n1, n2, n3;
    static real a11, bb, a22, cc, a12, a23, a13, a33, a21;
    static integer ii;
    static real co, si, sbb;
    static integer n2m1;
    static real sml;
    static integer iter;
    static real root;
    static integer maxit;

    /* Fortran I/O blocks */
    static cilist io___89 = { 0, 6, 0, fmt_90, 0 };


/*  STANDARD FORTRAN 66 (A VERFIED PFORT SUBROUTINE) */
    /* Parameter adjustments */
    --off;
    --value;
    --b;
    --a;

    /* Function Body */
    sml = eps * (real) (*m);
    value[1] = a[1];
    if (*m == 1) {
	return 0;
    }
    i__1 = *m;
    for (i__ = 2; i__ <= i__1; ++i__) {
	value[i__] = a[i__];
/* L10: */
	off[i__] = b[i__];
    }
/*     EACH QR ITERATION IS PERFORMED OF ROWS AND COLUMNS N1 TO N2 */
    maxit = *m * 10;
    i__1 = maxit;
    for (iter = 1; iter <= i__1; ++iter) {
	i__2 = *m;
	for (n3 = 2; n3 <= i__2; ++n3) {
	    n2 = *m + 2 - n3;
	    i__3 = n2;
	    for (ii = 2; ii <= i__3; ++ii) {
		n1 = n2 + 2 - ii;
		if ((r__3 = off[n1], dabs(r__3)) <= ((r__1 = value[n1 - 1], 
			dabs(r__1)) + (r__2 = value[n1], dabs(r__2))) * sml) {
		    goto L30;
		}
/* L20: */
	    }
	    n1 = 1;
L30:
	    if (n2 != n1) {
		goto L50;
	    }
/* L40: */
	}
	return 0;
/*     ROOT  IS THE EIGENVALUE OF THE BOTTOM 2*2 MATRIX THAT IS NEAREST */
/*     TO THE LAST MATRIX ELEMENT AND IS USED TO ACCELERATE THE */
/*     CONVERGENCE */
L50:
	bb = (value[n2] - value[n2 - 1]) * .5f;
	cc = off[n2] * off[n2];
	sbb = 1.f;
	if (bb < 0.f) {
	    sbb = -1.f;
	}
	root = value[n2] + cc / (bb + sbb * sqrt(bb * bb + cc));
	n2m1 = n2 - 1;
/* L60: */
	a22 = value[n1];
	a12 = a22 - root;
	a23 = off[n1 + 1];
	a13 = a23;
	i__2 = n2m1;
	for (i__ = n1; i__ <= i__2; ++i__) {
	    a33 = value[i__ + 1];
	    if (i__ != n2m1) {
		a34 = off[i__ + 2];
	    }
	    s = sqrt(a12 * a12 + a13 * a13);
	    si = a13 / s;
	    co = a12 / s;
	    if (i__ != n1) {
		off[i__] = s;
	    }
	    a11 = co * a22 + si * a23;
	    a12 = co * a23 + si * a33;
	    a13 = si * a34;
	    a21 = co * a23 - si * a22;
	    a22 = co * a33 - si * a23;
	    a23 = co * a34;
	    value[i__] = a11 * co + a12 * si;
	    a12 = -a11 * si + a12 * co;
	    off[i__ + 1] = a12;
/* L70: */
	    a22 = a22 * co - a21 * si;
	}
/* L80: */
	value[n2] = a22;
    }
    s_wsfe(&io___89);
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* ea09c_ */

/* Complex */ VOID fm06as_(complex * ret_val, integer *n, complex *a, integer 
	*ia, complex *b, integer *ib)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    complex q__1, q__2;

    /* Local variables */
    static integer i__;
    static complex sum;

/* ****************************************************** */

/*    FM06AS - A FUNCTION ROUTINE TO COMPUTE THE VALUE OF THE */
/*      INNER PRODUCT, OR DOT PRODUCT, OF TWO SINGLE PRECISION */
/*      COMPLEX VECTORS, ACCUMULATING THE INTERMEDIATE PRODUCTS */
/*      DOUBLE PRECISION.  THE ELEMENTS OF EACH VECTOR CAN BE */
/*      STORED IN ANY FIXED DISPLACEMENT FROM NEIGHBOURING */
/*      ELEMENTS. */

/*    COMPUTES: SUM(J=1,N) A((J-1)*IA+1)*B((J-1)*IB+1) */

/*          W = FM06AS(N,A,IA,B,IB) */

/*    N   INTEGER SCALAR; (USER:*); LENGTH OF THE VECTORS A AND B. */
/*        IF N <= 0 THE INNER PRODUCT VALUE IS DEFINED TO BE ZERO. */
/*    A   COMPLEX*8 ARRAY((N-1)*IABS(IA)+1); (USER:*); THE ARRAY */
/*        CONTAINING THE 1ST VECTOR.  THE FORTRAN CONVENTION OF STORING */
/*        REAL AND IMAGINARY PARTS IN ADJACENT WORDS IS ASSUMED. */
/*    IA  INTEGER SCALAR; (USER:*); THE SUBSCRIPT DISPLACEMENT OF */
/*        AN ELEMENT IN THE ARRAY A TO ITS NEIGHBOUR, I.E. THE VECTOR */
/*        ELEMENTS ARE IN A(1), A(IA+1), A(2*IA+1),... */
/*        IF IA < 0 THE ELEMENTS ARE ASSUMED TO BE STORED IN */
/*        A(1-(N-1)*IA), A(1-(N-2)*IA),..., A(1-IA), A(1). */
/*    B   COMPLEX*8 ARRAY((N-1)*IABS(IA)+1); (USER:*); THE ARRAY */
/*        CONTAINING THE SECOND VECTOR.  TREAT LIKE A. */
/*    IB  INTEGER SCALAR; (USER:*); THE SUBSCRIPT DISPLACEMENT OF */
/*        AN ELEMENT IN B TO ITS NEIGHBOUR. TREAT LIKE IA. */
/*    FM06AS  COMPLEX FUNCTION; (*:FM06AS); THE INNER PRODUCT VALUE. */
/*        IT IS RETURNED DOUBLE PRECISION, THE REAL PART IN FLT PNT */
/*        REG 0 AND THE IMAGINARY PART IN FLT PNT REG 2. */

/*    THIS ROUTINE IS WRITTEN IN FORTRAN. */

/* --------------------------------------------------------* */
    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    sum.r = 0.f, sum.i = 0.f;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	i__2 = (i__ - 1) * *ia + 1;
	i__3 = (i__ - 1) * *ib + 1;
	q__2.r = a[i__2].r * b[i__3].r - a[i__2].i * b[i__3].i, q__2.i = a[
		i__2].r * b[i__3].i + a[i__2].i * b[i__3].r;
	q__1.r = sum.r + q__2.r, q__1.i = sum.i + q__2.i;
	sum.r = q__1.r, sum.i = q__1.i;
    }
     ret_val->r = sum.r,  ret_val->i = sum.i;
    return ;
} /* fm06as_ */

/* Complex */ VOID fm06bs_(complex * ret_val, integer *n, complex *a, integer 
	*ia, complex *b, integer *ib)
{
    /* System generated locals */
    integer i__1, i__2;
    complex q__1, q__2, q__3;

    /* Builtin functions */
    void r_cnjg(complex *, complex *);

    /* Local variables */
    static integer i__;
    static complex sum;

/* ****************************************************** */

/*    FM06BS - A FUNCTION ROUTINE TO COMPUTE THE VALUE OF THE */
/*      INNER PRODUCT, OR DOT PRODUCT, OF A SIGLE    PRECISION */
/*      COMPLEX VECTORS, ACCUMULATING THE INTERMEDIATE PRODUCTS */
/*      DOUBLE PRECISION.  THE ELEMENTS OF EACH VECTOR CAN BE */
/*      STORED IN ANY FIXED DISPLACEMENT FROM NEIGHBOURING */
/*      ELEMENTS. */

/*    COMPUTES: SUM(J=1,N) A((J-1)*IA+1)*B((J-1)*IB+1) */

/*          W = FM06BS(N,A,IA,B,IB) */

/*    N   INTEGER SCALAR; (USER:*); LENGTH OF THE VECTORS A AND B. */
/*        IF N <= 0 THE INNER PRODUCT VALUE IS DEFINED TO BE ZERO. */
/*    A   COMPLEX*8 ARRAY((N-1)*IABS(IA)+1); (USER:*); THE ARRAY */
/*        CONTAINING THE 1ST VECTOR.  THE FORTRAN CONVENTION OF STORING */
/*        REAL AND IMAGINARY PARTS IN ADJACENT WORDS IS ASSUMED. */
/*    IA  INTEGER SCALAR; (USER:*); THE SUBSCRIPT DISPLACEMENT OF */
/*        AN ELEMENT IN THE ARRAY A TO ITS NEIGHBOUR, I.E. THE VECTOR */
/*        ELEMENTS ARE IN A(1), A(IA+1), A(2*IA+1),... */
/*        IF IA < 0 THE ELEMENTS ARE ASSUMED TO BE STORED IN */
/*        A(1-(N-1)*IA), A(1-(N-2)*IA),..., A(1-IA), A(1). */
/*    B   COMPLEX*8 ARRAY((N-1)*IABS(IA)+1); (USER:*); THE ARRAY */
/*        CONTAINING THE SECOND VECTOR.  TREAT LIKE A. */
/*    IB  INTEGER SCALAR; (USER:*); THE SUBSCRIPT DISPLACEMENT OF */
/*        AN ELEMENT IN B TO ITS NEIGHBOUR. TREAT LIKE IA. */
/*    FM06BS  COMPLEX FUNCTION; (*:FM06BS); THE INNER PRODUCT VALUE. */
/*        IT IS RETURNED DOUBLE PRECISION, THE REAL PART IN FLT PNT */
/*        REG 0 AND THE IMAGINARY PART IN FLT PNT REG 2. */

/*    THIS ROUTINE IS WRITTEN IN FORTRAN. */

/* --------------------------------------------------------* */
    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
    sum.r = 0.f, sum.i = 0.f;
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	i__2 = (i__ - 1) * *ia + 1;
	r_cnjg(&q__3, &b[(i__ - 1) * *ib + 1]);
	q__2.r = a[i__2].r * q__3.r - a[i__2].i * q__3.i, q__2.i = a[i__2].r *
		 q__3.i + a[i__2].i * q__3.r;
	q__1.r = sum.r + q__2.r, q__1.i = sum.i + q__2.i;
	sum.r = q__1.r, sum.i = q__1.i;
    }
     ret_val->r = sum.r,  ret_val->i = sum.i;
    return ;
} /* fm06bs_ */

/* Subroutine */ int me08a_(complex *a, complex *alpha, complex *beta, 
	integer *n, integer *ia, complex *q)
{
    /* Initialized data */

    static real zero = 0.f;
    static real p5 = .5f;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2, i__3, i__4;
    real r__1;
    complex q__1, q__2, q__3;

    /* Builtin functions */
    void r_cnjg(complex *, complex *);
    double sqrt(doublereal), c_abs(complex *);

    /* Local variables */
    static real h__;
    static integer i__, j, k, i1, n2;
    static real s1;
    static complex cw, qj;
    static real pp, pp1;
    extern /* Subroutine */ int me08b_(real *, real *, real *, integer *, 
	    integer *);
    extern /* Complex */ VOID fm06as_(complex *, integer *, complex *, 
	    integer *, complex *, integer *), fm06bs_(complex *, integer *, 
	    complex *, integer *, complex *, integer *);

    /* Parameter adjustments */
    --alpha;
    --beta;
    a_dim1 = *ia;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --q;

    /* Function Body */
/* ************************************************************** */
/* THE REDUCTION OF FULL HERMITIAN MATRIX INTO TRI-DIAGONAL HERMITIAN */
/* FORM IS DONE IN N-2 STEPS.AT THE I TH STEP ZEROS ARE INTRODUCED IN */
/* THE I TH ROW AND COLUMNS WITHOUT DESTROYING PREVIOUSLY PRODUCED ZEROS */

/*                                                    H */
/* AT THE I TH STEP WE HAVE  A =P A   P  WITH P =I-U U  /K */
/*                            I  I I-1 I       I    I I   I */

/* WHERE U =(0,0,...,A     (1+S /T ),A     ,...,A   ) */
/*        I           I,I+1    I  I   I,I+2      I,N */
/*        2   N          2        2                2 */
/*       S = SUM  ] A   ]     K =S +T   AND  T = SQRT(]A     ] S ) */
/*        I   J=I+1  I,J       I  I  I        I         I,I+1   I */

/* COMPUTATIONAL DETAILS AT THE I TH STAGE ARE (1) FORM S  ,K   THEN */
/*                                                       I   I */

/*                                     H                      H     H */
/* (2) Q =A   U  /K    (3) Q =Q -.5U (U Q /K ) (4) A =A   -U Q  -Q U */
/*      I  I-1 I   I        I  I    I  I I  I       I  I-1  I I   I I */

/*  THE VECTORS U BEING APPROPIATELY IN A. */
    if (*n <= 0) {
	goto L90;
    }
    i__1 = *n;
    for (j = 1; j <= i__1; ++j) {
	i__2 = j;
	i__3 = j + j * a_dim1;
	alpha[i__2].r = a[i__3].r, alpha[i__2].i = a[i__3].i;
	i__2 = j;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L10: */
	    i__3 = i__ + j * a_dim1;
	    r_cnjg(&q__1, &a[j + i__ * a_dim1]);
	    a[i__3].r = q__1.r, a[i__3].i = q__1.i;
	}
    }
    if ((i__3 = *n - 2) < 0) {
	goto L90;
    } else if (i__3 == 0) {
	goto L80;
    } else {
	goto L20;
    }
L20:
    n2 = *n - 2;
    i__3 = n2;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i1 = i__ + 1;
/*                       (1) */
	i__2 = *n - i__;
	fm06bs_(&q__1, &i__2, &a[i__ + (i__ + 1) * a_dim1], ia, &a[i__ + (i__ 
		+ 1) * a_dim1], ia);
	cw.r = q__1.r, cw.i = q__1.i;
	pp = cw.r;
	pp1 = sqrt(pp);
	i__2 = i__ + 1;
	r__1 = -pp1;
	q__1.r = r__1, q__1.i = zero;
	beta[i__2].r = q__1.r, beta[i__2].i = q__1.i;
	s1 = c_abs(&a[i__ + (i__ + 1) * a_dim1]);
	if (s1 > zero) {
	    i__2 = i__ + 1;
	    i__1 = i__ + 1;
	    i__4 = i__ + (i__ + 1) * a_dim1;
	    q__2.r = beta[i__1].r * a[i__4].r - beta[i__1].i * a[i__4].i, 
		    q__2.i = beta[i__1].r * a[i__4].i + beta[i__1].i * a[i__4]
		    .r;
	    q__1.r = q__2.r / s1, q__1.i = q__2.i / s1;
	    beta[i__2].r = q__1.r, beta[i__2].i = q__1.i;
	}
	if (pp <= 1e-15) {
	    goto L60;
	}
	h__ = pp + pp1 * s1;
	i__2 = i__ + (i__ + 1) * a_dim1;
	i__1 = i__ + (i__ + 1) * a_dim1;
	i__4 = i__ + 1;
	q__1.r = a[i__1].r - beta[i__4].r, q__1.i = a[i__1].i - beta[i__4].i;
	a[i__2].r = q__1.r, a[i__2].i = q__1.i;
/*                       (2) */
	i__2 = *n;
	for (k = i1; k <= i__2; ++k) {
	    i__1 = -(i__ - k);
	    fm06as_(&q__1, &i__1, &a[i__ + 1 + k * a_dim1], &c__1, &a[i__ + (
		    i__ + 1) * a_dim1], ia);
	    qj.r = q__1.r, qj.i = q__1.i;
	    i__1 = *n - k;
	    fm06bs_(&q__2, &i__1, &a[k + (k + 1) * a_dim1], ia, &a[i__ + (k + 
		    1) * a_dim1], ia);
	    r_cnjg(&q__3, &qj);
	    q__1.r = q__2.r + q__3.r, q__1.i = q__2.i + q__3.i;
	    qj.r = q__1.r, qj.i = q__1.i;
/* L30: */
	    i__1 = k;
	    q__1.r = qj.r / h__, q__1.i = qj.i / h__;
	    q[i__1].r = q__1.r, q[i__1].i = q__1.i;
	}
/*                       (3) */
	i__1 = *n - i__;
	fm06as_(&q__1, &i__1, &a[i__ + (i__ + 1) * a_dim1], ia, &q[i__ + 1], &
		c__1);
	cw.r = q__1.r, cw.i = q__1.i;
	q__2.r = p5 * cw.r, q__2.i = p5 * cw.i;
	q__1.r = q__2.r / h__, q__1.i = q__2.i / h__;
	pp = q__1.r;
	i__1 = *n;
	for (k = i1; k <= i__1; ++k) {
/* L40: */
	    i__2 = k;
	    i__4 = k;
	    r_cnjg(&q__3, &a[i__ + k * a_dim1]);
	    q__2.r = pp * q__3.r, q__2.i = pp * q__3.i;
	    q__1.r = q[i__4].r - q__2.r, q__1.i = q[i__4].i - q__2.i;
	    q[i__2].r = q__1.r, q[i__2].i = q__1.i;
	}
/*                       (4) */
	i__2 = *n;
	for (k = i1; k <= i__2; ++k) {
/* L50: */
	    i__4 = *n - k + 1;
	    i__1 = *ia << 1;
	    me08b_((real*)&a[k + k * a_dim1], (real*)&q[k], (real*)&a[i__ + k 
		    * a_dim1], &i__4, &i__1);
	}
L60:
	;
    }
    i__3 = *n;
    for (i__ = 2; i__ <= i__3; ++i__) {
	i__4 = i__;
	qj.r = alpha[i__4].r, qj.i = alpha[i__4].i;
	i__4 = i__;
	i__1 = i__ + i__ * a_dim1;
	alpha[i__4].r = a[i__1].r, alpha[i__4].i = a[i__1].i;
/* L70: */
	i__4 = i__ + i__ * a_dim1;
	a[i__4].r = qj.r, a[i__4].i = qj.i;
    }
L80:
    i__4 = *n;
    i__3 = *n - 1 + *n * a_dim1;
    beta[i__4].r = a[i__3].r, beta[i__4].i = a[i__3].i;
L90:
    return 0;
} /* me08a_ */

/* Subroutine */ int sort_(real *val, complex *vec, integer *n)
{
    /* System generated locals */
    integer vec_dim1, vec_offset, i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer i__, j, k;
    static real x;
    static complex sum;

    /* Parameter adjustments */
    --val;
    vec_dim1 = *n;
    vec_offset = 1 + vec_dim1 * 1;
    vec -= vec_offset;

    /* Function Body */
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x = 1e9f;
	i__2 = *n;
	for (j = i__; j <= i__2; ++j) {
	    if (val[j] < x) {
		k = j;
		x = val[j];
	    }
/* L10: */
	}
	i__2 = *n;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = j + k * vec_dim1;
	    sum.r = vec[i__3].r, sum.i = vec[i__3].i;
	    i__3 = j + k * vec_dim1;
	    i__4 = j + i__ * vec_dim1;
	    vec[i__3].r = vec[i__4].r, vec[i__3].i = vec[i__4].i;
/* L20: */
	    i__3 = j + i__ * vec_dim1;
	    vec[i__3].r = sum.r, vec[i__3].i = sum.i;
	}
	val[k] = val[i__];
	val[i__] = x;
/* L30: */
    }
    return 0;
} /* sort_ */

