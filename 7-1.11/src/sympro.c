/* sympro.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal r__[1680]	/* was [14][120] */;
    integer nsym, ipo[14400]	/* was [120][120] */, nent;
} symops_;

#define symops_1 symops_

struct {
    char isymt[60];
} symopc_;

#define symopc_1 symopc_

struct {
    doublereal coord;
    integer natoms, nvar;
} atoms_;

#define atoms_1 atoms_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal coord[360]	/* was [3][120] */;
} coord_;

#define coord_1 coord_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    doublereal ha[90300];
} fokmat_;

#define fokmat_1 fokmat_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int sympop_(doublereal *h__, integer *i__, integer *iskip, 
	doublereal *deldip)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k;
    extern /* Subroutine */ int symh_(doublereal *, doublereal *, integer *, 
	    integer *);

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
    deldip -= 4;
    --h__;

    /* Function Body */
    i__1 = symops_1.nsym;
    for (j = 1; j <= i__1; ++j) {
	if (symops_1.ipo[*i__ + j * 120 - 121] < *i__) {
	    symh_(&h__[1], &deldip[4], i__, &j);
	    *iskip = 3;
/*  atom ipo(i,j) is suitable for transition dipole calc'n */

	    k = *i__ * 3 - 2;

/*   INSERT DELDIP ROTATION HERE */

	    goto L20;
	}
/* L10: */
    }
    *iskip = 0;
L20:
    return 0;
} /* sympop_ */

/* Subroutine */ int symr_(void)
{
    /* Format strings */
    static char fmt_200[] = "(\002 NOT A VALID LINE. ONLY HAS ONE ENTRY\002)";
    static char fmt_210[] = "(x,a10,i7,8i7)";
    static char fmt_220[] = "(x,a10,i7,8f7.3)";
    static char fmt_230[] = "(\002 THE SYMMETRY FUNCTION MUST BE INTEGER\002)"
	    ;
    static char fmt_240[] = "(\002 NO AXIS INFORMATION WAS ENTERED FOR FUNCT"
	    "ION\002,i2)";
    static char fmt_250[] = "(\002 YOU MUST HAVE ALL INTEGER INPUT WHEN NO"
	    "T\002,\002 USING XYZ INPUT\002)";
    static char fmt_260[] = "(\002 ATOM NUMBER\002,i3,\002 IS OUT OF RANG"
	    "E\002)";
    static char fmt_270[] = "(\002 A C-10 AXIS IS THE HIGHEST THAT CAN BE SP"
	    "ECIFIED\002)";
    static char fmt_280[] = "(\002  YOUR VECTOR AXIS MUST HAVE A NON-ZERO LE"
	    "NGTH \002)";
    static char fmt_290[] = "(\002 THIS FUNCTION IS IDENTICAL TO AN EARLIER "
	    "ONE\002)";
    static char fmt_300[] = "(\002  ONE ATOM MAPS ONTO TWO DIFFERENT ATOMI"
	    "C C\002,\002ENTERS\002)";
    static char fmt_310[] = "(\002  ONE ATOM MAPS ONTO NO OTHER ATOM \002)";
    static char fmt_320[] = "(/,10x,\002| \002,3f10.6,\002 |\002)";
    static char fmt_330[] = "(i5,\002 =   | \002,3f10.6,\002 |\002)";
    static char fmt_340[] = "(10x,\002| \002,3f10.6,\002 |\002,/)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1, d__2, d__3;
    cllist cl__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_rsfe(cilist *), do_fio(integer *, char *, ftnlen), e_rsfe(void),
	     i_dnnt(doublereal *);
    double asin(doublereal), sqrt(doublereal), cos(doublereal), sin(
	    doublereal);
    integer i_indx(char *, char *, ftnlen, ftnlen), f_clos(cllist *);
    /* Subroutine */ int s_stop(char *, ftnlen);

    /* Local variables */
    static integer i__, j, n;
    static doublereal x, y, z__, ca, cb, ra, sa, sb, xa, ya, za, xy, res, rot;
    static char line[80];
    extern /* Subroutine */ int mat33_(doublereal *, doublereal *, doublereal 
	    *);
    static logical prob;
    static doublereal dist, temp[9], reso;
    extern /* Subroutine */ int symp_(void);
    static doublereal temp2[9];
    extern doublereal reada_(char *, integer *, ftnlen);
    static doublereal sigma;
    static integer itemp[9];
    static logical leadsp, allint;
    static integer nvalue, istart[7];

    /* Fortran I/O blocks */
    static cilist io___11 = { 0, 6, 0, "(/'   SYMMETRY OPERATIONS USED FOR S"
	    "YMMETRIZING',      ' THE HESSIAN')", 0 };
    static cilist io___12 = { 0, 6, 0, "(/,' OPERATOR  TYPE     AXIS DEFINIT"
	    "ION ')", 0 };
    static cilist io___13 = { 1, 5, 1, "(A)", 0 };
    static cilist io___19 = { 0, 6, 0, fmt_200, 0 };
    static cilist io___22 = { 0, 6, 0, fmt_210, 0 };
    static cilist io___23 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___25 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___27 = { 0, 6, 0, fmt_250, 0 };
    static cilist io___28 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___29 = { 0, 6, 0, fmt_270, 0 };
    static cilist io___33 = { 0, 6, 0, fmt_280, 0 };
    static cilist io___42 = { 0, 6, 0, fmt_290, 0 };
    static cilist io___45 = { 0, 6, 0, fmt_300, 0 };
    static cilist io___46 = { 0, 6, 0, fmt_310, 0 };
    static cilist io___47 = { 0, 6, 0, fmt_320, 0 };
    static cilist io___48 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___49 = { 0, 6, 0, fmt_340, 0 };
    static cilist io___50 = { 0, 5, 1, "(A)", 0 };


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
/* **************************************************************** */

/*   ON INPUT   NONE */

/*   ON OUTPUT  R    = SYMMETRY OPERATIONS */
/*              IPO  = PERMUTATION OPERATOR FOR SYMMETRY OPERATIONS */
/*              NSYM = NUMBER OF SYMMETRY OPERATIONS */
/*              NENT = NUMBER OF SYMMETRY OPERATIONS ENTERED */

/* **************************************************************** */

/*  A SUBROUTINE THAT WILL READ IN THE PRIMATIVE SYMMETRY OPERATIONS */
/*     AND DETERMINE IF THEY ARE VALID FOR THIS MOLECULE.  THIS */
/*     INFORMATION IS THEN EXPANDED TO THE COMPLETE SET AND USED FOR */
/*     SYMMATRIZING THE HESSIAN. */

/*  THE CORRECT FORMAT FOR DESCRIBING A SYMMETRY FUNCTION IS: */
/*  LABEL  IFNCN  AXIS */

/*  WHERE: */
/*       LABEL  -  MUST BE INCLUDED AND IS THE LABEL THAT WILL */
/*                 BE USED TO IDENTIFY THAT FUNCTION */
/*       IFNCN  -  THE NUMBER OF THE SYMMETRY FUNCTION TO BE USED: */
/*                 0   -  INVERSION OPERATOR */
/*                 1   -  REFLECTION PLANE PERPENDICULAR TO THE AXIS */
/*                 2-X -  A C(N) AXIS */
/*                -3-X -  A S(N) AXIS */
/*       AXIS   -  THE AXIS FOR THE OPERATION.  MAY BE SPECIFIED AS: */
/*                 X, Y, Z COORDINATES -> MUST USE 3 VALUES.  AT LEAST ONE */
/*                     MUST BE NON-INTEGER OR TWO MUST BE IDENTICAL */
/*                 AN ATOM LIST -> THE COORDINATES OF THE ATOMS LISTED WILL */
/*                     BE SUMMED TO GENERATE THE AXIS. */
/*                 A -B ->  THE VECTOR FROM ATOM B TO ATOM A WILL BE USED AS */
/*                     THE AXIS. */

/*   A MAXIMUM OF 6 SYMMETRY OPERATIONS CAN BE INPUTTED.  THESE SHOULD BE THE */
/*      UNIQUE GENERATING FUNCTIONS FROM WHICH ALL THE OPERATIONS OF THE GROUP */
/*      CAN BE CONSTRUCTED.  E.G.  ONLY C5 NEEDS TO BE SPECIFIED SINCE C5(2) */
/*      THROUGH C5(4) CAN BE GENERATED FROM THIS SINGLE FUNCTION. */

/*   A MAXIMUM OF 8 UNIQUE ATOMS CAN BE USED TO SPECIFY AN AXIS. */

/*   THE E FUNCTION IS BY DEFAULT THE FIRST SYMMETRY FUNCTION.  THIS FUNCTION */
/*      NEVER NEEDS TO BE EXPLICTLY INCLUDED IN YOUR LIST.  IT CANNOT BE */
/*      ENTERED. */

/*   IF YOU ENTER A GIVEN SYMMETRY FUNCTION MORE THAN ONCE, ONLY THE FIRST */
/*      OCCURANCE WILL BE USED.  ALL DUPLICATES WILL BE DELETED. */

/*  THE NEXT PARAMETERS ARE THE MAX NUMBER OF SYMM FUNCTIONS, THE */
/*     MAX NUMBER OF SYMM FUNCTIONS TO READ IN, AND THE */
/*     TOLERENCE USED TO DETERMINE IF TWO FUNCTIONS ARE IDENTICAL */


/*  Variables used:  (n represents the number of atomic centers) */
/*     TEMP(9), TEMP2(9):   Temporary matricies used to hold small parts */
/*          larger matricies for specific matrix operations. */

/*    For the next two items, the last index represents the symmetry */
/*        operation number. */
/*     R(9,*):   The 9 elements of each record are a packed 3 by 3 */
/*          array of a given symmetry operations. */
/*    IPO(n,*):  A vector that contains the symmetry mapping of atomic ce */

    prob = FALSE_;
/*  Get the symmetry functions: (NOTE: THE FIRST IS ALWAY E) */
    symops_1.r__[0] = 1.;
    symops_1.r__[1] = 0.;
    symops_1.r__[2] = 0.;
    symops_1.r__[3] = 0.;
    symops_1.r__[4] = 1.;
    symops_1.r__[5] = 0.;
    symops_1.r__[6] = 0.;
    symops_1.r__[7] = 0.;
    symops_1.r__[8] = 1.;

    x = 0.;
    y = 0.;
    z__ = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x += coord_1.coord[i__ * 3 - 3];
	y += coord_1.coord[i__ * 3 - 2];
	z__ += coord_1.coord[i__ * 3 - 1];
	symops_1.ipo[i__ - 1] = i__;
/* L10: */
    }
    xa = x / (real) molkst_1.numat;
    ya = y / (real) molkst_1.numat;
    za = z__ / (real) molkst_1.numat;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	coord_1.coord[i__ * 3 - 3] = -xa + coord_1.coord[i__ * 3 - 3];
	coord_1.coord[i__ * 3 - 2] = -ya + coord_1.coord[i__ * 3 - 2];
	coord_1.coord[i__ * 3 - 1] = -za + coord_1.coord[i__ * 3 - 1];
