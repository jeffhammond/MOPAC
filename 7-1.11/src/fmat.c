/* fmat.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal r__[1680]	/* was [14][120] */;
    integer nsym, ipo[14400]	/* was [120][120] */, nent;
} symops_;

#define symops_1 symops_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal dumy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal p[45150], pdumy[90300]	/* was [2][45150] */;
} densty_;

#define densty_1 densty_

struct {
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    doublereal time0;
} timec_;

#define timec_1 timec_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal coord[360]	/* was [3][120] */;
} coord_;

#define coord_1 coord_

struct {
    doublereal evecs[129600], bmat[259200]	/* was [360][720] */;
} nllcom_;

#define nllcom_1 nllcom_

/* Table of constant values */

static integer c__1 = 1;
static logical c_true = TRUE_;
static integer c__0 = 0;

/* Subroutine */ int fmat_(doublereal *fmatrx, integer *nreal, doublereal *
	tscf, doublereal *tder, doublereal *deldip, doublereal *heat)
{
    /* Initialized data */

    static doublereal fact = .00695125;

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    double sqrt(doublereal);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal q[120];
    static integer ii, kk, ll, lu;
    static logical big, log__;
    static integer lin;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal sum, del2[3], grad[360], escf, eigs[360];
    static logical prnt;
    extern /* Subroutine */ int symr_(void);
    static doublereal g2rad[360], g2old[360], time2, time3;
    static logical debug;
    extern /* Subroutine */ int chrge_(doublereal *, doublereal *);
    static doublereal delta, grold[360];
    static integer iskip;
    static doublereal estim;
    static integer iloop;
    static doublereal tlast;
    static logical group;
    static doublereal tstep, heataa;
    extern doublereal second_(void);
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *);
    extern doublereal dipole_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
#define coordl ((doublereal *)&coord_1)
    static logical resfil, precis;
    static doublereal fconst[360], estime;
    extern /* Subroutine */ int forsav_(doublereal *, doublereal *, integer *,
	     doublereal *, doublereal *, integer *, doublereal *, doublereal *
	    , integer *, doublereal *);
    static doublereal totime;
    static integer istart, jstart, kountf;
    static logical restrt;
    extern /* Subroutine */ int sympop_(doublereal *, integer *, integer *, 
	    doublereal *);

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 6, 0, "(//4X,'FIRST DERIVATIVES WILL BE USE"
	    "D IN THE'  ,' CALCULATION OF SECOND DERIVATIVES')", 0 };
    static cilist io___22 = { 0, 6, 0, "(/10X,'ESTIMATED TIME TO COMPLETE CA"
	    "LCULATION ='       ,F9.2,' SECONDS')", 0 };
    static cilist io___23 = { 0, 6, 0, "(/10X,'STARTING AGAIN AT LINE',18X,I"
	    "4)", 0 };
    static cilist io___24 = { 0, 6, 0, "(/10X,'TIME USED UP TO RESTART =',F2"
	    "2.2)", 0 };
    static cilist io___29 = { 0, 6, 0, "(' STEP:',I4,'       ',9X,  '       "
	    "INTEGRAL =',F10.2,' TIME LEFT:',F10.2)", 0 };
    static cilist io___33 = { 0, 6, 0, "(A,I3,A,F12.5)", 0 };
    static cilist io___34 = { 0, 6, 0, "(A,F12.5)", 0 };
    static cilist io___37 = { 0, 6, 0, "(A,F12.5)", 0 };
    static cilist io___38 = { 0, 6, 0, "(A,I3,A,F12.5)", 0 };
    static cilist io___40 = { 0, 6, 0, "(A,F12.5)", 0 };
    static cilist io___45 = { 0, 6, 0, "(A,F12.5)", 0 };
    static cilist io___51 = { 0, 6, 0, "(A)", 0 };
    static cilist io___52 = { 0, 6, 0, "(A)", 0 };
    static cilist io___53 = { 0, 6, 0, "(I7,6F12.6)", 0 };
    static cilist io___56 = { 0, 6, 0, "(' STEP:',I4,' RESTART FILE WRITTEN,"
	    " INTEGRAL =',F10.2,' TIME LEFT:',F10.2)", 0 };
    static cilist io___57 = { 0, 11, 0, "(' STEP:',I4,' RESTART FILE WRITTEN"
	    ", ','INTEGRAL =',F10.2,' TIME LEFT:',F10.2)", 0 };
    static cilist io___58 = { 0, 6, 0, "(' STEP:',I4,' TIME =',F9.2,' SECS, "
	    "INTEGRAL =',F10.2,' TIME LEFT:',F10.2)", 0 };
    static cilist io___59 = { 0, 11, 0, "(' STEP:',I4,' TIME =',F9.2,' SECS,"
	    " ','INTEGRAL =',F10.2,' TIME LEFT:',F10.2)", 0 };
    static cilist io___61 = { 0, 6, 0, "(//10X,'- - - - - - - TIME UP - - - "
	    "- - - -',//)", 0 };
    static cilist io___62 = { 0, 6, 0, "(/10X,' POINT REACHED =',I4)", 0 };
    static cilist io___63 = { 0, 6, 0, "(/10X,' RESTART USING KEY-WORD \"RES"
	    "TART\"')", 0 };
    static cilist io___64 = { 0, 6, 0, "(10X,'ESTIMATED TIME FOR THE NEXT ST"
	    "EP =',F8.2,  ' SECONDS')", 0 };
    static cilist io___65 = { 0, 6, 0, "(//10X,'FORCE MATRIX WRITTEN TO DISK"
	    "')", 0 };
    static cilist io___67 = { 0, 6, 0, "(A)", 0 };
    static cilist io___68 = { 0, 6, 0, "(A)", 0 };


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

