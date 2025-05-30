@echo off
setlocal enabledelayedexpansion

set BUILD_CMD=g++ -std=c++17 -o main.exe -Iinclude -Iunit_test -g main.cpp src\bellman.cpp unit_test\unit_test.cpp 

for %%f in (unit_test\testcase\*.cpp) do (
    set BUILD_CMD=!BUILD_CMD! %%f
)

echo Building project bellman VOTIEN with command:
echo %BUILD_CMD%
echo ----------------------------------------

%BUILD_CMD%
if %ERRORLEVEL% EQU 0 (
    echo Build successful!
    echo ----------------------------------------
    echo To run tests, use one of the following commands:
    echo 1. Run all tests: main.exe
    echo 2. Run a specific test: main.exe nameFunctionUnitTest
) else (
    echo Build failed!
    exit /b 1
)

