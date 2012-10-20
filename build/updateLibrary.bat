@echo off

set LIB_PATH=..\lib

if not exist %LIB_PATH% md %LIB_PATH%

if exist Debug\CppUnitLite.lib copy Debug\CppUnitLite.lib %LIB_PATH%\CppUnitLiteD.lib
if exist Release\CppUnitLite.lib copy Release\CppUnitLite.lib %LIB_PATH%\CppUnitLite.lib
@echo on
