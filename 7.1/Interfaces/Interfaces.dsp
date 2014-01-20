# Microsoft Developer Studio Project File - Name="Interfaces" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Interfaces - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Interfaces.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Interfaces.mak" CFG="Interfaces - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Interfaces - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Interfaces - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
RSC=rc.exe

!IF  "$(CFG)" == "Interfaces - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE F90 /compile_only /nologo /warn:nofileopt
# ADD F90 /compile_only /nologo /warn:nofileopt
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "Interfaces - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE F90 /check:bounds /compile_only /dbglibs /debug:full /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD F90 /check:bounds /compile_only /dbglibs /debug:full /include:"..\Modules\Debug" /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "Interfaces - Win32 Release"
# Name "Interfaces - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;f90;for;f;fpp"
# Begin Source File

SOURCE=..\src_interfaces\aababc_I.f90
DEP_F90_AABAB=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\aabacd_I.f90
DEP_F90_AABAC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\aabbcd_I.f90
DEP_F90_AABBC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\addfck_I.f90
DEP_F90_ADDFC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\addhcr_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\addnuc_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\aijm_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\aintgs_I.f90
DEP_F90_AINTG=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\alphaf_I.f90
DEP_F90_ALPHA=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\analyt_I.f90
DEP_F90_ANALY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\anavib_I.f90
DEP_F90_ANAVI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\asum_I.f90
DEP_F90_ASUM_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\aval_I.f90
DEP_F90_AVAL_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\axis_I.f90
DEP_F90_AXIS_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\babbbc_I.f90
DEP_F90_BABBB=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\babbcd_I.f90
DEP_F90_BABBC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bangle_I.f90
DEP_F90_BANGL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bdenin_I.f90
DEP_F90_BDENI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bdenup_I.f90
DEP_F90_BDENU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\beopor_I.f90
DEP_F90_BEOPO=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\betaf_I.f90
DEP_F90_BETAF=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\betal1_I.f90
DEP_F90_BETAL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\betall_I.f90
DEP_F90_BETALL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\betcom_I.f90
DEP_F90_BETCO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bfn_I.f90
DEP_F90_BFN_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bintgs_I.f90
DEP_F90_BINTG=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bldsym_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bmakuf_I.f90
DEP_F90_BMAKU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\bonds_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\break_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\brlzon_I.f90
DEP_F90_BRLZO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\btoc_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\calpar_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\capcor_I.f90
DEP_F90_CAPCO=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\cartab_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ccprod_I.f90
DEP_F90_CCPRO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ccrep_I.f90
DEP_F90_CCREP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\cdiag_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\charg_I.f90
DEP_F90_CHARG=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\charmo_I.f90
DEP_F90_CHARM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\charst_I.f90
DEP_F90_CHARS=\
	".\Debug\meci_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\charvi_I.f90
DEP_F90_CHARV=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\chi_I.f90
DEP_F90_CHI_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\chrge_I.f90
DEP_F90_CHRGE=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ciint_I.f90
DEP_F90_CIINT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ciosci_I.f90
DEP_F90_CIOSC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\cnvg_I.f90
DEP_F90_CNVG_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\coe_I.f90
DEP_F90_COE_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\collid_I.f90
DEP_F90_COLLI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\collis_I.f90
DEP_F90_COLLIS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\compfg_I.f90
DEP_F90_COMPF=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\compfn_I.f90
DEP_F90_COMPFN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\consts_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\copym_I.f90
DEP_F90_COPYM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\cqden_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\csum_I.f90
DEP_F90_CSUM_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dang_I.f90
DEP_F90_DANG_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\darea1_I.f90
DEP_F90_DAREA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\daread_I.f90
DEP_F90_DAREAD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dasum_I.f90
DEP_F90_DASUM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\datin_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dawrit_I.f90
DEP_F90_DAWRI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dawrt1_I.f90
DEP_F90_DAWRT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\daxpy_I.f90
DEP_F90_DAXPY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dcart_I.f90
DEP_F90_DCART=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dcopy_I.f90
DEP_F90_DCOPY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ddot_I.f90
DEP_F90_DDOT_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ddpo_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\delmol_I.f90
DEP_F90_DELMO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\delri_I.f90
DEP_F90_DELRI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\delta_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\denrot_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\densf_I.f90
DEP_F90_DENSF=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\densit_I.f90
DEP_F90_DENSI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deri0_I.f90
DEP_F90_DERI0=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deri1_I.f90
DEP_F90_DERI1=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deri21_I.f90
DEP_F90_DERI2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deri22_I.f90
DEP_F90_DERI22=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deri23_I.f90
DEP_F90_DERI23=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deri2_I.f90
DEP_F90_DERI2_=\
	".\Debug\meci_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deritr_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\deriv_I.f90
