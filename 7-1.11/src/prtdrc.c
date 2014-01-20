/* prtdrc.f -- translated by f2c (version 20020621).
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
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal xract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer mcoprt[720]	/* was [2][360] */, ncoprt;
    logical parmax;
} drccom_;

#define drccom_1 drccom_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal allxyz[1080]	/* was [3][360] */, allvel[1080]	/* 
	    was [3][360] */, parref[360], xyz3[1080]	/* was [3][360] */, 
	    vel3[1080]	/* was [3][360] */, allgeo[1080]	/* was [3][
	    360] */, geo3[1080]	/* was [3][360] */, dummy[123841];
    integer idumy[4];
} fmatrx_;

#define fmatrx_1 fmatrx_

/* Table of constant values */

static integer c__1 = 1;
static integer c__5 = 5;
static integer c__3 = 3;
static integer c__8 = 8;
static doublereal c_b188 = 57.29577951;
static integer c__0 = 0;

/* Subroutine */ int prtdrc_(doublereal *escf, doublereal *deltt, doublereal *
	xparam, doublereal *ref, doublereal *ekin, doublereal *gtot, 
	doublereal *etot, doublereal *velo0, integer *nvar)
{
    /* Initialized data */

    static integer icalcn = 0;
    static doublereal refscf = 0.;
    static char cotype[2*3] = "BL" "BA" "DI";
    static logical turn = FALSE_;

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void), s_rsle(cilist *), 
	    do_lio(integer *, integer *, char *, ftnlen), e_rsle(void), 
	    s_wsle(cilist *), e_wsle(void);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double log(doublereal);

    /* Local variables */
    static integer i__, j, k, l, n;
    static doublereal c1, t1, t2, aa, bb, cc, dh;
    static integer ii;
    static doublereal geo[360];
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal sum, sum1;
    static logical ldrc;
    static integer ione;
    static doublereal time, tref, vref[360], refx, escf0, escf1, escf2, escf3[
	    3], ekin0, ekin1, ekin2, ekin3[3], vref0[360], told1, told2, 
	    xold0, xold1, xold2, xold3[3], etot0, etot1, gtot0, etot3[3], 
	    gtot1, gtot3[3], etot2, gtot2;
    static char text1[3], text2[2];
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal xtot0, xtot1, xtot2, xtot3[3];
    extern /* Subroutine */ int chrge_(doublereal *, doublereal *);
    static doublereal fract;
    extern /* Subroutine */ int quadr_(doublereal *, doublereal *, doublereal 
	    *, doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *);
    static integer iloop;
    static doublereal steph, tlast;
    static integer jloop;
    static doublereal stept, stepx, charge[120], deltat;
    static integer nfract;
    static doublereal totime;
    extern /* Subroutine */ int drcout_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, doublereal *
	    , doublereal *, char *, char *, integer *, integer *, ftnlen, 
	    ftnlen);
    static logical goturn;
    static doublereal tsteps[100];
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 6, 0, "(/,' TIME PRIORITY, INTERVAL =',F4.1"
	    ",            ' FEMTOSECONDS',/)", 0 };
    static cilist io___20 = { 0, 6, 0, "(/,' KINETIC ENERGY PRIORITY, STEP ="
	    "',F5.2,      ' KCAL/MOLE',/)", 0 };
    static cilist io___21 = { 0, 6, 0, "(/,' GEOMETRY PRIORITY, STEP =',F5.2"
	    ",            ' ANGSTROMS',/)", 0 };
    static cilist io___22 = { 0, 9, 0, 0, 0 };
    static cilist io___23 = { 0, 9, 0, 0, 0 };
    static cilist io___24 = { 0, 9, 0, 0, 0 };
    static cilist io___25 = { 0, 9, 0, 0, 0 };
    static cilist io___26 = { 0, 9, 0, 0, 0 };
    static cilist io___27 = { 0, 9, 0, 0, 0 };
    static cilist io___28 = { 0, 9, 0, 0, 0 };
    static cilist io___29 = { 0, 9, 0, 0, 0 };
    static cilist io___30 = { 0, 9, 0, 0, 0 };
    static cilist io___31 = { 0, 9, 0, 0, 0 };
    static cilist io___32 = { 0, 9, 0, 0, 0 };
    static cilist io___33 = { 0, 9, 0, 0, 0 };
    static cilist io___34 = { 0, 9, 0, 0, 0 };
    static cilist io___35 = { 0, 9, 0, 0, 0 };
    static cilist io___53 = { 0, 9, 0, 0, 0 };
    static cilist io___54 = { 0, 9, 0, 0, 0 };
    static cilist io___55 = { 0, 9, 0, 0, 0 };
    static cilist io___56 = { 0, 9, 0, 0, 0 };
    static cilist io___57 = { 0, 9, 0, 0, 0 };
    static cilist io___58 = { 0, 9, 0, 0, 0 };
    static cilist io___59 = { 0, 9, 0, 0, 0 };
    static cilist io___60 = { 0, 9, 0, 0, 0 };
    static cilist io___61 = { 0, 9, 0, 0, 0 };
    static cilist io___62 = { 0, 9, 0, 0, 0 };
    static cilist io___63 = { 0, 9, 0, 0, 0 };
    static cilist io___64 = { 0, 9, 0, 0, 0 };
    static cilist io___65 = { 0, 9, 0, 0, 0 };
    static cilist io___66 = { 0, 9, 0, 0, 0 };
    static cilist io___99 = { 0, 6, 0, "(/,20('****'))", 0 };
    static cilist io___101 = { 0, 6, 0, "(/,20('****'))", 0 };
    static cilist io___102 = { 0, 6, 0, "(/,A,F8.5,A,F8.5,A,G12.3,A)", 0 };
    static cilist io___103 = { 0, 6, 0, "(//,A,F11.3,A)", 0 };


