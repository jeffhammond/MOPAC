/* jcarin.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal yparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    integer l1l, l2l, l3l, l1u, l2u, l3u;
} ucell_;

#define ucell_1 ucell_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

/* Subroutine */ int jcarin_(doublereal *coord, doublereal *xparam, 
	doublereal *step, logical *preci, doublereal *b, integer *ncol)
{
    /* System generated locals */
    integer b_dim1, b_offset, i__1, i__2, i__3, i__4, i__5;

    /* Local variables */
    static integer j, ii, ij, il, jl, kl, ll, ivar;
    static doublereal coold[9720]	/* was [3][3240] */;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *), symtry_(
	    void);

/*     JACOBIAN dCARTESIAN/dINTERNAL, WORKED OUT BY FINITE DIFFERENCE. */
/*  INPUT */
/*     XPARAM(*) : INTERNAL COORDINATES */
/*     STEP      : STEP SIZE FOR FINITE DIFFERENCE METHOD */
/*     PRECI     : .TRUE. IF 2-POINTS FINITE DIFFERENCES TO BE USED, */
/*                 .FALSE. OTHERWISE. */
/*  OUTPUT */
/*     B(NVAR,NCOL) : JACOBIAN, STEP TIME TOO LARGE. */

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
    b_dim1 = geovar_1.nvar;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    --xparam;
    coord -= 4;

    /* Function Body */
    *ncol = molkst_1.numat * 3;
    if (euler_1.id != 0) {
	*ncol = *ncol * (ucell_1.l1u - ucell_1.l1l + 1) * (ucell_1.l2u - 
		ucell_1.l2l + 1) * (ucell_1.l3u - ucell_1.l3l + 1);
    }

/*     INTERNAL OF CENTRAL POINT */
    i__1 = geovar_1.nvar;
    for (ivar = 1; ivar <= i__1; ++ivar) {
/* L10: */
	geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar << 1) - 
		2] * 3 - 4] = xparam[ivar];
    }

    if (euler_1.id == 0) {

/*        MOLECULAR SYSTEM */
/*        ---------------- */
	i__1 = geovar_1.nvar;
	for (ivar = 1; ivar <= i__1; ++ivar) {
/*        STEP FORWARD */
	    geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar << 
		    1) - 2] * 3 - 4] = xparam[ivar] + *step;
	    if (geosym_1.ndep != 0) {
		symtry_();
	    }
	    gmetry_(geom_1.geo, &coord[4]);
	    i__2 = *ncol;
	    for (j = 1; j <= i__2; ++j) {
/* L20: */
		b[ivar + j * b_dim1] = coord[j + 3];
	    }
/* L30: */
	    geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar << 
		    1) - 2] * 3 - 4] = xparam[ivar];
	}
	if (*preci) {
	    i__1 = geovar_1.nvar;
	    for (ivar = 1; ivar <= i__1; ++ivar) {
/*           STEP BACKWARD */
		geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar 
			<< 1) - 2] * 3 - 4] = xparam[ivar] - *step;
		if (geosym_1.ndep != 0) {
		    symtry_();
		}
		gmetry_(geom_1.geo, &coord[4]);
		i__2 = *ncol;
		for (j = 1; j <= i__2; ++j) {
/* L40: */
		    b[ivar + j * b_dim1] -= coord[j + 3];
		}
