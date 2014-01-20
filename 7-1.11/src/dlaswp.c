/* dlaswp.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dlaswp_(integer *n, doublereal *a, integer *lda, integer 
	*k1, integer *k2, integer *ipiv, integer *incx)
{
    /* System generated locals */
    integer a_dim1, a_offset, i__1;

    /* Local variables */
    static integer i__, ip, ix;
    extern /* Subroutine */ int dswap_(integer *, doublereal *, integer *, 
	    doublereal *, integer *);


/*  -- LAPACK AUXILIARY ROUTINE (VERSION 1.0B) -- */
/*     UNIV. OF TENNESSEE, UNIV. OF CALIFORNIA BERKELEY, NAG LTD., */
/*     COURANT INSTITUTE, ARGONNE NATIONAL LAB, AND RICE UNIVERSITY */
/*     OCTOBER 31, 1992 */

/*     .. SCALAR ARGUMENTS .. */
/*     .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DLASWP PERFORMS A SERIES OF ROW INTERCHANGES ON THE MATRIX A. */
/*  ONE ROW INTERCHANGE IS INITIATED FOR EACH OF ROWS K1 THROUGH K2 OF A. */

/*  ARGUMENTS */
/*  ========= */

/*  N       (INPUT) INTEGER */
/*          THE NUMBER OF COLUMNS OF THE MATRIX A. */

/*  A       (INPUT/OUTPUT) DOUBLE PRECISION ARRAY, DIMENSION (LDA,N) */
/*          ON ENTRY, THE MATRIX OF COLUMN DIMENSION N TO WHICH THE ROW */
/*          INTERCHANGES WILL BE APPLIED. */
/*          ON EXIT, THE PERMUTED MATRIX. */

/*  LDA     (INPUT) INTEGER */
/*          THE LEADING DIMENSION OF THE ARRAY A. */

/*  K1      (INPUT) INTEGER */
/*          THE FIRST ELEMENT OF IPIV FOR WHICH A ROW INTERCHANGE WILL */
/*          BE DONE. */

/*  K2      (INPUT) INTEGER */
/*          THE LAST ELEMENT OF IPIV FOR WHICH A ROW INTERCHANGE WILL */
/*          BE DONE. */

/*  IPIV    (INPUT) INTEGER ARRAY, DIMENSION (M*ABS(INCX)) */
/*          THE VECTOR OF PIVOT INDICES.  ONLY THE ELEMENTS IN POSITIONS */
/*          K1 THROUGH K2 OF IPIV ARE ACCESSED. */
/*          IPIV(K) = L IMPLIES ROWS K AND L ARE TO BE INTERCHANGED. */

/*  INCX    (INPUT) INTEGER */
/*          THE INCREMENT BETWEEN SUCCESSIVE VALUES OF IPIV.  IF IPIV */
/*          IS NEGATIVE, THE PIVOTS ARE APPLIED IN REVERSE ORDER. */

/* ===================================================================== */

/*     .. LOCAL SCALARS .. */
/*     .. */
/*     .. EXTERNAL SUBROUTINES .. */
/*     .. */
/*     .. EXECUTABLE STATEMENTS .. */

/*     INTERCHANGE ROW I WITH ROW IPIV(I) FOR EACH OF ROWS K1 THROUGH K2. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --ipiv;

    /* Function Body */
    if (*incx == 0) {
	return 0;
    }
    if (*incx > 0) {
	ix = *k1;
    } else {
	ix = (1 - *k2) * *incx + 1;
    }
    if (*incx == 1) {
	i__1 = *k2;
	for (i__ = *k1; i__ <= i__1; ++i__) {
	    ip = ipiv[i__];
	    if (ip != i__) {
		dswap_(n, &a[i__ + a_dim1], lda, &a[ip + a_dim1], lda);
	    }
/* L10: */
	}
    } else if (*incx > 1) {
	i__1 = *k2;
	for (i__ = *k1; i__ <= i__1; ++i__) {
	    ip = ipiv[ix];
	    if (ip != i__) {
		dswap_(n, &a[i__ + a_dim1], lda, &a[ip + a_dim1], lda);
	    }
	    ix += *incx;
/* L20: */
	}
    } else if (*incx < 0) {
	i__1 = *k1;
	for (i__ = *k2; i__ >= i__1; --i__) {
	    ip = ipiv[ix];
	    if (ip != i__) {
		dswap_(n, &a[i__ + a_dim1], lda, &a[ip + a_dim1], lda);
	    }
	    ix += *incx;
/* L30: */
	}
    }

    return 0;

/*     END OF DLASWP */

} /* dlaswp_ */

