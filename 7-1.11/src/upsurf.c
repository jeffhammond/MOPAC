/* upsurf.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer nspa, nss, iatsp[500], nar[500], nn[240]	/* was [2][120] */;
} solvi_;

#define solvi_1 solvi_

struct {
    doublereal dipl, fepsi, rds, disex2, tm[1080]	/* was [3][3][120] */,
	     aamat[250000]	/* was [500][500] */, admat[250000]	/* 
	    was [500][500] */, ccmat[90000]	/* was [300][300] */, bbmat[
	    150000]	/* was [300][500] */, cosurf[1500]	/* was [3][
	    500] */, srad[120];
} solvr_;

#define solvr_1 solvr_

struct {
    doublereal dirvec[3246]	/* was [3][1082] */;
    integer nnx[360]	/* was [3][120] */;
} dirvec_;

#define dirvec_1 dirvec_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer ifiles[30];
} chanel_;

#define chanel_1 chanel_

/* Table of constant values */

static integer c__500 = 500;
static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c_b38 = 150000;

/* Subroutine */ int upsurf_(doublereal *coord)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal), cos(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal r__, x;
    static integer j1, j2;
    static doublereal x1, x2, x3, aa, ds, xa[3], ri, rm;
#define iw ((integer *)&chanel_1 + 5)
    static integer ix;
    static doublereal sp, xx[3];
    static integer nn1, nn2;
    static doublereal aij;
    static logical din[1082];
    static integer ipm, ips, jps;
    static doublereal spm;
#define xsp ((doublereal *)&solvr_1 + 591084)
    static doublereal c2ds;
    static integer nss0, nss1;
    static doublereal area;
    static integer nara, nari, narj, info;
    static doublereal dist;
    static integer ipiv[500], nset[250000]	/* was [500][500] */;
    static doublereal dist1, dist2, fdiag;
#define cobas ((doublereal *)&solvr_1 + 251084)
    static doublereal dirtm[3246]	/* was [3][1082] */;
    extern /* Subroutine */ int dgetrf_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *), dgetri_(integer *, doublereal *,
	     integer *, integer *, doublereal *, integer *, integer *);
    static doublereal sininv;

    /* Fortran I/O blocks */
    static cilist io___47 = { 0, 0, 0, 0, 0 };
    static cilist io___48 = { 0, 0, 0, 0, 0 };


/* This routine is called alternatively to CONSTS during geometry */
/* optimization. It updates the segments on the SCAS , i.e. their */
/* areas and centers, according to a new geometry, but it doesnot create */
/* a new segmentation. The reason for using UPSURF is to smooth the total */
/* energy with respect to fluctations arisig from a fluctuating segmentation. */
/* Be aware that the use of UPSURF brings some 'hysteresis' into the */
/* Hamiltonian. */
/* UPSURF fills the A-matrix and calls the inversion routine. */
/* written by A. Klamt, Burscheider Str. 524, 5090 Leverkusen 3, Germany */
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
/*     Added to satisfy the LAPACK call to DGETRI. SJC 1/10/93 */
    /* Parameter adjustments */
    coord -= 4;

    /* Function Body */
    fdiag = sqrt(1082.) * 1.05;
    area = 0.;
    ds = sqrt(4. / solvi_1.nspa);
    c2ds = cos(ds * 2.);
    nss1 = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (ix = 1; ix <= 3; ++ix) {
/* L4: */
	    xa[ix - 1] = coord[ix + i__ * 3];
	}
	r__ = solvr_1.srad[i__ - 1];
	rm = r__ - solvr_1.rds;
	nss0 = nss1 + 1;
	if (solvi_1.iatsp[nss0 - 1] != i__) {
	    goto L1000;
	}
	ips = nss0;
L304:
	if (ips > solvi_1.nss || solvi_1.iatsp[ips - 1] != i__) {
	    goto L306;
	}
	solvi_1.nar[ips - 1] = 0;
	xsp[(ips << 2) - 4] = 0.;
	xsp[(ips << 2) - 3] = 0.;
	xsp[(ips << 2) - 2] = 0.;
	xsp[(ips << 2) - 1] = solvr_1.admat[ips + ips * 500 - 501];
	++ips;
	goto L304;
