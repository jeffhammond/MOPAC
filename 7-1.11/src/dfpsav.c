/* dfpsav.f -- translated by f2c (version 20020621).
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
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal dumy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    doublereal alparm[1080]	/* was [3][360] */, x0, x1, x2;
    integer iloop;
} alparm_;

#define alparm_1 alparm_

struct {
    doublereal currt;
} pparam_;

#define pparam_1 pparam_

struct {
    doublereal currt1, currt2;
} gparam_;

#define gparam_1 gparam_

struct {
    doublereal profil[200];
} profic_;

#define profic_1 profic_

struct {
    doublereal surf[529];
} surf_;

#define surf_1 surf_

struct {
    integer kloop;
} kloop_;

#define kloop_1 kloop_

struct {
    integer ijlp, ilp, jlp, jlp1, ione;
} ijlp_;

#define ijlp_1 ijlp_

struct {
    doublereal step, geoa[360]	/* was [3][120] */, geovec[360]	/* was [3][
	    120] */, calcst;
} reactn_;

#define reactn_1 reactn_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    integer latom1, lpara1, latom2, lpara2;
} mesh_;

#define mesh_1 mesh_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal hesinv[130681];
    integer idumy2[4];
} fmatrx_;

#define fmatrx_1 fmatrx_

struct {
    doublereal errfn[360], aicorr[360];
} errfn_;

#define errfn_1 errfn_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Table of constant values */

static integer c__1 = 1;
static doublereal c_b17 = 1.;
static integer c_n6 = -6;
static integer c__6 = 6;
static integer c__9 = 9;

