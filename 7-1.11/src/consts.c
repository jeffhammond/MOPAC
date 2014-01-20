/* consts.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal fepsi, rds, disex2;
    integer nspa, nps, nps2, nden;
    doublereal cosurf[1200]	/* was [3][400] */, srad[120], abcmat[162000],
	     tm[1080]	/* was [3][3][120] */, qden[660], dirtm[3246]	/* 
	    was [3][1082] */, bh[400];
} solv_;

#define solv_1 solv_

struct {
    integer iatsp[401], nar[400], nnx[240]	/* was [2][120] */;
} solvi_;

#define solvi_1 solvi_

struct {
    integer npsx, nps2x;
} solvps_;

#define solvps_1 solvps_

struct {
    doublereal dirvec[3246]	/* was [3][1082] */;
    integer nn[360]	/* was [3][120] */;
} dirvec_;

#define dirvec_1 dirvec_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal area;
} areavd_;

#define areavd_1 areavd_

struct {
    integer ifiles[30];
} chanel_;

#define chanel_1 chanel_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static doublereal c_b55 = -.5;
static integer c__3 = 3;
static integer c__1200 = 1200;

/* Subroutine */ int consts_(doublereal *coord)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double cos(doublereal), pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal r__, x;
    static integer i0, j1, j2, n0[2];
    static doublereal x1, x2, x3, y1, y2, y3, aa;
    static integer ii;
    static doublereal ds, xa[3], ri, rj;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal xi[3], xj[3];
    static integer ix;
    static doublereal sp, xx[3];
    static integer nn1, nn2, nn3;
    static doublereal aij;
    static logical din[1082];
    static integer ipm, ips, jps;
    static doublereal spm;
#define xsp ((doublereal *)&solv_1 + 161325)
    static doublereal c2ds;
    static integer nps0, nps3, nara, nari, narj, info, jmax;
    static doublereal sdis, dist;
    static integer ipiv[400], nset[64920];
    static logical isup;
    static doublereal sdis0, dist1, dist2, dist3, fdiag;
    static integer narea, nsetf[400], inset;
    extern /* Subroutine */ int dgetrf_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *), dgetri_(integer *, doublereal *,
	     integer *, integer *, doublereal *, integer *, integer *);
    static integer nsetfi, nsetfj, maxnps;
    static doublereal sininv;

    /* Fortran I/O blocks */
    static cilist io___6 = { 0, 0, 0, 0, 0 };
    static cilist io___43 = { 0, 0, 0, 0, 0 };
    static cilist io___65 = { 0, 6, 0, 0, 0 };
    static cilist io___66 = { 0, 6, 0, 0, 0 };


