/* refer.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    char allref[34240]	/* was [107][4] */;
} refs_;

#define refs_1 refs_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int refer_(void)
{
    /* Initialized data */

    static logical mix = FALSE_;

    /* Format strings */
    static char fmt_40[] = "(/////10x,a,4(/10x,a))";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, mode;
    static logical allok, mixok, elemns[107];

    /* Fortran I/O blocks */
    static cilist io___8 = { 0, 6, 0, "(A,I3)", 0 };
    static cilist io___9 = { 0, 6, 0, "(A)", 0 };
    static cilist io___10 = { 0, 6, 0, fmt_40, 0 };
    static cilist io___11 = { 0, 6, 0, fmt_40, 0 };


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
    mixok = i_indx(keywrd_1.keywrd, "PARASOK", (ftnlen)241, (ftnlen)7) != 0;
    for (i__ = 1; i__ <= 102; ++i__) {
/* L10: */
	elemns[i__ - 1] = FALSE_;
    }
    if (i_indx(keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0) {
	mode = 4;
    } else if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0) {
	mode = 3;
    } else if (i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0) 
	    {
	mode = 2;
    } else {
	mode = 1;
    }
    s_copy(refs_1.allref + (mode * 107 - 9) * 80, " DUMMY ATOMS ARE USED; TH"
	    "ESE DO NOT AFFECT THE CALCULATION", (ftnlen)80, (ftnlen)58);
    s_copy(refs_1.allref + (mode * 107 - 8) * 80, " ", (ftnlen)80, (ftnlen)1);
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = molkst_1.nat[i__ - 1];
/* L20: */
	elemns[j - 1] = TRUE_;
    }
    allok = TRUE_;
    for (i__ = 1; i__ <= 102; ++i__) {
	if (elemns[i__ - 1]) {
	    if (i__ < 99 && ! mix && mode == 3) {
		mix = i_indx(refs_1.allref + (i__ + 213) * 80, "MNDO", (
			ftnlen)80, (ftnlen)4) != 0;
	    }
	    if (*(unsigned char *)&refs_1.allref[(i__ + mode * 107 - 108) * 
		    80] != ' ') {
		s_wsfe(&io___8);
		do_fio(&c__1, " DATA ARE NOT AVAILABLE FOR ELEMENT NO.", (
			ftnlen)39);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		e_wsfe();
		allok = FALSE_;
	    } else {
		s_wsfe(&io___9);
		do_fio(&c__1, refs_1.allref + (i__ + mode * 107 - 108) * 80, (
			ftnlen)80);
		e_wsfe();
	    }
	}
/* L30: */
    }
    if (mix && ! mixok) {
	s_wsfe(&io___10);
	do_fio(&c__1, "SOME ELEMENTS HAVE BEEN SPECIFIED FOR WHICH ONLY MNDO",
		 (ftnlen)53);
	do_fio(&c__1, "PARAMETERS ARE AVAILABLE.  SUCH MIXTURES OF METHODS A"
		"RE", (ftnlen)55);
	do_fio(&c__1, "VERY RISKY AND HAVE NOT BEEN FULLY TESTED.  IF YOU FE"
		"EL", (ftnlen)55);
	do_fio(&c__1, "THE RISK IS WORTH WHILE - CHECK THE MANUAL FIRST - TH"
		"EN", (ftnlen)55);
	do_fio(&c__1, "SPECIFY \"PARASOK\" IN THE KEYWORDS", (ftnlen)33);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (allok) {
	return 0;
    }
    s_wsfe(&io___11);
    do_fio(&c__1, "SOME ELEMENTS HAVE BEEN SPECIFIED FOR WHICH", (ftnlen)43);
    do_fio(&c__1, "NO PARAMETERS ARE AVAILABLE.  CALCULATION STOPPED.", (
	    ftnlen)50);
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* refer_ */

