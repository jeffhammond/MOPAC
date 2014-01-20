/* vecprt.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int vecprt_(doublereal *a, integer *numm)
{
    /* Initialized data */

    static char atorbs[2*9] = " S" "PX" "PY" "PZ" "X2" "XZ" "Z2" "YZ" "XY";

    /* Format strings */
    static char fmt_100[] = "(\0020\002/13x,10(1x,a2,1x,a2,i3,2x))";
    static char fmt_110[] = "(\002 \002,21a6)";
    static char fmt_120[] = "(\0021\002)";
    static char fmt_130[] = "(\002 \002,a2,1x,a2,i5,10f11.6)";

    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, l, m, n, ma, na, kk, ll, jhi, jlo;
    static char line[6*21];
    static integer numb, natom[300], limit;
    static char itext[2*300], jtext[2*300];

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___20 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___21 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___22 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___24 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___25 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_120, 0 };


/* COMDECK SIZES */
/* *********************************************************************** */
/*   THIS FILE CONTAINS ALL THE ARRAY SIZES FOR USE IN MOPAC. */

/*     THERE ARE ONLY 5 PARAMETERS THAT THE PROGRAMMER NEED SET: */
/*     MAXHEV = MAXIMUM NUMBER OF HEAVY ATOMS (HEAVY: NON-HYDROGEN ATOMS) */
/*     MAXLIT = MAXIMUM NUMBER OF HYDROGEN ATOMS. */
/*     MAXTIM = DEFAULT TIME FOR A JOB. (SECONDS) */
/*     MAXDMP = DEFAULT TIME FOR AUTOMATIC RESTART FILE GENERATION (SECS) */
/*     ISYBYL = 1 IF MOPAC IS TO BE USED IN THE SYBYL PACKAGE, =0 OTHERWISE */
/*     SEE ALSO NMECI, NPULAY AND MESP AT THE END OF THIS FILE */


/* *********************************************************************** */

/*   THE FOLLOWING CODE DOES NOT NEED TO BE ALTERED BY THE PROGRAMMER */

/* *********************************************************************** */

/*    ALL OTHER PARAMETERS ARE DERIVED FUNCTIONS OF THESE TWO PARAMETERS */

/*      NAME                   DEFINITION */
/*     NUMATM         MAXIMUM NUMBER OF ATOMS ALLOWED. */
/*     MAXORB         MAXIMUM NUMBER OF ORBITALS ALLOWED. */
/*     MAXPAR         MAXIMUM NUMBER OF PARAMETERS FOR OPTIMISATION. */
/*     N2ELEC         MAXIMUM NUMBER OF TWO ELECTRON INTEGRALS ALLOWED. */
/*     MPACK          AREA OF LOWER HALF TRIANGLE OF DENSITY MATRIX. */
/*     MORB2          SQUARE OF THE MAXIMUM NUMBER OF ORBITALS ALLOWED. */
/*     MAXHES         AREA OF HESSIAN MATRIX */
/*     MAXALL         LARGER THAN MAXORB OR MAXPAR. */
/* *********************************************************************** */

/* *********************************************************************** */
/* DECK MOPAC */
/* ********************************************************************** */

/*  VECPRT PRINTS A LOWER-HALF TRIANGLE OF A SQUARE MATRIX, THE */
/*         LOWER-HALF TRIANGLE BEING STORED IN PACKED FORM IN THE */
/*         ARRAY "A" */

/* ON INPUT: */
/*      A      = ARRAY TO BE PRINTED */
/*      NUMM   = SIZE OF ARRAY TO BE PRINTED */
/* (REF) NUMAT  = NUMBER OF ATOMS IN THE MOLECULE (THIS IS NEEDED TO */
/*               DECIDE IF AN ATOMIC ARRAY OR ATOMIC ORBITAL ARRAY IS */
/*               TO BE PRINTED */
/* (REF) NAT    = LIST OF ATOMIC NUMBERS */
/* (REF) NFIRST = LIST OF ORBITAL COUNTERS */
/* (REF) NLAST  = LIST OF ORBITAL COUNTERS */

/*  NONE OF THE ARGUMENTS ARE ALTERED BY THE CALL OF VECPRT */

