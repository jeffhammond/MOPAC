/* libmopac7.c ; written by Tommi Hassinen 2005 as a part of mopac7 package */
/* this is a set of C wrapper functions NOT contained in the fortran sources */

#include "f2c.h"

/* these come from MOPAC7/compfg.c */

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
    doublereal elect;
} elect_;

#define elect_1 elect_

struct {
    doublereal enuclr;
} enuclr_;

#define enuclr_1 enuclr_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    doublereal c__[90000], eigs[300], cbeta[90000], eigb[300];
} vector_;

#define vector_1 vector_

/* these come from MOPAC7/force.c */

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

/* these come from MOPAC7/esp.c */

union {
    struct {
	doublereal potpt[150000]	/* was [3][50000] */, work1d[200000];
    } _1;
    struct {
	doublereal potpt[150000]	/* was [3][50000] */, pad1[100000], 
		rad[50000];
	integer ias[50000];
    } _2;
    struct {
	doublereal potpt[150000]	/* was [3][50000] */, es[50000],
		esp[50000], work1d[100000];
    } _3;
} work1_;

#define work1_1 (work1_._1)
#define work1_2 (work1_._2)
#define work1_3 (work1_._3)

struct {
    doublereal xc, yc, zc, espnuc, espele;
    integer nesp;
} potesp_;

#define potesp_1 potesp_

struct {
    doublereal cespm2[90000]	/* was [300][300] */, sla[10], cespml[90000], 
	    cesp[90000];
    integer inc[1800], nc, npr, is, ip, ipc, isc, icd, iorb;
} plots_;

#define plots_1 plots_

/****************************************************/
/* these are some definitions that do not change!!! */
/****************************************************/

static logical c_true = TRUE_;		/* the idea is that these are CONST */
static logical c_false = FALSE_;	/* the idea is that these are CONST */

extern int compfg_(doublereal *, logical *, doublereal *, logical *, doublereal *, logical *);

/**************************************************/
/* these are the libmopac7.c utility functions!!! */
/**************************************************/

void lm7_ini_full_xyz(void)
{
	int var_i;
	
/*	by default, MOPAC changes the molecule orientation, and limits the available variables.
	we will change it here, by writing our own variable table. THIS IS FOR XYZ MODE ONLY!	*/
	
	geovar_1.nvar = geokst_1.natoms * 3;
	
	for (var_i = 0;var_i < geovar_1.nvar;var_i++)
	{
		geovar_1.loc[var_i * 2 + 0] = (var_i / 3) + 1;
	}
	
	for (var_i = 0;var_i < geovar_1.nvar;var_i++)
	{
		geovar_1.loc[var_i * 2 + 1] = (var_i % 3) + 1;
	}
	
/*	ok, but now we still have to update the geometry before doing calculations...
	that will happen on each call of the energy functions separately.	*/
}

int lm7_get_atom_count(void)
{
	return geokst_1.natoms;
}

int lm7_get_electron_count(void)
{
	return molkst_1.nelecs;		/* for an RHF case... */
}

void lm7_set_atom_crd(int atm_i, double * xyz)
{
	const double cf = 10.0;		/* conversion factor for [nm] -> [Å] */
	
	geovar_1.dumy[atm_i * 3 + 0] = xyz[0] * cf;
	geovar_1.dumy[atm_i * 3 + 1] = xyz[1] * cf;
	geovar_1.dumy[atm_i * 3 + 2] = xyz[2] * cf;
}

void lm7_call_compfg(double * e, double * hf, int comp_grad)
{
	static doublereal escf;
	const double cf = 96.4853;	/* conversion factor for [eV] -> [kJ/mol] */
	
	if (comp_grad == 0)		/* energy was requested... */
	{
		compfg_(geovar_1.dumy, &c_true, &escf, &c_true, gradnt_1.grad, &c_false);
		
		(* e) = (elect_1.elect + enuclr_1.enuclr) * cf;
		(* hf) = escf;
	}
	else				/* both energy and gradient were requested... */
	{
		compfg_(geovar_1.dumy, &c_true, &escf, &c_true, gradnt_1.grad, &c_true);
		
		(* e) = (elect_1.elect + enuclr_1.enuclr) * cf;
		(* hf) = escf;
	}
}

void lm7_get_atom_grad(int atm_i, double * xyz)
{
	const double cf = 41.868;	/* conversion factors for [cal] -> [J] and [nm] -> [Å] */
	
	xyz[0] = gradnt_1.grad[atm_i * 3 + 0] * cf;
	xyz[1] = gradnt_1.grad[atm_i * 3 + 1] * cf;
	xyz[2] = gradnt_1.grad[atm_i * 3 + 2] * cf;
}

int lm7_get_orbital_count(void)
{
	return molkst_1.norbs;		/* for an RHF case... */

/*	cout << "norbs = " << molkst_1.norbs << endl;
	cout << "nalpha = " << molkst_1.nalpha << endl;		*/
}

void lm7_set_plots_orbital_index(int orb_i)
{
	plots_1.iorb = orb_i;
}

double lm7_get_orbital_energy(int orb_i)
{
	return vector_1.eigs[orb_i];
}

void lm7_set_num_potesp(int n_potesp)
{
	potesp_1.nesp = n_potesp;
}

void lm7_set_crd_potesp(int potesp_i, double * xyz)
{
	work1_3.potpt[potesp_i * 3 + 0] = xyz[0];
	work1_3.potpt[potesp_i * 3 + 1] = xyz[1];
	work1_3.potpt[potesp_i * 3 + 2] = xyz[2];
}

double lm7_get_val_potesp(int potesp_i)
{
	return work1_3.esp[potesp_i];
}

/* END */
