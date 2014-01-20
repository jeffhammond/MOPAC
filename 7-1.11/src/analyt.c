/* analyt.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    doublereal alpa[107];
} alpha_;

#define alpha_1 alpha_

struct {
    doublereal f03[107];
} twoel3_;

#define twoel3_1 twoel3_

struct {
    integer natorb[107];
} natorb_;

#define natorb_1 natorb_

struct {
    doublereal alp3[153];
} alpha3_;

#define alpha3_1 alpha3_

struct {
    doublereal fn1[1070]	/* was [107][10] */, fn2[1070]	/* was [107][
	    10] */, fn3[1070]	/* was [107][10] */;
} ideas_;

#define ideas_1 ideas_

struct {
    doublereal w[429540];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    integer nztype[107], mtype[30], ltype;
} natype_;

#define natype_1 natype_

struct {
    doublereal beta3[153];
} beta3_;

#define beta3_1 beta3_

struct {
    doublereal vs[107], vp[107], vd[107];
} vsips_;

#define vsips_1 vsips_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal ds[16], dg[22], dr[100], tdx[3], tdy[3], tdz[3];
} derivs_;

#define derivs_1 derivs_

struct {
    doublereal g[22], txyz[9];
} extra_;

#define extra_1 extra_

struct {
    integer idmy[5], i3n, ix;
} force3_;

#define force3_1 force3_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b11 = -1.5;

/* Subroutine */ int analyt_(doublereal *psum, doublereal *palpha, doublereal 
	*pbeta, doublereal *coord, integer *nat, integer *jja, integer *jjd, 
	integer *iia, integer *iid, doublereal *eng)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3, d__4, d__5, d__6;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_rsue(cilist *), do_uio(integer *, char *, ftnlen), e_rsue(void);
    double exp(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l, m, n;
    static doublereal a0, c1, c2, c3, f3;
    static integer i1, j1;
    static doublereal r0, r2, aa, bb, dd;
    static integer ia;
    static doublereal bi[4], bj[4];
    static integer jd, ja, id, ka, kg, la, lg, i22, ni, nj, ii, is, ig, lk, 
	    mn, jj, ij;
    static doublereal rr;
    static integer kk, ll, kl, mk, nk, ml, nl;
    static logical am1;
    static doublereal dr1, eaa[3], eab[3];
    static integer iol;
    static doublereal rij;
    static integer isp;
    static doublereal del1, del2, del3, exp1, exp2, enuc[3];
    extern /* Subroutine */ int ders_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, integer *);
    static doublereal anam1, alph1, alph2, part1, part2, part3, alpha;
    extern /* Subroutine */ int delri_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static integer nbond;
    static doublereal termk, terml;
    static logical mindo3;
    static doublereal termaa, termab;
    extern /* Subroutine */ int delmol_(doublereal *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *);
    static doublereal termnc;
    static integer istart, jstart;

    /* Fortran I/O blocks */
    static cilist io___36 = { 0, 2, 0, 0, 0 };


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
/*         CALCULATION OF ANALYTICAL DERIVATIVES                        * */
/*                                                                      * */
/* *********************************************************************** */

/* COMMON BLOCKS 'OWNED' BY REST OF PROGRAM. */


/* COMMON BLOCKS 'OWNED' BY ANT */


/* ON RETURN, ENG HOLDS ANALYTICAL DERIVATIVES */

    /* Parameter adjustments */
    --eng;
    --nat;
    coord -= 4;
    --pbeta;
    --palpha;
    --psum;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	am1 = i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) + i_indx(
		keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0;
	mindo3 = i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 
		0;
    }
    a0 = .529167;
    jd = *jjd - *jja + 1;
    ja = 1;
    id = *iid - *iia + 1 + jd;
    ia = jd + 1;
    for (j = 1; j <= 3; ++j) {
	eaa[j - 1] = 0.;
	eab[j - 1] = 0.;
	enuc[j - 1] = 0.;
	eng[j] = 0.;
/* L10: */
    }
    i__ = 2;
    ni = nat[i__];
    istart = (natype_1.nztype[ni - 1] << 2) - 3;
    j = 1;
    nj = nat[j];
    jstart = (natype_1.nztype[nj - 1] << 2) - 3;
