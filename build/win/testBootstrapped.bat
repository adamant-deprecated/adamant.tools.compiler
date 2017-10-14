REM This builds the compiler and runs it on the test-cases to test compiler output
CALL buildBootstrapped.bat

@echo.
@echo ************************
@echo Testing Current (compile test-cases with current)
rmdir /S/Q ..\..\translated\test-cases
@mkdir ..\..\translated\test-cases\resources
for %%E in (..\..\test-cases\*.ad) do (
	..\..\target\bootstrapped\Program.exe %%E -o ..\..\translated\test-cases\%%~nE.cpp
)
..\..\target\bootstrapped\Program.exe ..\..\test-cases\resources\Resources.ad -r ..\..\test-cases\resources\Hello.rsrc -r ..\..\test-cases\resources\World.rsrc -o ..\..\translated\test-cases\resources\Resources.cpp
