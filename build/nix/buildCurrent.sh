#!/bin/bash
# This script builds the previous version and uses it to build the current version
clear

pushd ../../

echo 'Deleting translated'
rm -rf translated/

echo 'Rebuilding Previous'
# This reads the last commit hash into a variable
commitHash=$(git rev-parse HEAD)
echo 'Using $commitHash for previous source'
git checkout translated/$commitHash -- translated
echo 'Moving current to previous'
mv translated/current translated/previous
#!/bin/bash

# The "target" directory is used for compiled versions of the program
mkdir -p target/previous
rm -rf target/previous/*
# Build the old program into target/previous
echo 'Compiling...'
clang++ translated/previous/*.cpp -o target/previous/Program -std=c++14

echo ''
echo '*************************'
echo 'Compiling Current'
echo '************************'
# The "translated" directory is where we store working versions of the program
# Empty the "current" directory so we can fill it with the new build
mkdir -p translated/current
rm -rf translated/current/*
source_files=`ls -d src/*.ad src/**/*.ad`
# Use the previous version of the compiler to compile the new version into translated/current
target/previous/Program $source_files -o translated/current/Program.cpp -r src/RuntimeLibrary.cpp -r src/RuntimeLibrary.h

# Build the new program into target/current for testing
mkdir -p target/current
rm -rf target/current/*
clang++ translated/current/*.cpp -o target/current/Program -std=c++14
# We're done building! Now off to test that the program works!

popd