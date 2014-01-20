/* lsame.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

logical lsame_(char *ca, char *cb, ftnlen ca_len, ftnlen cb_len)
{
    /* System generated locals */
    logical ret_val;

    /* Local variables */
    static integer inta, intb, zcode;


/*  -- LAPACK AUXILIARY ROUTINE (VERSION 1.0) -- */
/*     UNIV. OF TENNESSEE, UNIV. OF CALIFORNIA BERKELEY, NAG LTD., */
/*     COURANT INSTITUTE, ARGONNE NATIONAL LAB, AND RICE UNIVERSITY */
/*     FEBRUARY 29, 1992 */

/*     .. SCALAR ARGUMENTS .. */
/*     .. */

/*  PURPOSE */
/*  ======= */

/*  LSAME RETURNS .TRUE. IF CA IS THE SAME LETTER AS CB REGARDLESS OF */
/*  CASE. */

/*  ARGUMENTS */
/*  ========= */

/*  CA      (INPUT) CHARACTER*1 */
/*  CB      (INPUT) CHARACTER*1 */
/*          CA AND CB SPECIFY THE SINGLE CHARACTERS TO BE COMPARED. */

/*     .. INTRINSIC FUNCTIONS .. */
/*     .. */
/*     .. LOCAL SCALARS .. */
/*     .. */
/*     .. EXECUTABLE STATEMENTS .. */

/*     TEST IF THE CHARACTERS ARE EQUAL */

    ret_val = *(unsigned char *)ca == *(unsigned char *)cb;
    if (ret_val) {
	return ret_val;
    }

/*     NOW TEST FOR EQUIVALENCE IF BOTH CHARACTERS ARE ALPHABETIC. */

    zcode = 'Z';

/*     USE 'Z' RATHER THAN 'A' SO THAT ASCII CAN BE DETECTED ON PRIME */
/*     MACHINES, ON WHICH ICHAR RETURNS A VALUE WITH BIT 8 SET. */
/*     ICHAR('A') ON PRIME MACHINES RETURNS 193 WHICH IS THE SAME AS */
/*     ICHAR('A') ON AN EBCDIC MACHINE. */

    inta = *(unsigned char *)ca;
    intb = *(unsigned char *)cb;

    if (zcode == 90 || zcode == 122) {

/*        ASCII IS ASSUMED - ZCODE IS THE ASCII CODE OF EITHER LOWER OR */
/*        UPPER CASE 'Z'. */

	if (inta >= 97 && inta <= 122) {
	    inta += -32;
	}
	if (intb >= 97 && intb <= 122) {
	    intb += -32;
	}

    } else if (zcode == 233 || zcode == 169) {

/*        EBCDIC IS ASSUMED - ZCODE IS THE EBCDIC CODE OF EITHER LOWER OR */
/*        UPPER CASE 'Z'. */

	if (inta >= 129 && inta <= 137 || inta >= 145 && inta <= 153 || inta 
		>= 162 && inta <= 169) {
	    inta += 64;
	}
	if (intb >= 129 && intb <= 137 || intb >= 145 && intb <= 153 || intb 
		>= 162 && intb <= 169) {
	    intb += 64;
	}

    } else if (zcode == 218 || zcode == 250) {

/*        ASCII IS ASSUMED, ON PRIME MACHINES - ZCODE IS THE ASCII CODE */
/*        PLUS 128 OF EITHER LOWER OR UPPER CASE 'Z'. */

	if (inta >= 225 && inta <= 250) {
	    inta += -32;
	}
	if (intb >= 225 && intb <= 250) {
	    intb += -32;
	}
    }
    ret_val = inta == intb;

/*     RETURN */

/*     END OF LSAME */

    return ret_val;
} /* lsame_ */

