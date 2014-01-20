/* forsav.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int forsav_(doublereal *time, doublereal *deldip, integer *
	ipt, doublereal *fmatrx, doublereal *coord, integer *nvar, doublereal 
	*refh, doublereal *evecs, integer *jstart, doublereal *fconst)
{
    /* System generated locals */
    integer i__1, i__2;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_rew(alist *), s_rsue(cilist *), do_uio(integer 
	    *, char *, ftnlen), e_rsue(void), s_wsue(cilist *), e_wsue(void), 
	    f_clos(cllist *), s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, n33, ir, iw;
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer linear;

    /* Fortran I/O blocks */
    static cilist io___3 = { 1, 0, 1, 0, 0 };
    static cilist io___5 = { 0, 0, 0, 0, 0 };
    static cilist io___7 = { 1, 0, 1, 0, 0 };
    static cilist io___8 = { 0, 0, 0, 0, 0 };
    static cilist io___11 = { 0, 0, 0, 0, 0 };
    static cilist io___12 = { 0, 0, 0, 0, 0 };
    static cilist io___13 = { 0, 0, 0, 0, 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };
    static cilist io___17 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, 0, 0 };
    static cilist io___19 = { 0, 10, 0, 0, 0 };
    static cilist io___20 = { 0, 10, 0, 0, 0 };
    static cilist io___21 = { 0, 6, 0, "(10X,'INSUFFICIENT DATA ON DISK FILE"
	    "S FOR A FORCE ',   'CALCULATION',/10X,'RESTART. PERHAPS THIS STA"
	    "RTED OF AS A ',  'FORCE CALCULATION ')", 0 };
    static cilist io___22 = { 0, 6, 0, "(10X,'BUT THE GEOMETRY HAD TO BE OPT"
	    "IMIZED FIRST, ',   'IN WHICH CASE ',/10X,'REMOVE THE KEY-WORD \""
	    "FORCE\".')", 0 };
    static cilist io___23 = { 0, 6, 0, "(//10X,'NO RESTART FILE EXISTS!')", 0 
	    };


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

/*  FORSAV SAVES AND RESTORES DATA USED IN THE FORCE CALCULATION. */

/* ON INPUT TIME = TOTAL TIME ELAPSED SINCE THE START OF THE CALCULATION. */
/*          IPT  = LINE OF FORCE MATRIX REACHED, IF IN WRITE MODE, */
/*               = 0 IF IN READ MODE. */
/*        FMATRX = FORCE MATRIX */
/* *********************************************************************** */
    /* Parameter adjustments */
    --fconst;
    --evecs;
    --coord;
    --fmatrx;
    deldip -= 4;

    /* Function Body */
    o__1.oerr = 0;
    o__1.ounit = 9;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR009", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 9;
    f_rew(&al__1);
    o__1.oerr = 0;
    o__1.ounit = 10;
    o__1.ofnmlen = 80;
    getnam_(ch__1, (ftnlen)80, "FOR010", (ftnlen)6);
    o__1.ofnm = ch__1;
    o__1.orl = 0;
    o__1.osta = "UNKNOWN";
    o__1.oacc = 0;
    o__1.ofm = "UNFORMATTED";
    o__1.oblnk = 0;
    f_open(&o__1);
    al__1.aerr = 0;
    al__1.aunit = 10;
    f_rew(&al__1);
    ir = 9;
    iw = 9;
    if (*ipt == 0) {

/*   READ IN FORCE DATA */

	io___3.ciunit = ir;
	i__1 = s_rsue(&io___3);
	if (i__1 != 0) {
	    goto L20;
	}
	i__1 = do_uio(&c__1, (char *)&(*time), (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L20;
	}
	i__1 = do_uio(&c__1, (char *)&(*ipt), (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L20;
	}
	i__1 = do_uio(&c__1, (char *)&(*refh), (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L20;
	}
	i__1 = e_rsue();
	if (i__1 != 0) {
	    goto L20;
	}
	linear = *nvar * (*nvar + 1) / 2;
	io___5.ciunit = ir;
	s_rsue(&io___5);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&coord[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___7.ciunit = ir;
	i__1 = s_rsue(&io___7);
	if (i__1 != 0) {
	    goto L10;
	}
	i__2 = linear;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__1 = do_uio(&c__1, (char *)&fmatrx[i__], (ftnlen)sizeof(
		    doublereal));
	    if (i__1 != 0) {
		goto L10;
	    }
	}
	i__1 = e_rsue();
	if (i__1 != 0) {
	    goto L10;
	}
	io___8.ciunit = ir;
	s_rsue(&io___8);
	i__1 = *ipt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		do_uio(&c__1, (char *)&deldip[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_rsue();
	n33 = *nvar * *nvar;
	io___11.ciunit = ir;
	s_rsue(&io___11);
	i__1 = n33;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&evecs[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___12.ciunit = ir;
	s_rsue(&io___12);
	do_uio(&c__1, (char *)&(*jstart), (ftnlen)sizeof(integer));
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&fconst[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	return 0;
    } else {

/*    WRITE FORCE DATA */

	al__1.aerr = 0;
	al__1.aunit = iw;
	f_rew(&al__1);
	if (*time > 1e6) {
	    *time += -1e6;
	}
	io___13.ciunit = iw;
	s_wsue(&io___13);
	do_uio(&c__1, (char *)&(*time), (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&(*ipt), (ftnlen)sizeof(integer));
	do_uio(&c__1, (char *)&(*refh), (ftnlen)sizeof(doublereal));
	e_wsue();
	linear = *nvar * (*nvar + 1) / 2;
	io___14.ciunit = iw;
	s_wsue(&io___14);
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&coord[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___15.ciunit = iw;
	s_wsue(&io___15);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&fmatrx[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___16.ciunit = iw;
	s_wsue(&io___16);
	i__1 = *ipt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		do_uio(&c__1, (char *)&deldip[j + i__ * 3], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsue();
	n33 = *nvar * *nvar;
	io___17.ciunit = ir;
	s_wsue(&io___17);
	i__1 = n33;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&evecs[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___18.ciunit = ir;
	s_wsue(&io___18);
	do_uio(&c__1, (char *)&(*jstart), (ftnlen)sizeof(integer));
	i__1 = *nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&fconst[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	s_wsue(&io___19);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	if (molkst_1.nalpha != 0) {
	    s_wsue(&io___20);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsue();
	}
	cl__1.cerr = 0;
	cl__1.cunit = 9;
	cl__1.csta = 0;
	f_clos(&cl__1);
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    return 0;
L10:
    s_wsfe(&io___21);
    e_wsfe();
    s_wsfe(&io___22);
    e_wsfe();
    s_stop("", (ftnlen)0);
L20:
    s_wsfe(&io___23);
    e_wsfe();
    s_stop("", (ftnlen)0);
    return 0;
} /* forsav_ */

