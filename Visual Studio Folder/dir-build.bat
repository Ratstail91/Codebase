@ECHO OFF

REM Written on Windows 7

REM This batch file builds the library directory from *.h and *.cpp, which is a convenience, not a necessity
REM Simply call this script

REM parameter list:
REM %0 $(SolutionDir)dir-build


REM -------------------------
REM Rebuild the directory

RMDIR /S /Q "%~p0Release\Codebase Library\"

MKDIR "%~p0Release\Codebase Library\include\"
MKDIR "%~p0Release\Codebase Library\lib\"
MKDIR "%~p0Release\Codebase Library\Scene Framework\"


REM -------------------------
REM Copy the library

XCOPY "%~p0Library\*.h" "%~p0Release\Codebase Library\include\" /D /S /Y /I
MOVE /Y "%~p0Release\cb.lib" "%~p0Release\Codebase Library\lib\"


REM -------------------------
REM Copy the framework

XCOPY "%~p0Scene Framework\*.h" "%~p0Release\Codebase Library\Scene Framework\" /D /S /Y /I
XCOPY "%~p0Scene Framework\*.cpp" "%~p0Release\Codebase Library\Scene Framework\" /D /S /Y /I
XCOPY "%~p0Scene Framework\*.lua" "%~p0Release\Codebase Library\Scene Framework\" /D /S /Y /I


