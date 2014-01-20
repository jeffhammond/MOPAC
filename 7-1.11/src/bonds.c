/* bonds.f -- translated by f2c (version 20020621).
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
    doublereal b[90000]	/* was [300][300] */, bondab[39600];
} scrach_;

#define scrach_1 scrach_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal c__[90000], eigs[300], cbeta[90000], eigb[300];
} vector_;

#define vector_1 vector_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal pdummy[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal sdm[45150];
} drohf_;

#define drohf_1 drohf_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int bonds_(doublereal *p)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal a;
    static integer i__, j, k, l, m, n;
    static doublereal v[120], x, aa, da;
    static logical ci;
    static doublereal aq[120];
    static integer ij, il, kk;
    static doublereal sd[120];
    static integer ll, ih;
    static doublereal fv[120], pm[120];
    static integer mu;
    static doublereal ps[90000]	/* was [300][300] */, sq[120], tq[120], sp[
	    120];
    static logical kci, nci;
    static doublereal aux[14400]	/* was [120][120] */, sum, spna[120], 
	    spsa[120];
    static integer nopn;
    static doublereal spsq[120];
    extern /* Subroutine */ int dopen_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *);
    static doublereal pspin[45150];
    static integer linear;
    static doublereal spinab[39600], zkappa;
    extern /* Subroutine */ int vecprt_(doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, "(2x,'nelecs nclose nopen nopn',4I5)", 
	    0 };
    static cilist io___15 = { 0, 6, 0, "(10X,'ROHF ZKAPPA=',F10.5,2I5)", 0 };
    static cilist io___33 = { 0, 6, 0, "(//)", 0 };
    static cilist io___34 = { 0, 6, 0, "(1X,10X,51('* '),//1X, 10X,'* ',9X,'"
	    "STATISTICAL POP ULATION ANALYSIS',9X,'* ',//1X,10X,51('* '))", 0 }
	    ;
    static cilist io___35 = { 0, 6, 0, "(1X//20X,'DEGREES OF BONDING'/)", 0 };
    static cilist io___36 = { 0, 6, 0, "(///)", 0 };
    static cilist io___37 = { 0, 6, 0, "(1X,5X,'SELF-Q',4X,'ACTIV-Q',3X,'TOT"
	    "AL-Q',3X,'VALENCE',3X,'FREE-VA',1X,'STAT.PROM',1X,'MULL.PROM'//)",
	     0 };
    static cilist io___38 = { 0, 6, 0, "(1X,I2,7F10.5/)", 0 };
    static cilist io___40 = { 0, 6, 0, "(1X,'CLOSED SHELL'//)", 0 };
    static cilist io___42 = { 0, 6, 0, "(1X,'ROHF'//)", 0 };
    static cilist io___43 = { 0, 6, 0, "(1X,'UHF '//)", 0 };
    static cilist io___45 = { 0, 6, 0, "(//)", 0 };
    static cilist io___46 = { 0, 6, 0, "(10X,'NALPHA-NBETA= ',F10.5,//)", 0 };
    static cilist io___47 = { 0, 6, 0, "(1X,'OPEN SHELL& UHF CASE'//)", 0 };
    static cilist io___49 = { 0, 6, 0, "(1X,10X,51('* ')//1X,10X,'* ',9X,'ST"
	    "ATISTICAL SPIN   POPULATION ANALYSIS',9X,'* ',//1X,10X,51('* '))",
	     0 };
    static cilist io___54 = { 0, 6, 0, "(1X//20X,'SELF UNPAIRED AND BOND SPI"
	    "N POPULATIONS '/)", 0 };
    static cilist io___55 = { 0, 6, 0, "(//)", 0 };
    static cilist io___56 = { 0, 6, 0, "(10X,' TOTAL ATOMIC SPIN POPULATIONS"
	    "'/)", 0 };
    static cilist io___57 = { 0, 6, 0, "(1X,'ATOM    SELF UNCPLD SPIN    SHA"
	    "RED UNCPLD SPIN      TOTAL UNCPLD SPIN '///(1X,I3,3F20.5))", 0 };


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
/*   CALCULATES AND PRINTS THE BOND INDICES AND VALENCIES OF ATOMS */
/*   FOR REFERENCE, SEE "BOND INDICES AND VALENCY", J.C.S.DALTON, */
/*   ARMSTRONG,D.R., PERKINS,P.G. AND STEWART,J.J.P., 838 (1973) */

