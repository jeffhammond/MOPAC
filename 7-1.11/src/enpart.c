/* enpart.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal uss[107], upp[107], udd[107];
} onelec_;

#define onelec_1 onelec_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal fn1[1070]	/* was [107][10] */, fn2[1070]	/* was [107][
	    10] */, fn3[1070]	/* was [107][10] */;
} ideas_;

#define ideas_1 ideas_

struct {
    doublereal alp3[153];
} alpha3_;

#define alpha3_1 alpha3_

struct {
    doublereal f03[107];
} twoel3_;

#define twoel3_1 twoel3_

struct {
    doublereal alp[107];
} alpha_;

#define alpha_1 alpha_

struct {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
} twoele_;

#define twoele_1 twoele_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal w[429540];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal ea[240]	/* was [120][2] */, eat[120], e[29040]	/* was [7260][
	    4] */, xdumy[100200];
} scrach_;

#define scrach_1 scrach_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int enpart_(logical *uhf, doublereal *h__, doublereal *alpha,
	 doublereal *beta, doublereal *p, doublereal *q, doublereal *coord)
{
    /* Format strings */
    static char fmt_370[] = "(///,\002***  SUMMARY OF ENERGY PARTITION  **"
	    "*\002)";
    static char fmt_380[] = "(\002 \002,\002--------------------------------"
	    "-------\002)";
    static char fmt_390[] = "(/,\002 ELECTRON-NUCLEAR  (ONE-ELECTRON) \002,f"
	    "17.4,\002 EV\002)";
    static char fmt_400[] = "(\002 ELECTRON-ELECTRON (TWO-ELECTRON) \002,f17"
	    ".4,\002 EV\002)";
    static char fmt_410[] = "(/,\002 TOTAL OF ONE-CENTER TERMS        \002,1"
	    "8x,f15.4,\002 EV\002)";
    static char fmt_420[] = "(/,\002 RESONANCE ENERGY\002,8x,f15.4,\002 E"
	    "V\002)";
    static char fmt_430[] = "(\002 EXCHANGE ENERGY \002,8x,f15.4,\002 EV\002)"
	    ;
    static char fmt_440[] = "(/,\002 EXCHANGE + RESONANCE ENERGY:       \002"
	    ",f15.4,\002 EV\002)";
    static char fmt_450[] = "(/,\002 ELECTRON-ELECTRON REPULSION\002,f12.4"
	    ",\002 EV\002)";
    static char fmt_460[] = "(\002 ELECTRON-NUCLEAR ATTRACTION\002,f12.4,"
	    "\002 EV\002)";
    static char fmt_470[] = "(\002 NUCLEAR-NUCLEAR REPULSION  \002,f12.4,"
	    "\002 EV\002)";
    static char fmt_480[] = "(/,\002 TOTAL ELECTROSTATIC INTERACTION    \002"
	    ",f15.4,\002 EV\002,/)";
    static char fmt_490[] = "(\002 GRAND TOTAL OF TWO-CENTER TERMS   \002,17"
	    "x,f15.4,\002 EV\002)";
    static char fmt_500[] = "(\002 ETOT (EONE + ETWO)   \002,30x,f15.4,\002 "
	    "EV\002//)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void);
    double sqrt(doublereal), exp(doublereal);
    integer do_fio(integer *, char *, ftnlen), s_wsle(cilist *), e_wsle(void);

    /* Local variables */
    static doublereal g;
    static integer i__, j, k, l, n;
    static doublereal r__, t, aa, bb;
    static integer ia, ib, ja, jb, ka, kc, ig, kb, ii, ij, jj, ik, kk, ni, kl,
	     nj, jk, il, jl;
    static doublereal ex[21780]	/* was [7260][3] */;
    static integer lk;
    static doublereal et;
    static integer nt, ia1, ia2;
    static logical am1;
    static doublereal ss1, ss2, ss3, ss4, ss5, tt1, tt2, tt3, tt4, tt5, eae, 
	    eau, gij, pij, rij;
    static integer iss, jss, isx, isy, isz, ixx, ixy, iyy, izz, ixz, iyz;
    static doublereal pab2;
    static integer iap1, jap1;
    static doublereal eabe, eabr, eabx;
    static integer kinc;
    static doublereal tone, ttwo, eabee, eaben, eabnn, scale;
    static integer nbond;
    static doublereal eabrx, oneii, onejj;
    static logical mindo3;
    static integer numat1, linear, iminus;

    /* Fortran I/O blocks */
    static cilist io___33 = { 0, 6, 0, "(///,10X,'TOTAL ENERGY PARTITIONING "
	    "IN MINDO/3')", 0 };
    static cilist io___34 = { 0, 6, 0, "(///,10X,'TOTAL ENERGY PARTITIONING "
	    "IN PM3')", 0 };
    static cilist io___35 = { 0, 6, 0, "(///,10X,'TOTAL ENERGY PARTITIONING "
	    "IN AM1')", 0 };
    static cilist io___36 = { 0, 6, 0, "(///,10X,'TOTAL ENERGY PARTITIONING "
	    "IN MNDO')", 0 };
    static cilist io___37 = { 0, 6, 0, "(/10X,'ALL ENERGIES ARE IN ELECTRON "
	    "VOLTS')", 0 };
    static cilist io___80 = { 0, 6, 0, "(/,8(10X,A,/))", 0 };
    static cilist io___81 = { 0, 6, 0, "(/,'   ATOM     E-E       E-N    (E-"
	    "E + E-N)')", 0 };
    static cilist io___82 = { 0, 6, 0, "(2X,A2,I3,1X,2F10.4,F10.4)", 0 };
    static cilist io___83 = { 0, 6, 0, "(/,8(10X,A,/))", 0 };
    static cilist io___84 = { 0, 6, 0, "(/,'   ATOM          J        K     "
	    "  E-',             'E       E-N      N-N      C        EE')", 0 };
    static cilist io___85 = { 0, 6, 0, "('   PAIR')", 0 };
    static cilist io___86 = { 0, 6, 0, "(1X,A2,I3,1X,A2,I3,1X,2F9.4,F9.4,F10"
	    ".4,F9.4,F8.4,F9.4)", 0 };
    static cilist io___87 = { 0, 6, 0, 0, 0 };
    static cilist io___88 = { 0, 6, 0, "(/,'   ATOM          J        K     "
	    "  E-', 'E       E-N      N-N      C        EE')", 0 };
    static cilist io___89 = { 0, 6, 0, "('   PAIR')", 0 };
    static cilist io___99 = { 0, 6, 0, fmt_370, 0 };
    static cilist io___100 = { 0, 6, 0, fmt_380, 0 };
    static cilist io___101 = { 0, 6, 0, "('     ONE-CENTER TERMS')", 0 };
    static cilist io___102 = { 0, 6, 0, fmt_390, 0 };
    static cilist io___103 = { 0, 6, 0, fmt_400, 0 };
    static cilist io___104 = { 0, 6, 0, fmt_410, 0 };
    static cilist io___105 = { 0, 6, 0, fmt_380, 0 };
    static cilist io___106 = { 0, 6, 0, "('     TWO-CENTER TERMS')", 0 };
    static cilist io___107 = { 0, 6, 0, fmt_420, 0 };
    static cilist io___108 = { 0, 6, 0, fmt_430, 0 };
    static cilist io___109 = { 0, 6, 0, fmt_440, 0 };
    static cilist io___110 = { 0, 6, 0, fmt_450, 0 };
    static cilist io___111 = { 0, 6, 0, fmt_460, 0 };
    static cilist io___112 = { 0, 6, 0, fmt_470, 0 };
    static cilist io___113 = { 0, 6, 0, fmt_480, 0 };
    static cilist io___114 = { 0, 6, 0, fmt_490, 0 };
    static cilist io___115 = { 0, 6, 0, fmt_380, 0 };
    static cilist io___116 = { 0, 6, 0, fmt_500, 0 };


/* ----------------------------------------------------------* */

/*     NEW SUB. ENPART,  MODIFIED BY TSUNEO HIRANO 1986/6/3/ */

/* ---------------------------------------------------------* */
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
/* --- DEFINED HERE, AND TO BE USED FOR ENPART-PRINT ONLY ---* */
/* --- END OF DIMENSION DEFINITION ----------------- BY TH --* */
/* *********************************************************************** */

/* *** ENERGY PARTITIONING WITHIN THE UMINDO/3 AND UMNDO SCHEME */
/*     ROUTINE WRITTEN BY S.OLIVELLA, BARCELONA NOV. 1979. */
/*     EXTENDED TO AM1 AND PM3 BY JJPS. */

/*   ON INPUT UHF     = .TRUE. IF A U.H.F. CALCULATION. */
/*            H       = ONE-ELECTRON MATRIX. */
/*            ALPHA   = ALPHA ELECTRON DENSITY. */
/*            BETA    = BETA ELECTRON DENSITY. */
/*            P       = TOTAL ELECTRON DENSITY. */
/*            Q       = ATOM ELECTRON DENSITIES. */

/*    NOTHING IS CHANGED ON EXIT. */

/* *********************************************************************** */
    /* Parameter adjustments */
    coord -= 4;
    --q;
    --p;
    --beta;
    --alpha;
    --h__;

    /* Function Body */
    mindo3 = i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0;
/* *** RECALCULATE THE DENSITY MATRICES IN THE UHF SCHEME */

    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
    if (! (*uhf)) {
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	    beta[i__] = alpha[i__];
	}
    }

