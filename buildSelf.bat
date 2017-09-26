REM this builds the current version, then uses it on itself
CALL build.bat
target\current\Program.exe src\Program.ad translated\current\Program.cpp
xcopy src\runtime.cpp translated\current /Y
clang translated\current\Program.cpp -o target\current\Program.exe