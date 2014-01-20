/* esp.f -- translated by f2c (version 20020621).
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
    doublereal geo[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

union {
    struct {
	integer natoms, labels[120], nabc[360];
    } _1;
    struct {
	integer natoms, labels[120], na[120], nb[120], nc[120];
    } _2;
} geokst_;

#define geokst_1 (geokst_._1)
#define geokst_2 (geokst_._2)

struct {
    doublereal co[360]	/* was [3][120] */;
    integer ian[120], natom;
} abc_;

#define abc_1 abc_

union {
    struct {
	doublereal potpt[150000]	/* was [3][50000] */, work1d[200000];
    } _1;
    struct {
	doublereal potpt[150000]	/* was [3][50000] */, pad1[100000], 
		rad[50000];
	integer ias[50000];
    } _2;
    struct {
	doublereal potpt[150000]	/* was [3][50000] */, es[50000], esp[
		50000], work1d[100000];
    } _3;
} work1_;

#define work1_1 (work1_._1)
#define work1_2 (work1_._2)
#define work1_3 (work1_._3)

struct {
    doublereal xc, yc, zc, espnuc, espele;
    integer nesp;
} potesp_;

#define potesp_1 potesp_

struct {
    doublereal tore[107];
} core_;

#define core_1 core_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal ux, uy, uz, ch[120];
} dipsto_;

#define dipsto_1 dipsto_

union {
    struct {
	doublereal al[15376], a[14400]	/* was [120][120] */, b[120], q[124], 
		qsc[124], cf, espfd[89875];
    } _1;
    struct {
	doublereal al[15376], a[14400]	/* was [120][120] */, b[120], q[124], 
		cespm[90000]	/* was [300][300] */;
    } _2;
} espf_;

#define espf_1 (espf_._1)
#define espf_2 (espf_._2)

struct {
    doublereal allc[72]	/* was [6][6][2] */, allz[72]	/* was [6][6][2] */;
} sto6g_;

#define sto6g_1 sto6g_

struct {
    doublereal c__[180600];
} vector_;

#define vector_1 vector_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct espc_1_ {
    doublereal cc[1800], cen[5400]	/* was [1800][3] */;
    integer iam[3600]	/* was [1800][2] */, ind[1800];
    doublereal ex[1800], espi[90000]	/* was [300][300] */, fv[7389]	/* 
	    was [9][821] */, fac[8], dex[98], tf[3], temp[1800];
    integer itemp[1800];
    doublereal ovl[90000]	/* was [300][300] */, fc[10800];
};
struct espc_2_ {
    doublereal cc[1800], cen[5400]	/* was [1800][3] */;
    integer iam[3600]	/* was [1800][2] */, ind[1800];
    doublereal ex[1800], espi[90000]	/* was [300][300] */, fv[7389]	/* 
	    was [9][821] */, fac[8], dex[98], tf[3], temp[1800];
    integer itemp[1800];
    doublereal ovl[90000]	/* was [300][300] */, xdmy[10800];
};
struct espc_3_ {
    doublereal cc[1800], cen[5400]	/* was [1800][3] */;
    integer iam[3600]	/* was [1800][2] */, ind[1800];
    doublereal ex[1800], espi[90000]	/* was [300][300] */, fv[7389]	/* 
	    was [9][821] */, fac[8], dex[98], tf[3], temp[1800];
    integer itemp[1800];
    doublereal ovl[90000]	/* was [300][300] */, exsr[10800]	/* 
	    was [1800][6] */;
};

#define espc_1 (*(struct espc_1_ *) &espc_)
#define espc_2 (*(struct espc_2_ *) &espc_)
#define espc_3 (*(struct espc_3_ *) &espc_)

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    integer indc[300];
} indx_;

#define indx_1 indx_

struct {
    integer nztype[107], mtype[30], ltype;
} natype_;

#define natype_1 natype_

struct {
    doublereal dx[1800], dy[1800], dz[1800], f1[10800]	/* was [1800][6] */, 
	    f2[10800]	/* was [1800][6] */, td[1800], ce[10800]	/* 
	    was [1800][6] */, u[10800]	/* was [1800][6] */, exs[10800]	/* 
	    was [1800][6] */, expn[10800]	/* was [1800][6] */, nai[
	    10800]	/* was [1800][6] */, ewcx[10800]	/* was [1800][
	    6] */, ewcy[10800]	/* was [1800][6] */, ewcz[10800]	/* 
	    was [1800][6] */, f0[10800]	/* was [1800][6] */, nai1[10800]	
	    /* was [1800][6] */, nai2[10800]	/* was [1800][6] */;
} x_;

#define x_1 x_

struct {
    doublereal pf0[64980], pf1[64980], pf2[64980];
    integer id[360];
    doublereal pexs[64980], pce[64980], pexpn[64980], ptd[64980], pewcx[64980]
	    , pewcy[64980], pewcz[64980];
    integer ird[64980];
} fp_;

#define fp_1 fp_

struct {
    doublereal cespm2[90000]	/* was [300][300] */, sla[10], cespml[90000], 
	    cesp[90000];
    integer inc[1800], nc, npr, is, ip, ipc, isc, icd, iorb;
} plots_;

#define plots_1 plots_

/* Initialized data */

struct {
    doublereal fill_1[109089];
    doublereal e_2[8];
    doublereal fill_3[98];
    doublereal e_4[3];
    doublereal fill_5[103500];
    } espc_ = { {0}, 1., 1., 2., 6., 24., 120., 720., 5040., {0}, 33., 37., 
	    41. };


/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__3 = 3;
static doublereal c_b182 = .75;
static integer c__2 = 2;
static doublereal c_b261 = 1.5;

/* Subroutine */ int esp_(void)
{
    /* Format strings */
    static char fmt_20[] = "(/9x,a,f8.2,a)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, n;
    static doublereal den, time1;
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal scale;
    extern /* Subroutine */ int pdgrid_(void);
    extern doublereal second_(void);
    static doublereal scincr;
    extern /* Subroutine */ int potcal_(void), surfac_(doublereal *, 
	    doublereal *, integer *);

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 6, 0, fmt_20, 0 };


/* *********************************************************************** */

/*     THIS IS A DRIVER ROUTINE FOR ELECTROSTATIC POTENTIAL GENERATION */
/*     WRITTEN BY K.M.MERZ FEB. 1989 AT UCSF */

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

/*     SET STANDARD PARAMETERS FOR THE SURFACE GENERATION */

    if (i_indx(keywrd_1.keywrd, "SCALE=", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "SCALE=", (ftnlen)241, (ftnlen)6);
	scale = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	scale = 1.4;
    }

    if (i_indx(keywrd_1.keywrd, "DEN=", (ftnlen)241, (ftnlen)4) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "DEN=", (ftnlen)241, (ftnlen)4);
	den = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	den = 1.;
    }

    if (i_indx(keywrd_1.keywrd, "SCINCR=", (ftnlen)241, (ftnlen)7) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "SCINCR=", (ftnlen)241, (ftnlen)7);
	scincr = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	scincr = .2;
    }

    if (i_indx(keywrd_1.keywrd, "NSURF=", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "NSURF=", (ftnlen)241, (ftnlen)6);
	n = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	n = 4;
    }

    time1 = second_();

/*     NOW CALCULATE THE SURFACE POINTS */

    if (i_indx(keywrd_1.keywrd, "WILLIAMS", (ftnlen)241, (ftnlen)8) != 0) {
	pdgrid_();
    } else {
	i__1 = n;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    surfac_(&scale, &den, &i__);
	    scale += scincr;
/* L10: */
	}
    }

/*     NEXT CALCULATE THE ESP AT THE POINTS CALCULATED BY SURFAC */

    potcal_();

/*     END OF CALCULATION */

    time1 = second_() - time1;
    s_wsfe(&io___7);
    do_fio(&c__1, "TIME TO CALCULATE ESP:", (ftnlen)22);
    do_fio(&c__1, (char *)&time1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, " SECONDS", (ftnlen)8);
    e_wsfe();
    return 0;
} /* esp_ */

/* Subroutine */ int pdgrid_(void)
{
    /* Initialized data */

    static doublereal vderw[53] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, l, ia, ix, jz;
    static doublereal grid, dist[100], xmin[3], xmax[3];
    static integer npnt;
    static doublereal coord[360]	/* was [3][120] */, shell, xgrid;
    static integer icntr;
    static doublereal vdmax, zgrid, ygrid, closer;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);
    static doublereal xstart, ystart, zstart;

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 6, 0, 0, 0 };
    static cilist io___17 = { 0, 6, 0, 0, 0 };



/*     ROUTINE TO CALCULATE WILLIAMS SURFACE */

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


    vderw[0] = 2.4;
    vderw[4] = 3.;
    vderw[5] = 2.9;
    vderw[6] = 2.7;
    vderw[7] = 2.6;
    vderw[8] = 2.55;
    vderw[14] = 3.1;
    vderw[15] = 3.05;
    vderw[16] = 3.;
    vderw[34] = 3.15;
    vderw[52] = 3.35;
    shell = 1.2;
    potesp_1.nesp = 0;
    grid = .8;
    closer = 0.;
/*     CHECK IF VDERW IS DEFINED FOR ALL ATOMS */

/*     CONVERT INTERNAL TO CARTESIAN COORDINATES */

    gmetry_(geom_1.geo, coord);

/*     STRIP COORDINATES AND ATOM LABEL FOR DUMMIES (I.E. 99) */

    icntr = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L10: */
	    abc_1.co[j + i__ * 3 - 4] = coord[j + i__ * 3 - 4];
	}
	if (geokst_1.labels[i__ - 1] == 99) {
	    goto L20;
	}
	++icntr;
	abc_1.ian[icntr - 1] = geokst_1.labels[i__ - 1];
L20:
	;
    }
    abc_1.natom = icntr;

    i__1 = abc_1.natom;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = abc_1.ian[i__ - 1];
	if (vderw[j - 1] == 0.) {
	    goto L40;
	}
/* L30: */
    }
    goto L50;
L40:
    s_wsle(&io___16);
    do_lio(&c__9, &c__1, "VAN DER WAALS' RADIUS NOT DEFINED FOR ATOM", (
	    ftnlen)42);
    do_lio(&c__3, &c__1, (char *)&i__, (ftnlen)sizeof(integer));
    e_wsle();
    s_wsle(&io___17);
    do_lio(&c__9, &c__1, "IN WILLIAMS SURFACE ROUTINE PDGRID!", (ftnlen)35);
    e_wsle();
    s_stop("", (ftnlen)0);
/*     NOW CREATE LIMITS FOR A BOX */
L50:
    for (ix = 1; ix <= 3; ++ix) {
	xmin[ix - 1] = 1e5;
	xmax[ix - 1] = -1e5;
	i__1 = abc_1.natom;
	for (ia = 1; ia <= i__1; ++ia) {
	    if (abc_1.co[ix + ia * 3 - 4] - xmin[ix - 1] >= 0.) {
		goto L70;
	    } else {
		goto L60;
	    }
L60:
	    xmin[ix - 1] = abc_1.co[ix + ia * 3 - 4];
L70:
	    if (abc_1.co[ix + ia * 3 - 4] - xmax[ix - 1] <= 0.) {
		goto L90;
	    } else {
		goto L80;
	    }
L80:
	    xmax[ix - 1] = abc_1.co[ix + ia * 3 - 4];
L90:
	    ;
	}
/* L100: */
    }
/*     ADD (OR SUBTRACT) THE MAXIMUM VDERW PLUS SHELL */
    vdmax = 0.;
    for (i__ = 1; i__ <= 53; ++i__) {
	if (vderw[i__ - 1] > vdmax) {
	    vdmax = vderw[i__ - 1];
	}
/* L110: */
    }
    for (i__ = 1; i__ <= 3; ++i__) {
	xmin[i__ - 1] = xmin[i__ - 1] - vdmax - shell;
/* L120: */
	xmax[i__ - 1] = xmax[i__ - 1] + vdmax + shell;
    }
/* STEP GRID BACK FROM ZERO TO FIND STARTING POINTS */
    xstart = 0.;
L130:
    xstart -= grid;
    if (xstart > xmin[0]) {
	goto L130;
    }
    ystart = 0.;
L140:
    ystart -= grid;
    if (ystart > xmin[1]) {
	goto L140;
    }
    zstart = 0.;
L150:
    zstart -= grid;
    if (zstart > xmin[2]) {
	goto L150;
    }
    npnt = 0;
    zgrid = zstart;
L160:
    ygrid = ystart;
L170:
    xgrid = xstart;
L180:
    i__1 = abc_1.natom;
    for (l = 1; l <= i__1; ++l) {
	jz = abc_1.ian[l - 1];
/* Computing 2nd power */
	d__1 = abc_1.co[l * 3 - 3] - xgrid;
/* Computing 2nd power */
	d__2 = abc_1.co[l * 3 - 2] - ygrid;
/* Computing 2nd power */
	d__3 = abc_1.co[l * 3 - 1] - zgrid;
	dist[l - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/*     REJECT GRID POINT IF ANY ATOM IS TOO CLOSE */
	if (dist[l - 1] < vderw[jz - 1] - closer) {
	    goto L220;
	}
/* L190: */
    }
/* BUT AT LEAST ONE ATOM MUST BE CLOSE ENOUGH */
    i__1 = abc_1.natom;
    for (l = 1; l <= i__1; ++l) {
	jz = abc_1.ian[l - 1];
	if (dist[l - 1] > vderw[jz - 1] + shell) {
	    goto L200;
	}
	goto L210;
L200:
	;
    }
    goto L220;
L210:
    ++npnt;
    ++potesp_1.nesp;
    work1_1.potpt[potesp_1.nesp * 3 - 3] = xgrid;
    work1_1.potpt[potesp_1.nesp * 3 - 2] = ygrid;
    work1_1.potpt[potesp_1.nesp * 3 - 1] = zgrid;
L220:
    xgrid += grid;
    if (xgrid <= xmax[0]) {
	goto L180;
    }
    ygrid += grid;
    if (ygrid <= xmax[1]) {
	goto L170;
    }
    zgrid += grid;
    if (zgrid <= xmax[2]) {
	goto L160;
    }
    return 0;
} /* pdgrid_ */

/* *********************************************************************** */
/* Subroutine */ int surfac_(doublereal *scale, doublereal *dens, integer *
	ipt)
{
    /* Initialized data */

    static doublereal vander[100] = { 1.2,1.2,1.37,1.45,1.45,1.5,1.5,1.4,1.35,
	    1.3,1.57,1.36,1.24,1.17,1.8,1.75,1.7,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,2.3,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0. };
    static char ieldat[4*56] = "  BQ" "  H " "  HE" "  LI" "  BE" "  B " 
	    "  C " "  N " "  O " "  F " "  NE" "  NA" "  MG" "  AL" "  SI" 
	    "  P " "  S " "  CL" "  AR" "  K " "  CA" "  SC" "  TI" "  V " 
	    "  CR" "  MN" "  FE" "  CO" "  NI" "  CU" "  ZN" "  GA" "  GE" 
	    "  AS" "  SE" "  BR" "  KR" "  RB" "  SR" "   Y" "  ZR" "  NB" 
	    "  MO" "  TC" "  RU" "  RH" "  PD" "  AG" "  CD" "  IN" "  SN" 
	    "  SB" "  TE" "   I" "   X" "  CS";

    /* Format strings */
    static char fmt_90[] = "(/\002ERROR - TO MANY POINTS GENERATED IN SURFA"
	    "C\002)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double atan(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k;
    static doublereal d2, ci[3];
    static integer kk;
    static doublereal pi, cw[6]	/* was [3][2] */;
    static logical si;
    static doublereal ri, rw, den, con[3000]	/* was [3][1000] */;
    static integer iop;
    static doublereal area, cnbr[600]	/* was [3][200] */;
    static integer inbr[200], jnbr, knbr, ncon;
    static logical mnbr[200];
    static integer nnbr;
    static doublereal rnbr[200];
    static logical snbr[200];
    static doublereal temp0[3];
    extern doublereal dist2_(doublereal *, doublereal *);
    static doublereal coord[360]	/* was [3][120] */;
    static integer iatom, jatom;
    extern /* Subroutine */ int genun_(doublereal *, integer *);
    static integer icntr;
    extern logical collid_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, logical *, integer *, integer *, integer *, integer 
	    *);
    static char namatm[4];
    static integer ipoint;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___47 = { 0, 6, 0, "(T2,'VAN DER WAALS'' RADIUS FOR ATOM"
	    " ',I3,              ' IS ZERO, SUPPLY A VALUE IN SUBROUTINE SURF"
	    "AC)'                )", 0 };
    static cilist io___57 = { 0, 6, 0, "('ERROR',2X,'TOO MANY NEIGHBORS:',I5)"
	    , 0 };
    static cilist io___63 = { 0, 6, 0, "(T2,'VECTOR LENGTH OF ZERO IN SURFAC"
	    "')", 0 };
    static cilist io___72 = { 0, 6, 0, fmt_90, 0 };
    static cilist io___73 = { 0, 6, 0, "('    REDUCE NSURF, SCALE, DEN, OR S"
	    "CINCR')", 0 };


/* *********************************************************************** */

/*      THIS SUBROUTINE CALCULATES THE MOLECULAR SURFACE OF A MOLECULE */
/*      GIVEN THE COORDINATES OF ITS ATOMS.  VAN DER WAALS' RADII FOR */
/*      THE ATOMS AND THE PROBE RADIUS MUST ALSO BE SPECIFIED. */

/*      ON INPUT    SCALE = INITIAL VAN DER WAALS' SCALE FACTOR */
/*                  DENS  = DENSITY OF POINTS PER UNIT AREA */

