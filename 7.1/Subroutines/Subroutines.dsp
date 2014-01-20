# Microsoft Developer Studio Project File - Name="Subroutines" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Subroutines - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Subroutines.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Subroutines.mak" CFG="Subroutines - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Subroutines - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Subroutines - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
RSC=rc.exe

!IF  "$(CFG)" == "Subroutines - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Subroutines - Win32 Debug"

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
# ADD F90 /check:bounds /compile_only /dbglibs /debug:full /include:"..\Modules\Debug" /include:"..\Interfaces\Debug" /nologo /traceback /warn:argument_checking /warn:nofileopt
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

# Name "Subroutines - Win32 Release"
# Name "Subroutines - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;f90;for;f;fpp"
# Begin Source File

SOURCE=..\src_subroutines\aababc.F90
DEP_F90_AABAB=\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\aabacd.F90
DEP_F90_AABAC=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\aabbcd.F90
DEP_F90_AABBC=\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\aintgs.F90
DEP_F90_AINTG=\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\analyt.F90
DEP_F90_ANALY=\
	"..\Interfaces\Debug\delri_I.mod"\
	"..\Interfaces\Debug\ders_I.mod"\
	"..\Interfaces\Debug\rotat_I.mod"\
	"..\Modules\Debug\analyt_C.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\anavib.F90
DEP_F90_ANAVI=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\axis.F90
DEP_F90_AXIS_=\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\babbbc.F90
DEP_F90_BABBB=\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\babbcd.F90
DEP_F90_BABBC=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\bangle.F90
DEP_F90_BANGL=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\bfn.F90
DEP_F90_BFN_F=\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\bintgs.F90
DEP_F90_BINTG=\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\blas.F90
DEP_F90_BLAS_=\
	"..\Interfaces\Debug\lsame_I.mod"\
	"..\Interfaces\Debug\xerbla_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\bldsym.F90
DEP_F90_BLDSY=\
	"..\Interfaces\Debug\mult33_I.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\bonds.F90
DEP_F90_BONDS=\
	"..\Interfaces\Debug\dopen_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\brlzon.F90
DEP_F90_BRLZO=\
	"..\Interfaces\Debug\cdiag_I.mod"\
	"..\Interfaces\Debug\dofs_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\calpar.F90
DEP_F90_CALPA=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\capcor.F90
DEP_F90_CAPCO=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\cartab.F90
DEP_F90_CARTA=\
	"..\Interfaces\Debug\symdec_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\charmo.F90
DEP_F90_CHARM=\
	"..\Interfaces\Debug\dtrans_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\charst.F90
DEP_F90_CHARS=\
	"..\Interfaces\Debug\dtrans_I.mod"\
	"..\Interfaces\Debug\matout_I.mod"\
	"..\Interfaces\Debug\minv_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\charvi.F90
DEP_F90_CHARV=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\chi.F90
DEP_F90_CHI_F=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\chrge.F90
DEP_F90_CHRGE=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\ciosci.F90
DEP_F90_CIOSC=\
	"..\Interfaces\Debug\matout_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\cnvg.F90
DEP_F90_CNVG_=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\coe.F90
DEP_F90_COE_F=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\compfg.F90
DEP_F90_COMPF=\
	"..\Interfaces\Debug\btoc_I.mod"\
	"..\Interfaces\Debug\consts_I.mod"\
	"..\Interfaces\Debug\deriv_I.mod"\
	"..\Interfaces\Debug\dihed_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\hcore_I.mod"\
	"..\Interfaces\Debug\hcored_I.mod"\
	"..\Interfaces\Debug\iter_I.mod"\
	"..\Interfaces\Debug\mecip_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\prthco_I.mod"\
	"..\Interfaces\Debug\prtpar_I.mod"\
	"..\Interfaces\Debug\setupg_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Interfaces\Debug\timer_I.mod"\
	"..\Modules\Debug\analyt_C.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\molmec_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\cosmo.F90
