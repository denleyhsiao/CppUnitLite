# Microsoft Developer Studio Project File - Name="CppUnitLite" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=CppUnitLite - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CppUnitLite.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CppUnitLite.mak" CFG="CppUnitLite - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CppUnitLite - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "CppUnitLite - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CppUnitLite - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../include/CppUnitLite/" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Special Build Tool
TargetPath=.\Release\CppUnitLite.lib
TargetName=CppUnitLite
SOURCE="$(InputPath)"
PostBuild_Cmds=copy "$(TargetPath)" ..\lib\$(TargetName).lib
# End Special Build Tool

!ELSEIF  "$(CFG)" == "CppUnitLite - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../include/CppUnitLite/" /D "_WINDOWS" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_AFXDLL" /D "PRODUCTION" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo
# Begin Special Build Tool
TargetPath=.\Debug\CppUnitLite.lib
TargetName=CppUnitLite
SOURCE="$(InputPath)"
PostBuild_Cmds=copy "$(TargetPath)" ..\lib\$(TargetName)D.lib
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "CppUnitLite - Win32 Release"
# Name "CppUnitLite - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\src\CommandLineTestRunner.cpp
# End Source File
# Begin Source File

SOURCE=..\src\EqualsFailure.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Failure.cpp
# End Source File
# Begin Source File

SOURCE=..\src\SimpleString.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Test.cpp
# End Source File
# Begin Source File

SOURCE=..\src\TestRegistry.cpp
# End Source File
# Begin Source File

SOURCE=..\src\TestResult.cpp
# End Source File
# Begin Source File

SOURCE=..\src\Win32MemoryLeakWarning.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\CppUnitLite\CommandLineTestRunner.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\EqualsFailure.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\Failure.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\MemoryLeakWarning.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\SimpleString.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\Test.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\TestHarness.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\TestRegistry.h
# End Source File
# Begin Source File

SOURCE=..\include\CppUnitLite\TestResult.h
# End Source File
# End Group
# End Target
# End Project
