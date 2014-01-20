/* react1.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    doublereal ams[107];
} istope_;

#define istope_1 istope_

struct {
    doublereal cosine;
} gravec_;

#define gravec_1 gravec_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer iflepo, iscf;
} mesage_;

#define mesage_1 mesage_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal step, geoa[360]	/* was [3][120] */, geovec[360]	/* was [3][
	    120] */, calcst;
} reactn_;

#define reactn_1 reactn_

/* Table of constant values */

static integer c__5 = 5;
static integer c__1 = 1;
static doublereal c_b64 = 4.;
static logical c_true = TRUE_;
static integer c__6 = 6;

/* Subroutine */ int react1_(doublereal *escf)
{
    /* Initialized data */

    static integer irot[6]	/* was [2][3] */ = { 1,2,1,3,2,3 };

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    static doublereal equiv_0[360];

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    double pow_di(doublereal *, integer *), cos(doublereal), sqrt(doublereal);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal x, c1, c2, ca, sa;
    static integer ir, jr;
    static logical gok[2];
    static doublereal one;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static logical int__;
    static doublereal sum;
    static logical xyz;
    static doublereal dell, eold, gold, xold[360], swap, summ, sumx, sumy, 
	    sumz, time0;
    static integer idum1[120], idum2[120], idum3[120];
    static doublereal time1, time2, step0;
    extern doublereal reada_(char *, integer *, ftnlen);
    static integer iflag;
    extern /* Subroutine */ int flepo_(doublereal *, integer *, doublereal *);
#define coord (equiv_0)
    static doublereal grold[360];
    extern /* Subroutine */ int geout_(integer *);
    static integer iloop;
    static doublereal funct1;
    static integer numat2;
    static logical gradnt, finish;
    static integer linear;
    extern /* Subroutine */ int getgeo_(integer *, integer *, doublereal *, 
	    integer *, integer *, integer *, integer *, doublereal *, integer 
	    *, logical *);
    extern doublereal second_(void);
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *);
#define idummy ((integer *)equiv_0)
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);
    static real pastor[45150], pbstor[45150];
    static integer maxstp;
    static doublereal stepmx;
    extern /* Subroutine */ int writmo_(doublereal *, doublereal *);
    static doublereal xstore[360];
    extern /* Subroutine */ int symtry_(void);

    /* Fortran I/O blocks */
    static cilist io___18 = { 0, 6, 0, "(10X,'ERRORS DETECTED IN CONNECTIVIT"
	    "Y')", 0 };
    static cilist io___19 = { 0, 6, 0, "(A,I3,A,I3,A,I3,A)", 0 };
    static cilist io___20 = { 0, 6, 0, "(10X,'ERRORS DETECTED IN CONNECTIVIT"
	    "Y')", 0 };
    static cilist io___21 = { 0, 6, 0, "(A,I3,A,I3,A,I3,A)", 0 };
    static cilist io___22 = { 0, 6, 0, "(10X,'ERRORS DETECTED IN CONNECTIVIT"
	    "Y')", 0 };
    static cilist io___23 = { 0, 6, 0, "(A,I3,A,I3,A,I3,A)", 0 };
    static cilist io___24 = { 0, 6, 0, "(10X,A)", 0 };
    static cilist io___28 = { 0, 6, 0, "(//10X,' NUMBER OF ATOMS IN SECOND S"
	    "YSTEM IS ',     'INCORRECT',/)", 0 };
    static cilist io___29 = { 0, 6, 0, "(' NUMBER OF ATOMS IN FIRST  SYSTEM "
	    "=',I4)", 0 };
    static cilist io___30 = { 0, 6, 0, "(' NUMBER OF ATOMS IN SECOND SYSTEM "
	    "=',I4)", 0 };
    static cilist io___31 = { 0, 6, 0, "(//10X,' GEOMETRY OF SECOND SYSTEM',"
	    "/)", 0 };
    static cilist io___36 = { 0, 6, 0, "(//,'  CARTESIAN GEOMETRY OF FIRST S"
	    "YSTEM',//)", 0 };
    static cilist io___37 = { 0, 6, 0, "(3F14.5)", 0 };
    static cilist io___45 = { 0, 6, 0, "(//,'  CARTESIAN GEOMETRY OF SECOND "
	    "SYSTEM',//)", 0 };
    static cilist io___46 = { 0, 6, 0, "(3F14.5)", 0 };
    static cilist io___47 = { 0, 6, 0, "(//,'   \"DISTANCE\":',F13.6)", 0 };
    static cilist io___48 = { 0, 6, 0, "(//,'  REACTION COORDINATE VECTOR',/"
	    "/)", 0 };
    static cilist io___49 = { 0, 6, 0, "(3F14.5)", 0 };
    static cilist io___50 = { 0, 6, 0, "(///10X,'THERE ARE NO VARIABLES IN T"
	    "HE SADDLE',     ' CALCULATION!')", 0 };
    static cilist io___54 = { 0, 6, 0, "(//,3(5X,A,/))", 0 };
    static cilist io___61 = { 0, 6, 0, "(' ',40('*+'))", 0 };
    static cilist io___62 = { 0, 6, 0, "('  BAR SHORTENED BY',F12.7,' PERCEN"
	    "T')", 0 };
    static cilist io___66 = { 0, 6, 0, "(//10X,'FOR POINT',I3,' SECOND STRUC"
	    "TURE')", 0 };
    static cilist io___67 = { 0, 6, 0, "(//10X,'FOR POINT',I3,' FIRST  STRUC"
	    "TURE')", 0 };
    static cilist io___68 = { 0, 6, 0, "(' DISTANCE A - B  ',F12.6)", 0 };
    static cilist io___70 = { 0, 6, 0, "('  ACTUAL GRADIENTS OF THIS POINT')",
	     0 };
    static cilist io___71 = { 0, 6, 0, "(8F10.4)", 0 };
    static cilist io___72 = { 0, 6, 0, "(' HEAT            ',F12.6)", 0 };
    static cilist io___73 = { 0, 6, 0, "(' GRADIENT NORM   ',F12.6)", 0 };
    static cilist io___74 = { 0, 6, 0, "(' DIRECTION COSINE',F12.6)", 0 };
    static cilist io___76 = { 0, 6, 0, "(//10X,' BOTH SYSTEMS ARE ON THE SAM"
	    "E SIDE OF THE ','TRANSITION STATE -',/10X,' GEOMETRIES OF THE SY"
	    "STEMS', ' ON EACH SIDE OF THE T.S. ARE AS FOLLOWS')", 0 };
    static cilist io___77 = { 0, 6, 0, "(//10X,' GEOMETRY ON ONE SIDE OF THE"
	    " TRANSITION',' STATE')", 0 };
    static cilist io___79 = { 0, 6, 0, "(' TIME=',F9.2)", 0 };
    static cilist io___80 = { 0, 6, 0, "('  REACTANTS AND PRODUCTS SWAPPED A"
	    "ROUND')", 0 };
    static cilist io___81 = { 0, 6, 0, "(' AT END OF REACTION')", 0 };
    static cilist io___84 = { 0, 6, 0, "(' BEST ESTIMATE GEOMETRY OF THE TRA"
	    "NSITION STATE')", 0 };
    static cilist io___85 = { 0, 6, 0, "(//10X,' C1=',F8.3,'C2=',F8.3)", 0 };


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