DEP_F90_COSMO=\
	"..\Interfaces\Debug\cqden_I.mod"\
	"..\Interfaces\Debug\dgemm_I.mod"\
	"..\Interfaces\Debug\dgemv_I.mod"\
	"..\Interfaces\Debug\dger_I.mod"\
	"..\Interfaces\Debug\dgetf2_I.mod"\
	"..\Interfaces\Debug\dgetrf_I.mod"\
	"..\Interfaces\Debug\dgetri_I.mod"\
	"..\Interfaces\Debug\dlaswp_I.mod"\
	"..\Interfaces\Debug\dscal_I.mod"\
	"..\Interfaces\Debug\dswap_I.mod"\
	"..\Interfaces\Debug\dtrmm_I.mod"\
	"..\Interfaces\Debug\dtrmv_I.mod"\
	"..\Interfaces\Debug\dtrsm_I.mod"\
	"..\Interfaces\Debug\dtrti2_I.mod"\
	"..\Interfaces\Debug\dtrtri_I.mod"\
	"..\Interfaces\Debug\dvfill_I.mod"\
	"..\Interfaces\Debug\idamax_I.mod"\
	"..\Interfaces\Debug\ilaenv_I.mod"\
	"..\Interfaces\Debug\initsn_I.mod"\
	"..\Interfaces\Debug\lsame_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\wrdkey_I.mod"\
	"..\Interfaces\Debug\xerbla_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dang.F90
DEP_F90_DANG_=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\datin.F90
DEP_F90_DATIN=\
	"..\Interfaces\Debug\calpar_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\upcase_I.mod"\
	"..\Interfaces\Debug\update_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\parameters_for_mndod_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dcart.F90
DEP_F90_DCART=\
	"..\Interfaces\Debug\analyt_I.mod"\
	"..\Interfaces\Debug\dhc_I.mod"\
	"..\Interfaces\Debug\diegrd_I.mod"\
	"..\Interfaces\Debug\dihed_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\molmec_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\denrot.F90
DEP_F90_DENRO=\
	"..\Interfaces\Debug\coe_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\densit.F90
DEP_F90_DENSI=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deri0.F90
DEP_F90_DERI0=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deri1.F90
DEP_F90_DERI1=\
	"..\Interfaces\Debug\dcopy_I.mod"\
	"..\Interfaces\Debug\dfock2_I.mod"\
	"..\Interfaces\Debug\dfockd_I.mod"\
	"..\Interfaces\Debug\dhcore_I.mod"\
	"..\Interfaces\Debug\dijkl1_I.mod"\
	"..\Interfaces\Debug\dijkld_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\helect_I.mod"\
	"..\Interfaces\Debug\mecid_I.mod"\
	"..\Interfaces\Debug\mecih_I.mod"\
	"..\Interfaces\Debug\mtxm_I.mod"\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Interfaces\Debug\supdot_I.mod"\
	"..\Interfaces\Debug\timer_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deri2.F90
DEP_F90_DERI2=\
	"..\Interfaces\Debug\dcopy_I.mod"\
	"..\Interfaces\Debug\deri22_I.mod"\
	"..\Interfaces\Debug\deri23_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\mecid_I.mod"\
	"..\Interfaces\Debug\mecih_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\mtxm_I.mod"\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Interfaces\Debug\mxmt_I.mod"\
	"..\Interfaces\Debug\osinv_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\supdot_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deri21.F90
DEP_F90_DERI21=\
	"..\Interfaces\Debug\mtxmc_I.mod"\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deri22.F90
DEP_F90_DERI22=\
	"..\Interfaces\Debug\ddot_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\fock1_I.mod"\
	"..\Interfaces\Debug\fock2_I.mod"\
	"..\Interfaces\Debug\fockd1_I.mod"\
	"..\Interfaces\Debug\fockd2_I.mod"\
	"..\Interfaces\Debug\mtxm_I.mod"\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Interfaces\Debug\mxmt_I.mod"\
	"..\Interfaces\Debug\supdot_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deri23.F90
DEP_F90_DERI23=\
	"..\Interfaces\Debug\dcopy_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deritr.F90
DEP_F90_DERIT=\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\hcore_I.mod"\
	"..\Interfaces\Debug\iter_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\deriv.F90
DEP_F90_DERIV=\
	"..\Interfaces\Debug\dcart_I.mod"\
	"..\Interfaces\Debug\dernvo_I.mod"\
	"..\Interfaces\Debug\dfield_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\jcarin_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Interfaces\Debug\upcase_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dernvo.F90
DEP_F90_DERNV=\
	"..\Interfaces\Debug\deri0_I.mod"\
	"..\Interfaces\Debug\deri1_I.mod"\
	"..\Interfaces\Debug\deri2_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dfield.F90
DEP_F90_DFIEL=\
	"..\Interfaces\Debug\chrge_I.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dfock2.F90
DEP_F90_DFOCK=\
	"..\Interfaces\Debug\jab_I.mod"\
	"..\Interfaces\Debug\kab_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dfpsav.F90
