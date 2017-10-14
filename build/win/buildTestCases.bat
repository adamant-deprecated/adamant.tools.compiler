REM this builds the test-cases expected values to make sure they are valid C++
cls
@rmdir /S/Q ..\..\target\test-cases
mkdir "..\..\target\test-cases"
for %%C in (..\..\test-cases\*.cpp) do clang++ "%%C" ..\..\src\RuntimeLibrary.cpp --include-directory ..\..\src -o "..\..\target\test-cases\%%~nC.exe" -std=c++14 -Xclang -flto-visibility-public-std
clang++ ..\..\test-cases\resources\Resources.cpp ..\..\src\RuntimeLibrary.cpp --include-directory ..\..\src -o "..\..\target\test-cases\Resources.exe" -std=c++14 -Xclang -flto-visibility-public-std