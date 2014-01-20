/* readmo.f -- translated by f2c (version 20020621).
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
    char koment[81], title[81];
} titles_;

#define titles_1 titles_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

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
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    logical isok;
} okmany_;

#define okmany_1 okmany_

struct {
    doublereal trans, rtr, sig;
    char name__[4], namo[1920];
    integer indx[480];
    char ista[8];
} symres_;

#define symres_1 symres_

struct {
    doublereal ams[107];
} istope_;

#define istope_1 istope_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

/* Table of constant values */

static integer c__1 = 1;
static integer c__5 = 5;
static doublereal c_b64 = 7.01;
static integer c__6 = 6;
static integer c__60 = 60;
static integer c__11 = 11;
static logical c_false = FALSE_;

/* Subroutine */ int readmo_(void)
{
    /* Initialized data */

    static char space[1] = " ";
    static char space2[2] = "  ";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;
    char ch__1[80];
    olist o__1;
    alist al__1;

    /* Builtin functions */
    double asin(doublereal);
    integer i_indx(char *, char *, ftnlen, ftnlen), f_rew(alist *), s_rsfe(
	    cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void), 
	    s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_open(olist *);

    /* Local variables */
    static doublereal c__[1];
    static integer i__, j, k, l;
    static char ch[1];
    static integer ij;
    static char ch2[2];
    static logical int__;
    static doublereal dum1, dum2;
    static integer iend;
    static char line[80];
#define keys ((char *)&keywrd_1)
    static doublereal step;
    static integer lopt[360]	/* was [3][120] */, npts;
    static doublereal sumx, sumy, sumz;
    extern doublereal reada_(char *, integer *, ftnlen);
    static integer iflag;
    extern /* Subroutine */ int fdate_(char *, ftnlen);
    static logical aigeo;
    static char idate[24];
    static doublereal coord[360]	/* was [3][120] */, value[40];
    extern /* Subroutine */ int geout_(integer *);
    static doublereal degree;
    extern /* Subroutine */ int getgeg_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, doublereal *, integer *, logical 
	    *);
    static char banner[80];
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static integer ireact;
    extern /* Subroutine */ int getgeo_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, logical *), nuchar_(char *, doublereal *, integer *, ftnlen);
    static integer nreact;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *), getsym_(
	    void);
    static doublereal convtr, convrt;
    extern /* Subroutine */ int gettxt_(void), makpol_(doublereal *), wrtkey_(
	    char *, ftnlen), xyzint_(doublereal *, integer *, integer *, 
	    integer *, integer *, doublereal *, doublereal *), symtry_(void), 
	    symtrz_(doublereal *, doublereal *, integer *, integer *, logical 
	    *, logical *), wrttxt_(integer *);

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 5, 1, "(A)", 0 };
    static cilist io___10 = { 0, 6, 0, "(1X,A)", 0 };
    static cilist io___11 = { 0, 6, 0, "('1')", 0 };
    static cilist io___16 = { 0, 6, 0, "(//,A)", 0 };
    static cilist io___17 = { 0, 6, 0, "(/,A)", 0 };
    static cilist io___20 = { 0, 6, 0, "(A)", 0 };
    static cilist io___21 = { 0, 6, 0, "(A)", 0 };
    static cilist io___23 = { 0, 6, 0, "(1X,15('*****'),'****')", 0 };
    static cilist io___25 = { 0, 6, 0, "(A)", 0 };
    static cilist io___26 = { 0, 6, 0, "(1X,79('*'))", 0 };
    static cilist io___28 = { 0, 6, 0, "(/29X,A,' CALCULATION RESULTS',28X,/"
	    "//1X,15('*****') ,'****' )", 0 };
    static cilist io___29 = { 0, 6, 0, "(' *',10X,'MOPAC:  VERSION ',F5.2,  "
	    "                 15X,'CALC''D. ',A)", 0 };
    static cilist io___30 = { 0, 6, 0, "(' ATOMIC NUMBER OF ',I3,' ?')", 0 };
    static cilist io___31 = { 0, 6, 0, "(A)", 0 };
    static cilist io___32 = { 0, 6, 0, "(A)", 0 };
    static cilist io___33 = { 0, 6, 0, "(' ATOM NUMBER ',I3,' IS ILL-DEFINED"
	    "')", 0 };
    static cilist io___34 = { 0, 6, 0, "(/,'  GEOMETRY READ IN',/)", 0 };
    static cilist io___35 = { 0, 6, 0, "(1X,14('*****'),'*',I3.3,'BY',I3.3)", 
	    0 };
    static cilist io___38 = { 0, 6, 0, "(' ONLY ONE REACTION COORDINATE PERM"
	    "ITTED')", 0 };
    static cilist io___40 = { 0, 6, 0, "(A)", 0 };
    static cilist io___41 = { 0, 6, 0, "(A)", 0 };
    static cilist io___44 = { 0, 6, 0, "(///,'    ONLY TWO HUNDRED POINTS AL"
	    "LOWED IN REACT','ION COORDINATE')", 0 };
    static cilist io___45 = { 0, 6, 0, "(///,'    STEP FOR BOND LENGTH SHOUL"
	    "D BE SET POSITIVE ','TO PREVENT TWO ATOMS COLLAPSE')", 0 };
    static cilist io___46 = { 0, 5, 1, "(A)", 0 };
    static cilist io___50 = { 0, 6, 0, "(///,'    ONLY TWO HUNDRED POINTS AL"
	    "LOWED IN REACTION',' COORDINATE')", 0 };
    static cilist io___53 = { 0, 6, 0, "(///,' TWO ADJACENT POINTS ARE IDENT"
	    "ICAL:  ',     F7.3,2X,F7.3,/,' THIS IS NOT ALLOWED IN A PATH CAL"
	    "CULATION')", 0 };
    static cilist io___54 = { 0, 6, 0, "(//10X,' NO POINTS SUPPLIED FOR REAC"
	    "TION PATH')", 0 };
    static cilist io___55 = { 0, 6, 0, "(//10X,' GEOMETRY AS READ IN IS AS F"
	    "OLLOWS')", 0 };
    static cilist io___56 = { 0, 6, 0, "(//10X,' POINTS ON REACTION COORDINA"
	    "TE')", 0 };
    static cilist io___57 = { 0, 6, 0, "(10X,8F8.2)", 0 };
    static cilist io___59 = { 0, 6, 0, "(A)", 0 };
    static cilist io___60 = { 0, 6, 0, "(2X,A,3(F19.13,I3))", 0 };
    static cilist io___61 = { 0, 6, 0, "(//10X,'CARTESIAN COORDINATES ',/)", 
	    0 };
    static cilist io___62 = { 0, 6, 0, "(4X,'NO.',7X,'ATOM',9X,'X',         "
	    "           9X,'Y',9X,'Z',/)", 0 };
    static cilist io___64 = { 0, 6, 0, "(I6,8X,A2,4X,3F10.4)", 0 };
    static cilist io___66 = { 0, 6, 0, "(//'     MOLECULAR POINT GROUP   :  "
	    " ',A4)", 0 };
    static cilist io___67 = { 0, 6, 0, "(//10X,' INTERNAL COORDINATES READ I"
	    "N, AND SYMMETRY'   ,/10X,' SPECIFIED, BUT CALCULATION TO BE RUN "
	    "IN CARTESIAN '     ,'COORDINATES')", 0 };
    static cilist io___68 = { 0, 6, 0, "(//10X,' INTERNAL COORDINATES READ I"
	    "N, AND',           ' CALCULATION ',/10X,'TO BE RUN IN CARTESIAN "
	    "COORDINATES, ',  /10X,'BUT NOT ALL COORDINATES MARKED FOR OPTIMI"
	    "SATION')", 0 };
    static cilist io___69 = { 0, 6, 0, "(//10X,' THIS INVOLVES A LOGICALLLY "
	    "ABSURD CHOICE',/10X,' SO THE CALCULATION IS TERMINATED AT THIS P"
	    "OINT')", 0 };
    static cilist io___73 = { 0, 6, 0, "(//10X,' CARTESIAN COORDINATES READ "
	    "IN, AND SYMMETRY'  ,/10X,' SPECIFIED, BUT CALCULATION TO BE RUN "
	    "IN INTERNAL '      ,'COORDINATES')", 0 };
    static cilist io___74 = { 0, 6, 0, "(//10X,' CARTESIAN COORDINATES READ "
	    "IN, AND',          ' CALCULATION ',/10X,'TO BE RUN IN INTERNAL C"
	    "OORDINATES, ',   /10X,'BUT NOT ALL COORDINATES MARKED FOR OPTIMI"
	    "SATION')", 0 };
    static cilist io___75 = { 0, 6, 0, "(//10X,'MOPAC, BY DEFAULT, USES INTE"
	    "RNAL COORDINATES',/10X,'TO SPECIFY CARTESIAN COORDINATES USE KEY"
	    "-WORD :XYZ:')", 0 };
    static cilist io___76 = { 0, 6, 0, "(10X,'YOUR CURRENT CHOICE OF KEY-WOR"
	    "DS INVOLVES' ,' A LOGICALLLY',/10X,'ABSURD CHOICE SO THE CALCULA"
	    "TION IS',  ' TERMINATED AT THIS POINT')", 0 };