DEP_F90_DFPSA=\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\ef_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dhc.F90
DEP_F90_DHC_F=\
	"..\Interfaces\Debug\elenuc_I.mod"\
	"..\Interfaces\Debug\fock2_I.mod"\
	"..\Interfaces\Debug\fockd2_I.mod"\
	"..\Interfaces\Debug\h1elec_I.mod"\
	"..\Interfaces\Debug\helect_I.mod"\
	"..\Interfaces\Debug\rotatd_I.mod"\
	"..\Interfaces\Debug\rotate_I.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dhcore.F90
DEP_F90_DHCOR=\
	"..\Interfaces\Debug\elenuc_I.mod"\
	"..\Interfaces\Debug\h1elec_I.mod"\
	"..\Interfaces\Debug\rotatd_I.mod"\
	"..\Interfaces\Debug\rotate_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\diag.F90
DEP_F90_DIAG_=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\diagi.F90
DEP_F90_DIAGI=\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\diat.F90
DEP_F90_DIAT_=\
	"..\Interfaces\Debug\bfn_I.mod"\
	"..\Interfaces\Debug\coe_I.mod"\
	"..\Interfaces\Debug\diat2_I.mod"\
	"..\Interfaces\Debug\gover_I.mod"\
	"..\Interfaces\Debug\set_I.mod"\
	"..\Interfaces\Debug\ss_I.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\digit.F90
DEP_F90_DIGIT=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dihed.F90
DEP_F90_DIHED=\
	"..\Interfaces\Debug\dang_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dijkl1.F90
DEP_F90_DIJKL=\
	"..\Interfaces\Debug\formxy_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dijkl2.F90
DEP_F90_DIJKL2=\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dimens.F90
DEP_F90_DIMEN=\
	"..\Interfaces\Debug\symopr_I.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dipole.F90
DEP_F90_DIPOL=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dist2.F90
DEP_F90_DIST2=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dofs.F90
DEP_F90_DOFS_=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dot.F90
DEP_F90_DOT_F=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\drc.F90
DEP_F90_DRC_F=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\prtdrc_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\drcout.F90
DEP_F90_DRCOU=\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dtran2.F90
DEP_F90_DTRAN=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\dtrans.F90
DEP_F90_DTRANS=\
	"..\Interfaces\Debug\dtran2_I.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\ef.F90
DEP_F90_EF_F9=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\daxpy_I.mod"\
	"..\Interfaces\Debug\dgedi_I.mod"\
	"..\Interfaces\Debug\dgefa_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\dscal_I.mod"\
	"..\Interfaces\Debug\dswap_I.mod"\
	"..\Interfaces\Debug\efsav_I.mod"\
	"..\Interfaces\Debug\efstr_I.mod"\
	"..\Interfaces\Debug\formd_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\gethes_I.mod"\
	"..\Interfaces\Debug\idamax_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\overlp_I.mod"\
	"..\Interfaces\Debug\prjfc_I.mod"\
	"..\Interfaces\Debug\prthes_I.mod"\
	"..\Interfaces\Debug\prttim_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Interfaces\Debug\updhes_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\ef_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\enpart.F90
DEP_F90_ENPAR=\
	"..\Interfaces\Debug\elenuc_I.mod"\
	"..\Interfaces\Debug\rotatd_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\esp.F90
DEP_F90_ESP_F=\
	"..\Interfaces\Debug\collid_I.mod"\
	"..\Interfaces\Debug\densit_I.mod"\
	"..\Interfaces\Debug\dex2_I.mod"\
	"..\Interfaces\Debug\dist2_I.mod"\
	"..\Interfaces\Debug\espfit_I.mod"\
	"..\Interfaces\Debug\fsub_I.mod"\
	"..\Interfaces\Debug\genun_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\mult_I.mod"\
	"..\Interfaces\Debug\naicas_I.mod"\
	"..\Interfaces\Debug\ovlp_I.mod"\
	"..\Interfaces\Debug\pdgrid_I.mod"\
	"..\Interfaces\Debug\potcal_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\setup3_I.mod"\
	"..\Interfaces\Debug\setupg_I.mod"\
	"..\Interfaces\Debug\surfac_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\esp_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\exchng.F90
DEP_F90_EXCHN=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\finish.F90
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\flepo.F90
DEP_F90_FLEPO=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dcopy_I.mod"\
	"..\Interfaces\Debug\dfpsav_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\linmin_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\prttim_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\supdot_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\fmat.F90
DEP_F90_FMAT_=\
	"..\Interfaces\Debug\chrge_I.mod"\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dipole_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\sympop_I.mod"\
	"..\Interfaces\Debug\symr_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\fock1.F90
