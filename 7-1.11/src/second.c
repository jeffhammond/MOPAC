/* second.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;

doublereal second_(void)
{
    /* Initialized data */

    static logical setok = TRUE_;
    static real shut = 0.f;

    /* System generated locals */
    integer i__1;
    doublereal ret_val;
    char ch__1[80];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer f_open(olist *), s_rsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_rsfe(void), s_wsfe(cilist *), e_wsfe(void), f_clos(
	    cllist *);

    /* Local variables */
    static real a[2];
    static char x[1];
    static real y, cpu;
    extern doublereal etime_(real *);
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___6 = { 1, 4, 1, "(A)", 0 };
    static cilist io___8 = { 0, 6, 0, "(///10X,'****   JOB STOPPED BY OPERAT"
	    "OR   ****')", 0 };


/* ****************************************************** */

/*   SECOND, ON EXIT, CONTAINS THE NUMBER OF CPU SECONDS */
/*   SINCE THE START OF THE CALCULATION. */

/* ****************************************************** */

/*   IF YOU ARE NOT USING A VAX OR A UNIX COMPUTER, UNCOMMENT THE */
/*   NEXT LINE */
/*     CPU=0.0 */

/*   IF YOU ARE NOT USING A VAX OR A UNIX COMPUTER, REMOVE THE NEXT LINE */
    y = etime_(a);
    cpu = a[0];
/* ********************************************************************** */

/*   NOW TO SEE IF A FILE LOGICALLY CALLED SHUTDOWN EXISTS, IF IT DOES */
/*   THEN INCREMENT CPU TIME BY 1,000,000 SECONDS. */

/* *********************************************************************** */
    o__1.oerr = 0;
    o__1.ounit = 4;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "SHUTDOWN", (ftnlen)8);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    i__1 = s_rsfe(&io___6);
    if (i__1 != 0) {
	goto L10;
    }
    i__1 = do_fio(&c__1, x, (ftnlen)1);
    if (i__1 != 0) {
	goto L10;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L10;
    }

/*          FILE EXISTS, THEREFORE INCREMENT TIME */

    shut = 1e6f;
    if (setok) {
	s_wsfe(&io___8);
	e_wsfe();
	setok = FALSE_;
    }
L10:
    ret_val = cpu + shut;
    cl__1.cerr = 0;
    cl__1.cunit = 4;
    cl__1.csta = 0;
    f_clos(&cl__1);
    return ret_val;
} /* second_ */

/* Character */ VOID getnam_(char *ret_val, ftnlen ret_val_len, char *namein, 
	ftnlen namein_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    extern /* Subroutine */ int getenv_(char *, char *, ftnlen, ftnlen);
    static char nameout[80];


/*    THIS FUNCTION IS DESIGNED FOR USE ON A VMS AND ON A UNIX */
/*    SYSTEM.  IF YOUR SYSTEM IS VMS, COMMENT OUT THE LINE */
/*    "      CALL GETENV(NAMEIN, NAMEOUT)", FURTHER ON IN THIS FUNCTION. */
/*    IF YOUR SYSTEM IS UNIX, MAKE SURE THE LINE IS NOT */
/*    COMMENTED OUT. */
/*    ON A UNIX SYSTEM, GETENV WILL CONSULT THE ENVIRONMENT */
/*    FOR THE CURRENT ALIAS OF THE CHARACTER STRING CONTAINED IN */
/*    'NAMEIN'.  THE ALIAS, IF IT EXISTS, OR THE ORIGINAL NAME IN NAMEIN */
/*    WILL BE RETURNED. */

    s_copy(nameout, " ", (ftnlen)80, (ftnlen)1);
    getenv_(namein, nameout, namein_len, (ftnlen)80);
    if (s_cmp(nameout, "  ", (ftnlen)80, (ftnlen)2) == 0) {
	s_copy(nameout, namein, (ftnlen)80, namein_len);
    }
    s_copy(ret_val, nameout, (ftnlen)80, (ftnlen)80);
    return ;
} /* getnam_ */