/* MODULE TO READ IN GEOMETRY FILE, OUTPUT IT TO THE USER, */
/* AND CHECK THE DATA TO SEE IF IT IS REASONABLE. */
/* EXIT IF NECESSARY. */



/*  ON EXIT NATOMS    = NUMBER OF ATOMS PLUS DUMMY ATOMS (IF ANY). */
/*          KEYWRD    = KEYWORDS TO CONTROL CALCULATION */
/*          KOMENT    = COMMENT CARD */
/*          TITLE     = TITLE CARD */
/*          LABELS    = ARRAY OF ATOMIC LABELS INCLUDING DUMMY ATOMS. */
/*          GEO       = ARRAY OF INTERNAL COORDINATES. */
/*          LOPT      = FLAGS FOR OPTIMIZATION OF MOLECULE */
/*          NA        = ARRAY OF LABELS OF ATOMS, BOND LENGTHS. */
/*          NB        = ARRAY OF LABELS OF ATOMS, BOND ANGLES. */
/*          NC        = ARRAY OF LABELS OF ATOMS, DIHEDRAL ANGLES. */
/*          LATOM     = LABEL OF ATOM OF REACTION COORDINATE. */
/*          LPARAM    = RC: 1 FOR LENGTH, 2 FOR ANGLE, AND 3 FOR DIHEDRAL */
/*          REACT(200)= REACTION COORDINATE PARAMETERS */
/*          LOC(1,I)  = LABEL OF ATOM TO BE OPTIMIZED. */
/*          LOC(2,I)  = 1 FOR LENGTH, 2 FOR ANGLE, AND 3 FOR DIHEDRAL. */
/*          NVAR      = NUMBER OF PARAMETERS TO BE OPTIMIZED. */
/*          XPARAM    = STARTING VALUE OF PARAMETERS TO BE OPTIMIZED. */