L306:
	nss1 = ips - 1;
/* TRANSFORM COSURF ACCORDING TO TM(INV) */
	i__2 = nss1;
	for (j = nss0; j <= i__2; ++j) {
	    xx[0] = solvr_1.cosurf[j * 3 - 3];
	    xx[1] = solvr_1.cosurf[j * 3 - 2];
	    xx[2] = solvr_1.cosurf[j * 3 - 1];
	    solvr_1.cosurf[j * 3 - 3] = xx[0] * solvr_1.tm[(i__ * 3 + 1) * 3 
		    - 12] + xx[1] * solvr_1.tm[(i__ * 3 + 2) * 3 - 12] + xx[2]
		     * solvr_1.tm[(i__ * 3 + 3) * 3 - 12];
	    solvr_1.cosurf[j * 3 - 2] = xx[0] * solvr_1.tm[(i__ * 3 + 1) * 3 
		    - 11] + xx[1] * solvr_1.tm[(i__ * 3 + 2) * 3 - 11] + xx[2]
		     * solvr_1.tm[(i__ * 3 + 3) * 3 - 11];
	    solvr_1.cosurf[j * 3 - 1] = xx[0] * solvr_1.tm[(i__ * 3 + 1) * 3 
		    - 10] + xx[1] * solvr_1.tm[(i__ * 3 + 2) * 3 - 10] + xx[2]
		     * solvr_1.tm[(i__ * 3 + 3) * 3 - 10];
/* L5: */
	}
/* UPDATE TM */
	nn1 = solvi_1.nn[(i__ << 1) - 2];
	nn2 = solvi_1.nn[(i__ << 1) - 1];
	if (nn1 == 0) {
	    solvr_1.tm[(i__ * 3 + 1) * 3 - 12] = 1.;
	    solvr_1.tm[(i__ * 3 + 2) * 3 - 12] = 0.;
	    solvr_1.tm[(i__ * 3 + 3) * 3 - 12] = 0.;
	} else {
	    dist1 = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
/* L6: */
/* Computing 2nd power */
		d__1 = xa[ix - 1] - coord[ix + nn1 * 3];
		dist1 += d__1 * d__1;
	    }
	    dist = 1. / sqrt(dist1);
	    solvr_1.tm[(i__ * 3 + 1) * 3 - 12] = (coord[nn1 * 3 + 1] - xa[0]) 
		    * dist;
	    solvr_1.tm[(i__ * 3 + 2) * 3 - 12] = (coord[nn1 * 3 + 2] - xa[1]) 
		    * dist;
	    solvr_1.tm[(i__ * 3 + 3) * 3 - 12] = (coord[nn1 * 3 + 3] - xa[2]) 
		    * dist;
	}
	if (nn2 == 0) {
	    solvr_1.tm[(i__ * 3 + 1) * 3 - 11] = -solvr_1.tm[(i__ * 3 + 2) * 
		    3 - 12];
	    solvr_1.tm[(i__ * 3 + 2) * 3 - 11] = solvr_1.tm[(i__ * 3 + 1) * 3 
		    - 12];
	    solvr_1.tm[(i__ * 3 + 3) * 3 - 11] = 0.;
	} else {
	    dist2 = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
/* L7: */
/* Computing 2nd power */
		d__1 = xa[ix - 1] - coord[ix + nn2 * 3];
		dist2 += d__1 * d__1;
	    }
	    dist = 1. / sqrt(dist2);
	    xx[0] = (coord[nn2 * 3 + 1] - xa[0]) * dist;
	    xx[1] = (coord[nn2 * 3 + 2] - xa[1]) * dist;
	    xx[2] = (coord[nn2 * 3 + 3] - xa[2]) * dist;
	    sp = xx[0] * solvr_1.tm[(i__ * 3 + 1) * 3 - 12] + xx[1] * 
		    solvr_1.tm[(i__ * 3 + 2) * 3 - 12] + xx[2] * solvr_1.tm[(
		    i__ * 3 + 3) * 3 - 12];
	    sininv = 1. / sqrt(1. - sp * sp);
	    solvr_1.tm[(i__ * 3 + 1) * 3 - 11] = (xx[0] - sp * solvr_1.tm[(
		    i__ * 3 + 1) * 3 - 12]) * sininv;
	    solvr_1.tm[(i__ * 3 + 2) * 3 - 11] = (xx[1] - sp * solvr_1.tm[(
		    i__ * 3 + 2) * 3 - 12]) * sininv;
	    solvr_1.tm[(i__ * 3 + 3) * 3 - 11] = (xx[2] - sp * solvr_1.tm[(
		    i__ * 3 + 3) * 3 - 12]) * sininv;
	}
	solvr_1.tm[(i__ * 3 + 1) * 3 - 10] = solvr_1.tm[(i__ * 3 + 2) * 3 - 
		12] * solvr_1.tm[(i__ * 3 + 3) * 3 - 11] - solvr_1.tm[(i__ * 
		3 + 2) * 3 - 11] * solvr_1.tm[(i__ * 3 + 3) * 3 - 12];
	solvr_1.tm[(i__ * 3 + 2) * 3 - 10] = solvr_1.tm[(i__ * 3 + 3) * 3 - 
		12] * solvr_1.tm[(i__ * 3 + 1) * 3 - 11] - solvr_1.tm[(i__ * 
		3 + 3) * 3 - 11] * solvr_1.tm[(i__ * 3 + 1) * 3 - 12];
	solvr_1.tm[(i__ * 3 + 3) * 3 - 10] = solvr_1.tm[(i__ * 3 + 1) * 3 - 
		12] * solvr_1.tm[(i__ * 3 + 2) * 3 - 11] - solvr_1.tm[(i__ * 
		3 + 1) * 3 - 11] * solvr_1.tm[(i__ * 3 + 2) * 3 - 12];