/*      THIS SUBROUTINE WAS LIFTED FROM MICHAEL CONNOLLY'S SURFACE */
/*      PROGRAM FOR UCSF GRAPHICS SYSTEM BY U.CHANDRA SINGH AND */
/*      P.A.KOLLMAN AND MODIFIED FOR USE IN QUEST. K.M.MERZ */
/*      ADAPTED AND CLEANED UP THIS PROGRAM FOR USE IN AMPAC/MOPAC */
/*      IN FEB. 1989 AT UCSF. */

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



/*     CARTESIAN COORDINATE AND ATOM LABELS */


/*     NEIGHBOR ARRAYS */

/*     THIS SAME DIMENSION FOR THE MAXIMUM NUMBER OF NEIGHBORS */
/*     IS USED TO DIMENSION ARRAYS IN THE LOGICAL FUNCTION COLLID */


/*     ARRAYS FOR ALL ATOMS */

/*     IATOM, JATOM AND KATOM COORDINATES */


/*     GEOMETRIC CONSTRUCTION VECTORS */


/*     LOGICAL VARIABLES */


/*     LOGICAL FUNCTIONS */


/*     DATA FOR VANDER VALL RADII */


    pi = 4. * atan(1.);
/*     INSERT VAN DER WAAL RADII FOR ZINC */
    vander[29] = 1.;

/*     CONVERT INTERNAL TO CARTESIAN COORDINATES */

    gmetry_(geom_1.geo, coord);

/*     STRIP COORDINATES AND ATOM LABEL FOR DUMMIES (I.E. 99) */

    icntr = 0;
    i__1 = geokst_2.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L10: */
	    abc_1.co[j + i__ * 3 - 4] = coord[j + i__ * 3 - 4];
	}
	if (geokst_2.labels[i__ - 1] == 99) {
	    goto L20;
	}
	++icntr;
	abc_1.ian[icntr - 1] = geokst_2.labels[i__ - 1];
L20:
	;
    }

/*     ONLY VAN DER WAALS' TYPE SURFACE IS GENERATED */

    iop = 1;
    rw = 0.;
    abc_1.natom = icntr;
    den = *dens;
    i__1 = abc_1.natom;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ipoint = abc_1.ian[i__ - 1];
	work1_2.rad[i__ - 1] = vander[ipoint - 1] * *scale;
	if (work1_2.rad[i__ - 1] < .01) {
	    s_wsfe(&io___47);
	    e_wsfe();
	}
	work1_2.ias[i__ - 1] = 2;
/* L30: */
    }

/*     BIG LOOP FOR EACH ATOM */

    i__1 = abc_1.natom;
    for (iatom = 1; iatom <= i__1; ++iatom) {
	if (work1_2.ias[iatom - 1] == 0) {
	    goto L110;
	}

/*     TRANSFER VALUES FROM LARGE ARRAYS TO IATOM VARIABLES */

	s_copy(namatm, ieldat + (abc_1.ian[iatom - 1] << 2), (ftnlen)4, (
		ftnlen)4);
	ri = work1_2.rad[iatom - 1];
	si = work1_2.ias[iatom - 1] == 2;
	for (k = 1; k <= 3; ++k) {
	    ci[k - 1] = abc_1.co[k + iatom * 3 - 4];
/* L40: */
	}

/*     GATHER THE NEIGHBORING ATOMS OF IATOM */

	nnbr = 0;
	i__2 = abc_1.natom;
	for (jatom = 1; jatom <= i__2; ++jatom) {
	    if (iatom == jatom || work1_2.ias[jatom - 1] == 0) {
		goto L60;
	    }
	    d2 = dist2_(ci, &abc_1.co[jatom * 3 - 3]);
/* Computing 2nd power */
	    d__1 = rw * 2 + ri + work1_2.rad[jatom - 1];
	    if (d2 >= d__1 * d__1) {
		goto L60;
	    }

/*     WE HAVE A NEW NEIGHBOR */
/*     TRANSFER ATOM COORDINATES, RADIUS AND SURFACE REQUEST NUMBER */

	    ++nnbr;
	    if (nnbr > 200) {
		s_wsfe(&io___57);
		do_fio(&c__1, (char *)&nnbr, (ftnlen)sizeof(integer));
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    inbr[nnbr - 1] = jatom;
	    for (k = 1; k <= 3; ++k) {
		cnbr[k + nnbr * 3 - 4] = abc_1.co[k + jatom * 3 - 4];
/* L50: */
	    }
	    rnbr[nnbr - 1] = work1_2.rad[jatom - 1];
	    snbr[nnbr - 1] = work1_2.ias[jatom - 1] == 2;
L60:
	    ;
	}

/*     CONTACT SURFACE */

	if (! si) {
	    goto L110;
	}
/* Computing 2nd power */
	d__1 = ri;
	ncon = (integer) (pi * 4 * (d__1 * d__1) * den);
	if (ncon > 1000) {
	    ncon = 1000;
	}

/*     THIS CALL MAY DECREASE NCON SOMEWHAT */

	if (ncon == 0) {
	    s_wsfe(&io___63);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	genun_(con, &ncon);
/* Computing 2nd power */
	d__1 = ri;
	area = pi * 4 * (d__1 * d__1) / ncon;

/*     CONTACT PROBE PLACEMENT LOOP */

	i__2 = ncon;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    for (k = 1; k <= 3; ++k) {
		cw[k - 1] = ci[k - 1] + (ri + rw) * con[k + i__ * 3 - 4];
/* L70: */
	    }

/*     CHECK FOR COLLISION WITH NEIGHBORING ATOMS */

	    if (collid_(cw, &rw, cnbr, rnbr, mnbr, &nnbr, &c__1, &jnbr, &knbr)
		    ) {
		goto L100;
	    }
	    for (kk = 1; kk <= 3; ++kk) {
		temp0[kk - 1] = ci[kk - 1] + ri * con[kk + i__ * 3 - 4];
/* L80: */
	    }

/*     STORE POINT IN POTPT AND INCREMENT NESP */

	    ++potesp_1.nesp;
	    if (potesp_1.nesp > 50000) {
		s_wsfe(&io___72);
		e_wsfe();
		s_wsfe(&io___73);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    work1_2.potpt[potesp_1.nesp * 3 - 3] = temp0[0];
	    work1_2.potpt[potesp_1.nesp * 3 - 2] = temp0[1];
	    work1_2.potpt[potesp_1.nesp * 3 - 1] = temp0[2];
L100:
	    ;
	}
L110:
	;
    }
    return 0;
} /* surfac_ */

/* **************************************************************** */
doublereal dist2_(doublereal *a, doublereal *b)
{
    /* System generated locals */
    doublereal ret_val, d__1, d__2, d__3;


/*     DETERMINE DISTANCES BETWEEN NEIGHBORING ATOMS */

    /* Parameter adjustments */
    --b;
    --a;

    /* Function Body */
/* Computing 2nd power */
    d__1 = a[1] - b[1];
/* Computing 2nd power */
    d__2 = a[2] - b[2];
/* Computing 2nd power */
    d__3 = a[3] - b[3];
    ret_val = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
    return ret_val;
} /* dist2_ */

/* **************************************************************** */
logical collid_(doublereal *cw, doublereal *rw, doublereal *cnbr, doublereal *
	rnbr, logical *mnbr, integer *nnbr, integer *ishape, integer *jnbr, 
	integer *knbr)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;
    logical ret_val;

    /* Local variables */
    static integer i__;
    static doublereal dd2, sr2, vect1, vect2, vect3, sumrad;

/* **************************************************************** */

/*     COLLISION CHECK OF PROBE WITH NEIGHBORING ATOMS */
/*     USED BY SURFAC ONLY. */

/* **************************************************************** */
    /* Parameter adjustments */
    --mnbr;
    --rnbr;
    cnbr -= 4;
    --cw;

    /* Function Body */
    if (*nnbr <= 0) {
	goto L20;
    }

/*     CHECK WHETHER PROBE IS TOO CLOSE TO ANY NEIGHBOR */

    i__1 = *nnbr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (*ishape > 1 && i__ == *jnbr) {
	    goto L10;
	}
	if (*ishape == 3 && (i__ == *knbr || ! mnbr[i__])) {
	    goto L10;
	}
	sumrad = *rw + rnbr[i__];
	vect1 = (d__1 = cw[1] - cnbr[i__ * 3 + 1], abs(d__1));
	if (vect1 >= sumrad) {
	    goto L10;
	}
	vect2 = (d__1 = cw[2] - cnbr[i__ * 3 + 2], abs(d__1));
	if (vect2 >= sumrad) {
	    goto L10;
	}
	vect3 = (d__1 = cw[3] - cnbr[i__ * 3 + 3], abs(d__1));
	if (vect3 >= sumrad) {
	    goto L10;
	}
/* Computing 2nd power */
	d__1 = sumrad;
	sr2 = d__1 * d__1;
/* Computing 2nd power */
	d__1 = vect1;
/* Computing 2nd power */
	d__2 = vect2;
/* Computing 2nd power */
	d__3 = vect3;
	dd2 = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	if (dd2 < sr2) {
	    goto L30;
	}
L10:
	;
    }
L20:
    ret_val = FALSE_;
    goto L40;
L30:
    ret_val = TRUE_;
L40:
    return ret_val;
} /* collid_ */

/* **************************************************************** */
/* Subroutine */ int genun_(doublereal *u, integer *n)
{
    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    double atan(doublereal), sqrt(doublereal), cos(doublereal), sin(
	    doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal x, y, z__, fi, fj, pi;
    static integer nu;
    static doublereal xy;
    static integer nhor, nvert, nequat;

/* **************************************************************** */

/*     GENERATE UNIT VECTORS OVER SPHERE. USED BY SURFAC ONLY. */

/* **************************************************************** */
    /* Parameter adjustments */
    u -= 4;

    /* Function Body */
    pi = atan(1.) * 4.;
    nequat = (integer) sqrt(*n * pi);
    nvert = nequat / 2;
    nu = 0;
    i__1 = nvert + 1;
    for (i__ = 1; i__ <= i__1; ++i__) {
	fi = pi * (i__ - 1) / nvert;
	z__ = cos(fi);
	xy = sin(fi);
	nhor = (integer) (nequat * xy);
	if (nhor < 1) {
	    nhor = 1;
	}
	i__2 = nhor;
	for (j = 1; j <= i__2; ++j) {
	    fj = pi * 2. * (j - 1) / nhor;
	    x = cos(fj) * xy;
	    y = sin(fj) * xy;
	    if (nu >= *n) {
		goto L30;
	    }
	    ++nu;
	    u[nu * 3 + 1] = x;
	    u[nu * 3 + 2] = y;
	    u[nu * 3 + 3] = z__;
/* L10: */
	}
/* L20: */
    }
L30:
    *n = nu;
    return 0;
} /* genun_ */

/* *********************************************************************** */
/* Subroutine */ int potcal_(void)
{
    /* Format strings */
    static char fmt_40[] = "(//5x,\002DIPOLE MOMENT EVALUATED FROM \002,\002"
	    "THE POINT CHARGES\002,/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);

    /* Local variables */
    static integer i__, j;
    static doublereal dx, dy, dz;
    static integer iz;
    static doublereal dip;
    static integer ieq;
    static doublereal rms;
    static integer idip;
    static doublereal bohr, dipx, dipy, dipz, rrms;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical debug;
    extern /* Subroutine */ int elesp_(void);
    static doublereal slope;
    extern /* Subroutine */ int espfit_(integer *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, doublereal *);
    static logical cequiv[14400]	/* was [120][120] */;

    /* Fortran I/O blocks */
    static cilist io___96 = { 0, 6, 0, "(//12X,'ELECTROSTATIC POTENTIAL CHAR"
	    "GES',/)", 0 };
    static cilist io___99 = { 0, 6, 0, "(/12X,'  DIPOLE CONSTRAINTS NOT USED"
	    "')", 0 };
    static cilist io___100 = { 0, 6, 0, "(12X,'        CHARGED MOLECULE',/)", 
	    0 };
    static cilist io___101 = { 0, 6, 0, "(/12X,'DIPOLE CONSTRAINTS WILL BE U"
	    "SED',/)", 0 };
    static cilist io___107 = { 0, 6, 0, "(15X,'ATOM NO.    TYPE    CHARGE')", 
	    0 };
    static cilist io___109 = { 0, 6, 0, "(17X,I2,9X,A2,1X,F10.4)", 0 };
    static cilist io___111 = { 0, 6, 0, "(7X,'ATOM NO.    TYPE    CHARGE   S"
	    "CALED CHARGE')", 0 };
    static cilist io___112 = { 0, 6, 0, "(9X,I2,9X,A2,1X,F10.4,2X,F10.4)", 0 }
	    ;
    static cilist io___113 = { 0, 6, 0, "(/12X,A,4X,I6)", 0 };
    static cilist io___114 = { 0, 6, 0, "(12X,A,4X,F9.4)", 0 };
    static cilist io___115 = { 0, 6, 0, "(12X,A,3X,F9.4)", 0 };
    static cilist io___116 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___121 = { 0, 6, 0, "(12X,' X        Y        Z       TO"
	    "TAL')", 0 };
    static cilist io___122 = { 0, 6, 0, "(8X,4F9.4)", 0 };
    static cilist io___126 = { 0, 6, 0, 0, 0 };
    static cilist io___127 = { 0, 6, 0, 0, 0 };
    static cilist io___128 = { 0, 6, 0, 0, 0 };
    static cilist io___129 = { 0, 6, 0, 0, 0 };
    static cilist io___130 = { 0, 6, 0, "(7X,'ATOM NO.    TYPE    CHARGE')", 
	    0 };
    static cilist io___131 = { 0, 6, 0, "(9X,I2,9X,A2,1X,F10.4)", 0 };
    static cilist io___132 = { 0, 6, 0, "(7X,'ATOM NO.    TYPE    CHARGE   S"
	    "CALED CHARGE')", 0 };
    static cilist io___133 = { 0, 6, 0, "(9X,I2,9X,A2,1X,F10.4,2X,F10.4)", 0 }
	    ;


/* *********************************************************************** */

/*     THIS SUBROUTINE CALCULATES THE TOTAL ELECTROSTATIC POTENTIAL */
/*     THE NUCLEAR CONTRIBUTION IS EVALUATED BY NUCPOT */
/*     THE ELECTRONIC CONTRIBUTION IS EVALUATED BY ELESP */
/*     ESPFIT FITS THE QUANTUM POTENTIAL TO A CLASSICAL POINT CHARGE */
/*     MODEL. */
/*     THIS SUBROUTINE WAS WRITTEN BY B.H.BESLER AND K.M.MERZ IN FEB. */
/*     1989 AT UCSF */

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

/*     DEBUG PRINTING - RESULTS IN COPIOUS OUTPUT */

    debug = i_indx(keywrd_1.keywrd, "DEBUG", (ftnlen)241, (ftnlen)5) != 0;


    elesp_();
    bohr = .529167;

/*     NOW FIT THE ELECTROSTATIC POTENTIAL */

    s_wsfe(&io___96);
    e_wsfe();
    iz = 0;
    if (i_indx(keywrd_1.keywrd, "CHARGE=", (ftnlen)241, (ftnlen)7) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "CHARGE=", (ftnlen)241, (ftnlen)7);
	iz = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    }

/*     DIPOLAR CONSTRAINTS IF DESIRED */

    if (i_indx(keywrd_1.keywrd, "DIPOLE", (ftnlen)241, (ftnlen)6) != 0) {
	idip = 1;
	if (iz != 0) {
	    idip = 0;
	    s_wsfe(&io___99);
	    e_wsfe();
	    s_wsfe(&io___100);
	    e_wsfe();
	}
    } else {
	idip = 0;
    }
    if (idip == 1) {
	s_wsfe(&io___101);
	e_wsfe();
    }

/*     GET X,Y,Z DIPOLE COMPONENTS IF DESIRED */

    if (i_indx(keywrd_1.keywrd, "DIPX=", (ftnlen)241, (ftnlen)5) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "DIPX=", (ftnlen)241, (ftnlen)5);
	dx = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	dx = dipsto_1.ux;
    }
    if (i_indx(keywrd_1.keywrd, "DIPY=", (ftnlen)241, (ftnlen)5) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "DIPY=", (ftnlen)241, (ftnlen)5);
	dy = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	dy = dipsto_1.uy;
    }
    if (i_indx(keywrd_1.keywrd, "DIPZ=", (ftnlen)241, (ftnlen)5) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "DIPZ=", (ftnlen)241, (ftnlen)5);
	dz = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    } else {
	dz = dipsto_1.uz;
    }
    espfit_(&idip, &abc_1.natom, &potesp_1.nesp, &iz, work1_3.esp, 
	    work1_3.potpt, abc_1.co, &dx, &dy, &dz, &rms, &rrms);