/* ******************************************************************** */

/*    PRTDRC PREPARES TO PRINT THE GEOMETRY ETC. FOR POINTS IN A DRC */
/*    OR IRC */
/*    CALCULATION. */
/*    ON INPUT  ESCF   = HEAT OF FORMATION FOR THE CURRENT POINT */
/*              DELTT  = CHANGE IN TIME, PREVIOUS TO CURRENT POINT */
/*              XPARAM = CURRENT CARTESIAN GEOMETRY */
/*              EKIN   = CURRENT KINETIC ENERGY */
/*              GTOT   = TOTAL GRADIENT NORM IN IRC CALC'N. */
/*              VELO0  = CURRENT VELOCITY */
/*              NVAR   = NUMBER OF VARIABLES = 3 * NUMBER OF ATOMS. */

/* ******************************************************************* */
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
    --velo0;
    --ref;
    --xparam;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	    fmatrx_1.parref[i__ - 1] = xparam[i__];
	}
	*etot = *escf + *ekin;
	tlast = 0.;
	goturn = FALSE_;
	sum = 0.;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* Computing 2nd power */
	    d__1 = velo0[i__];
	    sum += d__1 * d__1;
	    vref0[i__ - 1] = velo0[i__];
/* L20: */
	    vref[i__ - 1] = velo0[i__];
	}
	ione = 1;
	ldrc = sum > 1.;
	iloop = 1;
	told1 = 0.;