DEP_F90_FOCK1=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\fock2.F90
DEP_F90_FOCK2=\
	"..\Interfaces\Debug\addfck_I.mod"\
	"..\Interfaces\Debug\jab_I.mod"\
	"..\Interfaces\Debug\kab_I.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\force.F90
DEP_F90_FORCE=\
	"..\Interfaces\Debug\anavib_I.mod"\
	"..\Interfaces\Debug\axis_I.mod"\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\drc_I.mod"\
	"..\Interfaces\Debug\flepo_I.mod"\
	"..\Interfaces\Debug\fmat_I.mod"\
	"..\Interfaces\Debug\frame_I.mod"\
	"..\Interfaces\Debug\freqcy_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\intfc_I.mod"\
	"..\Interfaces\Debug\matou1_I.mod"\
	"..\Interfaces\Debug\matout_I.mod"\
	"..\Interfaces\Debug\nllsq_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\symtrz_I.mod"\
	"..\Interfaces\Debug\thermo_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Interfaces\Debug\writmo_I.mod"\
	"..\Interfaces\Debug\xyzint_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\formxy.F90
DEP_F90_FORMX=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\forsav.F90
DEP_F90_FORSA=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\frame.F90
DEP_F90_FRAME=\
	"..\Interfaces\Debug\axis_I.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\freqcy.F90
DEP_F90_FREQC=\
	"..\Interfaces\Debug\brlzon_I.mod"\
	"..\Interfaces\Debug\frame_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\symt_I.mod"\
	"..\Interfaces\Debug\symtrz_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\genun.F90
DEP_F90_GENUN=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\geout.F90
DEP_F90_GEOUT=\
	"..\Interfaces\Debug\chrge_I.mod"\
	"..\Interfaces\Debug\wrttxt_I.mod"\
	"..\Interfaces\Debug\xyzint_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\geoutg.F90
DEP_F90_GEOUTG=\
	"..\Interfaces\Debug\xxx_I.mod"\
	"..\Interfaces\Debug\xyzint_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\getdat.F90
DEP_F90_GETDA=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\getgeg.F90
DEP_F90_GETGE=\
	"..\Interfaces\Debug\getval_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\getgeo.F90
DEP_F90_GETGEO=\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\nuchar_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\upcase_I.mod"\
	"..\Interfaces\Debug\xyzint_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\getsym.F90
DEP_F90_GETSY=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\gettxt.F90
DEP_F90_GETTX=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\upcase_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\getval.F90
DEP_F90_GETVA=\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\gmetry.F90
DEP_F90_GMETR=\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\gover.F90
DEP_F90_GOVER=\
	"..\Modules\Debug\analyt_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\grid.F90
DEP_F90_GRID_=\
	"..\Interfaces\Debug\dfpsav_I.mod"\
	"..\Interfaces\Debug\ef_I.mod"\
	"..\Interfaces\Debug\flepo_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\wrttxt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\h1elec.F90
DEP_F90_H1ELE=\
	"..\Interfaces\Debug\diat_I.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\haddon.F90
DEP_F90_HADDO=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\hcore.F90
DEP_F90_HCORE=\
	"..\Interfaces\Debug\addhcr_I.mod"\
	"..\Interfaces\Debug\addnuc_I.mod"\
	"..\Interfaces\Debug\h1elec_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rotate_I.mod"\
	"..\Interfaces\Debug\solrot_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\helect.F90
DEP_F90_HELEC=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\ijkl.F90
DEP_F90_IJKL_=\
	"..\Interfaces\Debug\ciint_I.mod"\
	"..\Interfaces\Debug\partxy_I.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\init_filenames.F90
DEP_F90_INIT_=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\interp.F90
DEP_F90_INTER=\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\schmib_I.mod"\
	"..\Interfaces\Debug\schmit_I.mod"\
	"..\Interfaces\Debug\spline_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\intfc.F90
DEP_F90_INTFC=\
	"..\Interfaces\Debug\jcarin_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\iter.F90
DEP_F90_ITER_=\
	"..\Interfaces\Debug\capcor_I.mod"\
	"..\Interfaces\Debug\chrge_I.mod"\
	"..\Interfaces\Debug\cnvg_I.mod"\
	"..\Interfaces\Debug\densit_I.mod"\
	"..\Interfaces\Debug\diag_I.mod"\
	"..\Interfaces\Debug\fock1_I.mod"\
	"..\Interfaces\Debug\fock2_I.mod"\
	"..\Interfaces\Debug\fockd1_I.mod"\
	"..\Interfaces\Debug\fockd2_I.mod"\
	"..\Interfaces\Debug\helect_I.mod"\
	"..\Interfaces\Debug\interp_I.mod"\
	"..\Interfaces\Debug\matout_I.mod"\
	"..\Interfaces\Debug\meci_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\pulay_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\swap_I.mod"\
	"..\Interfaces\Debug\timer_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Interfaces\Debug\writmo_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\iter_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\jab.F90
