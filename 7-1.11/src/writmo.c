/* writmo.f -- translated by f2c (version 20020621).
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
    char elemnt[214];
} elemts_;

#define elemts_1 elemts_

struct {
    doublereal geo[360]	/* was [3][120] */, xcoord[360]	/* was [3][120] */;
} geom_;

#define geom_1 geom_

struct {
    integer natoms, labels[120], na[120], nb[120], nc[120];
} geokst_;

#define geokst_1 geokst_

struct {
    doublereal h__[45150];
} hmatrx_;

#define hmatrx_1 hmatrx_

struct {
    doublereal f[45150], fb[45150];
} fokmat_;

#define fokmat_1 fokmat_

struct {
    doublereal c__[90000], eigs[300], cbeta[90000], eigb[300];
} vector_;

#define vector_1 vector_

struct {
    doublereal p[45150], pa[45150], pb[45150];
} densty_;

#define densty_1 densty_

struct {
    integer ndep, locpar[360], idepfn[360], locdep[360];
} geosym_;

#define geosym_1 geosym_

struct {
    doublereal tvec[9]	/* was [3][3] */;
    integer id;
} euler_;

#define euler_1 euler_

struct {
    doublereal rjkab[64]	/* was [8][8] */, rjkaa[64]	/* was [8][8] 
	    */;
} rjks_;

#define rjks_1 rjks_

struct {
    doublereal errfn[360], aicorr[360];
} errfn_;

#define errfn_1 errfn_

struct {
    doublereal fmat2d[180600];
    complex sec[90300], vec[90300];
    doublereal alband[586950];
} work1_;

#define work1_1 work1_

struct {
    integer latom, lparam;
    doublereal react[200];
} path_;

#define path_1 path_

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    integer nscf;
} numscf_;

#define numscf_1 numscf_

struct {
    doublereal wj[214770], wk[214770];
} wmatrx_;

#define wmatrx_1 wmatrx_

struct {
    doublereal atheat;
} atheat_;

#define atheat_1 atheat_

struct {
    doublereal trans, rtr, sig;
    char name__[4], namo[1920];
    integer indx[480];
    char ista[8];
} symres_;

#define symres_1 symres_

struct {
    doublereal core[107];
} core_;

#define core_1 core_

struct {
    integer last;
} last_;

#define last_1 last_

struct {
    doublereal rxyz[45150], xdumy[84450];
} scrach_;

#define scrach_1 scrach_

struct {
    doublereal engyci[3], vectci[9], eci[6];
} cimats_;

#define cimats_1 cimats_

struct {
    integer iflepo, iiter;
} mesage_;

#define mesage_1 mesage_

struct {
    doublereal atmass[120];
} atmass_;

#define atmass_1 atmass_

struct {
    doublereal enuclr;
} enuclr_;

#define enuclr_1 enuclr_

struct {
    doublereal elect;
} elect_;

#define elect_1 elect_

struct {
    doublereal dxyz[1080];
} xyzgra_;

#define xyzgra_1 xyzgra_

struct {
    doublereal grad[360], gnorm;
} gradnt_;

#define gradnt_1 gradnt_

struct {
    integer numat, nat[120], nfirst[120], nmidle[120], nlast[120], norbs, 
	    nelecs, nalpha, nbeta, nclose, nopen, ndumy;
    doublereal fract;
} molkst_;

#define molkst_1 molkst_

struct {
    integer nvar, loc[720]	/* was [2][360] */, idumy;
    doublereal xparam[360];
} geovar_;

#define geovar_1 geovar_

struct {
    logical iseps, useps, upda;
} iseps_;

#define iseps_1 iseps_

/* Table of constant values */

static integer c__6 = 6;
static integer c__1 = 1;
static doublereal c_b29 = 7.01;
static logical c_false = FALSE_;
static logical c_true = TRUE_;
static integer c__300 = 300;
static integer c__2 = 2;
static doublereal c_b199 = 2.;
static doublereal c_b201 = 1.;
static integer c__0 = 0;

