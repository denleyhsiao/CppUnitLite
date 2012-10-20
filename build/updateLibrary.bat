@echo off

set LIB_PATH=..\lib

if not exist %LIB_PATH% md %LIB_PATH%

copy Debug\CppUnitLite.lib %LIB_PATH%\CppUnitLiteD.lib
copy Release\CppUnitLite.lib %LIB_PATH%\CppUnitLite.lib
@echo on