DEP_F90_JAB_F=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\jcarin.F90
DEP_F90_JCARI=\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\kab.F90
DEP_F90_KAB_F=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\linmin.F90
DEP_F90_LINMI=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\exchng_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\local.F90
DEP_F90_LOCAL=\
	"..\Interfaces\Debug\matout_I.mod"\
	"..\Interfaces\Debug\resolv_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\locmin.F90
DEP_F90_LOCMI=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\exchng_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\makopr.F90
DEP_F90_MAKOP=\
	"..\Interfaces\Debug\bldsym_I.mod"\
	"..\Interfaces\Debug\chi_I.mod"\
	"..\Interfaces\Debug\symopr_I.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\maksym.F90
DEP_F90_MAKSY=\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mamult.F90
DEP_F90_MAMUL=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mat33.F90
DEP_F90_MAT33=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\matou1.F90
DEP_F90_MATOU=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\matout.F90
DEP_F90_MATOUT=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\meci.F90
DEP_F90_MECI_=\
	"..\Interfaces\Debug\ciosci_I.mod"\
	"..\Interfaces\Debug\diagi_I.mod"\
	"..\Interfaces\Debug\dmecip_I.mod"\
	"..\Interfaces\Debug\matou1_I.mod"\
	"..\Interfaces\Debug\matout_I.mod"\
	"..\Interfaces\Debug\mecih_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\perm_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\symtrz_I.mod"\
	"..\Interfaces\Debug\upcase_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mecid.F90
DEP_F90_MECID=\
	"..\Interfaces\Debug\diagi_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mecih.F90
DEP_F90_MECIH=\
	"..\Interfaces\Debug\aababc_I.mod"\
	"..\Interfaces\Debug\aabacd_I.mod"\
	"..\Interfaces\Debug\aabbcd_I.mod"\
	"..\Interfaces\Debug\babbbc_I.mod"\
	"..\Interfaces\Debug\babbcd_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mecip.F90
DEP_F90_MECIP=\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\minv.F90
DEP_F90_MINV_=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mndod.F90
DEP_F90_MNDOD=\
	"..\Interfaces\Debug\addfck_I.mod"\
	"..\Interfaces\Debug\addhcr_I.mod"\
	"..\Interfaces\Debug\addnuc_I.mod"\
	"..\Interfaces\Debug\aijm_I.mod"\
	"..\Interfaces\Debug\ccrep_I.mod"\
	"..\Interfaces\Debug\charg_I.mod"\
	"..\Interfaces\Debug\ddpo_I.mod"\
	"..\Interfaces\Debug\eiscor_I.mod"\
	"..\Interfaces\Debug\elenuc_I.mod"\
	"..\Interfaces\Debug\fbx_I.mod"\
	"..\Interfaces\Debug\fordd_I.mod"\
	"..\Interfaces\Debug\formxd_I.mod"\
	"..\Interfaces\Debug\formxy_I.mod"\
	"..\Interfaces\Debug\h1elec_I.mod"\
	"..\Interfaces\Debug\inighd_I.mod"\
	"..\Interfaces\Debug\mlig_I.mod"\
	"..\Interfaces\Debug\poij_I.mod"\
	"..\Interfaces\Debug\printp_I.mod"\
	"..\Interfaces\Debug\reppd2_I.mod"\
	"..\Interfaces\Debug\reppd_I.mod"\
	"..\Interfaces\Debug\rijkl_I.mod"\
	"..\Interfaces\Debug\rotatd_I.mod"\
	"..\Interfaces\Debug\rotmat_I.mod"\
	"..\Interfaces\Debug\rsc_I.mod"\
	"..\Interfaces\Debug\scprm_I.mod"\
	"..\Interfaces\Debug\spcore_I.mod"\
	"..\Interfaces\Debug\tx_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Interfaces\Debug\w2mat_I.mod"\
	"..\Interfaces\Debug\wstore_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\mndod_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\moldat.F90
DEP_F90_MOLDA=\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\refer_I.mod"\
	"..\Interfaces\Debug\symtrz_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\molmec_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\molsym.F90
