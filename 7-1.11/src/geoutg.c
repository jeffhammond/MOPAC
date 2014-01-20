/* geoutg.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal dumy[360];
} geovar_;

#define geovar_1 geovar_

struct {
    char simbol[3600];
} simbol_;

#define simbol_1 simbol_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    char ltxt[1], txtatm[960];
} atomtx_;

#define atomtx_1 atomtx_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

/* Table of constant values */

static integer c__1 = 1;
static integer c__3 = 3;

/* Subroutine */ int geoutg_(integer *iprt)
{
    /* Initialized data */

    static char elemnt[2*107] = " H" "He" "Li" "Be" " B" " C" " N" " O" " F" 
	    "Ne" "Na" "Mg" "Al" "Si" " P" " S" "Cl" "Ar" " K" "Ca" "Sc" "Ti" 
	    " V" "Cr" "Mn" "Fe" "Co" "Ni" "Cu" "Zn" "Ga" "Ge" "As" "Se" "Br" 
	    "Kr" "Rb" "Sr" " Y" "Zr" "Nb" "Mo" "Tc" "Ru" "Rh" "Pd" "Ag" "Cd" 
	    "In" "Sn" "Sb" "Te" " I" "Xe" "Cs" "Ba" "La" "Ce" "Pr" "Nd" "Pm" 
	    "Sm" "Eu" "Gd" "Tb" "Dy" "Ho" "Er" "Tm" "Yb" "Lu" "Hf" "Ta" " W" 
	    "Re" "Os" "Ir" "Pt" "Au" "Hg" "Tl" "Pb" "Bi" "Po" "At" "Rn" "Fr" 
	    "Ra" "Ac" "Th" "Pa" " U" "Np" "Pu" "Am" "Cm" "Bk" "Cf" "XX" "Fm" 
	    "Md" "Cb" "++" " +" "--" " -" "Tv";
    static char type__[1*3] = "r" "a" "d";

    /* System generated locals */
    address a__1[3];
    integer i__1, i__2[3], i__3, i__4;
    doublereal d__1;
    olist o__1;
    alist al__1;

    /* Builtin functions */
    integer f_open(olist *);
    double asin(doublereal);
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer f_rew(alist *), s_wsfe(cilist *), do_fio(integer *, char *, 
	    ftnlen), e_wsfe(void), s_rsfe(cilist *), e_rsfe(void), s_cmp(char 
	    *, char *, ftnlen, ftnlen);
    /* Subroutine */ int s_cat(char *, char **, integer *, integer *, ftnlen);
    integer s_wsle(cilist *), e_wsle(void);

    /* Local variables */
    static integer i__, j, l, nbi, nci;
    extern /* Subroutine */ int xxx_(char *, integer *, integer *, integer *, 
	    integer *, char *, ftnlen, ftnlen);
    static integer igeo[360]	/* was [3][120] */;
    static char line[15*3*120];
    static integer nopt;
    static char blank[80];
    static doublereal degree;
    static char optdat[14*360];
    static integer maxtxt;

    /* Fortran I/O blocks */
    static cilist io___10 = { 0, 21, 0, "(F12.6)", 0 };
    static cilist io___11 = { 0, 21, 0, "(F12.6)", 0 };
    static cilist io___12 = { 0, 21, 0, "(A)", 0 };
    static cilist io___17 = { 0, 0, 0, "(1X,A,I4,A,I4,A,I4,A,I4)", 0 };
    static cilist io___18 = { 0, 0, 0, "(1X,A,I4,A,I4,A,I4,A,I4)", 0 };
    static cilist io___19 = { 0, 0, 0, "(1X,A,I4,A,I4,A,I4,A,I4)", 0 };
    static cilist io___21 = { 0, 0, 0, "(1X,A,I4,A,I4,A,I4,A,I4)", 0 };
    static cilist io___22 = { 0, 0, 0, 0, 0 };
    static cilist io___23 = { 0, 0, 0, "(A,F12.6)", 0 };
    static cilist io___24 = { 0, 0, 0, "(A,F12.6)", 0 };


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

/*   GEOUTG WRITES OUT THE GEOMETRY IN GAUSSIAN-8X STYLE */

/* *********************************************************************** */
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
/* L10: */
	    igeo[j + i__ * 3 - 4] = -1;
	}
    }
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	igeo[geovar_1.loc[(i__ << 1) - 1] + geovar_1.loc[(i__ << 1) - 2] * 3 
		- 4] = -2;
    }
    i__1 = geosym_1.ndep;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (geosym_1.idepfn[i__ - 1] == 14) {
	    igeo[geosym_1.locdep[i__ - 1] * 3 - 1] = -geosym_1.locpar[i__ - 1]
		    ;
	} else {
	    if (geosym_1.idepfn[i__ - 1] > 3) {
		goto L30;
	    }
	    igeo[geosym_1.idepfn[i__ - 1] + geosym_1.locdep[i__ - 1] * 3 - 4] 
		    = geosym_1.locpar[i__ - 1];
	}