/*     WRITE OUT OUR RESULTS TO CHANNEL 6 */
/*     THE CHARGES ARE SCALED TO REPRODUCE 6-31G* CHARGES FOR MNDO ONLY */
/*     AM1 AND MINDO/3 CHARGES ARE NOT SCALED DUE TO THE LOW COORELATION */
/*     COEFFICIENT. SEE BESLER,MERZ,KOLLMAN IN J. COMPUT. CHEM. */
/*     (IN PRESS) */

    if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0 || i_indx(
	    keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0 || i_indx(
	    keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0) {
	s_wsfe(&io___107);
	e_wsfe();
	i__1 = abc_1.natom;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_wsfe(&io___109);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (abc_1.ian[i__ - 1] - 1 << 1), (
		    ftnlen)2);
	    do_fio(&c__1, (char *)&espf_1.q[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
/* L10: */
	}
    } else {

/*     MNDO CALCULATION-SCALE THE CHARGES. TEST FOR SLOPE KEYWORD */

	if (i_indx(keywrd_1.keywrd, "SLOPE=", (ftnlen)241, (ftnlen)6) != 0) {
	    i__1 = i_indx(keywrd_1.keywrd, "SLOPE=", (ftnlen)241, (ftnlen)6);
	    slope = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	} else {
	    slope = 1.422;
	}
	i__1 = abc_1.natom;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    espf_1.qsc[i__ - 1] = slope * espf_1.q[i__ - 1];
/* L20: */
	}
	s_wsfe(&io___111);
	e_wsfe();
	i__1 = abc_1.natom;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_wsfe(&io___112);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (abc_1.ian[i__ - 1] - 1 << 1), (
		    ftnlen)2);
	    do_fio(&c__1, (char *)&espf_1.q[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, (char *)&espf_1.qsc[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
/* L30: */
	}
    }
    s_wsfe(&io___113);
    do_fio(&c__1, "THE NUMBER OF POINTS IS:", (ftnlen)24);
    do_fio(&c__1, (char *)&potesp_1.nesp, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___114);
    do_fio(&c__1, "THE RMS DEVIATION IS:", (ftnlen)21);
    do_fio(&c__1, (char *)&rms, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___115);
    do_fio(&c__1, "THE RRMS DEVIATION IS:", (ftnlen)22);
    do_fio(&c__1, (char *)&rrms, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*     CALCULATE DIPOLE MOMENT IF NEUTRAL MOLECULE */

    if (iz != 0) {
	goto L60;
    } else {
	s_wsfe(&io___116);
	e_wsfe();
	i__1 = abc_1.natom;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    dipx += abc_1.co[i__ * 3 - 3] * espf_1.q[i__ - 1] / bohr;
	    dipy += abc_1.co[i__ * 3 - 2] * espf_1.q[i__ - 1] / bohr;
	    dipz += abc_1.co[i__ * 3 - 1] * espf_1.q[i__ - 1] / bohr;
/* L50: */
	}
/* Computing 2nd power */
	d__1 = dipx;
/* Computing 2nd power */
	d__2 = dipy;
/* Computing 2nd power */
	d__3 = dipz;
	dip = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	s_wsfe(&io___121);
	e_wsfe();
	s_wsfe(&io___122);
	d__1 = dipx * espf_1.cf;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	d__2 = dipy * espf_1.cf;
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	d__3 = dipz * espf_1.cf;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	d__4 = dip * espf_1.cf;
	do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
L60:
/*     DETERMINE WHICH CHARGES SHOULD BE EQUIVALENT BY SYMMETRY AND */
/*     AVERAGE THEM IF DESIRED */
    if (i_indx(keywrd_1.keywrd, "SYMAVG", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = abc_1.natom;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = abc_1.natom;
	    for (j = 1; j <= i__2; ++j) {
		cequiv[i__ + j * 120 - 121] = FALSE_;
		if ((d__3 = (d__1 = dipsto_1.ch[i__ - 1], abs(d__1)) - (d__2 =
			 dipsto_1.ch[j - 1], abs(d__2)), abs(d__3)) < 1e-5) {
		    cequiv[i__ + j * 120 - 121] = TRUE_;
		}
/* L70: */
	    }
	}
	i__2 = abc_1.natom;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    ieq = 0;
	    espf_1.qsc[i__ - 1] = 0.;
	    i__1 = abc_1.natom;
	    for (j = 1; j <= i__1; ++j) {
		if (cequiv[i__ + j * 120 - 121]) {
		    espf_1.qsc[i__ - 1] += (d__1 = espf_1.q[j - 1], abs(d__1))
			    ;
		    ++ieq;
		}
/* L80: */
	    }
	    dipsto_1.ch[i__ - 1] = espf_1.q[i__ - 1] / (d__1 = espf_1.q[i__ - 
		    1], abs(d__1)) * espf_1.qsc[i__ - 1] / ieq;
/* L90: */
	}
	s_wsle(&io___126);
	do_lio(&c__9, &c__1, " ", (ftnlen)1);
	e_wsle();
	s_wsle(&io___127);
	do_lio(&c__9, &c__1, "   ELECTROSTATIC POTENTIAL CHARGES AVERAGED FOR"
		, (ftnlen)47);
	e_wsle();
	s_wsle(&io___128);
	do_lio(&c__9, &c__1, "   SYMMETRY EQUIVALENT ATOMS", (ftnlen)28);
	e_wsle();
	s_wsle(&io___129);
	do_lio(&c__9, &c__1, " ", (ftnlen)1);
	e_wsle();
	if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0 || 
		i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0 
		|| i_indx(keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 
		0) {
	    s_wsfe(&io___130);
	    e_wsfe();
	    i__2 = abc_1.natom;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		s_wsfe(&io___131);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, elemts_1.elemnt + (abc_1.ian[i__ - 1] - 1 << 1),
			 (ftnlen)2);
		do_fio(&c__1, (char *)&dipsto_1.ch[i__ - 1], (ftnlen)sizeof(
			doublereal));
		e_wsfe();
/* L100: */
	    }
	} else {
	    s_wsfe(&io___132);
	    e_wsfe();
	    i__2 = abc_1.natom;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		s_wsfe(&io___133);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, elemts_1.elemnt + (abc_1.ian[i__ - 1] - 1 << 1),
			 (ftnlen)2);
		do_fio(&c__1, (char *)&dipsto_1.ch[i__ - 1], (ftnlen)sizeof(
			doublereal));
		d__1 = dipsto_1.ch[i__ - 1] * slope;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		e_wsfe();
/* L110: */
	    }
	}
    }
    return 0;
} /* potcal_ */

/* Subroutine */ int elesp_(void)
{
    /* Initialized data */

    static doublereal bohr = .529167;

    /* Format strings */
    static char fmt_420[] = "(1x,4e16.7)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;
    olist o__1;

    /* Builtin functions */
    double atan(doublereal);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);
    integer f_open(olist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal t;
    static integer nc;
    static doublereal ra;
    static integer in;
    static doublereal pi;
    static integer is, ip, icd, ipc, ipe, isc;
    static doublereal rij;
    static integer ipr, nqn, npr, ipx;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sum;
    extern doublereal dex2_(integer *);
    static doublereal fval, cesp[90000];
    extern /* Subroutine */ int fsub_(integer *, doublereal *, doublereal *);
    static doublereal norm;
    extern /* Subroutine */ int ovlp_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), mult_(doublereal *, 
	    doublereal *, doublereal *, integer *);
    static logical sto3g;
    static doublereal cespm2[90000]	/* was [300][300] */;
    extern /* Subroutine */ int setup3_(void), naicap_(integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *, integer *),
	     naicas_(integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *, integer *);
    static doublereal cespml[90000];
    extern /* Subroutine */ int densit_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *, integer *), 
	    setupg_(void);
    static logical potwrt;

    /* Fortran I/O blocks */
    static cilist io___164 = { 0, 21, 0, "(I5)", 0 };
    static cilist io___165 = { 0, 21, 0, fmt_420, 0 };


/* *********************************************************************** */
/*     ELESP LOADS THE STO-6G BASIS SET ONTO THE ATOMS, PERFOMS THE */
/*     DEORTHOGONALIZATION OF THE COEFFICIENTS AND EVALUATES THE */
/*     ELECTRONIC CONTRIBUTION TO THE ESP. IT WAS WRITTEN BY B.H.BESLER */
/*     AND K.M.MERZ IN FEB. 1989 AT UCSF. */

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

/*  END OF MINDO/3 COMMON BLOCKS */

    pi = 4. * atan(1.);

/*     PUT STO-6G BASIS SET ON ATOM CENTERS */

    for (i__ = -1; i__ <= 10; ++i__) {
	espc_1.dex[i__ + 1] = dex2_(&i__);
/* L10: */
    }
    for (i__ = 0; i__ <= 7; ++i__) {
	espc_1.fac[i__] = 1. / espc_1.fac[i__];
/* L20: */
    }
    for (m = 0; m <= 8; ++m) {
	k = 1;
	espc_1.fv[m] = 1. / (m * 2. + 1.);
	for (t = .05; t <= 41.; t += .05) {
	    ++k;
	    fsub_(&m, &t, &fval);
	    espc_1.fv[m + k * 9 - 9] = fval;
/* L30: */
	}
    }

/*     LOAD BASIS FUNCTIONS INTO ARRAYS */

    sto3g = i_indx(keywrd_1.keywrd, "STO3G", (ftnlen)241, (ftnlen)5) != 0;
    if (sto3g) {
	icd = 3;
	setup3_();
    } else {
	icd = 6;
	setupg_();
    }
    nc = 0;
    npr = 0;
    i__1 = abc_1.natom;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (abc_1.ian[i__ - 1] <= 2) {
	    i__2 = icd;
	    for (j = 1; j <= i__2; ++j) {
		espc_1.cc[npr + j - 1] = sto6g_1.allc[j - 1];
/* Computing 2nd power */
		d__1 = expont_1.zs[0];
		espc_1.ex[npr + j - 1] = sto6g_1.allz[j - 1] * (d__1 * d__1);
		espc_1.cen[npr + j - 1] = abc_1.co[i__ * 3 - 3] / bohr;
		espc_1.cen[npr + j + 1799] = abc_1.co[i__ * 3 - 2] / bohr;
		espc_1.cen[npr + j + 3599] = abc_1.co[i__ * 3 - 1] / bohr;
		espc_1.iam[npr + j - 1] = 0;
		espc_1.iam[npr + j + 1799] = 0;
		espc_1.fc[npr + j - 1] = (doublereal) i__;
/* L40: */
	    }
	    ++nc;
	    npr += icd;
	} else {
/*        DETERMINE PRINCIPAL QUANTUM NUMBER(NQN) */
/*        OF ORBITALS TO BE USED */

	    nqn = 2;
	    if (abc_1.ian[i__ - 1] > 10 && abc_1.ian[i__ - 1] <= 18) {
		nqn = 3;
	    }
	    if (abc_1.ian[i__ - 1] > 18 && abc_1.ian[i__ - 1] <= 36) {
		nqn = 4;
	    }
	    if (abc_1.ian[i__ - 1] > 36 && abc_1.ian[i__ - 1] <= 54) {
		nqn = 5;
	    }

	    i__2 = icd;
	    for (j = 1; j <= i__2; ++j) {
		espc_1.cc[npr + j - 1] = sto6g_1.allc[j + (nqn + 6) * 6 - 43];
/* Computing 2nd power */
		d__1 = expont_1.zs[abc_1.ian[i__ - 1] - 1];
		espc_1.ex[npr + j - 1] = sto6g_1.allz[j + (nqn + 6) * 6 - 43] 
			* (d__1 * d__1);
		espc_1.cen[npr + j - 1] = abc_1.co[i__ * 3 - 3] / bohr;
		espc_1.cen[npr + j + 1799] = abc_1.co[i__ * 3 - 2] / bohr;
		espc_1.cen[npr + j + 3599] = abc_1.co[i__ * 3 - 1] / bohr;
		espc_1.iam[npr + j - 1] = 0;
		espc_1.iam[npr + j + 1799] = 0;
/* L50: */
	    }
	    ++nc;
	    npr += icd;
	    for (k = 1; k <= 3; ++k) {
		i__2 = icd;
		for (j = 1; j <= i__2; ++j) {
		    espc_1.cc[npr + j - 1] = sto6g_1.allc[j + (nqn + 12) * 6 
			    - 43];
/* Computing 2nd power */
		    d__1 = expont_1.zp[abc_1.ian[i__ - 1] - 1];
		    espc_1.ex[npr + j - 1] = sto6g_1.allz[j + (nqn + 12) * 6 
			    - 43] * (d__1 * d__1);
		    espc_1.cen[npr + j - 1] = abc_1.co[i__ * 3 - 3] / bohr;
		    espc_1.cen[npr + j + 1799] = abc_1.co[i__ * 3 - 2] / bohr;
		    espc_1.cen[npr + j + 3599] = abc_1.co[i__ * 3 - 1] / bohr;
		    espc_1.iam[npr + j - 1] = 1;
		    espc_1.iam[npr + j + 1799] = k;
/* L60: */
		}
		++nc;
		npr += icd;
/* L70: */
	    }
	}
/* L80: */
    }

/*     CALCULATE NORMALIZATION CONSTANTS AND INCLUDE */
/*     THEM IN THE CONTRACTION COEFFICIENTS */

    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	d__1 = espc_1.ex[i__ - 1] * 2. / pi;
	d__2 = espc_1.ex[i__ - 1] * 4.;
	d__3 = espc_1.iam[i__ - 1] / 2.;
	norm = pow_dd(&d__1, &c_b182) * pow_dd(&d__2, &d__3) / sqrt(
		espc_1.dex[espc_1.iam[i__ - 1] * 2]);
	espc_1.cc[i__ - 1] *= norm;
/* L90: */
    }
    ipr = 0;

/*     PERFORM SORT OF PRIMITIVES BY ANGULAR MOMENTUM */

    is = 0;
    ip = 0;
    ipc = 0;
    isc = 0;
    j = 0;
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 0) {
	    ++is;
	    espc_1.ind[is - 1] = i__;
	}
/* L100: */
    }
    ip = is;
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 1 && espc_1.iam[i__ + 1799] == 1) {
	    ++ip;
	    espc_1.ind[ip - 1] = i__;
	}
/* L110: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 1 && espc_1.iam[i__ + 1799] == 2) {
	    ++ip;
	    espc_1.ind[ip - 1] = i__;
	}
/* L120: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 1 && espc_1.iam[i__ + 1799] == 3) {
	    ++ip;
	    espc_1.ind[ip - 1] = i__;
	}
/* L130: */
    }
    i__1 = nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * icd - icd + 1;
	if (espc_1.iam[in - 1] == 0) {
	    ++isc;
	    indx_1.indc[isc - 1] = i__;
	}
/* L140: */
    }
    ipc = isc;
    i__1 = nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * icd - icd + 1;
	if (espc_1.iam[in - 1] == 1 && espc_1.iam[in + 1799] == 1) {
	    ++ipc;
	    indx_1.indc[ipc - 1] = i__;
	}
/* L150: */
    }
    i__1 = nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * icd - icd + 1;
	if (espc_1.iam[in - 1] == 1 && espc_1.iam[in + 1799] == 2) {
	    ++ipc;
	    indx_1.indc[ipc - 1] = i__;
	}
/* L160: */
    }
    i__1 = nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * icd - icd + 1;
	if (espc_1.iam[in - 1] == 1 && espc_1.iam[in + 1799] == 3) {
	    ++ipc;
	    indx_1.indc[ipc - 1] = i__;
	}
/* L170: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cc[espc_1.ind[i__ - 1] - 1];
/* L180: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cc[i__ - 1] = espc_1.temp[i__ - 1];
/* L190: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.ex[espc_1.ind[i__ - 1] - 1];
/* L200: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.ex[i__ - 1] = espc_1.temp[i__ - 1];
/* L210: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cen[espc_1.ind[i__ - 1] - 1];
/* L220: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cen[i__ - 1] = espc_1.temp[i__ - 1];
/* L230: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cen[espc_1.ind[i__ - 1] + 1799];
/* L240: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cen[i__ + 1799] = espc_1.temp[i__ - 1];
/* L250: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cen[espc_1.ind[i__ - 1] + 3599];
/* L260: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cen[i__ + 3599] = espc_1.temp[i__ - 1];
/* L270: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.itemp[i__ - 1] = espc_1.iam[espc_1.ind[i__ - 1] - 1];
/* L280: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.iam[i__ - 1] = espc_1.itemp[i__ - 1];
/* L290: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.itemp[i__ - 1] = espc_1.iam[espc_1.ind[i__ - 1] + 1799];
/* L300: */
    }
    i__1 = npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.iam[i__ + 1799] = espc_1.itemp[i__ - 1];
/* L310: */
    }
/*     CALCULATE OVERLAP MATRIX OF STO-6G FUNCTIONS */

    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	ovlp_(&j, &c__1, &is, &ip, &npr, &nc, &icd);
/* L320: */
    }

    i__1 = nc;
    for (j = 1; j <= i__1; ++j) {
	i__2 = nc;
	for (k = 1; k <= i__2; ++k) {
	    cespm2[indx_1.indc[j - 1] + indx_1.indc[k - 1] * 300 - 301] = 
		    espc_1.ovl[j + k * 300 - 301];
/* L330: */
	}
    }
    i__2 = nc;
    for (j = 1; j <= i__2; ++j) {
	i__1 = nc;
	for (k = 1; k <= i__1; ++k) {
	    espc_1.ovl[j + k * 300 - 301] = cespm2[j + k * 300 - 301];
/* L340: */
	}
    }
    l = 0;
    i__1 = nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
	    cesp[l - 1] = espc_1.ovl[i__ + j * 300 - 301];
/* L350: */
	}
    }

/*     DEORTHOGONALIZE THE COEFFICIENTS AND REFORM THE DENSITY MATRIX */

    rsp_(cesp, &nc, &c__1, espc_1.temp, cespml);
    i__2 = nc;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    sum = 0.;
	    i__3 = nc;
	    for (k = 1; k <= i__3; ++k) {
		sum += cespml[i__ + (k - 1) * nc - 1] / sqrt(espc_1.temp[k - 
			1]) * cespml[j + (k - 1) * nc - 1];
		cesp[i__ + (j - 1) * nc - 1] = sum;
		cesp[j + (i__ - 1) * nc - 1] = sum;
/* L360: */
	    }
	}
    }
    mult_(vector_1.c__, cesp, cespml, &nc);
    densit_(cespml, &nc, &nc, &molkst_1.nclose, &molkst_1.nopen, &
	    molkst_1.fract, cesp, &c__2);

