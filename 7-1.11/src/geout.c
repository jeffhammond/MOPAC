/* geout.f -- translated by f2c (version 20020621).
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
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

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
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

struct {
    char ltxt[1], txtatm[960];
} atomtx_;

#define atomtx_1 atomtx_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

/* Table of constant values */

static doublereal c_b8 = 1.;
static integer c__1 = 1;
static doublereal c_b21 = .49999999899999997;
static integer c__3 = 3;

/* Subroutine */ int geout_(integer *mode1)
{
    /* Format strings */
    static char fmt_40[] = "(/4x,\002ATOM\002,3x,\002CHEMICAL\002,a,\002BOND"
	    " LENGTH\002,4x,\002BOND ANGLE\002,4x,\002 TWIST ANGLE\002,/3x"
	    ",\002NUMBER\002,2x,\002SYMBOL\002,a,\002(ANGSTROMS)\002,5x,\002("
	    "DEGREES)\002,5x,\002 (DEGREES)\002,/4x,\002(I)\002,a,\002NA:I"
	    "\002,10x,\002NB:NA:I\002,5x,\002 NC:NB:NA:I\002,5x,\002NA\002,3x,"
	    "\002NB\002,3x,\002NC\002,/)";

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2, i__3, i__4, i__5, i__6, i__7[3];
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    double d_int(doublereal *), d_sign(doublereal *, doublereal *);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsle(cilist *), e_wsle(void);

    /* Local variables */
    static integer i__, j, k, l, n;
    static char q[2*3];
    static doublereal w, x, q2[120];
    static integer ia, ii, mode;
    static logical cart;
    static integer iprt;
    static char flag0[2], flag1[2], flagn[2], blank[80];
    extern /* Subroutine */ int chrge_(doublereal *, doublereal *);
    static doublereal coord[360]	/* was [3][120] */, degree;
    static integer loctmp[720]	/* was [2][360] */, nvartm, maxtxt;
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *), wrttxt_(
	    integer *);

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___25 = { 0, 0, 0, "(1X,A,F11.7,1X,A2,F14.6,1X,A2,F14.6,"
	    "1X,  A2,3I5,A,F7.4)", 0 };
    static cilist io___26 = { 0, 0, 0, "(1X,A,F11.7,1X,A2,F14.6,1X,A2,F14.6,"
	    "1X,  A2,3I5)", 0 };
    static cilist io___27 = { 0, 6, 0, "(3X,I4 ,5X,A,F9.5,1X,A2,F14.5,1X,A2,"
	    "F11.5,1X,  A2,I4,2I5)", 0 };
    static cilist io___28 = { 0, 6, 0, "('      3',5X,A,F9.5,1X,A2,F14.5,1X,"
	    "A2,13X,  2I5)", 0 };
    static cilist io___29 = { 0, 6, 0, "('      2',5X,A,F9.5,1X,A2,30X,I5)", 
	    0 };
    static cilist io___30 = { 0, 6, 0, "('      1',5X,A)", 0 };
    static cilist io___31 = { 0, 0, 0, 0, 0 };
    static cilist io___32 = { 0, 0, 0, "(I4,I3,I5,15I4)", 0 };
    static cilist io___33 = { 0, 0, 0, "(I4,I3,I5,15I4)", 0 };


/* ********************************************************************* */

/*   GEOUT PRINTS THE CURRENT GEOMETRY.  IT CAN BE CALLED ANY TIME, */
/*         FROM ANY POINT IN THE PROGRAM AND DOES NOT AFFECT ANYTHING. */

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
    mode = *mode1;
    if (mode == 1) {
	s_copy(flag1, " *", (ftnlen)2, (ftnlen)2);
	s_copy(flag0, "  ", (ftnlen)2, (ftnlen)2);
	s_copy(flagn, " +", (ftnlen)2, (ftnlen)2);
	iprt = 6;
    } else {
	s_copy(flag1, " 1", (ftnlen)2, (ftnlen)2);
	s_copy(flag0, " 0", (ftnlen)2, (ftnlen)2);
	s_copy(flagn, "-1", (ftnlen)2, (ftnlen)2);
	iprt = abs(mode);
    }