/* TRANSFORM COSURF ACCORDING TO TM */
	i__2 = nss1;
	for (j = nss0; j <= i__2; ++j) {
	    xx[0] = solvr_1.cosurf[j * 3 - 3];
	    xx[1] = solvr_1.cosurf[j * 3 - 2];
	    xx[2] = solvr_1.cosurf[j * 3 - 1];
	    solvr_1.cosurf[j * 3 - 3] = xx[0] * solvr_1.tm[(i__ * 3 + 1) * 3 
		    - 12] + xx[1] * solvr_1.tm[(i__ * 3 + 1) * 3 - 11] + xx[2]
		     * solvr_1.tm[(i__ * 3 + 1) * 3 - 10];
	    solvr_1.cosurf[j * 3 - 2] = xx[0] * solvr_1.tm[(i__ * 3 + 2) * 3 
		    - 12] + xx[1] * solvr_1.tm[(i__ * 3 + 2) * 3 - 11] + xx[2]
		     * solvr_1.tm[(i__ * 3 + 2) * 3 - 10];
	    solvr_1.cosurf[j * 3 - 1] = xx[0] * solvr_1.tm[(i__ * 3 + 3) * 3 
		    - 12] + xx[1] * solvr_1.tm[(i__ * 3 + 3) * 3 - 11] + xx[2]
		     * solvr_1.tm[(i__ * 3 + 3) * 3 - 10];
/* L35: */
	}
	for (j = 1; j <= 1082; ++j) {
	    xx[0] = dirvec_1.dirvec[j * 3 - 3];
	    xx[1] = dirvec_1.dirvec[j * 3 - 2];
	    xx[2] = dirvec_1.dirvec[j * 3 - 1];
	    for (ix = 1; ix <= 3; ++ix) {
		x = xx[0] * solvr_1.tm[(ix + i__ * 3) * 3 - 12] + xx[1] * 
			solvr_1.tm[(ix + i__ * 3) * 3 - 11] + xx[2] * 
			solvr_1.tm[(ix + i__ * 3) * 3 - 10];
		dirtm[ix + j * 3 - 4] = x;
		cobas[ix + (j + i__ * 1082) * 3 - 3250] = rm * x + xa[ix - 1];
/* L45: */
	    }
	}
	for (j = 1; j <= 1082; ++j) {
	    din[j - 1] = FALSE_;
	    for (ix = 1; ix <= 3; ++ix) {
		xx[ix - 1] = xa[ix - 1] + dirtm[ix + j * 3 - 4] * r__;
/* L2020: */
	    }
	    i__2 = molkst_1.numat;
	    for (k = 1; k <= i__2; ++k) {
		if (k == i__) {
		    goto L2040;
		}
		dist = 0.;
		for (ix = 1; ix <= 3; ++ix) {
/* Computing 2nd power */
		    d__1 = xx[ix - 1] - coord[ix + k * 3];
		    dist += d__1 * d__1;
/* L2030: */
		}
		dist = sqrt(dist) - solvr_1.srad[k - 1];
		if (dist < 0.) {
		    goto L2080;
		}
L2040:
		;
	    }
	    din[j - 1] = TRUE_;
L2080:
	    ;
	}
	for (j = 1; j <= 1082; ++j) {
	    if (! din[j - 1]) {
		goto L350;
	    }
	    spm = -1.;
	    x1 = dirtm[j * 3 - 3];
	    x2 = dirtm[j * 3 - 2];
	    x3 = dirtm[j * 3 - 1];
	    i__2 = nss1;
	    for (ips = nss0; ips <= i__2; ++ips) {
		sp = x1 * solvr_1.cosurf[ips * 3 - 3] + x2 * solvr_1.cosurf[
			ips * 3 - 2] + x3 * solvr_1.cosurf[ips * 3 - 1];
		if (sp < spm) {
		    goto L340;
		}
		spm = sp;
		ipm = ips;
L340:
		;
	    }
	    if (spm < c2ds) {
		goto L350;
	    }
	    nara = solvi_1.nar[ipm - 1] + 1;
	    nset[ipm + nara * 500 - 501] = j;
	    solvi_1.nar[ipm - 1] = nara;
	    for (ix = 1; ix <= 3; ++ix) {
/* L345: */
		xsp[ix + (ipm << 2) - 5] += dirtm[ix + j * 3 - 4];
	    }
L350:
	    ;
	}
	i__2 = nss1;
	for (ips = nss0; ips <= i__2; ++ips) {
	    dist = 0.;
	    if (solvi_1.nar[ips - 1] == 0) {
		goto L400;
	    }
	    for (ix = 1; ix <= 3; ++ix) {
		x = xsp[ix + (ips << 2) - 5];
		dist += x * x;
/* L390: */
	    }
	    dist = 1. / sqrt(dist);
	    for (ix = 1; ix <= 3; ++ix) {
/* L391: */
		solvr_1.cosurf[ix + ips * 3 - 4] = xsp[ix + (ips << 2) - 5] * 
			dist;
	    }
L400:
	    ;
	}
	i__2 = nss1;
	for (ips = nss0; ips <= i__2; ++ips) {
	    for (ix = 1; ix <= 3; ++ix) {
/* L405: */
		xsp[ix + (ips << 2) - 5] = xa[ix - 1] + solvr_1.cosurf[ix + 
			ips * 3 - 4] * rm;
	    }
/* L490: */
	}
