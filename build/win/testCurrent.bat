REM This builds the compiler and runs it on the test-cases to test compiler output
CALL buildCurrent.bat

@echo.
@echo ************************
@echo Testing Current (compile test-cases with current)
rmdir /S/Q ..\..\translated\test-cases
@mkdir ..\..\translated\test-cases
for %%E in (..\..\test-cases\*.ad) do (
	..\..\target\current\Program.exe %%E ..\..\translated\test-cases\%%~nE.cpp
)