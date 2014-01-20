/* drc.f -- translated by f2c (version 20020621).
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
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal xract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer mcoprt[720]	/* was [2][360] */, ncoprt;
    logical prtmax;
} drccom_;

#define drccom_1 drccom_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__5 = 5;
static integer c__3 = 3;
static integer c__8 = 8;
static doublereal c_b125 = .5;
static logical c_true = TRUE_;
static doublereal c_b138 = .25;

/* Subroutine */ int drc_(doublereal *startv, doublereal *startk)
{
    /* Initialized data */

    static doublereal velo0[360] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static logical addk = TRUE_;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3, d__4;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void), 
	    s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    double d_sign(doublereal *, doublereal *);
    integer f_rew(alist *), s_rsfe(cilist *), e_rsfe(void), s_rsle(cilist *), 
	    e_rsle(void);
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);
    integer f_clos(cllist *), s_wsue(cilist *), do_uio(integer *, char *, 
	    ftnlen), e_wsue(void);

    /* Local variables */
    static integer i__, j, k, l, i1, ii, kl;
    static doublereal ams, one;
    static logical let;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static integer ilp;
    static doublereal sum, half, accu, escf, ekin, etot, gtot, summ, tnow, 
	    velo1[360], velo2[360], velo3[360];
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal alpha, coord[360]	/* was [3][120] */, grold[360], 
	    past10[10], gnlim, etold, quadr;
    static integer iskin;
    static doublereal const__;
    static logical letot;
    static integer iloop;
    static doublereal error, elost, dummy, delta1, dlold2, grold2[360], 
	    elost1, addonk, delold;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static doublereal georef[360]	/* was [3][120] */;
    static logical velred;
    extern doublereal second_(void);
    static doublereal deltat, velvec, oldtim, gerror[360];
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);
    static doublereal summas;
    static integer iupper;
    static doublereal scfold;
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), prtdrc_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static doublereal tcycle;
    static integer linear;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 6, 0, "(A)", 0 };
    static cilist io___13 = { 0, 6, 0, "(3F13.5)", 0 };
    static cilist io___15 = { 0, 6, 0, 0, 0 };
    static cilist io___21 = { 0, 6, 0, "(//10X,' DAMPING FACTOR FOR KINETIC "
	    "ENERGY =',F12.6)", 0 };
    static cilist io___25 = { 0, 6, 0, "(//10X,' EXCESS KINETIC ENERGY ENTER"
	    "ED INTO SYSTEM =',F12.6)", 0 };
    static cilist io___31 = { 0, 9, 0, "(A80)", 0 };
    static cilist io___33 = { 0, 9, 0, "(3F19.13)", 0 };
    static cilist io___34 = { 0, 9, 0, "(A80)", 0 };
    static cilist io___35 = { 0, 9, 0, "(3F19.3)", 0 };
    static cilist io___36 = { 0, 9, 0, "(A80)", 0 };
    static cilist io___37 = { 0, 9, 0, 0, 0 };
    static cilist io___38 = { 0, 9, 0, 0, 0 };
    static cilist io___40 = { 0, 9, 0, 0, 0 };
    static cilist io___42 = { 0, 9, 0, 0, 0 };
    static cilist io___47 = { 0, 6, 0, "(//10X,'CALCULATION RESTARTED, CURRE"
	    "NT',            ' KINETIC ENERGY=',F10.5,//)", 0 };
    static cilist io___57 = { 0, 6, 0, "(A,F10.3,A,/,A)", 0 };
    static cilist io___58 = { 0, 6, 0, "(A,F7.2,A)", 0 };
    static cilist io___59 = { 0, 6, 0, "(A,F9.2,A)", 0 };
    static cilist io___60 = { 0, 6, 0, "(A)", 0 };
    static cilist io___61 = { 0, 6, 0, "(A)", 0 };
    static cilist io___74 = { 0, 6, 0, "(//,' IRC CALCULATION COMPLETE ')", 0 
	    };
    static cilist io___75 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___78 = { 0, 9, 0, "(A)", 0 };
    static cilist io___79 = { 0, 9, 0, "(3F19.13)", 0 };
    static cilist io___80 = { 0, 9, 0, "(A)", 0 };
    static cilist io___81 = { 0, 9, 0, "(3F19.3)", 0 };
    static cilist io___82 = { 0, 9, 0, "(A)", 0 };
    static cilist io___83 = { 0, 9, 0, 0, 0 };
    static cilist io___84 = { 0, 9, 0, 0, 0 };
    static cilist io___85 = { 0, 9, 0, 0, 0 };
    static cilist io___86 = { 0, 9, 0, 0, 0 };
    static cilist io___88 = { 0, 10, 0, 0, 0 };
    static cilist io___89 = { 0, 10, 0, 0, 0 };
    static cilist io___90 = { 0, 6, 0, "(//10X,' RUNNING OUT OF TIME, RESTAR"
	    "T FILE WRITTEN')", 0 };
    static cilist io___91 = { 0, 6, 0, "(A)", 0 };