L1000:
	;
    }

/* filling AAMAT */
    i__1 = solvi_1.nss;
    for (ips = 1; ips <= i__1; ++ips) {
	i__ = solvi_1.iatsp[ips - 1];
	ri = solvr_1.srad[i__ - 1] - solvr_1.rds;
	nari = solvi_1.nar[ips - 1];
	aa = 0.;
	i__2 = nari;
	for (k = 1; k <= i__2; ++k) {
	    j1 = nset[ips + k * 500 - 501];
	    aa += fdiag * .5;
	    x1 = dirvec_1.dirvec[j1 * 3 - 3];
	    x2 = dirvec_1.dirvec[j1 * 3 - 2];
	    x3 = dirvec_1.dirvec[j1 * 3 - 1];
	    i__3 = k - 1;
	    for (l = 1; l <= i__3; ++l) {
		j2 = nset[ips + l * 500 - 501];
/* Computing 2nd power */
		d__1 = x1 - dirvec_1.dirvec[j2 * 3 - 3];
/* Computing 2nd power */
		d__2 = x2 - dirvec_1.dirvec[j2 * 3 - 2];
/* Computing 2nd power */
		d__3 = x3 - dirvec_1.dirvec[j2 * 3 - 1];
		aa += 1. / sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3);
/* L140: */
	    }
	}
	aa = aa * 2 / ri;
	if (nari == 0) {
	    solvr_1.aamat[ips + ips * 500 - 501] = xsp[(ips << 2) - 1];
	} else {
	    solvr_1.aamat[ips + ips * 500 - 501] = aa;
	}
	for (ix = 1; ix <= 3; ++ix) {
/* L141: */
	    xa[ix - 1] = xsp[ix + (ips << 2) - 5];
	}
	i__3 = ips - 1;
	for (jps = 1; jps <= i__3; ++jps) {
	    narj = solvi_1.nar[jps - 1];
	    dist = 0.;
	    for (ix = 1; ix <= 3; ++ix) {
/* L143: */
/* Computing 2nd power */
		d__1 = xsp[ix + (jps << 2) - 5] - xa[ix - 1];
		dist += d__1 * d__1;
	    }
	    if (dist < solvr_1.disex2) {
		j = solvi_1.iatsp[jps - 1];
		aij = 0.;
		i__2 = nari;
		for (k = 1; k <= i__2; ++k) {
		    j1 = nset[ips + k * 500 - 501];
		    x1 = cobas[(j1 + i__ * 1082) * 3 - 3249];
		    x2 = cobas[(j1 + i__ * 1082) * 3 - 3248];
		    x3 = cobas[(j1 + i__ * 1082) * 3 - 3247];
		    i__4 = narj;
		    for (l = 1; l <= i__4; ++l) {
			j2 = nset[jps + l * 500 - 501];
/* Computing 2nd power */
			d__1 = cobas[(j2 + j * 1082) * 3 - 3249] - x1;
/* Computing 2nd power */
			d__2 = cobas[(j2 + j * 1082) * 3 - 3248] - x2;
/* Computing 2nd power */
			d__3 = cobas[(j2 + j * 1082) * 3 - 3247] - x3;
			aij += 1. / sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * 
				d__3);
/* L149: */
		    }
		}
	    } else {
		aij = nari * narj / sqrt(dist);
	    }
	    solvr_1.aamat[ips + jps * 500 - 501] = aij;
	    solvr_1.aamat[jps + ips * 500 - 501] = aij;
