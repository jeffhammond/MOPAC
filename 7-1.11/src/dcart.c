/* dcart.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

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
    integer l1l, l2l, l3l, l1u, l2u, l3u;
} ucell_;

#define ucell_1 ucell_

struct {
    integer k1l, k2l, k3l, k1u, k2u, k3u;
} dcartc_;

#define dcartc_1 dcartc_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    logical iseps, useps, upda;
} iseps_;

#define iseps_1 iseps_

struct {
    doublereal uss[107], upp[107], udd[107];
} onelec_;

#define onelec_1 onelec_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static doublereal c_b70 = 100.;

/* Subroutine */ int dcart_(doublereal *coord, doublereal *dxyz)
{
    /* Initialized data */

    static integer icalcn = 0;
    static doublereal chnge = 1e-4;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7;
    doublereal d__1;
    alist al__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), f_rew(alist *);
    double sin(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal aa, ee;
    static integer if__, jf, ii, jj, il, im, jm, jl, ik, jk, kl, ij, iw, im1;
    extern /* Subroutine */ int dhc_(doublereal *, doublereal *, doublereal *,
	     doublereal *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *, doublereal *, integer *);
    static doublereal cdi[6]	/* was [3][2] */, del, eng[3];
    static integer ndi[2], iii;
    static doublereal pdi[171];
    static integer jjj;
    static doublereal sum, padi[171], pbdi[171], heat, refh;
    static integer irot;
    extern /* Subroutine */ int dihed_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *);
    static logical debug;
    static doublereal angle;
    static logical large, force, makep;
    static doublereal deriv, chnge2;
#define lstor1 ((integer *)&ucell_1)
#define lstor2 ((integer *)&dcartc_1)
    static logical anader;
    extern /* Subroutine */ int diegrd_(doublereal *, doublereal *);
    static integer ncells, iofset;
    extern /* Subroutine */ int analyt_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, integer *, integer *, integer *, 
	    integer *, integer *, doublereal *);
    static integer numtot;

    /* Fortran I/O blocks */
    static cilist io___48 = { 0, 0, 0, "(//10X,'CARTESIAN COORDINATE DERIVAT"
	    "IVES',//3X,       'NUMBER  ATOM ',5X,'X',12X,'Y',12X,'Z',/)", 0 };
    static cilist io___49 = { 0, 0, 0, "(2I6,F13.6,2F13.6)", 0 };
    static cilist io___50 = { 0, 0, 0, "(2I6,F13.6,2F13.6)", 0 };
    static cilist io___51 = { 0, 0, 0, "(2I6,F13.6,2F13.6)", 0 };
    static cilist io___53 = { 0, 6, 0, "(//10X,'CARTESIAN COORDINATE DERIVAT"
	    "IVES',//3X,        'NUMBER  ATOM ',5X,'X',12X,'Y',12X,'Z',/)", 0 }
	    ;
    static cilist io___54 = { 0, 6, 0, "(2I6,F13.6,2F13.6)", 0 };
    static cilist io___55 = { 0, 6, 0, "(2I6,F13.6,2F13.6)", 0 };
    static cilist io___56 = { 0, 6, 0, "(2I6,F13.6,2F13.6)", 0 };


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

/*    DCART CALCULATES THE DERIVATIVES OF THE ENERGY WITH RESPECT TO THE */
/*          CARTESIAN COORDINATES. THIS IS DONE BY FINITE DIFFERENCES. */

/*    THE MAIN ARRAYS IN DCART ARE: */
/*        DXYZ   ON EXIT CONTAINS THE CARTESIAN DERIVATIVES. */

/* *********************************************************************** */
/* COSMO change */
/* end of COSMO change */
    /* Parameter adjustments */
    dxyz -= 4;
    coord -= 4;

    /* Function Body */
    chnge2 = chnge * .5;