/* L20: */
    }
    s_wsfe(&io___11);
    e_wsfe();
    s_wsfe(&io___12);
    e_wsfe();

    symops_1.nent = 1;
    symops_1.nsym = 0;
    s_copy(symopc_1.isymt, "E", (ftnlen)10, (ftnlen)1);
L30:
    ++symops_1.nsym;
    i__1 = s_rsfe(&io___13);
    if (i__1 != 0) {
	goto L120;
    }
    i__1 = do_fio(&c__1, line, (ftnlen)80);
    if (i__1 != 0) {
	goto L120;
    }
    i__1 = e_rsfe();
    if (i__1 != 0) {
	goto L120;
    }
    leadsp = TRUE_;
    nvalue = 0;
    allint = TRUE_;
    for (i__ = 1; i__ <= 80; ++i__) {
	if (leadsp && *(unsigned char *)&line[i__ - 1] != ' ') {
	    ++nvalue;
	    istart[nvalue - 1] = i__;
	}
	leadsp = *(unsigned char *)&line[i__ - 1] == ' ';
/* L40: */
    }
    if (nvalue == 0) {
	goto L120;
    }
    if (nvalue == 1) {
	s_wsfe(&io___19);
	e_wsfe();
	prob = TRUE_;
	goto L120;
    }
    i__1 = istart[0] - 1;
    s_copy(symopc_1.isymt + symops_1.nent * 10, line + i__1, (ftnlen)10, 
	    istart[1] - 1 - i__1);
    i__1 = nvalue;
    for (i__ = 2; i__ <= i__1; ++i__) {
	temp[i__ - 2] = reada_(line, &istart[i__ - 1], (ftnlen)80);
	itemp[i__ - 2] = i_dnnt(&temp[i__ - 2]);
	if ((d__1 = itemp[i__ - 2] - temp[i__ - 2], abs(d__1)) > .001 && i__ 
		!= 2) {
	    allint = FALSE_;
	}
/* L50: */
    }
    if (allint) {
	s_wsfe(&io___22);
	do_fio(&c__1, symopc_1.isymt + symops_1.nent * 10, (ftnlen)10);
	i__1 = nvalue - 1;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&itemp[i__ - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
    } else {
	s_wsfe(&io___23);
	do_fio(&c__1, symopc_1.isymt + symops_1.nent * 10, (ftnlen)10);
	do_fio(&c__1, (char *)&itemp[0], (ftnlen)sizeof(integer));
	i__1 = nvalue - 1;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    do_fio(&c__1, (char *)&temp[i__ - 1], (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }
    sigma = 1.;
    if (itemp[0] <= -3) {
	sigma = -1.;
    }
    temp[0] = abs(temp[0]);
    itemp[0] = abs(itemp[0]);
    if ((d__1 = itemp[0] - temp[0], abs(d__1)) >= .001) {
	s_wsfe(&io___25);
	e_wsfe();
	prob = TRUE_;
	goto L120;
    }
    if (itemp[0] == 0) {
/*  WITH INVERSION, THE AXIS IS UNIMPORTANT */
	symops_1.r__[(symops_1.nent + 1) * 14 - 14] = -1.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 13] = 0.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 12] = 0.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 11] = 0.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 10] = -1.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 9] = 0.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 8] = 0.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 7] = 0.;
	symops_1.r__[(symops_1.nent + 1) * 14 - 6] = -1.;
	goto L70;
    }
/*  WITH ANYTHING ELSE, THE AXIS MUST BE DETERMINED.  IF NO AXIS IS DEFINED */
/*    FLAG IT AS A PROBLEM */
    if (nvalue == 2) {
	prob = TRUE_;
	s_wsfe(&io___26);
	do_fio(&c__1, (char *)&symops_1.nsym, (ftnlen)sizeof(integer));
	e_wsfe();
	goto L120;
    }
    if (nvalue == 5 && (temp[1] == temp[2] || temp[1] == temp[3] || temp[2] ==
	     temp[3] || ! allint || abs(itemp[1]) < 1 || abs(itemp[1]) > 
	    molkst_1.numat || abs(itemp[2]) < 1 || abs(itemp[2]) > 
	    molkst_1.numat || abs(itemp[3]) < 1 || abs(itemp[3]) > 
	    molkst_1.numat)) {
/*  IT APPEARS TO BE XYZ INPUT */
	x = temp[1];
	y = temp[2];
	z__ = temp[3];
    } else {
/*  APPEARS TO BE ATOM NUMBER INPUT */
	if (! allint) {
	    prob = TRUE_;
	    s_wsfe(&io___27);
	    e_wsfe();
	    goto L120;
	}
	x = 0.;
	y = 0.;
	z__ = 0.;
	i__1 = nvalue - 1;
	for (i__ = 2; i__ <= i__1; ++i__) {
	    if ((i__2 = itemp[i__ - 1], abs(i__2)) < 1 || (i__3 = itemp[i__ - 
		    1], abs(i__3)) > molkst_1.numat) {
		s_wsfe(&io___28);
		do_fio(&c__1, (char *)&itemp[i__ - 1], (ftnlen)sizeof(integer)
			);
		e_wsfe();
		prob = TRUE_;
	    }
	    x += itemp[i__ - 1] / (i__2 = itemp[i__ - 1], abs(i__2)) * 
		    coord_1.coord[(i__3 = itemp[i__ - 1], abs(i__3)) * 3 - 3];
	    y += itemp[i__ - 1] / (i__2 = itemp[i__ - 1], abs(i__2)) * 
		    coord_1.coord[(i__3 = itemp[i__ - 1], abs(i__3)) * 3 - 2];
	    z__ += itemp[i__ - 1] / (i__2 = itemp[i__ - 1], abs(i__2)) * 
		    coord_1.coord[(i__3 = itemp[i__ - 1], abs(i__3)) * 3 - 1];
/* L60: */
	}
    }