DEP_F90_DERIV=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dernvo_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ders_I.f90
DEP_F90_DERS_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dex2_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dfield_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dfock2_I.f90
DEP_F90_DFOCK=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dfockd_I.f90
DEP_F90_DFOCKD=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dfpsav_I.f90
DEP_F90_DFPSA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgedi_I.f90
DEP_F90_DGEDI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgefa_I.f90
DEP_F90_DGEFA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgemm_I.f90
DEP_F90_DGEMM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgemv_I.f90
DEP_F90_DGEMV=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dger_I.f90
DEP_F90_DGER_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgetf2_I.f90
DEP_F90_DGETF=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgetrf_I.f90
DEP_F90_DGETR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dgetri_I.f90
DEP_F90_DGETRI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dhc_I.f90
DEP_F90_DHC_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dhcore_I.f90
DEP_F90_DHCOR=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\diag_I.f90
DEP_F90_DIAG_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\diagi_I.f90
DEP_F90_DIAGI=\
	".\Debug\meci_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\diat2_I.f90
DEP_F90_DIAT2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\diat_I.f90
DEP_F90_DIAT_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\diegrd_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dielen_I.f90
DEP_F90_DIELE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\digit_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dihed_I.f90
DEP_F90_DIHED=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dijkl1_I.f90
DEP_F90_DIJKL=\
	".\Debug\meci_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dijkl2_I.f90
DEP_F90_DIJKL2=\
	".\Debug\meci_C.mod"\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dijkld_I.f90
DEP_F90_DIJKLD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dimens_I.f90
DEP_F90_DIMEN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dipole_I.f90
DEP_F90_DIPOL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dist2_I.f90
DEP_F90_DIST2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dlaswp_I.f90
DEP_F90_DLASW=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dmecip_I.f90
DEP_F90_DMECI=\
	".\Debug\meci_C.mod"\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dnrm2_I.f90
DEP_F90_DNRM2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dofs_I.f90
DEP_F90_DOFS_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dopen_I.f90
DEP_F90_DOPEN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dot_I.f90
DEP_F90_DOT_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\drc_I.f90
DEP_F90_DRC_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\drcout_I.f90
DEP_F90_DRCOU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\drepp2_I.f90
DEP_F90_DREPP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\drotat_I.f90
DEP_F90_DROTA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dscal_I.f90
DEP_F90_DSCAL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dsum_I.f90
DEP_F90_DSUM_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dswap_I.f90
DEP_F90_DSWAP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtran2_I.f90
DEP_F90_DTRAN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtrans_I.f90
DEP_F90_DTRANS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtrmm_I.f90
DEP_F90_DTRMM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtrmv_I.f90
DEP_F90_DTRMV=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtrsm_I.f90
DEP_F90_DTRSM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtrti2_I.f90
DEP_F90_DTRTI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dtrtri_I.f90
DEP_F90_DTRTR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\dvfill_I.f90
DEP_F90_DVFIL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ef_I.f90
DEP_F90_EF_I_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\efsav_I.f90
DEP_F90_EFSAV=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\efstr_I.f90
DEP_F90_EFSTR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\einvit_I.f90
DEP_F90_EINVI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\eiscor_I.f90
DEP_F90_EISCO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\elau_I.f90
DEP_F90_ELAU_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\elenuc_I.f90
DEP_F90_ELENU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\elesn_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\en_I.f90
DEP_F90_EN_I_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\enpart_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\epsab_I.f90
DEP_F90_EPSAB=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\epseta_I.f90
DEP_F90_EPSET=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\epslon_I.f90
DEP_F90_EPSLO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\eqlrat_I.f90
DEP_F90_EQLRA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\esn_I.f90
DEP_F90_ESN_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\esp1_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\espfit_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\estpi1_I.f90
DEP_F90_ESTPI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\etime_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\etrbk3_I.f90
DEP_F90_ETRBK=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\etred3_I.f90
DEP_F90_ETRED=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\evvrsp_I.f90
DEP_F90_EVVRS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\exchng_I.f90
DEP_F90_EXCHN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fbx_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fcnpp_I.f90
DEP_F90_FCNPP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ffreq1_I.f90
DEP_F90_FFREQ=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ffreq2_I.f90
DEP_F90_FFREQ2=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fhpatn_I.f90
DEP_F90_FHPAT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\flepo_I.f90
DEP_F90_FLEPO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fmat_I.f90
DEP_F90_FMAT_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fock1_I.f90
DEP_F90_FOCK1=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fock2_I.f90
DEP_F90_FOCK2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fockd1_I.f90
DEP_F90_FOCKD=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fockd2_I.f90
DEP_F90_FOCKD2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\force_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fordd_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\formd_I.f90
DEP_F90_FORMD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\formxd_I.f90
DEP_F90_FORMX=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\formxy_I.f90
DEP_F90_FORMXY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\frame_I.f90
DEP_F90_FRAME=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\freda_I.f90
DEP_F90_FREDA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\freqcy_I.f90
DEP_F90_FREQC=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\fsub_I.f90
DEP_F90_FSUB_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\genun_I.f90
DEP_F90_GENUN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\genvec_I.f90
DEP_F90_GENVE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\geout_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\geoutg_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\getgeg_I.f90
DEP_F90_GETGE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\getgeo_I.f90
DEP_F90_GETGEO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\gethes_I.f90
DEP_F90_GETHE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\getsym_I.f90
DEP_F90_GETSY=\
	".\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\gettxt_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\getval_I.f90
