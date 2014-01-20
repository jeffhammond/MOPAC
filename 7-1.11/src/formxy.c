/* formxy.f -- translated by f2c (version 20020621).
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
    integer numcal;
} numcal_;

#define numcal_1 numcal_

/* Subroutine */ int formxy_(doublereal *w, integer *kr, doublereal *wca, 
	doublereal *wcb, doublereal *ca, integer *na, doublereal *cb, integer 
	*nb)
{
    /* Initialized data */

    static integer icalcn = 0;

    /* System generated locals */
    integer i__1;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j;
    static doublereal w1, pa, pb;
    static integer ij;
    static doublereal pwa, pwb, sum;
    static logical mindo3;

/* *********************************************************************** */

/*    EACH OF THE NA ELEMENTS OF WCA WILL ADD ON THE NB ELECTROSTATIC */
/*    TERMS FROM ATOM B IN CB */

/*    EACH OF THE NB ELEMENTS OF WCB WILL ADD ON THE NA ELECTROSTATIC */
/*    TERMS FROM ATOM A IN CA */

/*    BOTH SUMS WILL INVOLVE THE NA*NB TERMS IN ARRAY W.  ONCE USED, */
/*    W WILL BE INCREMENTED BY NA*NB. */

/* NA=1 IF ATOM 'A' IS A HYDROGEN, NA=10 IF ATOM 'A' IS NOT A HYDROGEN */
/* NB=1 IF ATOM 'B' IS A HYDROGEN, NB=10 IF ATOM 'B' IS NOT A HYDROGEN */

/* *********************************************************************** */
    /* Parameter adjustments */
    --w;
    --ca;
    --wca;
    --cb;
    --wcb;

    /* Function Body */
    if (icalcn != numcal_1.numcal) {
	icalcn = numcal_1.numcal;
	mindo3 = i_indx(keywrd_1.keywrd, "MINDO", (ftnlen)241, (ftnlen)5) != 
		0;
    }
    if (mindo3) {
	w1 = w[1] * .25;

/*   CALCULATE THE TOTAL NUMBER OF ELECTRONS ON ATOMS A AND B */

	pa = ca[1];
	pb = cb[1];
	if (*na > 1 && *nb > 1) {
	    pwa = (pa + ca[3] + ca[6] + ca[10]) * w1;
	    pwb = (pb + cb[3] + cb[6] + cb[10]) * w1;
	    wca[1] += pwb;
	    wca[3] += pwb;
	    wca[6] += pwb;
	    wca[10] += pwb;
	    wcb[1] += pwa;
	    wcb[3] += pwa;
	    wcb[6] += pwa;
	    wcb[10] += pwa;
	} else if (*na > 1) {
	    pwb = pb * w1;
	    wca[1] += pwb;
	    wca[3] += pwb;
	    wca[6] += pwb;
	    wca[10] += pwb;
	    wcb[1] += (pa + ca[3] + ca[6] + ca[10]) * w1;
	} else if (*nb > 1) {
	    pwa = pa * w1;
	    wca[1] += (pb + cb[3] + cb[6] + cb[10]) * w1;
	    wcb[1] += pwa;
	    wcb[3] += pwa;
	    wcb[6] += pwa;
	    wcb[10] += pwa;
	} else {
	    wca[1] += pb * w1;
	    wcb[1] += pa * w1;
	}
	++(*kr);
	return 0;
    }
    if (*na > 1 && *nb > 1) {

/*   BOTH ATOMS 'A' AND 'B' ARE HEAVY ATOMS */


/*  THIS COMMENTED-OUT CODE RUNS SLOWER ON A SCALAR MACHINE THAN THE */
/*  EXPLICIT CODE ACTUALLY USED HERE.  THE CODE COMMENTED OUT IS PROVIDED */
/*  FOR USERS WHO WANT TO VECTORIZE THE CODE */

/* #         IJP=0 */
/* #         DO 3 II=1,4 */
/* #         DO 4 JJ=1,II */
/* #         IJ=IJP*10 */
/* #         IJP=IJP+1 */
/* #         KL=-10+IJP */
/* #         SUM1=0.D0 */
/* #         SUM2=0.D0 */
/* #         JI=0 */
/* #         DO 10 I=1,4 */
/* #            DO 10 J=1,I */
/* #               JI=JI+1 */
/* #               IJ=IJ+1 */
/* #               KL=KL+10 */
/* #               FACT=1.D0 */
/* #               IF(I.EQ.J)FACT=0.5D0 */
/* #               SUM1=SUM1+CB(JI)*W(IJ)*FACT */
/* #   10    SUM2=SUM2+CA(JI)*W(KL)*FACT */
/* #      IF(II.EQ.JJ)THEN */
/* #      SUM1=SUM1*0.5D0 */
/* #      SUM2=SUM2*0.5D0 */
/* #      ENDIF */
/* #      WCA(IJP)=WCA(IJP)+SUM1 */
/* #      WCB(IJP)=WCB(IJP)+SUM2 */
/* #   4  CONTINUE */
/* #   3  CONTINUE */

/*   START OF EXPLICIT CODE */

	wca[1] = wca[1] + (cb[1] * w[1] + cb[3] * w[3] + cb[6] * w[6] + cb[10]
		 * w[10]) * .25 + (cb[2] * w[2] + cb[4] * w[4] + cb[5] * w[5] 
		+ cb[7] * w[7] + cb[8] * w[8] + cb[9] * w[9]) * .5;
	wca[2] = wca[2] + (cb[1] * w[11] + cb[3] * w[13] + cb[6] * w[16] + cb[
		10] * w[20]) * .5 + cb[2] * w[12] + cb[4] * w[14] + cb[5] * w[
		15] + cb[7] * w[17] + cb[8] * w[18] + cb[9] * w[19];
	wca[3] = wca[3] + (cb[1] * w[21] + cb[3] * w[23] + cb[6] * w[26] + cb[
		10] * w[30]) * .25 + (cb[2] * w[22] + cb[4] * w[24] + cb[5] * 
		w[25] + cb[7] * w[27] + cb[8] * w[28] + cb[9] * w[29]) * .5;
	wca[4] = wca[4] + (cb[1] * w[31] + cb[3] * w[33] + cb[6] * w[36] + cb[
		10] * w[40]) * .5 + cb[2] * w[32] + cb[4] * w[34] + cb[5] * w[
		35] + cb[7] * w[37] + cb[8] * w[38] + cb[9] * w[39];
	wca[5] = wca[5] + (cb[1] * w[41] + cb[3] * w[43] + cb[6] * w[46] + cb[
		10] * w[50]) * .5 + cb[2] * w[42] + cb[4] * w[44] + cb[5] * w[
		45] + cb[7] * w[47] + cb[8] * w[48] + cb[9] * w[49];
	wca[6] = wca[6] + (cb[1] * w[51] + cb[3] * w[53] + cb[6] * w[56] + cb[
		10] * w[60]) * .25 + (cb[2] * w[52] + cb[4] * w[54] + cb[5] * 
		w[55] + cb[7] * w[57] + cb[8] * w[58] + cb[9] * w[59]) * .5;
	wca[7] = wca[7] + (cb[1] * w[61] + cb[3] * w[63] + cb[6] * w[66] + cb[
		10] * w[70]) * .5 + cb[2] * w[62] + cb[4] * w[64] + cb[5] * w[
		65] + cb[7] * w[67] + cb[8] * w[68] + cb[9] * w[69];
	wca[8] = wca[8] + (cb[1] * w[71] + cb[3] * w[73] + cb[6] * w[76] + cb[
		10] * w[80]) * .5 + cb[2] * w[72] + cb[4] * w[74] + cb[5] * w[
		75] + cb[7] * w[77] + cb[8] * w[78] + cb[9] * w[79];
	wca[9] = wca[9] + (cb[1] * w[81] + cb[3] * w[83] + cb[6] * w[86] + cb[
		10] * w[90]) * .5 + cb[2] * w[82] + cb[4] * w[84] + cb[5] * w[
		85] + cb[7] * w[87] + cb[8] * w[88] + cb[9] * w[89];
	wca[10] = wca[10] + (cb[1] * w[91] + cb[3] * w[93] + cb[6] * w[96] + 
		cb[10] * w[100]) * .25 + (cb[2] * w[92] + cb[4] * w[94] + cb[
		5] * w[95] + cb[7] * w[97] + cb[8] * w[98] + cb[9] * w[99]) * 
		.5;
	wcb[1] = wcb[1] + (ca[1] * w[1] + ca[3] * w[21] + ca[6] * w[51] + ca[
		10] * w[91]) * .25 + (ca[2] * w[11] + ca[4] * w[31] + ca[5] * 
		w[41] + ca[7] * w[61] + ca[8] * w[71] + ca[9] * w[81]) * .5;
	wcb[2] = wcb[2] + (ca[1] * w[2] + ca[3] * w[22] + ca[6] * w[52] + ca[
		10] * w[92]) * .5 + ca[2] * w[12] + ca[4] * w[32] + ca[5] * w[
		42] + ca[7] * w[62] + ca[8] * w[72] + ca[9] * w[82];
	wcb[3] = wcb[3] + (ca[1] * w[3] + ca[3] * w[23] + ca[6] * w[53] + ca[
		10] * w[93]) * .25 + (ca[2] * w[13] + ca[4] * w[33] + ca[5] * 
		w[43] + ca[7] * w[63] + ca[8] * w[73] + ca[9] * w[83]) * .5;
	wcb[4] = wcb[4] + (ca[1] * w[4] + ca[3] * w[24] + ca[6] * w[54] + ca[
		10] * w[94]) * .5 + ca[2] * w[14] + ca[4] * w[34] + ca[5] * w[
		44] + ca[7] * w[64] + ca[8] * w[74] + ca[9] * w[84];
	wcb[5] = wcb[5] + (ca[1] * w[5] + ca[3] * w[25] + ca[6] * w[55] + ca[
		10] * w[95]) * .5 + ca[2] * w[15] + ca[4] * w[35] + ca[5] * w[
		45] + ca[7] * w[65] + ca[8] * w[75] + ca[9] * w[85];
	wcb[6] = wcb[6] + (ca[1] * w[6] + ca[3] * w[26] + ca[6] * w[56] + ca[
		10] * w[96]) * .25 + (ca[2] * w[16] + ca[4] * w[36] + ca[5] * 
		w[46] + ca[7] * w[66] + ca[8] * w[76] + ca[9] * w[86]) * .5;
	wcb[7] = wcb[7] + (ca[1] * w[7] + ca[3] * w[27] + ca[6] * w[57] + ca[
		10] * w[97]) * .5 + ca[2] * w[17] + ca[4] * w[37] + ca[5] * w[
		47] + ca[7] * w[67] + ca[8] * w[77] + ca[9] * w[87];
	wcb[8] = wcb[8] + (ca[1] * w[8] + ca[3] * w[28] + ca[6] * w[58] + ca[
		10] * w[98]) * .5 + ca[2] * w[18] + ca[4] * w[38] + ca[5] * w[
		48] + ca[7] * w[68] + ca[8] * w[78] + ca[9] * w[88];
	wcb[9] = wcb[9] + (ca[1] * w[9] + ca[3] * w[29] + ca[6] * w[59] + ca[
		10] * w[99]) * .5 + ca[2] * w[19] + ca[4] * w[39] + ca[5] * w[
		49] + ca[7] * w[69] + ca[8] * w[79] + ca[9] * w[89];
	wcb[10] = wcb[10] + (ca[1] * w[10] + ca[3] * w[30] + ca[6] * w[60] + 
		ca[10] * w[100]) * .25 + (ca[2] * w[20] + ca[4] * w[40] + ca[
		5] * w[50] + ca[7] * w[70] + ca[8] * w[80] + ca[9] * w[90]) * 
		.5;

/*   END OF EXPLICIT CODE */

    } else if (*na > 1) {

/*   ATOM 'A' IS NOT A HYDROGEN, ATOM 'B' IS A HYDROGEN */

	sum = 0.;
	ij = 0;
	for (i__ = 1; i__ <= 4; ++i__) {
	    i__1 = i__ - 1;
	    for (j = 1; j <= i__1; ++j) {
		++ij;
		sum += ca[ij] * w[ij];
/* L10: */
		wca[ij] += cb[1] * w[ij] * .5;
	    }
	    ++ij;
	    sum += ca[ij] * w[ij] * .5;
/* L20: */
	    wca[ij] += cb[1] * w[ij] * .25;
	}
	wcb[1] += sum * .5;
    } else if (*nb > 1) {

	sum = 0.;
	ij = 0;
	for (i__ = 1; i__ <= 4; ++i__) {
	    i__1 = i__ - 1;
	    for (j = 1; j <= i__1; ++j) {
		++ij;
		sum += cb[ij] * w[ij];
/* L30: */
		wcb[ij] += ca[1] * w[ij] * .5;
	    }
	    ++ij;
	    sum += cb[ij] * w[ij] * .5;
/* L40: */
	    wcb[ij] += ca[1] * w[ij] * .25;
	}
	wca[1] += sum * .5;
    } else if (*nb > 1) {

/*   ATOM 'A' IS A HYDROGEN, ATOM 'B' IS NOT A HYDROGEN */

    } else {

/*   BOTH ATOMS 'A' AND 'B' ARE HYDROGENS */

	wcb[1] += ca[1] * w[1] * .25;
	wca[1] += cb[1] * w[1] * .25;
    }
    *kr += *na * *nb;
    return 0;
} /* formxy_ */