L30:
	;
    }
    o__1.oerr = 0;
    o__1.ounit = 21;
    o__1.ofnm = 0;
    o__1.orl = 0;
    o__1.osta = "SCRATCH";
    o__1.oacc = 0;
    o__1.ofm = 0;
    o__1.oblnk = 0;
    f_open(&o__1);
    degree = 90. / asin(1.);
    maxtxt = *(unsigned char *)atomtx_1.ltxt;
    nopt = 0;
    i__1 = geokst_1.natoms;
    for (i__ = 1; i__ <= i__1; ++i__) {
	for (j = 1; j <= 3; ++j) {
	    s_copy(line + (j + i__ * 3 - 4) * 15, " ", (ftnlen)15, (ftnlen)1);
	    if (igeo[j + i__ * 3 - 4] == -1) {
		al__1.aerr = 0;
		al__1.aunit = 21;
		f_rew(&al__1);
		if (j != 1) {
		    s_wsfe(&io___10);
		    d__1 = geom_1.geo[j + i__ * 3 - 4] * degree;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    e_wsfe();
		} else {
		    s_wsfe(&io___11);
		    do_fio(&c__1, (char *)&geom_1.geo[j + i__ * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		    e_wsfe();
		}
		al__1.aerr = 0;
		al__1.aunit = 21;
		f_rew(&al__1);
		s_rsfe(&io___12);
		do_fio(&c__1, line + (j + i__ * 3 - 4) * 15, (ftnlen)15);
		e_rsfe();
	    } else if (igeo[j + i__ * 3 - 4] == -2) {
		++nopt;
		if (s_cmp(simbol_1.simbol + (nopt - 1) * 10, "---", (ftnlen)
			10, (ftnlen)3) != 0) {
		    if (*(unsigned char *)&simbol_1.simbol[(nopt - 1) * 10] ==
			     '-') {
			s_copy(line + ((j + i__ * 3 - 4) * 15 + 3), 
				simbol_1.simbol + ((nopt - 1) * 10 + 1), (
				ftnlen)12, (ftnlen)9);
		    } else {
			s_copy(line + ((j + i__ * 3 - 4) * 15 + 3), 
				simbol_1.simbol + (nopt - 1) * 10, (ftnlen)12,
				 (ftnlen)10);
		    }
		} else {
		    nbi = geokst_1.nb[i__ - 1];
		    nci = geokst_1.nc[i__ - 1];
		    if (j != 3) {
			nci = 0;
		    }
		    if (j == 1) {
			nbi = 0;
		    }
		    xxx_(type__ + (j - 1), &i__, &geokst_1.na[i__ - 1], &nbi, 
			    &nci, line + ((j + i__ * 3 - 4) * 15 + 3), (
			    ftnlen)1, (ftnlen)12);
		}
		s_copy(optdat + (nopt - 1) * 14, line + (j + i__ * 3 - 4) * 
			15, (ftnlen)14, (ftnlen)15);
	    } else if (igeo[j + i__ * 3 - 4] < 0) {
		s_copy(line + (i__ * 3 - 1) * 15, line + (-igeo[j + i__ * 3 - 
			4] * 3 - 1) * 15, (ftnlen)15, (ftnlen)15);
		*(unsigned char *)&line[(i__ * 3 - 1) * 15 + 2] = '-';
	    } else {
		s_copy(line + (j + i__ * 3 - 4) * 15, line + (j + igeo[j + 
			i__ * 3 - 4] * 3 - 4) * 15, (ftnlen)15, (ftnlen)15);
	    }
/* L40: */
	}
/* Writing concatenation */
	i__2[0] = 2, a__1[0] = elemnt + (geokst_1.labels[i__ - 1] - 1 << 1);
	i__2[1] = 8, a__1[1] = atomtx_1.txtatm + (i__ - 1 << 3);
	i__2[2] = 2, a__1[2] = "  ";
	s_cat(blank, a__1, i__2, &c__3, (ftnlen)80);
	if (geokst_1.labels[i__ - 1] == 99) {
	    *(unsigned char *)blank = ' ';
	}
/* Computing MAX */
	i__3 = 4, i__4 = maxtxt + 2;
	j = max(i__3,i__4);
	if (i__ == 1) {
	    io___17.ciunit = *iprt;
	    s_wsfe(&io___17);
	    do_fio(&c__1, blank, j);
	    e_wsfe();
	} else if (i__ == 2) {
	    io___18.ciunit = *iprt;
	    s_wsfe(&io___18);
	    do_fio(&c__1, blank, j);
	    do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, line + (i__ * 3 - 3) * 15, (ftnlen)15);
	    e_wsfe();
	} else if (i__ == 3) {
	    io___19.ciunit = *iprt;
	    s_wsfe(&io___19);
	    do_fio(&c__1, blank, j);
	    do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, line + (i__ * 3 - 3) * 15, (ftnlen)15);
	    do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, line + (i__ * 3 - 2) * 15, (ftnlen)15);
	    e_wsfe();
	} else {
	    l = 0;
	    io___21.ciunit = *iprt;
	    s_wsfe(&io___21);
	    do_fio(&c__1, blank, j);
	    do_fio(&c__1, (char *)&geokst_1.na[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, line + (i__ * 3 - 3) * 15, (ftnlen)15);
	    do_fio(&c__1, (char *)&geokst_1.nb[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, line + (i__ * 3 - 2) * 15, (ftnlen)15);
	    do_fio(&c__1, (char *)&geokst_1.nc[i__ - 1], (ftnlen)sizeof(
		    integer));
	    do_fio(&c__1, line + (i__ * 3 - 1) * 15, (ftnlen)15);
	    do_fio(&c__1, (char *)&l, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
/* L50: */
    }
    io___22.ciunit = *iprt;
    s_wsle(&io___22);
    e_wsle();
    for (l = 1; l <= 3; ++l) {
	i__1 = nopt;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    if (geovar_1.loc[(i__ << 1) - 1] == l) {
		if (geovar_1.loc[(i__ << 1) - 1] != 1) {
		    io___23.ciunit = *iprt;
		    s_wsfe(&io___23);
		    do_fio(&c__1, optdat + (i__ - 1) * 14, (ftnlen)14);
		    d__1 = geom_1.geo[geovar_1.loc[(i__ << 1) - 1] + 
			    geovar_1.loc[(i__ << 1) - 2] * 3 - 4] * degree;
		    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
		    e_wsfe();
		} else {
		    io___24.ciunit = *iprt;
		    s_wsfe(&io___24);
		    do_fio(&c__1, optdat + (i__ - 1) * 14, (ftnlen)14);
		    do_fio(&c__1, (char *)&geom_1.geo[geovar_1.loc[(i__ << 1) 
			    - 1] + geovar_1.loc[(i__ << 1) - 2] * 3 - 4], (
			    ftnlen)sizeof(doublereal));
		    e_wsfe();
		}
	    }
/* L60: */
	}
/* L70: */
    }
    return 0;
} /* geoutg_ */

/* Subroutine */ int xxx_(char *type__, integer *i__, integer *j, integer *k, 
	integer *l, char *r__, ftnlen type_len, ftnlen r_len)
{
    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer m, i2, ii, ijk[4], loop;

/* *********************************************************************** */

/*    XXX WILL FORM A UNIQUE STRING LABEL 'R' FOR GAUSSIAN-TYPE INPUT */
/*    THE LABEL WILL BE LETTER (EITHER R, P, OR F, NORMALLY), FOLLOWED */
/*    BY THE CONNECTIVITY, IN THE ORDER I, J, K, L. */
/*    'R' IS 13 CHARACTERS LONG IN ORDER TO ACCOMMODATE 3 DIGITS PER */
/*    LABEL, WHEN NECESSARY */

/* *********************************************************************** */
    s_copy(r__, type__, r_len, (ftnlen)1);
    ijk[0] = *i__;
    ijk[1] = *j;
    ijk[2] = *k;
    ijk[3] = *l;
    m = 1;
    for (loop = 1; loop <= 4; ++loop) {
	ii = ijk[loop - 1];
	if (ii == 0) {
	    goto L10;
	}

/*   IF LABELS GREATER THAN 99 ARE USED, UNCOMMENT THE FOLLOWING CODE */

/* #         I2=II/100 */
/* #         IF(I2.NE.0) THEN */
/* #            M=M+1 */
/* #            R(M:M)=CHAR(ICHAR('0')+I2) */
/* #            II=II-I2*100 */
/* #         ENDIF */
	i2 = ii / 10;
	if (i2 != 0) {
	    ++m;
	    *(unsigned char *)&r__[m - 1] = (char) ('0' + i2);
	    ii -= i2 * 10;
	}
	++m;
	*(unsigned char *)&r__[m - 1] = (char) ('0' + ii);
L10:
	;
    }
    return 0;
} /* xxx_ */

