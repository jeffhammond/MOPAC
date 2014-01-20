/* datin.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal eisol[107], eheat[107];
} atomic_;

#define atomic_1 atomic_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__1 = 1;
static integer c__2 = 2;
static integer c__3 = 3;
static integer c__9 = 9;

/* Subroutine */ int datin_(void)
{
    /* Initialized data */

    static char numbrs[1*10] = " " "1" "2" "3" "4" "5" "6" "7" "8" "9";
    static char partyp[5*25] = "USS  " "UPP  " "UDD  " "ZS   " "ZP   " "ZD   "
	     "BETAS" "BETAP" "BETAD" "GSS  " "GSP  " "GPP  " "GP2  " "HSP  " 
	    "AM1  " "EXPC " "GAUSS" "ALP  " "GSD  " "GPD  " "GDD  " "FN1  " 
	    "FN2  " "FN3  " "ORB  ";
    static char elemnt[2*107] = "H " "HE" "LI" "BE" "B " "C " "N " "O " "F " 
	    "NE" "NA" "MG" "AL" "SI" "P " "S " "CL" "AR" "K " "CA" "SC" "TI" 
	    "V " "CR" "MN" "FE" "CO" "NI" "CU" "ZN" "GA" "GE" "AS" "SE" "BR" 
	    "KR" "RB" "SR" "Y " "ZR" "NB" "MO" "TC" "RU" "RH" "PD" "AG" "CD" 
	    "IN" "SN" "SB" "TE" "I " "XE" "CS" "BA" "LA" "CE" "PR" "ND" "PM" 
	    "SM" "EU" "GD" "TB" "DY" "HO" "ER" "TM" "YB" "LU" "HF" "TA" "W " 
	    "RE" "OS" "IR" "PT" "AU" "HG" "TL" "PB" "BI" "PO" "AT" "RN" "FR" 
	    "RA" "AC" "TH" "PA" "U " "NP" "PU" "AM" "CM" "BK" "CF" "XX" "FM" 
	    "MD" "CB" "++" "+ " "--" "- " "TV";

    /* System generated locals */
    address a__1[2], a__2[3];
    integer i__1, i__2[2], i__3[3];
    char ch__1[80], ch__2[3], ch__3[66], ch__4[6];
    olist o__1;
    cllist cl__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), f_open(olist *), s_rsfe(cilist *),
	     do_fio(integer *, char *, ftnlen), e_rsfe(void), s_cmp(char *, 
	    char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen), s_cat(char *, char **, 
	    integer *, integer *, ftnlen);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void), f_clos(cllist *);

    /* Local variables */
    static integer i__, j, k, ni, it, kfn;
    static doublereal eth;
    static char text[50];
    extern doublereal reada_(char *, integer *, ftnlen);
    static integer icapa, iline;
    static char files[64];
    static doublereal param;
    static integer ilowa, lpars;
    static char dummy[50];
    static integer ilowz;
    extern /* Subroutine */ int calpar_(void);
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer iparam;
    extern /* Subroutine */ int moldat_(integer *), update_(integer *, 
	    integer *, doublereal *, integer *);
    static integer nparas, ijpars[5000]	/* was [5][1000] */;
    static doublereal parsij[1000];
    static integer ielmnt;
    static char txtnew[50];

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 6, 0, "(//5X,' PARAMETER TYPE      ELEMENT  "
	    "  PARAMETER')", 0 };
    static cilist io___9 = { 1, 14, 1, "(A40)", 0 };
    static cilist io___17 = { 0, 6, 0, "('  FAULTY LINE:',A)", 0 };
    static cilist io___18 = { 0, 6, 0, "('  FAULTY LINE:',A)", 0 };
    static cilist io___19 = { 0, 6, 0, "('   NAME NOT FOUND')", 0 };
    static cilist io___24 = { 0, 6, 0, "(' ELEMENT NOT FOUND ')", 0 };
    static cilist io___25 = { 0, 6, 0, 0, 0 };
    static cilist io___31 = { 0, 6, 0, "(//10X,A)", 0 };
    static cilist io___32 = { 0, 6, 0, "(10X,A6,11X,A2,F17.6)", 0 };
    static cilist io___33 = { 0, 6, 0, "(10X,A6,11X,A2,F17.6)", 0 };


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
    i__ = i_indx(keywrd_1.keywrd, "EXTERNAL=", (ftnlen)241, (ftnlen)9) + 9;
    j = i_indx(keywrd_1.keywrd + (i__ - 1), " ", 241 - (i__ - 1), (ftnlen)1) 
	    + i__ - 1;
    getnam_(ch__1, (ftnlen)80, keywrd_1.keywrd + (i__ - 1), j - (i__ - 1));
    s_copy(files, ch__1, (ftnlen)64, (ftnlen)80);
    s_wsfe(&io___7);
    e_wsfe();
    o__1.oerr = 0;
    o__1.ounit = 14;
    o__1.ofnmlen = 64;
    o__1.ofnm = files;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    i__ = 0;
    nparas = 0;
