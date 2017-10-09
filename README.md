# Adamant Compiler

A compiler for the [Adamant language](http://adamant-lang.org) that is in the process of being bootstrapped. The compiler currently compiles a small subset of the Adamant language to C++.  It is capable of compiling itself and a small test suite.  Additional language features are being implemented and the compiler code refactored to take advantages of them.

## Project Status: Alpha Active

The compiler is under active development. It is in a very early stage, and there are likely issues and limitations. APIs are subject to frequent breaking changes.

## Implementation Notes

The list of the currently [implemented language features](docs/ImplementedLanguageFeatures.md) can be found in the docs directory.

## Contributing

Fork the project and then clone the repository.  Submit changes as a pull request.  Language features should have a test in the test suite for them.

The compiler translates into code that is compiled using the [clang++ compiler](https://clang.llvm.org) version 5.0.  Older versions of the compiler may work, but this is not being tested and may change.  Currently, the project only builds on Windows out of the box.

Please read all of this section, particularly about the development cycle before attempting to contribute.

### Bootstrapping Structure

Because the Adamant compiler is being bootstrapped, there are multiple versions of the compiler that must be dealt with at any given time.  This can be confusing at first if one is not used to thinking about the bootstrapping process.  Many of the directories contain subdirectories for each version of the compiler.  The three versions of the compiler are:

  * **previous**:  the previous version of the compiler is used as a stable development environment for the next version of the compiler.
  * **current**: the version of the compiler being developed at any given time *as compiled by the previous version of the compiler*.
  * **bootstrapped**: to ensure that the current version doesn't introduce any breaking issues, it is used to recompile its own source.  The version produced is the bootstrapped version.

### Directory Structure

  * **DebugCurrent**: a Visual Studio 2015 project that is sometimes used for debugging.  Visual studio is not necessary for development.
  * **src**: the source code of the compiler
  * **target**: where executable binaries are placed.  Contains a directory for each version of the compiler as well as a directory for the compiled test cases.
  * **test-cases**: contains Adamant code files representing test cases for the compiler functionality and matching C++ code files that are the expected output of the compiler for the given input.
  * **translated**: where the Adamant code that has been compiled to C++ is placed before compiling to binary.  Contains a directory for each version of the compiler and for the test cases.

### Build and Test Scripts

The following scripts are available at the root of the project:

  * **buildCurrent**: compiles the C++ code of the previous version in `translated\previous` then uses that executable to compile the compiler source in `src` to C++ in the `translated\current` directory and compiles it to an executable.
  * **buildBootstrapped**: first runs `buildCurrent`, then uses the executable of the current version produced by `buildCurrent` to compile the source in `src` to C++ in the `translated\bootstrapped` directory and compile it to an executable.
  * **buildTestCases**: compiles the C++ code representing the expected result of the test cases to ensure it is valid C++.
  * **runTestCases**: first runs `buildTestCases`, then executes all the test case executables with no arguments and reports the return code.  *Note that many test cases intentionally return non-zero return codes*.
  * **testCurrent**: first runs `buildCurrent`, then uses the current version executable to compile all the test cases to C++ in the `translated\test-cases` directory.
  * **testBootstrapped**: first runs `buildBootstrapped`, then uses the bootstrapped version executable to compile all the test cases to C++ in the `translated\test-cases` directory.
  * **saveVersion**: copies the contents of `translated\current` into `translated\previous` to prepare the workspace for working on the next version of the compiler.

###  Development Cycle

Since the compiler is being bootstrapped, the three versions of the compiler discussed above must be managed.  Additionally, to avoid issues with trying distributing binaries of the compiler for each commit, the C++ for each version is committed along with the Adamant code used to produce it.  This enables someone to clone the repository, compile the C++ code and begin development.  When working on a new commit, follow these steps:

  1. Have the repository cloned and not uncommitted changes.
  2. Run `saveVersion` to prepare to work on a new version of the compiler by copying the C++ code of the current version into the previous version directory.  `buildCurrent` should still run successfully.  It may be easiest to stage the modified previous version in git to avoid accidentally changing them further.
  3. Make the intended code changes in `src`, adding test cases as needed.
  4. Make sure that `buildCurrent`, `buildBootstrapped`, `testCurrent` and `testBootstrapped` all run without error.  Check that the test cases pass by diffing the `test-cases` directory expected files with the compiled filed in `translated\test-cases`.
  5. Before committing run `buildCurrent` to ensure that the `translated\current` directory truly contains the current version.
  6. Commit changes to the source and test cases as well as the changes to the `translated\previous` and `translated\current` files.

Several directories are intentionally not committed and are in the `.gitignore` file.  These are:

  * target
  * translated\bootstrapped
  * translated\test-cases