/*  REACT1 DETERMINES THE TRANSITION STATE OF A CHEMICAL REACTION. */

/*   REACT WORKS BY USING TWO SYSTEMS SIMULTANEOUSLY, THE HEATS OF */
/*   FORMATION OF BOTH ARE CALCULATED, THEN THE MORE STABLE ONE */
/*   IS MOVED IN THE DIRECTION OF THE OTHER. AFTER A STEP THE */
/*   ENERGIES ARE COMPARED, AND THE NOW LOWER-ENERGY FORM IS MOVED */
/*   IN THE DIRECTION OF THE HIGHER-ENERGY FORM. THIS IS REPEATED */
/*   UNTIL THE SADDLE POINT IS REACHED. */

/*   IF ONE FORM IS MOVED 3 TIMES IN SUCCESSION, THEN THE HIGHER ENERGY */
/*   FORM IS RE-OPTIMIZED WITHOUT SHORTENING THE DISTANCE BETWEEN THE TWO */
/*   FORMS. THIS REDUCES THE CHANCE OF BEING CAUGHT ON THE SIDE OF A */
/*   TRANSITION STATE. */

/* *********************************************************************** */
    gold = 0.;
    linear = 0;
    iflag = 1;
    gok[0] = FALSE_;
    gok[1] = FALSE_;
    xyz = i_indx(keywrd_1.keywrd, " XYZ", (ftnlen)241, (ftnlen)4) != 0;
    gradnt = i_indx(keywrd_1.keywrd, "GRAD", (ftnlen)241, (ftnlen)4) != 0;
    i__ = i_indx(keywrd_1.keywrd, " BAR", (ftnlen)241, (ftnlen)4);
    stepmx = .15;
    if (i__ != 0) {
	stepmx = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
    }
    maxstp = 1000;