/* *********************************************************************** */
/*                                                                      * */
/*    DRC IS DESIGNED TO FOLLOW A REACTION PATH FROM THE TRANSITION     * */
/*    STATE.  TWO MODES ARE SUPPORTED, FIRST: GAS PHASE:- AS THE SYSTEM * */
/*    MOVES FROM THE T/S THE MOMENTUM OF THE ATOMS IS STORED AND THE    * */
/*    POSITION OF THE ATOMS IS RELATED TO THE OLD POSITION BY (A) THE   * */
/*    CURRENT VELOCITY OF THE ATOM, AND (B) THE FORCES ACTING ON THAT   * */
/*    ATOM.  THE SECOND MODE IS CONDENSED PHASE, IN WHICH THE ATOMS MOVE* */
/*    IN RESPONSE TO THE FORCES ACTING ON THEM. I.E. INFINITELY DAMPED  * */
/*                                                                      * */
/* *********************************************************************** */
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
    --startk;
    --startv;

    /* Function Body */
    tnow = second_();
    oldtim = second_();
    delold = 10.;
    gtot = 0.;
    o__1.oerr = 0;
    o__1.ounit = 7;
    o__1.ofnm = 0;
    o__1.orl = 0;
    o__1.osta = "SCRATCH";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    if (i_indx(keywrd_1.keywrd, " PREC", (ftnlen)241, (ftnlen)5) != 0) {
	accu = .25;
    } else {
	accu = 1.;
    }
    gnlim = 1.;
    past10[4] = 100.;
    i__ = i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5);
    if (i__ != 0) {
	gnlim = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    velred = i_indx(keywrd_1.keywrd, "VELO", (ftnlen)241, (ftnlen)4) != 0;
    i__1 = molkst_1.numat * 3;
    if (dot_(&startv[1], &startv[1], &i__1) > .001) {

/*     PRINT OUT INITIAL VELOCITIES */

	s_wsfe(&io___12);
	do_fio(&c__1, " INITIAL VELOCITY IN DRC", (ftnlen)24);
	e_wsfe();
	s_wsfe(&io___13);
	i__1 = molkst_1.numat * 3;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&startv[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    let = i_indx(keywrd_1.keywrd, " GEO-OK", (ftnlen)241, (ftnlen)7) != 0 || 
	    velred;
    if (i_indx(keywrd_1.keywrd, " SYM", (ftnlen)241, (ftnlen)4) != 0) {
	s_wsle(&io___15);
	do_lio(&c__9, &c__1, "  SYMMETRY SPECIFIED, BUT CANNOT BE USED IN DRC"
		, (ftnlen)47);
	e_wsle();
	geosym_1.ndep = 0;
    }

/*      CONVERT TO CARTESIAN COORDINATES, IF NOT ALREADY DONE. */

    if (i_indx(keywrd_1.keywrd, " XYZ", (ftnlen)241, (ftnlen)4) == 0) {
	geokst_1.na[0] = 0;
	gmetry_(geom_1.geo, coord);
	l = 0;

	for (j = 1; j <= 3; ++j) {
	    i__1 = molkst_1.numat;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		geom_1.geo[j + i__ * 3 - 4] = coord[j + i__ * 3 - 4];
		coord[j + i__ * 3 - 4] = 0.;
/* L20: */
	    }
/* L30: */
	}

	geokst_1.na[0] = 99;
    }

/*  TRANSFER COORDINATES TO XPARAM AND LOC */

    if (i_indx(keywrd_1.keywrd, " DRC", (ftnlen)241, (ftnlen)4) != 0) {
	drccom_1.prtmax = geovar_1.loc[0] == 1;
	if (drccom_1.prtmax) {
	    j = 1;
	} else {
	    j = 0;
	}
	geovar_1.nvar -= j;
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    drccom_1.mcoprt[(i__ << 1) - 2] = geovar_1.loc[(i__ + j << 1) - 2]
		    ;
/* L40: */
	    drccom_1.mcoprt[(i__ << 1) - 1] = geovar_1.loc[(i__ + j << 1) - 1]
		    ;
	}
	if (geovar_1.loc[0] == 0) {
	    geovar_1.nvar = 0;
	}
	drccom_1.ncoprt = geovar_1.nvar;
    } else {
	drccom_1.ncoprt = 0;
    }
    l = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	geovar_1.loc[(l + 1 << 1) - 2] = i__;
	geovar_1.loc[(l + 1 << 1) - 1] = 1;
	georef[i__ * 3 - 3] = geom_1.geo[i__ * 3 - 3];
	geovar_1.xparam[l] = geom_1.geo[i__ * 3 - 3];

	geovar_1.loc[(l + 2 << 1) - 2] = i__;
	geovar_1.loc[(l + 2 << 1) - 1] = 2;
	georef[i__ * 3 - 2] = geom_1.geo[i__ * 3 - 2];
	geovar_1.xparam[l + 1] = geom_1.geo[i__ * 3 - 2];

	geovar_1.loc[(l + 3 << 1) - 2] = i__;
	geovar_1.loc[(l + 3 << 1) - 1] = 3;
	georef[i__ * 3 - 1] = geom_1.geo[i__ * 3 - 1];
	geovar_1.xparam[l + 2] = geom_1.geo[i__ * 3 - 1];

	l += 3;
/* L50: */
    }
    geovar_1.nvar = molkst_1.numat * 3;

