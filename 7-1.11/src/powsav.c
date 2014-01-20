/* powsav.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal dumy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal errfn[360], aicorr[360];
} errfn_;

#define errfn_1 errfn_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

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
    integer locvar[720]	/* was [2][360] */;
} locvar_;

#define locvar_1 locvar_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal valvar[360];
    integer numvar;
} valvar_;

#define valvar_1 valvar_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal alparm[1080]	/* was [3][360] */, x0, x1, x2;
    integer jloop;
} alparm_;

#define alparm_1 alparm_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b15 = 1.;
static integer c__6 = 6;
static integer c__9 = 9;

/* Subroutine */ int powsav_(doublereal *hess, doublereal *grad, doublereal *
	xparam, doublereal *pmat, integer *iloop, doublereal *bmat, integer *
	ipow)
{
    /* System generated locals */
    integer i__1, i__2;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_rew(alist *), s_wsfe(cilist *), e_wsfe(void);
    double sqrt(doublereal);
    integer do_fio(integer *, char *, ftnlen), s_wsue(cilist *), do_uio(
	    integer *, char *, ftnlen), e_wsue(void), i_indx(char *, char *, 
	    ftnlen, ftnlen), f_clos(cllist *), s_rsue(cilist *), e_rsue(void);

    /* Local variables */
    static integer i__, j, k, l, ir;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal coord[360]	/* was [3][120] */;
    extern /* Subroutine */ int geout_(integer *);
    static doublereal funct1;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer linear;
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, "(//10X,'- - - - - - - TIME UP - - - -"
	    " - - -',//)", 0 };
    static cilist io___3 = { 0, 6, 0, "(//10X,' - THE CALCULATION IS BEING D"
	    "UMPED TO DISK',/10X,'   RESTART IT USING THE KEY-WORD \"RESTAR"
	    "T\"')", 0 };
    static cilist io___5 = { 0, 6, 0, "(//10X,'CURRENT VALUE OF GRADIENT NOR"
	    "M ='          ,F12.6)", 0 };
    static cilist io___9 = { 0, 6, 0, "(/10X,'CURRENT VALUE OF GEOMETRY',/)", 
	    0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, 0, 0 };
    static cilist io___19 = { 0, 0, 0, 0, 0 };
    static cilist io___20 = { 0, 10, 0, 0, 0 };
    static cilist io___21 = { 0, 10, 0, 0, 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 6, 0, "(//10X,' RESTORING DATA FROM DISK'/)",
	     0 };
    static cilist io___25 = { 0, 0, 0, 0, 0 };
    static cilist io___26 = { 0, 0, 0, 0, 0 };
    static cilist io___27 = { 0, 0, 0, 0, 0 };
    static cilist io___28 = { 0, 0, 0, 0, 0 };
    static cilist io___29 = { 0, 0, 0, 0, 0 };
    static cilist io___30 = { 0, 6, 0, "(10X,'FUNCTION =',F13.6//)", 0 };
    static cilist io___31 = { 0, 0, 0, 0, 0 };
    static cilist io___32 = { 0, 0, 0, 0, 0 };
    static cilist io___33 = { 0, 10, 0, 0, 0 };
    static cilist io___34 = { 0, 10, 0, 0, 0 };
    static cilist io___35 = { 0, 0, 0, 0, 0 };
    static cilist io___36 = { 0, 0, 0, 0, 0 };


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

/* POWSAV STORES AND RESTORES DATA USED IN THE SIGMA GEOMETRY */
/*        OPTIMISATION. */

/*  ON INPUT HESS   = HESSIAN MATRIX, PARTIAL OR WHOLE. */
/*           GRAD   = GRADIENTS. */
/*           XPARAM = CURRENT STATE OF PARAMETERS. */
/*           ILOOP  = INDEX OF HESSIAN, OR FLAG OF POINT REACHED SO-FAR. */
/*           BMAT   = "B" MATRIX! */
/*           IPOW   = INDICES AND FLAGS. */
/*           IPOW(9)= 0 FOR RESTORE, 1 FOR DUMP */