/*    READ IN THE SECOND GEOMETRY. */

    if (xyz) {
	getgeo_(&c__5, geokst_1.labels, reactn_1.geoa, geovar_1.loc, 
		geokst_1.na, geokst_1.nb, geokst_1.nc, istope_1.ams, &
		geokst_1.natoms, &int__);
    } else {
	getgeo_(&c__5, idum1, reactn_1.geoa, idummy, idum1, idum2, idum3, 
		istope_1.ams, &geokst_1.natoms, &int__);

/*  IF INTERNAL COORDINATES ARE TO BE USED, CHECK THE CONNECTIVITY */

	l = 0;
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (idum1[i__ - 1] != geokst_1.na[i__ - 1]) {
		++l;
		if (l == 1) {
		    s_wsfe(&io___18);
		    e_wsfe();
		}
		s_wsfe(&io___19);
		do_fio(&c__1, " FOR ATOM", (ftnlen)9);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, " THE BOND LABELS ARE DIFFERENT:      ", (
			ftnlen)37);
		do_fio(&c__1, (char *)&idum1[i__ - 1], (ftnlen)sizeof(integer)
			);
		do_fio(&c__1, " AND", (ftnlen)4);
		do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
			integer));
		e_wsfe();
	    }
	    if (idum2[i__ - 1] != geokst_1.nb[i__ - 1]) {
		++l;
		if (l == 1) {
		    s_wsfe(&io___20);
		    e_wsfe();
		}
		s_wsfe(&io___21);
		do_fio(&c__1, " FOR ATOM", (ftnlen)9);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, " THE BOND ANGLE LABELS ARE DIFFERENT:", (
			ftnlen)37);
		do_fio(&c__1, (char *)&idum2[i__ - 1], (ftnlen)sizeof(integer)
			);
		do_fio(&c__1, " AND", (ftnlen)4);
		do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)sizeof(
			integer));
		e_wsfe();
	    }
	    if (idum3[i__ - 1] != geokst_1.nc[i__ - 1]) {
		++l;
		if (l == 1) {
		    s_wsfe(&io___22);
		    e_wsfe();
		}
		s_wsfe(&io___23);
		do_fio(&c__1, " FOR ATOM", (ftnlen)9);
		do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		do_fio(&c__1, " THE DIHEDRAL LABELS ARE DIFFERENT:  ", (
			ftnlen)37);
		do_fio(&c__1, (char *)&idum3[i__ - 1], (ftnlen)sizeof(integer)
			);
		do_fio(&c__1, " AND", (ftnlen)4);
		do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)sizeof(
			integer));
		e_wsfe();
	    }
/* L10: */
	}
	if (l != 0) {
	    s_wsfe(&io___24);
	    do_fio(&c__1, " CORRECT BEFORE RESUBMISSION", (ftnlen)28);
	    e_wsfe();
	}
	if (l != 0) {
	    s_stop("", (ftnlen)0);
	}
    }
    time0 = second_();

