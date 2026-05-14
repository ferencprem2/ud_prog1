@echo off
setlocal

if "%CC%"=="" set CC=gcc
set CFLAGS=-O2 -Wall -Wextra -std=c99
set SRC=base.c
set TARGET=alap.exe

%CC% %CFLAGS% %SRC% -o %TARGET%
if errorlevel 1 (
    echo Build failed.
    exit /b 1
)
echo Built %TARGET%
