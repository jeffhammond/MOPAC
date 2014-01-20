/* dijkl2.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int dijkl2_(doublereal *dc, integer *norbs, integer *nmos, 
	doublereal *dijkl, doublereal *wijkl, integer *nmeci)
{
    /* System generated locals */
    integer dc_dim1, dc_offset, wijkl_dim1, wijkl_dim2, wijkl_dim3, 
	    wijkl_offset, dijkl_dim1, dijkl_dim2, dijkl_offset, i__1, i__2, 
	    i__3, i__4;

    /* Local variables */
    static integer i__, j, k, l, ij, kl, ll;
    static logical lij, lkl;
    static doublereal val;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal val2;

/* *********************************************************************** */
/*     RELAXATION OF 2-ELECTRONS INTEGRALS IN M.O BASIS. */

/*   INPUT */
/*   DC(NORBS,NMOS) : C.I-ACTIVE M.O DERIVATIVES IN M.O BASIS, IN COLUMN. */
/*   NORBS          : TOTAL NUMBER OF M.O. */
/*   NMOS           : NUMBER OF C.I-ACTIVE M.O. */
/*   DIJKL(I,J,KL)  : <I(1),J(1)|K(2),L(2)> WITH */
/*                     I              OVER     ALL    M.O. */
/*                     J,KL CANONICAL OVER C.I-ACTIVE M.O. */
/*   NMECI          : MAX. SIZE OF WIJKL. (NMOS <= NMECI). */
/*   OUTPUT */
/*     WIJKL(I,J,K,L)= d< I(1),J(1) | K(2),L(2) > */
/*                   = <dI,J|K,L> + <I,dJ|K,L> + <I,J|dK,L> + <I,J|K,dL> */
/*                     WITH I,J,K,L OVER ALL C.I-ACTIVE M.O. */
/*     WRITTEN BY DANIEL LIOTARD */
/* (NOTE BY JJPS: AS THIS CODE IS HIGHLY EFFICIENT, NO CHANGES WERE MADE) */
/* *********************************************************************** */

    /* Parameter adjustments */
    dc_dim1 = *norbs;
    dc_offset = 1 + dc_dim1 * 1;
    dc -= dc_offset;
    dijkl_dim1 = *norbs;
    dijkl_dim2 = *nmos;
    dijkl_offset = 1 + dijkl_dim1 * (1 + dijkl_dim2 * 1);
    dijkl -= dijkl_offset;
    wijkl_dim1 = *nmeci;
    wijkl_dim2 = *nmeci;
    wijkl_dim3 = *nmeci;
    wijkl_offset = 1 + wijkl_dim1 * (1 + wijkl_dim2 * (1 + wijkl_dim3 * 1));
    wijkl -= wijkl_offset;

    /* Function Body */
    ij = 0;
    i__1 = *nmos;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ++ij;
	    lij = i__ == j;
	    kl = 0;
	    i__3 = i__;
	    for (k = 1; k <= i__3; ++k) {
		if (k == i__) {
		    ll = j;
		} else {
		    ll = k;
		}
		i__4 = ll;
		for (l = 1; l <= i__4; ++l) {
		    ++kl;
		    lkl = k == l;
		    val = dot_(&dc[i__ * dc_dim1 + 1], &dijkl[(j + kl * 
			    dijkl_dim2) * dijkl_dim1 + 1], norbs);
		    if (lij && lkl && j == k) {
			val *= 4.;
		    } else {
			if (lij) {
			    val *= 2.;
			} else {
			    val += dot_(&dc[j * dc_dim1 + 1], &dijkl[(i__ + 
				    kl * dijkl_dim2) * dijkl_dim1 + 1], norbs)
				    ;
			}
			val2 = dot_(&dc[k * dc_dim1 + 1], &dijkl[(l + ij * 
				dijkl_dim2) * dijkl_dim1 + 1], norbs);
			if (lkl) {
			    val += val2 * 2.;
			} else {
			    val = val + val2 + dot_(&dc[l * dc_dim1 + 1], &
				    dijkl[(k + ij * dijkl_dim2) * dijkl_dim1 
				    + 1], norbs);
			}
		    }
		    wijkl[i__ + (j + (k + l * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		    wijkl[i__ + (j + (l + k * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		    wijkl[j + (i__ + (k + l * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		    wijkl[j + (i__ + (l + k * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		    wijkl[k + (l + (i__ + j * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		    wijkl[k + (l + (j + i__ * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		    wijkl[l + (k + (i__ + j * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
/* L10: */
		    wijkl[l + (k + (j + i__ * wijkl_dim3) * wijkl_dim2) * 
			    wijkl_dim1] = val;
		}
	    }
	}
    }
    return 0;
} /* dijkl2_ */

