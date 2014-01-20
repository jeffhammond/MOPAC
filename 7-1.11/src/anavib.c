/* anavib.f -- translated by f2c (version 20020621).
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
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal f[90300];
} fokmat_;

#define fokmat_1 fokmat_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int anavib_(doublereal *coord, doublereal *eigs, doublereal *
	dipt, integer *n3, doublereal *vibs, doublereal *rij, doublereal *
	hess, doublereal *travel, doublereal *redmas)
{
    /* Initialized data */

    static doublereal vanrad[107] = { .32,.93,1.23,.9,.82,.77,.75,.73,.72,.71,
	    1.54,1.36,1.18,1.11,1.06,1.02,.99,.98,2.03,1.74,1.44,1.32,1.22,
	    1.18,1.17,1.17,1.16,1.15,1.17,1.25,1.26,1.22,1.2,1.16,1.14,1.12,
	    2.16,1.91,1.62,1.45,1.34,1.3,1.27,1.25,1.25,1.28,1.34,1.48,1.44,
	    1.41,1.4,1.36,1.33,1.31,2.35,1.98,1.69,1.65,1.65,1.64,1.63,1.62,
	    1.85,1.61,1.59,1.59,1.58,1.57,1.56,1.56,1.56,1.44,1.34,1.3,1.28,
	    1.26,1.27,1.3,1.34,1.49,1.48,1.47,1.46,1.46,1.45,1.45,1.45,1.45,
	    1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,1.45,
	    1.45,1.45,1.45,1.45,1.45,1.45 };

    /* System generated locals */
    integer vibs_dim1, vibs_offset, i__1, i__2, i__3, i__4, i__5;
    doublereal d__1, d__2, d__3;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static doublereal e;
    static integer i__, j, k, l;
    static doublereal x, y, z__;
    static integer i1, j1, j2, j3, i3, i2;
    static doublereal ea, eb;
    static integer ii, ij, jj;
    static doublereal xi, xj, yj, zj, yi, zi, eab;
    static integer ijf[10];
    static doublereal fij[10], ans, vdw, sum, tot;
    static logical vib1, vib2, vib3, vib4;
    static integer iline;
    static doublereal shift, radial;
    static integer linear;

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, "('1',//10X,'DESCRIPTION OF VIBRATIONS"
	    "',/)", 0 };
    static cilist io___42 = { 0, 6, 0, "(/,' VIBRATION',I4,'            ATOM"
	    " PAIR  ','    ENERGY CONTRIBUTION              RADIAL')", 0 };
    static cilist io___44 = { 0, 6, 0, "(' FREQ.   ',F9.2,6X,1A2,I2,        "
	    "       ' -- ',A2,I2, '         ',F6.1,'% (',F5.1,'%)',F18.1     "
	    " ,'%')", 0 };
    static cilist io___45 = { 0, 6, 0, "(' T-DIPOLE',F9.4,6X,1A2,I2,        "
	    "       ' -- ',A2,I2, '         ',F6.1,'%',F27.1,'%')", 0 };
    static cilist io___46 = { 0, 6, 0, "(' TRAVEL  ',F9.4,6X,1A2,I2,        "
	    "       ' -- ',A2,I2, '         ',F6.1,'%',F27.1,'%')", 0 };
    static cilist io___47 = { 0, 6, 0, "(' RED. MASS',F8.4,6X,1A2,I2,       "
	    "       ' -- ',A2,I2, '         ',F6.1,'%',F27.1,'%')", 0 };
    static cilist io___48 = { 0, 6, 0, "('                        ',1A2,I2, "
	    "       ' -- ',A2,I2, '         ',F6.1,'%',F27.1,'%')", 0 };
    static cilist io___49 = { 0, 6, 0, "(/,' VIBRATION',I4)", 0 };
    static cilist io___50 = { 0, 6, 0, "(  ' FREQ.    ',F8.2)", 0 };
    static cilist io___51 = { 0, 6, 0, "(  ' T-DIPOLE ',F8.4)", 0 };
    static cilist io___52 = { 0, 6, 0, "(  ' TRAVEL   ',F8.4)", 0 };
    static cilist io___53 = { 0, 6, 0, "(  ' RED. MASS',F8.4)", 0 };
    static cilist io___54 = { 0, 6, 0, "('1')", 0 };


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
    --travel;
    vibs_dim1 = *n3;
    vibs_offset = 1 + vibs_dim1 * 1;
    vibs -= vibs_offset;
    --dipt;
    --eigs;
    --rij;
    --hess;
    --redmas;

    /* Function Body */
    *n3 = molkst_1.numat * 3;

