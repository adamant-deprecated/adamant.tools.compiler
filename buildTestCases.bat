REM this builds the test-cases expected values to make sure they are valid C++
cls
mkdir "target\test-cases"
for %%C in (test-cases\*.cpp) do clang "%%C" --include-directory src -o "target\test-cases\%%~nC.exe"
