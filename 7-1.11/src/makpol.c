/* makpol.f -- translated by f2c (version 20020621).
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
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    char ltxt[1], txtatm[960];
} atomtx_;

#define atomtx_1 atomtx_

struct {
    char simbol[3600];
} simbol_;

#define simbol_1 simbol_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int makpol_(doublereal *coord)
{
    /* Format strings */
    static char fmt_160[] = "(\002    T\002,i1,\002 = \002,f11.7,\002    "
	    "\002,f11.7,\002    \002,f11.7)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, im1, nan, nbn, ncn, ioff, joff, koff, last, 
	    mers;
    extern doublereal reada_(char *, integer *, ftnlen);
    extern /* Subroutine */ int geout_(integer *);
    static doublereal degree;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *), xyzint_(
	    doublereal *, integer *, integer *, integer *, integer *, 
	    doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___14 = { 0, 6, 0, fmt_160, 0 };
    static cilist io___15 = { 0, 6, 0, "(/,10X,A)", 0 };


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

/*   MAKPOL TAKES A PRIMITIVE UNIT CELL AND GENERATES A TOTAL OF 'MERS' */
/*   COPIES.  THE RESULTING GEOMETRY IS PLACED IN GEO.  ARRAYS LOC, */
/*   XPARAM, NA, NB, NC, SIMBOL, TXTATM, LABELS, LOCPAR, IDEPFN, AND */
/*   LOCDEP ARE EXPANDED TO SUIT.  ARRAY TVEC IS MODIFIED, AS ARE SCALARS */
/*   NVAR, NATOMS, AND NDEP. */

/*   SYMMETRY IS FORCED ON, OR ADDED ON, IN ORDER TO MAKE THE NEW MERS */
/*   EQUIVALENT TO THE SUPPLIED MER. */

/* *********************************************************************** */
    /* Parameter adjustments */
    coord -= 4;

    /* Function Body */
    ioff = 0;
    i__1 = i_indx(keywrd_1.keywrd, " MERS", (ftnlen)241, (ftnlen)5);
    mers = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L270: */
	if (geokst_1.labels[i__ - 1] == 99) {
	    geokst_1.labels[i__ - 1] = 100;
	}
    }
    gmetry_(geom_1.geo, &coord[4]);
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L280: */
	if (geokst_1.labels[i__ - 1] == 100) {
	    geokst_1.labels[i__ - 1] = 99;
	}
    }
    nan = geokst_1.na[geokst_1.natoms - 2];
    nbn = geokst_1.nb[geokst_1.natoms - 2];
    ncn = geokst_1.nc[geokst_1.natoms - 2];
    i__1 = mers + 1;
    for (i__ = 2; i__ <= i__1; ++i__) {
	im1 = ioff;
	ioff = ioff + geokst_1.natoms - 2;

/*   FILL THE NA, NB, AND NC ADDRESSES FOR THE NEW ATOMS */

	i__2 = geokst_1.natoms - 2;
	for (j = 1; j <= i__2; ++j) {
	    if (j != 1 && i__ > mers) {
		goto L310;
	    }
	    s_copy(simbol_1.simbol + (ioff + j - 1) * 10, simbol_1.simbol + (
		    im1 + j - 1) * 10, (ftnlen)10, (ftnlen)10);
	    if (ioff + j != geokst_1.natoms - 1) {
		geokst_1.na[ioff + j - 1] = geokst_1.na[im1 + j - 1] + 
			geokst_1.natoms - 2;
		geokst_1.nb[ioff + j - 1] = geokst_1.nb[im1 + j - 1] + 
			geokst_1.natoms - 2;
		geokst_1.nc[ioff + j - 1] = geokst_1.nc[im1 + j - 1] + 
			geokst_1.natoms - 2;
	    }
	    geokst_1.labels[ioff + j - 1] = geokst_1.labels[im1 + j - 1];
	    s_copy(atomtx_1.txtatm + (ioff + j - 1 << 3), atomtx_1.txtatm + (
		    im1 + j - 1 << 3), (ftnlen)8, (ftnlen)8);
	    for (k = 1; k <= 3; ++k) {
/* L300: */
		coord[k + (ioff + j) * 3] = coord[k + (im1 + j) * 3] + 
			euler_1.tvec[k - 1];
	    }
L310:
	    ;
	}
	if (i__ == 2) {

/*  SPECIAL TREATMENT FOR THE FIRST THREE ATOMS OF THE SECOND MER */

	    geokst_1.na[geokst_1.natoms - 2] = nan;
	    geokst_1.nb[geokst_1.natoms - 2] = nbn;
	    geokst_1.nc[geokst_1.natoms - 2] = ncn;
	    geokst_1.nb[geokst_1.natoms - 1] = geokst_1.na[geokst_1.natoms - 
		    3];
	    geokst_1.nc[geokst_1.natoms - 1] = geokst_1.nb[geokst_1.natoms - 
		    3];
	    geokst_1.nc[geokst_1.natoms] = geokst_1.na[geokst_1.natoms - 3];
	}
/* #            DO 320 J=1,NATOMS-2 */
/* #  320       WRITE(6,'(3I5,3F12.5,3I4)')I,J,LABELS(IFF+J), */
/* #     1(COORD(K,IOFF+J),K=1,3), */
/* #     2NA(IOFF+J), NB(IOFF+J), NC(IOFF+J) */
/* L330: */
    }