/*  SWAP FIRST AND SECOND GEOMETRIES AROUND */
/*  SO THAT GEOUT CAN OUTPUT DATA ON SECOND GEOMETRY. */

    numat2 = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geokst_1.labels[i__ - 1] != 99) {
	    ++numat2;
	}
	x = reactn_1.geoa[i__ * 3 - 3];
	reactn_1.geoa[i__ * 3 - 3] = geom_1.geo[i__ * 3 - 3];
	geom_1.geo[i__ * 3 - 3] = x;
	x = reactn_1.geoa[i__ * 3 - 2] * .0174532925;
	reactn_1.geoa[i__ * 3 - 2] = geom_1.geo[i__ * 3 - 2];
	geom_1.geo[i__ * 3 - 2] = x;
	x = reactn_1.geoa[i__ * 3 - 1] * .0174532925;
	reactn_1.geoa[i__ * 3 - 1] = geom_1.geo[i__ * 3 - 1];
	geom_1.geo[i__ * 3 - 1] = x;
/* L20: */
    }
    if (numat2 != molkst_1.numat) {
	s_wsfe(&io___28);
	e_wsfe();
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&molkst_1.numat, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___30);
	do_fio(&c__1, (char *)&numat2, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L280;
    }
    s_wsfe(&io___31);
    e_wsfe();
    if (geosym_1.ndep != 0) {
	symtry_();
    }
    geout_(&c__1);

/*     CONVERT TO CARTESIAN, IF NECESSARY */

    if (xyz) {
	gmetry_(geom_1.geo, coord);
	sumx = 0.;
	sumy = 0.;
	sumz = 0.;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    sumx += coord[j * 3 - 3];
	    sumy += coord[j * 3 - 2];
/* L30: */
	    sumz += coord[j * 3 - 1];
	}
	sumx /= molkst_1.numat;
	sumy /= molkst_1.numat;
	sumz /= molkst_1.numat;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    geom_1.geo[j * 3 - 3] = coord[j * 3 - 3] - sumx;
	    geom_1.geo[j * 3 - 2] = coord[j * 3 - 2] - sumy;
/* L40: */
	    geom_1.geo[j * 3 - 1] = coord[j * 3 - 1] - sumz;
	}
	s_wsfe(&io___36);
	e_wsfe();
	s_wsfe(&io___37);
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&geom_1.geo[j + i__ * 3 - 4], (ftnlen)
			sizeof(doublereal));
	    }
	}
	e_wsfe();
	sumx = 0.;
	sumy = 0.;
	sumz = 0.;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    sumx += reactn_1.geoa[j * 3 - 3];
	    sumy += reactn_1.geoa[j * 3 - 2];