/* THIS ROUTINE CONSTRUCTS OR UPDATES THE SOLVENT-ACCESSIBLE */
/* SURFACE (SAS) */
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

    /* Function Body */
    solv_1.nps = solvps_1.npsx;
    solv_1.nps2 = solvps_1.nps2x;
    isup = solv_1.nps > 0;
    n0[0] = solv_1.nps2;
    n0[1] = -solv_1.nps;
    maxnps = sqrt(324000.25099999999f) - solv_1.nden - .5f;
    maxnps = min(maxnps,400);
    if (maxnps < molkst_1.numat * 3) {
	io___6.ciunit = *iw;
	s_wsle(&io___6);
	do_lio(&c__9, &c__1, " PARAMETER LENABC MUST BE INCREASED FOR THIS S"
		"YSTEM", (ftnlen)51);
	e_wsle();
	s_stop(" PARAMETER LENABC MUST BE INCREASED FOR THIS SYSTEM", (ftnlen)
		51);
    }
    if (isup) {
	nps3 = 400 - solv_1.nps;
	for (i__ = solv_1.nps; i__ >= 1; --i__) {
	    solvi_1.iatsp[nps3 + i__ - 1] = solvi_1.iatsp[i__ - 1];
	    for (ix = 1; ix <= 3; ++ix) {
		solv_1.cosurf[ix + (nps3 + i__) * 3 - 4] = solv_1.cosurf[ix + 
			i__ * 3 - 4];
/* L10: */
	    }
	}
	++nps3;
    }
    sdis = 0.;
    fdiag = sqrt(1082.) * 1.05;
    inset = 1;
    solvi_1.iatsp[400] = 0;
    solv_1.nps = 0;
    areavd_1.area = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ds = sqrt(4. / solv_1.nspa);
	if (molkst_1.nat[i__ - 1] == 1) {
	    ds *= 2;
	}
	c2ds = cos(ds * 2.);
	r__ = solv_1.srad[i__ - 1];
	ri = r__ - solv_1.rds;
	for (ix = 1; ix <= 3; ++ix) {
/* L20: */
	    xa[ix - 1] = coord[ix + i__ * 3];
	}
	nps0 = solv_1.nps + 1;
	if (isup) {
	    if (solv_1.nps >= nps3) {
		s_stop("NPS .GT. NPS3", (ftnlen)13);
	    }
	    solv_1.nps2 = nps3;
/*           IF (IATSP(NPS0) .NE. I) GO TO 340 */
	    for (ips = solv_1.nps2; ips <= 401; ++ips) {
/* L30: */
		if (solvi_1.iatsp[ips - 1] != i__) {
		    goto L40;
		}
	    }
L40:
	    nps3 = ips;
/* TRANSFORM COSURF ACCORDING TO TM(INV) */
	    i__2 = nps3 - 1;
	    for (j = solv_1.nps2; j <= i__2; ++j) {
		xx[0] = solv_1.cosurf[j * 3 - 3];
		xx[1] = solv_1.cosurf[j * 3 - 2];
		xx[2] = solv_1.cosurf[j * 3 - 1];
		solv_1.cosurf[j * 3 - 3] = xx[0] * solv_1.tm[(i__ * 3 + 1) * 
			3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 2) * 3 - 12] + 
			xx[2] * solv_1.tm[(i__ * 3 + 3) * 3 - 12];
		solv_1.cosurf[j * 3 - 2] = xx[0] * solv_1.tm[(i__ * 3 + 1) * 
			3 - 11] + xx[1] * solv_1.tm[(i__ * 3 + 2) * 3 - 11] + 
			xx[2] * solv_1.tm[(i__ * 3 + 3) * 3 - 11];
		solv_1.cosurf[j * 3 - 1] = xx[0] * solv_1.tm[(i__ * 3 + 1) * 
			3 - 10] + xx[1] * solv_1.tm[(i__ * 3 + 2) * 3 - 10] + 
			xx[2] * solv_1.tm[(i__ * 3 + 3) * 3 - 10];
/* L50: */
	    }
	    nn1 = dirvec_1.nn[i__ * 3 - 3];
	    nn2 = dirvec_1.nn[i__ * 3 - 2];
	    nn3 = dirvec_1.nn[i__ * 3 - 1];
	} else {
/* SEARCH FOR 3 NEAREST NEIGHBOR ATOMS */
	    dist1 = 1e20;
	    dist2 = 1e20;
	    dist3 = 1e20;
	    nn1 = 0;
	    nn2 = 0;
	    nn3 = 0;
	    i__2 = molkst_1.numat;
	    for (j = 1; j <= i__2; ++j) {
		if (j == i__) {
		    goto L70;
		}
		dist = 0.;
		for (ix = 1; ix <= 3; ++ix) {
/* L60: */
/* Computing 2nd power */
		    d__1 = xa[ix - 1] - coord[ix + j * 3];
		    dist += d__1 * d__1;
		}
		if (dist + .05 < dist3) {
		    dist3 = dist;
		    nn3 = j;
		}
		if (dist3 + .05 < dist2) {
		    dist = dist2;
		    dist2 = dist3;
		    dist3 = dist;
		    nn3 = nn2;
		    nn2 = j;
		}
		if (dist2 + .05 < dist1) {
		    dist = dist1;
		    dist1 = dist2;
		    dist2 = dist;
		    nn2 = nn1;
		    nn1 = j;
		}
L70:
		;
	    }
	    dirvec_1.nn[i__ * 3 - 3] = nn1;
	    dirvec_1.nn[i__ * 3 - 2] = nn2;
	    dirvec_1.nn[i__ * 3 - 1] = nn3;
	}
