/* getgeg.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

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
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;

/* Subroutine */ int getgeg_(integer *iread, integer *labels, doublereal *geo,
	 integer *na, integer *nb, integer *nc, doublereal *ams, integer *
	natoms, logical *int__)
{
    /* Initialized data */

    static char elemnt[2*107] = " H" "HE" "LI" "BE" " B" " C" " N" " O" " F" 
	    "NE" "NA" "MG" "AL" "SI" " P" " S" "CL" "AR" "K " "CA" "SC" "TI" 
	    " V" "CR" "MN" "FE" "CO" "NI" "CU" "ZN" "GA" "GE" "AS" "SE" "BR" 
	    "KR" "RB" "SR" " Y" "ZR" "NB" "MO" "TC" "RU" "RH" "PD" "AG" "CD" 
	    "IN" "SN" "SB" "TE" " I" "XE" "CS" "BA" "LA" "CE" "PR" "ND" "PM" 
	    "SM" "EU" "GD" "TB" "DY" "HO" "ER" "TM" "YB" "LU" "HF" "TA" " W" 
	    "RE" "OS" "IR" "PT" "AU" "HG" "TL" "PB" "BI" "PO" "AT" "RN" "FR" 
	    "RA" "AC" "TH" "PA" "U " "NP" "PU" "AM" "CM" "BK" "CF" "XX" "FM" 
	    "MD" "CB" "++" " +" "--" " -" "TV";

    /* System generated locals */
    address a__1[2], a__2[2];
    integer i__1, i__2, i__3[2], i__4[2];
    char ch__1[81], ch__2[3], ch__3[29];

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_cmp(char *, char *, ftnlen, ftnlen), i_indx(char *, char *, 
	    ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen), s_cat(char *,
	     char **, integer *, integer *, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double asin(doublereal);

    /* Local variables */
    static integer i__, j, k, l, n;
    static doublereal sum;
    static integer lgeo[300]	/* was [3][100] */;
    static char line[80], tgeo[12*3*100];
    static integer ivar, kerr, merr, nerr, lerr;
    extern doublereal reada_(char *, integer *, ftnlen);
    static integer iline, numat;
    static doublereal degree;
    static logical leadsp;
    extern /* Subroutine */ int getval_(char *, doublereal *, char *, ftnlen, 
	    ftnlen);
    static integer nvalue, istart[20];
    static char string[80];
    static integer maxtxt;

    /* Fortran I/O blocks */
    static cilist io___5 = { 1, 0, 1, "(A)", 0 };
    static cilist io___15 = { 0, 6, 0, "(2A)", 0 };
    static cilist io___16 = { 0, 6, 0, "(' FOR ATOM',I4,'  ISOTOPIC MASS:'  "
	    "            ,F15.5)", 0 };
    static cilist io___21 = { 1, 0, 1, "(A)", 0 };
    static cilist io___27 = { 0, 6, 0, "(A)", 0 };
    static cilist io___28 = { 0, 6, 0, "(A)", 0 };
    static cilist io___29 = { 0, 6, 0, "(2A)", 0 };
    static cilist io___30 = { 0, 6, 0, "(2A)", 0 };
    static cilist io___31 = { 0, 6, 0, "(2A)", 0 };
    static cilist io___32 = { 0, 6, 0, "(I4,A)", 0 };
    static cilist io___33 = { 0, 6, 0, "(A,I3,A)", 0 };


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
    --ams;
    --nc;
    --nb;
    --na;
    geo -= 4;
    --labels;

    /* Function Body */
    nerr = 0;
    *int__ = TRUE_;
    numat = 0;
    na[1] = 0;
    nb[1] = 0;
    nc[1] = 0;
    nb[2] = 0;
    nc[2] = 0;
    nc[3] = 0;
    maxtxt = 0;
    for (*natoms = 1; *natoms <= 100; ++(*natoms)) {
	io___5.ciunit = *iread;
	i__1 = s_rsfe(&io___5);
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
	if (s_cmp(line, " ", (ftnlen)80, (ftnlen)1) == 0) {
	    goto L70;
	}

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
	    s_copy(atomtx_1.txtatm + (*natoms - 1 << 3), " ", (ftnlen)8, (
		    ftnlen)1);
	}
/* *********************************************************************** */
	for (i__ = 1; i__ <= 80; ++i__) {
	    iline = *(unsigned char *)&line[i__ - 1];
	    if (iline >= 'a' && iline <= 'z') {
		*(unsigned char *)&line[i__ - 1] = (char) (iline + 'A' - 'a');
	    }
/* L10: */
	}
/* *********************************************************************** */
	nvalue = 0;
	leadsp = TRUE_;
	for (i__ = 1; i__ <= 80; ++i__) {
	    if (leadsp && *(unsigned char *)&line[i__ - 1] != ' ') {
		++nvalue;
		istart[nvalue - 1] = i__;
	    }
	    leadsp = *(unsigned char *)&line[i__ - 1] == ' ';
/* L20: */
	}
	for (j = 1; j <= 107; ++j) {
/* L30: */
	    i__1 = istart[0] - 1;
/* Writing concatenation */
	    i__3[0] = 1, a__1[0] = " ";
	    i__3[1] = istart[0] + 2 - i__1, a__1[1] = line + i__1;
	    s_cat(ch__1, a__1, i__3, &c__2, (ftnlen)81);
/* Writing concatenation */
	    i__4[0] = 2, a__2[0] = elemnt + (j - 1 << 1);
	    i__4[1] = 1, a__2[1] = " ";
	    s_cat(ch__2, a__2, i__4, &c__2, (ftnlen)3);
	    if (i_indx(ch__1, ch__2, istart[0] + 2 - i__1 + 1, (ftnlen)3) != 
		    0) {
		goto L40;
	    }
	}
	i__1 = istart[0] - 1;
/* Writing concatenation */
	i__3[0] = 1, a__1[0] = " ";
	i__3[1] = istart[0] + 2 - i__1, a__1[1] = line + i__1;
	s_cat(ch__1, a__1, i__3, &c__2, (ftnlen)81);
	if (i_indx(ch__1, " X", istart[0] + 2 - i__1 + 1, (ftnlen)2) != 0) {
	    j = 99;
	    goto L40;
	}
	s_wsfe(&io___15);
	do_fio(&c__1, " ELEMENT NOT RECOGNIZED: ", (ftnlen)25);
	i__1 = istart[0] - 1;
	do_fio(&c__1, line + i__1, istart[0] + 2 - i__1);
	e_wsfe();
	++nerr;
L40:
	labels[*natoms] = j;
	if (j != 99) {
	    ++numat;
/* Computing MAX */
	    i__1 = istart[1] - 1;
	    atmass_1.atmass[numat - 1] = reada_(line, istart, (max(i__1,1)));
	    if (atmass_1.atmass[numat - 1] > 1e-15) {
		s_wsfe(&io___16);
		do_fio(&c__1, (char *)&(*natoms), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&atmass_1.atmass[numat - 1], (ftnlen)
			sizeof(doublereal));
		e_wsfe();
	    } else {
		atmass_1.atmass[numat - 1] = ams[j];
	    }
/* #         WRITE(6,*)NATOMS,NUMAT,ATMASS(NUMAT) */
	}
	s_copy(tgeo + (*natoms * 3 - 3) * 12, " ", (ftnlen)12, (ftnlen)1);
	s_copy(tgeo + (*natoms * 3 - 2) * 12, " ", (ftnlen)12, (ftnlen)1);
	s_copy(tgeo + (*natoms * 3 - 1) * 12, " ", (ftnlen)12, (ftnlen)1);
	if (*natoms == 1) {
	    goto L50;
	}
	na[*natoms] = (integer) reada_(line, &istart[1], (ftnlen)80);
	i__1 = istart[2] - 1;
	getval_(line + i__1, &geo[*natoms * 3 + 1], tgeo + (*natoms * 3 - 3) *
		 12, 80 - i__1, (ftnlen)12);
	if (*natoms == 2) {
	    goto L50;
	}
	nb[*natoms] = (integer) reada_(line, &istart[3], (ftnlen)80);
	i__1 = istart[4] - 1;
	getval_(line + i__1, &geo[*natoms * 3 + 2], tgeo + (*natoms * 3 - 2) *
		 12, 80 - i__1, (ftnlen)12);
	if (*natoms == 3) {
	    goto L50;
	}
	nc[*natoms] = (integer) reada_(line, &istart[5], (ftnlen)80);
	i__1 = istart[6] - 1;
	getval_(line + i__1, &geo[*natoms * 3 + 3], tgeo + (*natoms * 3 - 1) *
		 12, 80 - i__1, (ftnlen)12);
L50:
/* L60: */
	;
    }
L70:
    --(*natoms);
    i__1 = *natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L80: */
	    lgeo[j + i__ * 3 - 4] = -1;
	}
    }
    ivar = -1;
    geovar_1.nvar = 0;
    geosym_1.ndep = 0;
    kerr = 0;