/* Computing 2nd power */
    d__1 = coord[i__ * 3 + 1] - coord[j * 3 + 1];
/* Computing 2nd power */
    d__2 = coord[i__ * 3 + 2] - coord[j * 3 + 2];
/* Computing 2nd power */
    d__3 = coord[i__ * 3 + 3] - coord[j * 3 + 3];
    r2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    rij = sqrt(r2);
    r0 = rij / a0;
    rr = r2 / (a0 * a0);
    for (force3_1.ix = 1; force3_1.ix <= 3; ++force3_1.ix) {
	del1 = coord[force3_1.ix + i__ * 3] - coord[force3_1.ix + j * 3];
	termaa = 0.;
	termab = 0.;
	isp = 0;
	iol = 0;
/*   THE FIRST DERIVATIVES OF OVERLAP INTEGRALS */
	i__1 = id;
	for (k = ia; k <= i__1; ++k) {
	    ka = k - ia;
	    kg = istart + ka;
	    i__2 = jd;
	    for (l = ja; l <= i__2; ++l) {
		la = l - ja;
		lg = jstart + la;
		++iol;
		derivs_1.ds[iol - 1] = 0.;
		if (ka == 0 && la == 0) {
/*   (S/S) TERM */
		    if (abs(del1) <= 1e-6) {
			goto L30;
		    }
		    is = 1;
		} else if (ka == 0 && la > 0) {
/*   (S/P) TERM */
		    is = 3;
		    if (force3_1.ix == la) {
			goto L20;
		    }
		    if (abs(del1) <= 1e-6) {
			goto L30;
		    }
		    is = 2;
		    del2 = coord[la + i__ * 3] - coord[la + j * 3];
		} else if (ka > 0 && la == 0) {
/*   (P/S) TERM */
		    is = 5;
		    if (force3_1.ix == ka) {
			goto L20;
		    }
		    if (abs(del1) <= 1e-6) {
			goto L30;
		    }
		    is = 4;
		    del2 = coord[ka + i__ * 3] - coord[ka + j * 3];
		} else {
/*   (P/P) TERM */
		    if (ka == la) {
/*    P/P */
			is = 9;
			if (force3_1.ix == ka) {
			    goto L20;
			}
			if (abs(del1) <= 1e-6) {
			    goto L30;
			}
/*    P'/P' */
			is = 8;
			del2 = coord[ka + i__ * 3] - coord[ka + j * 3];
		    } else if (force3_1.ix != ka && force3_1.ix != la) {
/*    P'/P" */
			if (abs(del1) <= 1e-6) {
			    goto L30;
			}
			is = 7;
			del2 = coord[ka + i__ * 3] - coord[ka + j * 3];
			del3 = coord[la + i__ * 3] - coord[la + j * 3];
		    } else {
/*    P/P' OR P'/P */
			del2 = coord[ka + la - force3_1.ix + i__ * 3] - coord[
				ka + la - force3_1.ix + j * 3];
			is = 6;
		    }
		}

/*        CALCULATE OVERLAP DERIVATIVES, STORE RESULTS IN DS */

L20:
		ders_(&kg, &lg, &rr, &del1, &del2, &del3, &is, &iol);
L30:
		;
	    }
	}
	if (! mindo3 && force3_1.ix == 1) {
	    s_rsue(&io___36);
	    for (i22 = 1; i22 <= 22; ++i22) {
		do_uio(&c__1, (char *)&extra_1.g[i22 - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsue();
	}
	if (! mindo3) {
	    delri_(derivs_1.dg, &ni, &nj, &r0, &del1);
	}
	delmol_(&coord[4], &i__, &j, &ni, &nj, &ia, &id, &ja, &jd, &
		force3_1.ix, &rij, &del1, &isp);

/*   THE FIRST DERIVATIVE OF NUCLEAR REPULSION TERM */
	if (mindo3) {
	    ii = max(ni,nj);
	    nbond = ii * (ii - 1) / 2 + ni + nj - ii;
	    alpha = 0.;
	    if (nbond < 154) {
		alpha = alpha3_1.alp3[nbond - 1];
	    } else {
		alph1 = 100.;
		alph2 = 100.;
		if (natorb_1.natorb[ni - 1] == 0) {
		    alph1 = alpha_1.alpa[ni - 1];
		}
		if (natorb_1.natorb[nj - 1] == 0) {
		    alph2 = alpha_1.alpa[nj - 1];
		}
	    }
/* Computing 2nd power */
	    d__1 = 7.1995 / twoel3_1.f03[ni - 1] + 7.1995 / twoel3_1.f03[nj - 
		    1];
	    c2 = d__1 * d__1;
	    c1 = del1 / rij * core_1.core[ni - 1] * core_1.core[nj - 1] * 
		    14.399;
	    c3 = del1 / rij * (d__1 = core_1.core[ni - 1] * core_1.core[nj - 
		    1], abs(d__1)) * 14.399;
	    if (nbond == 22 || nbond == 29) {
/* Computing 2nd power */
		d__1 = rij;
/* Computing 2nd power */
		d__3 = rij;
		d__2 = d__3 * d__3 + c2;
/* Computing 2nd power */
		d__4 = rij;
/* Computing 2nd power */
		d__6 = rij;
		d__5 = d__6 * d__6 + c2;
		termnc = -c1 * alpha * (1. / (d__1 * d__1) - rij * pow_dd(&
			d__2, &c_b11) + 1. / rij - 1. / sqrt(d__4 * d__4 + c2)
			) * exp(-rij) - c1 * rij * pow_dd(&d__5, &c_b11);
	    } else if (rij < 1. && natorb_1.natorb[ni - 1] * natorb_1.natorb[
		    nj - 1] == 0) {
		termnc = 0.;
	    } else if (nbond >= 154) {

/*  SPECIAL CASE INVOLVING SPARKLES */

/* Computing MIN */
		d__1 = alph1 * rij;
		exp1 = exp(-min(d__1,20.));
/* Computing MIN */
		d__1 = alph2 * rij;
		exp2 = exp(-min(d__1,20.));
/* Computing 2nd power */
		d__1 = rij;
/* Computing 2nd power */
		d__3 = rij;
		d__2 = d__3 * d__3 + c2;
		part1 = -c3 * (1. / (d__1 * d__1) - rij * pow_dd(&d__2, &
			c_b11)) * (exp1 + exp2);
/* Computing 2nd power */
		d__1 = rij;
		part2 = -c3 * (1. / rij - 1. / sqrt(d__1 * d__1 + c2)) * (
			alph1 * exp1 + alph2 * exp2);
/* Computing 2nd power */
		d__2 = rij;
		d__1 = d__2 * d__2 + c2;
		part3 = -c1 * rij * pow_dd(&d__1, &c_b11);
		termnc = part1 + part2 + part3;
/* #            WRITE(6,'(4F13.6)')PART1,PART2,PART3,TERMNC */
	    } else {
/* Computing 2nd power */
		d__1 = rij;
/* Computing 2nd power */
		d__3 = rij;
		d__2 = d__3 * d__3 + c2;
/* Computing 2nd power */
		d__4 = rij;
/* Computing 2nd power */
		d__6 = rij;
		d__5 = d__6 * d__6 + c2;
		termnc = -c1 * (1. / (d__1 * d__1) - rij * pow_dd(&d__2, &
			c_b11) + alpha / rij - alpha / sqrt(d__4 * d__4 + c2))
			 * exp(-alpha * rij) - c1 * rij * pow_dd(&d__5, &
			c_b11);
	    }
/* Computing 2nd power */
	    d__2 = rij;
	    d__1 = d__2 * d__2 + c2;
	    dr1 = del1 / rij * 14.399 * rij * pow_dd(&d__1, &c_b11);
	} else {

/*      CORE-CORE TERMS, MNDO AND AM1 */


/*  SPECIAL TREATMENT FOR N-H AND O-H TERMS */

	    if (rij < 1. && natorb_1.natorb[ni - 1] * natorb_1.natorb[nj - 1] 
		    == 0) {
		termnc = 0.;
		goto L50;
	    }
	    c1 = core_1.core[ni - 1] * core_1.core[nj - 1];
	    if (ni == 1 && (nj == 7 || nj == 8)) {
		f3 = exp(-alpha_1.alpa[0] * rij) + 1. + rij * exp(
			-alpha_1.alpa[nj - 1] * rij);
		dd = (derivs_1.dg[0] * f3 - extra_1.g[0] * (del1 / rij) * (
			alpha_1.alpa[0] * exp(-alpha_1.alpa[0] * rij) + (
			alpha_1.alpa[nj - 1] * rij - 1.) * exp(-alpha_1.alpa[
			nj - 1] * rij))) * c1;
	    } else if ((ni == 7 || ni == 8) && nj == 1) {
		f3 = exp(-alpha_1.alpa[0] * rij) + 1. + rij * exp(
			-alpha_1.alpa[ni - 1] * rij);
		dd = (derivs_1.dg[0] * f3 - extra_1.g[0] * (del1 / rij) * (
			alpha_1.alpa[0] * exp(-alpha_1.alpa[0] * rij) + (
			alpha_1.alpa[ni - 1] * rij - 1.) * exp(-alpha_1.alpa[
			ni - 1] * rij))) * c1;
	    } else {
/* #            ELSEIF(NATORB(NI)+NATORB(NJ).EQ.0) THEN */

/*  SPECIAL CASE OF TWO SPARKLES */

		part1 = derivs_1.dg[0] * c1;
		part2 = -(extra_1.g[0] * (del1 / rij) * (alpha_1.alpa[ni - 1] 
			* exp(-alpha_1.alpa[ni - 1] * rij) + alpha_1.alpa[nj 
			- 1] * exp(-alpha_1.alpa[nj - 1] * rij))) * abs(c1);
		part3 = derivs_1.dg[0] * (exp(-alpha_1.alpa[ni - 1] * rij) + 
			exp(-alpha_1.alpa[nj - 1] * rij)) * abs(c1);
		dd = part1 + part2 + part3;
/* #            WRITE(6,'(4F13.6)')PART1,PART2,PART3,DD */
/* #            ELSE */

/*   THE GENERAL CASE */

/* #               F3=1.0D0+EXP(-ALPA(NI)*RIJ)+EXP(-ALPA(NJ)*RIJ) */
/* #               DD=(DG(1)*F3-G(1)*(DEL1/RIJ)*(ALPA(NI)*EXP(-ALPA(NI)*RI */
/* #     1J) +ALPA(NJ)*EXP(-ALPA(NJ)*RIJ)))*C1 */
	    }
	    termnc = dd;
	}

/*   ****   START OF THE AM1 SPECIFIC DERIVATIVE CODE   *** */

/*      ANALYT=-A*(1/(R*R)+2.D0*B*(R-C)/R)*EXP(-B*(R-C)**2) */

/*    ANALYTICAL DERIVATIVES */

	if (am1) {
	    anam1 = 0.;
	    for (ig = 1; ig <= 10; ++ig) {
		if ((d__1 = ideas_1.fn1[ni + ig * 107 - 108], abs(d__1)) > 0.)
			 {
/* Computing MAX */
/* Computing 2nd power */
		    d__4 = rij - ideas_1.fn3[ni + ig * 107 - 108];
		    d__2 = -30., d__3 = -ideas_1.fn2[ni + ig * 107 - 108] * (
			    d__4 * d__4);
		    anam1 += ideas_1.fn1[ni + ig * 107 - 108] * (1. / (rij * 
			    rij) + ideas_1.fn2[ni + ig * 107 - 108] * 2. * (
			    rij - ideas_1.fn3[ni + ig * 107 - 108]) / rij) * 
			    exp((max(d__2,d__3)));
		}
		if ((d__1 = ideas_1.fn1[nj + ig * 107 - 108], abs(d__1)) > 0.)
			 {
/* Computing MAX */
/* Computing 2nd power */
		    d__4 = rij - ideas_1.fn3[nj + ig * 107 - 108];
		    d__2 = -30., d__3 = -ideas_1.fn2[nj + ig * 107 - 108] * (
			    d__4 * d__4);
		    anam1 += ideas_1.fn1[nj + ig * 107 - 108] * (1. / (rij * 
			    rij) + ideas_1.fn2[nj + ig * 107 - 108] * 2. * (
			    rij - ideas_1.fn3[nj + ig * 107 - 108]) / rij) * 
			    exp((max(d__2,d__3)));
		}
/* L40: */
	    }
	    anam1 = anam1 * core_1.core[ni - 1] * core_1.core[nj - 1];
	    termnc -= anam1 * del1 / rij;
	}

/*   ****   END OF THE AM1 SPECIFIC DERIVATIVE CODE   *** */

L50:

/*   COMBINE TOGETHER THE OVERLAP DERIVATIVE PARTS */

	if (mindo3) {
	    ii = max(ni,nj);
	    nbond = ii * (ii - 1) / 2 + ni + nj - ii;
	    if (nbond > 153) {
		goto L60;
	    }
	    bi[0] = beta3_1.beta3[nbond - 1] * vsips_1.vs[ni - 1] * 2.;
	    bi[1] = beta3_1.beta3[nbond - 1] * vsips_1.vp[ni - 1] * 2.;
	    bi[2] = bi[1];
	    bi[3] = bi[1];
	    bj[0] = beta3_1.beta3[nbond - 1] * vsips_1.vs[nj - 1] * 2.;
	    bj[1] = beta3_1.beta3[nbond - 1] * vsips_1.vp[nj - 1] * 2.;
	    bj[2] = bj[1];
	    bj[3] = bj[1];
L60:
	    ;
	} else {
	    bi[0] = betas_1.betas[ni - 1];
	    bi[1] = betas_1.betap[ni - 1];
	    bi[2] = bi[1];
	    bi[3] = bi[1];
	    bj[0] = betas_1.betas[nj - 1];
	    bj[1] = betas_1.betap[nj - 1];
	    bj[2] = bj[1];
	    bj[3] = bj[1];
	}

/*       CODE COMMON TO MINDO/3, MNDO, AND AM1 */

	iol = 0;
	i__2 = id;
	for (k = ia; k <= i__2; ++k) {
	    i__1 = jd;
	    for (l = ja; l <= i__1; ++l) {
		lk = l + k * (k - 1) / 2;
		termk = bi[k - ia];
		terml = bj[l - ja];
		++iol;
		termab += (termk + terml) * psum[lk] * derivs_1.ds[iol - 1];
/* L70: */
	    }
	}
	if (mindo3) {

/*        FIRST, CORE-ELECTRON ATTRACTION DERIVATIVES (MINDO/3) */

/*          ATOM CORE I AFFECTING A.O.S ON J */
	    i__1 = jd;
	    for (m = ja; m <= i__1; ++m) {
		mn = m * (m + 1) / 2;
/* L80: */
		termab += core_1.core[ni - 1] * psum[mn] * dr1;
	    }
/*          ATOM CORE J AFFECTING A.O.S ON I */
	    i__1 = id;
	    for (m = ia; m <= i__1; ++m) {
		mn = m * (m + 1) / 2;
/* L90: */
		termab += core_1.core[nj - 1] * psum[mn] * dr1;
	    }

/*   NOW FOR COULOMB AND EXCHANGE TERMS (MINDO/3) */

	    i__1 = id;
	    for (i1 = ia; i1 <= i__1; ++i1) {
		ii = i1 * (i1 + 1) / 2;
		i__2 = jd;
		for (j1 = ja; j1 <= i__2; ++j1) {
		    jj = j1 * (j1 + 1) / 2;
		    ij = j1 + i1 * (i1 - 1) / 2;

/*           COULOMB TERM */

		    termaa -= psum[ii] * dr1 * psum[jj];

/*           EXCHANGE TERM */

		    termaa += (palpha[ij] * palpha[ij] + pbeta[ij] * pbeta[ij]
			    ) * dr1;
/* L100: */
		}
	    }
	} else {

/*        FIRST, CORE-ELECTRON ATTRACTION DERIVATIVES (MNDO AND AM1) */

/*          ATOM CORE I AFFECTING A.O.S ON J */
	    isp = 0;
	    i__2 = jd;
	    for (m = ja; m <= i__2; ++m) {
		bb = 1.;
		i__1 = jd;
		for (n = m; n <= i__1; ++n) {
		    mn = m + n * (n - 1) / 2;
		    ++isp;
		    termab -= bb * core_1.core[ni - 1] * psum[mn] * 
			    derivs_1.dr[isp - 1];
/* L110: */
		    bb = 2.;
		}
	    }
/*          ATOM CORE J AFFECTING A.O.S ON I */
/* Computing MAX */
	    i__1 = jd - ja + 1;
	    k = max(i__1,1);
	    k = k * (k + 1) / 2;
	    isp = -k + 1;
	    i__1 = id;
	    for (m = ia; m <= i__1; ++m) {
		bb = 1.;
		i__2 = id;
		for (n = m; n <= i__2; ++n) {
		    mn = m + n * (n - 1) / 2;
		    isp += k;
		    termab -= bb * core_1.core[nj - 1] * psum[mn] * 
			    derivs_1.dr[isp - 1];
/* L120: */
		    bb = 2.;
		}
	    }
	    isp = 0;

/*   NOW FOR COULOMB AND EXCHANGE TERMS (MNDO AND AM1) */

	    i__2 = id;
	    for (k = ia; k <= i__2; ++k) {
		aa = 1.;
		kk = k * (k - 1) / 2;
		i__1 = id;
		for (l = k; l <= i__1; ++l) {
		    ll = l * (l - 1) / 2;
		    i__3 = jd;
		    for (m = ja; m <= i__3; ++m) {
			bb = 1.;
			i__4 = jd;
			for (n = m; n <= i__4; ++n) {
			    ++isp;
			    kl = k + ll;
			    mn = m + n * (n - 1) / 2;

/*    COULOMB TERM */

			    termaa += aa * bb * psum[kl] * psum[mn] * 
				    derivs_1.dr[isp - 1];
			    mk = m + kk;
			    nk = n + kk;
			    ml = m + ll;
			    nl = n + ll;

/*    EXCHANGE TERM */

			    termaa -= aa * .5 * bb * (palpha[mk] * palpha[nl] 
				    + palpha[nk] * palpha[ml] + pbeta[mk] * 
				    pbeta[nl] + pbeta[nk] * pbeta[ml]) * 
				    derivs_1.dr[isp - 1];
/* L130: */
			    bb = 2.;
			}
		    }
/* L140: */
		    aa = 2.;
		}
	    }
/*           END OF MNDO AND AM1 SPECIFIC CODE */
	}
	eaa[force3_1.ix - 1] += termaa;
	eab[force3_1.ix - 1] += termab;
	enuc[force3_1.ix - 1] += termnc;
/* L150: */
    }
/* #            WRITE(6,*)EAA,EAB,ENUC,NAT(1),NAT(2) */
/* L160: */
/* L170: */
    for (j = 1; j <= 3; ++j) {
	eng[j] = eaa[j - 1] + eab[j - 1] + enuc[j - 1];
	eng[j] = -eng[j] * 23.061;
/* L180: */
    }
    return 0;
} /* analyt_ */

