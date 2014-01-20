/* getgeo.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer idum[2];
    doublereal react[198]	/* was [3][66] */, dumm1, dumm2;
} path_;

#define path_1 path_

struct {
    char simbol[3600];
} simbol_;

#define simbol_1 simbol_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    char ltxt[1], txtatm[960];
} atomtx_;

#define atomtx_1 atomtx_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__120 = 120;
static integer c__6 = 6;

/* Subroutine */ int getgeo_(integer *iread, integer *labels, doublereal *geo,
	 integer *lopt, integer *na, integer *nb, integer *nc, doublereal *
	ams, integer *natoms, logical *int__)
{
    /* Initialized data */

    static char elemnt[2*107] = "H " "HE" "LI" "BE" "B " "C " "N " "O " "F " 
	    "NE" "NA" "MG" "AL" "SI" "P " "S " "CL" "AR" "K " "CA" "SC" "TI" 
	    "V " "CR" "MN" "FE" "CO" "NI" "CU" "ZN" "GA" "GE" "AS" "SE" "BR" 
	    "KR" "RB" "SR" "Y " "ZR" "NB" "MO" "TC" "RU" "RH" "PD" "AG" "CD" 
	    "IN" "SN" "SB" "TE" "I " "XE" "CS" "BA" "LA" "CE" "PR" "ND" "PM" 
	    "SM" "EU" "GD" "TB" "DY" "HO" "ER" "TM" "YB" "LU" "HF" "TA" "W " 
	    "RE" "OS" "IR" "PT" "AU" "HG" "TL" "PB" "BI" "PO" "AT" "RN" "FR" 
	    "RA" "AC" "TH" "PA" "U " "NP" "PU" "AM" "CM" "BK" "CF" "XX" "FM" 
	    "MD" "CB" "++" "+ " "--" "- " "TV";
    static char comma[1] = ",";
    static char space[1] = " ";
    static char nine[1] = "9";
    static char zero[1] = "0";

    /* Format strings */
    static char fmt_260[] = "(i4,2x,3(f10.5,2x,i2,2x),3(i2,1x))";

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2, i__3[2];
    doublereal d__1, d__2;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double sqrt(doublereal), d_sign(doublereal *, doublereal *), asin(
	    doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal ca, sa;
    static integer jj;
    static char ele[2], tab[1];
    static doublereal xyz[360]	/* was [3][120] */;
    static integer itab;
    static doublereal real__;
    static integer khar;
    static char line[80];
    static integer ndmy;
    static char turn[1];
    static doublereal temp1, temp2;
    extern doublereal reada_(char *, integer *, ftnlen);
    static integer icapa, label, iline, icapz, ilowa;
    static doublereal value[40];
    extern /* Subroutine */ int geout_(integer *);
    static integer numat, iserr;
    static doublereal const__;
    static integer ilowz;
    static doublereal degree;
    static integer icomma;
    static logical ircdrc, leadsp;
    extern /* Subroutine */ int nuchar_(char *, doublereal *, integer *, 
	    ftnlen);
    static integer nvalue;
    static doublereal weight;
    static integer istart[40];
    static char string[80];
    static integer maxtxt;
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___16 = { 1, 0, 1, "(A)", 0 };
    static cilist io___29 = { 0, 6, 0, "('  ILLEGAL ATOMIC NUMBER')", 0 };
    static cilist io___32 = { 0, 6, 0, "('  UNRECOGNIZED ELEMENT NAME: (',A,"
	    "')')", 0 };
    static cilist io___33 = { 0, 6, 0, "(' FOR ATOM',I4,'  ISOTOPIC MASS:'  "
	    "                  ,F15.5)", 0 };
    static cilist io___34 = { 0, 6, 0, "(//10X,'****  MAX. NUMBER OF ATOMS A"
	    "LLOWED:',I4)", 0 };
    static cilist io___36 = { 0, 6, 0, "(A)", 0 };
    static cilist io___38 = { 0, 6, 0, "(A)", 0 };
    static cilist io___41 = { 0, 6, 0, "(//10X,' WARNING: INTERNAL COORDINAT"
	    "ES ARE ASSUMED -',/10X,' FOR THREE-ATOM SYSTEMS ',//)", 0 };
    static cilist io___42 = { 0, 6, 0, "(A)", 0 };
    static cilist io___43 = { 0, 5, 0, "(A)", 0 };
    static cilist io___46 = { 0, 6, 0, "(/10X,A)", 0 };
    static cilist io___53 = { 0, 6, 0, "(A)", 0 };
    static cilist io___54 = { 0, 6, 0, "(//10X,' AN UNOPTIMIZABLE GEOMETRIC "
	    "PARAMETER HAS',/10X,' BEEN MARKED FOR OPTIMIZATION. THIS IS A NO"
	    "N-FATAL '    ,'ERROR')", 0 };
    static cilist io___55 = { 0, 6, 0, "( ' ERROR DURING READ AT ATOM NUMBER"
	    " ', I3 )", 0 };
    static cilist io___56 = { 0, 6, 0, "(' DATA CURRENTLY READ IN ARE ')", 0 }
	    ;
    static cilist io___57 = { 0, 6, 0, fmt_260, 0 };


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

/*   GETGEO READS IN THE GEOMETRY. THE ELEMENT IS SPECIFIED BY IT'S */
/*          CHEMICAL SYMBOL, OR, OPTIONALLY, BY IT'S ATOMIC NUMBER. */

/*  ON INPUT   IREAD  = CHANNEL NUMBER FOR READ, NORMALLY 5 */
/*             AMS    = DEFAULT ATOMIC MASSES. */

/* ON OUTPUT LABELS = ATOMIC NUMBERS OF ALL ATOMS, INCLUDING DUMMIES. */
/*           GEO    = INTERNAL COORDINATES, IN ANGSTROMS, AND DEGREES. */
/*           LOPT   = INTEGER ARRAY, A '1' MEANS OPTIMIZE THIS PARAMETER, */
/*                    '0' MEANS DO NOT OPTIMIZE, AND A '-1' LABELS THE */
/*                    REACTION COORDINATE. */
/*           NA     = INTEGER ARRAY OF ATOMS (SEE DATA INPUT) */
/*           NB     = INTEGER ARRAY OF ATOMS (SEE DATA INPUT) */
/*           NC     = INTEGER ARRAY OF ATOMS (SEE DATA INPUT) */
/*           ATMASS = ATOMIC MASSES OF ATOMS. */
/* *********************************************************************** */
    /* Parameter adjustments */
    --ams;
    --nc;
    --nb;
    --na;
    lopt -= 4;
    geo -= 4;
    --labels;

    /* Function Body */
    *(unsigned char *)tab = '\t';
    ircdrc = i_indx(keywrd_1.keywrd, "IRC", (ftnlen)241, (ftnlen)3) + i_indx(
	    keywrd_1.keywrd, "DRC", (ftnlen)241, (ftnlen)3) != 0;
    ilowa = 'a';
    ilowz = 'z';
    icapa = 'A';
    icapz = 'Z';
    maxtxt = 0;
    *natoms = 0;
    numat = 0;
    iserr = 0;
    for (i__ = 1; i__ <= 360; ++i__) {
/* L10: */
	s_copy(simbol_1.simbol + (i__ - 1) * 10, "---", (ftnlen)10, (ftnlen)3)
		;
    }
L20:
    io___16.ciunit = *iread;
    i__1 = s_rsfe(&io___16);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)80);
    if (i__1 != 0) {
	goto L100001;
    }
    i__1 = e_rsfe();