/* BUILD NEW TRANSFORMATION MATRIX */
	if (nn1 == 0) {
	    solv_1.tm[(i__ * 3 + 1) * 3 - 12] = 1.;
	    solv_1.tm[(i__ * 3 + 2) * 3 - 12] = 0.;
	    solv_1.tm[(i__ * 3 + 3) * 3 - 12] = 0.;
	} else {
	    dist1 = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
/* L80: */
/* Computing 2nd power */
		d__1 = xa[ix - 1] - coord[ix + nn1 * 3];
		dist1 += d__1 * d__1;
	    }
	    dist = 1. / sqrt(dist1);
	    solv_1.tm[(i__ * 3 + 1) * 3 - 12] = (coord[nn1 * 3 + 1] - xa[0]) *
		     dist;
	    solv_1.tm[(i__ * 3 + 2) * 3 - 12] = (coord[nn1 * 3 + 2] - xa[1]) *
		     dist;
	    solv_1.tm[(i__ * 3 + 3) * 3 - 12] = (coord[nn1 * 3 + 3] - xa[2]) *
		     dist;
	}
L90:
	if (nn2 == 0) {
/* Computing 2nd power */
	    d__1 = solv_1.tm[(i__ * 3 + 3) * 3 - 12];
/* Computing 2nd power */
	    d__2 = solv_1.tm[(i__ * 3 + 2) * 3 - 12];
/* Computing 2nd power */
	    d__3 = solv_1.tm[(i__ * 3 + 1) * 3 - 12];
	    dist = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
	    solv_1.tm[(i__ * 3 + 1) * 3 - 11] = -solv_1.tm[(i__ * 3 + 2) * 3 
		    - 12] / dist;
	    solv_1.tm[(i__ * 3 + 2) * 3 - 11] = solv_1.tm[(i__ * 3 + 1) * 3 - 
		    12] / dist;
	    solv_1.tm[(i__ * 3 + 3) * 3 - 11] = 0.;
	} else {
	    dist2 = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
/* L100: */
/* Computing 2nd power */
		d__1 = xa[ix - 1] - coord[ix + nn2 * 3];
		dist2 += d__1 * d__1;
	    }
	    dist = 1. / sqrt(dist2);
	    xx[0] = (coord[nn2 * 3 + 1] - xa[0]) * dist;
	    xx[1] = (coord[nn2 * 3 + 2] - xa[1]) * dist;
	    xx[2] = (coord[nn2 * 3 + 3] - xa[2]) * dist;
	    sp = xx[0] * solv_1.tm[(i__ * 3 + 1) * 3 - 12] + xx[1] * 
		    solv_1.tm[(i__ * 3 + 2) * 3 - 12] + xx[2] * solv_1.tm[(
		    i__ * 3 + 3) * 3 - 12];
	    if (sp * sp > .99) {
		nn2 = nn3;
		nn3 = 0;
		dist2 = dist3;
		goto L90;
	    }
	    sininv = 1. / sqrt(1. - sp * sp);
	    solv_1.tm[(i__ * 3 + 1) * 3 - 11] = (xx[0] - sp * solv_1.tm[(i__ *
		     3 + 1) * 3 - 12]) * sininv;
	    solv_1.tm[(i__ * 3 + 2) * 3 - 11] = (xx[1] - sp * solv_1.tm[(i__ *
		     3 + 2) * 3 - 12]) * sininv;
	    solv_1.tm[(i__ * 3 + 3) * 3 - 11] = (xx[2] - sp * solv_1.tm[(i__ *
		     3 + 3) * 3 - 12]) * sininv;
	}
	solv_1.tm[(i__ * 3 + 1) * 3 - 10] = solv_1.tm[(i__ * 3 + 2) * 3 - 12] 
		* solv_1.tm[(i__ * 3 + 3) * 3 - 11] - solv_1.tm[(i__ * 3 + 2) 
		* 3 - 11] * solv_1.tm[(i__ * 3 + 3) * 3 - 12];
	solv_1.tm[(i__ * 3 + 2) * 3 - 10] = solv_1.tm[(i__ * 3 + 3) * 3 - 12] 
		* solv_1.tm[(i__ * 3 + 1) * 3 - 11] - solv_1.tm[(i__ * 3 + 3) 
		* 3 - 11] * solv_1.tm[(i__ * 3 + 1) * 3 - 12];
	solv_1.tm[(i__ * 3 + 3) * 3 - 10] = solv_1.tm[(i__ * 3 + 1) * 3 - 12] 
		* solv_1.tm[(i__ * 3 + 2) * 3 - 11] - solv_1.tm[(i__ * 3 + 1) 
		* 3 - 11] * solv_1.tm[(i__ * 3 + 2) * 3 - 12];