/*  VALUE CALCULATES THE SECOND-ORDER OF THE ENERGY WITH */
/*        RESPECT TO THE CARTESIAN COORDINATES I AND J AND PLACES IT */
/*        IN FMATRX */

/*  ON INPUT NATOMS  = NUMBER OF ATOMS IN THE SYSTEM. */
/*           XPARAM  = INTERNAL COORDINATES OF MOLECULE STORED LINEARLY */

/*  VARIABLES USED */
/*           COORDL  = ARRAY OF CARTESIAN COORDINATES, STORED LINEARLY. */
/*           I       = INDEX OF CARTESIAN COORDINATE. */
/*           J       = INDEX OF CARTESIAN COORDINATE. */

/*  ON OUTPUT FMATRX = SECOND DERIVATIVE OF THE ENERGY WITH RESPECT TO */
/*                    CARTESIAN COORDINATES I AND J. */
/* ********************************************************************** */
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /TIME  / TIME0 */
/* ***************************** at 1994-05-25 ***** */
    /* Parameter adjustments */
    deldip -= 4;
    --fmatrx;

    /* Function Body */

/*    FACT IS THE CONVERSION FACTOR FROM KCAL/MOLE TO ERGS */

/* SET UP CONSTANTS AND FLAGS */
    geokst_1.na[0] = 99;

/*  SET UP THE VARIABLES IN XPARAM ANDLOC,THESE ARE IN CARTESIAN COORDINA */

    molkst_1.numat = 0;
/* $DOIT ASIS */
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] != 99 && geokst_1.labels[i__ - 1] != 107)
		 {
	    ++molkst_1.numat;
	    geokst_1.labels[molkst_1.numat - 1] = geokst_1.labels[i__ - 1];
	}
/* L10: */
    }
    geokst_1.natoms = molkst_1.numat;

/*   THIS IS A QUICK, IF CLUMSY, WAY TO CALCULATE NUMAT, AND TO REMOVE */
/*   THE DUMMY ATOMS FROM THE ARRAY LABELS. */

    geovar_1.nvar = molkst_1.numat * 3;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	geovar_1.loc[((i__ - 1) * 3 + 1 << 1) - 2] = i__;
	geovar_1.loc[((i__ - 1) * 3 + 1 << 1) - 1] = 1;

	geovar_1.loc[((i__ - 1) * 3 + 2 << 1) - 2] = i__;
	geovar_1.loc[((i__ - 1) * 3 + 2 << 1) - 1] = 2;

	geovar_1.loc[((i__ - 1) * 3 + 3 << 1) - 2] = i__;
	geovar_1.loc[((i__ - 1) * 3 + 3 << 1) - 1] = 3;
