/* linmin.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal cosine;
} gravec_;

#define gravec_1 gravec_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    char keywrd[241];
} keywrd_;

#define keywrd_1 keywrd_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

/* Table of constant values */

static logical c_true = TRUE_;
static logical c_false = FALSE_;
static integer c__1 = 1;

/* Subroutine */ int linmin_(doublereal *xparam, doublereal *alpha, 
	doublereal *pvect, integer *nvar, doublereal *funct, logical *okf, 
	integer *ic, doublereal *dott)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* Format strings */
    static char fmt_50[] = "(\002 ---QLINMN \002,/5x,\002LEFT   ...\002,f17."
	    "8,2f17.11/5x,\002CENTER ...\002,f17.8,2f17.11,/5x,\002RIGHT  .."
	    ".\002,f17.8,2f17.11,/)";
    static char fmt_130[] = "(5x,\002LEFT    ...\002,f17.8,2f17.11,/5x,\002C"
	    "ENTER  ...\002,f17.8,2f17.11,/5x,\002RIGHT   ...\002,f17.8,2f17."
	    "11,/5x,\002NEW     ...\002,f17.8,2f17.11,/)";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3, d__4;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen), s_wsfe(cilist *), do_fio(
	    integer *, char *, ftnlen), e_wsfe(void);
    double d_sign(doublereal *, doublereal *);

    /* Local variables */
    static integer i__;
    static doublereal s, vt[4], fin, phi[3], xxm, beta, grad[360], pabs, alfs;
    static logical diis;
    static doublereal fmin;
    static integer left;
    static doublereal fmax;
    static integer ictr;
    static doublereal drop;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical halfe;
    static doublereal gamma;
    static integer right;
    static doublereal xmaxm;
    static logical print;
    static doublereal estor, delta1, delta2, xstor[360];
    extern /* Subroutine */ int compfg_(doublereal *, logical *, doublereal *,
	     logical *, doublereal *, logical *), exchng_(doublereal *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *, doublereal *, integer *);
    static integer center;
    static doublereal alpold, xparef[360];
    static integer maxlin;
    static doublereal energy, funold, ymaxst, ssqlst, sqstor;

    /* Fortran I/O blocks */
    static cilist io___29 = { 0, 6, 0, fmt_50, 0 };
    static cilist io___37 = { 0, 6, 0, fmt_130, 0 };


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

/*  LINMIN DOES A LINE MINIMISATION. */

/*  ON INPUT:  XPARAM = STARTING COORDINATE OF SEARCH. */
/*             ALPHA  = STEP SIZE FOR INITIATING SEARCH. */
/*             PVECT  = DIRECTION OF SEARCH. */
/*             NVAR   = NUMBER OF VARIABLES IN XPARAM. */
/*             FUNCT  = INITIAL VALUE OF THE FUNCTION TO BE MINIMIZED. */
/*             ISOK   = NOT IMPORTANT. */
/*             COSINE = COSINE OF ANGLE OF CURRENT AND PREVIOUS GRADIENT. */

/*  ON OUTPUT: XPARAM = COORDINATE OF MINIMUM OF FUNCTI0N. */
/*             ALPHA  = NEW STEP SIZE, USED IN NEXT CALL OF LINMIN. */
/*             FUNCT  = FINAL, MINIMUM VALUE OF THE FUNCTION. */
/*             OKF    = TRUE IF LINMIN IMPROVED FUNCT, FALSE OTHERWISE. */

/* ********************************************************************** */

/*  THE FOLLOWING COMMON IS USED TO FIND OUT IF A NON-VARIATIONALLY */
/*  OPTIMIZED WAVE-FUNCTION IS BEING USED. */

    /* Parameter adjustments */
    --pvect;
    --xparam;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	halfe = i_indx(keywrd_1.keywrd, "C.I.", (ftnlen)241, (ftnlen)4) != 0 
		|| molkst_1.nclose != molkst_1.nopen;
	if (i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5) != 0) {
/* Computing MIN */
	    i__1 = i_indx(keywrd_1.keywrd, "GNORM", (ftnlen)241, (ftnlen)5);
	    d__1 = reada_(keywrd_1.keywrd, &i__1, (ftnlen)241);
	    drop *= min(d__1,1.);
	}
	xmaxm = .4;
	delta2 = .001;
	if (i_indx(keywrd_1.keywrd, "NOTH", (ftnlen)241, (ftnlen)4) == 0) {
	    delta1 = .5;
	} else {
	    delta1 = .1;
	}
	*alpha = 1.;
	maxlin = 15;
	if (*nvar == 1) {
	    pvect[1] = .01;
	    drop = .01;
	    *alpha = 1.;
	    delta1 = 5e-5;
	    delta2 = 1e-5;
	    if (i_indx(keywrd_1.keywrd, "PREC", (ftnlen)241, (ftnlen)4) != 0) 
		    {
		delta1 = 5e-7;
	    }
	    maxlin = 30;
	}
	gravec_1.cosine = 99.99;

	ymaxst = .4;
	print = i_indx(keywrd_1.keywrd, "LINMIN", (ftnlen)241, (ftnlen)6) != 
		0;
	icalcn = numcal_1.numcal;
    }
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	xparef[i__ - 1] = xparam[i__];
/* L10: */
    }
    xmaxm = 0.;
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
	pabs = (d__1 = pvect[i__], abs(d__1));
