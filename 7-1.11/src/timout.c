/* timout.f -- translated by f2c (version 20020621).
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
    doublereal core[107];
} core_;

#define core_1 core_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int timout_(integer *nout, doublereal *tim)
{
    /* Initialized data */

    static doublereal hrspd = 24.;
    static doublereal minphr = 60.;
    static doublereal secpd = 86400.;
    static doublereal secpmi = 60.;

    /* Format strings */
    static char fmt_10[] = "(10x,\002COMPUTATION TIME = \002,i2,1x,\002DAY"
	    "S\002,2x,i2,1x,\002HOURS\002,1x,i2,1x,\002MINUTES AND\002,1x,f7."
	    "3,1x,\002SECONDS\002)";
    static char fmt_20[] = "(10x,\002COMPUTATION TIME = \002,i2,1x,\002DA"
	    "Y\002,2x,i2,1x,\002HOURS\002,1x,i2,1x,\002MINUTES AND\002,1x,f7."
	    "3,1x,\002SECONDS\002)";
    static char fmt_30[] = "(10x,\002COMPUTATION TIME = \002i2,1x,\002HOUR"
	    "S\002,1x,i2,1x,\002MINUTES AND\002,1x,f7.3,1x,\002SECONDS\002)";
    static char fmt_40[] = "(10x,\002COMPUTATION TIME = \002,i2,1x,\002MINUT"
	    "ES AND\002,1x,f7.3,1x,\002SECONDS\002)";
    static char fmt_50[] = "(10x,\002COMPUTATION TIME = \002,f7.3,1x,\002SEC"
	    "ONDS\002)";

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal secs, days, mins;
    static integer idays, imins;
    static doublereal hours;
    static integer ihours;

    /* Fortran I/O blocks */
    static cilist io___12 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___13 = { 0, 0, 0, fmt_20, 0 };
    static cilist io___14 = { 0, 0, 0, fmt_30, 0 };
    static cilist io___15 = { 0, 0, 0, fmt_40, 0 };
    static cilist io___16 = { 0, 0, 0, fmt_50, 0 };