/*     NOW CALCULATE THE ELECTRONIC CONTRIBUTION TO THE ELECTROSTATIC POT */

    l = 0;
    i__3 = nc;
    for (i__ = 1; i__ <= i__3; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    ++l;
	    espf_2.cespm[i__ + j * 300 - 301] = cesp[l - 1];
	    espf_2.cespm[j + i__ * 300 - 301] = cesp[l - 1];
/* L370: */
	}
    }
    ipx = (npr - is) / 3;
    ipe = is + ipx;
    i__1 = potesp_1.nesp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	work1_3.es[i__ - 1] = 0.;
/* L380: */
    }
    naicas_(&isc, &is, &ip, &npr, &nc, &ipe, &ipx, &icd);
    naicap_(&isc, &is, &ip, &npr, &nc, &ipe, &ipx, &icd);
/*     CALCULATE TOTAL ESP AND FORM ARRAYS FOR ESPFIT */
    i__1 = potesp_1.nesp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	work1_3.esp[i__ - 1] = 0.;
	i__3 = abc_1.natom;
	for (j = 1; j <= i__3; ++j) {
/* Computing 2nd power */
	    d__1 = abc_1.co[j * 3 - 3] - work1_3.potpt[i__ * 3 - 3];
/* Computing 2nd power */
	    d__2 = abc_1.co[j * 3 - 2] - work1_3.potpt[i__ * 3 - 2];
/* Computing 2nd power */
	    d__3 = abc_1.co[j * 3 - 1] - work1_3.potpt[i__ * 3 - 1];
	    ra = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    work1_3.esp[i__ - 1] += core_1.tore[abc_1.ian[j - 1] - 1] / (ra / 
		    bohr);
/* L390: */
	}
	work1_3.esp[i__ - 1] -= work1_3.es[i__ - 1];
	i__3 = abc_1.natom;
	for (j = 1; j <= i__3; ++j) {
/* Computing 2nd power */
	    d__1 = abc_1.co[j * 3 - 3] - work1_3.potpt[i__ * 3 - 3];
/* Computing 2nd power */
	    d__2 = abc_1.co[j * 3 - 2] - work1_3.potpt[i__ * 3 - 2];
/* Computing 2nd power */
	    d__3 = abc_1.co[j * 3 - 1] - work1_3.potpt[i__ * 3 - 1];
	    rij = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) / bohr;
	    espf_2.b[j - 1] += work1_3.esp[i__ - 1] * 1. / rij;
/* L400: */
	}
    }

/*     IF REQUESTED WRITE OUT ELECTRIC POTENTIAL DATA TO */
/*     UNIT 21 */

    potwrt = i_indx(keywrd_1.keywrd, "POTWRT", (ftnlen)241, (ftnlen)6) != 0;
    if (potwrt) {
	o__1.oerr = 0;
	o__1.ounit = 21;
	o__1.ofnm = 0;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
	s_wsfe(&io___164);
	do_fio(&c__1, (char *)&potesp_1.nesp, (ftnlen)sizeof(integer));
	e_wsfe();
	i__3 = potesp_1.nesp;
	for (i__ = 1; i__ <= i__3; ++i__) {
/* L410: */
	    s_wsfe(&io___165);
	    do_fio(&c__1, (char *)&work1_3.esp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    d__1 = work1_3.potpt[i__ * 3 - 3] / bohr;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = work1_3.potpt[i__ * 3 - 2] / bohr;
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&work1_3.potpt[i__ * 3 - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
    }
    return 0;
} /* elesp_ */

doublereal dex2_(integer *m)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__;

    if (*m < 2) {
	ret_val = 1.;
    } else {
	ret_val = 1.;
	i__1 = *m;
	for (i__ = 1; i__ <= i__1; i__ += 2) {
/* L10: */
	    ret_val *= i__;
	}
    }
    return ret_val;
} /* dex2_ */

/* Subroutine */ int espblo_(void)
{
    return 0;
} /* espblo_ */

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
/* Subroutine */ int espfit_(integer *idip, integer *natom, integer *nesp, 
	integer *iz, doublereal *esp, doublereal *potpt, doublereal *co, 
	doublereal *dx, doublereal *dy, doublereal *dz, doublereal *rms, 
	doublereal *rrms)
{
    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal det, rij, rik, bohr, espc, ctot;
    extern /* Subroutine */ int osinv_(doublereal *, integer *, doublereal *);

/* *********************************************************************** */

/*     THIS ROUTINE FITS THE ELECTROSTATIC POTENTIAL TO A MONOPOLE */
/*     EXPANSION. FITTING TO THE DIPOLE MONENT CAN ALSO BE DONE. */
/*     THIS ROUTINE WAS WRITTEN BY B.H.BESLER AND K.M.MERZ */
/*     IN FEB. 1989 AT UCSF. */

/*     ON INPUT:  IDIP = FLAG TO INDICATE IF THE DIPOLE IS FIT */
/*                NATOM = NUMBER OF ATOMS */
/*                NESP = NUMBER OF ESP POINTS */
/*                IZ = MOLECULAR CHARGE */
/*                ESP = TOTAL ESP AT THE POINTS */
/*                POTPT = ESP POINTS */
/*                CO = COORDINATES */
/*                DX = X COMPONENT OF THE DIPOLE */
/*                DY = Y COMPONENT OF THE DIPOLE */
/*                DZ = Z COMPONENT OF THE DIPOLE */

/*     ON OUTPUT: Q = ESP CHARGES */
/*                RMS = ROOT MEAN SQUARE FIT */
/*                RRMS = RELATIVE ROOT MEAN SQUARE FIT */

/*     FOR MORE DETAILS SEE: BESLER,MERZ,KOLLMAN J. COMPUT. CHEM. */
/*     (IN PRESS) */
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
    co -= 4;
    potpt -= 4;
    --esp;

    /* Function Body */
    bohr = .529167;
/*     CONVERSION FACTOR FOR DEBYE TO ATOMIC UNITS */
    espf_1.cf = 2.5413350139599897;

/*     THE FOLLOWING SETS UP THE LINEAR EQUATION A*Q=B */
/*     SET UP THE A(J,K) ARRAY */

    i__1 = *natom;
    for (k = 1; k <= i__1; ++k) {
	i__2 = *natom;
	for (j = 1; j <= i__2; ++j) {
	    i__3 = *nesp;
	    for (i__ = 1; i__ <= i__3; ++i__) {
/* Computing 2nd power */
		d__1 = co[k * 3 + 1] - potpt[i__ * 3 + 1];
/* Computing 2nd power */
		d__2 = co[k * 3 + 2] - potpt[i__ * 3 + 2];
/* Computing 2nd power */
		d__3 = co[k * 3 + 3] - potpt[i__ * 3 + 3];
		rik = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) / bohr;
/* Computing 2nd power */
		d__1 = co[j * 3 + 1] - potpt[i__ * 3 + 1];
/* Computing 2nd power */
		d__2 = co[j * 3 + 2] - potpt[i__ * 3 + 2];
/* Computing 2nd power */
		d__3 = co[j * 3 + 3] - potpt[i__ * 3 + 3];
		rij = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) / bohr;
		espf_1.a[j + k * 120 - 121] += 1. / rik * 1. / rij;
/* L10: */
	    }
	}
	espf_1.a[*natom + 1 + k * 120 - 121] = 1.;
	espf_1.a[k + (*natom + 1) * 120 - 121] = 1.;
	espf_1.a[*natom + 1 + (*natom + 1) * 120 - 121] = 0.;
	if (*idip == 1) {
	    espf_1.a[*natom + 2 + k * 120 - 121] = co[k * 3 + 1] / bohr;
	    espf_1.a[k + (*natom + 2) * 120 - 121] = co[k * 3 + 1] / bohr;
	    espf_1.a[*natom + 2 + (*natom + 2) * 120 - 121] = 0.;
	    espf_1.a[*natom + 3 + k * 120 - 121] = co[k * 3 + 2] / bohr;
	    espf_1.a[k + (*natom + 3) * 120 - 121] = co[k * 3 + 2] / bohr;
	    espf_1.a[*natom + 3 + (*natom + 3) * 120 - 121] = 0.;
	    espf_1.a[*natom + 4 + k * 120 - 121] = co[k * 3 + 3] / bohr;
	    espf_1.a[k + (*natom + 4) * 120 - 121] = co[k * 3 + 3] / bohr;
	    espf_1.a[*natom + 4 + (*natom + 4) * 120 - 121] = 0.;
	}
/* L20: */
    }
    espf_1.b[*natom] = (real) (*iz);
    espf_1.b[*natom + 1] = *dx / espf_1.cf;
    espf_1.b[*natom + 2] = *dy / espf_1.cf;
    espf_1.b[*natom + 3] = *dz / espf_1.cf;

/*     INSERT CHARGE AND DIPOLAR (IF DESIRED) CONSTRAINTS */

    if (*idip == 1) {
	l = 0;
	i__1 = *natom + 4;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__3 = *natom + 4;
	    for (j = 1; j <= i__3; ++j) {
		++l;
/* L30: */
		espf_1.al[l - 1] = espf_1.a[i__ + j * 120 - 121];
	    }
	}
    } else {
	l = 0;
	i__3 = *natom + 1;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__1 = *natom + 1;
	    for (j = 1; j <= i__1; ++j) {
		++l;
/* L40: */
		espf_1.al[l - 1] = espf_1.a[i__ + j * 120 - 121];
	    }
	}
    }
    if (*idip == 1) {
	i__1 = *natom + 4;
	osinv_(espf_1.al, &i__1, &det);
    } else {
	i__1 = *natom + 1;
	osinv_(espf_1.al, &i__1, &det);
    }
    if (*idip == 1) {
	l = 0;
	i__1 = *natom + 4;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__3 = *natom + 4;
	    for (j = 1; j <= i__3; ++j) {
		++l;
/* L50: */
		espf_1.a[i__ + j * 120 - 121] = espf_1.al[l - 1];
	    }
	}
    } else {
	l = 0;
	i__3 = *natom + 1;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__1 = *natom + 1;
	    for (j = 1; j <= i__1; ++j) {
		++l;
/* L60: */
		espf_1.a[i__ + j * 120 - 121] = espf_1.al[l - 1];
	    }
	}
    }

/*     SOLVE FOR THE CHARGES */

    if (*idip == 1) {
	i__1 = *natom + 4;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__3 = *natom + 4;
	    for (j = 1; j <= i__3; ++j) {
		espf_1.q[i__ - 1] += espf_1.a[i__ + j * 120 - 121] * espf_1.b[
			j - 1];
/* L70: */
	    }
	}
    } else {
	i__3 = *natom + 1;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    i__1 = *natom + 1;
	    for (j = 1; j <= i__1; ++j) {
		espf_1.q[i__ - 1] += espf_1.a[i__ + j * 120 - 121] * espf_1.b[
			j - 1];
/* L80: */
	    }
	}
    }

/*     CALCULATE ROOT MEAN SQUARE FITS AND RELATIVE ROOT MEAN SQUARE FITS */

    ctot = 0.f;
    i__1 = *nesp;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc = 0.;
	i__3 = *natom;
	for (j = 1; j <= i__3; ++j) {
/* Computing 2nd power */
	    d__1 = co[j * 3 + 1] - potpt[i__ * 3 + 1];
/* Computing 2nd power */
	    d__2 = co[j * 3 + 2] - potpt[i__ * 3 + 2];
/* Computing 2nd power */
	    d__3 = co[j * 3 + 3] - potpt[i__ * 3 + 3];
	    rij = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) / bohr;
/* L90: */
	    espc += espf_1.q[j - 1] / rij;
	}
/* Computing 2nd power */
	d__1 = espc - esp[i__];
	*rms += d__1 * d__1;
/* L100: */
/* Computing 2nd power */
	d__1 = esp[i__];
	*rrms += d__1 * d__1;
    }
    *rms = sqrt(*rms / *nesp);
    *rrms = *rms / sqrt(*rrms / *nesp);
    *rms *= 627.51;
    return 0;
} /* espfit_ */

/* *********************************************************************** */
/* Subroutine */ int fsub_(integer *n, doublereal *x, doublereal *fval)
{
    /* Initialized data */

    static doublereal a0 = 0.;
    static doublereal a1s2 = .5;
    static doublereal pie4 = .7853981633974483096156608;
    static doublereal a1 = 1.;
    static doublereal xsw = 24.;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    double exp(doublereal), sqrt(doublereal);

    /* Local variables */
    static doublereal e;
    static integer i__, k;
    static doublereal ff[21];
    static integer ku;
    static doublereal fac, sum, fac0, sum1, suma, term[200], term0;

/* *********************************************************************** */

/*     CALCULATE THE FM(T). KINDLY SUPPLIED BY RUS PITZER AND CLEANED UP */
/*     BY K.M.MERZ IN FEB. 1989 AT UCSF. */

/*     ON INPUT:  N = INDEX */
/*                X = EXPONENT */
/*     ON OUTPUT: FVAL = VALUE OF THE FUNCTION */

/*     FOR MORE DETAILS SEE: OBARA AND SAIKA J. CHEM. PHYS. 1986,84,3963 */
/* *********************************************************************** */
    e = a1s2 * exp(-(*x));
    fac0 = (doublereal) (*n);
    fac0 += a1s2;
    if (*x > xsw) {
	goto L50;
    }

/*     USE POWER SERIES */

L10:
    fac = fac0;
    term0 = e / fac;
    sum = term0;
    ku = (integer) (*x - fac0);
    if (ku < 1) {
	goto L30;
    }

/*     SUM INCREASING TERMS FORWARDS */

    i__1 = ku;
    for (k = 1; k <= i__1; ++k) {
	fac += a1;
	term0 = term0 * *x / fac;
	sum += term0;
/* L20: */
    }
L30:
    i__ = 1;
    fac += a1;
    term[0] = term0 * *x / fac;
    suma = sum + term[0];
    if (sum == suma) {
	goto L90;
    }
L40:
    ++i__;
    fac += a1;
    term[i__ - 1] = term[i__ - 2] * *x / fac;
    sum1 = suma;
    suma += term[i__ - 1];
    if (sum1 - suma != 0.) {
	goto L40;
    } else {
	goto L90;
    }

/*     USE ASYMPTOTIC SERIES */

L50:
    sum = sqrt(pie4 / *x);
    if (*n == 0) {
	goto L70;
    }
    fac = -a1s2;
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fac += a1;
	sum = sum * fac / *x;
/* L60: */
    }
L70:
    i__ = 1;
    term[0] = -e / *x;
    suma = sum + term[0];
    if (sum == suma) {
	goto L90;
    }
    fac = fac0;
    ku = (integer) (*x + fac0 - a1);
    i__1 = ku;
    for (i__ = 2; i__ <= i__1; ++i__) {
	fac -= a1;
	term[i__ - 1] = term[i__ - 2] * fac / *x;
	sum1 = suma;
	suma += term[i__ - 1];
	if (sum1 == suma) {
	    goto L90;
	}
/* L80: */
    }

/*     XSW SET TOO LOW. USE POWER SERIES. */

    goto L10;

/*     SUM DECREASING TERMS BACKWARDS */

L90:
    sum1 = a0;
    i__1 = i__;
    for (k = 1; k <= i__1; ++k) {
	sum1 += term[i__ + 1 - k - 1];
/* L100: */
    }
    ff[*n] = sum + sum1;

/*     USE RECURRENCE RELATION */

    if (*n == 0) {
	goto L120;
    }
    i__1 = *n;
    for (k = 1; k <= i__1; ++k) {
	fac0 -= a1;
	ff[*n + 1 - k - 1] = (e + *x * ff[*n + 2 - k - 1]) / fac0;
/* L110: */
    }
L120:
    *fval = ff[*n];
    return 0;
} /* fsub_ */

/* Subroutine */ int setup3_(void)
{
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
/*     SET-UP THE STEWART'S STO-3G EXPANSIONS */
/*     FROM J. CHEM. PHYS. 52 431. */
/*                                            1S */
    sto6g_1.allz[0] = 2.227660584;
    sto6g_1.allz[1] = .4057711562;
    sto6g_1.allz[2] = .1098175104;

    sto6g_1.allc[0] = .1543289673;
    sto6g_1.allc[1] = .5353281423;
    sto6g_1.allc[2] = .4446345422;
/*                                      2S */
    sto6g_1.allz[6] = 2.581578398;
    sto6g_1.allz[7] = .1567622104;
    sto6g_1.allz[8] = .06018332272;

    sto6g_1.allc[6] = -.05994474934;
    sto6g_1.allc[7] = .5960385398;
    sto6g_1.allc[8] = .4581786291;
/*                                     2P */
    sto6g_1.allz[42] = .9192379002;
    sto6g_1.allz[43] = .2359194503;
    sto6g_1.allz[44] = .08009805746;

    sto6g_1.allc[42] = .1623948553;
    sto6g_1.allc[43] = .5661708862;
    sto6g_1.allc[44] = .4223071752;
/*                                      3S */
    sto6g_1.allz[12] = .5641487709;
    sto6g_1.allz[13] = .06924421391;
    sto6g_1.allz[14] = .03269529097;

    sto6g_1.allc[12] = -.1782577972;
    sto6g_1.allc[13] = .8612761663;
    sto6g_1.allc[14] = .2261841969;
/*                                     3P */
    sto6g_1.allz[48] = 2.692880368;
    sto6g_1.allz[49] = .1489359592;
    sto6g_1.allz[50] = .0573958504;

    sto6g_1.allc[48] = -.01061945788;
    sto6g_1.allc[49] = .5218564264;
    sto6g_1.allc[50] = .5450015143;
/*                                      4S */
    sto6g_1.allz[18] = .2267938753;
    sto6g_1.allz[19] = .04448178019;
    sto6g_1.allz[20] = .02195294664;

    sto6g_1.allc[18] = -.3349048323;
    sto6g_1.allc[19] = 1.056744667;
    sto6g_1.allc[20] = .125666168;
/*                                     4P */
    sto6g_1.allz[54] = .485969222;
    sto6g_1.allz[55] = .07430216918;
    sto6g_1.allz[56] = .03653340923;

    sto6g_1.allc[54] = -.06147823411;
    sto6g_1.allc[55] = .6604172234;
    sto6g_1.allc[56] = .3932639495;
/*                                      5S */
    sto6g_1.allz[24] = .1080198458;
    sto6g_1.allz[25] = .04408119382;
    sto6g_1.allz[26] = .0261081181;

    sto6g_1.allc[24] = -.6617401158;
    sto6g_1.allc[25] = .7467595004;
    sto6g_1.allc[26] = .7146490945;
/*                                     5P */
    sto6g_1.allz[60] = .2127482317;
    sto6g_1.allz[61] = .0472964862;
    sto6g_1.allz[62] = .02604865324;

    sto6g_1.allc[60] = -.1389529695;
    sto6g_1.allc[61] = .8076691064;
    sto6g_1.allc[62] = .2726029342;

    return 0;
} /* setup3_ */