/* L50: */
	    sumz += reactn_1.geoa[j * 3 - 1];
	}
	sum = 0.;
	sumx /= molkst_1.numat;
	sumy /= molkst_1.numat;
	sumz /= molkst_1.numat;
	i__1 = molkst_1.numat;
	for (j = 1; j <= i__1; ++j) {
	    reactn_1.geoa[j * 3 - 3] -= sumx;
	    reactn_1.geoa[j * 3 - 2] -= sumy;
	    reactn_1.geoa[j * 3 - 1] -= sumz;
/* Computing 2nd power */
	    d__1 = geom_1.geo[j * 3 - 3] - reactn_1.geoa[j * 3 - 3];
/* Computing 2nd power */
	    d__2 = geom_1.geo[j * 3 - 2] - reactn_1.geoa[j * 3 - 2];
/* Computing 2nd power */
	    d__3 = geom_1.geo[j * 3 - 1] - reactn_1.geoa[j * 3 - 1];
	    sum = sum + d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* L60: */
	}
	for (l = 3; l >= 1; --l) {

/*     DOCKING IS DONE IN STEPS OF 16, 4, AND 1 DEGREES AT A TIME. */

	    i__1 = l - 1;
	    ca = cos(pow_di(&c_b64, &i__1) * .01745329);
/* Computing 2nd power */
	    d__2 = ca;
	    sa = sqrt((d__1 = 1. - d__2 * d__2, abs(d__1)));
	    for (j = 1; j <= 3; ++j) {
		ir = irot[(j << 1) - 2];
		jr = irot[(j << 1) - 1];
		for (i__ = 1; i__ <= 10; ++i__) {
		    summ = 0.;
		    i__1 = molkst_1.numat;
		    for (k = 1; k <= i__1; ++k) {
			x = ca * reactn_1.geoa[ir + k * 3 - 4] + sa * 
				reactn_1.geoa[jr + k * 3 - 4];
			reactn_1.geoa[jr + k * 3 - 4] = -sa * reactn_1.geoa[
				ir + k * 3 - 4] + ca * reactn_1.geoa[jr + k * 
				3 - 4];
			reactn_1.geoa[ir + k * 3 - 4] = x;
/* Computing 2nd power */
			d__1 = geom_1.geo[k * 3 - 3] - reactn_1.geoa[k * 3 - 
				3];
/* Computing 2nd power */
			d__2 = geom_1.geo[k * 3 - 2] - reactn_1.geoa[k * 3 - 
				2];
/* Computing 2nd power */
			d__3 = geom_1.geo[k * 3 - 1] - reactn_1.geoa[k * 3 - 
				1];
			summ = summ + d__1 * d__1 + d__2 * d__2 + d__3 * d__3;
/* L70: */
		    }
		    if (summ > sum) {
			if (i__ > 1) {
			    sa = -sa;
			    i__1 = molkst_1.numat;
			    for (k = 1; k <= i__1; ++k) {
				x = ca * reactn_1.geoa[ir + k * 3 - 4] + sa * 
					reactn_1.geoa[jr + k * 3 - 4];
				reactn_1.geoa[jr + k * 3 - 4] = -sa * 
					reactn_1.geoa[ir + k * 3 - 4] + ca * 
					reactn_1.geoa[jr + k * 3 - 4];
				reactn_1.geoa[ir + k * 3 - 4] = x;
/* L80: */
			    }
			    goto L100;
			}
			sa = -sa;
		    }
/* L90: */
		    sum = summ;
		}
L100:
		;
	    }
/* L110: */
	}
	s_wsfe(&io___45);
	e_wsfe();
	s_wsfe(&io___46);
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&reactn_1.geoa[j + i__ * 3 - 4], (
			ftnlen)sizeof(doublereal));
	    }
	}
	e_wsfe();
	s_wsfe(&io___47);
	do_fio(&c__1, (char *)&sum, (ftnlen)sizeof(doublereal));
	e_wsfe();
	s_wsfe(&io___48);
	e_wsfe();
	s_wsfe(&io___49);
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    for (j = 1; j <= 3; ++j) {
		d__1 = reactn_1.geoa[j + i__ * 3 - 4] - geom_1.geo[j + i__ * 
			3 - 4];
		do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    }
	}
	e_wsfe();
	geokst_1.na[0] = 99;
	j = 0;
	geovar_1.nvar = 0;
	i__1 = geokst_1.natoms;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (geokst_1.labels[i__ - 1] != 99) {
		++j;
		for (k = 1; k <= 3; ++k) {
		    ++geovar_1.nvar;
		    geovar_1.loc[(geovar_1.nvar << 1) - 1] = k;
/* L120: */
		    geovar_1.loc[(geovar_1.nvar << 1) - 2] = j;
		}
		geokst_1.labels[j - 1] = geokst_1.labels[i__ - 1];
	    }
/* L130: */
	}
	geokst_1.natoms = molkst_1.numat;
    }