/*    COMPUTE INTERATOMIC DISTANCES. */

    l = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__ - 1;
	for (j = 1; j <= i__2; ++j) {
	    ++l;
/* L10: */
/* Computing 2nd power */
	    d__1 = coord[j * 3 + 1] - coord[i__ * 3 + 1];
/* Computing 2nd power */
	    d__2 = coord[j * 3 + 2] - coord[i__ * 3 + 2];
/* Computing 2nd power */
	    d__3 = coord[j * 3 + 3] - coord[i__ * 3 + 3];
	    rij[l] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 * d__3) + 1e-10;
	}
    }

/*     ANALYSE VIBRATIONS */

    s_wsfe(&io___5);
    e_wsfe();
    iline = 0;
    i__2 = *n3;
    for (k = 1; k <= i__2; ++k) {
	if ((d__1 = eigs[k], abs(d__1)) < 50.) {
	    goto L120;
	}
	vib1 = TRUE_;
	vib2 = TRUE_;
	vib3 = TRUE_;
	vib4 = TRUE_;
	j3 = 0;
	l = 0;
	tot = 0.;
	linear = 0;
	j1 = -2;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    j1 += 3;
	    i1 = -2;
	    i__3 = j - 1;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		i1 += 3;
		vdw = (vanrad[molkst_1.nat[i__ - 1] - 1] + vanrad[
			molkst_1.nat[j - 1] - 1]) * 1.5;
		++l;
		fokmat_1.f[l - 1] = 0.;
		if (rij[l] < vdw) {

/* CALCULATE ENERGY TERM BETWEEN THE TWO ATOMS */

		    eab = 0.;
		    i__4 = j1 + 2;
		    for (jj = j1; jj <= i__4; ++jj) {
			i__5 = i1 + 2;
			for (ii = i1; ii <= i__5; ++ii) {
/* L20: */
			    eab += vibs[jj + k * vibs_dim1] * hess[jj * (jj - 
				    1) / 2 + ii] * vibs[ii + k * vibs_dim1];
			}
		    }
		    eb = 0.;
		    i__5 = j1 + 2;
		    for (jj = j1; jj <= i__5; ++jj) {
			i__4 = jj;
			for (ii = j1; ii <= i__4; ++ii) {
/* L30: */
			    eb += vibs[jj + k * vibs_dim1] * hess[jj * (jj - 
				    1) / 2 + ii] * vibs[ii + k * vibs_dim1] * 
				    2.;
			}
/* L40: */
			eb -= vibs[jj + k * vibs_dim1] * hess[jj * (jj + 1) / 
				2] * vibs[jj + k * vibs_dim1];
		    }
		    ea = 0.;
		    i__5 = i1 + 2;
		    for (jj = i1; jj <= i__5; ++jj) {
			i__4 = jj;
			for (ii = i1; ii <= i__4; ++ii) {
/* L50: */
			    ea += vibs[jj + k * vibs_dim1] * hess[jj * (jj - 
				    1) / 2 + ii] * vibs[ii + k * vibs_dim1] * 
				    2.;
			}
/* L60: */
			ea -= vibs[jj + k * vibs_dim1] * hess[jj * (jj + 1) / 
				2] * vibs[jj + k * vibs_dim1];
		    }
		    ++linear;
		    fokmat_1.f[l - 1] = ea + eab * 2. + eb;
		    tot += fokmat_1.f[l - 1];
		}
/* L70: */
	    }
	}

/*  NOW TO SORT F INTO DECENDING ORDER */

	for (i__ = 1; i__ <= 10; ++i__) {
	    sum = -100.;
	    i__3 = l;
	    for (j = 1; j <= i__3; ++j) {
		if ((d__1 = fokmat_1.f[j - 1], abs(d__1)) > sum) {
		    jj = j;
		    sum = (d__1 = fokmat_1.f[j - 1], abs(d__1));
		}
/* L80: */
	    }
	    if (sum < 0.) {
		goto L100;
	    }
	    fij[i__ - 1] = sum;
	    fokmat_1.f[jj - 1] = -1e-5;
	    ijf[i__ - 1] = jj;
/* #      WRITE(6,*)FIJ(I),IJF(I) */
/* L90: */
	}
	i__ = 10;