/* Subroutine */ int writmo_(doublereal *time0, doublereal *funct)
{
    /* Initialized data */

    static integer icalcn = 0;
    static char type__[11*3] = "BOND       " "ANGLE      " "DIHEDRAL   ";
    static char calcn[5*2] = "     " "ALPHA";
    static char numbrs[1*11] = "0" "1" "2" "3" "4" "5" "6" "7" "8" "9" " ";
    static char flepo[58*16] = " 1SCF WAS SPECIFIED, SO BFGS WAS NOT USED   "
	    "              " " GRADIENTS WERE INITIALLY ACCEPTABLY SMALL     "
	    "           " " HERBERTS TEST WAS SATISFIED IN BFGS              "
	    "        " " THE LINE MINIMIZATION FAILED TWICE IN A ROW.   TAKE "
	    "CARE!" " BFGS FAILED DUE TO COUNTS EXCEEDED. TAKE CARE!         "
	    "  " " PETERS TEST WAS SATISFIED IN BFGS OPTIMIZATION           " 
	    " THIS MESSAGE SHOULD NEVER APPEAR, CONSULT A PROGRAMMER!! " 
	    " GRADIENT TEST NOT PASSED, BUT FURTHER WORK NOT JUSTIFIED " 
	    " A FAILURE HAS OCCURRED, TREAT RESULTS WITH CAUTION!!     " 
	    " GEOMETRY OPTIMIZED USING NLLSQ. GRADIENT NORM MINIMIZED  " 
	    " GEOMETRY OPTIMIZED USING POWSQ. GRADIENT NORM MINIMIZED  " 
	    " CYCLES EXCEEDED, GRADIENT NOT FULLY MINIMIZED IN NLLSQ   " 
	    " 1SCF RUN AFTER RESTART.  GEOMETRY MIGHT NOT BE OPTIMIZED " 
	    " HEAT OF FORMATION MINIMIZED IN ONE LINE SEARCH           " 
	    " GEOMETRY OPTIMISED USING EIGENVECTOR FOLLOWING (EF).     " 
	    " EF-OPTIMIZED GEOMETRY.  NUMBER OF -VE ROOTS INCORRECT    ";
    static char iter[58*2] = " SCF FIELD WAS ACHIEVED                       "
	    "            " "  ++++----**** FAILED TO ACHIEVE SCF. ****----+++"
	    "+        ";

    /* Format strings */
    static char fmt_180[] = "(//,1x,17(a2,a1,a1))";

    /* System generated locals */
    integer i__1, i__2;
    doublereal d__1, d__2, d__3;
    char ch__1[80];
    olist o__1;
    cllist cl__1;
    alist al__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer i_indx(char *, char *, ftnlen, ftnlen);
    double sqrt(doublereal);
    integer s_wsfe(cilist *), e_wsfe(void), do_fio(integer *, char *, ftnlen);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer f_open(olist *), i_dnnt(doublereal *), f_rew(alist *), s_wsue(
	    cilist *), do_uio(integer *, char *, ftnlen), e_wsue(void), 
	    f_clos(cllist *), s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, k, l;
    static doublereal q[300];
#define w ((doublereal *)&wmatrx_1)
    static doublereal x, q2[300];
    static logical ci;
    static integer iw;
    static doublereal xi, sz, ss2, dip;
    static integer igo;
    static logical uhf;
    extern doublereal dot_(doublereal *, doublereal *, integer *);
    static doublereal tim, sum;
    static integer nzs, iel1[107], iel2[107];
    static doublereal edie;
    extern doublereal meci_(doublereal *, doublereal *);
    static integer loc11, loc21, jend, iend, inam, iuhf, ksec, jnam, mvar, 
	    nopn;
    static doublereal step, dumy[3], sumw;
    static integer mono3;
    extern doublereal reada_(char *, integer *, ftnlen);
    extern /* Subroutine */ int fdate_(char *, ftnlen);
    static char idate[24];
    extern /* Subroutine */ int chrge_(doublereal *, doublereal *), local_(
	    doublereal *, integer *, integer *, doublereal *);
    static doublereal coord[360]	/* was [3][120] */;
    extern /* Subroutine */ int bonds_(doublereal *), deriv_(doublereal *, 
	    doublereal *);
    static logical still;
    static char gtype[13];
    extern /* Subroutine */ int geout_(integer *);
    static integer kfrst;
    extern /* Subroutine */ int matou1_(doublereal *, doublereal *, integer *,
	     integer *, integer *, integer *);
    static doublereal degree;
    extern /* Subroutine */ int dielen_(doublereal *);
    static integer kchrge, nelemt[107];
    static doublereal gcoord[1];
    static logical singlt, excitd, triplt, prtgra;
    static char grtype[14];
    extern /* Character */ VOID getnam_(char *, ftnlen, char *, ftnlen);
    static char ielemt[2*20], caltyp[7], namfil[80];
    static integer linear;
    static doublereal xreact, eionis;
    extern doublereal second_(void);
    extern /* Subroutine */ int timout_(integer *, doublereal *), gmetry_(
	    doublereal *, doublereal *), vecprt_(doublereal *, integer *);
    extern doublereal dipole_(doublereal *, doublereal *, doublereal *, 
	    doublereal *, integer *);
    extern /* Subroutine */ int brlzon_(doublereal *, doublereal *, integer *,
	     complex *, complex *, doublereal *, integer *, doublereal *, 
	    integer *);
    static integer nfilld;
    extern /* Subroutine */ int mpcsyb_(integer *, doublereal *, doublereal *,
	     integer *, doublereal *, integer *, doublereal *, doublereal *, 
	    integer *, doublereal *), denrot_(void), molval_(doublereal *, 
	    doublereal *, integer *, doublereal *), enpart_(logical *, 
	    doublereal *, doublereal *, doublereal *, doublereal *, 
	    doublereal *, doublereal *);
    static integer ichfor;
    extern /* Subroutine */ int mullik_(doublereal *, doublereal *, 
	    doublereal *, integer *, doublereal *, doublereal *), symtry_(
	    void), symtrz_(doublereal *, doublereal *, integer *, integer *, 
	    logical *, logical *), mpcpop_(doublereal *, integer *), greenf_(
	    void);
    static integer iwrite;
    extern /* Subroutine */ int wrttxt_(integer *), geoutg_(integer *);

    /* Fortran I/O blocks */
    static cilist io___20 = { 0, 6, 0, "(/,' ----',15('-----'))", 0 };
    static cilist io___21 = { 0, 6, 0, "(//4X,A58)", 0 };
    static cilist io___22 = { 0, 6, 0, "(4X,A58)", 0 };
    static cilist io___23 = { 0, 6, 0, "(//30X,A7,'  CALCULATION')", 0 };
    static cilist io___24 = { 0, 6, 0, "(55X,'VERSION ',F5.2)", 0 };
    static cilist io___25 = { 0, 6, 0, "(55X,A24)", 0 };
    static cilist io___26 = { 0, 6, 0, "(//,' FOR SOME REASON THE SCF CALCUL"
	    "ATION FAILED.',/,' THE RESULTS WOULD BE MEANINGLESS, SO WILL NOT"
	    " BE PRINTED.')", 0 };
    static cilist io___27 = { 0, 6, 0, "(' TRY TO FIND THE REASON FOR THE FA"
	    "ILURE BY USING ','\"PL\".',/,                                   "
	    "                  ' CHECK YOUR GEOMETRY AND ALSO TRY USING SHIFT"
	    " OR PULAY. ')", 0 };
    static cilist io___28 = { 0, 6, 0, "(////10X,'FINAL HEAT OF FORMATION ='"
	    ",F17.5,' KCAL'   )", 0 };
    static cilist io___29 = { 0, 6, 0, "(/)", 0 };
    static cilist io___30 = { 0, 6, 0, "(    10X,'TOTAL ENERGY            ='"
	    ",F17.5,' EV'     )", 0 };
    static cilist io___31 = { 0, 6, 0, "(    10X,'ELECTRONIC ENERGY       ='"
	    ",F17.5,' EV'     )", 0 };
    static cilist io___32 = { 0, 6, 0, "(    10X,'CORE-CORE REPULSION     ='"
	    ",F17.5,' EV'     )", 0 };
    static cilist io___35 = { 0, 0, 0, "(    10X,'DIELECTRIC ENERGY       ='"
	    ",F17.5,' EV'    )", 0 };
    static cilist io___36 = { 0, 6, 0, "(1X)", 0 };
    static cilist io___37 = { 0, 6, 0, "(    10X,'GRADIENT NORM           ='"
	    ",F17.5)", 0 };
    static cilist io___39 = { 0, 6, 0, "(A)", 0 };
    static cilist io___46 = { 0, 6, 0, "(    10X,'FOR REACTION COORDINATE ='"
	    ",F17.5               ,' ANGSTROMS')", 0 };
    static cilist io___47 = { 0, 6, 0, "(    10X,'FOR REACTION COORDINATE ='"
	    ",F17.5               ,' DEGREES')", 0 };
    static cilist io___48 = { 0, 6, 0, "(    10X,'REACTION GRADIENT       ='"
	    ",F17.5,A14          )", 0 };
    static cilist io___52 = { 0, 6, 0, "(       10X,'IONIZATION POTENTIAL   "
	    " =',F17.5)", 0 };
    static cilist io___53 = { 0, 6, 0, "(      10X,'NO. OF ALPHA ELECTRONS  "
	    "=',I11)", 0 };
    static cilist io___54 = { 0, 6, 0, "(      10X,'NO. OF BETA  ELECTRONS  "
	    "=',I11)", 0 };
    static cilist io___55 = { 0, 6, 0, "(      10X,'NO. OF FILLED LEVELS    "
	    "=',I11)", 0 };
    static cilist io___56 = { 0, 6, 0, "(   10X,'AND NO. OF OPEN LEVELS  =',"
	    "I11)", 0 };
    static cilist io___58 = { 0, 6, 0, "(    10X,'MOLECULAR WEIGHT        ='"
	    ",F11.3)", 0 };
    static cilist io___59 = { 0, 6, 0, "(/)", 0 };
    static cilist io___60 = { 0, 6, 0, "(10X,'SCF CALCULATIONS  =   ',I14 )", 
	    0 };
    static cilist io___63 = { 0, 6, 0, "(///7X,'FINAL  POINT  AND  DERIVATIV"
	    "ES',/)", 0 };
    static cilist io___64 = { 0, 6, 0, "('   PARAMETER     ATOM    TYPE  '  "
	    "                    ,'          VALUE       GRADIENT')", 0 };
    static cilist io___72 = { 0, 6, 0, "(I7,I11,1X,A2,4X,A11,F13.6,F13.6,2X,"
	    "A13)", 0 };
    static cilist io___73 = { 0, 6, 0, "(///)", 0 };
    static cilist io___74 = { 0, 6, 0, "(//10X,'  INTERATOMIC DISTANCES')", 0 
	    };
    static cilist io___75 = { 0, 6, 0, "(A)", 0 };
    static cilist io___76 = { 0, 6, 0, "(//'      MOLECULAR POINT GROUP   : "
	    "  ',A4)", 0 };
    static cilist io___77 = { 0, 6, 0, "(//10X,A5,' EIGENVECTORS  ')", 0 };
    static cilist io___78 = { 0, 6, 0, "(//10X,' BETA EIGENVECTORS  ')", 0 };
    static cilist io___79 = { 0, 6, 0, "(//10X,A5,'   EIGENVALUES',/)", 0 };
    static cilist io___80 = { 0, 6, 0, "(8F10.5)", 0 };
    static cilist io___81 = { 0, 6, 0, "(//10X,' BETA EIGENVALUES ')", 0 };
    static cilist io___82 = { 0, 6, 0, "(8F10.5)", 0 };
    static cilist io___83 = { 0, 6, 0, "(//13X,' NET ATOMIC CHARGES AND DIPO"
	    "LE ',              'CONTRIBUTIONS',/)", 0 };
    static cilist io___84 = { 0, 6, 0, "(8X,' ATOM NO.   TYPE          CHARG"
	    "E        ATOM'     ,'  ELECTRON DENSITY')", 0 };
    static cilist io___87 = { 0, 6, 0, "(I12,9X,A2,4X,F13.4,F16.4)", 0 };
    static cilist io___90 = { 0, 6, 0, "(//10X,'CARTESIAN COORDINATES ',/)", 
	    0 };
    static cilist io___91 = { 0, 6, 0, "(4X,'NO.',7X,'ATOM',15X,'X',        "
	    "              9X,'Y',9X,'Z',/)", 0 };
    static cilist io___92 = { 0, 6, 0, "(I6,8X,A2,14X,3F10.4)", 0 };
    static cilist io___95 = { 0, 6, 0, "(A)", 0 };
    static cilist io___96 = { 0, 6, 0, "(A)", 0 };
    static cilist io___98 = { 0, 6, 0, "(' FOCK MATRIX IS ')", 0 };
    static cilist io___99 = { 0, 6, 0, "(//,20X,' DENSITY MATRIX IS ')", 0 };
    static cilist io___100 = { 0, 6, 0, "(//10X,'ATOMIC ORBITAL ELECTRON POP"
	    "ULATIONS',/)", 0 };
    static cilist io___101 = { 0, 6, 0, "(8F10.5)", 0 };
    static cilist io___102 = { 0, 6, 0, "(//10X,'SIGMA-PI BOND-ORDER MATRIX')"
	    , 0 };
    static cilist io___105 = { 0, 6, 0, "(//20X,'(SZ)    =',F10.6)", 0 };
    static cilist io___106 = { 0, 6, 0, "(  20X,'(S**2)  =',F10.6)", 0 };
    static cilist io___107 = { 0, 6, 0, "(//10X,'SPIN DENSITY MATRIX')", 0 };
    static cilist io___108 = { 0, 6, 0, "(//10X,'ATOMIC ORBITAL SPIN POPULAT"
	    "IONS',/)", 0 };
    static cilist io___109 = { 0, 6, 0, "(8F10.5)", 0 };
    static cilist io___110 = { 0, 6, 0, "(//10X,'    HYPERFINE COUPLING COEF"
	    "FICIENTS',/)", 0 };
    static cilist io___111 = { 0, 6, 0, "(5(2X,A2,I2,F9.5,1X))", 0 };
    static cilist io___112 = { 0, 6, 0, "(/10X,'BONDING CONTRIBUTION OF EACH"
	    " M.O.',/)", 0 };
    static cilist io___113 = { 0, 6, 0, "(/10X,'BONDING CONTRIBUTION OF EACH"
	    " ALPHA M.O.',/)", 0 };
    static cilist io___114 = { 0, 6, 0, "(/10X,'BONDING CONTRIBUTION OF EACH"
	    " BETA  M.O.',/)", 0 };
    static cilist io___115 = { 0, 6, 0, "(//10X,' LOCALIZED BETA MOLECULAR O"
	    "RBITALS')", 0 };
    static cilist io___116 = { 0, 6, 0, "(' FINAL ONE-ELECTRON MATRIX ')", 0 }
	    ;
    static cilist io___126 = { 0, 10, 0, 0, 0 };
    static cilist io___127 = { 0, 10, 0, 0, 0 };
    static cilist io___128 = { 0, 6, 0, "(//10X,                            "
	    "                   'MULTI-ELECTRON CONFIGURATION INTERACTION CAL"
	    "CULATION',//)", 0 };
    static cilist io___130 = { 0, 6, 0, "(/10X,' MULLIKEN POPULATION ANALYSI"
	    "S')", 0 };
    static cilist io___131 = { 0, 6, 0, "(/10X,' DATA FOR GRAPH WRITTEN TO D"
	    "ISK')", 0 };
    static cilist io___137 = { 0, 0, 0, "(//20X,' SUMMARY OF ',A7,          "
	    "               ' CALCULATION',/)", 0 };
    static cilist io___138 = { 0, 0, 0, "(60X,'VERSION ',F5.2)", 0 };
    static cilist io___139 = { 0, 0, 0, fmt_180, 0 };
    static cilist io___140 = { 0, 0, 0, "(55X,A24)", 0 };
    static cilist io___141 = { 0, 0, 0, "(//4X,A58)", 0 };
    static cilist io___142 = { 0, 0, 0, "(4X,A58)", 0 };
    static cilist io___143 = { 0, 0, 0, "(//10X,'HEAT OF FORMATION       =' "
	    "               ,F17.6,' KCAL')", 0 };
    static cilist io___144 = { 0, 0, 0, "(  10X,'ELECTRONIC ENERGY       =' "
	    "               ,F17.6,' EV')", 0 };
    static cilist io___145 = { 0, 0, 0, "(  10X,'CORE-CORE REPULSION     =' "
	    "               ,F17.6,' EV')", 0 };
    static cilist io___146 = { 0, 0, 0, "(  10X,'GRADIENT NORM           =' "
	    "               ,F17.6)", 0 };
    static cilist io___147 = { 0, 0, 0, "(A)", 0 };
    static cilist io___148 = { 0, 0, 0, "(    10X,'FOR REACTION COORDINATE ="
	    "',F17.4          ,' ANGSTROMS')", 0 };
    static cilist io___149 = { 0, 0, 0, "(    10X,'FOR REACTION COORDINATE ="
	    "',F17.4          ,' DEGREES')", 0 };
    static cilist io___150 = { 0, 0, 0, "(    10X,'REACTION GRADIENT       ="
	    "',F17.6,A14     )", 0 };
    static cilist io___151 = { 0, 0, 0, "(  10X,'DIPOLE                  =' "
	    "               ,F16.5, ' DEBYE')", 0 };
    static cilist io___152 = { 0, 0, 0, "(  10X,'(SZ)                    =',"
	    "F17.6)", 0 };
    static cilist io___153 = { 0, 0, 0, "(  10X,'(S**2)                  =',"
	    "F17.6)", 0 };
    static cilist io___154 = { 0, 0, 0, "(  10X,'NO. OF ALPHA ELECTRONS  =',"
	    "I10)", 0 };
    static cilist io___155 = { 0, 0, 0, "(  10X,'NO. OF BETA  ELECTRONS  =',"
	    "I10)", 0 };
    static cilist io___156 = { 0, 0, 0, "(  10X,'NO. OF FILLED LEVELS    =',"
	    "I10)", 0 };
    static cilist io___157 = { 0, 0, 0, "(  10X,'AND NO. OF OPEN LEVELS  =',"
	    "I10)", 0 };
    static cilist io___158 = { 0, 0, 0, "(  10X,'CONFIGURATION INTERACTION W"
	    "AS USED')", 0 };
    static cilist io___159 = { 0, 0, 0, "(  10X,'CHARGE ON SYSTEM        =',"
	    "I10)", 0 };
    static cilist io___160 = { 0, 0, 0, "(  10X,'IONIZATION POTENTIAL    =' "
	    "               ,F17.6,' EV')", 0 };
    static cilist io___161 = { 0, 0, 0, "(  10X,'MOLECULAR WEIGHT        =',"
	    "F14.3)", 0 };
    static cilist io___162 = { 0, 0, 0, "(  10X,'SCF CALCULATIONS        =' "
	    "               ,I10)", 0 };
    static cilist io___163 = { 0, 0, 0, "(//10X,'FINAL GEOMETRY OBTAINED',36"
	    "X,'CHARGE')", 0 };
    static cilist io___164 = { 0, 0, 0, "(//,A)", 0 };


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
/* COSMO change */
/* end of COSMO change */
/* *********************************************************************** */

/*   WRITE PRINTS OUT MOST OF THE RESULTS. */
/*         IT SHOULD NOT ALTER ANY PARAMETERS, SO THAT IT CAN BE CALLED */
/*         AT ANY CONVENIENT TIME. */

/* *********************************************************************** */

/* SUMMARY OF RESULTS (NOTE: THIS IS IN A SUBROUTINE SO IT */
/*          CAN BE USED BY THE PATH OPTION) */
    if (icalcn == 0) {
	s_copy(namfil, "**NULL**", (ftnlen)80, (ftnlen)8);
    }
    s_copy(idate, " ", (ftnlen)24, (ftnlen)1);
    if (mesage_1.iflepo == 0) {
	mesage_1.iflepo = 7;
    }
/* Computing MIN */
    i__1 = i_indx(keywrd_1.keywrd, " UHF", (ftnlen)241, (ftnlen)4);
    iuhf = min(i__1,1) + 1;
    prtgra = i_indx(keywrd_1.keywrd, " GRAD", (ftnlen)241, (ftnlen)5) != 0 && 
	    geovar_1.nvar > 0;
    linear = molkst_1.norbs * (molkst_1.norbs + 1) / 2;
    singlt = i_indx(keywrd_1.keywrd, " SING", (ftnlen)241, (ftnlen)5) != 0;
    triplt = i_indx(keywrd_1.keywrd, " TRIP", (ftnlen)241, (ftnlen)5) != 0;
    excitd = i_indx(keywrd_1.keywrd, " EXCI", (ftnlen)241, (ftnlen)5) != 0;
    ci = i_indx(keywrd_1.keywrd, " C.I.", (ftnlen)241, (ftnlen)5) != 0;
    if (i_indx(keywrd_1.keywrd, " MINDO", (ftnlen)241, (ftnlen)6) != 0) {
	s_copy(caltyp, "MINDO/3", (ftnlen)7, (ftnlen)7);
    } else if (i_indx(keywrd_1.keywrd, " AM1", (ftnlen)241, (ftnlen)4) != 0) {
	s_copy(caltyp, "  AM1  ", (ftnlen)7, (ftnlen)7);
    } else if (i_indx(keywrd_1.keywrd, " PM3", (ftnlen)241, (ftnlen)4) != 0) {
	s_copy(caltyp, "  PM3  ", (ftnlen)7, (ftnlen)7);
    } else {
	s_copy(caltyp, " MNDO  ", (ftnlen)7, (ftnlen)7);
    }
    uhf = iuhf == 2;
    fdate_(idate, (ftnlen)24);
    degree = 57.29577951;
    if (geokst_1.na[0] == 99) {
	degree = 1.;
	s_copy(type__, "CARTESIAN X", (ftnlen)11, (ftnlen)11);
	s_copy(type__ + 11, "CARTESIAN Y", (ftnlen)11, (ftnlen)11);
	s_copy(type__ + 22, "CARTESIAN Z", (ftnlen)11, (ftnlen)11);
    }
    gradnt_1.gnorm = 0.;
    if (geovar_1.nvar != 0) {
	gradnt_1.gnorm = sqrt(dot_(gradnt_1.grad, gradnt_1.grad, &
		geovar_1.nvar));
    }
    s_wsfe(&io___20);
    e_wsfe();
    wrttxt_(&c__6);
    s_wsfe(&io___21);
    do_fio(&c__1, flepo + (mesage_1.iflepo - 1) * 58, (ftnlen)58);
    e_wsfe();
    mesage_1.iiter = max(1,mesage_1.iiter);
    s_wsfe(&io___22);
    do_fio(&c__1, iter + (mesage_1.iiter - 1) * 58, (ftnlen)58);
    e_wsfe();
    s_wsfe(&io___23);
    do_fio(&c__1, caltyp, (ftnlen)7);
    e_wsfe();
    s_wsfe(&io___24);
    do_fio(&c__1, (char *)&c_b29, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___25);
    do_fio(&c__1, idate, (ftnlen)24);
    e_wsfe();
    if (mesage_1.iiter == 2) {

/*   RESULTS ARE MEANINGLESS. DON'T PRINT ANYTHING! */

	s_wsfe(&io___26);
	e_wsfe();
	s_wsfe(&io___27);
	e_wsfe();
	geout_(&c__1);
	s_stop("", (ftnlen)0);
    }
    s_wsfe(&io___28);
    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (path_1.latom == 0) {
	s_wsfe(&io___29);
	e_wsfe();
    }
    s_wsfe(&io___30);
    d__1 = elect_1.elect + enuclr_1.enuclr;
    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___31);
    do_fio(&c__1, (char *)&elect_1.elect, (ftnlen)sizeof(doublereal));
    e_wsfe();
    s_wsfe(&io___32);
    do_fio(&c__1, (char *)&enuclr_1.enuclr, (ftnlen)sizeof(doublereal));
    e_wsfe();