DEP_F90_MOLSY=\
	"..\Interfaces\Debug\bldsym_I.mod"\
	"..\Interfaces\Debug\cartab_I.mod"\
	"..\Interfaces\Debug\chi_I.mod"\
	"..\Interfaces\Debug\orient_I.mod"\
	"..\Interfaces\Debug\plato_I.mod"\
	"..\Interfaces\Debug\rotmol_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\symopr_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\molval.F90
DEP_F90_MOLVA=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mopend.F90
DEP_F90_MOPEN=\
	"..\Modules\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mpcpop.F90
DEP_F90_MPCPO=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mtxm.F90
DEP_F90_MTXM_=\
	"..\Interfaces\Debug\dgemm_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mtxmc.F90
DEP_F90_MTXMC=\
	"..\Interfaces\Debug\mxm_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mullik.F90
DEP_F90_MULLI=\
	"..\Interfaces\Debug\densit_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\mult_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mult.F90
DEP_F90_MULT_=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mult33.F90
DEP_F90_MULT3=\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mxm.F90
DEP_F90_MXM_F=\
	"..\Interfaces\Debug\dgemm_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mxmt.F90
DEP_F90_MXMT_=\
	"..\Interfaces\Debug\dgemm_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\myword.F90
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\nllsq.F90
DEP_F90_NLLSQ=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\locmin_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\parsav_I.mod"\
	"..\Interfaces\Debug\prttim_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\nuchar.F90
DEP_F90_NUCHA=\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\orient.F90
DEP_F90_ORIEN=\
	"..\Interfaces\Debug\chi_I.mod"\
	"..\Interfaces\Debug\mult33_I.mod"\
	"..\Interfaces\Debug\rotmol_I.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\osinv.F90
DEP_F90_OSINV=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\parsav.F90
DEP_F90_PARSA=\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\partxy.F90
DEP_F90_PARTX=\
	"..\Interfaces\Debug\formxd_I.mod"\
	"..\Interfaces\Debug\formxy_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\pathk.F90
DEP_F90_PATHK=\
	"..\Interfaces\Debug\dfpsav_I.mod"\
	"..\Interfaces\Debug\ef_I.mod"\
	"..\Interfaces\Debug\flepo_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\wrttxt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\paths.F90
DEP_F90_PATHS=\
	"..\Interfaces\Debug\dfpsav_I.mod"\
	"..\Interfaces\Debug\ef_I.mod"\
	"..\Interfaces\Debug\flepo_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\writmo_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\ef_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\perm.F90
DEP_F90_PERM_=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\plato.F90
DEP_F90_PLATO=\
	"..\Interfaces\Debug\bangle_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\symopr_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\pmep.F90
DEP_F90_PMEP_=\
	"..\Interfaces\Debug\collis_I.mod"\
	"..\Interfaces\Debug\drepp2_I.mod"\
	"..\Interfaces\Debug\drotat_I.mod"\
	"..\Interfaces\Debug\genvec_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\grids_I.mod"\
	"..\Interfaces\Debug\mepchg_I.mod"\
	"..\Interfaces\Debug\mepmap_I.mod"\
	"..\Interfaces\Debug\meprot_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\osinv_I.mod"\
	"..\Interfaces\Debug\packp_I.mod"\
	"..\Interfaces\Debug\pmepco_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\surfa_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\pmep_C.mod"\
	"..\Modules\Debug\rotate_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\polar.F90
DEP_F90_POLAR=\
	"..\Interfaces\Debug\alphaf_I.mod"\
	"..\Interfaces\Debug\aval_I.mod"\
	"..\Interfaces\Debug\axis_I.mod"\
	"..\Interfaces\Debug\bdenin_I.mod"\
	"..\Interfaces\Debug\bdenup_I.mod"\
	"..\Interfaces\Debug\beopor_I.mod"\
	"..\Interfaces\Debug\betaf_I.mod"\
	"..\Interfaces\Debug\betal1_I.mod"\
	"..\Interfaces\Debug\betall_I.mod"\
	"..\Interfaces\Debug\betcom_I.mod"\
	"..\Interfaces\Debug\bmakuf_I.mod"\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\copym_I.mod"\
	"..\Interfaces\Debug\darea1_I.mod"\
	"..\Interfaces\Debug\daread_I.mod"\
	"..\Interfaces\Debug\dawrit_I.mod"\
	"..\Interfaces\Debug\dawrt1_I.mod"\
	"..\Interfaces\Debug\densf_I.mod"\
	"..\Interfaces\Debug\epsab_I.mod"\
	"..\Interfaces\Debug\ffreq1_I.mod"\
	"..\Interfaces\Debug\ffreq2_I.mod"\
	"..\Interfaces\Debug\fhpatn_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\hmuf_I.mod"\
	"..\Interfaces\Debug\hplusf_I.mod"\
	"..\Interfaces\Debug\makeuf_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\ngamtg_I.mod"\
	"..\Interfaces\Debug\ngefis_I.mod"\
	"..\Interfaces\Debug\ngidri_I.mod"\
	"..\Interfaces\Debug\ngoke_I.mod"\
	"..\Interfaces\Debug\nonbet_I.mod"\
	"..\Interfaces\Debug\nonope_I.mod"\
	"..\Interfaces\Debug\nonor_I.mod"\
	"..\Interfaces\Debug\openda_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\tf_I.mod"\
	"..\Interfaces\Debug\transf_I.mod"\
	"..\Interfaces\Debug\trsub_I.mod"\
	"..\Interfaces\Debug\trudgu_I.mod"\
	"..\Interfaces\Debug\trugdu_I.mod"\
	"..\Interfaces\Debug\trugud_I.mod"\
	"..\Interfaces\Debug\wrdkey_I.mod"\
	"..\Interfaces\Debug\zerom_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\polar_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\powsav.F90