/*       DETERMINE TYPE OF PRINT: TIME, ENERGY OR GEOMETRY PRIORITY */
/*       OR PRINT ALL POINTS */

	stept = 0.;
	steph = 0.;
	stepx = 0.;
	if (i_indx(keywrd_1.keywrd, " T-PRIO", (ftnlen)241, (ftnlen)7) != 0) {
	    if (i_indx(keywrd_1.keywrd, " T-PRIORITY=", (ftnlen)241, (ftnlen)
		    12) != 0) {
		i__1 = i_indx(keywrd_1.keywrd, "T-PRIO", (ftnlen)241, (ftnlen)
			6) + 5;
		stept = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    } else {
		stept = .1;
	    }
	    tref = -1e-6;
	    s_wsfe(&io___19);
	    do_fio(&c__1, (char *)&stept, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else if (i_indx(keywrd_1.keywrd, " H-PRIO", (ftnlen)241, (ftnlen)7) 
		!= 0) {
	    if (i_indx(keywrd_1.keywrd, " H-PRIORITY=", (ftnlen)241, (ftnlen)
		    12) != 0) {
		i__1 = i_indx(keywrd_1.keywrd, "H-PRIO", (ftnlen)241, (ftnlen)
			6) + 5;
		steph = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    } else {
		steph = .1;
	    }
	    s_wsfe(&io___20);
	    do_fio(&c__1, (char *)&steph, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else if (i_indx(keywrd_1.keywrd, " X-PRIO", (ftnlen)241, (ftnlen)7) 
		!= 0) {
	    if (i_indx(keywrd_1.keywrd, " X-PRIORITY=", (ftnlen)241, (ftnlen)
		    12) != 0) {
		i__1 = i_indx(keywrd_1.keywrd, "X-PRIO", (ftnlen)241, (ftnlen)
			6) + 5;
		stepx = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    } else {
		stepx = .05;
	    }
	    s_wsfe(&io___21);
	    do_fio(&c__1, (char *)&stepx, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (i_indx(keywrd_1.keywrd, " RESTART", (ftnlen)241, (ftnlen)8) != 0 
		&& i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) == 
		0) {
	    s_rsle(&io___22);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.parref[i__ - 1], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___23);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&ref[i__], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___24);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&vref0[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___25);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&vref[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___26);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allgeo[i__ * 3 - 1], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___27);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allgeo[i__ * 3 - 2], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___28);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allgeo[i__ * 3 - 3], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___29);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allvel[i__ * 3 - 1], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___30);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allvel[i__ * 3 - 2], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___31);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allvel[i__ * 3 - 3], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___32);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allxyz[i__ * 3 - 1], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___33);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allxyz[i__ * 3 - 2], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___34);
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_lio(&c__5, &c__1, (char *)&fmatrx_1.allxyz[i__ * 3 - 3], (
			ftnlen)sizeof(doublereal));
	    }
	    e_rsle();
	    s_rsle(&io___35);
	    do_lio(&c__3, &c__1, (char *)&iloop, (ftnlen)sizeof(integer));
	    do_lio(&c__8, &c__1, (char *)&ldrc, (ftnlen)sizeof(logical));
	    do_lio(&c__3, &c__1, (char *)&ione, (ftnlen)sizeof(integer));
	    do_lio(&c__5, &c__1, (char *)&etot1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&etot0, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&escf1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&escf0, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&ekin1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&ekin0, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&told2, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&told1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&gtot1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&gtot0, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&xold2, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&xold1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&xold0, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
	    do_lio(&c__3, &c__1, (char *)&jloop, (ftnlen)sizeof(integer));
	    do_lio(&c__5, &c__1, (char *)&(*etot), (ftnlen)sizeof(doublereal))
		    ;
	    do_lio(&c__5, &c__1, (char *)&refx, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&xtot1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&xtot0, (ftnlen)sizeof(doublereal));
	    e_rsle();
	}
    }
    if (*escf < -1e8) {
	s_wsle(&io___53);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.parref[i__ - 1], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___54);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&ref[i__], (ftnlen)sizeof(doublereal)
		    );
	}
	e_wsle();
	s_wsle(&io___55);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&vref0[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsle();
	s_wsle(&io___56);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&vref[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsle();
	s_wsle(&io___57);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allgeo[i__ * 3 - 1], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___58);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allgeo[i__ * 3 - 2], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___59);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allgeo[i__ * 3 - 3], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___60);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allvel[i__ * 3 - 1], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___61);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allvel[i__ * 3 - 2], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___62);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allvel[i__ * 3 - 3], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___63);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allxyz[i__ * 3 - 1], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___64);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allxyz[i__ * 3 - 2], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___65);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&fmatrx_1.allxyz[i__ * 3 - 3], (
		    ftnlen)sizeof(doublereal));
	}
	e_wsle();
	s_wsle(&io___66);
	do_lio(&c__3, &c__1, (char *)&iloop, (ftnlen)sizeof(integer));
	do_lio(&c__8, &c__1, (char *)&ldrc, (ftnlen)sizeof(logical));
	do_lio(&c__3, &c__1, (char *)&ione, (ftnlen)sizeof(integer));
	do_lio(&c__5, &c__1, (char *)&etot1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&etot0, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&escf1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&escf0, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&ekin1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&ekin0, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&told2, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&told1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&gtot1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&gtot0, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&xold2, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&xold1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&xold0, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
	do_lio(&c__3, &c__1, (char *)&jloop, (ftnlen)sizeof(integer));
	do_lio(&c__5, &c__1, (char *)&(*etot), (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&refx, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&xtot1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&xtot0, (ftnlen)sizeof(doublereal));
	e_wsle();
	return 0;
    }
    chrge_(densty_1.p, charge);
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	l = molkst_1.nat[i__ - 1];
/* L30: */
	charge[i__ - 1] = core_1.core[l - 1] - charge[i__ - 1];
    }
    deltat = *deltt * 1e15;
    geokst_1.na[1] = -1;
    xyzint_(&xparam[1], &molkst_1.numat, geokst_1.na, geokst_1.nb, 
	    geokst_1.nc, &c_b188, geo);
    geokst_1.na[0] = 99;
    if (iloop == 1) {
	etot1 = etot0;
	etot0 = *etot;
	escf1 = *escf;
	escf0 = *escf;
	ekin1 = *ekin;
	ekin0 = *ekin;
	for (j = 1; j <= 3; ++j) {
/* $DOIT VBEST */
	    i__1 = *nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		fmatrx_1.allgeo[j + i__ * 3 - 4] = geo[i__ - 1];
		fmatrx_1.allxyz[j + i__ * 3 - 4] = xparam[i__];
/* L40: */
		fmatrx_1.allvel[j + i__ * 3 - 4] = velo0[i__];
	    }
	}
    } else {
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    fmatrx_1.allgeo[i__ * 3 - 1] = fmatrx_1.allgeo[i__ * 3 - 2];
	    fmatrx_1.allgeo[i__ * 3 - 2] = fmatrx_1.allgeo[i__ * 3 - 3];
	    fmatrx_1.allgeo[i__ * 3 - 3] = geo[i__ - 1];
	    fmatrx_1.allxyz[i__ * 3 - 1] = fmatrx_1.allxyz[i__ * 3 - 2];
	    fmatrx_1.allxyz[i__ * 3 - 2] = fmatrx_1.allxyz[i__ * 3 - 3];
	    fmatrx_1.allxyz[i__ * 3 - 3] = xparam[i__];
	    fmatrx_1.allvel[i__ * 3 - 1] = fmatrx_1.allvel[i__ * 3 - 2];
	    fmatrx_1.allvel[i__ * 3 - 2] = fmatrx_1.allvel[i__ * 3 - 3];
/* L50: */
	    fmatrx_1.allvel[i__ * 3 - 3] = velo0[i__];
	}
    }

