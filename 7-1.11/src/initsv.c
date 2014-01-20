/* initsv.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal fepsi, rds, disex2;
    integer nspa, npsx, nps2x, nden;
    doublereal cosurf[1200]	/* was [3][400] */, srad[120], abcmat[162000],
	     tm[1080]	/* was [3][3][120] */, qden[660], dirtm[3246]	/* 
	    was [3][1082] */, bh[400];
} solv_;

#define solv_1 solv_

struct {
    integer iatsp[401], nar[400], nnx[240]	/* was [2][120] */;
} solvi_;

#define solvi_1 solvi_

struct {
    integer nps, nps2;
} solvps_;

#define solvps_1 solvps_

struct {
    doublereal dirvec[3246]	/* was [3][1082] */;
    integer nn[360]	/* was [3][120] */;
} dirvec_;

#define dirvec_1 dirvec_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer ifiles[30];
} chanel_;

#define chanel_1 chanel_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

/* Table of constant values */

static integer c__9 = 9;
static integer c__1 = 1;
static integer c__3 = 3;
static integer c__4 = 4;
static integer c__1082 = 1082;

/* Subroutine */ int initsv_(integer *indeps)
{
    /* Initialized data */

    static doublereal rvdw[53] = { 1.08,1.,1.8,999.,999.,1.53,1.48,1.36,1.3,
	    999.,2.3,999.,2.05,2.1,1.75,1.7,1.65,999.,2.8,2.75,999.,999.,999.,
	    999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,1.8,999.,
	    999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,999.,
	    999.,999.,999.,2.05 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;

    /* Builtin functions */
    double sqrt(doublereal);
    integer s_wsle(cilist *), do_lio(integer *, integer *, char *, ftnlen), 
	    e_wsle(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen), i_dnnt(doublereal *);
    double log(doublereal);
    integer pow_ii(integer *, integer *);

    /* Local variables */
    static integer i__, n;
    static doublereal x;
    static integer i4;
    static doublereal x0, z3, z4;
#define iw ((integer *)&chanel_1 + 5)
    static integer iat;
    static doublereal epsi, avdw;
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal delsc, disex;
#define dirsm ((doublereal *)&solv_1 + 1325)
    static doublereal rsolv;
    static integer indels, indise;
    extern /* Subroutine */ int dvfill_(integer *, doublereal *);
#define dirsmh ((doublereal *)&solv_1 + 4571)
    static integer maxnps, inrsol;
    static doublereal usevdw[53];

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, 0, 0 };


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
    for (i__ = 1; i__ <= 53; ++i__) {
/* L10: */
	usevdw[i__ - 1] = rvdw[i__ - 1];
    }
    epsi = reada_(keywrd_1.keywrd, indeps, (ftnlen)241);
    solv_1.fepsi = (epsi - 1.) / (epsi + .5);
    solvps_1.nps = 0;
    *iw = 6;
    solv_1.nden = molkst_1.norbs * 3 - (molkst_1.numat << 1);
    maxnps = sqrt(324000.25099999999f) - solv_1.nden - .5f;
    maxnps = min(maxnps,400);
/*     WRITE(IW,*) 'MAXIMUM NUMBER OF SEGMENTS ALLOWED:',MAXNPS */
    if (solv_1.nden * (solv_1.nden + 1) / 2 > 162000) {
	io___10.ciunit = *iw;
	s_wsle(&io___10);
	do_lio(&c__9, &c__1, "PARAMETER LENABC IS TOO SMALL FOR THIS SYSTEM", 
		(ftnlen)45);
	e_wsle();
	s_stop("PARAMETER LENABC IS TOO SMALL FOR THIS SYSTEM", (ftnlen)45);
    }
    rsolv = 1.;
    inrsol = i_indx(keywrd_1.keywrd, "RSOLV=", (ftnlen)241, (ftnlen)6);
    if (inrsol != 0) {
	rsolv = reada_(keywrd_1.keywrd, &inrsol, (ftnlen)241);
    }
    if (rsolv < 0.f) {
	s_stop(" RSOLV MUST NOT BE NEGATIVE", (ftnlen)27);
    }
    delsc = rsolv;
    indels = i_indx(keywrd_1.keywrd, "DELSC=", (ftnlen)241, (ftnlen)6);
    if (indels != 0) {
	delsc = reada_(keywrd_1.keywrd, &indels, (ftnlen)241);
    }
    if (delsc < .1) {
	io___15.ciunit = *iw;
	s_wsle(&io___15);
	do_lio(&c__9, &c__1, " DELSC TOO SMALL: SET TO 0.1", (ftnlen)28);
	e_wsle();
    }
    if (delsc > rsolv + .5) {
	s_stop(" DELSC UNREASONABLY LARGE", (ftnlen)25);
    }
    solv_1.rds = max(delsc,.1);
    disex = 2.;
    indise = i_indx(keywrd_1.keywrd, "DISEX=", (ftnlen)241, (ftnlen)6);
    if (indise != 0) {
	disex = reada_(keywrd_1.keywrd, &indise, (ftnlen)241);
    }
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iat = molkst_1.nat[i__ - 1];
	if (iat > 53) {
	    s_stop("MISSING VAN DER WAALS RADIUS", (ftnlen)28);
	} else {
	    avdw = usevdw[iat - 1];
	    if (avdw > 10.) {
		s_stop("MISSING VAN DER WAALS RADIUS", (ftnlen)28);
	    }
	}
	solv_1.srad[i__ - 1] = avdw + rsolv;
/* L20: */
    }
    solv_1.nspa = 60;
    if (i_indx(keywrd_1.keywrd, "NSPA=", (ftnlen)241, (ftnlen)5) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "NSPA", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	solv_1.nspa = i_dnnt(&d__1);
    }
    x0 = log(solv_1.nspa * .1 - .199999);
    z3 = log(3.);
    z4 = log(4.);
    i4 = (integer) (x0 / z4);
    solvps_1.nps2 = 0;
    i__1 = i4;
    for (i__ = 0; i__ <= i__1; ++i__) {
	x = x0 - i__ * z4;
	i__2 = (integer) (x / z3);
	n = pow_ii(&c__3, &i__2) * pow_ii(&c__4, &i__);
/* L7: */
	if (n > solvps_1.nps2) {
	    solvps_1.nps2 = n;
	}
    }
    solvps_1.nps = solvps_1.nps2 / 3;
    if (solvps_1.nps2 % 3 != 0) {
	solvps_1.nps = solvps_1.nps2 / 4;
    }
    solvps_1.nps2 = solvps_1.nps2 * 10 + 2;
/* Computing MAX */
    i__1 = 12, i__2 = solvps_1.nps * 10 + 2;
    solvps_1.nps = max(i__1,i__2);
    dvfill_(&solvps_1.nps2, dirsm);
    dvfill_(&solvps_1.nps, dirsmh);
    solvps_1.nps = -solvps_1.nps;
/* Computing 2nd power */
    d__1 = (rsolv + 1.5 - solv_1.rds) * 4 * disex;
    solv_1.disex2 = d__1 * d__1 / solv_1.nspa;
    dvfill_(&c__1082, dirvec_1.dirvec);
    return 0;
} /* initsv_ */

#undef dirsmh
#undef dirsm
#undef iw