L90:
    io___21.ciunit = *iread;
    i__1 = s_rsfe(&io___21);
    if (i__1 != 0) {
	goto L180;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)80);
    if (i__1 != 0) {
	goto L180;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L180;
    }
    if (s_cmp(line, " ", (ftnlen)80, (ftnlen)1) == 0) {
	if (ivar == -1) {
	    merr = 0;
	    i__1 = *natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
/* L100: */
		    if (geo[j + i__ * 3] < -998.) {
			++merr;
		    }
		}
/* L110: */
	    }

/*  IF ALL SYMBOLS ARE DEFINED, THEN DO NOT READ 'FIXED' SYMBOLS */

	    if (merr == 0) {
		goto L180;
	    }
	    ivar = geovar_1.nvar;
	    goto L90;
	} else {
	    goto L180;
	}
    }
/* *********************************************************************** */
    for (i__ = 1; i__ <= 80; ++i__) {
	iline = *(unsigned char *)&line[i__ - 1];
	if (iline >= 'a' && iline <= 'z') {
	    *(unsigned char *)&line[i__ - 1] = (char) (iline + 'A' - 'a');
	}
/* L120: */
    }
/* *********************************************************************** */
    for (i__ = 1; i__ <= 80; ++i__) {
/* L130: */
	if (*(unsigned char *)&line[i__ - 1] != ' ') {
	    goto L140;
	}
    }
