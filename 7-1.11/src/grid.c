/* grid.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    doublereal cosine;
} gravec_;

#define gravec_1 gravec_

struct {
    integer latom1, lpara1, latom2, lpara2;
} mesh_;

#define mesh_1 mesh_

struct {
    doublereal currt1, currt2;
} gparam_;

#define gparam_1 gparam_

struct {
    integer ijlp, ilp, jlp, jlp1, ione;
} ijlp_;

#define ijlp_1 ijlp_

struct {
    doublereal surf[529];
} surf_;

#define surf_1 surf_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

/* Table of constant values */

static integer c__1 = 1;
static integer c__6 = 6;
static integer c__12 = 12;

/* Subroutine */ int grid_(void)
{
    /* Format strings */
    static char fmt_40[] = "(\002 ARCHIVE FILE FOR GRID CALCULATION\002/\002"
	    "GRID OF HEATS\002/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;
    char ch__1[80];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen), f_open(olist *), f_clos(
	    cllist *);

    /* Local variables */
    static integer i__, j, n;
    static doublereal c1, c2, gd[360];
    static integer ij;
    static doublereal cpu1, cpu2, cpu3, escf;
    static integer mdfp[20];
    static doublereal xdfp[20], umpx[23], umpy[23], umpz[529], step1, step2;
    static integer npts1, npts2;
    extern doublereal reada_(char *, integer *, ftnlen);
    extern /* Subroutine */ int flepo_(doublereal *, integer *, doublereal *);
    static integer iloop, jloop;
    extern /* Subroutine */ int geout_(integer *);
    static doublereal xlast[360];
    static integer jloop1;
    static doublereal start1, start2, degree;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    extern doublereal second_(void);
    static doublereal surfac[529]	/* was [23][23] */;
    extern /* Subroutine */ int dfpsav_(doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *)
	    ;
    static doublereal cputot;
    static logical restrt;
    extern /* Subroutine */ int wrttxt_(integer *);

    /* Fortran I/O blocks */
    static cilist io___25 = { 0, 6, 0, "(/'       FIRST VARIABLE   SECOND VA"
	    "RIABLE         FUNCTION')", 0 };
    static cilist io___26 = { 0, 6, 0, "(' :',F16.5,F16.5,F16.6)", 0 };
    static cilist io___27 = { 0, 6, 0, "(/10X,'HORIZONTAL: VARYING SECOND PA"
	    "RAMETER,',                   /10X,'VERTICAL:   VARYING FIRST PAR"
	    "AMETER')", 0 };
    static cilist io___28 = { 0, 6, 0, "(/10X,'WHOLE OF GRID, SUITABLE FOR P"
	    "LOTTING',//)", 0 };
    static cilist io___29 = { 0, 12, 0, fmt_40, 0 };
    static cilist io___30 = { 0, 12, 0, "(/' TOTAL CPU TIME IN FLEPO : ',F10"
	    ".3/)", 0 };
    static cilist io___37 = { 0, 6, 0, "(11F7.2)", 0 };
    static cilist io___38 = { 0, 12, 0, "(11F7.2)", 0 };
    static cilist io___39 = { 0, 6, 0, "(11F7.2)", 0 };
    static cilist io___40 = { 0, 12, 0, "(11F7.2)", 0 };
    static cilist io___41 = { 0, 6, 0, "(11F7.2)", 0 };
    static cilist io___42 = { 0, 12, 0, "(11F7.2)", 0 };
    static cilist io___43 = { 0, 6, 0, "(11F7.2)", 0 };
    static cilist io___44 = { 0, 12, 0, "(11F7.2)", 0 };
    static cilist io___45 = { 0, 20, 0, "(3(1X,F8.3))", 0 };


/* *********************************************************************** */

/*  GRID CALCULATES THE ENERGY-SURFACE RESULTING FROM VARIATION OF */
/*       TWO COORDINATES. THE STEP-SIZE IS STEP1 AND STEP2, AND A 11 */
/*       BY 11 GRID OF POINTS IS GENERATED */

/* 	This subroutine is extensively modified by Manyin Yi, Aug 1989. */