/* DETERMINE DAMPING FACTOR */

    if (i_indx(keywrd_1.keywrd, "DRC=", (ftnlen)241, (ftnlen)4) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "DRC=", (ftnlen)241, (ftnlen)4);
	half = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___21);
	do_fio(&c__1, (char *)&half, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else if (i_indx(keywrd_1.keywrd, "DRC", (ftnlen)241, (ftnlen)3) == 0) {
	half = 0.;
    } else {
	half = 1e6;
    }

/*  LETOT IS TRUE IF CORRECTIONS ARE NOT TO BE MADE PART WAY INTO */
/*        THE CALCULATION */

/*  USAGE OF LETOT: */
/* (1) WHILE LETOT IS FALSE, NO DAMPING WILL BE DONE */
/* (2) WHEN LETOT IS TURNED TRUE, */
/*     IF AN IRC, THEN ETOT IS RESET SO THE ERROR IS ZERO. */
/*     IF A  DRC, EXCESS KINETIC ENERGY USED TO START THE RUN IS REMOVED. */

    letot = i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) == 0 && ! 
	    let;
/* Computing MAX */
    d__2 = 1e-6, d__3 = abs(half);
    d__1 = max(d__2,d__3);
    half = d_sign(&d__1, &half);

/* DETERMINE EXCESS KINETIC ENERGY */

    iskin = 0;
    if (i_indx(keywrd_1.keywrd, "KINE", (ftnlen)241, (ftnlen)4) != 0) {
	iskin = 1;
	i__1 = i_indx(keywrd_1.keywrd, "KINE", (ftnlen)241, (ftnlen)4);
	addonk = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___25);
	do_fio(&c__1, (char *)&addonk, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	addonk = 0.;
    }

