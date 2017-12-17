REM this builds the previous version and uses it to build the current version
cls

@pushd ..\..\

@echo Deleting translated
@rmdir /S/Q translated

@echo Rebuilding Previous
@REM This reads the last commit hash into a variable
@for /f "delims=" %%A in ('git rev-parse HEAD') do @set "commitHash=%%A"
@echo Using %commitHash% for previous source
@git checkout translated/%commitHash% -- translated
@echo Moving current to previous
@move translated\current translated\previous
@rmdir /S/Q target\previous
@mkdir target\previous
@echo Compiling...
@clang++ translated\previous\*.cpp -o target\previous\Program.exe -std=c++14 -Xclang -flto-visibility-public-std

@echo.
@echo ************************
@echo Building Current
@echo ************************
@REM there is no current directory at this point
@mkdir translated\current
@set source_files=
@for /f "tokens=*" %%F in ('dir /b /S "src\*.ad"') do @call set source_files=%%source_files%% "%%F"
target\previous\Program.exe %source_files% -o translated\current\Program.cpp -r src\RuntimeLibrary.cpp -r src\RuntimeLibrary.h
@rmdir /S/Q target\current
@mkdir target\current
@echo Compiling...
@clang++ translated\current\*.cpp -o target\current\Program.exe -std=c++14 -Xclang -flto-visibility-public-std

@popd