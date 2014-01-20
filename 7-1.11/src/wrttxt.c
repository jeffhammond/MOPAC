/* wrttxt.f -- translated by f2c (version 20020621).
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
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int wrttxt_(integer *iprt)
{
    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, "(A)", 0 };
    static cilist io___3 = { 0, 0, 0, "(1X,A)", 0 };
    static cilist io___4 = { 0, 0, 0, "(A)", 0 };
    static cilist io___5 = { 0, 0, 0, "(1X,A)", 0 };
    static cilist io___6 = { 0, 0, 0, "(A)", 0 };
    static cilist io___7 = { 0, 0, 0, "(A)", 0 };
    static cilist io___8 = { 0, 0, 0, "(A)", 0 };


    for (i__ = 81; i__ >= 2; --i__) {
/* L10: */
	if (*(unsigned char *)&keywrd_1.keywrd[i__ - 1] != ' ') {
	    goto L20;
	}
    }
L20:
    io___2.ciunit = *iprt;
    s_wsfe(&io___2);
    do_fio(&c__1, keywrd_1.keywrd, i__);
    e_wsfe();
    if (i_indx(keywrd_1.keywrd, " +", (ftnlen)81, (ftnlen)2) + i_indx(
	    keywrd_1.keywrd, "&", (ftnlen)81, (ftnlen)1) + i_indx(
	    keywrd_1.keywrd, "SETUP", (ftnlen)241, (ftnlen)5) != 0) {
	for (i__ = 161; i__ >= 82; --i__) {
/* L30: */
	    if (*(unsigned char *)&keywrd_1.keywrd[i__ - 1] != ' ') {
		goto L40;
	    }
	}
L40:
	if (*(unsigned char *)&keywrd_1.keywrd[80] != ' ') {
	    io___3.ciunit = *iprt;
	    s_wsfe(&io___3);
	    do_fio(&c__1, keywrd_1.keywrd + 80, i__ - 80);
	    e_wsfe();
	} else {
	    io___4.ciunit = *iprt;
	    s_wsfe(&io___4);
	    do_fio(&c__1, keywrd_1.keywrd + 80, i__ - 80);
	    e_wsfe();
	}
    }
    if (i_indx(keywrd_1.keywrd + 80, " +", (ftnlen)161, (ftnlen)2) + i_indx(
	    keywrd_1.keywrd + 80, "&", (ftnlen)161, (ftnlen)1) + i_indx(
	    keywrd_1.keywrd, "SETUP", (ftnlen)241, (ftnlen)5) != 0) {
	for (i__ = 241; i__ >= 161; --i__) {
/* L50: */
	    if (*(unsigned char *)&keywrd_1.keywrd[i__ - 1] != ' ') {
		goto L60;
	    }
	}
L60:
	if (*(unsigned char *)&keywrd_1.keywrd[160] != ' ') {
	    io___5.ciunit = *iprt;
	    s_wsfe(&io___5);
	    do_fio(&c__1, keywrd_1.keywrd + 160, i__ - 160);
	    e_wsfe();
	} else {
	    io___6.ciunit = *iprt;
	    s_wsfe(&io___6);
	    do_fio(&c__1, keywrd_1.keywrd + 160, i__ - 160);
	    e_wsfe();
	}
    }
    for (i__ = 81; i__ >= 2; --i__) {
/* L70: */
	if (*(unsigned char *)&titles_1.koment[i__ - 1] != ' ') {
	    goto L80;
	}
    }
L80:
    if (i_indx(titles_1.koment, " NULL ", (ftnlen)81, (ftnlen)6) == 0) {
	io___7.ciunit = *iprt;
	s_wsfe(&io___7);
	do_fio(&c__1, titles_1.koment, i__);
	e_wsfe();
    }
    for (i__ = 81; i__ >= 2; --i__) {
/* L90: */
	if (*(unsigned char *)&titles_1.title[i__ - 1] != ' ') {
	    goto L100;
	}
    }
L100:
    if (i_indx(titles_1.title, " NULL ", (ftnlen)81, (ftnlen)6) == 0) {
	io___8.ciunit = *iprt;
	s_wsfe(&io___8);
	do_fio(&c__1, titles_1.title, i__);
	e_wsfe();
    }
    return 0;
} /* wrttxt_ */