/* L20: */
	xmaxm = max(xmaxm,pabs);
    }
    xmaxm = ymaxst / xmaxm;
    if (*nvar == 1) {
	compfg_(&xparam[1], &c_true, funct, &c_true, grad, &c_false);
    }
    fin = *funct;
    ssqlst = *funct;
    diis = *ic == 1 && *nvar > 1;
    phi[0] = *funct;
    *alpha = 1.;
    vt[0] = 0.;
    vt[1] = *alpha;
    if (vt[1] > xmaxm) {
	vt[1] = xmaxm;
    }
    fmax = *funct;
    fmin = *funct;
    *alpha = vt[1];
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	xparam[i__] = xparef[i__ - 1] + *alpha * pvect[i__];
    }
    compfg_(&xparam[1], &c_true, &phi[1], &c_true, grad, &c_false);
    if (phi[1] > fmax) {
	fmax = phi[1];
    }
    if (phi[1] < fmin) {
	fmin = phi[1];
    }
    exchng_(&phi[1], &sqstor, &energy, &estor, &xparam[1], xstor, alpha, &
	    alfs, nvar);
    if (diis) {
	goto L190;
    }
    if (*nvar > 1) {

/*   CALCULATE A NEW ALPHA BASED ON THIEL'S FORMULA */

/* Computing 2nd power */
	d__1 = *alpha;
	*alpha = -(d__1 * d__1) * *dott / ((phi[1] - ssqlst - *alpha * *dott) 
		* 2.);
	if (*alpha > 2.) {
	    *alpha = 2.;
	}
    } else {
	if (phi[1] < phi[0]) {
	    *alpha *= 2;
	} else {
	    *alpha = -(*alpha);
	}
    }
