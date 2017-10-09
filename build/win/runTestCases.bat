REM this builds and runs the test cases expected values
CALL buildTestCases.bat
setlocal enabledelayedexpansion
for %%E in (..\..\target\test-cases\*.exe) do (
	%%E
	echo Exit Code is !errorlevel!
)
