@echo off
setlocal enabledelayedexpansion

echo ============================================================
echo   Keylogger for Security Research - Automated Build Script
echo ============================================================
echo.

set "CMAKE_BIN="

REM 1. Check if cmake is available in system PATH
where cmake >nul 2>nul
if %errorlevel% equ 0 (
    set "CMAKE_BIN=cmake"
    goto :FOUND_CMAKE
)

REM 2. Search common Visual Studio install paths
set "VS_SEARCH_PATHS[0]=C:\Program Files\Microsoft Visual Studio\18\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "VS_SEARCH_PATHS[1]=C:\Program Files\Microsoft Visual Studio\2022\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "VS_SEARCH_PATHS[2]=C:\Program Files\Microsoft Visual Studio\2022\Professional\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "VS_SEARCH_PATHS[3]=C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"
set "VS_SEARCH_PATHS[4]=C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\CommonExtensions\Microsoft\CMake\CMake\bin\cmake.exe"

for /L %%i in (0,1,4) do (
    if exist "!VS_SEARCH_PATHS[%%i]!" (
        set "CMAKE_BIN=!VS_SEARCH_PATHS[%%i]!"
        goto :FOUND_CMAKE
    )
)

:FOUND_CMAKE
if "%CMAKE_BIN%"=="" (
    echo [ERROR] CMake executable could not be found automatically.
    echo Please install CMake or Visual Studio C++ workload.
    pause
    exit /b 1
)

echo [*] Using CMake at: "%CMAKE_BIN%"
echo [*] Configuring project build files...
echo.

"%CMAKE_BIN%" -B build -S .
if %errorlevel% neq 0 (
    echo.
    echo [ERROR] CMake configuration failed.
    pause
    exit /b %errorlevel%
)

echo.
echo [*] Building project (Release Configuration)...
echo.

"%CMAKE_BIN%" --build build --config Release
if %errorlevel% neq 0 (
    echo.
    echo [ERROR] Build failed.
    pause
    exit /b %errorlevel%
)

echo.
echo ============================================================
echo [SUCCESS] Build completed successfully!
echo [OUTPUT] Executable: .\build\Release\KeyloggerSecurityResearch.exe
echo ============================================================
echo.
pause