/* *** ONE-CENTER ENERGIES */
    k = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = molkst_1.nfirst[i__ - 1];
	ib = molkst_1.nlast[i__ - 1];
	ni = molkst_1.nat[i__ - 1];
	scrach_1.ea[i__ - 1] = 0.;
	i__2 = ib;
	for (j = ia; j <= i__2; ++j) {
	    k += j;
	    t = onelec_1.upp[ni - 1];
	    if (j == ia) {
		t = onelec_1.uss[ni - 1];
	    }
/* L30: */
	    scrach_1.ea[i__ - 1] += p[k] * t;
	}
	iss = ia * (ia + 1) / 2;
	scrach_1.ea[i__ + 119] = twoele_1.gss[ni - 1] * .5 * p[iss] * p[iss] 
		- twoele_1.gss[ni - 1] * .5 * (alpha[iss] * alpha[iss] + beta[
		iss] * beta[iss]);
	if (ia == ib) {
	    goto L40;
	}
	ia1 = ia + 1;
	ia2 = ia + 2;
	ixx = ia1 * ia2 / 2;
	iyy = ia2 * ib / 2;
	izz = ib * (ib + 1) / 2;
	ixy = ia1 + ia2 * ia1 / 2;
	ixz = ia1 + ib * ia2 / 2;
	iyz = ia2 + ib * ia2 / 2;
	isx = ia + ia1 * ia / 2;
	isy = ia + ia2 * ia1 / 2;
	isz = ia + ib * ia2 / 2;
	ss1 = p[ixx] * p[ixx] + p[iyy] * p[iyy] + p[izz] * p[izz];
	ss2 = p[iss] * (p[ixx] + p[iyy] + p[izz]);
	ss3 = p[ixx] * p[iyy] + p[ixx] * p[izz] + p[iyy] * p[izz];
	ss4 = p[isx] * p[isx] + p[isy] * p[isy] + p[isz] * p[isz];
	ss5 = p[ixy] * p[ixy] + p[ixz] * p[ixz] + p[iyz] * p[iyz];
	tt1 = alpha[ixx] * alpha[ixx] + alpha[iyy] * alpha[iyy] + alpha[izz] *
		 alpha[izz] + beta[ixx] * beta[ixx] + beta[iyy] * beta[iyy] + 
		beta[izz] * beta[izz];
	tt2 = alpha[iss] * (alpha[ixx] + alpha[iyy] + alpha[izz]) + beta[iss] 
		* (beta[ixx] + beta[iyy] + beta[izz]);
	tt3 = alpha[ixx] * alpha[iyy] + alpha[ixx] * alpha[izz] + alpha[iyy] *
		 alpha[izz] + beta[ixx] * beta[iyy] + beta[ixx] * beta[izz] + 
		beta[iyy] * beta[izz];
	tt4 = alpha[isx] * alpha[isx] + alpha[isy] * alpha[isy] + alpha[isz] *
		 alpha[isz] + beta[isx] * beta[isx] + beta[isy] * beta[isy] + 
		beta[isz] * beta[isz];
	tt5 = alpha[ixy] * alpha[ixy] + alpha[ixz] * alpha[ixz] + alpha[iyz] *
		 alpha[iyz] + beta[ixy] * beta[ixy] + beta[ixz] * beta[ixz] + 
		beta[iyz] * beta[iyz];
	scrach_1.ea[i__ + 119] = scrach_1.ea[i__ + 119] + twoele_1.gpp[ni - 1]
		 * .5 * ss1 + twoele_1.gsp[ni - 1] * ss2 + twoele_1.gp2[ni - 
		1] * ss3 + twoele_1.hsp[ni - 1] * ss4 * 2. + (twoele_1.gpp[ni 
		- 1] - twoele_1.gp2[ni - 1]) * .5 * ss5 * 2. - twoele_1.gpp[
		ni - 1] * .5 * tt1 - twoele_1.gsp[ni - 1] * tt4 - 
		twoele_1.gp2[ni - 1] * tt5 - twoele_1.hsp[ni - 1] * (tt2 + 
		tt4) - (twoele_1.gpp[ni - 1] - twoele_1.gp2[ni - 1]) * .5 * (
		tt3 + tt5);
