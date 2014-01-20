/* denrot.f -- translated by f2c (version 20020621).
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
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal b[90000], bondab[39600];
} scrach_;

#define scrach_1 scrach_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int denrot_(void)
{
    /* Initialized data */

    static char atorbs[7*9] = "S-SIGMA" "P-SIGMA" "  P-PI " "  P-PI " "D-SIG"
	    "MA" "  D-PI " "  D-PI " " D-DELL" " D-DELL";
    static integer irot[175]	/* was [5][35] */ = { 1,1,1,3,3,2,2,2,4,3,3,2,
	    2,2,3,4,2,2,3,3,2,3,2,4,2,3,3,2,2,2,4,3,2,3,2,2,4,2,4,4,3,4,2,2,4,
	    4,4,2,3,4,5,5,3,1,5,6,5,3,4,3,7,5,3,3,3,8,5,3,2,3,9,5,3,5,3,5,6,3,
	    1,2,6,6,3,4,2,7,7,3,3,2,8,6,3,2,2,9,6,3,5,2,5,7,3,1,4,6,7,3,4,4,7,
	    7,3,3,4,8,7,3,2,4,9,7,3,5,4,5,8,3,1,1,6,8,3,4,1,7,8,3,3,1,8,8,3,2,
	    1,9,8,3,5,1,5,9,3,1,5,6,9,3,4,5,7,9,3,3,5,8,9,3,2,5,9,9,3,5,5 };
    static integer isp[9] = { 1,2,3,3,4,5,5,6,6 };

    /* System generated locals */
    integer i__1, i__2, i__3, i__4, i__5, i__6;
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), do_fio(integer *, char *, ftnlen), e_wsfe(void);

    /* Local variables */
    static doublereal c__[75]	/* was [3][5][5] */;
    static integer i__, j, k, l, m, n;
    static doublereal r__;
    static integer i1, j1, l1, l2, ma, if__, jf, ii, jj, il, jl, kk, ll, ij, 
	    na;
    static doublereal pab[81]	/* was [9][9] */;
    extern /* Subroutine */ int coe_(doublereal *, doublereal *, doublereal *,
	     doublereal *, doublereal *, doublereal *, integer *, integer *, 
	    doublereal *, doublereal *);
    static integer ipq, jpq;
    static doublereal sum, xyz[360]	/* was [3][120] */;
    static char line[6*21];
    static doublereal vect[81]	/* was [9][9] */, arot[81]	/* was [9][9] 
	    */;
    static integer iprt, natom[300], limit;
    static char itext[7*300], jtext[2*300];
    static integer linear;
    extern /* Subroutine */ int gmetry_(doublereal *, doublereal *);

    /* Fortran I/O blocks */
    static cilist io___40 = { 0, 6, 0, "(/16X,10(1X,A7,3X))", 0 };
    static cilist io___41 = { 0, 6, 0, "(15X,10(2X,A2,I3,4X))", 0 };
    static cilist io___42 = { 0, 6, 0, "(20A6)", 0 };
    static cilist io___43 = { 0, 6, 0, "('1')", 0 };
    static cilist io___44 = { 0, 6, 0, "(/17X,10(1X,A7,3X))", 0 };
    static cilist io___46 = { 0, 6, 0, "( 17X,10(2X,A2,I3,4X))", 0 };
    static cilist io___47 = { 0, 6, 0, "(20A6)", 0 };
    static cilist io___48 = { 0, 6, 0, "(1X,A7,1X,A2,I3,10F11.6)", 0 };
    static cilist io___49 = { 0, 6, 0, "('1')", 0 };


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

/* DENROT PRINTS THE DENSITY MATRIX AS (S-SIGMA, P-SIGMA, P-PI) RATHER */
/*        THAN (S, PX, PY, PZ). */

/* *********************************************************************** */
/* ********************************************************************** */
/* IROT IS A MAPPING LIST. FOR EACH ELEMENT OF AROT 5 NUMBERS ARE */
/* NEEDED. THESE ARE, IN ORDER, FIRST AND SECOND SUBSCRIPTS OF AROT, */
/* AND FIRST,SECOND, AND THIRD SUBSCRIPTS OF C, THUS THE FIRST */
/* LINE OF IROT DEFINES AROT(1,1)=C(1,3,3) */