/* L20: */
    }
    lin = geovar_1.nvar * (geovar_1.nvar + 1) / 2;
    i__1 = lin;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	fmatrx[i__] = 0.;
    }
    prnt = i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) == 0;
    log__ = i_indx(keywrd_1.keywrd, "NOLOG", (ftnlen)241, (ftnlen)5) == 0;
    precis = i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0;
    restrt = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0;
    group = i_indx(keywrd_1.keywrd, " GROUP", (ftnlen)241, (ftnlen)6) != 0;
    if (i_indx(keywrd_1.keywrd, "NLLSQ", (ftnlen)241, (ftnlen)5) != 0) {
	restrt = FALSE_;
    }
    debug = i_indx(keywrd_1.keywrd, "FMAT", (ftnlen)241, (ftnlen)4) != 0;
    big = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5) != 0 && 
	    debug;
    if (prnt) {
	s_wsfe(&io___12);
	e_wsfe();
    }
    tlast = timdmp_1.tleft;
    resfil = FALSE_;
    if (restrt) {
	istart = 0;
	i__ = 0;
	forsav_(&totime, &deldip[4], &istart, &fmatrx[1], coord_1.coord, &
		geovar_1.nvar, heat, nllcom_1.evecs, &jstart, fconst);
	kountf = istart * (istart + 1) / 2;
	++istart;
	++jstart;
	time2 = second_();
    } else {
	kountf = 0;
	totime = 0.;
	if (*tscf > 0.) {
	    timdmp_1.tleft = timdmp_1.tleft - *tscf - *tder;
	}
	istart = 1;
    }