/* 	New features: */
/*      1. The input geometry definition should always be the upper-left */
/* 	   corner(smallest coordinates) instead of the middle point; */
/* 	2. The starting point for calculation can be one of the four */
/* 	   corners by setting "+/-" STEP1/2; */
/* 	3. The grid size(max 23*23) is controlled by POINT1/2, */
/* 	   if POINT1/2 is omitted, then a size of 11*11 is assumed; */
/* 	   kwd MAX sets the max size; */
/* 	4. The upper-left corner of the plotting grid always corresponds */
/* 	   to the smallest coordinates, the lower-right corner to the */
/* 	   largest, no matter where the calculation starts; */
/* 	5. Restartable. */
/*       6. Write out UNIMAP irregular data UMP.DAT */

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

    i__1 = i_indx(keywrd_1.keywrd, "STEP1", (ftnlen)241, (ftnlen)5) + 6;
    step1 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    i__1 = i_indx(keywrd_1.keywrd, "STEP2", (ftnlen)241, (ftnlen)5) + 6;
    step2 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    npts1 = 11;
    npts2 = 11;
    if (i_indx(keywrd_1.keywrd, " MAX", (ftnlen)241, (ftnlen)4) != 0) {
	npts1 = 23;
	npts2 = 23;
	goto L10;
    }
    if (i_indx(keywrd_1.keywrd, "POINT1", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "POINT1", (ftnlen)241, (ftnlen)6) + 7;
	npts1 = (d__1 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241), (integer)
		 abs(d__1));
    }
    if (i_indx(keywrd_1.keywrd, "POINT2", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "POINT2", (ftnlen)241, (ftnlen)6) + 7;
	npts2 = (d__1 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241), (integer)
		 abs(d__1));
    }
L10:
    restrt = i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) != 0;

/*  THE TOP-LEFT VALUE OF THE FIRST AND SECOND DIMENSIONS ARE */
/*      GEO(LPARA1,LATOM1) AND GEO(LPARA2,LATOM2) */

    umpy[0] = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4];
    umpx[0] = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4];
    degree = 57.29577951307855;
    if (mesh_1.lpara1 != 1) {
	step1 /= degree;
    }
    if (mesh_1.lpara2 != 1) {
	step2 /= degree;
    }

/*  NOW SET THE STARTING POINT TO THE DESIRED CORNER */

    if (step1 > 0.f && step2 > 0.f) {
	start1 = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4];
	start2 = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4];
    }
/* BOTTOM-LEFT */
    if (step1 < 0.f && step2 > 0.f) {
	start1 = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4] + (npts1 - 
		1) * abs(step1);
	start2 = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4];
    }
/* TOP-RIGHT */
    if (step1 > 0.f && step2 < 0.f) {
	start1 = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4];
	start2 = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4] + (d__1 = (
		npts2 - 1) * step2, abs(d__1));
    }
/* BOTTOM-RIGHT */
    if (step1 < 0.f && step2 < 0.f) {
	start1 = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4] + (d__1 = (
		npts1 - 1) * step1, abs(d__1));
	start2 = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4] + (d__1 = (
		npts2 - 1) * step2, abs(d__1));
    }

/*  NOW TO SWEEP THROUGH THE GRID OF POINTS LEFT TO RIGHT THEN RIGHT */
/*  TO LEFT OR VISA VERSA. THIS SHOULD AVOID THE GEOMETRY OR SCF GETTING */
/*  MESSED UP. */

    if (mesh_1.lpara1 != 1) {
	c1 = degree;
    } else {
	c1 = 1.;
    }
    if (mesh_1.lpara2 != 1) {
	c2 = degree;
    } else {
	c2 = 1.;
    }
/*   THESE PARAMETERS NEED TO BE DUMPED IN '.RES' */
    gparam_1.currt1 = start1;
    gparam_1.currt2 = start2;
    ijlp_1.ione = -1;
    cputot = 0.;
    ijlp_1.ijlp = 0;
    ijlp_1.ilp = 1;
    ijlp_1.jlp = 1;
    ijlp_1.jlp1 = 1;
    surf_1.surf[0] = 0.;

    if (restrt) {
	mdfp[8] = 0;
	dfpsav_(&cputot, geovar_1.xparam, gd, xlast, &escf, mdfp, xdfp);
    }

    geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4] = gparam_1.currt1;
    geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4] = gparam_1.currt2;
    i__1 = npts1;
    for (iloop = ijlp_1.ilp; iloop <= i__1; ++iloop) {
	ijlp_1.ione = -ijlp_1.ione;
	i__2 = npts2;
	for (jloop = ijlp_1.jlp; jloop <= i__2; ++jloop) {
	    jloop1 = 0;
	    if (ijlp_1.ione < 0) {
		jloop1 = npts2 + 1;
	    }
	    if (restrt) {
		jloop1 = ijlp_1.jlp1;
		ijlp_1.ione = -ijlp_1.ione;
		restrt = FALSE_;
	    } else {
		jloop1 += ijlp_1.ione;
		ijlp_1.jlp1 = jloop1;
	    }
	    cpu1 = second_();
	    gparam_1.currt1 = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 
		    4];
	    gparam_1.currt2 = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 
		    4];
	    flepo_(geovar_1.xparam, &geovar_1.nvar, &escf);
	    cpu2 = second_();
	    cpu3 = cpu2 - cpu1;
	    cputot += cpu3;
	    ++ijlp_1.jlp;
	    ++ijlp_1.ijlp;
	    surf_1.surf[ijlp_1.ijlp - 1] = escf;
	    s_wsfe(&io___25);
	    e_wsfe();
	    s_wsfe(&io___26);
	    d__1 = geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4] * c1;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    d__2 = geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4] * c2;
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    geout_(&c__6);
	    geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4] += step2 * 
		    ijlp_1.ione;