DEP_F90_POWSA=\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\ef_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\powsq.F90
DEP_F90_POWSQ=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\prttim_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Interfaces\Debug\search_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\prtdrc.F90
DEP_F90_PRTDR=\
	"..\Interfaces\Debug\chrge_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\drcout_I.mod"\
	"..\Interfaces\Debug\quadr_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\xyzint_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\prttim.F90
DEP_F90_PRTTI=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\pulay.F90
DEP_F90_PULAY=\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\mamult_I.mod"\
	"..\Interfaces\Debug\osinv_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\quadr.F90
DEP_F90_QUADR=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\react1.F90
DEP_F90_REACT=\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\getgeo_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Interfaces\Debug\writmo_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\reada.F90
DEP_F90_READA=\
	"..\Interfaces\Debug\digit_I.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\readmo.F90
DEP_F90_READM=\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\getgeg_I.mod"\
	"..\Interfaces\Debug\getgeo_I.mod"\
	"..\Interfaces\Debug\getsym_I.mod"\
	"..\Interfaces\Debug\gettxt_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\maksym_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\nuchar_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Interfaces\Debug\wrtkey_I.mod"\
	"..\Interfaces\Debug\wrttxt_I.mod"\
	"..\Interfaces\Debug\xyzint_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\refer.F90
DEP_F90_REFER=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\refs_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\repp.F90
DEP_F90_REPP_=\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\resolv.F90
DEP_F90_RESOL=\
	"..\Interfaces\Debug\rsp_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\rotate.F90
DEP_F90_ROTAT=\
	"..\Interfaces\Debug\repp_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\rotate_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\rotmol.F90
DEP_F90_ROTMO=\
	"..\Interfaces\Debug\symopr_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\rsp.F90
DEP_F90_RSP_F=\
	"..\Interfaces\Debug\dasum_I.mod"\
	"..\Interfaces\Debug\daxpy_I.mod"\
	"..\Interfaces\Debug\ddot_I.mod"\
	"..\Interfaces\Debug\dnrm2_I.mod"\
	"..\Interfaces\Debug\dscal_I.mod"\
	"..\Interfaces\Debug\einvit_I.mod"\
	"..\Interfaces\Debug\elau_I.mod"\
	"..\Interfaces\Debug\epslon_I.mod"\
	"..\Interfaces\Debug\eqlrat_I.mod"\
	"..\Interfaces\Debug\estpi1_I.mod"\
	"..\Interfaces\Debug\etrbk3_I.mod"\
	"..\Interfaces\Debug\etred3_I.mod"\
	"..\Interfaces\Debug\evvrsp_I.mod"\
	"..\Interfaces\Debug\freda_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\schmib.F90
DEP_F90_SCHMI=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\schmit.F90
DEP_F90_SCHMIT=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\second.F90
DEP_F90_SECON=\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\set.F90
DEP_F90_SET_F=\
	"..\Interfaces\Debug\aintgs_I.mod"\
	"..\Interfaces\Debug\bintgs_I.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\setup_mopac_arrays.F90
DEP_F90_SETUP=\
	"..\Modules\Debug\iter_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\setupg.F90
DEP_F90_SETUPG=\
	"..\Modules\Debug\analyt_C.mod"\
	"..\Modules\Debug\overlaps_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\solrot.F90