/* CHNGE IS A MACHINE-PRECISION DEPENDENT CONSTANT */
/* CHNGE2=CHNGE/2 */

    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	large = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5) != 0;
	anader = i_indx(keywrd_1.keywrd, "ANALYT", (ftnlen)241, (ftnlen)6) != 
		0;
	debug = i_indx(keywrd_1.keywrd, "DCART", (ftnlen)241, (ftnlen)5) != 0;
	force = i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) + 
		i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0;
    }
    ncells = (ucell_1.l1u - ucell_1.l1l + 1) * (ucell_1.l2u - ucell_1.l2l + 1)
	     * (ucell_1.l3u - ucell_1.l3l + 1);
    for (i__ = 1; i__ <= 6; ++i__) {
	lstor2[i__ - 1] = lstor1[i__ - 1];
/* L10: */
	lstor1[i__ - 1] = 0;
    }
    iofset = (ncells + 1) / 2;
    numtot = molkst_1.numat * ncells;
    i__1 = numtot;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L20: */
	    dxyz[j + i__ * 3] = 0.;
	}
    }
    if (anader) {
	al__1.aerr = 0;
	al__1.aunit = 2;
	f_rew(&al__1);
    }
    i__1 = molkst_1.numat;
    for (ii = 1; ii <= i__1; ++ii) {
	iii = ncells * (ii - 1) + iofset;
	im1 = ii;
	if__ = molkst_1.nfirst[ii - 1];
	im = molkst_1.nmidle[ii - 1];
	il = molkst_1.nlast[ii - 1];
	ndi[1] = molkst_1.nat[ii - 1];
	for (i__ = 1; i__ <= 3; ++i__) {
/* L30: */
	    cdi[i__ + 2] = coord[i__ + ii * 3];
	}
	i__2 = im1;
	for (jj = 1; jj <= i__2; ++jj) {
	    jjj = ncells * (jj - 1);
/*  FORM DIATOMIC MATRICES */
	    jf = molkst_1.nfirst[jj - 1];
	    jm = molkst_1.nmidle[jj - 1];
	    jl = molkst_1.nlast[jj - 1];
/*   GET FIRST ATOM */
	    ndi[0] = molkst_1.nat[jj - 1];
	    makep = TRUE_;
	    i__3 = dcartc_1.k1u;
	    for (ik = dcartc_1.k1l; ik <= i__3; ++ik) {
		i__4 = dcartc_1.k2u;
		for (jk = dcartc_1.k2l; jk <= i__4; ++jk) {
		    i__5 = dcartc_1.k3u;
		    for (kl = dcartc_1.k3l; kl <= i__5; ++kl) {
			++jjj;
/*                    KKK=KKK-1 */
			for (l = 1; l <= 3; ++l) {
/* L40: */
			    cdi[l - 1] = coord[l + jj * 3] + euler_1.tvec[l - 
				    1] * ik + euler_1.tvec[l + 2] * jk + 
				    euler_1.tvec[l + 5] * kl;
			}
			if (! makep) {
			    goto L90;
			}
			makep = FALSE_;
			ij = 0;
			i__6 = jl;
			for (i__ = jf; i__ <= i__6; ++i__) {
			    k = i__ * (i__ - 1) / 2 + jf - 1;
			    i__7 = i__;
			    for (j = jf; j <= i__7; ++j) {
				++ij;
				++k;
				padi[ij - 1] = densty_1.pa[k - 1];
				pbdi[ij - 1] = densty_1.pb[k - 1];
/* L50: */
				pdi[ij - 1] = densty_1.p[k - 1];
			    }
			}
/* GET SECOND ATOM FIRST ATOM INTERSECTION */
			i__7 = il;
			for (i__ = if__; i__ <= i__7; ++i__) {
			    l = i__ * (i__ - 1) / 2;
			    k = l + jf - 1;
			    i__6 = jl;
			    for (j = jf; j <= i__6; ++j) {
				++ij;
				++k;
				padi[ij - 1] = densty_1.pa[k - 1];
				pbdi[ij - 1] = densty_1.pb[k - 1];
/* L60: */
				pdi[ij - 1] = densty_1.p[k - 1];
			    }
			    k = l + if__ - 1;
			    i__6 = i__;
			    for (l = if__; l <= i__6; ++l) {
				++k;
				++ij;
				padi[ij - 1] = densty_1.pa[k - 1];
				pbdi[ij - 1] = densty_1.pb[k - 1];
/* L70: */
				pdi[ij - 1] = densty_1.p[k - 1];
			    }
/* L80: */
			}
L90:
			if (ii == jj) {
			    goto L120;
			}
			if (anader) {
			    analyt_(pdi, padi, pbdi, cdi, ndi, &jf, &jl, &
				    if__, &il, eng);
			    for (k = 1; k <= 3; ++k) {
				dxyz[k + iii * 3] -= eng[k - 1];
/* L100: */
				dxyz[k + jjj * 3] += eng[k - 1];
			    }
			} else {
			    if (! force) {
				cdi[0] += chnge2;
				cdi[1] += chnge2;
				cdi[2] += chnge2;
				dhc_(pdi, padi, pbdi, cdi, ndi, &jf, &jm, &jl,
					 &if__, &im, &il, &aa, &c__1);
			    }
			    for (k = 1; k <= 3; ++k) {
				if (force) {
				    cdi[k + 2] -= chnge2;
				    dhc_(pdi, padi, pbdi, cdi, ndi, &jf, &jm, 
					    &jl, &if__, &im, &il, &aa, &c__1);
				}
				cdi[k + 2] += chnge;
				dhc_(pdi, padi, pbdi, cdi, ndi, &jf, &jm, &jl,
					 &if__, &im, &il, &ee, &c__2);
				cdi[k + 2] -= chnge2;
				if (! force) {
				    cdi[k + 2] -= chnge2;
				}
				deriv = (aa - ee) * 23.061 / chnge;
				dxyz[k + iii * 3] -= deriv;
				dxyz[k + jjj * 3] += deriv;
/* L110: */
			    }
			}
L120:
			;
		    }
		}
	    }
/* L130: */
	}
    }
    if (molmec_1.nnhco != 0) {

/*   NOW ADD IN MOLECULAR-MECHANICS CORRECTION TO THE H-N-C=O TORSION */

	del = 1e-8;
	i__2 = molmec_1.nnhco;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    for (j = 1; j <= 4; ++j) {
		for (k = 1; k <= 3; ++k) {
		    coord[k + molmec_1.nhco[j + (i__ << 2) - 5] * 3] -= del;
		    dihed_(&coord[4], &molmec_1.nhco[(i__ << 2) - 4], &
			    molmec_1.nhco[(i__ << 2) - 3], &molmec_1.nhco[(
			    i__ << 2) - 2], &molmec_1.nhco[(i__ << 2) - 1], &
			    angle);
/* Computing 2nd power */
		    d__1 = sin(angle);
		    refh = molmec_1.htype[molmec_1.itype - 1] * (d__1 * d__1);
		    coord[k + molmec_1.nhco[j + (i__ << 2) - 5] * 3] += del * 
			    2.;
		    dihed_(&coord[4], &molmec_1.nhco[(i__ << 2) - 4], &
			    molmec_1.nhco[(i__ << 2) - 3], &molmec_1.nhco[(
			    i__ << 2) - 2], &molmec_1.nhco[(i__ << 2) - 1], &
			    angle);
		    coord[k + molmec_1.nhco[j + (i__ << 2) - 5] * 3] -= del;
/* Computing 2nd power */
		    d__1 = sin(angle);
		    heat = molmec_1.htype[molmec_1.itype - 1] * (d__1 * d__1);
		    sum = (refh - heat) / (del * 2.);
		    dxyz[k + molmec_1.nhco[j + (i__ << 2) - 5] * 3] -= sum;
/* L140: */
		}
/* L150: */
	    }
/* L160: */
	}
    }