L40:
	;
    }
    am1 = i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) + i_indx(
	    keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0;
    if (mindo3) {
	s_wsfe(&io___33);
	e_wsfe();
    } else if (i_indx(keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0) {
	s_wsfe(&io___34);
	e_wsfe();
    } else if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0) {
	s_wsfe(&io___35);
	e_wsfe();
    } else {
	s_wsfe(&io___36);
	e_wsfe();
    }
    s_wsfe(&io___37);
    e_wsfe();
    kl = 0;
L50:
    k = kl + 1;
    kl += 10;
    kl = min(kl,molkst_1.numat);
    i__1 = kl;
    for (i__ = k; i__ <= i__1; ++i__) {
/* L60: */
	scrach_1.eat[i__ - 1] = scrach_1.ea[i__ - 1] + scrach_1.ea[i__ + 119];
    }
    if (molkst_1.numat > kl) {
	goto L50;
    }
/* L70: */
    eau = 0.;
    eae = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	eau += scrach_1.ea[i__ - 1];
/* L80: */
	eae += scrach_1.ea[i__ + 119];
    }
    tone = eau + eae;
/* *** TWO-CENTER ENERGIES */
/*     RESONANCE (E(N,1)) TERMS */
    n = 1;
    i__1 = molkst_1.numat;
    for (ii = 2; ii <= i__1; ++ii) {
	scrach_1.e[n - 1] = 0.;
	ia = molkst_1.nfirst[ii - 1];
	ib = molkst_1.nlast[ii - 1];
	iminus = ii - 1;
	oneii = 1.;
	if (molkst_1.nat[ii - 1] == 102) {
	    oneii = 0.;
	}
	i__2 = iminus;
	for (jj = 1; jj <= i__2; ++jj) {
	    ++n;
	    ja = molkst_1.nfirst[jj - 1];
	    jb = molkst_1.nlast[jj - 1];
	    onejj = 1.;
	    if (molkst_1.nat[jj - 1] == 102) {
		onejj = 0.;
	    }
	    scrach_1.e[n - 1] = 0.;
	    i__3 = ib;
	    for (i__ = ia; i__ <= i__3; ++i__) {
		ka = i__ * (i__ - 1) / 2;
		i__4 = jb;
		for (k = ja; k <= i__4; ++k) {
		    ik = ka + k;
/* L90: */
		    scrach_1.e[n - 1] += p[ik] * 2. * h__[ik] * oneii * onejj;
		}
	    }
	}
/* L100: */
	++n;
    }

