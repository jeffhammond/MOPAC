/* hcore.f -- translated by f2c (version 20020621).
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
    doublereal uspd[300], dumy[300];
} molorb_;

#define molorb_1 molorb_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    doublereal efield[3];
} field_;

#define field_1 field_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    logical iseps, useps, upda;
} iseps_;

#define iseps_1 iseps_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int hcore_(doublereal *coord, doublereal *h__, doublereal *w,
	 doublereal *wj, doublereal *wk, doublereal *enuclr)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* Format strings */
    static char fmt_120[] = "(10f8.4)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, i1, i2, j1, j2, ia, ib, ic;
    static doublereal di[81]	/* was [9][9] */;
    static integer ja, jb, jc, ii, jj, ni, nj, kr;
    static doublereal xf, yf, zf, e1b[10], e2a[10];
    static integer im1, io1, jo1;
    static doublereal wjd[100], wkd[100];
    static integer kro;
    static doublereal half;
    static integer ione;
    static doublereal fnuc, enuc;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical debug, fldon, first;
    extern /* Subroutine */ int h1elec_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *), addhcr_(doublereal *), addnuc_(
	    doublereal *);
    static doublereal fldcon, hterme, cutoff;
    extern /* Subroutine */ int rotate_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, integer *, doublereal *, doublereal *,
	     doublereal *, doublereal *), vecprt_(doublereal *, integer *);
    static char tmpkey[241];
    extern /* Subroutine */ int solrot_(integer *, integer *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *, doublereal *,
	     doublereal *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 6, 0, "(/10X,'THE ELECTRIC FIELD IS',3F10.5)"
	    , 0 };
    static cilist io___12 = { 0, 6, 0, "(10X,'IN 8*A.U. (8*27.21/0.529 VOLTS"
	    "/ANGSTROM)',/)", 0 };
    static cilist io___44 = { 0, 6, 0, "(//10X,'ONE-ELECTRON MATRIX FROM HCO"
	    "RE')", 0 };
    static cilist io___45 = { 0, 6, 0, "(//10X,'TWO-ELECTRON MATRIX IN HCORE"
	    "'/)", 0 };
    static cilist io___46 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___47 = { 0, 6, 0, "(//10X,'TWO-ELECTRON J MATRIX IN HCO"
	    "RE'/)", 0 };
    static cilist io___48 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___49 = { 0, 6, 0, "(//10X,'TWO-ELECTRON K MATRIX IN HCO"
	    "RE'/)", 0 };
    static cilist io___50 = { 0, 6, 0, fmt_120, 0 };


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
/* COSMO change */
/* end of COSMO change */
/* *********************************************************************** */

/*   HCORE GENERATES THE ONE-ELECTRON MATRIX AND TWO ELECTRON INTEGRALS */
/*         FOR A GIVEN MOLECULE WHOSE GEOMETRY IS DEFINED IN CARTESIAN */
/*         COORDINATES. */

/*  ON INPUT  COORD   = COORDINATES OF THE MOLECULE. */