/* *** OUTPUT THE PARAMETER DATA. */

    cart = FALSE_;
    if (geokst_1.na[0] != 0) {
	cart = TRUE_;
	xyzint_(geom_1.geo, &geokst_1.natoms, geokst_1.na, geokst_1.nb, 
		geokst_1.nc, &c_b8, coord);
	loctmp[0] = 2;
	loctmp[1] = 1;
	loctmp[2] = 3;
	loctmp[3] = 1;
	loctmp[4] = 3;
	loctmp[5] = 2;
	nvartm = 0;
	i__1 = geokst_1.natoms;
	for (i__ = 4; i__ <= i__1; ++i__) {
	    nvartm += 3;
	    for (j = 1; j <= 3; ++j) {
		loctmp[(nvartm + j << 1) - 2] = i__;
/* L10: */
		loctmp[(nvartm + j << 1) - 1] = j;
	    }
	}
	nvartm += 3;
    } else {
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    loctmp[(i__ << 1) - 2] = geovar_1.loc[(i__ << 1) - 2];
/* L20: */
	    loctmp[(i__ << 1) - 1] = geovar_1.loc[(i__ << 1) - 1];
	}
	nvartm = geovar_1.nvar;
	for (j = 1; j <= 3; ++j) {
/* $DOUT VBEST */
	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
		coord[j + i__ * 3 - 4] = geom_1.geo[j + i__ * 3 - 4];
	    }
	}
    }
    degree = 57.29577951;
    maxtxt = *(unsigned char *)atomtx_1.ltxt;
    s_copy(blank, " ", (ftnlen)80, (ftnlen)1);
    if (mode == 1) {
	s_wsfe(&io___15);
/* Computing MAX */
	i__1 = 2, i__2 = maxtxt - 4;
	do_fio(&c__1, blank, (max(i__1,i__2)));
/* Computing MAX */
	i__3 = 4, i__4 = maxtxt - 2;
	do_fio(&c__1, blank, (max(i__3,i__4)));
/* Computing MAX */
	i__5 = 18, i__6 = maxtxt + 12;
	do_fio(&c__1, blank, (max(i__5,i__6)));
	e_wsfe();
    } else {
	if (mode > 0) {
	    wrttxt_(&iprt);
	}
    }
    if (mode != 1) {
	chrge_(densty_1.p, q2);
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    l = molkst_1.nat[i__ - 1];
/* L50: */
	    q2[i__ - 1] = core_1.core[l - 1] - q2[i__ - 1];
	}
    }
    n = 1;
    ia = loctmp[0];
    ii = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    s_copy(q + (j - 1 << 1), flag0, (ftnlen)2, (ftnlen)2);
	    if (ia != i__) {
		goto L60;
	    }
	    if (j != loctmp[(n << 1) - 1] || n > nvartm) {
		goto L60;
	    }
	    s_copy(q + (j - 1 << 1), flag1, (ftnlen)2, (ftnlen)2);
	    ++n;
	    ia = loctmp[(n << 1) - 2];
L60:
	    ;
	}
	w = coord[i__ * 3 - 2] * degree;
	x = coord[i__ * 3 - 1] * degree;

/*  CONSTRAIN ANGLE TO DOMAIN 0 - 180 DEGREES */

	d__1 = w / 360.;
	w -= d_int(&d__1) * 360.;
	if (w < 0.) {
	    w += 360.;
	}
	if (w > 180.) {
	    x += 180.;
	    w = 360. - w;
	}

/*  CONSTRAIN DIHEDRAL TO DOMAIN -180 - 180 DEGREES */

	d__1 = x / 360. + d_sign(&c_b21, &x) - 1e-9;
	x -= d_int(&d__1) * 360.;
	if (path_1.latom != i__) {
	    goto L70;
	}
	j = path_1.lparam;
	s_copy(q + (j - 1 << 1), flagn, (ftnlen)2, (ftnlen)2);