/* Subroutine */ int ovlp_(integer *ic, integer *iesp, integer *is, integer *
	ip, integer *npr, integer *nc, integer *icd)
{

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double atan(doublereal), exp(doublereal), pow_dd(doublereal *, doublereal 
	    *);

    /* Local variables */
    static integer i__, j, k;
    static doublereal pi;
    static integer np, ipr, ips, jps, istart;

/* *********************************************************************** */

/*     OVLP CALCULATES THE OVERLAP INTEGRALS FOR A STO-6G BASIS SET. */
/*     THE RESULTING INTEGRALS ARE USED IN THE DEORTHOGONALIZATION */
/*     PROCESS. */
/*     THE CODE WAS WRITTEN BY B.H.BESLER AND K.M.MERZ IN FEB. 1989 */
/*     AT UCSF. */

/*     ON INPUT:  IC = LOOP INDEX */
/*                IESP = LOOP INDEX */
/*                IS = NUMBER OF S ORBITALS */
/*                IP = NUMBER OF P ORBITALS */
/*                NPR = NUMBER OF PRIMITIVES */
/*                NC = NUMBER OF CONTRACTED FUNCTIONS */

/*     ON OUTPUT: OVL IS FILLED WITH THE OVERLAP INTEGRAL VALUE */

/*     FOR FURTHER INFO SEE: OBARA & SAIKA J.CHEM.PHYS. 1986,84,3963 */
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

/*     CALCULATE DISTANCE ARRAYS */

    pi = 4. * atan(1.);
    ipr = *ic * *icd - *icd + 1;
    istart = ipr;
    i__1 = *npr;
    for (i__ = istart; i__ <= i__1; ++i__) {
	x_1.dx[i__ - 1] = espc_2.cen[ipr - 1] - espc_2.cen[i__ - 1];
	x_1.dy[i__ - 1] = espc_2.cen[ipr + 1799] - espc_2.cen[i__ + 1799];
	x_1.dz[i__ - 1] = espc_2.cen[ipr + 3599] - espc_2.cen[i__ + 3599];
/* Computing 2nd power */
	d__1 = x_1.dx[i__ - 1];
/* Computing 2nd power */
	d__2 = x_1.dy[i__ - 1];
/* Computing 2nd power */
	d__3 = x_1.dz[i__ - 1];
	x_1.td[i__ - 1] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* L10: */
    }

/*     CALCULATE EXPONENT SUM */

    i__1 = *npr;
    for (i__ = istart; i__ <= i__1; ++i__) {
	i__2 = *icd;
	for (j = 1; j <= i__2; ++j) {
	    x_1.exs[i__ + j * 1800 - 1801] = 1. / (espc_2.ex[ipr + j - 2] + 
		    espc_2.ex[i__ - 1]);
	    x_1.ce[i__ + j * 1800 - 1801] = espc_2.ex[ipr + j - 2] * 
		    espc_2.ex[i__ - 1] * x_1.exs[i__ + j * 1800 - 1801];
/* L20: */
	}
    }

/*     CALCULATE EXPONENT WEIGHTED CENTERS */

    i__2 = *npr;
    for (i__ = istart; i__ <= i__2; ++i__) {
	i__1 = *icd;
	for (j = 1; j <= i__1; ++j) {
	    x_1.ewcx[i__ + j * 1800 - 1801] = (espc_2.ex[i__ - 1] * 
		    espc_2.cen[i__ - 1] + espc_2.ex[ipr + j - 2] * espc_2.cen[
		    ipr + j - 2]) * x_1.exs[i__ + j * 1800 - 1801];
	    x_1.ewcy[i__ + j * 1800 - 1801] = (espc_2.ex[i__ - 1] * 
		    espc_2.cen[i__ + 1799] + espc_2.ex[ipr + j - 2] * 
		    espc_2.cen[ipr + j + 1798]) * x_1.exs[i__ + j * 1800 - 
		    1801];
	    x_1.ewcz[i__ + j * 1800 - 1801] = (espc_2.ex[i__ - 1] * 
		    espc_2.cen[i__ + 3599] + espc_2.ex[ipr + j - 2] * 
		    espc_2.cen[ipr + j + 3598]) * x_1.exs[i__ + j * 1800 - 
		    1801];
/* L30: */
	}
    }
    i__1 = *npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = *icd;
	for (j = 1; j <= i__2; ++j) {
	    x_1.expn[i__ + j * 1800 - 1801] = exp(-x_1.ce[i__ + j * 1800 - 
		    1801] * x_1.td[i__ - 1]);
	    d__1 = pi * x_1.exs[i__ + j * 1800 - 1801];
	    x_1.nai[i__ + j * 1800 - 1801] = pow_dd(&d__1, &c_b261) * 
		    x_1.expn[i__ + j * 1800 - 1801];
	    x_1.expn[i__ + j * 1800 - 1801] = x_1.nai[i__ + j * 1800 - 1801];
/* L40: */
	}
    }

/*     CALCULATE (S||P) ESP INTEGRALS */

    if (espc_2.iam[ipr - 1] == 0 && *is != *ip) {
	np = *is + 1;
	i__2 = *npr;
	for (i__ = np; i__ <= i__2; ++i__) {
	    i__1 = *icd;
	    for (j = 1; j <= i__1; ++j) {
		switch (espc_2.iam[i__ + 1799]) {
		    case 1:  goto L50;
		    case 2:  goto L60;
		    case 3:  goto L70;
		}
L50:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcx[i__ + j * 1800 - 
			1801] - espc_2.cen[i__ - 1]) * x_1.expn[i__ + j * 
			1800 - 1801];
		goto L80;
L60:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcy[i__ + j * 1800 - 
			1801] - espc_2.cen[i__ + 1799]) * x_1.expn[i__ + j * 
			1800 - 1801];
		goto L80;
L70:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcz[i__ + j * 1800 - 
			1801] - espc_2.cen[i__ + 3599]) * x_1.expn[i__ + j * 
			1800 - 1801];
L80:
		;
	    }
	}
    }

/*     CALCULATE (P||S) ESP INTEGRALS */

    if (espc_2.iam[ipr - 1] == 1 && *is != *ip) {
	np = *is + 1;
	i__1 = *npr;
	for (i__ = istart; i__ <= i__1; ++i__) {
	    i__2 = *icd;
	    for (j = 1; j <= i__2; ++j) {
		switch (espc_2.iam[ipr + j + 1798]) {
		    case 1:  goto L90;
		    case 2:  goto L100;
		    case 3:  goto L110;
		}
L90:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcx[i__ + j * 1800 - 
			1801] - espc_2.cen[ipr + j - 2]) * x_1.expn[i__ + j * 
			1800 - 1801];
		goto L120;
L100:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcy[i__ + j * 1800 - 
			1801] - espc_2.cen[ipr + j + 1798]) * x_1.expn[i__ + 
			j * 1800 - 1801];
		goto L120;
L110:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcz[i__ + j * 1800 - 
			1801] - espc_2.cen[ipr + j + 3598]) * x_1.expn[i__ + 
			j * 1800 - 1801];
L120:
		;
	    }
	}
    }

/*     CALCULATE (P||P) ESP INTEGRALS */

    if (espc_2.iam[ipr - 1] == 1 && *is != *ip) {
	i__2 = *npr;
	for (i__ = istart; i__ <= i__2; ++i__) {
	    i__1 = *icd;
	    for (j = 1; j <= i__1; ++j) {
		switch (espc_2.iam[i__ + 1799]) {
		    case 1:  goto L130;
		    case 2:  goto L140;
		    case 3:  goto L150;
		}
L130:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcx[i__ + j * 1800 - 
			1801] - espc_2.cen[i__ - 1]) * x_1.nai[i__ + j * 1800 
			- 1801];
		if (espc_2.iam[ipr + j + 1798] == espc_2.iam[i__ + 1799]) {
		    x_1.nai[i__ + j * 1800 - 1801] += x_1.exs[i__ + j * 1800 
			    - 1801] * .5 * x_1.expn[i__ + j * 1800 - 1801];
		}
		goto L160;
L140:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcy[i__ + j * 1800 - 
			1801] - espc_2.cen[i__ + 1799]) * x_1.nai[i__ + j * 
			1800 - 1801];
		if (espc_2.iam[ipr + j + 1798] == espc_2.iam[i__ + 1799]) {
		    x_1.nai[i__ + j * 1800 - 1801] += x_1.exs[i__ + j * 1800 
			    - 1801] * .5 * x_1.expn[i__ + j * 1800 - 1801];
		}
		goto L160;
L150:
		x_1.nai[i__ + j * 1800 - 1801] = (x_1.ewcz[i__ + j * 1800 - 
			1801] - espc_2.cen[i__ + 3599]) * x_1.nai[i__ + j * 
			1800 - 1801];
		if (espc_2.iam[ipr + j + 1798] == espc_2.iam[i__ + 1799]) {
		    x_1.nai[i__ + j * 1800 - 1801] += x_1.exs[i__ + j * 1800 
			    - 1801] * .5 * x_1.expn[i__ + j * 1800 - 1801];
		}
L160:
		;
	    }
	}
    }
    ips = *ic * *icd - *icd + 1;
    i__1 = *nc;
    for (i__ = *ic; i__ <= i__1; ++i__) {
	jps = i__ * *icd - *icd + 1;
	espc_2.ovl[*ic + i__ * 300 - 301] = 0.;
	i__2 = jps + *icd - 1;
	for (j = jps; j <= i__2; ++j) {
	    i__3 = ips + *icd - 1;
	    for (k = ips; k <= i__3; ++k) {
		espc_2.ovl[*ic + i__ * 300 - 301] += espc_2.cc[j - 1] * 
			espc_2.cc[k - 1] * x_1.nai[j + (k - ips + 1) * 1800 - 
			1801];
/* L170: */
	    }
	}
	espc_2.ovl[i__ + *ic * 300 - 301] = espc_2.ovl[*ic + i__ * 300 - 301];
/* L180: */
    }
    return 0;
} /* ovlp_ */

