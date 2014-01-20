/* fock2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    doublereal htype[4];
    integer nhco[80]	/* was [4][20] */, nnhco, itype;
} molmec_;

#define molmec_1 molmec_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal ptot2[1920]	/* was [120][16] */;
} work4_;

#define work4_1 work4_

struct {
    logical iseps, useps, upda;
} iseps_;

#define iseps_1 iseps_

/* Subroutine */ int fock2_(doublereal *f, doublereal *ptot, doublereal *p, 
	doublereal *w, doublereal *wj, doublereal *wk, integer *numat, 
	integer *nat, integer *nfirst, integer *nmidle, integer *nlast)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;

    /* Local variables */
    static doublereal a;
    static integer i__, j, k, l, m, i1, j1;
    static doublereal aa, bb;
    static integer ia, ib, ja, jb, jc, ka, kb, ii, ij, ji, ik, ki, kl, lk, jl,
	     lj;
    static doublereal pk[16];
    static integer kk, jk, kj, jj, ll, kc, il;
    static doublereal aj, ak;
    static integer kr, im1;
    extern /* Subroutine */ int jab_(integer *, integer *, integer *, integer 
	    *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), kab_(integer *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *);
    static logical lid;
    static doublereal pja[16], pjb[16], sum;
    static integer ione, ifact[300];
    static doublereal elexc, elrep;
    static integer i1fact[300];
    extern /* Subroutine */ int addfck_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);
    static integer jindex[256], kindex[256], jjndex[256];
    static doublereal sumdia;
    static integer ijperm[10], llperm[10], mmperm[10];
    static doublereal sumoff;
    static integer iminus;

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

/* FOCK2 FORMS THE TWO-ELECTRON TWO-CENTER REPULSION PART OF THE FOCK */
/* MATRIX */
/* ON INPUT  PTOT = TOTAL DENSITY MATRIX. */
/*           P    = ALPHA OR BETA DENSITY MATRIX. */
/*           W    = TWO-ELECTRON INTEGRAL MATRIX. */

/*  ON OUTPUT F   = PARTIAL FOCK MATRIX */
/* *********************************************************************** */
/* COSMO change */
/* end of COSMO change */
    /* Parameter adjustments */
    --nlast;
    --nmidle;
    --nfirst;
    --nat;
    --wk;
    --wj;
    --w;
    --p;
    --ptot;
    --f;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;

/*   SET UP ARRAY OF LOWER HALF TRIANGLE INDICES (PASCAL'S TRIANGLE) */

	for (i__ = 1; i__ <= 300; ++i__) {
	    ifact[i__ - 1] = i__ * (i__ - 1) / 2;
/* L10: */
	    i1fact[i__ - 1] = ifact[i__ - 1] + i__;
	}

/*   SET UP GATHER-SCATTER TYPE ARRAYS FOR USE WITH TWO-ELECTRON */
/*   INTEGRALS.  JINDEX ARE THE INDICES OF THE J-INTEGRALS FOR ATOM I */
/*   INTEGRALS.  JJNDEX ARE THE INDICES OF THE J-INTEGRALS FOR ATOM J */
/*               KINDEX ARE THE INDICES OF THE K-INTEGRALS */

	m = 0;
	for (i__ = 1; i__ <= 4; ++i__) {
	    for (j = 1; j <= 4; ++j) {
		ij = min(i__,j);
		ji = i__ + j - ij;
		for (k = 1; k <= 4; ++k) {
		    ik = min(i__,k);
		    ki = i__ + k - ik;
		    for (l = 1; l <= 4; ++l) {
			++m;
			kl = min(k,l);
			lk = k + l - kl;
			jl = min(j,l);
			lj = j + l - jl;
			kindex[m - 1] = ifact[lj - 1] + jl + (ifact[ki - 1] + 
				ik) * 10 - 10;
/* L20: */
			jindex[m - 1] = (ifact[ji - 1] + ij) * 10 + ifact[lk 
				- 1] + kl - 10;
		    }
		}
	    }
	}
	l = 0;
	for (i__ = 1; i__ <= 4; ++i__) {
	    i1 = i__ - 1 << 2;
	    i__1 = i__;
	    for (j = 1; j <= i__1; ++j) {
		++i1;
		++l;
		ijperm[l - 1] = i1;
		mmperm[l - 1] = ijperm[l - 1] - 16;
		llperm[l - 1] = i1 - 1 << 4;
/* L30: */
	    }
	}
	l = 0;
	for (i__ = 1; i__ <= 10; ++i__) {
	    m = mmperm[i__ - 1];
	    l = llperm[i__ - 1];
	    for (k = 1; k <= 16; ++k) {
		++l;
		m += 16;
/* L40: */
		jjndex[l - 1] = jindex[m - 1];
	    }
	}
	lid = euler_1.id == 0;
	ione = 1;
	if (euler_1.id != 0) {
	    ione = 0;
	}