/* COSMO change A. Klamt */
/* analytic calculation of the gradient of the dielectric energy A.Klamt */
    if (iseps_1.useps) {
	diegrd_(&coord[4], &dxyz[4]);
    }
/*     DO 170 I=1,6 */
/* 170 LSTOR1(I)=LSTOR2(I) */
    if (! debug) {
	return 0;
    }
    iw = 6;
    io___48.ciunit = iw;
    s_wsfe(&io___48);
    e_wsfe();
    if (ncells == 1) {
	io___49.ciunit = iw;
	s_wsfe(&io___49);
	i__2 = numtot;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nat[i__ - 1], (ftnlen)sizeof(
		    integer));
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&dxyz[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    } else if (large) {
	io___50.ciunit = iw;
	s_wsfe(&io___50);
	i__2 = numtot;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nat[(i__ - 1) / ncells], (ftnlen)
		    sizeof(integer));
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&dxyz[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    } else {
	io___51.ciunit = iw;
	s_wsfe(&io___51);
	i__2 = numtot;
	for (i__ = 1; i__ <= i__2; i__ += 3) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nat[(i__ - 1) / ncells], (ftnlen)
		    sizeof(integer));
	    for (j = 1; j <= 3; ++j) {
		d__1 = dxyz[j + i__ * 3] + dxyz[j + (i__ + 1) * 3] + dxyz[j + 
			(i__ + 2) * 3];
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    }
	}
	e_wsfe();
    }
    irot = 2;
    if (anader) {
	al__1.aerr = 0;
	al__1.aunit = irot;
	f_rew(&al__1);
    }