/* Subroutine */ int dfpsav_(doublereal *totime, doublereal *xparam, 
	doublereal *gd, doublereal *xlast, doublereal *funct1, integer *mdfp, 
	doublereal *xdfp)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1, i__2;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *), f_rew(alist *), s_wsfe(cilist *), e_wsfe(void), 
	    i_indx(char *, char *, ftnlen, ftnlen), do_fio(integer *, char *, 
	    ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_wsue(cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void),
	     f_clos(cllist *), s_rsue(cilist *), e_rsue(void);

    /* Local variables */
    static integer i__, j, ir;
    static doublereal coord[360]	/* was [3][120] */;
    static logical first;
    extern /* Subroutine */ int geout_(integer *);
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer linear;
    static logical intxyz;
    extern /* Subroutine */ int xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___4 = { 0, 6, 0, "(//10X,'- - - - - - - TIME UP - - - -"
	    " - - -',//)", 0 };
    static cilist io___5 = { 0, 6, 0, "(//10X,' NO RESTART EXISTS FOR SADDLE"
	    "',//       10X,' HERE IS A DATA-FILE FILES THAT MIGHT BE SUITABL"
	    "E',/       10X,' FOR RESTARTING THE CALCULATION',///)", 0 };
    static cilist io___6 = { 0, 6, 0, "(A)", 0 };
    static cilist io___11 = { 0, 6, 0, "(///10X,'CALCULATION TERMINATED HERE"
	    "')", 0 };
    static cilist io___12 = { 0, 6, 0, "(//10X,' - THE CALCULATION IS BEING "
	    "DUMPED TO DISK',  /10X,'   RESTART IT USING THE MAGIC WORD \"RES"
	    "TART\"')", 0 };
    static cilist io___13 = { 0, 6, 0, "(//10X,'CURRENT VALUE OF HEAT OF FOR"
	    "MATION ='      ,F12.6)", 0 };
    static cilist io___14 = { 0, 0, 0, 0, 0 };
    static cilist io___15 = { 0, 0, 0, 0, 0 };
    static cilist io___16 = { 0, 0, 0, 0, 0 };
    static cilist io___18 = { 0, 0, 0, 0, 0 };
    static cilist io___19 = { 0, 10, 0, 0, 0 };
    static cilist io___20 = { 0, 10, 0, 0, 0 };
    static cilist io___21 = { 0, 0, 0, 0, 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, 0, 0 };
    static cilist io___24 = { 0, 0, 0, 0, 0 };
    static cilist io___25 = { 0, 0, 0, 0, 0 };
    static cilist io___26 = { 0, 0, 0, 0, 0 };
    static cilist io___27 = { 0, 0, 0, 0, 0 };
    static cilist io___28 = { 0, 0, 0, 0, 0 };
    static cilist io___29 = { 0, 0, 0, 0, 0 };
    static cilist io___30 = { 0, 6, 0, "(//10X,' RESTORING DATA FROM DISK'/)",
	     0 };
    static cilist io___31 = { 1, 0, 1, 0, 0 };
    static cilist io___32 = { 0, 6, 0, "(10X,'FUNCTION =',F13.6//)", 0 };
    static cilist io___33 = { 0, 0, 0, 0, 0 };
    static cilist io___34 = { 0, 0, 0, 0, 0 };
    static cilist io___35 = { 0, 0, 0, 0, 0 };
    static cilist io___36 = { 0, 10, 0, 0, 0 };
    static cilist io___37 = { 0, 10, 0, 0, 0 };
    static cilist io___38 = { 0, 0, 0, 0, 0 };
    static cilist io___39 = { 0, 0, 0, 0, 0 };
    static cilist io___40 = { 0, 0, 0, 0, 0 };
    static cilist io___41 = { 0, 0, 0, 0, 0 };
    static cilist io___42 = { 0, 0, 0, 0, 0 };
    static cilist io___43 = { 0, 0, 0, 0, 0 };
    static cilist io___44 = { 0, 0, 0, 0, 0 };
    static cilist io___45 = { 0, 0, 0, 0, 0 };
    static cilist io___46 = { 0, 0, 0, 0, 0 };
    static cilist io___47 = { 0, 6, 0, "(//10X,'NO RESTART FILE EXISTS!')", 0 
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
/* ********************************************************************* */

/* DFPSAV STORES AND RESTORES DATA USED IN THE D-F-P GEOMETRY */
/*        OPTIMISATION. */

/*  ON INPUT TOTIME = TOTAL CPU TIME ELAPSED DURING THE CALCULATION. */
/*           XPARAM = CURRENT VALUE OF PARAMETERS. */
/*           GD     = OLD GRADIENT. */
/*           XLAST  = OLD VALUE OF PARAMETERS. */
/*           FUNCT1 = CURRENT VALUE OF HEAT OF FORMATION. */
/*           MDFP   = INTEGER CONSTANTS USED IN D-F-P. */
/*           XDFP   = REAL CONSTANTS USED IN D-F-P. */
/*           MDFP(9)= 1 FOR DUMP, 0 FOR RESTORE. */
/* ********************************************************************* */
/* ***** Modified by Jiro Toyoda at 1994-05-25 ***** */
/*     COMMON /PROFIL/ PROFIL */
/* ***************************** at 1994-05-25 ***** */
    /* Parameter adjustments */
    --xdfp;
    --mdfp;
    --xlast;
    --gd;
    --xparam;

    /* Function Body */
    first = icalcn == numcal_1.numcal;
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
    if (mdfp[9] != 0) {
	if (mdfp[9] == 1) {
	    s_wsfe(&io___4);
	    e_wsfe();
	    if (i_indx(keywrd_1.keywrd, "SADDLE", (ftnlen)241, (ftnlen)6) != 
		    0) {
		s_wsfe(&io___5);
		e_wsfe();
		s_wsfe(&io___6);
		do_fio(&c__1, keywrd_1.keywrd, (ftnlen)241);
		do_fio(&c__1, titles_1.koment, (ftnlen)81);
		do_fio(&c__1, titles_1.title, (ftnlen)81);
		e_wsfe();
		intxyz = geokst_1.na[0] == 0;
		for (alparm_1.iloop = 1; alparm_1.iloop <= 2; 
			++alparm_1.iloop) {
		    if (intxyz) {
			geom_1.geo[1] = 0.;
			geom_1.geo[2] = 0.;
			geom_1.geo[0] = 0.;
			geom_1.geo[4] = 0.;
			geom_1.geo[5] = 0.;
			geom_1.geo[8] = 0.;
			i__1 = geokst_1.natoms;
			for (i__ = 1; i__ <= i__1; ++i__) {
			    for (j = 1; j <= 3; ++j) {
/* L10: */
				coord[j + i__ * 3 - 4] = geom_1.geo[j + i__ * 
					3 - 4];
			    }
			}
		    } else {
			xyzint_(geom_1.geo, &molkst_1.numat, geokst_1.na, 
				geokst_1.nb, geokst_1.nc, &c_b17, coord);
		    }
		    geout_(&c_n6);
		    i__1 = geokst_1.natoms;
		    for (i__ = 1; i__ <= i__1; ++i__) {
			for (j = 1; j <= 3; ++j) {
/* L20: */
			    geom_1.geo[j + i__ * 3 - 4] = reactn_1.geoa[j + 
				    i__ * 3 - 4];
			}
		    }
		    geokst_1.na[0] = 99;
/* L30: */
		}
		s_wsfe(&io___11);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
	    s_wsfe(&io___12);
	    e_wsfe();
	    s_wsfe(&io___13);
	    do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	if (mdfp[9] == 1) {
	    if (geokst_1.na[0] == 99) {

/*  CONVERT FROM CARTESIAN COORDINATES TO INTERNAL */

		i__1 = geokst_1.natoms;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    for (j = 1; j <= 3; ++j) {
/* L40: */
			coord[j + i__ * 3 - 4] = geom_1.geo[j + i__ * 3 - 4];
		    }
		}
		xyzint_(coord, &molkst_1.numat, geokst_1.na, geokst_1.nb, 
			geokst_1.nc, &c_b17, geom_1.geo);
	    }
	    geom_1.geo[1] = 0.;
	    geom_1.geo[2] = 0.;
	    geom_1.geo[0] = 0.;
	    geom_1.geo[4] = 0.;
	    geom_1.geo[5] = 0.;
	    geom_1.geo[8] = 0.;
	    geokst_1.na[0] = 0;
	    geout_(&c__6);
	}
	io___14.ciunit = ir;
	s_wsue(&io___14);
	do_uio(&c__9, (char *)&mdfp[1], (ftnlen)sizeof(integer));
	do_uio(&c__9, (char *)&xdfp[1], (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&(*totime), (ftnlen)sizeof(doublereal));
	do_uio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	e_wsue();
	io___15.ciunit = ir;
	s_wsue(&io___15);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&gd[i__], (ftnlen)sizeof(doublereal));
	}
	e_wsue();
	io___16.ciunit = ir;
	s_wsue(&io___16);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xlast[i__], (ftnlen)sizeof(doublereal));
	}
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	linear = geovar_1.nvar * (geovar_1.nvar + 1) / 2;
	io___18.ciunit = ir;
	s_wsue(&io___18);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&fmatrx_1.hesinv[i__ - 1], (ftnlen)sizeof(
		    doublereal));
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
	if (path_1.latom != 0) {
	    if (i_indx(keywrd_1.keywrd, "STEP", (ftnlen)241, (ftnlen)4) != 0) 
		    {
		io___21.ciunit = ir;
		s_wsue(&io___21);
		do_uio(&c__1, (char *)&kloop_1.kloop, (ftnlen)sizeof(integer))
			;
		e_wsue();
		io___22.ciunit = ir;
		s_wsue(&io___22);
		do_uio(&c__1, (char *)&pparam_1.currt, (ftnlen)sizeof(
			doublereal));
		e_wsue();
		io___23.ciunit = ir;
		s_wsue(&io___23);
		i__1 = kloop_1.kloop;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    do_uio(&c__1, (char *)&profic_1.profil[i__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsue();
	    } else {
		io___24.ciunit = ir;
		s_wsue(&io___24);
		i__1 = geovar_1.nvar;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    for (j = 1; j <= 3; ++j) {
			do_uio(&c__1, (char *)&alparm_1.alparm[j + i__ * 3 - 
				4], (ftnlen)sizeof(doublereal));
		    }
		}
		e_wsue();
		io___25.ciunit = ir;
		s_wsue(&io___25);
		do_uio(&c__1, (char *)&alparm_1.iloop, (ftnlen)sizeof(integer)
			);
		do_uio(&c__1, (char *)&alparm_1.x0, (ftnlen)sizeof(doublereal)
			);
		do_uio(&c__1, (char *)&alparm_1.x1, (ftnlen)sizeof(doublereal)
			);
		do_uio(&c__1, (char *)&alparm_1.x2, (ftnlen)sizeof(doublereal)
			);
		e_wsue();
	    }
	}
	if (i_indx(keywrd_1.keywrd, "STEP1", (ftnlen)241, (ftnlen)5) != 0) {
	    io___26.ciunit = ir;
	    s_wsue(&io___26);
	    do_uio(&c__1, (char *)&ijlp_1.ijlp, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.ilp, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.jlp, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.jlp1, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.ione, (ftnlen)sizeof(integer));
	    e_wsue();
	    io___27.ciunit = ir;
	    s_wsue(&io___27);
	    do_uio(&c__1, (char *)&gparam_1.currt1, (ftnlen)sizeof(doublereal)
		    );
	    do_uio(&c__1, (char *)&gparam_1.currt2, (ftnlen)sizeof(doublereal)
		    );
	    e_wsue();
	    io___28.ciunit = ir;
	    s_wsue(&io___28);
	    i__1 = ijlp_1.ijlp;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&surf_1.surf[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsue();
	}
	io___29.ciunit = ir;
	s_wsue(&io___29);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&errfn_1.errfn[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	cl__1.cerr = 0;
	cl__1.cunit = 9;
	cl__1.csta = 0;
	f_clos(&cl__1);
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
    } else {
	if (first) {
	    s_wsfe(&io___30);
	    e_wsfe();
	}
	io___31.ciunit = ir;
	i__1 = s_rsue(&io___31);
	if (i__1 != 0) {
	    goto L60;
	}
	i__1 = do_uio(&c__9, (char *)&mdfp[1], (ftnlen)sizeof(integer));
	if (i__1 != 0) {
	    goto L60;
	}
	i__1 = do_uio(&c__9, (char *)&xdfp[1], (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L60;
	}
	i__1 = do_uio(&c__1, (char *)&(*totime), (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L60;
	}
	i__1 = do_uio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	if (i__1 != 0) {
	    goto L60;
	}
	i__1 = e_rsue();
	if (i__1 != 0) {
	    goto L60;
	}
	if (first) {
	    s_wsfe(&io___32);
	    do_fio(&c__1, (char *)&(*funct1), (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	io___33.ciunit = ir;
	s_rsue(&io___33);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xparam[i__], (ftnlen)sizeof(doublereal));
	}
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&gd[i__], (ftnlen)sizeof(doublereal));
	}
	e_rsue();
	io___34.ciunit = ir;
	s_rsue(&io___34);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&xlast[i__], (ftnlen)sizeof(doublereal));
	}
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
	linear = geovar_1.nvar * (geovar_1.nvar + 1) / 2;
	io___35.ciunit = ir;
	s_rsue(&io___35);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&fmatrx_1.hesinv[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
	linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	s_rsue(&io___36);
	i__1 = linear;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
	if (molkst_1.nalpha != 0) {
	    s_rsue(&io___37);
	    i__1 = linear;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsue();
	}
	if (path_1.latom != 0) {
	    if (i_indx(keywrd_1.keywrd, "STEP", (ftnlen)241, (ftnlen)4) != 0) 
		    {
		io___38.ciunit = ir;
		s_rsue(&io___38);
		do_uio(&c__1, (char *)&kloop_1.kloop, (ftnlen)sizeof(integer))
			;
		e_rsue();
		io___39.ciunit = ir;
		s_rsue(&io___39);
		do_uio(&c__1, (char *)&pparam_1.currt, (ftnlen)sizeof(
			doublereal));
		e_rsue();
		io___40.ciunit = ir;
		s_rsue(&io___40);
		i__1 = kloop_1.kloop;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    do_uio(&c__1, (char *)&profic_1.profil[i__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_rsue();
	    } else {
		io___41.ciunit = ir;
		s_rsue(&io___41);
		i__1 = geovar_1.nvar;
		for (i__ = 1; i__ <= i__1; ++i__) {
		    for (j = 1; j <= 3; ++j) {
			do_uio(&c__1, (char *)&alparm_1.alparm[j + i__ * 3 - 
				4], (ftnlen)sizeof(doublereal));
		    }
		}
		e_rsue();
		io___42.ciunit = ir;
		s_rsue(&io___42);
		do_uio(&c__1, (char *)&alparm_1.iloop, (ftnlen)sizeof(integer)
			);
		do_uio(&c__1, (char *)&alparm_1.x0, (ftnlen)sizeof(doublereal)
			);
		do_uio(&c__1, (char *)&alparm_1.x1, (ftnlen)sizeof(doublereal)
			);
		do_uio(&c__1, (char *)&alparm_1.x2, (ftnlen)sizeof(doublereal)
			);
		e_rsue();
	    }
	}
	if (i_indx(keywrd_1.keywrd, "STEP1", (ftnlen)241, (ftnlen)5) != 0) {
	    io___43.ciunit = ir;
	    s_rsue(&io___43);
	    do_uio(&c__1, (char *)&ijlp_1.ijlp, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.ilp, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.jlp, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.jlp1, (ftnlen)sizeof(integer));
	    do_uio(&c__1, (char *)&ijlp_1.ione, (ftnlen)sizeof(integer));
	    e_rsue();
	    io___44.ciunit = ir;
	    s_rsue(&io___44);
	    do_uio(&c__1, (char *)&gparam_1.currt1, (ftnlen)sizeof(doublereal)
		    );
	    do_uio(&c__1, (char *)&gparam_1.currt2, (ftnlen)sizeof(doublereal)
		    );
	    e_rsue();
	    io___45.ciunit = ir;
	    s_rsue(&io___45);
	    i__1 = ijlp_1.ijlp;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		do_uio(&c__1, (char *)&surf_1.surf[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_rsue();
	}
	io___46.ciunit = ir;
	s_rsue(&io___46);
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_uio(&c__1, (char *)&errfn_1.errfn[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_rsue();
/* L50: */
	first = FALSE_;
	return 0;
L60:
	s_wsfe(&io___47);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    return 0;
} /* dfpsav_ */

