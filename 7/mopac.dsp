# Microsoft Developer Studio Project File - Name="mopac" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mopac - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mopac.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mopac.mak" CFG="mopac - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mopac - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mopac - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
F90=df.exe
RSC=rc.exe

!IF  "$(CFG)" == "mopac - Win32 Release"

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

!ELSEIF  "$(CFG)" == "mopac - Win32 Debug"

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
# ADD F90 /check:bounds /compile_only /dbglibs /debug:full /nologo /traceback /warn:argument_checking /warn:nofileopt
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "mopac - Win32 Release"
# Name "mopac - Win32 Debug"
# Begin Source File

SOURCE=.\aababc.f
DEP_F90_AABAB=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\addfck.f
DEP_F90_ADDFC=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\addhcr.f
DEP_F90_ADDHC=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\addnuc.f
DEP_F90_ADDNU=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\analyt.f
DEP_F90_ANALY=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\anavib.f
DEP_F90_ANAVI=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\axis.f
DEP_F90_AXIS_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\block.f
# End Source File
# Begin Source File

SOURCE=.\bonds.f
DEP_F90_BONDS=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\brlzon.f
DEP_F90_BRLZO=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\btoc.f
DEP_F90_BTOC_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\calpar.f
# End Source File
# Begin Source File

SOURCE=.\capcor.f
# End Source File
# Begin Source File

SOURCE=.\cdiag.f
# End Source File
# Begin Source File

SOURCE=.\chrge.f
DEP_F90_CHRGE=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\cnvg.f
# End Source File
# Begin Source File

SOURCE=.\compfg.f
DEP_F90_COMPF=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\consts.f
DEP_F90_CONST=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\cqden.f
DEP_F90_CQDEN=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\datin.f
DEP_F90_DATIN=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dcart.f
DEP_F90_DCART=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\delmol.f
# End Source File
# Begin Source File

SOURCE=.\delri.f
# End Source File
# Begin Source File

SOURCE=.\denrot.f
DEP_F90_DENRO=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\densit.f
# End Source File
# Begin Source File

SOURCE=.\depvar.f
# End Source File
# Begin Source File

SOURCE=.\deri0.f
# End Source File
# Begin Source File

SOURCE=.\deri1.f
DEP_F90_DERI1=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\deri2.f
DEP_F90_DERI2=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\deri21.f
# End Source File
# Begin Source File

SOURCE=.\deri22.f
DEP_F90_DERI22=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\deri23.f
DEP_F90_DERI23=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\deritr.f
DEP_F90_DERIT=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\deriv.f
DEP_F90_DERIV=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dernvo.f
DEP_F90_DERNV=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\ders.f
# End Source File
# Begin Source File

SOURCE=.\dfock2.f
DEP_F90_DFOCK=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dfpsav.f
DEP_F90_DFPSA=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dgemm.f
# End Source File
# Begin Source File

SOURCE=.\dgemv.f
# End Source File
# Begin Source File

SOURCE=.\dger.f
# End Source File
# Begin Source File

SOURCE=.\dgetf2.f
# End Source File
# Begin Source File

SOURCE=.\dgetrf.f
# End Source File
# Begin Source File

SOURCE=.\dgetri.f
# End Source File
# Begin Source File

SOURCE=.\diag.f
DEP_F90_DIAG_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\diat.f
# End Source File
# Begin Source File

SOURCE=.\diat2.f
# End Source File
# Begin Source File

SOURCE=.\diegrd.f
DEP_F90_DIEGR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dielen.f
DEP_F90_DIELE=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\diis.f
DEP_F90_DIIS_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dijkl1.f
DEP_F90_DIJKL=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dijkl2.f
# End Source File
# Begin Source File

SOURCE=.\dipind.f
DEP_F90_DIPIN=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dipole.f
DEP_F90_DIPOL=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dlaswp.f
# End Source File
# Begin Source File

SOURCE=.\dofs.f
# End Source File
# Begin Source File

SOURCE=.\dot.f
# End Source File
# Begin Source File

SOURCE=.\drc.f
DEP_F90_DRC_F=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\drcout.f
DEP_F90_DRCOU=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\dtrmm.f
# End Source File
# Begin Source File

SOURCE=.\dtrmv.f
# End Source File
# Begin Source File

SOURCE=.\dtrsm.f
# End Source File
# Begin Source File

SOURCE=.\dtrti2.f
# End Source File
# Begin Source File

SOURCE=.\dtrtri.f
# End Source File
# Begin Source File

SOURCE=.\dvfill.f
# End Source File
# Begin Source File

SOURCE=.\ef.f
DEP_F90_EF_F46=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\enpart.f
DEP_F90_ENPAR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\esp.f
DEP_F90_ESP_F=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\exchng.f
# End Source File
# Begin Source File

SOURCE=.\ffhpol.f
DEP_F90_FFHPO=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\flepo.f
DEP_F90_FLEPO=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\flushm.f
# End Source File
# Begin Source File

