/* depvar.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int depvar_(doublereal *a, integer *i__, doublereal *w, 
	integer *l)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal fact;
    extern doublereal reada_(char *, integer *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___3 = { 0, 6, 0, "('  UNIT CELL LENGTH =',F14.7,       "
	    "               ' TIMES BOND LENGTH')", 0 };


/* *********************************************************************** */

/*  IN SUBROUTINE HADDON WHEN M, THE SYMMETRY OPERATION, IS 18 DEPVAR IS */
/*  CALLED. DEPVAR SHOULD THEN CONTAIN A USER-WRITTEN SYMMETRY OPERATION. */
/*  SEE HADDON TO GET THE IDEA ON HOW TO WRITE DEPVAR. */

/* ON INPUT: */
/*           A = ARRAY OF INTERNAL COORDINATES */
/*           I = ADDRESS OF REFERENCE ATOM */
/* ON OUTPUT: */
/*           L = 1 (IF A BOND-LENGTH IS THE DEPENDENT FUNCTION) */
/*             = 2 (IF AN ANGLE IS THE DEPENDENT FUNCTION) */
/*             = 3 (IF A DIHEDRAL ANGLE IS THE DEPENDENT FUNCTION) */
/*           W = VALUE OF THE FUNCTION */

/*  NOTE:  IT IS THE WRITER'S RESPONSIBILITY TO MAKE CERTAIN THAT THE */
/*         SUBROUTINE DOES NOT CONTAIN ANY ERRORS! */
/* *********************************************************************** */
    /* Parameter adjustments */
    a -= 4;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	i__1 = i_indx(keywrd_1.keywrd, "DEPVAR", (ftnlen)241, (ftnlen)6);
	fact = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___3);
	do_fio(&c__1, (char *)&fact, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    *w = a[*i__ * 3 + 1] * fact;
    *l = 1;
    return 0;
} /* depvar_ */