/*  TIME TO DECIPHER THE SYMMETRY FUNCTION */

    if (itemp[0] > 10) {
	s_wsfe(&io___29);
	e_wsfe();
	prob = TRUE_;
	goto L120;
    }
    rot = asin(1.) * 4. / itemp[0];
    if (itemp[0] == 1) {
	sigma = -1.;
    }

/*  First, construct the matrix defining the rotation axis */
/* Computing 2nd power */
    d__1 = x;
/* Computing 2nd power */
    d__2 = y;
    xy = d__1 * d__1 + d__2 * d__2;
/* Computing 2nd power */
    d__1 = z__;
    ra = sqrt(xy + d__1 * d__1);
    if (ra < .001) {
	prob = TRUE_;
	s_wsfe(&io___33);
	e_wsfe();
	goto L120;
    }
    xy = sqrt(xy);
    if (xy > 1e-10) {
	ca = y / xy;
	cb = z__ / ra;
	sa = x / xy;
	sb = xy / ra;
    } else if (z__ > 0.) {
	ca = 1.;
	cb = 1.;
	sa = 0.;
	sb = 0.;
    } else {
	ca = -1.;
	cb = -1.;
	sa = 0.;
	sb = 0.;
    }
/*  GENERATE THE MATRIX ELEMENTS BY DOING THE EULER TRANSFORM */
    temp[0] = ca;
    temp[1] = -sa;
    temp[2] = 0.;
    temp[3] = sa * cb;
    temp[4] = ca * cb;
    temp[5] = -sb;
    temp[6] = sa * sb;
    temp[7] = ca * sb;
    temp[8] = cb;


    ca = cos(rot);
    sa = sin(rot);

/*  The construct the actual R matrix to be used */


    temp2[0] = ca;
    temp2[1] = sa;
    temp2[2] = 0.;
    temp2[3] = -sa;
    temp2[4] = ca;
    temp2[5] = 0.;
    temp2[6] = 0.;
    temp2[7] = 0.;
    temp2[8] = sigma;
    mat33_(temp, temp2, &symops_1.r__[(symops_1.nent + 1) * 14 - 14]);

/*  Now, verify that this is a unique and valid function */
L70:

    res = 10.;
    i__1 = symops_1.nent;
    for (i__ = 2; i__ <= i__1; ++i__) {
	reso = 0.;
	for (j = 1; j <= 9; ++j) {
/* L80: */
	    reso = (d__1 = symops_1.r__[j + i__ * 14 - 15] - symops_1.r__[j + 
		    (symops_1.nent + 1) * 14 - 15], abs(d__1)) + reso;
	}
	res = min(res,reso);
/* L90: */
    }
    if (res < .001) {
/*  THIS IS NOT VALID FUNCTION */
	s_wsfe(&io___42);
	e_wsfe();
	goto L120;
    }
/*  NOW, TO CALCULATE THE IPO OF THIS FUNCTION */
    ++symops_1.nent;
    n = symops_1.nent;
/*  Now, to initialize IPO(n) and */
/*  Perform R on each atomic center and determine where it maps to. */
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	x = coord_1.coord[i__ * 3 - 3] * symops_1.r__[n * 14 - 14] + 
		coord_1.coord[i__ * 3 - 2] * symops_1.r__[n * 14 - 13] + 
		coord_1.coord[i__ * 3 - 1] * symops_1.r__[n * 14 - 12];
	y = coord_1.coord[i__ * 3 - 3] * symops_1.r__[n * 14 - 11] + 
		coord_1.coord[i__ * 3 - 2] * symops_1.r__[n * 14 - 10] + 
		coord_1.coord[i__ * 3 - 1] * symops_1.r__[n * 14 - 9];
	z__ = coord_1.coord[i__ * 3 - 3] * symops_1.r__[n * 14 - 8] + 
		coord_1.coord[i__ * 3 - 2] * symops_1.r__[n * 14 - 7] + 
		coord_1.coord[i__ * 3 - 1] * symops_1.r__[n * 14 - 6];
	symops_1.ipo[i__ + n * 120 - 121] = 0;
	i__2 = molkst_1.numat;
	for (j = 1; j <= i__2; ++j) {
	    dist = (d__1 = x - coord_1.coord[j * 3 - 3], abs(d__1)) + (d__2 = 
		    y - coord_1.coord[j * 3 - 2], abs(d__2)) + (d__3 = z__ - 
		    coord_1.coord[j * 3 - 1], abs(d__3));
	    if (dist < .05) {
		if (symops_1.ipo[i__ + n * 120 - 121] == 0) {
		    symops_1.ipo[i__ + n * 120 - 121] = j;
		} else {
		    s_wsfe(&io___45);
		    e_wsfe();
		    prob = TRUE_;
		    goto L120;
		}
	    }
/* L100: */
	}
	if (symops_1.ipo[i__ + n * 120 - 121] == 0) {
	    s_wsfe(&io___46);
	    e_wsfe();
	    prob = TRUE_;
	    goto L120;
	}
/* L110: */
    }

