/* block.f -- translated by f2c (version 20020621).
   You must link the resulting object file with the libraries:
	-lf2c -lm   (in that order)
*/

#include "f2c.h"

/* Common Block Declarations */

struct natorb_1_ {
    integer natorb[107];
};

#define natorb_1 (*(struct natorb_1_ *) &natorb_)

struct elemts_1_ {
    char elemnt[214];
};

#define elemts_1 (*(struct elemts_1_ *) &elemts_)

struct core_1_ {
    doublereal core[107];
};

#define core_1 (*(struct core_1_ *) &core_)

struct {
    doublereal dd[107], qq[107], am[107], ad[107], aq[107];
} multip_;

#define multip_1 multip_

struct {
    doublereal zs[107], zp[107], zd[107];
} expont_;

#define expont_1 expont_

struct {
    doublereal uss[107], upp[107], udd[107];
} onelec_;

#define onelec_1 onelec_

struct {
    doublereal betas[107], betap[107], betad[107];
} betas_;

#define betas_1 betas_

struct twoele_1_ {
    doublereal gss[107], gsp[107], gpp[107], gp2[107], hsp[107], gsd[107], 
	    gpd[107], gdd[107];
};

#define twoele_1 (*(struct twoele_1_ *) &twoele_)

struct atomic_1_ {
    doublereal eisol[107], eheat[107];
};

#define atomic_1 (*(struct atomic_1_ *) &atomic_)

struct vsips_1_ {
    doublereal vs[107], vp[107], vd[107];
};

#define vsips_1 (*(struct vsips_1_ *) &vsips_)

struct istope_1_ {
    doublereal ams[107];
};

#define istope_1 (*(struct istope_1_ *) &istope_)

struct ideaa_1_ {
    doublereal guesa1[1070]	/* was [107][10] */, guesa2[1070]	/* 
	    was [107][10] */, guesa3[1070]	/* was [107][10] */;
};

#define ideaa_1 (*(struct ideaa_1_ *) &ideaa_)

struct ideap_1_ {
    doublereal guesp1[1070]	/* was [107][10] */, guesp2[1070]	/* 
	    was [107][10] */, guesp3[1070]	/* was [107][10] */;
};

#define ideap_1 (*(struct ideap_1_ *) &ideap_)

struct {
    doublereal fn1[107], fn2[107];
} gauss_;

#define gauss_1 gauss_

struct mndo_1_ {
    doublereal ussm[107], uppm[107], uddm[107], zsm[107], zpm[107], zdm[107], 
	    betasm[107], betapm[107], betadm[107], alpm[107], eisolm[107], 
	    ddm[107], qqm[107], amm[107], adm[107], aqm[107], gssm[107], gspm[
	    107], gppm[107], gp2m[107], hspm[107], polvom[107];
};

#define mndo_1 (*(struct mndo_1_ *) &mndo_)

struct pm3_1_ {
    doublereal usspm3[107], upppm3[107], uddpm3[107], zspm3[107], zppm3[107], 
	    zdpm3[107], betasp[107], betapp[107], betadp[107], alppm3[107], 
	    eisolp[107], ddpm3[107], qqpm3[107], ampm3[107], adpm3[107], 
	    aqpm3[107], gsspm3[107], gsppm3[107], gpppm3[107], gp2pm3[107], 
	    hsppm3[107], polvop[107];
};

#define pm3_1 (*(struct pm3_1_ *) &pm3_)

struct am1blo_1_ {
    doublereal ussam1[107], uppam1[107], uddam1[107], zsam1[107], zpam1[107], 
	    zdam1[107], betasa[107], betapa[107], betada[107], alpam1[107], 
	    eisola[107], ddam1[107], qqam1[107], amam1[107], adam1[107], 
	    aqam1[107], gssam1[107], gspam1[107], gppam1[107], gp2am1[107], 
	    hspam1[107], polvoa[107];
};

#define am1blo_1 (*(struct am1blo_1_ *) &am1blo_)

struct refs_1_ {
    char refmn[8560], refm3[8560], refam[8560], refpm3[8560];
};

#define refs_1 (*(struct refs_1_ *) &refs_)

struct onele3_1_ {
    doublereal uss3[18], upp3[18];
};

#define onele3_1 (*(struct onele3_1_ *) &onele3_)

struct twoel3_1_ {
    doublereal f03[107];
};

#define twoel3_1 (*(struct twoel3_1_ *) &twoel3_)

struct atomi3_1_ {
    doublereal eisol3[18], eheat3[18];
};

#define atomi3_1 (*(struct atomi3_1_ *) &atomi3_)

struct beta3_1_ {
    doublereal beta3[153];
};

#define beta3_1 (*(struct beta3_1_ *) &beta3_)

struct alpha3_1_ {
    doublereal alp3[153];
};

#define alpha3_1 (*(struct alpha3_1_ *) &alpha3_)

struct expon3_1_ {
    doublereal zs3[18], zp3[18];
};

#define expon3_1 (*(struct expon3_1_ *) &expon3_)

struct field_1_ {
    doublereal efield[3];
};

#define field_1 (*(struct field_1_ *) &field_)

/* Initialized data */

struct {
    integer e_1[107];
    } natorb_ = { 1, 1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 4, 0, 4, 
	    9, 9, 9, 9, 9, 9, 9, 9, 9, 4, 4, 4, 4, 4, 4, 4, 4, 4, 9, 9, 9, 9, 
	    9, 9, 9, 9, 9, 4, 4, 4, 4, 4, 4, 4, 2, 2, 8, 8, 8, 8, 8, 8, 8, 8, 
	    8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 4, 4, 4, 4, 4, 4, 4, 
	    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 };

struct {
    char e_1[214];
    } elemts_ = { " HHeLiBe B C N O FNeNaMgAlSi P SClAr KCaScTi VCrMnFeCoNiC"
	    "uZnGaGeAsSeBrKrRbSr YZrNbMoTcRuRhPdAgCdInSnSbTe IXeCsBaLaCePrNdP"
	    "mSmEuGdTbDyHoErTmYbLuHfTa WReOsIrPtAuHgTlPbBiPoAtRnFrRaAcThPa UN"
	    "pPuAmCmBkCfXXFmMdCb++ +-- -Tv" };

struct {
    doublereal e_1[107];
    } istope_ = { 1.0079, 4.0026, 6.94, 9.01218, 10.81, 12.011, 14.0067, 
	    15.9994, 18.9984, 20.179, 22.98977, 24.305, 26.98154, 28.0855, 
	    30.97376, 32.06, 35.453, 39.948, 39.0983, 40.08, 44.9559, 47.9, 
	    50.9415, 51.996, 54.938, 55.847, 58.9332, 58.71, 63.546, 65.38, 
	    69.735, 72.59, 74.9216, 78.96, 79.904, 83.8, 85.4678, 87.62, 
	    88.9059, 91.22, 92.9064, 95.94, 98.9062, 101.07, 102.9055, 106.4, 
	    107.868, 112.41, 114.82, 118.69, 121.75, 127.6, 126.9045, 131.3, 
	    132.9054, 137.33, 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 178.49, 180.9479, 183.85, 186.207, 190.2, 192.22, 
	    195.09, 196.9665, 200.59, 204.37, 207.2, 208.9804, 0., 0., 0., 0.,
	     0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 1.0079, 
	    0., 0., 0., 0., 0. };

struct {
    doublereal e_1;
    doublereal fill_2[4];
    doublereal e_3[4];
    doublereal fill_4[3];
    doublereal e_5[5];
    doublereal fill_6[17];
    doublereal e_7;
    doublereal fill_8[17];
    doublereal e_9;
    doublereal fill_10[54];
    doublereal e_11;
    doublereal fill_12[4];
    doublereal e_13[4];
    doublereal fill_14[4];
    doublereal e_15[4];
    doublereal fill_16[17];
    doublereal e_17;
    doublereal fill_18[17];
    doublereal e_19;
    doublereal fill_20[54];
    doublereal e_21;
    doublereal fill_22[4];
    doublereal e_23[2];
    doublereal fill_24[6];
    doublereal e_25[3];
    doublereal fill_26[96];
    doublereal e_27;
    doublereal fill_28[743];
    doublereal e_29;
    doublereal fill_30[4];
    doublereal e_31[4];
    doublereal fill_32[3];
    doublereal e_33[5];
    doublereal fill_34[17];
    doublereal e_35;
    doublereal fill_36[17];
    doublereal e_37;
    doublereal fill_38[54];
    doublereal e_39;
    doublereal fill_40[4];
    doublereal e_41[4];
    doublereal fill_42[4];
    doublereal e_43[4];
    doublereal fill_44[17];
    doublereal e_45;
    doublereal fill_46[17];
    doublereal e_47;
    doublereal fill_48[54];
    doublereal e_49;
    doublereal fill_50[4];
    doublereal e_51[2];
    doublereal fill_52[6];
    doublereal e_53[3];
    doublereal fill_54[96];
    doublereal e_55;
    doublereal fill_56[743];
    doublereal e_57;
    doublereal fill_58[4];
    doublereal e_59[4];
    doublereal fill_60[3];
    doublereal e_61[5];
    doublereal fill_62[17];
    doublereal e_63;
    doublereal fill_64[17];
    doublereal e_65;
    doublereal fill_66[54];
    doublereal e_67;
    doublereal fill_68[4];
    doublereal e_69[4];
    doublereal fill_70[4];
    doublereal e_71[4];
    doublereal fill_72[17];
    doublereal e_73;
    doublereal fill_74[17];
    doublereal e_75;
    doublereal fill_76[54];
    doublereal e_77;
    doublereal fill_78[4];
    doublereal e_79[2];
    doublereal fill_80[6];
    doublereal e_81[3];
    doublereal fill_82[96];
    doublereal e_83;
    doublereal fill_84[743];
    } ideaa_ = { .122796, {0}, .011355, .025251, .280962, .242079, {0}, .09, 
	    .25, -.031827, -.509195, .094243, {0}, .066685, {0}, .004361, {0},
	     .00509, {0}, .045924, .028953, .08143, .003607, {0}, .061513, 
	    .01847, -.011863, .027168, {0}, .025568, {0}, .015706, {0}, 
	    -.018336, {0}, -.020061, -.005806, {0}, .020789, .03329, .012334, 
	    {0}, -.00126, {0}, 5., {0}, 5., 5., 5., 4.8, {0}, 12.392443, 9., 
	    6., 4.593691, 4., {0}, 4., {0}, 2.3, {0}, 5., {0}, 5., 5., 7., 
	    4.6, {0}, 5., 7., 5.865731, 4., {0}, 4., {0}, 3., {0}, 2., {0}, 
	    5., 2., {0}, 5., 9., 13.557336, {0}, 5., {0}, 1.2, {0}, 1.6, 1.5, 
	    .847918, .93, {0}, 2.050394, .911453, 1.474323, .770665, 1.3, {0},
	     1.5, {0}, 1.8, {0}, 1.8, {0}, 1.85, 2.1, 1.445071, 1.66, {0}, 
	    1.995569, 1.779354, 1.503313, 2.1, {0}, 2.3, {0}, 2.24, {0}, 2.1, 
	    {0}, 2.05, 2.4, {0}, 2.99061, 3.006576, 2.009173, {0}, 2.65 };