/*  USE ATOMS OF FIRST MER TO DEFINE THE OTHER MERS.  FOR ATOMS 1, 2, AND */
/*  3, USE DATA FROM THE SECOND MER. */

    i__1 = geokst_1.natoms - 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (k = 1; k <= 3; ++k) {
	    if (k >= i__) {
		koff = geokst_1.natoms - 2;
		joff = 3;
	    } else {
		koff = 0;
		joff = 2;
	    }
	    i__2 = mers + 1;
	    for (j = joff; j <= i__2; ++j) {
		if (i__ != 1 && j > mers) {
		    goto L340;
		}
		++geosym_1.ndep;
		geosym_1.locpar[geosym_1.ndep - 1] = i__ + koff;
		geosym_1.idepfn[geosym_1.ndep - 1] = k;
		geosym_1.locdep[geosym_1.ndep - 1] = (geokst_1.natoms - 2) * (
			j - 1) + i__;
L340:
		;
	    }
/* L350: */
	}
/* L360: */
    }

/*   CARTESIAN COORDINATES OF THE TV */

    last = (geokst_1.natoms - 2) * mers + 2;
    coord[last * 3 + 1] = coord[(ioff + 1) * 3 + 1];
    coord[last * 3 + 2] = coord[(ioff + 1) * 3 + 2];
    coord[last * 3 + 3] = coord[(ioff + 1) * 3 + 3];

/*  REMOVE OPTIMIZATION FLAGS OF LAST TWO ATOMS SUPPLIED BY THE USER */

    for (i__ = 1; i__ <= 6; ++i__) {
/* L331: */
	if (geovar_1.loc[(geovar_1.nvar << 1) - 2] > geokst_1.natoms - 2) {
	    --geovar_1.nvar;
	}
    }