/*  FORM QUADRATIC EXPRESSION FOR POSITION AND VELOCITY W.R.T. TIME. */

    t1 = max(told2,.02);
    t2 = max(told1,.02) + t1;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	quadr_(&fmatrx_1.allgeo[i__ * 3 - 1], &fmatrx_1.allgeo[i__ * 3 - 2], &
		fmatrx_1.allgeo[i__ * 3 - 3], &t1, &t2, &fmatrx_1.geo3[i__ * 
		3 - 3], &fmatrx_1.geo3[i__ * 3 - 2], &fmatrx_1.geo3[i__ * 3 - 
		1]);

/* *************************************************** */
/*                                                  * */
/*    QUADR CALCULATES THE A, B AND C IN THE EQUNS. * */
/*                                                  * */
/*     A                   =   F0                   * */
/*     A + B.X0 + C.X0**2  =   F1                   * */
/*     A + B.X2 + C.X2**2  =   F2                   * */
/* GIVEN THE ARGUMENT LIST (F0,F1,F2, X1,X2, A,B,C) * */
/*                                                  * */
/* *************************************************** */
	quadr_(&fmatrx_1.allxyz[i__ * 3 - 1], &fmatrx_1.allxyz[i__ * 3 - 2], &
		fmatrx_1.allxyz[i__ * 3 - 3], &t1, &t2, &fmatrx_1.xyz3[i__ * 
		3 - 3], &fmatrx_1.xyz3[i__ * 3 - 2], &fmatrx_1.xyz3[i__ * 3 - 
		1]);
	quadr_(&fmatrx_1.allvel[i__ * 3 - 1], &fmatrx_1.allvel[i__ * 3 - 2], &
		fmatrx_1.allvel[i__ * 3 - 3], &t1, &t2, &fmatrx_1.vel3[i__ * 
		3 - 3], &fmatrx_1.vel3[i__ * 3 - 2], &fmatrx_1.vel3[i__ * 3 - 
		1]);