/* L20: */
	}
	geom_1.geo[mesh_1.lpara1 + mesh_1.latom1 * 3 - 4] += step1;
	geom_1.geo[mesh_1.lpara2 + mesh_1.latom2 * 3 - 4] -= step2 * 
		ijlp_1.ione;
	++ijlp_1.ilp;
	ijlp_1.jlp = 1;
/* L30: */
    }
    s_wsfe(&io___27);
    e_wsfe();
    s_wsfe(&io___28);
    e_wsfe();

/*  ARCHIVE */
    o__1.oerr = 0;
    o__1.ounit = 12;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR012", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    o__1.oerr = 1;
    o__1.ounit = 20;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR020", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "NEW";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    i__1 = f_open(&o__1);
    if (i__1 != 0) {
	goto L31;
    }
    goto L32;
L31:
    o__1.oerr = 0;
    o__1.ounit = 20;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR020", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "OLD";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
L32:
    s_wsfe(&io___29);
    e_wsfe();
    wrttxt_(&c__12);
    s_wsfe(&io___30);
    do_fio(&c__1, (char *)&cputot, (ftnlen)sizeof(doublereal));
    e_wsfe();

/*  WRITE OUT THE GRIDS */
    ijlp_1.ione = 1;
    iloop = 1;
    jloop1 = 1;
    i__1 = npts1 * npts2;
    for (ij = 1; ij <= i__1; ++ij) {
	surfac[jloop1 + iloop * 23 - 24] = surf_1.surf[ij - 1];
	n = ij - ij / npts2 * npts2;
	if (n == 0) {
	    ++iloop;
	    jloop1 += ijlp_1.ione;
	    ijlp_1.ione = -ijlp_1.ione;
	}
	jloop1 += ijlp_1.ione;
/* L50: */
    }

    i__1 = npts1;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L60: */
	umpy[i__ - 1] = umpy[0] + (i__ - 1) * abs(step1);
    }
    i__1 = npts2;
    for (i__ = 2; i__ <= i__1; ++i__) {
/* L70: */
	umpx[i__ - 1] = umpx[0] + (i__ - 1) * abs(step2);
    }
    n = 0;
    if (step1 > 0.f && step2 > 0.f) {
	i__1 = npts1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = npts2;
	    for (j = 1; j <= i__2; ++j) {
		++n;
/* L80: */
		umpz[n - 1] = surfac[j + i__ * 23 - 24];
	    }
	    s_wsfe(&io___37);
	    i__2 = npts2;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
/* L90: */
	    s_wsfe(&io___38);
	    i__2 = npts2;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    if (step1 < 0.f && step2 > 0.f) {
	for (i__ = npts1; i__ >= 1; --i__) {
	    i__2 = npts2;
	    for (j = 1; j <= i__2; ++j) {
		++n;
/* L100: */
		umpz[n - 1] = surfac[j + i__ * 23 - 24];
	    }
	    s_wsfe(&io___39);
	    i__2 = npts2;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
/* L110: */
	    s_wsfe(&io___40);
	    i__2 = npts2;
	    for (j = 1; j <= i__2; ++j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    if (step1 > 0.f && step2 < 0.f) {
	i__2 = npts1;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    for (j = npts2; j >= 1; --j) {
		++n;
/* L120: */
		umpz[n - 1] = surfac[j + i__ * 23 - 24];
	    }
	    s_wsfe(&io___41);
	    for (j = npts2; j >= 1; --j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
/* L130: */
	    s_wsfe(&io___42);
	    for (j = npts2; j >= 1; --j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    if (step1 < 0.f && step2 < 0.f) {
	for (i__ = npts1; i__ >= 1; --i__) {
	    for (j = npts2; j >= 1; --j) {
		++n;
/* L140: */
		umpz[n - 1] = surfac[j + i__ * 23 - 24];
	    }
	    s_wsfe(&io___43);
	    for (j = npts2; j >= 1; --j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
/* L150: */
	    s_wsfe(&io___44);
	    for (j = npts2; j >= 1; --j) {
		do_fio(&c__1, (char *)&surfac[j + i__ * 23 - 24], (ftnlen)
			sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    i__2 = npts1 - 1;
    for (i__ = 0; i__ <= i__2; ++i__) {
	i__1 = npts2;
	for (j = 1; j <= i__1; ++j) {
	    n = i__ * npts2 + j;
/* L160: */
	    s_wsfe(&io___45);
	    do_fio(&c__1, (char *)&umpx[j - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&umpy[i__], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&umpz[n - 1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
    }
    cl__1.cerr = 0;
    cl__1.cunit = 20;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return 0;
} /* grid_ */

