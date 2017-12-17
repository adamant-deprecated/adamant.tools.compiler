REM this builds the current version, then uses it on itself
@CALL buildCurrent.bat

@pushd ..\..\

@echo.
@echo ************************
@echo Building Bootstrapped
@echo ************************
@mkdir translated\bootstrapped
target\current\Program.exe %source_files% -o translated\bootstrapped\Program.cpp -r src\RuntimeLibrary.cpp -r src\RuntimeLibrary.h
@rmdir /S/Q target\bootstrapped
@mkdir target\bootstrapped
@echo Compiling...
@clang++ translated\bootstrapped\*.cpp -o target\bootstrapped\Program.exe -std=c++14 -Xclang -flto-visibility-public-std

@popd