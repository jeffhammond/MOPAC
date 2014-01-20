/* parsav.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal alparm[1080]	/* was [3][360] */, x0, x1, x2;
    integer iloop;
} alparm_;

#define alparm_1 alparm_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal errfn[360], aicorr[360];
} errfn_;

#define errfn_1 errfn_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal q[129600]	/* was [360][360] */, r__[259200]	/* 
	    was [360][720] */;
} nllcom_;

#define nllcom_1 nllcom_

struct {
    doublereal dddum[6], efslst[360], xlast[360];
    integer iiium[7];
} nllco2_;

#define nllco2_1 nllco2_

struct {
    integer nvar, loc[720]	/* was [2][360] */, jdumy;
    doublereal dumy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    integer locvar[720]	/* was [2][360] */;
} locvar_;

#define locvar_1 locvar_

struct {
    doublereal valvar[360];
    integer numvar;
} valvar_;

#define valvar_1 valvar_

/* Table of constant values */

static integer c__7 = 7;
static integer c__6 = 6;
static integer c__360 = 360;
static integer c__1 = 1;
static doublereal c_b31 = 1.;

/* Subroutine */ int parsav_(integer *mode, integer *n, integer *m)
{
    /* System generated locals */
    integer i__1, i__2;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_rew(alist *), s_rsue(cilist *), do_uio(integer 
	    *, char *, ftnlen), e_rsue(void), i_indx(char *, char *, ftnlen, 
	    ftnlen), s_wsfe(cilist *), e_wsfe(void), s_wsue(cilist *), e_wsue(
	    void), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal coord[360]	/* was [3][120] */;
    extern /* Subroutine */ int geout_(integer *);
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer linear;
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___1 = { 1, 9, 1, 0, 0 };
    static cilist io___3 = { 0, 9, 0, 0, 0 };
    static cilist io___5 = { 0, 9, 0, 0, 0 };
    static cilist io___6 = { 0, 9, 0, 0, 0 };
    static cilist io___7 = { 0, 9, 0, 0, 0 };
    static cilist io___8 = { 0, 6, 0, "(//10X,' **** TIME UP ****')", 0 };
    static cilist io___9 = { 0, 6, 0, "(//10X,' CURRENT VALUES OF GEOMETRIC "
	    "VARIABLES',//)", 0 };
    static cilist io___11 = { 0, 6, 0, "(//10X,                             "
	    "                  'TO RESTART CALCULATION USE THE KEYWORD \"REST"
	    "ART\".')", 0 };
    static cilist io___12 = { 0, 9, 0, 0, 0 };
    static cilist io___13 = { 0, 9, 0, 0, 0 };
    static cilist io___14 = { 0, 9, 0, 0, 0 };
    static cilist io___15 = { 0, 9, 0, 0, 0 };
    static cilist io___16 = { 0, 9, 0, 0, 0 };
    static cilist io___18 = { 0, 10, 0, 0, 0 };
    static cilist io___19 = { 0, 10, 0, 0, 0 };
    static cilist io___20 = { 0, 6, 0, "(//10X,'NO RESTART FILE EXISTS!')", 0 
	    };


/* ********************************************************************* */

/*   PARSAV SAVES AND RESTORES DATA USED IN NLLSQ GRADIENT MINIMIZATION. */

/*    IF MODE IS 0 DATA ARE RESTORED, IF 1 THEN SAVED. */

/* ********************************************************************* */
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
    o__1.oerr = 0;
    o__1.ounit = 9;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR009", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 9;
    f_rew(&al__1);
    o__1.oerr = 0;
    o__1.ounit = 10;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR010", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 10;
    f_rew(&al__1);
    if (*mode != 0) {
	goto L10;
    }

/*  MODE=0: RETRIEVE DATA FROM DISK. */

    i__1 = s_rsue(&io___1);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_uio(&c__7, (char *)&nllco2_1.iiium[0], (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_uio(&c__6, (char *)&nllco2_1.dddum[0], (ftnlen)sizeof(
	    doublereal));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_uio(&c__360, (char *)&nllco2_1.efslst[0], (ftnlen)sizeof(
	    doublereal));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_uio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = do_uio(&c__1, (char *)&nllco2_1.xlast[i__ - 1], (ftnlen)sizeof(
		doublereal));
	if (i__1 != 0) {
	    goto L30;
	}
    }
    i__1 = do_uio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_rsue();
    if (i__1 != 0) {
	goto L30;
    }
    s_rsue(&io___3);
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    do_uio(&c__1, (char *)&nllcom_1.q[j + i__ * 360 - 361], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_rsue();
    s_rsue(&io___5);
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    do_uio(&c__1, (char *)&nllcom_1.r__[j + i__ * 360 - 361], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_rsue();
    s_rsue(&io___6);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&valvar_1.valvar[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_rsue();
    if (i_indx(keywrd_1.keywrd, "AIDER", (ftnlen)241, (ftnlen)5) != 0) {
	s_rsue(&io___7);
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&errfn_1.aicorr[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
    }
    return 0;
L10:
    if (*mode == 1) {
	s_wsfe(&io___8);
	e_wsfe();
	s_wsfe(&io___9);
	e_wsfe();
	if (geokst_1.na[0] == 99) {

/*  CONVERT FROM CARTESIAN COORDINATES TO INTERNAL */

	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
/* L20: */
		    coord[j + i__ * 3 - 4] = geom_1.geo[j + i__ * 3 - 4];
		}
	    }
	    xyzint_(coord, &molkst_1.numat, geokst_1.na, geokst_1.nb, 
		    geokst_1.nc, &c_b31, geom_1.geo);
	}
	geout_(&c__6);
	s_wsfe(&io___11);
	e_wsfe();
    }
    s_wsue(&io___12);
    do_uio(&c__7, (char *)&nllco2_1.iiium[0], (ftnlen)sizeof(integer));
    do_uio(&c__6, (char *)&nllco2_1.dddum[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__360, (char *)&nllco2_1.efslst[0], (ftnlen)sizeof(doublereal));
    do_uio(&c__1, (char *)&(*n), (ftnlen)sizeof(integer));
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&nllco2_1.xlast[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    do_uio(&c__1, (char *)&(*m), (ftnlen)sizeof(integer));
    e_wsue();
    s_wsue(&io___13);
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *m;
	for (j = 1; j <= i__2; ++j) {
	    do_uio(&c__1, (char *)&nllcom_1.q[j + i__ * 360 - 361], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_wsue();
    s_wsue(&io___14);
    i__2 = *n;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = *n;
	for (j = 1; j <= i__1; ++j) {
	    do_uio(&c__1, (char *)&nllcom_1.r__[j + i__ * 360 - 361], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_wsue();
    s_wsue(&io___15);
    i__1 = *n;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&valvar_1.valvar[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsue();
    if (i_indx(keywrd_1.keywrd, "AIDER", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsue(&io___16);
	i__1 = *n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&errfn_1.aicorr[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
    }
/* ***** */
/*     The density matrix is required by ITER upon restart . */

    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
    s_wsue(&io___18);
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsue();
    if (molkst_1.nalpha != 0) {
	s_wsue(&io___19);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
    }
/* ***** */
    cl__1.cerr = 0;
    cl__1.cunit = 9;
    cl__1.csta = 0;
    f_clos(&cl__1);
    cl__1.cerr = 0;
    cl__1.cunit = 10;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
L30:
    s_wsfe(&io___20);
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* parsav_ */