struct {
    doublereal e_1;
    doublereal fill_2[2];
    doublereal e_3;
    doublereal fill_4[1];
    doublereal e_5[4];
    doublereal fill_6[2];
    doublereal e_7[6];
    doublereal fill_8[12];
    doublereal e_9[6];
    doublereal fill_10[13];
    doublereal e_11[5];
    doublereal fill_12[26];
    doublereal e_13[4];
    doublereal fill_14[24];
    doublereal e_15;
    doublereal fill_16[2];
    doublereal e_17;
    doublereal fill_18[1];
    doublereal e_19[4];
    doublereal fill_20[2];
    doublereal e_21[6];
    doublereal fill_22[12];
    doublereal e_23[6];
    doublereal fill_24[13];
    doublereal e_25[5];
    doublereal fill_26[26];
    doublereal e_27[4];
    doublereal fill_28[880];
    doublereal e_29;
    doublereal fill_30[2];
    doublereal e_31;
    doublereal fill_32[1];
    doublereal e_33[4];
    doublereal fill_34[2];
    doublereal e_35[6];
    doublereal fill_36[12];
    doublereal e_37[6];
    doublereal fill_38[13];
    doublereal e_39[5];
    doublereal fill_40[26];
    doublereal e_41[4];
    doublereal fill_42[24];
    doublereal e_43;
    doublereal fill_44[2];
    doublereal e_45;
    doublereal fill_46[1];
    doublereal e_47[4];
    doublereal fill_48[2];
    doublereal e_49[6];
    doublereal fill_50[12];
    doublereal e_51[6];
    doublereal fill_52[13];
    doublereal e_53[5];
    doublereal fill_54[26];
    doublereal e_55[4];
    doublereal fill_56[880];
    doublereal e_57;
    doublereal fill_58[2];
    doublereal e_59;
    doublereal fill_60[1];
    doublereal e_61[4];
    doublereal fill_62[2];
    doublereal e_63[6];
    doublereal fill_64[12];
    doublereal e_65[6];
    doublereal fill_66[13];
    doublereal e_67[5];
    doublereal fill_68[26];
    doublereal e_69[4];
    doublereal fill_70[24];
    doublereal e_71;
    doublereal fill_72[2];
    doublereal e_73;
    doublereal fill_74[1];
    doublereal e_75[4];
    doublereal fill_76[2];
    doublereal e_77[6];
    doublereal fill_78[12];
    doublereal e_79[6];
    doublereal fill_80[13];
    doublereal e_81[5];
    doublereal fill_82[26];
    doublereal e_83[4];
    doublereal fill_84[880];
    } ideap_ = { 1.12875, {0}, 1.631572, {0}, .050107, 1.501674, -1.131128, 
	    -.012166, {0}, 2.11705, -.47309, -.3906, -.611421, -.399191, 
	    -.171591, {0}, -.111234, -.560179, .9631726, -.460095, .047873, 
	    .960458, {0}, -.343138, -.150353, 3.002028, .033391, -.131481, {0}
	    , 1.08272, -1.361399, -.122576, 2.581693, {0}, -1.060329, {0}, 
	    -2.110959, {0}, .050733, -1.505772, 1.137891, -.002852, {0}, 
	    -2.547767, -.154051, .057259, -.093935, -.054899, -.013458, {0}, 
	    -.13237, -.272731, -.9593891, -.088996, .11472, -.954916, {0}, 
	    -.109532, -.044417, -.018892, -1.921867, -.036897, {0}, -.096553, 
	    -.045401, -.056648, .06032, {0}, 5.096282, {0}, 2.672962, {0}, 
	    6.003165, 5.901148, 6.002477, 6.023574, {0}, 6.009477, 1.915825, 
	    6.000054, 1.997272, 6.000669, 6.000802, {0}, 6.001478, 5.623273, 
	    6.0120134, 1.983115, 6.0074, 5.976508, {0}, 1.994034, 6.005694, 
	    6.005342, 5.956379, 5.206417, {0}, 6.496598, 3.557226, 6.003062, 
	    5.094022, {0}, 6.003788, {0}, 1.968594, {0}, 6.002979, 6.004658, 
	    5.950512, 6.003717, {0}, 4.39537, 6.005086, 6.007183, 1.99836, 
	    6.001845, 1.966618, {0}, 1.995839, 1.991843, 5.7491802, 1.992944, 
	    6.008672, 5.944703, {0}, 5.683217, 2.257381, 6.011478, 4.973219, 
	    6.010117, {0}, 3.926281, 2.306995, 4.743705, 6.001538, {0}, 
	    1.537465, {0}, 1.791686, {0}, 1.642214, 1.71074, 1.607311, 
	    1.856859, {0}, 2.084406, 1.451728, .632262, .794624, .962123, 
	    1.087502, {0}, 1.516032, 1.53178, 2.1633655, 1.086793, 2.081717, 
	    2.321654, {0}, 1.625516, 1.704642, .85306, 2.277575, 1.748824, {0}
	    , 1.195146, 1.092802, 1.901597, .499787, {0}, 1.570189, {0}, 
	    1.755871, {0}, .892488, 1.716149, 1.598395, 2.636158, {0}, 
	    2.063674, 2.519997, 2.019987, 1.910677, 1.579944, 2.292891, {0}, 
	    2.519642, 2.183864, 2.1693724, 2.140058, 1.516423, 2.328142, {0}, 
	    2.867009, 2.469869, 2.793311, .524243, 2.710373, {0}, 2.62716, 
	    2.965029, 2.861879, 2.42797 };