/* L50: */
		geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar 
			<< 1) - 2] * 3 - 4] = xparam[ivar];
	    }
	} else {
/*           CENTRAL POINT */
	    if (geosym_1.ndep != 0) {
		symtry_();
	    }
	    gmetry_(geom_1.geo, &coord[4]);
	    i__1 = geovar_1.nvar;
	    for (ivar = 1; ivar <= i__1; ++ivar) {
		i__2 = *ncol;
		for (j = 1; j <= i__2; ++j) {
/* L60: */
		    b[ivar + j * b_dim1] -= coord[j + 3];
		}
	    }
	}
    } else {

/*        SOLID STATE */
/*        ----------- */
	i__2 = geovar_1.nvar;
	for (ivar = 1; ivar <= i__2; ++ivar) {
/*        STEP FORWARD */
	    geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar << 
		    1) - 2] * 3 - 4] = xparam[ivar] + *step;
	    if (geosym_1.ndep != 0) {
		symtry_();
	    }
	    gmetry_(geom_1.geo, &coord[4]);
	    ij = 0;
	    i__1 = molkst_1.numat;
	    for (ii = 1; ii <= i__1; ++ii) {
		i__3 = ucell_1.l1u;
		for (il = ucell_1.l1l; il <= i__3; ++il) {
		    i__4 = ucell_1.l2u;
		    for (jl = ucell_1.l2l; jl <= i__4; ++jl) {
			i__5 = ucell_1.l3u;
			for (kl = ucell_1.l3l; kl <= i__5; ++kl) {
			    for (ll = 1; ll <= 3; ++ll) {
				++ij;
/* L70: */
				b[ivar + ij * b_dim1] = coord[ll + ii * 3] + 
					euler_1.tvec[ll - 1] * il + 
					euler_1.tvec[ll + 2] * jl + 
					euler_1.tvec[ll + 5] * kl;
			    }
			}
		    }
		}
	    }
/* L80: */
	    geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar << 
		    1) - 2] * 3 - 4] = xparam[ivar];
	}
	if (*preci) {
	    i__2 = geovar_1.nvar;
	    for (ivar = 1; ivar <= i__2; ++ivar) {
/*           STEP BACKWARD */
		geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar 
			<< 1) - 2] * 3 - 4] = xparam[ivar] - *step;
		if (geosym_1.ndep != 0) {
		    symtry_();
		}
		gmetry_(geom_1.geo, &coord[4]);
		ij = 0;
		i__5 = molkst_1.numat;
		for (ii = 1; ii <= i__5; ++ii) {
		    i__4 = ucell_1.l1u;
		    for (il = ucell_1.l1l; il <= i__4; ++il) {
			i__3 = ucell_1.l2u;
			for (jl = ucell_1.l2l; jl <= i__3; ++jl) {
			    i__1 = ucell_1.l3u;
			    for (kl = ucell_1.l3l; kl <= i__1; ++kl) {
				for (ll = 1; ll <= 3; ++ll) {
				    ++ij;
/* L90: */
				    b[ivar + ij * b_dim1] = b[ivar + ij * 
					    b_dim1] - coord[ll + ii * 3] - 
					    euler_1.tvec[ll - 1] * il - 
					    euler_1.tvec[ll + 2] * jl - 
					    euler_1.tvec[ll + 5] * kl;
				}
			    }
			}
		    }
		}
/* L100: */
		geom_1.geo[geovar_1.loc[(ivar << 1) - 1] + geovar_1.loc[(ivar 
			<< 1) - 2] * 3 - 4] = xparam[ivar];
	    }
	} else {
/*           CENTRAL POINT */
	    if (geosym_1.ndep != 0) {
		symtry_();
	    }
	    gmetry_(geom_1.geo, &coord[4]);
	    ij = 0;
	    i__2 = molkst_1.numat;
	    for (ii = 1; ii <= i__2; ++ii) {
		i__1 = ucell_1.l1u;
		for (il = ucell_1.l1l; il <= i__1; ++il) {
		    i__3 = ucell_1.l2u;
		    for (jl = ucell_1.l2l; jl <= i__3; ++jl) {
			i__4 = ucell_1.l3u;
			for (kl = ucell_1.l3l; kl <= i__4; ++kl) {
			    ++ij;
			    for (ll = 1; ll <= 3; ++ll) {
/* L110: */
				coold[ll + ij * 3 - 4] = coord[ll + ii * 3] + 
					euler_1.tvec[ll - 1] * il + 
					euler_1.tvec[ll + 2] * jl + 
					euler_1.tvec[ll + 5] * kl;
			    }
			}
		    }
		}
	    }
	    i__4 = geovar_1.nvar;
	    for (ivar = 1; ivar <= i__4; ++ivar) {
		i__3 = *ncol;
		for (ij = 1; ij <= i__3; ++ij) {
/* L120: */
		    b[ivar + ij * b_dim1] -= coold[ij - 1];
		}
	    }
	}
    }
    return 0;
} /* jcarin_ */

