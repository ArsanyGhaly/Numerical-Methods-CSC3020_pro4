@echo off
cls

set DRIVE_LETTER=c:
set PATH=%DRIVE_LETTER%\TDM-GCC-64\bin;%DRIVE_LETTER%\TDM-GCC-64\wxWidgets-3.0.2\lib;c:\windows
set PROJECT_PATH=.

mingw32-make DRIVE_LETTER="%DRIVE_LETTER%" PROJECT_PATH="%PROJECT_PATH%"

Sailboat
::diffusion