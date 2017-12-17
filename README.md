# Adamant Compiler

A compiler for the [Adamant language](http://adamant-lang.org) that is in the process of being bootstrapped. The compiler currently compiles a small subset of the Adamant language to C++.  It is capable of compiling itself and a small test suite.  Additional language features are being implemented and the compiler code refactored to take advantages of them.

## Project Status: Alpha Active

The compiler is under active development. It is in a very early stage, and there are likely issues and limitations. APIs are subject to frequent breaking changes.

## Implementation Notes

The list of the currently [implemented language features](docs/ImplementedLanguageFeatures.md) can be found in the docs directory.

## Contributing

Fork the project and then clone the repository.  Submit changes as a pull request.  Language features should have a test in the test suite for them.

The compiler translates into code that is compiled using the [clang++ compiler](https://clang.llvm.org) version 5.0.  Older versions of the compiler may work, but this is not being tested and may change.  It should build on both Windows and Linux, but the Linux builds are not tested very often.

Please read all of this section, particularly about the development cycle before attempting to contribute.

### Bootstrapping Structure

Because the Adamant compiler is being bootstrapped, there are multiple versions of the compiler that must be dealt with at any given time.  This can be confusing at first if one is not used to thinking about the bootstrapping process.  Many of the directories contain subdirectories for each version of the compiler.  The four versions of the compiler are:

  * **previous**:  the previous version of the compiler is used as a stable development environment for the next version of the compiler.
  * **current**: the version of the compiler being developed at any given time *as compiled by the previous version of the compiler*.
  * **bootstrapped**: to ensure that the current version doesn't introduce any breaking issues, it is used to recompile its own source.  The version produced is the bootstrapped version.
  * **double-bootstrapped**: to avoid some very unusual edge cases, the compiler is recompiled using the bootstrapped version to make sure that the same output is produced.

### Directory Structure

  * **src**: the source code of the compiler
  * **target**: where executable binaries are placed.  Contains a directory for each version of the compiler as well as a directory for the compiled test cases.
  * **test-cases**: contains Adamant code files representing test cases for the compiler functionality and matching C++ code files that are the expected output of the compiler for the given input.
  * **translated**: where the Adamant code that has been compiled to C++ is placed before compiling to binary.  Contains a directory for each version of the compiler and for the test cases.

### Build and Test Scripts

The following scripts are available at the in the appropriate `build/<os>` directory:

  * **buildCurrent**: puts the C++ code of the previous version into `translated\previous` then uses that executable to compile the compiler source in `src` to C++ in the `translated\current` directory and compiles it to an executable.
  * **buildBootstrapped**: first runs `buildCurrent`, then uses the executable of the current version produced by `buildCurrent` to compile the source in `src` to C++ in the `translated\bootstrapped` directory and compile it to an executable.
  * **buildDoubleBootstrapped**: first runs `buildBootstrapped`, then uses the executable of the bootstrapped version produced by `buildBootstrapped` to compile the source in `src` to C++ in the `translated\double-bootstrapped` directory and compile it to an executable.  Checks that the translated code of bootstrapped and double bootstrapped are identical.
  * **buildTestCases**: compiles the C++ code representing the expected result of the test cases to ensure it is valid C++.
  * **runTestCases**: first runs `buildTestCases`, then executes all the test case executables with no arguments and reports the return code.  *Note that many test cases intentionally return non-zero return codes*.
  * **testCurrent**: first runs `buildCurrent`, then uses the current version executable to compile all the test cases to C++ in the `translated\test-cases` directory.
  * **testBootstrapped**: first runs `buildBootstrapped`, then uses the bootstrapped version executable to compile all the test cases to C++ in the `translated\test-cases` directory.

###  Development Cycle

Since the compiler is being bootstrapped, the versions of the compiler discussed above must be managed.  Additionally, to avoid issues with trying distributing binaries of the compiler for each commit, the C++ for each version is committed on a separate branch in the repository.  This enables someone to clone the repository, compile the C++ code and begin development.  When you commit, you will need to push that commit up to github so that the CI server can build it and check in the matching C++ code before you will be able to build again.  Additionally, you will need to fetch tags by running `git fetch --tags` to get the built C++ code.

Several directories are intentionally not committed and are in the `.gitignore` file.  These are:

  * target
  * translated