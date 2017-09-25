REM This builds the compiler and runs it on the test-cases to test compiler output
CALL build.bat
for %%E in (test-cases\*.ad) do (
	target\Program.exe %%E translated\text-cases\%%~nE
)