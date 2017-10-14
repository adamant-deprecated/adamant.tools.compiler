REM this builds the previous version and uses it to build the current version
cls
@echo ************************
@echo Rebuilding Previous
rmdir /S/Q ..\..\target\previous
@mkdir ..\..\target\previous

clang++ ..\..\translated\previous\*.cpp -o ..\..\target\previous\Program.exe -std=c++14 -Xclang -flto-visibility-public-std

@echo.
@echo ************************
@echo Building Current
rmdir /S/Q ..\..\translated\current
@mkdir ..\..\translated\current
@set source_files=
@for /f "tokens=*" %%F in ('dir /b /S "..\..\src\*.ad"') do @call set source_files=%%source_files%% "%%F"
..\..\target\previous\Program.exe %source_files% -o ..\..\translated\current\Program.cpp -r ..\..\src\RuntimeLibrary.cpp -r ..\..\src\RuntimeLibrary.h
rmdir /S/Q ..\..\target\current
@mkdir ..\..\target\current
clang++ ..\..\translated\current\*.cpp -o ..\..\target\current\Program.exe -std=c++14 -Xclang -flto-visibility-public-std
