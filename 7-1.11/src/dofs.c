/* dofs.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int dofs_(doublereal *eref, integer *mono3, integer *n, 
	doublereal *dd, integer *m, doublereal *bottom, doublereal *top)
{
    /* System generated locals */
    integer eref_dim1, eref_offset, i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal a, b;
    static integer i__, j, k, l;
    static doublereal x;
    static integer ii;
    static doublereal range, partj, partk, spread;

    /* Fortran I/O blocks */
    static cilist io___13 = { 0, 6, 0, "(A)", 0 };
    static cilist io___14 = { 0, 6, 0, "(F9.2,F12.6)", 0 };


/* *********************************************************************** */
/*                                                                      * */
/* DOFS FORMS A NORMALISED, SLIGHTLY SMOOTHED DENSITY OF STATES FOR A   * */
/*      1-D DENSITY OF STATES                                           * */
/*  ON INPUT EREF = REFERENCE ENERGY LEVELS                             * */
/*           P    = POPULATION OF ENERGY LEVELS (=1 FOR ENERGY D.O.S.   * */
/*                  OR ATOMIC ORBITAL POPULATION FOR PARTIAL D.O.S.)    * */
/*           N    = NUMBER OF ENERGY LEVELS SUPPLIED                    * */
/*           M    = SIZE OF D.O.S. VECTOR                               * */
/*           D    = ARRAY TO HOLD D.O.S.                                * */
/*           BOTTOM = BOTTOM OF D.O.S. VECTOR                           * */
/*           TOP    = TOP OF D.O.S. VECTOR                              * */
/*                                                                      * */
/*   ON OUTPUT D = DENSITY OF STATES.  THIS ANALYSES IS INDEPENDENT OF N* */
/*                 ROUGHNESS WILL OCCUR IF N < CA. 30.                  * */
/*                                                                      * */
/* *********************************************************************** */

/*  FIRST, EMPTY THE DENSITY-OF-STATES (DOS) BINS */

    /* Parameter adjustments */
    eref_dim1 = *mono3;
    eref_offset = 1 + eref_dim1 * 1;
    eref -= eref_offset;
    --dd;

    /* Function Body */
    for (i__ = 1; i__ <= 500; ++i__) {
/* L10: */
	dd[i__] = 0.;
    }

/*   SPREAD OUT THE ENERGIES OVER THE ENERGY SPECTRUM, TOP TO BOTTOM */

    range = (*m + 1) / (*top - *bottom);
    i__1 = *mono3;
    for (j = 1; j <= i__1; ++j) {
	i__2 = *n;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    x = eref[j + i__ * eref_dim1];
	    if (x < *bottom || x > *top) {
		x = -1e7;
	    }
/* L20: */
	    eref[j + i__ * eref_dim1] = (x - *bottom) * range;
	}
    }
    i__2 = *mono3;
    for (ii = 1; ii <= i__2; ++ii) {
	i__1 = *n;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    b = eref[ii + (i__ - 1) * eref_dim1];
	    if (b < 1.) {
		goto L40;
	    }
	    a = eref[ii + i__ * eref_dim1];
	    if (a < 1.) {
		goto L40;
	    }
	    if (b > a) {
		x = b;
		b = a;
		a = x;
	    }
	    j = (integer) b;
	    k = (integer) a;

/* IF J EQUALS K THE INTERVAL FALLS WITHIN ONE BIN */

	    if (j == k) {
		dd[k] += 1.;
	    } else {
		spread = 1. / (a - b + 1e-12);
		partj = (j + 1 - b) * spread;
		partk = (a - k) * spread;
		dd[j] += partj;
		dd[k] += partk;

/* IF K EQUALS J+1 THE INTERVAL STRADDLES TWO BINS */

		if (k != j + 1) {

/* IF K IS GREATER THAN J+1 THE INTERVAL COVERS MORE THAN TWO BINS */

		    ++j;
		    --k;
		    i__3 = k;
		    for (l = j; l <= i__3; ++l) {
/* L30: */
			dd[l] += spread;
		    }
		}
	    }
L40:
	    ;
	}
    }
    x = *m / ((*n - 1) * (*top - *bottom));
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	dd[i__] *= x;
    }
    s_wsfe(&io___13);
    do_fio(&c__1, " NORMALIZED DENSITY OF STATES", (ftnlen)29);
    e_wsfe();

/*  THE FIRST 'BIN' HAS LOWER BOUND AT BOTTOM AND UPPER BOUND */
/*  AT BOTTOM+RANGE, THEREFORE THE FIRST 'BIN' IS FOR BOTTOM+0.5*RANGE */
/*  THE LAST 'BIN' HAS BOUNDS TOP-RANGE AND TOP, */
/*  THEREFOR THE LAST 'BIN' IS FOR TOP-0.5*RANGE */
    range = *m / (*top - *bottom);
    i__1 = *m;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L60: */
	s_wsfe(&io___14);
	d__1 = *bottom + (i__ - .5) / range;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&dd[i__], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    return 0;
} /* dofs_ */

