/* perm.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int perm_(integer *iperm, integer *nels, integer *nmos, 
	integer *maxmos, integer *nperms)
{
    /* System generated locals */
    integer iperm_dim1, iperm_offset, i__1, i__2, i__3, i__4, i__5, i__6, 
	    i__7, i__8, i__9, i__10, i__11, i__12, i__13, i__14, i__15, i__16,
	     i__17, i__18, i__19, i__20, i__21, i__22, i__23, i__24, i__25;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, i12, 
	    nel[20], iadd[20];

    /* Fortran I/O blocks */
    static cilist io___1 = { 0, 6, 0, "(' NUMBER OF PARTICLES,',I3,' GREATER"
	    " THAN NO. ', 'OF STATES,',I3)", 0 };
    static cilist io___18 = { 0, 6, 0, "(' NUMBER OF PERMUTATIONS TOO GREAT,"
	    " LIMIT 60')", 0 };


/* *********************************************************************** */

/*  PERM PERMUTES NELS ENTITIES AMONG NMOS LOCATIONS. THE ENTITIES AND */
/*       LOCATIONS ARE EACH INDISTINGUISHABLE. THE PAULI EXCLUSION */
/*       PRINCIPLE IS FOLLOWED. THE NUMBER OF STATES PRODUCED IS GIVEN */
/*       BY NMOS!/(NELS!*(NMOS-NELS)!). */
/* ON INPUT: NELS  = NUMBER OF INDISTINGUISHABLE ENTITIES */
/*           NMOS  = NUMBER OF INDISTINGUISHABLE LOCATIONS */

/* ON OUTPUT IPERM = ARRAY OF PERMUTATIONS, A 0 INDICATES NO ENTITY, */
/*                   A 1 INDICATES AN ENTITY. */
/*           NPERM = NUMBER OF PERMUTATIONS. */

/* *********************************************************************** */
    /* Parameter adjustments */
    iperm_dim1 = *maxmos;
    iperm_offset = 1 + iperm_dim1 * 1;
    iperm -= iperm_offset;

    /* Function Body */
    if (*nels > *nmos) {
	s_wsfe(&io___1);
	do_fio(&c__1, (char *)&(*nels), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&(*nmos), (ftnlen)sizeof(integer));
	e_wsfe();
	*nperms = 0;
	return 0;
    }
    *nperms = 1;
    for (i__ = 1; i__ <= 20; ++i__) {
/* L10: */
	nel[i__ - 1] = 1000;
    }
    i__1 = *nels;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	nel[i__ - 1] = 1;
    }
    i__1 = *nmos;
    i__2 = nel[11];
    for (i12 = *nels - 11; i__2 < 0 ? i12 >= i__1 : i12 <= i__1; i12 += i__2) 
	    {
	iadd[11] = i12;
	i__3 = *nmos;
	i__4 = nel[10];
	for (i11 = i12 + 1; i__4 < 0 ? i11 >= i__3 : i11 <= i__3; i11 += i__4)
		 {
	    iadd[10] = i11;
	    i__5 = *nmos;
	    i__6 = nel[9];
	    for (i10 = i11 + 1; i__6 < 0 ? i10 >= i__5 : i10 <= i__5; i10 += 
		    i__6) {
		iadd[9] = i10;
		i__7 = *nmos;
		i__8 = nel[8];
		for (i9 = i10 + 1; i__8 < 0 ? i9 >= i__7 : i9 <= i__7; i9 += 
			i__8) {
		    iadd[8] = i9;
		    i__9 = *nmos;
		    i__10 = nel[7];
		    for (i8 = i9 + 1; i__10 < 0 ? i8 >= i__9 : i8 <= i__9; i8 
			    += i__10) {
			iadd[7] = i8;
			i__11 = *nmos;
			i__12 = nel[6];
			for (i7 = i8 + 1; i__12 < 0 ? i7 >= i__11 : i7 <= 
				i__11; i7 += i__12) {
			    iadd[6] = i7;
			    i__13 = *nmos;
			    i__14 = nel[5];
			    for (i6 = i7 + 1; i__14 < 0 ? i6 >= i__13 : i6 <= 
				    i__13; i6 += i__14) {
				iadd[5] = i6;
				i__15 = *nmos;
				i__16 = nel[4];
				for (i5 = i6 + 1; i__16 < 0 ? i5 >= i__15 : 
					i5 <= i__15; i5 += i__16) {
				    iadd[4] = i5;
				    i__17 = *nmos;
				    i__18 = nel[3];
				    for (i4 = i5 + 1; i__18 < 0 ? i4 >= i__17 
					    : i4 <= i__17; i4 += i__18) {
					iadd[3] = i4;
					i__19 = *nmos;
					i__20 = nel[2];
					for (i3 = i4 + 1; i__20 < 0 ? i3 >= 
						i__19 : i3 <= i__19; i3 += 
						i__20) {
					    iadd[2] = i3;
					    i__21 = *nmos;
					    i__22 = nel[1];
					    for (i2 = i3 + 1; i__22 < 0 ? i2 
						    >= i__21 : i2 <= i__21; 
						    i2 += i__22) {
			  iadd[1] = i2;
			  i__23 = *nmos;
			  i__24 = nel[0];
			  for (i1 = i2 + 1; i__24 < 0 ? i1 >= i__23 : i1 <= 
				  i__23; i1 += i__24) {
			      iadd[0] = i1;
			      i__25 = *nmos;
			      for (j = 1; j <= i__25; ++j) {
/* L30: */
				  iperm[j + *nperms * iperm_dim1] = 0;
			      }
			      i__25 = *nels;
			      for (j = 1; j <= i__25; ++j) {
/* L40: */
				  iperm[iadd[j - 1] + *nperms * iperm_dim1] = 
					  1;
			      }
			      ++(*nperms);
			      if (*nperms > 61) {
				  s_wsfe(&io___18);
				  e_wsfe();
				  goto L60;
			      }
/* L50: */
			  }
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
L60:
    --(*nperms);
    return 0;
} /* perm_ */