/* TRANSFORM DIRVEC ACCORDING TO TM */
	for (j = 1; j <= 1082; ++j) {
	    xx[0] = dirvec_1.dirvec[j * 3 - 3];
	    xx[1] = dirvec_1.dirvec[j * 3 - 2];
	    xx[2] = dirvec_1.dirvec[j * 3 - 1];
	    for (ix = 1; ix <= 3; ++ix) {
		x = xx[0] * solv_1.tm[(ix + i__ * 3) * 3 - 12] + xx[1] * 
			solv_1.tm[(ix + i__ * 3) * 3 - 11] + xx[2] * 
			solv_1.tm[(ix + i__ * 3) * 3 - 10];
		solv_1.dirtm[ix + j * 3 - 4] = x;
/* L110: */
	    }
	}
/* FIND THE POINTS OF THE BASIC GRID ON THE SAS */
	narea = 0;
	for (j = 1; j <= 1082; ++j) {
	    din[j - 1] = FALSE_;
	    for (ix = 1; ix <= 3; ++ix) {
		xx[ix - 1] = xa[ix - 1] + solv_1.dirtm[ix + j * 3 - 4] * r__;
/* L130: */
	    }
	    i__2 = molkst_1.numat;
	    for (k = 1; k <= i__2; ++k) {
		if (k == i__) {
		    goto L150;
		}
		dist = 0.;
		for (ix = 1; ix <= 3; ++ix) {
/* Computing 2nd power */
		    d__1 = xx[ix - 1] - coord[ix + k * 3];
		    dist += d__1 * d__1;
/* L140: */
		}
		dist = sqrt(dist) - solv_1.srad[k - 1];
		if (dist < 0.) {
		    goto L160;
		}
L150:
		;
	    }
	    ++narea;
	    din[j - 1] = TRUE_;
L160:
	    ;
	}
	if (narea == 0) {
	    goto L340;
	}
	areavd_1.area += narea * ri * ri;
	if (isup) {
	    i__2 = nps3 - 1;
	    for (j = solv_1.nps2; j <= i__2; ++j) {
		++solv_1.nps;
		solvi_1.iatsp[solv_1.nps - 1] = i__;
		xx[0] = solv_1.cosurf[j * 3 - 3];
		xx[1] = solv_1.cosurf[j * 3 - 2];
		xx[2] = solv_1.cosurf[j * 3 - 1];
		solv_1.cosurf[solv_1.nps * 3 - 3] = xx[0] * solv_1.tm[(i__ * 
			3 + 1) * 3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 1) * 
			3 - 11] + xx[2] * solv_1.tm[(i__ * 3 + 1) * 3 - 10];
		solv_1.cosurf[solv_1.nps * 3 - 2] = xx[0] * solv_1.tm[(i__ * 
			3 + 2) * 3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 2) * 
			3 - 11] + xx[2] * solv_1.tm[(i__ * 3 + 2) * 3 - 10];
		solv_1.cosurf[solv_1.nps * 3 - 1] = xx[0] * solv_1.tm[(i__ * 
			3 + 3) * 3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 3) * 
			3 - 11] + xx[2] * solv_1.tm[(i__ * 3 + 3) * 3 - 10];
