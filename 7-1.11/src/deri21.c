/* deri21.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int deri21_(doublereal *a, integer *nvar, integer *minear, 
	integer *nfirst, doublereal *vnert, doublereal *pnert, doublereal *b, 
	integer *ncut)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, i__1, i__2;

    /* Builtin functions */
    double sqrt(doublereal);

    /* Local variables */
    static integer i__, j, l;
    extern /* Subroutine */ int mxm_(doublereal *, integer *, doublereal *, 
	    integer *, doublereal *, integer *);
    static doublereal sum, sum2, work[4];
    extern /* Subroutine */ int hqrii_(doublereal *, integer *, integer *, 
	    doublereal *, doublereal *), mtxmc_(doublereal *, integer *, 
	    doublereal *, integer *, doublereal *);
    static doublereal cutoff;

/* *********************************************************************** */

/*     LEAST-SQUARE ANALYSIS OF A SET OF NVAR POINTS {A} : */

/*     PRODUCE A SUBSET OF NCUT ORTHONORMALIZED VECTORS B, OPTIMUM IN A */
/*     LEAST-SQUARE SENSE WITH RESPECT TO THE INITIAL SPACE {A}. */
/*     EACH NEW HIERARCHIZED VECTOR B EXTRACTS A MAXIMUM PERCENTAGE FROM */
/*     THE REMAINING DISPERSION OF THE SET {A} OUT OF THE PREVIOUS */
/*     {B} SUBSPACE. */
/*   INPUT */
/*     A(MINEAR,NVAR): ORIGINAL SET {A}. */
/*     NFIRST        : MAXIMUM ALLOWED SIZE OF THE BASIS B. */
/*   OUTPUT */
/*     VNERT(NVAR)   : LOWEST EIGENVECTOR OF A'* A. */
/*     PNERT(NVAR)     : SQUARE ROOT OF THE ASSOCIATED EIGENVALUES */
/*                     IN DECREASING ORDER. */
/*     B(MINEAR,NCUT): OPTIMUM ORTHONORMALIZED SUBSET {B}. */

/* *********************************************************************** */

/*     VNERT = A' * A */
    /* Parameter adjustments */
    --pnert;
    --vnert;
    b_dim1 = *minear;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    a_dim1 = *minear;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;

    /* Function Body */
    cutoff = .85;
    sum2 = 0.;
    mtxmc_(&a[a_offset], nvar, &a[a_offset], minear, work);
    i__1 = *nvar * (*nvar + 1) / 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	work[i__ - 1] = -work[i__ - 1];
    }
/*     DIAGONALIZE IN DECREASING ORDER OF EIGENVALUES */
    if (abs(work[0]) < 1e-28 && *nvar == 1) {
	pnert[1] = sqrt(-work[0]);
	work[0] = 1e15;
	vnert[1] = 1.;
	*ncut = 1;
	goto L50;
    } else {
	hqrii_(work, nvar, nvar, &pnert[1], &vnert[1]);
/*     FIND NCUT ACCORDING TO CUTOFF, BUILD WORK = VNERT * (PNERT)**-0.5 */
	sum = 0.;
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	    sum -= pnert[i__];
	}
	l = 1;
	i__1 = *nfirst;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    sum2 -= pnert[i__] / sum;
	    pnert[i__] = sqrt(-pnert[i__]);
	    i__2 = *nvar;
	    for (j = 1; j <= i__2; ++j) {
		work[l - 1] = vnert[l] / pnert[i__];
/* L30: */
		++l;
	    }
	    if (sum2 >= cutoff) {
		*ncut = i__;
		goto L50;
	    }
/* L40: */
	}
	*ncut = *nfirst;
/*     ORTHONORMALIZED BASIS */
/*     B(MINEAR,NCUT) = A(MINEAR,NVAR)*WORK(NVAR,NCUT) */
    }
L50:
    mxm_(&a[a_offset], minear, work, nvar, &b[b_offset], ncut);
    return 0;
} /* deri21_ */

