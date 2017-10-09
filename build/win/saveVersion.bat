REM This script saves off the current translated code so that we can have a stable version while we are working
rmdir /S/Q ..\..\translated\previous
mkdir "..\..\translated\previous"
xcopy ..\..\translated\current ..\..\translated\previous