/* *********************************************************************** */
/* *** INPUT THE TRIAL GEOMETRY  \IE.  KGEOM=0\ */
/*   LABEL(I) = THE ATOMIC NUMBER OF ATOM\I\. */
/*            = 99, THEN THE I-TH ATOM IS A DUMMY ATOM USED ONLY TO */
/*              SIMPLIFY THE DEFINITION OF THE MOLECULAR GEOMETRY. */
/*   GEO(1,I) = THE INTERNUCLEAR SEPARATION \IN ANGSTROMS\ BETWEEN ATOMS */
/*              NA(I) AND (I). */
/*   GEO(2,I) = THE ANGLE NB(I):NA(I):(I) INPUT IN DEGREES; STORED IN */
/*              RADIANS. */
/*   GEO(3,I) = THE ANGLE BETWEEN THE VECTORS NC(I):NB(I) AND NA(I):(I) */
/*              INPUT IN DEGREES - STORED IN RADIANS. */
/*  LOPT(J,I) = -1 IF GEO(J,I) IS THE REACTION COORDINATE. */
/*            = +1 IF GEO(J,I) IS A PARAMETER TO BE OPTIMIZED */
/*            =  0 OTHERWISE. */
/* *** NOTE:    MUCH OF THIS DATA IS NOT INCLUDED FOR THE FIRST 3 ATOMS. */
/*     ATOM1  INPUT LABELS(1) ONLY. */
/*     ATOM2  INPUT LABELS(2) AND GEO(1,2) SEPARATION BETWEEN ATOMS 1+2 */
/*     ATOM3  INPUT LABELS(3), GEO(1,3)    SEPARATION BETWEEN ATOMS 2+3 */
/*              AND GEO(2,3)              ANGLE ATOM1 : ATOM2 : ATOM3 */

/* *********************************************************************** */

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
    convtr = 2. * asin(1.) / 180.;
    aigeo = FALSE_;