/*   XPARAM HOLDS THE VARIABLE PARAMETERS FOR GEOMETRY IN GEO */
/*   XOLD   HOLDS THE VARIABLE PARAMETERS FOR GEOMETRY IN GEOA */

    if (geovar_1.nvar == 0) {
	s_wsfe(&io___50);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    sum = 0.;
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	grold[i__ - 1] = 1.;
	geovar_1.xparam[i__ - 1] = geom_1.geo[geovar_1.loc[(i__ << 1) - 1] + 
		geovar_1.loc[(i__ << 1) - 2] * 3 - 4];
	xold[i__ - 1] = reactn_1.geoa[geovar_1.loc[(i__ << 1) - 1] + 
		geovar_1.loc[(i__ << 1) - 2] * 3 - 4];
/* L140: */
/* Computing 2nd power */
	d__1 = geovar_1.xparam[i__ - 1] - xold[i__ - 1];
	sum += d__1 * d__1;
    }
    step0 = sqrt(sum);
    if (step0 < 1e-5) {
	s_wsfe(&io___54);
	do_fio(&c__1, " BOTH GEOMETRIES ARE IDENTICAL", (ftnlen)30);
	do_fio(&c__1, " A SADDLE CALCULATION INVOLVES A REACTANT AND A PRODU"
		"CT", (ftnlen)55);
	do_fio(&c__1, " THESE MUST BE DIFFERENT GEOMETRIES", (ftnlen)35);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    one = 1.;
    dell = .1;
    eold = -2e3;
    time1 = second_();
    swap = 0.;
    i__1 = maxstp;
    for (iloop = 1; iloop <= i__1; ++iloop) {
	s_wsfe(&io___61);
	e_wsfe();

/*   THIS METHOD OF CALCULATING 'STEP' IS QUITE ARBITARY, AND NEEDS */
/*   TO BE IMPROVED BY INTELLIGENT GUESSWORK! */

	if (gradnt_1.gnorm < .001) {
	    gradnt_1.gnorm = .001;
	}
/* Computing MIN */
	d__1 = min(swap,.5), d__2 = 6. / gradnt_1.gnorm, d__1 = min(d__1,d__2)
		, d__1 = min(d__1,dell), d__2 = stepmx * step0 + .005;
	reactn_1.step = min(d__1,d__2);
/* Computing MIN */
	d__1 = .2, d__2 = reactn_1.step / step0;
	reactn_1.step = min(d__1,d__2) * step0;
	swap += 1.;
	dell += .1;
	s_wsfe(&io___62);
	d__1 = reactn_1.step / step0 * 100.;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	step0 -= reactn_1.step;
	if (step0 < .01) {
	    goto L250;
	}
	reactn_1.step = step0;
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L150: */
	    xstore[i__ - 1] = geovar_1.xparam[i__ - 1];
	}
	flepo_(geovar_1.xparam, &geovar_1.nvar, escf);
	if (linear == 0) {
	    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
	    i__2 = linear;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		pastor[i__ - 1] = densty_1.pa[i__ - 1];
/* L160: */
		pbstor[i__ - 1] = densty_1.pb[i__ - 1];
	    }
	}
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L170: */
	    geovar_1.xparam[i__ - 1] = geom_1.geo[geovar_1.loc[(i__ << 1) - 1]
		     + geovar_1.loc[(i__ << 1) - 2] * 3 - 4];
	}
	if (iflag == 1) {
	    s_wsfe(&io___66);
	    do_fio(&c__1, (char *)&iloop, (ftnlen)sizeof(integer));
	    e_wsfe();
	} else {
	    s_wsfe(&io___67);
	    do_fio(&c__1, (char *)&iloop, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
	s_wsfe(&io___68);
	do_fio(&c__1, (char *)&reactn_1.step, (ftnlen)sizeof(doublereal));
	e_wsfe();

/*   NOW TO CALCULATE THE "CORRECT" GRADIENTS, SWITCH OFF 'STEP'. */

	reactn_1.step = 0.;
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L180: */
	    gradnt_1.grad[i__ - 1] = grold[i__ - 1];
	}
	compfg_(geovar_1.xparam, &c_true, &funct1, &c_true, gradnt_1.grad, &
		c_true);
	i__2 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L190: */
	    grold[i__ - 1] = gradnt_1.grad[i__ - 1];
	}
	if (gradnt) {
	    s_wsfe(&io___70);
	    e_wsfe();
	    s_wsfe(&io___71);
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	}
	s_wsfe(&io___72);
	do_fio(&c__1, (char *)&funct1, (ftnlen)sizeof(doublereal));
	e_wsfe();
	gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, &
		geovar_1.nvar));
	s_wsfe(&io___73);
	do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
	e_wsfe();
	gravec_1.cosine *= one;
	s_wsfe(&io___74);
	do_fio(&c__1, (char *)&gravec_1.cosine, (ftnlen)sizeof(doublereal));
	e_wsfe();
	geout_(&c__6);
	if (swap > 2.9 || iloop > 3 && gravec_1.cosine < 0. || *escf > eold) {
	    if (swap > 2.9) {
		swap = 0.;
	    } else {
		swap = .5;
	    }

/*   SWAP REACTANT AND PRODUCT AROUND */

	    finish = gok[0] && gok[1] && gravec_1.cosine < 0.;
	    if (finish) {
		s_wsfe(&io___76);
		e_wsfe();
		i__2 = geovar_1.nvar;
		for (i__ = 1; i__ <= i__2; ++i__) {
/* L200: */
		    geovar_1.xparam[i__ - 1] = xstore[i__ - 1];
		}
		compfg_(geovar_1.xparam, &c_true, &funct1, &c_true, 
			gradnt_1.grad, &c_true);
		s_wsfe(&io___77);
		e_wsfe();
		writmo_(&time0, &funct1);
	    }
	    time2 = second_();
	    s_wsfe(&io___79);
	    d__1 = time2 - time1;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    time1 = time2;
	    s_wsfe(&io___80);
	    e_wsfe();
	    iflag = 1 - iflag;
	    one = -1.;
	    eold = *escf;
	    sum = gold;
	    gold = gradnt_1.gnorm;
	    i__ = (integer) (one * .5 + 1.7);
	    if (gradnt_1.gnorm > 10.) {
		gok[i__ - 1] = TRUE_;
	    }
	    gradnt_1.gnorm = sum;
	    i__2 = geokst_1.natoms;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		for (j = 1; j <= 3; ++j) {
		    x = geom_1.geo[j + i__ * 3 - 4];
		    geom_1.geo[j + i__ * 3 - 4] = reactn_1.geoa[j + i__ * 3 - 
			    4];
/* L210: */
		    reactn_1.geoa[j + i__ * 3 - 4] = x;
		}
	    }
	    i__2 = geovar_1.nvar;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		x = xold[i__ - 1];
		xold[i__ - 1] = geovar_1.xparam[i__ - 1];
