/* dgemm.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dgemm_(char *transa, char *transb, integer *m, integer *
	n, integer *k, doublereal *alpha, doublereal *a, integer *lda, 
	doublereal *b, integer *ldb, doublereal *beta, doublereal *c__, 
	integer *ldc, ftnlen transa_len, ftnlen transb_len)
{
    /* System generated locals */
    integer a_dim1, a_offset, b_dim1, b_offset, c_dim1, c_offset, i__1, i__2, 
	    i__3;

    /* Local variables */
    static integer i__, j, l, info;
    static logical nota, notb;
    static doublereal temp;
    static integer ncola;
    extern logical lsame_(char *, char *, ftnlen, ftnlen);
    static integer nrowa, nrowb;
    extern /* Subroutine */ int xerbla_(char *, integer *, ftnlen);

/*     .. SCALAR ARGUMENTS .. */
/*     .. ARRAY ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  DGEMM  PERFORMS ONE OF THE MATRIX-MATRIX OPERATIONS */

/*     C := ALPHA*OP( A )*OP( B ) + BETA*C, */

/*  WHERE  OP( X ) IS ONE OF */

/*     OP( X ) = X   OR   OP( X ) = X', */

/*  ALPHA AND BETA ARE SCALARS, AND A, B AND C ARE MATRICES, WITH OP( A ) */
/*  AN M BY K MATRIX,  OP( B )  A  K BY N MATRIX AND  C AN M BY N MATRIX. */

/*  PARAMETERS */
/*  ========== */

/*  TRANSA - CHARACTER*1. */
/*           ON ENTRY, TRANSA SPECIFIES THE FORM OF OP( A ) TO BE USED IN */
/*           THE MATRIX MULTIPLICATION AS FOLLOWS: */

/*              TRANSA = 'N' OR 'N',  OP( A ) = A. */

/*              TRANSA = 'T' OR 'T',  OP( A ) = A'. */

/*              TRANSA = 'C' OR 'C',  OP( A ) = A'. */

/*           UNCHANGED ON EXIT. */

/*  TRANSB - CHARACTER*1. */
/*           ON ENTRY, TRANSB SPECIFIES THE FORM OF OP( B ) TO BE USED IN */
/*           THE MATRIX MULTIPLICATION AS FOLLOWS: */

/*              TRANSB = 'N' OR 'N',  OP( B ) = B. */

/*              TRANSB = 'T' OR 'T',  OP( B ) = B'. */

/*              TRANSB = 'C' OR 'C',  OP( B ) = B'. */

/*           UNCHANGED ON EXIT. */

/*  M      - INTEGER. */
/*           ON ENTRY,  M  SPECIFIES  THE NUMBER  OF ROWS  OF THE  MATRIX */
/*           OP( A )  AND OF THE  MATRIX  C.  M  MUST  BE AT LEAST  ZERO. */
/*           UNCHANGED ON EXIT. */

/*  N      - INTEGER. */
/*           ON ENTRY,  N  SPECIFIES THE NUMBER  OF COLUMNS OF THE MATRIX */
/*           OP( B ) AND THE NUMBER OF COLUMNS OF THE MATRIX C. N MUST BE */
/*           AT LEAST ZERO. */
/*           UNCHANGED ON EXIT. */

/*  K      - INTEGER. */
/*           ON ENTRY,  K  SPECIFIES  THE NUMBER OF COLUMNS OF THE MATRIX */
/*           OP( A ) AND THE NUMBER OF ROWS OF THE MATRIX OP( B ). K MUST */
/*           BE AT LEAST  ZERO. */
/*           UNCHANGED ON EXIT. */

/*  ALPHA  - DOUBLE PRECISION. */
/*           ON ENTRY, ALPHA SPECIFIES THE SCALAR ALPHA. */
/*           UNCHANGED ON EXIT. */

/*  A      - DOUBLE PRECISION ARRAY OF DIMENSION ( LDA, KA ), WHERE KA IS */
/*           K  WHEN  TRANSA = 'N' OR 'N',  AND IS  M  OTHERWISE. */
/*           BEFORE ENTRY WITH  TRANSA = 'N' OR 'N',  THE LEADING  M BY K */
/*           PART OF THE ARRAY  A  MUST CONTAIN THE MATRIX  A,  OTHERWISE */
/*           THE LEADING  K BY M  PART OF THE ARRAY  A  MUST CONTAIN  THE */
/*           MATRIX A. */
/*           UNCHANGED ON EXIT. */