L10:

    gettxt_();
    if (i_indx(keywrd_1.keywrd, "ECHO", (ftnlen)241, (ftnlen)4) != 0) {
	al__1.aerr = 0;
	al__1.aunit = 5;
	f_rew(&al__1);
	okmany_1.isok = FALSE_;
	for (i__ = 1; i__ <= 1000; ++i__) {
	    i__1 = s_rsfe(&io___7);
	    if (i__1 != 0) {
		goto L60;
	    }
	    i__1 = do_fio(&c__1, keywrd_1.keywrd, (ftnlen)241);
	    if (i__1 != 0) {
		goto L60;
	    }
	    i__1 = e_rsfe();
	    if (i__1 != 0) {
		goto L60;
	    }
	    for (j = 80; j >= 2; --j) {
/* L20: */
		if (*(unsigned char *)&keywrd_1.keywrd[j - 1] != ' ') {
		    goto L30;
		}
	    }
	    j = 1;
L30:
	    i__1 = j;
	    for (k = 1; k <= i__1; ++k) {
/* L40: */
		if (*(unsigned char *)&keywrd_1.keywrd[k - 1] < 32) {
		    *(unsigned char *)&keywrd_1.keywrd[k - 1] = '*';
		}
	    }
	    s_wsfe(&io___10);
	    do_fio(&c__1, keywrd_1.keywrd, j);
	    e_wsfe();
/* L50: */
	}
L60:
	al__1.aerr = 0;
	al__1.aunit = 5;
	f_rew(&al__1);
	gettxt_();
    }
    if (i_indx(keywrd_1.keywrd, "ECHO", (ftnlen)241, (ftnlen)4) != 0) {
	s_wsfe(&io___11);
	e_wsfe();
    }
    if (*(unsigned char *)keywrd_1.keywrd != *(unsigned char *)&space[0]) {
	*(unsigned char *)ch = *(unsigned char *)keywrd_1.keywrd;
	*(unsigned char *)keywrd_1.keywrd = *(unsigned char *)&space[0];
	for (i__ = 2; i__ <= 239; ++i__) {
	    s_copy(ch2, keywrd_1.keywrd + (i__ - 1), (ftnlen)2, (ftnlen)1);
	    *(unsigned char *)&keywrd_1.keywrd[i__ - 1] = *(unsigned char *)
		    ch;
	    s_copy(ch, ch2, (ftnlen)1, (ftnlen)2);
	    i__1 = i__;
	    if (s_cmp(keywrd_1.keywrd + i__1, space2, i__ + 2 - i__1, (ftnlen)
		    2) == 0) {
		i__1 = i__;
		s_copy(keywrd_1.keywrd + i__1, ch, i__ + 1 - i__1, (ftnlen)1);
		goto L80;
	    }
/* L70: */
	}
	s_copy(ch2, keywrd_1.keywrd + 239, (ftnlen)2, (ftnlen)1);
	*(unsigned char *)&keywrd_1.keywrd[239] = *(unsigned char *)ch;
	s_copy(keywrd_1.keywrd + 240, ch2, (ftnlen)1, (ftnlen)2);
L80:
	;
    }
    if (*(unsigned char *)titles_1.koment != *(unsigned char *)&space[0]) {
	*(unsigned char *)ch = *(unsigned char *)titles_1.koment;
	*(unsigned char *)titles_1.koment = *(unsigned char *)&space[0];
	for (i__ = 2; i__ <= 79; ++i__) {
	    s_copy(ch2, titles_1.koment + (i__ - 1), (ftnlen)2, (ftnlen)1);
	    *(unsigned char *)&titles_1.koment[i__ - 1] = *(unsigned char *)
		    ch;
	    s_copy(ch, ch2, (ftnlen)1, (ftnlen)2);
	    i__1 = i__;
	    if (s_cmp(titles_1.koment + i__1, space2, i__ + 2 - i__1, (ftnlen)
		    2) == 0) {
		i__1 = i__;
		s_copy(titles_1.koment + i__1, ch, i__ + 1 - i__1, (ftnlen)1);
		goto L100;
	    }
/* L90: */
	}
	s_copy(ch2, titles_1.koment + 79, (ftnlen)2, (ftnlen)1);
	*(unsigned char *)&titles_1.koment[79] = *(unsigned char *)ch;
	s_copy(titles_1.koment + 80, ch2, (ftnlen)1, (ftnlen)2);
L100:
	;
    }
    if (*(unsigned char *)titles_1.title != *(unsigned char *)&space[0]) {
	*(unsigned char *)ch = *(unsigned char *)titles_1.title;
	*(unsigned char *)titles_1.title = *(unsigned char *)&space[0];
	for (i__ = 2; i__ <= 79; ++i__) {
	    s_copy(ch2, titles_1.title + (i__ - 1), (ftnlen)2, (ftnlen)1);
	    *(unsigned char *)&titles_1.title[i__ - 1] = *(unsigned char *)ch;
	    s_copy(ch, ch2, (ftnlen)1, (ftnlen)2);
	    i__1 = i__;
	    if (s_cmp(titles_1.title + i__1, space2, i__ + 2 - i__1, (ftnlen)
		    2) == 0) {
		i__1 = i__;
		s_copy(titles_1.title + i__1, ch, i__ + 1 - i__1, (ftnlen)1);
		goto L120;
	    }
/* L110: */
	}
	s_copy(ch2, titles_1.title + 79, (ftnlen)2, (ftnlen)1);
	*(unsigned char *)&titles_1.title[79] = *(unsigned char *)ch;
	s_copy(titles_1.title + 80, ch2, (ftnlen)1, (ftnlen)2);
L120:
	;
    }
    for (i__ = 1; i__ <= 200; ++i__) {
/* L121: */
	path_1.react[i__ - 1] = 0.;
    }
    path_1.latom = 0;
    path_1.lparam = 0;
    if (i_indx(keywrd_1.keywrd, "OLDGEO", (ftnlen)241, (ftnlen)6) == 0) {
	geovar_1.nvar = 0;
	geosym_1.ndep = 0;
	if (aigeo || i_indx(keywrd_1.keywrd, "AIGIN", (ftnlen)241, (ftnlen)5) 
		!= 0) {
	    getgeg_(&c__5, geokst_1.labels, geom_1.geo, geokst_1.na, 
		    geokst_1.nb, geokst_1.nc, istope_1.ams, &geokst_1.natoms, 
		    &int__);
	    if (geovar_1.nvar == 0) {
		for (j = 1; j <= 3; ++j) {
		    i__1 = geokst_1.natoms;
		    for (i__ = 1; i__ <= i__1; ++i__) {
/* L122: */
			lopt[j + i__ * 3 - 4] = 0;
		    }
		}
	    }
	} else {
	    getgeo_(&c__5, geokst_1.labels, geom_1.geo, lopt, geokst_1.na, 
		    geokst_1.nb, geokst_1.nc, istope_1.ams, &geokst_1.natoms, 
		    &int__);
	    if (geokst_1.natoms < 0) {
		al__1.aerr = 0;
		al__1.aunit = 5;
		f_rew(&al__1);
		if (numcal_1.numcal != 1) {
		    s_wsfe(&io___16);
		    do_fio(&c__1, "   GAUSSIAN INPUT REQUIRES STAND-ALONE JOB"
			    , (ftnlen)42);
		    e_wsfe();
		    s_wsfe(&io___17);
		    do_fio(&c__1, "   OR KEYWORD \"AIGIN\"", (ftnlen)21);
		    e_wsfe();
		    s_stop("", (ftnlen)0);
		}
		aigeo = TRUE_;
		goto L10;
	    }
	}
	if (geokst_1.natoms == 0) {
	    s_stop("", (ftnlen)0);
	}
    } else {
	degree = 90. / asin(1.);
	if (geokst_1.na[0] == 99) {
	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    lopt[j + i__ * 3 - 4] = 1;
/* L128: */
		    coord[j + i__ * 3 - 4] = geom_1.geo[j + i__ * 3 - 4];
		}
	    }
	    lopt[0] = 0;
	    lopt[1] = 0;
	    lopt[2] = 0;
	    lopt[4] = 0;
	    lopt[5] = 0;
	    lopt[8] = 0;
	    xyzint_(coord, &geokst_1.natoms, geokst_1.na, geokst_1.nb, 
		    geokst_1.nc, &degree, geom_1.geo);
	} else {
	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		for (j = 2; j <= 3; ++j) {
/* L130: */
		    geom_1.geo[j + i__ * 3 - 4] *= degree;
		}
	    }
	}
    }
    if (i_indx(keywrd_1.keywrd, "FORCE", (ftnlen)241, (ftnlen)5) != 0 && 
	    geokst_1.labels[geokst_1.natoms - 1] == 107) {
	i__1 = geokst_1.na[geokst_1.natoms - 1];
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (geokst_1.labels[i__ - 1] == 99) {
		s_wsfe(&io___20);
		do_fio(&c__1, " NO DUMMY ATOMS ALLOWED BEFORE TRANSLATION", (
			ftnlen)42);
		e_wsfe();
		s_wsfe(&io___21);
		do_fio(&c__1, " ATOM IN A FORCE CALCULATION", (ftnlen)28);
		e_wsfe();
		s_stop("", (ftnlen)0);
	    }
/* L131: */
	}
    }