DEP_F90_GETVA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\gmetry_I.f90
DEP_F90_GMETR=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\gover_I.f90
DEP_F90_GOVER=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\grid_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\grids_I.f90
DEP_F90_GRIDS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\gstore_I.f90
DEP_F90_GSTOR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\h1elec_I.f90
DEP_F90_H1ELE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\haddon_I.f90
DEP_F90_HADDO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\hcore_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\hcored_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\helect_I.f90
DEP_F90_HELEC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\hmuf_I.f90
DEP_F90_HMUF_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\hplusf_I.f90
DEP_F90_HPLUS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\idamax_I.f90
DEP_F90_IDAMA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ilaenv_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\inid_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\inighd_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\initsn_I.f90
DEP_F90_INITS=\
	".\Debug\cosmo_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\initsv_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\insymc_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\interp_I.f90
DEP_F90_INTER=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\intfc_I.f90
DEP_F90_INTFC=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ird_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\iten_I.f90
DEP_F90_ITEN_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\iter_I.f90
DEP_F90_ITER_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\jab_I.f90
DEP_F90_JAB_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\jcarin_I.f90
DEP_F90_JCARI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\kab_I.f90
DEP_F90_KAB_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\linmin_I.f90
DEP_F90_LINMI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\local_I.f90
DEP_F90_LOCAL=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\locmin_I.f90
DEP_F90_LOCMI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\lsame_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\makeuf_I.f90
DEP_F90_MAKEU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\makopr_I.f90
DEP_F90_MAKOP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\maksym_I.f90
DEP_F90_MAKSY=\
	".\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mamult_I.f90
DEP_F90_MAMUL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mat33_I.f90
DEP_F90_MAT33=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\matou1_I.f90
DEP_F90_MATOU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\matout_I.f90
DEP_F90_MATOUT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\me08a_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\meci_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mecid_I.f90
DEP_F90_MECID=\
	".\Debug\meci_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mecih_I.f90
DEP_F90_MECIH=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mecip_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mepchg_I.f90
DEP_F90_MEPCH=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mepmap_I.f90
DEP_F90_MEPMA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\meprot_I.f90
DEP_F90_MEPRO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\minv_I.f90
DEP_F90_MINV_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mlig_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\molsym_I.f90
DEP_F90_MOLSY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\molval_I.f90
DEP_F90_MOLVA=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mopend_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mpcbds_I.f90
DEP_F90_MPCBD=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mpcpop_I.f90
DEP_F90_MPCPO=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mpcsyb_I.f90
DEP_F90_MPCSY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mtxm_I.f90
DEP_F90_MTXM_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mtxmc_I.f90
DEP_F90_MTXMC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mullik_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mult33_I.f90
DEP_F90_MULT3=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mult_I.f90
DEP_F90_MULT_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mxm_I.f90
DEP_F90_MXM_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\mxmt_I.f90
DEP_F90_MXMT_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\myword_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\naican_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\naicas_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ngamtg_I.f90
DEP_F90_NGAMT=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ngefis_I.f90
DEP_F90_NGEFI=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ngidri_I.f90
DEP_F90_NGIDR=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ngoke_I.f90
DEP_F90_NGOKE=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\nllsn_I.f90
DEP_F90_NLLSN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\nllsq_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\nonbet_I.f90
DEP_F90_NONBE=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\nonope_I.f90
DEP_F90_NONOP=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\nonor_I.f90
DEP_F90_NONOR=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\nuchar_I.f90
DEP_F90_NUCHA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\openda_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\orient_I.f90
DEP_F90_ORIEN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\osinv_I.f90
DEP_F90_OSINV=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\overlp_I.f90
DEP_F90_OVERL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ovlp_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\packp_I.f90
DEP_F90_PACKP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\parsav_I.f90
DEP_F90_PARSA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\partxy_I.f90
DEP_F90_PARTX=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\pathk_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\paths_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\pdgrid_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\perm_I.f90
DEP_F90_PERM_=\
	".\Debug\meci_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\plato_I.f90