/* ********************************************************************* */
    /* Parameter adjustments */
    --a;

    /* Function Body */
    if (molkst_1.numat != 0 && molkst_1.numat == *numm) {

/*    PRINT OVER ATOM COUNT */

	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_copy(itext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
	    s_copy(jtext + (i__ - 1 << 1), elemts_1.elemnt + (molkst_1.nat[
		    i__ - 1] - 1 << 1), (ftnlen)2, (ftnlen)2);
	    natom[i__ - 1] = i__;
/* L10: */
	}
    } else {
	if (molkst_1.numat != 0 && molkst_1.nlast[molkst_1.numat - 1] == *
		numm) {
	    i__1 = molkst_1.numat;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		jlo = molkst_1.nfirst[i__ - 1];
		jhi = molkst_1.nlast[i__ - 1];
		l = molkst_1.nat[i__ - 1];
		k = 0;
		i__2 = jhi;
		for (j = jlo; j <= i__2; ++j) {
		    ++k;
		    s_copy(itext + (j - 1 << 1), atorbs + (k - 1 << 1), (
			    ftnlen)2, (ftnlen)2);
		    s_copy(jtext + (j - 1 << 1), elemts_1.elemnt + (l - 1 << 
			    1), (ftnlen)2, (ftnlen)2);
		    natom[j - 1] = i__;
/* L20: */
		}
/* L30: */
	    }
	} else {
	    numb = abs(*numm);
	    i__1 = numb;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		s_copy(itext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
		s_copy(jtext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
/* L40: */
		natom[i__ - 1] = i__;
	    }
	}
    }
    numb = abs(*numm);
    for (i__ = 1; i__ <= 21; ++i__) {
/* L50: */
	s_copy(line + (i__ - 1) * 6, "------", (ftnlen)6, (ftnlen)6);
    }
    limit = numb * (numb + 1) / 2;
    kk = 8;
    na = 1;
L60:
    ll = 0;
/* Computing MIN */
    i__1 = numb + 1 - na;
    m = min(i__1,6);
    ma = (m << 1) + 1;
    m = na + m - 1;
    s_wsfe(&io___19);
    i__1 = m;
    for (i__ = na; i__ <= i__1; ++i__) {
	do_fio(&c__1, itext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, jtext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, (char *)&natom[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    s_wsfe(&io___20);
    i__1 = ma;
    for (k = 1; k <= i__1; ++k) {
	do_fio(&c__1, line + (k - 1) * 6, (ftnlen)6);
    }
    e_wsfe();
    i__1 = numb;
    for (i__ = na; i__ <= i__1; ++i__) {
	++ll;
	k = i__ * (i__ - 1) / 2;
/* Computing MIN */
	i__2 = k + m, i__3 = k + i__;
	l = min(i__2,i__3);
	k += na;
	if (kk + ll <= 50) {
	    goto L70;
	}
	s_wsfe(&io___21);
	e_wsfe();
	s_wsfe(&io___22);
	i__2 = m;
	for (n = na; n <= i__2; ++n) {
	    do_fio(&c__1, itext + (n - 1 << 1), (ftnlen)2);
	    do_fio(&c__1, jtext + (n - 1 << 1), (ftnlen)2);
	    do_fio(&c__1, (char *)&natom[n - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
	s_wsfe(&io___24);
	i__2 = ma;
	for (n = 1; n <= i__2; ++n) {
	    do_fio(&c__1, line + (n - 1) * 6, (ftnlen)6);
	}
	e_wsfe();
	kk = 4;
	ll = 0;
L70:
	s_wsfe(&io___25);
	do_fio(&c__1, itext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, jtext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, (char *)&natom[i__ - 1], (ftnlen)sizeof(integer));
	i__2 = l;
	for (n = k; n <= i__2; ++n) {
	    do_fio(&c__1, (char *)&a[n], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
/* L80: */
    }
    if (l >= limit) {
	goto L90;
    }
    kk = kk + ll + 4;
    na = m + 1;
    if (kk + numb + 1 - na <= 50) {
	goto L60;
    }
    kk = 4;
    s_wsfe(&io___26);
    e_wsfe();
    goto L60;
L90:
    return 0;


} /* vecprt_ */

