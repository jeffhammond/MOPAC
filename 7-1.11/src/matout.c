/* matout.f -- translated by f2c (version 20020621).
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

/* Subroutine */ int matout_(doublereal *a, doublereal *b, integer *nc, 
	integer *nnr, integer *ndim)
{
    /* Initialized data */

    static char atorbs[2*9] = " S" "PX" "PY" "PZ" "X2" "XZ" "Z2" "YZ" "XY";

    /* Format strings */
    static char fmt_100[] = "(////,3x,\002 ROOT NO.\002,i5,9i12)";
    static char fmt_110[] = "(/8x,10f12.5)";
    static char fmt_120[] = "(\002  \002)";
    static char fmt_130[] = "(2(1x,a2),i4,f10.5,10f12.5)";
    static char fmt_140[] = "(\0021\002)";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ka, kb, kc, la, lc, lb, nr, jhi, jlo, natom[
	    420];
    static char itext[2*420], jtext[2*420];

    /* Fortran I/O blocks */
    static cilist io___15 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___21 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___22 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___23 = { 0, 6, 0, fmt_140, 0 };
    static cilist io___24 = { 0, 6, 0, fmt_140, 0 };


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

/*      MATOUT PRINTS A SQUARE MATRIX OF EIGENVECTORS AND EIGENVALUES */

/*    ON INPUT A CONTAINS THE MATRIX TO BE PRINTED. */
/*             B CONTAINS THE EIGENVALUES. */
/*             NC NUMBER OF MOLECULAR ORBITALS TO BE PRINTED. */
/*             NR IS THE SIZE OF THE SQUARE ARRAY TO BE PRINTED. */
/*             NDIM IS THE ACTUAL SIZE OF THE SQUARE ARRAY "A". */
/*             NFIRST AND NLAST CONTAIN ATOM ORBITAL COUNTERS. */
/*             NAT = ARRAY OF ATOMIC NUMBERS OF ATOMS. */


/* *********************************************************************** */
    /* Parameter adjustments */
    --b;
    a_dim1 = *ndim;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;

    /* Function Body */
    nr = *nnr;
    if (molkst_1.numat == 0) {
	goto L30;
    }
    if (molkst_1.nlast[molkst_1.numat - 1] != nr) {
	goto L30;
    }
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jlo = molkst_1.nfirst[i__ - 1];
	jhi = molkst_1.nlast[i__ - 1];
	l = molkst_1.nat[i__ - 1];
	k = 0;
	i__2 = jhi;
	for (j = jlo; j <= i__2; ++j) {
	    ++k;
	    s_copy(itext + (j - 1 << 1), atorbs + (k - 1 << 1), (ftnlen)2, (
		    ftnlen)2);
	    s_copy(jtext + (j - 1 << 1), elemts_1.elemnt + (l - 1 << 1), (
		    ftnlen)2, (ftnlen)2);
	    natom[j - 1] = i__;
/* L10: */
	}
/* L20: */
    }
    goto L50;
L30:
    nr = abs(nr);
    i__1 = nr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_copy(itext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
	s_copy(jtext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
/* L40: */
	natom[i__ - 1] = i__;
    }
L50:
    ka = 1;
    kc = 6;
L60:
    kb = min(kc,*nc);
    s_wsfe(&io___15);
    i__1 = kb;
    for (i__ = ka; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    if (b[1] != 0.) {
	s_wsfe(&io___16);
	i__1 = kb;
	for (i__ = ka; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&b[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    s_wsfe(&io___17);
    e_wsfe();
    la = 1;
    lc = 40;
L70:
    lb = min(lc,nr);
    i__1 = lb;
    for (i__ = la; i__ <= i__1; ++i__) {
	if (s_cmp(itext + (i__ - 1 << 1), " S", (ftnlen)2, (ftnlen)2) == 0) {
	    s_wsfe(&io___21);
	    e_wsfe();
	}
	s_wsfe(&io___22);
	do_fio(&c__1, itext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, jtext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, (char *)&natom[i__ - 1], (ftnlen)sizeof(integer));
	i__2 = kb;
	for (j = ka; j <= i__2; ++j) {
	    do_fio(&c__1, (char *)&a[i__ + j * a_dim1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
/* L80: */
    }
    if (lb == nr) {
	goto L90;
    }
    la = lc + 1;
    lc += 40;
    s_wsfe(&io___23);
    e_wsfe();
    goto L70;
L90:
    if (kb == *nc) {
	return 0;
    }
    ka = kc + 1;
    kc += 6;
    if (nr > 25) {
	s_wsfe(&io___24);
	e_wsfe();
    }
    goto L60;


} /* matout_ */

