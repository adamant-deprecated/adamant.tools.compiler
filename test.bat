REM This builds the compiler and runs it on the test-cases to test compiler output
CALL build.bat
rmdir /S/Q translated\test-cases
mkdir translated\test-cases
for %%E in (test-cases\*.ad) do (
	target\current\Program.exe %%E translated\test-cases\%%~nE.cpp
)