/* gmetry.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    doublereal step, geoa[360]	/* was [3][120] */, geovec[360]	/* was [3][
	    120] */, colcst;
} reactn_;

#define reactn_1 reactn_

struct {
    integer igeook;
} geook_;

#define geook_1 geook_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int gmetry_(doublereal *geo, doublereal *coord)
{
    /* Initialized data */

    static integer icalcn = 0;
    static char ndimen[15*4] = " MOLECULE      " " POLYMER       " "LAYER ST"
	    "RUCTURE" " SOLID         ";

    /* Format strings */
    static char fmt_140[] = "(/10x,\002    THE SYSTEM IS A \002,a15,/)";
    static char fmt_150[] = "(/,\002                UNIT CELL TRANSLATION VE"
	    "CTORS\002,//,\002              X              Y              "
	    "Z\002)";
    static char fmt_160[] = "(\002    T\002,i1,\002 = \002,f11.7,\002    "
	    "\002,f11.7,\002    \002,f11.7)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal), sin(doublereal);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ma, mb, mc;
    static doublereal xa, xb, yb, zb, ya, za, xd, yd, zd, rbc, xpa, xpb, ypa, 
	    zqa, ypd, zpd, xpd, zqd, xqd, xyb, yza, sum, yqd, xrd, cosa, ccos,
	     cosd, sina, sind;
    static logical geook;
    static doublereal coskh, cosph, sinkh, costh, sinph;
    extern /* Subroutine */ int geout_(integer *);
    static doublereal sinth, error;

    /* Fortran I/O blocks */
    static cilist io___16 = { 0, 6, 0, "(A,I4,A,I4,A)", 0 };
    static cilist io___17 = { 0, 6, 0, "(A)", 0 };
    static cilist io___33 = { 0, 6, 0, "(//20X,' CALCULATION ABANDONED AT TH"
	    "IS POINT')", 0 };
    static cilist io___34 = { 0, 6, 0, "(//10X,' THREE ATOMS BEING USED TO D"
	    "EFINE THE',/ 10X,' COORDINATES OF A FOURTH ATOM, WHOSE BOND-ANGL"
	    "E IS')", 0 };
    static cilist io___35 = { 0, 6, 0, "(10X,' NOT ZERO OR 180 DEGREEES, ARE"
	    " ',          'IN AN ALMOST STRAIGHT')", 0 };
    static cilist io___36 = { 0, 6, 0, "(10X,' LINE.  THERE IS A HIGH PROBAB"
	    "ILITY THAT THE',/10X,' COORDINATES OF THE ATOM WILL BE INCORRECT"
	    ".')", 0 };
    static cilist io___37 = { 0, 6, 0, "(//20X,'THE FAULTY ATOM IS ATOM NUMB"
	    "ER',I4)", 0 };
    static cilist io___38 = { 0, 6, 0, "(//20X,'CARTESIAN COORDINATES UP TO "
	    "FAULTY ATOM')", 0 };
    static cilist io___39 = { 0, 6, 0, "(//5X,'I',12X,'X',12X,'Y',12X,'Z')", 
	    0 };
    static cilist io___40 = { 0, 6, 0, "(I6,F16.5,2F13.5)", 0 };
    static cilist io___41 = { 0, 6, 0, "(//6X,' ATOMS',I3,',',I3,', AND',I3,"
	    "         ' ARE WITHIN',F7.4,' ANGSTROMS OF A STRAIGHT LINE')", 0 }
	    ;
    static cilist io___58 = { 0, 6, 0, fmt_140, 0 };
    static cilist io___59 = { 0, 6, 0, fmt_150, 0 };
    static cilist io___60 = { 0, 6, 0, fmt_160, 0 };


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
    coord -= 4;
    geo -= 4;

    /* Function Body */
/* *********************************************************************** */

/*    GMETRY  COMPUTES COORDINATES FROM BOND-ANGLES AND LENGTHS. */
/* *** IT IS ADAPTED FROM THE PROGRAM WRITTEN BY M.J.S. DEWAR. */

/*     THREE SEPARATE OPTIONS EXIST WITHIN GMETRY. THESE ARE: */
/*    (A) IF NA(1) IS EQUAL TO 99 (IMPOSSIBLE UNDER NORMAL CIRCUMSTANCES) */
/*        THEN GEO IS ASSUMED TO BE IN CARTESIAN RATHER THAN INTERNAL */
/*        COORDINATES, AND COORD IS THEN SET EQUAL TO GEO. */
/*    (B) IF STEP IS NON-ZERO (THIS IS THE CASE WHEN "SADDLE" IS USED) */
/*        THEN GEO IS FIRST MODIFIED BY SHIFTING THE INTERNAL COORDINATES */
/*        ALONG A RADIUS FROM GEOA TO PLACE GEO AT ADISTANCESTEPFROMGEOA. */
/*    (C) NORMAL CONVERSION FROM INTERNAL TO CARTESIAN COORDINATESISDONE. */

/*  ON INPUT: */
/*         GEO    = ARRAY OF INTERNAL COORDINATES. */
/*         NATOMS = NUMBER OF ATOMS, INCLUDING DUMMIES. */
/*         NA     = ARRAY OF ATOM LABELS FOR BOND LENGTHS. */

/*  ON OUTPUT: */
/*         COORD  = ARRAY OF CARTESIAN COORDINATES */

/* *********************************************************************** */
/*                                     OPTION (B) */
    geook = geook_1.igeook == 99;
    if (abs(reactn_1.step) > 1e-4) {
	sum = 0.;
	for (j = 1; j <= 3; ++j) {
/* $DOIT VBEST */
	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		reactn_1.geovec[j + i__ * 3 - 4] = geo[j + i__ * 3] - 
			reactn_1.geoa[j + i__ * 3 - 4];
/* L10: */
/* Computing 2nd power */
		d__1 = reactn_1.geovec[j + i__ * 3 - 4];
		sum += d__1 * d__1;
	    }
	}
	sum = sqrt(sum);
	error = (sum - reactn_1.step) / sum;
    } else {
	error = 0.;
    }
    for (j = 1; j <= 3; ++j) {
/* $DOIT VBEST */
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	    geo[j + i__ * 3] -= error * reactn_1.geovec[j + i__ * 3 - 4];
	}
    }