/* Subroutine */ int naicas_(integer *isc, integer *is, integer *ip, integer *
	npr, integer *nc, integer *ipe, integer *ipx, integer *icd)
{
    /* Initialized data */

    static doublereal bohr = .529167;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double atan(doublereal), exp(doublereal), sqrt(doublereal), d_nint(
	    doublereal *);

    /* Local variables */
    static doublereal f;
    static integer i__, j, k, ic;
    static doublereal fi, pi;
    static integer np;
    static doublereal ts, ts1, ref, res;
    static integer ipr, ips, jps, ipx2, iref, iesp;
    static doublereal term, term1, potp1, potp2, potp3;
    static integer istart, jstart;

/* *********************************************************************** */

/*     THIS SUBROUTINE EVALUATES (S|S) , (S|P) TYPE NUCLEAR ATTRACTION */
/*     INTEGRALS FOR A STO-NG BASIS SET */
/*     WRITTEN BY B.H. BESLER AT FORD SCIENTIFIC RESEARCH LABS IN */
/*     DECEMBER 1989. */

/*     ON INPUT:  IC = LOOP INDEX OF THE GAUSSIAN */
/*                IESP = LOOP INDEX OF THE ESP POINT */
/*                IPE = INDEX OF LAST Px PRIMITIVE */
/*                IPX = NUMBER OF Px PRIMITIVES */
/*                IS = NUMBER OS S ORBITALS */
/*                ISC = NUMBER OF CONTRACTED S ORBITALS */
/*                IP = NUMBER OF P ORBITALS */
/*                NPR = NUMBER OF PRIMITIVES */
/*                NC = NUMBER OF CONTRACTED FUNCTIONS */


/*     FOR MORE INFO SEE: OBARA&SAIKA J.CHEM.PHYS. 1986,84,3963. */
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

/*     CALCULATE DISTANCE ARRAYS */

/* *** it seems that this is not necessary... */
/*      WRITE(6,*) */
    pi = 4. * atan(1.);
    ipx2 = *ipx << 1;
/*     IF THIS IS A RESTART RUN, READ IN RESTART INFO */
/* *** skip all restart stuff, we don't need that... */
/*      IF(INDEX(KEYWRD,'ESPRST') .NE. 0) THEN */
/*         OPEN(UNIT=15,FILE='ESP.DUMP',STATUS='OLD',FORM='UNFORMATTED') */
/*         READ(15) JSTART,IESPS */
/*         IF(JSTART .EQ. ISC*2) THEN */
/*            CLOSE(15) */
/*            RETURN */
/*         ENDIF */
/*         DO 10 I=1,NESP */
/*            READ(15) ES(I) */
/*   10    CONTINUE */
/*         CLOSE(15) */
/* C */
/*         JSTART=JSTART+1 */
/*      ELSE */
    jstart = 1;
/*      ENDIF */
    np = *is + 1;
    i__1 = *isc;
    for (ic = jstart; ic <= i__1; ++ic) {
	ipr = ic * *icd - *icd + 1;
	istart = ipr;
	i__2 = *ipe;
	for (i__ = istart; i__ <= i__2; ++i__) {
	    x_1.dx[i__ - 1] = espc_3.cen[ipr - 1] - espc_3.cen[i__ - 1];
	    x_1.dy[i__ - 1] = espc_3.cen[ipr + 1799] - espc_3.cen[i__ + 1799];
	    x_1.dz[i__ - 1] = espc_3.cen[ipr + 3599] - espc_3.cen[i__ + 3599];
/* Computing 2nd power */
	    d__1 = x_1.dx[i__ - 1];
/* Computing 2nd power */
	    d__2 = x_1.dy[i__ - 1];
/* Computing 2nd power */
	    d__3 = x_1.dz[i__ - 1];
	    x_1.td[i__ - 1] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* L20: */
	}

/*     CALCULATE EXPONENT SUM */

	i__2 = *ipe;
	for (i__ = istart; i__ <= i__2; ++i__) {
	    i__3 = *icd;
	    for (j = 1; j <= i__3; ++j) {
		espc_3.exsr[i__ + j * 1800 - 1801] = espc_3.ex[ipr + j - 2] + 
			espc_3.ex[i__ - 1];
		x_1.exs[i__ + j * 1800 - 1801] = 1. / espc_3.exsr[i__ + j * 
			1800 - 1801];
		x_1.ce[i__ + j * 1800 - 1801] = espc_3.ex[ipr + j - 2] * 
			espc_3.ex[i__ - 1] * x_1.exs[i__ + j * 1800 - 1801];
		x_1.expn[i__ + j * 1800 - 1801] = exp(-x_1.ce[i__ + j * 1800 
			- 1801] * x_1.td[i__ - 1]);
/* L30: */
	    }
	}

/*     CALCULATE EXPONENT WEIGHTED CENTERS */

	i__3 = *ipe;
	for (i__ = istart; i__ <= i__3; ++i__) {
	    i__2 = *icd;
	    for (j = 1; j <= i__2; ++j) {
		x_1.ewcx[i__ + j * 1800 - 1801] = (espc_3.ex[i__ - 1] * 
			espc_3.cen[i__ - 1] + espc_3.ex[ipr + j - 2] * 
			espc_3.cen[ipr + j - 2]) * x_1.exs[i__ + j * 1800 - 
			1801];
		x_1.ewcy[i__ + j * 1800 - 1801] = (espc_3.ex[i__ - 1] * 
			espc_3.cen[i__ + 1799] + espc_3.ex[ipr + j - 2] * 
			espc_3.cen[ipr + j + 1798]) * x_1.exs[i__ + j * 1800 
			- 1801];
		x_1.ewcz[i__ + j * 1800 - 1801] = (espc_3.ex[i__ - 1] * 
			espc_3.cen[i__ + 3599] + espc_3.ex[ipr + j - 2] * 
			espc_3.cen[ipr + j + 3598]) * x_1.exs[i__ + j * 1800 
			- 1801];
/* L40: */
	    }
	}

/*     BEGIN LOOP OVER ESP POINTS */

	i__2 = potesp_1.nesp;
	for (iesp = 1; iesp <= i__2; ++iesp) {
	    potp1 = work1_3.potpt[iesp * 3 - 3] / bohr;
	    potp2 = work1_3.potpt[iesp * 3 - 2] / bohr;
	    potp3 = work1_3.potpt[iesp * 3 - 1] / bohr;

/*     BEGIN LOOP OVER COMPONENTS OF CONTRACTED FUNCTION IC */

	    i__3 = *icd;
	    for (j = 1; j <= i__3; ++j) {

/*     CALCULATE DISTANCE BETWEEN EXPONENT WEIGHTED AND PROBE POINT */

		i__4 = *ipe;
		for (i__ = istart; i__ <= i__4; ++i__) {
/* Computing 2nd power */
		    d__1 = x_1.ewcx[i__ + j * 1800 - 1801] - potp1;
/* Computing 2nd power */
		    d__2 = x_1.ewcy[i__ + j * 1800 - 1801] - potp2;
/* Computing 2nd power */
		    d__3 = x_1.ewcz[i__ + j * 1800 - 1801] - potp3;
		    x_1.u[i__ + j * 1800 - 1801] = (d__1 * d__1 + d__2 * d__2 
			    + d__3 * d__3) * espc_3.exsr[i__ + j * 1800 - 
			    1801];
		    x_1.nai[i__ + j * 1800 - 1801] = sqrt(pi / x_1.u[i__ + j *
			     1800 - 1801]);
/* L50: */
		}

/*     CALCULATE ESP INTEGRALS */

		i__4 = *ipe;
		for (i__ = istart; i__ <= i__4; ++i__) {
		    if (x_1.u[i__ + j * 1800 - 1801] <= espc_3.tf[0]) {
			d__1 = x_1.u[i__ + j * 1800 - 1801] * 20.;
			iref = (integer) d_nint(&d__1);
			ref = iref * .05;
			res = x_1.u[i__ + j * 1800 - 1801] - ref;
			term = 1.;
			x_1.f0[i__ + j * 1800 - 1801] = 0.;
			for (k = 0; k <= 6; ++k) {
			    f = espc_3.fv[k + (iref + 1) * 9 - 9];
			    ts = f * term * espc_3.fac[k];
			    term = -term * res;
			    x_1.f0[i__ + j * 1800 - 1801] += ts;
/* L60: */
			}
		    } else {
			x_1.f0[i__ + j * 1800 - 1801] = x_1.nai[i__ + j * 
				1800 - 1801] * .5;
		    }
/* L70: */
		}
		i__4 = *ipe;
		for (i__ = np; i__ <= i__4; ++i__) {
		    if (x_1.u[i__ + j * 1800 - 1801] <= espc_3.tf[1]) {
			d__1 = x_1.u[i__ + j * 1800 - 1801] * 20.;
			iref = (integer) d_nint(&d__1);
			ref = iref * .05;
			res = x_1.u[i__ + j * 1800 - 1801] - ref;
			term1 = 1.;
			x_1.f1[i__ + j * 1800 - 1801] = 0.;
			for (k = 0; k <= 6; ++k) {
			    fi = espc_3.fv[k + 1 + (iref + 1) * 9 - 9];
			    ts1 = fi * term1 * espc_3.fac[k];
			    term1 = -term1 * res;
			    x_1.f1[i__ + j * 1800 - 1801] += ts1;
/* L80: */
			}
		    } else {
			x_1.f1[i__ + j * 1800 - 1801] = x_1.nai[i__ + j * 
				1800 - 1801] * .25 / x_1.u[i__ + j * 1800 - 
				1801];
		    }
/* L90: */
		}
		i__4 = *is;
		for (i__ = istart; i__ <= i__4; ++i__) {
/* L100: */
		    x_1.u[i__ + j * 1800 - 1801] = pi * 2. * x_1.exs[i__ + j *
			     1800 - 1801] * x_1.expn[i__ + j * 1800 - 1801] * 
			    x_1.f0[i__ + j * 1800 - 1801];
		}
		np = *is + 1;
		i__4 = *ipe;
		for (i__ = np; i__ <= i__4; ++i__) {
		    x_1.nai[i__ + j * 1800 - 1801] = pi * 2. * x_1.exs[i__ + 
			    j * 1800 - 1801] * x_1.expn[i__ + j * 1800 - 1801]
			     * x_1.f0[i__ + j * 1800 - 1801];
		    x_1.nai1[i__ + j * 1800 - 1801] = pi * 2. * x_1.exs[i__ + 
			    j * 1800 - 1801] * x_1.expn[i__ + j * 1800 - 1801]
			     * x_1.f1[i__ + j * 1800 - 1801];
/* L110: */
		}

/*     CALCULATE (S||P) ESP INTEGRALS */

		if (espc_3.iam[ipr - 1] == 0 && *is != *ip) {
		    i__4 = *ipe;
		    for (i__ = np; i__ <= i__4; ++i__) {
/* L120: */
			x_1.u[i__ + j * 1800 - 1801] = (x_1.ewcx[i__ + j * 
				1800 - 1801] - espc_3.cen[i__ - 1]) * x_1.nai[
				i__ + j * 1800 - 1801] - (x_1.ewcx[i__ + j * 
				1800 - 1801] - potp1) * x_1.nai1[i__ + j * 
				1800 - 1801];
		    }
		    i__4 = *ipe + 1 + *ipx;
		    for (i__ = *ipe + 1; i__ <= i__4; ++i__) {
/* L130: */
			x_1.u[i__ + j * 1800 - 1801] = (x_1.ewcy[i__ - *ipx + 
				j * 1800 - 1801] - espc_3.cen[i__ - *ipx + 
				1799]) * x_1.nai[i__ - *ipx + j * 1800 - 1801]
				 - (x_1.ewcy[i__ - *ipx + j * 1800 - 1801] - 
				potp2) * x_1.nai1[i__ - *ipx + j * 1800 - 
				1801];
		    }
		    i__4 = *npr;
		    for (i__ = *ipe + 1 + *ipx; i__ <= i__4; ++i__) {
/* L140: */
			x_1.u[i__ + j * 1800 - 1801] = (x_1.ewcz[i__ - ipx2 + 
				j * 1800 - 1801] - espc_3.cen[i__ - ipx2 + 
				3599]) * x_1.nai[i__ - ipx2 + j * 1800 - 1801]
				 - (x_1.ewcz[i__ - ipx2 + j * 1800 - 1801] - 
				potp3) * x_1.nai1[i__ - ipx2 + j * 1800 - 
				1801];
		    }
		}
/* L150: */
	    }
	    ips = ic * *icd - *icd + 1;
	    i__3 = *nc;
	    for (i__ = ic; i__ <= i__3; ++i__) {
		jps = i__ * *icd - *icd + 1;
		espc_3.espi[i__ + ic * 300 - 301] = 0.;
		i__4 = jps + *icd - 1;
		for (j = jps; j <= i__4; ++j) {
		    i__5 = ips + *icd - 1;
		    for (k = ips; k <= i__5; ++k) {
			espc_3.espi[i__ + ic * 300 - 301] += espc_3.cc[j - 1] 
				* espc_3.cc[k - 1] * x_1.u[j + (k - ips + 1) *
				 1800 - 1801];
/* L160: */
		    }
		}
		work1_3.es[iesp - 1] += espf_2.cespm[indx_1.indc[i__ - 1] + 
			indx_1.indc[ic - 1] * 300 - 301] * 2. * espc_3.espi[
			i__ + ic * 300 - 301];
/* L170: */
	    }
	    work1_3.es[iesp - 1] -= espf_2.cespm[indx_1.indc[ic - 1] + 
		    indx_1.indc[ic - 1] * 300 - 301] * espc_3.espi[ic + ic * 
		    300 - 301];
/* L180: */
	}
/*     WRITE OUT RESTART INFORMATION */
/* *** no dumps please... */
/* *** no dumps please... */
/* *** no dumps please... */
/*         OPEN(UNIT=15,FILE='ESP.DUMP',STATUS='UNKNOWN',FORM='UNFORMATTED */
/*     1') */
/*         IESPS=0 */
/*         WRITE(15) IC,IESPS */
/*         DO 190 I=1,NESP */
/*            WRITE(15) ES(I) */
/*  190    CONTINUE */
/*         CLOSE(15) */

/*         WRITE(6,'(A,F6.2,A)') */
/*     1'NAICAS DUMPED: ',100.D0/ISC*IC,' PERCENT COMPLETE' */
/* L200: */
    }
    return 0;
} /* naicas_ */

/* Subroutine */ int naicap_(integer *isc, integer *is, integer *ip, integer *
	npr, integer *nc, integer *ipe, integer *ipx, integer *icd)
{
    /* Initialized data */

    static doublereal bohr = .529167;

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double atan(doublereal), exp(doublereal), sqrt(doublereal), d_nint(
	    doublereal *);

    /* Local variables */
    static doublereal f;
    static integer i__, j, k, l, ic;
    static doublereal fi;
    static integer il, in;
    static doublereal pi;
    static integer np;
    static doublereal ts;
    static integer ir, ir2;
    static doublereal ts1, ts2;
    static integer idc, idn;
    static doublereal ref, fii, res;
    static integer ipr, ips, jps, ipx2, iref, iesp;
    static doublereal term, term1, term2, potp1, potp2, potp3;
    static integer iesps, istart;

/* *********************************************************************** */
/*     THIS ROUTINE EVALUATES (P|P) NUCLEAR ATTRACTION INTEGRALS OVER */

/*     A STO-NG BASIS SET. */
/*     WRITTEN BY B.H. BESLER AT FORD SCIENTIFIC RESEARCH LABS IN */
/*     SEPT. 1989 */

/*     ON INPUT:  IC = LOOP INDEX OF THE GAUSSIAN */
/*                ICD = CONTRACTION DEPTH OF BASIS SET */
/*                IESP = LOOP INDEX OF THE ESP POINT */
/*                IS = NUMBER OS S PRIMITIVES */
/*                IPE = INDEX OF LAST PX PRIMITIVE */
/*                IPX = NUMBER OF PX PRIMITIVES */
/*                IS = NUMBER OS S PRIMITIVES */
/*                ISC = NUMBER OF CONTRACTED */
/*                NPR = NUMBER OF PRIMITIVES */
/*                NC = NUMBER OF CONTRACTED FUNCTIONS */


/*     FOR MORE INFO SEE: OBARA&SAIKA J.CHEM.PHYS. 1986,84,3963. */
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
/*     SET NUMBER OF EQUALLY SPACED DUMPS */
    idn = 10;

    idc = 0;
/* *** it seems that this is not necessary... */
/*      WRITE(6,*) */
    ipx2 = *ipx << 1;
    pi = atan(1.) * 4.;
    np = *is + 1;
/*     SETUP INDEX ARRAY */
    i__1 = *ipe;
    for (i__ = np; i__ <= i__1; ++i__) {
	fp_1.ird[i__ - 1] = i__ - *is;
	fp_1.ird[i__ + *ipx - 1] = i__ - *is;
	fp_1.ird[i__ + ipx2 - 1] = i__ - *is;
/* L10: */
    }

/*     CALCULATE QUANTITIES INVARIANT WITH ESP POINT FOR */
/*     (P|P) ESP INTEGRALS */

    il = l;
    l = 0;
    i__1 = *ipe;
    for (i__ = np; i__ <= i__1; ++i__) {
	i__2 = *ipe;
	for (j = i__; j <= i__2; ++j) {
	    ++l;
/* Computing 2nd power */
	    d__1 = espc_3.cen[i__ - 1] - espc_3.cen[j - 1];
/* Computing 2nd power */
	    d__2 = espc_3.cen[i__ + 1799] - espc_3.cen[j + 1799];
/* Computing 2nd power */
	    d__3 = espc_3.cen[i__ + 3599] - espc_3.cen[j + 3599];
	    fp_1.ptd[l - 1] = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	    fp_1.pexs[l - 1] = 1. / (espc_3.ex[i__ - 1] + espc_3.ex[j - 1]);
	    fp_1.pce[l - 1] = espc_3.ex[i__ - 1] * espc_3.ex[j - 1] * 
		    fp_1.pexs[l - 1];
	    fp_1.pexpn[l - 1] = exp(-fp_1.pce[l - 1] * fp_1.ptd[l - 1]);
	    fp_1.pewcx[l - 1] = (espc_3.ex[i__ - 1] * espc_3.cen[i__ - 1] + 
		    espc_3.ex[j - 1] * espc_3.cen[j - 1]) * fp_1.pexs[l - 1];
	    fp_1.pewcy[l - 1] = (espc_3.ex[i__ - 1] * espc_3.cen[i__ + 1799] 
		    + espc_3.ex[j - 1] * espc_3.cen[j + 1799]) * fp_1.pexs[l 
		    - 1];
	    fp_1.pewcz[l - 1] = (espc_3.ex[i__ - 1] * espc_3.cen[i__ + 3599] 
		    + espc_3.ex[j - 1] * espc_3.cen[j + 3599]) * fp_1.pexs[l 
		    - 1];
/* L20: */
	}

/*     SET UP OTHER INDEX ARRAY FOR PACKED SYMMETRIC ARRAY */
/*     STORAGE */

	fp_1.id[i__ - *is - 1] = l - *ipx;
/* L30: */
    }

/*     READ IN RESTART INFORMATION IF THIS IS A RESTART */

/* *** skip all restart stuff, we don't need that... */
/*      IF(INDEX(KEYWRD,'ESPRST') .NE. 0) THEN */
/*         OPEN(UNIT=15,FILE='ESP.DUMP',STATUS='UNKNOWN',FORM='UNFORMATTED */
/*     1') */
/*         READ(15) JSTART,IESPS */
/*         IF(JSTART .NE. ISC*2) THEN */
/*            IESPS=0 */
/*            CLOSE(15) */
/*            GOTO 50 */
/*         ENDIF */
/*         DO 40 I=1,NESP */
/*            READ(15) ES(I) */
/*   40    CONTINUE */
/*         CLOSE(15) */
/*         IDC=FLOAT(IESPS)/FLOAT(NESP)*10 */
/*      ELSE */
    iesps = 0;
/*      ENDIF */
/* L50: */

/*     LOOP OVER ESP PROBE POINTS */

    i__1 = potesp_1.nesp;
    for (iesp = iesps + 1; iesp <= i__1; ++iesp) {
	potp1 = work1_3.potpt[iesp * 3 - 3] / bohr;
	potp2 = work1_3.potpt[iesp * 3 - 2] / bohr;
	potp3 = work1_3.potpt[iesp * 3 - 1] / bohr;
/*     CALCULATE QUANTITY U */

	l = 0;
	i__2 = *ipe;
	for (i__ = np; i__ <= i__2; ++i__) {
	    i__3 = *ipe;
	    for (j = i__; j <= i__3; ++j) {
		++l;
/* Computing 2nd power */
		d__1 = fp_1.pewcx[l - 1] - potp1;
/* Computing 2nd power */
		d__2 = fp_1.pewcy[l - 1] - potp2;
/* Computing 2nd power */
		d__3 = fp_1.pewcz[l - 1] - potp3;
		fp_1.ptd[l - 1] = (d__1 * d__1 + d__2 * d__2 + d__3 * d__3) / 
			fp_1.pexs[l - 1];
		fp_1.pce[l - 1] = sqrt(pi / fp_1.ptd[l - 1]);
/* L60: */
	    }
	}

/*     CALCULATE F0, F1, AND F2(U) USING TAYLOR SERIES */
/*     OR ASYMPTOTIC EXPANSION */

	il = l;
	l = 0;
	i__3 = il;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    if (fp_1.ptd[i__ - 1] <= espc_3.tf[0]) {
		d__1 = fp_1.ptd[i__ - 1] * 20.;
		iref = (integer) d_nint(&d__1);
		ref = iref * .05;
		res = fp_1.ptd[i__ - 1] - ref;
		term = 1.;
		fp_1.pf0[i__ - 1] = 0.;
		for (k = 0; k <= 6; ++k) {
		    f = espc_3.fv[k + (iref + 1) * 9 - 9];
		    ts = f * term * espc_3.fac[k];
		    term = -term * res;
		    fp_1.pf0[i__ - 1] += ts;
/* L70: */
		}
	    } else {
		fp_1.pf0[i__ - 1] = fp_1.pce[i__ - 1] * .5;
	    }
	    if (fp_1.ptd[i__ - 1] <= espc_3.tf[1]) {
		d__1 = fp_1.ptd[i__ - 1] * 20.;
		iref = (integer) d_nint(&d__1);
		ref = iref * .05;
		res = fp_1.ptd[i__ - 1] - ref;
		term1 = 1.;
		fp_1.pf1[i__ - 1] = 0.;
		for (k = 0; k <= 6; ++k) {
		    fi = espc_3.fv[k + 1 + (iref + 1) * 9 - 9];
		    ts1 = fi * term1 * espc_3.fac[k];
		    term1 = -term1 * res;
		    fp_1.pf1[i__ - 1] += ts1;
/* L80: */
		}
	    } else {
		fp_1.pf1[i__ - 1] = fp_1.pce[i__ - 1] * .25 / fp_1.ptd[i__ - 
			1];
	    }
	    if (fp_1.ptd[i__ - 1] <= espc_3.tf[2]) {
		d__1 = fp_1.ptd[i__ - 1] * 20.;
		iref = (integer) d_nint(&d__1);
		ref = iref * .05;
		res = fp_1.ptd[i__ - 1] - ref;
		term2 = 1.;
		fp_1.pf2[i__ - 1] = 0.;
		for (k = 0; k <= 6; ++k) {
		    fii = espc_3.fv[k + 2 + (iref + 1) * 9 - 9];
		    ts2 = fii * term2 * espc_3.fac[k];
		    term2 = -term2 * res;
		    fp_1.pf2[i__ - 1] += ts2;
/* L90: */
		}
	    } else {
		fp_1.pf2[i__ - 1] = fp_1.pce[i__ - 1] * .375 / (fp_1.ptd[i__ 
			- 1] * fp_1.ptd[i__ - 1]);
	    }
/* L100: */
	}

/*     CALCULATE (S||S) TYPE INTEGRALS */

	i__3 = il;
	for (i__ = 1; i__ <= i__3; ++i__) {
	    fp_1.pf0[i__ - 1] = pi * 2. * fp_1.pexs[i__ - 1] * fp_1.pexpn[i__ 
		    - 1] * fp_1.pf0[i__ - 1];
	    fp_1.ptd[i__ - 1] = fp_1.pf0[i__ - 1];
	    fp_1.pf1[i__ - 1] = pi * 2. * fp_1.pexs[i__ - 1] * fp_1.pexpn[i__ 
		    - 1] * fp_1.pf1[i__ - 1];
	    fp_1.pf2[i__ - 1] = pi * 2. * fp_1.pexs[i__ - 1] * fp_1.pexpn[i__ 
		    - 1] * fp_1.pf2[i__ - 1];
/* L110: */
	}

	i__3 = *nc;
	for (ic = *isc + 1; ic <= i__3; ++ic) {
	    ipr = ic * *icd - *icd + 1;
	    istart = ipr;
	    i__2 = *icd;
	    for (j = 1; j <= i__2; ++j) {

/*     CALCULATE (P||S) ESP INTEGRALS */

		if (espc_3.iam[ipr - 1] == 1 && *is != *ip) {
		    i__4 = *npr;
		    for (i__ = istart; i__ <= i__4; ++i__) {
			in = ipr + j - 1;
			ir = fp_1.ird[i__ - 1] + fp_1.id[fp_1.ird[in - 1] - 1]
				;
			ir2 = fp_1.id[fp_1.ird[i__ - 1] - 1] + fp_1.ird[in - 
				1];
			if (ir2 <= ir) {
			    ir = ir2;
			}
			switch (espc_3.iam[in + 1799]) {
			    case 1:  goto L120;
			    case 2:  goto L130;
			    case 3:  goto L140;
			}
L120:
			x_1.nai2[i__ + j * 1800 - 1801] = (fp_1.pewcx[ir - 1] 
				- espc_3.cen[in - 1]) * fp_1.pf1[ir - 1] - 
				fp_1.pf2[ir - 1] * (fp_1.pewcx[ir - 1] - 
				potp1);
			x_1.nai[i__ + j * 1800 - 1801] = (fp_1.pewcx[ir - 1] 
				- espc_3.cen[in - 1]) * fp_1.pf0[ir - 1] - 
				fp_1.pf1[ir - 1] * (fp_1.pewcx[ir - 1] - 
				potp1);
			goto L150;
L130:
			x_1.nai2[i__ + j * 1800 - 1801] = (fp_1.pewcy[ir - 1] 
				- espc_3.cen[in + 1799]) * fp_1.pf1[ir - 1] - 
				fp_1.pf2[ir - 1] * (fp_1.pewcy[ir - 1] - 
				potp2);
			x_1.nai[i__ + j * 1800 - 1801] = (fp_1.pewcy[ir - 1] 
				- espc_3.cen[in + 1799]) * fp_1.pf0[ir - 1] - 
				fp_1.pf1[ir - 1] * (fp_1.pewcy[ir - 1] - 
				potp2);
			goto L150;
L140:
			x_1.nai2[i__ + j * 1800 - 1801] = (fp_1.pewcz[ir - 1] 
				- espc_3.cen[in + 3599]) * fp_1.pf1[ir - 1] - 
				fp_1.pf2[ir - 1] * (fp_1.pewcz[ir - 1] - 
				potp3);
			x_1.nai[i__ + j * 1800 - 1801] = (fp_1.pewcz[ir - 1] 
				- espc_3.cen[in + 3599]) * fp_1.pf0[ir - 1] - 
				fp_1.pf1[ir - 1] * (fp_1.pewcz[ir - 1] - 
				potp3);
L150:
			;
		    }
		}

/*     CALCULATE (P||P) ESP INTEGRALS */

		if (espc_3.iam[ipr - 1] == 1 && *is != *ip) {
		    i__4 = *npr;
		    for (i__ = istart; i__ <= i__4; ++i__) {
			in = ipr + j - 1;
			ir = fp_1.ird[i__ - 1] + fp_1.id[fp_1.ird[in - 1] - 1]
				;
			ir2 = fp_1.id[fp_1.ird[i__ - 1] - 1] + fp_1.ird[in - 
				1];
			if (ir2 <= ir) {
			    ir = ir2;
			}
			switch (espc_3.iam[i__ + 1799]) {
			    case 1:  goto L160;
			    case 2:  goto L170;
			    case 3:  goto L180;
			}
L160:
			x_1.nai[i__ + j * 1800 - 1801] = (fp_1.pewcx[ir - 1] 
				- espc_3.cen[i__ - 1]) * x_1.nai[i__ + j * 
				1800 - 1801] - (fp_1.pewcx[ir - 1] - potp1) * 
				x_1.nai2[i__ + j * 1800 - 1801];
			if (espc_3.iam[in + 1799] == espc_3.iam[i__ + 1799]) {
			    x_1.nai[i__ + j * 1800 - 1801] += fp_1.pexs[ir - 
				    1] * .5 * (fp_1.ptd[ir - 1] - fp_1.pf1[ir 
				    - 1]);
			}
			goto L190;
L170:
			x_1.nai[i__ + j * 1800 - 1801] = (fp_1.pewcy[ir - 1] 
				- espc_3.cen[i__ + 1799]) * x_1.nai[i__ + j * 
				1800 - 1801] - (fp_1.pewcy[ir - 1] - potp2) * 
				x_1.nai2[i__ + j * 1800 - 1801];
			if (espc_3.iam[in + 1799] == espc_3.iam[i__ + 1799]) {
			    x_1.nai[i__ + j * 1800 - 1801] += fp_1.pexs[ir - 
				    1] * .5 * (fp_1.ptd[ir - 1] - fp_1.pf1[ir 
				    - 1]);
			}
			goto L190;
L180:
			x_1.nai[i__ + j * 1800 - 1801] = (fp_1.pewcz[ir - 1] 
				- espc_3.cen[i__ + 3599]) * x_1.nai[i__ + j * 
				1800 - 1801] - (fp_1.pewcz[ir - 1] - potp3) * 
				x_1.nai2[i__ + j * 1800 - 1801];
			if (espc_3.iam[in + 1799] == espc_3.iam[i__ + 1799]) {
			    x_1.nai[i__ + j * 1800 - 1801] += fp_1.pexs[ir - 
				    1] * .5 * (fp_1.ptd[ir - 1] - fp_1.pf1[ir 
				    - 1]);
			}
L190:
			;
		    }
		}
/* L200: */
	    }

/*     FORM INTEGRALS OVER CONTRACTED FUNCTIONS */

	    ips = ic * *icd - *icd + 1;
	    i__2 = *nc;
	    for (i__ = ic; i__ <= i__2; ++i__) {
		jps = i__ * *icd - *icd + 1;
		espc_3.espi[i__ + ic * 300 - 301] = 0.;
		i__4 = jps + *icd - 1;
		for (j = jps; j <= i__4; ++j) {
		    i__5 = ips + *icd - 1;
		    for (k = ips; k <= i__5; ++k) {
			espc_3.espi[i__ + ic * 300 - 301] += espc_3.cc[j - 1] 
				* espc_3.cc[k - 1] * x_1.nai[j + (k - ips + 1)
				 * 1800 - 1801];
/* L210: */
		    }
		}
		work1_3.es[iesp - 1] += espf_2.cespm[indx_1.indc[i__ - 1] + 
			indx_1.indc[ic - 1] * 300 - 301] * 2. * espc_3.espi[
			i__ + ic * 300 - 301];
/* L220: */
	    }
	    work1_3.es[iesp - 1] -= espf_2.cespm[indx_1.indc[ic - 1] + 
		    indx_1.indc[ic - 1] * 300 - 301] * espc_3.espi[ic + ic * 
		    300 - 301];
/* L230: */
	}

/*     WRITE OUT RESTART INFORMATION EVERY NESP/10 POINTS */

/* *** no dumps please... */
/* *** no dumps please... */
/* *** no dumps please... */
/*         IF(MOD(IESP,NESP/IDN) .EQ. 0) THEN */
/*            OPEN(UNIT=15,FILE='ESP.DUMP',STATUS='UNKNOWN',FORM='UNFORMAT */
/*     1TED') */
/*            JSTART=ISC*2 */
/*            WRITE(15) JSTART,IESP */
/*            DO 240 I=1,NESP */
/*               WRITE(15) ES(I) */
/*  240       CONTINUE */
/*            CLOSE(15) */
/*            IDC=IDC+1 */
/*            WRITE(6,'(A,F6.2,A)') */
/*     1'NAICAP DUMPED: ',100.D0/IDN*IDC,' PERCENT COMPLETE' */
/*         ENDIF */
/* L250: */
    }
    return 0;
} /* naicap_ */