struct {
    doublereal e_1;
    doublereal fill_2[1];
    doublereal e_3[7];
    doublereal fill_4[3];
    doublereal e_5[5];
    doublereal fill_6[6];
    doublereal e_7;
    doublereal fill_8[5];
    doublereal e_9;
    doublereal fill_10[1];
    doublereal e_11;
    doublereal fill_12[2];
    doublereal e_13;
    doublereal fill_14[14];
    doublereal e_15;
    doublereal fill_16[2];
    doublereal e_17;
    doublereal fill_18[26];
    doublereal e_19;
    doublereal fill_20[1];
    doublereal e_21;
    doublereal fill_22[7];
    doublereal e_23[2];
    doublereal fill_24[10];
    doublereal e_25;
    doublereal fill_26[7];
    doublereal e_27[7];
    doublereal fill_28[3];
    doublereal e_29[5];
    doublereal fill_30[6];
    doublereal e_31;
    doublereal fill_32[5];
    doublereal e_33;
    doublereal fill_34[1];
    doublereal e_35;
    doublereal fill_36[2];
    doublereal e_37;
    doublereal fill_38[14];
    doublereal e_39;
    doublereal fill_40[2];
    doublereal e_41;
    doublereal fill_42[26];
    doublereal e_43;
    doublereal fill_44[1];
    doublereal e_45;
    doublereal fill_46[7];
    doublereal e_47[2];
    doublereal fill_48[39];
    doublereal e_49;
    doublereal fill_50[83];
    doublereal e_51;
    doublereal fill_52[1];
    doublereal e_53[7];
    doublereal fill_54[3];
    doublereal e_55[5];
    doublereal fill_56[6];
    doublereal e_57;
    doublereal fill_58[5];
    doublereal e_59;
    doublereal fill_60[1];
    doublereal e_61;
    doublereal fill_62[2];
    doublereal e_63;
    doublereal fill_64[14];
    doublereal e_65;
    doublereal fill_66[2];
    doublereal e_67;
    doublereal fill_68[26];
    doublereal e_69;
    doublereal fill_70[1];
    doublereal e_71;
    doublereal fill_72[7];
    doublereal e_73[2];
    doublereal fill_74[10];
    doublereal e_75;
    doublereal fill_76[7];
    doublereal e_77[7];
    doublereal fill_78[3];
    doublereal e_79[5];
    doublereal fill_80[6];
    doublereal e_81;
    doublereal fill_82[5];
    doublereal e_83;
    doublereal fill_84[1];
    doublereal e_85;
    doublereal fill_86[2];
    doublereal e_87;
    doublereal fill_88[14];
    doublereal e_89;
    doublereal fill_90[2];
    doublereal e_91;
    doublereal fill_92[26];
    doublereal e_93;
    doublereal fill_94[1];
    doublereal e_95;
    doublereal fill_96[7];
    doublereal e_97[2];
    doublereal fill_98[10];
    doublereal e_99;
    doublereal fill_100[17];
    doublereal e_101[5];
    doublereal fill_102[6];
    doublereal e_103;
    doublereal fill_104[5];
    doublereal e_105;
    doublereal fill_106[4];
    doublereal e_107;
    doublereal fill_108[17];
    doublereal e_109;
    doublereal fill_110[36];
    doublereal e_111[2];
    doublereal fill_112[10];
    doublereal e_113;
    doublereal fill_114[5];
    doublereal e_115;
    doublereal fill_116[1];
    doublereal e_117[7];
    doublereal fill_118[3];
    doublereal e_119[5];
    doublereal fill_120[6];
    doublereal e_121;
    doublereal fill_122[5];
    doublereal e_123;
    doublereal fill_124[1];
    doublereal e_125;
    doublereal fill_126[2];
    doublereal e_127;
    doublereal fill_128[14];
    doublereal e_129;
    doublereal fill_130[2];
    doublereal e_131;
    doublereal fill_132[26];
    doublereal e_133;
    doublereal fill_134[1];
    doublereal e_135;
    doublereal fill_136[7];
    doublereal e_137[2];
    doublereal fill_138[10];
    doublereal e_139;
    doublereal fill_140[7];
    doublereal e_141[7];
    doublereal fill_142[3];
    doublereal e_143[5];
    doublereal fill_144[6];
    doublereal e_145;
    doublereal fill_146[5];
    doublereal e_147;
    doublereal fill_148[1];
    doublereal e_149;
    doublereal fill_150[2];
    doublereal e_151;
    doublereal fill_152[14];
    doublereal e_153;
    doublereal fill_154[2];
    doublereal e_155;
    doublereal fill_156[26];
    doublereal e_157;
    doublereal fill_158[1];
    doublereal e_159;
    doublereal fill_160[7];
    doublereal e_161[2];
    doublereal fill_162[39];
    doublereal e_163;
    doublereal fill_164[83];
    doublereal e_165;
    doublereal fill_166[1];
    doublereal e_167[7];
    doublereal fill_168[1];
    doublereal e_169;
    doublereal fill_170[1];
    doublereal e_171[5];
    doublereal fill_172[1];
    doublereal e_173;
    doublereal fill_174[4];
    doublereal e_175;
    doublereal fill_176[5];
    doublereal e_177;
    doublereal fill_178[1];
    doublereal e_179;
    doublereal fill_180[2];
    doublereal e_181;
    doublereal fill_182[14];
    doublereal e_183;
    doublereal fill_184[2];
    doublereal e_185;
    doublereal fill_186[26];
    doublereal e_187;
    doublereal fill_188[1];
    doublereal e_189;
    doublereal fill_190[7];
    doublereal e_191[2];
    doublereal fill_192[10];
    doublereal e_193[5];
    doublereal fill_194[1];
    doublereal e_195;
    doublereal fill_196[1];
    doublereal e_197[7];
    doublereal fill_198[1];
    doublereal e_199;
    doublereal fill_200[1];
    doublereal e_201[5];
    doublereal fill_202[1];
    doublereal e_203;
    doublereal fill_204[4];
    doublereal e_205;
    doublereal fill_206[5];
    doublereal e_207;
    doublereal fill_208[1];
    doublereal e_209;
    doublereal fill_210[2];
    doublereal e_211;
    doublereal fill_212[14];
    doublereal e_213;
    doublereal fill_214[2];
    doublereal e_215;
    doublereal fill_216[26];
    doublereal e_217;
    doublereal fill_218[1];
    doublereal e_219;
    doublereal fill_220[7];
    doublereal e_221[2];
    doublereal fill_222[10];
    doublereal e_223[5];
    doublereal fill_224[3];
    doublereal e_225[7];
    doublereal fill_226[3];
    doublereal e_227[5];
    doublereal fill_228[6];
    doublereal e_229;
    doublereal fill_230[5];
    doublereal e_231;
    doublereal fill_232[1];
    doublereal e_233;
    doublereal fill_234[2];
    doublereal e_235;
    doublereal fill_236[14];
    doublereal e_237;
    doublereal fill_238[2];
    doublereal e_239;
    doublereal fill_240[26];
    doublereal e_241;
    doublereal fill_242[1];
    doublereal e_243;
    doublereal fill_244[7];
    doublereal e_245[2];
    doublereal fill_246[10];
    doublereal e_247;
    doublereal fill_248[7];
    doublereal e_249[7];
    doublereal fill_250[3];
    doublereal e_251[5];
    doublereal fill_252[6];
    doublereal e_253;
    doublereal fill_254[5];
    doublereal e_255;
    doublereal fill_256[1];
    doublereal e_257;
    doublereal fill_258[2];
    doublereal e_259;
    doublereal fill_260[14];
    doublereal e_261;
    doublereal fill_262[2];
    doublereal e_263;
    doublereal fill_264[26];
    doublereal e_265;
    doublereal fill_266[1];
    doublereal e_267;
    doublereal fill_268[7];
    doublereal e_269[2];
    doublereal fill_270[10];
    doublereal e_271;
    doublereal fill_272[5];
    doublereal e_273;
    doublereal fill_274[1];
    doublereal e_275[7];
    doublereal fill_276[1];
    doublereal e_277;
    doublereal fill_278[1];
    doublereal e_279[5];
    doublereal fill_280[1];
    doublereal e_281;
    doublereal fill_282[4];
    doublereal e_283;
    doublereal fill_284[5];
    doublereal e_285;
    doublereal fill_286[1];
    doublereal e_287;
    doublereal fill_288[2];
    doublereal e_289;
    doublereal fill_290[14];
    doublereal e_291;
    doublereal fill_292[2];
    doublereal e_293;
    doublereal fill_294[26];
    doublereal e_295;
    doublereal fill_296[1];
    doublereal e_297;
    doublereal fill_298[7];
    doublereal e_299[2];
    doublereal fill_300[10];
    doublereal e_301[5];
    doublereal fill_302[1];
    doublereal e_303;
    doublereal fill_304[1];
    doublereal e_305[7];
    doublereal fill_306[3];
    doublereal e_307[5];
    doublereal fill_308[6];
    doublereal e_309;
    doublereal fill_310[5];
    doublereal e_311;
    doublereal fill_312[1];
    doublereal e_313;
    doublereal fill_314[2];
    doublereal e_315;
    doublereal fill_316[14];
    doublereal e_317;
    doublereal fill_318[2];
    doublereal e_319;
    doublereal fill_320[26];
    doublereal e_321;
    doublereal fill_322[1];
    doublereal e_323;
    doublereal fill_324[7];
    doublereal e_325[2];
    doublereal fill_326[10];
    doublereal e_327;
    doublereal fill_328[5];
    doublereal e_329;
    doublereal fill_330[1];
    doublereal e_331[7];
    doublereal fill_332[3];
    doublereal e_333[5];
    doublereal fill_334[6];
    doublereal e_335;
    doublereal fill_336[5];
    doublereal e_337;
    doublereal fill_338[1];
    doublereal e_339;
    doublereal fill_340[2];
    doublereal e_341;
    doublereal fill_342[14];
    doublereal e_343;
    doublereal fill_344[2];
    doublereal e_345;
    doublereal fill_346[26];
    doublereal e_347;
    doublereal fill_348[1];
    doublereal e_349;
    doublereal fill_350[7];
    doublereal e_351[2];
    doublereal fill_352[10];
    doublereal e_353;
    doublereal fill_354[5];
    doublereal e_355;
    doublereal fill_356[1];
    doublereal e_357[7];
    doublereal fill_358[3];
    doublereal e_359[5];
    doublereal fill_360[6];
    doublereal e_361;
    doublereal fill_362[5];
    doublereal e_363;
    doublereal fill_364[1];
    doublereal e_365;
    doublereal fill_366[2];
    doublereal e_367;
    doublereal fill_368[14];
    doublereal e_369;
    doublereal fill_370[2];
    doublereal e_371;
    doublereal fill_372[26];
    doublereal e_373;
    doublereal fill_374[1];
    doublereal e_375;
    doublereal fill_376[7];
    doublereal e_377;
    doublereal fill_378[11];
    doublereal e_379;
    doublereal fill_380[7];
    doublereal e_381[7];
    doublereal fill_382[3];
    doublereal e_383[5];
    doublereal fill_384[6];
    doublereal e_385;
    doublereal fill_386[5];
    doublereal e_387;
    doublereal fill_388[1];
    doublereal e_389;
    doublereal fill_390[2];
    doublereal e_391;
    doublereal fill_392[14];
    doublereal e_393;
    doublereal fill_394[2];
    doublereal e_395;
    doublereal fill_396[26];
    doublereal e_397;
    doublereal fill_398[1];
    doublereal e_399;
    doublereal fill_400[7];
    doublereal e_401;
    doublereal fill_402[19];
    doublereal e_403[7];
    doublereal fill_404[3];
    doublereal e_405[5];
    doublereal fill_406[6];
    doublereal e_407;
    doublereal fill_408[5];
    doublereal e_409;
    doublereal fill_410[1];
    doublereal e_411;
    doublereal fill_412[2];
    doublereal e_413;
    doublereal fill_414[14];
    doublereal e_415;
    doublereal fill_416[2];
    doublereal e_417;
    doublereal fill_418[26];
    doublereal e_419;
    doublereal fill_420[1];
    doublereal e_421;
    doublereal fill_422[7];
    doublereal e_423;
    doublereal fill_424[19];
    doublereal e_425[7];
    doublereal fill_426[3];
    doublereal e_427[5];
    doublereal fill_428[6];
    doublereal e_429;
    doublereal fill_430[5];
    doublereal e_431;
    doublereal fill_432[1];
    doublereal e_433;
    doublereal fill_434[2];
    doublereal e_435;
    doublereal fill_436[14];
    doublereal e_437;
    doublereal fill_438[2];
    doublereal e_439;
    doublereal fill_440[26];
    doublereal e_441;
    doublereal fill_442[1];
    doublereal e_443;
    doublereal fill_444[7];
    doublereal e_445;
    doublereal fill_446[19];
    doublereal e_447[7];
    doublereal fill_448[3];
    doublereal e_449[5];
    doublereal fill_450[6];
    doublereal e_451;
    doublereal fill_452[5];
    doublereal e_453;
    doublereal fill_454[1];
    doublereal e_455;
    doublereal fill_456[2];
    doublereal e_457;
    doublereal fill_458[14];
    doublereal e_459;
    doublereal fill_460[2];
    doublereal e_461;
    doublereal fill_462[26];
    doublereal e_463;
    doublereal fill_464[1];
    doublereal e_465;
    doublereal fill_466[7];
    doublereal e_467;
    doublereal fill_468[11];
    doublereal e_469;
    doublereal fill_470[5];
    doublereal e_471;
    doublereal fill_472[4];
    doublereal e_473[4];
    doublereal fill_474[7];
    doublereal e_475;
    doublereal fill_476[17];
    doublereal e_477;
    doublereal fill_478[17];
    doublereal e_479;
    doublereal fill_480[54];
    } mndo_ = { -11.906276, {0}, -5.128, -16.602378, -34.54713, -52.279745, 
	    -71.932122, -99.644309, -131.071548, {0}, -23.807097, -37.037533, 
	    -56.14336, -72.242281, -100.227166, {0}, -17.517027, {0}, 
	    -20.839716, {0}, -33.949367, {0}, -99.9864405, {0}, -40.851802, {
	    0}, -100.0030538, {0}, -19.809574, {0}, -47.319692, {0}, 
	    -40.568292, -75.239152, {0}, -11.906276, {0}, -2.7212, -10.703771,
	     -23.12169, -39.205558, -57.172319, -77.797472, -105.782137, {0}, 
	    -17.519878, -27.769678, -42.85108, -56.973207, -77.378667, {0}, 
	    -12.533729, {0}, -19.625224, {0}, -27.425105, {0}, -75.6713075, {
	    0}, -28.560249, {0}, -74.6114692, {0}, -13.10253, {0}, -28.84756, 
	    {0}, -28.089187, -57.832013, {0}, -44.124928, {0}, 1.331967, {0}, 
	    .70238, 1.00421, 1.506801, 1.787537, 2.255614, 2.699905, 2.848487,
	     {0}, 1.444161, 1.315986, 2.10872, 2.312962, 3.784645, {0}, 1.5, {
	    0}, 2.047359, {0}, 1.29318, {0}, 3.8543019, {0}, 2.08038, {0}, 
	    2.272961, {0}, 2.218184, {0}, 2.498286, {0}, 1.435306, 2.613591, {
	    0}, 4., {0}, .70238, 1.00421, 1.506801, 1.787537, 2.255614, 
	    2.699905, 2.848487, {0}, 1.444161, 1.709943, 1.78581, 2.009146, 
	    2.036263, {0}, 1.5, {0}, 1.460946, {0}, 2.020564, {0}, 2.1992091, 
	    {0}, 1.937106, {0}, 2.169498, {0}, 2.065038, {0}, 2.082071, {0}, 
	    1.435306, 2.034393, {0}, .3, {0}, 1., 1., 1., 1., 1., {0}, 
	    2.884549, {0}, 1., {0}, 1., {0}, 1., {0}, 1., 1., {0}, .3, {0}, 
	    -6.989064, {0}, -1.35004, -4.017096, -8.252054, -18.985044, 
	    -20.495758, -32.688082, -48.290466, {0}, -2.670284, -9.086804, 
	    -6.7916, -10.76167, -14.26232, {0}, -.1, {0}, -1., {0}, -4.516479,
	     {0}, -8.917107, {0}, -3.235147, {0}, -7.414451, {0}, -.404525, {
	    0}, -8.042387, {0}, -4.256218, -11.142231, {0}, -9999999., {0}, 
	    -1.35004, -4.017096, -8.252054, -7.934122, -20.495758, -32.688082,
	     -36.50854, {0}, -2.670284, -1.075827, -6.7916, -10.108433, 
	    -14.26232, {0}, -.1, {0}, -2., {0}, -1.755517, {0}, -9.94374, {0},
	     -4.290416, {0}, -6.196781, {0}, -6.206683, {0}, -3., {0}, 
	    -4.256218, -11.142231, {0}, -8.776636, {0}, 2.5441341, {0}, 
	    1.25014, 1.669434, 2.134993, 2.54638, 2.861342, 3.160604, 
	    3.4196606, {0}, 1.66, {0}, 1.8688394, 2.205316, 2.41528, 2.478026,
	     2.542201, {0}, 1.396, {0}, 3.068307, {0}, 1.506457, {0}, 
	    1.978498, {0}, 2.4457051, {0}, 1.800814, {0}, 2.20732, {0}, 
	    1.335641, {0}, 1.728333, {0}, 2.1961078, 2.4916445, {0}, 
	    2.5441341, 1.5, 1.5, 1.5, 1.5, {0}, -11.906276, {0}, -5.128, 
	    -24.204756, -64.31595, -120.500606, -202.566201, -317.868506, 
	    -476.683781, {0}, 0., {0}, -44.484072, -82.839422, -152.95996, 
	    -226.01239, -353.117667, {0}, 0., {0}, -134.818792, {0}, 
	    -29.879432, {0}, -76.248944, {0}, -346.68125, {0}, -92.324102, {0}
	    , -340.59836, {0}, -28.819148, {0}, -105.834504, {0}, -90.539958, 
	    -235.441356, {0}, 4., 0., 0., 0., 0., {0}, 2.0549783, 1.4373245, 
	    .9579073, .8074662, .6399037, .5346024, .5067166, {0}, 1.3992387, 
	    1.2580349, 1.0129699, .9189935, .498687, {0}, 1.7320508, {0}, 
	    1.3037826, {0}, 1.2556091, {0}, .6051074, {0}, 1.5697766, {0}, 
	    1.4253233, {0}, 1.7378048, {0}, 1.5526624, {0}, 1.4078712, 
	    .8231596, {0}, .0684105, {0}, 1.7437069, 1.2196103, .8128113, 
	    .6851578, .5429763, .4536252, .4299633, {0}, 1.1586797, .9785824, 
	    .937009, .8328514, .8217603, {0}, 1.4142136, {0}, 1.4520183, {0}, 
	    1.0498655, {0}, .9645873, {0}, 1.3262292, {0}, 1.1841707, {0}, 
	    1.4608064, {0}, 1.4488558, {0}, 1.1658281, .8225156, {0}, 
	    1.0540926, {0}, .4721793, {0}, .2682837, .3307607, .3891951, 
	    .4494671, .4994487, .5667034, .6218302, {0}, .5, {0}, .2973172, 
	    .3608967, .4248438, .4733554, .5523705, {0}, .5, {0}, .2205072, {
	    0}, .4336641, {0}, .3601617, {0}, .5526068, {0}, .3601617, {0}, 
	    .5527541, {0}, .3969129, {0}, .3601617, {0}, .3608967, .4733554, {
	    0}, .4721793, .5, .5, .5, .5, {0}, .4721793, {0}, .2269793, 
	    .3356142, .490473, .6149474, .7843643, .9592562, 1.0850301, {0}, 
	    .2635574, .3664244, .488242, .5544502, .806122, {0}, .2711332, {0}
	    , .2375912, {0}, .3643722, {0}, .725833, {0}, .3219998, {0}, 
	    .4593451, {0}, .3047694, {0}, .3239309, {0}, .3441817, .5889395, {
	    0}, .9262742, {0}, .4721793, {0}, .2614581, .3846373, .5556979, 
	    .6685897, .8126445, .9495934, 1.0343643, {0}, .367356, .450674, 
	    .4979406, .5585244, .6053435, {0}, .4464656, {0}, .2738858, {0}, 
	    .4347337, {0}, .5574589, {0}, .3713827, {0}, .4585376, {0}, 
	    .3483102, {0}, .3502057, {0}, .3999442, .5632724, {0}, .2909059, {
	    0}, 12.848, {0}, 7.3, 9., 10.59, 12.23, 13.59, 15.42, 16.92, {0}, 
	    8.09, 9.82, 11.56, 12.88, 15.03, {0}, 6., {0}, 11.8, {0}, 9.8, {0}
	    , 15.03643948, {0}, 9.8, {0}, 15.04044855, {0}, 10.8, {0}, 9.8, {
	    0}, 9.82, {0}, 12.848, {0}, 5.42, 7.43, 9.56, 11.47, 12.66, 14.48,
	     17.25, {0}, 6.63, 8.36, 10.08, 11.26, 13.16, {0}, 4.15, {0}, 
	    11.182018, {0}, 8.3, {0}, 13.03468242, {0}, 8.3, {0}, 13.05655798,
	     {0}, 9.3, {0}, 8.3, {0}, 8.36, {0}, 5., 6.97, 8.86, 11.08, 12.98,
	     14.52, 16.71, {0}, 5.98, 7.31, 8.64, 9.9, 11.3, {0}, 5., {0}, 
	    13.3, {0}, 7.3, {0}, 11.27632539, {0}, 7.3, {0}, 11.14778369, {0},
	     14.3, {0}, 7.3, {0}, 7.31, {0}, 4.52, 6.22, 7.86, 9.84, 11.59, 
	    12.98, 14.91, {0}, 5.4, 6.54, 7.68, 8.83, 9.97, {0}, 3.5, {0}, 
	    12.93052, {0}, 6.5, {0}, 9.85442552, {0}, 6.5, {0}, 9.91409071, {
	    0}, 13.5, {0}, 6.5, {0}, 6.54, {0}, .83, 1.28, 1.81, 2.43, 3.14, 
	    3.94, 4.83, {0}, .7, 1.32, 1.92, 2.26, 2.42, {0}, 1., {0}, 
	    .484606, {0}, 1.3, {0}, 2.45586832, {0}, 1.3, {0}, 2.45638202, {0}
	    , 1.3, {0}, 1.3, {0}, 1.32, {0}, .1, {0}, .2287, {0}, .2647, 
	    .3584, .2324, .1982, {0}, 1.3236, {0}, 2.2583, {0}, 4.093 };

