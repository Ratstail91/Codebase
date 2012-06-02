@ECHO OFF

REM I don't know how portible this is, but it was written on Windows 7

REM This batch file builds the library directory from *.h and *.cpp, which is a convenience, not a necessity
REM Simply call this script; the Visual Studio solution calls this after the library is built

REM parameter list:
REM %0 $(SolutionDir)dir-build

RMDIR /S /Q "%~p0Release\Codebase Library\include\"
RMDIR /S /Q "%~p0Release\Codebase Library\Quick Start\"

XCOPY "%~p0Codebase Library\*.h" "%~p0Release\Codebase Library\include\" /D /S /Y /I
XCOPY "%~p0Quick Start\*.h" "%~p0Release\Codebase Library\Quick Start\" /D /S /Y /I
XCOPY "%~p0Quick Start\*.cpp" "%~p0Release\Codebase Library\Quick Start\" /D /S /Y /I
