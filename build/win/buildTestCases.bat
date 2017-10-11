REM this builds the test-cases expected values to make sure they are valid C++
cls
@rmdir /S/Q ..\..\target\test-cases
mkdir "..\..\target\test-cases"
for %%C in (..\..\test-cases\*.cpp) do clang++ "%%C" ..\..\src\runtime.cpp --include-directory ..\..\src -o "..\..\target\test-cases\%%~nC.exe" -std=c++14