L70:
/* Writing concatenation */
	i__7[0] = 2, a__1[0] = elemts_1.elemnt + (geokst_1.labels[i__ - 1] - 
		1 << 1);
	i__7[1] = 8, a__1[1] = atomtx_1.txtatm + (i__ - 1 << 3);
	i__7[2] = 2, a__1[2] = "  ";
	s_cat(blank, a__1, i__7, &c__3, (ftnlen)80);
	if (mode != 1) {
/* Computing MAX */
	    i__2 = 4, i__3 = maxtxt + 2;
	    j = max(i__2,i__3);
/* Computing MAX */
	    i__2 = 0, i__3 = 8 - j;
	    k = max(i__2,i__3);
	} else {
/* Computing MAX */
	    i__2 = 9, i__3 = maxtxt + 3;
	    j = max(i__2,i__3);
	}
	if (geokst_1.labels[i__ - 1] != 0) {
	    if (mode != 1) {
		if (geokst_1.labels[i__ - 1] != 99 && geokst_1.labels[i__ - 1]
			 != 107) {
		    ++ii;
		    io___25.ciunit = iprt;
		    s_wsfe(&io___25);
		    do_fio(&c__1, blank, j);
		    do_fio(&c__1, (char *)&coord[i__ * 3 - 3], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, q, (ftnlen)2);
		    do_fio(&c__1, (char *)&w, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, q + 2, (ftnlen)2);
		    do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, q + 4, (ftnlen)2);
		    do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, blank + 19, k + 1);
		    do_fio(&c__1, (char *)&q2[ii - 1], (ftnlen)sizeof(
			    doublereal));
		    e_wsfe();
		} else {
		    io___26.ciunit = iprt;
		    s_wsfe(&io___26);
		    do_fio(&c__1, blank, j);
		    do_fio(&c__1, (char *)&coord[i__ * 3 - 3], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, q, (ftnlen)2);
		    do_fio(&c__1, (char *)&w, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, q + 2, (ftnlen)2);
		    do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, q + 4, (ftnlen)2);
		    do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)
			    sizeof(integer));
		    do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)
			    sizeof(integer));
		    e_wsfe();
		}
	    } else if (i__ > 3) {
		s_wsfe(&io___27);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, blank, j);
		do_fio(&c__1, (char *)&coord[i__ * 3 - 3], (ftnlen)sizeof(
			doublereal));
		do_fio(&c__1, q, (ftnlen)2);
		do_fio(&c__1, (char *)&w, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, q + 2, (ftnlen)2);
		do_fio(&c__1, (char *)&x, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, q + 4, (ftnlen)2);
		do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)sizeof(
			integer));
		e_wsfe();
	    } else if (i__ == 3) {
		s_wsfe(&io___28);
		do_fio(&c__1, blank, j);
		do_fio(&c__1, (char *)&coord[6], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, q, (ftnlen)2);
		do_fio(&c__1, (char *)&w, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, q + 2, (ftnlen)2);
		do_fio(&c__1, (char *)&geokst_1.na[2], (ftnlen)sizeof(integer)
			);
		do_fio(&c__1, (char *)&geokst_1.nb[2], (ftnlen)sizeof(integer)
			);
		e_wsfe();
	    } else if (i__ == 2) {
		s_wsfe(&io___29);
		do_fio(&c__1, blank, j);
		do_fio(&c__1, (char *)&coord[3], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, q, (ftnlen)2);
		do_fio(&c__1, (char *)&geokst_1.na[1], (ftnlen)sizeof(integer)
			);
		e_wsfe();
	    } else {
		s_wsfe(&io___30);
		do_fio(&c__1, blank, j);
		e_wsfe();
	    }
	}
/* L80: */
    }
    if (cart) {
	geokst_1.na[0] = 99;
    }
    if (mode == 1) {
	return 0;
    }
    io___31.ciunit = iprt;
    s_wsle(&io___31);
    e_wsle();
    if (geosym_1.ndep == 0) {
	return 0;
    }

/*   OUTPUT SYMMETRY DATA. */

    i__ = 1;
L90:
    j = i__;
L100:
    if (j == geosym_1.ndep) {
	goto L110;
    }
    if (geosym_1.locpar[j - 1] == geosym_1.locpar[j] && geosym_1.idepfn[j - 1]
	     == geosym_1.idepfn[j] && j - i__ < 15) {
	++j;
	goto L100;
    } else {
	io___32.ciunit = iprt;
	s_wsfe(&io___32);
	do_fio(&c__1, (char *)&geosym_1.locpar[i__ - 1], (ftnlen)sizeof(
		integer));
	do_fio(&c__1, (char *)&geosym_1.idepfn[i__ - 1], (ftnlen)sizeof(
		integer));
	i__1 = j;
	for (k = i__; k <= i__1; ++k) {
	    do_fio(&c__1, (char *)&geosym_1.locdep[k - 1], (ftnlen)sizeof(
		    integer));
	}
	e_wsfe();
    }
    i__ = j + 1;
    goto L90;
L110:
    io___33.ciunit = iprt;
    s_wsfe(&io___33);
    do_fio(&c__1, (char *)&geosym_1.locpar[i__ - 1], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&geosym_1.idepfn[i__ - 1], (ftnlen)sizeof(integer));
    i__1 = j;
    for (k = i__; k <= i__1; ++k) {
	do_fio(&c__1, (char *)&geosym_1.locdep[k - 1], (ftnlen)sizeof(integer)
		);
    }
    e_wsfe();
    return 0;
} /* geout_ */

