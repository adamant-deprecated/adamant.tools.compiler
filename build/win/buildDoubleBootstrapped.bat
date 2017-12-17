REM this builds the current version, then uses it on itself
@CALL buildBootstrapped.bat

@pushd ..\..\

@echo.
@echo ************************
@echo Building Double Bootstrapped
@echo ************************
@mkdir translated\double-bootstrapped
target\bootstrapped\Program.exe %source_files% -o translated\double-bootstrapped\Program.cpp -r src\RuntimeLibrary.cpp -r src\RuntimeLibrary.h
@rmdir /S/Q target\double-bootstrapped
@mkdir target\double-bootstrapped
@echo Compiling...
@clang++ translated\double-bootstrapped\*.cpp -o target\double-bootstrapped\Program.exe -std=c++14 -Xclang -flto-visibility-public-std

@echo.
@echo ************************
@echo Comparing Bootstrapped and Double Bootstrapped
@echo ************************
@comp translated\bootstrapped translated\double-bootstrapped

@popd