/* L60: */
    }
    etot2 = etot1;
    etot1 = etot0;
    etot0 = *etot;
    quadr_(&etot2, &etot1, &etot0, &t1, &t2, etot3, &etot3[1], &etot3[2]);
    ekin2 = ekin1;
    ekin1 = ekin0;
    ekin0 = *ekin;
    quadr_(&ekin2, &ekin1, &ekin0, &t1, &t2, ekin3, &ekin3[1], &ekin3[2]);
    escf2 = escf1;
    escf1 = escf0;
    escf0 = *escf;
    quadr_(&escf2, &escf1, &escf0, &t1, &t2, escf3, &escf3[1], &escf3[2]);
    gtot2 = gtot1;
    gtot1 = gtot0;
    gtot0 = *gtot;
    quadr_(&gtot2, &gtot1, &gtot0, &t1, &t2, gtot3, &gtot3[1], &gtot3[2]);
    xtot2 = xtot1;
    xtot1 = xtot0;
    xold2 += xold1;
    xold1 = xold0;

/*   CALCULATE CHANGE IN GEOMETRY */

    xold0 = 0.;
    l = 0;
    xtot0 = 0.;
    sum1 = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	sum1 = 0.;
/* $DOIT ASIS */
	for (j = 1; j <= 3; ++j) {
	    ++l;
/* Computing 2nd power */
	    d__1 = fmatrx_1.allxyz[l * 3 - 3] - ref[l];
	    sum1 += d__1 * d__1;
/* L70: */
/* Computing 2nd power */
	    d__1 = fmatrx_1.allxyz[l * 3 - 2] - fmatrx_1.allxyz[l * 3 - 3];
	    sum += d__1 * d__1;
	}
	xold0 += sqrt(sum);
/* L80: */
	xtot0 += sqrt(sum1);
    }
    quadr_(&xtot2, &xtot1, &xtot0, &t1, &t2, xtot3, &xtot3[1], &xtot3[2]);
    d__1 = xold2 + xold1;
    d__2 = xold2 + xold1 + xold0;
    quadr_(&xold2, &d__1, &d__2, &t1, &t2, xold3, &xold3[1], &xold3[2]);