/*   LOOP OVER TIME-INTERVALS OF DELTAT SECOND */

    deltat = 1e-16;
    quadr = 1.;
    etot = 0.;
    escf = 0.;
    const__ = 1.;
    if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0 && 
	    i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) == 0) {

/*  RESTART FROM A PREVIOUS RUN */

	o__1.oerr = 0;
	o__1.ounit = 9;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR009", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "UNKNOWN";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
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
	s_rsfe(&io___31);
	do_fio(&c__1, (char *)&alpha, (ftnlen)sizeof(doublereal));
	e_rsfe();
	s_rsfe(&io___33);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&geovar_1.xparam[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsfe();
	s_rsfe(&io___34);
	do_fio(&c__1, (char *)&alpha, (ftnlen)sizeof(doublereal));
	e_rsfe();
	s_rsfe(&io___35);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&velo0[i__ - 1], (ftnlen)sizeof(doublereal))
		    ;
	}
	e_rsfe();
	s_rsfe(&io___36);
	do_fio(&c__1, (char *)&alpha, (ftnlen)sizeof(doublereal));
	e_rsfe();
	s_rsle(&io___37);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)
		    sizeof(doublereal));
	}
	e_rsle();
	s_rsle(&io___38);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&grold[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsle();
	s_rsle(&io___40);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_lio(&c__5, &c__1, (char *)&grold2[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsle();
	s_rsle(&io___42);
	do_lio(&c__5, &c__1, (char *)&etot, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&delold, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&deltat, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&dlold2, (ftnlen)sizeof(doublereal));
	do_lio(&c__3, &c__1, (char *)&iloop, (ftnlen)sizeof(integer));
	do_lio(&c__5, &c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(
		doublereal));
	do_lio(&c__8, &c__1, (char *)&letot, (ftnlen)sizeof(logical));
	do_lio(&c__5, &c__1, (char *)&elost1, (ftnlen)sizeof(doublereal));
	do_lio(&c__5, &c__1, (char *)&gtot, (ftnlen)sizeof(doublereal));
	e_rsle();
	s_wsfe(&io___47);
	do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
	e_wsfe();
	goto L100;
    } else {
/*                         NOT A RESTART */
	iloop = 1;
	if (i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) != 0 || 
		velred) {

/*  GET HOLD OF VELOCITY VECTOR */

	    if (i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) != 0) 
		    {
		i__1 = i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4)
			;
		k = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    } else {
		k = 1;
	    }
	    if (k < 0) {
		k = -k;
		one = -1.;
	    } else {
		one = 1.;
	    }
	    kl = (k - 1) * geovar_1.nvar;
	    summ = 0.;
	    velo1[0] = 0.;
	    velo1[1] = 0.;
	    velo1[2] = 0.;
	    summas = 0.;
	    i__ = 0;
	    i__1 = molkst_1.numat;
	    for (ii = 1; ii <= i__1; ++ii) {
		ams = atmass_1.atmass[ii - 1];
		summas += ams;
		velo0[i__] = startv[kl + i__ + 1] * one;
		velo1[0] += velo0[i__] * ams;

		velo0[i__ + 1] = startv[kl + i__ + 2] * one;
		velo1[1] += velo0[i__ + 1] * ams;

		velo0[i__ + 2] = startv[kl + i__ + 3] * one;
		velo1[2] += velo0[i__ + 2] * ams;

		i__ += 3;
/* L60: */
	    }
/* $DOIT ASIS */
	    for (i__ = 1; i__ <= 3; ++i__) {
/* L70: */
		velo1[i__ - 1] = -velo1[i__ - 1] / summas;
	    }
	    i__ = 0;
/* $DOIT ASIS */
	    i__1 = molkst_1.numat;
	    for (ii = 1; ii <= i__1; ++ii) {
		ams = atmass_1.atmass[ii - 1];
/* $DOIT ASIS */
		for (i1 = 1; i1 <= 3; ++i1) {
		    ++i__;
		    if (addonk > 1e-5 || ! velred) {
			velo0[i__ - 1] += velo1[i1 - 1];
		    }
/* L80: */
/* Computing 2nd power */
		    d__1 = velo0[i__ - 1];
		    summ += d__1 * d__1 * ams;
		}
	    }
	    if (addonk < 1e-5 && velred) {
		addonk = summ * .5 / 4.184e10;
	    }
	    if (addonk < 1e-5 && ! velred) {
		if (abs(half) > .001 && startk[k] > 105.) {
		    s_wsfe(&io___57);
		    do_fio(&c__1, " BY DEFAULT, ONE QUANTUM OF ENERGY, EQUIV"
			    "ALENT TO", (ftnlen)49);
		    do_fio(&c__1, (char *)&startk[k], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, " CM(-1)", (ftnlen)7);
		    do_fio(&c__1, " WILL BE USED TO START THE DRC", (ftnlen)
			    30);
		    e_wsfe();

/*    2.8585086D-3 CONVERTS CM(-1) INTO KCAL/MOLE */

		    addonk = startk[k] * .0028585086;
		    s_wsfe(&io___58);
		    do_fio(&c__1, " THIS REPRESENTS AN ENERGY OF", (ftnlen)29)
			    ;
		    do_fio(&c__1, (char *)&addonk, (ftnlen)sizeof(doublereal))
			    ;
		    do_fio(&c__1, " KCALS/MOLE", (ftnlen)11);
		    e_wsfe();
		} else if (abs(half) > .001) {
		    s_wsfe(&io___59);
		    do_fio(&c__1, " THE VIBRATIONAL FREQUENCY (", (ftnlen)28);
		    do_fio(&c__1, (char *)&startk[k], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, "CM(-1)) IS TOO SMALL", (ftnlen)20);
		    do_fio(&c__1, " FOR ONE QUANTUM TO BE USED", (ftnlen)27);
		    e_wsfe();
		    s_wsfe(&io___60);
		    do_fio(&c__1, " INSTEAD 0.3KCAL/MOLE WILL BE USED TO STA"
			    "RT THE IRC", (ftnlen)51);
		    e_wsfe();
		    addonk = .3;
		} else {
		    addonk = .3;
		}
	    }

/*   AT THIS POINT ADDONK IS IN KCAL/MOLE */
/*   NORMALIZE SO THAT TOTAL K.E. = ONE QUANTUM (DEFAULT) (DRC ONLY) */
/*                              OR 0.3KCAL/MOLE (IRC ONLY) */
/*                              OR ADDONK IF KINETIC=NN SUPPLIED */

	    if (summ < 1e-4) {
		s_wsfe(&io___61);
		do_fio(&c__1, " SYSTEM IS APPARENTLY NOT MOVING!", (ftnlen)33)
			;
		e_wsfe();
		return 0;
	    }

/*  ADDONK IS EXCESS KINETIC ENERGY.  IF THE CALCULATION IS AN IRC, */
/*  THIS ENERGY MUST BE REMOVED AFTER A SHORT 'TIME'. */

/*  MAKE AN AD-HOC CORRECTION: IF ADDONK IS NON-ZERO AND HALF IS LARGER */
/*  THAN 0.1, MODIFY ADDONK TO REFLECT ERRORS DUE TO START-UP. */

	    if (half > .1 && half < 1e4) {
		addonk *= .06972 / half + 1.;
	    }

/*  MAKE AN AD-HOC CORRECTION: IF ADDONK IS NON-ZERO AND HALF IS LESS */
/*  THAN -0.1, MODIFY ADDONK TO REFLECT ERRORS DUE TO START-UP. */

	    if (half < -.1 && half > -1e4) {
		addonk *= .06886 / half + 1.;
	    }
	    summ = sqrt(addonk / (summ * .5 / 4.184e10));
	    addk = FALSE_;
	    if (summ > 1e-10) {
		i__1 = geovar_1.nvar;
		for (i__ = 1; i__ <= i__1; ++i__) {
/* L90: */
		    velo0[i__ - 1] *= summ;
		}

/*  IF IT IS A DRC, DESTROY ADDONK.  THE KINETIC ENERGY USED WILL COME */
/*  FROM THE VELOCITY ONLY. */

		if (half > .001) {
		    addonk = 0.;
		}
	    }
	}
    }