/* *** extensions for "miniMOPAC" plotting start here... */
/* *** extensions for "miniMOPAC" plotting start here... */
/* *** extensions for "miniMOPAC" plotting start here... */
/* Subroutine */ int getgeom_(void)
{
    /* Initialized data */

    static doublereal vderw[53] = { 0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,
	    0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0. };

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__, j;
    static doublereal grid, coord[360]	/* was [3][120] */, shell;
    static integer icntr;
    static doublereal closer;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);

/* *** this is a start of PDGRID subroutine with small modifications. */
/* *** this will just copy the geometry data for orginal ELESP. */

/*     ROUTINE TO CALCULATE WILLIAMS SURFACE */

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


    vderw[0] = 2.4;
    vderw[4] = 3.;
    vderw[5] = 2.9;
    vderw[6] = 2.7;
    vderw[7] = 2.6;
    vderw[8] = 2.55;
    vderw[14] = 3.1;
    vderw[15] = 3.05;
    vderw[16] = 3.;
    vderw[34] = 3.15;
    vderw[52] = 3.35;
    shell = 1.2;
/*     NESP=0 */
    grid = .8;
    closer = 0.;
/*     CHECK IF VDERW IS DEFINED FOR ALL ATOMS */

/*     CONVERT INTERNAL TO CARTESIAN COORDINATES */

    gmetry_(geom_1.geo, coord);

/*     STRIP COORDINATES AND ATOM LABEL FOR DUMMIES (I.E. 99) */

    icntr = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L10: */
	    abc_1.co[j + i__ * 3 - 4] = coord[j + i__ * 3 - 4];
	}
	if (geokst_1.labels[i__ - 1] == 99) {
	    goto L20;
	}
	++icntr;
	abc_1.ian[icntr - 1] = geokst_1.labels[i__ - 1];
L20:
	;
    }
    abc_1.natom = icntr;
    return 0;
} /* getgeom_ */

/* Subroutine */ int lm7iniplt_(void)
{
    /* Initialized data */

    static doublereal bohr = .529167;

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double atan(doublereal);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l, m;
    static doublereal t;
    static integer in;
    static doublereal pi;
    static integer ipr, nqn;
    extern /* Subroutine */ int rsp_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static doublereal sum;
    extern doublereal dex2_(integer *);
    static doublereal fval;
    extern /* Subroutine */ int fsub_(integer *, doublereal *, doublereal *);
    static doublereal norm;
    extern /* Subroutine */ int ovlp_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *), mult_(doublereal *, 
	    doublereal *, doublereal *, integer *);
    static logical sto3g;
    extern /* Subroutine */ int setup3_(void), densit_(doublereal *, integer *
	    , integer *, integer *, integer *, doublereal *, doublereal *, 
	    integer *), setupg_(void), getgeom_(void);

/* *** this is a modification to ELESP. it initializes the ELESP */
/* *** calculation and also stores some extra data for other plots. */
/* *********************************************************************** */
/*     ELESP LOADS THE STO-6G BASIS SET ONTO THE ATOMS, PERFOMS THE */
/*     DEORTHOGONALIZATION OF THE COEFFICIENTS AND EVALUATES THE */
/*     ELECTRONIC CONTRIBUTION TO THE ESP. IT WAS WRITTEN BY B.H.BESLER */
/*     AND K.M.MERZ IN FEB. 1989 AT UCSF. */

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

/*  END OF MINDO/3 COMMON BLOCKS */

/* *** an additional common block that carries variables for plotting routines. */
/* *** old arrays that are no longer needed are here, commented out. */
/*     DIMENSION CESPM2(MAXORB,MAXORB),SLA(10) */
/*     DIMENSION CESPML(MAXORB*MAXORB),CESP(MAXORB*MAXORB) */
/* *** now we call our GETGEOM subroutine here... */
    getgeom_();
    pi = atan(1.) * 4.;

/*     PUT STO-6G BASIS SET ON ATOM CENTERS */

    for (i__ = -1; i__ <= 10; ++i__) {
	espc_1.dex[i__ + 1] = dex2_(&i__);
/* L10: */
    }
    for (i__ = 0; i__ <= 7; ++i__) {
	espc_1.fac[i__] = 1. / espc_1.fac[i__];
/* L20: */
    }
    for (m = 0; m <= 8; ++m) {
	k = 1;
	espc_1.fv[m] = 1. / (m * 2. + 1.);
	for (t = .05; t <= 41.; t += .05) {
	    ++k;
	    fsub_(&m, &t, &fval);
	    espc_1.fv[m + k * 9 - 9] = fval;
/* L30: */
	}
    }

/*     LOAD BASIS FUNCTIONS INTO ARRAYS */

    sto3g = i_indx(keywrd_1.keywrd, "STO3G", (ftnlen)241, (ftnlen)5) != 0;
    if (sto3g) {
	plots_1.icd = 3;
	setup3_();
    } else {
	plots_1.icd = 6;
	setupg_();
    }
/* *** NC is number of contractions */
/* *** NPR is number of primitives */
    plots_1.nc = 0;
    plots_1.npr = 0;
/* *** the new array INC() will store the contraction indices... */
/* *** the new array INC() will store the contraction indices... */
/* *** the new array INC() will store the contraction indices... */
    i__1 = abc_1.natom;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (abc_1.ian[i__ - 1] <= 2) {
	    ++plots_1.nc;
	    i__2 = plots_1.icd;
	    for (j = 1; j <= i__2; ++j) {
		espc_1.cc[plots_1.npr + j - 1] = sto6g_1.allc[j - 1];
/* Computing 2nd power */
		d__1 = expont_1.zs[0];
		espc_1.ex[plots_1.npr + j - 1] = sto6g_1.allz[j - 1] * (d__1 *
			 d__1);
		espc_1.cen[plots_1.npr + j - 1] = abc_1.co[i__ * 3 - 3] / 
			bohr;
		espc_1.cen[plots_1.npr + j + 1799] = abc_1.co[i__ * 3 - 2] / 
			bohr;
		espc_1.cen[plots_1.npr + j + 3599] = abc_1.co[i__ * 3 - 1] / 
			bohr;
		espc_1.iam[plots_1.npr + j - 1] = 0;
		espc_1.iam[plots_1.npr + j + 1799] = 0;
		plots_1.inc[plots_1.npr + j - 1] = plots_1.nc;
		espc_1.fc[plots_1.npr + j - 1] = (doublereal) i__;
/* L40: */
	    }
	    plots_1.npr += plots_1.icd;
	} else {
/*        DETERMINE PRINCIPAL QUANTUM NUMBER(NQN) */
/*        OF ORBITALS TO BE USED */

	    nqn = 2;
	    if (abc_1.ian[i__ - 1] > 10 && abc_1.ian[i__ - 1] <= 18) {
		nqn = 3;
	    }
	    if (abc_1.ian[i__ - 1] > 18 && abc_1.ian[i__ - 1] <= 36) {
		nqn = 4;
	    }
	    if (abc_1.ian[i__ - 1] > 36 && abc_1.ian[i__ - 1] <= 54) {
		nqn = 5;
	    }

	    ++plots_1.nc;
	    i__2 = plots_1.icd;
	    for (j = 1; j <= i__2; ++j) {
		espc_1.cc[plots_1.npr + j - 1] = sto6g_1.allc[j + (nqn + 6) * 
			6 - 43];
/* Computing 2nd power */
		d__1 = expont_1.zs[abc_1.ian[i__ - 1] - 1];
		espc_1.ex[plots_1.npr + j - 1] = sto6g_1.allz[j + (nqn + 6) * 
			6 - 43] * (d__1 * d__1);
		espc_1.cen[plots_1.npr + j - 1] = abc_1.co[i__ * 3 - 3] / 
			bohr;
		espc_1.cen[plots_1.npr + j + 1799] = abc_1.co[i__ * 3 - 2] / 
			bohr;
		espc_1.cen[plots_1.npr + j + 3599] = abc_1.co[i__ * 3 - 1] / 
			bohr;
		espc_1.iam[plots_1.npr + j - 1] = 0;
		espc_1.iam[plots_1.npr + j + 1799] = 0;
		plots_1.inc[plots_1.npr + j - 1] = plots_1.nc;
/* L50: */
	    }
	    plots_1.npr += plots_1.icd;
	    for (k = 1; k <= 3; ++k) {
		++plots_1.nc;
		i__2 = plots_1.icd;
		for (j = 1; j <= i__2; ++j) {
		    espc_1.cc[plots_1.npr + j - 1] = sto6g_1.allc[j + (nqn + 
			    12) * 6 - 43];
/* Computing 2nd power */
		    d__1 = expont_1.zp[abc_1.ian[i__ - 1] - 1];
		    espc_1.ex[plots_1.npr + j - 1] = sto6g_1.allz[j + (nqn + 
			    12) * 6 - 43] * (d__1 * d__1);
		    espc_1.cen[plots_1.npr + j - 1] = abc_1.co[i__ * 3 - 3] / 
			    bohr;
		    espc_1.cen[plots_1.npr + j + 1799] = abc_1.co[i__ * 3 - 2]
			     / bohr;
		    espc_1.cen[plots_1.npr + j + 3599] = abc_1.co[i__ * 3 - 1]
			     / bohr;
		    espc_1.iam[plots_1.npr + j - 1] = 1;
		    espc_1.iam[plots_1.npr + j + 1799] = k;
		    plots_1.inc[plots_1.npr + j - 1] = plots_1.nc;
/* L60: */
		}
		plots_1.npr += plots_1.icd;
/* L70: */
	    }
	}
