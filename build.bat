REM this builds the previous version and uses it to build the current version
cls
rmdir /S/Q target\previous
mkdir target\previous
clang++ translated\previous\*.cpp -o target\previous\Program.exe -std=c++14
rmdir /S/Q translated\current
mkdir translated\current
xcopy src\runtime.* translated\current /Y
target\previous\Program.exe src\Program.ad translated\current\Program.cpp
rmdir /S/Q target\current
mkdir target\current
clang++ translated\current\*.cpp -o target\current\Program.exe -std=c++14