/* #      IF(PRINT)WRITE(6,'(3(A,F12.6))')' ESTIMATED DROP:',DOTT*0.5D0, */
/* #     1'  ACTUAL: ',PHI(2)-SSQLST, '  PREDICTED ALPHA',ALPHA */
    *okf = *okf || phi[1] < ssqlst;
    if (delta1 > .3) {

/*  THIEL'S TESTS # 18 AND 19 */

	if (*okf && *alpha < 2.) {
	    goto L190;
	}
    }
    vt[2] = *alpha;
    if (vt[2] <= 1.) {
	left = 3;
	center = 1;
	right = 2;
    } else {
	left = 1;
	center = 2;
	right = 3;
    }
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L40: */
	xparam[i__] = xparef[i__ - 1] + *alpha * pvect[i__];
    }
    compfg_(&xparam[1], &c_true, funct, &c_true, grad, &c_false);
    if (*funct > fmax) {
	fmax = *funct;
    }
    if (*funct < fmin) {
	fmin = *funct;
    }
    if (*funct < sqstor) {
	exchng_(funct, &sqstor, &energy, &estor, &xparam[1], xstor, alpha, &
		alfs, nvar);
    }
    *okf = *okf || *funct < fin;
    phi[2] = *funct;
    if (print) {
	s_wsfe(&io___29);
	do_fio(&c__1, (char *)&vt[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi[0], (ftnlen)sizeof(doublereal));
	d__1 = phi[0] - fin;
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vt[1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi[1], (ftnlen)sizeof(doublereal));
	d__2 = phi[1] - fin;
	do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&vt[2], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&phi[2], (ftnlen)sizeof(doublereal));
	d__3 = phi[2] - fin;
	do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    i__1 = maxlin;
    for (ictr = 3; ictr <= i__1; ++ictr) {
	*alpha = vt[1] - vt[2];
	beta = vt[2] - vt[0];
	gamma = vt[0] - vt[1];
	if ((d__1 = *alpha * beta * gamma, abs(d__1)) > 1e-4) {
	    *alpha = -(phi[0] * *alpha + phi[1] * beta + phi[2] * gamma) / (*
		    alpha * beta * gamma);
	} else {

/*   FINISH BECAUSE TWO POINTS CALCULATED ARE VERY CLOSE TOGETHER */

	    goto L190;
	}
	beta = (phi[0] - phi[1]) / gamma - *alpha * (vt[0] + vt[1]);
	if (*alpha <= 0.) {
	    goto L60;
	} else {
	    goto L90;
	}
L60:
	if (phi[right - 1] > phi[left - 1]) {
	    goto L70;
	}
	*alpha = vt[right - 1] * 3. - vt[center - 1] * 2.;
	goto L80;
L70:
	*alpha = vt[left - 1] * 3. - vt[center - 1] * 2.;
L80:
	s = *alpha - alpold;
	if (abs(s) > xmaxm) {
	    s = d_sign(&xmaxm, &s) * (xmaxm / s * .01 + 1);
	}
	*alpha = s + alpold;
	goto L100;
L90:
	*alpha = -beta / (*alpha * 2.);
	s = *alpha - alpold;
	xxm = xmaxm * 2.;
	if (abs(s) > xxm) {
	    s = d_sign(&xxm, &s) * (xxm / s * .01 + 1);
	}
	*alpha = s + alpold;
L100:

/*   FINISH IF CALCULATED POINT IS NEAR TO POINT ALREADY CALCULATED */

	for (i__ = 1; i__ <= 3; ++i__) {
/* L110: */
	    if ((d__1 = *alpha - vt[i__ - 1], abs(d__1)) < delta1 * (vt[i__ - 
		    1] + 1.) && *okf) {
		goto L190;
	    }
	}
	i__2 = *nvar;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L120: */
	    xparam[i__] = xparef[i__ - 1] + *alpha * pvect[i__];
	}
	funold = *funct;
	compfg_(&xparam[1], &c_true, funct, &c_true, grad, &c_false);
	if (*funct > fmax) {
	    fmax = *funct;
	}
	if (*funct < fmin) {
	    fmin = *funct;
	}
	if (*funct < sqstor) {
	    exchng_(funct, &sqstor, &energy, &estor, &xparam[1], xstor, alpha,
		     &alfs, nvar);
	}
	*okf = *okf || *funct < fin;
	if (print) {
	    s_wsfe(&io___37);
	    do_fio(&c__1, (char *)&vt[left - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phi[left - 1], (ftnlen)sizeof(doublereal));
	    d__1 = phi[left - 1] - fin;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&vt[center - 1], (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, (char *)&phi[center - 1], (ftnlen)sizeof(doublereal)
		    );
	    d__2 = phi[center - 1] - fin;
	    do_fio(&c__1, (char *)&d__2, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&vt[right - 1], (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&phi[right - 1], (ftnlen)sizeof(doublereal))
		    ;
	    d__3 = phi[right - 1] - fin;
	    do_fio(&c__1, (char *)&d__3, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*alpha), (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
	    d__4 = *funct - fin;
	    do_fio(&c__1, (char *)&d__4, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}

/* TEST TO EXIT FROM LINMIN IF NOT DROPPING IN VALUE OF FUNCTION FAST. */

	if ((d__1 = funold - *funct, abs(d__1)) < delta2 && *okf) {
	    goto L190;
	}
	alpold = *alpha;
	if (*alpha > vt[right - 1] || *alpha > vt[center - 1] && *funct < phi[
		center - 1] || *alpha > vt[left - 1] && *alpha < vt[center - 
		1] && *funct > phi[center - 1]) {
	    goto L140;
	}
	vt[right - 1] = *alpha;
	phi[right - 1] = *funct;
	goto L150;
L140:
	vt[left - 1] = *alpha;
	phi[left - 1] = *funct;
L150:
	if (vt[center - 1] < vt[right - 1]) {
	    goto L160;
	}
	i__ = center;
	center = right;
	right = i__;
L160:
	if (vt[left - 1] < vt[center - 1]) {
	    goto L170;
	}
	i__ = left;
	left = center;
	center = i__;
L170:
	if (vt[center - 1] < vt[right - 1]) {
	    goto L180;
	}
	i__ = center;
	center = right;
	right = i__;
L180:
	;
    }
L190:

/*  IC=1 IF THE LAST POINT CALCULATED WAS THE BEST POINT, IC=2 OTHERWISE */

    *ic = 2;
    if ((d__1 = estor - energy, abs(d__1)) < 1e-12) {
	*ic = 1;
    }
    exchng_(&sqstor, funct, &estor, &energy, xstor, &xparam[1], &alfs, alpha, 
	    nvar);
    *okf = *funct < ssqlst || diis;
    if (*funct >= ssqlst) {
	return 0;
    }
    if (*alpha >= 0.) {
	goto L220;
    } else {
	goto L200;
    }
L200:
    *alpha = -(*alpha);
    i__1 = *nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L210: */
	pvect[i__] = -pvect[i__];
    }
L220:
    return 0;


} /* linmin_ */