/*     THE CODE THAT FOLLOWS APPLIES ONLY TO MNDO */

    if (! mindo3) {
/*     CORE-CORE REPULSION (E(N,2)) AND CORE-ELEC. ATTRACTION (E(N,3)). */
	n = 1;
	kk = 0;
	i__1 = molkst_1.numat;
	for (ii = 2; ii <= i__1; ++ii) {
	    scrach_1.e[n + 7259] = 0.;
	    scrach_1.e[n + 14519] = 0.;
	    ia = molkst_1.nfirst[ii - 1];
	    ib = molkst_1.nlast[ii - 1];
	    ni = molkst_1.nat[ii - 1];
	    iss = ia * (ia + 1) / 2;
	    iminus = ii - 1;
	    i__4 = iminus;
	    for (jj = 1; jj <= i__4; ++jj) {
		++n;
		ja = molkst_1.nfirst[jj - 1];
		jb = molkst_1.nlast[jj - 1];
		nj = molkst_1.nat[jj - 1];
		jss = ja * (ja + 1) / 2;
		++kk;
		g = wmatrx_1.w[kk - 1];
/* Computing 2nd power */
		d__1 = coord[ii * 3 + 1] - coord[jj * 3 + 1];
/* Computing 2nd power */
		d__2 = coord[ii * 3 + 2] - coord[jj * 3 + 2];
/* Computing 2nd power */
		d__3 = coord[ii * 3 + 3] - coord[jj * 3 + 3];
		r__ = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
		scale = exp(-alpha_1.alp[ni - 1] * r__) + 1. + exp(
			-alpha_1.alp[nj - 1] * r__);
		nt = ni + nj;
		if (nt < 8 || nt > 9) {
		    goto L110;
		}
		if (ni == 7 || ni == 8) {
		    scale += (r__ - 1.) * exp(-alpha_1.alp[ni - 1] * r__);
		}
		if (nj == 7 || nj == 8) {
		    scale += (r__ - 1.) * exp(-alpha_1.alp[nj - 1] * r__);
		}
L110:
		scrach_1.e[n + 7259] = core_1.core[ni - 1] * core_1.core[nj - 
			1] * g * scale;
		if (am1) {
		    scale = 0.;
		    for (ig = 1; ig <= 10; ++ig) {
			if ((d__1 = ideas_1.fn1[ni + ig * 107 - 108], abs(
				d__1)) > 0.) {
/* Computing 2nd power */
			    d__2 = r__ - ideas_1.fn3[ni + ig * 107 - 108];
			    scale += core_1.core[ni - 1] * core_1.core[nj - 1]
				     / r__ * ideas_1.fn1[ni + ig * 107 - 108] 
				    * exp(-ideas_1.fn2[ni + ig * 107 - 108] * 
				    (d__2 * d__2));
			}
			if ((d__1 = ideas_1.fn1[nj + ig * 107 - 108], abs(
				d__1)) > 0.) {
/* Computing 2nd power */
			    d__2 = r__ - ideas_1.fn3[nj + ig * 107 - 108];
			    scale += core_1.core[ni - 1] * core_1.core[nj - 1]
				     / r__ * ideas_1.fn1[nj + ig * 107 - 108] 
				    * exp(-ideas_1.fn2[nj + ig * 107 - 108] * 
				    (d__2 * d__2));
			}
/* L120: */
		    }
		    scrach_1.e[n + 7259] += scale;
		}
		scrach_1.e[n + 14519] = -(p[iss] * core_1.core[nj - 1] + p[
			jss] * core_1.core[ni - 1]) * g;
		if (nj < 3) {
		    goto L140;
		}
		kinc = 9;
		jap1 = ja + 1;
		i__3 = jb;
		for (k = jap1; k <= i__3; ++k) {
		    kc = k * (k - 1) / 2;
		    i__2 = k;
		    for (l = ja; l <= i__2; ++l) {
			kl = kc + l;
			bb = 2.;
			if (k == l) {
			    bb = 1.;
			}
			++kk;
/* L130: */
			scrach_1.e[n + 14519] -= p[kl] * core_1.core[ni - 1] *
				 bb * wmatrx_1.w[kk - 1];
		    }
		}
		goto L150;
L140:
		kinc = 0;
L150:
		if (ni < 3) {
		    goto L170;
		}
		iap1 = ia + 1;
		i__2 = ib;
		for (i__ = iap1; i__ <= i__2; ++i__) {
		    ka = i__ * (i__ - 1) / 2;
		    i__3 = i__;
		    for (j = ia; j <= i__3; ++j) {
			ij = ka + j;
			aa = 2.;
			if (i__ == j) {
			    aa = 1.;
			}
			++kk;
			scrach_1.e[n + 14519] -= p[ij] * core_1.core[nj - 1] *
				 aa * wmatrx_1.w[kk - 1];
/* L160: */
			kk += kinc;
		    }
		}
L170:
		;
	    }
/* L180: */
	    ++n;
	}
/*     COULOMB (E(N,4)) AND EXCHANGE (EX(N)) TERMS */
	n = 1;
	kk = 0;
	i__1 = molkst_1.numat;
	for (ii = 2; ii <= i__1; ++ii) {
	    scrach_1.e[n + 21779] = 0.;
	    ex[n - 1] = 0.;
	    ia = molkst_1.nfirst[ii - 1];
	    ib = molkst_1.nlast[ii - 1];
	    iminus = ii - 1;
	    i__4 = iminus;
	    for (jj = 1; jj <= i__4; ++jj) {
		ja = molkst_1.nfirst[jj - 1];
		jb = molkst_1.nlast[jj - 1];
		++n;
		scrach_1.e[n + 21779] = 0.;
		ex[n - 1] = 0.;
		i__3 = ib;
		for (i__ = ia; i__ <= i__3; ++i__) {
		    ka = i__ * (i__ - 1) / 2;
		    i__2 = i__;
		    for (j = ia; j <= i__2; ++j) {
			kb = j * (j - 1) / 2;
			ij = ka + j;
			aa = 2.;
			if (i__ == j) {
			    aa = 1.;
			}
			pij = p[ij];
			i__5 = jb;
			for (k = ja; k <= i__5; ++k) {
			    kc = k * (k - 1) / 2;
			    ik = ka + k;
			    jk = kb + k;
			    i__6 = k;
			    for (l = ja; l <= i__6; ++l) {
				il = ka + l;
				jl = kb + l;
				kl = kc + l;
				bb = 2.;
				if (k == l) {
				    bb = 1.;
				}
				++kk;
				g = wmatrx_1.w[kk - 1];
				scrach_1.e[n + 21779] += aa * bb * g * pij * 
					p[kl];
/* L190: */
				ex[n - 1] -= aa * .5 * bb * g * (alpha[ik] * 
					alpha[jl] + alpha[il] * alpha[jk] + 
					beta[ik] * beta[jl] + beta[il] * beta[
					jk]);
			    }
			}
		    }
		}
	    }
/* L200: */
	    ++n;
	}
    } else {
	n = 1;
	i__1 = molkst_1.numat;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    scrach_1.e[n + 7259] = 0.;
	    scrach_1.e[n + 14519] = 0.;
	    scrach_1.e[n + 21779] = 0.;
	    ex[n - 1] = 0.;
	    ia = molkst_1.nfirst[i__ - 1];
	    ib = molkst_1.nlast[i__ - 1];
	    ni = molkst_1.nat[i__ - 1];
	    iminus = i__ - 1;
	    i__6 = iminus;
	    for (j = 1; j <= i__6; ++j) {
		++n;
		ja = molkst_1.nfirst[j - 1];
		jb = molkst_1.nlast[j - 1];
		nj = molkst_1.nat[j - 1];
/* Computing 2nd power */
		d__1 = coord[i__ * 3 + 1] - coord[j * 3 + 1];
/* Computing 2nd power */
		d__2 = coord[i__ * 3 + 2] - coord[j * 3 + 2];
/* Computing 2nd power */
		d__3 = coord[i__ * 3 + 3] - coord[j * 3 + 3];
		rij = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* Computing 2nd power */
		d__1 = 7.1995 / twoel3_1.f03[ni - 1] + 7.1995 / twoel3_1.f03[
			nj - 1];
		gij = 14.399 / sqrt(rij + d__1 * d__1);
		pab2 = 0.;
		ij = max(ni,nj);
		nbond = ij * (ij - 1) / 2 + ni + nj - ij;
		rij = sqrt(rij);
		if (nbond == 22 || nbond == 29) {
		    goto L210;
		}
		goto L220;
L210:
		scale = alpha3_1.alp3[nbond - 1] * exp(-rij);
		goto L230;
L220:
		scale = exp(-alpha3_1.alp3[nbond - 1] * rij);
L230:
		scrach_1.e[n + 7259] = core_1.core[ni - 1] * core_1.core[nj - 
			1] * gij + (d__1 = core_1.core[ni - 1] * core_1.core[
			nj - 1] * (14.399 / rij - gij) * scale, abs(d__1));
		scrach_1.e[n + 14519] = (-q[i__] * core_1.core[nj - 1] - q[j] 
			* core_1.core[ni - 1]) * gij;
		scrach_1.e[n + 21779] = q[i__] * q[j] * gij;
		i__5 = ib;
		for (k = ia; k <= i__5; ++k) {
		    kk = k * (k - 1) / 2;
		    i__2 = jb;
		    for (l = ja; l <= i__2; ++l) {
			lk = kk + l;
/* L240: */
			pab2 = pab2 + alpha[lk] * alpha[lk] + beta[lk] * beta[
				lk];
		    }
		}
/* L250: */
		ex[n - 1] = -pab2 * gij;
	    }
/* L260: */
	    ++n;
	}
    }
    numat1 = molkst_1.numat * (molkst_1.numat + 1) / 2;
    for (i__ = 1; i__ <= 4; ++i__) {
/* L270: */
	scrach_1.e[numat1 + i__ * 7260 - 7261] = 0.;
    }
    for (i__ = 1; i__ <= 3; ++i__) {
/* L280: */
	ex[numat1 + i__ * 7260 - 7261] = 0.;
    }