L10:
    i__1 = s_rsfe(&io___9);
    if (i__1 != 0) {
	goto L90;
    }
    i__1 = do_fio(&c__1, text, (ftnlen)50);
    if (i__1 != 0) {
	goto L90;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L90;
    }
    ++nparas;
    if (s_cmp(text, " ", (ftnlen)50, (ftnlen)1) == 0) {
	goto L90;
    }
    if (i_indx(text, "END", (ftnlen)50, (ftnlen)3) != 0) {
	goto L90;
    }
    ilowa = 'a';
    ilowz = 'z';
    icapa = 'A';
/* *********************************************************************** */
    for (i__ = 1; i__ <= 50; ++i__) {
	iline = *(unsigned char *)&text[i__ - 1];
	if (iline >= ilowa && iline <= ilowz) {
	    *(unsigned char *)&text[i__ - 1] = (char) (iline + icapa - ilowa);
	}
/* L20: */
    }
/* *********************************************************************** */
    if (i_indx(text, "END", (ftnlen)50, (ftnlen)3) != 0) {
	goto L90;
    }
    for (j = 1; j <= 25; ++j) {
	if (j > 21) {
	    it = i_indx(text, "FN", (ftnlen)50, (ftnlen)2);
	    s_copy(txtnew, text, (ftnlen)50, it + 2);
	    if (i_indx(txtnew, partyp + (j - 1) * 5, (ftnlen)50, (ftnlen)5) !=
		     0) {
		goto L40;
	    }
	}
	if (i_indx(text, partyp + (j - 1) * 5, (ftnlen)50, (ftnlen)5) != 0) {
	    goto L40;
	}
/* L30: */
    }
    s_wsfe(&io___17);
    do_fio(&c__1, txtnew, (ftnlen)50);
    e_wsfe();
    s_wsfe(&io___18);
    do_fio(&c__1, text, (ftnlen)50);
    e_wsfe();
    s_wsfe(&io___19);
    e_wsfe();
    s_stop("", (ftnlen)0);
L40:
    iparam = j;
    if (iparam > 21) {
	i__ = i_indx(text, "FN", (ftnlen)50, (ftnlen)2);
	i__1 = i__ + 3;
	kfn = (integer) reada_(text, &i__1, (ftnlen)50);
    } else {
	kfn = 0;
	i__ = i_indx(text, partyp + (j - 1) * 5, (ftnlen)50, (ftnlen)5);
    }
    k = i_indx(text + (i__ - 1), " ", 50 - (i__ - 1), (ftnlen)1) + 1;
    s_copy(dummy, text + (k - 1), (ftnlen)50, 50 - (k - 1));
    s_copy(text, dummy, (ftnlen)50, (ftnlen)50);
    for (j = 1; j <= 107; ++j) {
/* L50: */
/* Writing concatenation */
	i__2[0] = 1, a__1[0] = " ";
	i__2[1] = 2, a__1[1] = elemnt + (j - 1 << 1);
	s_cat(ch__2, a__1, i__2, &c__2, (ftnlen)3);
	if (i_indx(text, ch__2, (ftnlen)50, (ftnlen)3) != 0) {
	    goto L60;
	}
    }
    s_wsfe(&io___24);
    e_wsfe();
    s_wsle(&io___25);
