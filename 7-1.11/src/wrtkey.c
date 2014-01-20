/* wrtkey.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct {
    integer numcal;
} numcal_;

#define numcal_1 numcal_

struct {
    doublereal tleft, tdump;
} timdmp_;

#define timdmp_1 timdmp_

/* Table of constant values */

static integer c__1 = 1;

/* Subroutine */ int wrtkey_(char *keywrd, ftnlen keywrd_len)
{
    /* Initialized data */

    static logical am1 = FALSE_;
    static logical mndo = FALSE_;
    static logical mindo3 = FALSE_;
    static logical pm3 = FALSE_;

    /* Format strings */
    static char fmt_210[] = "(\002 *  VECTORS  - FINAL EIGENVECTORS TO BE PR"
	    "INTED\002)";
    static char fmt_220[] = "(\002 *  EXTERNAL - USE ATOMIC PARAMETERS FROM "
	    "THE FOLLOWING \002,\002FILE\002,/15x,a)";
    static char fmt_230[] = "(\002 *  DENSITY  - FINAL DENSITY MATRIX TO BE "
	    "PRINTED\002)";
    static char fmt_240[] = "(\002 *  SPIN     - FINAL UHF SPIN MATRIX TO BE"
	    " PRINTED\002)";
    static char fmt_250[] = "(\002 *  DEPVAR=N - SPECIFIED DISTANCE IS\002,f"
	    "7.4,\002 TIMES BOND LENGTH\002)";
    static char fmt_260[] = "(\002 *  DEP      - OUTPUT FORTRAN CODE FOR BLO"
	    "CK-DATA\002)";
    static char fmt_270[] = "(\002 *  VELOCITY - INPUT STARTING VELOCITIES F"
	    "OR DRC\002)";
    static char fmt_378[] = "(\002 *  GREEN    - RUN DANOVICH'S GREEN'S FUNC"
	    "TION CALCN.\002)";
    static char fmt_280[] = "(\002 *  TIMES    - TIMES OF VARIOUS STAGES TO "
	    "BE PRINTED\002)";
    static char fmt_290[] = "(\002 *  PARASOK  - USE SOME MNDO PARAMETERS IN"
	    " AN AM1 CALCULA\002,\002TION\002)";
    static char fmt_300[] = "(\002 *  NODIIS   - DO NOT USE GDIIS GEOMETRY O"
	    "PTIMIZER\002)";
    static char fmt_310[] = "(\002 *  BONDS    - FINAL BOND-ORDER MATRIX TO "
	    "BE PRINTED\002)";
    static char fmt_320[] = "(\002 *  GEO-OK   - OVERRIDE INTERATOMIC DISTAN"
	    "CE CHECK\002)";
    static char fmt_330[] = "(\002 *  FOCK     - LAST FOCK MATRIX TO BE PRIN"
	    "TED\002)";
    static char fmt_340[] = "(\002 *  LARGE    - EXPANDED OUTPUT TO BE PRINT"
	    "ED\002)";
    static char fmt_350[] = "(\002 *   K=      - BRILLOUIN ZONE STRUCTURE TO"
	    " BE CALCULATED\002)";
    static char fmt_360[] = "(\002 *  NOLOG    - SUPPRESS LOG FILE TRAIL, WH"
	    "ERE POSSIBLE\002)";
    static char fmt_370[] = "(\002 *  AIGIN    - GEOMETRY MUST BE IN GAUSSIA"
	    "N FORMAT\002)";
    static char fmt_380[] = "(\002 *  AIGOUT   - IN ARC FILE, INCLUDE AB-INI"
	    "TIO GEOMETRY\002)";
    static char fmt_390[] = "(\002 *  AIDER    - READ IN AB INITIO DERIVATIV"
	    "ES\002)";
    static char fmt_400[] = "(\002 *  S1978    - 1978 SULFUR PARAMETERS TO B"
	    "E USED\002)";
    static char fmt_410[] = "(\002 *  SI1978   - 1978 SILICON PARAMETERS TO "
	    "BE USED\002)";
    static char fmt_420[] = "(\002 *  GRAPH    - GENERATE FILE FOR GRAPHIC"
	    "S\002)";
    static char fmt_440[] = "(\002 *  NOANCI   - DO NOT USE ANALYTICAL C.I. "
	    "DERIVATIVES\002)";
    static char fmt_430[] = "(\002 *  1ELECTRON- FINAL ONE-ELECTRON MATRIX T"
	    "O BE PRINTED\002)";
    static char fmt_470[] = "(\002 *  SETUP    - EXTRA KEYWORDS TO BE READ F"
	    "ROM FILE SETUP\002)";
    static char fmt_460[] = "(\002 *  NOMM     - DO NOT MAKE MM CORRECTION T"
	    "O CONH BARRIER\002)";
    static char fmt_480[] = "(\002 *  MMOK     - APPLY MM CORRECTION TO CONH"
	    " BARRIER\002)";
    static char fmt_490[] = "(\002 *  INTERP   - PRINT DETAILS OF CAMP-KING "
	    "CONVERGER\002)";
    static char fmt_450[] = "(\002 *  ESR      - RHF SPIN DENSITY CALCULATIO"
	    "N REQUESTED\002)";
    static char fmt_500[] = "(\002 *  DFP      - USE DAVIDON FLETCHER POWELL"
	    " OPTIMIZER\002)";
    static char fmt_510[] = "(\002 *  ANALYT   - USE ANALYTIC DERIVATIVES"
	    " \002)";
    static char fmt_520[] = "(\002 *  MECI     - M.E.C.I. WORKING TO BE PRIN"
	    "TED\002)";
    static char fmt_560[] = "(\002 *  LOCALIZE - LOCALIZED ORBITALS TO BE PR"
	    "INTED\002)";
    static char fmt_570[] = "(\002 *  MULLIK   - THE MULLIKEN ANALYSIS TO BE"
	    " PERFORMED\002)";
    static char fmt_580[] = "(\002 *   XYZ     - CARTESIAN COORDINATE SYSTEM"
	    " TO BE USED\002)";
    static char fmt_590[] = "(\002 *   PI      - BONDS MATRIX, SPLIT INTO SI"
	    "GMA-PI-DELL\002,\002 COMPONENTS, TO BE PRINTED\002)";
    static char fmt_600[] = "(\002 *  ECHO     - ALL INPUT DATA TO BE ECHOED"
	    " BEFORE RUN\002)";
    static char fmt_910[] = "(\002 *  SINGLET  - SPIN STATE DEFINED AS A SIN"
	    "GLET\002)";
    static char fmt_920[] = "(\002 *  DOUBLET  - SPIN STATE DEFINED AS A DOU"
	    "BLET\002)";
    static char fmt_940[] = "(\002 *  QUARTET  - SPIN STATE DEFINED AS A QUA"
	    "RTET\002)";
    static char fmt_950[] = "(\002 *  QUINTET  - SPIN STATE DEFINED AS A QUI"
	    "NTET\002)";
    static char fmt_960[] = "(\002 *  SEXTET   - SPIN STATE DEFINED AS A SEX"
	    "TET\002)";
    static char fmt_610[] = "(\002 *  H-PRIOR  - HEAT OF FORMATION TAKES PRI"
	    "ORITY IN DRC\002)";
    static char fmt_620[] = "(\002 *  X-PRIOR  - GEOMETRY CHANGES TAKE PRIOR"
	    "ITY IN DRC\002)";
    static char fmt_630[] = "(\002 *  T-PRIOR  - TIME TAKES PRIORITY IN DR"
	    "C\002)";
    static char fmt_650[] = "(\002 *  COMPFG   - PRINT HEAT OF FORMATION CAL"
	    "C'D IN COMPFG\002)";
    static char fmt_640[] = "(\002 *  POLAR    - CALCULATE FIRST, SECOND AND"
	    " THIRD-ORDER\002,\002 POLARIZABILITIES\002)";
    static char fmt_660[] = "(\002 *  DEBUG    - DEBUG OPTION TURNED ON\002)";
    static char fmt_670[] = "(\002 *  RESTART  - CALCULATION RESTARTED\002)";
    static char fmt_680[] = "(\002 *  ESP      - ELECTROSTATIC POTENTIAL CAL"
	    "CULATION\002)";
    static char fmt_690[] = "(\002 *  NSURF    - NUMBER OF LAYERS\002)";
    static char fmt_700[] = "(\002 *  SCALE    - SCALING FACTOR FOR VAN DER "
	    "WAALS DISTANCE\002)";
    static char fmt_710[] = "(\002 *  SCINCR   - INCREMENT BETWEEN LAYERS"
	    "\002)";
    static char fmt_720[] = "(\002 *  SLOPE    - SLOPE - USED TO SCALE MNDO "
	    "ESP CHARGES\002)";
    static char fmt_730[] = "(\002 *  DIPOLE   - FIT THE ESP TO THE CALCULAT"
	    "ED DIPOLE\002)";
    static char fmt_740[] = "(\002 *  DIPX     - X COMPONENT OF DIPOLE TO BE"
	    " FIT\002)";
    static char fmt_750[] = "(\002 *  DIPY     - Y COMPONENT OF DIPOLE TO BE"
	    " FIT\002)";
    static char fmt_760[] = "(\002 *  DIPZ     - Z COMPONENT OF DIPOLE TO BE"
	    " FIT\002)";
    static char fmt_770[] = "(\002 *  CONNOLLY - USE CONNOLLY SURFACE\002)";
    static char fmt_780[] = "(\002 *  ESPRST   - RESTART OF ELECTRIC POTENTI"
	    "AL CALCULATION\002)";
    static char fmt_790[] = "(\002 *  POTWRT   - WRITE OUT ELECTRIC POT. DAT"
	    "A TO FILE 21\002)";
    static char fmt_800[] = "(\002 *  WILLIAMS - USE WILLIAMS SURFACE\002)";
    static char fmt_810[] = "(\002 *  SYMAVG   - AVERAGE SYMMETRY EQUIVALENT"
	    " ESP CHARGES\002)";
    static char fmt_820[] = "(\002 *  STO3G    - DEORTHOGONALIZE ORBITALS IN"
	    " STO-3G BASIS\002)";
    static char fmt_90[] = "(\002 *  IUPD=    - HESSIAN WILL NOT BE UPDATE"
	    "D\002)";
    static char fmt_100[] = "(\002 *  IUPD=    - HESSIAN WILL BE UPDATED USI"
	    "NG POWELL\002)";
    static char fmt_110[] = "(\002 *  IUPD=    - HESSIAN WILL BE UPDATED USI"
	    "NG BFGS\002)";
    static char fmt_120[] = "(\002 *  HESS=    - DIAGONAL HESSIAN USED AS IN"
	    "ITIAL GUESS\002)";
    static char fmt_130[] = "(\002 *  HESS=    - INITIAL HESSIAN WILL BE CAL"
	    "CULATED\002)";
    static char fmt_140[] = "(\002 *  HESS=    - INITIAL HESSIAN READ FROM D"
	    "ISK\002)";
    static char fmt_150[] = "(\002 *  HESS=    - INITIAL HESSIAN READ FROM I"
	    "NPUT\002)";
    static char fmt_160[] = "(\002 *  MODE=    - FOLLOW HESSIAN MODE\002,i3"
	    ",\002 TOWARD TS\002)";
    static char fmt_170[] = "(\002 *  RECALC=  - DO\002,i4,\002 CYCLES BETWE"
	    "EN HESSIAN RECALC\002)";
    static char fmt_180[] = "(\002 *  DMAX=    - TAKE MAXIMUM STEPSIZE OF"
	    "\002,f5.3,\002 ANG/RAD\002)";
    static char fmt_190[] = "(\002 *  MS=      - IN MECI, MAGNETIC COMPONENT"
	    " OF SPIN =\002,i3)";
    static char fmt_200[] = "(\002 *  PRNT     - EXTRA PRINTING IN EF ROUT"
	    "INE\002)";
    static char fmt_830[] = "(\002 *  IRC=N    - INTRINSIC REACTION COORDINA"
	    "TE\002,i3,\002 DEFINED\002)";
    static char fmt_840[] = "(\002 *  IRC      - INTRINSIC REACTION COORDINA"
	    "TE CALCULATION\002)";
    static char fmt_850[] = "(3(\002 *\002,/),\002 *\002,15x,\002  CHARGE ON"
	    " SYSTEM =\002,i3,3(/,\002 *\002))";
    static char fmt_860[] = "(\002 *  GRADIENTS- ALL GRADIENTS TO BE PRINTE"
	    "D\002)";
    static char fmt_870[] = "(\002 *  UHF      - UNRESTRICTED HARTREE-FOCK C"
	    "ALCULATION\002)";
    static char fmt_890[] = "(\002 *  BIRADICAL- SYSTEM HAS TWO UNPAIRED ELE"
	    "CTRONS\002)";
    static char fmt_900[] = "(\002 *  EXCITED  - FIRST EXCITED STATE IS TO B"
	    "E OPTIMIZED\002)";
    static char fmt_930[] = "(\002 *  TRIPLET  - SPIN STATE DEFINED AS A TRI"
	    "PLET\002)";
    static char fmt_970[] = "(\002 *  SYMMETRY - SYMMETRY CONDITIONS TO BE I"
	    "MPOSED\002)";
    static char fmt_971[] = "(\002 *  GROUP    - FREQUENCIES TO BE SYMMETRIZ"
	    "ED\002)";
    static char fmt_972[] = "(\002 *  RMAT     - PRINT R MATRICES\002)";
    static char fmt_973[] = "(\002 *  IPO      - PRINT PERMUTATION OPERATO"
	    "R\002)";
    static char fmt_974[] = "(\002 *  NODEGEN  - DO NOT COLLAPSE DEGENERATE "
	    "FREQUENCIES\002)";
    static char fmt_990[] = "(\002 *  OPEN(N,N)- THERE ARE\002,i2,\002 ELECT"
	    "RONS IN\002,i2,\002 LEVELS\002)";
    static char fmt_980[] = "(\002 *  MICROS=N -\002,i4,\002 MICROSTATES TO "
	    "BE SUPPLIED FOR C.I.\002)";
    static char fmt_540[] = "(\002 *  DRC=     - HALF-LIFE FOR KINETIC ENERG"
	    "Y LOSS =\002,f9.2,\002 * 10**(-15) SECONDS\002)";
    static char fmt_530[] = "(\002 *  DRC      - DYNAMIC REACTION COORDINATE"
	    " CALCULATION\002)";
    static char fmt_550[] = "(\002 *  KINETIC= - \002,f9.3,\002 KCAL KINETIC"
	    " ENERGY ADDED TO DRC\002)";
    static char fmt_1000[] = "(\002 *   T=      - A TIME OF\002,f8.1,\002"
	    " \002,a7,\002 REQUESTED\002)";
    static char fmt_1010[] = "(\002 *   T=      - A TIME OF\002,g11.3,\002"
	    " \002,a7,\002 REQUESTED\002)";
    static char fmt_1020[] = "(\002 *  DUMP=N   - RESTART FILE WRITTEN EVER"
	    "Y\002,f8.1,\002 \002,a7)";
    static char fmt_1030[] = "(\002 *  DUMP=N   - RESTART FILE WRITTEN EVER"
	    "Y\002,g11.3,\002 \002,a7)";
    static char fmt_1040[] = "(\002 *  1SCF     - DO 1 SCF AND THEN STOP "
	    "\002)";
    static char fmt_1060[] = "(\002 * C.I.=(N,M)-\002,i2,\002 DOUBLY FILLED "
	    "LEVELS USED IN A \002,/,\002 *             C.I. INVOLVING \002,i"
	    "2,\002 M.O.'S\002)";
    static char fmt_1050[] = "(\002 *  C.I.=N   -\002,i2,\002 M.O.S TO BE US"
	    "ED IN C.I.\002)";
    static char fmt_1070[] = "(\002 *  FORCE    - FORCE CALCULATION SPECIF"
	    "IED\002)";
    static char fmt_70[] = "(\002 *  EF       - USE EF ROUTINE FOR MINIMUM S"
	    "EARCH\002)";
    static char fmt_80[] = "(\002 *  TS       - USE EF ROUTINE FOR TS SEARC"
	    "H\002)";
    static char fmt_1080[] = "(\002 *  MINDO/3  - THE MINDO/3 HAMILTONIAN TO"
	    " BE USED\002)";
    static char fmt_1090[] = "(\002 *  AM1      - THE AM1 HAMILTONIAN TO BE "
	    "USED\002)";
    static char fmt_1100[] = "(\002 *  PM3      - THE PM3 HAMILTONIAN TO BE "
	    "USED\002)";
    static char fmt_1120[] = "(\002 *  OLDGEO   - PREVIOUS GEOMETRY TO BE US"
	    "ED\002)";
    static char fmt_1110[] = "(\002 *  PRECISE  - CRITERIA TO BE INCREASED B"
	    "Y 100 TIMES\002)";
    static char fmt_1130[] = "(\002 *  NOINTER  - INTERATOMIC DISTANCES NOT "
	    "TO BE PRINTED\002)";
    static char fmt_1140[] = "(\002 *  ISOTOPE  - FORCE MATRIX WRITTEN TO DI"
	    "SK (CHAN. 9 )\002)";
    static char fmt_1150[] = "(\002 *  DENOUT   - DENSITY MATRIX OUTPUT ON C"
	    "HANNEL 10\002)";
    static char fmt_1160[] = "(\002 *  SHIFT    - A DAMPING FACTOR OF\002,f8"
	    ".2,\002 DEFINED\002)";
    static char fmt_1170[] = "(\002 *  OLDENS   - INITIAL DENSITY MATRIX REA"
	    "D OF DISK\002)";
    static char fmt_1180[] = "(\002 *  SCFCRT   - DEFAULT SCF CRITERION REPL"
	    "ACED BY\002,g12.3)";
    static char fmt_1190[] = "(\002 *  ENPART   - ENERGY TO BE PARTITIONED I"
	    "NTO COMPONENTS\002)";
    static char fmt_1200[] = "(\002 *  NOXYZ    - CARTESIAN COORDINATES NOT "
	    "TO BE PRINTED\002)";
    static char fmt_1210[] = "(\002 *  SIGMA    - GEOMETRY TO BE OPTIMIZED U"
	    "SING SIGMA.\002)";
    static char fmt_1220[] = "(\002 *  NLLSQ    - GRADIENTS TO BE MINIMIZED "
	    "USING NLLSQ.\002)";
    static char fmt_1230[] = "(\002 *  ROOT     - IN A C.I. CALCULATION, R"
	    "OOT\002,i2,\002 TO BE OPTIMIZED.\002)";
    static char fmt_1250[] = "(\002 *  TRANS=   - \002,i4,\002 VIBRATIONS AR"
	    "E TO BE DELETED FROM\002,\002 THE THERMO CALCULATION\002)";
    static char fmt_1240[] = "(\002 *  TRANS    - THE REACTION VIBRATION TO "
	    "BE DELETED FROM\002,\002 THE THERMO CALCULATION\002)";
    static char fmt_1260[] = "(\002 *  SADDLE   - TRANSITION STATE TO BE OPT"
	    "IMIZED\002)";
    static char fmt_1270[] = "(\002 *   LET     - OVERRIDE SOME SAFETY CHE"
	    "CKS\002)";
    static char fmt_1280[] = "(\002 *  COMPFG   - PRINT HEAT OF FORMATION CA"
	    "LC'D IN COMPFG\002)";
    static char fmt_1290[] = "(\002 *  GNORM=   - EXIT WHEN GRADIENT NORM DR"
	    "OPS BELOW \002,g8.3)";
    static char fmt_1300[] = "(\002 *  PULAY    - PULAY'S METHOD TO BE USED "
	    "IN SCF\002)";
    static char fmt_1310[] = "(\002 *  STEP1    - FIRST  STEP-SIZE IN GRID "
	    "=\002,f7.2)";
    static char fmt_1320[] = "(\002 *  STEP2    - SECOND STEP-SIZE IN GRID "
	    "=\002,f7.2)";
    static char fmt_1500[] = "(\002 *  STEP     - STEP-SIZE IN PATH=\002,f7."
	    "3)";
    static char fmt_1330[] = "(\002 *  POINT1   - NUMBER OF ROWS IN GRID "
	    "=\002,i3)";
    static char fmt_1340[] = "(\002 *  POINT2   - NUMBER OF COLUMNS IN GRI"
	    "D =\002,i3)";
    static char fmt_1350[] = "(\002 *  MAX      - GRID SIZE 23*23 \002)";
    static char fmt_1510[] = "(\002 *  POINT    - NUMBER OF POINTS IN PATH"
	    "=\002,i3)";
    static char fmt_1360[] = "(\002 *  BAR=     - REDUCE BAR LENGTH BY A MAX"
	    ". OF\002,f7.2)";
    static char fmt_1370[] = "(\002 *  CAMP,KING- THE CAMP-KING CONVERGER TO"
	    " BE USED\002)";
    static char fmt_1380[] = "(\002 *  EIGS     - PRINT ALL EIGENVALUES IN I"
	    "TER\002)";
    static char fmt_1390[] = "(\002 *  EIGINV   - USE HESSIAN EIGENVALUE REV"
	    "ERSION IN EF\002)";
    static char fmt_1400[] = "(\002 *  NONR     - DO NOT USE NEWTON-RAPHSON "
	    "STEP IN EF\002)";
    static char fmt_1410[] = "(\002 *  ORIDE    - UNCONDITIONALLY, USE CALCU"
	    "LATED LAMDAS IN\002//\002 EF\002)";
    static char fmt_1420[] = "(\002 *  HYPERFINE- HYPERFINE COUPLING CONSTAN"
	    "TS TO BE\002,\002 PRINTED\002)";
    static char fmt_1430[] = "(\002 *   PL      - MONITOR CONVERGANCE IN DEN"
	    "SITY MATRIX\002)";
    static char fmt_1440[] = "(\002 *  FILL=    - IN RHF CLOSED SHELL, FORCE"
	    " M.O.\002,i3,\002 TO BE FILLED\002)";
    static char fmt_1470[] = "(\002 *  ITRY=    - DO A MAXIMUM OF\002,i6,"
	    "\002 ITERATIONS FOR SCF\002)";
    static char fmt_1490[] = "(\002 *  0SCF     - AFTER READING AND PRINTING"
	    " DATA, STOP\002)";
    static char fmt_1480[] = "(//10x,\002 IMPOSSIBLE OPTION REQUESTED,\002)";
    static char fmt_1445[] = "(\002 *  FIELD    - APPLY A STATIC ELECTRIC FI"
	    "ELD\002)";
    static char fmt_1450[] = "(\002 *  THERMO   - THERMODYNAMIC QUANTITIES T"
	    "O BE CALCULATED\002)";
    static char fmt_1460[] = "(\002 *  ROT      - SYMMETRY NUMBER OF\002,i3"
	    ",\002 SPECIFIED\002)";

    /* System generated locals */
    integer i__1, i__2, i__3, i__4;
    doublereal d__1;

    /* Builtin functions */
    /* Subroutine */ int s_copy(char *, char *, ftnlen, ftnlen);
    integer s_wsfe(cilist *), e_wsfe(void), i_indx(char *, char *, ftnlen, 
	    ftnlen), do_fio(integer *, char *, ftnlen), i_dnnt(doublereal *);
    /* Subroutine */ int s_stop(char *, ftnlen);
    integer s_cmp(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer i__, j, l;
    static char ch[1];
    static logical ci;
    static integer ii, ip, ip1, ip2;
    static logical uhf, exci;
    static doublereal time;
    static logical trip;
    extern doublereal reada_(char *, integer *, ftnlen);
    static logical birad;
    static integer ielec, maxgeo;
    static char allkey[241];
    static integer ilevel, method;
    static char chrono[7];
    extern logical myword_(char *, char *, ftnlen, ftnlen);

    /* Fortran I/O blocks */
    static cilist io___7 = { 0, 6, 0, "(10X,' MOPAC - A GENERAL MOLECULAR OR"
	    "BITAL PACKAGE',/         ,10X,'   ORIGINAL VERSION WRITTEN IN 19"
	    "83')", 0 };
    static cilist io___8 = { 0, 6, 0, "(10X,'     BY JAMES J. P. STEWART AT "
	    "THE',/                  ,10X,'     UNIVERSITY OF TEXAS AT AUSTIN"
	    "',/                     ,10X,'          AUSTIN, TEXAS, 78712')", 
	    0 };
    static cilist io___9 = { 0, 6, 0, fmt_210, 0 };
    static cilist io___11 = { 0, 6, 0, fmt_220, 0 };
    static cilist io___13 = { 0, 6, 0, fmt_230, 0 };
    static cilist io___14 = { 0, 6, 0, fmt_240, 0 };
    static cilist io___15 = { 0, 6, 0, fmt_250, 0 };
    static cilist io___16 = { 0, 6, 0, fmt_260, 0 };
    static cilist io___17 = { 0, 6, 0, fmt_270, 0 };
    static cilist io___18 = { 0, 6, 0, fmt_378, 0 };
    static cilist io___19 = { 0, 6, 0, fmt_280, 0 };
    static cilist io___20 = { 0, 6, 0, fmt_290, 0 };
    static cilist io___21 = { 0, 6, 0, fmt_300, 0 };
    static cilist io___22 = { 0, 6, 0, fmt_310, 0 };
    static cilist io___23 = { 0, 6, 0, fmt_320, 0 };
    static cilist io___24 = { 0, 6, 0, fmt_330, 0 };
    static cilist io___25 = { 0, 6, 0, fmt_340, 0 };
    static cilist io___26 = { 0, 6, 0, fmt_350, 0 };
    static cilist io___27 = { 0, 6, 0, fmt_360, 0 };
    static cilist io___28 = { 0, 6, 0, fmt_370, 0 };
    static cilist io___29 = { 0, 6, 0, fmt_380, 0 };
    static cilist io___30 = { 0, 6, 0, fmt_390, 0 };
    static cilist io___31 = { 0, 6, 0, fmt_400, 0 };
    static cilist io___32 = { 0, 6, 0, fmt_410, 0 };
    static cilist io___33 = { 0, 6, 0, fmt_420, 0 };
    static cilist io___34 = { 0, 6, 0, fmt_440, 0 };
    static cilist io___35 = { 0, 6, 0, fmt_430, 0 };
    static cilist io___36 = { 0, 6, 0, fmt_470, 0 };
    static cilist io___37 = { 0, 6, 0, fmt_460, 0 };
    static cilist io___38 = { 0, 6, 0, fmt_480, 0 };
    static cilist io___39 = { 0, 6, 0, fmt_490, 0 };
    static cilist io___40 = { 0, 6, 0, fmt_450, 0 };
    static cilist io___41 = { 0, 6, 0, fmt_500, 0 };
    static cilist io___42 = { 0, 6, 0, fmt_510, 0 };
    static cilist io___43 = { 0, 6, 0, fmt_520, 0 };
    static cilist io___44 = { 0, 6, 0, fmt_560, 0 };
    static cilist io___45 = { 0, 6, 0, fmt_570, 0 };
    static cilist io___46 = { 0, 6, 0, fmt_580, 0 };
    static cilist io___47 = { 0, 6, 0, fmt_590, 0 };
    static cilist io___48 = { 0, 6, 0, fmt_600, 0 };
    static cilist io___49 = { 0, 6, 0, fmt_910, 0 };
    static cilist io___50 = { 0, 6, 0, fmt_920, 0 };
    static cilist io___51 = { 0, 6, 0, fmt_940, 0 };
    static cilist io___52 = { 0, 6, 0, fmt_950, 0 };
    static cilist io___53 = { 0, 6, 0, fmt_960, 0 };
    static cilist io___54 = { 0, 6, 0, fmt_610, 0 };
    static cilist io___55 = { 0, 6, 0, fmt_620, 0 };
    static cilist io___56 = { 0, 6, 0, fmt_630, 0 };
    static cilist io___57 = { 0, 6, 0, fmt_650, 0 };
    static cilist io___58 = { 0, 6, 0, fmt_640, 0 };
    static cilist io___59 = { 0, 6, 0, fmt_660, 0 };
    static cilist io___60 = { 0, 6, 0, fmt_670, 0 };
    static cilist io___61 = { 0, 6, 0, fmt_680, 0 };
    static cilist io___62 = { 0, 6, 0, fmt_690, 0 };
    static cilist io___63 = { 0, 6, 0, fmt_700, 0 };
    static cilist io___64 = { 0, 6, 0, fmt_710, 0 };
    static cilist io___65 = { 0, 6, 0, fmt_720, 0 };
    static cilist io___66 = { 0, 6, 0, fmt_730, 0 };
    static cilist io___67 = { 0, 6, 0, fmt_740, 0 };
    static cilist io___68 = { 0, 6, 0, fmt_750, 0 };
    static cilist io___69 = { 0, 6, 0, fmt_760, 0 };
    static cilist io___70 = { 0, 6, 0, fmt_770, 0 };
    static cilist io___71 = { 0, 6, 0, fmt_780, 0 };
    static cilist io___72 = { 0, 6, 0, fmt_790, 0 };
    static cilist io___73 = { 0, 6, 0, fmt_800, 0 };
    static cilist io___74 = { 0, 6, 0, fmt_810, 0 };
    static cilist io___75 = { 0, 6, 0, fmt_820, 0 };
    static cilist io___77 = { 0, 6, 0, fmt_90, 0 };
    static cilist io___78 = { 0, 6, 0, fmt_100, 0 };
    static cilist io___79 = { 0, 6, 0, fmt_110, 0 };
    static cilist io___80 = { 0, 6, 0, fmt_120, 0 };
    static cilist io___81 = { 0, 6, 0, fmt_130, 0 };
    static cilist io___82 = { 0, 6, 0, fmt_140, 0 };
    static cilist io___83 = { 0, 6, 0, fmt_150, 0 };
    static cilist io___84 = { 0, 6, 0, fmt_160, 0 };
    static cilist io___85 = { 0, 6, 0, fmt_170, 0 };
    static cilist io___86 = { 0, 6, 0, fmt_180, 0 };
    static cilist io___87 = { 0, 6, 0, fmt_190, 0 };
    static cilist io___88 = { 0, 6, 0, fmt_200, 0 };
    static cilist io___89 = { 0, 6, 0, fmt_830, 0 };
    static cilist io___90 = { 0, 6, 0, fmt_840, 0 };
    static cilist io___91 = { 0, 6, 0, fmt_850, 0 };
    static cilist io___92 = { 0, 6, 0, fmt_860, 0 };
    static cilist io___94 = { 0, 6, 0, fmt_870, 0 };
    static cilist io___96 = { 0, 6, 0, fmt_890, 0 };
    static cilist io___98 = { 0, 6, 0, fmt_900, 0 };
    static cilist io___100 = { 0, 6, 0, fmt_930, 0 };
    static cilist io___101 = { 0, 6, 0, fmt_970, 0 };
    static cilist io___102 = { 0, 6, 0, fmt_971, 0 };
    static cilist io___103 = { 0, 6, 0, fmt_972, 0 };
    static cilist io___104 = { 0, 6, 0, fmt_973, 0 };
    static cilist io___105 = { 0, 6, 0, fmt_974, 0 };
    static cilist io___106 = { 0, 6, 0, "(//,10X,'RMAT MUST BE SPECIFIED WIT"
	    "H ',                'GROUP')", 0 };
    static cilist io___107 = { 0, 6, 0, "(//,10X,'IPO MUST BE SPECIFIED WITH"
	    " ',                 'GROUP')", 0 };
    static cilist io___108 = { 0, 6, 0, "(//,10X,'NODEGEN MUST BE SPECIFIED "
	    "WITH ',             'GROUP')", 0 };
    static cilist io___111 = { 0, 6, 0, fmt_990, 0 };
    static cilist io___112 = { 0, 6, 0, fmt_980, 0 };
    static cilist io___113 = { 0, 6, 0, fmt_540, 0 };
    static cilist io___114 = { 0, 6, 0, fmt_530, 0 };
    static cilist io___115 = { 0, 6, 0, fmt_550, 0 };
    static cilist io___119 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___120 = { 0, 6, 0, fmt_1010, 0 };
    static cilist io___121 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___122 = { 0, 6, 0, fmt_1000, 0 };
    static cilist io___123 = { 0, 6, 0, fmt_1020, 0 };
    static cilist io___124 = { 0, 6, 0, fmt_1030, 0 };
    static cilist io___125 = { 0, 6, 0, fmt_1020, 0 };
    static cilist io___126 = { 0, 6, 0, fmt_1020, 0 };
    static cilist io___127 = { 0, 6, 0, fmt_1040, 0 };
    static cilist io___129 = { 0, 6, 0, fmt_1060, 0 };
    static cilist io___130 = { 0, 6, 0, fmt_1050, 0 };
    static cilist io___131 = { 0, 6, 0, fmt_1070, 0 };
    static cilist io___132 = { 0, 6, 0, fmt_70, 0 };
    static cilist io___133 = { 0, 6, 0, fmt_80, 0 };
    static cilist io___135 = { 0, 6, 0, fmt_1080, 0 };
    static cilist io___136 = { 0, 6, 0, fmt_1090, 0 };
    static cilist io___137 = { 0, 6, 0, fmt_1100, 0 };
    static cilist io___138 = { 0, 6, 0, fmt_1120, 0 };
    static cilist io___139 = { 0, 6, 0, fmt_1110, 0 };
    static cilist io___140 = { 0, 6, 0, fmt_1130, 0 };
    static cilist io___141 = { 0, 6, 0, fmt_1140, 0 };
    static cilist io___142 = { 0, 6, 0, fmt_1150, 0 };
    static cilist io___143 = { 0, 6, 0, fmt_1160, 0 };
    static cilist io___144 = { 0, 6, 0, fmt_1170, 0 };
    static cilist io___145 = { 0, 6, 0, fmt_1180, 0 };
    static cilist io___146 = { 0, 6, 0, fmt_1190, 0 };
    static cilist io___147 = { 0, 6, 0, fmt_1200, 0 };
    static cilist io___148 = { 0, 6, 0, fmt_1210, 0 };
    static cilist io___149 = { 0, 6, 0, fmt_1220, 0 };
    static cilist io___150 = { 0, 6, 0, fmt_1230, 0 };
    static cilist io___151 = { 0, 6, 0, fmt_1250, 0 };
    static cilist io___152 = { 0, 6, 0, fmt_1240, 0 };
    static cilist io___153 = { 0, 6, 0, fmt_1260, 0 };
    static cilist io___154 = { 0, 6, 0, fmt_1270, 0 };
    static cilist io___155 = { 0, 6, 0, fmt_1280, 0 };
    static cilist io___156 = { 0, 6, 0, fmt_1290, 0 };
    static cilist io___157 = { 0, 6, 0, fmt_1300, 0 };
    static cilist io___158 = { 0, 6, 0, fmt_1310, 0 };
    static cilist io___159 = { 0, 6, 0, fmt_1320, 0 };
    static cilist io___160 = { 0, 6, 0, fmt_1500, 0 };
    static cilist io___162 = { 0, 6, 0, fmt_1330, 0 };
    static cilist io___164 = { 0, 6, 0, fmt_1340, 0 };
    static cilist io___165 = { 0, 6, 0, fmt_1350, 0 };
    static cilist io___167 = { 0, 6, 0, fmt_1510, 0 };
    static cilist io___168 = { 0, 6, 0, fmt_1360, 0 };
    static cilist io___169 = { 0, 6, 0, fmt_1370, 0 };
    static cilist io___170 = { 0, 6, 0, fmt_1370, 0 };
    static cilist io___171 = { 0, 6, 0, fmt_1380, 0 };
    static cilist io___172 = { 0, 6, 0, fmt_1390, 0 };
    static cilist io___173 = { 0, 6, 0, fmt_1400, 0 };
    static cilist io___174 = { 0, 6, 0, fmt_1410, 0 };
    static cilist io___175 = { 0, 6, 0, fmt_1420, 0 };
    static cilist io___176 = { 0, 6, 0, fmt_1430, 0 };
    static cilist io___177 = { 0, 6, 0, fmt_1440, 0 };
    static cilist io___178 = { 0, 6, 0, fmt_1470, 0 };
    static cilist io___179 = { 0, 6, 0, fmt_1490, 0 };
    static cilist io___180 = { 0, 6, 0, "(//10X,                            "
	    "                ' UHF USED WITH EITHER BIRAD, EXCITED OR C.I. ')",
	     0 };
    static cilist io___181 = { 0, 6, 0, fmt_1480, 0 };
    static cilist io___182 = { 0, 6, 0, "(//10X,' EXCITED USED WITH TRIPLET')"
	    , 0 };
    static cilist io___183 = { 0, 6, 0, fmt_1480, 0 };
    static cilist io___184 = { 0, 6, 0, "(//10X,'T-PRIO AND NO DRC')", 0 };
    static cilist io___185 = { 0, 6, 0, fmt_1480, 0 };
    static cilist io___186 = { 0, 6, 0, "(//10X,                            "
	    "                   ' ONLY ONE OF MINDO, MNDO, AM1 AND PM3 ALLOWE"
	    "D')", 0 };
    static cilist io___187 = { 0, 6, 0, fmt_1480, 0 };
    static cilist io___188 = { 0, 6, 0, fmt_1445, 0 };
    static cilist io___189 = { 0, 6, 0, fmt_1450, 0 };
    static cilist io___190 = { 0, 6, 0, fmt_1460, 0 };
    static cilist io___191 = { 0, 6, 0, "                                   "
	    "                    (//10X,' YOU MUST SUPPLY THE SYMMETRY NUMBER "
	    "\"ROT\"')", 0 };
    static cilist io___192 = { 0, 6, 0, "(//10X,'MORE THAN ONE GEOMETRY OPTI"
	    "ON HAS BEEN ',   'SPECIFIED',/10X,                              "
	    "                 'CONFLICT MUST BE RESOLVED BEFORE JOB WILL RUN')"
	    , 0 };
    static cilist io___193 = { 0, 6, 0, "(A)", 0 };
    static cilist io___195 = { 0, 6, 0, "(' *  DEBUG KEYWORDS USED:  ',A)", 0 
	    };
    static cilist io___196 = { 0, 6, 0, "(///10X,'UNRECOGNIZED KEY-WORDS: ('"
	    ",A,')')", 0 };
    static cilist io___197 = { 0, 6, 0, "(///10X,'CALCULATION STOPPED TO AVO"
	    "ID WASTING TIME.')", 0 };
    static cilist io___198 = { 0, 6, 0, "(///10X,'IF THESE ARE DEBUG KEYWORD"
	    "S, ADD THE KEYWORD \"DEBUG\"')", 0 };
    static cilist io___199 = { 0, 6, 0, "(//10X,' CALCULATION ABANDONED, SOR"
	    "RY!')", 0 };


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
/* ********************************************************************** */

/*  WRTKEY CHECKS ALL KEY-WORDS AND PRINTS THOSE IT RECOGNIZES.  IF IT */
/*  FINDS A WORD IT DOES NOT RECOGNIZE THE PROGRAM WILL BE STOPPED. */

/* ********************************************************************** */
    s_copy(allkey, keywrd, (ftnlen)241, (ftnlen)241);
/*    DUMMY IF STATEMENT TO REMOVE AMPERSAND AND PLUS SIGNS, IF PRESENT */
    if (myword_(allkey + 159, " SETUP", (ftnlen)82, (ftnlen)6)) {
	i__ = 1;
    }
    if (myword_(allkey, "&", (ftnlen)241, (ftnlen)1)) {
	i__ = 2;
    }
    if (myword_(allkey, " +", (ftnlen)241, (ftnlen)2)) {
	i__ = 3;
    }
    if (myword_(allkey, "AUTHOR", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___7);
	e_wsfe();
	s_wsfe(&io___8);
	e_wsfe();
    }
    if (myword_(allkey, "VECT", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___9);
	e_wsfe();
    }
    if (myword_(allkey, " EXTE", (ftnlen)241, (ftnlen)5)) {
	i__ = i_indx(keywrd, " EXTE", (ftnlen)241, (ftnlen)5);
	j = i_indx(keywrd + (i__ - 1), "=", 241 - (i__ - 1), (ftnlen)1) + i__;
	i__ = i_indx(keywrd + (j - 1), " ", 241 - (j - 1), (ftnlen)1) + j - 1;
	s_wsfe(&io___11);
	do_fio(&c__1, keywrd + (j - 1), i__ - (j - 1));
	e_wsfe();
    }
    maxgeo = 0;
    if (myword_(allkey, " DENS", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___13);
	e_wsfe();
    }
    if (myword_(allkey, "SPIN", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___14);
	e_wsfe();
    }
    if (myword_(allkey, " DEPVAR", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___15);
	i__1 = i_indx(keywrd, "DEPVAR", (ftnlen)241, (ftnlen)6);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, " DEP ", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___16);
	e_wsfe();
    }
    if (myword_(allkey, "VELO", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___17);
	e_wsfe();
    }
    if (myword_(allkey, " GREENF", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___18);
	e_wsfe();
    }
    if (myword_(allkey, "TIMES", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___19);
	e_wsfe();
    }
    if (myword_(allkey, "PARASOK", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___20);
	e_wsfe();
    }
    if (myword_(allkey, "NODIIS", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___21);
	e_wsfe();
    }
    if (myword_(allkey, "BONDS", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___22);
	e_wsfe();
    }
    if (myword_(allkey, "GEO-OK", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___23);
	e_wsfe();
    }
    if (myword_(allkey, "FOCK", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___24);
	e_wsfe();
    }
    if (myword_(allkey, "LARGE", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___25);
	e_wsfe();
    }
    if (myword_(allkey, " K=", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___26);
	e_wsfe();
    }
    if (myword_(allkey, "NOLOG", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___27);
	e_wsfe();
    }
    if (myword_(allkey, "AIGIN", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___28);
	e_wsfe();
    }
    if (myword_(allkey, "AIGOUT", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___29);
	e_wsfe();
    }
    if (myword_(allkey, "AIDER", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___30);
	e_wsfe();
    }
    if (myword_(allkey, " S1978", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___31);
	e_wsfe();
    }
    if (myword_(allkey, " SI1978", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___32);
	e_wsfe();
    }
    if (myword_(allkey, " GRAP", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___33);
	e_wsfe();
    }
    if (myword_(allkey, "NOANCI", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___34);
	e_wsfe();
    }
    if (myword_(allkey, "1ELEC", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___35);
	e_wsfe();
    }
    if (myword_(allkey, " SETUP", (ftnlen)162, (ftnlen)6)) {
	s_wsfe(&io___36);
	e_wsfe();
    }
    if (myword_(allkey, " NOMM", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___37);
	e_wsfe();
    }
    if (myword_(allkey, " MMOK", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___38);
	e_wsfe();
    }
    if (myword_(allkey, "INTERP", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___39);
	e_wsfe();
    }
    if (myword_(allkey, " ESR", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___40);
	e_wsfe();
    }
    if (myword_(allkey, "DFP", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___41);
	e_wsfe();
    }
    if (myword_(allkey, "ANALYT", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___42);
	e_wsfe();
    }
    if (myword_(allkey, " MECI", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___43);
	e_wsfe();
    }
    if (myword_(allkey, "LOCAL", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___44);
	e_wsfe();
    }
    if (myword_(allkey, "MULLIK", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___45);
	e_wsfe();
    }
    if (myword_(allkey, " XYZ", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___46);
	e_wsfe();
    }
    if (myword_(allkey, " PI", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___47);
	e_wsfe();
    }
    if (myword_(allkey, "ECHO", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___48);
	e_wsfe();
    }
    if (myword_(allkey, "SING", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___49);
	e_wsfe();
    }
    if (myword_(allkey, "DOUB", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___50);
	e_wsfe();
    }
    if (myword_(allkey, "QUAR", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___51);
	e_wsfe();
    }
    if (myword_(allkey, "QUIN", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___52);
	e_wsfe();
    }
    if (myword_(allkey, "SEXT", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___53);
	e_wsfe();
    }
    if (myword_(allkey, "H-PRIO", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___54);
	e_wsfe();
    }
    if (myword_(allkey, "X-PRIO", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___55);
	e_wsfe();
    }
    if (myword_(allkey, "T-PRIO", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___56);
	e_wsfe();
    }
    if (myword_(allkey, "COMPFG", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___57);
	e_wsfe();
    }
    if (myword_(allkey, "POLAR", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___58);
	e_wsfe();
    }
    if (myword_(allkey, "DEBUG ", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___59);
	e_wsfe();
    }
    if (myword_(allkey, "RESTART", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___60);
	e_wsfe();
    }

/*     KEYWORDS ADDED FOR ESP MOPAC */

    if (myword_(allkey, "ESP ", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___61);
	e_wsfe();
    }
    if (myword_(allkey, "NSURF", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___62);
	e_wsfe();
    }
    if (myword_(allkey, "SCALE", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___63);
	e_wsfe();
    }
    if (myword_(allkey, "SCINCR", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___64);
	e_wsfe();
    }
    if (myword_(allkey, "SLOPE", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___65);
	e_wsfe();
    }
    if (myword_(allkey, "DIPOLE", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___66);
	e_wsfe();
    }
    if (myword_(allkey, "DIPX", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___67);
	e_wsfe();
    }
    if (myword_(allkey, "DIPY", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___68);
	e_wsfe();
    }
    if (myword_(allkey, "DIPZ", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___69);
	e_wsfe();
    }
    if (myword_(allkey, "CONNOLLY", (ftnlen)241, (ftnlen)8)) {
	s_wsfe(&io___70);
	e_wsfe();
    }
    if (myword_(allkey, "ESPRST", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___71);
	e_wsfe();
    }
    if (myword_(allkey, " POTWRT", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___72);
	e_wsfe();
    }
    if (myword_(allkey, "WILLIAMS", (ftnlen)241, (ftnlen)8)) {
	s_wsfe(&io___73);
	e_wsfe();
    }
    if (myword_(allkey, "SYMAVG", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___74);
	e_wsfe();
    }
    if (myword_(allkey, "STO3G", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___75);
	e_wsfe();
    }
    if (myword_(allkey, "IUPD", (ftnlen)241, (ftnlen)4)) {
	i__1 = i_indx(keywrd, "IUPD=", (ftnlen)241, (ftnlen)5);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	ii = i_dnnt(&d__1);
	if (ii == 0) {
	    s_wsfe(&io___77);
	    e_wsfe();
	}
	if (ii == 1) {
	    s_wsfe(&io___78);
	    e_wsfe();
	}
	if (ii == 2) {
	    s_wsfe(&io___79);
	    e_wsfe();
	}
    }
    if (myword_(allkey, "HESS", (ftnlen)241, (ftnlen)4)) {
	i__1 = i_indx(keywrd, "HESS=", (ftnlen)241, (ftnlen)5);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	ii = i_dnnt(&d__1);
	if (ii == 0) {
	    s_wsfe(&io___80);
	    e_wsfe();
	}
	if (ii == 1) {
	    s_wsfe(&io___81);
	    e_wsfe();
	}
	if (ii == 2) {
	    s_wsfe(&io___82);
	    e_wsfe();
	}
	if (ii == 3) {
	    s_wsfe(&io___83);
	    e_wsfe();
	}
    }
    if (myword_(allkey, " MODE", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___84);
	i__2 = i_indx(keywrd, "MODE=", (ftnlen)241, (ftnlen)5);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, " RECALC", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___85);
	i__2 = i_indx(keywrd, "RECALC", (ftnlen)241, (ftnlen)6);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, " DMAX", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___86);
	i__1 = i_indx(keywrd, "DMAX=", (ftnlen)241, (ftnlen)5);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, " MS=", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___87);
	i__2 = i_indx(keywrd, " MS=", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, " PRNT", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___88);
	e_wsfe();
    }
    if (myword_(allkey, "IRC=", (ftnlen)241, (ftnlen)4)) {
	maxgeo = 1;
	s_wsfe(&io___89);
	i__2 = i_indx(keywrd, "IRC=", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    } else if (myword_(allkey, "IRC", (ftnlen)241, (ftnlen)3)) {
	maxgeo = 1;
	s_wsfe(&io___90);
	e_wsfe();
    }
    if (myword_(allkey, "CHARGE", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___91);
	i__2 = i_indx(keywrd, "CHARGE", (ftnlen)241, (ftnlen)6);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "GRAD", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___92);
	e_wsfe();
    }
    uhf = myword_(allkey, "UHF", (ftnlen)241, (ftnlen)3);
    if (uhf) {
	s_wsfe(&io___94);
	e_wsfe();
    }
    birad = myword_(allkey, "BIRAD", (ftnlen)241, (ftnlen)5);
    if (birad) {
	s_wsfe(&io___96);
	e_wsfe();
    }
    exci = myword_(allkey, "EXCITED", (ftnlen)241, (ftnlen)7);
    if (exci) {
	s_wsfe(&io___98);
	e_wsfe();
    }
    trip = myword_(allkey, "TRIP", (ftnlen)241, (ftnlen)4);
    if (trip) {
	s_wsfe(&io___100);
	e_wsfe();
    }
    if (myword_(allkey, "SYM", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___101);
	e_wsfe();
    }
    if (myword_(allkey, " GROUP", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___102);
	e_wsfe();
	if (myword_(allkey, " RMAT", (ftnlen)241, (ftnlen)5)) {
	    s_wsfe(&io___103);
	    e_wsfe();
	}
	if (myword_(allkey, " IPO", (ftnlen)241, (ftnlen)4)) {
	    s_wsfe(&io___104);
	    e_wsfe();
	}
	if (myword_(allkey, " NODEGEN", (ftnlen)241, (ftnlen)8)) {
	    s_wsfe(&io___105);
	    e_wsfe();
	}
    }
    if (myword_(allkey, " RMAT", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___106);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (myword_(allkey, " IPO", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___107);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (myword_(allkey, " NODEGEN", (ftnlen)241, (ftnlen)8)) {
	s_wsfe(&io___108);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (myword_(allkey, "OPEN(", (ftnlen)241, (ftnlen)5)) {
	i__ = i_indx(keywrd, "OPEN(", (ftnlen)241, (ftnlen)5);
	ielec = (integer) reada_(keywrd, &i__, (ftnlen)241);
	i__1 = i__ + 7;
	ilevel = (integer) reada_(keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___111);
	do_fio(&c__1, (char *)&ielec, (ftnlen)sizeof(integer));
	do_fio(&c__1, (char *)&ilevel, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "MICROS", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___112);
	i__2 = i_indx(keywrd, "MICROS", (ftnlen)241, (ftnlen)6);
	i__1 = (integer) reada_(keywrd, &i__2, (ftnlen)241);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "DRC=", (ftnlen)241, (ftnlen)4)) {
	maxgeo = 1;
	s_wsfe(&io___113);
	i__1 = i_indx(keywrd, "DRC=", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    } else if (myword_(allkey, " DRC", (ftnlen)241, (ftnlen)4)) {
	maxgeo = 1;
	s_wsfe(&io___114);
	e_wsfe();
    }
    if (myword_(allkey, "KINE", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___115);
	i__1 = i_indx(keywrd, "KINE", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    s_copy(chrono, "SECONDS", (ftnlen)7, (ftnlen)7);
    time = 1.;
    if (myword_(allkey, " T=", (ftnlen)241, (ftnlen)3)) {
	i__ = i_indx(keywrd, " T=", (ftnlen)241, (ftnlen)3);
	timdmp_1.tleft = reada_(keywrd, &i__, (ftnlen)241);
	for (j = i__ + 3; j <= 241; ++j) {
	    i__1 = j;
	    if (j == 241 || s_cmp(keywrd + i__1, " ", j + 1 - i__1, (ftnlen)1)
		     == 0) {
		*(unsigned char *)ch = *(unsigned char *)&keywrd[j - 1];
		if (*(unsigned char *)ch == 'M') {
		    s_copy(chrono, "MINUTES", (ftnlen)7, (ftnlen)7);
		}
		if (*(unsigned char *)ch == 'M') {
		    time = 60.;
		}
		if (*(unsigned char *)ch == 'H') {
		    s_copy(chrono, "HOURS", (ftnlen)7, (ftnlen)5);
		}
		if (*(unsigned char *)ch == 'H') {
		    time = 3600.;
		}
		if (*(unsigned char *)ch == 'D') {
		    s_copy(chrono, "DAYS", (ftnlen)7, (ftnlen)4);
		}
		if (*(unsigned char *)ch == 'D') {
		    time = 86400.;
		}
		goto L20;
	    }
/* L10: */
	}
L20:
	if (timdmp_1.tleft < 99999.9) {
	    s_wsfe(&io___119);
	    do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, chrono, (ftnlen)7);
	    e_wsfe();
	} else {
	    s_wsfe(&io___120);
	    do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, chrono, (ftnlen)7);
	    e_wsfe();
	}
	timdmp_1.tleft *= time;
    } else if (numcal_1.numcal == 1) {
	timdmp_1.tleft = 3600.;
	s_wsfe(&io___121);
	do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, "SECONDS", (ftnlen)7);
	e_wsfe();
    } else {
	s_wsfe(&io___122);
	do_fio(&c__1, (char *)&timdmp_1.tleft, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, "SECONDS", (ftnlen)7);
	e_wsfe();
    }
    time = 1.;
    s_copy(chrono, "SECONDS", (ftnlen)7, (ftnlen)7);
    if (myword_(allkey, " DUMP", (ftnlen)241, (ftnlen)5)) {
	i__ = i_indx(keywrd, " DUMP", (ftnlen)241, (ftnlen)5);
	timdmp_1.tdump = reada_(keywrd, &i__, (ftnlen)241);
	for (j = i__ + 6; j <= 241; ++j) {
	    i__1 = j;
	    if (j == 241 || s_cmp(keywrd + i__1, " ", j + 1 - i__1, (ftnlen)1)
		     == 0) {
		*(unsigned char *)ch = *(unsigned char *)&keywrd[j - 1];
		if (*(unsigned char *)ch == 'M') {
		    s_copy(chrono, "MINUTES", (ftnlen)7, (ftnlen)7);
		}
		if (*(unsigned char *)ch == 'M') {
		    time = 60.;
		}
		if (*(unsigned char *)ch == 'H') {
		    s_copy(chrono, "HOURS", (ftnlen)7, (ftnlen)5);
		}
		if (*(unsigned char *)ch == 'H') {
		    time = 3600.;
		}
		if (*(unsigned char *)ch == 'D') {
		    s_copy(chrono, "DAYS", (ftnlen)7, (ftnlen)4);
		}
		if (*(unsigned char *)ch == 'D') {
		    time = 86400.;
		}
		goto L40;
	    }
/* L30: */
	}
L40:
	if (timdmp_1.tdump < 99999.9) {
	    s_wsfe(&io___123);
	    do_fio(&c__1, (char *)&timdmp_1.tdump, (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, chrono, (ftnlen)7);
	    e_wsfe();
	} else {
	    s_wsfe(&io___124);
	    do_fio(&c__1, (char *)&timdmp_1.tdump, (ftnlen)sizeof(doublereal))
		    ;
	    do_fio(&c__1, chrono, (ftnlen)7);
	    e_wsfe();
	}
	timdmp_1.tdump *= time;
    } else if (numcal_1.numcal == 1) {
	timdmp_1.tdump = 3600.;
	s_wsfe(&io___125);
	do_fio(&c__1, (char *)&timdmp_1.tdump, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, "SECONDS", (ftnlen)7);
	e_wsfe();
    } else {
	s_wsfe(&io___126);
	do_fio(&c__1, (char *)&timdmp_1.tdump, (ftnlen)sizeof(doublereal));
	do_fio(&c__1, "SECONDS", (ftnlen)7);
	e_wsfe();
    }
    if (myword_(allkey, "1SCF", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___127);
	e_wsfe();
	if (i_indx(keywrd, "RESTART", (ftnlen)241, (ftnlen)7) == 0) {
	    ++maxgeo;
	}
    }
    ci = myword_(allkey, "C.I.", (ftnlen)241, (ftnlen)4);
    if (ci) {
	j = i_indx(keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6);
	if (j != 0) {
	    s_wsfe(&io___129);
	    i__2 = i_indx(keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) + 7;
	    i__1 = (integer) reada_(keywrd, &i__2, (ftnlen)241);
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    i__4 = i_indx(keywrd, "C.I.=(", (ftnlen)241, (ftnlen)6) + 5;
	    i__3 = (integer) reada_(keywrd, &i__4, (ftnlen)241);
	    do_fio(&c__1, (char *)&i__3, (ftnlen)sizeof(integer));
	    e_wsfe();
	} else {
	    s_wsfe(&io___130);
	    i__2 = i_indx(keywrd, "C.I.", (ftnlen)241, (ftnlen)4) + 5;
	    i__1 = (integer) reada_(keywrd, &i__2, (ftnlen)241);
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    e_wsfe();
	}
    }
    if (myword_(allkey, " FORCE", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___131);
	e_wsfe();
	++maxgeo;
    }
    if (myword_(allkey, " EF", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___132);
	e_wsfe();
	++maxgeo;
    }
    if (myword_(allkey, " TS", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___133);
	e_wsfe();
	++maxgeo;
    }
    method = 0;
    if (myword_(allkey, "MINDO", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___135);
	e_wsfe();
	mindo3 = TRUE_;
	method = 1;
    }
    if (myword_(allkey, "AM1", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___136);
	e_wsfe();
	am1 = TRUE_;
	++method;
    }
    if (myword_(allkey, "PM3", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___137);
	e_wsfe();
	pm3 = TRUE_;
	++method;
    }
    if (myword_(allkey, "MNDO", (ftnlen)241, (ftnlen)4)) {
	mndo = TRUE_;
	++method;
    }
    if (myword_(allkey, "OLDGEO", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___138);
	e_wsfe();
    }
    if (myword_(allkey, "PREC", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___139);
	e_wsfe();
    }
    if (myword_(allkey, "NOINTER", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___140);
	e_wsfe();
    }
    if (myword_(allkey, "ISOTOPE", (ftnlen)241, (ftnlen)7)) {
	s_wsfe(&io___141);
	e_wsfe();
    }
    if (myword_(allkey, "DENOUT", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___142);
	e_wsfe();
    }
    if (myword_(allkey, "SHIFT", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___143);
	i__1 = i_indx(keywrd, "SHIFT", (ftnlen)241, (ftnlen)5);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, "OLDENS", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___144);
	e_wsfe();
    }
    if (myword_(allkey, "SCFCRT", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___145);
	i__1 = i_indx(keywrd, "SCFCRT", (ftnlen)241, (ftnlen)6);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, "ENPART", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___146);
	e_wsfe();
    }
    if (myword_(allkey, "NOXYZ", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___147);
	e_wsfe();
    }
    if (myword_(allkey, "SIGMA", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___148);
	e_wsfe();
	++maxgeo;
    }
    if (myword_(allkey, "NLLSQ", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___149);
	e_wsfe();
	++maxgeo;
    }
    if (myword_(allkey, "ROOT", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___150);
	i__2 = i_indx(keywrd, "ROOT", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "TRANS=", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___151);
	i__2 = i_indx(keywrd, "TRANS=", (ftnlen)241, (ftnlen)6);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    } else if (myword_(allkey, "TRANS", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___152);
	e_wsfe();
    }
    if (myword_(allkey, "SADDLE", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___153);
	e_wsfe();
	++maxgeo;
    }
    if (myword_(allkey, " LET", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___154);
	e_wsfe();
    }
    if (myword_(allkey, "COMPFG", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___155);
	e_wsfe();
    }
    if (myword_(allkey, "GNORM", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___156);
	i__1 = i_indx(keywrd, "GNORM", (ftnlen)241, (ftnlen)5);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, "PULAY", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___157);
	e_wsfe();
    }
    if (myword_(allkey, " STEP1", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___158);
	i__1 = i_indx(keywrd, "STEP1", (ftnlen)241, (ftnlen)5) + 6;
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, " STEP2", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___159);
	i__1 = i_indx(keywrd, "STEP2", (ftnlen)241, (ftnlen)5) + 6;
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, " STEP", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___160);
	i__1 = i_indx(keywrd, "STEP", (ftnlen)241, (ftnlen)4) + 5;
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, " POINT1", (ftnlen)241, (ftnlen)7)) {
	i__1 = i_indx(keywrd, "POINT1", (ftnlen)241, (ftnlen)6) + 7;
	ip1 = (integer) reada_(keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___162);
	do_fio(&c__1, (char *)&ip1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, " POINT2", (ftnlen)241, (ftnlen)7)) {
	i__1 = i_indx(keywrd, "POINT2", (ftnlen)241, (ftnlen)6) + 7;
	ip2 = (integer) reada_(keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___164);
	do_fio(&c__1, (char *)&ip2, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, " MAX", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___165);
	e_wsfe();
    }
    if (myword_(allkey, " POINT", (ftnlen)241, (ftnlen)6)) {
	i__1 = i_indx(keywrd, "POINT", (ftnlen)241, (ftnlen)5) + 6;
	ip = (integer) reada_(keywrd, &i__1, (ftnlen)241);
	s_wsfe(&io___167);
	do_fio(&c__1, (char *)&ip, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "BAR", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___168);
	i__1 = i_indx(keywrd, "BAR", (ftnlen)241, (ftnlen)3);
	d__1 = reada_(keywrd, &i__1, (ftnlen)241);
	do_fio(&c__1, (char *)&d__1, (ftnlen)sizeof(doublereal));
	e_wsfe();
    }
    if (myword_(allkey, "CAMP", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___169);
	e_wsfe();
    }
    if (myword_(allkey, "KING", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___170);
	e_wsfe();
    }
    if (myword_(allkey, "EIGS", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___171);
	e_wsfe();
    }
    if (myword_(allkey, "EIGINV", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___172);
	e_wsfe();
    }
    if (myword_(allkey, "NONR", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___173);
	e_wsfe();
    }
    if (myword_(allkey, "ORIDE", (ftnlen)241, (ftnlen)5)) {
	s_wsfe(&io___174);
	e_wsfe();
    }
    if (myword_(allkey, "HYPERF", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___175);
	e_wsfe();
    }
    if (myword_(allkey, " PL", (ftnlen)241, (ftnlen)3)) {
	s_wsfe(&io___176);
	e_wsfe();
    }
    if (myword_(allkey, "FILL", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___177);
	i__2 = i_indx(keywrd, "FILL", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "ITRY", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___178);
	i__2 = i_indx(keywrd, "ITRY", (ftnlen)241, (ftnlen)4);
	d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	i__1 = i_dnnt(&d__1);
	do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	e_wsfe();
    }
    if (myword_(allkey, "0SCF", (ftnlen)241, (ftnlen)4)) {
	s_wsfe(&io___179);
	e_wsfe();
    }
    if (uhf) {
	if (birad || exci || ci) {
	    s_wsfe(&io___180);
	    e_wsfe();
	    s_wsfe(&io___181);
	    e_wsfe();
	    goto L60;
	}
    } else {
	if (exci && trip) {
	    s_wsfe(&io___182);
	    e_wsfe();
	    s_wsfe(&io___183);
	    e_wsfe();
	    goto L60;
	}
    }
    if (i_indx(keywrd, "T-PRIO", (ftnlen)241, (ftnlen)6) != 0 && i_indx(
	    keywrd, "DRC", (ftnlen)241, (ftnlen)3) == 0) {
	s_wsfe(&io___184);
	e_wsfe();
	s_wsfe(&io___185);
	e_wsfe();
	goto L60;
    }
    if (method > 1) {
	s_wsfe(&io___186);
	e_wsfe();
	s_wsfe(&io___187);
	e_wsfe();
	goto L60;
    }
    if (myword_(allkey, " FIELD", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___188);
	e_wsfe();
    }
    if (myword_(allkey, "THERMO", (ftnlen)241, (ftnlen)6)) {
	s_wsfe(&io___189);
	e_wsfe();
	if (myword_(allkey, " ROT", (ftnlen)241, (ftnlen)4)) {
	    s_wsfe(&io___190);
	    i__2 = i_indx(keywrd, " ROT", (ftnlen)241, (ftnlen)4);
	    d__1 = reada_(keywrd, &i__2, (ftnlen)241);
	    i__1 = i_dnnt(&d__1);
	    do_fio(&c__1, (char *)&i__1, (ftnlen)sizeof(integer));
	    e_wsfe();
	} else {
	    s_wsfe(&io___191);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
    if (maxgeo > 1) {
	s_wsfe(&io___192);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (i_indx(keywrd, "MULLIK", (ftnlen)241, (ftnlen)6) != 0 && uhf) {
	s_wsfe(&io___193);
	do_fio(&c__1, " MULLIKEN POPULATION NOT AVAILABLE WITH UHF", (ftnlen)
		43);
	e_wsfe();
	s_stop("", (ftnlen)0);
    }
    if (s_cmp(allkey, " ", (ftnlen)241, (ftnlen)1) != 0) {
	j = 0;
	for (i__ = 1; i__ <= 240; ++i__) {
	    if (*(unsigned char *)&allkey[i__ - 1] != ' ' || s_cmp(allkey + (
		    i__ - 1), "  ", (ftnlen)2, (ftnlen)2) != 0) {
		++j;
		*(unsigned char *)ch = *(unsigned char *)&allkey[i__ - 1];
		*(unsigned char *)&allkey[j - 1] = *(unsigned char *)ch;
	    }
/* L50: */
	}
	if (*(unsigned char *)&allkey[240] != ' ') {
	    ++j;
	    *(unsigned char *)ch = *(unsigned char *)&allkey[240];
	    *(unsigned char *)&allkey[j - 1] = *(unsigned char *)ch;
	}
	j = max(1,j);
	l = i_indx(keywrd, "DEBUG", (ftnlen)241, (ftnlen)5);
	if (l != 0) {
	    s_wsfe(&io___195);
	    do_fio(&c__1, allkey, j);
	    e_wsfe();
	} else {
	    s_wsfe(&io___196);
	    do_fio(&c__1, allkey, j);
	    e_wsfe();
	    s_wsfe(&io___197);
	    e_wsfe();
	    s_wsfe(&io___198);
	    e_wsfe();
	    s_stop("", (ftnlen)0);
	}
    }
    return 0;
L60:
    s_wsfe(&io___199);
    e_wsfe();
    s_stop("", (ftnlen)0);
/* *********************************************************** */
/* *********************************************************** */
/* *********************************************************** */

/*     KEYWORDS ADDED FOR ESP MOPAC */

/* L880: */
    return 0;
} /* wrtkey_ */

logical myword_(char *keywrd, char *testwd, ftnlen keywrd_len, ftnlen 
	testwd_len)
{
    /* System generated locals */
    logical ret_val;

    /* Builtin functions */
    integer i_indx(char *, char *, ftnlen, ftnlen);

    /* Local variables */
    static integer j, k;

    ret_val = FALSE_;
L10:
    j = i_indx(keywrd, testwd, keywrd_len, testwd_len);
    if (j != 0) {
L20:
	if (*(unsigned char *)&keywrd[j - 1] != ' ') {
	    goto L30;
	}
	++j;
	goto L20;
L30:
	ret_val = TRUE_;
	for (k = j; k <= 241; ++k) {
	    if (*(unsigned char *)&keywrd[k - 1] == '=' || *(unsigned char *)&
		    keywrd[k - 1] == ' ') {

/*     CHECK FOR ATTACHED '=' SIGN */

		j = k;
		if (*(unsigned char *)&keywrd[j - 1] == '=') {
		    goto L50;
		}

/*     CHECK FOR SEPARATED '=' SIGN */

		for (j = k + 1; j <= 241; ++j) {
		    if (*(unsigned char *)&keywrd[j - 1] == '=') {
			goto L50;
		    }
/* L40: */
		    if (*(unsigned char *)&keywrd[j - 1] != ' ') {
			goto L10;
		    }
		}

/*    THERE IS NO '=' SIGN ASSOCIATED WITH THIS KEYWORD */

		goto L10;
L50:
		*(unsigned char *)&keywrd[j - 1] = ' ';

/*   THERE MUST BE A NUMBER AFTER THE '=' SIGN, SOMEWHERE */

		goto L20;
	    }
/* L60: */
	    *(unsigned char *)&keywrd[k - 1] = ' ';
	}
    }
    return ret_val;
} /* myword_ */