/*      END OF INITIALIZATION */

    }
    if (molmec_1.itype == 4) {
	goto L200;
    }

/*     START OF MNDO, AM1, OR PM3 OPTION */

    kk = 0;
    l = 0;
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = nfirst[i__];
	ib = nlast[i__];
	m = 0;
	i__2 = ib;
	for (j = ia; j <= i__2; ++j) {
	    i__3 = ib;
	    for (k = ia; k <= i__3; ++k) {
		++m;
		jk = min(j,k);
		kj = k + j - jk;
		jk += kj * (kj - 1) / 2;
		work4_1.ptot2[i__ + m * 120 - 121] = ptot[jk];
/* L50: */
	    }
	}
/* L60: */
    }
    i__1 = *numat;
    for (ii = 1; ii <= i__1; ++ii) {
	ia = nfirst[ii];
	ib = nlast[ii];

/*  IF NUMAT=2 THEN WE ARE IN A DERIVATIVE OR IN A MOLECULE CALCULATION */

	if (*numat != 2) {
	    iminus = ii - ione;
	} else {
	    iminus = ii - 1;
	}
	i__3 = iminus;
	for (jj = 1; jj <= i__3; ++jj) {
	    ja = nfirst[jj];
	    jb = nlast[jj];
	    jc = nmidle[jj];
	    if (lid) {
		if (ib - ia >= 3 && jb - ja >= 3) {

/*                         HEAVY-ATOM  - HEAVY-ATOM */

/*   EXTRACT COULOMB TERMS */

		    for (i__ = 1; i__ <= 16; ++i__) {
			pja[i__ - 1] = work4_1.ptot2[ii + i__ * 120 - 121];
/* L70: */
			pjb[i__ - 1] = work4_1.ptot2[jj + i__ * 120 - 121];
		    }

/*  COULOMB TERMS */

		    jab_(&ia, &ja, llperm, jindex, jjndex, pja, pjb, &w[kk + 
			    1], &f[1]);

/*  EXCHANGE TERMS */


/*  EXTRACT INTERSECTION OF ATOMS II AND JJ IN THE SPIN DENSITY MATRIX */

		    l = 0;
		    i__2 = ib;
		    for (i__ = ia; i__ <= i__2; ++i__) {
			i1 = ifact[i__ - 1] + ja;
			i__4 = i1 + 3;
			for (j = i1; j <= i__4; ++j) {
			    ++l;
/* L80: */
			    pk[l - 1] = p[j];
			}
		    }
		    kab_(&ia, &ja, pk, &w[kk + 1], kindex, &f[1]);
		    kk += 100;
		} else if (ib - ia >= 3 && ja == jb) {

/*                         LIGHT-ATOM  - HEAVY-ATOM */


/*   COULOMB TERMS */

		    sumdia = 0.;
		    sumoff = 0.;
		    ll = i1fact[ja - 1];
		    k = 0;
		    for (i__ = 0; i__ <= 3; ++i__) {
			j1 = ifact[ia + i__ - 1] + ia - 1;
			i__4 = i__ - 1;
			for (j = 0; j <= i__4; ++j) {
			    ++k;
			    ++j1;
			    f[j1] += ptot[ll] * w[kk + k];
/* L90: */
			    sumoff += ptot[j1] * w[kk + k];
			}
			++j1;
			++k;
			f[j1] += ptot[ll] * w[kk + k];
/* L100: */
			sumdia += ptot[j1] * w[kk + k];
		    }
		    f[ll] = f[ll] + sumoff * 2. + sumdia;

/*  EXCHANGE TERMS */


/*  EXTRACT INTERSECTION OF ATOMS II AND JJ IN THE SPIN DENSITY MATRIX */

		    k = 0;
		    i__4 = ib;
		    for (i__ = ia; i__ <= i__4; ++i__) {
			i1 = ifact[i__ - 1] + ja;
			sum = 0.;
			i__2 = ib;
			for (j = ia; j <= i__2; ++j) {
			    ++k;
			    j1 = ifact[j - 1] + ja;
/* L110: */
			    sum += p[j1] * w[kk + jindex[k - 1]];
			}
/* L120: */
			f[i1] -= sum;
		    }
		    kk += 10;
		} else if (jb - ja >= 3 && ia == ib) {

/*                         HEAVY-ATOM - LIGHT-ATOM */


/*   COULOMB TERMS */

		    sumdia = 0.;
		    sumoff = 0.;
		    ll = i1fact[ia - 1];
		    k = 0;
		    for (i__ = 0; i__ <= 3; ++i__) {
			j1 = ifact[ja + i__ - 1] + ja - 1;
			i__4 = i__ - 1;
			for (j = 0; j <= i__4; ++j) {
			    ++k;
			    ++j1;
			    f[j1] += ptot[ll] * w[kk + k];
/* L130: */
			    sumoff += ptot[j1] * w[kk + k];
			}
			++j1;
			++k;
			f[j1] += ptot[ll] * w[kk + k];
/* L140: */
			sumdia += ptot[j1] * w[kk + k];
		    }
		    f[ll] = f[ll] + sumoff * 2. + sumdia;

/*  EXCHANGE TERMS */


/*  EXTRACT INTERSECTION OF ATOMS II AND JJ IN THE SPIN DENSITY MATRIX */

		    k = ifact[ia - 1] + ja;
		    j = 0;
		    i__4 = k + 3;
		    for (i__ = k; i__ <= i__4; ++i__) {
			sum = 0.;
			i__2 = k + 3;
			for (l = k; l <= i__2; ++l) {
			    ++j;
/* L150: */
			    sum += p[l] * w[kk + jindex[j - 1]];
			}
/* L160: */
			f[i__] -= sum;
		    }
		    kk += 10;
		} else if (jb == ja && ia == ib) {

/*                         LIGHT-ATOM - LIGHT-ATOM */

		    i1 = i1fact[ia - 1];
		    j1 = i1fact[ja - 1];
		    ij = i1 + ja - ia;
		    f[i1] += ptot[j1] * w[kk + 1];
		    f[j1] += ptot[i1] * w[kk + 1];
		    f[ij] -= p[ij] * w[kk + 1];
		    ++kk;
		}
	    } else {
		i__4 = ib;
		for (i__ = ia; i__ <= i__4; ++i__) {
		    ka = ifact[i__ - 1];
		    i__2 = i__;
		    for (j = ia; j <= i__2; ++j) {
			kb = ifact[j - 1];
			ij = ka + j;
			aa = 2.;
			if (i__ == j) {
			    aa = 1.;
			}
			i__5 = jc;
			for (k = ja; k <= i__5; ++k) {
			    kc = ifact[k - 1];
			    if (i__ >= k) {
				ik = ka + k;
			    } else {
				ik = 0;
			    }
			    if (j >= k) {
				jk = kb + k;
			    } else {
				jk = 0;
			    }
			    i__6 = k;
			    for (l = ja; l <= i__6; ++l) {
				if (i__ >= l) {
				    il = ka + l;
				} else {
				    il = 0;
				}
				if (j >= l) {
				    jl = kb + l;
				} else {
				    jl = 0;
				}
				kl = kc + l;
				bb = 2.;
				if (k == l) {
				    bb = 1.;
				}
				++kk;
				aj = wj[kk];
				ak = wk[kk];

/*     A  IS THE REPULSION INTEGRAL (I,J/K,L) WHERE ORBITALS I AND J ARE */
/*     ON ATOM II, AND ORBITALS K AND L ARE ON ATOM JJ. */
/*     AA AND BB ARE CORRECTION FACTORS SINCE */
/*     (I,J/K,L)=(J,I/K,L)=(I,J/L,K)=(J,I/L,K) */
/*     IJ IS THE LOCATION OF THE MATRIX ELEMENTS BETWEEN ATOMIC ORBITALS */
/*     I AND J.  SIMILARLY FOR IK ETC. */

/* THIS FORMS THE TWO-ELECTRON TWO-CENTER REPULSION PART OF THE FOCK */
/* MATRIX.  THE CODE HERE IS HARD TO FOLLOW, AND IMPOSSIBLE TO MODIFY!, */
/* BUT IT WORKS, */
				if (kl <= ij) {
				    if (i__ == k && aa + bb < 2.1) {
					bb *= .5;
					aa *= .5;
					f[ij] += bb * aj * ptot[kl];
					f[kl] += aa * aj * ptot[ij];
				    } else {
					f[ij] += bb * aj * ptot[kl];
					f[kl] += aa * aj * ptot[ij];
					a = ak * aa * bb * .25;
					f[ik] -= a * p[jl];
					f[il] -= a * p[jk];
					f[jk] -= a * p[il];
					f[jl] -= a * p[ik];
				    }
				}
/* L170: */
			    }
			}
		    }
		}
	    }
/* L180: */
	}
/* L190: */
    }