/* Writing concatenation */
    i__3[0] = 15, a__2[0] = " FAULTY LINE: \"";
    i__3[1] = 50, a__2[1] = text;
    i__3[2] = 1, a__2[2] = "\"";
    s_cat(ch__3, a__2, i__3, &c__3, (ftnlen)66);
    do_lio(&c__9, &c__1, ch__3, (ftnlen)66);
    e_wsle();
    s_stop("", (ftnlen)0);
L60:
    ielmnt = j;
    i__1 = i_indx(text, elemnt + (j - 1 << 1), (ftnlen)50, (ftnlen)2);
    param = reada_(text, &i__1, (ftnlen)50);
    i__1 = lpars;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (ijpars[i__ * 5 - 5] == kfn && ijpars[i__ * 5 - 4] == ielmnt && 
		ijpars[i__ * 5 - 3] == iparam) {
	    goto L80;
	}
/* L70: */
    }
    ++lpars;
    i__ = lpars;
L80:
    ijpars[i__ * 5 - 5] = kfn;
    ijpars[i__ * 5 - 4] = ielmnt;
    ijpars[i__ * 5 - 3] = iparam;
    parsij[i__ - 1] = param;
    goto L10;
L90:
    if (nparas == 0) {
	s_wsfe(&io___31);
	do_fio(&c__1, " EXTERNAL PARAMETERS FILE MISSING OR EMPTY", (ftnlen)
		42);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    cl__1.cerr = 0;
    cl__1.cunit = 14;
    cl__1.csta = 0;
    f_clos(&cl__1);
    for (j = 1; j <= 107; ++j) {
	for (k = 1; k <= 25; ++k) {
	    i__1 = lpars;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		iparam = ijpars[i__ * 5 - 3];
		kfn = ijpars[i__ * 5 - 5];
		ielmnt = ijpars[i__ * 5 - 4];
		if (iparam != k) {
		    goto L100;
		}
		if (ielmnt != j) {
		    goto L100;
		}
		param = parsij[i__ - 1];
		if (kfn != 0) {
		    s_wsfe(&io___32);
/* Writing concatenation */
		    i__3[0] = 3, a__2[0] = partyp + (iparam - 1) * 5;
		    i__3[1] = 1, a__2[1] = numbrs + kfn;
		    i__3[2] = 2, a__2[2] = "  ";
		    s_cat(ch__4, a__2, i__3, &c__3, (ftnlen)6);
		    do_fio(&c__1, ch__4, (ftnlen)6);
		    do_fio(&c__1, elemnt + (ielmnt - 1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&param, (ftnlen)sizeof(doublereal));
		    e_wsfe();
		} else {
		    s_wsfe(&io___33);
/* Writing concatenation */
		    i__2[0] = 5, a__1[0] = partyp + (iparam - 1) * 5;
		    i__2[1] = 1, a__1[1] = numbrs + kfn;
		    s_cat(ch__4, a__1, i__2, &c__2, (ftnlen)6);
		    do_fio(&c__1, ch__4, (ftnlen)6);
		    do_fio(&c__1, elemnt + (ielmnt - 1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&param, (ftnlen)sizeof(doublereal));
		    e_wsfe();
		}
		update_(&iparam, &ielmnt, &param, &kfn);
L100:
		;
	    }
/* L110: */
	}
/* L120: */
    }
    moldat_(&c__1);
    calpar_();
    atheat_1.atheat = 0.;
    eth = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ni = molkst_1.nat[i__ - 1];
	atheat_1.atheat += atomic_1.eheat[ni - 1];
/* L130: */
	eth += atomic_1.eisol[ni - 1];
    }
    atheat_1.atheat -= eth * 23.061;
    return 0;
} /* datin_ */

