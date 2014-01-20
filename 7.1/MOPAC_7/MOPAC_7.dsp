# Microsoft Developer Studio Project File - Name="MOPAC_7" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=MOPAC_7 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MOPAC_7.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MOPAC_7.mak" CFG="MOPAC_7 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MOPAC_7 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "MOPAC_7 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
RSC=rc.exe

!IF  "$(CFG)" == "MOPAC_7 - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "MOPAC_7 - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE F90 /check:bounds /compile_only /dbglibs /debug:full /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD F90 /check:bounds /compile_only /dbglibs /debug:full /include:"..\Modules\Debug" /include:"..\Interfaces\Debug" /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib /nologo /stack:0x8000000 /subsystem:console /incremental:no /debug /machine:I386 /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "MOPAC_7 - Win32 Release"
# Name "MOPAC_7 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat;f90;for;f;fpp"
# Begin Source File

SOURCE=..\src_modules\mndod_C.f90
DEP_F90_MNDOD=\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# Begin Source File

SOURCE=..\src_subroutines\mopac.F90
DEP_F90_MOPAC=\
	"..\Interfaces\Debug\calpar_I.mod"\
	"..\Interfaces\Debug\compfg_I.mod"\
	"..\Interfaces\Debug\datin_I.mod"\
	"..\Interfaces\Debug\drc_I.mod"\
	"..\Interfaces\Debug\ef_I.mod"\
	"..\Interfaces\Debug\fbx_I.mod"\
	"..\Interfaces\Debug\flepo_I.mod"\
	"..\Interfaces\Debug\force_I.mod"\
	"..\Interfaces\Debug\fordd_I.mod"\
	"..\Interfaces\Debug\geout_I.mod"\
	"..\Interfaces\Debug\geoutg_I.mod"\
	"..\Interfaces\Debug\grid_I.mod"\
	"..\Interfaces\Debug\inid_I.mod"\
	"..\Interfaces\Debug\initsv_I.mod"\
	"..\Interfaces\Debug\nllsq_I.mod"\
	"..\Interfaces\Debug\pathk_I.mod"\
	"..\Interfaces\Debug\paths_I.mod"\
	"..\Interfaces\Debug\pmep_I.mod"\
	"..\Interfaces\Debug\polar_I.mod"\
	"..\Interfaces\Debug\powsq_I.mod"\
	"..\Interfaces\Debug\react1_I.mod"\
	"..\Interfaces\Debug\second_I.mod"\
	"..\Interfaces\Debug\writmo_I.mod"\
	"..\Interfaces\Debug\wrttxt_I.mod"\
	"..\Modules\Debug\chanel_C.mod"\
	"..\Modules\Debug\conref_C.mod"\
	"..\Modules\Debug\cosmo_C.mod"\
	"..\Modules\Debug\errmes_C.mod"\
	"..\Modules\Debug\funcon_C.mod"\
	"..\Modules\Debug\indexw_C.mod"\
	"..\Modules\Debug\jobnam_C.mod"\
	"..\Modules\Debug\molkst_C.mod"\
	"..\Modules\Debug\okmany_C.mod"\
	"..\Modules\Debug\parameters_C.mod"\
	"..\Modules\Debug\path_C.mod"\
	"..\Modules\Debug\permanent_arrays.mod"\
	"..\Modules\Debug\vast_kind_param.mod"\
	
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl;fi;fd"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
