/* reada.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b21 = 10.;

doublereal reada_(char *string, integer *istart, ftnlen string_len)
{
    /* System generated locals */
    integer i__1, i__2;
    doublereal ret_val, d__1;

    /* Builtin functions */
    integer i_len(char *, ftnlen), i_indx(char *, char *, ftnlen, ftnlen);
    double pow_dd(doublereal *, doublereal *);

    /* Local variables */
    static integer i__, j, l, n, i0, i9, iadd, ineg, idot, ipos, icapd, icape;
    extern doublereal digit_(char *, integer *, ftnlen);
    static integer ismld, ismle;
    static logical expnnt;

/*     FORTRAN FUNCTION TO EXTRACT NUMBER FROM STRING */


/*     DEFINE ASCII VALUES OF NUMERIC FIELD CHARACTERS */
    i0 = '0';
    i9 = '9';
    idot = '.';
    ineg = '-';
    ipos = '+';
    icapd = 'D';
    icape = 'E';
    ismld = 'd';
    ismle = 'e';

    l = i_len(string, string_len);

/*     FIND THE START OF THE NUMERIC FIELD */
    i__1 = l;
    for (i__ = *istart; i__ <= i__1; ++i__) {
	iadd = 0;
	n = *(unsigned char *)&string[i__ - 1];

/*       SIGNAL START OF NUMERIC FIELD IF DIGIT FOUND */
	if (n >= i0 && n <= i9) {
	    goto L20;
	}

/*       ACCOUNT FOR CONSECUTIVE SIGNS [- AND(OR) +] */
	if (n == ineg || n == ipos) {
	    ++iadd;
	    if (i__ + iadd > l) {
		goto L50;
	    }
	    i__2 = i__ + iadd - 1;
	    n = *(unsigned char *)&string[i__2];
	    if (n >= i0 && n <= i9) {
		goto L20;
	    }
	}

/*       ACCOUNT FOR CONSECUTIVE DECIMAL POINTS (.) */
	if (n == idot) {
	    ++iadd;
	    if (i__ + iadd > l) {
		goto L50;
	    }
	    i__2 = i__ + iadd - 1;
	    n = *(unsigned char *)&string[i__2];
	    if (n >= i0 && n <= i9) {
		goto L20;
	    }
	}
/* L10: */
    }
    goto L50;

/*     FIND THE END OF THE NUMERIC FIELD */
L20:
    expnnt = FALSE_;
    i__1 = l;
    for (j = i__ + 1; j <= i__1; ++j) {
	iadd = 0;
	n = *(unsigned char *)&string[j - 1];

/*       CONTINUE SEARCH FOR END IF DIGIT FOUND */
	if (n >= i0 && n <= i9) {
	    goto L30;
	}

/*       CONTINUE SEARCH FOR END IF SIGN FOUND AND EXPNNT TRUE */
	if (n == ineg || n == ipos) {
	    if (! expnnt) {
		goto L40;
	    }
	    ++iadd;
	    if (j + iadd > l) {
		goto L40;
	    }
	    i__2 = j + iadd - 1;
	    n = *(unsigned char *)&string[i__2];
	    if (n >= i0 && n <= i9) {
		goto L30;
	    }
	}
	if (n == idot) {
	    ++iadd;
	    if (j + iadd > l) {
		goto L40;
	    }
	    i__2 = j + iadd - 1;
	    n = *(unsigned char *)&string[i__2];
	    if (n >= i0 && n <= i9) {
		goto L30;
	    }
	    if (n == icape || n == ismle || n == icapd || n == ismld) {
		goto L30;
	    }
	}
	if (n == icape || n == ismle || n == icapd || n == ismld) {
	    if (expnnt) {
		goto L40;
	    }
	    expnnt = TRUE_;
	    goto L30;
	}
	goto L40;
L30:
	;
    }
    j = l + 1;
L40:
    i__1 = j - 2;
    n = *(unsigned char *)&string[i__1];
    if (n == icape || n == ismle || n == icapd || n == ismld) {
	--j;
    }

/*     FOUND THE END OF THE NUMERIC FIELD (IT RUNS 'I' THRU 'J-1') */
    n = 0;
    n += i_indx(string + (i__ - 1), "e", j - 1 - (i__ - 1), (ftnlen)1);
    n += i_indx(string + (i__ - 1), "E", j - 1 - (i__ - 1), (ftnlen)1);
    n += i_indx(string + (i__ - 1), "d", j - 1 - (i__ - 1), (ftnlen)1);
    n += i_indx(string + (i__ - 1), "D", j - 1 - (i__ - 1), (ftnlen)1);
    if (n == 0) {
	ret_val = digit_(string + (i__ - 1), &c__1, j - 1 - (i__ - 1));
    } else {
	i__1 = i__ + n;
	d__1 = digit_(string, &i__1, j - 1);
	ret_val = digit_(string, &i__, i__ + n - 2) * pow_dd(&c_b21, &d__1);
    }
    return ret_val;

/*     DEFAULT VALUE RETURNED BECAUSE NO NUMERIC FIELD FOUND */
L50:
    ret_val = 0.;
    return ret_val;
} /* reada_ */

/*     ****************************************************************** */
doublereal digit_(char *string, integer *istart, ftnlen string_len)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Builtin functions */
    integer i_len(char *, ftnlen);

    /* Local variables */
    static integer i__, j, l, n;
    static doublereal c1, c2;
    static integer i0, i9, idig, ineg, ispc, idot;
    static logical sign;
    static integer ipos;
    static doublereal deciml;

/*     FORTRAN FUNCTION TO CONVERT NUMERIC FIELD TO DOUBLE PRECISION */
/*     NUMBER.  THE STRING IS ASSUMED TO BE CLEAN (NO INVALID DIGIT */
/*     OR CHARACTER COMBINATIONS FROM ISTART TO THE FIRST NONSPACE, */
/*     NONDIGIT, NONSIGN, AND NONDECIMAL POINT CHARACTER). */


/*     DEFINE ASCII VALUES OF NUMERIC FIELD CHARACTERS */
    i0 = '0';
    i9 = '9';
    ineg = '-';
    ipos = '+';
    idot = '.';
    ispc = ' ';

    c1 = 0.;
    c2 = 0.;
    sign = TRUE_;
    l = i_len(string, string_len);

/*     DETERMINE THE CONTRIBUTION TO THE NUMBER GREATER THAN ONE */
    idig = 0;
    i__1 = l;
    for (i__ = *istart; i__ <= i__1; ++i__) {
	n = *(unsigned char *)&string[i__ - 1];
	if (n >= i0 && n <= i9) {
	    ++idig;
	    c1 = c1 * 10. + n - i0;
	} else if (n == ineg || n == ipos || n == ispc) {
	    if (n == ineg) {
		sign = FALSE_;
	    }
	} else if (n == idot) {
	    goto L20;
	} else {
	    goto L40;
	}
/* L10: */
    }

/*     DETERMINE THE CONTRIBUTION TO THE NUMBER LESS THAN THAN ONE */
L20:
    deciml = 1.;
    i__1 = l;
    for (j = i__ + 1; j <= i__1; ++j) {
	n = *(unsigned char *)&string[j - 1];
	if (n >= i0 && n <= i9) {
	    deciml /= 10.;
	    c2 += (n - i0) * deciml;
	} else if (n != ispc) {
	    goto L40;
	}
/* L30: */
    }

/*     PUT THE PIECES TOGETHER */
L40:
    ret_val = c1 + c2;
    if (! sign) {
	ret_val = -ret_val;
    }
    return ret_val;
} /* digit_ */