L100001:
    if (i__1 < 0) {
	goto L130;
    }
    if (i__1 > 0) {
	goto L230;
    }
    if (s_cmp(line, " ", (ftnlen)80, (ftnlen)1) == 0) {
	goto L130;
    }
    ++(*natoms);

/*   SEE IF TEXT IS ASSOCIATED WITH THIS ELEMENT */

    i__ = i_indx(line, "(", (ftnlen)80, (ftnlen)1);
    if (i__ != 0) {

/*  YES, ELEMENT IS LABELLED. */

	k = i_indx(line, ")", (ftnlen)80, (ftnlen)1);
	s_copy(atomtx_1.txtatm + (*natoms - 1 << 3), line + (i__ - 1), (
		ftnlen)8, k - (i__ - 1));
/* Computing MAX */
	i__1 = maxtxt, i__2 = k - i__ + 1;
	maxtxt = max(i__1,i__2);
	i__1 = k;
/* Writing concatenation */
	i__3[0] = i__ - 1, a__1[0] = line;
	i__3[1] = 80 - i__1, a__1[1] = line + i__1;
	s_cat(string, a__1, i__3, &c__2, (ftnlen)80);
	s_copy(line, string, (ftnlen)80, (ftnlen)80);
    } else {
	s_copy(atomtx_1.txtatm + (*natoms - 1 << 3), " ", (ftnlen)8, (ftnlen)
		1);
    }