/*                                     OPTION (A) */
    if (geokst_1.na[0] == 99) {
	for (i__ = 1; i__ <= 3; ++i__) {
/* $DOIT VBEST */
	    i__1 = geokst_1.natoms;
	    for (j = 1; j <= i__1; ++j) {
/* L30: */
		coord[i__ + j * 3] = geo[i__ + j * 3];
	    }
	}
	goto L100;
    }
/*                                     OPTION (C) */
    coord[4] = 0.;
    coord[5] = 0.;
    coord[6] = 0.;
    coord[7] = geo[7];
    coord[8] = 0.;
    coord[9] = 0.;
    if (geokst_1.natoms == 2) {
	goto L100;
    }
    ccos = cos(geo[11]);
    if (geokst_1.na[2] == 1) {
	coord[10] = coord[4] + geo[10] * ccos;
    } else {
	coord[10] = coord[7] - geo[10] * ccos;
    }
    coord[11] = geo[10] * sin(geo[11]);
    coord[12] = 0.;
    i__1 = geokst_1.natoms;
    for (i__ = 4; i__ <= i__1; ++i__) {
	cosa = cos(geo[i__ * 3 + 2]);
	mb = geokst_1.nb[i__ - 1];
	mc = geokst_1.na[i__ - 1];
	xb = coord[mb * 3 + 1] - coord[mc * 3 + 1];
	yb = coord[mb * 3 + 2] - coord[mc * 3 + 2];
	zb = coord[mb * 3 + 3] - coord[mc * 3 + 3];
	rbc = xb * xb + yb * yb + zb * zb;
	if (rbc < 1e-16) {

/*     TWO ATOMS ARE COINCIDENT.  A FATAL ERROR. */

	    s_wsfe(&io___16);
	    do_fio(&c__1, " ATOMS", (ftnlen)6);
	    do_fio(&c__1, (char *)&mb, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " AND", (ftnlen)4);
	    do_fio(&c__1, (char *)&mc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, " ARE COINCIDENT", (ftnlen)15);
	    e_wsfe();
	    s_wsfe(&io___17);
	    do_fio(&c__1, " THIS IS A FATAL ERROR, RUN STOPPED IN GMETRY", (
		    ftnlen)45);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	} else {
	    rbc = 1. / sqrt(rbc);
	}
	ma = geokst_1.nc[i__ - 1];
	xa = coord[ma * 3 + 1] - coord[mc * 3 + 1];
	ya = coord[ma * 3 + 2] - coord[mc * 3 + 2];
	za = coord[ma * 3 + 3] - coord[mc * 3 + 3];

/*     ROTATE ABOUT THE Z-AXIS TO MAKE YB=0, AND XB POSITIVE.  IF XYB IS */
/*     TOO SMALL, FIRST ROTATE THE Y-AXIS BY 90 DEGREES. */

	xyb = sqrt(xb * xb + yb * yb);
	k = -1;
	if (xyb > .1) {
	    goto L40;
	}
	xpa = za;
	za = -xa;
	xa = xpa;
	xpb = zb;
	zb = -xb;
	xb = xpb;
	xyb = sqrt(xb * xb + yb * yb);
	k = 1;

/*     ROTATE ABOUT THE Y-AXIS TO MAKE ZB VANISH */

L40:
	costh = xb / xyb;
	sinth = yb / xyb;
	xpa = xa * costh + ya * sinth;
	ypa = ya * costh - xa * sinth;
	sinph = zb * rbc;
	cosph = sqrt((d__1 = 1. - sinph * sinph, abs(d__1)));
	zqa = za * cosph - xpa * sinph;

/*     ROTATE ABOUT THE X-AXIS TO MAKE ZA=0, AND YA POSITIVE. */

/* Computing 2nd power */
	d__1 = ypa;
/* Computing 2nd power */
	d__2 = zqa;
	yza = sqrt(d__1 * d__1 + d__2 * d__2);
	if (yza < 1e-4) {
	    goto L60;
	}
	if (yza < .02 && ! geook) {
	    s_wsfe(&io___33);
	    e_wsfe();
	    s_wsfe(&io___34);
	    e_wsfe();
	    s_wsfe(&io___35);
	    e_wsfe();
	    s_wsfe(&io___36);
	    e_wsfe();
	    s_wsfe(&io___37);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    geout_(&c__1);
	    s_wsfe(&io___38);
	    e_wsfe();
	    s_wsfe(&io___39);
	    e_wsfe();
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
/* L50: */
		s_wsfe(&io___40);
		do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		for (k = 1; k <= 3; ++k) {
		    do_fio(&c__1, (char *)&coord[k + j * 3], (ftnlen)sizeof(
			    doublereal));
		}
		e_wsfe();
	    }
	    s_wsfe(&io___41);
	    do_fio(&c__1, (char *)&mc, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&mb, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&ma, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&yza, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	coskh = ypa / yza;
	sinkh = zqa / yza;
	goto L70;
L60:

/*   ANGLE TOO SMALL TO BE IMPORTANT */

	coskh = 1.;
	sinkh = 0.;
L70:

/*     COORDINATES :-   A=(???,YZA,0),   B=(RBC,0,0),  C=(0,0,0) */
/*     NONE ARE NEGATIVE. */
/*     THE COORDINATES OF I ARE EVALUATED IN THE NEW FRAME. */

	sina = sin(geo[i__ * 3 + 2]);
	sind = -sin(geo[i__ * 3 + 3]);
	cosd = cos(geo[i__ * 3 + 3]);
	xd = geo[i__ * 3 + 1] * cosa;
	yd = geo[i__ * 3 + 1] * sina * cosd;
	zd = geo[i__ * 3 + 1] * sina * sind;

/*     TRANSFORM THE COORDINATES BACK TO THE ORIGINAL SYSTEM. */

	ypd = yd * coskh - zd * sinkh;
	zpd = zd * coskh + yd * sinkh;
	xpd = xd * cosph - zpd * sinph;
	zqd = zpd * cosph + xd * sinph;
	xqd = xpd * costh - ypd * sinth;
	yqd = ypd * costh + xpd * sinth;
	if (k < 1) {
	    goto L80;
	}
	xrd = -zqd;
	zqd = xqd;
	xqd = xrd;
L80:
	coord[i__ * 3 + 1] = xqd + coord[mc * 3 + 1];
	coord[i__ * 3 + 2] = yqd + coord[mc * 3 + 2];
	coord[i__ * 3 + 3] = zqd + coord[mc * 3 + 3];
/* L90: */
    }

/* *** NOW REMOVE THE TRANSLATION VECTORS, IF ANY, FROM THE ARRAY COOR */

L100:
    k = geokst_1.natoms;
L110:
    if (geokst_1.labels[k - 1] != 107) {
	goto L120;
    }
    --k;
    goto L110;
L120:
    ++k;
    if (k > geokst_1.natoms) {
	goto L170;
    }

/*   SYSTEM IS A SOLID, OF DIMENSION NATOMS+1-K */

    l = 0;
    i__1 = geokst_1.natoms;
    for (i__ = k; i__ <= i__1; ++i__) {
	++l;
	mc = geokst_1.na[i__ - 1];
	euler_1.tvec[l * 3 - 3] = coord[i__ * 3 + 1] - coord[mc * 3 + 1];
	euler_1.tvec[l * 3 - 2] = coord[i__ * 3 + 2] - coord[mc * 3 + 2];
	euler_1.tvec[l * 3 - 1] = coord[i__ * 3 + 3] - coord[mc * 3 + 3];
/* L130: */
    }
    euler_1.id = l;
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	s_wsfe(&io___58);
	do_fio(&c__1, ndimen + euler_1.id * 15, (ftnlen)15);
	e_wsfe();
	if (euler_1.id == 0) {
	    goto L170;
	}
	s_wsfe(&io___59);
	e_wsfe();
	s_wsfe(&io___60);
	i__1 = euler_1.id;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&euler_1.tvec[j + i__ * 3 - 4], (ftnlen)
			sizeof(doublereal));
	    }
	}
	e_wsfe();
    }
L170:
    j = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] == 99 || geokst_1.labels[i__ - 1] == 107)
		 {
	    goto L190;
	}
	++j;
/* $DOIT ASIS */
	for (k = 1; k <= 3; ++k) {
/* L180: */
	    coord[k + j * 3] = coord[k + i__ * 3];
	}
L190:
	;
    }
    return 0;
} /* gmetry_ */