/*   PUT ON OPTIMIZATION FLAGES FOR FIRST THREE ATOMS OF THE SECOND MER */

    geovar_1.loc[(geovar_1.nvar + 1 << 1) - 2] = geokst_1.natoms - 1;
    geovar_1.loc[(geovar_1.nvar + 1 << 1) - 1] = 1;
    geovar_1.loc[(geovar_1.nvar + 2 << 1) - 2] = geokst_1.natoms - 1;
    geovar_1.loc[(geovar_1.nvar + 2 << 1) - 1] = 2;
    geovar_1.loc[(geovar_1.nvar + 3 << 1) - 2] = geokst_1.natoms - 1;
    geovar_1.loc[(geovar_1.nvar + 3 << 1) - 1] = 3;
    geovar_1.loc[(geovar_1.nvar + 4 << 1) - 2] = geokst_1.natoms;
    geovar_1.loc[(geovar_1.nvar + 4 << 1) - 1] = 2;
    geovar_1.loc[(geovar_1.nvar + 5 << 1) - 2] = geokst_1.natoms;
    geovar_1.loc[(geovar_1.nvar + 5 << 1) - 1] = 3;
    geovar_1.loc[(geovar_1.nvar + 6 << 1) - 2] = geokst_1.natoms + 1;
    geovar_1.loc[(geovar_1.nvar + 6 << 1) - 1] = 3;

/*  RE-DO SPECIFICATION OF THE TV */

    geokst_1.labels[last - 2] = 99;
    geokst_1.labels[last - 1] = 107;
    s_copy(atomtx_1.txtatm + (last - 2 << 3), " ", (ftnlen)8, (ftnlen)1);
    s_copy(atomtx_1.txtatm + (last - 1 << 3), " ", (ftnlen)8, (ftnlen)1);
    geokst_1.na[last - 1] = 1;
    geokst_1.nb[last - 1] = last - 1;
    geokst_1.nc[last - 1] = last - 2;
    geovar_1.loc[(geovar_1.nvar + 7 << 1) - 2] = last;
    geovar_1.loc[(geovar_1.nvar + 7 << 1) - 1] = 1;

/*   CONVERT TO INTERNAL COORDINATES.  USE CONNECTIVITY CREATED HERE */

    degree = 1.;
    geokst_1.na[1] = -2;
    xyzint_(&coord[4], &last, geokst_1.na, geokst_1.nb, geokst_1.nc, &degree, 
	    geom_1.geo);

/*  RE-SIZE THE TRANSLATION VECTOR */

    euler_1.tvec[0] = coord[last * 3 + 1];
    euler_1.tvec[1] = coord[last * 3 + 2];
    euler_1.tvec[2] = coord[last * 3 + 3];

/* THE COORDINATES OF THE FIRST 3 ATOMS NEED TO BE OPTIMIZED */

    geovar_1.xparam[geovar_1.nvar] = geom_1.geo[(geokst_1.natoms - 1) * 3 - 3]
	    ;
    geovar_1.xparam[geovar_1.nvar + 1] = geom_1.geo[(geokst_1.natoms - 1) * 3 
	    - 2];
    geovar_1.xparam[geovar_1.nvar + 2] = geom_1.geo[(geokst_1.natoms - 1) * 3 
	    - 1];
    geovar_1.xparam[geovar_1.nvar + 3] = geom_1.geo[geokst_1.natoms * 3 - 2];
    geovar_1.xparam[geovar_1.nvar + 4] = geom_1.geo[geokst_1.natoms * 3 - 1];
    geovar_1.xparam[geovar_1.nvar + 5] = geom_1.geo[(geokst_1.natoms + 1) * 3 
	    - 1];
    geokst_1.natoms = last;
    geovar_1.xparam[geovar_1.nvar + 6] = geom_1.geo[geokst_1.natoms * 3 - 3];
    geovar_1.nvar += 7;
    s_wsfe(&io___14);
    i__1 = euler_1.id;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	for (j = 1; j <= 3; ++j) {
	    do_fio(&c__1, (char *)&euler_1.tvec[j + i__ * 3 - 4], (ftnlen)
		    sizeof(doublereal));
	}
    }
    e_wsfe();
/* L150: */
    s_wsfe(&io___15);
    do_fio(&c__1, " EXPANDED POLYMER UNIT CELL", (ftnlen)27);
    e_wsfe();
    geout_(&c__1);
    return 0;
} /* makpol_ */