/* L120: */
	    }
	} else {
	    i0 = 2 - 1 / molkst_1.nat[i__ - 1];
	    jmax = n0[i0 - 1];
	    i0 = (i0 - 1) * 3246 - 3;
	    i__2 = jmax;
	    for (j = 1; j <= i__2; ++j) {
		++solv_1.nps;
		solvi_1.iatsp[solv_1.nps - 1] = i__;
		xx[0] = solv_1.abcmat[i0 + j * 3];
		xx[1] = solv_1.abcmat[i0 + j * 3 + 1];
		xx[2] = solv_1.abcmat[i0 + j * 3 + 2];
		solv_1.cosurf[solv_1.nps * 3 - 3] = xx[0] * solv_1.tm[(i__ * 
			3 + 1) * 3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 1) * 
			3 - 11] + xx[2] * solv_1.tm[(i__ * 3 + 1) * 3 - 10];
		solv_1.cosurf[solv_1.nps * 3 - 2] = xx[0] * solv_1.tm[(i__ * 
			3 + 2) * 3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 2) * 
			3 - 11] + xx[2] * solv_1.tm[(i__ * 3 + 2) * 3 - 10];
		solv_1.cosurf[solv_1.nps * 3 - 1] = xx[0] * solv_1.tm[(i__ * 
			3 + 3) * 3 - 12] + xx[1] * solv_1.tm[(i__ * 3 + 3) * 
			3 - 11] + xx[2] * solv_1.tm[(i__ * 3 + 3) * 3 - 10];
/* L45: */
	    }
	}
L200:
	sdis0 = sdis;
	i__2 = solv_1.nps;
	for (ips = nps0; ips <= i__2; ++ips) {
	    solvi_1.nar[ips - 1] = 0;
	    xsp[ips * 3 - 3] = 0.;
	    xsp[ips * 3 - 2] = 0.;
	    xsp[ips * 3 - 1] = 0.;
/* L210: */
	}
	for (j = 1; j <= 1082; ++j) {
	    if (! din[j - 1]) {
		goto L250;
	    }
	    spm = -1.;
	    x1 = solv_1.dirtm[j * 3 - 3];
	    x2 = solv_1.dirtm[j * 3 - 2];
	    x3 = solv_1.dirtm[j * 3 - 1];
	    i__2 = solv_1.nps;
	    for (ips = nps0; ips <= i__2; ++ips) {
		sp = x1 * solv_1.cosurf[ips * 3 - 3] + x2 * solv_1.cosurf[ips 
			* 3 - 2] + x3 * solv_1.cosurf[ips * 3 - 1];
		if (sp < spm) {
		    goto L220;
		}
		spm = sp;
		ipm = ips;
L220:
		;
	    }
	    if (spm < c2ds) {
		++solv_1.nps;
		if (solv_1.nps > maxnps) {
		    io___43.ciunit = *iw;
		    s_wsle(&io___43);
		    do_lio(&c__9, &c__1, "NPS IS GREATER THAN MAXNPS-USE SMA"
			    "LLER NSPA", (ftnlen)43);
		    e_wsle();
		    s_stop("NPS GREATER THAN MAXNPS", (ftnlen)23);
		}
		for (ix = 1; ix <= 3; ++ix) {
/* L230: */
		    solv_1.cosurf[ix + solv_1.nps * 3 - 4] = solv_1.dirtm[ix 
			    + j * 3 - 4];
		}
		solvi_1.iatsp[solv_1.nps - 1] = i__;
		goto L200;
	    }
	    ++solvi_1.nar[ipm - 1];
	    for (ix = 1; ix <= 3; ++ix) {
/* L240: */
		xsp[ix + ipm * 3 - 4] += solv_1.dirtm[ix + j * 3 - 4];
	    }
L250:
	    ;
	}
	sdis = 0.;
	ips = nps0 - 1;
	if (solv_1.nps < ips) {
	    goto L200;
	}