/* COSMO change */
/* The following routine adds the dielectric corretion to F */
    if (iseps_1.useps) {
	addfck_(&f[1], &p[1], numat, &nat[1], &nfirst[1], &nlast[1]);
    }
/* A. Klamt 18.7.91 */
/* end of COSMO change */
    return 0;

/*                    START OF MINDO/3 OPTION */

L200:
    kr = 0;
    i__1 = *numat;
    for (ii = 1; ii <= i__1; ++ii) {
	ia = nfirst[ii];
	ib = nlast[ii];
	im1 = ii - ione;
	i__3 = im1;
	for (jj = 1; jj <= i__3; ++jj) {
	    ++kr;
	    if (lid) {
		elrep = w[kr];
		elexc = elrep;
	    } else {
		elrep = wj[kr];
		elexc = wk[kr];
	    }
	    ja = nfirst[jj];
	    jb = nlast[jj];
	    i__6 = ib;
	    for (i__ = ia; i__ <= i__6; ++i__) {
		ka = ifact[i__ - 1];
		kk = ka + i__;
		i__5 = jb;
		for (k = ja; k <= i__5; ++k) {
		    ll = i1fact[k - 1];
		    ik = ka + k;
		    f[kk] += ptot[ll] * elrep;
		    f[ll] += ptot[kk] * elrep;
/* L210: */
		    f[ik] -= p[ik] * elexc;
		}
	    }
/* L220: */
	}
/* L230: */
    }
    return 0;
} /* fock2_ */

