/* diat.f -- translated by f2c (version 20020621).
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
    doublereal emus[107], emup[107], emud[107];
} expont_;

#define expont_1 expont_

/* Table of constant values */

static integer c_n1 = -1;
static doublereal c_b15 = 2.;
static doublereal c_b34 = -1.;

/* Subroutine */ int diat_(integer *ni, integer *nj, doublereal *xi, 
	doublereal *xj, doublereal *di)
{
    /* Initialized data */

    static integer npq[107] = { 1,0,2,2,2,2,2,2,2,0,0,3,3,3,3,3,3,0,0,4,4,4,4,
	    4,4,4,4,4,4,4,4,4,4,4,4,0,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,6,6,
	    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,0,0,0,
	    0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0 };
    static integer ival[15]	/* was [3][5] */ = { 1,0,9,1,3,8,1,4,7,1,2,6,
	    0,0,5 };
    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;
    static doublereal equiv_5[75], equiv_8[27];

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer a, b;
#define c__ (equiv_5)
    static integer i__, j, k, l;
    static doublereal r__;
#define s (equiv_8)
#define c1 (equiv_5)
#define c2 (equiv_5 + 15)
#define c3 (equiv_5 + 30)
#define c4 (equiv_5 + 45)
#define c5 (equiv_5 + 60)
#define s1 (equiv_8)
#define s2 (equiv_8 + 9)
#define s3 (equiv_8 + 18)
    static doublereal x1, x2, y1, y2, z1, z2;
    static integer aa, bb, ia, ib, ii, jj;
    extern doublereal ss_(integer *, integer *, integer *, integer *, integer 
	    *, doublereal *, doublereal *, doublereal *);
    static integer nk1, pq1, pq2;
    static doublereal ul1[3], ul2[3];
    extern /* Subroutine */ int coe_(doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static integer iss, jss, kss, kmin, lmin, kmax, lmax, newk;
#define slin (equiv_8)
    extern /* Subroutine */ int diat2_(integer *, doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *)
	    , gover_(integer *, integer *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    static logical analyt;

/* *********************************************************************** */

/*   DIAT CALCULATES THE DI-ATOMIC OVERLAP INTEGRALS BETWEEN ATOMS */
/*        CENTERED AT XI AND XJ. */

/*   ON INPUT NI  = ATOMIC NUMBER OF THE FIRST ATOM. */
/*            NJ  = ATOMIC NUMBER OF THE SECOND ATOM. */
/*            XI  = CARTESIAN COORDINATES OF THE FIRST ATOM. */
/*            XJ  = CARTESIAN COORDINATES OF THE SECOND ATOM. */

/*  ON OUTPUT DI  = DIATOMIC OVERLAP, IN A 9 * 9 MATRIX. LAYOUT OF */
/*                  ATOMIC ORBITALS IN DI IS */
/*                  1   2   3   4   5            6     7       8     9 */
/*                  S   PX  PY  PZ  D(X**2-Y**2) D(XZ) D(Z**2) D(YZ)D(XY) */

/*   LIMITATIONS:  IN THIS FORMULATION, NI AND NJ MUST BE LESS THAN 107 */
/*         EXPONENTS ARE ASSUMED TO BE PRESENT IN COMMON BLOCK EXPONT. */

/* *********************************************************************** */
    /* Parameter adjustments */
    di -= 10;
    --xj;
    --xi;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	analyt = i_indx(keywrd_1.keywrd, "ANALYT", (ftnlen)241, (ftnlen)6) != 
		0;
	icalcn = numcal_1.numcal;
    }
    x1 = xi[1];
    x2 = xj[1];
    y1 = xi[2];
    y2 = xj[2];
    z1 = xi[3];
    z2 = xj[3];
    pq1 = npq[*ni - 1];
    pq2 = npq[*nj - 1];
    for (i__ = 1; i__ <= 9; ++i__) {
	for (j = 1; j <= 9; ++j) {
	    di[i__ + j * 9] = 0.;
/* L10: */
	}
/* L20: */
    }
    coe_(&x1, &y1, &z1, &x2, &y2, &z2, &pq1, &pq2, c__, &r__);
    if (pq1 == 0 || pq2 == 0 || r__ >= 10.) {
	return 0;
    }
    if (r__ < .001f) {
	return 0;
    }
    ia = min(pq1,3);
    ib = min(pq2,3);
    a = ia - 1;
    b = ib - 1;
    if (analyt) {
	gover_(ni, nj, &xi[1], &xj[1], &r__, &di[10]);
/* #      WRITE(6,*)' OVERLAP FROM GOVER' */
/* #      WRITE(6,'(4F15.10)')SG */
	return 0;
    }
    if (*ni < 18 && *nj < 18) {
	diat2_(ni, &expont_1.emus[*ni - 1], &expont_1.emup[*ni - 1], &r__, nj,
		 &expont_1.emus[*nj - 1], &expont_1.emup[*nj - 1], s);
    } else {
	ul1[0] = expont_1.emus[*ni - 1];
	ul2[0] = expont_1.emus[*nj - 1];
	ul1[1] = expont_1.emup[*ni - 1];
	ul2[1] = expont_1.emup[*nj - 1];
/* Computing MAX */
	d__1 = expont_1.emud[*ni - 1];
	ul1[2] = max(d__1,.3);
/* Computing MAX */
	d__1 = expont_1.emud[*nj - 1];
	ul2[2] = max(d__1,.3);
	for (i__ = 1; i__ <= 27; ++i__) {
/* L30: */
	    slin[i__ - 1] = 0.;
	}
	newk = min(a,b);
	nk1 = newk + 1;
	i__1 = ia;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    iss = i__;
	    ib = b + 1;
	    i__2 = ib;
	    for (j = 1; j <= i__2; ++j) {
		jss = j;
		i__3 = nk1;
		for (k = 1; k <= i__3; ++k) {
		    if (k > i__ || k > j) {
			goto L40;
		    }
		    kss = k;
		    s[i__ + (j + k * 3) * 3 - 13] = ss_(&pq1, &pq2, &iss, &
			    jss, &kss, &ul1[i__ - 1], &ul2[j - 1], &r__);
L40:
		    ;
		}
	    }
	}
    }
    i__3 = ia;
    for (i__ = 1; i__ <= i__3; ++i__) {
	kmin = 4 - i__;
	kmax = i__ + 2;
	i__2 = ib;
	for (j = 1; j <= i__2; ++j) {
	    if (j == 2) {
		aa = -1;
		bb = 1;
	    } else {
		aa = 1;
		if (j == 3) {
		    bb = -1;
		} else {
		    bb = 1;
		}
	    }
	    lmin = 4 - j;
	    lmax = j + 2;
	    i__1 = kmax;
	    for (k = kmin; k <= i__1; ++k) {
		i__4 = lmax;
		for (l = lmin; l <= i__4; ++l) {
		    ii = ival[i__ + k * 3 - 4];
		    jj = ival[j + l * 3 - 4];
		    di[ii + jj * 9] = s1[i__ + j * 3 - 4] * (c3[i__ + k * 3 - 
			    4] * c3[j + l * 3 - 4]) * aa + (c4[i__ + k * 3 - 
			    4] * c4[j + l * 3 - 4] + c2[i__ + k * 3 - 4] * c2[
			    j + l * 3 - 4]) * bb * s2[i__ + j * 3 - 4] + (c5[
			    i__ + k * 3 - 4] * c5[j + l * 3 - 4] + c1[i__ + k 
			    * 3 - 4] * c1[j + l * 3 - 4]) * s3[i__ + j * 3 - 
			    4];
/* L50: */
		}
	    }
	}
    }
/* #      WRITE(6,*)' OVERLAP FROM DIAT2' */
/* #      DO 12 I=1,4 */
/* #  12  WRITE(6,'(4F15.10)')(DI(J,I),J=1,4) */
    return 0;
} /* diat_ */