L260:
	++ips;
L352:
	if (solvi_1.nar[ips - 1] == 0) {
	    --solv_1.nps;
	    if (solv_1.nps < ips) {
		goto L200;
	    }
	    i__2 = solv_1.nps;
	    for (jps = ips; jps <= i__2; ++jps) {
		solvi_1.nar[jps - 1] = solvi_1.nar[jps];
		xsp[jps * 3 - 3] = xsp[(jps + 1) * 3 - 3];
		xsp[jps * 3 - 2] = xsp[(jps + 1) * 3 - 2];
/* L369: */
		xsp[jps * 3 - 1] = xsp[(jps + 1) * 3 - 1];
	    }
	    goto L352;
	}
	dist = 0.;
	for (ix = 1; ix <= 3; ++ix) {
	    x = xsp[ix + ips * 3 - 4];
	    dist += x * x;
/* L280: */
	}
	sdis += dist;
	dist = 1. / sqrt(dist);
	for (ix = 1; ix <= 3; ++ix) {
/* L290: */
	    solv_1.cosurf[ix + ips * 3 - 4] = xsp[ix + ips * 3 - 4] * dist;
	}
	if (ips < solv_1.nps) {
	    goto L260;
	}
	if ((d__1 = sdis - sdis0, abs(d__1)) > 1e-5) {
	    goto L200;
	}
	i__2 = solv_1.nps;
	for (ips = nps0; ips <= i__2; ++ips) {
	    nsetf[ips - 1] = inset;
	    inset += solvi_1.nar[ips - 1];
	    solvi_1.nar[ips - 1] = 0;
	    for (ix = 1; ix <= 3; ++ix) {
/* L300: */
		xsp[ix + ips * 3 - 4] = xa[ix - 1] + solv_1.cosurf[ix + ips * 
			3 - 4] * ri;
	    }
/* L310: */
	}
	for (j = 1; j <= 1082; ++j) {
	    if (! din[j - 1]) {
		goto L330;
	    }
	    spm = -1.;
	    x1 = solv_1.dirtm[j * 3 - 3];
	    x2 = solv_1.dirtm[j * 3 - 2];
	    x3 = solv_1.dirtm[j * 3 - 1];
	    i__2 = solv_1.nps;
	    for (ips = nps0; ips <= i__2; ++ips) {
		sp = x1 * solv_1.cosurf[ips * 3 - 3] + x2 * solv_1.cosurf[ips 
			* 3 - 2] + x3 * solv_1.cosurf[ips * 3 - 1];
		if (sp < spm) {
		    goto L320;
		}
		spm = sp;
		ipm = ips;
L320:
		;
	    }
	    if (spm < c2ds) {
		goto L330;
	    }
	    nara = solvi_1.nar[ipm - 1];
	    nset[nsetf[ipm - 1] + nara - 1] = j;
	    solvi_1.nar[ipm - 1] = nara + 1;
L330:
	    ;
	}
L340:
	;
    }
    areavd_1.area = areavd_1.area * 4. * 3.14159 / 1082;
