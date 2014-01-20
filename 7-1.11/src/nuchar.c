/* nuchar.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Subroutine */ int nuchar_(char *line, doublereal *value, integer *nvalue, 
	ftnlen line_len)
{
    /* Initialized data */

    static char comma[1] = ",";
    static char space[1] = " ";

    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer i__;
    static char tab[1];
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical leadsp;
    static integer istart[40];

/* *********************************************************************** */

/*   NUCHAR  DETERMINS AND RETURNS THE REAL VALUES OF ALL NUMBERS */
/*           FOUND IN 'LINE'. ALL CONNECTED SUBSTRINGS ARE ASSUMED */
/*           TO CONTAIN NUMBERS */
/*   ON ENTRY LINE    = CHARACTER STRING */
/*   ON EXIT  VALUE   = ARRAY OF NVALUE REAL VALUES */

/* *********************************************************************** */
    /* Parameter adjustments */
    --value;

    /* Function Body */
    *(unsigned char *)tab = '\t';

/* CLEAN OUT TABS AND COMMAS */

    for (i__ = 1; i__ <= 80; ++i__) {
/* L10: */
	if (*(unsigned char *)&line[i__ - 1] == *(unsigned char *)tab || *(
		unsigned char *)&line[i__ - 1] == *(unsigned char *)&comma[0])
		 {
	    *(unsigned char *)&line[i__ - 1] = *(unsigned char *)&space[0];
	}
    }

/* FIND INITIAL DIGIT OF ALL NUMBERS, CHECK FOR LEADING SPACES FOLLOWED */
/*     BY A CHARACTER */

    leadsp = TRUE_;
    *nvalue = 0;
    for (i__ = 1; i__ <= 80; ++i__) {
	if (leadsp && *(unsigned char *)&line[i__ - 1] != *(unsigned char *)&
		space[0]) {
	    ++(*nvalue);
	    istart[*nvalue - 1] = i__;
	}
	leadsp = *(unsigned char *)&line[i__ - 1] == *(unsigned char *)&space[
		0];
/* L20: */
    }

/* FILL NUMBER ARRAY */

    i__1 = *nvalue;
    for (i__ = 1; i__ <= i__1; ++i__) {
	value[i__] = reada_(line, &istart[i__ - 1], (ftnlen)80);
/* L30: */
    }
    return 0;
} /* nuchar_ */