/* @ --------------------------* */
/* -----PRINT OUT ONE AND TWO CENTER ENERGIES */

/*     E(I,1):     RESONANCE ENERGY */
/*     E(I,2):     NUCLEAR-NUCLEAR REPULSION ENERGY */
/*     E(I,3):     ELECTRON-NUCLEAR ATTRACTION ENERGY */
/*     E(I,4):     ELECTRON-ELECTRON REPULSION ENERGY */
/*     EX(I,1):    EXCHANGE  ENERGY */
/*     EX(I,2):    EXCHANGE + RESONANCE ENERGY */
/* #      WRITE(6,'(//,''       ONE AND TWO CENTER ENERGIES (EV) '')') */

/* #      WRITE(6,'(/,''  [RESONANCE TERM] (EV)'')') */
/* #      CALL VECPRT(E,NUMAT) */

/* #      WRITE(6,'(/,''  [EXCHANGE TERM] (EV)'')') */
/* #      CALL VECPRT(EX,NUMAT) */

/* #      WRITE(6,'(/,''  [RESONANCE + EXCHANGE] (EV)'')') */
    i__1 = numat1;
    for (n = 1; n <= i__1; ++n) {
/* L290: */
	ex[n + 7259] = scrach_1.e[n - 1] + ex[n - 1];
    }