/*  ON INPUT */
/*           P = DENSITY MATRIX, LOWER HALF TRIANGLE, PACKED. */
/*               P IS NOT ALTERED BY BONDS */

/* ********************************************************************* */
/*     DIMENSION DENW(MAXORB,MAXORB) */

    /* Parameter adjustments */
    --p;

    /* Function Body */
    ci = i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)241, (ftnlen)4) + i_indx(
	    keywrd_1.keywrd, "MECI", (ftnlen)241, (ftnlen)4) != 0;
    kci = i_indx(keywrd_1.keywrd, "MICROS", (ftnlen)241, (ftnlen)6) == 0;
    nci = i_indx(keywrd_1.keywrd, "ROOT", (ftnlen)241, (ftnlen)4) + i_indx(
	    keywrd_1.keywrd, "OPEN", (ftnlen)241, (ftnlen)4) == 0;
    nopn = molkst_1.nopen - molkst_1.nclose;
    molkst_1.nelecs = molkst_1.nclose + molkst_1.nclose + nopn;
    s_wsfe(&io___5);
    do_fio(&c__1, (char *)&molkst_1.nelecs, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&molkst_1.nclose, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&molkst_1.nopen, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&nopn, (ftnlen)sizeof(integer));
    e_wsfe();
/* *****   CALCULATE THE DEGREE OF BONDING   ************ */

    k = 0;
    i__1 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++k;
	    scrach_1.b[i__ + j * 300 - 301] = p[k];
/* L20: */
	    scrach_1.b[j + i__ * 300 - 301] = p[k];
	}
    }

/* *******  CALCULATE KAPPA FACTOR FOR UHF OR ROHF  ****************** */

    if (i_indx(keywrd_1.keywrd, "UHF", (ftnlen)241, (ftnlen)3) != 0) {
/* ****** UHF CASE */
	zkappa = 0.;
	i__2 = molkst_1.nalpha;
	for (n = 1; n <= i__2; ++n) {
	    i__1 = molkst_1.nbeta;
	    for (m = 1; m <= i__1; ++m) {
		sum = 0.;
		i__3 = molkst_1.norbs;
		for (mu = 1; mu <= i__3; ++mu) {
		    l = mu + molkst_1.norbs * (n - 1);
		    k = mu + molkst_1.norbs * (m - 1);
/* L27: */
		    sum += vector_1.c__[l - 1] * vector_1.cbeta[k - 1];
		}
/* L23: */
/* Computing 2nd power */
		d__1 = sum;
		zkappa += d__1 * d__1;
	    }
	}
	zkappa = 1. / (zkappa / (doublereal) (molkst_1.nalpha + 
		molkst_1.nbeta) + .5);
    } else {
	if (! ci && nopn == 0 && nci && kci) {
	    zkappa = 1.;
	} else {
/* ****** ROHF CASE */
	    zkappa = 1. / (1. - (doublereal) nopn / (doublereal) 
		    molkst_1.nelecs / 2.);
	    s_wsfe(&io___15);
	    do_fio(&c__1, (char *)&zkappa, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&molkst_1.nopen, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&molkst_1.nclose, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    }
    ij = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	a = 0.;
	l = molkst_1.nfirst[i__ - 1];
	ll = molkst_1.nlast[i__ - 1];
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++ij;
	    k = molkst_1.nfirst[j - 1];
	    kk = molkst_1.nlast[j - 1];
	    x = 0.;
	    i__3 = ll;
	    for (il = l; il <= i__3; ++il) {
		i__4 = kk;
		for (ih = k; ih <= i__4; ++ih) {
/* L30: */
		    x += scrach_1.b[il + ih * 300 - 301] * scrach_1.b[il + ih 
			    * 300 - 301];
		}
	    }
/* L40: */
	    scrach_1.bondab[ij - 1] = x;
	}
	x = -scrach_1.bondab[ij - 1];
	i__2 = ll;
	for (j = l; j <= i__2; ++j) {
	    a += scrach_1.b[j + j * 300 - 301];
/* L50: */
	    x += scrach_1.b[j + j * 300 - 301] * 2.;
	}
	v[i__ - 1] = x;
	sd[i__ - 1] = a;
/* L60: */
    }


