/* delmol.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    doublereal ds[16], dg[22], dr[100], tdx[3], tdy[3], tdz[3];
} derivs_;

#define derivs_1 derivs_

struct {
    doublereal g[22], tx[3], ty[3], tz[3];
} extra_;

#define extra_1 extra_

/* Table of constant values */

static integer c__2 = 2;

/* Subroutine */ int delmol_(doublereal *coord, integer *i__, integer *j, 
	integer *ni, integer *nj, integer *ia, integer *id, integer *ja, 
	integer *jd, integer *ix, doublereal *rij, doublereal *tomb, integer *
	isp)
{
    /* System generated locals */
    integer i__1, i__2, i__3, i__4;

    /* Local variables */
    static integer k, l, m, n, ib, jb, kk, ll, mm, nn;
    static doublereal temp1, temp2;
    extern /* Subroutine */ int rotat_(doublereal *, integer *, integer *, 
	    integer *, doublereal *, doublereal *, integer *);

    /* Parameter adjustments */
    coord -= 4;

    /* Function Body */
    if (*ni > 1 || *nj > 1) {
	rotat_(&coord[4], i__, j, ix, rij, tomb, &c__2);
    }
    ib = max(*ia,*id);
    jb = max(*ja,*jd);
    i__1 = ib;
    for (k = *ia; k <= i__1; ++k) {
	kk = k - *ia;
	i__2 = ib;
	for (l = k; l <= i__2; ++l) {
	    ll = l - *ia;
	    i__3 = jb;
	    for (m = *ja; m <= i__3; ++m) {
		mm = m - *ja;
		i__4 = jb;
		for (n = m; n <= i__4; ++n) {
		    nn = n - *ja;
		    ++(*isp);
		    if (nn == 0) {
			if (ll == 0) {
/*   (SS/SS) */
			    derivs_1.dr[*isp - 1] = derivs_1.dg[0];
			} else if (kk == 0) {
/*   (SP/SS) */
			    derivs_1.dr[*isp - 1] = derivs_1.dg[1] * 
				    extra_1.tx[ll - 1] + extra_1.g[1] * 
				    derivs_1.tdx[ll - 1];
			} else {
/*   (PP/SS) */
			    derivs_1.dr[*isp - 1] = derivs_1.dg[2] * 
				    extra_1.tx[kk - 1] * extra_1.tx[ll - 1] + 
				    extra_1.g[2] * (derivs_1.tdx[kk - 1] * 
				    extra_1.tx[ll - 1] + extra_1.tx[kk - 1] * 
				    derivs_1.tdx[ll - 1]) + derivs_1.dg[3] * (
				    extra_1.ty[kk - 1] * extra_1.ty[ll - 1] + 
				    extra_1.tz[kk - 1] * extra_1.tz[ll - 1]) 
				    + extra_1.g[3] * (derivs_1.tdy[kk - 1] * 
				    extra_1.ty[ll - 1] + extra_1.ty[kk - 1] * 
				    derivs_1.tdy[ll - 1] + derivs_1.tdz[kk - 
				    1] * extra_1.tz[ll - 1] + extra_1.tz[kk - 
				    1] * derivs_1.tdz[ll - 1]);
			}
		    } else if (mm == 0) {
			if (ll == 0) {
/*   (SS/SP) */
			    derivs_1.dr[*isp - 1] = derivs_1.dg[4] * 
				    extra_1.tx[nn - 1] + extra_1.g[4] * 
				    derivs_1.tdx[nn - 1];
			} else if (kk == 0) {
/*   (SP/SP) */
			    derivs_1.dr[*isp - 1] = derivs_1.dg[5] * 
				    extra_1.tx[ll - 1] * extra_1.tx[nn - 1] + 
				    extra_1.g[5] * (derivs_1.tdx[ll - 1] * 
				    extra_1.tx[nn - 1] + extra_1.tx[ll - 1] * 
				    derivs_1.tdx[nn - 1]) + derivs_1.dg[6] * (
				    extra_1.ty[ll - 1] * extra_1.ty[nn - 1] + 
				    extra_1.tz[ll - 1] * extra_1.tz[nn - 1]) 
				    + extra_1.g[6] * (derivs_1.tdy[ll - 1] * 
				    extra_1.ty[nn - 1] + extra_1.ty[ll - 1] * 
				    derivs_1.tdy[nn - 1] + derivs_1.tdz[ll - 
				    1] * extra_1.tz[nn - 1] + extra_1.tz[ll - 
				    1] * derivs_1.tdz[nn - 1]);
			} else {
/*   (PP/SP) */
			    derivs_1.dr[*isp - 1] = derivs_1.dg[7] * 
				    extra_1.tx[kk - 1] * extra_1.tx[ll - 1] * 
				    extra_1.tx[nn - 1] + extra_1.g[7] * (
				    derivs_1.tdx[kk - 1] * extra_1.tx[ll - 1] 
				    * extra_1.tx[nn - 1] + extra_1.tx[kk - 1] 
				    * derivs_1.tdx[ll - 1] * extra_1.tx[nn - 
				    1] + extra_1.tx[kk - 1] * extra_1.tx[ll - 
				    1] * derivs_1.tdx[nn - 1]) + derivs_1.dg[
				    8] * (extra_1.ty[kk - 1] * extra_1.ty[ll 
				    - 1] + extra_1.tz[kk - 1] * extra_1.tz[ll 
				    - 1]) * extra_1.tx[nn - 1] + extra_1.g[8] 
				    * ((derivs_1.tdy[kk - 1] * extra_1.ty[ll 
				    - 1] + extra_1.ty[kk - 1] * derivs_1.tdy[
				    ll - 1] + derivs_1.tdz[kk - 1] * 
				    extra_1.tz[ll - 1] + extra_1.tz[kk - 1] * 
				    derivs_1.tdz[ll - 1]) * extra_1.tx[nn - 1]
				     + (extra_1.ty[kk - 1] * extra_1.ty[ll - 
				    1] + extra_1.tz[kk - 1] * extra_1.tz[ll - 
				    1]) * derivs_1.tdx[nn - 1]) + derivs_1.dg[
				    9] * (extra_1.tx[kk - 1] * (extra_1.ty[ll 
				    - 1] * extra_1.ty[nn - 1] + extra_1.tz[ll 
				    - 1] * extra_1.tz[nn - 1]) + extra_1.tx[
				    ll - 1] * (extra_1.ty[kk - 1] * 
				    extra_1.ty[nn - 1] + extra_1.tz[kk - 1] * 
				    extra_1.tz[nn - 1])) + extra_1.g[9] * (
				    derivs_1.tdx[kk - 1] * (extra_1.ty[ll - 1]
				     * extra_1.ty[nn - 1] + extra_1.tz[ll - 1]
				     * extra_1.tz[nn - 1]) + derivs_1.tdx[ll 
				    - 1] * (extra_1.ty[kk - 1] * extra_1.ty[
				    nn - 1] + extra_1.tz[kk - 1] * extra_1.tz[
				    nn - 1]) + extra_1.tx[kk - 1] * (
				    derivs_1.tdy[ll - 1] * extra_1.ty[nn - 1] 
				    + extra_1.ty[ll - 1] * derivs_1.tdy[nn - 
				    1] + derivs_1.tdz[ll - 1] * extra_1.tz[nn 
				    - 1] + extra_1.tz[ll - 1] * derivs_1.tdz[
				    nn - 1]) + extra_1.tx[ll - 1] * (
				    derivs_1.tdy[kk - 1] * extra_1.ty[nn - 1] 
				    + extra_1.ty[kk - 1] * derivs_1.tdy[nn - 
				    1] + derivs_1.tdz[kk - 1] * extra_1.tz[nn 
				    - 1] + extra_1.tz[kk - 1] * derivs_1.tdz[
				    nn - 1]));
			}
		    } else if (ll == 0) {
/*   (SS/PP) */
			derivs_1.dr[*isp - 1] = derivs_1.dg[10] * extra_1.tx[
				mm - 1] * extra_1.tx[nn - 1] + extra_1.g[10] *
				 (derivs_1.tdx[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tx[mm - 1] * derivs_1.tdx[nn - 1]) + 
				derivs_1.dg[11] * (extra_1.ty[mm - 1] * 
				extra_1.ty[nn - 1] + extra_1.tz[mm - 1] * 
				extra_1.tz[nn - 1]) + extra_1.g[11] * (
				derivs_1.tdy[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.ty[mm - 1] * derivs_1.tdy[nn - 1] + 
				derivs_1.tdz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[mm - 1] * derivs_1.tdz[nn - 1]);
		    } else if (kk == 0) {
/*   (SP/PP) */
			derivs_1.dr[*isp - 1] = derivs_1.dg[12] * extra_1.tx[
				ll - 1] * extra_1.tx[mm - 1] * extra_1.tx[nn 
				- 1] + extra_1.g[12] * (derivs_1.tdx[ll - 1] *
				 extra_1.tx[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tx[ll - 1] * derivs_1.tdx[mm - 1] * 
				extra_1.tx[nn - 1] + extra_1.tx[ll - 1] * 
				extra_1.tx[mm - 1] * derivs_1.tdx[nn - 1]) + 
				derivs_1.dg[13] * extra_1.tx[ll - 1] * (
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1]) + 
				extra_1.g[13] * (derivs_1.tdx[ll - 1] * (
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1]) + 
				extra_1.tx[ll - 1] * (derivs_1.tdy[mm - 1] * 
				extra_1.ty[nn - 1] + extra_1.ty[mm - 1] * 
				derivs_1.tdy[nn - 1] + derivs_1.tdz[mm - 1] * 
				extra_1.tz[nn - 1] + extra_1.tz[mm - 1] * 
				derivs_1.tdz[nn - 1])) + derivs_1.dg[14] * (
				extra_1.ty[ll - 1] * (extra_1.ty[mm - 1] * 
				extra_1.tx[nn - 1] + extra_1.ty[nn - 1] * 
				extra_1.tx[mm - 1]) + extra_1.tz[ll - 1] * (
				extra_1.tz[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tz[nn - 1] * extra_1.tx[mm - 1])) + 
				extra_1.g[14] * (derivs_1.tdy[ll - 1] * (
				extra_1.ty[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.ty[nn - 1] * extra_1.tx[mm - 1]) + 
				derivs_1.tdz[ll - 1] * (extra_1.tz[mm - 1] * 
				extra_1.tx[nn - 1] + extra_1.tz[nn - 1] * 
				extra_1.tx[mm - 1]) + extra_1.ty[ll - 1] * (
				derivs_1.tdy[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.ty[mm - 1] * derivs_1.tdx[nn - 1] + 
				derivs_1.tdy[nn - 1] * extra_1.tx[mm - 1] + 
				extra_1.ty[nn - 1] * derivs_1.tdx[mm - 1]) + 
				extra_1.tz[ll - 1] * (derivs_1.tdz[mm - 1] * 
				extra_1.tx[nn - 1] + extra_1.tz[mm - 1] * 
				derivs_1.tdx[nn - 1] + derivs_1.tdz[nn - 1] * 
				extra_1.tx[mm - 1] + extra_1.tz[nn - 1] * 
				derivs_1.tdx[mm - 1]));
		    } else {
/*   (PP/PP) */
			derivs_1.dr[*isp - 1] = derivs_1.dg[15] * extra_1.tx[
				kk - 1] * extra_1.tx[ll - 1] * extra_1.tx[mm 
				- 1] * extra_1.tx[nn - 1] + extra_1.g[15] * (
				derivs_1.tdx[kk - 1] * extra_1.tx[ll - 1] * 
				extra_1.tx[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tx[kk - 1] * derivs_1.tdx[ll - 1] * 
				extra_1.tx[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tx[kk - 1] * extra_1.tx[ll - 1] * 
				derivs_1.tdx[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tx[kk - 1] * extra_1.tx[ll - 1] * 
				extra_1.tx[mm - 1] * derivs_1.tdx[nn - 1]) + 
				derivs_1.dg[16] * (extra_1.ty[kk - 1] * 
				extra_1.ty[ll - 1] + extra_1.tz[kk - 1] * 
				extra_1.tz[ll - 1]) * extra_1.tx[mm - 1] * 
				extra_1.tx[nn - 1] + extra_1.g[16] * ((
				derivs_1.tdy[kk - 1] * extra_1.ty[ll - 1] + 
				extra_1.ty[kk - 1] * derivs_1.tdy[ll - 1] + 
				derivs_1.tdz[kk - 1] * extra_1.tz[ll - 1] + 
				extra_1.tz[kk - 1] * derivs_1.tdz[ll - 1]) * 
				extra_1.tx[mm - 1] * extra_1.tx[nn - 1] + (
				extra_1.ty[kk - 1] * extra_1.ty[ll - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[ll - 1]) * (
				derivs_1.tdx[mm - 1] * extra_1.tx[nn - 1] + 
				extra_1.tx[mm - 1] * derivs_1.tdx[nn - 1])) + 
				derivs_1.dg[17] * extra_1.tx[kk - 1] * 
				extra_1.tx[ll - 1] * (extra_1.ty[mm - 1] * 
				extra_1.ty[nn - 1] + extra_1.tz[mm - 1] * 
				extra_1.tz[nn - 1]) + extra_1.g[17] * ((
				derivs_1.tdx[kk - 1] * extra_1.tx[ll - 1] + 
				extra_1.tx[kk - 1] * derivs_1.tdx[ll - 1]) * (
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1]) + 
				extra_1.tx[kk - 1] * extra_1.tx[ll - 1] * (
				derivs_1.tdy[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.ty[mm - 1] * derivs_1.tdy[nn - 1] + 
				derivs_1.tdz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[mm - 1] * derivs_1.tdz[nn - 1]));
			derivs_1.dr[*isp - 1] = derivs_1.dr[*isp - 1] + 
				derivs_1.dg[18] * (extra_1.ty[kk - 1] * 
				extra_1.ty[ll - 1] * extra_1.ty[mm - 1] * 
				extra_1.ty[nn - 1] + extra_1.tz[kk - 1] * 
				extra_1.tz[ll - 1] * extra_1.tz[mm - 1] * 
				extra_1.tz[nn - 1]) + extra_1.g[18] * (
				derivs_1.tdy[kk - 1] * extra_1.ty[ll - 1] * 
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.ty[kk - 1] * derivs_1.tdy[ll - 1] * 
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.ty[kk - 1] * extra_1.ty[ll - 1] * 
				derivs_1.tdy[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.ty[kk - 1] * extra_1.ty[ll - 1] * 
				extra_1.ty[mm - 1] * derivs_1.tdy[nn - 1] + 
				derivs_1.tdz[kk - 1] * extra_1.tz[ll - 1] * 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[kk - 1] * derivs_1.tdz[ll - 1] * 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[ll - 1] * 
				derivs_1.tdz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[ll - 1] * 
				extra_1.tz[mm - 1] * derivs_1.tdz[nn - 1]) + 
				derivs_1.dg[19] * (extra_1.tx[kk - 1] * (
				extra_1.tx[mm - 1] * (extra_1.ty[ll - 1] * 
				extra_1.ty[nn - 1] + extra_1.tz[ll - 1] * 
				extra_1.tz[nn - 1]) + extra_1.tx[nn - 1] * (
				extra_1.ty[ll - 1] * extra_1.ty[mm - 1] + 
				extra_1.tz[ll - 1] * extra_1.tz[mm - 1])) + 
				extra_1.tx[ll - 1] * (extra_1.tx[mm - 1] * (
				extra_1.ty[kk - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[nn - 1]) + 
				extra_1.tx[nn - 1] * (extra_1.ty[kk - 1] * 
				extra_1.ty[mm - 1] + extra_1.tz[kk - 1] * 
				extra_1.tz[mm - 1])));
/*      TO AVOID COMPILER DIFFICULTIES THIS IS DIVIDED */
			temp1 = derivs_1.tdx[kk - 1] * (extra_1.tx[mm - 1] * (
				extra_1.ty[ll - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[ll - 1] * extra_1.tz[nn - 1]) + 
				extra_1.tx[nn - 1] * (extra_1.ty[ll - 1] * 
				extra_1.ty[mm - 1] + extra_1.tz[ll - 1] * 
				extra_1.tz[mm - 1])) + derivs_1.tdx[ll - 1] * 
				(extra_1.tx[mm - 1] * (extra_1.ty[kk - 1] * 
				extra_1.ty[nn - 1] + extra_1.tz[kk - 1] * 
				extra_1.tz[nn - 1]) + extra_1.tx[nn - 1] * (
				extra_1.ty[kk - 1] * extra_1.ty[mm - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[mm - 1])) + 
				extra_1.tx[kk - 1] * (derivs_1.tdx[mm - 1] * (
				extra_1.ty[ll - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[ll - 1] * extra_1.tz[nn - 1]) + 
				derivs_1.tdx[nn - 1] * (extra_1.ty[ll - 1] * 
				extra_1.ty[mm - 1] + extra_1.tz[ll - 1] * 
				extra_1.tz[mm - 1])) + extra_1.tx[ll - 1] * (
				derivs_1.tdx[mm - 1] * (extra_1.ty[kk - 1] * 
				extra_1.ty[nn - 1] + extra_1.tz[kk - 1] * 
				extra_1.tz[nn - 1]) + derivs_1.tdx[nn - 1] * (
				extra_1.ty[kk - 1] * extra_1.ty[mm - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[mm - 1]));
			temp2 = extra_1.tx[kk - 1] * (extra_1.tx[mm - 1] * (
				derivs_1.tdy[ll - 1] * extra_1.ty[nn - 1] + 
				extra_1.ty[ll - 1] * derivs_1.tdy[nn - 1] + 
				derivs_1.tdz[ll - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[ll - 1] * derivs_1.tdz[nn - 1]) + 
				extra_1.tx[nn - 1] * (derivs_1.tdy[ll - 1] * 
				extra_1.ty[mm - 1] + extra_1.ty[ll - 1] * 
				derivs_1.tdy[mm - 1] + derivs_1.tdz[ll - 1] * 
				extra_1.tz[mm - 1] + extra_1.tz[ll - 1] * 
				derivs_1.tdz[mm - 1])) + extra_1.tx[ll - 1] * 
				(extra_1.tx[mm - 1] * (derivs_1.tdy[kk - 1] * 
				extra_1.ty[nn - 1] + extra_1.ty[kk - 1] * 
				derivs_1.tdy[nn - 1] + derivs_1.tdz[kk - 1] * 
				extra_1.tz[nn - 1] + extra_1.tz[kk - 1] * 
				derivs_1.tdz[nn - 1]) + extra_1.tx[nn - 1] * (
				derivs_1.tdy[kk - 1] * extra_1.ty[mm - 1] + 
				extra_1.ty[kk - 1] * derivs_1.tdy[mm - 1] + 
				derivs_1.tdz[kk - 1] * extra_1.tz[mm - 1] + 
				extra_1.tz[kk - 1] * derivs_1.tdz[mm - 1]));
			derivs_1.dr[*isp - 1] += extra_1.g[19] * (temp1 + 
				temp2);
			derivs_1.dr[*isp - 1] = derivs_1.dr[*isp - 1] + 
				derivs_1.dg[20] * (extra_1.ty[kk - 1] * 
				extra_1.ty[ll - 1] * extra_1.tz[mm - 1] * 
				extra_1.tz[nn - 1] + extra_1.tz[kk - 1] * 
				extra_1.tz[ll - 1] * extra_1.ty[mm - 1] * 
				extra_1.ty[nn - 1]) + extra_1.g[20] * (
				derivs_1.tdy[kk - 1] * extra_1.ty[ll - 1] * 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.ty[kk - 1] * derivs_1.tdy[ll - 1] * 
				extra_1.tz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.ty[kk - 1] * extra_1.ty[ll - 1] * 
				derivs_1.tdz[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.ty[kk - 1] * extra_1.ty[ll - 1] * 
				extra_1.tz[mm - 1] * derivs_1.tdz[nn - 1] + 
				derivs_1.tdz[kk - 1] * extra_1.tz[ll - 1] * 
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[kk - 1] * derivs_1.tdz[ll - 1] * 
				extra_1.ty[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[ll - 1] * 
				derivs_1.tdy[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[kk - 1] * extra_1.tz[ll - 1] * 
				extra_1.ty[mm - 1] * derivs_1.tdy[nn - 1]);
			derivs_1.dr[*isp - 1] = derivs_1.dr[*isp - 1] + 
				derivs_1.dg[21] * (extra_1.ty[kk - 1] * 
				extra_1.tz[ll - 1] + extra_1.tz[kk - 1] * 
				extra_1.ty[ll - 1]) * (extra_1.ty[mm - 1] * 
				extra_1.tz[nn - 1] + extra_1.tz[mm - 1] * 
				extra_1.ty[nn - 1]) + extra_1.g[21] * ((
				derivs_1.tdy[kk - 1] * extra_1.tz[ll - 1] + 
				extra_1.ty[kk - 1] * derivs_1.tdz[ll - 1] + 
				derivs_1.tdz[kk - 1] * extra_1.ty[ll - 1] + 
				extra_1.tz[kk - 1] * derivs_1.tdy[ll - 1]) * (
				extra_1.ty[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.tz[mm - 1] * extra_1.ty[nn - 1]) + (
				extra_1.ty[kk - 1] * extra_1.tz[ll - 1] + 
				extra_1.tz[kk - 1] * extra_1.ty[ll - 1]) * (
				derivs_1.tdy[mm - 1] * extra_1.tz[nn - 1] + 
				extra_1.ty[mm - 1] * derivs_1.tdz[nn - 1] + 
				derivs_1.tdz[mm - 1] * extra_1.ty[nn - 1] + 
				extra_1.tz[mm - 1] * derivs_1.tdy[nn - 1]));
		    }
/* L10: */
		}
	    }
	}
    }
    return 0;
} /* delmol_ */