struct {
    doublereal e_1;
    doublereal fill_2[2];
    doublereal e_3;
    doublereal fill_4[1];
    doublereal e_5[4];
    doublereal fill_6[2];
    doublereal e_7[6];
    doublereal fill_8[12];
    doublereal e_9[6];
    doublereal fill_10[12];
    doublereal e_11[6];
    doublereal fill_12[26];
    doublereal e_13[4];
    doublereal fill_14[18];
    doublereal e_15;
    doublereal fill_16[8];
    doublereal e_17;
    doublereal fill_18[1];
    doublereal e_19[4];
    doublereal fill_20[2];
    doublereal e_21[6];
    doublereal fill_22[12];
    doublereal e_23[6];
    doublereal fill_24[12];
    doublereal e_25[6];
    doublereal fill_26[26];
    doublereal e_27[4];
    doublereal fill_28[131];
    doublereal e_29;
    doublereal fill_30[2];
    doublereal e_31;
    doublereal fill_32[1];
    doublereal e_33[4];
    doublereal fill_34[2];
    doublereal e_35[6];
    doublereal fill_36[12];
    doublereal e_37[6];
    doublereal fill_38[12];
    doublereal e_39[6];
    doublereal fill_40[26];
    doublereal e_41[4];
    doublereal fill_42[18];
    doublereal e_43;
    doublereal fill_44[8];
    doublereal e_45;
    doublereal fill_46[1];
    doublereal e_47[4];
    doublereal fill_48[2];
    doublereal e_49[6];
    doublereal fill_50[12];
    doublereal e_51[6];
    doublereal fill_52[12];
    doublereal e_53[6];
    doublereal fill_54[26];
    doublereal e_55[4];
    doublereal fill_56[18];
    doublereal e_57;
    doublereal fill_58[17];
    doublereal e_59[5];
    doublereal fill_60[12];
    doublereal e_61;
    doublereal fill_62[4];
    doublereal e_63;
    doublereal fill_64[17];
    doublereal e_65;
    doublereal fill_66[48];
    doublereal e_67;
    doublereal fill_68[5];
    doublereal e_69;
    doublereal fill_70[2];
    doublereal e_71;
    doublereal fill_72[1];
    doublereal e_73[4];
    doublereal fill_74[2];
    doublereal e_75[6];
    doublereal fill_76[12];
    doublereal e_77[6];
    doublereal fill_78[12];
    doublereal e_79[6];
    doublereal fill_80[26];
    doublereal e_81[4];
    doublereal fill_82[18];
    doublereal e_83;
    doublereal fill_84[8];
    doublereal e_85;
    doublereal fill_86[1];
    doublereal e_87[4];
    doublereal fill_88[2];
    doublereal e_89[6];
    doublereal fill_90[12];
    doublereal e_91[6];
    doublereal fill_92[12];
    doublereal e_93[6];
    doublereal fill_94[26];
    doublereal e_95[4];
    doublereal fill_96[131];
    doublereal e_97;
    doublereal fill_98[2];
    doublereal e_99;
    doublereal fill_100[1];
    doublereal e_101[4];
    doublereal fill_102[1];
    doublereal e_103[7];
    doublereal fill_104[1];
    doublereal e_105;
    doublereal fill_106[10];
    doublereal e_107[6];
    doublereal fill_108[12];
    doublereal e_109[6];
    doublereal fill_110[26];
    doublereal e_111[4];
    doublereal fill_112[18];
    doublereal e_113[5];
    doublereal fill_114[1];
    doublereal e_115;
    doublereal fill_116[2];
    doublereal e_117;
    doublereal fill_118[1];
    doublereal e_119[4];
    doublereal fill_120[1];
    doublereal e_121[7];
    doublereal fill_122[1];
    doublereal e_123;
    doublereal fill_124[10];
    doublereal e_125[6];
    doublereal fill_126[12];
    doublereal e_127[6];
    doublereal fill_128[26];
    doublereal e_129[4];
    doublereal fill_130[18];
    doublereal e_131[5];
    doublereal fill_132[4];
    doublereal e_133;
    doublereal fill_134[1];
    doublereal e_135[4];
    doublereal fill_136[2];
    doublereal e_137[6];
    doublereal fill_138[12];
    doublereal e_139[6];
    doublereal fill_140[12];
    doublereal e_141[6];
    doublereal fill_142[26];
    doublereal e_143[4];
    doublereal fill_144[18];
    doublereal e_145;
    doublereal fill_146[8];
    doublereal e_147;
    doublereal fill_148[1];
    doublereal e_149[4];
    doublereal fill_150[2];
    doublereal e_151[6];
    doublereal fill_152[12];
    doublereal e_153[6];
    doublereal fill_154[12];
    doublereal e_155[6];
    doublereal fill_156[26];
    doublereal e_157[4];
    doublereal fill_158[18];
    doublereal e_159;
    doublereal fill_160[5];
    doublereal e_161;
    doublereal fill_162[2];
    doublereal e_163;
    doublereal fill_164[1];
    doublereal e_165[4];
    doublereal fill_166[1];
    doublereal e_167[7];
    doublereal fill_168[1];
    doublereal e_169;
    doublereal fill_170[10];
    doublereal e_171[6];
    doublereal fill_172[12];
    doublereal e_173[6];
    doublereal fill_174[26];
    doublereal e_175[4];
    doublereal fill_176[18];
    doublereal e_177[5];
    doublereal fill_178[1];
    doublereal e_179;
    doublereal fill_180[2];
    doublereal e_181;
    doublereal fill_182[1];
    doublereal e_183[4];
    doublereal fill_184[2];
    doublereal e_185[6];
    doublereal fill_186[12];
    doublereal e_187[6];
    doublereal fill_188[12];
    doublereal e_189[6];
    doublereal fill_190[26];
    doublereal e_191[4];
    doublereal fill_192[18];
    doublereal e_193;
    doublereal fill_194[5];
    doublereal e_195;
    doublereal fill_196[2];
    doublereal e_197;
    doublereal fill_198[1];
    doublereal e_199[4];
    doublereal fill_200[2];
    doublereal e_201[6];
    doublereal fill_202[12];
    doublereal e_203[6];
    doublereal fill_204[12];
    doublereal e_205[6];
    doublereal fill_206[26];
    doublereal e_207[4];
    doublereal fill_208[18];
    doublereal e_209;
    doublereal fill_210[5];
    doublereal e_211;
    doublereal fill_212[2];
    doublereal e_213;
    doublereal fill_214[1];
    doublereal e_215[4];
    doublereal fill_216[2];
    doublereal e_217[6];
    doublereal fill_218[12];
    doublereal e_219[6];
    doublereal fill_220[12];
    doublereal e_221[6];
    doublereal fill_222[26];
    doublereal e_223[4];
    doublereal fill_224[18];
    doublereal e_225;
    doublereal fill_226[8];
    doublereal e_227;
    doublereal fill_228[1];
    doublereal e_229[4];
    doublereal fill_230[2];
    doublereal e_231[6];
    doublereal fill_232[12];
    doublereal e_233[6];
    doublereal fill_234[12];
    doublereal e_235[6];
    doublereal fill_236[26];
    doublereal e_237[4];
    doublereal fill_238[27];
    doublereal e_239;
    doublereal fill_240[1];
    doublereal e_241[4];
    doublereal fill_242[2];
    doublereal e_243[6];
    doublereal fill_244[12];
    doublereal e_245[6];
    doublereal fill_246[12];
    doublereal e_247[6];
    doublereal fill_248[26];
    doublereal e_249[4];
    doublereal fill_250[27];
    doublereal e_251;
    doublereal fill_252[1];
    doublereal e_253[4];
    doublereal fill_254[2];
    doublereal e_255[6];
    doublereal fill_256[12];
    doublereal e_257[6];
    doublereal fill_258[12];
    doublereal e_259[6];
    doublereal fill_260[26];
    doublereal e_261[4];
    doublereal fill_262[27];
    doublereal e_263;
    doublereal fill_264[1];
    doublereal e_265[4];
    doublereal fill_266[2];
    doublereal e_267[6];
    doublereal fill_268[12];
    doublereal e_269[6];
    doublereal fill_270[12];
    doublereal e_271[6];
    doublereal fill_272[26];
    doublereal e_273[4];
    doublereal fill_274[18];
    doublereal e_275;
    doublereal fill_276[112];
    } pm3_ = { -13.073321, {0}, -17.264752, {0}, -47.27032, -49.335672, 
	    -86.993002, -110.435303, {0}, -14.623688, -24.845404, -26.763483, 
	    -40.413096, -49.895371, -100.626747, {0}, -18.532198, -29.855593, 
	    -35.4671955, -38.507424, -55.378135, -116.619311, {0}, -15.828584,
	     -26.176205, -34.550192, -56.432196, -44.938036, -96.454037, {0}, 
	    -17.762229, -30.05317, -30.322756, -33.495938, {0}, -11.906276, {
	    0}, -11.304243, {0}, -36.266918, -47.509736, -71.87958, 
	    -105.685047, {0}, -14.17346, -22.264159, -22.813635, -29.593052, 
	    -44.392583, -53.614396, {0}, -11.047409, -21.875371, -31.5863583, 
	    -35.152415, -49.823076, -74.227129, {0}, 8.749795, -20.005822, 
	    -25.894419, -29.434954, -46.314099, -61.091582, {0}, -18.330751, 
	    -26.920637, -24.425834, -35.521026, {0}, .967807, {0}, .877439, {
	    0}, 1.565085, 2.028094, 3.796544, 4.708555, {0}, .698552, 
	    1.702888, 1.635075, 2.017563, 1.891185, 2.24621, {0}, 1.819989, 
	    1.84704, 2.2373526, 2.636177, 2.828051, 5.348457, {0}, 1.679351, 
	    2.016116, 2.373328, 2.343039, 4.165492, 7.001013, {0}, 1.476885, 
	    6.867921, 3.141289, 4.916451, {0}, 4., {0}, 1.508755, {0}, 
	    1.842345, 2.313728, 2.389402, 2.491178, {0}, 1.483453, 1.073629, 
	    1.313088, 1.504732, 1.658972, 2.15101, {0}, 1.506922, .839411, 
	    1.5924319, 1.703889, 1.732536, 2.12759, {0}, 2.066412, 1.44535, 
	    1.638233, 1.899992, 1.647555, 2.454354, {0}, 2.479951, 1.969445, 
	    1.892418, 1.934935, {0}, .3, {0}, 1., 1., 1., 1., 1., {0}, 1., {0}
	    , 1., {0}, 1., {0}, .3, {0}, -5.626512, {0}, -3.962053, {0}, 
	    -11.910015, -14.062521, -45.202651, -48.405939, {0}, -2.071691, 
	    -.594301, -2.862145, -12.615879, -8.827465, -27.52856, {0}, 
	    -.715578, -4.945618, -5.3250024, -8.232165, -6.157822, -31.171342,
	     {0}, -8.581944, -2.993319, -2.785802, -14.794217, -2.665146, 
	    -14.494234, {0}, -3.101365, -1.084495, -6.126024, -5.607283, {0}, 
	    -9999999., {0}, -2.780684, {0}, -9.802755, -20.043848, -24.752515,
	     -27.74466, {0}, -.569581, -.95655, -3.933148, -4.16004, 
	    -8.091415, -11.593922, {0}, -6.351864, -.407053, -2.2501567, 
	    -5.017386, -5.493039, -6.814013, {0}, -.601034, -1.828908, 
	    -2.005999, -2.817948, -3.89543, -5.894703, {0}, -3.464031, 
	    -7.946799, -1.39543, -5.800152, {0}, 3.356386, {0}, 1.593536, {0},
	     2.707807, 2.830545, 3.217102, 3.358921, {0}, 1.681, 1.329147, 
	    1.521703, 2.135809, 1.940534, 2.269706, 2.517296, {0}, 1.4, {0}, 
	    1.350126, 1.605115, 1.972337, 1.794477, 3.043957, 2.511842, {0}, 
	    1.525382, 1.418385, 1.69965, 2.034301, 2.485019, 1.990185, {0}, 
	    1.529377, 1.340951, 1.620045, 1.857431, {0}, 2.5441341, 1.5, 1.5, 
	    1.5, 1.5, {0}, -13.073321, {0}, -25.516653, {0}, -111.229917, 
	    -157.6137755, -289.3422065, -437.517169, {0}, 0., -22.553076, 
	    -46.864763, -67.788214, -117.959174, -183.4537395, -315.194948, {
	    0}, 0., {0}, -27.3872, -57.328025, -84.0156006, -122.632614, 
	    -192.7748115, -352.539897, {0}, -22.450208, -51.975047, 
	    -78.887779, -148.938289, -168.0945925, -288.316086, {0}, 
	    -28.899738, -56.649205, -73.4660775, -109.277491, {0}, 4., 0., 0.,
	     0., 0., {0}, 1.0090531, {0}, .8332396, .6577006, .4086173, 
	    .3125302, {0}, 1.140395, 1.2102799, 1.314455, 1.0644947, 
	    1.1214313, .9175856, {0}, 1.5005758, .9776692, 1.1920304, 
	    .9679655, .8719813, .2759025, {0}, 1.5982681, 1.5766241, 
	    1.3120038, 1.4091903, .3484177, .1581469, {0}, 1.2317811, 
	    .0781362, .986629, .2798609, {0}, .0684105, {0}, .8117586, {0}, 
	    .664775, .5293383, .5125738, .4916328, {0}, 1.1279899, 1.5585645, 
	    1.2743396, 1.1120386, 1.0086488, .777923, {0}, 1.4077174, 
	    2.5271534, 1.3321263, 1.2449874, 1.2244019, .9970532, {0}, 
	    1.2432402, 1.7774563, 1.5681814, 1.3521354, 1.5593085, 1.0467302, 
	    {0}, 1.2164033, 1.531711, 1.5940562, 1.5590294, {0}, 1.0540926, {
	    0}, .5437048, {0}, .331233, {0}, .4116394, .4375151, .579043, 
	    .385765, {0}, .5, .2460235, .212302, .1854905, .2867187, .3294622,
	     .588519, {0}, .5, {0}, .3556485, .310862, .1976098, .3230063, 
	    .2731566, .5859399, {0}, .3383668, .2409004, .3744959, .3395177, 
	    .3768862, .5009902, {0}, .2434664, .3844326, .2576991, .1833693, {
	    0}, .4721793, .5, .5, .5, .5, {0}, .5437048, {0}, .2908996, {0}, 
	    .5885862, .5030995, .529963, .6768503, {0}, .2695751, .6418584, 
	    .3060715, .4309446, .6679118, .6814522, {0}, .2375689, .512936, 
	    .3798182, .5042239, .7509697, .6755383, {0}, .357029, .4532655, 
	    .3218163, .458901, 1.1960743, 1.6699104, {0}, .4515472, 2.5741815,
	     .4527678, .6776013, {0}, .9262742, {0}, .5437048, {0}, .3530008, 
	    {0}, .7647667, .7364933, .817963, .6120047, {0}, .2767522, 
	    .2262838, .4877432, .3732517, .6137472, .3643694, {0}, .2661069, 
	    .1546208, .3620669, .2574219, .5283737, .3823719, {0}, .2820582, 
	    .3689812, .2832529, .2423472, .2184786, .5153082, {0}, .2618394, 
	    .2213264, .2150175, .258652, {0}, .2909059, {0}, 14.794208, {0}, 
	    9.012851, {0}, 11.200708, 11.904787, 15.75576, 10.496667, {0}, 
	    6.6943, 5.776737, 5.047196, 7.801615, 8.964667, 16.013601, {0}, 
	    9.677196, 8.458554, 5.3769635, 8.789001, 7.432591, 15.943425, {0},
	     9.20696, 6.5549, 10.190033, 9.238277, 10.255073, 13.631943, {0}, 
	    6.62472, 10.460412, 7.011992, 4.98948, {0}, 12.848, {0}, 6.576199,
	     {0}, 10.265027, 7.348565, 10.62116, 16.073689, {0}, 6.793995, 
	    11.659856, 5.949057, 5.186949, 6.785936, 8.048115, {0}, 7.736204, 
	    8.925619, 10.2095293, 5.397983, 10.060461, 16.06168, {0}, 
	    8.231539, 8.229873, 7.235327, 5.27768, 8.169145, 14.990406, {0}, 
	    10.639297, 11.223883, 6.793782, 6.103308, {0}, 6.057182, {0}, 
	    10.796292, 11.754672, 13.654016, 14.817256, {0}, 6.910446, 
	    6.34779, 6.759367, 6.618478, 9.968164, 7.522215, {0}, 4.980174, 
	    5.086855, 7.6718647, 8.28725, 9.568326, 8.282763, {0}, 4.948104, 
	    6.299269, 5.67381, 6.35, 7.777592, 7.28833, {0}, 14.709283, 
	    4.992785, 5.18378, 8.696007, {0}, 9.005219, {0}, 9.042566, 
	    10.807277, 12.406095, 14.418393, {0}, 7.090823, 6.121077, 
	    5.161297, 6.062002, 7.970247, 7.504154, {0}, 4.669656, 4.983045, 
	    6.9242663, 8.210346, 7.724289, 7.816849, {0}, 4.669656, 4.984211, 
	    5.182214, 6.25, 7.755121, 5.966407, {0}, 16.00074, 8.962727, 
	    5.045651, 8.335447, {0}, .544679, {0}, 2.29098, 1.136713, .593883,
	     .727763, {0}, .5433, 4.006245, .919832, 1.542809, 4.041836, 
	    3.481153, {0}, .600413, 2.05126, 1.3370204, 1.951034, 4.016558, 
	    .578869, {0}, 1.656234, 2.631461, 1.033157, 2.424464, 3.772462, 
	    2.630035, {0}, 2.036311, 2.530406, 1.566302, .599122, {0}, .1 };

