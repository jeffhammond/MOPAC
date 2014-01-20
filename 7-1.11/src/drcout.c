/* drcout.f -- translated by f2c (version 20020621).
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
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    integer iivar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal xract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;
static integer c__9 = 9;
static integer c__2 = 2;

/* Subroutine */ int drcout_(doublereal *xyz3, doublereal *geo3, doublereal *
	vel3, integer *nvar, doublereal *time, doublereal *escf3, doublereal *
	ekin3, doublereal *gtot3, doublereal *etot3, doublereal *xtot3, 
	integer *iloop, doublereal *charge, doublereal *fract, char *text1, 
	char *text2, integer *ii, integer *jloop, ftnlen text1_len, ftnlen 
	text2_len)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    address a__1[2];
    integer i__1, i__2[2];
    doublereal d__1, d__2, d__3, d__4;
    char ch__1[3];

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_cmp(char *, char *, 
	    ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(void), do_fio(integer *,
	     char *, ftnlen), s_wsle(cilist *), do_lio(integer *, integer *, 
	    char *, ftnlen), e_wsle(void);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal gg[3];
    static integer ll;
    static logical drc;
    static doublereal vel[360]	/* was [3][120] */, xyz[360]	/* was [3][
	    120] */;
    static integer iel1[3];
    static doublereal escf, ekin;
    static integer ivar;
    static doublereal errr, etot, xtot;
    extern doublereal reada_(char *, integer *, ftnlen);
    static char alpha[2];
    static logical large;
    static integer iprint, prtkom, prtkey, prtitl;

    /* Fortran I/O blocks */
    static cilist io___9 = { 0, 6, 0, "(//,' FEMTOSECONDS  POINT  POTENTIAL "
	    "+'          ,' KINETIC  =  TOTAL     ERROR    REF%   MOVEMENT')", 
	    0 };
    static cilist io___10 = { 0, 6, 0, "(//,'     POINT   POTENTIAL  +  '   "
	    "             ,'ENERGY LOST   =   TOTAL      ERROR    REF%   MOVE"
	    "MENT')", 0 };
    static cilist io___16 = { 0, 6, 0, "(F10.3,I8,F12.5,F11.5,F11.5,        "
	    "               F10.5,' ',I5,3X,'%',A,A,I3)", 0 };
    static cilist io___17 = { 0, 6, 0, "(9X,A,F9.4,A)", 0 };
    static cilist io___18 = { 0, 6, 0, "(I8,F14.5,F13.5,F17.5,              "
	    "               F10.5,' ',I5,3X,'%',A,A,I3)", 0 };
    static cilist io___19 = { 0, 6, 0, "(9X,A,F9.4,A)", 0 };
    static cilist io___20 = { 0, 6, 0, "(F10.3,I8,F12.5,F11.5,F11.5,        "
	    "            F10.5,' ',I5,3X,'%',F8.4)", 0 };
    static cilist io___21 = { 0, 6, 0, "(F10.3,I8,F12.5,F11.5,F11.5,        "
	    "            F10.5,' ',I5,3X,'%',A,A,I3)", 0 };
    static cilist io___22 = { 0, 6, 0, "(I8,F14.5,F13.5,F17.5,              "
	    "            F10.5,' ',I5,3X,'%',F8.4)", 0 };
    static cilist io___23 = { 0, 6, 0, "(I8,F14.5,F13.5,F17.5,              "
	    "            F10.5,' ',I5,3X,'%',A,A,I3)", 0 };
    static cilist io___28 = { 0, 6, 0, 0, 0 };
    static cilist io___29 = { 0, 6, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, "(I4,3X,A2,3F11.5,2X,3F11.1)", 0 };
    static cilist io___33 = { 0, 6, 0, "(//10X,'FINAL GEOMETRY OBTAINED',33X"
	    ",'CHARGE')", 0 };
    static cilist io___34 = { 0, 6, 0, "(A)", 0 };
    static cilist io___38 = { 0, 6, 0, "(2X,A2,3(F12.6,I3),I4,2I3,F13.4,I5,A)"
	    , 0 };
    static cilist io___40 = { 0, 6, 0, "(2X,A2,3(F12.6,I3),I4,2I3,13X,I5,A)", 
	    0 };


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
/* ************************************************************ */
/*                                                           * */
/*    DRCOUT PRINTS THE GEOMETRY, ETC. FOR A DRC AT A        * */
/*    POSITION DETERMINED BY FRACT.                          * */
/*    ON INPUT XYZ3  = QUADRATIC EXPRESSION FOR THE GEOMETRY * */
/*             VEL3  = QUADRATIC EXPRESSION FOR THE VELOCITY * */
/*             ESCF3 = QUADRATIC EXPRESSION FOR THE P.E.     * */
/*             EKIN3 = QUADRATIC EXPRESSION FOR THE K.E.     * */
/*                                                           * */
/* ************************************************************ */
    /* Parameter adjustments */
    geo3 -= 4;
    vel3 -= 4;
    xyz3 -= 4;
    --escf3;
    --ekin3;
    --gtot3;
    --etot3;
    --xtot3;
    --charge;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	if (i_indx(keywrd_1.keywrd, "RESTART", (ftnlen)241, (ftnlen)7) == 0 ||
		 i_indx(keywrd_1.keywrd, "IRC=", (ftnlen)241, (ftnlen)4) != 0)
		 {
	    *jloop = 0;
	}
	for (i__ = 80; i__ >= 1; --i__) {
/* L10: */
	    if (*(unsigned char *)&keywrd_1.keywrd[i__ - 1] != ' ') {
		goto L20;
	    }
	}
	i__ = 1;
L20:
	prtkey = i__;
	for (i__ = 80; i__ >= 1; --i__) {
/* L30: */
	    if (*(unsigned char *)&titles_1.koment[i__ - 1] != ' ') {
		goto L40;
	    }
	}
	i__ = 1;
L40:
	prtkom = i__;
	for (i__ = 80; i__ >= 1; --i__) {
/* L50: */
	    if (*(unsigned char *)&titles_1.title[i__ - 1] != ' ') {
		goto L60;
	    }
	}
	i__ = 1;
L60:
	prtitl = i__;
	drc = i_indx(keywrd_1.keywrd, "DRC", (ftnlen)241, (ftnlen)3) != 0;
	i__ = i_indx(keywrd_1.keywrd, "LARGE", (ftnlen)241, (ftnlen)5);
	iprint = 10000;
	if (i__ != 0) {
	    iprint = 1;
	    i__ += 5;
	    i__1 = i__;
	    large = *(unsigned char *)&keywrd_1.keywrd[i__ - 1] == ' ' || 
		    s_cmp(keywrd_1.keywrd + i__1, "-", i__ + 1 - i__1, (
		    ftnlen)1) == 0;
	    if (*(unsigned char *)&keywrd_1.keywrd[i__ - 1] == '=') {
		iprint = (d__1 = reada_(keywrd_1.keywrd, &i__, (ftnlen)241), (
			integer) abs(d__1));
	    }
	}
    }
    if (*jloop == 0 || *jloop / iprint * iprint == *jloop) {
	if (drc) {
	    s_wsfe(&io___9);
	    e_wsfe();
	} else {
	    s_wsfe(&io___10);
	    e_wsfe();
	}
    }
    ++(*jloop);