/* end of COSMO (A. Klamt) changes */
    if (! debug) {
	return 0;
    }
    s_wsfe(&io___53);
    e_wsfe();
    if (ncells == 1) {
	s_wsfe(&io___54);
	i__2 = numtot;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nat[i__ - 1], (ftnlen)sizeof(
		    integer));
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&dxyz[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    } else if (large) {
	s_wsfe(&io___55);
	i__2 = numtot;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nat[(i__ - 1) / ncells], (ftnlen)
		    sizeof(integer));
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&dxyz[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    } else {
	s_wsfe(&io___56);
	i__2 = numtot;
	for (i__ = 1; i__ <= i__2; i__ += 3) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nat[(i__ - 1) / ncells], (ftnlen)
		    sizeof(integer));
	    for (j = 1; j <= 3; ++j) {
		d__1 = dxyz[j + i__ * 3] + dxyz[j + (i__ + 1) * 3] + dxyz[j + 
			(i__ + 2) * 3];
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    }
	}
	e_wsfe();
    }
    if (anader) {
	al__1.aerr = 0;
	al__1.aunit = 2;
	f_rew(&al__1);
    }
    return 0;
} /* dcart_ */

#undef lstor2
#undef lstor1


/* Subroutine */ int dhc_(doublereal *p, doublereal *pa, doublereal *pb, 
	doublereal *xi, integer *nat, integer *if__, integer *im, integer *il,
	 integer *jf, integer *jm, integer *jl, doublereal *dener, integer *
	mode)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static doublereal f[171], h__[171];
    static integer i__, j, k;
    static doublereal w[100];
    static integer i1, j1, i2, ia, ja, jb, jc, ib, ic, nj, ni, jj, ii, kr;
    static doublereal ee, wj[100], wk[100], e1b[10], e2a[10];
    static logical uhf;
    static doublereal wjs[100], wks[100], wlim;
    extern /* Subroutine */ int fock2_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, integer *, integer *,
	     integer *, integer *, integer *);
    static doublereal shmat[81]	/* was [9][9] */;
    static integer nlast[2];
    extern /* Subroutine */ int h1elec_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *);
    extern doublereal helect_(integer *, doublereal *, doublereal *, 
	    doublereal *);
    static integer nmidle[2], linear;
    static logical cutoff;
    static doublereal enuclr;
    extern /* Subroutine */ int rotate_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *);
    static integer nfirst[2];
    extern /* Subroutine */ int solrot_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *);

/* *********************************************************************** */

/*  DHC CALCULATES THE ENERGY CONTRIBUTIONS FROM THOSE PAIRS OF ATOMS */
/*         THAT HAVE BEEN MOVED BY SUBROUTINE DERIV. */

/* *********************************************************************** */
    /* Parameter adjustments */
    --nat;
    xi -= 4;
    --pb;
    --pa;
    --p;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	wlim = 4.;
	if (euler_1.id == 0) {
	    wlim = 0.;
	}
	uhf = i_indx(keywrd_1.keywrd, "UHF", (ftnlen)241, (ftnlen)3) != 0;
    }
    nfirst[0] = 1;
    nmidle[0] = *im - *if__ + 1;
    nlast[0] = *il - *if__ + 1;
    nfirst[1] = nlast[0] + 1;
    nmidle[1] = nfirst[1] + *jm - *jf;
    nlast[1] = nfirst[1] + *jl - *jf;
    linear = nlast[1] * (nlast[1] + 1) / 2;
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
	f[i__ - 1] = 0.;