struct {
    doublereal e_1;
    doublereal fill_2[1];
    doublereal e_3[7];
    doublereal fill_4[3];
    doublereal e_5[5];
    doublereal fill_6[12];
    doublereal e_7;
    doublereal fill_8[1];
    doublereal e_9;
    doublereal fill_10[2];
    doublereal e_11;
    doublereal fill_12[17];
    doublereal e_13;
    doublereal fill_14[26];
    doublereal e_15;
    doublereal fill_16[9];
    doublereal e_17[2];
    doublereal fill_18[10];
    doublereal e_19;
    doublereal fill_20[7];
    doublereal e_21[7];
    doublereal fill_22[3];
    doublereal e_23[5];
    doublereal fill_24[12];
    doublereal e_25;
    doublereal fill_26[1];
    doublereal e_27;
    doublereal fill_28[2];
    doublereal e_29;
    doublereal fill_30[17];
    doublereal e_31;
    doublereal fill_32[26];
    doublereal e_33;
    doublereal fill_34[9];
    doublereal e_35[2];
    doublereal fill_36[123];
    doublereal e_37;
    doublereal fill_38[1];
    doublereal e_39[7];
    doublereal fill_40[3];
    doublereal e_41[5];
    doublereal fill_42[12];
    doublereal e_43;
    doublereal fill_44[1];
    doublereal e_45;
    doublereal fill_46[2];
    doublereal e_47;
    doublereal fill_48[17];
    doublereal e_49;
    doublereal fill_50[26];
    doublereal e_51;
    doublereal fill_52[9];
    doublereal e_53[2];
    doublereal fill_54[10];
    doublereal e_55;
    doublereal fill_56[7];
    doublereal e_57[7];
    doublereal fill_58[3];
    doublereal e_59[5];
    doublereal fill_60[12];
    doublereal e_61;
    doublereal fill_62[1];
    doublereal e_63;
    doublereal fill_64[2];
    doublereal e_65;
    doublereal fill_66[17];
    doublereal e_67;
    doublereal fill_68[26];
    doublereal e_69;
    doublereal fill_70[9];
    doublereal e_71[2];
    doublereal fill_72[10];
    doublereal e_73;
    doublereal fill_74[17];
    doublereal e_75[5];
    doublereal fill_76[12];
    doublereal e_77;
    doublereal fill_78[4];
    doublereal e_79;
    doublereal fill_80[17];
    doublereal e_81;
    doublereal fill_82[36];
    doublereal e_83[2];
    doublereal fill_84[10];
    doublereal e_85;
    doublereal fill_86[5];
    doublereal e_87;
    doublereal fill_88[1];
    doublereal e_89[7];
    doublereal fill_90[3];
    doublereal e_91[5];
    doublereal fill_92[12];
    doublereal e_93;
    doublereal fill_94[1];
    doublereal e_95;
    doublereal fill_96[2];
    doublereal e_97;
    doublereal fill_98[17];
    doublereal e_99;
    doublereal fill_100[26];
    doublereal e_101;
    doublereal fill_102[9];
    doublereal e_103[2];
    doublereal fill_104[10];
    doublereal e_105;
    doublereal fill_106[7];
    doublereal e_107[7];
    doublereal fill_108[3];
    doublereal e_109[5];
    doublereal fill_110[12];
    doublereal e_111;
    doublereal fill_112[1];
    doublereal e_113;
    doublereal fill_114[2];
    doublereal e_115;
    doublereal fill_116[17];
    doublereal e_117;
    doublereal fill_118[26];
    doublereal e_119;
    doublereal fill_120[9];
    doublereal e_121[2];
    doublereal fill_122[123];
    doublereal e_123;
    doublereal fill_124[1];
    doublereal e_125[7];
    doublereal fill_126[1];
    doublereal e_127;
    doublereal fill_128[1];
    doublereal e_129[5];
    doublereal fill_130[1];
    doublereal e_131;
    doublereal fill_132[10];
    doublereal e_133;
    doublereal fill_134[1];
    doublereal e_135;
    doublereal fill_136[2];
    doublereal e_137;
    doublereal fill_138[17];
    doublereal e_139;
    doublereal fill_140[26];
    doublereal e_141;
    doublereal fill_142[9];
    doublereal e_143[2];
    doublereal fill_144[10];
    doublereal e_145[5];
    doublereal fill_146[1];
    doublereal e_147;
    doublereal fill_148[1];
    doublereal e_149[7];
    doublereal fill_150[1];
    doublereal e_151;
    doublereal fill_152[1];
    doublereal e_153[5];
    doublereal fill_154[1];
    doublereal e_155;
    doublereal fill_156[10];
    doublereal e_157;
    doublereal fill_158[1];
    doublereal e_159;
    doublereal fill_160[2];
    doublereal e_161;
    doublereal fill_162[17];
    doublereal e_163;
    doublereal fill_164[26];
    doublereal e_165;
    doublereal fill_166[9];
    doublereal e_167[2];
    doublereal fill_168[10];
    doublereal e_169[5];
    doublereal fill_170[3];
    doublereal e_171[7];
    doublereal fill_172[3];
    doublereal e_173[5];
    doublereal fill_174[12];
    doublereal e_175;
    doublereal fill_176[1];
    doublereal e_177;
    doublereal fill_178[2];
    doublereal e_179;
    doublereal fill_180[17];
    doublereal e_181;
    doublereal fill_182[26];
    doublereal e_183;
    doublereal fill_184[9];
    doublereal e_185[2];
    doublereal fill_186[10];
    doublereal e_187;
    doublereal fill_188[7];
    doublereal e_189[7];
    doublereal fill_190[3];
    doublereal e_191[5];
    doublereal fill_192[12];
    doublereal e_193;
    doublereal fill_194[1];
    doublereal e_195;
    doublereal fill_196[2];
    doublereal e_197;
    doublereal fill_198[17];
    doublereal e_199;
    doublereal fill_200[26];
    doublereal e_201;
    doublereal fill_202[9];
    doublereal e_203[2];
    doublereal fill_204[10];
    doublereal e_205;
    doublereal fill_206[5];
    doublereal e_207;
    doublereal fill_208[1];
    doublereal e_209[7];
    doublereal fill_210[1];
    doublereal e_211;
    doublereal fill_212[1];
    doublereal e_213[5];
    doublereal fill_214[1];
    doublereal e_215;
    doublereal fill_216[10];
    doublereal e_217;
    doublereal fill_218[1];
    doublereal e_219;
    doublereal fill_220[2];
    doublereal e_221;
    doublereal fill_222[17];
    doublereal e_223;
    doublereal fill_224[26];
    doublereal e_225;
    doublereal fill_226[9];
    doublereal e_227[2];
    doublereal fill_228[10];
    doublereal e_229[5];
    doublereal fill_230[1];
    doublereal e_231;
    doublereal fill_232[1];
    doublereal e_233[7];
    doublereal fill_234[3];
    doublereal e_235[5];
    doublereal fill_236[12];
    doublereal e_237;
    doublereal fill_238[1];
    doublereal e_239;
    doublereal fill_240[2];
    doublereal e_241;
    doublereal fill_242[17];
    doublereal e_243;
    doublereal fill_244[26];
    doublereal e_245;
    doublereal fill_246[9];
    doublereal e_247[2];
    doublereal fill_248[10];
    doublereal e_249;
    doublereal fill_250[5];
    doublereal e_251;
    doublereal fill_252[1];
    doublereal e_253[7];
    doublereal fill_254[3];
    doublereal e_255[5];
    doublereal fill_256[12];
    doublereal e_257;
    doublereal fill_258[1];
    doublereal e_259;
    doublereal fill_260[2];
    doublereal e_261;
    doublereal fill_262[17];
    doublereal e_263;
    doublereal fill_264[26];
    doublereal e_265;
    doublereal fill_266[9];
    doublereal e_267[2];
    doublereal fill_268[10];
    doublereal e_269;
    doublereal fill_270[5];
    doublereal e_271;
    doublereal fill_272[1];
    doublereal e_273[7];
    doublereal fill_274[3];
    doublereal e_275[5];
    doublereal fill_276[12];
    doublereal e_277;
    doublereal fill_278[1];
    doublereal e_279;
    doublereal fill_280[2];
    doublereal e_281;
    doublereal fill_282[17];
    doublereal e_283;
    doublereal fill_284[26];
    doublereal e_285;
    doublereal fill_286[9];
    doublereal e_287[2];
    doublereal fill_288[10];
    doublereal e_289;
    doublereal fill_290[7];
    doublereal e_291[7];
    doublereal fill_292[3];
    doublereal e_293[5];
    doublereal fill_294[12];
    doublereal e_295;
    doublereal fill_296[1];
    doublereal e_297;
    doublereal fill_298[2];
    doublereal e_299;
    doublereal fill_300[17];
    doublereal e_301;
    doublereal fill_302[26];
    doublereal e_303;
    doublereal fill_304[9];
    doublereal e_305[2];
    doublereal fill_306[18];
    doublereal e_307[7];
    doublereal fill_308[3];
    doublereal e_309[5];
    doublereal fill_310[12];
    doublereal e_311;
    doublereal fill_312[1];
    doublereal e_313;
    doublereal fill_314[2];
    doublereal e_315;
    doublereal fill_316[17];
    doublereal e_317;
    doublereal fill_318[26];
    doublereal e_319;
    doublereal fill_320[9];
    doublereal e_321[2];
    doublereal fill_322[18];
    doublereal e_323[7];
    doublereal fill_324[3];
    doublereal e_325[5];
    doublereal fill_326[12];
    doublereal e_327;
    doublereal fill_328[1];
    doublereal e_329;
    doublereal fill_330[2];
    doublereal e_331;
    doublereal fill_332[17];
    doublereal e_333;
    doublereal fill_334[26];
    doublereal e_335;
    doublereal fill_336[9];
    doublereal e_337[2];
    doublereal fill_338[18];
    doublereal e_339[7];
    doublereal fill_340[3];
    doublereal e_341[5];
    doublereal fill_342[12];
    doublereal e_343;
    doublereal fill_344[1];
    doublereal e_345;
    doublereal fill_346[2];
    doublereal e_347;
    doublereal fill_348[17];
    doublereal e_349;
    doublereal fill_350[26];
    doublereal e_351;
    doublereal fill_352[9];
    doublereal e_353[2];
    doublereal fill_354[10];
    doublereal e_355;
    doublereal fill_356[112];
    } am1blo_ = { -11.396427, {0}, -5.128, -16.602378, -34.49287, -52.028658, 
	    -71.86, -97.83, -136.105579, {0}, -24.353585, -33.953622, 
	    -42.029863, -56.694056, -111.613948, {0}, -21.040008, {0}, 
	    -34.183889, {0}, -104.656063, {0}, -103.589663, {0}, -19.941578, {
	    0}, -40.568292, -75.239152, {0}, -11.906276, {0}, -2.7212, 
	    -10.703771, -22.631525, -39.614239, -57.167581, -78.26238, 
	    -104.889885, {0}, -18.363645, -28.934749, -34.030709, -48.717049, 
	    -76.640107, {0}, -17.655574, {0}, -28.640811, {0}, -74.930052, {0}
	    , -74.429997, {0}, -11.11087, {0}, -28.089187, -57.832013, {0}, 
	    1.188078, {0}, .70238, 1.00421, 1.611709, 1.808665, 2.31541, 
	    3.108032, 3.770082, {0}, 1.516593, 1.830697, 1.98128, 2.366515, 
	    3.631376, {0}, 1.954299, {0}, 1.219631, {0}, 3.064133, {0}, 
	    2.102858, {0}, 2.036413, {0}, 1.435306, 2.613591, {0}, 4., {0}, 
	    .70238, 1.00421, 1.555385, 1.685116, 2.15794, 2.524039, 2.49467, {
	    0}, 1.306347, 1.284953, 1.87515, 1.667263, 2.076799, {0}, 
	    1.372365, {0}, 1.982794, {0}, 2.038333, {0}, 2.161153, {0}, 
	    1.955766, {0}, 1.435306, 2.034393, {0}, .3, {0}, 1., 1., 1., 1., 
	    1., {0}, 1., {0}, 1., {0}, 1., {0}, 1., 1., {0}, .3, {0}, 
	    -6.173787, {0}, -1.35004, -4.017096, -9.599114, -15.715783, 
	    -20.29911, -29.272773, -69.590277, {0}, -3.866822, -3.784852, 
	    -6.353764, -3.920566, -24.59467, {0}, -1.997429, {0}, -4.356607, {
	    0}, -19.39988, {0}, -8.443327, {0}, -.908657, {0}, -4.256218, 
	    -11.142231, {0}, -9999999., {0}, -1.35004, -4.017096, -6.273757, 
	    -7.719283, -18.238666, -29.272773, -27.92236, {0}, -2.317146, 
	    -1.968123, -6.590709, -7.905278, -14.637216, {0}, -4.758119, {0}, 
	    -.991091, {0}, -8.957195, {0}, -6.323405, {0}, -4.909384, {0}, 
	    -4.256218, -11.142231, {0}, 2.882324, {0}, 1.25014, 1.669434, 
	    2.446909, 2.648274, 2.947286, 4.455371, 5.5178, {0}, 1.668, {0}, 
	    1.976586, 2.257816, 2.455322, 2.461648, 2.919368, {0}, 1.405, {0},
	     1.484563, {0}, 2.136405, {0}, 2.576546, {0}, 2.299424, {0}, 
	    1.484734, {0}, 2.1961078, 2.4916445, {0}, 2.5441341, 1.5, 1.5, 
	    1.5, 1.5, {0}, -11.396427, {0}, -5.128, -24.204756, -63.717265, 
	    -120.815794, -202.407743, -316.09952, -482.290583, {0}, 0., {0}, 
	    -46.420815, -79.001742, -124.4368355, -191.732193, -372.198431, {
	    0}, 0., {0}, -30.280016, {0}, -78.708481, {0}, -352.3142087, {0}, 
	    -346.8642857, {0}, -29.083156, {0}, -90.539958, -235.441356, {0}, 
	    4., 0., 0., 0., 0., {0}, 2.0549783, 1.4373245, .9107622, .8236736,
	     .6433247, .4988896, .4145203, {0}, 1.4040443, 1.1631107, 
	    1.0452022, .9004265, .5406286, {0}, 1.3581113, {0}, 1.2472095, {0}
	    , .8458104, {0}, 1.4878778, {0}, 1.8750829, {0}, 1.4078712, 
	    .8231596, {0}, .0684105, {0}, 1.7437069, 1.2196103, .7874223, 
	    .7268015, .5675528, .4852322, .4909446, {0}, 1.2809154, 1.3022422,
	     .892366, 1.0036329, .8057208, {0}, 1.5457406, {0}, 1.0698642, {0}
	    , 1.0407133, {0}, 1.1887388, {0}, 1.5424241, {0}, 1.1658281, 
	    .8225156, {0}, 1.0540926, {0}, .4721793, {0}, .2682837, .3307607, 
	    .3891951, .4494671, .4994487, .5667034, .6218302, {0}, .5, {0}, 
	    .2973172, .3608967, .424844, .4331617, .5523705, {0}, .5, {0}, 
	    .4336641, {0}, .3737084, {0}, .5526071, {0}, .5527544, {0}, 
	    .3969129, {0}, .3608967, .4733554, {0}, .4721793, .5, .5, .5, .5, 
	    {0}, .4721793, {0}, .2269793, .3356142, .5045152, .6082946, 
	    .782084, .9961066, 1.2088792, {0}, .2630229, .3829813, .3275319, 
	    .5907115, .76932, {0}, .2317423, {0}, .3180309, {0}, .6024598, {0}
	    , .4497523, {0}, .2926605, {0}, .3441817, .5889395, {0}, .9262742,
	     {0}, .4721793, {0}, .2614581, .3846373, .5678856, .6423492, 
	    .7883498, .9065223, .9449355, {0}, .3427832, .3712106, .4386854, 
	    .6454943, .6133369, {0}, .2621165, {0}, .3485612, {0}, .5307555, {
	    0}, .4631775, {0}, .3360599, {0}, .3999442, .5632724, {0}, 
	    .2909059, {0}, 12.848, {0}, 7.3, 9., 10.59, 12.23, 13.59, 15.42, 
	    16.92, {0}, 8.09, 9.82, 11.560005, 11.786329, 15.03, {0}, 11.8, {
	    0}, 10.168605, {0}, 15.0364395, {0}, 15.0404486, {0}, 10.8, {0}, 
	    9.82, 12.88, {0}, 12.848, {0}, 5.42, 7.43, 9.56, 11.47, 12.66, 
	    14.48, 17.25, {0}, 6.63, 8.36, 5.237449, 8.663127, 13.16, {0}, 
	    11.182018, {0}, 8.144473, {0}, 13.0346824, {0}, 13.056558, {0}, 
	    9.3, {0}, 8.36, 11.26, {0}, 5., 6.97, 8.86, 11.08, 12.98, 14.52, 
	    16.71, {0}, 5.98, 7.31, 7.877589, 10.039308, 11.3, {0}, 13.3, {0},
	     6.671902, {0}, 11.2763254, {0}, 11.1477837, {0}, 14.3, {0}, 7.31,
	     9.9, {0}, 4.52, 6.22, 7.86, 9.84, 11.59, 12.98, 14.91, {0}, 5.4, 
	    6.54, 7.307648, 7.781688, 9.97, {0}, 12.93052, {0}, 6.269706, {0},
	     9.8544255, {0}, 9.9140907, {0}, 13.5, {0}, 6.54, 8.83, {0}, .83, 
	    1.28, 1.81, 2.43, 3.14, 3.94, 4.83, {0}, .7, 1.32, .779238, 
	    2.532137, 2.42, {0}, .484606, {0}, .937093, {0}, 2.4558683, {0}, 
	    2.456382, {0}, 1.3, {0}, 1.32, 2.26, {0}, .1 };