SOURCE=.\fmat.f
DEP_F90_FMAT_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\fock1.f
DEP_F90_FOCK1=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\fock2.f
DEP_F90_FOCK2=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\force.f
DEP_F90_FORCE=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\formxy.f
# End Source File
# Begin Source File

SOURCE=.\forsav.f
DEP_F90_FORSA=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\frame.f
DEP_F90_FRAME=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\freqcy.f
DEP_F90_FREQC=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\geout.f
DEP_F90_GEOUT=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\geoutg.f
DEP_F90_GEOUTG=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\getdat.f
# End Source File
# Begin Source File

SOURCE=.\getgeg.f
DEP_F90_GETGE=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\getgeo.f
DEP_F90_GETGEO=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\getsym.f
DEP_F90_GETSY=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\gettxt.f
# End Source File
# Begin Source File

SOURCE=.\gmetry.f
DEP_F90_GMETR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\gover.f
DEP_F90_GOVER=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\greenf.f
DEP_F90_GREEN=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\grid.f
DEP_F90_GRID_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\h1elec.f
# End Source File
# Begin Source File

SOURCE=.\haddon.f
# End Source File
# Begin Source File

SOURCE=.\hcore.f
DEP_F90_HCORE=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\helect.f
# End Source File
# Begin Source File

SOURCE=.\hqrii.f
DEP_F90_HQRII=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\ijkl.f
DEP_F90_IJKL_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\ilaenv.f
# End Source File
# Begin Source File

SOURCE=.\initsv.f
DEP_F90_INITS=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\interp.f
DEP_F90_INTER=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\iter.f
DEP_F90_ITER_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\jcarin.f
DEP_F90_JCARI=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\linmin.f
DEP_F90_LINMI=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\local.f
DEP_F90_LOCAL=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\locmin.f
DEP_F90_LOCMI=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\lsame.f
# End Source File
# Begin Source File

SOURCE=.\makpol.f
DEP_F90_MAKPO=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mamult.f
# End Source File
# Begin Source File

SOURCE=.\matou1.f
DEP_F90_MATOU=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\matout.f
DEP_F90_MATOUT=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\matpak.f
# End Source File
# Begin Source File

SOURCE=.\meci.f
DEP_F90_MECI_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mecid.f
DEP_F90_MECID=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mecih.f
DEP_F90_MECIH=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mecip.f
DEP_F90_MECIP=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\moldat.f
DEP_F90_MOLDA=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\molval.f
DEP_F90_MOLVA=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mopac.f
DEP_F90_MOPAC=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mullik.f
DEP_F90_MULLI=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\mult.f
# End Source File
# Begin Source File

SOURCE=.\myword.f
# End Source File
# Begin Source File

SOURCE=.\nllsq.f
DEP_F90_NLLSQ=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\nuchar.f
# End Source File
# Begin Source File

SOURCE=.\parsav.f
DEP_F90_PARSA=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\partxy.f
DEP_F90_PARTX=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\pathk.f
DEP_F90_PATHK=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\paths.f
DEP_F90_PATHS=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\perm.f
# End Source File
# Begin Source File

SOURCE=.\pmep.f
DEP_F90_PMEP_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\polar.f
DEP_F90_POLAR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\powsav.f
DEP_F90_POWSA=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\powsq.f
DEP_F90_POWSQ=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\prtdrc.f
DEP_F90_PRTDR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\quadr.f
# End Source File
# Begin Source File

SOURCE=.\react1.f
DEP_F90_REACT=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\reada.f
# End Source File
# Begin Source File

SOURCE=.\readmo.f
DEP_F90_READM=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\refer.f
DEP_F90_REFER=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\repp.f
DEP_F90_REPP_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\rotat.f
# End Source File
# Begin Source File

SOURCE=.\rotate.f
DEP_F90_ROTAT=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\rsp.f
DEP_F90_RSP_F=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\search.f
DEP_F90_SEARC=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\second.f
# End Source File
# Begin Source File

SOURCE=.\setupg.f
DEP_F90_SETUP=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\solrot.f
# End Source File
# Begin Source File

SOURCE=.\swap.f
DEP_F90_SWAP_=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\sympro.f
DEP_F90_SYMPR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\symtry.f
DEP_F90_SYMTR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\symtrz.f
DEP_F90_SYMTRZ=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\thermo.f
# End Source File
# Begin Source File

SOURCE=.\timer.f
# End Source File
# Begin Source File

SOURCE=.\timout.f
DEP_F90_TIMOU=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\tom.f
DEP_F90_TOM_F=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\update.f
# End Source File
# Begin Source File

SOURCE=.\upsurf.f
DEP_F90_UPSUR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\vecprt.f
DEP_F90_VECPR=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\writmo.f
DEP_F90_WRITM=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\wrtkey.f
DEP_F90_WRTKE=\
	".\SIZES"\
	
# End Source File
# Begin Source File

SOURCE=.\wrttxt.f
# End Source File
# Begin Source File

SOURCE=.\xerbla.f
# End Source File
# Begin Source File

SOURCE=.\xyzint.f
# End Source File
# End Target
# End Project