/*   CLEAN THE INPUT DATA */
/* *********************************************************************** */
    for (i__ = 1; i__ <= 80; ++i__) {
	iline = *(unsigned char *)&line[i__ - 1];
	if (iline >= ilowa && iline <= ilowz) {
	    *(unsigned char *)&line[i__ - 1] = (char) (iline + icapa - ilowa);
	}
/* L30: */
    }
/* *********************************************************************** */
    icomma = *(unsigned char *)&comma[0];
    itab = *(unsigned char *)tab;
    for (i__ = 1; i__ <= 80; ++i__) {
	khar = *(unsigned char *)&line[i__ - 1];
	if (khar == icomma || khar == itab) {
	    *(unsigned char *)&line[i__ - 1] = *(unsigned char *)&space[0];
	}
/* L40: */
    }

/*   INITIALIZE ISTART TO INTERPRET BLANKS AS ZERO'S */
    for (i__ = 1; i__ <= 10; ++i__) {
/* L50: */
	istart[i__ - 1] = 80;
    }

/* FIND INITIAL DIGIT OF ALL NUMBERS, CHECK FOR LEADING SPACES FOLLOWED */
/*     BY A CHARACTER AND STORE IN ISTART */
    leadsp = TRUE_;
    nvalue = 0;
    for (i__ = 1; i__ <= 80; ++i__) {
	if (leadsp && *(unsigned char *)&line[i__ - 1] != *(unsigned char *)&
		space[0]) {
	    ++nvalue;
	    istart[nvalue - 1] = i__;
	}
	leadsp = *(unsigned char *)&line[i__ - 1] == *(unsigned char *)&space[
		0];
/* L60: */
    }

/* ESTABLISH THE ELEMENT'S NAME AND ISOTOPE, CHECK FOR ERRORS OR E.O.DATA */

    weight = 0.;
    i__1 = istart[0] - 1;
    s_copy(string, line + i__1, (ftnlen)80, istart[1] - 1 - i__1);
    if (*(unsigned char *)string >= *(unsigned char *)&zero[0] && *(unsigned 
	    char *)string <= *(unsigned char *)&nine[0]) {
/*  ATOMIC NUMBER USED: NO ISOTOPE ALLOWED */
	label = (integer) reada_(string, &c__1, (ftnlen)80);
	if (label == 0) {
	    goto L120;
	}
	if (label < 0 || label > 107) {
	    s_wsfe(&io___29);
	    e_wsfe();
	    goto L240;
	}
	goto L80;
    }