struct {
    char e_1[80];
    char fill_2[80];
    char e_3[560];
    char fill_4[80];
    char e_5[80];
    char fill_6[80];
    char e_7[400];
    char fill_8[80];
    char e_9[80];
    char fill_10[320];
    char e_11[80];
    char fill_12[400];
    char e_13[80];
    char fill_14[80];
    char e_15[80];
    char fill_16[160];
    char e_17[80];
    char fill_18[1120];
    char e_19[80];
    char fill_20[160];
    char e_21[80];
    char fill_22[2080];
    char e_23[80];
    char fill_24[80];
    char e_25[80];
    char fill_26[560];
    char e_27[160];
    char fill_28[800];
    char e_29[80];
    char fill_30[400];
    char e_31[80];
    char fill_32[240];
    char e_33[400];
    char fill_34[320];
    char e_35[320];
    char fill_36[7200];
    char e_37[80];
    char fill_38[80];
    char e_39[560];
    char fill_40[80];
    char e_41[80];
    char fill_42[80];
    char e_43[400];
    char fill_44[80];
    char e_45[80];
    char fill_46[800];
    char e_47[80];
    char fill_48[80];
    char e_49[80];
    char fill_50[160];
    char e_51[80];
    char fill_52[1360];
    char e_53[80];
    char fill_54[2080];
    char e_55[80];
    char fill_56[720];
    char e_57[160];
    char fill_58[800];
    char e_59[80];
    char fill_60[400];
    char e_61[80];
    char fill_62[160];
    char e_63[80];
    char fill_64[80];
    char e_65[320];
    char fill_66[80];
    char e_67[560];
    char fill_68[80];
    char e_69[80];
    char fill_70[800];
    char e_71[480];
    char fill_72[960];
    char e_73[480];
    char fill_74[2080];
    char e_75[320];
    char fill_76[1440];
    char e_77[80];
    char fill_78[400];
    } refs_ = { "  H: (MNDO):  M.J.S. DEWAR, W. THIEL, J. AM. CHEM. SOC., 99"
	    ", 4899, (1977)       ", {0}, " Li: (MNDO):  TAKEN FROM MNDOC BY "
	    "W.THIEL,      QCPE NO.438, V. 2, P.63, (1982). Be: (MNDO):  M.J."
	    "S. DEWAR, H.S. RZEPA, J. AM. CHEM. SOC., 100, 777, (1978)       "
	    "B: (MNDO):  M.J.S. DEWAR, M.L. MCKEE, J. AM. CHEM. SOC., 99, 523"
	    "1, (1977)       C: (MNDO):  M.J.S. DEWAR, W. THIEL, J. AM. CHEM."
	    " SOC., 99, 4899, (1977)         N: (MNDO):  M.J.S. DEWAR, W. THI"
	    "EL, J. AM. CHEM. SOC., 99, 4899, (1977)         O: (MNDO):  M.J."
	    "S. DEWAR, W. THIEL, J. AM. CHEM. SOC., 99, 4899, (1977)         "
	    "F: (MNDO):  M.J.S. DEWAR, H.S. RZEPA, J. AM. CHEM. SOC., 100, 77"
	    "7, (1978)     ", {0}, " Na: (MNDO):  SODIUM-LIKE SPARKLE.   USE "
	    "WITH CARE.                             ", {0}, " Al: (MNDO):  L."
	    "P. DAVIS, ET.AL.  J. COMP. CHEM., 2, 433, (1981) SEE MANUAL.    "
	    " Si: (MNDO): M.J.S.DEWAR, ET. AL. ORGANOMETALLICS  5, 375 (1986)"
	    "                  P: (MNDO): M.J.S.DEWAR, M.L.MCKEE, H.S.RZEPA, "
	    "J. AM. CHEM. SOC., 100 3607 1978  S: (MNDO): M.J.S.DEWAR, C.H. R"
	    "EYNOLDS, J. COM P. CHEM. 7, 140-143 (1986)       Cl: (MNDO): M.J"
	    ".S.DEWAR, H.S.RZEPA, J. COMP. CHEM., 4, 158, (1983)             ",
	     {0}, " K:  (MNDO): POTASSIUM-LIKE SPARKLE.   USE WITH CARE.    "
	    "                       ", {0}, " Cr: (MNDO):  M.J.S. DEWAR, E.F."
	    " HEALY, J.J.P.  STEWART (IN PREPARATION)        ", {0}, " Zn: (M"
	    "NDO):  M.J.S. DEWAR, K.M. MERZ, ORGANOMETALLICS, 5, 1494-1496 (1"
	    "986)     ", {0}, " Ge: (MNDO): M.J.S.DEWAR, G.L.GRADY, E.F.HEALY"
	    ",ORGANOMETALLICS 6 186-189, (1987)", {0}, " Br: (MNDO): M.J.S.DE"
	    "WAR, E.F. HEALY, J. COMP. CHEM., 4, 542, (1983)            ", {0},
	     " Sn: (MNDO): M.J.S.DEWAR,G.L.GRADY,J.J.P.STEWART, J.AM.CHEM.SO"
	    "C.,106 6771 (1984)", {0}, "  I: (MNDO): M.J.S.DEWAR, E.F. HEALY,"
	    " J.J.P. STEWART, J.COMP.CHEM., 5,358,(1984)", {0}, " Hg: (MNDO):"
	    " M.J.S.DEWAR,  ET. AL. ORGANOMETALLICS 4, 1964, (1985) SEE MANUA"
	    "L   ", {0}, " Pb: (MNDO): M.J.S.DEWAR, ET.AL ORGANOMETALLICS 4 1"
	    "973-1980 (1985)              ", {0}, " Si: (MNDO): M.J.S.DEWAR, "
	    "M.L.MCKEE, H.S.RZEPA, J. AM. CHEM. SOC., 100 3607 1978  S: (MNDO"
	    "): M.J.S.DEWAR, H.S. RZEPA, M.L.MCKEE, J.AM.CHEM.SOC.100, 3607 ("
	    "1978).", {0}, " Cb: (MNDO):  Capped Bond  (Hydrogen-like, takes "
	    "on a  zero charge.)            ", {0}, "  H: (MINDO/3): R.C.BING"
	    "HAM ET.AL., J.AM.CHEM.SOC. 97,1285,1294,1302,1307 (1975)", {0}, 
	    "  B: (MINDO/3): R.C.BINGHAM ET.AL., J.AM.CHEM.SOC. 97,1285,1294"
	    ",1302,1307 (1975)  C: (MINDO/3): R.C.BINGHAM ET.AL., J.AM.CHEM.S"
	    "OC. 97,1285,1294,1302,1307 (1975)  N: (MINDO/3): R.C.BINGHAM ET."
	    "AL., J.AM.CHEM.SOC. 97,1285,1294,1302,1307 (1975)  O: (MINDO/3):"
	    " R.C.BINGHAM ET.AL., J.AM.CHEM.SOC. 97,1285,1294,1302,1307 (1975"
	    ")  F: (MINDO/3): R.C.BINGHAM ET.AL., J.AM.CHEM.SOC. 97,1285,1294"
	    ",1302,1307 (1975)", {0}, " Si: (MINDO/3): R.C.BINGHAM ET.AL., J."
	    "AM.CHEM.SOC. 97,1285,1294,1302,1307 (1975)  P: (MINDO/3): R.C.BI"
	    "NGHAM ET.AL., J.AM.CHEM.SOC. 97,1285,1294,1302,1307 (1975)  S: ("
	    "MINDO/3): R.C.BINGHAM ET.AL., J.AM.CHEM.SOC. 97,1285,1294,1302,1"
	    "307 (1975) Cl: (MINDO/3): R.C.BINGHAM ET.AL., J.AM.CHEM.SOC. 97,"
	    "1285,1294,1302,1307 (1975)", {0}, "  H: (AM1): M.J.S. DEWAR ET A"
	    "L, J. AM. CHEM. SOC. 107 3902-3909 (1985)          ", {0}, " Li:"
	    " (MNDO):  TAKEN FROM MNDOC BY W.THIEL,      QCPE NO.438, V. 2, P"
	    ".63, (1982). Be: (MNDO):  M.J.S. DEWAR, H.S. RZEPA, J. AM. CHEM."
	    " SOC., 100, 777, (1978)       B: (AM1):  M.J.S. DEWAR, C. JIE, E"
	    ". G. ZOEBISCH ORGANOMETALLICS 7, 513 (1988)   C: (AM1): M.J.S. D"
	    "EWAR ET AL, J. AM. CHEM. SOC. 107 3902-3909 (1985)            N:"
	    " (AM1): M.J.S. DEWAR ET AL, J. AM. CHEM. SOC. 107 3902-3909 (198"
	    "5)            O: (AM1): M.J.S. DEWAR ET AL, J. AM. CHEM. SOC. 10"
	    "7 3902-3909 (1985)            F: (AM1): M.J.S. DEWAR AND E. G. Z"
	    "OEBISCH, THEOCHEM, 180, 1 (1988).           ", {0}, " Na: (AM1):"
	    "   SODIUM-LIKE SPARKLE.   USE WITH CARE.                        "
	    "     ", {0}, " Al: (AM1):  M. J. S. Dewar, A. J. Holder, Organom"
	    "etallics, 9, 508-511 (1990).   Si: (AM1): M.J.S.DEWAR, C. JIE, O"
	    "RGANOMETALLICS, 6, 1486-1490 (1987).            P: (AM1): M.J.S."
	    "DEWAR, JIE, C, THEOCHEM, 187, 1 (1989)                          "
	    "S: (AM1): M.J.S.DEWAR, Y-C YUAN, THEOCHEM, IN  PRESS            "
	    "               Cl: (AM1): M.J.S. DEWAR AND E. G. ZOEBISCH, THEOC"
	    "HEM, 180, 1 (1988).           ", {0}, " K:  (AM1):  POTASSIUM-LI"
	    "KE SPARKLE.   USE WITH CARE.                           ", {0}, 
	    " Zn: (AM1):  M.J.S. DEWAR, K.M. MERZ, ORGANOMET ALLICS, 7, 522-"
	    "524 (1988)       ", {0}, " Ge: (AM1): M.J.S.Dewar and C.Jie, Org"
	    "anometallics, 8, 1544, (1989)             ", {0}, " Br: (AM1): M"
	    ".J.S. DEWAR AND E. G. ZOEBISCH, THEOCHEM, 180, 1 (1988).        "
	    "   ", {0}, "  I: (AM1): M.J.S. DEWAR AND E. G. ZOEBISCH, THEOCHE"
	    "M, 180, 1 (1988).           ", {0}, " Hg: (AM1): M.J.S.Dewar and"
	    " C.Jie, Organometallics 8, 1547, (1989)              ", {0}, 
	    " Si: (MNDO): M.J.S.DEWAR, M.L.MCKEE, H.S.RZEPA, J. AM. CHEM. SO"
	    "C., 100 3607 1978  S: (MNDO): M.J.S.DEWAR, H.S. RZEPA, M.L.MCKEE"
	    ", J.AM.CHEM.SOC.100, 3607 (1978).", {0}, " Cb: (AM1):  Capped Bo"
	    "nd  (Hydrogen-like, takes  on zero charge.)               ", {0}, 
	    "  H: (PM3): J. J. P. STEWART, J. COMP. CHEM.     10, 209 (1989)"
	    ".                ", {0}, " Be: (PM3): J. J. P. STEWART, J. COMP."
	    " CHEM.    (ACCEPTED)                      ", {0}, "  C: (PM3): J"
	    ". J. P. STEWART, J. COMP. CHEM.     10, 209 (1989).             "
	    "     N: (PM3): J. J. P. STEWART, J. COMP. CHEM.     10, 209 (198"
	    "9).                  O: (PM3): J. J. P. STEWART, J. COMP. CHEM. "
	    "    10, 209 (1989).                  F: (PM3): J. J. P. STEWART,"
	    " J. COMP. CHEM.     10, 209 (1989).                ", {0}, " Na:"
	    " (PM3):   SODIUM-LIKE SPARKLE.   USE WITH CARE.                 "
	    "             Mg: (PM3): J. J. P. STEWART, J. COMP. CHEM.    (ACC"
	    "EPTED)                       Al: (PM3): J. J. P. STEWART, J. COM"
	    "P. CHEM.     10, 209 (1989).                 Si: (PM3): J. J. P."
	    " STEWART, J. COMP. CHEM.     10, 209 (1989).                  P:"
	    " (PM3): J. J. P. STEWART, J. COMP. CHEM.     10, 209 (1989).    "
	    "              S: (PM3): J. J. P. STEWART, J. COMP. CHEM.     10,"
	    " 209 (1989).                 Cl: (PM3): J. J. P. STEWART, J. COM"
	    "P. CHEM.     10, 209 (1989).                ", {0}, " K:  (PM3):"
	    "  POTASSIUM-LIKE SPARKLE.   USE WITH CARE.                      "
	    "     ", {0}, " Zn: (PM3): J. J. P. STEWART, J. COMP. CHEM.    (A"
	    "CCEPTED)                       Ga: (PM3): J. J. P. STEWART, J. C"
	    "OMP. CHEM.    (ACCEPTED)                       Ge: (PM3): J. J. "
	    "P. STEWART, J. COMP. CHEM.    (ACCEPTED)                       A"
	    "s: (PM3): J. J. P. STEWART, J. COMP. CHEM.    (ACCEPTED)        "
	    "               Se: (PM3): J. J. P. STEWART, J. COMP. CHEM.    (A"
	    "CCEPTED)                       Br: (PM3): J. J. P. STEWART, J. C"
	    "OMP. CHEM.     10, 209 (1989).                ", {0}, " Cd: (PM3"
	    "): J. J. P. STEWART, J. COMP. CHEM.    (ACCEPTED)               "
	    "        In: (PM3): J. J. P. STEWART, J. COMP. CHEM.    (ACCEPTED"
	    ")                       Sn: (PM3): J. J. P. STEWART, J. COMP. CH"
	    "EM.    (ACCEPTED)                       Sb: (PM3): J. J. P. STEW"
	    "ART, J. COMP. CHEM.    (ACCEPTED)                       Te: (PM3"
	    "): J. J. P. STEWART, J. COMP. CHEM.    (ACCEPTED)               "
	    "         I: (PM3): J. J. P. STEWART, J. COMP. CHEM.     10, 209 "
	    "(1989).                ", {0}, " Hg: (PM3): J. J. P. STEWART, J."
	    " COMP. CHEM.    (ACCEPTED)                       Tl: (PM3): J. J"
	    ". P. STEWART, J. COMP. CHEM.    (ACCEPTED)                      "
	    " Pb: (PM3): J. J. P. STEWART, J. COMP. CHEM.    (ACCEPTED)      "
	    "                 Bi: (PM3): J. J. P. STEWART, J. COMP. CHEM.    "
	    "(ACCEPTED)                      ", {0}, " Cb: (PM3):  Capped Bon"
	    "d  (Hydrogen-like, takes on a  zero charge.)             " };

