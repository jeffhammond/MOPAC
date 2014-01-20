/* dfock2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal ptot2[1920]	/* was [120][16] */;
} work4_;

#define work4_1 work4_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Subroutine */ int dfock2_(doublereal *f, doublereal *ptot, doublereal *p, 
	doublereal *w, integer *numat, integer *nfirst, integer *nmidle, 
	integer *nlast, integer *nati)
{
    /* Initialized data */

    static integer itype = 1;
    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, i1, j1, ia, ib, ja, jb, ka, ii, ij, ji, 
	    ik, ki, kl, lk, jl, lj;
    static doublereal pk[16];
    static integer kk, jk, kj, jj, ll, kr;
    extern /* Subroutine */ int jab_(integer *, integer *, integer *, integer 
	    *, integer *, doublereal *, doublereal *, doublereal *, 
	    doublereal *), kab_(integer *, integer *, doublereal *, 
	    doublereal *, integer *, doublereal *);
    static doublereal pja[16], pjb[16], sum;
    static integer ifact[300];
    static doublereal elrep;
    static integer i1fact[300], jindex[256], kindex[256], jjndex[256];
    static doublereal sumdia;
    static integer ijperm[10], llperm[10], mmperm[10];
    static doublereal sumoff;

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

/*     DFOCK2 ADDS THE 2-ELECTRON 2-CENTER REPULSION CONTRIBUTION TO */
/*     THE FOCK MATRIX DERIVATIVE WITHIN THE NDDO OR MINDO FORMALISMS. */
/*  INPUT */
/*     F    : 1-ELECTRON CONTRIBUTIONS DERIVATIVES. */
/*     PTOT : TOTAL DENSITY MATRIX. */
/*     P    : ALPHA OR BETA DENSITY MATRIX. = 0.5 * PTOT */
/*     W    : NON VANISHING TWO-ELECTRON INTEGRAL DERIVATIVES */
/*            (ORDERED AS DEFINED IN DHCORE). */
/*     NATI : # OF THE ATOM SUPPORTING THE VARYING CARTESIAN COORDINATE. */
/*  OUTPUT */
/*     F    : FOCK MATRIX DERIVATIVE WITH RESPECT TO THE CART. COORD. */

/* *********************************************************************** */
    /* Parameter adjustments */
    --nlast;
    --nmidle;
    --nfirst;
    --w;
    --p;
    --ptot;
    --f;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	itype = 0;
    }
L10:
    switch (itype) {
	case 1:  goto L20;
	case 2:  goto L270;
	case 3:  goto L70;
    }
L20:

/*   SET UP ARRAY OF LOWER HALF TRIANGLE INDICES (PASCAL'S TRIANGLE) */

    for (i__ = 1; i__ <= 300; ++i__) {
	ifact[i__ - 1] = i__ * (i__ - 1) / 2;
/* L30: */
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
		    kindex[m - 1] = ifact[lj - 1] + jl + (ifact[ki - 1] + ik) 
			    * 10 - 10;
/* L40: */
		    jindex[m - 1] = (ifact[ji - 1] + ij) * 10 + ifact[lk - 1] 
			    + kl - 10;
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
/* L50: */
	}
    }
    l = 0;
    for (i__ = 1; i__ <= 10; ++i__) {
	m = mmperm[i__ - 1];
	l = llperm[i__ - 1];
	for (k = 1; k <= 16; ++k) {
	    ++l;
	    m += 16;
/* L60: */
	    jjndex[l - 1] = jindex[m - 1];
	}
    }
    if (i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0) {
	itype = 2;
    } else {
	itype = 3;
    }
    goto L10;
L70:
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
/* L80: */
	    }
	}