L100:
    iupper = iloop + 4999;
    ilp = iloop;
    one = 0.;
    if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0 && 
	    i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) == 0) {
	one = 1.;
    }
    i__1 = iupper;
    for (iloop = ilp; iloop <= i__1; ++iloop) {

/*  MOVEMENT OF ATOMS WILL BE PROPORTIONAL TO THE AVERAGE VELOCITIES */
/*  OF THE ATOMS BEFORE AND AFTER TIME INTERVAL */


/*  RAPID CHANGE IN GRADIENT IMPLIES SMALL STEP SIZE FOR DELTAT */

/*   KINETIC ENERGY = 1/2 * M * V * V */
/*                  = 0.5 / (4.184D10) * M * V * V */
/*   NEW VELOCITY = OLD VELOCITY + GRADIENT * TIME / MASS */
/*                = KCAL/ANGSTROM*SECOND/(ATOMIC WEIGHT) */
/*                =4.184*10**10(ERGS)*10**8(PER CM)*DELTAT(SECONDS) */
/*   NEW POSITION = OLD POSITION - AVERAGE VELOCITY * TIME INTERVAL */


/*   ESTABLISH REFERENCE TOTAL ENERGY */

	error = etot - (ekin + escf);
	if (iloop > 2) {
	    quadr = error / (ekin * const__ + .001) * .5 + 1.;
/* Computing MIN */
	    d__1 = 1.3, d__2 = max(.8,quadr);
	    quadr = min(d__1,d__2);
	} else {
	    quadr = 1.;
	}
	if ((let || ekin > .2f) && addk) {

/*   DUMP IN EXCESS KINETIC ENERGY */

	    etot += addonk;
	    addk = FALSE_;
	    addonk = 0.;
	}

/*  CALCULATE THE DURATION OF THE NEXT STEP. */
/*  STEP SIZE IS THAT REQUIRED TO PRODUCE A CONSTANT CHANGE IN GEOMETRY */


/*  IF DAMPING IS USED, CALCULATE THE NEW TOTAL ENERGY AND */
/*  THE RATIO FOR REDUCING THE KINETIC ENERGY */

/* Computing MAX */
	d__3 = deltat * 1e15 / half;
	d__1 = 1e-36, d__2 = pow_dd(&c_b125, &d__3);
	const__ = max(d__1,d__2);
	const__ = sqrt(const__);
	velvec = 0.;
	ekin = 0.;
	delta1 = delold + dlold2;
	elost = 0.;
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {

/*   CALCULATE COMPONENTS OF VELOCITY AS */
/*   V = V(0) + V'*T + V"*T*T */
/*   WE NEED ALL THREE TERMS, V(0), V' AND V" */

	    velo1[i__ - 1] = 1. / atmass_1.atmass[geovar_1.loc[(i__ << 1) - 2]
		     - 1] * gradnt_1.grad[i__ - 1];
	    if (iloop > 3) {
/* Computing 2nd power */
		d__1 = delold;
/* Computing 2nd power */
		d__2 = delta1;
		velo3[i__ - 1] = 2. / atmass_1.atmass[geovar_1.loc[(i__ << 1) 
			- 2] - 1] * (delta1 * (grold[i__ - 1] - gradnt_1.grad[
			i__ - 1]) - delold * (grold2[i__ - 1] - gradnt_1.grad[
			i__ - 1])) / (delta1 * (d__1 * d__1 * 1e30) - delold *
			 (d__2 * d__2 * 1e30));
/* Computing 2nd power */
		d__1 = delold;
		velo2[i__ - 1] = 1. / atmass_1.atmass[geovar_1.loc[(i__ << 1) 
			- 2] - 1] * (gradnt_1.grad[i__ - 1] - grold[i__ - 1] 
			- velo3[i__ - 1] * .5 * (d__1 * d__1 * 1e30)) / (
			delold * 1e15);
	    } else {
		velo2[i__ - 1] = 1. / atmass_1.atmass[geovar_1.loc[(i__ << 1) 
			- 2] - 1] * (gradnt_1.grad[i__ - 1] - grold[i__ - 1]) 
			/ (delold * 1e15);
		velo3[i__ - 1] = 0.;
	    }

/*  MOVE ATOMS THROUGH DISTANCE EQUAL TO VELOCITY * DELTA-TIME, NOTE */
/*  VELOCITY CHANGES FROM START TO FINISH, THEREFORE AVERAGE. */

/* Computing 2nd power */
	    d__1 = deltat;
/* Computing 2nd power */
	    d__2 = deltat;
/* Computing 2nd power */
	    d__3 = deltat;
/* Computing 2nd power */
	    d__4 = deltat;
	    geovar_1.xparam[i__ - 1] -= (deltat * velo0[i__ - 1] * one + d__1 
		    * d__1 * .5 * velo1[i__ - 1] + d__2 * d__2 * 1e15 * 
		    .16666 * deltat * velo2[i__ - 1] + d__3 * d__3 * .0416666 
		    * (d__4 * d__4 * 1e30) * velo3[i__ - 1]) * 1e8;

/*   CORRECT ERRORS DUE TO CUBIC COMPONENTS IN ENERGY GRADIENT, */
/*   ALSO TO ADD ON EXCESS ENERGY, IF NECESSARY. */

/* Computing 2nd power */
	    d__1 = velo0[i__ - 1];
	    velvec += d__1 * d__1;

/*   MODIFY VELOCITY IN LIGHT OF CURRENT ENERGY GRADIENTS. */

/*   VELOCITY = OLD VELOCITY + (DELTA-T / ATOMIC MASS) * CURRENT GRADIENT */
/*                           + 1/2 *(DELTA-T * DELTA-T /ATOMIC MASS) * */
/*                             (SLOPE OF GRADIENT) */
/*              SLOPE OF GRADIENT = (GRAD(I)-GROLD(I))/DELOLD */


/*   THIS EXPRESSION IS ACCURATE TO SECOND ORDER IN TIME. */

/* Computing 2nd power */
	    d__1 = deltat;
/* Computing 2nd power */
	    d__2 = deltat;
	    velo0[i__ - 1] = velo0[i__ - 1] + deltat * velo1[i__ - 1] + d__1 *
		     d__1 * .5 * velo2[i__ - 1] * 1e15 + deltat * .166666 * (
		    d__2 * d__2 * 1e30) * velo3[i__ - 1];
	    if (let || gradnt_1.gnorm > 3.) {
		let = TRUE_;
/* Computing 2nd power */
		d__1 = velo0[i__ - 1];
/* Computing 2nd power */
		d__2 = const__;
		elost += d__1 * d__1 * atmass_1.atmass[geovar_1.loc[(i__ << 1)
			 - 2] - 1] * (1 - d__2 * d__2);
		velo0[i__ - 1] = velo0[i__ - 1] * const__ * quadr;
	    }

/*  CALCULATE KINETIC ENERGY (IN 2*ERGS AT THIS POINT) */

/* Computing 2nd power */
	    d__1 = velo0[i__ - 1];
	    ekin += d__1 * d__1 * atmass_1.atmass[geovar_1.loc[(i__ << 1) - 2]
		     - 1];
/* L110: */
	}
	one = 1.;
	if (let || gradnt_1.gnorm > 3.) {
	    if (! letot) {
		if (abs(half) < .001) {

/*  IT IS AN IRC, SO RESET THE TOTAL ENERGY */

		    etot = escf + elost1;
		    addonk = 0.;
		    elost1 = 0.;
		    elost = 0.;
		} else if (iskin == 0) {

/*  IT IS A DRC AND KINETIC NOT USED, SO REMOVE EXTRA KINETIC ENERGY */

		    etot -= addonk;
		}
	    }
	    letot = TRUE_;
	}

/*  CONVERT ENERGY INTO KCAL/MOLE */

	ekin = ekin * .5 / 4.184e10;

/*  IF IT IS A DAMPED DRC, MODIFY ETOT TO REFLECT LOSS OF KINETIC ENERGY */

	if (letot && abs(half) > 1e-5) {
/* Computing 2nd power */
	    d__1 = const__;
	    etot = etot - ekin / (d__1 * d__1) + ekin;
	}
	elost1 += elost * .5 / 4.184e10;

/* STORE OLD GRADIENTS FOR DELTA - VELOCITY CALCULATION */

	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    grold2[i__ - 1] = grold[i__ - 1];
	    grold[i__ - 1] = gradnt_1.grad[i__ - 1];
/* L120: */
	    gradnt_1.grad[i__ - 1] = 0.;
	}