/*  ON OUTPUT  H      = ONE-ELECTRON MATRIX. */
/*             W      = TWO-ELECTRON INTEGRALS. */
/*             ENUCLR = NUCLEAR ENERGY */
/* *********************************************************************** */
    /* Parameter adjustments */
    --wk;
    --wj;
    --w;
    --h__;
    coord -= 4;

    /* Function Body */
    first = icalcn != numcal_1.numcal;
    icalcn = numcal_1.numcal;
    if (first) {
	ione = 1;
	cutoff = 1e10;
	if (euler_1.id != 0) {
	    cutoff = 60.;
	}
	if (euler_1.id != 0) {
	    ione = 0;
	}
	debug = i_indx(keywrd_1.keywrd, "HCORE", (ftnlen)241, (ftnlen)5) != 0;
/* ****************************************************************** */
	xf = 0.;
	yf = 0.;
	zf = 0.;
	s_copy(tmpkey, keywrd_1.keywrd, (ftnlen)241, (ftnlen)241);
	i__ = i_indx(tmpkey, " FIELD(", (ftnlen)241, (ftnlen)7);
	if (i__ == 0) {
	    goto L6;
	}

/*   ERASE ALL TEXT FROM TMPKEY EXCEPT FIELD DATA */

	s_copy(tmpkey, " ", i__, (ftnlen)1);
	i__1 = i_indx(tmpkey, ")", (ftnlen)241, (ftnlen)1) - 1;
	s_copy(tmpkey + i__1, " ", 241 - i__1, (ftnlen)1);

/*   READ IN THE EFFECTIVE FIELD IN X,Y,Z COORDINATES */

	xf = reada_(tmpkey, &i__, (ftnlen)241);
	i__ = i_indx(tmpkey, ",", (ftnlen)241, (ftnlen)1);
	if (i__ == 0) {
	    goto L5;
	}
	*(unsigned char *)&tmpkey[i__ - 1] = ' ';
	yf = reada_(tmpkey, &i__, (ftnlen)241);
	i__ = i_indx(tmpkey, ",", (ftnlen)241, (ftnlen)1);
	if (i__ == 0) {
	    goto L5;
	}
	*(unsigned char *)&tmpkey[i__ - 1] = ' ';
	zf = reada_(tmpkey, &i__, (ftnlen)241);
L5:
	s_wsfe(&io___11);
	do_fio(&c__1, (char *)&xf, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&yf, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&zf, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___12);
	e_wsfe();
L6:
	field_1.efield[0] = xf;
	field_1.efield[1] = yf;
	field_1.efield[2] = zf;
/* ********************************************************************** */
    }
    fldon = FALSE_;
    if (field_1.efield[0] != 0. || field_1.efield[1] != 0. || field_1.efield[
	    2] != 0.) {
	fldcon = 51.4257;
	fldon = TRUE_;
    }
    i__1 = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	h__[i__] = 0.;
    }
    *enuclr = 0.;
    kr = 1;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ia = molkst_1.nfirst[i__ - 1];
	ib = molkst_1.nlast[i__ - 1];
	ic = molkst_1.nmidle[i__ - 1];
	ni = molkst_1.nat[i__ - 1];

/* FIRST WE FILL THE DIAGONALS, AND OFF-DIAGONALS ON THE SAME ATOM */

	i__2 = ib;
	for (i1 = ia; i1 <= i__2; ++i1) {
	    i2 = i1 * (i1 - 1) / 2 + ia - 1;
	    i__3 = i1;
	    for (j1 = ia; j1 <= i__3; ++j1) {
		++i2;
		h__[i2] = 0.;
		if (fldon) {
		    io1 = i1 - ia;
		    jo1 = j1 - ia;
		    if (jo1 == 0 && io1 == 1) {
			hterme = multip_1.dd[ni - 1] * -.529177 * 
				field_1.efield[0] * fldcon;
			h__[i2] = hterme;
		    }
		    if (jo1 == 0 && io1 == 2) {
			hterme = multip_1.dd[ni - 1] * -.529177 * 
				field_1.efield[1] * fldcon;
			h__[i2] = hterme;
		    }
		    if (jo1 == 0 && io1 == 3) {
			hterme = multip_1.dd[ni - 1] * -.529177 * 
				field_1.efield[2] * fldcon;
			h__[i2] = hterme;
		    }
		}
/* L20: */
	    }
	    h__[i2] = molorb_1.uspd[i1 - 1];
	    if (fldon) {
		fnuc = -(field_1.efield[0] * coord[i__ * 3 + 1] + 
			field_1.efield[1] * coord[i__ * 3 + 2] + 
			field_1.efield[2] * coord[i__ * 3 + 3]) * fldcon;
		h__[i2] += fnuc;
	    }
/* L30: */
	}