/*  ATOMIC SYMBOL USED */
    real__ = (d__1 = reada_(string, &c__1, (ftnlen)80), abs(d__1));
    if (real__ < 1e-15) {
/*   NO ISOTOPE */
	s_copy(ele, string, (ftnlen)2, (ftnlen)2);
    } else {
	weight = real__;
	if (*(unsigned char *)&string[1] >= *(unsigned char *)&zero[0] && *(
		unsigned char *)&string[1] <= *(unsigned char *)&nine[0]) {
	    s_copy(ele, string, (ftnlen)2, (ftnlen)1);
	} else {
	    s_copy(ele, string, (ftnlen)2, (ftnlen)2);
	}
    }
/*   CHECK FOR ERROR IN ATOMIC SYMBOL */
    if (*(unsigned char *)ele == '-' && *(unsigned char *)&ele[1] != '-') {
	*(unsigned char *)&ele[1] = ' ';
    }
    for (i__ = 1; i__ <= 107; ++i__) {
	if (s_cmp(ele, elemnt + (i__ - 1 << 1), (ftnlen)2, (ftnlen)2) == 0) {
	    label = i__;
	    goto L80;
	}
/* L70: */
    }
    if (*(unsigned char *)ele == 'X') {
	label = 99;
	goto L80;
    }
    s_wsfe(&io___32);
    do_fio(&c__1, ele, (ftnlen)2);
    e_wsfe();
    goto L240;

/* ALL O.K. */

