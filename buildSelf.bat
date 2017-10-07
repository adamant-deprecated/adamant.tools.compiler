REM this builds the current version, then uses it on itself
CALL build.bat
rmdir /S/Q translated\current
mkdir translated\current
target\current\Program.exe src\Program.ad translated\current\Program.cpp
xcopy src\runtime.* translated\current /Y
clang++ translated\current\*.cpp -o target\current\Program.exe -std=c++14