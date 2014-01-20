/* xerbla.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ifiles[30];
} chanel_;

#define chanel_1 chanel_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int xerbla_(char *srname, integer *info, ftnlen srname_len)
{
    /* Format strings */
    static char fmt_9999[] = "(\002 ** ON ENTRY TO \002,a6,\002 PARAMETER NU"
	    "MBER \002,i2,\002 HAD \002,\002AN ILLEGAL VALUE\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
#define iw ((integer *)&chanel_1 + 5)

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, fmt_9999, 0 };



/*  -- LAPACK AUXILIARY ROUTINE (VERSION 1.0B) -- */
/*     UNIV. OF TENNESSEE, UNIV. OF CALIFORNIA BERKELEY, NAG LTD., */
/*     COURANT INSTITUTE, ARGONNE NATIONAL LAB, AND RICE UNIVERSITY */
/*     FEBRUARY 29, 1992 */

/*     .. SCALAR ARGUMENTS .. */
/* MOPAC CHANGE */
/* END OF MOPAC CHANGE */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  XERBLA  IS AN ERROR HANDLER FOR THE LAPACK ROUTINES. */
/*  IT IS CALLED BY AN LAPACK ROUTINE IF AN INPUT PARAMETER HAS AN */
/*  INVALID VALUE.  A MESSAGE IS PRINTED AND EXECUTION STOPS. */

/*  INSTALLERS MAY CONSIDER MODIFYING THE STOP STATEMENT IN ORDER TO */
/*  CALL SYSTEM-SPECIFIC EXCEPTION-HANDLING FACILITIES. */

/*  ARGUMENTS */
/*  ========= */

/*  SRNAME  (INPUT) CHARACTER*6 */
/*          THE NAME OF THE ROUTINE WHICH CALLED XERBLA. */

/*  INFO    (INPUT) INTEGER */
/*          THE POSITION OF THE INVALID PARAMETER IN THE PARAMETER LIST */
/*          OF THE CALLING ROUTINE. */

/*     .. EXECUTABLE STATEMENTS .. */

/* MOPAC CHANGE */
/*     WRITE( *, FMT = 9999 )SRNAME, INFO */
    io___2.ciunit = *iw;
    s_wsfe(&io___2);
    do_fio(&c__1, srname, (ftnlen)6);
    do_fio(&c__1, (char *)&(*info), (ftnlen)sizeof(integer));
    e_wsfe();
/* END OF MOPAC CHANGE */

    s_stop("", (ftnlen)0);


/*     END OF XERBLA */

    return 0;
} /* xerbla_ */

#undef iw