/* Subroutine */ int jab_(integer *ia, integer *ja, integer *llperm, integer *
	jindex, integer *jjndex, doublereal *pja, doublereal *pjb, doublereal 
	*w, doublereal *f)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, i5, i6, iia, ija, ioff, joff;
    static doublereal suma[10], sumb[10];


/*  FOR VECTOR MACHINES, REMOVE THE ARRAYS  SUMA AND SUMB, UNCOMMENT */
/*  THE LINES MARKED CVECTOR, AND COMMENT OUT THE SECOND WHOLE PART */
/*  OF THE SUBROUTINE */
/* VECTOR                  I=0 */
/* VECTOR                  DO 100 I5=1,4 */
/* VECTOR                  IIA=IA+I5-1 */
/* VECTOR                  IJA=JA+I5-1 */
/* VECTOR                  IOFF=(IIA*(IIA-1))/2+IA-1 */
/* VECTOR                  JOFF=(IJA*(IJA-1))/2+JA-1 */
/* VECTOR                  DO 100 I6=1,I5 */
/* VECTOR                  IOFF=IOFF+1 */
/* VECTOR                  JOFF=JOFF+1 */
/* VECTOR                        I=I+1 */
/* VECTOR                        L=LLPERM(I) */
/* VECTOR                        SUMA=0 */
/* VECTOR                        SUMB=0 */
/* VECTOR                        DO 90 K=1,16 */
/* VECTOR                           L=L+1 */
/* VECTOR                           SUMB=SUMB+PJA(K)*W(JJNDEX(L)) */
/* VECTOR   90                   SUMA=SUMA+PJB(K)*W(JINDEX(L)) */
/* VECTOR                        F(IOFF)=F(IOFF)+SUMA */
/* VECTOR  100             F(JOFF)=F(JOFF)+SUMB */
    /* Parameter adjustments */
    --f;
    --w;
    --pjb;
    --pja;
    --jjndex;
    --jindex;
    --llperm;

    /* Function Body */
    suma[0] = pja[1] * w[1] + pja[2] * w[11] + pja[3] * w[31] + pja[4] * w[61]
	     + pja[5] * w[11] + pja[6] * w[21] + pja[7] * w[41] + pja[8] * w[
	    71] + pja[9] * w[31] + pja[10] * w[41] + pja[11] * w[51] + pja[12]
	     * w[81] + pja[13] * w[61] + pja[14] * w[71] + pja[15] * w[81] + 
	    pja[16] * w[91];
    suma[1] = pja[1] * w[2] + pja[2] * w[12] + pja[3] * w[32] + pja[4] * w[62]
	     + pja[5] * w[12] + pja[6] * w[22] + pja[7] * w[42] + pja[8] * w[
	    72] + pja[9] * w[32] + pja[10] * w[42] + pja[11] * w[52] + pja[12]
	     * w[82] + pja[13] * w[62] + pja[14] * w[72] + pja[15] * w[82] + 
	    pja[16] * w[92];
    suma[2] = pja[1] * w[3] + pja[2] * w[13] + pja[3] * w[33] + pja[4] * w[63]
	     + pja[5] * w[13] + pja[6] * w[23] + pja[7] * w[43] + pja[8] * w[
	    73] + pja[9] * w[33] + pja[10] * w[43] + pja[11] * w[53] + pja[12]
	     * w[83] + pja[13] * w[63] + pja[14] * w[73] + pja[15] * w[83] + 
	    pja[16] * w[93];
    suma[3] = pja[1] * w[4] + pja[2] * w[14] + pja[3] * w[34] + pja[4] * w[64]
	     + pja[5] * w[14] + pja[6] * w[24] + pja[7] * w[44] + pja[8] * w[
	    74] + pja[9] * w[34] + pja[10] * w[44] + pja[11] * w[54] + pja[12]
	     * w[84] + pja[13] * w[64] + pja[14] * w[74] + pja[15] * w[84] + 
	    pja[16] * w[94];
    suma[4] = pja[1] * w[5] + pja[2] * w[15] + pja[3] * w[35] + pja[4] * w[65]
	     + pja[5] * w[15] + pja[6] * w[25] + pja[7] * w[45] + pja[8] * w[
	    75] + pja[9] * w[35] + pja[10] * w[45] + pja[11] * w[55] + pja[12]
	     * w[85] + pja[13] * w[65] + pja[14] * w[75] + pja[15] * w[85] + 
	    pja[16] * w[95];
    suma[5] = pja[1] * w[6] + pja[2] * w[16] + pja[3] * w[36] + pja[4] * w[66]
	     + pja[5] * w[16] + pja[6] * w[26] + pja[7] * w[46] + pja[8] * w[
	    76] + pja[9] * w[36] + pja[10] * w[46] + pja[11] * w[56] + pja[12]
	     * w[86] + pja[13] * w[66] + pja[14] * w[76] + pja[15] * w[86] + 
	    pja[16] * w[96];
    suma[6] = pja[1] * w[7] + pja[2] * w[17] + pja[3] * w[37] + pja[4] * w[67]
	     + pja[5] * w[17] + pja[6] * w[27] + pja[7] * w[47] + pja[8] * w[
	    77] + pja[9] * w[37] + pja[10] * w[47] + pja[11] * w[57] + pja[12]
	     * w[87] + pja[13] * w[67] + pja[14] * w[77] + pja[15] * w[87] + 
	    pja[16] * w[97];
    suma[7] = pja[1] * w[8] + pja[2] * w[18] + pja[3] * w[38] + pja[4] * w[68]
	     + pja[5] * w[18] + pja[6] * w[28] + pja[7] * w[48] + pja[8] * w[
	    78] + pja[9] * w[38] + pja[10] * w[48] + pja[11] * w[58] + pja[12]
	     * w[88] + pja[13] * w[68] + pja[14] * w[78] + pja[15] * w[88] + 
	    pja[16] * w[98];
    suma[8] = pja[1] * w[9] + pja[2] * w[19] + pja[3] * w[39] + pja[4] * w[69]
	     + pja[5] * w[19] + pja[6] * w[29] + pja[7] * w[49] + pja[8] * w[
	    79] + pja[9] * w[39] + pja[10] * w[49] + pja[11] * w[59] + pja[12]
	     * w[89] + pja[13] * w[69] + pja[14] * w[79] + pja[15] * w[89] + 
	    pja[16] * w[99];
    suma[9] = pja[1] * w[10] + pja[2] * w[20] + pja[3] * w[40] + pja[4] * w[
	    70] + pja[5] * w[20] + pja[6] * w[30] + pja[7] * w[50] + pja[8] * 
	    w[80] + pja[9] * w[40] + pja[10] * w[50] + pja[11] * w[60] + pja[
	    12] * w[90] + pja[13] * w[70] + pja[14] * w[80] + pja[15] * w[90] 
	    + pja[16] * w[100];
    sumb[0] = pjb[1] * w[1] + pjb[2] * w[2] + pjb[3] * w[4] + pjb[4] * w[7] + 
	    pjb[5] * w[2] + pjb[6] * w[3] + pjb[7] * w[5] + pjb[8] * w[8] + 
	    pjb[9] * w[4] + pjb[10] * w[5] + pjb[11] * w[6] + pjb[12] * w[9] 
	    + pjb[13] * w[7] + pjb[14] * w[8] + pjb[15] * w[9] + pjb[16] * w[
	    10];
    sumb[1] = pjb[1] * w[11] + pjb[2] * w[12] + pjb[3] * w[14] + pjb[4] * w[
	    17] + pjb[5] * w[12] + pjb[6] * w[13] + pjb[7] * w[15] + pjb[8] * 
	    w[18] + pjb[9] * w[14] + pjb[10] * w[15] + pjb[11] * w[16] + pjb[
	    12] * w[19] + pjb[13] * w[17] + pjb[14] * w[18] + pjb[15] * w[19] 
	    + pjb[16] * w[20];
    sumb[2] = pjb[1] * w[21] + pjb[2] * w[22] + pjb[3] * w[24] + pjb[4] * w[
	    27] + pjb[5] * w[22] + pjb[6] * w[23] + pjb[7] * w[25] + pjb[8] * 
	    w[28] + pjb[9] * w[24] + pjb[10] * w[25] + pjb[11] * w[26] + pjb[
	    12] * w[29] + pjb[13] * w[27] + pjb[14] * w[28] + pjb[15] * w[29] 
	    + pjb[16] * w[30];
    sumb[3] = pjb[1] * w[31] + pjb[2] * w[32] + pjb[3] * w[34] + pjb[4] * w[
	    37] + pjb[5] * w[32] + pjb[6] * w[33] + pjb[7] * w[35] + pjb[8] * 
	    w[38] + pjb[9] * w[34] + pjb[10] * w[35] + pjb[11] * w[36] + pjb[
	    12] * w[39] + pjb[13] * w[37] + pjb[14] * w[38] + pjb[15] * w[39] 
	    + pjb[16] * w[40];
    sumb[4] = pjb[1] * w[41] + pjb[2] * w[42] + pjb[3] * w[44] + pjb[4] * w[
	    47] + pjb[5] * w[42] + pjb[6] * w[43] + pjb[7] * w[45] + pjb[8] * 
	    w[48] + pjb[9] * w[44] + pjb[10] * w[45] + pjb[11] * w[46] + pjb[
	    12] * w[49] + pjb[13] * w[47] + pjb[14] * w[48] + pjb[15] * w[49] 
	    + pjb[16] * w[50];
    sumb[5] = pjb[1] * w[51] + pjb[2] * w[52] + pjb[3] * w[54] + pjb[4] * w[
	    57] + pjb[5] * w[52] + pjb[6] * w[53] + pjb[7] * w[55] + pjb[8] * 
	    w[58] + pjb[9] * w[54] + pjb[10] * w[55] + pjb[11] * w[56] + pjb[
	    12] * w[59] + pjb[13] * w[57] + pjb[14] * w[58] + pjb[15] * w[59] 
	    + pjb[16] * w[60];
    sumb[6] = pjb[1] * w[61] + pjb[2] * w[62] + pjb[3] * w[64] + pjb[4] * w[
	    67] + pjb[5] * w[62] + pjb[6] * w[63] + pjb[7] * w[65] + pjb[8] * 
	    w[68] + pjb[9] * w[64] + pjb[10] * w[65] + pjb[11] * w[66] + pjb[
	    12] * w[69] + pjb[13] * w[67] + pjb[14] * w[68] + pjb[15] * w[69] 
	    + pjb[16] * w[70];
    sumb[7] = pjb[1] * w[71] + pjb[2] * w[72] + pjb[3] * w[74] + pjb[4] * w[
	    77] + pjb[5] * w[72] + pjb[6] * w[73] + pjb[7] * w[75] + pjb[8] * 
	    w[78] + pjb[9] * w[74] + pjb[10] * w[75] + pjb[11] * w[76] + pjb[
	    12] * w[79] + pjb[13] * w[77] + pjb[14] * w[78] + pjb[15] * w[79] 
	    + pjb[16] * w[80];
    sumb[8] = pjb[1] * w[81] + pjb[2] * w[82] + pjb[3] * w[84] + pjb[4] * w[
	    87] + pjb[5] * w[82] + pjb[6] * w[83] + pjb[7] * w[85] + pjb[8] * 
	    w[88] + pjb[9] * w[84] + pjb[10] * w[85] + pjb[11] * w[86] + pjb[
	    12] * w[89] + pjb[13] * w[87] + pjb[14] * w[88] + pjb[15] * w[89] 
	    + pjb[16] * w[90];
    sumb[9] = pjb[1] * w[91] + pjb[2] * w[92] + pjb[3] * w[94] + pjb[4] * w[
	    97] + pjb[5] * w[92] + pjb[6] * w[93] + pjb[7] * w[95] + pjb[8] * 
	    w[98] + pjb[9] * w[94] + pjb[10] * w[95] + pjb[11] * w[96] + pjb[
	    12] * w[99] + pjb[13] * w[97] + pjb[14] * w[98] + pjb[15] * w[99] 
	    + pjb[16] * w[100];
    i__ = 0;
    for (i5 = 1; i5 <= 4; ++i5) {
	iia = *ia + i5 - 1;
	ija = *ja + i5 - 1;
	ioff = iia * (iia - 1) / 2 + *ia - 1;
	joff = ija * (ija - 1) / 2 + *ja - 1;
	i__1 = i5;
	for (i6 = 1; i6 <= i__1; ++i6) {
	    ++ioff;
	    ++joff;
	    ++i__;
	    f[ioff] += sumb[i__ - 1];
/* L10: */
	    f[joff] += suma[i__ - 1];
	}
    }
    return 0;
} /* jab_ */

