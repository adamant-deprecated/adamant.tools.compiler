cls
mkdir "target\test-cases"
for %%C in (test-cases\*.cpp) do clang "%%C" --include-directory src -o "target\test-cases\%%~nC.exe"
