/* setupg.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    integer nztype[107], mtype[30], ltype;
} natype_;

#define natype_1 natype_

struct {
    doublereal cc[360]	/* was [60][6] */, zz[360]	/* was [60][6] */;
} temp_;

#define temp_1 temp_

struct {
    doublereal allc[72]	/* was [6][6][2] */, allz[72]	/* was [6][6][2] */;
} sto6g_;

#define sto6g_1 sto6g_

/* Subroutine */ int setupg_(void)
{
    /* System generated locals */
    integer i__1;
    doublereal d__1;

    /* Local variables */
    static integer i__, j, k, l, ia, ib, ni;
    static doublereal xi;
    static integer nqn;

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
/*     SET-UP THE STEWART'S STO-6G EXPANSIONS */
/*                                            1S */
    sto6g_1.allz[0] = 23.10303149;
    sto6g_1.allz[1] = 4.235915534;
    sto6g_1.allz[2] = 1.185056519;
    sto6g_1.allz[3] = .4070988982;
    sto6g_1.allz[4] = .1580884151;
    sto6g_1.allz[5] = .06510953954;

    sto6g_1.allc[0] = .00916359628;
    sto6g_1.allc[1] = .04936149294;
    sto6g_1.allc[2] = .1685383049;
    sto6g_1.allc[3] = .3705627997;
    sto6g_1.allc[4] = .4164915298;
    sto6g_1.allc[5] = .1303340841;
/*                                      2S */
    sto6g_1.allz[6] = 27.68496241;
    sto6g_1.allz[7] = 5.077140627;
    sto6g_1.allz[8] = 1.42678605;
    sto6g_1.allz[9] = .2040335729;
    sto6g_1.allz[10] = .09260298399;
    sto6g_1.allz[11] = .04416183978;

    sto6g_1.allc[6] = -.004151277819;
    sto6g_1.allc[7] = -.02067024148;
    sto6g_1.allc[8] = -.05150303337;
    sto6g_1.allc[9] = .3346271174;
    sto6g_1.allc[10] = .5621061301;
    sto6g_1.allc[11] = .1712994697;
/*                                     2P */
    sto6g_1.allz[42] = 5.868285913;
    sto6g_1.allz[43] = 1.530329631;
    sto6g_1.allz[44] = .5475665231;
    sto6g_1.allz[45] = .2288932733;
    sto6g_1.allz[46] = .1046655969;
    sto6g_1.allz[47] = .04948220127;

    sto6g_1.allc[42] = .007924233646;
    sto6g_1.allc[43] = .05144104825;
    sto6g_1.allc[44] = .189840006;
    sto6g_1.allc[45] = .4049863191;
    sto6g_1.allc[46] = .4012362861;
    sto6g_1.allc[47] = .1051855189;
/*                                      3S */
    sto6g_1.allz[12] = 3.273031938;
    sto6g_1.allz[13] = .9200611311;
    sto6g_1.allz[14] = .3593349765;
    sto6g_1.allz[15] = .08636686991;
    sto6g_1.allz[16] = .04797373812;
    sto6g_1.allz[17] = .02724741144;
    sto6g_1.allc[12] = -.006775596947;
    sto6g_1.allc[13] = -.05639325779;
    sto6g_1.allc[14] = -.1587856086;
    sto6g_1.allc[15] = .5534527651;
    sto6g_1.allc[16] = .501535102;
    sto6g_1.allc[17] = .07223633674;
/*                                     3P */
    sto6g_1.allz[48] = 5.077973607;
    sto6g_1.allz[49] = 1.34078694;
    sto6g_1.allz[50] = .2248434849;
    sto6g_1.allz[51] = .1131741848;
    sto6g_1.allz[52] = .06076408893;
    sto6g_1.allz[53] = .03315424265;
    sto6g_1.allc[48] = -.00332992984;
    sto6g_1.allc[49] = -.0141948834;
    sto6g_1.allc[50] = .163939577;
    sto6g_1.allc[51] = .4485358256;
    sto6g_1.allc[52] = .390881305;
    sto6g_1.allc[53] = .07411456232;
/*                                     4S */
    sto6g_1.allz[18] = 1.365346;
    sto6g_1.allz[19] = .4393213;
    sto6g_1.allz[20] = .1877069;
    sto6g_1.allz[21] = .0936027;
    sto6g_1.allz[22] = .05052263;
    sto6g_1.allz[23] = .02809354;
    sto6g_1.allc[18] = .003775056;
    sto6g_1.allc[19] = -.05585965;
    sto6g_1.allc[20] = -.3192946;
    sto6g_1.allc[21] = -.0276478;
    sto6g_1.allc[22] = .9049199;
    sto6g_1.allc[23] = .3406258;
/*                                   4P */
    sto6g_1.allc[54] = -.007052075;
    sto6g_1.allc[55] = -.05259505;
    sto6g_1.allc[56] = -.0377345;
    sto6g_1.allc[57] = .3874773;
    sto6g_1.allc[58] = .5791672;
    sto6g_1.allc[59] = .1221817;
    sto6g_1.allz[54] = 1.365346;
    sto6g_1.allz[55] = .4393213;
    sto6g_1.allz[56] = .1877069;
    sto6g_1.allz[57] = .0936027;
    sto6g_1.allz[58] = .05052263;
    sto6g_1.allz[59] = .02809354;
/*                                     5S */
    sto6g_1.allz[24] = .7701420258;
    sto6g_1.allz[25] = .2756268915;
    sto6g_1.allz[26] = .130184748;
    sto6g_1.allz[27] = .0695344194;
    sto6g_1.allz[28] = .04002545502;
    sto6g_1.allz[29] = .02348388309;
    sto6g_1.allc[24] = .01267447151;
    sto6g_1.allc[25] = .003266734789;
    sto6g_1.allc[26] = -.4307553999;
    sto6g_1.allc[27] = -.3231998963;
    sto6g_1.allc[28] = 1.104322879;
    sto6g_1.allc[29] = .4368498703;
/*                                      5P */
    sto6g_1.allz[60] = .7701420258;
    sto6g_1.allz[61] = .2756268915;
    sto6g_1.allz[62] = .130184748;
    sto6g_1.allz[63] = .0695344194;
    sto6g_1.allz[64] = .04002545502;
    sto6g_1.allz[65] = .02348388309;
    sto6g_1.allc[60] = -.001105673292;
    sto6g_1.allc[61] = -.06243132446;
    sto6g_1.allc[62] = -.1628476766;
    sto6g_1.allc[63] = .3210328714;
    sto6g_1.allc[64] = .6964579592;
    sto6g_1.allc[65] = .1493146125;
/*                                   6S */
    sto6g_1.allz[30] = .5800292686;
    sto6g_1.allz[31] = .2718262251;
    sto6g_1.allz[32] = .07938523262;
    sto6g_1.allz[33] = .04975088254;
    sto6g_1.allz[34] = .02983643556;
    sto6g_1.allz[35] = .01886067216;
    sto6g_1.allc[30] = .004554359511;
    sto6g_1.allc[31] = .05286443143;
    sto6g_1.allc[32] = -.7561016358;
    sto6g_1.allc[33] = -.226980382;
    sto6g_1.allc[34] = 1.332494651;
    sto6g_1.allc[35] = .3622518293;
/*                                   6P */
    sto6g_1.allz[66] = .6696537714;
    sto6g_1.allz[67] = .1395089793;
    sto6g_1.allz[68] = .0816389496;
    sto6g_1.allz[69] = .04586329272;
    sto6g_1.allz[70] = .02961305556;
    sto6g_1.allz[71] = .01882221321;
    sto6g_1.allc[66] = .00278272368;
    sto6g_1.allc[67] = -.128288778;
    sto6g_1.allc[68] = -.2266255943;
    sto6g_1.allc[69] = .4682259383;
    sto6g_1.allc[70] = .6752048848;
    sto6g_1.allc[71] = .1091534212;
    for (i__ = 1; i__ <= 10; ++i__) {
	if (natype_1.mtype[i__ - 1] == 0) {
	    goto L30;
	}
	ni = natype_1.mtype[i__ - 1];
	xi = expont_1.zs[ni - 1];
	ia = (i__ << 2) - 3;
	ib = ia + 3;
	if (ni < 2) {
	    nqn = 1;
	} else if (ni < 10) {
	    nqn = 2;
	} else if (ni < 18) {
	    nqn = 3;
	} else if (ni < 36) {
	    nqn = 4;
	} else if (ni < 54) {
	    nqn = 5;
	} else {
	    nqn = 6;
	}
	i__1 = ib;
	for (k = ia; k <= i__1; ++k) {
	    l = 1;
	    if (k > ia) {
		l = 2;
	    }
	    if (k > ia) {
		xi = expont_1.zp[ni - 1];
	    }
	    for (j = 1; j <= 6; ++j) {
		temp_1.cc[k + j * 60 - 61] = sto6g_1.allc[j + (nqn + l * 6) * 
			6 - 43];
/* L10: */
/* Computing 2nd power */
		d__1 = xi;
		temp_1.zz[k + j * 60 - 61] = sto6g_1.allz[j + (nqn + l * 6) * 
			6 - 43] * (d__1 * d__1);
	    }
/* L20: */
	}
L30:
	;
    }
    return 0;
} /* setupg_ */