L140:
    i__1 = i__ + 12;
    for (l = i__; l <= i__1; ++l) {
/* L150: */
	if (*(unsigned char *)&line[l - 1] == ' ') {
	    goto L160;
	}
    }
L160:
    sum = reada_(line, &l, (ftnlen)80);
    n = 0;
    lerr = 0;
    i__1 = *natoms;
    for (j = 1; j <= i__1; ++j) {
	for (k = 1; k <= 3; ++k) {
	    if (s_cmp(tgeo + (k + j * 3 - 4) * 12, line + (i__ - 1), (ftnlen)
		    12, l - (i__ - 1)) == 0 || s_cmp(tgeo + ((k + j * 3 - 4) *
		     12 + 1), line + (i__ - 1), (ftnlen)11, l - (i__ - 1)) == 
		    0 && *(unsigned char *)&tgeo[(k + j * 3 - 4) * 12] == '-')
		     {
		if (lgeo[k + j * 3 - 4] != -1) {
		    lerr = 1;
		}
		++lgeo[k + j * 3 - 4];
		++n;
		geo[k + j * 3] = sum;
		if (n == 1) {
		    ++geovar_1.nvar;
		    geovar_1.loc[(geovar_1.nvar << 1) - 2] = j;
		    geovar_1.loc[(geovar_1.nvar << 1) - 1] = k;
		    geovar_1.xparam[geovar_1.nvar - 1] = sum;
		    s_copy(simbol_1.simbol + (geovar_1.nvar - 1) * 10, tgeo + 
			    (k + j * 3 - 4) * 12, (ftnlen)10, (ftnlen)12);
		    if (*(unsigned char *)&simbol_1.simbol[(geovar_1.nvar - 1)
			     * 10] == '-') {
			s_wsfe(&io___27);
			do_fio(&c__1, " NEGATIVE SYMBOLICS MUST BE PRECEEDED"
				" BY  THE POSITIVE EQUIVALENT", (ftnlen)65);
			e_wsfe();
			s_wsfe(&io___28);
/* Writing concatenation */
			i__3[0] = 19, a__1[0] = " FAULTY SYMBOLIC:  ";
			i__3[1] = 10, a__1[1] = simbol_1.simbol + (
				geovar_1.nvar - 1) * 10;
			s_cat(ch__3, a__1, i__3, &c__2, (ftnlen)29);
			do_fio(&c__1, ch__3, (ftnlen)29);
			e_wsfe();
			s_stop("", (ftnlen)0);
		    }
		}
		if (n > 1) {
		    ++geosym_1.ndep;
		    geosym_1.locpar[geosym_1.ndep - 1] = geovar_1.loc[(
			    geovar_1.nvar << 1) - 2];
		    geosym_1.idepfn[geosym_1.ndep - 1] = geovar_1.loc[(
			    geovar_1.nvar << 1) - 1];
		    if (*(unsigned char *)&tgeo[(k + j * 3 - 4) * 12] == '-') 
			    {
			geosym_1.idepfn[geosym_1.ndep - 1] = 14;
			if (geovar_1.loc[(geovar_1.nvar << 1) - 1] != 3) {
			    ++kerr;
			    s_wsfe(&io___29);
			    do_fio(&c__1, " ONLY DIHEDRAL SYMBOLICS CAN BE P"
				    "RECEEDED BY A \"-\" SIGN", (ftnlen)55);
			    e_wsfe();
			}
		    }
		    geosym_1.locdep[geosym_1.ndep - 1] = j;
		}
	    }
/* L170: */
	}
    }
    kerr += lerr;
    if (lerr == 1) {
	s_wsfe(&io___30);
	do_fio(&c__1, " THE FOLLOWING SYMBOL HAS BEEN DEFINED MORE THAN ONCE:"
		, (ftnlen)54);
	do_fio(&c__1, line + (i__ - 1), l - (i__ - 1));
	e_wsfe();
	++nerr;
    }
    if (n == 0) {
	s_wsfe(&io___31);
	do_fio(&c__1, " THE FOLLOWING SYMBOLIC WAS NOT USED:", (ftnlen)37);
	do_fio(&c__1, line + (i__ - 1), l - (i__ - 1));
	e_wsfe();
	++nerr;
    }
    goto L90;
