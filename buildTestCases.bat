mkdir "target\test-cases"
cls
for %%C in (test-cases\*.cpp) do clang "%%C" -o "target\test-cases\%%~nC.exe"