DEP_F90_SOLRO=\
	"..\Interfaces\Debug\rotate_I.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\sort.F90
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\supdot.F90
DEP_F90_SUPDO=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\superd.F90
DEP_F90_SUPER=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\swap.F90
DEP_F90_SWAP_=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\switch.F90
DEP_F90_SWITC=\
	"..\Interfaces\Debug\calpar_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\parameters_for_am1_C.mod"\
	"..\Modules\Debug\parameters_for_mndo_C.mod"\
	"..\Modules\Debug\parameters_for_mndod_C.mod"\
	"..\Modules\Debug\parameters_for_pm3_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symdec.F90
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symh.F90
DEP_F90_SYMH_=\
	"..\Interfaces\Debug\mat33_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symoir.F90
DEP_F90_SYMOI=\
	"..\Interfaces\Debug\charmo_I.mod"\
	"..\Interfaces\Debug\charst_I.mod"\
	"..\Interfaces\Debug\charvi_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symopr.F90
DEP_F90_SYMOP=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symp.f90
DEP_F90_SYMP_=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\sympop.F90
DEP_F90_SYMPO=\
	"..\Interfaces\Debug\symh_I.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symr.F90
DEP_F90_SYMR_=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\symp_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symt.F90
DEP_F90_SYMT_=\
	"..\Interfaces\Debug\mat33_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symtry.F90
DEP_F90_SYMTR=\
	"..\Interfaces\Debug\haddon_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\symtrz.F90
DEP_F90_SYMTRZ=\
	"..\Interfaces\Debug\makopr_I.mod"\
	"..\Interfaces\Debug\molsym_I.mod"\
	"..\Interfaces\Debug\mult33_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\thermo.F90
DEP_F90_THERM=\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\timer.F90
DEP_F90_TIMER=\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\timout.F90
DEP_F90_TIMOU=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\upcase.F90
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\update.F90
DEP_F90_UPDAT=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\vecprt.F90
DEP_F90_VECPR=\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\volume.f90
DEP_F90_VOLUM=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\writmo.F90
DEP_F90_WRITM=\
	"..\Interfaces\Debug\bonds_I.mod"\
	"..\Interfaces\Debug\brlzon_I.mod"\
	"..\Interfaces\Debug\chrge_I.mod"\
	"..\Interfaces\Debug\denrot_I.mod"\
	"..\Interfaces\Debug\deriv_I.mod"\
	"..\Interfaces\Debug\dielen_I.mod"\
	"..\Interfaces\Debug\dimens_I.mod"\
	"..\Interfaces\Debug\dipole_I.mod"\
	"..\Interfaces\Debug\dot_I.mod"\
	"..\Interfaces\Debug\enpart_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\geoutg_I.mod"\
	"..\Interfaces\Debug\gmetry_I.mod"\
	"..\Interfaces\Debug\local_I.mod"\
	"..\Interfaces\Debug\matou1_I.mod"\
	"..\Interfaces\Debug\meci_I.mod"\
	"..\Interfaces\Debug\mecip_I.mod"\
	"..\Interfaces\Debug\molval_I.mod"\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\mpcpop_I.mod"\
	"..\Interfaces\Debug\mullik_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\superd_I.mod"\
	"..\Interfaces\Debug\symtry_I.mod"\
	"..\Interfaces\Debug\symtrz_I.mod"\
	"..\Interfaces\Debug\timout_I.mod"\
	"..\Interfaces\Debug\vecprt_I.mod"\
	"..\Interfaces\Debug\volume_I.mod"\
	"..\Interfaces\Debug\wrttxt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\elemts_C.mod"\
	"..\Modules\Debug\euler_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\maps_C.mod"\
	"..\Modules\Debug\meci_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\symmetry_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\wrtkey.F90
DEP_F90_WRTKE=\
	"..\Interfaces\Debug\mopend_I.mod"\
	"..\Interfaces\Debug\myword_I.mod"\
	"..\Interfaces\Debug\reada_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\wrttxt.F90
DEP_F90_WRTTX=\
	"..\Modules\Debug\molkst_C.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\xxx.F90
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\xyzcry.F90
DEP_F90_XYZCR=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\xyzgeo.F90
DEP_F90_XYZGE=\
	"..\Interfaces\Debug\bangle_I.mod"\
	"..\Interfaces\Debug\dihed_I.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\xyzint.F90
DEP_F90_XYZIN=\
	"..\Interfaces\Debug\bangle_I.mod"\
	"..\Interfaces\Debug\dihed_I.mod"\
	"..\Interfaces\Debug\xyzgeo_I.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# End Group
# End Target
# End Project
