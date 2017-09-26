REM this builds the current version, then uses it on itself
CALL build.bat
rmdir /S/Q target\current
mkdir target\current
target\current\Program.exe src\Program.ad translated\current\Program.cpp
xcopy src\runtime.* translated\current /Y
clang translated\current\Program.cpp -o target\current\Program.exe