/* FILLING AAMAT */
    i__1 = solv_1.nps;
    for (ips = 1; ips <= i__1; ++ips) {
	i__ = solvi_1.iatsp[ips - 1];
	ri = solv_1.srad[i__ - 1] - solv_1.rds;
	nari = solvi_1.nar[ips - 1];
	nsetfi = nsetf[ips - 1];
	aa = 0.;
	i__2 = nsetfi + nari - 1;
	for (k = nsetfi; k <= i__2; ++k) {
	    j1 = nset[k - 1];
	    aa += fdiag;
	    x1 = dirvec_1.dirvec[j1 * 3 - 3];
	    x2 = dirvec_1.dirvec[j1 * 3 - 2];
	    x3 = dirvec_1.dirvec[j1 * 3 - 1];
	    i__3 = k - 1;
	    for (l = nsetfi; l <= i__3; ++l) {
		j2 = nset[l - 1];
/* Computing 2nd power */
		d__1 = x1 - dirvec_1.dirvec[j2 * 3 - 3];
/* Computing 2nd power */
		d__2 = x2 - dirvec_1.dirvec[j2 * 3 - 2];
/* Computing 2nd power */
		d__3 = x3 - dirvec_1.dirvec[j2 * 3 - 1];
		aa += 2. / sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* L350: */
	    }
	}
/* Computing 2nd power */
	i__3 = nari;
	aa = aa / ri / (i__3 * i__3);
	solv_1.abcmat[ips + (ips - 1) * solv_1.nps - 1] = aa;
	for (ix = 1; ix <= 3; ++ix) {
	    xi[ix - 1] = coord[ix + i__ * 3];
/* L360: */
	    xa[ix - 1] = xsp[ix + ips * 3 - 4];
	}
	i__3 = solv_1.nps;
	for (jps = ips + 1; jps <= i__3; ++jps) {
	    narj = solvi_1.nar[jps - 1];
	    nsetfj = nsetf[jps - 1];
	    j = solvi_1.iatsp[jps - 1];
	    dist = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
		xj[ix - 1] = coord[ix + j * 3] - xi[ix - 1];
/* L370: */
/* Computing 2nd power */
		d__1 = xsp[ix + jps * 3 - 4] - xa[ix - 1];
		dist += d__1 * d__1;
	    }
	    if (dist < solv_1.disex2) {
		rj = solv_1.srad[j - 1] - solv_1.rds;
		aij = 0.;
		i__2 = nsetfi + nari - 1;
		for (k = nsetfi; k <= i__2; ++k) {
		    j1 = nset[k - 1];
		    for (ix = 1; ix <= 3; ++ix) {
/* L380: */
			xx[ix - 1] = dirvec_1.dirvec[ix + j1 * 3 - 4] * ri;
		    }
		    if (i__ != j) {
			x1 = xx[0] * solv_1.tm[(i__ * 3 + 1) * 3 - 12] + xx[1]
				 * solv_1.tm[(i__ * 3 + 1) * 3 - 11] + xx[2] *
				 solv_1.tm[(i__ * 3 + 1) * 3 - 10] - xj[0];
			x2 = xx[0] * solv_1.tm[(i__ * 3 + 2) * 3 - 12] + xx[1]
				 * solv_1.tm[(i__ * 3 + 2) * 3 - 11] + xx[2] *
				 solv_1.tm[(i__ * 3 + 2) * 3 - 10] - xj[1];
			x3 = xx[0] * solv_1.tm[(i__ * 3 + 3) * 3 - 12] + xx[1]
				 * solv_1.tm[(i__ * 3 + 3) * 3 - 11] + xx[2] *
				 solv_1.tm[(i__ * 3 + 3) * 3 - 10] - xj[2];
			i__4 = nsetfj + narj - 1;
			for (l = nsetfj; l <= i__4; ++l) {
			    j2 = nset[l - 1];
			    for (ix = 1; ix <= 3; ++ix) {
/* L390: */
				xx[ix - 1] = dirvec_1.dirvec[ix + j2 * 3 - 4] 
					* rj;
			    }
			    y1 = xx[0] * solv_1.tm[(j * 3 + 1) * 3 - 12] + xx[
				    1] * solv_1.tm[(j * 3 + 1) * 3 - 11] + xx[
				    2] * solv_1.tm[(j * 3 + 1) * 3 - 10] - x1;
			    y2 = xx[0] * solv_1.tm[(j * 3 + 2) * 3 - 12] + xx[
				    1] * solv_1.tm[(j * 3 + 2) * 3 - 11] + xx[
				    2] * solv_1.tm[(j * 3 + 2) * 3 - 10] - x2;
			    y3 = xx[0] * solv_1.tm[(j * 3 + 3) * 3 - 12] + xx[
				    1] * solv_1.tm[(j * 3 + 3) * 3 - 11] + xx[
				    2] * solv_1.tm[(j * 3 + 3) * 3 - 10] - x3;
			    aij += 1. / sqrt(y1 * y1 + y2 * y2 + y3 * y3);
/* L400: */
			}
		    } else {
/* L410: */
			i__4 = nsetfj + narj - 1;
			for (l = nsetfj; l <= i__4; ++l) {
			    j2 = nset[l - 1];
/*                  AA=((DIRVEC(1,J2)*RJ-XX(1))**2+(DIRVEC(2,J2)*RJ */
/*     &                   -XX(2))**2+(DIRVEC(3,J2)*RJ-XX(3))**2) */
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*                       AIJ=AIJ+((DIRVEC(1,J2)*RJ-XX(1))**2+(DIRVEC(2,J2 */
/*    1)*RJ                   -XX(2))**2+(DIRVEC(3,J2)*RJ-XX(3))**2)**-.5 */
/*    2D0 */
/* Computing 2nd power */
			    d__2 = dirvec_1.dirvec[j2 * 3 - 3] * rj - xx[0];
/* Computing 2nd power */
			    d__3 = dirvec_1.dirvec[j2 * 3 - 2] * rj - xx[1];
/* Computing 2nd power */
			    d__4 = dirvec_1.dirvec[j2 * 3 - 1] * rj - xx[2];
			    d__1 = d__2 * d__2 + d__3 * d__3 + d__4 * d__4;
			    aij += pow_dd(&d__1, &c_b55);
/* ***************************** at 1994-05-25 ***** */
/* L420: */
			}
		    }
/* L430: */
		}
		aij = aij / nari / narj;
	    } else {
		aij = 1. / sqrt(dist);
	    }
	    solv_1.abcmat[ips + (jps - 1) * solv_1.nps - 1] = aij;
	    solv_1.abcmat[jps + (ips - 1) * solv_1.nps - 1] = aij;
/* L440: */
	}
/* L450: */
    }
/* INVERT A-MATRIX */
    dgetrf_(&solv_1.nps, &solv_1.nps, solv_1.abcmat, &solv_1.nps, ipiv, &info)
	    ;
    if (info != 0) {
	s_wsle(&io___65);
	do_lio(&c__9, &c__1, " DGETRF FAILED WITH ERROR CODE ", (ftnlen)31);
	do_lio(&c__3, &c__1, (char *)&info, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("CONSTS", (ftnlen)6);
    }
    dgetri_(&solv_1.nps, solv_1.abcmat, &solv_1.nps, ipiv, xsp, &c__1200, &
	    info);
    if (info != 0) {
	s_wsle(&io___66);
	do_lio(&c__9, &c__1, " DGETRI FAILED WITH ERROR CODE ", (ftnlen)31);
	do_lio(&c__3, &c__1, (char *)&info, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("CONSTS", (ftnlen)6);
    }
/*  STORE INV. A-MATRIX AS LOWER TRIANGLE */
    ii = 0;
    i__1 = solv_1.nps;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__3 = i__;
	for (j = 1; j <= i__3; ++j) {
	    ++ii;
	    solv_1.abcmat[ii - 1] = solv_1.abcmat[j + (i__ - 1) * solv_1.nps 
		    - 1];
/* L460: */
	}
    }
    solv_1.nps2 = ii;
    return 0;
} /* consts_ */

#undef xsp
#undef iw


