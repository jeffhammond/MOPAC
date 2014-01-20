/* greenf.f -- translated by f2c (version 20020621).
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
    integer itl[200], it[200];
} dod_;

#define dod_1 dod_

struct {
    integer nmux, lm6, lm7;
} dod1_;

#define dod1_1 dod1_

struct {
    integer ifiles[30];
} chanel_;

#define chanel_1 chanel_

struct {
    integer imoci[200];
} cimos_;

#define cimos_1 cimos_

struct {
    integer ici1, ici2, iout2;
} ciparm_;

#define ciparm_1 ciparm_

union {
    struct {
	doublereal c__[90000], eig[300], cbeta[90000], eigb[300];
    } _1;
    struct {
	doublereal c__[90000], eig[300], dumy[90300];
    } _2;
    struct {
	doublereal c__[90000], eig[300], cbeta[90000], eigbet[300];
    } _3;
} vector_;

#define vector_1 (vector_._1)
#define vector_2 (vector_._2)
#define vector_3 (vector_._3)

struct {
    doublereal w[214770], wk[214770];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    doublereal x[600000];
} fmcom_;

#define fmcom_1 fmcom_

union {
    struct {
	integer nintg;
    } _1;
    struct {
	integer intso;
    } _2;
} davi_;

#define davi_1 (davi_._1)
#define davi_2 (davi_._2)

union {
    struct {
	integer nyr, iy, iggv, iggw;
    } _1;
    struct {
	integer nyr, iyr, iggv, iggw;
    } _2;
} perem_;

#define perem_1 (perem_._1)
#define perem_2 (perem_._2)

struct {
    doublereal su2r, eps, sum1, sum2;
} suma_;

#define suma_1 suma_

struct {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
} twoele_;

#define twoele_1 twoele_

struct {
    doublereal as1, as2, as3, as4, as5, as6;
} asma_;

#define asma_1 asma_

struct {
    doublereal cs1, cs2, cs3, cs4, cs5, cs6;
} csuc_;

#define csuc_1 csuc_

struct {
    doublereal ds1, ds2, ds3, ds4, ds5, ds6;
} dsmd_;

#define dsmd_1 dsmd_

/* Table of constant values */

static integer c__1 = 1;
static integer c_b31 = 600000;
static doublereal c_b328 = 10.;

/* Subroutine */ int greenf_(void)
{
    /* Format strings */
    static char fmt_10[] = "(///)";
    static char fmt_20[] = "(10x,\002***************************************"
	    "*********\002/10x,\002*                                         "
	    "     *\002/10x,\002*   SEMIEMPIRICAL GREEN FUNCTION CALCULATION "
	    "  *\002/10x,\002*                                              "
	    "*\002/10x,\002*  This package was written by Dr. D.Danovich  "
	    "*\002/10x,\002*            Chemistry Department              "
	    "*\002/10x,\002*    TECHNION-Israel Institute of Technology   "
	    "*\002/10x,\002*      Technion City, Haifa  32000, ISRAEL     "
	    "*\002/10x,\002*                                              "
	    "*\002/10x,\002***********************************************"
	    "*\002)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, k, n;
    extern /* Subroutine */ int mo_(integer *);
#define iw ((integer *)&chanel_1 + 5)
    static integer iao, mmm;
    extern /* Subroutine */ int insymc_(void);
    static integer memory;

    /* Fortran I/O blocks */
    static cilist io___2 = { 0, 0, 0, fmt_10, 0 };
    static cilist io___3 = { 0, 0, 0, fmt_20, 0 };


/* ****************************************************************** */
/*                                                                 * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATION              * */
/* ****************************************************************** */
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

    *iw = 6;
    io___2.ciunit = *iw;
    s_wsfe(&io___2);
    e_wsfe();
    io___3.ciunit = *iw;
    s_wsfe(&io___3);
    e_wsfe();
    k = 0;
    for (i__ = 1; i__ <= 200; ++i__) {
	dod_1.it[i__ - 1] = k;
/* L30: */
	k += i__;
    }
    for (i__ = 1; i__ <= 200; ++i__) {
	n = dod_1.it[i__ - 1];
/* L40: */
	dod_1.itl[i__ - 1] = n * (n - 1) / 2;
    }
    mmm = molkst_1.norbs;
    dod1_1.nmux = dod_1.itl[mmm - 1] + dod_1.it[mmm - 1] * mmm + dod_1.it[mmm 
	    - 1] + dod_1.it[mmm - 1] + mmm;
    dod1_1.lm6 = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	iao = molkst_1.nlast[i__ - 1] - molkst_1.nfirst[i__ - 1] + 1;
/* L50: */
	dod1_1.lm6 += iao * (iao + 1) / 2;
    }
    dod1_1.lm7 = dod1_1.lm6 * dod1_1.lm6;
    memory = dod1_1.nmux + (dod1_1.lm6 << 1) + dod1_1.lm7 + 8;
    insymc_();
    mo_(&memory);
    return 0;
} /* greenf_ */

#undef iw



/* ================================================================== */

/* Subroutine */ int gstore_(integer *ii, integer *jj, integer *kk, integer *
	ll, doublereal *wert, doublereal *pgr, integer *nmux)
{
    static integer lt, iii, jjj, kkk, lll, nnnn;

/* *********************************************************** */
/*                                                          * */
/*     STORE TWO-ELECTRON MO INTEGRALS ON FILE NTP3.        * */
/*     SUBROUTINE WRITTEN BY DR.DAVID DANOVICH,             * */
/*     COMPUTATIONAL CHEMISTRY CENTRE, CHEMISTRY DEPARTMENT * */
/*     TECHNION-ISRAEL INSTITUTE OF TECHNOLOGY, HAIFA,      * */
/*     32000, ISRAEL,          VERSION     02.09.90         * */
/* *********************************************************** */
    /* Parameter adjustments */
    --pgr;

    /* Function Body */
    iii = *ii;
    jjj = *jj;
    kkk = *kk;
    lll = *ll;
    if (iii >= jjj) {
	goto L10;
    }
    lt = iii;
    iii = jjj;
    jjj = lt;
L10:
    if (kkk >= lll) {
	goto L20;
    }
    lt = kkk;
    kkk = lll;
    lll = lt;
L20:
    if (iii > kkk) {
	goto L40;
    }
    if (iii == kkk) {
	goto L30;
    }
    lt = iii;
    iii = kkk;
    kkk = lt;
    lt = jjj;
    jjj = lll;
    lll = lt;
    goto L40;
L30:
    if (jjj >= lll) {
	goto L40;
    }
    lt = jjj;
    jjj = lll;
    lll = lt;
L40:
    nnnn = dod_1.itl[iii - 1] + dod_1.it[iii - 1] * jjj + dod_1.it[jjj - 1] + 
	    dod_1.it[kkk - 1] + lll;
    pgr[nnnn] = *wert;
    return 0;
} /* gstore_ */


/* ====================================================================== */

/* Subroutine */ int insymc_(void)
{
    /* Format strings */
    static char fmt_3185[] = "(///1x,\002NUMBER OF OCCUPIED MOS\002,4x,i4,/1"
	    "x,\002NUMBER OF UNOCCUPIED MOS\002,2x,i4,/1x,\002PRINTING FLA"
	    "G\002,13x,i4)";

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     s_wsfe(cilist *), e_wsfe(void);

    /* Local variables */
    static integer i__, ia, ib, nra, namb;
    static char line[80];
    static doublereal value[40];
    extern /* Subroutine */ int nuchar_(char *, doublereal *, integer *, 
	    ftnlen);
    static integer nvalue, ioutci;

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 5, 0, "(A)", 0 };
    static cilist io___23 = { 0, 0, 0, fmt_3185, 0 };


/* ***************************************************************** */
/*                                                                * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATIONS            * */
/* ***************************************************************** */
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
    nra = 6;
    namb = molkst_1.norbs - molkst_1.nclose;
    s_rsfe(&io___18);
    do_fio(&c__1, line, (ftnlen)80);
    e_rsfe();
    nuchar_(line, value, &nvalue, (ftnlen)80);
    ciparm_1.ici1 = (integer) value[0];
    ciparm_1.ici2 = (integer) value[1];
    ioutci = (integer) value[2];
    if (ciparm_1.ici1 == 0) {
	ciparm_1.ici1 = 20;
    }
    if (ciparm_1.ici1 > molkst_1.nclose) {
	ciparm_1.ici1 = molkst_1.nclose;
    }
    if (ciparm_1.ici2 == 0) {
	ciparm_1.ici2 = 20;
    }
    if (ciparm_1.ici2 > namb) {
	ciparm_1.ici2 = namb;
    }
    io___23.ciunit = nra;
    s_wsfe(&io___23);
    do_fio(&c__1, (char *)&ciparm_1.ici1, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ciparm_1.ici2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ioutci, (ftnlen)sizeof(integer));
    e_wsfe();
    ciparm_1.iout2 = ioutci;
/* *** DEFINITION OF ORBITALS INVOLVED IN THE GREEN TREATMENT. */
    ia = ciparm_1.ici1 + 1;
    ib = ciparm_1.ici1 + ciparm_1.ici2;
    i__1 = ciparm_1.ici1;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L101: */
	cimos_1.imoci[i__ - 1] = molkst_1.nclose + 1 - i__;
    }
    i__1 = ib;
    for (i__ = ia; i__ <= i__1; ++i__) {
/* L102: */
	cimos_1.imoci[i__ - 1] = molkst_1.nclose + 1 + i__ - ia;
    }
    return 0;
} /* insymc_ */


/* ============================================================== */