struct {
    doublereal e_1[36];
    } onele3_ = { -12.505, 0., 0., 0., -33.61, -51.79, -66.06, -91.73, 
	    -129.86, 0., 0., 0., 0., -39.82, -56.23, -73.39, -98.99, 0., 0., 
	    0., 0., 0., -25.11, -39.18, -56.4, -78.8, -105.93, 0., 0., 0., 0.,
	     -29.15, -42.31, -57.25, -76.43, 0. };

struct {
    doublereal e_1[107];
    } twoel3_ = { 12.848, 10., 10., 0., 8.958, 10.833, 12.377, 13.985, 16.25, 
	    10., 10., 0., 0., 7.57, 9., 10.2, 11.73, 10., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 0., 10., 10., 
	    10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 
	    10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 
	    10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 
	    10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10., 10. };

struct {
    doublereal e_1[107];
    } core_ = { 1., 0., 1., 2., 3., 4., 5., 6., 7., 0., 1., 2., 3., 4., 5., 
	    6., 7., 0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 2., 3., 
	    4., 5., 6., 7., 0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 10., 11., 
	    2., 3., 4., 5., 6., 7., 0., 1., 2., 3., 4., 5., 6., 7., 8., 9., 
	    10., 11., 12., 13., 14., 15., 16., 3., 4., 5., 6., 7., 8., 9., 
	    10., 11., 2., 3., 4., 5., 6., 7., 0., 0., 0., 0., 0., 0., 0., 0., 
	    0., 0., 0., 0., 0., 0., 0., 0., 1., 2., 1., -2., -1., 0. };

struct {
    doublereal e_1[36];
    } atomi3_ = { -12.505, 0., 0., 0., -61.7, -119.47, -187.51, -307.07, 
	    -475., 0., 0., 0., 0., -90.98, -150.81, -229.15, -345.93, 0., 
	    52.102, 0., 0., 0., 135.7, 170.89, 113., 59.559, 18.86, 0., 0., 
	    0., 0., 106., 79.8, 65.65, 28.95, 0. };

struct {
    doublereal e_1;
    doublereal fill_2[9];
    doublereal e_3;
    doublereal fill_4[3];
    doublereal e_5[2];
    doublereal fill_6[3];
    doublereal e_7[3];
    doublereal fill_8[3];
    doublereal e_9[4];
    doublereal fill_10[3];
    doublereal e_11[5];
    doublereal fill_12[3];
    doublereal e_13[5];
    doublereal fill_14[46];
    doublereal e_15;
    doublereal fill_16[4];
    doublereal e_17;
    doublereal fill_18[7];
    doublereal e_19[2];
    doublereal fill_20[4];
    doublereal e_21;
    doublereal fill_22[1];
    doublereal e_23[2];
    doublereal fill_24[5];
    doublereal e_25[2];
    doublereal fill_26[4];
    doublereal e_27[3];
    doublereal fill_28[7];
    doublereal e_29[2];
    doublereal fill_30[4];
    doublereal e_31[2];
    doublereal fill_32[7];
    doublereal e_33[3];
    } beta3_ = { .24477, {0}, .185347, {0}, .151324, .315011, {0}, .250031, 
	    .419907, .360776, {0}, .310959, .410886, .377342, .417759, {0}, 
	    .349745, .464514, .45811, .659407, .195242, {0}, .219591, .247494,
	     .205347, .334044, .197464, {0}, .289647, {0}, .411377, {0}, 
	    .291703, .320118, {0}, .457816, {0}, .47, .3, {0}, .31179, 
	    .220654, {0}, .28462, .31317, .42289, {0}, .202489, .231653, {0}, 
	    .31548, .302298, {0}, .277322, .221764, .258969 };

struct {
    doublereal e_1;
    doublereal fill_2[9];
    doublereal e_3;
    doublereal fill_4[3];
    doublereal e_5[2];
    doublereal fill_6[3];
    doublereal e_7[3];
    doublereal fill_8[3];
    doublereal e_9[4];
    doublereal fill_10[3];
    doublereal e_11[5];
    doublereal fill_12[3];
    doublereal e_13[5];
    doublereal fill_14[46];
    doublereal e_15;
    doublereal fill_16[4];
    doublereal e_17;
    doublereal fill_18[7];
    doublereal e_19[2];
    doublereal fill_20[4];
    doublereal e_21;
    doublereal fill_22[1];
    doublereal e_23[2];
    doublereal fill_24[5];
    doublereal e_25[2];
    doublereal fill_26[4];
    doublereal e_27[3];
    doublereal fill_28[7];
    doublereal e_29[2];
    doublereal fill_30[4];
    doublereal e_31[2];
    doublereal fill_32[7];
    doublereal e_33[3];
    } alpha3_ = { 1.48945, {0}, 2.090352, {0}, 2.280544, 1.475836, {0}, 
	    2.138291, 1.371208, .58938, {0}, 1.909763, 1.635259, 2.029618, 
	    .478901, {0}, 2.484827, 1.820975, 1.873859, 1.53719, 3.771362, {0}
	    , 2.862183, 2.725913, 2.861667, 2.266949, 3.864997, {0}, .940789, 
	    {0}, 1.101382, {0}, .918432, .92317, {0}, 1.029693, {0}, 1.6625, 
	    1.75, {0}, 1.186652, 1.700698, {0}, 1.76137, 1.878176, 2.07724, {
	    0}, 1.751617, 2.089404, {0}, 1.676222, 1.817064, {0}, 1.54372, 
	    1.950318, 1.792125 };

struct {
    doublereal e_1;
    doublereal fill_2[3];
    doublereal e_3[5];
    doublereal fill_4[4];
    doublereal e_5[4];
    doublereal fill_6[1];
    doublereal e_7;
    doublereal fill_8[3];
    doublereal e_9[5];
    doublereal fill_10[4];
    doublereal e_11[4];
    doublereal fill_12[1];
    } expon3_ = { 1.3, {0}, 1.211156, 1.739391, 2.704546, 3.640575, 3.11127, {
	    0}, 1.629173, 1.926108, 1.71948, 3.430887, {0}, 0., {0}, .972826, 
	    1.709645, 1.870839, 2.168448, 1.41986, {0}, 1.381721, 1.590665, 
	    1.403205, 1.627017 };

struct {
    doublereal e_1[3];
    } field_ = { 0., 0., 0. };

struct {
    doublereal fill_1[558];
    doublereal e_2;
    doublereal fill_3[106];
    doublereal e_4;
    doublereal fill_5[106];
    doublereal e_6;
    doublereal fill_7[83];
    } twoele_ = { {0}, 2.874641, {0}, 3., {0}, 8.894967 };