/* L90: */
    }
    ii = *nati;
    ia = nfirst[ii];
    ib = nlast[ii];
    i__1 = *numat;
    for (jj = 1; jj <= i__1; ++jj) {
	if (ii == jj) {
	    goto L260;
	}
	ja = nfirst[jj];
	jb = nlast[jj];
/*        JC=NMIDLE(JJ) */
	if (ib - ia >= 3 && jb - ja >= 3) {

/*                         HEAVY-ATOM  - HEAVY-ATOM */

/*   EXTRACT COULOMB TERMS */

	    for (i__ = 1; i__ <= 16; ++i__) {
		pja[i__ - 1] = work4_1.ptot2[ii + i__ * 120 - 121];
/* L100: */
		pjb[i__ - 1] = work4_1.ptot2[jj + i__ * 120 - 121];
	    }

/*  COULOMB TERMS */

	    jab_(&ia, &ja, llperm, jindex, jjndex, pja, pjb, &w[kk + 1], &f[1]
		    );

/*  EXCHANGE TERMS */


/*  EXTRACT INTERSECTION OF ATOMS II AND JJ IN THE SPIN DENSITY MATRIX */

	    if (ia > ja) {
		l = 0;
		i__3 = ib;
		for (i__ = ia; i__ <= i__3; ++i__) {
		    i__2 = jb;
		    for (j = ja; j <= i__2; ++j) {
			++l;
/* L110: */
			pk[l - 1] = p[ifact[i__ - 1] + j];
		    }
		}
	    } else {
		l = 0;
		i__2 = ib;
		for (i__ = ia; i__ <= i__2; ++i__) {
		    i__3 = jb;
		    for (j = ja; j <= i__3; ++j) {
			++l;
/* L120: */
			pk[l - 1] = p[ifact[j - 1] + i__];
		    }
		}
	    }
	    i1 = ia;
	    j1 = ja;
	    kab_(&ia, &ja, pk, &w[kk + 1], kindex, &f[1]);
	    ia = i1;
	    ja = j1;
	    kk += 100;
	} else if (ib - ia >= 3) {

/*                         LIGHT-ATOM  - HEAVY-ATOM */


/*   COULOMB TERMS */

	    sumdia = 0.;
	    sumoff = 0.;
	    ll = i1fact[ja - 1];
	    k = 0;
	    for (i__ = 0; i__ <= 3; ++i__) {
		j1 = ifact[ia + i__ - 1] + ia - 1;
		i__3 = i__ - 1;
		for (j = 0; j <= i__3; ++j) {
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

	    if (ia > ja) {
		k = 0;
		i__3 = ib;
		for (i__ = ia; i__ <= i__3; ++i__) {
		    i1 = ifact[i__ - 1] + ja;
		    sum = 0.;
		    i__2 = ib;
		    for (j = ia; j <= i__2; ++j) {
			++k;
			j1 = ifact[j - 1] + ja;
/* L150: */
			sum += p[j1] * w[kk + jindex[k - 1]];
		    }
/* L160: */
		    f[i1] -= sum;
		}
	    } else {
		k = 0;
		i__3 = ib;
		for (i__ = ia; i__ <= i__3; ++i__) {
		    i1 = ifact[ja - 1] + i__;
		    sum = 0.;
		    i__2 = ib;
		    for (j = ia; j <= i__2; ++j) {
			++k;
			j1 = ifact[ja - 1] + j;
/* L170: */
			sum += p[j1] * w[kk + jindex[k - 1]];
		    }
/* L180: */
		    f[i1] -= sum;
		}
	    }
	    kk += 10;
	} else if (jb - ja >= 3) {

/*                         HEAVY-ATOM - LIGHT-ATOM */


/*   COULOMB TERMS */

	    sumdia = 0.;
	    sumoff = 0.;
	    ll = i1fact[ia - 1];
	    k = 0;
	    for (i__ = 0; i__ <= 3; ++i__) {
		j1 = ifact[ja + i__ - 1] + ja - 1;
		i__3 = i__ - 1;
		for (j = 0; j <= i__3; ++j) {
		    ++k;
		    ++j1;
		    f[j1] += ptot[ll] * w[kk + k];
/* L190: */
		    sumoff += ptot[j1] * w[kk + k];
		}
		++j1;
		++k;
		f[j1] += ptot[ll] * w[kk + k];
/* L200: */
		sumdia += ptot[j1] * w[kk + k];
	    }
	    f[ll] = f[ll] + sumoff * 2. + sumdia;

/*  EXCHANGE TERMS */


/*  EXTRACT INTERSECTION OF ATOMS II AND JJ IN THE SPIN DENSITY MATRIX */

	    if (ia > ja) {
		k = ifact[ia - 1] + ja;
		j = 0;
		i__3 = k + 3;
		for (i__ = k; i__ <= i__3; ++i__) {
		    sum = 0.;
		    i__2 = k + 3;
		    for (l = k; l <= i__2; ++l) {
			++j;
/* L210: */
			sum += p[l] * w[kk + jindex[j - 1]];
		    }
/* L220: */
		    f[i__] -= sum;
		}
	    } else {
		j = 0;
		i__3 = ja + 3;
		for (k = ja; k <= i__3; ++k) {
		    i__ = ifact[k - 1] + ia;
		    sum = 0.;
		    i__2 = ja + 3;
		    for (ll = ja; ll <= i__2; ++ll) {
			l = ifact[ll - 1] + ia;
			++j;
/* L230: */
			sum += p[l] * w[kk + jindex[j - 1]];
		    }
/* L240: */
		    f[i__] -= sum;
		}
	    }
	    kk += 10;
	} else {

/*                         LIGHT-ATOM - LIGHT-ATOM */

	    i1 = i1fact[ia - 1];
	    j1 = i1fact[ja - 1];
	    f[i1] += ptot[j1] * w[kk + 1];
	    f[j1] += ptot[i1] * w[kk + 1];
	    if (ia > ja) {
		ij = i1 + ja - ia;
		f[ij] -= p[ij] * w[kk + 1];
	    } else {
		ij = j1 + ia - ja;
		f[ij] -= p[ij] * w[kk + 1];
	    }
	    ++kk;
	}
L260:
	;
    }

    return 0;
L270:
    kr = 0;
    ii = *nati;
    ia = nfirst[ii];
    ib = nlast[ii];
    i__1 = *numat;
    for (jj = 1; jj <= i__1; ++jj) {
	if (jj == ii) {
	    goto L290;
	}
	++kr;
	elrep = w[kr];
	ja = nfirst[jj];
	jb = nlast[jj];
	i__3 = ib;
	for (i__ = ia; i__ <= i__3; ++i__) {
	    ka = ifact[i__ - 1];
	    kk = ka + i__;
	    i__2 = jb;
	    for (k = ja; k <= i__2; ++k) {
		ll = i1fact[k - 1];
		if (ja < ia) {
		    ik = ka + k;
		} else {
		    ik = ll + i__ - k;
		}
		f[kk] += ptot[ll] * elrep;
		f[ll] += ptot[kk] * elrep;
/* L280: */
		f[ik] -= p[ik] * elrep;
	    }
	}
L290:
	;
    }
    return 0;
} /* dfock2_ */

