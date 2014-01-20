/* getsym.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int getsym_(void)
{
    /* Initialized data */

    static char text[60*18] = " BOND LENGTH    IS SET EQUAL TO THE REFERENCE"
	    " BOND LENGTH   " " BOND ANGLE     IS SET EQUAL TO THE REFERENCE "
	    "BOND ANGLE    " " DIHEDRAL ANGLE IS SET EQUAL TO THE REFERENCE D"
	    "IHEDRAL ANGLE" " DIHEDRAL ANGLE VARIES AS  90 DEGREES - REFERENC"
	    "E DIHEDRAL  " " DIHEDRAL ANGLE VARIES AS  90 DEGREES + REFERENCE"
	    " DIHEDRAL  " " DIHEDRAL ANGLE VARIES AS 120 DEGREES - REFERENCE "
	    "DIHEDRAL  " " DIHEDRAL ANGLE VARIES AS 120 DEGREES + REFERENCE D"
	    "IHEDRAL  " " DIHEDRAL ANGLE VARIES AS 180 DEGREES - REFERENCE DI"
	    "HEDRAL  " " DIHEDRAL ANGLE VARIES AS 180 DEGREES + REFERENCE DIH"
	    "EDRAL  " " DIHEDRAL ANGLE VARIES AS 240 DEGREES - REFERENCE DIHE"
	    "DRAL  " " DIHEDRAL ANGLE VARIES AS 240 DEGREES + REFERENCE DIHED"
	    "RAL  " " DIHEDRAL ANGLE VARIES AS 270 DEGREES - REFERENCE DIHEDR"
	    "AL  " " DIHEDRAL ANGLE VARIES AS 270 DEGREES - REFERENCE DIHEDRA"
	    "L  " " DIHEDRAL ANGLE VARIES AS - REFERENCE DIHEDRAL            "
	    "  " " BOND LENGTH VARIES AS HALF THE REFERENCE BOND LENGTH       "
	     " BOND ANGLE VARIES AS HALF THE REFERENCE BOND ANGLE         " 
	    " BOND ANGLE VARIES AS 180 DEGREES - REFERENCE BOND ANGLE    " 
	    " THE USER HAS TO SUPPLY THIS FUNCTION IN DEPVAR             ";

    /* Format strings */
    static char fmt_10[] = "(///5x,\002PARAMETER DEPENDENCE DATA\002//\002  "
	    "      REFERENCE ATOM      FUNCTION NO.    DEPENDENT ATOM(S)\002)";
    static char fmt_60[] = "(i13,i19,i14,11i3,10(/,43x,12i3))";
    static char fmt_80[] = "(/10x,\002   DESCRIPTIONS OF THE FUNCTIONS USE"
	    "D\002,/)";
    static char fmt_110[] = "(i4,5x,a)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), s_rsfe(cilist *), do_fio(integer *
	    , char *, ftnlen), e_rsfe(void);

    /* Local variables */
    static integer i__, j, ll;
    static char line[80];
    static doublereal value[40];
    extern /* Subroutine */ int nuchar_(char *, doublereal *, integer *, 
	    ftnlen);
    static integer ivalue[40], nvalue;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 6, 0, fmt_10, 0 };
    static cilist io___3 = { 0, 5, 1, "(A)", 0 };
    static cilist io___10 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___12 = { 0, 6, 0, fmt_80, 0 };
    static cilist io___13 = { 0, 6, 0, fmt_110, 0 };


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
/* *********************************************************************** */

/*   GETSYM READS IN THE SYMMETRY DEPENDENCE RELATIONSHIPS. */

/*   ON EXIT     NDEP    = NUMBER OF SYMMETRY RELATIONS. */
/*               LOCPAR  = ARRAY OF REFERENCE FUNCTION INDICES. */
/*               IDEPFN  = ARRAY OF REFERENCE ATOM LOCATIONS. */
/*               LOCDEP  = ARRAY OF DEPENDENT ATOM LOCATIONS. */

/* *********************************************************************** */

/*     LOCDEP IS THE ATOM WHOSE COORDINATES DEPEND ON THE COORDINATES OF */
/*     LOCPAR. */
/*     LOCPAR IS THE ATOM WHOSE COORDINATES ARE USED TO CALCULATE THOSE */
/*     OF LOCDEP */
/*     IDEPFN POINTS TO THE PARTICULAR FUNCTION TO BE USED (SEE NDDO) */

/* *********************************************************************** */

/* TITLE OUTPUT */
    s_wsfe(&io___2);
    e_wsfe();

/* INPUT SYMMETRY : FUNCTION, REFERANCE PARAMETER, AND DEPENDENT ATOMS */

    geosym_1.ndep = 0;
L20:
    i__1 = s_rsfe(&io___3);
    if (i__1 != 0) {
	goto L70;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)80);
    if (i__1 != 0) {
	goto L70;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L70;
    }
    nuchar_(line, value, &nvalue, (ftnlen)80);
/*   INTEGER VALUES */
    i__1 = nvalue;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	ivalue[i__ - 1] = (integer) value[i__ - 1];
    }
/*   FILL THE LOCDEP ARRAY */
    if (nvalue == 0 || ivalue[2] == 0) {
	goto L70;
    }
    i__1 = nvalue;
    for (i__ = 3; i__ <= i__1; ++i__) {
	if (ivalue[i__ - 1] == 0) {
	    goto L50;
	}
	++geosym_1.ndep;
	geosym_1.locdep[geosym_1.ndep - 1] = ivalue[i__ - 1];
	geosym_1.locpar[geosym_1.ndep - 1] = ivalue[0];
	geosym_1.idepfn[geosym_1.ndep - 1] = ivalue[1];
/* L40: */
    }
L50:
    ll = i__ - 1;
    s_wsfe(&io___10);
    do_fio(&c__1, (char *)&ivalue[0], (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ivalue[1], (ftnlen)sizeof(integer));
    i__1 = ll;
    for (j = 3; j <= i__1; ++j) {
	do_fio(&c__1, (char *)&ivalue[j - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    goto L20;

/* CLEAN UP */
L70:
    s_wsfe(&io___12);
    e_wsfe();
    for (j = 1; j <= 18; ++j) {
	i__1 = geosym_1.ndep;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (geosym_1.idepfn[i__ - 1] == j) {
		goto L100;
	    }
/* L90: */
	}
	goto L120;
L100:
	s_wsfe(&io___13);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	do_fio(&c__1, text + (j - 1) * 60, (ftnlen)60);
	e_wsfe();
L120:
	;
    }
    return 0;
} /* getsym_ */