/*   ADD IN MONOCENTRIC EXCHANGE AND COULOMBIC TERM */

    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L300: */
	ex[i__ * (i__ + 1) / 2 + 7259] = scrach_1.ea[i__ + 119];
    }
/* #      CALL VECPRT(EX(1,2),NUMAT) */

/* #      WRITE(6,'(/,''  [ELECTRON - ELECTRON REPULSION] (EV)'')') */
/* #      CALL VECPRT(E(1,4),NUMAT) */

/* #      WRITE(6,'(/,''  [ELECTRON-NUCLEAR ATTRACTION] (EV)'')') */
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L310: */
	scrach_1.e[i__ * (i__ + 1) / 2 + 14519] = scrach_1.ea[i__ - 1];
    }
/* #      CALL VECPRT(E(1,3),NUMAT) */

/* #      WRITE(6,'(/,''  [NUCLEAR-NUCLEAR REPULSION] (EV)'')') */
/* #      CALL VECPRT(E(1,2),NUMAT) */

    i__1 = numat1;
    for (n = 1; n <= i__1; ++n) {
/* L320: */
	ex[n + 14519] = scrach_1.e[n + 21779] + scrach_1.e[n + 14519] + 
		scrach_1.e[n + 7259];
    }
/*     PRINT OUT OF TOTAL COULOMB TERM */
/* #      WRITE(6,'(/,''  [TOTAL COULOMB TERM (E-E, E-N, AND N-N)] (EV)'') */
/* #      CALL VECPRT(EX(1,3),NUMAT) */
/*     PRINT OUT OF TWO-CENTER SUM(OFF-DIAGONAL) + */
/*                  ONE-CENTER SUM(DIAGONAL). */
/* #      WRITE(6,'(/,''  [TWO-CENTER SUM (OFF-DIAGONAL), AND  '', */
/* #     1''ONE-CENTER SUM (DIAGONAL)] (EV)'')') */
/* #      DO 340 N=1,NUMAT1 */
/* #  340 EX(N,3)=EX(N,3)+EX(N,2) */
/* #      CALL VECPRT(EX(1,3),NUMAT) */
    s_wsfe(&io___80);
    do_fio(&c__1, "  ONE-CENTER TERMS", (ftnlen)18);
    do_fio(&c__1, " ", (ftnlen)1);
    do_fio(&c__1, "E-E:  ELECTRON-ELECTRON REPULSION", (ftnlen)33);
    do_fio(&c__1, "E-N:  ELECTRON-NUCLEAR ATTRACTION", (ftnlen)33);
    e_wsfe();
    s_wsfe(&io___81);
    e_wsfe();
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = i__ * (i__ + 1) / 2;
	s_wsfe(&io___82);
	do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 1 << 1), (
		ftnlen)2);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ex[j + 7259], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&scrach_1.e[j + 14519], (ftnlen)sizeof(
		doublereal));
	d__1 = ex[j + 7259] + scrach_1.e[j + 14519];
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
/* L330: */
    }
    s_wsfe(&io___83);
    do_fio(&c__1, "    TWO-CENTER TERMS", (ftnlen)20);
    do_fio(&c__1, " ", (ftnlen)1);
    do_fio(&c__1, "J:   RESONANCE ENERGY          E-E: ELECTRON-ELECTRON REP"
	    "ULSION", (ftnlen)63);
    do_fio(&c__1, "K:   EXCHANGE ENERGY           E-N: ELECTRON-NUCLEAR ATTR"
	    "ACTION", (ftnlen)63);
    do_fio(&c__1, "                               N-N: NUCLEAR-NUCLEAR REPUL"
	    "SION", (ftnlen)61);
    do_fio(&c__1, "C:   COULOMBIC INTERACTION = E-E + E-N + N-N", (ftnlen)44);
    do_fio(&c__1, "EE:  TOTAL OF ELECTRONIC AND NUCLEAR ENERGIES", (ftnlen)45)
	    ;
    e_wsfe();
    s_wsfe(&io___84);
    e_wsfe();
    s_wsfe(&io___85);
    e_wsfe();
    ij = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__6 = i__;
	for (j = 1; j <= i__6; ++j) {
	    ++ij;
	    if (i__ != j) {
		s_wsfe(&io___86);
		do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 1 << 
			1), (ftnlen)2);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[j - 1] - 1 << 1)
			, (ftnlen)2);
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&scrach_1.e[ij - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&ex[ij - 1], (ftnlen)sizeof(doublereal))
			;
		do_fio(&c__1, (char *)&scrach_1.e[ij + 21779], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&scrach_1.e[ij + 14519], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&scrach_1.e[ij + 7259], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&ex[ij + 14519], (ftnlen)sizeof(
			doublereal));
		d__1 = ex[ij + 7259] + ex[ij + 14519];
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else {
		if (i__ < 6 || i__ == molkst_1.numat) {
		    s_wsle(&io___87);
		    e_wsle();
		} else {
		    s_wsfe(&io___88);
		    e_wsfe();
		    s_wsfe(&io___89);
		    e_wsfe();
		}
	    }