/* ********************************************************************** */
/*   GO THROUGH THE CRITERIA FOR DECIDING WHETHER OR NOT TO PRINT THIS * */
/*   POINT.  IF YES, THEN ALSO CALCULATE THE EXACT POINT AS A FRACTION * */
/*   BETWEEN THE LAST POINT AND THE CURRENT POINT                      * */
/* ********************************************************************** */
/*   NFRACT IS THE NUMBER OF POINTS TO BE PRINTED IN THE CURRENT DOMAIN */
/* ********************************************************************** */
    if (iloop < 3) {
	goto L170;
    }
    fract = -10.;
    nfract = 1;
    if (steph != 0.) {

/*   CRITERION FOR PRINTING RESULTS  IS A CHANGE IN HEAT OF FORMATION = */
/*   -CHANGE IN KINETIC ENERGY */

	if (refscf == 0.) {
	    i__ = (integer) (escf2 / steph);
	    refscf = i__ * steph;
	}
	dh = (d__1 = escf1 - refscf, abs(d__1));
	if (dh > steph) {
	    d__1 = escf1 - refscf;
	    steph = d_sign(&steph, &d__1);
	    nfract = (d__1 = dh / steph, (integer) abs(d__1));
	    cc = escf3[0];
	    bb = escf3[1];
	    aa = escf3[2];
/* *********************************************** */
/* PROGRAMMERS! - BE VERY CAREFUL IF YOU CHANGE * */
/* THIS FOLLOWING SECTION.  THERE IS NUMERICAL  * */
/* INSTABILITY IF ABS(BB/AA) IS VERY LARGE. NEAR* */
/* INFLECTION POINTS AA CHANGES SIGN.       JJPS* */
/* *********************************************** */
	    if ((d__1 = bb / aa, abs(d__1)) > 30.) {

/*   USE LINEAR INTERPOLATION */

		i__1 = nfract;
		for (i__ = 1; i__ <= i__1; ++i__) {
/* L90: */
		    tsteps[i__ - 1] = -(cc - (refscf + i__ * steph)) / bb;
		}
	    } else {

/*  USE QUADRATIC INTERPOLATION */

		i__1 = nfract;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    c1 = cc - (refscf + i__ * steph);
/* L100: */
		    d__1 = sqrt(bb * bb - aa * c1 * 4.);
		    tsteps[i__ - 1] = (-bb + d_sign(&d__1, &bb)) / (aa * 2.);
		}
	    }
	    fract = -.1;
	    refscf += nfract * steph;
	}
    } else if (stept != 0.) {

/*   CRITERION FOR PRINTING RESULTS IS A CHANGE IN TIME. */

	if ((d__1 = totime + told2 - tref, abs(d__1)) > stept) {
	    i__ = (integer) (totime / stept);
	    fract = i__ * stept - totime;
	    i__ = (integer) ((told2 + totime) / stept);
	    j = (integer) (totime / stept);
	    nfract = i__ - j + ione;
	    ione = 0;
	    i__1 = nfract;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L110: */
		tsteps[i__ - 1] = fract + i__ * stept;
	    }
	    tref += nfract * stept;
	}
    } else if (stepx != 0.) {

/*   CRITERION FOR PRINTING RESULTS IS A CHANGE IN GEOMETRY. */

	if (xold2 + xold1 - refx > stepx) {
	    nfract = (integer) ((xold2 + xold1 - refx) / stepx);
	    cc = xold3[0];
	    bb = xold3[1];
	    aa = xold3[2];
	    if ((d__1 = bb / aa, abs(d__1)) > 30.) {

/*   USE LINEAR INTERPOLATION */

		i__1 = nfract;
		for (i__ = 1; i__ <= i__1; ++i__) {
/* L120: */
		    tsteps[i__ - 1] = -(cc - (refx + i__ * stepx)) / bb;
		}
	    } else {

/*  USE QUADRATIC INTERPOLATION */

		i__1 = nfract;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    c1 = cc - (refx + i__ * stepx);
/* L130: */
		    d__1 = sqrt(bb * bb - aa * c1 * 4.);
		    tsteps[i__ - 1] = (-bb + d_sign(&d__1, &bb)) / (aa * 2.);
		}
	    }
	    refx += nfract * stepx;
	    fract = -.1;
	}
    } else {

/*   PRINT EVERY POINT. */

	fract = 0.;
    }
    if (fract < -9.) {
	goto L170;
    }
    turn = turn || (d__1 = fract - 1., abs(d__1)) > 1e-6;