/* CALCULATE FMATRX */
    if (istart > 1) {
	estime = (geovar_1.nvar - istart + 1) * totime / (istart - 1.);
    } else {
	estime = geovar_1.nvar * (*tscf + *tder) * 2.;
	if (precis) {
	    estime *= 2.;
	}
    }
    if (*tscf > 0.) {
	s_wsfe(&io___22);
	do_fio(&c__1, (char *)&estime, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (restrt) {
	if (istart <= geovar_1.nvar) {
	    s_wsfe(&io___23);
	    do_fio(&c__1, (char *)&istart, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	s_wsfe(&io___24);
	do_fio(&c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    lu = kountf;
    molkst_1.numat = geovar_1.nvar / 3;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	eigs[i__ - 1] = 0.;
    }

/*  READ IN THE SYMMETRY OPERATIONS, IF PRESENT */

    if (group) {
	symr_();
    }
    iskip = 0;
    i__1 = geovar_1.nvar;
    for (i__ = istart; i__ <= i__1; ++i__) {
	if (group && (i__ - 1) / 3 * 3 == i__ - 1) {

/*  START OF A NEW ATOM.  DOES A SYMMETRY OPERATION RELATE AN ALREADY */
/*  CALCULATED ATOM TO THIS ONE */

	    j = (i__ + 2) / 3;
	    sympop_(&fmatrx[1], &j, &iskip, &deldip[4]);
	}
	if (iskip > 0) {
	    s_wsfe(&io___29);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
	    --iskip;
	    lu += i__;
	    goto L110;
	}
	time2 = second_();
	delta = .0083333333333333332;
	if (precis) {

/*   DETERMINE A GOOD STEP SIZE */

	    g2old[0] = 100.;
	    coordl[i__ - 1] += delta;
	    compfg_(coordl, &c_true, &escf, &c_true, g2old, &c_true);
	    coordl[i__ - 1] -= delta;
	    delta = delta * 10. / sqrt(dot_(g2old, g2old, &geovar_1.nvar));

/*   CONSTRAIN DELTA TO A 'REASONABLE' VALUE */

/* Computing MIN */
	    d__1 = .05, d__2 = max(.005,delta);
	    delta = min(d__1,d__2);
	    if (debug) {
		s_wsfe(&io___33);
		do_fio(&c__1, " STEP:", (ftnlen)6);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, " DELTA :", (ftnlen)8);
		do_fio(&c__1, (char *)&delta, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    g2old[0] = 100.;
	    coordl[i__ - 1] += delta;
	    compfg_(coordl, &c_true, &escf, &c_true, g2old, &c_true);
	    if (debug) {
		s_wsfe(&io___34);
		do_fio(&c__1, " GNORM +1.0*DELTA", (ftnlen)17);
		d__1 = sqrt(dot_(g2old, g2old, &geovar_1.nvar));
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	    coordl[i__ - 1] -= delta * 2.;
	    g2rad[0] = 100.;
	    compfg_(coordl, &c_true, &heataa, &c_true, g2rad, &c_true);
	    coordl[i__ - 1] += delta;
	    if (debug) {
		s_wsfe(&io___37);
		do_fio(&c__1, " GNORM -1.0*DELTA", (ftnlen)17);
		d__1 = sqrt(dot_(g2rad, g2rad, &geovar_1.nvar));
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	} else {
	    if (debug) {
		s_wsfe(&io___38);
		do_fio(&c__1, " STEP:", (ftnlen)6);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, " DELTA :", (ftnlen)8);
		do_fio(&c__1, (char *)&delta, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    }
	}
	coordl[i__ - 1] += delta * .5;
	grold[0] = 100.;
	compfg_(coordl, &c_true, &escf, &c_true, grold, &c_true);
	if (debug) {
	    s_wsfe(&io___40);
	    do_fio(&c__1, " GNORM +0.5*DELTA", (ftnlen)17);
	    d__1 = sqrt(dot_(grold, grold, &geovar_1.nvar));
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	chrge_(densty_1.p, q);
	i__2 = molkst_1.numat;
	for (ii = 1; ii <= i__2; ++ii) {
/* L50: */
	    q[ii - 1] = core_1.core[geokst_1.labels[ii - 1] - 1] - q[ii - 1];
	}
	sum = dipole_(densty_1.p, q, coordl, &deldip[i__ * 3 + 1], &c__0);
	coordl[i__ - 1] -= delta;
	grad[0] = 100.;
	compfg_(coordl, &c_true, &heataa, &c_true, grad, &c_true);
	if (debug) {
	    s_wsfe(&io___45);
	    do_fio(&c__1, " GNORM -0.5*DELTA", (ftnlen)17);
	    d__1 = sqrt(dot_(grad, grad, &geovar_1.nvar));
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	chrge_(densty_1.p, q);
	i__2 = molkst_1.numat;
	for (ii = 1; ii <= i__2; ++ii) {
/* L60: */
	    q[ii - 1] = core_1.core[geokst_1.labels[ii - 1] - 1] - q[ii - 1];
	}
	sum = dipole_(densty_1.p, q, coordl, del2, &c__0);
	coordl[i__ - 1] += delta * .5;
	deldip[i__ * 3 + 1] = (deldip[i__ * 3 + 1] - del2[0]) * .5 / delta;
	deldip[i__ * 3 + 2] = (deldip[i__ * 3 + 2] - del2[1]) * .5 / delta;
	deldip[i__ * 3 + 3] = (deldip[i__ * 3 + 3] - del2[2]) * .5 / delta;
	ll = lu + 1;
	lu = ll + i__ - 1;
	l = 0;
	if (precis) {
	    i__2 = lu;
	    for (kountf = ll; kountf <= i__2; ++kountf) {
		++l;

/*       G2OLD = X + 1.0*DELTA */
/*       GROLD = X + 0.5*DELTA */
/*       GRAD  = X - 0.5*DELTA */
/*       G2RAD = X - 1.0*DELTA */

		geovar_1.dumy[l - 1] = ((grold[l - 1] - grad[l - 1]) * 8. - (
			g2old[l - 1] - g2rad[l - 1])) / delta * fact / 24.;
/* Computing 3rd power */
		d__1 = delta;
		eigs[l - 1] = ((grold[l - 1] - grad[l - 1]) * 2. - (g2old[l - 
			1] - g2rad[l - 1])) / (d__1 * (d__1 * d__1)) * fact / 
			56.;

/*  CORRECT FOR 4'TH ORDER CONTAMINATION */

/* #             CORR=MIN(ABS(DUMY(L)),ABS(EIGS(L))*0.0001D0) */
/* #             DUMY(L)=DUMY(L)-SIGN(CORR,DUMY(L)) */
		fmatrx[kountf] += geovar_1.dumy[l - 1];
/* L70: */
	    }
	    --l;
	    i__2 = geovar_1.nvar;
	    for (k = i__; k <= i__2; ++k) {
		++l;
		kk = k * (k - 1) / 2 + i__;
		geovar_1.dumy[l - 1] = ((grold[l - 1] - grad[l - 1]) * 8. - (
			g2old[l - 1] - g2rad[l - 1])) / delta * fact / 24.;
/* Computing 3rd power */
		d__1 = delta;
		eigs[l - 1] = ((grold[l - 1] - grad[l - 1]) * 2. - (g2old[l - 
			1] - g2rad[l - 1])) / (d__1 * (d__1 * d__1)) * fact / 
			56.;

/*  CORRECT FOR 4'TH ORDER CONTAMINATION */

/* #             CORR=MIN(ABS(DUMY(L)),ABS(EIGS(L))*0.0001D0) */
/* #             DUMY(L)=DUMY(L)-SIGN(CORR,DUMY(L)) */
		fmatrx[kk] += geovar_1.dumy[l - 1];
/* L80: */
	    }
	} else {
	    i__2 = lu;
	    for (kountf = ll; kountf <= i__2; ++kountf) {
		++l;
		geovar_1.dumy[l - 1] = (grold[l - 1] - grad[l - 1]) * .25 / 
			delta * fact;
		fmatrx[kountf] += geovar_1.dumy[l - 1];
/* L90: */
	    }
	    --l;
	    i__2 = geovar_1.nvar;
	    for (k = i__; k <= i__2; ++k) {
		++l;
		kk = k * (k - 1) / 2 + i__;
		geovar_1.dumy[l - 1] = (grold[l - 1] - grad[l - 1]) * .25 / 
			delta * fact;
		fmatrx[kk] += geovar_1.dumy[l - 1];
/* L100: */
	    }
	}
	if (big) {
	    s_wsfe(&io___51);
	    do_fio(&c__1, " CONTRIBUTIONS TO F-MATRIX", (ftnlen)26);
	    e_wsfe();
	    s_wsfe(&io___52);
	    do_fio(&c__1, " ELEMENT  +1.0*DELTA  +0.5*DELTA  -0.5*DELTA  -1."
		    "0*DELTA   2'ND ORDER 4TH ORDER", (ftnlen)79);
	    e_wsfe();
	    s_wsfe(&io___53);
	    i__2 = geovar_1.nvar;
	    for (l = 1; l <= i__2; ++l) {
		do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&g2old[l - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&grold[l - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&grad[l - 1], (ftnlen)sizeof(doublereal)
			);
		do_fio(&c__1, (char *)&g2rad[l - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&geovar_1.dumy[l - 1], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, (char *)&eigs[l - 1], (ftnlen)sizeof(doublereal)
			);
	    }
	    e_wsfe();
	}
	time3 = second_();
	tstep = time3 - time2;
/* Computing MAX */
	d__1 = .1, d__2 = timdmp_1.tleft - tstep;
	timdmp_1.tleft = max(d__1,d__2);
	if (tstep > 1e6) {
	    tstep += -1e6;
	}
	totime += tstep;
	if (resfil) {
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
	    if (log__) {
		s_wsfe(&io___57);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(
			doublereal));
		e_wsfe();
	    }
	    resfil = FALSE_;
	} else {
	    s_wsfe(&io___58);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&tstep, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal))
		    ;
	    e_wsfe();
	    if (log__) {
		s_wsfe(&io___59);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&tstep, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&totime, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(
			doublereal));
		e_wsfe();
	    }
	}
	estim = totime / i__;
	if (tlast - timdmp_1.tleft > timdmp_1.tdump) {
	    tlast = timdmp_1.tleft;
	    resfil = TRUE_;
	    jstart = 1;
	    ii = i__;
	    forsav_(&totime, &deldip[4], &ii, &fmatrx[1], coord_1.coord, &
		    geovar_1.nvar, heat, nllcom_1.evecs, &jstart, fconst);
	}
	if (i__ != geovar_1.nvar && timdmp_1.tleft - 10. < estim) {
	    s_wsfe(&io___61);
	    e_wsfe();
	    s_wsfe(&io___62);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_wsfe(&io___63);
	    e_wsfe();
	    s_wsfe(&io___64);
	    do_fio(&c__1, (char *)&estim, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    jstart = 1;
	    ii = i__;
	    forsav_(&totime, &deldip[4], &ii, &fmatrx[1], coord_1.coord, &
		    geovar_1.nvar, heat, nllcom_1.evecs, &jstart, fconst);
	    s_wsfe(&io___65);
	    e_wsfe();
	    *nreal = -1;
	    return 0;
	}
L110:
	;
    }
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (atmass_1.atmass[i__ - 1] < 1e-20 && geokst_1.labels[i__ - 1] < 99)
		 {
	    forsav_(&totime, &deldip[4], &geovar_1.nvar, &fmatrx[1], 
		    coord_1.coord, &geovar_1.nvar, heat, nllcom_1.evecs, &
		    iloop, fconst);
	    s_wsfe(&io___67);
	    do_fio(&c__1, " AT LEAST ONE ATOM HAS A ZERO MASS. A RESTART", (
		    ftnlen)45);
	    e_wsfe();
	    s_wsfe(&io___68);
	    do_fio(&c__1, " FILE HAS BEEN WRITTEN AND THE JOB STOPPED", (
		    ftnlen)42);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
/* L120: */
    }
    if (istart <= geovar_1.nvar && i_indx(keywrd_1.keywrd, "ISOT", (ftnlen)
	    241, (ftnlen)4) != 0) {
	forsav_(&totime, &deldip[4], &geovar_1.nvar, &fmatrx[1], 
		coord_1.coord, &geovar_1.nvar, heat, nllcom_1.evecs, &iloop, 
		fconst);
    }
    return 0;
} /* fmat_ */

#undef coordl