/*   CALCULATE ENERGY AND GRADIENTS */

	scfold = escf;
	compfg_(geovar_1.xparam, &c_true, &escf, &c_true, gradnt_1.grad, &
		c_true);
	if (iloop > 2) {
	    gradnt_1.gnorm = 0.;
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; i__ += 3) {
		sum = sqrt(dot_(&gradnt_1.grad[i__ - 1], &gradnt_1.grad[i__ - 
			1], &c__3) / (dot_(&velo0[i__ - 1], &velo0[i__ - 1], &
			c__3) + 1e-20));
		i__3 = i__ + 2;
		for (j = i__; j <= i__3; ++j) {
/* L130: */
		    gerror[j - 1] = gerror[j - 1] + gradnt_1.grad[j - 1] + 
			    velo0[j - 1] * sum;
		}
/* L140: */
	    }
	    gradnt_1.gnorm = sqrt(dot_(gerror, gerror, &geovar_1.nvar));
	    gtot = gradnt_1.gnorm;
	}
	gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, &
		geovar_1.nvar));

/*   CONVERT GRADIENTS INTO ERGS/CM */

	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L150: */
	    gradnt_1.grad[i__ - 1] *= 4.184e18;
	}

/*   SPECIAL TREATMENT FOR FIRST POINT - SET "OLD" GRADIENTS EQUAL TO */
/*   CURRENT GRADIENTS. */

	if (iloop == 1) {
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L160: */
		grold[i__ - 1] = gradnt_1.grad[i__ - 1];
	    }
	}
	dlold2 = delold;
	delold = deltat;
	sum = 0.;
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L170: */
/* Computing 2nd power */
	    d__1 = (gradnt_1.grad[i__ - 1] - grold[i__ - 1]) / 4.184e18;
	    sum += d__1 * d__1;
	}
	if (abs(half) < .001) {
/* Computing MIN */
	    d__3 = 2., d__4 = accu * 5e-5 / ((d__1 = escf + elost1 - etold, 
		    abs(d__1)) + 1e-20);
	    d__2 = min(d__3,d__4);
	    deltat *= pow_dd(&d__2, &c_b138);
	    etold = escf + elost1;
	    if (iloop > 5 && scfold - escf < -.001 || iloop > 30 && scfold - 
		    escf < 0.) {
		s_wsfe(&io___74);
		e_wsfe();
		return 0;
	    }
	} else {
/* Computing MIN */
	    d__1 = 1.05, d__2 = accu * 10. / (sum + 1e-4);
	    deltat *= min(d__1,d__2);
/* Computing MIN */
	    d__1 = deltat, d__2 = accu * 3e-15;
	    deltat = min(d__1,d__2);
	    past10[9] = gradnt_1.gnorm;
	    sum = 0.;
	    for (i__ = 1; i__ <= 9; ++i__) {
		sum += (d__1 = past10[i__ - 1] - past10[i__], abs(d__1));
/* L180: */
		past10[i__ - 1] = past10[i__];
	    }
	    if (sum < gnlim) {
		s_wsfe(&io___75);
		do_fio(&c__1, " GRADIENT CONSTANT AND SMALL -- ASSUME ALL MO"
			"TION STOPPED", (ftnlen)57);
		e_wsfe();
		return 0;
	    }
	    deltat = min(deltat,2e-15);
/* *********************************************************************** */

/*         TESTING CODE - REMOVE BEFORE FINAL VERSION ASSEMBLED */
/* #          (ILOOP/400)*400.EQ.ILOOP)DELTAT=-DELTAT */

/* *********************************************************************** */
	}
	deltat = max(1e-16,deltat);
	if (abs(half) < 1e-5) {

/*   FOR THE IRC: */

/* ESCF   = POTENTIAL ENERGY */
/* ELOST1 = ENERGY LOST (IN DRC, THIS WOULD HAVE BEEN THE KINETIC ENERGY) */
/* ETOT   = COMPUTED TOTAL ENERGY = STARTING POTENTIAL ENERGY */

/*   IN DRCOUT  'TOTAL' = ESCF + ELOST1 */
/*              'ERROR' = ESCF + ELOST1 - ETOT */

	    prtdrc_(&escf, &deltat, geovar_1.xparam, georef, &elost1, &gtot, &
		    etot, velo0, &geovar_1.nvar);
	} else {

/*   FOR THE DRC: */

/* ESCF   = POTENTIAL ENERGY */
/* EKIN   = CURRENT KINETIC ENERGY */
/* ETOT   = COMPUTED TOTAL ENERGY = STARTING POTENTIAL ENERGY - */
/*          KINETIC ENERGY LOST THROUGH DAMPING, IF PRESENT. */

/*   IN DRCOUT  'TOTAL' = ESCF + EKIN */
/*              'ERROR' = ESCF + EKIN - ETOT */

	    prtdrc_(&escf, &deltat, geovar_1.xparam, georef, &ekin, &dummy, &
		    etot, velo0, &geovar_1.nvar);
	}
	tnow = second_();
	tcycle = tnow - oldtim;
	oldtim = tnow;
	timdmp_1.tleft -= tcycle;
	if (iloop == iupper || timdmp_1.tleft < tcycle * 3) {
L46:
	    o__1.oerr = 1;
	    o__1.ounit = 9;
	    o__1.ofnmlen = 80;
	    getnam_(ch__1, (ftnlen)80, "FOR009", (ftnlen)6);
	    o__1.ofnm = ch__1;
	    o__1.orl = 0;
	    o__1.osta = "NEW";
	    o__1.oacc = 0;
	    o__1.ofm = "FORMATTED";
	    o__1.oblnk = 0;
	    i__2 = f_open(&o__1);
	    if (i__2 != 0) {
		goto L45;
	    }
	    goto L47;
L45:
	    o__1.oerr = 0;
	    o__1.ounit = 9;
	    o__1.ofnmlen = 80;
	    getnam_(ch__1, (ftnlen)80, "FOR009", (ftnlen)6);
	    o__1.ofnm = ch__1;
	    o__1.orl = 0;
	    o__1.osta = "OLD";
	    o__1.oacc = 0;
	    o__1.ofm = 0;
	    o__1.oblnk = 0;
	    f_open(&o__1);
	    cl__1.cerr = 0;
	    cl__1.cunit = 9;
	    cl__1.csta = "DELETE";
	    f_clos(&cl__1);
	    goto L46;
L47:
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
	    s_wsfe(&io___78);
	    do_fio(&c__1, " CARTESIAN GEOMETRY PARAMETERS IN ANGSTROMS", (
		    ftnlen)43);
	    e_wsfe();
	    s_wsfe(&io___79);
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, (char *)&geovar_1.xparam[i__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___80);
	    do_fio(&c__1, " VELOCITY FOR EACH CARTESIAN COORDINATE, IN CM/SEC"
		    , (ftnlen)50);
	    e_wsfe();
	    s_wsfe(&io___81);
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, (char *)&velo0[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    s_wsfe(&io___82);
	    do_fio(&c__1, " FIRST, SECOND, AND THIRD-ORDER GRADIENTS, ETC", (
		    ftnlen)46);
	    e_wsfe();
	    s_wsle(&io___83);
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_lio(&c__5, &c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsle();
	    s_wsle(&io___84);
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_lio(&c__5, &c__1, (char *)&grold[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsle();
	    s_wsle(&io___85);
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_lio(&c__5, &c__1, (char *)&grold2[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsle();
	    i__ = iloop + 1;
	    s_wsle(&io___86);
	    do_lio(&c__5, &c__1, (char *)&etot, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&delold, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&deltat, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&dlold2, (ftnlen)sizeof(doublereal));
	    do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_lio(&c__5, &c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(
		    doublereal));
	    do_lio(&c__8, &c__1, (char *)&letot, (ftnlen)sizeof(logical));
	    do_lio(&c__5, &c__1, (char *)&elost1, (ftnlen)sizeof(doublereal));
	    do_lio(&c__5, &c__1, (char *)&gtot, (ftnlen)sizeof(doublereal));
	    e_wsle();
	    escf = -1e9;
	    prtdrc_(&escf, &deltat, geovar_1.xparam, georef, &ekin, &elost, &
		    etot, velo0, &geovar_1.nvar);
	    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	    s_wsue(&io___88);
	    i__2 = linear;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsue();
	    if (molkst_1.nalpha != 0) {
		s_wsue(&io___89);
		i__2 = linear;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsue();
	    }
	    s_wsfe(&io___90);
	    e_wsfe();
	    s_wsfe(&io___91);
	    do_fio(&c__1, " GEOMETRY AND VELOCITY ARE IN RESTART FILE IN ASC"
		    "II", (ftnlen)51);
	    e_wsfe();
	    return 0;
	}
/* L190: */
    }
    return 0;
} /* drc_ */