/* L169: */
	}
/* L170: */
    }
    i__1 = solvi_1.nss;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__3 = solvi_1.nss;
	for (j = 1; j <= i__3; ++j) {
/* L175: */
	    solvr_1.admat[i__ + j * 500 - 501] = solvr_1.aamat[i__ + j * 500 
		    - 501];
	}
    }
/* invert AAMAX */
/*     CALL MA22BD(AAMAT,MAXNSS,NSS,BBMAT,ERROR) */
/*     CALL INVAA(AAMAT,MAXNSS,NSS) */
    dgetrf_(&solvi_1.nss, &solvi_1.nss, solvr_1.aamat, &c__500, ipiv, &info);
    if (info != 0) {
	io___47.ciunit = *iw;
	s_wsle(&io___47);
	do_lio(&c__9, &c__1, "UPSURF: Factorization failed. INFO=", (ftnlen)
		35);
	do_lio(&c__3, &c__1, (char *)&info, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    dgetri_(&solvi_1.nss, solvr_1.aamat, &c__500, ipiv, solvr_1.bbmat, &c_b38,
	     &info);
    if (info != 0) {
	io___48.ciunit = *iw;
	s_wsle(&io___48);
	do_lio(&c__9, &c__1, "UPSURF: Inversion failed. INFO=", (ftnlen)31);
	do_lio(&c__3, &c__1, (char *)&info, (ftnlen)sizeof(integer));
	e_wsle();
	s_stop("", (ftnlen)0);
    }
    return 0;
} /* upsurf_ */

#undef cobas
#undef xsp
#undef iw