/* L80: */
    }

/*     CALCULATE NORMALIZATION CONSTANTS AND INCLUDE */
/*     THEM IN THE CONTRACTION COEFFICIENTS */

    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	d__1 = espc_1.ex[i__ - 1] * 2. / pi;
	d__2 = espc_1.ex[i__ - 1] * 4.;
	d__3 = espc_1.iam[i__ - 1] / 2.;
	norm = pow_dd(&d__1, &c_b182) * pow_dd(&d__2, &d__3) / sqrt(
		espc_1.dex[espc_1.iam[i__ - 1] * 2]);
	espc_1.cc[i__ - 1] *= norm;
/* L90: */
    }
    ipr = 0;

/*     PERFORM SORT OF PRIMITIVES BY ANGULAR MOMENTUM */

/* *** IS is count of S primitives??? */
/* *** IP is count of P primitives??? */
    plots_1.is = 0;
    plots_1.ip = 0;
    plots_1.ipc = 0;
    plots_1.isc = 0;
    j = 0;
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 0) {
	    ++plots_1.is;
	    espc_1.ind[plots_1.is - 1] = i__;
	}
/* L100: */
    }
    plots_1.ip = plots_1.is;
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 1 && espc_1.iam[i__ + 1799] == 1) {
	    ++plots_1.ip;
	    espc_1.ind[plots_1.ip - 1] = i__;
	}
/* L110: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 1 && espc_1.iam[i__ + 1799] == 2) {
	    ++plots_1.ip;
	    espc_1.ind[plots_1.ip - 1] = i__;
	}
/* L120: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (espc_1.iam[i__ - 1] == 1 && espc_1.iam[i__ + 1799] == 3) {
	    ++plots_1.ip;
	    espc_1.ind[plots_1.ip - 1] = i__;
	}
/* L130: */
    }
    i__1 = plots_1.nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * plots_1.icd - plots_1.icd + 1;
	if (espc_1.iam[in - 1] == 0) {
	    ++plots_1.isc;
	    indx_1.indc[plots_1.isc - 1] = i__;
	}
/* L140: */
    }
    plots_1.ipc = plots_1.isc;
    i__1 = plots_1.nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * plots_1.icd - plots_1.icd + 1;
	if (espc_1.iam[in - 1] == 1 && espc_1.iam[in + 1799] == 1) {
	    ++plots_1.ipc;
	    indx_1.indc[plots_1.ipc - 1] = i__;
	}
/* L150: */
    }
    i__1 = plots_1.nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * plots_1.icd - plots_1.icd + 1;
	if (espc_1.iam[in - 1] == 1 && espc_1.iam[in + 1799] == 2) {
	    ++plots_1.ipc;
	    indx_1.indc[plots_1.ipc - 1] = i__;
	}
/* L160: */
    }
    i__1 = plots_1.nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	in = i__ * plots_1.icd - plots_1.icd + 1;
	if (espc_1.iam[in - 1] == 1 && espc_1.iam[in + 1799] == 3) {
	    ++plots_1.ipc;
	    indx_1.indc[plots_1.ipc - 1] = i__;
	}
/* L170: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cc[espc_1.ind[i__ - 1] - 1];
/* L180: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cc[i__ - 1] = espc_1.temp[i__ - 1];
/* L190: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.ex[espc_1.ind[i__ - 1] - 1];
/* L200: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.ex[i__ - 1] = espc_1.temp[i__ - 1];
/* L210: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cen[espc_1.ind[i__ - 1] - 1];
/* L220: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cen[i__ - 1] = espc_1.temp[i__ - 1];
/* L230: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cen[espc_1.ind[i__ - 1] + 1799];
/* L240: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cen[i__ + 1799] = espc_1.temp[i__ - 1];
/* L250: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.temp[i__ - 1] = espc_1.cen[espc_1.ind[i__ - 1] + 3599];
/* L260: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.cen[i__ + 3599] = espc_1.temp[i__ - 1];
/* L270: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.itemp[i__ - 1] = espc_1.iam[espc_1.ind[i__ - 1] - 1];
/* L280: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.iam[i__ - 1] = espc_1.itemp[i__ - 1];
/* L290: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.itemp[i__ - 1] = espc_1.iam[espc_1.ind[i__ - 1] + 1799];
/* L300: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.iam[i__ + 1799] = espc_1.itemp[i__ - 1];
/* L310: */
    }
/* *** also arrange our new array INC() like the others... */
/* *** also arrange our new array INC() like the others... */
/* *** also arrange our new array INC() like the others... */
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	espc_1.itemp[i__ - 1] = plots_1.inc[espc_1.ind[i__ - 1] - 1];
/* L315: */
    }
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	plots_1.inc[i__ - 1] = espc_1.itemp[i__ - 1];
/* L316: */
    }
/*     CALCULATE OVERLAP MATRIX OF STO-6G FUNCTIONS */

    i__1 = plots_1.nc;
    for (j = 1; j <= i__1; ++j) {
	ovlp_(&j, &c__1, &plots_1.is, &plots_1.ip, &plots_1.npr, &plots_1.nc, 
		&plots_1.icd);
/* L320: */
    }

    i__1 = plots_1.nc;
    for (j = 1; j <= i__1; ++j) {
	i__2 = plots_1.nc;
	for (k = 1; k <= i__2; ++k) {
	    plots_1.cespm2[indx_1.indc[j - 1] + indx_1.indc[k - 1] * 300 - 
		    301] = espc_1.ovl[j + k * 300 - 301];
/* L330: */
	}
    }
    i__2 = plots_1.nc;
    for (j = 1; j <= i__2; ++j) {
	i__1 = plots_1.nc;
	for (k = 1; k <= i__1; ++k) {
	    espc_1.ovl[j + k * 300 - 301] = plots_1.cespm2[j + k * 300 - 301];
/* L340: */
	}
    }
    l = 0;
    i__1 = plots_1.nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
	    plots_1.cesp[l - 1] = espc_1.ovl[i__ + j * 300 - 301];
/* L350: */
	}
    }

/*     DEORTHOGONALIZE THE COEFFICIENTS AND REFORM THE DENSITY MATRIX */

    rsp_(plots_1.cesp, &plots_1.nc, &c__1, espc_1.temp, plots_1.cespml);
    i__2 = plots_1.nc;
    for (i__ = 1; i__ <= i__2; ++i__) {
	i__1 = i__;
	for (j = 1; j <= i__1; ++j) {
	    sum = 0.;
	    i__3 = plots_1.nc;
	    for (k = 1; k <= i__3; ++k) {
		sum += plots_1.cespml[i__ + (k - 1) * plots_1.nc - 1] / sqrt(
			espc_1.temp[k - 1]) * plots_1.cespml[j + (k - 1) * 
			plots_1.nc - 1];
		plots_1.cesp[i__ + (j - 1) * plots_1.nc - 1] = sum;
		plots_1.cesp[j + (i__ - 1) * plots_1.nc - 1] = sum;
/* L360: */
	    }
	}
    }
    mult_(vector_1.c__, plots_1.cesp, plots_1.cespml, &plots_1.nc);
    densit_(plots_1.cespml, &plots_1.nc, &plots_1.nc, &molkst_1.nclose, &
	    molkst_1.nopen, &molkst_1.fract, plots_1.cesp, &c__2);
/* *** does CESPML now contain the eigenvectors??? and TEMP the eigenvalues??? */
/* *** does CESPML now contain the eigenvectors??? and TEMP the eigenvalues??? */
/* *** does CESPML now contain the eigenvectors??? and TEMP the eigenvalues??? */
    return 0;
} /* lm7iniplt_ */

/* Subroutine */ int getesp_(void)
{
    /* Initialized data */

    static doublereal bohr = .529167;

    /* Format strings */
    static char fmt_420[] = "(1x,4e16.7)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    olist o__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer i_indx(char *, char *, ftnlen, ftnlen), f_open(olist *), s_wsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, l;
    static doublereal ra;
    static integer ipe;
    static doublereal rij;
    static integer ipx;
    extern /* Subroutine */ int naicap_(integer *, integer *, integer *, 
	    integer *, integer *, integer *, integer *, integer *), naicas_(
	    integer *, integer *, integer *, integer *, integer *, integer *, 
	    integer *, integer *);
    static logical potwrt;

    /* Fortran I/O blocks */
    static cilist io___298 = { 0, 21, 0, "(I5)", 0 };
    static cilist io___299 = { 0, 21, 0, fmt_420, 0 };


/* *** this is the end part of ELESP subroutine. */
/* *** this is the end part of ELESP subroutine. */
/* *** this is the end part of ELESP subroutine. */
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

/*  END OF MINDO/3 COMMON BLOCKS */

/* *** an additional common block that carries variables for plotting routines. */
/* *** old arrays that are no longer needed are here, commented out. */
/*     DIMENSION CESPM2(MAXORB,MAXORB),SLA(10) */
/*     DIMENSION CESPML(MAXORB*MAXORB),CESP(MAXORB*MAXORB) */
/* *** end of ELESP starts here... */

/*     NOW CALCULATE THE ELECTRONIC CONTRIBUTION TO THE ELECTROSTATIC POT */

    l = 0;
    i__1 = plots_1.nc;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
	    espf_2.cespm[i__ + j * 300 - 301] = plots_1.cesp[l - 1];
	    espf_2.cespm[j + i__ * 300 - 301] = plots_1.cesp[l - 1];
/* L370: */
	}
    }
    ipx = (plots_1.npr - plots_1.is) / 3;
    ipe = plots_1.is + ipx;
    i__2 = potesp_1.nesp;
    for (i__ = 1; i__ <= i__2; ++i__) {
	work1_3.es[i__ - 1] = 0.;
/* L380: */
    }
    naicas_(&plots_1.isc, &plots_1.is, &plots_1.ip, &plots_1.npr, &plots_1.nc,
	     &ipe, &ipx, &plots_1.icd);
    naicap_(&plots_1.isc, &plots_1.is, &plots_1.ip, &plots_1.npr, &plots_1.nc,
	     &ipe, &ipx, &plots_1.icd);
/*     CALCULATE TOTAL ESP AND FORM ARRAYS FOR ESPFIT */
    i__2 = potesp_1.nesp;
    for (i__ = 1; i__ <= i__2; ++i__) {
	work1_3.esp[i__ - 1] = 0.;
	i__1 = abc_1.natom;
	for (j = 1; j <= i__1; ++j) {
/* Computing 2nd power */
	    d__1 = abc_1.co[j * 3 - 3] - work1_3.potpt[i__ * 3 - 3];
/* Computing 2nd power */
	    d__2 = abc_1.co[j * 3 - 2] - work1_3.potpt[i__ * 3 - 2];
/* Computing 2nd power */
	    d__3 = abc_1.co[j * 3 - 1] - work1_3.potpt[i__ * 3 - 1];
	    ra = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    work1_3.esp[i__ - 1] += core_1.tore[abc_1.ian[j - 1] - 1] / (ra / 
		    bohr);
/* L390: */
	}
	work1_3.esp[i__ - 1] -= work1_3.es[i__ - 1];
	i__1 = abc_1.natom;
	for (j = 1; j <= i__1; ++j) {
/* Computing 2nd power */
	    d__1 = abc_1.co[j * 3 - 3] - work1_3.potpt[i__ * 3 - 3];
/* Computing 2nd power */
	    d__2 = abc_1.co[j * 3 - 2] - work1_3.potpt[i__ * 3 - 2];
/* Computing 2nd power */
	    d__3 = abc_1.co[j * 3 - 1] - work1_3.potpt[i__ * 3 - 1];
	    rij = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) / bohr;
	    espf_2.b[j - 1] += work1_3.esp[i__ - 1] * 1. / rij;
/* L400: */
	}
    }

/*     IF REQUESTED WRITE OUT ELECTRIC POTENTIAL DATA TO */
/*     UNIT 21 */

    potwrt = i_indx(keywrd_1.keywrd, "POTWRT", (ftnlen)241, (ftnlen)6) != 0;
    if (potwrt) {
	o__1.oerr = 0;
	o__1.ounit = 21;
	o__1.ofnm = 0;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
	s_wsfe(&io___298);
	do_fio(&c__1, (char *)&potesp_1.nesp, (ftnlen)sizeof(integer));
	e_wsfe();
	i__1 = potesp_1.nesp;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L410: */
	    s_wsfe(&io___299);
	    do_fio(&c__1, (char *)&work1_3.esp[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    d__1 = work1_3.potpt[i__ * 3 - 3] / bohr;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = work1_3.potpt[i__ * 3 - 2] / bohr;
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&work1_3.potpt[i__ * 3 - 1], (ftnlen)sizeof(
		    doublereal));
	    e_wsfe();
	}
    }
    return 0;
} /* getesp_ */

/* Subroutine */ int getorb_(void)
{

    /* System generated locals */
    integer i__1;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double exp(doublereal);

    /* Local variables */
    static integer i__;
    static doublereal dx, dy, dz, td, prim;

/* *** this will calculate values for orbital plots... */
/* *** this will calculate values for orbital plots... */
/* *** this will calculate values for orbital plots... */
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

/*  END OF MINDO/3 COMMON BLOCKS */

/* *** an additional common block that carries variables for plotting routines. */
/* *** old arrays that are no longer needed are here, commented out. */
/*     DIMENSION CESPM2(MAXORB,MAXORB),SLA(10) */
/*     DIMENSION CESPML(MAXORB*MAXORB),CESP(MAXORB*MAXORB) */
    work1_3.esp[0] = 0.;
/* *** variable I loops over all gaussian primitives. */
/* *** we calculate value of the primitive to PRIM and weight it according to the eigenvector. */
/* *** eigenvector contains weights for contracted functions; the array INC() contains contraction indices. */
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dx = work1_3.potpt[0] - espc_1.cen[i__ - 1];
	dy = work1_3.potpt[1] - espc_1.cen[i__ + 1799];
	dz = work1_3.potpt[2] - espc_1.cen[i__ + 3599];
/* Computing 2nd power */
	d__1 = dx;
/* Computing 2nd power */
	d__2 = dy;
/* Computing 2nd power */
	d__3 = dz;
	td = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	prim = espc_1.cc[i__ - 1] * exp(-espc_1.ex[i__ - 1] * td);
	if (espc_1.iam[i__ + 1799] == 1) {
	    prim *= dx;
	}
	if (espc_1.iam[i__ + 1799] == 2) {
	    prim *= dy;
	}
	if (espc_1.iam[i__ + 1799] == 3) {
	    prim *= dz;
	}
	work1_3.esp[0] += plots_1.cespml[plots_1.inc[i__ - 1] + (plots_1.iorb 
		- 1) * plots_1.nc - 1] * prim;
/* L500: */
    }
    return 0;
} /* getorb_ */

/* Subroutine */ int geteldens_(void)
{

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double exp(doublereal);

    /* Local variables */
    static integer i__, j;
    static doublereal dx, dy, dz, td, orb, prim;
    static integer iloop;

/* *** this will calculate values for the electron density plot... */
/* *** this will calculate values for the electron density plot... */
/* *** this will calculate values for the electron density plot... */
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

/*  END OF MINDO/3 COMMON BLOCKS */

/* *** an additional common block that carries variables for plotting routines. */
/* *** old arrays that are no longer needed are here, commented out. */
/*     DIMENSION CESPM2(MAXORB,MAXORB),SLA(10) */
/*     DIMENSION CESPML(MAXORB*MAXORB),CESP(MAXORB*MAXORB) */
    work1_3.esp[0] = 0.;
/* *** this is quite similar to GETORB, we just loop over all occupied orbitals here... */
/* *** here we assume that we have an open-shell RHF model... */
    iloop = molkst_1.nelecs / 2;
/* *** variable I loops over all gaussian primitives. */
/* *** we calculate value of the primitive to PRIM and weight it according to the eigenvector. */
/* *** eigenvector contains weights for contracted functions; the array INC() contains contraction indices. */
    i__1 = plots_1.npr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	dx = work1_3.potpt[0] - espc_1.cen[i__ - 1];
	dy = work1_3.potpt[1] - espc_1.cen[i__ + 1799];
	dz = work1_3.potpt[2] - espc_1.cen[i__ + 3599];
/* Computing 2nd power */
	d__1 = dx;
/* Computing 2nd power */
	d__2 = dy;
/* Computing 2nd power */
	d__3 = dz;
	td = d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
	i__2 = iloop;
	for (j = 1; j <= i__2; ++j) {
	    prim = espc_1.cc[i__ - 1] * exp(-espc_1.ex[i__ - 1] * td);
	    if (espc_1.iam[i__ + 1799] == 1) {
		prim *= dx;
	    }
	    if (espc_1.iam[i__ + 1799] == 2) {
		prim *= dy;
	    }
	    if (espc_1.iam[i__ + 1799] == 3) {
		prim *= dz;
	    }
	    orb = plots_1.cespml[plots_1.inc[i__ - 1] + (j - 1) * plots_1.nc 
		    - 1] * prim;
/* *** here we assume that we have an open-shell RHF model... */
	    work1_3.esp[0] += orb * orb * 2.;
/* L600: */
	}
/* L500: */
    }
    return 0;
} /* geteldens_ */

