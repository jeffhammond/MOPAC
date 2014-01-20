# Microsoft Developer Studio Project File - Name="Modules" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=Modules - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Modules.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Modules.mak" CFG="Modules - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Modules - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Modules - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
RSC=rc.exe

!IF  "$(CFG)" == "Modules - Win32 Release"

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

!ELSEIF  "$(CFG)" == "Modules - Win32 Debug"

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
# ADD F90 /check:bounds /compile_only /dbglibs /debug:full /include:"..\..\new_common\Debug" /include:"..\..\new_interface\Debug" /nologo /traceback /warn:argument_checking /warn:nofileopt
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

# Name "Modules - Win32 Release"
# Name "Modules - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;f90;for;f;fpp"
# Begin Source File

SOURCE=..\src_modules\analyt_C.f90
DEP_F90_ANALY=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\chanel_C.f90
DEP_F90_CHANE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\conref_C.f90
DEP_F90_CONRE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\cosmo_C.f90
DEP_F90_COSMO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\ef_C.f90
DEP_F90_EF_C_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\elemts_C.f90
DEP_F90_ELEMT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\esp_C.f90
DEP_F90_ESP_C=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\euler_C.f90
DEP_F90_EULER=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\funcon_C.f90
DEP_F90_FUNCO=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\iter_C.f90
DEP_F90_ITER_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\maps_C.f90
DEP_F90_MAPS_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\meci_C.f90
DEP_F90_MECI_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\mndod_C.f90
DEP_F90_MNDOD=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\molkst_C.f90
DEP_F90_MOLKS=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\molmec_C.f90
DEP_F90_MOLME=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\overlaps_C.f90
DEP_F90_OVERL=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\parameters_C.f90
DEP_F90_PARAM=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\parameters_for_AM1_C.f90
DEP_F90_PARAME=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\parameters_for_mndo_C.f90
DEP_F90_PARAMET=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\parameters_for_mndod_C.f90
DEP_F90_PARAMETE=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\parameters_for_pm3_C.f90
DEP_F90_PARAMETER=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\permanent_arrays.F90
DEP_F90_PERMA=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\pmep_C.f90
DEP_F90_PMEP_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\polar_C.f90
DEP_F90_POLAR=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\refkey_C.F90
# End Source File
# Begin Source File

SOURCE=..\src_modules\refs_C.f90
DEP_F90_REFS_=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\rotate_C.f90
DEP_F90_ROTAT=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\symmetry_C.f90
DEP_F90_SYMME=\
	".\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_modules\vastkind.f90
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# End Group
# End Target
# End Project
