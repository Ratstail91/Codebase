@ECHO OFF

REM Written on Windows 7

REM This batch file builds the library directory from *.h and *.cpp, which is a convenience, not a necessity
REM Simply call this script

REM parameter list:
REM %0 $(SolutionDir)dir-build


RMDIR /S /Q "%~p0Release\Codebase Library\"


REM Copy the framework

XCOPY "%~p0Scene Framework\*.h" "%~p0Release\Codebase Library\Scene Framework\" /D /S /Y /I
XCOPY "%~p0Scene Framework\*.cpp" "%~p0Release\Codebase Library\Scene Framework\" /D /S /Y /I
XCOPY "%~p0Scene Framework\*.lua" "%~p0Release\Codebase Library\Scene Framework\" /D /S /Y /I


