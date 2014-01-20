/* matou1.f -- translated by f2c (version 20020621).
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

struct {
    doublereal trans, rtr, sig;
    char name__[4], namo[1920];
    integer jndex[480];
    char ista[8];
} symres_;

#define symres_1 symres_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int matou1_(doublereal *a, doublereal *b, integer *ncx, 
	integer *nr, integer *ndim, integer *iflag)
{
    /* Initialized data */

    static char xyz[2*3] = " x" " y" " z";
    static char atorbs[2*9] = "S " "Px" "Py" "Pz" "x2" "xz" "z2" "yz" "xz";

    /* Format strings */
    static char fmt_100[] = "(//,2x,\002 Root No.\002,i5,9i8)";
    static char fmt_150[] = "(/12x,10(i3,1x,a4))";
    static char fmt_111[] = "(/10x,10f8.1)";
    static char fmt_110[] = "(/10x,10f8.3)";
    static char fmt_120[] = "(\002  \002)";
    static char fmt_130[] = "(\002 \002,2(1x,a2),i3,f8.4,10f8.4)";

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ka, kb, kc, la, lc, nc, lb, jhi, jlo, nfix, 
	    nsave, natom[360];
    static char itext[2*360], jtext[2*360];
    static logical allprt;

    /* Fortran I/O blocks */
    static cilist io___19 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___20 = { 0, 6, 0, fmt_150, 0 };
    static cilist io___21 = { 0, 6, 0, fmt_111, 0 };
    static cilist io___22 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___23 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___27 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___28 = { 0, 6, 0, fmt_130, 0 };


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


/*     OUTPUT TYPE (ROW LABELING) */
/*       IFLAG=1 : ORBITALS */
/*       IFLAG=2 : ORBITALS + SYMMETRY-DESIGNATORS */
/*       IFLAG=3 : ATOMS */
/*       IFLAG=4 : NUMBERS ONLY */
/*       IFLAG=5 : VIBRATIONS + SYMMETRY-DESIGNATIONS */


/* *********************************************************************** */
    /* Parameter adjustments */
    a_dim1 = *nr;
    a_offset = 1 + a_dim1 * 1;
    a -= a_offset;
    --b;

    /* Function Body */
/*      ------------------------------------------------- */
    allprt = i_indx(keywrd_1.keywrd, "ALLVEC", (ftnlen)241, (ftnlen)6) != 0;
    if (*iflag > 2 && *iflag != 5) {
	goto L30;
    }
    nc = *ncx;
    if (allprt) {
	goto L1988;
    }
    nsave = *ncx;
    nfix = max(molkst_1.nalpha,molkst_1.nclose);
    if (*iflag == 2 && nc > 16) {
	nc = nfix + 7;
    }
    if (nc > nsave) {
	nc = nsave;
    }
L1988:
    if (molkst_1.numat == 0) {
	goto L30;
    }
    if (molkst_1.nlast[molkst_1.numat - 1] != *nr) {
	goto L30;
    }
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	jlo = molkst_1.nfirst[i__ - 1];
	jhi = molkst_1.nlast[i__ - 1];
	l = molkst_1.nat[i__ - 1];
	k = 0;
	if (*iflag <= 2) {
	    i__2 = jhi;
	    for (j = jlo; j <= i__2; ++j) {
		++k;
		s_copy(itext + (j - 1 << 1), atorbs + (k - 1 << 1), (ftnlen)2,
			 (ftnlen)2);
		s_copy(jtext + (j - 1 << 1), elemts_1.elemnt + (l - 1 << 1), (
			ftnlen)2, (ftnlen)2);
		natom[j - 1] = i__;
/* L10: */
	    }
	} else {
	    jhi = (i__ - 1) * 3;
	    for (j = 1; j <= 3; ++j) {
		++k;
		s_copy(itext + (j + jhi - 1 << 1), xyz + (j - 1 << 1), (
			ftnlen)2, (ftnlen)2);
		s_copy(jtext + (j + jhi - 1 << 1), elemts_1.elemnt + (l - 1 <<
			 1), (ftnlen)2, (ftnlen)2);
/* L15: */
		natom[j + jhi - 1] = i__;
	    }
	}
/* L20: */
    }
    goto L50;
L30:
    *nr = abs(*nr);
    i__1 = *nr;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_copy(itext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
	s_copy(jtext + (i__ - 1 << 1), "  ", (ftnlen)2, (ftnlen)2);
	if (*iflag == 3) {
	    s_copy(jtext + (i__ - 1 << 1), elemts_1.elemnt + (molkst_1.nat[
		    i__ - 1] - 1 << 1), (ftnlen)2, (ftnlen)2);
	}
/* L40: */
	natom[i__ - 1] = i__;
    }
L50:
    ka = 1;
    kc = 8;
    if (allprt) {
	goto L1989;
    }
    if (*iflag == 2 && molkst_1.norbs > 16) {
	ka = nfix - 8;
    }
    if (ka < 1) {
	ka = 1;
    }
    if (*iflag == 2 && molkst_1.norbs > 16) {
	kc = ka + 7;
    }
L1989:
L60:
    kb = min(kc,nc);
    s_wsfe(&io___19);
    i__1 = kb;
    for (i__ = ka; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    if (*iflag == 2 || *iflag == 5) {
	s_wsfe(&io___20);
	i__1 = kb;
	for (i__ = ka; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&symres_1.jndex[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, symres_1.namo + (i__ - 1 << 2), (ftnlen)4);
	}
	e_wsfe();
    }
    if (b[1] != 0.) {
	if (*iflag == 5) {
	    s_wsfe(&io___21);
	    i__1 = kb;
	    for (i__ = ka; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&b[i__], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	} else {
	    s_wsfe(&io___22);
	    i__1 = kb;
	    for (i__ = ka; i__ <= i__1; ++i__) {
		do_fio(&c__1, (char *)&b[i__], (ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
    }
    s_wsfe(&io___23);
    e_wsfe();
    la = 1;
    lc = 40;
L70:
    lb = min(lc,*nr);
    i__1 = lb;
    for (i__ = la; i__ <= i__1; ++i__) {
	if (s_cmp(itext + (i__ - 1 << 1), " S", (ftnlen)2, (ftnlen)2) == 0) {
	    s_wsfe(&io___27);
	    e_wsfe();
	}
	s_wsfe(&io___28);
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
    if (lb == *nr) {
	goto L90;
    }
    la = lc + 1;
    lc += 40;
    goto L70;
L90:
    if (kb == nc) {
	return 0;
    }
    ka = kc + 1;
    kc += 8;
    goto L60;
} /* matou1_ */