/* Subroutine */ int kab_(integer *ia, integer *ja, doublereal *pk, 
	doublereal *w, integer *kindex, doublereal *f)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Local variables */
    static integer j, m, j1, j2, j3;
    static doublereal sum[16];


/*  FOR VECTOR MACHINES, REMOVE THE ARRAY SUM, UNCOMMENT THE LINES */
/*  MARKED CVECTOR, AND COMMENT OUT THE SECOND WHOLE PART OF THE */
/*  SUBROUTINE */

/* VECTOR                  L=0 */
/* VECTOR                  M=0 */
/* VECTOR                  DO 130 J1=IA,IA+3 */
/* VECTOR                  J=(J1*(J1-1))/2 */
/* VECTOR                  DO 130 J2=JA,JA+3 */
/* VECTOR                  M=M+1 */
/* VECTOR                  IF(IA.GT.JA)THEN */
/* VECTOR                  J3=J+J2 */
/* VECTOR                  ELSE */
/* VECTOR                  J3=J1+(J2*(J2-1))/2 */
/* VECTOR                  ENDIF */
/* VECTOR                     SUM=0 */
/* VECTOR                     DO 120 I=1,16 */
/* VECTOR                        L=L+1 */
/* VECTOR  120                SUM=SUM+PK(I)*W(KINDEX(L)) */
/* VECTOR  130             F(J3)=F(J3)-SUM */
    /* Parameter adjustments */
    --f;
    --kindex;
    --w;
    --pk;

    /* Function Body */
    sum[0] = pk[1] * w[1] + pk[2] * w[2] + pk[3] * w[4] + pk[4] * w[7] + pk[5]
	     * w[11] + pk[6] * w[12] + pk[7] * w[14] + pk[8] * w[17] + pk[9] *
	     w[31] + pk[10] * w[32] + pk[11] * w[34] + pk[12] * w[37] + pk[13]
	     * w[61] + pk[14] * w[62] + pk[15] * w[64] + pk[16] * w[67];
    sum[1] = pk[1] * w[2] + pk[2] * w[3] + pk[3] * w[5] + pk[4] * w[8] + pk[5]
	     * w[12] + pk[6] * w[13] + pk[7] * w[15] + pk[8] * w[18] + pk[9] *
	     w[32] + pk[10] * w[33] + pk[11] * w[35] + pk[12] * w[38] + pk[13]
	     * w[62] + pk[14] * w[63] + pk[15] * w[65] + pk[16] * w[68];
    sum[2] = pk[1] * w[4] + pk[2] * w[5] + pk[3] * w[6] + pk[4] * w[9] + pk[5]
	     * w[14] + pk[6] * w[15] + pk[7] * w[16] + pk[8] * w[19] + pk[9] *
	     w[34] + pk[10] * w[35] + pk[11] * w[36] + pk[12] * w[39] + pk[13]
	     * w[64] + pk[14] * w[65] + pk[15] * w[66] + pk[16] * w[69];
    sum[3] = pk[1] * w[7] + pk[2] * w[8] + pk[3] * w[9] + pk[4] * w[10] + pk[
	    5] * w[17] + pk[6] * w[18] + pk[7] * w[19] + pk[8] * w[20] + pk[9]
	     * w[37] + pk[10] * w[38] + pk[11] * w[39] + pk[12] * w[40] + pk[
	    13] * w[67] + pk[14] * w[68] + pk[15] * w[69] + pk[16] * w[70];
    sum[4] = pk[1] * w[11] + pk[2] * w[12] + pk[3] * w[14] + pk[4] * w[17] + 
	    pk[5] * w[21] + pk[6] * w[22] + pk[7] * w[24] + pk[8] * w[27] + 
	    pk[9] * w[41] + pk[10] * w[42] + pk[11] * w[44] + pk[12] * w[47] 
	    + pk[13] * w[71] + pk[14] * w[72] + pk[15] * w[74] + pk[16] * w[
	    77];
    sum[5] = pk[1] * w[12] + pk[2] * w[13] + pk[3] * w[15] + pk[4] * w[18] + 
	    pk[5] * w[22] + pk[6] * w[23] + pk[7] * w[25] + pk[8] * w[28] + 
	    pk[9] * w[42] + pk[10] * w[43] + pk[11] * w[45] + pk[12] * w[48] 
	    + pk[13] * w[72] + pk[14] * w[73] + pk[15] * w[75] + pk[16] * w[
	    78];
    sum[6] = pk[1] * w[14] + pk[2] * w[15] + pk[3] * w[16] + pk[4] * w[19] + 
	    pk[5] * w[24] + pk[6] * w[25] + pk[7] * w[26] + pk[8] * w[29] + 
	    pk[9] * w[44] + pk[10] * w[45] + pk[11] * w[46] + pk[12] * w[49] 
	    + pk[13] * w[74] + pk[14] * w[75] + pk[15] * w[76] + pk[16] * w[
	    79];
    sum[7] = pk[1] * w[17] + pk[2] * w[18] + pk[3] * w[19] + pk[4] * w[20] + 
	    pk[5] * w[27] + pk[6] * w[28] + pk[7] * w[29] + pk[8] * w[30] + 
	    pk[9] * w[47] + pk[10] * w[48] + pk[11] * w[49] + pk[12] * w[50] 
	    + pk[13] * w[77] + pk[14] * w[78] + pk[15] * w[79] + pk[16] * w[
	    80];
    sum[8] = pk[1] * w[31] + pk[2] * w[32] + pk[3] * w[34] + pk[4] * w[37] + 
	    pk[5] * w[41] + pk[6] * w[42] + pk[7] * w[44] + pk[8] * w[47] + 
	    pk[9] * w[51] + pk[10] * w[52] + pk[11] * w[54] + pk[12] * w[57] 
	    + pk[13] * w[81] + pk[14] * w[82] + pk[15] * w[84] + pk[16] * w[
	    87];
    sum[9] = pk[1] * w[32] + pk[2] * w[33] + pk[3] * w[35] + pk[4] * w[38] + 
	    pk[5] * w[42] + pk[6] * w[43] + pk[7] * w[45] + pk[8] * w[48] + 
	    pk[9] * w[52] + pk[10] * w[53] + pk[11] * w[55] + pk[12] * w[58] 
	    + pk[13] * w[82] + pk[14] * w[83] + pk[15] * w[85] + pk[16] * w[
	    88];
    sum[10] = pk[1] * w[34] + pk[2] * w[35] + pk[3] * w[36] + pk[4] * w[39] + 
	    pk[5] * w[44] + pk[6] * w[45] + pk[7] * w[46] + pk[8] * w[49] + 
	    pk[9] * w[54] + pk[10] * w[55] + pk[11] * w[56] + pk[12] * w[59] 
	    + pk[13] * w[84] + pk[14] * w[85] + pk[15] * w[86] + pk[16] * w[
	    89];
    sum[11] = pk[1] * w[37] + pk[2] * w[38] + pk[3] * w[39] + pk[4] * w[40] + 
	    pk[5] * w[47] + pk[6] * w[48] + pk[7] * w[49] + pk[8] * w[50] + 
	    pk[9] * w[57] + pk[10] * w[58] + pk[11] * w[59] + pk[12] * w[60] 
	    + pk[13] * w[87] + pk[14] * w[88] + pk[15] * w[89] + pk[16] * w[
	    90];
    sum[12] = pk[1] * w[61] + pk[2] * w[62] + pk[3] * w[64] + pk[4] * w[67] + 
	    pk[5] * w[71] + pk[6] * w[72] + pk[7] * w[74] + pk[8] * w[77] + 
	    pk[9] * w[81] + pk[10] * w[82] + pk[11] * w[84] + pk[12] * w[87] 
	    + pk[13] * w[91] + pk[14] * w[92] + pk[15] * w[94] + pk[16] * w[
	    97];
    sum[13] = pk[1] * w[62] + pk[2] * w[63] + pk[3] * w[65] + pk[4] * w[68] + 
	    pk[5] * w[72] + pk[6] * w[73] + pk[7] * w[75] + pk[8] * w[78] + 
	    pk[9] * w[82] + pk[10] * w[83] + pk[11] * w[85] + pk[12] * w[88] 
	    + pk[13] * w[92] + pk[14] * w[93] + pk[15] * w[95] + pk[16] * w[
	    98];
    sum[14] = pk[1] * w[64] + pk[2] * w[65] + pk[3] * w[66] + pk[4] * w[69] + 
	    pk[5] * w[74] + pk[6] * w[75] + pk[7] * w[76] + pk[8] * w[79] + 
	    pk[9] * w[84] + pk[10] * w[85] + pk[11] * w[86] + pk[12] * w[89] 
	    + pk[13] * w[94] + pk[14] * w[95] + pk[15] * w[96] + pk[16] * w[
	    99];
    sum[15] = pk[1] * w[67] + pk[2] * w[68] + pk[3] * w[69] + pk[4] * w[70] + 
	    pk[5] * w[77] + pk[6] * w[78] + pk[7] * w[79] + pk[8] * w[80] + 
	    pk[9] * w[87] + pk[10] * w[88] + pk[11] * w[89] + pk[12] * w[90] 
	    + pk[13] * w[97] + pk[14] * w[98] + pk[15] * w[99] + pk[16] * w[
	    100];
    if (*ia > *ja) {
	m = 0;
	i__1 = *ia + 3;
	for (j1 = *ia; j1 <= i__1; ++j1) {
	    j = j1 * (j1 - 1) / 2;
	    i__2 = *ja + 3;
	    for (j2 = *ja; j2 <= i__2; ++j2) {
		++m;
		j3 = j + j2;
/* L10: */
		f[j3] -= sum[m - 1];
	    }
	}
    } else {

/*   IA IS LESS THAN JA, THEREFORE USE OTHER HALF OF TRIANGLE */

	m = 0;
	i__2 = *ia + 3;
	for (j1 = *ia; j1 <= i__2; ++j1) {
	    i__1 = *ja + 3;
	    for (j2 = *ja; j2 <= i__1; ++j2) {
		++m;
		j3 = j2 * (j2 - 1) / 2 + j1;
/* L20: */
		f[j3] -= sum[m - 1];
	    }
	}
    }
    return 0;
} /* kab_ */