/*     CONVERT THE TIME FROM SECONDS TO DAYS, HOURS, MINUTES, AND SECONDS */





    days = *tim / secpd;
    idays = (integer) days;
    hours = (days - (real) idays) * hrspd;
    ihours = (integer) hours;
    mins = (hours - (real) ihours) * minphr;
    imins = (integer) mins;
    secs = (mins - (real) imins) * secpmi;

    if (idays > 1) {
	io___12.ciunit = *nout;
	s_wsfe(&io___12);
	do_fio(&c__1, (char *)&idays, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ihours, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&imins, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&secs, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else if (idays == 1) {
	io___13.ciunit = *nout;
	s_wsfe(&io___13);
	do_fio(&c__1, (char *)&idays, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ihours, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&imins, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&secs, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else if (ihours > 0) {
	io___14.ciunit = *nout;
	s_wsfe(&io___14);
	do_fio(&c__1, (char *)&ihours, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&imins, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&secs, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else if (imins > 0) {
	io___15.ciunit = *nout;
	s_wsfe(&io___15);
	do_fio(&c__1, (char *)&imins, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&secs, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else {
	io___16.ciunit = *nout;
	s_wsfe(&io___16);
	do_fio(&c__1, (char *)&secs, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }

    return 0;
} /* timout_ */

/* Subroutine */ int mpcpop_(doublereal *c__, integer *icok)
{
    /* Format strings */
    static char fmt_60[] = "(5x,i4,4x,f11.6,6x,f11.6)";
    static char fmt_70[] = "(2f12.6)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, if__, il;
    static doublereal pop[120], sum, chrg[120];

    /* Fortran I/O blocks */
    static cilist io___17 = { 1, 16, 0, "(I4,5X' MULLIKEN POPULATION AND CHA"
	    "RGE')", 0 };
    static cilist io___26 = { 0, 6, 0, "(///10X,'MULLIKEN POPULATIONS AND CH"
	    "ARGES')", 0 };
    static cilist io___27 = { 0, 6, 0, fmt_60, 0 };
    static cilist io___28 = { 1, 16, 0, fmt_70, 0 };
    static cilist io___29 = { 0, 6, 0, "(A)", 0 };



/* This subroutine calculates the total Mulliken populations on the */
/*   atoms by summing the diagonal elements from the  Mulliken */
/*   population analysis. */

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
    /* Parameter adjustments */
    --c__;

    /* Function Body */
    i__1 = s_wsfe(&io___17);
    if (i__1 != 0) {
	goto L40;
    }
    i__1 = do_fio(&c__1, (char *)&(*icok), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L40;
    }
    i__1 = e_wsfe();
    if (i__1 != 0) {
	goto L40;
    }

/* ICOK = 1 ==> PRINT POPULATIONS */
/* ICOK = 0 ==> KEYWORD mulliken = .f. */
/*         NO POPULATION ANALYSIS PERFORMED */

    if (*icok != 0) {
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if__ = molkst_1.nfirst[i__ - 1];
	    il = molkst_1.nlast[i__ - 1];
	    sum = 0.;
	    pop[i__ - 1] = 0.;
	    chrg[i__ - 1] = 0.;
	    i__2 = il;
	    for (j = if__; j <= i__2; ++j) {

/*    Diagonal element of mulliken matrix */

		sum += c__[j * (j + 1) / 2];
/* L10: */
	    }
	    k = molkst_1.nat[i__ - 1];

/*    Mulliken population for i'th atom */

	    pop[i__ - 1] = sum;
	    chrg[i__ - 1] = core_1.core[k - 1] - pop[i__ - 1];
/* L20: */
	}
	s_wsfe(&io___26);
	e_wsfe();
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    s_wsfe(&io___27);
	    do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&pop[j - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&chrg[j - 1], (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    i__2 = s_wsfe(&io___28);
	    if (i__2 != 0) {
		goto L40;
	    }
	    i__2 = do_fio(&c__1, (char *)&pop[j - 1], (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L40;
	    }
	    i__2 = do_fio(&c__1, (char *)&chrg[j - 1], (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L40;
	    }
	    i__2 = e_wsfe();
	    if (i__2 != 0) {
		goto L40;
	    }
/* L30: */
	}
    }
    return 0;
L40:
    s_wsfe(&io___29);
    do_fio(&c__1, "Error writing SYBYL Mulliken population output", (ftnlen)
	    46);
    e_wsfe();
    return 0;
/* L50: */
} /* mpcpop_ */


/* This subroutine writes out the optimized geometry and atomic charges */
/*   for a MOPAC run. */

/* Subroutine */ int mpcsyb_(integer *numat, doublereal *coord, doublereal *
	chr, integer *icok, doublereal *eigs, integer *nclose, doublereal *
	funct, doublereal *eionis, integer *kchrge, doublereal *dip)
{
    /* Format strings */
    static char fmt_20[] = "(4f12.6,2x,i4,2x,\002HOMOs,LUMOs,# of occupied M"
	    "Os\002)";

    /* System generated locals */
    integer i__1, i__2;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, i1, i2;

    /* Fortran I/O blocks */
    static cilist io___30 = { 1, 16, 0, "(2I4)", 0 };
    static cilist io___32 = { 1, 16, 0, "(4F12.6)", 0 };
    static cilist io___36 = { 1, 16, 0, fmt_20, 0 };
    static cilist io___37 = { 1, 16, 0, "(2F12.6,4X,'HF and IP')", 0 };
    static cilist io___38 = { 1, 16, 0, "(I4,F10.3,'  Charge,Dipole Moment')",
	     0 };
    static cilist io___39 = { 0, 6, 0, "(A)", 0 };


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
/*  Write out the charge flag and number of atoms */
    /* Parameter adjustments */
    --chr;
    coord -= 4;
    --eigs;

    /* Function Body */
    i__1 = s_wsfe(&io___30);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&(*icok), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&(*numat), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_wsfe();
    if (i__1 != 0) {
	goto L30;
    }
/*  Write out the coordinates and charges */
    i__1 = *numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	i__2 = s_wsfe(&io___32);
	if (i__2 != 0) {
	    goto L30;
	}
	for (j = 1; j <= 3; ++j) {
	    i__2 = do_fio(&c__1, (char *)&coord[j + i__ * 3], (ftnlen)sizeof(
		    doublereal));
	    if (i__2 != 0) {
		goto L30;
	    }
	}
	i__2 = do_fio(&c__1, (char *)&chr[i__], (ftnlen)sizeof(doublereal));
	if (i__2 != 0) {
	    goto L30;
	}
	i__2 = e_wsfe();
	if (i__2 != 0) {
	    goto L30;
	}
/* L10: */
    }
/* Computing MAX */
    i__1 = 1, i__2 = *nclose - 1;
    i1 = max(i__1,i__2);
/* Computing MIN */
    i__1 = 300, i__2 = *nclose + 2;
    i2 = min(i__1,i__2);

/*  Write out the 2 highest and 2 lowest orbital energies */

    i__1 = s_wsfe(&io___36);
    if (i__1 != 0) {
	goto L30;
    }
    i__2 = i2;
    for (j = i1; j <= i__2; ++j) {
	i__1 = do_fio(&c__1, (char *)&eigs[j], (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L30;
	}
    }
    i__1 = do_fio(&c__1, (char *)&(*nclose), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_wsfe();
    if (i__1 != 0) {
	goto L30;
    }

/*  Write out the Heat of Formation and Ionisation Potential */

    i__1 = s_wsfe(&io___37);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&(*eionis), (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_wsfe();
    if (i__1 != 0) {
	goto L30;
    }

/*  Write out the Dipole Moment */

    if (*kchrge != 0) {
	*dip = 0.;
    }
    i__1 = s_wsfe(&io___38);
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&(*kchrge), (ftnlen)sizeof(integer));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = do_fio(&c__1, (char *)&(*dip), (ftnlen)sizeof(doublereal));
    if (i__1 != 0) {
	goto L30;
    }
    i__1 = e_wsfe();
    if (i__1 != 0) {
	goto L30;
    }
    return 0;
L30:
    s_wsfe(&io___39);
    do_fio(&c__1, "Error writing SYBYL MOPAC output", (ftnlen)32);
    e_wsfe();
    return 0;
} /* mpcsyb_ */