L180:
    merr = 0;
    i__1 = *natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L190: */
	    if (geo[j + i__ * 3] < -998.) {
		++merr;
	    }
	}
/* #     WRITE(6,'(2X,A,3F12.6,3I4)')ELEMNT(LABELS(I)), */
/* #     1(GEO(J,I),J=1,3), NA(I), NB(I), NC(I) */
/* L200: */
    }
    if (merr != 0) {
	s_wsfe(&io___32);
	do_fio(&c__1, (char *)&merr, (ftnlen)sizeof(integer));
	do_fio(&c__1, " GEOMETRY VARIABLES WERE NOT DEFINED", (ftnlen)36);
	e_wsfe();
    }
    if (merr + kerr + nerr != 0) {
	s_wsfe(&io___33);
	do_fio(&c__1, " THE GEOMETRY DATA-SET CONTAINED", (ftnlen)32);
	i__1 = merr + kerr + nerr;
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	do_fio(&c__1, " ERRORS", (ftnlen)7);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }

/*  SORT PARAMETERS TO BE OPTIMIZED INTO INCREASING ORDER OF ATOMS */

    if (ivar != -1) {
	geovar_1.nvar = ivar;
    }
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	j = 100000;
	i__2 = geovar_1.nvar;
	for (l = i__; l <= i__2; ++l) {
	    if (j > (geovar_1.loc[(l << 1) - 2] << 2) + geovar_1.loc[(l << 1) 
		    - 1]) {
		k = l;
		j = (geovar_1.loc[(l << 1) - 2] << 2) + geovar_1.loc[(l << 1) 
			- 1];
	    }
/* L210: */
	}
	s_copy(string, simbol_1.simbol + (i__ - 1) * 10, (ftnlen)10, (ftnlen)
		10);
	s_copy(simbol_1.simbol + (i__ - 1) * 10, simbol_1.simbol + (k - 1) * 
		10, (ftnlen)10, (ftnlen)10);
	s_copy(simbol_1.simbol + (k - 1) * 10, string, (ftnlen)10, (ftnlen)80)
		;
	sum = geovar_1.xparam[i__ - 1];
	geovar_1.xparam[i__ - 1] = geovar_1.xparam[k - 1];
	geovar_1.xparam[k - 1] = sum;
	for (j = 1; j <= 2; ++j) {
	    l = geovar_1.loc[j + (i__ << 1) - 3];
	    geovar_1.loc[j + (i__ << 1) - 3] = geovar_1.loc[j + (k << 1) - 3];
/* L220: */
	    geovar_1.loc[j + (k << 1) - 3] = l;
	}
/* L230: */
    }
/* #      IF(NVAR.NE.0)WRITE(6,'(//,''    PARAMETERS TO BE OPTIMIZED'')') */
    degree = asin(1.) / 90;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* #      WRITE(6,'(2I6,F12.6)')LOC(1,I),LOC(2,I),XPARAM(I) */
/* L240: */
	if (geovar_1.loc[(i__ << 1) - 1] != 1) {
	    geovar_1.xparam[i__ - 1] *= degree;
	}
    }
/* #      IF(NDEP.NE.0)WRITE(6,'(//,''   SYMMETRY FUNCTIONS  '')') */
/* #      DO 28 I=1,NDEP */
/* #   28 WRITE(6,'(3I6)')LOCPAR(I),IDEPFN(I),LOCDEP(I) */
    *(unsigned char *)atomtx_1.ltxt = (char) maxtxt;
    return 0;
} /* getgeg_ */

/* Subroutine */ int getval_(char *line, doublereal *x, char *t, ftnlen 
	line_len, ftnlen t_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__;
    static char ch1[1], ch2[1];
    extern doublereal reada_(char *, integer *, ftnlen);

    *(unsigned char *)ch1 = *(unsigned char *)line;
    *(unsigned char *)ch2 = *(unsigned char *)&line[1];
    if ((*(unsigned char *)ch1 < 'A' || *(unsigned char *)ch1 > 'Z') && (*(
	    unsigned char *)ch2 < 'A' || *(unsigned char *)ch2 > 'Z')) {

/*   IS A NUMBER */

	*x = reada_(line, &c__1, (ftnlen)80);
	s_copy(t, " ", (ftnlen)12, (ftnlen)1);
    } else {
	i__ = i_indx(line, " ", (ftnlen)80, (ftnlen)1);
	s_copy(t, line, (ftnlen)12, i__);
	*x = -999.;
    }
    return 0;
} /* getval_ */