/*  IF THIS POINT IS REACHED, THE FUNCTION IS VALID */
/*  CHECK IF THE R MATRIX SHOULD BE PRINTED */

    if (i_indx(keywrd_1.keywrd, " RMAT", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___47);
	for (i__ = 1; i__ <= 3; ++i__) {
	    do_fio(&c__1, (char *)&symops_1.r__[i__ + n * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___48);
	do_fio(&c__1, (char *)&n, (ftnlen)sizeof(integer));
	for (i__ = 4; i__ <= 6; ++i__) {
	    do_fio(&c__1, (char *)&symops_1.r__[i__ + n * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___49);
	for (i__ = 7; i__ <= 9; ++i__) {
	    do_fio(&c__1, (char *)&symops_1.r__[i__ + n * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	e_wsfe();
    }

L120:
    if (nvalue != 0 && symops_1.nsym < 6) {
	goto L30;
    }

/*  If a problem exists.  Stop the program. */

    if (prob) {
	cl__1.cerr = 0;
	cl__1.cunit = 6;
	cl__1.csta = 0;
	f_clos(&cl__1);
	s_stop("PROBLEM IN SYMR", (ftnlen)15);
    }

/*  NOW, ALL USER FUNCTIONS ARE IN WITH NO ERRORS (JUST ELIMINATION OF DUPS) */

    if (nvalue != 0) {
	i__1 = s_rsfe(&io___50);
	if (i__1 != 0) {
	    goto L130;
	}
	i__1 = do_fio(&c__1, line, (ftnlen)80);
	if (i__1 != 0) {
	    goto L130;
	}
	i__1 = e_rsfe();
	if (i__1 != 0) {
	    goto L130;
	}
    }
L130:
    symops_1.nsym = symops_1.nent;

/*  NEXT, EXPAND THE EXISTING OPERATORS TO THE FULL SET */

    symp_();

    return 0;
} /* symr_ */

/* Subroutine */ int symh_(doublereal *h__, doublereal *dip, integer *i__, 
	integer *n)
{
    /* System generated locals */
    integer i__1;

    /* Local variables */
    static integer j, k, l;
    static doublereal fact;
    static integer iel33;
    extern /* Subroutine */ int mat33_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal temp[9], temp2[9];
    static integer istart;

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
/* **************************************************************** */

/*  INPUT:   H()   A packed lower triangular hessian */
/*           DIP(,) A MATRIX OF DIPOLE TENSORS TO BE SYMM */
/*           R(,)  A matrix of symmetry operations */
/*           IPO(,) A matrix of atomic mapping according to R */
/*           I     The atom (row and column) to add to H() */
/*           N     The symmetry operation to use to generate I */

/*  OUTPUT:  H()   A packed lower triangular Hessian with information */
/*                   about atom I added */
/*           DIP(,) A MATRIX OF DIPOLE TENSORS THAT HAVE BEEN SYMM */

/* **************************************************************** */


/*  This subroutine will add all necessary information to the Hessian con */
/*    atom I.  Since the Hessian is a packed lower half triangle, the exi */
/*    information for atom pair (K,L) where K,L < I is fully known, (K > */
/*    L < I) or (vice versa) is half known, K,L > I is completely unknown */
/*    Therefore, start in unknown region and make it half known.  Double */
/*    known values, and move in the diagonal element at full strength. */





/*  Variables used:  (n represents the number of atomic centers) */
/*     H(3n,3n):  Input/output matrix.  It is a packed lower half triangu */
/*        matrix.  Commonly, the Hessian. */
/*     TEMP(9), TEMP2(9):   Temporary matricies used to hold small parts */
/*          larger matricies for specific matrix operations. */

/*    For the next two items, the last indicy represents the symmetry */
/*        operation number. */
/*     R(14,*):   The first 9 elements of each record are a packed 3 by 3 */
/*          array of a given symmetry operations.  Elements 10 - 14 are t */
/*          users input describing the symmetry operation. */
/*     IPO(n,*):  A vector that contains the symmetry mapping of atomic c */


    /* Parameter adjustments */
    dip -= 4;
    --h__;

    /* Function Body */
    k = symops_1.ipo[*i__ + *n * 120 - 121];

/*  Now, to climb up the matrix */
    i__1 = *i__ + 1;
    for (j = molkst_1.numat; j >= i__1; --j) {
	l = symops_1.ipo[j + *n * 120 - 121];

/*  Now, to actually perform R H R */

/*  Do this multiplication in a 3 by 3 block at a time.  Store H(i,j) in */
/*    H( IPO(I,N), IPO(J,N)) */

	if (k > l) {
	    iel33 = k * 3 * (k * 3 - 1) / 2 + l * 3;
	    temp[8] = h__[iel33] * .5;
	    temp[7] = h__[iel33 - 1] * .5;
	    temp[6] = h__[iel33 - 2] * .5;
	    temp[5] = h__[iel33 - k * 3 + 1] * .5;
	    temp[4] = h__[iel33 - k * 3] * .5;
	    temp[3] = h__[iel33 - k * 3 - 1] * .5;
	    temp[2] = h__[iel33 - k * 6 + 3] * .5;
	    temp[1] = h__[iel33 - k * 6 + 2] * .5;
	    temp[0] = h__[iel33 - k * 6 + 1] * .5;
	} else {
	    iel33 = l * 3 * (l * 3 - 1) / 2 + k * 3;
	    fact = 1.;
	    if (l < *i__) {
		fact = .5;
	    }
	    temp[8] = fact * h__[iel33];
	    temp[5] = fact * h__[iel33 - 1];
	    temp[2] = fact * h__[iel33 - 2];
	    temp[7] = fact * h__[iel33 - l * 3 + 1];
	    temp[4] = fact * h__[iel33 - l * 3];
	    temp[1] = fact * h__[iel33 - l * 3 - 1];
	    temp[6] = fact * h__[iel33 - l * 6 + 3];
	    temp[3] = fact * h__[iel33 - l * 6 + 2];
	    temp[0] = fact * h__[iel33 - l * 6 + 1];
	}

	mat33_(&symops_1.r__[*n * 14 - 14], temp, temp2);

	iel33 = j * 3 * (j * 3 - 1) / 2 + *i__ * 3;
	h__[iel33] = temp2[8];
	h__[iel33 - j * 3 + 1] = temp2[7];
	h__[iel33 - j * 6 + 3] = temp2[6];
	h__[iel33 - 1] = temp2[5];
	h__[iel33 - j * 3] = temp2[4];
	h__[iel33 - j * 6 + 2] = temp2[3];
	h__[iel33 - 2] = temp2[2];
	h__[iel33 - j * 3 - 1] = temp2[1];
	h__[iel33 - j * 6 + 1] = temp2[0];
/* L10: */
    }

/*  Now, to do the diagonal term */

    iel33 = k * 3 * (k * 3 + 1) / 2;
    temp[8] = h__[iel33] * .5;
    temp[7] = h__[iel33 - 1] * .5;
    temp[6] = h__[iel33 - 2] * .5;
    temp[5] = temp[7];
    temp[4] = h__[iel33 - k * 3] * .5;
    temp[3] = h__[iel33 - k * 3 - 1] * .5;
    temp[2] = temp[6];
    temp[1] = temp[3];
    temp[0] = h__[iel33 - k * 6 + 1] * .5;

    mat33_(&symops_1.r__[*n * 14 - 14], temp, temp2);

    iel33 = *i__ * 3 * (*i__ * 3 + 1) / 2;
    h__[iel33] = temp2[8];
    h__[iel33 - 1] = temp2[7];
    h__[iel33 - 2] = temp2[6];
    h__[iel33 - *i__ * 3] = temp2[4];
    h__[iel33 - *i__ * 3 - 1] = temp2[3];
    h__[iel33 - *i__ * 6 + 1] = temp2[0];

/*   NOW, TO ROTATE THE DIPOLE TENSOR TERM */

    temp[8] = dip[k * 9 + 3];
    temp[7] = dip[k * 9 + 2];
    temp[6] = dip[k * 9 + 1];
    temp[5] = dip[(k * 3 - 1) * 3 + 3];
    temp[4] = dip[(k * 3 - 1) * 3 + 2];
    temp[3] = dip[(k * 3 - 1) * 3 + 1];
    temp[2] = dip[(k * 3 - 2) * 3 + 3];
    temp[1] = dip[(k * 3 - 2) * 3 + 2];
    temp[0] = dip[(k * 3 - 2) * 3 + 1];

    mat33_(&symops_1.r__[*n * 14 - 14], temp, temp2);

    dip[*i__ * 9 + 3] = temp2[8];
    dip[*i__ * 9 + 2] = temp2[7];
    dip[*i__ * 9 + 1] = temp2[6];
    dip[(*i__ * 3 - 1) * 3 + 3] = temp2[5];
    dip[(*i__ * 3 - 1) * 3 + 2] = temp2[4];
    dip[(*i__ * 3 - 1) * 3 + 1] = temp2[3];
    dip[(*i__ * 3 - 2) * 3 + 3] = temp2[2];
    dip[(*i__ * 3 - 2) * 3 + 2] = temp2[1];
    dip[(*i__ * 3 - 2) * 3 + 1] = temp2[0];


/*   Now, to double all existing values going across */
    istart = (*i__ - 1) * 3 * ((*i__ - 1) * 3 + 1) / 2 + 1;
    i__1 = iel33;
    for (j = istart; j <= i__1; ++j) {
	h__[j] += h__[j];
/* L20: */
    }
/*  Everything is now done for this symmetry element. */

    return 0;
} /* symh_ */

/* Subroutine */ int syma_(doublereal *e, doublereal *v)
{
    /* Format strings */
    static char fmt_100[] = "(\002  FREQ.\002,/,\002  NO.   FREQ.         CH"
	    "ARACTER TABLE \002)";
    static char fmt_130[] = "(i4,f9.3,3x,7f9.4)";

    /* System generated locals */
    integer i__1, i__2, i__3;
    doublereal d__1;

    /* Builtin functions */
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen),
	     i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, n;
    static doublereal t1[360], t2[2520]	/* was [360][7] */, tol, eref;
    static integer nvar;

    /* Fortran I/O blocks */
    static cilist io___67 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___68 = { 0, 6, 0, "('                    ',7A9)", 0 };
    static cilist io___70 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___71 = { 0, 6, 0, fmt_130, 0 };


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
/* ******************************************************************** */

/*  ON INPUT E    = FREQUENCIES IN CM(-1) */
/*           V    = EIGENVECTORS OF NORMAL MODES, NORMALIZED */
/*           R    = SYMMETRY OPERATIONS */
/*           IPO  = MAP OF ATOMS BEING MOVED */
/*           NSYM = NUMBER OF SYMMETRY OPERATION */

/* ******************************************************************** */

/*  THIS SUBROUTINE DETERMINES THE SYMMETRY FUNCTION VALUE OF EACH */
/*    VIBRATIONAL MODE.  IT DOES IT BY DOING <EV R EV> */


    /* Parameter adjustments */
    --v;
    --e;

    /* Function Body */
    tol = .001;

    nvar = molkst_1.numat * 3;

/*  T1(NVAR) AND T2(NVAR,NSYM) ARE THE ONLY ADDITIONAL ARRAYS NEEDED.  TH */
/*    ARE TEMPORARY ARRAYS. */
    i__1 = nvar - 1;
    for (k = 0; k <= i__1; ++k) {
	i__2 = symops_1.nent;
	for (n = 1; n <= i__2; ++n) {
	    i__3 = molkst_1.numat;
	    for (i__ = 1; i__ <= i__3; ++i__) {

		j = symops_1.ipo[i__ + n * 120 - 121];
		t1[i__ * 3 - 3] = v[j * 3 - 2 + k * nvar] * symops_1.r__[n * 
			14 - 14] + v[j * 3 - 1 + k * nvar] * symops_1.r__[n * 
			14 - 11] + v[j * 3 + k * nvar] * symops_1.r__[n * 14 
			- 8];
		t1[i__ * 3 - 2] = v[j * 3 - 2 + k * nvar] * symops_1.r__[n * 
			14 - 13] + v[j * 3 - 1 + k * nvar] * symops_1.r__[n * 
			14 - 10] + v[j * 3 + k * nvar] * symops_1.r__[n * 14 
			- 7];
		t1[i__ * 3 - 1] = v[j * 3 - 2 + k * nvar] * symops_1.r__[n * 
			14 - 12] + v[j * 3 - 1 + k * nvar] * symops_1.r__[n * 
			14 - 9] + v[j * 3 + k * nvar] * symops_1.r__[n * 14 - 
			6];
/* L10: */
	    }
	    t2[k + 1 + n * 360 - 361] = 0.;
	    i__3 = nvar;
	    for (i__ = 1; i__ <= i__3; ++i__) {
		t2[k + 1 + n * 360 - 361] += t1[i__ - 1] * v[i__ + k * nvar];
/* L20: */
	    }
	}
/* L30: */
    }
    s_wsfe(&io___67);
    e_wsfe();
    s_wsfe(&io___68);
    i__1 = symops_1.nent;
    for (i__ = 1; i__ <= i__1; ++i__) {
	do_fio(&c__1, symopc_1.isymt + (i__ - 1) * 10, (ftnlen)10);
    }
    e_wsfe();
    i__ = 1;
    j = i__ + 1;
    if (i_indx(keywrd_1.keywrd, " NODEGEN", (ftnlen)241, (ftnlen)8) != 0) {
	tol = -1.;
    }
    eref = e[1];
L110:
    if ((d__1 = e[j] - eref, abs(d__1)) <= tol) {
	i__1 = symops_1.nent;
	for (k = 1; k <= i__1; ++k) {
/* L120: */
	    t2[i__ + k * 360 - 361] += t2[j + k * 360 - 361];
	}
	e[i__] += e[j];
	++j;
    } else {
	e[i__] /= (real) (j - i__);
	s_wsfe(&io___70);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&e[i__], (ftnlen)sizeof(doublereal));
	i__1 = symops_1.nent;
	for (k = 1; k <= i__1; ++k) {
	    do_fio(&c__1, (char *)&t2[i__ + k * 360 - 361], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
	i__ = j;
	++j;
	eref = e[i__];
    }
    if (j <= nvar) {
	goto L110;
    }
    e[i__] /= (real) (j - i__);
    s_wsfe(&io___71);
    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
    do_fio(&c__1, (char *)&e[i__], (ftnlen)sizeof(doublereal));
    i__1 = symops_1.nent;
    for (k = 1; k <= i__1; ++k) {
	do_fio(&c__1, (char *)&t2[i__ + k * 360 - 361], (ftnlen)sizeof(
		doublereal));
    }
    e_wsfe();
    return 0;
} /* syma_ */

/* Subroutine */ int symt_(doublereal *h__, doublereal *deldip)
{
    /* System generated locals */
    integer i__1, i__2, i__3;

    /* Local variables */
    static integer i__, j, k, l, n, iel33;
    extern /* Subroutine */ int mat33_(doublereal *, doublereal *, doublereal 
	    *);
    static doublereal temp[9], temp2[9], deltmp[1080]	/* was [3][360] */;

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
/* **************************************************************** */

/*   ON INPUT   H    = HESSIAN MATRIX, PACKED LOWER HALF TRIANGLE */
/*              R    = SYMMETRY OPERATIONS */
/*              IPO  = MAP OF ATOMS MOVED */
/*              NSYM = NUMBER OF SYMMETRY OPERATIONS */

/*   ON OUTPUT  H    = SYMMETRIZED HESSIAN MATRIX */

/* **************************************************************** */
/*  A subroutine that will symmatrize the Hamiltonian, or other matrix */
/*     by successive application of group operations.  The method used */
/*     is R H R  added to HA then divided by the total number of symmetry */
/*     operations used.  This in effects averages all the values in a */
/*     symmetry correct fashion. */



/*  Variables used:  (n represents the number of atomic centers) */
/*     H(3n,3n):  Input/output matrix.  It is a packed lower half triangu */
/*        matrix.  Commonly, the Hessian. */
/*     HA(3n,3n): An internal matrix used to sum the symatrized Hessian */
/*     NSYM:      Input, the value of this symmetry operation. */
/*     TEMP(9), TEMP2(9):   Temporary matricies used to hold small parts */
/*          larger matricies for specific matrix operations. */

/*    For the next two items, the last indicy represents the symmetry */
/*        operation number. */
/*     IPO(n,*):  A vector that contains the symmetry mapping of atomic c */

/*   Skip this subroutine if NSYMM <= 0.  This implies that only E is pre */
    /* Parameter adjustments */
    deldip -= 4;
    --h__;

    /* Function Body */
    if (symops_1.nsym < 2) {
	return 0;
    }

    i__1 = molkst_1.numat * 3 * (molkst_1.numat * 3 + 1) / 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	fokmat_1.ha[i__ - 1] = 0.;
    }

    i__1 = molkst_1.numat * 3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	deltmp[i__ * 3 - 3] = 0.;
	deltmp[i__ * 3 - 2] = 0.;
/* L15: */
	deltmp[i__ * 3 - 1] = 0.;
    }

    i__1 = symops_1.nsym;
    for (n = 1; n <= i__1; ++n) {

/*  Now, to actually perform R H R */
	i__2 = molkst_1.numat;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    i__3 = i__ - 1;
	    for (j = 1; j <= i__3; ++j) {

/*  Do this multiplication in a 3 by 3 block at a time.  Store H(i,j) in */
/*    HA( IPO(I,N), IPO(J,N)) or HS( IPO(I,N), IPO(J,N)) */

		k = symops_1.ipo[i__ + n * 120 - 121];
		l = symops_1.ipo[j + n * 120 - 121];
		if (k > l) {
		    iel33 = k * 3 * (k * 3 - 1) / 2 + l * 3;
		    temp[8] = h__[iel33];
		    temp[7] = h__[iel33 - 1];
		    temp[6] = h__[iel33 - 2];
		    temp[5] = h__[iel33 - k * 3 + 1];
		    temp[4] = h__[iel33 - k * 3];
		    temp[3] = h__[iel33 - k * 3 - 1];
		    temp[2] = h__[iel33 - k * 6 + 3];
		    temp[1] = h__[iel33 - k * 6 + 2];
		    temp[0] = h__[iel33 - k * 6 + 1];
		} else {
		    iel33 = l * 3 * (l * 3 - 1) / 2 + k * 3;
		    temp[8] = h__[iel33];
		    temp[5] = h__[iel33 - 1];
		    temp[2] = h__[iel33 - 2];
		    temp[7] = h__[iel33 - l * 3 + 1];
		    temp[4] = h__[iel33 - l * 3];
		    temp[1] = h__[iel33 - l * 3 - 1];
		    temp[6] = h__[iel33 - l * 6 + 3];
		    temp[3] = h__[iel33 - l * 6 + 2];
		    temp[0] = h__[iel33 - l * 6 + 1];
		}

		mat33_(&symops_1.r__[n * 14 - 14], temp, temp2);

		iel33 = i__ * 3 * (i__ * 3 - 1) / 2 + j * 3;
		fokmat_1.ha[iel33 - 1] = temp2[8] + fokmat_1.ha[iel33 - 1];
		fokmat_1.ha[iel33 - 2] = temp2[7] + fokmat_1.ha[iel33 - 2];
		fokmat_1.ha[iel33 - 3] = temp2[6] + fokmat_1.ha[iel33 - 3];
		fokmat_1.ha[iel33 - i__ * 3] = temp2[5] + fokmat_1.ha[iel33 - 
			i__ * 3];
		fokmat_1.ha[iel33 - i__ * 3 - 1] = temp2[4] + fokmat_1.ha[
			iel33 - i__ * 3 - 1];
		fokmat_1.ha[iel33 - i__ * 3 - 2] = temp2[3] + fokmat_1.ha[
			iel33 - i__ * 3 - 2];
		fokmat_1.ha[iel33 - i__ * 6 + 2] = temp2[2] + fokmat_1.ha[
			iel33 - i__ * 6 + 2];
		fokmat_1.ha[iel33 - i__ * 6 + 1] = temp2[1] + fokmat_1.ha[
			iel33 - i__ * 6 + 1];
		fokmat_1.ha[iel33 - i__ * 6] = temp2[0] + fokmat_1.ha[iel33 - 
			i__ * 6];
/* L20: */
	    }
	    k = symops_1.ipo[i__ + n * 120 - 121];
	    iel33 = k * 3 * (k * 3 + 1) / 2;
	    temp[8] = h__[iel33];
	    temp[7] = h__[iel33 - 1];
	    temp[6] = h__[iel33 - 2];
	    temp[5] = temp[7];
	    temp[4] = h__[iel33 - k * 3];
	    temp[3] = h__[iel33 - k * 3 - 1];
	    temp[2] = temp[6];
	    temp[1] = temp[3];
	    temp[0] = h__[iel33 - k * 6 + 1];

	    mat33_(&symops_1.r__[n * 14 - 14], temp, temp2);

	    iel33 = i__ * 3 * (i__ * 3 + 1) / 2;
	    fokmat_1.ha[iel33 - 1] = temp2[8] + fokmat_1.ha[iel33 - 1];
	    fokmat_1.ha[iel33 - 2] = temp2[7] + fokmat_1.ha[iel33 - 2];
	    fokmat_1.ha[iel33 - 3] = temp2[6] + fokmat_1.ha[iel33 - 3];
	    fokmat_1.ha[iel33 - i__ * 3 - 1] = temp2[4] + fokmat_1.ha[iel33 - 
		    i__ * 3 - 1];
	    fokmat_1.ha[iel33 - i__ * 3 - 2] = temp2[3] + fokmat_1.ha[iel33 - 
		    i__ * 3 - 2];
	    fokmat_1.ha[iel33 - i__ * 6] = temp2[0] + fokmat_1.ha[iel33 - i__ 
		    * 6];

/*  APPLY SYMMETRY TO DIPOLE TERM AS WELL */

	    temp[8] = deldip[k * 9 + 3];
	    temp[7] = deldip[k * 9 + 2];
	    temp[6] = deldip[k * 9 + 1];
	    temp[5] = deldip[(k * 3 - 1) * 3 + 3];
	    temp[4] = deldip[(k * 3 - 1) * 3 + 2];
	    temp[3] = deldip[(k * 3 - 1) * 3 + 1];
	    temp[2] = deldip[(k * 3 - 2) * 3 + 3];
	    temp[1] = deldip[(k * 3 - 2) * 3 + 2];
	    temp[0] = deldip[(k * 3 - 2) * 3 + 1];

	    mat33_(&symops_1.r__[n * 14 - 14], temp, temp2);

	    deltmp[i__ * 9 - 1] = temp2[8] + deltmp[i__ * 9 - 1];
	    deltmp[i__ * 9 - 2] = temp2[7] + deltmp[i__ * 9 - 2];
	    deltmp[i__ * 9 - 3] = temp2[6] + deltmp[i__ * 9 - 3];
	    deltmp[(i__ * 3 - 1) * 3 - 1] = temp2[5] + deltmp[(i__ * 3 - 1) * 
		    3 - 1];
	    deltmp[(i__ * 3 - 1) * 3 - 2] = temp2[4] + deltmp[(i__ * 3 - 1) * 
		    3 - 2];
	    deltmp[(i__ * 3 - 1) * 3 - 3] = temp2[3] + deltmp[(i__ * 3 - 1) * 
		    3 - 3];
	    deltmp[(i__ * 3 - 2) * 3 - 1] = temp2[2] + deltmp[(i__ * 3 - 2) * 
		    3 - 1];
	    deltmp[(i__ * 3 - 2) * 3 - 2] = temp2[1] + deltmp[(i__ * 3 - 2) * 
		    3 - 2];
	    deltmp[(i__ * 3 - 2) * 3 - 3] = temp2[0] + deltmp[(i__ * 3 - 2) * 
		    3 - 3];

/* L30: */
	}
/* L40: */
    }

    i__1 = molkst_1.numat * 3 * (molkst_1.numat * 3 + 1) / 2;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L50: */
	h__[i__] = fokmat_1.ha[i__ - 1] / symops_1.nsym;
    }

    i__1 = molkst_1.numat * 3;
    for (i__ = 1; i__ <= i__1; ++i__) {
	deldip[i__ * 3 + 1] = deltmp[i__ * 3 - 3] / symops_1.nsym;
	deldip[i__ * 3 + 2] = deltmp[i__ * 3 - 2] / symops_1.nsym;
/* L60: */
	deldip[i__ * 3 + 3] = deltmp[i__ * 3 - 1] / symops_1.nsym;
    }

    return 0;
} /* symt_ */

/* Subroutine */ int mat33_(doublereal *a, doublereal *b, doublereal *c__)
{
    static doublereal t[9];

/*  A subroutine that will multiply two 3 by 3 matricies in the following */
/*     fashion:    C = A(transpose) B A */



    /* Parameter adjustments */
    --c__;
    --b;
    --a;

    /* Function Body */
    t[0] = b[1] * a[1] + b[2] * a[4] + b[3] * a[7];
    t[1] = b[1] * a[2] + b[2] * a[5] + b[3] * a[8];
    t[2] = b[1] * a[3] + b[2] * a[6] + b[3] * a[9];
    t[3] = b[4] * a[1] + b[5] * a[4] + b[6] * a[7];
    t[4] = b[4] * a[2] + b[5] * a[5] + b[6] * a[8];
    t[5] = b[4] * a[3] + b[5] * a[6] + b[6] * a[9];
    t[6] = b[7] * a[1] + b[8] * a[4] + b[9] * a[7];
    t[7] = b[7] * a[2] + b[8] * a[5] + b[9] * a[8];
    t[8] = b[7] * a[3] + b[8] * a[6] + b[9] * a[9];

    c__[1] = a[1] * t[0] + a[4] * t[3] + a[7] * t[6];
    c__[2] = a[1] * t[1] + a[4] * t[4] + a[7] * t[7];
    c__[3] = a[1] * t[2] + a[4] * t[5] + a[7] * t[8];
    c__[4] = a[2] * t[0] + a[5] * t[3] + a[8] * t[6];
    c__[5] = a[2] * t[1] + a[5] * t[4] + a[8] * t[7];
    c__[6] = a[2] * t[2] + a[5] * t[5] + a[8] * t[8];
    c__[7] = a[3] * t[0] + a[6] * t[3] + a[9] * t[6];
    c__[8] = a[3] * t[1] + a[6] * t[4] + a[9] * t[7];
    c__[9] = a[3] * t[2] + a[6] * t[5] + a[9] * t[8];

    return 0;
} /* mat33_ */

/* Subroutine */ int symp_(void)
{
    /* Format strings */
    static char fmt_100[] = "(/,\002 ENTERING THE SYMMETRY GENERATING ROUTIN"
	    "E \002,/,\002    NUMBER  SYMM. OPER.   * \002,\002   NUMBER  SYM"
	    "M. OPER.   = \002,\002   NUMBER  SYMM. OPER.\002)";
    static char fmt_110[] = "(8x,i3,6x,a5,4x,\002*\002,8x,i3,6x,a5,4x,\002"
	    "=\002,8x,i3,6x,a5)";
    static char fmt_120[] = "(\002 |\002,3f7.3,\002 |   |\002,3f7.3,\002 |  "
	    " |\002,3f7.3,\002 |\002)";
    static char fmt_130[] = "(\002 |\002,3f7.3,\002 | * |\002,3f7.3,\002 | ="
	    " |\002,3f7.3,\002 |\002)";
    static char fmt_140[] = "(\002 |\002,3f7.3,\002 |   |\002,3f7.3,\002 |  "
	    " |\002,3f7.3,\002 |\002,/)";
    static char fmt_150[] = "(/,\002 THERE ARE \002,i3,\002 UNIQUE SYMMETRY "
	    "FUNCTIONS.\002,/)";
    static char fmt_160[] = "(/,20x,\002THE PERMUTATION MATRIX\002)";
    static char fmt_170[] = "(/,/,5x,\002OPER. NO. \002,12i5)";
    static char fmt_175[] = "(5x,\002SYMM. OPER. \002,12a5)";
    static char fmt_180[] = "(5x,\002ATOM NO.\002)";
    static char fmt_190[] = "(i10,5x,12i5)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1;
    char ch__1[5], ch__2[5], ch__3[5], ch__4[5], ch__5[5], ch__6[5];

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), e_wsfe(
	    void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l, m, n;
    static doublereal res;
    extern /* Character */ VOID oper_(char *, ftnlen, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___84 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___88 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___89 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___91 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___92 = { 0, 6, 0, fmt_140, 0 };
    static cilist io___93 = { 0, 6, 0, fmt_150, 0 };
    static cilist io___94 = { 0, 6, 0, fmt_160, 0 };
    static cilist io___95 = { 0, 6, 0, fmt_170, 0 };
    static cilist io___96 = { 0, 6, 0, fmt_175, 0 };
    static cilist io___97 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_190, 0 };


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
/* **************************************************************** */

/*   ON INPUT   R    = SYMMETRY OPERATIONS (7 MAX) */
/*              IPO  = PERM OPR FOR ABOVE OPERATIONS */
/*              NSYM = CURRENT NUMBER OF SYMMETRY OPERATIONS */
/*              NENT = NUMBER OF USER SUPPLIED OPERATIONS */

/*   ON OUTPUT  R    = SYMMETRY OPERATIONS (120 MAX) */
/*              IPO  = PERMUTATION OPERATOR FOR SYMMETRY OPERATIONS */
/*              NSYM = NUMBER OF SYMMETRY OPERATIONS */

/* **************************************************************** */

/*  A SUBROUTINE THAT WILL EXPAND THE SYMMETRY OPERATIONS READ IN INTO */
/*     THE COMPLETE SET.  NOTE: VERY FEW OPERATIONS ARE REQUIRED TO */
/*     GENERATE EVEN VERY LARGE GROUPS OF OPERATIONS. */


/*  THE NEXT PARAMETERS ARE THE MAX NUMBER OF SYMM FUNCTIONS, THE */
/*     MAX NUMBER OF SYMM FUNCTIONS TO READ IN, AND THE */
/*     TOLERENCE USED TO DETERMINE IF TWO FUNCTIONS ARE IDENTICAL */


/*  Variables used:  (n represents the number of atomic centers) */

/*    For the next two items, the last index represents the symmetry */
/*        operation number. */
/*     R(9,*):   The 9 elements of each record are a packed 3 by 3 */
/*          array of a given symmetry operations. */
/*    IPO(n,*):  A vector that contains the symmetry mapping of atomic ce */

/*  NSYM IS ALWAYS THE UPPER BOUND OF THE VALID FUNCTIONS.  QUIT IF IT */
/*     REACHES 120. */
/*  I IS THE SLOW INDEX OF FUNCTIONS TO MULTIPLY */
/*  J IS THE FAST INDEX OF FUNCTIONS TO MULTIPLY */
/*  ALWAYS DO R(I)*R(J) AND TAKE I,J FROM 2 TO NSYM */

    i__ = 2;
    j = 1;

/*  IF MORE INFORMATION IS WANTED, PRINT HEADDER. */

    if (i_indx(keywrd_1.keywrd, " RMAT", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___84);
	e_wsfe();
    }
/*  DETERMINE IF IT IS TIME TO STOP */

L10:
    ++j;
    if (j > symops_1.nsym) {
	j = 2;
	++i__;
	if (i__ > symops_1.nsym) {
	    goto L50;
	}
    }
    if (symops_1.nsym == 120) {
	goto L50;
    }

/*  NOW TO START THE MULTIPLICATION */

    symops_1.r__[(symops_1.nsym + 1) * 14 - 14] = symops_1.r__[i__ * 14 - 14] 
	    * symops_1.r__[j * 14 - 14] + symops_1.r__[i__ * 14 - 13] * 
	    symops_1.r__[j * 14 - 11] + symops_1.r__[i__ * 14 - 12] * 
	    symops_1.r__[j * 14 - 8];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 13] = symops_1.r__[i__ * 14 - 14] 
	    * symops_1.r__[j * 14 - 13] + symops_1.r__[i__ * 14 - 13] * 
	    symops_1.r__[j * 14 - 10] + symops_1.r__[i__ * 14 - 12] * 
	    symops_1.r__[j * 14 - 7];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 12] = symops_1.r__[i__ * 14 - 14] 
	    * symops_1.r__[j * 14 - 12] + symops_1.r__[i__ * 14 - 13] * 
	    symops_1.r__[j * 14 - 9] + symops_1.r__[i__ * 14 - 12] * 
	    symops_1.r__[j * 14 - 6];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 11] = symops_1.r__[i__ * 14 - 11] 
	    * symops_1.r__[j * 14 - 14] + symops_1.r__[i__ * 14 - 10] * 
	    symops_1.r__[j * 14 - 11] + symops_1.r__[i__ * 14 - 9] * 
	    symops_1.r__[j * 14 - 8];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 10] = symops_1.r__[i__ * 14 - 11] 
	    * symops_1.r__[j * 14 - 13] + symops_1.r__[i__ * 14 - 10] * 
	    symops_1.r__[j * 14 - 10] + symops_1.r__[i__ * 14 - 9] * 
	    symops_1.r__[j * 14 - 7];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 9] = symops_1.r__[i__ * 14 - 11] *
	     symops_1.r__[j * 14 - 12] + symops_1.r__[i__ * 14 - 10] * 
	    symops_1.r__[j * 14 - 9] + symops_1.r__[i__ * 14 - 9] * 
	    symops_1.r__[j * 14 - 6];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 8] = symops_1.r__[i__ * 14 - 8] * 
	    symops_1.r__[j * 14 - 14] + symops_1.r__[i__ * 14 - 7] * 
	    symops_1.r__[j * 14 - 11] + symops_1.r__[i__ * 14 - 6] * 
	    symops_1.r__[j * 14 - 8];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 7] = symops_1.r__[i__ * 14 - 8] * 
	    symops_1.r__[j * 14 - 13] + symops_1.r__[i__ * 14 - 7] * 
	    symops_1.r__[j * 14 - 10] + symops_1.r__[i__ * 14 - 6] * 
	    symops_1.r__[j * 14 - 7];
    symops_1.r__[(symops_1.nsym + 1) * 14 - 6] = symops_1.r__[i__ * 14 - 8] * 
	    symops_1.r__[j * 14 - 12] + symops_1.r__[i__ * 14 - 7] * 
	    symops_1.r__[j * 14 - 9] + symops_1.r__[i__ * 14 - 6] * 
	    symops_1.r__[j * 14 - 6];