/* *****  CALCULATE ACTIVE CHARGE (AQ), SELF CHARGE (SQ), FREE VALENCE(FV) */
/*          TOTAL CHARGE (TQ), MULLIKEN TYPE PROMOTION (PM) AND STATISTICAL */
/*          PROMOTION (SP)  ******************************************** */

    k = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++k;
	    scrach_1.bondab[k - 1] *= zkappa;
	    aux[i__ + j * 120 - 121] = scrach_1.bondab[k - 1];
/* L65: */
	    aux[j + i__ * 120 - 121] = scrach_1.bondab[k - 1];
	}
    }
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	da = 0.;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
/* L80: */
	    if (j != i__) {
		da += aux[i__ + j * 120 - 121];
	    }
	}
	aq[i__ - 1] = da;
	sq[i__ - 1] = (aux[i__ + i__ * 120 - 121] - da) / 2.;
	fv[i__ - 1] = v[i__ - 1] - aq[i__ - 1];
	tq[i__ - 1] = aq[i__ - 1] + sq[i__ - 1];
	pm[i__ - 1] = sd[i__ - 1] - core_1.core[molkst_1.nat[i__ - 1] - 1];
/* L70: */
	sp[i__ - 1] = tq[i__ - 1] - core_1.core[molkst_1.nat[i__ - 1] - 1];
    }


/*  ********   OUTPUT    ***************** */


    s_wsfe(&io___33);
    e_wsfe();
    s_wsfe(&io___34);
    e_wsfe();
    s_wsfe(&io___35);
    e_wsfe();
    vecprt_(scrach_1.bondab, &molkst_1.numat);
    s_wsfe(&io___36);
    e_wsfe();
    s_wsfe(&io___37);
    e_wsfe();
    s_wsfe(&io___38);
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&sq[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&aq[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&tq[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&v[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&fv[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&sp[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&pm[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
/* ****** PERFORM SPIN POPULATION STATISTICAL ANALYSIS */
    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
    if (i_indx(keywrd_1.keywrd, "UHF", (ftnlen)241, (ftnlen)3) != 0) {
	goto L1000;
    }
    if (! ci && nopn == 0 && nci && kci) {
	s_wsfe(&io___40);
	e_wsfe();
	return 0;
    } else {
	dopen_(vector_1.c__, &molkst_1.norbs, &molkst_1.norbs, &
		molkst_1.nclose, &molkst_1.nopen, &molkst_1.fract);
	i__2 = linear;
	for (j = 1; j <= i__2; ++j) {
/* L91: */
	    pspin[j - 1] = drohf_1.sdm[j - 1];
	}
/*       WRITE(6,'(1X,''SDM'',10E12.3)')(SDM(J),J=1,LINEAR) */
	s_wsfe(&io___42);
	e_wsfe();
	goto L1002;
    }
L1000:
    s_wsfe(&io___43);
    e_wsfe();
    i__2 = linear;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L90: */
	pspin[i__ - 1] = densty_1.pa[i__ - 1] - densty_1.pb[i__ - 1];
    }
    sum = 0.;
    l = 0;
    i__2 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    aa = 2.;
	    if (i__ == j) {
		aa = 1.;
	    }
	    ++l;
/* L100: */
	    sum += aa * (pspin[l - 1] * p[l]);
	}
    }
    s_wsfe(&io___45);
    e_wsfe();
    s_wsfe(&io___46);
    do_fio(&c__1, (char *)&sum, (ftnlen)sizeof(doublereal));
    e_wsfe();
L1002:
    s_wsfe(&io___47);
    e_wsfe();
    kk = 0;
    i__1 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++kk;
	    ps[i__ + j * 300 - 301] = pspin[kk - 1];
/* L110: */
	    ps[j + i__ * 300 - 301] = pspin[kk - 1];
	}
    }
    s_wsfe(&io___49);
    e_wsfe();
/* EVALUATE  THE CORRESPONDING INACTIVE ATOMIC AND BOND SPIN POPULATIONS */
    ij = 0;
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	l = molkst_1.nfirst[i__ - 1];
	ll = molkst_1.nlast[i__ - 1];
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++ij;
	    k = molkst_1.nfirst[j - 1];
	    kk = molkst_1.nlast[j - 1];
	    x = 0.;
	    i__4 = ll;
	    for (il = l; il <= i__4; ++il) {
		i__3 = kk;
		for (ih = k; ih <= i__3; ++ih) {
/* L140: */
		    x += scrach_1.b[il + ih * 300 - 301] * ps[il + ih * 300 - 
			    301];
		}
	    }
/* L130: */
	    spinab[ij - 1] = x;
	}
/* L120: */
    }