/* OUTPUT FILE TO UNIT 6 */

/*    WRITE HEADER */
    s_copy(idate, " ", (ftnlen)24, (ftnlen)1);
    fdate_(idate, (ftnlen)24);
    s_wsfe(&io___23);
    e_wsfe();

/*     CHANGE THE FOLLOWING LINE TO SUIT LOCAL ENVIRONMENT, IF DESIRED */

    s_copy(banner, " ** MOPAC FOR LINUX (PUBLIC DOMAIN VERSION)  MTA ATOMKI,"
	    " Debrecen, 95-JUN-21  **", (ftnlen)80, (ftnlen)80);
    s_wsfe(&io___25);
    do_fio(&c__1, banner, (ftnlen)80);
    e_wsfe();

/*    THE BANNER DOES NOT APPEAR ANYWHERE ELSE. */

    s_wsfe(&io___26);
    e_wsfe();
    s_copy(line, "   MNDO", (ftnlen)80, (ftnlen)7);
    if (i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 0) {
	s_copy(line, "MINDO/3", (ftnlen)80, (ftnlen)7);
    }
    if (i_indx(keywrd_1.keywrd, "AM1", (ftnlen)241, (ftnlen)3) != 0) {
	s_copy(line, "    AM1", (ftnlen)80, (ftnlen)7);
    }
    if (i_indx(keywrd_1.keywrd, "PM3", (ftnlen)241, (ftnlen)3) != 0) {
	s_copy(line, "    PM3", (ftnlen)80, (ftnlen)7);
    }
    s_wsfe(&io___28);
    do_fio(&c__1, line, (ftnlen)7);
    e_wsfe();
    s_wsfe(&io___29);
    do_fio(&c__1, (char *)&c_b64, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, idate, (ftnlen)24);
    e_wsfe();

