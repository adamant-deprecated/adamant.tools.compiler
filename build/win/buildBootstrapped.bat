REM this builds the current version, then uses it on itself
CALL buildCurrent.bat

@echo.
@echo ************************
@echo Building Bootstrapped
rmdir /S/Q ..\..\translated\bootstrapped
@mkdir ..\..\translated\bootstrapped
..\..\target\current\Program.exe ..\..\src\Program.ad ..\..\translated\bootstrapped\Program.cpp
xcopy ..\..\src\runtime.* ..\..\translated\bootstrapped /Y
rmdir /S/Q ..\..\target\bootstrapped
@mkdir ..\..\target\bootstrapped
clang++ ..\..\translated\bootstrapped\*.cpp -o ..\..\target\bootstrapped\Program.exe -std=c++14