/*  LOOP OVER ALL POINTS IN CURRENT DOMAIN */

    if (fract == 0. && nfract == 1) {
	s_copy(text1, " ", (ftnlen)3, (ftnlen)1);
	s_copy(text2, " ", (ftnlen)2, (ftnlen)1);
	ii = 0;
	drcout_(fmatrx_1.xyz3, fmatrx_1.geo3, fmatrx_1.vel3, nvar, &totime, 
		escf3, ekin3, gtot3, etot3, xtot3, &iloop, charge, &fract, 
		text1, text2, &ii, &jloop, (ftnlen)3, (ftnlen)2);
	n = 0;
	i__1 = drccom_1.ncoprt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    k = drccom_1.mcoprt[(i__ << 1) - 2];
	    j = drccom_1.mcoprt[(i__ << 1) - 1];
	    l = k * 3 - 3 + j;
	    if ((d__1 = fmatrx_1.geo3[l * 3 - 1], abs(d__1)) > 1e-20) {
		fract = -fmatrx_1.geo3[l * 3 - 2] / (fmatrx_1.geo3[l * 3 - 1] 
			* 2.);
	    }
	    if (fract > 0. && fract < told2) {
		if (fmatrx_1.geo3[l * 3 - 1] > 0.) {
		    s_copy(text1, "MIN", (ftnlen)3, (ftnlen)3);
		}
		if (fmatrx_1.geo3[l * 3 - 1] < 0.) {
		    s_copy(text1, "MAX", (ftnlen)3, (ftnlen)3);
		}
		s_copy(text2, cotype + (j - 1 << 1), (ftnlen)2, (ftnlen)2);
		if (n == 0) {
		    ++n;
		    s_wsfe(&io___99);
		    e_wsfe();
		}
		time = totime + fract;
		drcout_(fmatrx_1.xyz3, fmatrx_1.geo3, fmatrx_1.vel3, nvar, &
			time, escf3, ekin3, gtot3, etot3, xtot3, &iloop, 
			charge, &fract, text1, text2, &k, &jloop, (ftnlen)3, (
			ftnlen)2);
	    }
/* L140: */
	}
	if (n != 0) {
	    s_wsfe(&io___101);
	    e_wsfe();
	}
	if (abs(escf3[2]) > 1e-20) {
	    fract = -escf3[1] / (escf3[2] * 2.);
	}
	if (! goturn && fract > 0. && fract < told2 * 1.04 && drccom_1.parmax)
		 {
	    goturn = TRUE_;
	    time = fract + totime;
	    if (escf3[2] > 0.) {
		s_copy(text1, "MIN", (ftnlen)3, (ftnlen)3);
		if (ldrc) {
/* Computing 2nd power */
		    d__1 = dot_(&velo0[1], vref, nvar);
		    sum = d__1 * d__1 / (dot_(&velo0[1], &velo0[1], nvar) * 
			    dot_(vref, vref, nvar) + 1e-10);
/* Computing 2nd power */
		    d__1 = dot_(&velo0[1], vref0, nvar);
		    sum1 = d__1 * d__1 / (dot_(&velo0[1], &velo0[1], nvar) * 
			    dot_(vref0, vref0, nvar) + 1e-10);
		    if (sum1 > .1 && (d__1 = sum1 - 1., abs(d__1)) > 1e-6) {
			s_wsfe(&io___102);
			do_fio(&c__1, " COEF. OF V(0)             =", (ftnlen)
				28);
			do_fio(&c__1, (char *)&sum1, (ftnlen)sizeof(
				doublereal));
			do_fio(&c__1, "   LAST V(0)", (ftnlen)12);
			do_fio(&c__1, (char *)&sum, (ftnlen)sizeof(doublereal)
				);
			do_fio(&c__1, "   HALF-LIFE =", (ftnlen)14);
			d__2 = time * -.6931472 / log(sum1);
			do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(
				doublereal));
			do_fio(&c__1, " FEMTOSECS", (ftnlen)10);
			e_wsfe();
		    }
		}
		s_wsfe(&io___103);
		do_fio(&c__1, " HALF-CYCLE TIME =", (ftnlen)18);
		d__1 = time - tlast;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, " FEMTOSECONDS", (ftnlen)13);
		e_wsfe();
		tlast = time;
		i__1 = *nvar;
		for (i__ = 1; i__ <= i__1; ++i__) {
/* L150: */
		    vref[i__ - 1] = velo0[i__];
		}
	    }
	    if (escf3[2] < 0.) {
		s_copy(text1, "MAX", (ftnlen)3, (ftnlen)3);
	    }
	    s_copy(text2, " ", (ftnlen)2, (ftnlen)1);
	    drcout_(fmatrx_1.xyz3, fmatrx_1.geo3, fmatrx_1.vel3, nvar, &time, 
		    escf3, ekin3, gtot3, etot3, xtot3, &iloop, charge, &fract,
		     text1, text2, &c__0, &jloop, (ftnlen)3, (ftnlen)2);
	} else {
	    goturn = FALSE_;
	}
    } else {
	i__1 = nfract;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    time = totime + tsteps[i__ - 1];
	    s_copy(text1, " ", (ftnlen)3, (ftnlen)1);
	    s_copy(text2, " ", (ftnlen)2, (ftnlen)1);
/* #           WRITE(6,'(A,4F12.4)')' KINETIC ENERGY, POINT',EKIN3,TSTEPS( */
	    drcout_(fmatrx_1.xyz3, fmatrx_1.geo3, fmatrx_1.vel3, nvar, &time, 
		    escf3, ekin3, gtot3, etot3, xtot3, &iloop, charge, &
		    tsteps[i__ - 1], text1, text2, &c__0, &jloop, (ftnlen)3, (
		    ftnlen)2);
/* L160: */
	}
    }
L170:

/* BUFFER TOTAL TIME TO 3 POINTS BACK! */

    totime += told2;
    told2 = told1;
    told1 = deltat;
    ++iloop;
    return 0;
} /* prtdrc_ */

