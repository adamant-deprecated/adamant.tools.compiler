mkdir "target\test-cases"
for %%C in (Bootstrap.Test\test-cases\*.cpp) do (
	echo %%C
	clang "%%C" -o "target\test-cases\%%~nC.exe"
)