/* ********************************************************************** */
    gmetry_(geom_1.geo, xyz);
    iprt = 0;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if__ = molkst_1.nfirst[i__ - 1];
	il = molkst_1.nlast[i__ - 1];
	ipq = il - if__ - 1;
	ii = ipq + 2;
	if (ii == 0) {
	    goto L120;
	}
	i__2 = ii;
	for (i1 = 1; i1 <= i__2; ++i1) {
	    j1 = iprt + isp[i1 - 1];
	    s_copy(itext + (j1 - 1) * 7, atorbs + (i1 - 1) * 7, (ftnlen)7, (
		    ftnlen)7);
	    s_copy(jtext + (j1 - 1 << 1), elemts_1.elemnt + (molkst_1.nat[i__ 
		    - 1] - 1 << 1), (ftnlen)2, (ftnlen)2);
	    natom[j1 - 1] = i__;
/* L10: */
	}
	iprt = j1;
	if (ipq != 2) {
/* Computing MIN */
	    i__2 = max(ipq,1);
	    ipq = min(i__2,3);
	}
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
	    jf = molkst_1.nfirst[j - 1];
	    jl = molkst_1.nlast[j - 1];
	    jpq = jl - jf - 1;
	    jj = jpq + 2;
	    if (jj == 0) {
		goto L110;
	    }
	    if (jpq != 2) {
/* Computing MIN */
		i__3 = max(jpq,1);
		jpq = min(i__3,3);
	    }
	    for (i1 = 1; i1 <= 9; ++i1) {
		for (j1 = 1; j1 <= 9; ++j1) {
/* L20: */
		    pab[i1 + j1 * 9 - 10] = 0.;
		}
	    }
	    kk = 0;
	    i__3 = il;
	    for (k = if__; k <= i__3; ++k) {
		++kk;
		ll = 0;
		i__4 = jl;
		for (l = jf; l <= i__4; ++l) {
		    ++ll;
/* L30: */
		    pab[kk + ll * 9 - 10] = densty_1.p[l + k * (k - 1) / 2 - 
			    1];
		}
	    }
	    coe_(&xyz[i__ * 3 - 3], &xyz[i__ * 3 - 2], &xyz[i__ * 3 - 1], &
		    xyz[j * 3 - 3], &xyz[j * 3 - 2], &xyz[j * 3 - 1], &ipq, &
		    jpq, c__, &r__);
	    for (i1 = 1; i1 <= 9; ++i1) {
		for (j1 = 1; j1 <= 9; ++j1) {
/* L40: */
		    arot[i1 + j1 * 9 - 10] = 0.;
		}
	    }
	    for (i1 = 1; i1 <= 35; ++i1) {
/* L50: */
		arot[irot[i1 * 5 - 5] + irot[i1 * 5 - 4] * 9 - 10] = c__[irot[
			i1 * 5 - 3] + (irot[i1 * 5 - 2] + irot[i1 * 5 - 1] * 
			5) * 3 - 19];
	    }
	    l1 = isp[ii - 1];
	    l2 = isp[jj - 1];
	    for (i1 = 1; i1 <= 9; ++i1) {
		for (j1 = 1; j1 <= 9; ++j1) {
/* L60: */
		    vect[i1 + j1 * 9 - 10] = -1.;
		}
	    }
	    i__4 = l1;
	    for (i1 = 1; i1 <= i__4; ++i1) {
		i__3 = l2;
		for (j1 = 1; j1 <= i__3; ++j1) {
/* L70: */
		    vect[i1 + j1 * 9 - 10] = 0.;
		}
	    }
	    if (i__ != j) {
		ij = max(ii,jj);
		i__3 = ii;
		for (i1 = 1; i1 <= i__3; ++i1) {
		    i__4 = jj;
		    for (j1 = 1; j1 <= i__4; ++j1) {
			sum = 0.;
			i__5 = ij;
			for (l1 = 1; l1 <= i__5; ++l1) {
			    i__6 = ij;
			    for (l2 = 1; l2 <= i__6; ++l2) {
/* L80: */
				sum += arot[l1 + i1 * 9 - 10] * pab[l1 + l2 * 
					9 - 10] * arot[l2 + j1 * 9 - 10];
			    }
			}
/* L90: */
/* Computing 2nd power */
			d__1 = sum;
			vect[isp[i1 - 1] + isp[j1 - 1] * 9 - 10] += d__1 * 
				d__1;
		    }
		}
	    }
	    k = 0;
	    i__4 = il;
	    for (i1 = if__; i1 <= i__4; ++i1) {
		++k;
		l = 0;
		i__3 = jl;
		for (j1 = jf; j1 <= i__3; ++j1) {
		    ++l;
/* L100: */
		    if (j1 <= i1) {
			scrach_1.b[j1 + i1 * (i1 - 1) / 2 - 1] = vect[k + l * 
				9 - 10];
		    }
		}
	    }
