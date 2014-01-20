/* timer.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int timer_(char *a, ftnlen a_len)
{
    /* Initialized data */

    static logical first = TRUE_;

    /* System generated locals */
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal t0, t1, t2;
    extern doublereal second_(void);

    /* Fortran I/O blocks */
    static cilist io___5 = { 0, 6, 0, "(2X,A,A,F7.2,A,F8.2)", 0 };
    static cilist io___6 = { 0, 6, 0, "(40X,'TIME LOST:',F7.2)", 0 };


    if (first) {

/*  DEFINE THE ZERO OF TIME */

	t0 = second_();
	t1 = t0;
	first = FALSE_;
    }

/*   THE ACT OF CALLING THIS ROUTINE COSTS 0.026 SECONDS */

    t0 += .026;
    t2 = second_();
    if (i_indx(a, "BEF", a_len, (ftnlen)3) == 0 && s_cmp(a, " ", a_len, (
	    ftnlen)1) != 0) {
	s_wsfe(&io___5);
	do_fio(&c__1, a, a_len);
	do_fio(&c__1, " INTERVAL:", (ftnlen)10);
	d__1 = t2 - t1;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, " INTEGRAL:", (ftnlen)10);
	d__2 = t2 - t0;
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	s_wsfe(&io___6);
	d__1 = t2 - t1;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    t1 = t2 + .026;
    return 0;
} /* timer_ */