/* CONVERT ANGLES TO RADIANS */
    for (j = 2; j <= 3; ++j) {
/* $DOIT VBEST */
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    geom_1.geo[j + i__ * 3 - 4] *= convtr;
/* L140: */
	}
    }

/* CHECK DATA */

    geokst_1.na[0] = 0;
    geokst_1.nb[0] = 0;
    geokst_1.nc[0] = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] <= 0) {
	    s_wsfe(&io___30);
	    do_fio(&c__1, (char *)&geokst_1.labels[i__ - 1], (ftnlen)sizeof(
		    integer));
	    e_wsfe();
	    if (i__ == 1) {
		s_wsfe(&io___31);
		do_fio(&c__1, " THIS WAS THE FIRST ATOM", (ftnlen)24);
		e_wsfe();
	    } else {
		s_wsfe(&io___32);
		do_fio(&c__1, "    GEOMETRY UP TO, BUT NOT INCLUDING, THE FA"
			"ULTY ATOM", (ftnlen)54);
		e_wsfe();
		geokst_1.natoms = i__ - 1;
		geout_(&c__6);
	    }
	    s_stop("", (ftnlen)0);
	}
	if (geokst_1.na[i__ - 1] >= i__ || geokst_1.nb[i__ - 1] >= i__ || 
		geokst_1.nc[i__ - 1] >= i__ || geokst_1.na[i__ - 1] == 
		geokst_1.nb[i__ - 1] && i__ > 1 || (geokst_1.na[i__ - 1] == 
		geokst_1.nc[i__ - 1] || geokst_1.nb[i__ - 1] == geokst_1.nc[
		i__ - 1]) && i__ > 2 || geokst_1.na[i__ - 1] * geokst_1.nb[
		i__ - 1] * geokst_1.nc[i__ - 1] == 0 && i__ > 3) {
	    s_wsfe(&io___33);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    e_wsfe();
	    if (i__ == 1) {
		s_stop("", (ftnlen)0);
	    }
	    s_wsfe(&io___34);
	    e_wsfe();
	    geout_(&c__6);
	    s_stop("", (ftnlen)0);
	}
/* L150: */
    }

/* WRITE KEYWORDS BACK TO USER AS FEEDBACK */
    wrtkey_(keywrd_1.keywrd, (ftnlen)241);
    s_wsfe(&io___35);
    do_fio(&c__1, (char *)&c__60, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&c__60, (ftnlen)sizeof(integer));
    e_wsfe();

/* FILL IN GEO MATRIX IF NEEDED */
    if (i_indx(keywrd_1.keywrd, "OLDGEO", (ftnlen)241, (ftnlen)6) == 0 && 
	    i_indx(keywrd_1.keywrd, "SYM", (ftnlen)241, (ftnlen)3) != 0 && 
	    geosym_1.ndep == 0) {
	getsym_();
    }
    if (geosym_1.ndep != 0) {
	symtry_();
    }

/* INITIALIZE FLAGS FOR OPTIMIZE AND PATH */
    iflag = 0;
    path_1.latom = 0;
    molkst_1.numat = 0;
    if (geovar_1.nvar != 0) {
	molkst_1.numat = geokst_1.natoms;
    } else {
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (geokst_1.labels[i__ - 1] != 99 && geokst_1.labels[i__ - 1] != 
		    107) {
		++molkst_1.numat;
	    }
	    for (j = 1; j <= 3; ++j) {
		if ((i__2 = lopt[j + i__ * 3 - 4]) < 0) {
		    goto L160;
		} else if (i__2 == 0) {
		    goto L180;
		} else {
		    goto L170;
		}
/*    FLAG FOR PATH */
L160:
		convrt = 1.;
		if (iflag != 0) {
		    if (i_indx(keywrd_1.keywrd, "STEP1", (ftnlen)241, (ftnlen)
			    5) != 0) {
			mesh_1.lpara1 = path_1.lparam;
			mesh_1.latom1 = path_1.latom;
			mesh_1.lpara2 = j;
			mesh_1.latom2 = i__;
			path_1.latom = 0;
			iflag = 0;
			goto L180;
		    } else {
			s_wsfe(&io___38);
			e_wsfe();
			s_stop("", (ftnlen)0);
		    }
		}
		path_1.latom = i__;
		path_1.lparam = j;
		if (j > 1) {
		    convrt = .01745329252;
		}
		path_1.react[0] = geom_1.geo[j + i__ * 3 - 4];
		ireact = 1;
		iflag = 1;
		goto L180;
/*    FLAG FOR OPTIMIZE */
L170:
		++geovar_1.nvar;
		geovar_1.loc[(geovar_1.nvar << 1) - 2] = i__;
		geovar_1.loc[(geovar_1.nvar << 1) - 1] = j;
		geovar_1.xparam[geovar_1.nvar - 1] = geom_1.geo[j + i__ * 3 - 
			4];
L180:
		;
	    }
	}
    }