/* L340: */
	}
    }

/*     ++++   TOTALS   ++++ */

    eabr = 0.;
    eabx = 0.;
    eabee = 0.;
    eaben = 0.;
    eabnn = 0.;
    i__6 = molkst_1.numat;
    for (i__ = 1; i__ <= i__6; ++i__) {
/* L350: */
	scrach_1.e[i__ * (i__ + 1) / 2 + 14519] = 0.;
    }
    i__6 = numat1;
    for (i__ = 1; i__ <= i__6; ++i__) {
	eabr += scrach_1.e[i__ - 1];
	eabx += ex[i__ - 1];
	eabee += scrach_1.e[i__ + 21779];
	eaben += scrach_1.e[i__ + 14519];
	eabnn += scrach_1.e[i__ + 7259];
/* L360: */
    }
    eabrx = eabr + eabx;
    eabe = eabee + eaben + eabnn;
    ttwo = eabrx + eabe;
    et = tone + ttwo;
/* @ *************************************************************** */
    s_wsfe(&io___99);
    e_wsfe();
    s_wsfe(&io___100);
    e_wsfe();
    s_wsfe(&io___101);
    e_wsfe();
    s_wsfe(&io___102);
    do_fio(&c__1, (char *)&eau, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___103);
    do_fio(&c__1, (char *)&eae, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___104);
    do_fio(&c__1, (char *)&tone, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___105);
    e_wsfe();
    s_wsfe(&io___106);
    e_wsfe();
    s_wsfe(&io___107);
    do_fio(&c__1, (char *)&eabr, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___108);
    do_fio(&c__1, (char *)&eabx, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___109);
    do_fio(&c__1, (char *)&eabrx, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___110);
    do_fio(&c__1, (char *)&eabee, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___111);
    do_fio(&c__1, (char *)&eaben, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___112);
    do_fio(&c__1, (char *)&eabnn, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___113);
    do_fio(&c__1, (char *)&eabe, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___114);
    do_fio(&c__1, (char *)&ttwo, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___115);
    e_wsfe();
    s_wsfe(&io___116);
    do_fio(&c__1, (char *)&et, (ftnlen)sizeof(doublereal));
    e_wsfe();
    return 0;
} /* enpart_ */