/* COSMO change */
    if (iseps_1.iseps) {
	dielen_(&edie);
	iw = 6;
	io___35.ciunit = iw;
	s_wsfe(&io___35);
	do_fio(&c__1, (char *)&edie, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
/* end of COSMO change */
    if (path_1.latom == 0) {
	s_wsfe(&io___36);
	e_wsfe();
    }
    prtgra = prtgra || gradnt_1.gnorm > 2.;
    if (prtgra) {
	s_wsfe(&io___37);
	do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    still = TRUE_;
    if (path_1.latom == 0) {
	if (i_indx(keywrd_1.keywrd, " AIDER", (ftnlen)241, (ftnlen)6) != 0) {
	    goto L45;
	}
	if (i_indx(keywrd_1.keywrd, "1SCF", (ftnlen)241, (ftnlen)4) != 0 && 
		i_indx(keywrd_1.keywrd, "GRAD", (ftnlen)241, (ftnlen)4) == 0) 
		{
	    goto L45;
	}

/*   CHECK THAT THE CARTESIAN COORDINATE GRADIENT IS ALSO SMALL */

	i__1 = molkst_1.numat * 3;
/* Computing MAX */
/* Computing 2nd power */
	d__3 = gradnt_1.gnorm;
	d__1 = 16., d__2 = d__3 * d__3 * 4;
	if (dot_(xyzgra_1.dxyz, xyzgra_1.dxyz, &i__1) > max(d__1,d__2) && 
		gradnt_1.gnorm < 2. && molkst_1.nclose == molkst_1.nopen && 
		euler_1.id == 0) {
	    s_wsfe(&io___39);
	    do_fio(&c__1, " WARNING -- GEOMETRY IS NOT AT A STATIONARY POINT",
		     (ftnlen)49);
	    e_wsfe();
	    still = FALSE_;
	}
L45:
	;
    } else {

/*   WE NEED TO CALCULATE THE REACTION COORDINATE GRADIENT. */

	mvar = geovar_1.nvar;
	loc11 = geovar_1.loc[0];
	loc21 = geovar_1.loc[1];
	geovar_1.nvar = 1;
	geovar_1.loc[0] = path_1.latom;
	geovar_1.loc[1] = path_1.lparam;
	xreact = geom_1.geo[path_1.lparam + path_1.latom * 3 - 4];
	deriv_(geom_1.geo, gcoord);
	geovar_1.nvar = mvar;
	geovar_1.loc[0] = loc11;
	geovar_1.loc[1] = loc21;
	s_copy(grtype, " KCAL/ANGSTROM", (ftnlen)14, (ftnlen)14);
	if (path_1.lparam == 1) {
	    s_wsfe(&io___46);
	    do_fio(&c__1, (char *)&xreact, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else {
	    if (geokst_1.na[0] != 99) {
		s_copy(grtype, " KCAL/RADIAN  ", (ftnlen)14, (ftnlen)14);
	    }
	    s_wsfe(&io___47);
	    d__1 = xreact * degree;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	s_wsfe(&io___48);
	do_fio(&c__1, (char *)&gcoord[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, grtype, (ftnlen)14);
	e_wsfe();
    }
    if (molkst_1.nalpha > 0) {
/* Computing MAX */
	d__1 = vector_1.eigs[molkst_1.nalpha - 1], d__2 = vector_1.eigb[
		molkst_1.nbeta - 1];
	eionis = -max(d__1,d__2);
    } else if (molkst_1.nelecs == 1) {
	eionis = -vector_1.eigs[0];
    } else if (molkst_1.nelecs > 1) {
/* Computing MAX */
	d__1 = vector_1.eigs[molkst_1.nclose - 1], d__2 = vector_1.eigs[
		molkst_1.nopen - 1];
	eionis = -max(d__1,d__2);
    } else {
	eionis = 0.;
    }
    nopn = molkst_1.nopen - molkst_1.nclose;
/*   CORRECTION TO I.P. OF DOUBLETS */
    if (nopn == 1) {
	i__ = molkst_1.nclose * molkst_1.norbs + 1;
	eionis += rjks_1.rjkab[0] * .5;
    }
    if (abs(eionis) > 1e-5) {
	s_wsfe(&io___52);
	do_fio(&c__1, (char *)&eionis, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (uhf) {
	s_wsfe(&io___53);
	do_fio(&c__1, (char *)&molkst_1.nalpha, (ftnlen)sizeof(integer));
	e_wsfe();
	s_wsfe(&io___54);
	do_fio(&c__1, (char *)&molkst_1.nbeta, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	s_wsfe(&io___55);
	do_fio(&c__1, (char *)&molkst_1.nclose, (ftnlen)sizeof(integer));
	e_wsfe();
	if (nopn != 0) {
	    s_wsfe(&io___56);
	    do_fio(&c__1, (char *)&nopn, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    }
    sumw = 0.;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L10: */
	sumw += atmass_1.atmass[i__ - 1];
    }
    if (sumw > .1) {
	s_wsfe(&io___58);
	do_fio(&c__1, (char *)&sumw, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (path_1.latom == 0) {
	s_wsfe(&io___59);
	e_wsfe();
    }
    s_wsfe(&io___60);
    do_fio(&c__1, (char *)&numscf_1.nscf, (ftnlen)sizeof(integer));
    e_wsfe();
    tim = second_() - *time0;
    i__ = (integer) (tim * 1e-6);
    tim -= i__ * 1000000;
    timout_(&c__6, &tim);
    if (geosym_1.ndep != 0) {
	symtry_();
    }
    i__1 = geovar_1.nvar;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L20: */
	geovar_1.xparam[i__ - 1] = geom_1.geo[geovar_1.loc[(i__ << 1) - 1] + 
		geovar_1.loc[(i__ << 1) - 2] * 3 - 4];
    }
    gmetry_(geom_1.geo, coord);
    if (prtgra) {
	s_wsfe(&io___63);
	e_wsfe();
	s_wsfe(&io___64);
	e_wsfe();
    }
    sum = .5;
    i__1 = molkst_1.numat;
    for (i__ = 1; i__ <= i__1; ++i__) {
/* L30: */
	sum += core_1.core[molkst_1.nat[i__ - 1] - 1];
    }
    i__ = (integer) sum;
    kchrge = i__ - molkst_1.nclose - molkst_1.nopen - molkst_1.nalpha - 
	    molkst_1.nbeta;

/*    WRITE OUT THE GEOMETRIC VARIABLES */

    if (prtgra) {
	i__1 = geovar_1.nvar;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    j = geovar_1.loc[(i__ << 1) - 1];
	    k = geovar_1.loc[(i__ << 1) - 2];
	    l = geokst_1.labels[k - 1];
	    xi = geovar_1.xparam[i__ - 1];
	    if (j != 1) {
		xi *= degree;
	    }
	    if (j == 1 || geokst_1.na[0] == 99) {
		s_copy(gtype, "KCAL/ANGSTROM", (ftnlen)13, (ftnlen)13);
	    } else {
		s_copy(gtype, "KCAL/RADIAN  ", (ftnlen)13, (ftnlen)13);
	    }
/* L40: */
	    s_wsfe(&io___72);
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, (char *)&k, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (l - 1 << 1), (ftnlen)2);
	    do_fio(&c__1, type__ + (j - 1) * 11, (ftnlen)11);
	    do_fio(&c__1, (char *)&xi, (ftnlen)sizeof(doublereal));
	    do_fio(&c__1, (char *)&gradnt_1.grad[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	    do_fio(&c__1, gtype, (ftnlen)13);
	    e_wsfe();
	}
    }

/*     WRITE OUT THE GEOMETRY */

    s_wsfe(&io___73);
    e_wsfe();
    geout_(&c__1);
    if (i_indx(keywrd_1.keywrd, " NOINTER", (ftnlen)241, (ftnlen)8) == 0) {

/*   WRITE OUT THE INTERATOMIC DISTANCES */

	l = 0;
	i__1 = molkst_1.numat;
	for (i__ = 1; i__ <= i__1; ++i__) {
	    i__2 = i__;
	    for (j = 1; j <= i__2; ++j) {
		++l;
/* L50: */
/* Computing 2nd power */
		d__1 = coord[i__ * 3 - 3] - coord[j * 3 - 3];
/* Computing 2nd power */
		d__2 = coord[i__ * 3 - 2] - coord[j * 3 - 2];
/* Computing 2nd power */
		d__3 = coord[i__ * 3 - 1] - coord[j * 3 - 1];
		scrach_1.rxyz[l - 1] = sqrt(d__1 * d__1 + d__2 * d__2 + d__3 *
			 d__3);
	    }
	}
	s_wsfe(&io___74);
	e_wsfe();
	vecprt_(scrach_1.rxyz, &molkst_1.numat);
    }
    i__2 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L60: */
	if (vector_1.eigs[i__ - 1] < -999. || vector_1.eigs[i__ - 1] > 1e3) {
	    vector_1.eigs[i__ - 1] = 0.;
	}
    }
    i__2 = molkst_1.norbs;
    for (i__ = 1; i__ <= i__2; ++i__) {
/* L70: */
	if (vector_1.eigb[i__ - 1] < -999. || vector_1.eigb[i__ - 1] > 1e3) {
	    vector_1.eigs[i__ - 1] = 0.;
	}
    }
    if (FALSE_) {

/*  THE FOLLOWING OPEN STATEMENTS ARE NON-STANDARD.  IF THIS CAUSES */
/*  DIFFICULTY REPLACE THEM WITH */
	o__1.oerr = 1;
	o__1.ounit = 16;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR016", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__2 = f_open(&o__1);
	if (i__2 != 0) {
	    goto L31;
	}
	goto L32;
L31:
	o__1.oerr = 0;
	o__1.ounit = 16;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR016", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "OLD";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	f_open(&o__1);
	s_wsfe(&io___75);
	do_fio(&c__1, "Error opening SYBYL MOPAC output", (ftnlen)32);
	e_wsfe();
L32:
/* #      OPEN(UNIT=16,FILE=GETNAM('FOR016'),CARRIAGECONTROL='LIST', */
/* #     +STATUS='NEW',ERR=31) */
/* #      GOTO 32 */
/* #  31  OPEN(UNIT=16,FILE=GETNAM('FOR016'),CARRIAGECONTROL='LIST', */
/* #     +STATUS='OLD') */
/* #      WRITE(6,'(A)') 'Error opening SYBYL MOPAC output' */
/* #  32  CONTINUE */
	;
    }
    if (molkst_1.norbs > 0) {
	symtrz_(coord, vector_1.c__, &molkst_1.norbs, &molkst_1.norbs, &
		c_false, &c_true);
	s_wsfe(&io___76);
	do_fio(&c__1, symres_1.name__, (ftnlen)4);
	e_wsfe();
	if (i_indx(keywrd_1.keywrd, "VECT", (ftnlen)241, (ftnlen)4) != 0) {
	    s_wsfe(&io___77);
	    do_fio(&c__1, calcn + (iuhf - 1) * 5, (ftnlen)5);
	    e_wsfe();
	    matou1_(vector_1.c__, vector_1.eigs, &molkst_1.norbs, &
		    molkst_1.norbs, &c__300, &c__2);
	    if (uhf) {
		s_wsfe(&io___78);
		e_wsfe();
		matou1_(vector_1.cbeta, vector_1.eigb, &molkst_1.norbs, &
			molkst_1.norbs, &c__300, &c__2);
	    }
	} else {
	    s_wsfe(&io___79);
	    do_fio(&c__1, calcn + (iuhf - 1) * 5, (ftnlen)5);
	    e_wsfe();
	    s_wsfe(&io___80);
	    i__2 = molkst_1.norbs;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, (char *)&vector_1.eigs[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsfe();
	    if (uhf) {
		s_wsfe(&io___81);
		e_wsfe();
		s_wsfe(&io___82);
		i__2 = molkst_1.norbs;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    do_fio(&c__1, (char *)&vector_1.eigb[i__ - 1], (ftnlen)
			    sizeof(doublereal));
		}
		e_wsfe();
	    }
	}
    }
    s_wsfe(&io___83);
    e_wsfe();
    s_wsfe(&io___84);
    e_wsfe();
    chrge_(densty_1.p, q);
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	l = molkst_1.nat[i__ - 1];
	q2[i__ - 1] = core_1.core[l - 1] - q[i__ - 1];
/* L80: */
	s_wsfe(&io___87);
	do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	do_fio(&c__1, elemts_1.elemnt + (l - 1 << 1), (ftnlen)2);
	do_fio(&c__1, (char *)&q2[i__ - 1], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, (char *)&q[i__ - 1], (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    dip = dipole_(densty_1.p, q2, coord, dumy, &c__1);
    if (i_indx(keywrd_1.keywrd, " NOXYZ", (ftnlen)241, (ftnlen)6) == 0) {
	s_wsfe(&io___90);
	e_wsfe();
	s_wsfe(&io___91);
	e_wsfe();
	s_wsfe(&io___92);
	i__2 = molkst_1.numat;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
	    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 1 << 1), 
		    (ftnlen)2);
	    for (j = 1; j <= 3; ++j) {
		do_fio(&c__1, (char *)&coord[j + i__ * 3 - 4], (ftnlen)sizeof(
			doublereal));
	    }
	}
	e_wsfe();
    }
    if (molkst_1.norbs > 0) {
	if (i_indx(keywrd_1.keywrd, " K=", (ftnlen)241, (ftnlen)3) != 0) {

/*  GO INTO BRILLOUIN ZONE MODE */

	    i__ = i_indx(keywrd_1.keywrd, " K=", (ftnlen)241, (ftnlen)3);
	    step = reada_(keywrd_1.keywrd, &i__, (ftnlen)241);
	    i__2 = i_indx(keywrd_1.keywrd + (i__ - 1), ",", 241 - (i__ - 1), (
		    ftnlen)1);
	    d__1 = reada_(keywrd_1.keywrd + (i__ - 1), &i__2, 241 - (i__ - 1))
		    ;
	    mono3 = molkst_1.nlast[i_dnnt(&d__1) - 1];
	    if (uhf) {
		s_wsfe(&io___95);
		do_fio(&c__1, "  ALPHA BANDS", (ftnlen)13);
		e_wsfe();
	    }
	    brlzon_(fokmat_1.f, work1_1.fmat2d, &molkst_1.norbs, work1_1.sec, 
		    work1_1.vec, work1_1.alband, &mono3, &step, &c__2);
	    if (uhf) {
		s_wsfe(&io___96);
		do_fio(&c__1, "  BETA BANDS", (ftnlen)12);
		e_wsfe();
		brlzon_(fokmat_1.fb, work1_1.fmat2d, &molkst_1.norbs, 
			work1_1.sec, work1_1.vec, work1_1.alband, &mono3, &
			step, &c__2);
	    }
	}
	if (FALSE_) {
/* Computing MAX */
	    i__2 = max(molkst_1.nclose,molkst_1.nalpha);
	    nfilld = max(i__2,molkst_1.nbeta);
	    mpcsyb_(&molkst_1.numat, coord, q2, &c__1, vector_1.eigs, &nfilld,
		     funct, &eionis, &kchrge, &dip);
	}
	if (i_indx(keywrd_1.keywrd, " FOCK", (ftnlen)241, (ftnlen)5) != 0) {
	    s_wsfe(&io___98);
	    e_wsfe();
	    vecprt_(fokmat_1.f, &molkst_1.norbs);
	}
	if (i_indx(keywrd_1.keywrd, " DENS", (ftnlen)241, (ftnlen)5) != 0) {
	    s_wsfe(&io___99);
	    e_wsfe();
	    vecprt_(densty_1.p, &molkst_1.norbs);
	} else {
	    s_wsfe(&io___100);
	    e_wsfe();
	    s_wsfe(&io___101);
	    i__2 = molkst_1.norbs;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_fio(&c__1, (char *)&densty_1.p[i__ * (i__ + 1) / 2 - 1], (
			ftnlen)sizeof(doublereal));
	    }
	    e_wsfe();
	}
	if (i_indx(keywrd_1.keywrd, " PI", (ftnlen)241, (ftnlen)3) != 0) {
	    s_wsfe(&io___102);
	    e_wsfe();
	    denrot_();
	}
	if (uhf) {
	    sz = (i__2 = molkst_1.nalpha - molkst_1.nbeta, abs(i__2)) * .5;
	    ss2 = sz * sz;
	    l = 0;
	    i__2 = molkst_1.norbs;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		i__1 = i__;
		for (j = 1; j <= i__1; ++j) {
		    ++l;
		    densty_1.pa[l - 1] -= densty_1.pb[l - 1];
/* L90: */
/* Computing 2nd power */
		    d__1 = densty_1.pa[l - 1];
		    ss2 += d__1 * d__1;
		}
/* L100: */
/* Computing 2nd power */
		d__1 = densty_1.pa[l - 1];
		ss2 -= d__1 * d__1 * .5;
	    }
	    s_wsfe(&io___105);
	    do_fio(&c__1, (char *)&sz, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    s_wsfe(&io___106);
	    do_fio(&c__1, (char *)&ss2, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	    if (i_indx(keywrd_1.keywrd, " SPIN", (ftnlen)241, (ftnlen)5) != 0)
		     {
		s_wsfe(&io___107);
		e_wsfe();
		vecprt_(densty_1.pa, &molkst_1.norbs);
	    } else {
		s_wsfe(&io___108);
		e_wsfe();
		s_wsfe(&io___109);
		i__2 = molkst_1.norbs;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    do_fio(&c__1, (char *)&densty_1.pa[i__ * (i__ + 1) / 2 - 
			    1], (ftnlen)sizeof(doublereal));
		}
		e_wsfe();
	    }
	    if (i_indx(keywrd_1.keywrd, " HYPERFINE", (ftnlen)241, (ftnlen)10)
		     != 0) {

/*  WORK OUT THE HYPERFINE COUPLING CONSTANTS. */

		s_wsfe(&io___110);
		e_wsfe();
		j = (molkst_1.nalpha - 1) * molkst_1.norbs;
		i__2 = molkst_1.numat;
		for (k = 1; k <= i__2; ++k) {
		    i__ = molkst_1.nfirst[k - 1];
/* #          WRITE(6,'('' PA:'',F13.6,'' C('',I2,''+'',I3,''):'', */
/* #     +F13.5)')PA((I*(I+1))/2),I,J,C(I+J) */
/* L110: */
/* Computing 2nd power */
		    d__1 = vector_1.c__[i__ + j - 1];
		    q[k - 1] = densty_1.pa[i__ * (i__ + 1) / 2 - 1] * 
			    .3333333 + d__1 * d__1 * .66666666;
		}
		s_wsfe(&io___111);
		i__2 = molkst_1.numat;
		for (i__ = 1; i__ <= i__2; ++i__) {
		    do_fio(&c__1, elemts_1.elemnt + (molkst_1.nat[i__ - 1] - 
			    1 << 1), (ftnlen)2);
		    do_fio(&c__1, (char *)&i__, (ftnlen)sizeof(integer));
		    do_fio(&c__1, (char *)&q[i__ - 1], (ftnlen)sizeof(
			    doublereal));
		}
		e_wsfe();
	    }
	    i__2 = linear;
	    for (i__ = 1; i__ <= i__2; ++i__) {
/* L120: */
		densty_1.pa[i__ - 1] = densty_1.p[i__ - 1] - densty_1.pb[i__ 
			- 1];
	    }
	}
	if (i_indx(keywrd_1.keywrd, " BONDS", (ftnlen)241, (ftnlen)6) != 0) {
	    if (molkst_1.nbeta == 0) {
		s_wsfe(&io___112);
		e_wsfe();
		molval_(vector_1.c__, densty_1.p, &molkst_1.norbs, &c_b199);
	    } else {
		s_wsfe(&io___113);
		e_wsfe();
		molval_(vector_1.c__, densty_1.p, &molkst_1.norbs, &c_b201);
		s_wsfe(&io___114);
		e_wsfe();
		molval_(vector_1.c__, densty_1.p, &molkst_1.norbs, &c_b201);
	    }
	    bonds_(densty_1.p);
	}
	i__ = molkst_1.nclose + molkst_1.nalpha;
	if (i_indx(keywrd_1.keywrd, " LOCAL", (ftnlen)241, (ftnlen)6) != 0) {
	    local_(vector_1.c__, &molkst_1.norbs, &i__, vector_1.eigs);
	    if (molkst_1.nbeta != 0) {
		s_wsfe(&io___115);
		e_wsfe();
		local_(vector_1.cbeta, &molkst_1.norbs, &molkst_1.nbeta, 
			vector_1.eigb);
	    }
	}
	if (i_indx(keywrd_1.keywrd, " 1ELE", (ftnlen)241, (ftnlen)5) != 0) {
	    s_wsfe(&io___116);
	    e_wsfe();
	    vecprt_(hmatrx_1.h__, &molkst_1.norbs);
	}
	if (i_indx(keywrd_1.keywrd, " ENPART", (ftnlen)241, (ftnlen)7) != 0) {
	    enpart_(&uhf, hmatrx_1.h__, densty_1.pa, densty_1.pb, densty_1.p, 
		    q, coord);
	}
    }
    for (i__ = 1; i__ <= 107; ++i__) {
/* L130: */
	nelemt[i__ - 1] = 0;
    }
    i__2 = molkst_1.numat;
    for (i__ = 1; i__ <= i__2; ++i__) {
	igo = molkst_1.nat[i__ - 1];
	if (igo > 107) {
	    goto L140;
	}
	++nelemt[igo - 1];
L140:
	;
    }
    ichfor = 0;
    if (nelemt[5] == 0) {
	goto L150;
    }
    ichfor = 1;
    s_copy(ielemt, elemts_1.elemnt + 10, (ftnlen)2, (ftnlen)2);
    nzs = nelemt[5];
    if (nzs < 10) {
	if (nzs == 1) {
	    iel1[0] = 11;
	} else {
	    iel1[0] = nzs + 1;
	}
	iel2[0] = 11;
    } else {
	kfrst = nzs / 10;
	ksec = nzs - kfrst * 10;
	iel1[0] = kfrst + 1;
	iel2[0] = ksec + 1;
    }
L150:
    nelemt[5] = 0;
    for (i__ = 1; i__ <= 107; ++i__) {
	if (nelemt[i__ - 1] == 0) {
	    goto L160;
	}
	++ichfor;
	s_copy(ielemt + (ichfor - 1 << 1), elemts_1.elemnt + (i__ - 1 << 1), (
		ftnlen)2, (ftnlen)2);
	nzs = nelemt[i__ - 1];
	if (nzs < 10) {
	    if (nzs == 1) {
		iel1[ichfor - 1] = 11;
	    } else {
		iel1[ichfor - 1] = nzs + 1;
	    }
	    iel2[ichfor - 1] = 11;
	} else {
	    kfrst = nzs / 10;
	    ksec = nzs - kfrst * 10;
	    iel1[ichfor - 1] = kfrst + 1;
	    iel2[ichfor - 1] = ksec + 1;
	}
L160:
	;
    }
    if (i_indx(keywrd_1.keywrd, " DENOUT", (ftnlen)241, (ftnlen)7) != 0) {
	o__1.oerr = 0;
	o__1.ounit = 10;
	o__1.ofnmlen = 80;
	getnam_(ch__1, (ftnlen)80, "FOR010", (ftnlen)6);
	o__1.ofnm = ch__1;
	o__1.orl = 0;
	o__1.osta = "UNKNOWN";
	o__1.oacc = 0;
	o__1.ofm = "UNFORMATTED";
	o__1.oblnk = 0;
	f_open(&o__1);
	al__1.aerr = 0;
	al__1.aunit = 10;
	f_rew(&al__1);
	s_wsue(&io___126);
	i__2 = linear;
	for (i__ = 1; i__ <= i__2; ++i__) {
	    do_uio(&c__1, (char *)&densty_1.pa[i__ - 1], (ftnlen)sizeof(
		    doublereal));
	}
	e_wsue();
	if (uhf) {
	    s_wsue(&io___127);
	    i__2 = linear;
	    for (i__ = 1; i__ <= i__2; ++i__) {
		do_uio(&c__1, (char *)&densty_1.pb[i__ - 1], (ftnlen)sizeof(
			doublereal));
	    }
	    e_wsue();
	}
	cl__1.cerr = 0;
	cl__1.cunit = 10;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if ((ci || molkst_1.nopen != molkst_1.nclose && molkst_1.fract != 2. && 
	    molkst_1.fract != 0. || i_indx(keywrd_1.keywrd, " SIZE", (ftnlen)
	    241, (ftnlen)5) != 0) && i_indx(keywrd_1.keywrd, " MECI", (ftnlen)
	    241, (ftnlen)5) + i_indx(keywrd_1.keywrd, " ESR", (ftnlen)241, (
	    ftnlen)4) != 0) {
	s_wsfe(&io___128);
	e_wsfe();
	last_1.last = 3;
	x = meci_(vector_1.eigs, vector_1.c__);
    }
    if (i_indx(keywrd_1.keywrd, " MULLIK", (ftnlen)241, (ftnlen)7) + i_indx(
	    keywrd_1.keywrd, " GRAPH", (ftnlen)241, (ftnlen)6) != 0) {
	if (i_indx(keywrd_1.keywrd, " MULLIK", (ftnlen)241, (ftnlen)7) != 0) {
	    s_wsfe(&io___130);
	    e_wsfe();
	}
	i__2 = molkst_1.norbs;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L172: */
	    q[i__ - 1] = densty_1.p[i__ * (i__ + 1) / 2 - 1];
	}
	mullik_(vector_1.c__, hmatrx_1.h__, fokmat_1.f, &molkst_1.norbs, 
		densty_1.p, scrach_1.rxyz);
	i__2 = molkst_1.norbs;
	for (i__ = 1; i__ <= i__2; ++i__) {
/* L174: */
	    densty_1.p[i__ * (i__ + 1) / 2 - 1] = q[i__ - 1];
	}
	if (i_indx(keywrd_1.keywrd, " GRAPH", (ftnlen)241, (ftnlen)6) != 0) {
	    s_wsfe(&io___131);
	    e_wsfe();
	}
    }

/*  NOTE THAT THE DENSITY, H AND F MATRICES ARE CORRUPTED BY A */
/*  CALL TO MULLIK. */
    if (FALSE_) {
	if (i_indx(keywrd_1.keywrd, "MULLIK", (ftnlen)241, (ftnlen)6) == 0) {
	    mpcpop_(vector_1.c__, &c__0);
	} else {
	    mpcpop_(vector_1.c__, &c__1);
	}
	cl__1.cerr = 0;
	cl__1.cunit = 16;
	cl__1.csta = 0;
	f_clos(&cl__1);
    }
    if (icalcn != numcal_1.numcal) {
	if (s_cmp(namfil, "**NULL**", (ftnlen)80, (ftnlen)8) == 0) {
	    getnam_(ch__1, (ftnlen)80, "FOR012", (ftnlen)6);
	    s_copy(namfil, ch__1, (ftnlen)80, (ftnlen)80);
	    inam = 'a';
	    jnam = inam;
	    jend = i_indx(namfil, " ", (ftnlen)80, (ftnlen)1);
	    iend = jend + 1;
	}
L162:
	cl__1.cerr = 0;
	cl__1.cunit = 12;
	cl__1.csta = 0;
	f_clos(&cl__1);
	o__1.oerr = 1;
	o__1.ounit = 12;
	o__1.ofnmlen = 80;
	o__1.ofnm = namfil;
	o__1.orl = 0;
	o__1.osta = "NEW";
	o__1.oacc = 0;
	o__1.ofm = 0;
	o__1.oblnk = 0;
	i__2 = f_open(&o__1);
	if (i__2 != 0) {
	    goto L163;
	}
	goto L164;
L163:
	*(unsigned char *)&namfil[iend - 1] = (char) inam;
	*(unsigned char *)&namfil[jend - 1] = (char) jnam;
	if (inam == 'z') {
	    inam += -26;
	    ++jnam;
	}
	++inam;
	goto L162;
L164:
	al__1.aerr = 0;
	al__1.aunit = 12;
	f_rew(&al__1);
	icalcn = numcal_1.numcal;
    }
    if (i_indx(keywrd_1.keywrd, "GREENF", (ftnlen)241, (ftnlen)6) != 0) {
	greenf_();
    }
    iwrite = 12;
L170:
    io___137.ciunit = iwrite;
    s_wsfe(&io___137);
    do_fio(&c__1, caltyp, (ftnlen)7);
    e_wsfe();
    io___138.ciunit = iwrite;
    s_wsfe(&io___138);
    do_fio(&c__1, (char *)&c_b29, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___139.ciunit = iwrite;
    s_wsfe(&io___139);
    i__2 = ichfor;
    for (i__ = 1; i__ <= i__2; ++i__) {
	do_fio(&c__1, ielemt + (i__ - 1 << 1), (ftnlen)2);
	do_fio(&c__1, numbrs + (iel1[i__ - 1] - 1), (ftnlen)1);
	do_fio(&c__1, numbrs + (iel2[i__ - 1] - 1), (ftnlen)1);
    }
    e_wsfe();
    io___140.ciunit = iwrite;
    s_wsfe(&io___140);
    do_fio(&c__1, idate, (ftnlen)24);
    e_wsfe();
    wrttxt_(&iwrite);
    io___141.ciunit = iwrite;
    s_wsfe(&io___141);
    do_fio(&c__1, flepo + (mesage_1.iflepo - 1) * 58, (ftnlen)58);
    e_wsfe();
    io___142.ciunit = iwrite;
    s_wsfe(&io___142);
    do_fio(&c__1, iter + (mesage_1.iiter - 1) * 58, (ftnlen)58);
    e_wsfe();
    io___143.ciunit = iwrite;
    s_wsfe(&io___143);
    do_fio(&c__1, (char *)&(*funct), (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___144.ciunit = iwrite;
    s_wsfe(&io___144);
    do_fio(&c__1, (char *)&elect_1.elect, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___145.ciunit = iwrite;
    s_wsfe(&io___145);
    do_fio(&c__1, (char *)&enuclr_1.enuclr, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (prtgra) {
	io___146.ciunit = iwrite;
	s_wsfe(&io___146);
	do_fio(&c__1, (char *)&gradnt_1.gnorm, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (path_1.latom == 0) {
	if (! still) {
	    io___147.ciunit = iwrite;
	    s_wsfe(&io___147);
	    do_fio(&c__1, " WARNING -- GEOMETRY IS NOT AT A STATIONARY POINT",
		     (ftnlen)49);
	    e_wsfe();
	}
    } else {
	s_copy(grtype, " KCAL/ANGSTROM", (ftnlen)14, (ftnlen)14);
	if (path_1.lparam == 1) {
	    io___148.ciunit = iwrite;
	    s_wsfe(&io___148);
	    do_fio(&c__1, (char *)&xreact, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	} else {
	    if (geokst_1.na[0] != 99) {
		s_copy(grtype, " KCAL/RADIAN  ", (ftnlen)14, (ftnlen)14);
	    }
	    io___149.ciunit = iwrite;
	    s_wsfe(&io___149);
	    d__1 = xreact * degree;
	    do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	    e_wsfe();
	}
	io___150.ciunit = iwrite;
	s_wsfe(&io___150);
	do_fio(&c__1, (char *)&gcoord[0], (ftnlen)sizeof(doublereal));
	do_fio(&c__1, grtype, (ftnlen)14);
	e_wsfe();
    }
    io___151.ciunit = iwrite;
    s_wsfe(&io___151);
    do_fio(&c__1, (char *)&dip, (ftnlen)sizeof(doublereal));
    e_wsfe();
    if (uhf) {
	io___152.ciunit = iwrite;
	s_wsfe(&io___152);
	do_fio(&c__1, (char *)&sz, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___153.ciunit = iwrite;
	s_wsfe(&io___153);
	do_fio(&c__1, (char *)&ss2, (ftnlen)sizeof(doublereal));
	e_wsfe();
	io___154.ciunit = iwrite;
	s_wsfe(&io___154);
	do_fio(&c__1, (char *)&molkst_1.nalpha, (ftnlen)sizeof(integer));
	e_wsfe();
	io___155.ciunit = iwrite;
	s_wsfe(&io___155);
	do_fio(&c__1, (char *)&molkst_1.nbeta, (ftnlen)sizeof(integer));
	e_wsfe();
    } else {
	io___156.ciunit = iwrite;
	s_wsfe(&io___156);
	do_fio(&c__1, (char *)&molkst_1.nclose, (ftnlen)sizeof(integer));
	e_wsfe();
	nopn = molkst_1.nopen - molkst_1.nclose;
	if (nopn != 0) {
	    io___157.ciunit = iwrite;
	    s_wsfe(&io___157);
	    do_fio(&c__1, (char *)&nopn, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    }
    if (ci) {
	io___158.ciunit = iwrite;
	s_wsfe(&io___158);
	e_wsfe();
    }
    if (kchrge != 0) {
	io___159.ciunit = iwrite;
	s_wsfe(&io___159);
	do_fio(&c__1, (char *)&kchrge, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    io___160.ciunit = iwrite;
    s_wsfe(&io___160);
    do_fio(&c__1, (char *)&eionis, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___161.ciunit = iwrite;
    s_wsfe(&io___161);
    do_fio(&c__1, (char *)&sumw, (ftnlen)sizeof(doublereal));
    e_wsfe();
    io___162.ciunit = iwrite;
    s_wsfe(&io___162);
    do_fio(&c__1, (char *)&numscf_1.nscf, (ftnlen)sizeof(integer));
    e_wsfe();
    tim = second_() - *time0;
    timout_(&iwrite, &tim);
    io___163.ciunit = iwrite;
    s_wsfe(&io___163);
    e_wsfe();
    geout_(&iwrite);
    if (i_indx(keywrd_1.keywrd, " AIGOUT", (ftnlen)241, (ftnlen)7) != 0) {
	io___164.ciunit = iwrite;
	s_wsfe(&io___164);
	do_fio(&c__1, "  GEOMETRY IN GAUSSIAN Z-MATRIX STYLE", (ftnlen)37);
	e_wsfe();
	wrttxt_(&iwrite);
	geoutg_(&iwrite);
    }
    if (iwrite != 11 && i_indx(keywrd_1.keywrd, " NOLOG", (ftnlen)241, (
	    ftnlen)6) == 0) {
	iwrite = 11;
	goto L170;
    }
    numscf_1.nscf = 0;
    return 0;
} /* writmo_ */

#undef w