/*  IS IT UNIQUE? */

    i__1 = symops_1.nsym;
    for (n = 1; n <= i__1; ++n) {
	res = 0.;
	for (m = 1; m <= 9; ++m) {
/* L20: */
	    res += (d__1 = symops_1.r__[m + n * 14 - 15] - symops_1.r__[m + (
		    symops_1.nsym + 1) * 14 - 15], abs(d__1));
	}
	if (res < .01) {
	    goto L10;
	}
/* L30: */
    }

/*  YES, IT IS UNIQUE.  NOW, GENERATE THE NEW IPO(,NSYM) */

    ++symops_1.nsym;
    i__1 = molkst_1.numat;
    for (n = 1; n <= i__1; ++n) {
/* L40: */
	symops_1.ipo[n + symops_1.nsym * 120 - 121] = symops_1.ipo[
		symops_1.ipo[n + j * 120 - 121] + i__ * 120 - 121];
    }

/*     ALL DONE ADDING THE NEW FUNCTION.  GO TRY TO FIND A NEW ONE. */
/*     BUT FIRST, SEE IF WE NEED TO PRINT THIS. */

    if (i_indx(keywrd_1.keywrd, " RMAT", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___88);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	oper_(ch__2, (ftnlen)5, &symops_1.r__[i__ * 14 - 14]);
	s_copy(ch__1, ch__2, (ftnlen)5, (ftnlen)5);
	do_fio(&c__1, ch__1, (ftnlen)5);
	do_fio(&c__1, (char *)&j, (ftnlen)sizeof(integer));
	oper_(ch__4, (ftnlen)5, &symops_1.r__[j * 14 - 14]);
	s_copy(ch__3, ch__4, (ftnlen)5, (ftnlen)5);
	do_fio(&c__1, ch__3, (ftnlen)5);
	do_fio(&c__1, (char *)&symops_1.nsym, (ftnlen)sizeof(integer));
	oper_(ch__6, (ftnlen)5, &symops_1.r__[symops_1.nsym * 14 - 14]);
	s_copy(ch__5, ch__6, (ftnlen)5, (ftnlen)5);
	do_fio(&c__1, ch__5, (ftnlen)5);
	e_wsfe();
    }
    if (i_indx(keywrd_1.keywrd, " RMAT", (ftnlen)241, (ftnlen)5) != 0) {
	s_wsfe(&io___89);
	for (k = 1; k <= 3; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + i__ * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	for (k = 1; k <= 3; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + j * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	for (k = 1; k <= 3; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + symops_1.nsym * 14 - 15], 
		    (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___91);
	for (k = 4; k <= 6; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + i__ * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	for (k = 4; k <= 6; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + j * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	for (k = 4; k <= 6; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + symops_1.nsym * 14 - 15], 
		    (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
	s_wsfe(&io___92);
	for (k = 7; k <= 9; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + i__ * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	for (k = 7; k <= 9; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + j * 14 - 15], (ftnlen)
		    sizeof(doublereal));
	}
	for (k = 7; k <= 9; ++k) {
	    do_fio(&c__1, (char *)&symops_1.r__[k + symops_1.nsym * 14 - 15], 
		    (ftnlen)sizeof(doublereal));
	}
	e_wsfe();
    }

    goto L10;


L50:

/*  NOW, TO DO FINAL WRAPUP */

    s_wsfe(&io___93);
    do_fio(&c__1, (char *)&symops_1.nsym, (ftnlen)sizeof(integer));
    e_wsfe();

/*  PRINT THE IPO MATRIX IF ASKED FOR. */

    if (i_indx(keywrd_1.keywrd, " IPO", (ftnlen)241, (ftnlen)4) != 0) {
	s_wsfe(&io___94);
	e_wsfe();
	i__ = 1;
	j = min(12,symops_1.nsym);
L60:
	s_wsfe(&io___95);
	i__1 = j;
	for (k = i__; k <= i__1; ++k) {
	    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	}
	e_wsfe();
	s_wsfe(&io___96);
	i__1 = j;
	for (k = i__; k <= i__1; ++k) {
	    oper_(ch__2, (ftnlen)5, &symops_1.r__[k * 14 - 14]);
	    s_copy(ch__1, ch__2, (ftnlen)5, (ftnlen)5);
	    do_fio(&c__1, ch__1, (ftnlen)5);
	}
	e_wsfe();
	s_wsfe(&io___97);
	e_wsfe();
	i__1 = molkst_1.numat;
	for (k = 1; k <= i__1; ++k) {
/* L70: */
	    s_wsfe(&io___98);
	    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	    i__2 = j;
	    for (l = i__; l <= i__2; ++l) {
		do_fio(&c__1, (char *)&symops_1.ipo[k + l * 120 - 121], (
			ftnlen)sizeof(integer));
	    }
	    e_wsfe();
	}
	if (j < symops_1.nsym) {
	    i__ = j + 1;
/* Computing MIN */
	    i__2 = j + 12;
	    j = min(i__2,symops_1.nsym);
	    goto L60;
	}
    }
    return 0;
} /* symp_ */

/* Character */ VOID oper_(char *ret_val, ftnlen ret_val_len, doublereal *r__)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    double acos(doublereal);
    integer i_dnnt(doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal ang, det, ans;
    static char num[10], opr[5];
    static doublereal trace, afull;




    /* Parameter adjustments */
    --r__;

    /* Function Body */
    s_copy(opr, " ", (ftnlen)5, (ftnlen)1);
    s_copy(num, "0123456789", (ftnlen)10, (ftnlen)10);
    trace = r__[1] + r__[5] + r__[9];
    det = r__[1] * r__[5] * r__[9] + r__[2] * r__[6] * r__[7] + r__[3] * r__[
	    4] * r__[8] - r__[1] * r__[6] * r__[8] - r__[2] * r__[4] * r__[9] 
	    - r__[3] * r__[5] * r__[7];
    trace = (trace - det) / 2.;
    if (det > 0.) {
	*(unsigned char *)opr = 'C';
	if (trace > .97) {
	    *(unsigned char *)opr = 'E';
	    goto L20;
	}
    } else {
	*(unsigned char *)opr = 'S';
	if (trace > .97) {
	    s_copy(opr, "Sigma", (ftnlen)5, (ftnlen)5);
	    goto L20;
	}
	if (trace < -.97) {
	    s_copy(opr, " Inv ", (ftnlen)5, (ftnlen)5);
	    goto L20;
	}
    }
    if (trace < -.97) {
	*(unsigned char *)&opr[1] = *(unsigned char *)&num[2];
	goto L20;
    }
    ang = acos(trace);
    afull = acos(-1.) * 2.;
    for (i__ = 3; i__ <= 18; ++i__) {
	ans = i__ * ang / afull;
	if ((d__1 = ans - i_dnnt(&ans), abs(d__1)) <= .0025) {
	    if (i__ >= 10) {
		*(unsigned char *)&opr[1] = *(unsigned char *)&num[1];
		i__1 = i__ - 10;
		s_copy(opr + 2, num + i__1, (ftnlen)1, i__ - 9 - i__1);
	    } else {
		i__1 = i__;
		s_copy(opr + 1, num + i__1, (ftnlen)1, i__ + 1 - i__1);
	    }
	    if (i_dnnt(&ans) != 1) {
		s_copy(opr + 3, "* ", (ftnlen)2, (ftnlen)2);
		i__1 = i_dnnt(&ans);
		s_copy(opr + 4, num + i__1, (ftnlen)1, i_dnnt(&ans) + 1 - 
			i__1);
	    }
	    goto L20;
	}
/* L10: */
    }
    s_copy(opr + 1, "Unkn", (ftnlen)4, (ftnlen)4);

L20:
    s_copy(ret_val, opr, (ftnlen)5, (ftnlen)5);
    return ;
} /* oper_ */

