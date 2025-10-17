@echo off

:: Get the directory where this batch file is located
set "BASEDIR=%~dp0"
set "BINDIR=%BASEDIR%bin\"

echo Starting build
echo.

:: Create bin folder if it doesn't exist
if not exist "%BINDIR%" (
    mkdir "%BINDIR%"
)

:: Run fasm32.exe from the fasmdll64 folder in the same directory
"%BASEDIR%fasmdll64\fasm32.exe" "%BASEDIR%main.asm"
echo.

:: Delete 010Keygen.exe in bin if it already exists
if exist "%BINDIR%010Keygen.exe" (
    del "%BINDIR%010Keygen.exe"
)

:: Move/rename the output executable to the bin folder
if exist "%BASEDIR%main.exe" (
    echo Moving build exe to bin folder
    echo.
    move "%BASEDIR%main.exe" "%BINDIR%010Keygen.exe" > NUL
)

echo Build completed
echo.
pause
::exit
