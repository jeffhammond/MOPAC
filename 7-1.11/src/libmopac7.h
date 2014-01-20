/* libmopac7.h ; written by Tommi Hassinen 2005 as a part of mopac7 package */
/* this is a set of C wrapper functions NOT contained in the fortran sources */

/* these are from fortran source files :
   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
extern "C" void lm7start_(void);
extern "C" void lm7stop_(void);

extern "C" int lm7iniplt_(void);

extern "C" int getesp_(void);
extern "C" int geteldens_(void);
extern "C" int getorb_(void);

/* the rest are from libmopac7.c :
   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ */
extern "C" void lm7_ini_full_xyz(void);

extern "C" int lm7_get_atom_count(void);
extern "C" int lm7_get_electron_count(void);

extern "C" void lm7_set_atom_crd(int, double *);		/* unit is nm */

extern "C" void lm7_call_compfg(double *, double *, int);
extern "C" void lm7_get_atom_grad(int, double *);		/* unit is kJ/mol nm^2 ??? */

extern "C" int lm7_get_orbital_count(void);
extern "C" void lm7_set_plots_orbital_index(int);
extern "C" double lm7_get_orbital_energy(int);			/* unit is ??? */

extern "C" void lm7_set_num_potesp(int);
extern "C" void lm7_set_crd_potesp(int, double *);
extern "C" double lm7_get_val_potesp(int);

/* END */