L100:
	linear = i__;
	sum = 1. / (tot + 1e-8);
	i__3 = linear;
	for (ij = 1; ij <= i__3; ++ij) {
	    j = (integer) ((sqrt(ijf[ij - 1] * 8. + 1.) + .99) * .5);
	    i__ = ijf[ij - 1] - j * (j - 1) / 2;
	    ++j;
	    xj = coord[j * 3 + 1];
	    yj = coord[j * 3 + 2];
	    zj = coord[j * 3 + 3];
	    j1 = j * 3 - 2;
	    j2 = j1 + 1;
	    j3 = j2 + 1;
	    i3 = 0;
	    xi = coord[i__ * 3 + 1];
	    yi = coord[i__ * 3 + 2];
	    zi = coord[i__ * 3 + 3];
	    i1 = i__ * 3 - 2;
	    i2 = i1 + 1;
	    i3 = i2 + 1;
	    x = vibs[j1 + k * vibs_dim1] - vibs[i1 + k * vibs_dim1];
	    y = vibs[j2 + k * vibs_dim1] - vibs[i2 + k * vibs_dim1];
	    z__ = vibs[j3 + k * vibs_dim1] - vibs[i3 + k * vibs_dim1];
	    e = fij[ij - 1] * sum * 100.;
/* #            IF(ABS(E).GT.110)GOTO 120 */
	    shift = x * x + y * y + z__ * z__ + 1e-30;
	    if (abs(e) > 10. || ij < 5 && abs(e) > .1f) {
		shift = sqrt(shift);
/* Computing 2nd power */
		d__1 = (x * (xi - xj) + y * (yi - yj) + z__ * (zi - zj)) / (
			shift * rij[ijf[ij - 1]]);
		radial = d__1 * d__1 * 100.;
		if (vib1) {
		    s_wsfe(&io___42);
		    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
		    e_wsfe();
		    ans = sqrt(fij[ij - 1] * 1e5 * 6.023e23) * 100. / 
			    188369736400. / eigs[k];
/* Computing MIN */
		    d__1 = 999.9, d__2 = max(-99.9,ans);
		    ans = min(d__1,d__2);
		    s_wsfe(&io___44);
		    do_fio(&c__1, (char *)&eigs[k], (ftnlen)sizeof(doublereal)
			    );
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 
			    1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[j - 1] - 1 
			    << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&ans, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&radial, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
/* #      WRITE(6,*)ANS */
		    vib1 = FALSE_;
		} else if (vib2) {
		    vib2 = FALSE_;
		    s_wsfe(&io___45);
		    do_fio(&c__1, (char *)&dipt[k], (ftnlen)sizeof(doublereal)
			    );
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 
			    1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[j - 1] - 1 
			    << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&radial, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
		} else if (vib3) {
		    vib3 = FALSE_;
		    s_wsfe(&io___46);
		    do_fio(&c__1, (char *)&travel[k], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 
			    1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[j - 1] - 1 
			    << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&radial, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
		} else if (vib4) {
		    vib4 = FALSE_;
		    s_wsfe(&io___47);
		    do_fio(&c__1, (char *)&redmas[k], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 
			    1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[j - 1] - 1 
			    << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&radial, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
		} else {
		    ++iline;
		    s_wsfe(&io___48);
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 
			    1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[j - 1] - 1 
			    << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&e, (ftnlen)sizeof(doublereal));
		    do_fio(&c__1, (char *)&radial, (ftnlen)sizeof(doublereal))
			    ;
		    e_wsfe();
		}
	    }
/* L110: */
	}
	iline += 6;
	if (vib1) {
	    s_wsfe(&io___49);
	    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	if (vib1) {
	    s_wsfe(&io___50);
	    do_fio(&c__1, (char *)&eigs[k], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (vib2) {
	    s_wsfe(&io___51);
	    do_fio(&c__1, (char *)&dipt[k], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (vib3) {
	    s_wsfe(&io___52);
	    do_fio(&c__1, (char *)&travel[k], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (vib4) {
	    s_wsfe(&io___53);
	    do_fio(&c__1, (char *)&redmas[k], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (iline > 52) {
	    iline = 0;
	    s_wsfe(&io___54);
	    e_wsfe();
	}
L120:
	;
    }
    return 0;
} /* anavib_ */