/*   FILL THE ATOM-OTHER ATOM ONE-ELECTRON MATRIX<PSI(LAMBDA)|PSI(SIGMA)> */

	im1 = i__ - ione;
	i__2 = im1;
	for (j = 1; j <= i__2; ++j) {
	    half = 1.;
	    if (i__ == j) {
		half = .5;
	    }
	    ja = molkst_1.nfirst[j - 1];
	    jb = molkst_1.nlast[j - 1];
	    jc = molkst_1.nmidle[j - 1];
	    nj = molkst_1.nat[j - 1];
	    h1elec_(&ni, &nj, &coord[i__ * 3 + 1], &coord[j * 3 + 1], di);
	    i2 = 0;
	    i__3 = ib;
	    for (i1 = ia; i1 <= i__3; ++i1) {
		ii = i1 * (i1 - 1) / 2 + ja - 1;
		++i2;
		j2 = 0;
		jj = min(i1,jb);
		i__4 = jj;
		for (j1 = ja; j1 <= i__4; ++j1) {
		    ++ii;
		    ++j2;
/* L40: */
		    h__[ii] += di[i2 + j2 * 9 - 10];
		}
	    }

/*   CALCULATE THE TWO-ELECTRON INTEGRALS, W; THE ELECTRON NUCLEAR TERMS */
/*   E1B AND E2A; AND THE NUCLEAR-NUCLEAR TERM ENUC. */

	    if (euler_1.id == 0) {
		rotate_(&ni, &nj, &coord[i__ * 3 + 1], &coord[j * 3 + 1], &w[
			kr], &kr, e1b, e2a, &enuc, &cutoff);
	    } else {
		kro = kr;
		solrot_(&ni, &nj, &coord[i__ * 3 + 1], &coord[j * 3 + 1], wjd,
			 wkd, &kr, e1b, e2a, &enuc, &cutoff);
		jj = 0;
		i__4 = kr - 1;
		for (ii = kro; ii <= i__4; ++ii) {
		    ++jj;
		    wj[ii] = wjd[jj - 1];
/* L50: */
		    wk[ii] = wkd[jj - 1];
		}
	    }
	    *enuclr += enuc;

/*   ADD ON THE ELECTRON-NUCLEAR ATTRACTION TERM FOR ATOM I. */

	    i2 = 0;
	    i__4 = ic;
	    for (i1 = ia; i1 <= i__4; ++i1) {
		ii = i1 * (i1 - 1) / 2 + ia - 1;
		i__3 = i1;
		for (j1 = ia; j1 <= i__3; ++j1) {
		    ++ii;
		    ++i2;
/* L60: */
		    h__[ii] += e1b[i2 - 1] * half;
		}
	    }
	    i__3 = ib;
	    for (i1 = ic + 1; i1 <= i__3; ++i1) {
		ii = i1 * (i1 + 1) / 2;
/* L70: */
		h__[ii] += e1b[0] * half;
	    }

/*   ADD ON THE ELECTRON-NUCLEAR ATTRACTION TERM FOR ATOM J. */

	    i2 = 0;
	    i__3 = jc;
	    for (i1 = ja; i1 <= i__3; ++i1) {
		ii = i1 * (i1 - 1) / 2 + ja - 1;
		i__4 = i1;
		for (j1 = ja; j1 <= i__4; ++j1) {
		    ++ii;
		    ++i2;
/* L80: */
		    h__[ii] += e2a[i2 - 1] * half;
		}
	    }
	    i__4 = jb;
	    for (i1 = jc + 1; i1 <= i__4; ++i1) {
		ii = i1 * (i1 + 1) / 2;
/* L90: */
		h__[ii] += e2a[0] * half;
	    }
/* L100: */
	}
/* L110: */
    }
/* COSMO change */
/* A. KLAMT 16.7.91 */
    if (iseps_1.useps) {
/* The following routine adds the dielectric correction for the electron-core */
/* interaction to the diagonal elements of H */
	addhcr_(&h__[1]);
/* In the following routine the dielectric correction to the core-core- */
/* interaction is added to ENUCLR */
	addnuc_(enuclr);
    }
/* end of COSMO change */
    if (! debug) {
	return 0;
    }
    s_wsfe(&io___44);
    e_wsfe();
    vecprt_(&h__[1], &molkst_1.norbs);
    j = min(400,kr);
    if (euler_1.id == 0) {
	s_wsfe(&io___45);
	e_wsfe();
	s_wsfe(&io___46);
	i__1 = j;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&w[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    } else {
	s_wsfe(&io___47);
	e_wsfe();
	s_wsfe(&io___48);
	i__1 = j;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&wj[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___49);
	e_wsfe();
	s_wsfe(&io___50);
	i__1 = j;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&wk[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    return 0;
} /* hcore_ */

