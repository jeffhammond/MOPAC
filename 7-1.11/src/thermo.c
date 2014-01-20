/* thermo.f -- translated by f2c (version 20020621).
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

/* Subroutine */ int thermo_(doublereal *a, doublereal *b, doublereal *c__, 
	logical *linear, doublereal *sym, doublereal *wt, doublereal *vibs, 
	integer *nvibs, doublereal *escf)
{
    /* Initialized data */

    static doublereal pi = 3.14159;
    static doublereal r__ = 1.98726;
    static doublereal h__ = 6.626e-27;
    static doublereal ak = 1.3807e-16;
    static doublereal ac = 2.99776e10;

    /* Format strings */
    static char fmt_20[] = "(10x,\002THIS THERMODYNAMICS CALCULATION IS LIMI"
	    "TED TO\002,/10x,\002MOLECULES WHICH HAVE NO INTERNAL ROTATION"
	    "S\002//)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    double exp(doublereal), log(doublereal), sqrt(doublereal), d_lg10(
	    doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal t, c1, e0, hr;
    static integer ir;
    static doublereal hv, wi, qr, sr, qv, sv, h298;
    static integer it1, it2;
    static doublereal sv1, sv2, cpr, ewj, cpv, htr, qtr, str;
    static integer ilim;
    static doublereal hint, cptr, qint, sint, htot, stot;
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal cpint;
    static integer itemp, istep;
    static doublereal cptot, trange[300];
    static char tmpkey[241];

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 6, 0, "(//10X,'TEMPERATURE RANGE STARTS TOO"
	    " LOW,',      ' LOWER BOUND IS RESET TO 30K')", 0 };
    static cilist io___12 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___13 = { 0, 6, 0, "(A)", 0 };
    static cilist io___14 = { 0, 6, 0, "(//10X,'MOLECULE IS LINEAR')", 0 };
    static cilist io___15 = { 0, 6, 0, "(//10X,'MOLECULE IS NOT LINEAR')", 0 }
	    ;
    static cilist io___16 = { 0, 6, 0, "(/10X,'THERE ARE',I3,' GENUINE VIBRA"
	    "TIONS IN THIS ', 'SYSTEM')", 0 };
    static cilist io___17 = { 0, 6, 0, fmt_20, 0 };
    static cilist io___18 = { 0, 6, 0, "(//20X,'CALCULATED THERMODYNAMIC PRO"
	    "PERTIES')", 0 };
    static cilist io___19 = { 0, 6, 0, "(42X,'*')", 0 };
    static cilist io___20 = { 0, 6, 0, "('   TEMP. (K)   PARTITION FUNCTION "
	    "  H.O.F.',         '    ENTHALPY   HEAT CAPACITY  ENTROPY')", 0 };
    static cilist io___21 = { 0, 6, 0, "(  '                                "
	    "    KCAL/MOL',     '   CAL/MOLE    CAL/K/MOL   CAL/K/MOL',/)", 0 }
	    ;
    static cilist io___53 = { 0, 6, 0, "(/,I7,'  VIB.',G18.4                "
	    "                        ,13X,3F11.5        )", 0 };
    static cilist io___54 = { 0, 6, 0, "(7X,'  ROT.',G13.3                  "
	    "                        ,16X,3F11.3        )", 0 };
    static cilist io___55 = { 0, 6, 0, "(7X,'  INT.',G13.3                  "
	    "                        ,16X,3F11.3        )", 0 };
    static cilist io___56 = { 0, 6, 0, "(7X,'  TRA.',G13.3                  "
	    "                        ,16X,3F11.3)", 0 };
    static cilist io___57 = { 0, 6, 0, "(7X,'  TOT.',13X,F17.3,F11.4,2F11.4)",
	     0 };
    static cilist io___58 = { 0, 6, 0, "(/3X,' * NOTE: HEATS OF FORMATION AR"
	    "E RELATIVE TO THE',/12X,' ELEMENTS IN THEIR STANDARD STATE AT 29"
	    "8K')", 0 };




/*   THERMO CALCULATES THE VARIOUS THERMODYNAMIC QUANTITIES FOR A */
/*   SPECIFIED TEMPERATURE GIVEN THE VIBRATIONAL FREQUENCIES, MOMENTS OF */
/*   INERTIA, MOLECULAR WEIGHT AND SYMMETRY NUMBER. */