/* L220: */
		geovar_1.xparam[i__ - 1] = x;
	    }


/*    SWAP AROUND THE DENSITY MATRICES. */

	    i__2 = linear;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		x = pastor[i__ - 1];
		pastor[i__ - 1] = densty_1.pa[i__ - 1];
		densty_1.pa[i__ - 1] = x;
		x = pbstor[i__ - 1];
		pbstor[i__ - 1] = densty_1.pb[i__ - 1];
		densty_1.pb[i__ - 1] = x;
		densty_1.p[i__ - 1] = densty_1.pa[i__ - 1] + densty_1.pb[i__ 
			- 1];
/* L230: */
	    }
	    if (finish) {
		goto L250;
	    }
	} else {
	    one = 1.;
	}
/* L240: */
    }
L250:
    s_wsfe(&io___81);
    e_wsfe();
    gold = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, &geovar_1.nvar));
    compfg_(geovar_1.xparam, &c_true, &funct1, &c_true, gradnt_1.grad, &
	    c_true);
    gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, &geovar_1.nvar));
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L260: */
	grold[i__ - 1] = geovar_1.xparam[i__ - 1];
    }
    writmo_(&time0, &funct1);

/* THE GEOMETRIES HAVE (A) BEEN OPTIMIZED CORRECTLY, OR */
/*                     (B) BOTH ENDED UP ON THE SAME SIDE OF THE T.S. */

/*  TRANSITION STATE LIES BETWEEN THE TWO GEOMETRIES */

    c1 = gold / (gold + gradnt_1.gnorm);
    c2 = 1. - c1;
    s_wsfe(&io___84);
    e_wsfe();
    s_wsfe(&io___85);
    do_fio(&c__1, (char *)&c1, (ftnlen)sizeof(doublereal));
    do_fio(&c__1, (char *)&c2, (ftnlen)sizeof(doublereal));
    e_wsfe();
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L270: */
	geovar_1.xparam[i__ - 1] = c1 * grold[i__ - 1] + c2 * xold[i__ - 1];
    }
    reactn_1.step = 0.;
    compfg_(geovar_1.xparam, &c_true, &funct1, &c_true, gradnt_1.grad, &
	    c_true);
    writmo_(&time0, &funct1);
L280:
    return 0;
} /* react1_ */

#undef idummy
#undef coord