/* #      FRACT=0.D0 */
/* Computing 2nd power */
    d__1 = *fract;
    escf = escf3[1] + escf3[2] * *fract + escf3[3] * (d__1 * d__1);
/* Computing 2nd power */
    d__1 = *fract;
    ekin = ekin3[1] + ekin3[2] * *fract + ekin3[3] * (d__1 * d__1);
/* Computing 2nd power */
    d__1 = *fract;
    etot = etot3[1] + etot3[2] * *fract + etot3[3] * (d__1 * d__1);
/* #      GTOT=GTOT3(1)+GTOT3(2)*FRACT+GTOT3(3)*FRACT**2 */
/* Computing 2nd power */
    d__1 = *fract;
    xtot = xtot3[1] + xtot3[2] * *fract + xtot3[3] * (d__1 * d__1);
/* Computing MIN */
/* Computing MAX */
    d__3 = -999.99999, d__4 = escf + ekin - etot;
    d__1 = 9999.99999, d__2 = max(d__3,d__4);
    errr = min(d__1,d__2);
    if (*ii != 0) {
	if (drc) {
	    s_wsfe(&io___16);
	    do_fio(&c__1, (char *)&(*time), (ftnlen)sizeof(doublereal));
	    i__1 = *iloop - 2;
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
	    d__1 = escf + ekin;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&errr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
	    do_fio(&c__1, text1, (ftnlen)3);
	    do_fio(&c__1, text2, (ftnlen)2);
	    do_fio(&c__1, (char *)&(*ii), (ftnlen)sizeof(integer));
	    e_wsfe();
	    s_wsfe(&io___17);
	    do_fio(&c__1, " MOVEMENT FROM START =", (ftnlen)22);
	    do_fio(&c__1, (char *)&xtot, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, " ANGSTROMS", (ftnlen)10);
	    e_wsfe();
	} else {
	    s_wsfe(&io___18);
	    i__1 = *iloop - 2;
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
	    d__1 = escf + ekin;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&errr, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
	    do_fio(&c__1, text1, (ftnlen)3);
	    do_fio(&c__1, text2, (ftnlen)2);
	    do_fio(&c__1, (char *)&(*ii), (ftnlen)sizeof(integer));
	    e_wsfe();
/* #      WRITE(6,'(24X,'' INTEGRATED GRADIENT ERROR ='',G10.3, */
/* #     1'' KCALS/ANGSTROM'')')GTOT */
	    s_wsfe(&io___19);
	    do_fio(&c__1, " MOVEMENT FROM START =", (ftnlen)22);
	    do_fio(&c__1, (char *)&xtot, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, " ANGSTROMS", (ftnlen)10);
	    e_wsfe();
	}
    } else {
	if (drc) {
	    if (s_cmp(text1, " ", (ftnlen)3, (ftnlen)1) == 0 && s_cmp(text2, 
		    " ", (ftnlen)2, (ftnlen)1) == 0) {
		s_wsfe(&io___20);
		do_fio(&c__1, (char *)&(*time), (ftnlen)sizeof(doublereal));
		i__1 = *iloop - 2;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
		d__1 = escf + ekin;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&errr, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&xtot, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else {
		s_wsfe(&io___21);
		do_fio(&c__1, (char *)&(*time), (ftnlen)sizeof(doublereal));
		i__1 = *iloop - 2;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
		d__1 = escf + ekin;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&errr, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
		do_fio(&c__1, text1, (ftnlen)3);
		do_fio(&c__1, text2, (ftnlen)2);
		e_wsfe();
	    }
	} else {
	    if (s_cmp(text1, " ", (ftnlen)3, (ftnlen)1) == 0 && s_cmp(text2, 
		    " ", (ftnlen)2, (ftnlen)1) == 0) {
		s_wsfe(&io___22);
		i__1 = *iloop - 2;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
		d__1 = escf + ekin;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&errr, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&xtot, (ftnlen)sizeof(doublereal));
		e_wsfe();
	    } else {
		s_wsfe(&io___23);
		i__1 = *iloop - 2;
		do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&escf, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&ekin, (ftnlen)sizeof(doublereal));
		d__1 = escf + ekin;
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&errr, (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
		do_fio(&c__1, text1, (ftnlen)3);
		do_fio(&c__1, text2, (ftnlen)2);
		e_wsfe();
	    }
	}
    }
    geokst_1.natoms = *nvar / 3;
    l = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    ++l;