/* Subroutine */ int mo_(integer *memory)
{
    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i10;
#define iw ((integer *)&chanel_1 + 5)
    static integer need, last, nnmm, nnmm1, nnnn1;
    extern /* Subroutine */ int fcnpp_(doublereal *, integer *), moint_(
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *, integer *, integer *, integer *, integer 
	    *);
    static integer loadfm;
    extern /* Subroutine */ int worder_(doublereal *, integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___28 = { 0, 0, 0, "(A)", 0 };
    static cilist io___29 = { 0, 0, 0, "(A,I8,A,I8)", 0 };
    static cilist io___30 = { 0, 0, 0, "(A)", 0 };


/* ****************************************************************** */
/*                                                                 * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATIONS             * */
/* ****************************************************************** */
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
    if (*memory > 600000) {
	io___28.ciunit = *iw;
	s_wsfe(&io___28);
	do_fio(&c__1, " AVAILABLE MEMORY IN GREENS FUNCTION CALCULATION", (
		ftnlen)48);
	e_wsfe();
	io___29.ciunit = *iw;
	s_wsfe(&io___29);
	do_fio(&c__1, " TOO SMALL.  AVAILABLE:", (ftnlen)23);
	do_fio(&c__1, (char *)&c_b31, (ftnlen)sizeof(integer));
	do_fio(&c__1, " NEEDED:", (ftnlen)8);
	do_fio(&c__1, (char *)&(*memory), (ftnlen)sizeof(integer));
	e_wsfe();
	io___30.ciunit = *iw;
	s_wsfe(&io___30);
	do_fio(&c__1, " TO RUN THIS JOB, MODIFY IGREEN IN SUBROUTINE MO (CAL"
		"LED BY GREENF) AND RECOMPILE", (ftnlen)81);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    loadfm = 0;
    i10 = loadfm + 1;
    nnmm = i10 + dod1_1.nmux;
    nnnn1 = nnmm + dod1_1.lm7;
    nnmm1 = nnnn1 + dod1_1.lm6;
    last = nnmm1 + dod1_1.lm6;
    need = last - i10;
    worder_(&fmcom_1.x[nnmm - 1], &dod1_1.lm7, &ciparm_1.iout2);
    moint_(vector_1.c__, &fmcom_1.x[i10 - 1], &fmcom_1.x[nnmm - 1], &
	    fmcom_1.x[nnnn1 - 1], &fmcom_1.x[nnmm1 - 1], &molkst_1.norbs, &
	    molkst_1.norbs, &dod1_1.lm7, &dod1_1.lm6, &dod1_1.nmux);
    fcnpp_(&fmcom_1.x[i10 - 1], &dod1_1.nmux);
    return 0;
} /* mo_ */

#undef iw


/* Subroutine */ int moint_(doublereal *c__, doublereal *pgr, doublereal *cc, 
	doublereal *w, doublereal *c12, integer *norbs, integer *lm2, integer 
	*lm8, integer *kmax, integer *nmux)
{
    /* Initialized data */

    static doublereal off = 1e-8;
    static doublereal zero = 0.;

    /* Format strings */
    static char fmt_20[] = "(///1x,\002THERE ARE\002,i12,\002 NONZERO INTEGR"
	    "ALS.\002/)";

    /* System generated locals */
    integer c_dim1, c_offset, i__1, i__2, i__3, i__4;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static integer i__, j, k, l, ii, ij, ik, il;
#define iw ((integer *)&chanel_1 + 5)
    static doublereal wnn;
    static integer iend, lmax;
    extern doublereal sisms_(doublereal *, doublereal *, integer *);
    extern /* Subroutine */ int ccprod_(doublereal *, doublereal *, 
	    doublereal *, integer *, integer *), gstore_(integer *, integer *,
	     integer *, integer *, doublereal *, doublereal *, integer *), 
	    wwstep_(doublereal *, doublereal *, doublereal *, integer *, 
	    integer *, integer *);

    /* Fortran I/O blocks */
    static cilist io___52 = { 0, 0, 0, fmt_20, 0 };


/* ******************************************************************* */
/*     TRANSFORMATION OF TWO-ELECTRON INTEGRALS FROM AO TO MO BASIS * */
/*     SUBROUTINE WRITTEN BY DR.DAVID DANOVICH, COMPUTATIONAL       * */
/*     CHEMISTRY CENTRE, DEPARTMENT OF CHEMISTRY, TECHNION -        * */
/*     ISRAEL INSTITUTE OF TECHNOLOGY, HAIFA, 32000, ISRAEL         * */
/*     VERSION     02.09.90                                         * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATIONS              * */
/* ******************************************************************* */
    /* Parameter adjustments */
    --pgr;
    --cc;
    --w;
    --c12;
    c_dim1 = *lm2;
    c_offset = 1 + c_dim1 * 1;
    c__ -= c_offset;

    /* Function Body */
/*     SET CONTROL VARIABLES. */
/*     LMAX   = STORAGE CAPACITY OF CC(LM8) */
    lmax = *lm8 / *kmax;
/*     COMPUTE (IJ,KL) INTEGRALS */
    iend = ciparm_1.ici1 + ciparm_1.ici2;
    davi_1.nintg = 0;
/*     OUTER IJ-LOOP */
    i__1 = iend;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ii = cimos_1.imoci[i__ - 1];
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    ij = cimos_1.imoci[j - 1];
/*     COMPUTE SET OF (IJ,AB) INTEGRALS */
	    ccprod_(&c__[ii * c_dim1 + 1], &c__[ij * c_dim1 + 1], &c12[1], 
		    lm2, kmax);
	    wwstep_(&c12[1], &cc[1], &w[1], lm8, kmax, &lmax);
/*     INNER KL-LOOP */
	    i__3 = i__;
	    for (k = 1; k <= i__3; ++k) {
		ik = cimos_1.imoci[k - 1];
		i__4 = k;
		for (l = 1; l <= i__4; ++l) {
		    if (i__ == k && j < l) {
			goto L10;
		    }
		    il = cimos_1.imoci[l - 1];
		    wnn = zero;
/*     COMPUTE THE INTEGRAL */
		    ++davi_1.nintg;
		    ccprod_(&c__[ik * c_dim1 + 1], &c__[il * c_dim1 + 1], &
			    c12[1], lm2, kmax);
		    wnn = sisms_(&c12[1], &w[1], kmax);
		    if (abs(wnn) < off) {
			wnn = zero;
		    }
		    gstore_(&ii, &ij, &ik, &il, &wnn, &pgr[1], nmux);
L10:
		    ;
		}
	    }
	}
    }
    if (ciparm_1.iout2 > -5) {
	io___52.ciunit = *iw;
	s_wsfe(&io___52);
	do_fio(&c__1, (char *)&davi_1.nintg, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    return 0;
} /* moint_ */

#undef iw



/* ======================================================================= */

doublereal sisms_(doublereal *c12, doublereal *cc, integer *lm6)
{
    /* System generated locals */
    integer i__1;
    doublereal ret_val;

    /* Local variables */
    static integer i__;

/*     SCALAR PRODUCT. */
/* ****************************************************************** */
/*     FUNCTION NEED FOR GREEN FUNCTION CALCULATIONS               * */
/* ****************************************************************** */
    /* Parameter adjustments */
    --cc;
    --c12;

    /* Function Body */
    ret_val = 0.;
    i__1 = *lm6;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	ret_val += c12[i__] * cc[i__];
    }
    return ret_val;
} /* sisms_ */


/* =================================================================== */

/* Subroutine */ int suma2_(doublereal *p, integer *ndis, doublereal *ep)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, m, n, ii, jj, mm, nn, lt, iyr, myr, kyr2, kyr1, 
	    numb, numb1;

/* ******************************************************************* */
/*     CALCULATION SECOND-ORDER CONTRIBUTION IN THE SELF-ENERGY     * */
/*     FUNCTION                                                     * */
/*     SUBROUTINE WRITTEN BY DR. DAVID DANOVICH, COMPUTATIONAL      * */
/*     CHEMISTRY CENTRE, DEPARTMENT OF CHEMISTRY, TECHNION -        * */
/*     ISRAEL INSTITUTE OF TECHNOLOGY, HAIFA, 32000, ISRAEL         * */
/*     VERSION    02.09.90                                          * */
/* ******************************************************************* */
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
    --p;

    /* Function Body */
    kyr2 = perem_1.nyr + perem_1.iggv;
    kyr1 = perem_1.nyr + 1;
    myr = perem_1.nyr - perem_1.iggw;
    suma_1.sum1 = 0.;
    suma_1.sum2 = 0.;
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = perem_1.nyr;
	for (i__ = myr; i__ <= i__2; ++i__) {
	    i__3 = perem_1.nyr;
	    for (j = myr; j <= i__3; ++j) {
		iyr = perem_1.iy;
		ii = i__;
		mm = m;
		jj = j;
		if (iyr >= ii) {
		    goto L10;
		}
		lt = iyr;
		iyr = ii;
		ii = lt;
L10:
		if (iyr > mm) {
		    goto L30;
		}
		if (iyr == mm) {
		    goto L20;
		}
		lt = iyr;
		iyr = mm;
		mm = lt;
		lt = ii;
		ii = jj;
		jj = lt;
		goto L30;
L20:
		if (ii >= jj) {
		    goto L30;
		}
		lt = ii;
		ii = jj;
		jj = lt;
L30:
		numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ii + dod_1.it[
			ii - 1] + dod_1.it[mm - 1] + jj;
		iyr = perem_1.iy;
		jj = j;
		mm = m;
		ii = i__;
		if (iyr >= jj) {
		    goto L40;
		}
		lt = iyr;
		iyr = jj;
		jj = lt;
L40:
		if (iyr > mm) {
		    goto L60;
		}
		if (iyr == mm) {
		    goto L50;
		}
		lt = iyr;
		iyr = mm;
		mm = lt;
		lt = jj;
		jj = ii;
		ii = lt;
		goto L60;
L50:
		if (jj >= ii) {
		    goto L60;
		}
		lt = jj;
		jj = ii;
		ii = lt;
L60:
		numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
			dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
		suma_1.sum1 += (p[numb] * 2. - p[numb1]) * p[numb] / (*ep + 
			vector_1.eig[m - 1] - vector_1.eig[i__ - 1] - 
			vector_1.eig[j - 1]);
/* L70: */
	    }
	}
    }
    i__3 = kyr2;
    for (m = kyr1; m <= i__3; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__1 = perem_1.nyr;
	    for (i__ = myr; i__ <= i__1; ++i__) {
		iyr = perem_1.iy;
		ii = i__;
		mm = m;
		nn = n;
		if (iyr >= mm) {
		    goto L80;
		}
		lt = iyr;
		iyr = mm;
		mm = lt;
L80:
		if (iyr > nn) {
		    goto L100;
		}
		if (iyr == nn) {
		    goto L90;
		}
		lt = iyr;
		iyr = nn;
		nn = lt;
		lt = mm;
		mm = ii;
		ii = lt;
		goto L100;
L90:
		if (mm >= ii) {
		    goto L100;
		}
		lt = mm;
		mm = ii;
		ii = lt;
L100:
		numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * mm + dod_1.it[
			mm - 1] + dod_1.it[nn - 1] + ii;
		iyr = perem_1.iy;
		nn = n;
		mm = m;
		ii = i__;
		if (iyr >= nn) {
		    goto L110;
		}
		lt = iyr;
		iyr = nn;
		nn = lt;
L110:
		if (iyr > mm) {
		    goto L130;
		}
		if (iyr == mm) {
		    goto L120;
		}
		lt = iyr;
		iyr = mm;
		mm = lt;
		lt = nn;
		nn = ii;
		ii = lt;
		goto L130;
L120:
		if (nn >= ii) {
		    goto L130;
		}
		lt = nn;
		nn = ii;
		ii = lt;
L130:
		numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
			dod_1.it[nn - 1] + dod_1.it[mm - 1] + ii;
		suma_1.sum2 += (p[numb] * 2. - p[numb1]) * p[numb] / (*ep + 
			vector_1.eig[i__ - 1] - vector_1.eig[m - 1] - 
			vector_1.eig[n - 1]);
/* L140: */
	    }
	}
    }
    suma_1.su2r = suma_1.sum1 + suma_1.sum2;
    return 0;
} /* suma2_ */


/* ======================================================================= */

/* Subroutine */ int worder_(doublereal *cc, integer *lm7, integer *iout2)
{
    /* Initialized data */

    static doublereal zero = 0.;

    /* Format strings */
    static char fmt_220[] = "(\0021\002,//1x,\002AO INTEGRALS IN NEW ORDER"
	    ".\002/)";
    static char fmt_230[] = "(//1x,\002THE AO INTEGRALS ARE STORED IN A MATR"
	    "IX WITH\002,i4,\002 ROWS AND COLUMNS.\002)";
    static char fmt_240[] = "(1x,\002THERE ARE\002,i4,\002 RECORDS EACH OF W"
	    "HICH CONTAINS\002,i4/2x\002 COLUMNS AND\002,i6,\002 INTEGRALS"
	    ".\002)";
    static char fmt_250[] = "(//1x,\002INTEGRALS IN THE FIRST RECORD.\002/)";
    static char fmt_260[] = "(1x,10f7.3)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, ia, ib, ja, la, lb, na, jb, ka, ii, kb, jj, 
	    kk, ni, kp, nn, no, ks;
#define iw ((integer *)&chanel_1 + 5)
    static integer jw, ns, iw1, kgo, lrec, imax, kmax, lmax, indx[120], indy[
	    120], ktot, iminus;

    /* Fortran I/O blocks */
    static cilist io___100 = { 0, 0, 0, fmt_220, 0 };
    static cilist io___101 = { 0, 0, 0, fmt_230, 0 };
    static cilist io___102 = { 0, 0, 0, fmt_240, 0 };
    static cilist io___104 = { 0, 0, 0, fmt_250, 0 };
    static cilist io___107 = { 0, 0, 0, fmt_260, 0 };


/* ******************************************************** */
/*                                                       * */
/*     ORDERING OF AO REPULSION INTEGRALS.               * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATION    * */
/* ******************************************************** */
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
    --cc;

    /* Function Body */
    kk = 1;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	indx[i__ - 1] = kk;
	++kk;
	if (molkst_1.nat[i__ - 1] > 2) {
	    kk += 9;
	}
	indy[i__ - 1] = kk - 1;
/* L10: */
    }
/*     STORAGE CONTROL. */
    kmax = kk - 1;
    lmax = *lm7 / kmax;
    ktot = kmax * kmax;
    if (kmax > lmax) {
	ktot = kmax * lmax;
    }
/*     SORTING OF INTEGRALS FOR MNDO */
/*     NUMBER OF RECORDS. */
    lrec = (kmax - 1) / lmax + 1;
    i__1 = lrec;
    for (l = 1; l <= i__1; ++l) {
	la = lmax * (l - 1) + 1;
	lb = lmax * l;
	kp = kmax * (la - 1);
/*     INITIALIZE INTEGRALS. */
	i__2 = ktot;
	for (kk = 1; kk <= i__2; ++kk) {
/* L20: */
	    cc[kk] = zero;
	}
/*     LOOP OVER ONE-CENTER INTEGRALS. */
	i__2 = molkst_1.numat;
	for (ii = 1; ii <= i__2; ++ii) {
	    ia = indx[ii - 1];
	    if (ia > lb) {
		goto L100;
	    }
	    ib = indy[ii - 1];
	    if (ib < la) {
		goto L90;
	    }
	    ni = molkst_1.nat[ii - 1];
	    if (ni > 2) {
		goto L30;
	    }
/*     HYDROGEN. */
	    kk = kmax * (ia - 1) + ia - kp;
	    cc[kk] = twoele_1.gss[ni - 1];
	    goto L90;
/*     HEAVY ATOM. */
L30:
	    i__3 = ib;
	    for (i__ = ia; i__ <= i__3; ++i__) {
		if (i__ < la || i__ > lb) {
		    goto L80;
		}
		ks = kmax * (i__ - 1) + ia - 1 - kp;
		kgo = i__ - ia + 1;
		kk = ks + kgo;
		switch (kgo) {
		    case 1:  goto L40;
		    case 2:  goto L50;
		    case 3:  goto L60;
		    case 4:  goto L50;
		    case 5:  goto L70;
		    case 6:  goto L60;
		    case 7:  goto L50;
		    case 8:  goto L70;
		    case 9:  goto L70;
		    case 10:  goto L60;
		}
L40:
		cc[kk] = twoele_1.gss[ni - 1];
		cc[ks + 3] = twoele_1.gsp[ni - 1];
		cc[ks + 6] = twoele_1.gsp[ni - 1];
		cc[ks + 10] = twoele_1.gsp[ni - 1];
		goto L80;
L50:
		cc[kk] = twoele_1.hsp[ni - 1];
		goto L80;
L60:
		cc[ks + 1] = twoele_1.gsp[ni - 1];
		cc[ks + 3] = twoele_1.gp2[ni - 1];
		cc[ks + 6] = twoele_1.gp2[ni - 1];
		cc[ks + 10] = twoele_1.gp2[ni - 1];
		cc[kk] = twoele_1.gpp[ni - 1];
		goto L80;
L70:
		cc[kk] = (twoele_1.gpp[ni - 1] - twoele_1.gp2[ni - 1]) * .5;
L80:
		;
	    }
L90:
	    ;
	}
/*     LOOP OVER TWO-CENTER INTEGRALS, MNDO. */
L100:
	if (molkst_1.numat == 1) {
	    goto L180;
	}
	na = 0;
	i__2 = molkst_1.numat;
	for (ii = 2; ii <= i__2; ++ii) {
	    ia = indx[ii - 1];
	    ib = indy[ii - 1];
	    iw1 = ib - ia + 1;
	    iminus = ii - 1;
	    i__3 = iminus;
	    for (jj = 1; jj <= i__3; ++jj) {
		ja = indx[jj - 1];
		jb = indy[jj - 1];
		jw = jb - ja + 1;
		no = iw1 * jw;
/*     CASE II.GT.JJ. */
		if (ia > lb || ib < la) {
		    goto L130;
		}
		i__4 = ib;
		for (i__ = ia; i__ <= i__4; ++i__) {
		    if (i__ < la || i__ > lb) {
			goto L120;
		    }
		    ks = kmax * (i__ - 1) + ja - 1 - kp;
		    ns = na + jw * (i__ - ia);
		    i__5 = jw;
		    for (j = 1; j <= i__5; ++j) {
			kk = ks + j;
			nn = ns + j;
/* L110: */
			cc[kk] = wmatrx_1.w[nn - 1];
		    }
L120:
		    ;
		}
/*     CASE II.LT.JJ. */
L130:
		if (ja > lb || jb < la) {
		    goto L160;
		}
		i__4 = jb;
		for (j = ja; j <= i__4; ++j) {
		    if (j < la || j > lb) {
			goto L150;
		    }
		    ks = kmax * (j - 1) + ia - 1 - kp;
		    ns = na + j - ja + 1 - jw;
		    i__5 = iw1;
		    for (i__ = 1; i__ <= i__5; ++i__) {
			kk = ks + i__;
			nn = ns + jw * i__;
/* L140: */
			cc[kk] = wmatrx_1.w[nn - 1];
		    }
L150:
		    ;
		}
L160:
		na += no;
/* L170: */
	    }
	}
L180:
/* L190: */
	;
    }