L80:
    if (label != 99) {
	++numat;
    }
    if (weight != 0.) {
	s_wsfe(&io___33);
	do_fio(&c__1, (char *)&(*natoms), (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&weight, (ftnlen)sizeof(doublereal));
	e_wsfe();
	atmass_1.atmass[numat - 1] = weight;
    } else {
	if (label != 99) {
	    atmass_1.atmass[numat - 1] = ams[label];
	}
    }
    if (*natoms > 120) {
	s_wsfe(&io___34);
	do_fio(&c__1, (char *)&c__120, (ftnlen)sizeof(integer));
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    labels[*natoms] = label;
    geo[*natoms * 3 + 1] = reada_(line, &istart[1], (ftnlen)80);
    geo[*natoms * 3 + 2] = reada_(line, &istart[3], (ftnlen)80);
    geo[*natoms * 3 + 3] = reada_(line, &istart[5], (ftnlen)80);
    if (ircdrc) {
	i__1 = istart[2] - 1;
	s_copy(turn, line + i__1, (ftnlen)1, istart[2] - i__1);
	if (*(unsigned char *)turn == 'T') {
	    lopt[*natoms * 3 + 1] = 1;
	    if (*natoms == 1) {
		s_wsfe(&io___36);
		do_fio(&c__1, " IN DRC MONITOR POTENTIAL ENERGY TURNING POIN"
			"TS", (ftnlen)47);
		e_wsfe();
	    }
	} else {
	    lopt[*natoms * 3 + 1] = 0;
	}
	i__1 = istart[4] - 1;
	s_copy(turn, line + i__1, (ftnlen)1, istart[4] - i__1);
	if (*(unsigned char *)turn == 'T') {
	    lopt[*natoms * 3 + 2] = 1;
	} else {
	    lopt[*natoms * 3 + 2] = 0;
	}
	i__1 = istart[6] - 1;
	s_copy(turn, line + i__1, (ftnlen)1, istart[6] - i__1);
	if (*(unsigned char *)turn == 'T') {
	    lopt[*natoms * 3 + 3] = 1;
	} else {
	    lopt[*natoms * 3 + 3] = 0;
	}
    } else {
	lopt[*natoms * 3 + 1] = (integer) reada_(line, &istart[2], (ftnlen)80)
		;
	lopt[*natoms * 3 + 2] = (integer) reada_(line, &istart[4], (ftnlen)80)
		;
	lopt[*natoms * 3 + 3] = (integer) reada_(line, &istart[6], (ftnlen)80)
		;
	for (i__ = 3; i__ <= 7; i__ += 2) {
	    i__1 = istart[i__ - 1] - 1;
	    i__2 = istart[i__ - 1] - 1;
	    if (*(unsigned char *)&line[i__1] >= icapa && *(unsigned char *)&
		    line[i__2] <= icapz) {
		iserr = 1;
	    }
/* L90: */
	}
    }
    na[*natoms] = (integer) reada_(line, &istart[7], (ftnlen)80);
    nb[*natoms] = (integer) reada_(line, &istart[8], (ftnlen)80);
    nc[*natoms] = (integer) reada_(line, &istart[9], (ftnlen)80);

/*  SPECIAL CASE OF USERS FORGETTING TO ADD DIHEDRAL DATA FOR ATOM 3 */

    if (*natoms == 3) {
	if (lopt[12] == 2) {
	    na[3] = 1;
	    nb[3] = 2;
	    geo[12] = 0.;
	    lopt[12] = 0;
	} else if (lopt[12] == 1 && (d__1 = geo[12] - 2., abs(d__1)) < 1e-4) {
	    na[3] = 2;
	    nb[3] = 1;
	    geo[12] = 0.;
	    lopt[12] = 0;
	}
    }
    if (lopt[*natoms * 3 + 1] > 1 || lopt[*natoms * 3 + 2] > 1 || lopt[*
	    natoms * 3 + 3] > 1) {
	iserr = 1;
    }
    if (iserr == 1) {

/*  MUST BE GAUSSIAN GEOMETRY INPUT */

	i__1 = *natoms;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    for (k = 1; k <= 3; ++k) {
		j = (integer) (geo[k + i__ * 3] + .4);
		if ((d__1 = geo[k + i__ * 3] - j, abs(d__1)) > 1e-5) {

/*   GEOMETRY CANNOT BE GAUSSIAN */

		    s_wsfe(&io___38);
		    do_fio(&c__1, " GEOMETRY IS FAULTY.  GEOMETRY READ IN IS",
			     (ftnlen)41);
		    e_wsfe();
		    const__ = .017453292519988887;
		    i__2 = *natoms;
		    for (l = 1; l <= i__2; ++l) {
			geo[l * 3 + 2] *= const__;
/* L100: */
			geo[l * 3 + 3] *= const__;
		    }
		    geout_(&c__6);
		    s_stop("", (ftnlen)0);
		}
/* L110: */
	    }
	}
	*natoms = -1;
	return 0;
    }
    goto L20;

/* ALL DATA READ IN, CLEAN UP AND RETURN */

L120:
    --(*natoms);
L130:
    na[2] = 1;
    *(unsigned char *)atomtx_1.ltxt = (char) maxtxt;
    if (*natoms > 3) {
	*int__ = na[4] != 0;
    } else {
	if (geo[11] < 10. && *natoms == 3) {
	    s_wsfe(&io___41);
	    e_wsfe();
	}
	*int__ = TRUE_;
    }
    if (*int__) {
	geo[8] = 0.;
    }

/*     READ IN VELOCITY VECTOR, IF PRESENT */

    if (i_indx(keywrd_1.keywrd, "VELO", (ftnlen)241, (ftnlen)4) > 0) {
	if (*int__) {
	    s_wsfe(&io___42);
	    do_fio(&c__1, " COORDINATES MUST BE CARTESIAN WHEN VELOCITY VECT"
		    "OR IS USED.", (ftnlen)60);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
/* #      WRITE(6,'(/10X,A)')'INITIAL VELOCITY VECTOR FOR DRC' */
	i__1 = *natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    s_rsfe(&io___43);
	    do_fio(&c__1, line, (ftnlen)80);
	    e_rsfe();
	    nuchar_(line, value, &ndmy, (ftnlen)80);
	    if (ndmy != 3) {
		s_wsfe(&io___46);
		do_fio(&c__1, "  THERE MUST BE EXACTLY THREE VELOCITY DATA P"
			"ER LINE", (ftnlen)52);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    for (j = 1; j <= 3; ++j) {
/* L140: */
		path_1.react[j + (i__ + 2) * 3 - 4] = value[j - 1];
	    }
/* #      WRITE(6,'(2X,A2,2X,3F13.5)')ELEMNT(LABELS(I)),(VALUE(J),J=1,3) */
/* L150: */
	}
	for (i__ = 1; i__ <= 3; ++i__) {
	    for (j = 1; j <= 2; ++j) {
/* L160: */
		path_1.react[i__ + j * 3 - 4] = geo[i__ + (j + 1) * 3] - geo[
			i__ + 3];
	    }
	}

/*  NOW TO ROTATE VELOCITY VECTOR TO SUIT INTERNAL COORDINATE DEFINITION */


/*   ROTATE AROUND THE 1-2 X-AXIS TO AS TO ELIMINATE REACT(3,2) */
/*   (PUT ATOM 2 IN X-Y PLANE) */
/* Computing 2nd power */
	d__1 = path_1.react[1];
/* Computing 2nd power */
	d__2 = path_1.react[2];
	sa = path_1.react[2] / sqrt(d__1 * d__1 + d__2 * d__2 + 1e-20);
/* Computing 2nd power */
	d__2 = sa;
	d__1 = sqrt(1. - d__2 * d__2);
	ca = d_sign(&d__1, &path_1.react[1]);
/* #      LABELS(NATOMS+1)=1 */
/* #      LABELS(NATOMS+2)=1 */
/* #      WRITE(6,*)' FIRST ROTATION, ABOUT 1-2 X-AXIS' */
	i__1 = *natoms + 2;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    temp1 = path_1.react[i__ * 3 - 2] * ca + path_1.react[i__ * 3 - 1]
		     * sa;
	    temp2 = -path_1.react[i__ * 3 - 2] * sa + path_1.react[i__ * 3 - 
		    1] * ca;
	    path_1.react[i__ * 3 - 2] = temp1;
	    path_1.react[i__ * 3 - 1] = temp2;
/* #      WRITE(6,'(2X,A2,2X,3F13.5)')ELEMNT(LABELS(I)),(REACT(J,I),J=1,3) */
/* L170: */
	}
/*   ROTATE AROUND THE 1-2 Z-AXIS TO AS TO ELIMINATE REACT(2,2) */
/*   (PUT ATOM 2 ON X AXIS) */
/* Computing 2nd power */
	d__1 = path_1.react[1];
/* Computing 2nd power */
	d__2 = path_1.react[0];
	ca = path_1.react[0] / sqrt(d__1 * d__1 + d__2 * d__2 + 1e-20);
/* Computing 2nd power */
	d__2 = ca;
	d__1 = sqrt(1. - d__2 * d__2);
	sa = d_sign(&d__1, &path_1.react[1]);
/* #      WRITE(6,*)' SECOND ROTATION, ABOUT 1-2 Z-AXIS' */
	i__1 = *natoms + 2;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    temp1 = path_1.react[i__ * 3 - 3] * ca + path_1.react[i__ * 3 - 2]
		     * sa;
	    temp2 = -path_1.react[i__ * 3 - 3] * sa + path_1.react[i__ * 3 - 
		    2] * ca;
	    path_1.react[i__ * 3 - 3] = temp1;
	    path_1.react[i__ * 3 - 2] = temp2;
/* #      WRITE(6,'(2X,A2,2X,3F13.5)')ELEMNT(LABELS(I)),(REACT(J,I),J=1,3) */
/* L180: */
	}
/*   ROTATE AROUND THE 2-3 X-AXIS TO AS TO ELIMINATE REACT(3,3) */
/*   (PUT ATOM 3 ON X-Y PLANE) */
/* Computing 2nd power */
	d__1 = path_1.react[4];
/* Computing 2nd power */
	d__2 = path_1.react[5];
	sa = path_1.react[5] / sqrt(d__1 * d__1 + d__2 * d__2 + 1e-20);
/* Computing 2nd power */
	d__2 = sa;
	d__1 = sqrt(1. - d__2 * d__2);
	ca = d_sign(&d__1, &path_1.react[4]);
/* #      WRITE(6,*)' THIRD ROTATION, ABOUT 2-3 X-AXIS' */
	i__1 = *natoms + 2;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    temp1 = path_1.react[i__ * 3 - 2] * ca + path_1.react[i__ * 3 - 1]
		     * sa;
	    temp2 = -path_1.react[i__ * 3 - 2] * sa + path_1.react[i__ * 3 - 
		    1] * ca;
	    path_1.react[i__ * 3 - 2] = temp1;
	    path_1.react[i__ * 3 - 1] = temp2;
/* #      WRITE(6,'(2X,A2,2X,3F13.5)')ELEMNT(LABELS(I)),(REACT(J,I),J=1,3) */
/* L190: */
	}