#undef slin
#undef s3
#undef s2
#undef s1
#undef c5
#undef c4
#undef c3
#undef c2
#undef c1
#undef s
#undef c__


doublereal ss_(integer *na, integer *nb, integer *la1, integer *lb1, integer *
	m1, doublereal *ua, doublereal *ub, doublereal *r1)
{
    /* Initialized data */

    static logical first = TRUE_;
    static doublereal aff[27]	/* was [3][3][3] */ = { 0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static doublereal fa[14] = { 1.,1.,2.,6.,24.,120.,720.,5040.,40320.,
	    362880.,3628800.,39916800.,479001600.,6227020800. };

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7, i__8, i__9;
    doublereal ret_val;

    /* Builtin functions */
    double exp(doublereal);
    integer pow_ii(integer *, integer *);
    double sqrt(doublereal), pow_di(doublereal *, integer *);

    /* Local variables */
    static doublereal b;
    static integer i__, j, m, n;
    static doublereal p, r__;
    static integer i1, k1, k2, k3, k4, k5, k6;
    static doublereal af[20], bf[20];
    static integer ia;
    static doublereal bi[169]	/* was [13][13] */;
    static integer ic, la, lb, ib, id, jx, iab, iaf, ibf;
    extern /* Subroutine */ int bfn_(doublereal *, doublereal *);
    static doublereal quo, sum;
    static integer lam1, lbm1;
    static doublereal sum1;

    m = *m1 - 1;
    lb = *lb1 - 1;
    la = *la1 - 1;
    r__ = *r1 / .529167;
    if (first) {
	first = FALSE_;

/*           INITIALISE SOME CONSTANTS */

/*                  BINOMIALS */

	for (i__ = 0; i__ <= 12; ++i__) {
	    bi[i__] = 1.;
	    bi[i__ + i__ * 13] = 1.;
/* L10: */
	}
	for (i__ = 0; i__ <= 11; ++i__) {
	    i1 = i__ - 1;
	    i__1 = i1;
	    for (j = 0; j <= i__1; ++j) {
		bi[i__ + 1 + (j + 1) * 13] = bi[i__ + (j + 1) * 13] + bi[i__ 
			+ j * 13];
/* L20: */
	    }
	}
	aff[0] = 1.;
	aff[1] = 1.;
	aff[4] = 1.;
	aff[2] = 1.5;
	aff[5] = 1.73205;
	aff[8] = 1.224745;
	aff[20] = -.5;
    }
    p = (*ua + *ub) * r__ * .5;
    b = (*ua - *ub) * r__ * .5;
    quo = 1 / p;
    af[0] = quo * exp(-p);
    for (n = 1; n <= 19; ++n) {
	af[n] = n * quo * af[n - 1] + af[0];
/* L30: */
    }
    bfn_(&b, bf);
    sum = 0.;
    lam1 = la - m;
    lbm1 = lb - m;

/*          START OF OVERLAP CALCULATION PROPER */

    i__1 = lam1;
    for (i__ = 0; i__ <= i__1; i__ += 2) {
	ia = *na + i__ - la;
	ic = la - i__ - m;
	i__2 = lbm1;
	for (j = 0; j <= i__2; j += 2) {
	    ib = *nb + j - lb;
	    id = lb - j - m;
	    sum1 = 0.;
	    iab = ia + ib;
	    i__3 = ia;
	    for (k1 = 0; k1 <= i__3; ++k1) {
		i__4 = ib;
		for (k2 = 0; k2 <= i__4; ++k2) {
		    i__5 = ic;
		    for (k3 = 0; k3 <= i__5; ++k3) {
			i__6 = id;
			for (k4 = 0; k4 <= i__6; ++k4) {
			    i__7 = m;
			    for (k5 = 0; k5 <= i__7; ++k5) {
				iaf = iab - k1 - k2 + k3 + k4 + (k5 << 1);
				i__8 = m;
				for (k6 = 0; k6 <= i__8; ++k6) {
				    ibf = k1 + k2 + k3 + k4 + (k6 << 1);
				    i__9 = m + k2 + k4 + k5 + k6;
				    jx = pow_ii(&c_n1, &i__9);
				    sum1 += bi[id + k4 * 13] * bi[m + k5 * 13]
					     * bi[ic + k3 * 13] * bi[ib + k2 *
					     13] * bi[ia + k1 * 13] * bi[m + 
					    k6 * 13] * jx * af[iaf] * bf[ibf];
/* L40: */
				}
			    }
			}
		    }
		}
	    }
	    sum += sum1 * aff[la + (m + i__ * 3) * 3] * aff[lb + (m + j * 3) *
		     3];
/* L50: */
	}
    }
    i__2 = *na + *nb + 1;
    i__1 = m + 1;
    ret_val = sum * pow_di(&r__, &i__2) * pow_di(ua, na) * pow_di(ub, nb) / 
	    pow_di(&c_b15, &i__1) * sqrt(*ua * *ub / (fa[*na + *na] * fa[*nb 
	    + *nb]) * ((la + la + 1) * (lb + lb + 1)));
    return ret_val;
} /* ss_ */

/* Subroutine */ int coe_(doublereal *x1, doublereal *y1, doublereal *z1, 
	doublereal *x2, doublereal *y2, doublereal *z2, integer *pq1, integer 
	*pq2, doublereal *c__, doublereal *r__)
{
    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal ca, cb, sa, sb;
    static integer pq;
    static doublereal xy, c2a, c2b, s2a, s2b;

    /* Parameter adjustments */
    --c__;

    /* Function Body */
/* Computing 2nd power */
    d__1 = *x2 - *x1;
/* Computing 2nd power */
    d__2 = *y2 - *y1;
    xy = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = *z2 - *z1;
    *r__ = sqrt(xy + d__1 * d__1);
    xy = sqrt(xy);
    if (xy < 1e-10) {
	goto L10;
    }
    ca = (*x2 - *x1) / xy;
    cb = (*z2 - *z1) / *r__;
    sa = (*y2 - *y1) / xy;
    sb = xy / *r__;
    goto L50;
L10:
    if ((d__1 = *z2 - *z1) < 0.) {
	goto L20;
    } else if (d__1 == 0) {
	goto L30;
    } else {
	goto L40;
    }
L20:
    ca = -1.;
    cb = -1.;
    sa = 0.;
    sb = 0.;
    goto L50;
L30:
    ca = 0.;
    cb = 0.;
    sa = 0.;
    sb = 0.;
    goto L50;
L40:
    ca = 1.;
    cb = 1.;
    sa = 0.;
    sb = 0.;
L50:
    for (i__ = 1; i__ <= 75; ++i__) {
/* L60: */
	c__[i__] = 0.;
    }
    if (*pq1 > *pq2) {
	goto L70;
    }
    pq = *pq2;
    goto L80;
L70:
    pq = *pq1;
L80:
    c__[37] = 1.;
    if (pq < 2) {
	goto L90;
    }
    c__[56] = ca * cb;
    c__[41] = ca * sb;
    c__[26] = -sa;
    c__[53] = -sb;
    c__[38] = cb;
    c__[23] = 0.;
    c__[50] = sa * cb;
    c__[35] = sa * sb;
    c__[20] = ca;
    if (pq < 3) {
	goto L90;
    }
    c2a = ca * 2 * ca - 1.;
    c2b = cb * 2 * cb - 1.;
    s2a = sa * 2 * ca;
    s2b = sb * 2 * cb;
    c__[75] = c2a * cb * cb + c2a * .5 * sb * sb;
    c__[60] = c2a * .5 * s2b;
    c__[45] = c2a * .8660254037841 * sb * sb;
    c__[30] = -s2a * sb;
    c__[15] = -s2a * cb;
    c__[72] = ca * -.5 * s2b;
    c__[57] = ca * c2b;
    c__[42] = ca * .8660254037841 * s2b;
    c__[27] = -sa * cb;
    c__[12] = sa * sb;
    c__[69] = sb * .5773502691894 * sb * 1.5;
    c__[54] = s2b * -.8660254037841;
    c__[39] = cb * cb - sb * .5 * sb;
    c__[66] = sa * -.5 * s2b;
    c__[51] = sa * c2b;
    c__[36] = sa * .8660254037841 * s2b;
    c__[21] = ca * cb;
    c__[6] = -ca * sb;
    c__[63] = s2a * cb * cb + s2a * .5 * sb * sb;
    c__[48] = s2a * .5 * s2b;
    c__[33] = s2a * .8660254037841 * sb * sb;
    c__[18] = c2a * sb;
    c__[3] = c2a * cb;
L90:
    return 0;
} /* coe_ */

/* Subroutine */ int bfn_(doublereal *x, doublereal *bf)
{
    /* Initialized data */

    static doublereal fact[17] = { 1.,2.,6.,24.,120.,720.,5040.,40320.,
	    362880.,3628800.,39916800.,479001600.,6227020800.,87178291200.,
	    1.307674368e12,2.092278989e13,3.556874281e14 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double exp(doublereal), pow_di(doublereal *, integer *);

    /* Local variables */
    static integer i__, k, m;
    static doublereal y;
    static integer io;
    static doublereal xf, absx;
    static integer last;
    static doublereal expx, expmx;

/* ********************************************************************** */

/*     BINTGS FORMS THE "B" INTEGRALS FOR THE OVERLAP CALCULATION. */

/* ********************************************************************** */
    /* Parameter adjustments */
    --bf;

    /* Function Body */
    k = 12;
    io = 0;
    absx = abs(*x);
    if (absx > 3.) {
	goto L40;
    }
    if (absx <= 2.) {
	goto L10;
    }
    last = 15;
    goto L60;
L10:
    if (absx <= 1.) {
	goto L20;
    }
    last = 12;
    goto L60;
L20:
    if (absx <= .5) {
	goto L30;
    }
    last = 7;
    goto L60;
L30:
    if (absx <= 1e-6) {
	goto L90;
    }
    last = 6;
    goto L60;
L40:
    expx = exp(*x);
    expmx = 1. / expx;
    bf[1] = (expx - expmx) / *x;
    i__1 = k;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	bf[i__ + 1] = (i__ * bf[i__] + pow_di(&c_b34, &i__) * expx - expmx) / 
		*x;
    }
    goto L110;
L60:
    i__1 = k;
    for (i__ = io; i__ <= i__1; ++i__) {
	y = 0.;
	i__2 = last;
	for (m = io; m <= i__2; ++m) {
	    xf = 1.;
	    if (m != 0) {
		xf = fact[m - 1];
	    }
/* L70: */
	    d__1 = -(*x);
	    y += pow_di(&d__1, &m) * ((m + i__ + 1) % 2 << 1) / (xf * (m + 
		    i__ + 1));
	}
/* L80: */
	bf[i__ + 1] = y;
    }
    goto L110;
L90:
    i__1 = k;
    for (i__ = io; i__ <= i__1; ++i__) {
/* L100: */
	bf[i__ + 1] = ((i__ + 1) % 2 << 1) / (i__ + 1.);
    }
L110:
    return 0;

} /* bfn_ */