DEP_F90_PLATO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\pmep1_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\pmep_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\pmepco_I.f90
DEP_F90_PMEPC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\poij_I.f90
DEP_F90_POIJ_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\polar_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\potcal_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\powsav_I.f90
DEP_F90_POWSA=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\powsq_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\printp_I.f90
DEP_F90_PRINT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\prjfc_I.f90
DEP_F90_PRJFC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\prtdrc_I.f90
DEP_F90_PRTDR=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\prthco_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\prthes_I.f90
DEP_F90_PRTHE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\prtpar_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\prttim_I.f90
DEP_F90_PRTTI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\pulay_I.f90
DEP_F90_PULAY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\quadr_I.f90
DEP_F90_QUADR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\react1_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\reada_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\readmo_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\redatm_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\refer_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\repp_I.f90
DEP_F90_REPP_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\reppd2_I.f90
DEP_F90_REPPD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\reppd_I.f90
DEP_F90_REPPD_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\resolv_I.f90
DEP_F90_RESOL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rijkl_I.f90
DEP_F90_RIJKL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rotat_I.f90
DEP_F90_ROTAT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rotatd_I.f90
DEP_F90_ROTATD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rotate_I.f90
DEP_F90_ROTATE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rotmat_I.f90
DEP_F90_ROTMA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rotmol_I.f90
DEP_F90_ROTMO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rsc_I.f90
DEP_F90_RSC_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\rsp_I.f90
DEP_F90_RSP_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\schmib_I.f90
DEP_F90_SCHMI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\schmit_I.f90
DEP_F90_SCHMIT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\scprm_I.f90
DEP_F90_SCPRM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\search_I.f90
DEP_F90_SEARC=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\second_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\set_I.f90
DEP_F90_SET_I=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\setup3_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\setupg_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\solrot_I.f90
DEP_F90_SOLRO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\sort_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\spcore_I.f90
DEP_F90_SPCOR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\spline_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\ss_I.f90
DEP_F90_SS_I_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\suma2_I.f90
DEP_F90_SUMA2=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\supdot_I.f90
DEP_F90_SUPDO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\superd_I.f90
DEP_F90_SUPER=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\surfa_I.f90
DEP_F90_SURFA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\surfac_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\swap_I.f90
DEP_F90_SWAP_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symdec_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symh_I.f90
DEP_F90_SYMH_=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symoir_I.f90
DEP_F90_SYMOI=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symopr_I.f90
DEP_F90_SYMOP=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symp_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\sympop_I.f90
DEP_F90_SYMPO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symr_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symt_I.f90
DEP_F90_SYMT_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symtry_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\symtrz_I.f90
DEP_F90_SYMTR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\tf_I.f90
DEP_F90_TF_I_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\thermo_I.f90
DEP_F90_THERM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\time_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\timer_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\timout_I.f90
DEP_F90_TIMOU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\transf_I.f90
DEP_F90_TRANS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\trsub_I.f90
DEP_F90_TRSUB=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\trudgu_I.f90
DEP_F90_TRUDG=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\trugdu_I.f90
DEP_F90_TRUGD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\trugud_I.f90
DEP_F90_TRUGU=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\tx_I.f90
DEP_F90_TX_I_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\upcase_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\update_I.f90
DEP_F90_UPDAT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\updhes_I.f90
DEP_F90_UPDHE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\vecprt_I.f90
DEP_F90_VECPR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\volume_I.f90
DEP_F90_VOLUM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\w2mat_I.f90
DEP_F90_W2MAT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\worder_I.f90
DEP_F90_WORDE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\wrdkey_I.f90
DEP_F90_WRDKE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\writmo_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\wrtkey_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\wrttxt_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\wstore_I.f90
DEP_F90_WSTOR=\
	".\Debug\molkst_C.mod"\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\wwstep_I.f90
DEP_F90_WWSTE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\xerbla_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\xxx_I.f90
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\xyzcry_I.f90
DEP_F90_XYZCR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\xyzgeo_I.f90
DEP_F90_XYZGE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\xyzint_I.f90
DEP_F90_XYZIN=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_interfaces\zerom_I.f90
DEP_F90_ZEROM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# End Group
# End Target
# End Project
