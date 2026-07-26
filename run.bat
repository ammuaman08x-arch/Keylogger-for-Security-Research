@echo off
echo ============================================================
echo   Keylogger for Security Research - Launcher
echo ============================================================
echo.

if not exist "build\Release\KeyloggerSecurityResearch.exe" (
    echo [*] Executable not found. Running automated build script first...
    call build.bat
    if %errorlevel% neq 0 (
        echo [ERROR] Build failed. Cannot launch application.
        pause
        exit /b 1
    )
)

echo [*] Launching Keylogger Security Research Tool...
echo.
".\build\Release\KeyloggerSecurityResearch.exe"
pause