/*  STRIP OFF FIRST TWO COORDINATES; THESE WERE THE COORDINATE AXIS */
/*  DEFINITIONS */

	i__1 = *natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
/* L200: */
		path_1.react[j + i__ * 3 - 4] = path_1.react[j + (i__ + 2) * 
			3 - 4];
	    }
	}
    }
    if (! (*int__)) {
	i__1 = *natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
/* L210: */
		xyz[j + i__ * 3 - 4] = geo[j + i__ * 3];
	    }
	}
	degree = 90. / asin(1.);
	xyzint_(xyz, natoms, &na[1], &nb[1], &nc[1], &degree, &geo[4]);
	if (i_indx(keywrd_1.keywrd, " XYZ", (ftnlen)241, (ftnlen)4) == 0) {

/*  UNCONDITIONALLY SET FLAGS FOR INTERNAL COORDINATES */

	    for (i__ = 1; i__ <= 3; ++i__) {
		for (j = i__; j <= 3; ++j) {
/* L220: */
		    lopt[j + i__ * 3] = 0;
		}
	    }
	}
	if ((d__1 = geo[11] - 180., abs(d__1)) < 1e-4 || abs(geo[11]) < 1e-4) 
		{
	    s_wsfe(&io___53);
	    do_fio(&c__1, " DUE TO PROGRAM BUG, THE FIRST THREE ATOMS MUST N"
		    "OT LIE IN A STRAIGHT LINE.", (ftnlen)75);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    } else if (! ircdrc) {
	lopt[8] = 0;
	if (lopt[4] + lopt[5] + lopt[6] + lopt[9] + lopt[12] > 0) {
	    lopt[4] = 0;
	    lopt[5] = 0;
	    lopt[6] = 0;
	    lopt[9] = 0;
	    lopt[12] = 0;
	    s_wsfe(&io___54);
	    e_wsfe();
	}
    }
    if (na[3] == 0) {
	nb[3] = 1;
	na[3] = 2;
    }
    return 0;
/* ERROR CONDITIONS */
L230:
    if (*iread == 5) {
	s_wsfe(&io___55);
	do_fio(&c__1, (char *)&(*natoms), (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	*natoms = 0;
	return 0;
    }
L240:
    j = *natoms - 1;
    s_wsfe(&io___56);
    e_wsfe();
    i__1 = j;
    for (k = 1; k <= i__1; ++k) {
/* L250: */
	s_wsfe(&io___57);
	do_fio(&c__1, (char *)&labels[k], (ftnlen)sizeof(integer));
	for (jj = 1; jj <= 3; ++jj) {
	    do_fio(&c__1, (char *)&geo[jj + k * 3], (ftnlen)sizeof(doublereal)
		    );
	    do_fio(&c__1, (char *)&lopt[jj + k * 3], (ftnlen)sizeof(integer));
	}
	do_fio(&c__1, (char *)&na[k], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nb[k], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&nc[k], (ftnlen)sizeof(integer));
	e_wsfe();
    }
    s_stop("", (ftnlen)0);
    return 0;
} /* getgeo_ */