/*  LDA    - INTEGER. */
/*           ON ENTRY, LDA SPECIFIES THE FIRST DIMENSION OF A AS DECLARED */
/*           IN THE CALLING (SUB) PROGRAM. WHEN  TRANSA = 'N' OR 'N' THEN */
/*           LDA MUST BE AT LEAST  MAX( 1, M ), OTHERWISE  LDA MUST BE AT */
/*           LEAST  MAX( 1, K ). */
/*           UNCHANGED ON EXIT. */

/*  B      - DOUBLE PRECISION ARRAY OF DIMENSION ( LDB, KB ), WHERE KB IS */
/*           N  WHEN  TRANSB = 'N' OR 'N',  AND IS  K  OTHERWISE. */
/*           BEFORE ENTRY WITH  TRANSB = 'N' OR 'N',  THE LEADING  K BY N */
/*           PART OF THE ARRAY  B  MUST CONTAIN THE MATRIX  B,  OTHERWISE */
/*           THE LEADING  N BY K  PART OF THE ARRAY  B  MUST CONTAIN  THE */
/*           MATRIX B. */
/*           UNCHANGED ON EXIT. */

/*  LDB    - INTEGER. */
/*           ON ENTRY, LDB SPECIFIES THE FIRST DIMENSION OF B AS DECLARED */
/*           IN THE CALLING (SUB) PROGRAM. WHEN  TRANSB = 'N' OR 'N' THEN */
/*           LDB MUST BE AT LEAST  MAX( 1, K ), OTHERWISE  LDB MUST BE AT */
/*           LEAST  MAX( 1, N ). */
/*           UNCHANGED ON EXIT. */

/*  BETA   - DOUBLE PRECISION. */
/*           ON ENTRY,  BETA  SPECIFIES THE SCALAR  BETA.  WHEN  BETA  IS */
/*           SUPPLIED AS ZERO THEN C NEED NOT BE SET ON INPUT. */
/*           UNCHANGED ON EXIT. */

/*  C      - DOUBLE PRECISION ARRAY OF DIMENSION ( LDC, N ). */
/*           BEFORE ENTRY, THE LEADING  M BY N  PART OF THE ARRAY  C MUST */
/*           CONTAIN THE MATRIX  C,  EXCEPT WHEN  BETA  IS ZERO, IN WHICH */
/*           CASE C NEED NOT BE SET ON ENTRY. */
/*           ON EXIT, THE ARRAY  C  IS OVERWRITTEN BY THE  M BY N  MATRIX */
/*           ( ALPHA*OP( A )*OP( B ) + BETA*C ). */

/*  LDC    - INTEGER. */
/*           ON ENTRY, LDC SPECIFIES THE FIRST DIMENSION OF C AS DECLARED */
/*           IN  THE  CALLING  (SUB)  PROGRAM.   LDC  MUST  BE  AT  LEAST */
/*           MAX( 1, M ). */
/*           UNCHANGED ON EXIT. */


/*  LEVEL 3 BLAS ROUTINE. */

/*  -- WRITTEN ON 8-FEBRUARY-1989. */
/*     JACK DONGARRA, ARGONNE NATIONAL LABORATORY. */
/*     IAIN DUFF, AERE HARWELL. */
/*     JEREMY DU CROZ, NUMERICAL ALGORITHMS GROUP LTD. */
/*     SVEN HAMMARLING, NUMERICAL ALGORITHMS GROUP LTD. */


/*     .. EXTERNAL FUNCTIONS .. */
/*     .. EXTERNAL SUBROUTINES .. */
/*     .. INTRINSIC FUNCTIONS .. */
/*     .. LOCAL SCALARS .. */
/*     .. PARAMETERS .. */
/*     .. */
/*     .. EXECUTABLE STATEMENTS .. */

/*     SET  NOTA  AND  NOTB  AS  TRUE IF  A  AND  B  RESPECTIVELY ARE NOT */
/*     TRANSPOSED AND SET  NROWA, NCOLA AND  NROWB  AS THE NUMBER OF ROWS */
/*     AND  COLUMNS OF  A  AND THE  NUMBER OF  ROWS  OF  B  RESPECTIVELY. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    b_dim1 = *ldb;
    b_offset = 1 + b_dim1 * 1;
    b -= b_offset;
    c_dim1 = *ldc;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;

    /* Function Body */
    nota = lsame_(transa, "N", (ftnlen)1, (ftnlen)1);
    notb = lsame_(transb, "N", (ftnlen)1, (ftnlen)1);
    if (nota) {
	nrowa = *m;
	ncola = *k;
    } else {
	nrowa = *k;
	ncola = *m;
    }
    if (notb) {
	nrowb = *k;
    } else {
	nrowb = *n;
    }