/* L10: */
	h__[i__ - 1] = 0.;
    }
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	f[i__ - 1] = h__[i__ - 1];
    }
    ja = nfirst[1];
    jb = nlast[1];
    jc = nmidle[1];
    ia = nfirst[0];
    ib = nlast[0];
    ic = nmidle[0];
    j = 2;
    i__ = 1;
    nj = nat[2];
    ni = nat[1];
    h1elec_(&ni, &nj, &xi[4], &xi[7], shmat);
    if (nat[1] == 102 || nat[2] == 102) {
	k = jb * (jb + 1) / 2;
	i__1 = k;
	for (j = 1; j <= i__1; ++j) {
/* L30: */
	    h__[j - 1] = 0.;
	}
    } else {
	j1 = 0;
	i__1 = jb;
	for (j = ja; j <= i__1; ++j) {
	    jj = j * (j - 1) / 2;
	    ++j1;
	    i1 = 0;
	    i__2 = ib;
	    for (i__ = ia; i__ <= i__2; ++i__) {
		++jj;
		++i1;
		h__[jj - 1] = shmat[i1 + j1 * 9 - 10];
		f[jj - 1] = shmat[i1 + j1 * 9 - 10];
/* L40: */
	    }
	}
    }
    kr = 1;
    if (euler_1.id == 0) {
	rotate_(&nj, &ni, &xi[7], &xi[4], &w[kr - 1], &kr, e2a, e1b, &enuclr, 
		&c_b70);
    } else {
	solrot_(&nj, &ni, &xi[7], &xi[4], wj, wk, &kr, e2a, e1b, &enuclr, &
		c_b70);
	if (*mode == 1) {
	    cutoff = wj[0] < wlim;
	}
	if (cutoff) {
	    i__2 = kr - 1;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L50: */
		wk[i__ - 1] = 0.;
	    }
	}
	i__2 = kr - 1;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    wjs[i__ - 1] = wj[i__ - 1];
	    wks[i__ - 1] = wk[i__ - 1];
/* L60: */
	}
    }

/*    * ENUCLR IS SUMMED OVER CORE-CORE REPULSION INTEGRALS. */

    i2 = 0;
    i__2 = ic;
    for (i1 = ia; i1 <= i__2; ++i1) {
	ii = i1 * (i1 - 1) / 2 + ia - 1;
	i__1 = i1;
	for (j1 = ia; j1 <= i__1; ++j1) {
	    ++ii;
	    ++i2;
	    h__[ii - 1] += e1b[i2 - 1];
/* L70: */
	    f[ii - 1] += e1b[i2 - 1];
	}
    }
    i__1 = ib;
    for (i1 = ic + 1; i1 <= i__1; ++i1) {
	ii = i1 * (i1 + 1) / 2;
	f[ii - 1] += e1b[0];
/* L80: */
	h__[ii - 1] += e1b[0];
    }
    i2 = 0;
    i__1 = jc;
    for (i1 = ja; i1 <= i__1; ++i1) {
	ii = i1 * (i1 - 1) / 2 + ja - 1;
	i__2 = i1;
	for (j1 = ja; j1 <= i__2; ++j1) {
	    ++ii;
	    ++i2;
	    h__[ii - 1] += e2a[i2 - 1];
/* L90: */
	    f[ii - 1] += e2a[i2 - 1];
	}
    }
    i__2 = jb;
    for (i1 = jc + 1; i1 <= i__2; ++i1) {
	ii = i1 * (i1 + 1) / 2;
	f[ii - 1] += e2a[0];
/* L100: */
	h__[ii - 1] += e2a[0];
    }
    fock2_(f, &p[1], &pa[1], w, wjs, wks, &c__2, &nat[1], nfirst, nmidle, 
	    nlast);
    ee = helect_(&nlast[1], &pa[1], h__, f);
    if (uhf) {
	i__2 = linear;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L110: */
	    f[i__ - 1] = h__[i__ - 1];
	}
	fock2_(f, &p[1], &pb[1], w, wjs, wks, &c__2, &nat[1], nfirst, nmidle, 
		nlast);
	ee += helect_(&nlast[1], &pb[1], h__, f);
    } else {
	ee *= 2.;
    }
    *dener = ee + enuclr;
    return 0;

} /* dhc_ */