/* READ IN PATH VALUES */
    if (iflag == 0) {
	goto L220;
    }
    if (i_indx(keywrd_1.keywrd, "NLLSQ", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___40);
	do_fio(&c__1, " NLLSQ USED WITH REACTION PATH; THIS OPTION IS NOT AL"
		"LOWED", (ftnlen)58);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (i_indx(keywrd_1.keywrd, "SIGMA", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___41);
	do_fio(&c__1, " SIGMA USED WITH REACTION PATH; THIS OPTION IS NOT AL"
		"LOWED", (ftnlen)58);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (i_indx(keywrd_1.keywrd, "STEP", (ftnlen)241, (ftnlen)4) + i_indx(
	    keywrd_1.keywrd, "POINTS", (ftnlen)241, (ftnlen)6) != 0) {
	i__1 = i_indx(keywrd_1.keywrd, "STEP=", (ftnlen)241, (ftnlen)5) + 5;
	step = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	i__1 = i_indx(keywrd_1.keywrd, "POINT=", (ftnlen)241, (ftnlen)6) + 6;
	npts = (integer) reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	if (npts > 200) {
	    s_wsfe(&io___44);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	if (path_1.lparam == 1 && step <= 0.) {
	    s_wsfe(&io___45);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	goto L220;
    }
L190:
    i__1 = s_rsfe(&io___46);
    if (i__1 != 0) {
	goto L210;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)80);
    if (i__1 != 0) {
	goto L210;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L210;
    }
    nuchar_(line, value, &nreact, (ftnlen)80);
    if (nreact == 0) {
	goto L210;
    }
    i__1 = nreact;
    for (i__ = 1; i__ <= i__1; ++i__) {
	ij = ireact + i__;
	if (ij > 200) {
	    s_wsfe(&io___50);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	path_1.react[ij - 1] = value[i__ - 1] * convrt;
	if ((d__1 = path_1.react[ij - 1] - path_1.react[ij - 2], abs(d__1)) < 
		1e-5) {
	    dum1 = path_1.react[ij - 1] / convrt;
	    dum2 = path_1.react[ij - 2] / convrt;
	    s_wsfe(&io___53);
	    do_fio(&c__1, (char *)&dum1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&dum2, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
/* L200: */
    }
    ireact += nreact;
    goto L190;
L210:
    degree = 1.;
    if (path_1.lparam > 1) {
	degree = 90. / asin(1.);
    }
    if (ireact <= 1) {
	s_wsfe(&io___54);
	e_wsfe();
	s_wsfe(&io___55);
	e_wsfe();
	geout_(&c__1);
	s_stop("", (ftnlen)0);
    } else {
	s_wsfe(&io___56);
	e_wsfe();
	s_wsfe(&io___57);
	i__1 = ireact;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    d__1 = path_1.react[i__ - 1] * degree;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    iend = ireact + 1;
    path_1.react[iend - 1] = -1e12;

/* OUTPUT GEOMETRY AS FEEDBACK */

L220:
    wrttxt_(&c__6);
    if (i_indx(keywrd_1.keywrd, "NOLOG", (ftnlen)241, (ftnlen)5) == 0) {
	o__1.oerr = 0;
	o__1.ounit = 11;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR011", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "UNKNOWN";
	o__1.oacc = 0;
	o__1.ofm = "FORMATTED";
	o__1.oblnk = 0;
	f_open(&o__1);
	wrttxt_(&c__11);
    }
    geout_(&c__1);
    gmetry_(geom_1.geo, coord);

/*  IF A POLYMER, EXPAND TO MERS */

    if (i_indx(keywrd_1.keywrd, " MERS", (ftnlen)241, (ftnlen)5) != 0) {
	makpol_(coord);
    }
    if (i_indx(keywrd_1.keywrd, "NOXYZ", (ftnlen)241, (ftnlen)5) == 0) {
	if (i_indx(keywrd_1.keywrd, "0SCF", (ftnlen)241, (ftnlen)4) != 0) {

/*  WRITE OUT CARTESIAN COORDINATES FOR USE AS A DATA-SET */

	    s_wsfe(&io___59);
	    do_fio(&c__1, "   GEOMETRY IN CARTESIAN COORDINATE FORMAT", (
		    ftnlen)42);
	    e_wsfe();
	    wrttxt_(&c__6);
	    j = 0;
	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (geokst_1.labels[i__ - 1] != 99) {
		    ++j;
		    s_wsfe(&io___60);
		    do_fio(&c__1, elemts_1.elemnt + (geokst_1.labels[i__ - 1] 
			    - 1 << 1), (ftnlen)2);
		    for (k = 1; k <= 3; ++k) {
			do_fio(&c__1, (char *)&coord[k + j * 3 - 4], (ftnlen)
				sizeof(doublereal));
			do_fio(&c__1, (char *)&c__1, (ftnlen)sizeof(integer));
		    }
		    e_wsfe();
		}
/* L230: */
	    }
	} else {
	    s_wsfe(&io___61);
	    e_wsfe();
	    s_wsfe(&io___62);
	    e_wsfe();
	    l = 0;
	    i__1 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__1; ++i__) {
		if (geokst_1.labels[i__ - 1] == 99 || geokst_1.labels[i__ - 1]
			 == 107) {
		    goto L240;
		}
		++l;
		s_wsfe(&io___64);
		do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
		do_fio(&c__1, elemts_1.elemnt + (geokst_1.labels[i__ - 1] - 1 
			<< 1), (ftnlen)2);
		for (j = 1; j <= 3; ++j) {
		    do_fio(&c__1, (char *)&coord[j + l * 3 - 4], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
L240:
		;
	    }
	}
    }

/*    C is not actually used in this call. */

    symtrz_(coord, c__, &molkst_1.norbs, &molkst_1.norbs, &c_false, &c_false);
    s_wsfe(&io___66);
    do_fio(&c__1, symres_1.name__, (ftnlen)4);
    e_wsfe();
    if (i_indx(keywrd_1.keywrd, " XYZ", (ftnlen)241, (ftnlen)4) != 0) {
	if (geovar_1.nvar != 0 && int__ && (geosym_1.ndep != 0 || 
		geovar_1.nvar < molkst_1.numat * 3 - 6)) {
	    if (geosym_1.ndep != 0) {
		s_wsfe(&io___67);
		e_wsfe();
	    }
	    if (geovar_1.nvar < molkst_1.numat * 3 - 6) {
		s_wsfe(&io___68);
		e_wsfe();
	    }
	    s_wsfe(&io___69);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
	sumx = 0.;
	sumy = 0.;
	sumz = 0.;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    sumx += coord[j * 3 - 3];
	    sumy += coord[j * 3 - 2];
/* L250: */
	    sumz += coord[j * 3 - 1];
	}
	sumx /= molkst_1.numat;
	sumy /= molkst_1.numat;
	sumz /= molkst_1.numat;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    geom_1.geo[j * 3 - 3] = coord[j * 3 - 3] - sumx;
	    geom_1.geo[j * 3 - 2] = coord[j * 3 - 2] - sumy;
/* L260: */
	    geom_1.geo[j * 3 - 1] = coord[j * 3 - 1] - sumz;
	}
	geokst_1.na[0] = 99;
	j = 0;
	geovar_1.nvar = 0;
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (geokst_1.labels[i__ - 1] != 99) {
		++j;
		if (j == 1) {
		    k = 0;
		} else if (j < 4) {
/* Computing MIN */
		    i__2 = 3, i__3 = i__ - 1;
		    k = min(i__2,i__3);
		} else {
		    k = 3;
		}
		i__2 = k;
		for (l = 1; l <= i__2; ++l) {
		    ++geovar_1.nvar;
		    geovar_1.loc[(geovar_1.nvar << 1) - 2] = j;
		    geovar_1.loc[(geovar_1.nvar << 1) - 1] = l;
/* L270: */
		    geovar_1.xparam[geovar_1.nvar - 1] = geom_1.geo[l + j * 3 
			    - 4];
		}
		geokst_1.labels[j - 1] = geokst_1.labels[i__ - 1];
	    }
/* L280: */
	}
	geokst_1.natoms = molkst_1.numat;
    } else {
	if (geovar_1.nvar == 0) {
	    return 0;
	}
	if (! int__ && (geosym_1.ndep != 0 || geovar_1.nvar < molkst_1.numat *
		 3 - 6)) {
	    if (geosym_1.ndep != 0) {
		s_wsfe(&io___73);
		e_wsfe();
	    }
	    if (geovar_1.nvar < molkst_1.numat * 3 - 6) {
		s_wsfe(&io___74);
		e_wsfe();
	    }
	    s_wsfe(&io___75);
	    e_wsfe();
	    s_wsfe(&io___76);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
    return 0;
} /* readmo_ */

#undef keys