struct {
    doublereal fill_1[107];
    doublereal e_2[42];
    doublereal fill_3[1];
    doublereal e_4[13];
    doublereal fill_5[1];
    doublereal e_6;
    doublereal fill_7[3];
    doublereal e_8;
    doublereal fill_9[5];
    doublereal e_10;
    doublereal fill_11[1];
    doublereal e_12;
    doublereal fill_13[1];
    doublereal e_14[12];
    doublereal fill_15[2];
    doublereal e_16;
    doublereal fill_17[15];
    doublereal e_18[5];
    doublereal fill_19[1];
    } atomic_ = { {0}, 52.102, 0., 38.41, 76.96, 135.7, 170.89, 113., 59.559, 
	    18.89, 0., 25.85, 35., 79.49, 108.39, 75.57, 66.4, 28.99, 0., 
	    21.42, 42.6, 90.3, 112.3, 122.9, 95., 67.7, 99.3, 102.4, 102.8, 
	    80.7, 31.17, 65.4, 89.5, 72.3, 54.3, 26.74, 0., 19.6, 39.1, 101.5,
	     145.5, 172.4, 157.3, {0}, 155.5, 133., 90., 68.1, 26.72, 58., 
	    72.2, 63.2, 47., 25.517, 0., 18.7, 42.5, {0}, 101.3, {0}, 49.4, {
	    0}, 75.8, {0}, 36.35, {0}, 148., 186.9, 203.1, 185., 188., 160., 
	    135.2, 88., 14.69, 43.55, 46.62, 50.1, {0}, 0., {0}, 207., 0., 0.,
	     0., 0. };

struct {
    doublereal e_1;
    doublereal fill_2[3];
    doublereal e_3[5];
    doublereal fill_4[1];
    doublereal e_5;
    doublereal fill_6[2];
    doublereal e_7[4];
    doublereal fill_8[1];
    doublereal e_9;
    doublereal fill_10[83];
    doublereal e_11[4];
    doublereal fill_12[1];
    doublereal e_13;
    doublereal fill_14[3];
    doublereal e_15[5];
    doublereal fill_16[4];
    doublereal e_17[4];
    doublereal fill_18[197];
    } vsips_ = { -13.605, {0}, -15.16, -21.34, -27.51, -35.3, -43.7, {0}, 10.,
	     {0}, -17.82, -21.1, -23.84, -25.26, {0}, 10., {0}, 10., 10., 10.,
	     10., {0}, 0., {0}, -8.52, -11.54, -14.34, -17.91, -20.89, {0}, 
	    -8.51, -10.29, -12.41, -15.09 };


/* ********************************************************************** */

/*     COMMON BLOCKS FOR AM1 */

/* ********************************************************************** */
/* ********************************************************************** */

/*     COMMON BLOCKS FOR MNDO */

/* ********************************************************************** */
/* ********************************************************************** */

/*     COMMON BLOCKS FOR PM3 */

/* ********************************************************************** */
/* ********************************************************************** */

/*     COMMON BLOCKS FOR AM1 */

/* ********************************************************************** */
/* ********************************************************************** */

/*  COMMON BLOCKS FOR MINDO/3 */

/* ********************************************************************** */

/*  END OF MINDO/3 COMMON BLOCKS */


/* ELECTRIC FIELD OPTIONS FOR POLARIZABILITY */


/*   NATORB IS THE NUMBER OF ATOMIC ORBITALS PER ATOM. */

/* ********************************************************************** */
/*                      VALENCE SHELLS ARE DEFINED AS                  * */
/*  PQN   VALENCE SHELLS                                               * */
/*                 P-GROUP              F-GROUP    TRANSITION METALS   * */
/*   1       1S                                                        * */
/*   2       2S 2P                                                     * */
/*   3       3S 3P  OR  3S 3P 3D                                       * */
/*   4       4S 4P                                    4S 4P 3D         * */
/*   5       5S 5P                                    5S 5P 4D         * */
/*   6       6S 6P                       6S 4F        6S 6P 5D         * */
/*   7  NOT ASSIGNED YET  ****DO  NOT  USE****                         * */
/* ********************************************************************** */

/*                STANDARD ATOMIC MASSES */


/*   CORE IS THE CHARGE ON THE ATOM AS SEEN BY THE ELECTRONS */


/*     ENTHALPIES OF FORMATION OF GASEOUS ATOMS ARE TAKEN FROM \ANNUAL */
/*     REPORTS,1974,71B,P 117\  THERE ARE SOME SIGNIFICANT DIFFERENCES */
/*     BETWEEN THE VALUES REPORTED THERE AND THE VALUES PREVIOUSLY IN */
/*     THE BLOCK DATA OF THIS PROGRAM.  ONLY THE THIRD  ROW ELEMENTS */
/*     HAVE BEEN UPDATED. */

/* ALL THE OTHER ELEMENTS ARE TAKEN FROM CRC HANDBOOK 1981-1982 */






/*      DATA NPQ/1,1, 2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3, 4,4,4,4,4,4,4,4, */
/*     +4,4,4,4,4,4,4,4,4,4, 5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5/ */

/* *** ONE CENTER REPULSION INTEGRALS */
/*     GSS ::= (SS,SS) */
/*     GPP ::= (PP,PP) */
/*     GSP ::= (SS,PP) */
/*     GP2 ::= (PP,P*P*) */
/*     HSP ::= (SP,SP) */
/* *********************************************************************** */

/*     THE MONOCENTRIC INTEGRALS HSP AND GSP FOR ALUMINIUM ARE ONLY */
/*     ESTIMATES. A VALUE OF G1 FOR AL IS NEEDED TO RESOLVE OLEARIS */
/*     INTEGRALS. */

/*     OPTIMIZED MNDO PARAMETERS FOR H, BE, B, C, N, O, F */
/*                                                     CL */
/*     ESTIMATED MNDO PARAMETERS FOR       AL,SI, P, S */

/*     ELEMENTS H, C, N, O WERE PARAMETERIZED BY WALTER THIEL */
/*     ELEMENTS B,SI,P,S   WERE      ..          MICHAEL MCKEE */
/*     ELEMENTS BE,F,AL,CL WERE      ..          HENRY RZEPA */

/* ********************************************************************** */

/*    START OF MINDO/3 PARAMETERS */

/* ********************************************************************** */
/* *** F03 IS THE ONE CENTER AVERAGED REPULSION INTEGRAL FOR USE IN THE */
/*        TWO CENTER ELECTRONIC REPULSION INTEGRAL EVALUATION. */
/* *** USS AND UPP ARE THE ONE-CENTER CORE ELECTRON ATTRACTION AND KINETI */
/*     ENERGY INTEGRALS FOR S AND P ELECTRONS RESPECTIVELY IN E.V. */
/* *** EISOL3 AND EHEAT3 ARE THE GS ELECTRONIC ENERGY OF THE NEUTRAL ATOM */
/*     (IN E.V.) AND THE HEAT OF FORMATION IF THE FREE ATOM (IN KCAL/MOL) */
/* *** BETA3 AND ALP3 ARE THE BOND PARAMETERS USED IN THE */
/*     RESONANCE INTEGRAL AND THE CORE CORE REPULSION INTEGRAL RESPECTIVE */
/*     THAT IS ACCORDING TO THE FOLLOWING CONVENTION */

/*     HERE IS THE */
/*     BOND TYPE DESIGNATION */


/*         H   B   C   N   O   F  SI   P   S  CL */
/*       ----------------------------------------- */
/*      H  1  11  16  22  29  37  92 106 121 137 */
/*      B     15  20  26  33  41 */
/*      C         21  27  34  42  97 111 126 142 */
/*      N             28  35  43         127 143 */
/*      O                 36  44     113 128 */
/*      F                     45     114 */
/*     SI                        105 */
/*      P                            120     151 */
/*      S                                136 152 */
/*     CL                                    153 */
/* *** HERE COMES THE OPTIMIZED SLATER_S EXPONENTS FOR THE EVALUATION */
/*     OF THE OVERLAP INTEGRALS AND MOLECULAR DIPOLE MOMENTS. */
/* ************************************************************ */
/*                                                           * */
/*               DATA FOR THE SPARKLES                       * */
/*                                                           * */
/* ************************************************************ */
/*                               DATA FOR THE " ++ " SPARKLE */

/*  START OF MNDO */


/*  START OF AM1 */


/*  START OF PM3 */

/*                               DATA FOR THE " + " SPARKLE */
/*                               DATA FOR THE " -- " SPARKLE */
/*                               DATA FOR THE " - " SPARKLE */
/* ********************************************************************** */

/*    START OF MNDO PARAMETERS */

/* ********************************************************************** */
/*                    DATA FOR ELEMENT  1        HYDROGEN */
/*                    DATA FOR ELEMENT  3        LITHIUM */
/*                    DATA FOR ELEMENT  4        BERYLLIUM */
/*                    DATA FOR ELEMENT  5        BORON */
/*                    DATA FOR ELEMENT  6        CARBON */
/*                    DATA FOR ELEMENT  7        NITROGEN */
/*                    DATA FOR ELEMENT  8        OXYGEN */
/*                    DATA FOR ELEMENT  9        FLUORINE */
/*                               DATA FOR THE SODIUM-LIKE SPARKLE */


/*                    DATA FOR ELEMENT 13        ALUMINUM */
/*                    DATA FOR ELEMENT 14          SILICON */
/*                    DATA FOR ELEMENT 15        PHOSPHORUS */
/*                    DATA FOR ELEMENT 16        SULFUR */

/*                    DATA FOR ELEMENT 17        CHLORINE */
/*                               DATA FOR THE POTASSIUM-LIKE SPARKLE */


/*                    DATA FOR ELEMENT 24  CHROMIUM */
/*                    DATA FOR ELEMENT 30        ZINC */
/*                    DATA FOR ELEMENT 30 */
/*                    DATA FOR ELEMENT 32        GERMANIUM */
/*                    DATA FOR ELEMENT 35        BROMINE */
/*                    DATA FOR ELEMENT 50        TIN */
/*                    DATA FOR ELEMENT 53        IODINE */
/*                    DATA FOR ELEMENT 80        MERCURY */
/*                    DATA FOR ELEMENT 82        LEAD */

/*     START OF "OLD" ELEMENTS: THESE ARE OLD PARAMETERS WHICH */
/*     CAN BE USED, IF DESIRED, BY SPECIFYING "<CHEMICAL SYMBOL>YEAR" */
/*     AS IN SI1978 OR  S1983. */

/*                    DATA FOR ELEMENT 90        SILICON */
/* ********************************************************************** */

/*    START OF AM1 PARAMETERS */

/* ********************************************************************** */
/*                    DATA FOR ELEMENT  1       AM1:   HYDROGEN */
/*                    DATA FOR ELEMENT  3       AM1:   LITHIUM    * */
/*                    DATA FOR ELEMENT  4       AM1:   BERYLLIUM  * */
/*                    DATA FOR ELEMENT  5       AM1:   BORON  * */
/*                    DATA FOR ELEMENT  5 */
/*                    DATA FOR ELEMENT  6       AM1:   CARBON */
/*                    DATA FOR ELEMENT  7       AM1:   NITROGEN */
/*                    DATA FOR ELEMENT  8       AM1:   OXYGEN */
/*                    DATA FOR ELEMENT  9       AM1:   FLUORINE  * */
/*                    DATA FOR ELEMENT 13       AM1:   ALUMINUM  * */
/*                    DATA FOR ELEMENT 14       AM1:   SILICON  * */
/*                    DATA FOR ELEMENT 15        PHOSPHORUS */
/*                    DATA FOR ELEMENT 16       AM1:   SULFUR  * */

/*                    DATA FOR ELEMENT 17       AM1:   CHLORINE  * */
/*                    DATA FOR ELEMENT 30        ZINC */
/*                    DATA FOR ELEMENT 32        GERMANIUM */
/*                    DATA FOR ELEMENT 35       AM1:   BROMINE  * */
/*                    DATA FOR ELEMENT 53       AM1:   IODINE  * */
/*                    DATA FOR ELEMENT 80        MERCURY */

/*     START OF "OLD" ELEMENTS: THESE ARE OLD PARAMETERS WHICH */
/*     CAN BE USED, IF DESIRED, BY SPECIFYING "<CHEMICAL SYMBOL>YEAR" */
/*     AS IN SI1978 OR  S1983. */

/*                    DATA FOR ELEMENT 90        SILICON */
/*                    DATA FOR ELEMENT102 */

/*     START OF MNDO-PM3 PARAMETER SET */

/*                    DATA FOR ELEMENT  1        HYDROGEN */
/*                    DATA FOR ELEMENT  4        BERYLLIUM */
/*                    DATA FOR ELEMENT  6        CARBON */
/*                    DATA FOR ELEMENT  7        NITROGEN */
/*                    DATA FOR ELEMENT  8        OXYGEN */
/*                    DATA FOR ELEMENT  9        FLUORINE */
/*                    DATA FOR ELEMENT 12        MAGNESIUM */
/*                    DATA FOR ELEMENT 13        ALUMINUM */
/*                    DATA FOR ELEMENT 14        SILICON */
/*                    DATA FOR ELEMENT 15        PHOSPHORUS */
/*                    DATA FOR ELEMENT 16        SULFUR */
/*                    DATA FOR ELEMENT 17        CHLORINE */
/*                    DATA FOR ELEMENT 30        ZINC */
/*                    DATA FOR ELEMENT 31        GALLIUM */
/*                    DATA FOR ELEMENT 32        GERMANIUM */
/*                    DATA FOR ELEMENT 33        ARSENIC */
/*                    DATA FOR ELEMENT 34        SELENIUM */
/*                    DATA FOR ELEMENT 35        BROMINE */
/*                    DATA FOR ELEMENT 48        CADMIUM */
/*                    DATA FOR ELEMENT 49        INDIUM */
/*                    DATA FOR ELEMENT 50        TIN */
/*                    DATA FOR ELEMENT 51        ANTIMONY */
/*                    DATA FOR ELEMENT 52        TELLURIUM */
/*                    DATA FOR ELEMENT 53        IODINE */
/*                    DATA FOR ELEMENT 80        MERCURY */
/*                    DATA FOR ELEMENT 81        THALLIUM */
/*                    DATA FOR ELEMENT 82        LEAD */
/*                    DATA FOR ELEMENT 83        BISMUTH */
/*                    DATA FOR ELEMENT  103      CAPPED BOND */

