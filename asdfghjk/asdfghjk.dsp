# Microsoft Developer Studio Project File - Name="asdfghjk" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=asdfghjk - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "asdfghjk.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "asdfghjk.mak" CFG="asdfghjk - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "asdfghjk - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "C:\Python27\include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 NLPIR.lib skinppwtl.lib /nologo /subsystem:windows /incremental:yes /debug /machine:I386 /libpath:"C:\Python27\libs"
# SUBTRACT LINK32 /profile /nodefaultlib
# Begin Target

# Name "asdfghjk - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\asdfghjk.cpp
# End Source File
# Begin Source File

SOURCE=.\asdfghjk.rc
# End Source File
# Begin Source File

SOURCE=.\asdfghjkDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Mdonwload.cpp
# End Source File
# Begin Source File

SOURCE=.\Para1.cpp
# End Source File
# Begin Source File

SOURCE=.\Para2.cpp
# End Source File
# Begin Source File

SOURCE=.\Para3.cpp
# End Source File
# Begin Source File

SOURCE=.\Para4.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\xunlian.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\asdfghjk.h
# End Source File
# Begin Source File

SOURCE=.\asdfghjkDlg.h
# End Source File
# Begin Source File

SOURCE=.\DLG.h
# End Source File
# Begin Source File

SOURCE=.\Mdonwload.h
# End Source File
# Begin Source File

SOURCE=.\include\NLPIR.h
# End Source File
# Begin Source File

SOURCE=.\Para1.h
# End Source File
# Begin Source File

SOURCE=.\Para2.h
# End Source File
# Begin Source File

SOURCE=.\Para3.h
# End Source File
# Begin Source File

SOURCE=.\Para4.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SkinPPWTL.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\xunlian.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\abc.bmp
# End Source File
# Begin Source File

SOURCE=.\abc13.bmp
# End Source File
# Begin Source File

SOURCE=.\abc_1.bmp
# End Source File
# Begin Source File

SOURCE=.\abc_11.bmp
# End Source File
# Begin Source File

SOURCE=.\abc_14.bmp
# End Source File
# Begin Source File

SOURCE=.\res\asdfghjk.ico
# End Source File
# Begin Source File

SOURCE=.\res\asdfghjk.rc2
# End Source File
# Begin Source File

SOURCE=.\res\bitmap3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\bitmap4.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