/* EVALUATE THE TOTAL ATOMIC SPIN POPULATIONS */
    k = 0;
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++k;
	    aux[i__ + j * 120 - 121] = spinab[k - 1];
/* L150: */
	    aux[j + i__ * 120 - 121] = spinab[k - 1];
	}
    }
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	da = 0.;
	i__2 = molkst_1.numat;
	for (j = 1; j <= i__2; ++j) {
/* L170: */
	    if (j != i__) {
		da += aux[i__ + j * 120 - 121];
	    }
	}
	spsa[i__ - 1] = da;
	spsq[i__ - 1] = aux[i__ + i__ * 120 - 121];
/* L160: */
	spna[i__ - 1] = da + aux[i__ + i__ * 120 - 121];
    }
    s_wsfe(&io___54);
    e_wsfe();
    vecprt_(spinab, &molkst_1.numat);
    s_wsfe(&io___55);
    e_wsfe();
    s_wsfe(&io___56);
    e_wsfe();
    s_wsfe(&io___57);
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&spsq[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&spsa[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&spna[i__ - 1], (ftnlen)sizeof(doublereal));
    }
    e_wsfe();
    return 0;
} /* bonds_ */

/* Subroutine */ int dopen_(doublereal *c__, integer *mdim, integer *norbs, 
	integer *ndubl, integer *nsingl, doublereal *fract)
{
    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, n2, nl1, nu1;
    static doublereal sum1, frac;

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
/* ********************************************************************** */

/*  DOPEN COMPUTES THE DENSITY MATRIX OF OPEN SHELL ROHF STATE FUNCTIONS */
/*  FROM THE EIGENVECTOR MATRIX AND THE M.O'S OCCUPANCIES */

/*  INPUT:   C      = SQUARE EIGENVECTOR MATRIX C */
/*           NORBS  = NUMBER OF ORBITALS */
/*           NDUBL  = NUMBER OF DOUBLY OCCUPIED M.O'S (=0 IF UHF) */
/*           NSINGL = NUMBER OF SINGLY OR FRACTIONALLY OCCUPIED M.O'S */

/*  EXIT:    SDM    = ROHF OPEN SHELL DENSITY MATRIX */

/* ********************************************************************** */

/*  SET UP LIMITS FOR SUMS */
/*    NL1 = BEGINNING OF ONE ELECTRON SUM */
/*    NU1 = END OF THE SAME */

    /* Parameter adjustments */
    c_dim1 = *mdim;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;

    /* Function Body */
    n2 = *norbs * (*norbs + 1) / 2;
    frac = *fract;
    nl1 = *ndubl + 1;
    nu1 = *nsingl;
    l = 0;
    i__1 = *norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
	    sum1 = 0.;
	    i__3 = nu1;
	    for (k = nl1; k <= i__3; ++k) {
/* L20: */
		sum1 += c__[i__ + k * c_dim1] * c__[j + k * c_dim1];
	    }
/* L30: */
	    drohf_1.sdm[l - 1] = sum1 * frac;
	}
/* L40: */
    }
    return 0;
} /* dopen_ */

