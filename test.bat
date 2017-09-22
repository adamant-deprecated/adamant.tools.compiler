REM this needs cleaned up with a for loop and not overwriting the expected values
CALL build.bat
target\Program.exe tests\Empty.ad
target\Program.exe tests\Return0.ad
target\Program.exe tests\Return42.ad