/*   REFERENCE: G.HERZBERG MOLECULAR SPECTRA AND MOLECULAR STRUCTURE */
/*              VOL 2, CHAP. 5 */

/*   ----    TABLE OF SYMMETRY NUMBERS    ---- */

/*        C1 CI CS     1      D2 D2D D2H  4       C(INF)V   1 */
/*        C2 C2V C2H   2      D3 D3D D3H  6       D(INF)H   2 */
/*        C3 C3V C3H   3      D4 D4D D4H  8       T TD     12 */
/*        C4 C4V C4H   4      D6 D6D D6H  12      OH       24 */
/*        C6 C6V C6H   6      S6          3 */


/*   PROGRAM LIMITATIONS:  THE EQUATIONS USED ARE APPROPRIATE TO THE */
/*   HIGH TEMPERATURE LIMIT AND WILL BEGIN TO BE INADEQUATE AT TEMPERA- */
/*   TURES BELOW ABOUT 100 K.  SECONDLY THIS PROGRAM IS ONLY APPROPRIATE */
/*   IN THE CASE OF MOLECULES IN WHICH THERE IS NO FREE ROTATION */




/* ****************************************************************** */

/*  THE FOLLOWING CONSTANTS ARE NOW DEFINED: */
/*          PI  = CIRCUMFERENCE TO DIAMETER OF A CIRCLE */
/*          R   = GAS CONSTANT IN CALORIES/MOLE */
/*          H   = PLANCK'S CONSTANT IN ERG-SECONDS */
/*          AK  = BOLTZMANN CONSTANT IN ERG/DEGREE */
/*          AC  = SPEED OF LIGHT IN CM/SEC */
/* ****************************************************************** */
    /* Parameter adjustments */
    --vibs;

    /* Function Body */
/* ****************************************************************** */
    it1 = 200;
    it2 = 400;
    istep = 10;
    s_copy(tmpkey, keywrd_1.keywrd, (ftnlen)241, (ftnlen)241);
    i__ = i_indx(tmpkey, "THERMO(", (ftnlen)241, (ftnlen)7);
    if (i__ != 0) {

/*   ERASE ALL TEXT FROM TMPKEY EXCEPT THERMO DATA */

	s_copy(tmpkey, " ", i__, (ftnlen)1);
	i__1 = i_indx(tmpkey, ")", (ftnlen)241, (ftnlen)1) - 1;
	s_copy(tmpkey + i__1, " ", 241 - i__1, (ftnlen)1);
	it1 = (integer) reada_(tmpkey, &i__, (ftnlen)241);
	if (it1 < 100) {
	    s_wsfe(&io___11);
	    e_wsfe();
	    it1 = 100;
	}
	i__ = i_indx(tmpkey, ",", (ftnlen)241, (ftnlen)1);
	if (i__ != 0) {
	    *(unsigned char *)&tmpkey[i__ - 1] = ' ';
	    it2 = (integer) reada_(tmpkey, &i__, (ftnlen)241);
	    if (it2 < it1) {
		it2 = it1 + 200;
		istep = 10;
		goto L10;
	    }
	    i__ = i_indx(tmpkey, ",", (ftnlen)241, (ftnlen)1);
	    if (i__ != 0) {
		*(unsigned char *)&tmpkey[i__ - 1] = ' ';
		istep = (integer) reada_(tmpkey, &i__, (ftnlen)241);
		if (istep < 1) {
		    istep = 1;
		}
	    } else {
		istep = (it2 - it1) / 20;
		if (istep == 0) {
		    istep = 1;
		}
		if (istep >= 2 && istep < 5) {
		    istep = 2;
		}
		if (istep >= 5 && istep < 10) {
		    istep = 5;
		}
		if (istep >= 10 && istep < 20) {
		    istep = 10;
		}
		if (istep > 20 && istep < 50) {
		    istep = 20;
		}
		if (istep > 50 && istep < 100) {
		    istep = 50;
		}
		if (istep > 100) {
		    istep = 100;
		}
	    }
	} else {
	    it2 = it1 + 200;
	}
    }