/*     DEBUG PRINT. */
    if (*iout2 < 1) {
	return 0;
    }
    io___100.ciunit = *iw;
    s_wsfe(&io___100);
    e_wsfe();
    io___101.ciunit = *iw;
    s_wsfe(&io___101);
    do_fio(&c__1, (char *)&kmax, (ftnlen)sizeof(integer));
    e_wsfe();
    if (lrec > 1) {
	io___102.ciunit = *iw;
	s_wsfe(&io___102);
	do_fio(&c__1, (char *)&lrec, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&lmax, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ktot, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (*iout2 < 4) {
	return 0;
    }
    imax = kmax;
    if (lrec == 1) {
	goto L200;
    }
    imax = lmax;
L200:
    io___104.ciunit = *iw;
    s_wsfe(&io___104);
    e_wsfe();
    kk = 1;
    i__1 = imax;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ka = kk;
	kb = ka + kmax - 1;
	io___107.ciunit = *iw;
	s_wsfe(&io___107);
	i__3 = kb;
	for (k = ka; k <= i__3; ++k) {
	    do_fio(&c__1, (char *)&cc[k], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
/* L210: */
	kk = ka + kmax;
    }
    return 0;
} /* worder_ */

#undef iw



/* ======================================================================= */

/* Subroutine */ int wwstep_(doublereal *c12, doublereal *cc, doublereal *ww, 
	integer *lm7, integer *kmax, integer *lmax)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer kk, ll, nn;
    extern doublereal sisms_(doublereal *, doublereal *, integer *);

/* ******************************************************** */
/*                                                       * */
/*     CALCULATION OF A SET OF (IJ,AB) INTEGRALS.        * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATION    * */
/* ******************************************************** */
    /* Parameter adjustments */
    --ww;
    --cc;
    --c12;

    /* Function Body */
    if (*kmax > *lmax) {
	goto L20;
    }
/*     AO INTEGRALS IN CC(LM7). */
    kk = 1 - *kmax;
    i__1 = *kmax;
    for (nn = 1; nn <= i__1; ++nn) {
	kk += *kmax;
/* L10: */
	ww[nn] = sisms_(&c12[1], &cc[kk], kmax);
    }
    return 0;
L20:
    kk = 1 - *kmax;
    ll = 0;
    i__1 = *kmax;
    for (nn = 1; nn <= i__1; ++nn) {
	++ll;
	if (ll <= *lmax) {
	    goto L30;
	}
	kk = 1 - *kmax;
	ll = 1;
L30:
	kk += *kmax;
/* L40: */
	ww[nn] = sisms_(&c12[1], &cc[kk], kmax);
    }
    return 0;
} /* wwstep_ */


/* ======================================================================= */

/* Subroutine */ int asum_(doublereal *p, integer *ndis)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;

    /* Local variables */
    static integer i__, j, k, l, m, n, ii, jj, kk, ll, mm, nn, lt, iyr, kyr1, 
	    kyr2, myr1, numb, numb1, numb2, numb3, numb4;

/* **************************************************************** */
/*  CALCULATION  "AI" VALUES FOR GREEN'S FUNCTION METHOD         * */
/*  SUBROUTINE WRITTEN BY DR. DAVID DANOVICH, DEPARTMENT OF      * */
/*  OF CHEMISTRY, TECHNION-ISRAEL INSTITUTE OF TECHNOLOGY,       * */
/*  HAIFA, 32000, ISRAEL.       VERSION: 2.09.90                 * */
/* **************************************************************** */
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
    --p;

    /* Function Body */
    kyr2 = perem_1.nyr + perem_1.iggv;
    kyr1 = perem_1.nyr + 1;
    myr1 = perem_1.nyr - perem_1.iggw;
    asma_1.as1 = 0.;
    asma_1.as2 = 0.;
    asma_1.as3 = 0.;
    asma_1.as4 = 0.;
    asma_1.as5 = 0.;
    asma_1.as6 = 0.;
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__3 = perem_1.nyr;
	    for (i__ = myr1; i__ <= i__3; ++i__) {
		i__4 = perem_1.nyr;
		for (j = myr1; j <= i__4; ++j) {
		    i__5 = perem_1.nyr;
		    for (k = myr1; k <= i__5; ++k) {
			iyr = perem_1.iy;
			kk = k;
			jj = j;
			if (kk >= jj) {
			    goto L10;
			}
			lt = kk;
			kk = jj;
			jj = lt;
L10:
			if (iyr > perem_1.nyr) {
			    goto L20;
			}
			if (iyr >= kk) {
			    goto L20;
			}
			numb = dod_1.itl[kk - 1] + dod_1.it[kk - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[iyr - 1] + iyr;
			goto L30;
L20:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[kk - 1] + jj;
L30:
			iyr = perem_1.iy;
			kk = k;
			jj = j;
			if (iyr <= perem_1.nyr) {
			    goto L50;
			}
			if (jj >= kk) {
			    goto L40;
			}
			lt = jj;
			jj = kk;
			kk = lt;
L40:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[iyr - 1] + kk;
			goto L100;
L50:
			if (iyr >= jj && iyr >= kk) {
			    goto L60;
			}
			if (iyr < jj && iyr < kk) {
			    goto L70;
			}
			if (iyr >= jj && iyr < kk) {
			    goto L90;
			}
			numb1 = dod_1.itl[jj - 1] + dod_1.it[jj - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[iyr - 1] + kk;
			goto L100;
L60:
			if (jj >= kk) {
			    goto L40;
			}
			lt = jj;
			jj = kk;
			kk = lt;
			goto L40;
L70:
			if (jj >= kk) {
			    goto L80;
			}
			lt = jj;
			jj = kk;
			kk = lt;
L80:
			numb1 = dod_1.itl[jj - 1] + dod_1.it[jj - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[kk - 1] + iyr;
			goto L100;
L90:
			numb1 = dod_1.itl[kk - 1] + dod_1.it[kk - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[iyr - 1] + jj;
L100:
			jj = j;
			ii = i__;
			mm = m;
			nn = n;
			if (mm > nn) {
			    goto L110;
			}
			if (mm == nn) {
			    goto L120;
			}
			numb2 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			goto L130;
L110:
			numb2 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ii;
			goto L130;
L120:
			if (jj >= ii) {
			    goto L110;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L110;
L130:
			jj = j;
			nn = n;
			ii = i__;
			mm = m;
			if (nn > mm) {
			    goto L140;
			}
			if (nn == mm) {
			    goto L150;
			}
			numb3 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[nn - 1] + jj;
			goto L160;
L140:
			numb3 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
			goto L160;
L150:
			if (jj >= ii) {
			    goto L140;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L140;
L160:
			mm = m;
			kk = k;
			nn = n;
			ii = i__;
			if (mm > nn) {
			    goto L170;
			}
			if (mm == nn) {
			    goto L180;
			}
			numb4 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + kk;
			goto L190;
L170:
			numb4 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[nn - 1] + ii;
			goto L190;
L180:
			if (kk >= ii) {
			    goto L170;
			}
			lt = kk;
			kk = ii;
			ii = lt;
			goto L170;
L190:
			asma_1.as1 += (p[numb] * 2. - p[numb1]) * (p[numb2] * 
				2. - p[numb3]) * p[numb4] / ((vector_2.eig[j 
				- 1] + vector_2.eig[i__ - 1] - vector_2.eig[m 
				- 1] - vector_2.eig[n - 1]) * (vector_2.eig[k 
				- 1] + vector_2.eig[i__ - 1] - vector_2.eig[m 
				- 1] - vector_2.eig[n - 1]));
/* L200: */
		    }
		}
	    }
	}
    }
    asma_1.as1 = -asma_1.as1;
    i__5 = kyr2;
    for (m = kyr1; m <= i__5; ++m) {
	i__4 = kyr2;
	for (n = kyr1; n <= i__4; ++n) {
	    i__3 = kyr2;
	    for (l = kyr1; l <= i__3; ++l) {
		i__2 = perem_1.nyr;
		for (i__ = myr1; i__ <= i__2; ++i__) {
		    i__1 = perem_1.nyr;
		    for (j = myr1; j <= i__1; ++j) {
			iyr = perem_1.iy;
			nn = n;
			ll = l;
			if (ll >= nn) {
			    goto L210;
			}
			lt = ll;
			ll = nn;
			nn = lt;
L210:
			if (iyr <= perem_1.nyr) {
			    goto L220;
			}
			if (iyr < ll) {
			    goto L220;
			}
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[ll - 1] + nn;
			goto L230;
L220:
			numb = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[iyr - 1] + iyr;
L230:
			iyr = perem_1.iy;
			nn = n;
			ll = l;
			if (iyr > perem_1.nyr) {
			    goto L250;
			}
			if (nn >= ll) {
			    goto L240;
			}
			lt = nn;
			nn = ll;
			ll = lt;
L240:
			numb1 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[ll - 1] + iyr;
			goto L300;
L250:
			if (iyr >= nn && iyr >= ll) {
			    goto L260;
			}
			if (iyr < nn && iyr < ll) {
			    goto L280;
			}
			if (iyr >= nn && iyr < ll) {
			    goto L290;
			}
			numb1 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[iyr - 1] + ll;
			goto L300;
L260:
			if (nn >= ll) {
			    goto L270;
			}
			lt = nn;
			nn = ll;
			ll = lt;
L270:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[iyr - 1] + ll;
			goto L300;
L280:
			if (nn >= ll) {
			    goto L240;
			}
			lt = nn;
			nn = ll;
			ll = lt;
			goto L240;
L290:
			numb1 = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[iyr - 1] + nn;
L300:
			jj = j;
			mm = m;
			ii = i__;
			nn = n;
			if (mm > nn) {
			    goto L310;
			}
			if (mm == nn) {
			    goto L320;
			}
			numb2 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			goto L330;
L310:
			numb2 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ii;
			goto L330;
L320:
			if (jj >= ii) {
			    goto L310;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L310;
L330:
			jj = j;
			nn = n;
			ii = i__;
			mm = m;
			if (nn > mm) {
			    goto L340;
			}
			if (nn == mm) {
			    goto L350;
			}
			numb3 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[nn - 1] + jj;
			goto L360;
L340:
			numb3 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
			goto L360;
L350:
			if (jj >= ii) {
			    goto L340;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L340;
L360:
			jj = j;
			ll = l;
			ii = i__;
			mm = m;
			if (ll > mm) {
			    goto L370;
			}
			if (ll == mm) {
			    goto L380;
			}
			numb4 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[ll - 1] + ii;
			goto L390;
L370:
			numb4 = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			goto L390;
L380:
			if (ii >= jj) {
			    goto L370;
			}
			lt = ii;
			ii = jj;
			jj = lt;
			goto L370;
L390:
			asma_1.as2 += (p[numb] * 2. - p[numb1]) * (p[numb2] * 
				2. - p[numb3]) * p[numb4] / ((vector_2.eig[j 
				- 1] + vector_2.eig[i__ - 1] - vector_2.eig[m 
				- 1] - vector_2.eig[n - 1]) * (vector_2.eig[j 
				- 1] + vector_2.eig[i__ - 1] - vector_2.eig[m 
				- 1] - vector_2.eig[l - 1]));
/* L400: */
		    }
		}
	    }
	}
    }
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__3 = kyr2;
	    for (l = kyr1; l <= i__3; ++l) {
		i__4 = perem_1.nyr;
		for (i__ = myr1; i__ <= i__4; ++i__) {
		    i__5 = perem_1.nyr;
		    for (j = myr1; j <= i__5; ++j) {
			iyr = perem_1.iy;
			ll = l;
			jj = j;
			if (iyr >= ll) {
			    goto L410;
			}
			numb = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[iyr - 1] + iyr;
			goto L420;
L410:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[ll - 1] + jj;
L420:
			iyr = perem_1.iy;
			jj = j;
			ll = l;
			if (iyr > perem_1.nyr) {
			    goto L440;
			}
			if (iyr >= jj) {
			    goto L430;
			}
			numb1 = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[jj - 1] + iyr;
			goto L460;
L430:
			numb1 = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[iyr - 1] + jj;
			goto L460;
L440:
			if (iyr < ll) {
			    goto L430;
			}
			if (iyr > ll) {
			    goto L450;
			}
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * iyr 
				+ dod_1.it[iyr - 1] + dod_1.it[ll - 1] + jj;
			goto L460;
L450:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[iyr - 1] + jj;
L460:
			jj = j;
			mm = m;
			ii = i__;
			nn = n;
			if (mm > nn) {
			    goto L470;
			}
			if (mm == nn) {
			    goto L480;
			}
			numb2 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			goto L490;
L470:
			numb2 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ii;
			goto L490;
L480:
			if (jj >= ii) {
			    goto L470;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L470;
L490:
			jj = j;
			nn = n;
			ii = i__;
			mm = m;
			if (nn > mm) {
			    goto L500;
			}
			if (nn == mm) {
			    goto L510;
			}
			numb3 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[nn - 1] + jj;
			goto L520;
L500:
			numb3 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
			goto L520;
L510:
			if (jj >= ii) {
			    goto L500;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L500;
L520:
			mm = m;
			ll = l;
			ii = i__;
			nn = n;
			if (mm >= ll) {
			    goto L530;
			}
			lt = mm;
			mm = ll;
			ll = lt;
L530:
			if (mm >= nn) {
			    goto L540;
			}
			numb4 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + ll;
			goto L550;
L540:
			numb4 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[nn - 1] + ii;
L550:
			asma_1.as3 += (p[numb] * 2. - p[numb1]) * (p[numb2] * 
				2. - p[numb3]) * p[numb4] / ((vector_2.eig[j 
				- 1] + vector_2.eig[i__ - 1] - vector_2.eig[m 
				- 1] - vector_2.eig[n - 1]) * (vector_2.eig[j 
				- 1] - vector_2.eig[l - 1]));
/* L560: */
		    }
		}
	    }
	}
    }
    asma_1.as4 = asma_1.as3;
    i__5 = kyr2;
    for (m = kyr1; m <= i__5; ++m) {
	i__4 = kyr2;
	for (n = kyr1; n <= i__4; ++n) {
	    i__3 = perem_1.nyr;
	    for (i__ = myr1; i__ <= i__3; ++i__) {
		i__2 = perem_1.nyr;
		for (j = myr1; j <= i__2; ++j) {
		    i__1 = perem_1.nyr;
		    for (k = myr1; k <= i__1; ++k) {
			iyr = perem_1.iy;
			nn = n;
			kk = k;
			if (iyr >= nn) {
			    goto L570;
			}
			numb = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[iyr - 1] + iyr;
			goto L580;
L570:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[nn - 1] + kk;
L580:
			iyr = perem_1.iy;
			kk = k;
			nn = n;
			if (iyr > perem_1.nyr) {
			    goto L600;
			}
			if (iyr >= kk) {
			    goto L590;
			}
			numb1 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[kk - 1] + iyr;
			goto L620;
L590:
			numb1 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * iyr + 
				dod_1.it[iyr - 1] + dod_1.it[iyr - 1] + kk;
			goto L620;
L600:
			if (iyr < nn) {
			    goto L590;
			}
			if (iyr > nn) {
			    goto L610;
			}
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * iyr 
				+ dod_1.it[iyr - 1] + dod_1.it[nn - 1] + kk;
			goto L620;
L610:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[iyr - 1] + kk;
L620:
			jj = j;
			mm = m;
			ii = i__;
			nn = n;
			if (mm > nn) {
			    goto L630;
			}
			if (mm == nn) {
			    goto L640;
			}
			numb2 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			goto L650;
L630:
			numb2 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ii;
			goto L650;
L640:
			if (jj >= ii) {
			    goto L630;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L630;
L650:
			jj = j;
			nn = n;
			ii = i__;
			mm = m;
			if (nn > mm) {
			    goto L660;
			}
			if (nn == mm) {
			    goto L670;
			}
			numb3 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[nn - 1] + jj;
			goto L680;
L660:
			numb3 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
			goto L680;
L670:
			if (jj >= ii) {
			    goto L660;
			}
			lt = jj;
			jj = ii;
			ii = lt;
			goto L660;
L680:
			ii = i__;
			kk = k;
			jj = j;
			mm = m;
			if (ii >= kk) {
			    goto L690;
			}
			lt = ii;
			ii = kk;
			kk = lt;
L690:
			numb4 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[ii - 1] + kk;
			asma_1.as5 += (p[numb] * 2. - p[numb1]) * (p[numb2] * 
				2. - p[numb3]) * p[numb4] / ((vector_2.eig[j 
				- 1] + vector_2.eig[i__ - 1] - vector_2.eig[m 
				- 1] - vector_2.eig[n - 1]) * (vector_2.eig[k 
				- 1] - vector_2.eig[n - 1]));
/* L700: */
		    }
		}
	    }
	}
    }
    asma_1.as5 = -asma_1.as5;
    asma_1.as6 = asma_1.as5;
    return 0;
} /* asum_ */


/* ===================================================================== */

/* Subroutine */ int ccprod_(doublereal *c1, doublereal *c2, doublereal *c12, 
	integer *lm2, integer *lm6)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer ia, ib, ii, kk;
    static doublereal cs1, cs2, cpx1, cpy1, cpz1, cpx2, cpy2, cpz2;

/* ********************************************************* */
/*     PRODUCTS OF COEFFICIENTS.                          * */
/*     SUBROUTINE FROM QCPE 438,  MNDOC                   * */
/*     WRITTEN BY W.THIEL                                 * */
/*     SUBROUTINE NEED FOR GREEN FUNCTION CALCULATIONS    * */
/*     SUBROUTINE REWRITTEN BY D.DANOVICH                 * */
/* ********************************************************* */
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
    --c12;
    --c2;
    --c1;

    /* Function Body */
    kk = 0;
    i__1 = molkst_1.numat;
    for (ii = 1; ii <= i__1; ++ii) {
	ia = molkst_1.nfirst[ii - 1];
	ib = molkst_1.nlast[ii - 1];
	++kk;
	c12[kk] = c1[ia] * c2[ia];
	if (ia == ib) {
	    goto L10;
	}
	cs1 = c1[ia];
	cpx1 = c1[ia + 1];
	cpy1 = c1[ia + 2];
	cpz1 = c1[ia + 3];
	cs2 = c2[ia];
	cpx2 = c2[ia + 1];
	cpy2 = c2[ia + 2];
	cpz2 = c2[ia + 3];
	c12[kk + 1] = cpx1 * cs2 + cpx2 * cs1;
	c12[kk + 2] = cpx1 * cpx2;
	c12[kk + 3] = cpy1 * cs2 + cpy2 * cs1;
	c12[kk + 4] = cpy1 * cpx2 + cpy2 * cpx1;
	c12[kk + 5] = cpy1 * cpy2;
	c12[kk + 6] = cpz1 * cs2 + cpz2 * cs1;
	c12[kk + 7] = cpz1 * cpx2 + cpz2 * cpx1;
	c12[kk + 8] = cpz1 * cpy2 + cpz2 * cpy1;
	c12[kk + 9] = cpz1 * cpz2;
	kk += 9;
L10:
	;
    }
    return 0;
} /* ccprod_ */


/* ================================================================= */

/* Subroutine */ int csum_(doublereal *p, integer *ndis, doublereal *ep)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;

    /* Local variables */
    static integer i__, j, k, l, m, n, ii, jj, kk, ll, mm, nn, lt, iyr, kyr1, 
	    kyr2, myr1, numb, numb1, numb2, numb3;

/* *********************************************************** */
/*  CALCULATION 'CI' VALUES FOR GREEN'S FUNCTION METHOD     * */
/*  SUBROUTINE WRITTEN BY DR. DAVID DANOVICH, DEPARTMENT OF * */
/*  CHEMISTRY, TECHNION-ISRAEL INSTITUTE OF TECHNOLOGY,     * */
/*  HAIFA, 32000, ISRAEL.      VERSION:  2.09.90            * */
/* *********************************************************** */
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
    --p;

    /* Function Body */
    kyr2 = perem_1.nyr + perem_1.iggv;
    kyr1 = perem_1.nyr + 1;
    myr1 = perem_1.nyr - perem_1.iggw;
    csuc_1.cs1 = 0.;
    csuc_1.cs2 = 0.;
    csuc_1.cs3 = 0.;
    csuc_1.cs4 = 0.;
    csuc_1.cs5 = 0.;
    csuc_1.cs6 = 0.;
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__3 = kyr2;
	    for (l = kyr1; l <= i__3; ++l) {
		i__4 = kyr2;
		for (k = kyr1; k <= i__4; ++k) {
		    i__5 = perem_1.nyr;
		    for (i__ = myr1; i__ <= i__5; ++i__) {
			iyr = perem_1.iy;
			mm = m;
			ii = i__;
			nn = n;
			if (iyr >= mm) {
			    goto L2;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
L2:
			if (iyr > nn) {
			    goto L3;
			}
			if (iyr == nn) {
			    goto L4;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = mm;
			mm = ii;
			ii = lt;
			goto L3;
L4:
			if (mm >= ii) {
			    goto L3;
			}
			lt = mm;
			mm = ii;
			ii = lt;
L3:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * mm + 
				dod_1.it[mm - 1] + dod_1.it[nn - 1] + ii;
			iyr = perem_1.iy;
			nn = n;
			ii = i__;
			mm = m;
			if (iyr >= nn) {
			    goto L5;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
L5:
			if (iyr > mm) {
			    goto L6;
			}
			if (iyr == mm) {
			    goto L7;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = nn;
			nn = ii;
			ii = lt;
			goto L6;
L7:
			if (nn >= ii) {
			    goto L6;
			}
			lt = nn;
			nn = ii;
			ii = lt;
L6:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[mm - 1] + ii;
			kk = k;
			ll = l;
			mm = m;
			nn = n;
			if (mm >= ll) {
			    goto L8;
			}
			lt = mm;
			mm = ll;
			ll = lt;
L8:
			if (nn >= kk) {
			    goto L9;
			}
			lt = nn;
			nn = kk;
			kk = lt;
L9:
			if (mm > nn) {
			    goto L10;
			}
			if (mm == nn) {
			    goto L11;
			}
			lt = mm;
			mm = nn;
			nn = lt;
			lt = ll;
			ll = kk;
			kk = lt;
			goto L10;
L11:
			if (ll >= kk) {
			    goto L10;
			}
			lt = ll;
			ll = kk;
			kk = lt;
L10:
			numb2 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[nn - 1] + kk;
			iyr = perem_1.iy;
			ll = l;
			ii = i__;
			kk = k;
			if (iyr >= ll) {
			    goto L12;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
L12:
			if (iyr > kk) {
			    goto L13;
			}
			if (iyr == kk) {
			    goto L14;
			}
			lt = iyr;
			iyr = kk;
			kk = lt;
			lt = ll;
			ll = ii;
			ii = lt;
			goto L13;
L14:
			if (ll >= ii) {
			    goto L13;
			}
			lt = ll;
			ll = ii;
			ii = lt;
L13:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[kk - 1] + ii;
			csuc_1.cs1 += (p[numb] * 2. - p[numb1]) * p[numb2] * 
				p[numb3] / ((*ep + vector_3.eig[i__ - 1] - 
				vector_3.eig[m - 1] - vector_3.eig[n - 1]) * (
				*ep + vector_3.eig[i__ - 1] - vector_3.eig[l 
				- 1] - vector_3.eig[k - 1]));
/* L1: */
		    }
		}
	    }
	}
    }
    i__5 = kyr2;
    for (m = kyr1; m <= i__5; ++m) {
	i__4 = kyr2;
	for (n = kyr1; n <= i__4; ++n) {
	    i__3 = perem_1.nyr;
	    for (i__ = myr1; i__ <= i__3; ++i__) {
		i__2 = perem_1.nyr;
		for (j = myr1; j <= i__2; ++j) {
		    i__1 = perem_1.nyr;
		    for (k = myr1; k <= i__1; ++k) {
			iyr = perem_1.iy;
			mm = m;
			ii = i__;
			nn = n;
			if (iyr >= mm) {
			    goto L22;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
L22:
			if (iyr > nn) {
			    goto L23;
			}
			if (iyr == nn) {
			    goto L24;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = mm;
			mm = ii;
			ii = lt;
			goto L23;
L24:
			if (mm >= ii) {
			    goto L23;
			}
			lt = mm;
			mm = ii;
			ii = lt;
L23:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * mm + 
				dod_1.it[mm - 1] + dod_1.it[nn - 1] + ii;
			iyr = perem_1.iy;
			nn = n;
			ii = i__;
			mm = m;
			if (iyr >= nn) {
			    goto L25;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
L25:
			if (iyr > mm) {
			    goto L26;
			}
			if (iyr == mm) {
			    goto L27;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = nn;
			nn = ii;
			ii = lt;
			goto L26;
L27:
			if (nn >= ii) {
			    goto L26;
			}
			lt = nn;
			nn = ii;
			ii = lt;
L26:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[mm - 1] + ii;
			mm = m;
			jj = j;
			nn = n;
			kk = k;
			if (mm > nn) {
			    goto L28;
			}
			if (mm == nn) {
			    goto L29;
			}
			lt = mm;
			mm = nn;
			nn = lt;
			lt = jj;
			jj = kk;
			kk = lt;
			goto L28;
L29:
			if (jj >= kk) {
			    goto L28;
			}
			lt = jj;
			jj = kk;
			kk = lt;
L28:
			numb2 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + kk;
			iyr = perem_1.iy;
			jj = j;
			ii = i__;
			kk = k;
			if (iyr >= jj) {
			    goto L30;
			}
			lt = iyr;
			iyr = jj;
			jj = lt;
L30:
			if (ii >= kk) {
			    goto L31;
			}
			lt = ii;
			ii = kk;
			kk = lt;
L31:
			if (iyr > ii) {
			    goto L32;
			}
			if (iyr == ii) {
			    goto L33;
			}
			lt = iyr;
			iyr = ii;
			ii = lt;
			lt = jj;
			jj = kk;
			kk = lt;
			goto L32;
L33:
			if (jj >= kk) {
			    goto L32;
			}
			lt = jj;
			jj = kk;
			kk = lt;
L32:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[ii - 1] + kk;
			csuc_1.cs2 += (p[numb] * 2. - p[numb1]) * p[numb2] * 
				p[numb3] / ((*ep + vector_3.eig[i__ - 1] - 
				vector_3.eig[m - 1] - vector_3.eig[n - 1]) * (
				vector_3.eig[j - 1] + vector_3.eig[k - 1] - 
				vector_3.eig[m - 1] - vector_3.eig[n - 1]));
/* L21: */
		    }
		}
	    }
	}
    }
    csuc_1.cs3 = csuc_1.cs2;
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__3 = kyr2;
	    for (l = kyr1; l <= i__3; ++l) {
		i__4 = perem_1.nyr;
		for (i__ = myr1; i__ <= i__4; ++i__) {
		    i__5 = perem_1.nyr;
		    for (j = myr1; j <= i__5; ++j) {
			iyr = perem_1.iy;
			mm = m;
			ii = i__;
			jj = j;
			if (iyr >= ii) {
			    goto L42;
			}
			lt = iyr;
			iyr = ii;
			ii = lt;
L42:
			if (iyr > mm) {
			    goto L43;
			}
			if (iyr == mm) {
			    goto L44;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L43;
L44:
			if (ii >= jj) {
			    goto L43;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L43:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			iyr = perem_1.iy;
			jj = j;
			ii = i__;
			mm = m;
			if (iyr >= jj) {
			    goto L45;
			}
			lt = iyr;
			iyr = jj;
			jj = lt;
L45:
			if (iyr > mm) {
			    goto L46;
			}
			if (iyr == mm) {
			    goto L47;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = jj;
			jj = ii;
			ii = lt;
			goto L46;
L47:
			if (jj >= ii) {
			    goto L46;
			}
			lt = jj;
			jj = ii;
			ii = lt;
L46:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
			ii = i__;
			jj = j;
			nn = n;
			ll = l;
			if (nn > ll) {
			    goto L48;
			}
			if (nn == ll) {
			    goto L49;
			}
			lt = nn;
			nn = ll;
			ll = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L48;
L49:
			if (ii >= jj) {
			    goto L48;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L48:
			numb2 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[ll - 1] + jj;
			iyr = perem_1.iy;
			nn = n;
			mm = m;
			ll = l;
			if (iyr >= nn) {
			    goto L50;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
L50:
			if (mm >= ll) {
			    goto L51;
			}
			lt = mm;
			mm = ll;
			ll = lt;
L51:
			if (iyr > mm) {
			    goto L52;
			}
			if (iyr == mm) {
			    goto L53;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = nn;
			nn = ll;
			ll = lt;
			goto L52;
L53:
			if (nn >= ll) {
			    goto L52;
			}
			lt = nn;
			nn = ll;
			ll = lt;
L52:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[mm - 1] + ll;
			csuc_1.cs4 += (p[numb] * 2. - p[numb1]) * p[numb2] * 
				p[numb3] / ((*ep + vector_3.eig[m - 1] - 
				vector_3.eig[i__ - 1] - vector_3.eig[j - 1]) *
				 (vector_3.eig[i__ - 1] + vector_3.eig[j - 1] 
				- vector_3.eig[n - 1] - vector_3.eig[l - 1]));
/* L41: */
		    }
		}
	    }
	}
    }
    csuc_1.cs5 = csuc_1.cs4;
    i__5 = kyr2;
    for (m = kyr1; m <= i__5; ++m) {
	i__4 = perem_1.nyr;
	for (i__ = myr1; i__ <= i__4; ++i__) {
	    i__3 = perem_1.nyr;
	    for (j = myr1; j <= i__3; ++j) {
		i__2 = perem_1.nyr;
		for (k = myr1; k <= i__2; ++k) {
		    i__1 = perem_1.nyr;
		    for (l = myr1; l <= i__1; ++l) {
			iyr = perem_1.iy;
			mm = m;
			kk = k;
			ll = l;
			if (iyr >= kk) {
			    goto L62;
			}
			lt = iyr;
			iyr = kk;
			kk = lt;
L62:
			if (iyr > mm) {
			    goto L63;
			}
			if (iyr == mm) {
			    goto L64;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = kk;
			kk = ll;
			ll = lt;
			goto L63;
L64:
			if (kk >= ll) {
			    goto L63;
			}
			lt = kk;
			kk = ll;
			ll = lt;
L63:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[mm - 1] + ll;
			iyr = perem_1.iy;
			ll = l;
			kk = k;
			mm = m;
			if (iyr >= ll) {
			    goto L65;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
L65:
			if (iyr > mm) {
			    goto L66;
			}
			if (iyr == mm) {
			    goto L67;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = ll;
			ll = kk;
			kk = lt;
			goto L66;
L67:
			if (ll >= kk) {
			    goto L66;
			}
			lt = ll;
			ll = kk;
			kk = lt;
L66:
			numb1 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[mm - 1] + kk;
			kk = k;
			ii = i__;
			ll = l;
			jj = j;
			if (kk >= ii) {
			    goto L68;
			}
			lt = kk;
			kk = ii;
			ii = lt;
L68:
			if (ll >= jj) {
			    goto L69;
			}
			lt = ll;
			ll = jj;
			jj = lt;
L69:
			if (kk > ll) {
			    goto L70;
			}
			if (kk == ll) {
			    goto L71;
			}
			lt = kk;
			kk = ll;
			ll = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L70;
L71:
			if (ii >= jj) {
			    goto L70;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L70:
			numb2 = dod_1.itl[kk - 1] + dod_1.it[kk - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[ll - 1] + jj;
			iyr = perem_1.iy;
			ii = i__;
			mm = m;
			jj = j;
			if (iyr >= ii) {
			    goto L72;
			}
			lt = iyr;
			iyr = ii;
			ii = lt;
L72:
			if (iyr > mm) {
			    goto L73;
			}
			if (iyr == mm) {
			    goto L74;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L73;
L74:
			if (ii >= jj) {
			    goto L73;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L73:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + jj;
			csuc_1.cs6 += (p[numb] * 2. - p[numb1]) * p[numb2] * 
				p[numb3] / ((*ep + vector_3.eig[m - 1] - 
				vector_3.eig[i__ - 1] - vector_3.eig[j - 1]) *
				 (*ep + vector_3.eig[m - 1] - vector_3.eig[k 
				- 1] - vector_3.eig[l - 1]));
/* L61: */
		    }
		}
	    }
	}
    }
    csuc_1.cs6 = -csuc_1.cs6;
    return 0;
} /* csum_ */


/* =================================================================== */

/* Subroutine */ int dsum_(doublereal *p, integer *ndis, doublereal *ep)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5;

    /* Local variables */
    static integer i__, j, k, l, m, n, ii, jj, kk, ll, mm, nn, lt, iyr, kyr1, 
	    kyr2, myr1, numb, numb1, numb2, numb3, numb4, numb5, numb6;

/* ************************************************************* */
/*  CALCULATION 'DI' VALUES FOR GREEN'S FUNCTION METHOD       * */
/*  SUBROUTINE WRITTEN BY DR. DAVID DANOVICH, DEPARTMENT OF   * */
/*  CHEMISTRY, TECHNION-ISRAEL INSTITUTE OF TECHNOLOGY,       * */
/*  HAIFA, 32000, ISRAEL.            VERSION: 2.09.90         * */
/* ************************************************************* */
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
    --p;

    /* Function Body */
    kyr2 = perem_1.nyr + perem_1.iggv;
    kyr1 = perem_1.nyr + 1;
    myr1 = perem_1.nyr - perem_1.iggw;
    dsmd_1.ds1 = 0.;
    dsmd_1.ds2 = 0.;
    dsmd_1.ds3 = 0.;
    dsmd_1.ds4 = 0.;
    dsmd_1.ds5 = 0.;
    dsmd_1.ds6 = 0.;
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__3 = kyr2;
	    for (l = kyr1; l <= i__3; ++l) {
		i__4 = perem_1.nyr;
		for (i__ = myr1; i__ <= i__4; ++i__) {
		    i__5 = perem_1.nyr;
		    for (j = myr1; j <= i__5; ++j) {
			iyr = perem_1.iy;
			mm = m;
			ii = i__;
			nn = n;
			if (iyr >= mm) {
			    goto L10;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
L10:
			if (iyr > nn) {
			    goto L30;
			}
			if (iyr == nn) {
			    goto L20;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = mm;
			mm = ii;
			ii = lt;
			goto L30;
L20:
			if (mm >= ii) {
			    goto L30;
			}
			lt = mm;
			mm = ii;
			ii = lt;
L30:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * mm + 
				dod_1.it[mm - 1] + dod_1.it[nn - 1] + ii;
			mm = m;
			ii = i__;
			jj = j;
			ll = l;
			if (mm > ll) {
			    goto L50;
			}
			if (mm == ll) {
			    goto L40;
			}
			lt = mm;
			mm = ll;
			ll = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L50;
L40:
			if (ii >= jj) {
			    goto L50;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L50:
			numb1 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[ll - 1] + jj;
			iyr = perem_1.iy;
			ll = l;
			jj = j;
			nn = n;
			if (iyr >= ll) {
			    goto L60;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
L60:
			if (iyr > nn) {
			    goto L80;
			}
			if (iyr == nn) {
			    goto L70;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = ll;
			ll = jj;
			jj = lt;
			goto L80;
L70:
			if (ll >= jj) {
			    goto L80;
			}
			lt = ll;
			ll = jj;
			jj = lt;
L80:
			numb2 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[nn - 1] + jj;
			iyr = perem_1.iy;
			ll = l;
			nn = n;
			jj = j;
			if (iyr >= nn) {
			    goto L90;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
L90:
			if (iyr > ll) {
			    goto L110;
			}
			if (iyr == ll) {
			    goto L100;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
			lt = nn;
			nn = jj;
			jj = lt;
			goto L110;
L100:
			if (nn >= jj) {
			    goto L110;
			}
			lt = nn;
			nn = jj;
			jj = lt;
L110:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[ll - 1] + jj;
			mm = m;
			ll = l;
			jj = j;
			ii = i__;
			if (mm >= ll) {
			    goto L120;
			}
			lt = mm;
			mm = ll;
			ll = lt;
L120:
			if (jj >= ii) {
			    goto L130;
			}
			lt = jj;
			jj = ii;
			ii = lt;
L130:
			numb4 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[jj - 1] + ii;
			iyr = perem_1.iy;
			nn = n;
			ii = i__;
			mm = m;
			if (iyr >= nn) {
			    goto L140;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
L140:
			if (iyr > mm) {
			    goto L160;
			}
			if (iyr == mm) {
			    goto L150;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = nn;
			nn = ii;
			ii = lt;
			goto L160;
L150:
			if (nn >= ii) {
			    goto L160;
			}
			lt = nn;
			nn = ii;
			ii = lt;
L160:
			numb6 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[mm - 1] + ii;
			dsmd_1.ds1 += p[numb] * (p[numb1] * (p[numb2] - p[
				numb3] * 2.) + p[numb4] * (p[numb3] - p[numb2]
				 * 2.)) / ((*ep + vector_2.eig[i__ - 1] - 
				vector_2.eig[m - 1] - vector_2.eig[n - 1]) * (
				*ep + vector_2.eig[j - 1] - vector_2.eig[n - 
				1] - vector_2.eig[l - 1])) + p[numb6] * (p[
				numb1] * (p[numb3] * 4. - p[numb2] * 2.) + p[
				numb4] * (p[numb2] - p[numb3] * 2.)) / ((*ep 
				+ vector_2.eig[i__ - 1] - vector_2.eig[m - 1] 
				- vector_2.eig[n - 1]) * (*ep + vector_2.eig[
				j - 1] - vector_2.eig[n - 1] - vector_2.eig[l 
				- 1]));
/* L170: */
		    }
		}
	    }
	}
    }
    i__5 = kyr2;
    for (m = kyr1; m <= i__5; ++m) {
	i__4 = kyr2;
	for (n = kyr1; n <= i__4; ++n) {
	    i__3 = kyr2;
	    for (l = kyr1; l <= i__3; ++l) {
		i__2 = perem_1.nyr;
		for (i__ = myr1; i__ <= i__2; ++i__) {
		    i__1 = perem_1.nyr;
		    for (j = myr1; j <= i__1; ++j) {
			iyr = perem_1.iy;
			mm = m;
			ii = i__;
			ll = l;
			if (iyr >= ll) {
			    goto L180;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
L180:
			if (iyr > mm) {
			    goto L200;
			}
			if (iyr == mm) {
			    goto L190;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = ll;
			ll = ii;
			ii = lt;
			goto L200;
L190:
			if (ll >= ii) {
			    goto L200;
			}
			lt = ll;
			ll = ii;
			ii = lt;
L200:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[mm - 1] + ii;
			mm = m;
			ii = i__;
			jj = j;
			nn = n;
			if (mm > nn) {
			    goto L220;
			}
			if (mm == nn) {
			    goto L210;
			}
			lt = mm;
			mm = nn;
			nn = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L220;
L210:
			if (ii >= jj) {
			    goto L220;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L220:
			numb1 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[nn - 1] + jj;
			iyr = perem_1.iy;
			ll = l;
			jj = j;
			nn = n;
			if (iyr >= ll) {
			    goto L230;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
L230:
			if (iyr > nn) {
			    goto L250;
			}
			if (iyr == nn) {
			    goto L240;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = ll;
			ll = jj;
			jj = lt;
			goto L250;
L240:
			if (ll >= jj) {
			    goto L250;
			}
			lt = ll;
			ll = jj;
			jj = lt;
L250:
			numb2 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ll + 
				dod_1.it[ll - 1] + dod_1.it[nn - 1] + jj;
			iyr = perem_1.iy;
			ll = l;
			nn = n;
			jj = j;
			if (iyr >= jj) {
			    goto L260;
			}
			lt = iyr;
			iyr = jj;
			jj = lt;
L260:
			if (nn >= ll) {
			    goto L270;
			}
			lt = nn;
			nn = ll;
			ll = lt;
L270:
			if (iyr > nn) {
			    goto L290;
			}
			if (iyr == nn) {
			    goto L280;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = jj;
			jj = ll;
			ll = lt;
			goto L290;
L280:
			if (jj >= ll) {
			    goto L290;
			}
			lt = jj;
			jj = ll;
			ll = lt;
L290:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ll;
			mm = m;
			nn = n;
			jj = j;
			ii = i__;
			if (mm > nn) {
			    goto L310;
			}
			if (mm == nn) {
			    goto L300;
			}
			lt = mm;
			mm = nn;
			nn = lt;
			lt = jj;
			jj = ii;
			ii = lt;
			goto L310;
L300:
			if (jj >= ii) {
			    goto L310;
			}
			lt = jj;
			jj = ii;
			ii = lt;
L310:
			numb4 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ii;
			iyr = perem_1.iy;
			ll = l;
			ii = i__;
			mm = m;
			if (iyr >= mm) {
			    goto L320;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
L320:
			if (iyr > ll) {
			    goto L340;
			}
			if (iyr == ll) {
			    goto L330;
			}
			lt = iyr;
			iyr = ll;
			ll = lt;
			lt = mm;
			mm = ii;
			ii = lt;
			goto L340;
L330:
			if (mm >= ii) {
			    goto L340;
			}
			lt = mm;
			mm = ii;
			ii = lt;
L340:
			numb5 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * mm + 
				dod_1.it[mm - 1] + dod_1.it[ll - 1] + ii;
			dsmd_1.ds2 += p[numb] * (p[numb1] * (p[numb2] * 4. - 
				p[numb3] * 2.) + p[numb4] * (p[numb3] - p[
				numb2] * 2.)) / ((*ep + vector_2.eig[i__ - 1] 
				- vector_2.eig[m - 1] - vector_2.eig[l - 1]) *
				 (vector_2.eig[i__ - 1] + vector_2.eig[j - 1] 
				- vector_2.eig[m - 1] - vector_2.eig[n - 1])) 
				+ p[numb5] * (p[numb1] * (p[numb3] - p[numb2] 
				* 2.) + p[numb4] * (p[numb2] - p[numb3] * 2.))
				 / ((*ep + vector_2.eig[i__ - 1] - 
				vector_2.eig[m - 1] - vector_2.eig[l - 1]) * (
				vector_2.eig[i__ - 1] + vector_2.eig[j - 1] - 
				vector_2.eig[m - 1] - vector_2.eig[n - 1]));
/* L350: */
		    }
		}
	    }
	}
    }
    dsmd_1.ds3 = dsmd_1.ds2;
    i__1 = kyr2;
    for (m = kyr1; m <= i__1; ++m) {
	i__2 = kyr2;
	for (n = kyr1; n <= i__2; ++n) {
	    i__3 = perem_1.nyr;
	    for (i__ = myr1; i__ <= i__3; ++i__) {
		i__4 = perem_1.nyr;
		for (j = myr1; j <= i__4; ++j) {
		    i__5 = perem_1.nyr;
		    for (k = myr1; k <= i__5; ++k) {
			iyr = perem_1.iy;
			mm = m;
			kk = k;
			jj = j;
			if (iyr >= kk) {
			    goto L360;
			}
			lt = iyr;
			iyr = kk;
			kk = lt;
L360:
			if (iyr > mm) {
			    goto L380;
			}
			if (iyr == mm) {
			    goto L370;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = kk;
			kk = jj;
			jj = lt;
			goto L380;
L370:
			if (kk >= jj) {
			    goto L380;
			}
			lt = kk;
			kk = jj;
			jj = lt;
L380:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[mm - 1] + jj;
			mm = m;
			ii = i__;
			jj = j;
			nn = n;
			if (mm > nn) {
			    goto L400;
			}
			if (mm == nn) {
			    goto L390;
			}
			lt = mm;
			mm = nn;
			nn = lt;
			lt = jj;
			jj = ii;
			ii = lt;
			goto L400;
L390:
			if (jj >= ii) {
			    goto L400;
			}
			lt = jj;
			jj = ii;
			ii = lt;
L400:
			numb1 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + ii;
			iyr = perem_1.iy;
			kk = k;
			ii = i__;
			nn = n;
			if (iyr >= kk) {
			    goto L410;
			}
			lt = iyr;
			iyr = kk;
			kk = lt;
L410:
			if (iyr > nn) {
			    goto L430;
			}
			if (iyr == nn) {
			    goto L420;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = kk;
			kk = ii;
			ii = lt;
			goto L430;
L420:
			if (kk >= ii) {
			    goto L430;
			}
			lt = kk;
			kk = ii;
			ii = lt;
L430:
			numb2 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[nn - 1] + ii;
			iyr = perem_1.iy;
			ii = i__;
			nn = n;
			kk = k;
			if (iyr >= nn) {
			    goto L440;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
L440:
			if (ii >= kk) {
			    goto L450;
			}
			lt = ii;
			ii = kk;
			kk = lt;
L450:
			if (iyr > ii) {
			    goto L470;
			}
			if (iyr == ii) {
			    goto L460;
			}
			lt = iyr;
			iyr = ii;
			ii = lt;
			lt = nn;
			nn = kk;
			kk = lt;
			goto L470;
L460:
			if (nn >= kk) {
			    goto L470;
			}
			lt = nn;
			nn = kk;
			kk = lt;
L470:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * nn + 
				dod_1.it[nn - 1] + dod_1.it[ii - 1] + kk;
			mm = m;
			nn = n;
			jj = j;
			ii = i__;
			if (nn > mm) {
			    goto L490;
			}
			if (nn == mm) {
			    goto L480;
			}
			lt = nn;
			nn = mm;
			mm = lt;
			lt = jj;
			jj = ii;
			ii = lt;
			goto L490;
L480:
			if (jj >= ii) {
			    goto L490;
			}
			lt = jj;
			jj = ii;
			ii = lt;
L490:
			numb4 = dod_1.itl[nn - 1] + dod_1.it[nn - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + ii;
			iyr = perem_1.iy;
			jj = j;
			kk = k;
			mm = m;
			if (iyr >= jj) {
			    goto L500;
			}
			lt = iyr;
			iyr = jj;
			jj = lt;
L500:
			if (iyr > mm) {
			    goto L520;
			}
			if (iyr == mm) {
			    goto L510;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = jj;
			jj = kk;
			kk = lt;
			goto L520;
L510:
			if (jj >= kk) {
			    goto L520;
			}
			lt = jj;
			jj = kk;
			kk = lt;
L520:
			numb5 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[mm - 1] + kk;
			dsmd_1.ds4 += p[numb] * (p[numb1] * (p[numb2] * 4. - 
				p[numb3] * 2.) + p[numb4] * (p[numb3] - p[
				numb2] * 2.)) / ((*ep + vector_2.eig[m - 1] - 
				vector_2.eig[j - 1] - vector_2.eig[k - 1]) * (
				vector_2.eig[i__ - 1] + vector_2.eig[j - 1] - 
				vector_2.eig[m - 1] - vector_2.eig[n - 1])) + 
				p[numb5] * (p[numb1] * (p[numb3] - p[numb2] * 
				2.) + p[numb4] * (p[numb2] - p[numb3] * 2)) / 
				((*ep + vector_2.eig[m - 1] - vector_2.eig[j 
				- 1] - vector_2.eig[k - 1]) * (vector_2.eig[
				i__ - 1] + vector_2.eig[j - 1] - vector_2.eig[
				m - 1] - vector_2.eig[n - 1]));
/* L530: */
		    }
		}
	    }
	}
    }
    dsmd_1.ds5 = dsmd_1.ds4;
    i__5 = kyr2;
    for (m = kyr1; m <= i__5; ++m) {
	i__4 = kyr2;
	for (n = kyr1; n <= i__4; ++n) {
	    i__3 = perem_1.nyr;
	    for (i__ = myr1; i__ <= i__3; ++i__) {
		i__2 = perem_1.nyr;
		for (j = myr1; j <= i__2; ++j) {
		    i__1 = perem_1.nyr;
		    for (k = myr1; k <= i__1; ++k) {
			iyr = perem_1.iy;
			mm = m;
			kk = k;
			ii = i__;
			if (iyr >= kk) {
			    goto L540;
			}
			lt = iyr;
			iyr = kk;
			kk = lt;
L540:
			if (iyr > mm) {
			    goto L560;
			}
			if (iyr == mm) {
			    goto L550;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = kk;
			kk = ii;
			ii = lt;
			goto L560;
L550:
			if (kk >= ii) {
			    goto L560;
			}
			lt = kk;
			kk = ii;
			ii = lt;
L560:
			numb = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[mm - 1] + ii;
			mm = m;
			ii = i__;
			jj = j;
			nn = n;
			if (mm > nn) {
			    goto L580;
			}
			if (mm == nn) {
			    goto L570;
			}
			lt = mm;
			mm = nn;
			nn = lt;
			lt = ii;
			ii = jj;
			jj = lt;
			goto L580;
L570:
			if (ii >= jj) {
			    goto L580;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L580:
			numb1 = dod_1.itl[mm - 1] + dod_1.it[mm - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[nn - 1] + jj;
			iyr = perem_1.iy;
			kk = k;
			jj = j;
			nn = n;
			if (iyr >= kk) {
			    goto L590;
			}
			lt = iyr;
			iyr = kk;
			kk = lt;
L590:
			if (iyr > nn) {
			    goto L610;
			}
			if (iyr == nn) {
			    goto L600;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = kk;
			kk = jj;
			jj = lt;
			goto L610;
L600:
			if (kk >= jj) {
			    goto L610;
			}
			lt = kk;
			kk = jj;
			jj = lt;
L610:
			numb2 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * kk + 
				dod_1.it[kk - 1] + dod_1.it[nn - 1] + jj;
			iyr = perem_1.iy;
			jj = j;
			nn = n;
			kk = k;
			if (iyr >= jj) {
			    goto L620;
			}
			lt = iyr;
			iyr = jj;
			jj = lt;
L620:
			if (iyr > nn) {
			    goto L640;
			}
			if (iyr == nn) {
			    goto L630;
			}
			lt = iyr;
			iyr = nn;
			nn = lt;
			lt = jj;
			jj = kk;
			kk = lt;
			goto L640;
L630:
			if (jj >= kk) {
			    goto L640;
			}
			lt = jj;
			jj = kk;
			kk = lt;
L640:
			numb3 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + kk;
			mm = m;
			nn = n;
			jj = j;
			ii = i__;
			if (ii >= jj) {
			    goto L650;
			}
			lt = ii;
			ii = jj;
			jj = lt;
L650:
			if (nn >= mm) {
			    goto L660;
			}
			lt = nn;
			nn = mm;
			mm = lt;
L660:
			if (ii > nn) {
			    goto L680;
			}
			if (ii == nn) {
			    goto L670;
			}
			lt = ii;
			ii = nn;
			nn = lt;
			lt = jj;
			jj = mm;
			mm = lt;
			goto L680;
L670:
			if (jj >= mm) {
			    goto L680;
			}
			lt = jj;
			jj = mm;
			mm = lt;
L680:
			numb4 = dod_1.itl[ii - 1] + dod_1.it[ii - 1] * jj + 
				dod_1.it[jj - 1] + dod_1.it[nn - 1] + mm;
			iyr = perem_1.iy;
			ii = i__;
			kk = k;
			mm = m;
			if (iyr >= ii) {
			    goto L690;
			}
			lt = iyr;
			iyr = ii;
			ii = lt;
L690:
			if (iyr > mm) {
			    goto L710;
			}
			if (iyr == mm) {
			    goto L700;
			}
			lt = iyr;
			iyr = mm;
			mm = lt;
			lt = ii;
			ii = kk;
			kk = lt;
			goto L710;
L700:
			if (ii >= kk) {
			    goto L710;
			}
			lt = ii;
			ii = kk;
			kk = lt;
L710:
			numb5 = dod_1.itl[iyr - 1] + dod_1.it[iyr - 1] * ii + 
				dod_1.it[ii - 1] + dod_1.it[mm - 1] + kk;
			dsmd_1.ds6 += p[numb] * (p[numb1] * (p[numb2] * 4. - 
				p[numb3] * 2.) + p[numb4] * (p[numb3] - p[
				numb2] * 2.)) / ((*ep + vector_2.eig[m - 1] - 
				vector_2.eig[i__ - 1] - vector_2.eig[k - 1]) *
				 (*ep + vector_2.eig[n - 1] - vector_2.eig[j 
				- 1] - vector_2.eig[k - 1])) + p[numb5] * (p[
				numb1] * (p[numb3] - p[numb2] * 2.) + p[numb4]
				 * (p[numb2] - p[numb3] * 2.)) / ((*ep + 
				vector_2.eig[m - 1] - vector_2.eig[i__ - 1] - 
				vector_2.eig[k - 1]) * (*ep + vector_2.eig[n 
				- 1] - vector_2.eig[j - 1] - vector_2.eig[k - 
				1]));
/* L720: */
		    }
		}
	    }
	}
    }
    dsmd_1.ds6 = -dsmd_1.ds6;
    return 0;
} /* dsum_ */


/* ==================================================================== */

/* Subroutine */ int fcnpp_(doublereal *p, integer *ndis)
{
    /* Format strings */
    static char fmt_1[] = "(//5x,\002number of nonzero integrals =\002,i10,5"
	    "x,\002Total number of MO  =\002,i4)";
    static char fmt_2[] = "(//35x,\002  Orbital energy \002)";
    static char fmt_3[] = "(/5x,10i7)";
    static char fmt_4[] = "(//5x,10f7.3)";
    static char fmt_5[] = "(//5x,\002 Higher occupied MO  is  \002,i4,\002  "
	    "MO \002)";
    static char fmt_120[] = "(///5x,\002TOTAL NUMBER OF OCCUPIED ORBITALS IN"
	    "VOLVED IN THE\002/5x,\002 OVGF CALCULATION =\002,i3/5x,\002TOTAL"
	    " NUMBER OF UNOCCUPIED \002,\002ORBITALS INVOLVED IN THE\002/5x"
	    ",\002 OVGF CALCULATION =\002,i3/5x,\002THE NUMBER OF FIRST OCCUP"
	    "IED MO FOR WHICH OVGF CORRECTION \002/5x,\002MUST BE STARTED "
	    "=\002,i3/5x,\002THE NUMBER OF LAST OCCUPIED MO FOR WHICH OVGF CO"
	    "RRECTION \002/5x,\002MUST BE  FINISHED =\002,i3/5x,\002TOLERANCE"
	    " FACTOR = \002,f12.8/5x,\002SECOND-ORDER CONTRIBUTION = \002,i3/"
	    "5x,\002THIRD-ORDER CONTRIBUTION = \002,i3/5x,\002FULL EXPRESSION"
	    " = \002,i3/5x,\002PRINT FACTOR = \002,i3/5x,\002ONLY SECOND-ORDE"
	    "R CONTRIBUTION = \002,i3)";
    static char fmt_122[] = "(/5x,\002EP =\002,f18.8)";
    static char fmt_154[] = "(/5x,\002 W1 = \002,f12.8,5x,\002 IR = \002,i5)";
    static char fmt_121[] = "(/5x,\002NUMH =\002,i4,5x,\002NUMV =\002,i4)";
    static char fmt_28[] = "(/5x,\002 SU2R=0 ON 0  STEP \002)";
    static char fmt_32[] = "(/5x,\002 SU2R =0 ON \002,i5,\002 STEP \002)";
    static char fmt_36[] = "(/5x,\002SUM1=0 ON 0  STEP  \002)";
    static char fmt_39[] = "(/5x,\002 SUM2 = 0 ON 0  STEP \002)";
    static char fmt_43[] = "(/5x,\002SUM1=0 ON\002,i5,\002 STEP  \002)";
    static char fmt_46[] = "(/5x,\002 SUM2 = 0 ON\002,i5,\002  STEP \002)";
    static char fmt_51[] = "(/5x,\002SUM1 B 3 =0 ON 0  STEP  \002)";
    static char fmt_54[] = "(/5x,\002 SUM2 B 3 = 0 ON 0  STEP \002)";
    static char fmt_56[] = "(/5x,\002 SZAM 0 ON 0  STEP \002)";
    static char fmt_61[] = "(/5x,\002SUM1=0 ON\002,i5,\002  STEP \002)";
    static char fmt_64[] = "(/5x,\002 SUM2 = 0 ON\002,i5,\002  STEP \002)";
    static char fmt_66[] = "(/5x,\002 SZAM 0 ON\002,i5,\002  STEP \002)";
    static char fmt_13[] = "(///5x,\002 RESULTS OF CALCULATION PES  \002)";
    static char fmt_14[] = "(/1x,\002LEVEL \002,3x,\002 2   \002,2x,\002 IR"
	    " \002,3x,\002 3   \002,2x,\002 IR \002,3x,\002 FINAL \002,2x,"
	    "\002 IR \002,3x,\002 SCF\002)";
    static char fmt_82[] = "(/i3,5x,f7.3,3x,i2,2x,f7.3,3x,i2,2x,f7.3,4x,i2,4"
	    "x,f7.3)";
    static char fmt_83[] = "(//5x,\002 IN CALCULATED USED \002,i5,\002 HOMO "
	    " and \002,i5,\002 LUMO \002/5x,\002 ACCURACY SELFCONSISTENT  ="
	    " \002,f12.8/5x,\002 FINAL RESULT CALCULATED BY \002,i3,\002  MET"
	    "HOD \002)";
    static char fmt_84[] = "(//6x,\002FINAL=0, CALCULATED BY  FORMULA W=EP+S"
	    "UM2+(1+A)\002,\002**(-1)*SU3R\002/6x,\002FINAL=1, CALCULATED BY "
	    "FORMULA W=EP+SUM2+(1+G1)**-1)\002/3x,\002*(CS4+CS5+CS6+DS4+DS5+D"
	    "S6)+(1+G2)**(-1)*(CS1+CS2+CS3+DS1\002/3x,\002+DS2+DS3)+AA\002/6x,"
	    "\002FINAL= -1, CALCULATED BY FORMULA W=EP+SUM2+(1+A)**(-1)*SUM"
	    "3\002)";
    static char fmt_320[] = "(5x,\002JJ=\002,i5,5x,\002II=\002,i5,5x,\002LL"
	    "=\002,i5)";
    static char fmt_355[] = "(//5x,\002 CALCULATION RELAXATION EFFECTS ONL"
	    "Y  \002)";
    static char fmt_359[] = "(/3x,\002LEVEL\002,2x,\002R.effect\002,3x,\002E"
	    "NERGY SCF\002,5x,\002ENERGY\002)";
    static char fmt_358[] = "(/3x,i3,2x,f10.6,3x,f8.4,8x,f8.4)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_rsfe(cilist *), e_rsfe(void);
    double pow_di(doublereal *, integer *);

    /* Local variables */
    static doublereal a;
    static integer i__, j, l;
    static doublereal w, g1, g2, w1;
    static integer ii, jj;
    static doublereal ep;
    static integer ll, ir, lt;
    static doublereal ps, eg2[20];
    static integer ig2[20];
    static doublereal ega[20], eg23[20];
    static integer iga[20], ig23[20], iii, kil, it23;
    static doublereal rir[20];
    static integer niz, num1, num2;
    static doublereal faca, su3r;
    static integer namb;
    static char line[80];
    static integer ieps, numb, iver;
    extern /* Subroutine */ int asum_(doublereal *, integer *);
    static integer numh;
    extern /* Subroutine */ int csum_(doublereal *, integer *, doublereal *), 
	    dsum_(doublereal *, integer *, doublereal *);
    static doublereal szam;
    static integer nymb;
    static doublereal prir[20];
    static integer numv;
    static doublereal zniz;
    static integer iter2, iter3;
    extern /* Subroutine */ int suma2_(doublereal *, integer *, doublereal *);
    static integer nymb1;
    static doublereal value[40];
    static integer iggww;
    static doublereal zsuma, zverx;
    extern /* Subroutine */ int nuchar_(char *, doublereal *, integer *, 
	    ftnlen);
    static integer nvalue, ifulit, iprint;

    /* Fortran I/O blocks */
    static cilist io___191 = { 0, 6, 0, fmt_1, 0 };
    static cilist io___192 = { 0, 6, 0, fmt_2, 0 };
    static cilist io___193 = { 0, 6, 0, fmt_3, 0 };
    static cilist io___195 = { 0, 6, 0, fmt_4, 0 };
    static cilist io___197 = { 0, 6, 0, fmt_5, 0 };
    static cilist io___206 = { 0, 5, 0, "(A)", 0 };
    static cilist io___219 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___224 = { 0, 6, 0, fmt_122, 0 };
    static cilist io___228 = { 0, 6, 0, fmt_154, 0 };
    static cilist io___229 = { 0, 6, 0, fmt_122, 0 };
    static cilist io___231 = { 0, 6, 0, fmt_154, 0 };
    static cilist io___232 = { 0, 6, 0, fmt_121, 0 };
    static cilist io___233 = { 0, 6, 0, fmt_122, 0 };
    static cilist io___235 = { 0, 6, 0, fmt_28, 0 };
    static cilist io___236 = { 0, 6, 0, fmt_32, 0 };
    static cilist io___237 = { 0, 6, 0, fmt_154, 0 };
    static cilist io___238 = { 0, 6, 0, fmt_122, 0 };
    static cilist io___240 = { 0, 6, 0, fmt_36, 0 };
    static cilist io___242 = { 0, 6, 0, fmt_39, 0 };
    static cilist io___243 = { 0, 6, 0, fmt_43, 0 };
    static cilist io___244 = { 0, 6, 0, fmt_46, 0 };
    static cilist io___245 = { 0, 6, 0, fmt_154, 0 };
    static cilist io___246 = { 0, 6, 0, fmt_122, 0 };
    static cilist io___247 = { 0, 6, 0, fmt_51, 0 };
    static cilist io___248 = { 0, 6, 0, fmt_54, 0 };
    static cilist io___250 = { 0, 6, 0, fmt_56, 0 };
    static cilist io___252 = { 0, 6, 0, fmt_61, 0 };
    static cilist io___253 = { 0, 6, 0, fmt_64, 0 };
    static cilist io___254 = { 0, 6, 0, fmt_66, 0 };
    static cilist io___255 = { 0, 6, 0, fmt_154, 0 };
    static cilist io___256 = { 0, 6, 0, fmt_13, 0 };
    static cilist io___257 = { 0, 6, 0, fmt_14, 0 };
    static cilist io___259 = { 0, 6, 0, fmt_82, 0 };
    static cilist io___260 = { 0, 6, 0, fmt_83, 0 };
    static cilist io___261 = { 0, 6, 0, fmt_84, 0 };
    static cilist io___273 = { 0, 6, 0, fmt_320, 0 };
    static cilist io___278 = { 0, 6, 0, fmt_355, 0 };
    static cilist io___279 = { 0, 6, 0, fmt_359, 0 };
    static cilist io___280 = { 0, 6, 0, fmt_358, 0 };


/* **************************************************************** */
/*     MAIN PROGRAM FOR GREEN'S FUNCTION CALCULATIONS            * */
/*     SUBROUTINE WRITTEN BY DR. D.DANOVICH, COMPUTATION         * */
/*     CHEMISTRY CENTRE, DEPARTMENT OF CHEMISTRY, TECHNION-      * */
/*     ISRAEL INSTITUTE OF TECHNOLOGY, HAIFA, 32000, ISRAEL      * */
/*     VERSION   2.09.90                                         * */
/* **************************************************************** */
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
    --p;

    /* Function Body */
    s_wsfe(&io___191);
    do_fio(&c__1, (char *)&davi_2.intso, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&molkst_1.norbs, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___192);
    e_wsfe();
    if (molkst_1.norbs > 200) {
	s_stop("", (ftnlen)0);
    }
    s_wsfe(&io___193);
    i__1 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    }
    e_wsfe();
    s_wsfe(&io___195);
    i__1 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, (char *)&vector_1.eig[i__ - 1], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    numb = molkst_1.nelecs / 2;
    s_wsfe(&io___197);
    do_fio(&c__1, (char *)&numb, (ftnlen)sizeof(integer));
    e_wsfe();
    for (i__ = 1; i__ <= 20; ++i__) {
	eg2[i__ - 1] = 0.;
	eg23[i__ - 1] = 0.;
	ega[i__ - 1] = 0.;
	rir[i__ - 1] = 0.;
	prir[i__ - 1] = 0.;
	ig2[i__ - 1] = 0;
	ig23[i__ - 1] = 0;
/* L2000: */
	iga[i__ - 1] = 0;
    }
    s_rsfe(&io___206);
    do_fio(&c__1, line, (ftnlen)80);
    e_rsfe();
    nuchar_(line, value, &nvalue, (ftnlen)80);
    iggww = (integer) value[0];
    perem_2.iggv = (integer) value[1];
    niz = (integer) value[2];
    iver = (integer) value[3];
    ieps = (integer) value[4];
    iter2 = (integer) value[5];
    iter3 = (integer) value[6];
    ifulit = (integer) value[7];
    iprint = (integer) value[8];
    it23 = (integer) value[9];
    i__1 = -ieps;
    suma_1.eps = pow_di(&c_b328, &i__1);
    perem_2.iggw = iggww - 1;
    s_wsfe(&io___219);
    do_fio(&c__1, (char *)&iggww, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&perem_2.iggv, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&niz, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&iver, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&suma_1.eps, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&iter2, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&iter3, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&ifulit, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&iprint, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&it23, (ftnlen)sizeof(integer));
    e_wsfe();
    perem_2.nyr = numb;
    numh = niz;
    numv = iver;
    if (iter2 != 0) {
	goto L16;
    }
    iii = 0;
    if (numh <= 0) {
	numh = 1;
    }
    i__1 = numv;
    for (perem_2.iyr = numh; perem_2.iyr <= i__1; ++perem_2.iyr) {
	ep = vector_1.eig[perem_2.iyr - 1];
	if (iprint != 0) {
	    s_wsfe(&io___224);
	    do_fio(&c__1, (char *)&ep, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	suma2_(&p[1], ndis, &ep);
	ir = 0;
	w = ep + suma_1.su2r;
L11:
	++ir;
	suma2_(&p[1], ndis, &w);
	w1 = ep + suma_1.su2r;
	if ((d__1 = w1 - w, abs(d__1)) < suma_1.eps) {
	    goto L12;
	}
	w = w1;
	goto L11;
L12:
	++iii;
	eg2[iii - 1] = w1;
	ig2[iii - 1] = ir;
	if (iprint != 0) {
	    s_wsfe(&io___228);
	    do_fio(&c__1, (char *)&w1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* L10: */
    }
L16:
    numh = niz;
    numv = iver;
    if (it23 != 0) {
	goto L1000;
    }
    if (iter3 != 0) {
	goto L17;
    }
    iii = 0;
    if (numh <= 0) {
	numh = 1;
    }
    i__1 = numv;
    for (perem_2.iyr = numh; perem_2.iyr <= i__1; ++perem_2.iyr) {
	ep = vector_1.eig[perem_2.iyr - 1];
	if (iprint != 0) {
	    s_wsfe(&io___229);
	    do_fio(&c__1, (char *)&ep, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	suma2_(&p[1], ndis, &ep);
	asum_(&p[1], ndis);
	csum_(&p[1], ndis, &ep);
	dsum_(&p[1], ndis, &ep);
	ir = 0;
	su3r = asma_1.as1 + csuc_1.cs1 + dsmd_1.ds1 + asma_1.as2 + csuc_1.cs2 
		+ dsmd_1.ds2 + asma_1.as3 + csuc_1.cs3 + dsmd_1.ds3 + 
		asma_1.as4 + csuc_1.cs4 + dsmd_1.ds4 + asma_1.as5 + 
		csuc_1.cs5 + dsmd_1.ds5 + asma_1.as6 + csuc_1.cs6 + 
		dsmd_1.ds6;
	w = ep + suma_1.su2r + su3r;
L19:
	++ir;
	suma2_(&p[1], ndis, &w);
	csum_(&p[1], ndis, &w);
	dsum_(&p[1], ndis, &w);
	su3r = asma_1.as1 + csuc_1.cs1 + dsmd_1.ds1 + asma_1.as2 + csuc_1.cs2 
		+ dsmd_1.ds2 + asma_1.as3 + csuc_1.cs3 + dsmd_1.ds3 + 
		asma_1.as4 + csuc_1.cs4 + dsmd_1.ds4 + asma_1.as5 + 
		csuc_1.cs5 + dsmd_1.ds5 + asma_1.as6 + csuc_1.cs6 + 
		dsmd_1.ds6;
	w1 = ep + suma_1.su2r + su3r;
	if ((d__1 = w1 - w, abs(d__1)) < suma_1.eps) {
	    goto L20;
	}
	w = w1;
	goto L19;
L20:
	++iii;
	eg23[iii - 1] = w1;
	ig23[iii - 1] = ir;
	if (iprint != 0) {
	    s_wsfe(&io___231);
	    do_fio(&c__1, (char *)&w1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* L18: */
    }
L17:
    numh = niz;
    numv = iver;
    if (numh <= 0) {
	numh = 1;
    }
    s_wsfe(&io___232);
    do_fio(&c__1, (char *)&numh, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&numv, (ftnlen)sizeof(integer));
    e_wsfe();
    if (ifulit > 0) {
	goto L23;
    }
    if (ifulit < 0) {
	goto L24;
    }
    iii = 0;
    i__1 = numv;
    for (perem_2.iyr = numh; perem_2.iyr <= i__1; ++perem_2.iyr) {
	ep = vector_1.eig[perem_2.iyr - 1];
	if (iprint != 0) {
	    s_wsfe(&io___233);
	    do_fio(&c__1, (char *)&ep, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	suma2_(&p[1], ndis, &ep);
	asum_(&p[1], ndis);
	csum_(&p[1], ndis, &ep);
	dsum_(&p[1], ndis, &ep);
	ir = 0;
	su3r = asma_1.as1 + csuc_1.cs1 + dsmd_1.ds1 + asma_1.as2 + csuc_1.cs2 
		+ dsmd_1.ds2 + asma_1.as3 + csuc_1.cs3 + dsmd_1.ds3 + 
		asma_1.as4 + csuc_1.cs4 + dsmd_1.ds4 + asma_1.as5 + 
		csuc_1.cs5 + dsmd_1.ds5 + asma_1.as6 + csuc_1.cs6 + 
		dsmd_1.ds6;
	if (suma_1.su2r == 0.) {
	    goto L26;
	}
	faca = -(csuc_1.cs2 + csuc_1.cs3 + csuc_1.cs4 + csuc_1.cs5 + 
		dsmd_1.ds2 + dsmd_1.ds3 + dsmd_1.ds4 + dsmd_1.ds5) / 
		suma_1.su2r;
	goto L27;
L26:
	s_wsfe(&io___235);
	e_wsfe();
	faca = 0.;
L27:
	w = ep + suma_1.su2r + 1 / (faca + 1) * su3r;
L29:
	++ir;
	suma2_(&p[1], ndis, &w);
	csum_(&p[1], ndis, &w);
	dsum_(&p[1], ndis, &w);
	su3r = asma_1.as1 + csuc_1.cs1 + dsmd_1.ds1 + asma_1.as2 + csuc_1.cs2 
		+ dsmd_1.ds2 + asma_1.as3 + csuc_1.cs3 + dsmd_1.ds3 + 
		asma_1.as4 + csuc_1.cs4 + dsmd_1.ds4 + asma_1.as5 + 
		csuc_1.cs5 + dsmd_1.ds5 + asma_1.as6 + csuc_1.cs6 + 
		dsmd_1.ds6;
	if (suma_1.su2r == 0.) {
	    goto L30;
	}
	faca = -(csuc_1.cs2 + csuc_1.cs3 + csuc_1.cs4 + csuc_1.cs5 + 
		dsmd_1.ds2 + dsmd_1.ds3 + dsmd_1.ds4 + dsmd_1.ds5) / 
		suma_1.su2r;
	goto L31;
L30:
	s_wsfe(&io___236);
	do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
	faca = 0.;
L31:
	w1 = ep + suma_1.su2r + 1 / (faca + 1) * su3r;
	if ((d__1 = w1 - w, abs(d__1)) < suma_1.eps) {
	    goto L33;
	}
	w = w1;
	goto L29;
L33:
	++iii;
	ega[iii - 1] = w1;
	iga[iii - 1] = ir;
	if (iprint != 0) {
	    s_wsfe(&io___237);
	    do_fio(&c__1, (char *)&w1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* L25: */
    }
    goto L1000;
L23:
    iii = 0;
    i__1 = numv;
    for (perem_2.iyr = numh; perem_2.iyr <= i__1; ++perem_2.iyr) {
	ep = vector_1.eig[perem_2.iyr - 1];
	if (iprint != 0) {
	    s_wsfe(&io___238);
	    do_fio(&c__1, (char *)&ep, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	suma2_(&p[1], ndis, &ep);
	asum_(&p[1], ndis);
	csum_(&p[1], ndis, &ep);
	dsum_(&p[1], ndis, &ep);
	ir = 0;
	if (suma_1.sum1 == 0.) {
	    goto L34;
	}
	g1 = -(csuc_1.cs4 + csuc_1.cs5 + dsmd_1.ds4 + dsmd_1.ds5) / 
		suma_1.sum1;
	goto L35;
L34:
	s_wsfe(&io___240);
	e_wsfe();
	g1 = 0.;
L35:
	if (suma_1.sum2 == 0.) {
	    goto L37;
	}
	g2 = -(csuc_1.cs2 + csuc_1.cs3 + dsmd_1.ds2 + dsmd_1.ds3) / 
		suma_1.sum2;
	goto L38;
L37:
	s_wsfe(&io___242);
	e_wsfe();
	g2 = 0.;
L38:
	w = ep + suma_1.su2r + 1 / (g1 + 1) * (csuc_1.cs4 + csuc_1.cs5 + 
		csuc_1.cs6 + dsmd_1.ds4 + dsmd_1.ds5 + dsmd_1.ds6) + 1 / (g2 
		+ 1) * (csuc_1.cs1 + csuc_1.cs2 + csuc_1.cs3 + dsmd_1.ds1 + 
		dsmd_1.ds2 + dsmd_1.ds3) + (asma_1.as1 + asma_1.as2 + 
		asma_1.as3 + asma_1.as4 + asma_1.as5 + asma_1.as6);
L40:
	++ir;
	suma2_(&p[1], ndis, &w);
	csum_(&p[1], ndis, &w);
	dsum_(&p[1], ndis, &w);
	if (suma_1.sum1 == 0.) {
	    goto L41;
	}
	g1 = -(csuc_1.cs4 + csuc_1.cs5 + dsmd_1.ds4 + dsmd_1.ds5) / 
		suma_1.sum1;
	goto L42;
L41:
	s_wsfe(&io___243);
	do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
	g1 = 0.;
L42:
	if (suma_1.sum2 == 0.) {
	    goto L44;
	}
	g2 = -(csuc_1.cs2 + csuc_1.cs3 + dsmd_1.ds2 + dsmd_1.ds3) / 
		suma_1.sum2;
	goto L45;
L44:
	s_wsfe(&io___244);
	do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
	g2 = 0.;
L45:
	w1 = ep + suma_1.su2r + 1 / (g1 + 1) * (csuc_1.cs4 + csuc_1.cs5 + 
		csuc_1.cs6 + dsmd_1.ds4 + dsmd_1.ds5 + dsmd_1.ds6) + 1 / (g2 
		+ 1) * (csuc_1.cs1 + csuc_1.cs2 + csuc_1.cs3 + dsmd_1.ds1 + 
		dsmd_1.ds2 + dsmd_1.ds3) + (asma_1.as1 + asma_1.as2 + 
		asma_1.as3 + asma_1.as4 + asma_1.as5 + asma_1.as6);
	if ((d__1 = w1 - w, abs(d__1)) < suma_1.eps) {
	    goto L47;
	}
	w = w1;
	goto L40;
L47:
	++iii;
	ega[iii - 1] = w1;
	iga[iii - 1] = ir;
	if (iprint != 0) {
	    s_wsfe(&io___245);
	    do_fio(&c__1, (char *)&w1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* L127: */
    }
    goto L1000;
L24:
    iii = 0;
    i__1 = numv;
    for (perem_2.iyr = numh; perem_2.iyr <= i__1; ++perem_2.iyr) {
	ep = vector_1.eig[perem_2.iyr - 1];
	if (iprint != 0) {
	    s_wsfe(&io___246);
	    do_fio(&c__1, (char *)&ep, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	suma2_(&p[1], ndis, &ep);
	asum_(&p[1], ndis);
	csum_(&p[1], ndis, &ep);
	dsum_(&p[1], ndis, &ep);
	ir = 0;
	if (suma_1.sum1 == 0.) {
	    goto L49;
	}
	g1 = -(csuc_1.cs4 + csuc_1.cs5 + dsmd_1.ds4 + dsmd_1.ds5) / 
		suma_1.sum1;
	goto L50;
L49:
	s_wsfe(&io___247);
	e_wsfe();
	g1 = 0.;
L50:
	if (suma_1.sum2 == 0.) {
	    goto L52;
	}
	g2 = -(csuc_1.cs2 + csuc_1.cs3 + dsmd_1.ds2 + dsmd_1.ds3) / 
		suma_1.sum2;
	goto L53;
L52:
	s_wsfe(&io___248);
	e_wsfe();
	g2 = 0.;
L53:
	szam = csuc_1.cs1 + dsmd_1.ds1 + csuc_1.cs2 + dsmd_1.ds2 + csuc_1.cs3 
		+ dsmd_1.ds3 + csuc_1.cs4 + dsmd_1.ds4 + csuc_1.cs5 + 
		dsmd_1.ds5 + csuc_1.cs6 + dsmd_1.ds6;
	if (szam != 0.) {
	    goto L55;
	}
	s_wsfe(&io___250);
	e_wsfe();
	a = 0.;
	goto L57;
L55:
	a = (g1 * (csuc_1.cs4 + csuc_1.cs5 + csuc_1.cs6 + dsmd_1.ds4 + 
		dsmd_1.ds5 + dsmd_1.ds6) + g2 * (csuc_1.cs1 + csuc_1.cs2 + 
		csuc_1.cs3 + dsmd_1.ds1 + dsmd_1.ds2 + dsmd_1.ds3)) / szam;
L57:
	su3r = asma_1.as1 + csuc_1.cs1 + dsmd_1.ds1 + asma_1.as2 + csuc_1.cs2 
		+ dsmd_1.ds2 + asma_1.as3 + csuc_1.cs3 + dsmd_1.ds3 + 
		asma_1.as4 + csuc_1.cs4 + dsmd_1.ds4 + asma_1.as5 + 
		csuc_1.cs5 + dsmd_1.ds5 + asma_1.as6 + csuc_1.cs6 + 
		dsmd_1.ds6;
	w = ep + suma_1.su2r + 1 / (a + 1) * su3r;
L58:
	++ir;
	suma2_(&p[1], ndis, &w);
	csum_(&p[1], ndis, &w);
	dsum_(&p[1], ndis, &w);
	if (suma_1.sum1 == 0.) {
	    goto L59;
	}
	g1 = -(csuc_1.cs4 + csuc_1.cs5 + dsmd_1.ds4 + dsmd_1.ds5) / 
		suma_1.sum1;
	goto L60;
L59:
	s_wsfe(&io___252);
	do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
	g1 = 0.;
L60:
	if (suma_1.sum2 == 0.) {
	    goto L62;
	}
	g2 = -(csuc_1.cs2 + csuc_1.cs3 + dsmd_1.ds2 + dsmd_1.ds3) / 
		suma_1.sum2;
	goto L63;
L62:
	s_wsfe(&io___253);
	do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
	g2 = 0.;
L63:
	szam = csuc_1.cs1 + dsmd_1.ds1 + csuc_1.cs2 + dsmd_1.ds2 + csuc_1.cs3 
		+ dsmd_1.ds3 + csuc_1.cs4 + dsmd_1.ds4 + csuc_1.cs5 + 
		dsmd_1.ds5 + csuc_1.cs6 + dsmd_1.ds6;
	if (szam != 0.) {
	    goto L65;
	}
	s_wsfe(&io___254);
	do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	e_wsfe();
	a = 0.;
	goto L67;
L65:
	a = (g1 * (csuc_1.cs4 + csuc_1.cs5 + csuc_1.cs6 + dsmd_1.ds4 + 
		dsmd_1.ds5 + dsmd_1.ds6) + g2 * (csuc_1.cs1 + csuc_1.cs2 + 
		csuc_1.cs3 + dsmd_1.ds1 + dsmd_1.ds2 + dsmd_1.ds3)) / szam;
L67:
	su3r = asma_1.as1 + csuc_1.cs1 + dsmd_1.ds1 + asma_1.as2 + csuc_1.cs2 
		+ dsmd_1.ds2 + asma_1.as3 + csuc_1.cs3 + dsmd_1.ds3 + 
		asma_1.as4 + csuc_1.cs4 + dsmd_1.ds4 + asma_1.as5 + 
		csuc_1.cs5 + dsmd_1.ds5 + asma_1.as6 + csuc_1.cs6 + 
		dsmd_1.ds6;
	w1 = ep + suma_1.su2r + 1 / (a + 1) * su3r;
	if ((d__1 = w1 - w, abs(d__1)) < suma_1.eps) {
	    goto L68;
	}
	w = w1;
	goto L58;
L68:
	++iii;
	ega[iii - 1] = w1;
	iga[iii - 1] = ir;
	if (iprint != 0) {
	    s_wsfe(&io___255);
	    do_fio(&c__1, (char *)&w1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&ir, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* L48: */
    }
L1000:
    s_wsfe(&io___256);
    e_wsfe();
    s_wsfe(&io___257);
    e_wsfe();
    i__1 = iii;
    for (ii = 1; ii <= i__1; ++ii) {
	s_wsfe(&io___259);
	do_fio(&c__1, (char *)&numh, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&eg2[ii - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ig2[ii - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&eg23[ii - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&ig23[ii - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ega[ii - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&iga[ii - 1], (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&vector_1.eig[numh - 1], (ftnlen)sizeof(
		doublereal));
	e_wsfe();
	++numh;
/* L81: */
    }
    s_wsfe(&io___260);
    do_fio(&c__1, (char *)&iggww, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&perem_2.iggv, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&suma_1.eps, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&ifulit, (ftnlen)sizeof(integer));
    e_wsfe();
    s_wsfe(&io___261);
    e_wsfe();
    numh = niz;
    numv = iver;
    num1 = numb - perem_2.iggw;
    num2 = numb + perem_2.iggv;
    kil = 0;
    i__1 = numv;
    for (i__ = numh; i__ <= i__1; ++i__) {
	zsuma = 0.;
	namb = numb + 1;
	i__2 = numb;
	for (j = num1; j <= i__2; ++j) {
	    i__3 = num2;
	    for (l = namb; l <= i__3; ++l) {
		jj = j;
		ll = l;
		ii = i__;
		if (jj >= ll) {
		    goto L302;
		}
		lt = jj;
		jj = ll;
		ll = lt;
L302:
		if (jj > ii) {
		    goto L303;
		}
		if (jj == ii) {
		    goto L304;
		}
L306:
		nymb = dod_1.itl[ii - 1] + dod_1.it[ii - 1] * ii + dod_1.it[
			ii - 1] + dod_1.it[jj - 1] + ll;
		goto L305;
L304:
		if (ll >= ii) {
		    goto L303;
		}
		goto L306;
L303:
		nymb = dod_1.itl[jj - 1] + dod_1.it[jj - 1] * ll + dod_1.it[
			ll - 1] + dod_1.it[ii - 1] + ii;
L305:
		jj = j;
		ll = l;
		ii = i__;
		if (jj >= ii && ii >= ll) {
		    goto L307;
		}
		if (jj >= ii && ll >= ii && jj >= ll) {
		    goto L308;
		}
		if (jj >= ii && ll >= ii && ll >= jj) {
		    goto L309;
		}
		if (ii >= jj && ii >= ll && jj >= ll) {
		    goto L310;
		}
		if (ii >= jj && ii >= ll && ll >= jj) {
		    goto L311;
		}
		if (ii >= jj && ll >= ii) {
		    goto L312;
		}
		s_wsfe(&io___273);
		do_fio(&c__1, (char *)&jj, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&ii, (ftnlen)sizeof(integer));
		do_fio(&c__1, (char *)&ll, (ftnlen)sizeof(integer));
		e_wsfe();
		s_stop("", (ftnlen)0);
L307:
		nymb1 = dod_1.itl[jj - 1] + dod_1.it[jj - 1] * ii + dod_1.it[
			ii - 1] + dod_1.it[ii - 1] + ll;
		goto L313;
L308:
		nymb1 = dod_1.itl[jj - 1] + dod_1.it[jj - 1] * ii + dod_1.it[
			ii - 1] + dod_1.it[ll - 1] + ii;
		goto L313;
L309:
		nymb1 = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * ii + dod_1.it[
			ii - 1] + dod_1.it[jj - 1] + ii;
		goto L313;
L310:
		nymb1 = dod_1.itl[ii - 1] + dod_1.it[ii - 1] * jj + dod_1.it[
			jj - 1] + dod_1.it[ii - 1] + ll;
		goto L313;
L311:
		nymb1 = dod_1.itl[ii - 1] + dod_1.it[ii - 1] * ll + dod_1.it[
			ll - 1] + dod_1.it[ii - 1] + jj;
		goto L313;
L312:
		nymb1 = dod_1.itl[ll - 1] + dod_1.it[ll - 1] * ii + dod_1.it[
			ii - 1] + dod_1.it[ii - 1] + jj;
L313:
/* Computing 2nd power */
		d__1 = p[nymb] - p[nymb1] * .5;
		zverx = d__1 * d__1;
		zniz = vector_1.eig[l - 1] - vector_1.eig[j - 1];
		ps = zverx / zniz;
		zsuma += ps;
/* L301: */
	    }
	}
	++kil;
	rir[kil - 1] = zsuma * 2.;
/* L350: */
    }
    s_wsfe(&io___278);
    e_wsfe();
    i__1 = iii;
    for (i__ = 1; i__ <= i__1; ++i__) {
	prir[i__ - 1] = -vector_1.eig[numh - 1] - rir[i__ - 1];
	++numh;
/* L356: */
    }
    numh = niz;
    s_wsfe(&io___279);
    e_wsfe();
    i__1 = iii;
    for (i__ = 1; i__ <= i__1; ++i__) {
	s_wsfe(&io___280);
	do_fio(&c__1, (char *)&numh, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&rir[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vector_1.eig[numh - 1], (ftnlen)sizeof(
		doublereal));
	do_fio(&c__1, (char *)&prir[i__ - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
	++numh;
/* L357: */
    }
    return 0;
} /* fcnpp_ */