/*     TEST THE INPUT PARAMETERS. */

    info = 0;
    if (! nota && ! lsame_(transa, "C", (ftnlen)1, (ftnlen)1) && ! lsame_(
	    transa, "T", (ftnlen)1, (ftnlen)1)) {
	info = 1;
    } else if (! notb && ! lsame_(transb, "C", (ftnlen)1, (ftnlen)1) && ! 
	    lsame_(transb, "T", (ftnlen)1, (ftnlen)1)) {
	info = 2;
    } else if (*m < 0) {
	info = 3;
    } else if (*n < 0) {
	info = 4;
    } else if (*k < 0) {
	info = 5;
    } else if (*lda < max(1,nrowa)) {
	info = 8;
    } else if (*ldb < max(1,nrowb)) {
	info = 10;
    } else if (*ldc < max(1,*m)) {
	info = 13;
    }
    if (info != 0) {
	xerbla_("DGEMM ", &info, (ftnlen)6);
	return 0;
    }

/*     QUICK RETURN IF POSSIBLE. */

    if (*m == 0 || *n == 0 || (*alpha == 0. || *k == 0) && *beta == 1.) {
	return 0;
    }

/*     AND IF  ALPHA.EQ.ZERO. */

    if (*alpha == 0.) {
	if (*beta == 0.) {
	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    c__[i__ + j * c_dim1] = 0.;
/* L10: */
		}
/* L20: */
	    }
	} else {
	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
/* L30: */
		}
/* L40: */
	    }
	}
	return 0;
    }

/*     START THE OPERATIONS. */

    if (notb) {
	if (nota) {

/*           FORM  C := ALPHA*A*B + BETA*C. */

	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		if (*beta == 0.) {
		    i__2 = *m;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			c__[i__ + j * c_dim1] = 0.;
/* L50: */
		    }
		} else if (*beta != 1.) {
		    i__2 = *m;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
/* L60: */
		    }
		}
		i__2 = *k;
		for (l = 1; l <= i__2; ++l) {
		    if (b[l + j * b_dim1] != 0.) {
			temp = *alpha * b[l + j * b_dim1];
			i__3 = *m;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    c__[i__ + j * c_dim1] += temp * a[i__ + l * 
				    a_dim1];
/* L70: */
			}
		    }
/* L80: */
		}
/* L90: */
	    }
	} else {

/*           FORM  C := ALPHA*A'*B + BETA*C */

	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    temp = 0.;
		    i__3 = *k;
		    for (l = 1; l <= i__3; ++l) {
			temp += a[l + i__ * a_dim1] * b[l + j * b_dim1];
/* L100: */
		    }
		    if (*beta == 0.) {
			c__[i__ + j * c_dim1] = *alpha * temp;
		    } else {
			c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[
				i__ + j * c_dim1];
		    }
/* L110: */
		}
/* L120: */
	    }
	}
    } else {
	if (nota) {

/*           FORM  C := ALPHA*A*B' + BETA*C */

	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		if (*beta == 0.) {
		    i__2 = *m;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			c__[i__ + j * c_dim1] = 0.;
/* L130: */
		    }
		} else if (*beta != 1.) {
		    i__2 = *m;
		    for (i__ = 1; i__ <= i__2; ++i__) {
			c__[i__ + j * c_dim1] = *beta * c__[i__ + j * c_dim1];
/* L140: */
		    }
		}
		i__2 = *k;
		for (l = 1; l <= i__2; ++l) {
		    if (b[j + l * b_dim1] != 0.) {
			temp = *alpha * b[j + l * b_dim1];
			i__3 = *m;
			for (i__ = 1; i__ <= i__3; ++i__) {
			    c__[i__ + j * c_dim1] += temp * a[i__ + l * 
				    a_dim1];
/* L150: */
			}
		    }
/* L160: */
		}
/* L170: */
	    }
	} else {

/*           FORM  C := ALPHA*A'*B' + BETA*C */

	    i__1 = *n;
	    for (j = 1; j <= i__1; ++j) {
		i__2 = *m;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    temp = 0.;
		    i__3 = *k;
		    for (l = 1; l <= i__3; ++l) {
			temp += a[l + i__ * a_dim1] * b[j + l * b_dim1];
/* L180: */
		    }
		    if (*beta == 0.) {
			c__[i__ + j * c_dim1] = *alpha * temp;
		    } else {
			c__[i__ + j * c_dim1] = *alpha * temp + *beta * c__[
				i__ + j * c_dim1];
		    }
/* L190: */
		}
/* L200: */
	    }
	}
    }

    return 0;

/*     END OF DGEMM . */

} /* dgemm_ */