L10:
    s_wsfe(&io___12);
    do_fio(&c__1, titles_1.title, (ftnlen)81);
    e_wsfe();
    s_wsfe(&io___13);
    do_fio(&c__1, titles_1.koment, (ftnlen)81);
    e_wsfe();
    if (*linear) {
	s_wsfe(&io___14);
	e_wsfe();
    } else {
	s_wsfe(&io___15);
	e_wsfe();
    }
    s_wsfe(&io___16);
    do_fio(&c__1, (char *)&(*nvibs), (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___17);
    e_wsfe();
    s_wsfe(&io___18);
    e_wsfe();
    s_wsfe(&io___19);
    e_wsfe();
    s_wsfe(&io___20);
    e_wsfe();
    s_wsfe(&io___21);
    e_wsfe();
    i__1 = *nvibs;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	vibs[i__] = (d__1 = vibs[i__], abs(d__1));
    }
    ilim = 1;
    i__1 = it2;
    i__2 = istep;
    for (itemp = it1; i__2 < 0 ? itemp >= i__1 : itemp <= i__1; itemp += i__2)
	     {
	++ilim;
/* L40: */
	trange[ilim - 1] = (doublereal) itemp;
    }
    trange[0] = 298.;
    i__2 = ilim;
    for (ir = 1; ir <= i__2; ++ir) {
	itemp = (integer) trange[ir - 1];
	t = (doublereal) itemp;
/*   ***   INITIALISE SOME VARIABLES   *** */
	c1 = h__ * ac / ak / t;
	qv = 1.;
	hv = 0.;
	e0 = 0.;
	cpv = 0.;
	sv1 = 0.;
	sv2 = 0.;
/*   ***   CONSTRUCT THE FREQUENCY DEPENDENT PARTS OF PARTITION FUNCTION */
	i__1 = *nvibs;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    wi = vibs[i__];
	    ewj = exp(-wi * c1);
	    qv /= 1 - ewj;
	    hv += wi * ewj / (1 - ewj);
	    e0 += wi;
	    cpv += wi * wi * ewj / (1 - ewj) / (1 - ewj);
	    sv1 += log(1. - ewj);
/* L50: */
	    sv2 += wi * ewj / (1 - ewj);
	}
/*   ***   FINISH CALCULATION OF VIBRATIONAL PARTS   *** */
	hv = hv * r__ * h__ * ac / ak;
	e0 *= 1.4295;
	cpv = cpv * r__ * c1 * c1;
	sv = sv2 * r__ * c1 - r__ * sv1;
/*   ***   NOW CALCULATE THE ROTATIONAL PARTS  (FIRST LINEAR MOLECULES */
	if (! (*linear)) {
	    goto L60;
	}
	qr = 1 / (c1 * *a * *sym);
	hr = r__ * t;
	cpr = r__;
	sr = r__ * log(t * ak / (h__ * ac * *a * *sym)) + r__;
	goto L70;
L60:
	qr = sqrt(pi / (*a * *b * *c__ * c1 * c1 * c1)) / *sym;
	hr = r__ * 3. * t / 2.;
	cpr = r__ * 3. / 2.;
	sr = r__ * .5 * (log(t * ak / (h__ * ac)) * 3. - log(*sym) * 2. + log(
		pi / (*a * *b * *c__)) + 3.);
L70:
/*   ***   CALCULATE INTERNAL CONTRIBUTIONS   *** */
	qint = qv * qr;
	hint = hv + hr;
	cpint = cpv + cpr;
	sint = sv + sr;
/*   ***   CONSTRUCT TRANSLATION CONTRIBUTIONS   *** */
/* Computing 3rd power */
	d__1 = sqrt(pi * 2. * *wt * t * ak * 1.6606e-24) / h__;
	qtr = d__1 * (d__1 * d__1);
	htr = r__ * 5. * t / 2.;
	cptr = r__ * 5. / 2.;
	str = (d_lg10(&t) * 5. + d_lg10(wt) * 3.) * 2.2868 - 2.3135;
/*   ***   CONSTRUCT TOTALS   *** */
	cptot = cptr + cpint;
	stot = str + sint;
	htot = htr + hint;
/*   ***   OUTPUT SECTION   *** */
	if (ir == 1) {
	    h298 = htot;
	} else {
	    s_wsfe(&io___53);
	    do_fio(&c__1, (char *)&itemp, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&qv, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&hv, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cpv, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sv, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___54);
	    do_fio(&c__1, (char *)&qr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&hr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cpr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sr, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___55);
	    do_fio(&c__1, (char *)&qint, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&hint, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cpint, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&sint, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&qtr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&htr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cptr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&str, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___57);
	    d__1 = *escf + (htot - h298) / 1e3;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&htot, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&cptot, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&stot, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
/* L80: */
    }
    s_wsfe(&io___58);
    e_wsfe();
    return 0;
} /* thermo_ */