/* Computing 2nd power */
	    d__1 = *fract;
	    vel[j + i__ * 3 - 4] = vel3[l * 3 + 1] + vel3[l * 3 + 2] * *fract 
		    + vel3[l * 3 + 3] * (d__1 * d__1);
/* L70: */
/* Computing 2nd power */
	    d__1 = *fract;
	    xyz[j + i__ * 3 - 4] = xyz3[l * 3 + 1] + xyz3[l * 3 + 2] * *fract 
		    + xyz3[l * 3 + 3] * (d__1 * d__1);
	}
/* L80: */
    }
    if (large && *jloop / iprint * iprint == *jloop) {
	s_wsle(&io___28);
	do_lio(&c__9, &c__1, "                CARTESIAN GEOMETRY           V"
		"ELOCITY (IN CM/SEC)", (ftnlen)65);
	e_wsle();
	s_wsle(&io___29);
	do_lio(&c__9, &c__1, "  ATOM        X          Y          Z         "
		"       X          Y          Z", (ftnlen)76);
	e_wsle();
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    ll = (i__ - 1) * 3 + 1;
	    s_wsfe(&io___31);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 1 << 1), 
		    (ftnlen)2);
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&xyz[j + i__ * 3 - 4], (ftnlen)sizeof(
			doublereal));
	    }
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&vel[j + i__ * 3 - 4], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
/* L90: */
	}
    }
    if (*jloop / iprint * iprint == *jloop) {
	ivar = 1;
	geokst_1.na[0] = 0;
	l = 0;
	s_wsfe(&io___33);
	e_wsfe();
	s_wsfe(&io___34);
	do_fio(&c__1, keywrd_1.keywrd, prtkey);
	do_fio(&c__1, titles_1.koment, prtkom);
	do_fio(&c__1, titles_1.title, prtitl);
	e_wsfe();
	l = 0;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    j = i__ / 26;
	    *(unsigned char *)alpha = (char) ('A' + j);
	    j = i__ - j * 26;
	    *(unsigned char *)&alpha[1] = (char) ('A' + j - 1);
/* $DOIT ASIS */
	    for (j = 1; j <= 3; ++j) {
/* L100: */
		iel1[j - 1] = 0;
	    }
L110:
	    if (geovar_1.loc[(ivar << 1) - 2] == i__) {
		iel1[geovar_1.loc[(ivar << 1) - 1] - 1] = 1;
		++ivar;
		goto L110;
	    }
	    if (i__ < 4) {
		iel1[2] = 0;
		if (i__ < 3) {
		    iel1[1] = 0;
		    if (i__ < 2) {
			iel1[0] = 0;
		    }
		}
	    }
	    if (geokst_1.labels[i__ - 1] < 99) {
		++l;
/* Computing 2nd power */
		d__1 = *fract;
		gg[0] = geo3[(i__ * 3 - 2) * 3 + 1] + geo3[(i__ * 3 - 2) * 3 
			+ 2] * *fract + geo3[(i__ * 3 - 2) * 3 + 3] * (d__1 * 
			d__1);
/* Computing 2nd power */
		d__1 = *fract;
		gg[1] = geo3[(i__ * 3 - 1) * 3 + 1] + geo3[(i__ * 3 - 1) * 3 
			+ 2] * *fract + geo3[(i__ * 3 - 1) * 3 + 3] * (d__1 * 
			d__1);
/* Computing 2nd power */
		d__1 = *fract;
		gg[2] = geo3[i__ * 9 + 1] + geo3[i__ * 9 + 2] * *fract + geo3[
			i__ * 9 + 3] * (d__1 * d__1);
		s_wsfe(&io___38);
		do_fio(&c__1, elemts_1.elemnt + (geokst_1.labels[i__ - 1] - 1 
			<< 1), (ftnlen)2);
		for (k = 1; k <= 3; ++k) {
		    do_fio(&c__1, (char *)&gg[k - 1], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, (char *)&iel1[k - 1], (ftnlen)sizeof(
			    integer));
		}
		do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&charge[l], (ftnlen)sizeof(doublereal));
		do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
/* Writing concatenation */
		i__2[0] = 2, a__1[0] = alpha;
		i__2[1] = 1, a__1[1] = "*";
		s_cat(ch__1, a__1, i__2, &c__2, (ftnlen)3);
		do_fio(&c__1, ch__1, (ftnlen)3);
		e_wsfe();
	    } else {
		s_wsfe(&io___40);
		do_fio(&c__1, elemts_1.elemnt + (geokst_1.labels[i__ - 1] - 1 
			<< 1), (ftnlen)2);
		for (k = 1; k <= 3; ++k) {
		    do_fio(&c__1, (char *)&gg[k - 1], (ftnlen)sizeof(
			    doublereal));
		    do_fio(&c__1, (char *)&iel1[k - 1], (ftnlen)sizeof(
			    integer));
		}
		do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)sizeof(
			integer));
		do_fio(&c__1, (char *)&(*jloop), (ftnlen)sizeof(integer));
/* Writing concatenation */
		i__2[0] = 2, a__1[0] = alpha;
		i__2[1] = 1, a__1[1] = "%";
		s_cat(ch__1, a__1, i__2, &c__2, (ftnlen)3);
		do_fio(&c__1, ch__1, (ftnlen)3);
		e_wsfe();
	    }
/* L120: */
	}
	geokst_1.na[0] = 99;
    }
    return 0;
} /* drcout_ */