/* ********************************************************************* */
    /* Parameter adjustments */
    --ipow;
    bmat -= 361;
    --pmat;
    --xparam;
    --grad;
    hess -= 361;

    /* Function Body */
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
    ir = 9;
    if (ipow[9] != 0) {
	if (ipow[9] == 1) {
	    s_wsfe(&io___2);
	    e_wsfe();
	    s_wsfe(&io___3);
	    e_wsfe();
	    funct1 = sqrt(dot_(&grad[1], &grad[1], &geovar_1.nvar));
	    s_wsfe(&io___5);
	    do_fio(&c__1, (char *)&funct1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		k = geovar_1.loc[(i__ << 1) - 2];
		l = geovar_1.loc[(i__ << 1) - 1];
/* L10: */
		geom_1.geo[l + k * 3 - 4] = xparam[i__];
	    }
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
			geokst_1.nc, &c_b15, geom_1.geo);
	    }
	    geout_(&c__6);
	}
	io___12.ciunit = ir;
	s_wsue(&io___12);
	do_uio(&c__9, (char *)&ipow[1], (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*iloop), (ftnlen)sizeof(integer));
	e_wsue();
	io___13.ciunit = ir;
	s_wsue(&io___13);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___14.ciunit = ir;
	s_wsue(&io___14);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&grad[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___15.ciunit = ir;
	s_wsue(&io___15);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = geovar_1.nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_uio(&c__1, (char *)&hess[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	io___16.ciunit = ir;
	s_wsue(&io___16);
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = geovar_1.nvar;
	    for (j = 1; j <= i__1; ++j) {
		do_uio(&c__1, (char *)&bmat[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	linear = geovar_1.nvar * (geovar_1.nvar + 1) / 2;
	io___18.ciunit = ir;
	s_wsue(&io___18);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&pmat[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	if (i_indx(keywrd_1.keywrd, "AIDER", (ftnlen)241, (ftnlen)5) != 0) {
	    io___19.ciunit = ir;
	    s_wsue(&io___19);
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&errfn_1.aicorr[i__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsue();
	}
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	s_wsue(&io___20);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	if (molkst_1.nalpha != 0) {
	    s_wsue(&io___21);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsue();
	}
	if (path_1.latom != 0) {
	    io___22.ciunit = ir;
	    s_wsue(&io___22);
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    do_uio(&c__1, (char *)&alparm_1.alparm[j + i__ * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		}
	    }
	    e_wsue();
	    io___23.ciunit = ir;
	    s_wsue(&io___23);
	    do_uio(&c__1, (char *)&alparm_1.jloop, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&alparm_1.x0, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x2, (ftnlen)sizeof(doublereal));
	    e_wsue();
	}
	cl__1.cerr = 0;
	cl__1.cunit = 9;
	cl__1.csta = 0;
	f_clos(&cl__1);
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
	return 0;
    } else {
	s_wsfe(&io___24);
	e_wsfe();
	io___25.ciunit = ir;
	s_rsue(&io___25);
	do_uio(&c__9, (char *)&ipow[1], (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*iloop), (ftnlen)sizeof(integer));
	e_rsue();
	io___26.ciunit = ir;
	s_rsue(&io___26);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___27.ciunit = ir;
	s_rsue(&io___27);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&grad[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___28.ciunit = ir;
	s_rsue(&io___28);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = geovar_1.nvar;
	    for (j = 1; j <= i__2; ++j) {
		do_uio(&c__1, (char *)&hess[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	io___29.ciunit = ir;
	s_rsue(&io___29);
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = geovar_1.nvar;
	    for (j = 1; j <= i__1; ++j) {
		do_uio(&c__1, (char *)&bmat[j + i__ * 360], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	funct1 = sqrt(dot_(&grad[1], &grad[1], &geovar_1.nvar));
	s_wsfe(&io___30);
	do_fio(&c__1, (char *)&funct1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	linear = geovar_1.nvar * (geovar_1.nvar + 1) / 2;
	io___31.ciunit = ir;
	s_rsue(&io___31);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&pmat[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	if (i_indx(keywrd_1.keywrd, "AIDER", (ftnlen)241, (ftnlen)5) != 0) {
	    io___32.ciunit = ir;
	    s_rsue(&io___32);
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&errfn_1.aicorr[i__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_rsue();
	}
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	s_rsue(&io___33);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
	if (molkst_1.nalpha != 0) {
	    s_rsue(&io___34);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsue();
	}
	if (path_1.latom != 0) {
	    io___35.ciunit = ir;
	    s_rsue(&io___35);
	    i__1 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    do_uio(&c__1, (char *)&alparm_1.alparm[j + i__ * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		}
	    }
	    e_rsue();
	    io___36.ciunit = ir;
	    s_rsue(&io___36);
	    do_uio(&c__1, (char *)&alparm_1.jloop, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&alparm_1.x0, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x1, (ftnlen)sizeof(doublereal));
	    do_uio(&c__1, (char *)&alparm_1.x2, (ftnlen)sizeof(doublereal));
	    e_rsue();
	    ++(*iloop);
	}
	++(*iloop);
	return 0;
    }
    return 0;
} /* powsav_ */