L110:
	    ;
	}
L120:
	;
    }

/* NOW TO REMOVE ALL THE DEAD SPACE IN P, CHARACTERIZED BY -1.0 */

    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
    l = 0;
    i__1 = linear;
    for (i__ = 1; i__ <= i__1; ++i__) {
	if (scrach_1.b[i__ - 1] > -.1f) {
	    ++l;
	    scrach_1.b[l - 1] = scrach_1.b[i__ - 1];
	}
/* L130: */
    }

/*   PUT ATOMIC ORBITAL VALENCIES ONTO THE DIAGONAL */

    i__1 = iprt;
    for (i__ = 1; i__ <= i__1; ++i__) {
	sum = 0.;
	ii = i__ * (i__ - 1) / 2;
	i__2 = i__;
	for (j = 1; j <= i__2; ++j) {
/* L140: */
	    sum += scrach_1.b[j + ii - 1];
	}
	i__2 = iprt;
	for (j = i__ + 1; j <= i__2; ++j) {
/* L150: */
	    sum += scrach_1.b[j * (j - 1) / 2 + i__ - 1];
	}
/* L160: */
	scrach_1.b[i__ * (i__ + 1) / 2 - 1] = sum;
    }
    for (i__ = 1; i__ <= 21; ++i__) {
/* L170: */
	s_copy(line + (i__ - 1) * 6, "------", (ftnlen)6, (ftnlen)6);
    }
    limit = iprt * (iprt + 1) / 2;
    kk = 8;
    na = 1;
L180:
    ll = 0;
/* Computing MIN */
    i__1 = iprt + 1 - na;
    m = min(i__1,6);
    ma = (m << 1) + 1;
    m = na + m - 1;
    s_wsfe(&io___40);
    i__1 = m;
    for (i__ = na; i__ <= i__1; ++i__) {
	do_fio(&c__1, itext + (i__ - 1) * 7, (ftnlen)7);
    }
    e_wsfe();
    s_wsfe(&io___41);
    i__1 = m;
    for (i__ = na; i__ <= i__1; ++i__) {
	do_fio(&c__1, jtext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, (char *)&natom[i__ - 1], (ftnlen)sizeof(integer));
    }
    e_wsfe();
    s_wsfe(&io___42);
    i__1 = ma;
    for (k = 1; k <= i__1; ++k) {
	do_fio(&c__1, line + (k - 1) * 6, (ftnlen)6);
    }
    e_wsfe();
    i__1 = iprt;
    for (i__ = na; i__ <= i__1; ++i__) {
	++ll;
	k = i__ * (i__ - 1) / 2;
/* Computing MIN */
	i__2 = k + m, i__3 = k + i__;
	l = min(i__2,i__3);
	k += na;
	if (kk + ll <= 50) {
	    goto L190;
	}
	s_wsfe(&io___43);
	e_wsfe();
	s_wsfe(&io___44);
	i__2 = m;
	for (n = na; n <= i__2; ++n) {
	    do_fio(&c__1, itext + (n - 1) * 7, (ftnlen)7);
	}
	e_wsfe();
	s_wsfe(&io___46);
	i__2 = m;
	for (n = na; n <= i__2; ++n) {
	    do_fio(&c__1, jtext + (n - 1 << 1), (ftnlen)2);
	    do_fio(&c__1, (char *)&natom[n - 1], (ftnlen)sizeof(integer));
	}
	e_wsfe();
	s_wsfe(&io___47);
	i__2 = ma;
	for (n = 1; n <= i__2; ++n) {
	    do_fio(&c__1, line + (n - 1) * 6, (ftnlen)6);
	}
	e_wsfe();
	kk = 4;
	ll = 0;
L190:
	s_wsfe(&io___48);
	do_fio(&c__1, itext + (i__ - 1) * 7, (ftnlen)7);
	do_fio(&c__1, jtext + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, (char *)&natom[i__ - 1], (ftnlen)sizeof(integer));
	i__2 = l;
	for (n = k; n <= i__2; ++n) {
	    do_fio(&c__1, (char *)&scrach_1.b[n - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsfe();
/* L200: */
    }
    if (l >= limit) {
	goto L210;
    }
    kk = kk + ll + 4;
    na = m + 1;
    if (kk + iprt + 1 - na <= 50) {
	goto L180;
    }
    kk = 4;
    s_wsfe(&io___49);
    e_wsfe();
    goto L180;
L210:
    return 0;
} /* denrot_ */

