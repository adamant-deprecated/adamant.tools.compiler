REM this builds the previous version and uses it to build the current version
cls
rmdir /S/Q target\previous
mkdir target\previous
clang translated\previous\Program.cpp -o target\previous\Program.exe
rmdir /S/Q translated\current
mkdir translated\current
xcopy src\runtime.* translated\current /Y
target\previous\Program.exe src\Program.ad translated\current\Program.cpp
rmdir /S/Q target\current
mkdir target\current
clang translated\current\Program.cpp -o target\current\Program.exe