#addin nuget:?package=Cake.Git&version=0.16.1
#addin nuget:?package=Cake.FileHelpers&version=2.0.0

// Fix up the working directory to be the root of the project even though we are in build\
System.IO.Directory.SetCurrentDirectory(System.IO.Path.GetDirectoryName(System.IO.Directory.GetCurrentDirectory()));

var target = Argument("target", "Build");
var testName = Argument<string>("test", null);
string currentCommit = null;
string sourceCommit = null;

// Clean is used only by the rebuild steps, otherwise each thing cleans itself
Task("Clean")
    .Does(() =>
    {
        CleanDirectory("translated");
        CleanDirectory("target");
    });

Task("Source-Commit")
    .Does(() =>
    {
        var hasUncommitedChanges = Command("git", "status --porcelain=v2").Read().Any();
        int generation;
        if(hasUncommitedChanges)
        {
            Information("Uncommitted changes, using current commit source");
            currentCommit = null; // There is no commit for the uncommitted changes
            sourceCommit = GitRevParse("HEAD");
            Information("Source commit is {0}", sourceCommit);
            generation = 1;
        }
        else
        {
            Information("NO uncommitted changes, using parent commit source");
            currentCommit = GitRevParse("HEAD");
            Information("Current commit is {0}", currentCommit);
            sourceCommit = GitRevParse("HEAD~1");
            Information("Source commit is {0}", sourceCommit);
            generation = 2;
        }

        var sourceExists = GitTagExists("translated/" + sourceCommit);
        if(!sourceExists)
        {
            Warning("No source for commit. Searching ancestors.");
            var found = false;
            for(; generation < 100; generation++)
            {
                sourceCommit = GitRevParse("HEAD~" + generation);
                if(GitTagExists("translated/" + sourceCommit))
                {
                    Warning("Found source for HEAD~{0} {1}", generation, sourceCommit);
                    found = true;
                    break;
                }
            }
            if(!found)
            {
                Error("No source for previous");
                throw new Exception("Couldn't find source to use for Build-Previous of the compiler");
            }
        }
    });

Task("Build-Previous")
    .IsDependentOn("Source-Commit")
    .WithCriteria(() => IsOutOfDate("target/previous/Program", sourceCommit))
    .Does(() =>
    {
        // Delete this directory becuase we are going to move to it
        if(DirectoryExists("translated/previous"))
            DeleteDirectory("translated/previous", new DeleteDirectorySettings()
            {
                Recursive = true,
                Force = true,
            });
        CleanDirectory("target/previous");

        // When we pull the C source from the other branch, it is in these
        // directories so we have to clean them out.
        CleanDirectory("translated/current");
        CleanDirectory("target/current");

        Information("Getting source for previous");
        Verbose("Checking out translated from previous source branch"); // Git commands don't have verbose output
        GitCheckout(".", "translated/" + sourceCommit, new FilePath[] { "translated" });
        // Git checkout stages the changes, we don't want that
        Verbose("Unstaging files staged by checkout"); // Git commands don't have verbose output
        GitUnstage(".", new FilePath[] { "translated" });
        MoveDirectory("translated/current", "translated/previous");

        Information("Compiling previous C");
        EnsureDirectoryExists("target/previous");
        CompileC("translated/previous/*.c", "target/previous/Program").Run();
        SaveVersionInfo("target/previous/Program", sourceCommit);
    });

Task("Build-Current")
    .IsDependentOn("Build-Previous")
    .Does(() =>
    {
        CleanDirectory("translated/current");
        CleanDirectory("target/current");

        Information("Compiling Adamant to C");
        EnsureDirectoryExists("translated/current");
        CompileAdamant("previous", "current").Run();

        Information("Compiling current C");
        EnsureDirectoryExists("target/current");
        CompileC("translated/current/*.c", "target/current/Program").Run();
    });

Task("Unit-Test-Current")
    .IsDependentOn("Build-Current")
    .Does(() =>
    {
        UnitTest("current");
    });

Task("Test-Current")
    .IsDependentOn("Build-Current")
    .Does(() =>
    {
        Test("current");
    });

Task("Build-Bootstrapped")
    .IsDependentOn("Build-Current")
    .Does(() =>
    {
        CleanDirectory("translated/bootstrapped");
        CleanDirectory("target/bootstrapped");

        Information("Compiling Adamant to C");
        EnsureDirectoryExists("translated/bootstrapped");
        CompileAdamant("current", "bootstrapped").Run();

        Information("Compiling bootstrapped C");
        EnsureDirectoryExists("target/bootstrapped");
        CompileC("translated/bootstrapped/*.c", "target/bootstrapped/Program").Run();
    });

Task("Unit-Test-Bootstrapped")
    .IsDependentOn("Build-Bootstrapped")
    .Does(() =>
    {
        UnitTest("bootstrapped");
    });

Task("Test-Bootstrapped")
    .IsDependentOn("Build-Bootstrapped")
    .Does(() =>
    {
        Test("bootstrapped");
    });

Task("Build-Double-Bootstrapped")
    .IsDependentOn("Build-Bootstrapped")
    .Does(() =>
    {
        CleanDirectory("translated/double-bootstrapped");
        CleanDirectory("target/double-bootstrapped");

        Information("Compiling Adamant to C");
        EnsureDirectoryExists("translated/double-bootstrapped");
        CompileAdamant("bootstrapped", "double-bootstrapped").Run();

        Information("Compiling double-bootstrapped C");
        EnsureDirectoryExists("target/double-bootstrapped");
        CompileC("translated/double-bootstrapped/*.c", "target/double-bootstrapped/Program").Run();

        Information("Verifying bootstrapped and double-bootstrapped are equal");
        var bootstrappedFiles = GetFiles("translated/bootstrapped/**/*");
        var bootstrappedDir = MakeAbsolute(Directory("translated/bootstrapped"));
        foreach(var bootstrappedFile in bootstrappedFiles)
        {
            var relativeBootstrappedFile = bootstrappedDir.GetRelativePath(bootstrappedFile);
            var expected = Directory("translated/bootstrapped") + relativeBootstrappedFile;
            var actual = Directory("translated/double-bootstrapped") + relativeBootstrappedFile;
            Verbose("Checking {0} matches {1}", expected, actual);
            if(FileReadText(expected) != FileReadText(actual))
            {
                Error("Double bootstrapped version does not match bootstrapped.");
                Error(" {0}", actual);
                throw new Exception("Double boostrapping failed");
            }
        }
    });

Task("Unit-Test-Double-Bootstrapped")
    .IsDependentOn("Build-Double-Bootstrapped")
    .Does(() =>
    {
        UnitTest("double-bootstrapped");
    });

Task("Test-Double-Bootstrapped")
    .IsDependentOn("Build-Double-Bootstrapped")
    .Does(() =>
    {
        Test("double-bootstrapped");
    });

// Builds all the expected values of the test cases
Task("Build-Expected")
    .Does(() =>
    {
        CleanDirectory("target/test-cases");

        var wd = MakeAbsolute(Directory("."));
        var testCases = GetFiles("test-cases/**/*.c").ToList();
        if(testName != null)
            testCases = testCases.Where(c => c.FullPath.Contains(testName)).ToList();
        Information("Found {0} Test Case Expected Outputs", testCases.Count);
        foreach(var testCase in testCases)
        {
            var relativePath = wd.GetRelativePath(testCase);
            var outputDir = Directory("target") + relativePath.GetDirectory();
            EnsureDirectoryExists(outputDir);
            var output = outputDir + relativePath.GetFilenameWithoutExtension();
            CompileC(new []{ relativePath.ToString(), "src/*.c" }, output, "src").Run();
        }
        Information("Compiled {0} Test Case Expected Outputs", testCases.Count);
    });

// Runs all the expected values of the test cases and checks the output
Task("Test-Expected")
    .IsDependentOn("Build-Expected")
    .Does(() =>
    {
        var wd = MakeAbsolute(Directory("."));
        var testCases = GetFiles("target/test-cases/**/*")
                        // We need to exclude lib files etc, but on linux, the exe has no extension
                        .Where(path => !path.HasExtension || path.GetExtension() == ".exe")
                        .ToList();
        var testCasesDir = Directory("test-cases");
        var targetTestCasesDir = MakeAbsolute(Directory("target/test-cases"));
        Information("Found {0} Test Cases to Execute", testCases.Count);
        var failed = 0;
        foreach(var testCase in testCases)
        {
            var program = wd.GetRelativePath(testCase);
            var actual = Command(program).Test();
            actual.WriteFile(program.ChangeExtension(".run.txt"));

            var expectedFile = (testCasesDir + targetTestCasesDir.GetRelativePath(testCase)).Path.ChangeExtension(".run.txt");
            var expected = FileExists(expectedFile) ? ReadResultFile(expectedFile) : DefaultResult();

            if(TestResult(program, expected, actual))
                failed++;
            else
                Verbose("  {0} [PASS]", program);
        }

        Information("=== RUN SUMMARY ===");
        Information("  Total: {0}, Failed: {1}", testCases.Count, failed);
        if(failed > 0)
            throw new Exception("Run-Expected Failed");
    });

// This is the default task
Task("Build")
    .IsDependentOn("Build-Current")
    .IsDependentOn("Unit-Test-Current")
    .IsDependentOn("Test-Current")
    .IsDependentOn("Build-Bootstrapped")
    .IsDependentOn("Unit-Test-Bootstrapped")
    .IsDependentOn("Test-Bootstrapped");

// Force clean and build
Task("Rebuild")
    .IsDependentOn("Clean")
    .IsDependentOn("Build");

Task("All")
    .IsDependentOn("Unit-Test-Current")
    .IsDependentOn("Test-Current")
    .IsDependentOn("Test-Expected")
    .IsDependentOn("Unit-Test-Bootstrapped")
    .IsDependentOn("Test-Bootstrapped")
    .IsDependentOn("Unit-Test-Double-Bootstrapped")
    .IsDependentOn("Test-Double-Bootstrapped");

Task("Rebuild-All")
    .IsDependentOn("Clean")
    .IsDependentOn("All");

Task("Commit-Translated")
    // technically, this is all that is needed,
    // really though, you should run All as CI does
    .IsDependentOn("Build-Current")
    .Does(() =>
    {
        if(currentCommit == null)
        {
            Error("Building uncommitted changes, can't commit translated");
            throw new Exception("Uncommitted changes");
        }

        if(AppVeyor.IsRunningOnAppVeyor)
        {
            if(AppVeyor.Environment.PullRequest.IsPullRequest)
            {
                Warning("Not committing translated code becuase this is a pull request build.");
                return;
            }
            if(AppVeyor.Environment.Repository.Branch != "master")
            {
                Warning("Not committing translated code becuase this is not the master branch.");
                return;
            }
        }

        var deleteSettings = new DeleteDirectorySettings()
            {
                Recursive = true,
                Force = true,
            };

        Information("Saving off translated current");
        if(DirectoryExists("saved"))
            DeleteDirectory("saved", deleteSettings);
        MoveDirectory("translated/current", "saved");

        Information("Checking out previous source {0}", sourceCommit);
        GitCheckout(".", "translated/" + sourceCommit);

        Information("Restoring saved source");
        DeleteDirectory("translated/current", deleteSettings);
        MoveDirectory("saved", "translated/current");

        Information("Staging files");
        GitAdd(".", "translated/current");
        Command("git", "status --untracked-files=no").Run();

        Information("Commiting changes");
        var currentCommitMessage = GitLogLookup(".", currentCommit).Message;
        // Allow empty commits so we can make a properly named commit to match each commit
        var message = string.Format("Translated files for {0} '{1}'", currentCommit, currentCommitMessage);
        var messageLines = message.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.None);
        var messageOptions = string.Join(" ", messageLines.Select(line => string.Format("-m \"{0}\"", line)));
        Command("git", string.Format("commit {0} --allow-empty --untracked-files=no", messageOptions)).Run();

        var tag = "translated/"+currentCommit;
        if(GitTagExists(tag))
        {
            Warning("Tag {0} already exists, not modifying", tag);
        }
        else
        {
            Information("Applying tag {0}", tag);
            GitTag(".", tag);
        }

        if(AppVeyor.IsRunningOnAppVeyor)
        {
            Information("Pushing tag to server");
            // Have to use the command line because of authentication
            Command("git", "push origin " + tag).Run();
        }
        else
        {
            Warning("Skipping push of tag because not running in AppVeyor");
        }
    });

Task("CI")
    .IsDependentOn("Rebuild-All") // Be certian we are starting fresh
    .IsDependentOn("Commit-Translated");

/// This task provides commands to clean up translated/* tags that aren't needed
Task("Clean-Translated")
    .Does(() =>
    {
        Warning("Run 'git fetch --tags' first");
        var tags = GitTags(".")
            .Select(t => t.FriendlyName)
            .Where(t => t.StartsWith("translated/"))
            .ToList();
        Information("Found {0} translated tags", tags.Count);
        var prefixLength = "translated/".Length;
        var deleteTags = tags
            .Where(t => Command("git", string.Format("cat-file -e {0}^{{commit}}", t.Substring(prefixLength))).Test().ExitCode != 0)
            .ToList();
        Information("Found {0} tags to delete:", deleteTags.Count);
        foreach(var tag in deleteTags)
        {
            Information("    {0}", tag);
        }
        Information("Commands to delete and refetch 'translated/*'");
        foreach(var tag in deleteTags)
        {
            Warning("git push --delete origin {0}", tag);
        }
        Warning("git tag -l 'translated/*' | xargs git tag -d");
        Warning("git fetch -t");
    });

RunTarget(target);

void UnitTest(string version)
{
    var program = File(string.Format("target/{0}/Program", version)).Path;
    if(IsRunningOnWindows())
    {
        program = program.AppendExtension("exe");
    }
    Command(program, "--unit-test").Run();
}

void Test(string version)
{
    var outputDir = Directory(string.Format("translated/{0}-test-cases", version));
    CleanDirectory(outputDir);

    var compiler = string.Format("target/{0}/Program", version);
    var testCases = GetFiles("test-cases/**/*.ad").ToList();
    if(testName != null)
        testCases = testCases.Where(c => c.FullPath.Contains(testName)).ToList();
    var testCasesDir = MakeAbsolute(Directory("test-cases"));
    var failed = 0;
    foreach(var testCase in testCases)
    {
        var testCaseName = testCasesDir.GetRelativePath(testCase);
        var output = outputDir + testCaseName.ChangeExtension("c");
        EnsureDirectoryExists(output.Path.GetDirectory());
        var resources = GetFiles(testCase.GetDirectory().ToString() + "/*.rsrc");
        var actual = CompileAdamant(compiler, new [] { testCase }, output, resources).Test();
        actual.WriteFile(output.Path.ChangeExtension(".compile.txt"));

        var expectedFile = testCase.ChangeExtension(".compile.txt");
        var expected = FileExists(expectedFile) ? ReadResultFile(expectedFile) : DefaultResult();

        var expectedC = testCase.ChangeExtension(".c");
        var caseFailed = TestResult(testCaseName, expected, actual);

        if(!caseFailed && actual.ExitCode == 0)
        {
            if(!FileExists(output))
            {
                Error("  {0} [FAIL]", testCaseName);
                Information("    C output does not exist.");
                caseFailed = true;
            }
            else if(FileReadText(expectedC) != FileReadText(output))
            {
                Error("  {0} [FAIL]", testCaseName);
                Information("    C does not match expected.");
                caseFailed = true;
            }
        }

        if(caseFailed)
            failed++;
        else
            Verbose("  {0} [PASS]", testCaseName);
    }

    Information("=== TEST EXECUTION SUMMARY ===");
    Information("  Total: {0}, Failed: {1}", testCases.Count, failed);
    if(failed > 0)
        throw new Exception("Test cases failed for " + version);
}

bool TestResult(FilePath testCase, CommandResult expected, CommandResult actual)
{
    if(expected.ExitCode == actual.ExitCode
        && expected.Output.SequenceEqual(actual.Output)
        && expected.ErrorOutput.SequenceEqual(actual.ErrorOutput))
        return false;

    Error("  {0} [FAIL]", testCase.ToString());
    if(expected.ExitCode != actual.ExitCode)
        Information("    Exit code of {0} did not match expected value {1}", actual.ExitCode, expected.ExitCode);

    if(expected.Output.Count != actual.Output.Count)
    {
        Information("    {0} lines output did not match the {1} expected", actual.Output.Count, expected.Output.Count);
        Verbose("    Actual output:");
        for(var i=0; i < actual.Output.Count; i++)
            Verbose("    "+actual.Output[i]);
    }
    else
        for(var i = 0; i < actual.Output.Count; i++)
            if(expected.Output[i] != actual.Output[i])
            {
                Information("    Line {0} didn't match", i);
                Information("    Expected: {0}", expected.Output[i]);
                Information("    Actual:   {0}", actual.Output[i]);
            }
    if(expected.ErrorOutput.Count != actual.ErrorOutput.Count)
    {
        Information("    {0} error lines output did not match the {1} expected", actual.ErrorOutput.Count, expected.ErrorOutput.Count);
        Verbose("    Actual error output:");
        for(var i=0; i< actual.ErrorOutput.Count; i++)
            Verbose("    "+actual.ErrorOutput[i]);
    }
    else
        for(var i = 0; i < actual.ErrorOutput.Count; i++)
            if(expected.ErrorOutput[i] != actual.ErrorOutput[i])
            {
                Information("    Error Line {0} didn't match", i);
                Information("    Expected: {0}", expected.ErrorOutput[i]);
                Information("    Actual:   {0}", actual.ErrorOutput[i]);
            }
    return true;
}

ConsoleCommand CompileAdamant(string sourceVersion, string targetVersion)
{
    var compiler = string.Format("target/{0}/Program", sourceVersion);
    var sources = GetFiles("src/**/*.ad");
    var output = string.Format("translated/{0}/Program.c", targetVersion);
    var resources = new FilePath[] { "src/RuntimeLibrary.c", "src/RuntimeLibrary.h" };
    return CompileAdamant(compiler, sources, output, resources);
}

ConsoleCommand CompileAdamant(FilePath compiler, IEnumerable<FilePath> sources, FilePath output, IEnumerable<FilePath> resources)
{
    if(IsRunningOnWindows())
    {
        compiler = compiler.AppendExtension("exe");
    }
    // Make sure the paths are relative.  To handle either, we first make absolute then compute relative
    var wd = MakeAbsolute(Directory("."));
    var relativeSources = sources.Select(s => wd.GetRelativePath(MakeAbsolute(s)));
    var relativeResources = resources.Select(r => wd.GetRelativePath(MakeAbsolute(r)));
    return Command(compiler, string.Join(" ", relativeSources) + " -o " + output + string.Concat(relativeResources.Select(r => " -r " + r)));
}

ConsoleCommand CompileC(string sourceGlob, FilePath output, FilePath includeDirectory = null)
{
    return CompileC(new [] { sourceGlob }, output, includeDirectory);
}

ConsoleCommand CompileC(string[] sourceGlobs, FilePath output, FilePath includeDirectory = null)
{
    // Compiler Options Explained:
    // -std=c11 use the C 2011 standard (newest fully finalized)
    // -fsanitize=undefined -fsanitize=integer -fsanitize=nullability perform runtime checks for undefined and bad behavior
    // -Wall all warnings
    var options = " -std=c11 -fsanitize=undefined -fsanitize=integer -fsanitize=nullability -Wall -Wno-incompatible-pointer-types";

    // Additional options that can be useful:
    // -Werror treat warnings as errors
    // --analyze --analyzer-outputhtml run static analysis, may require hacking command line to remove -o option
    // -fsanitize=address perform runtime address safety checks
    // -fno-ms-extensions disable Microsoft extensions
    //  Note: With this, headers don't compile on windows, but it catches some errors that the standard
    //          says should be errors and are caught on linux.

    if(includeDirectory != null)
    {
        options += string.Format(" --include-directory \"{0}\"", includeDirectory);
    }
    if(IsRunningOnWindows())
    {
        output = output.AppendExtension("exe");
        // Don't remeber why the below option used to be needed, leaving it around for a while
        //options += " -Xclang -flto-visibility-public-std";
    }

    // Because wildcard expansion is handled by the shell on Linux and Cake StartProcess() always
    // sets UseShellExecute=false, we just expand the wildcards ourselves
    var wd = MakeAbsolute(Directory("."));
    var sources = string.Join(" ", sourceGlobs.SelectMany(glob => GetFiles(glob)).Select(file => wd.GetRelativePath(file)));

    return Command("clang", sources + " -o " + output + options);
}

bool IsOutOfDate(FilePath file, string commit)
{
    if(IsRunningOnWindows())
    {
        file = file.AppendExtension("exe");
    }

    Verbose("Checking if {0} matches commit {1}", file, commit);

    // No file, it is out of date
    if(!FileExists(file)) return true;
    Verbose(" File exists {0}", file);

    var versionFile = file.AppendExtension("version");

    // No info on the current version, assume out of date
    if(!FileExists(versionFile)) return true;
    Verbose(" Version file exists {0}", versionFile);

    // Read version info
    var lines = FileReadLines(versionFile);
    var versionHash = lines[0];
    var versionCommit = lines[1];

    // Version is for different commit, out of date
    if(versionCommit != commit) return true;
    Verbose(" Commits match {0}", commit);

    // If file hash doesn't match, its been modified, out of date
    var hash = CalculateFileHash(file, HashAlgorithm.MD5);
    if(versionHash != hash.ToHex()) return true;
    Verbose(" Hashes match {0}", versionHash);

    // The file is up to date and doesn't need rebuilt
    return false;
}

void SaveVersionInfo(FilePath file, string commit)
{
    if(IsRunningOnWindows())
    {
        file = file.AppendExtension("exe");
    }

    Verbose("Saving version info of {0}, commit {1}", file, commit);

    var versionFile = file.AppendExtension("version");
    var hash = CalculateFileHash(file, HashAlgorithm.MD5);
    var lines = new[] {hash.ToHex(), commit};
    FileWriteLines(versionFile, lines);
}

bool GitTagExists(string tag)
{
    try
    {
        Verbose("Checking if tag '{0}' exists", tag);
        GitDescribe(".", tag, false, GitDescribeStrategy.Tags, 0);
        return true; // if it succedes the tag exists
    }
    catch(LibGit2Sharp.NotFoundException)
    {
        // tag doesn't exist
        return false;
    }
}

string GitRevParse(string revision)
{
    return Command("git", string.Format("rev-parse \"{0}\"", revision)).Read().SingleOrDefault().ToLower();
}

// Command Library
// Separates the construction of command arguments from how we want to run the process

ConsoleCommand Command(FilePath command, string arguments)
{
    return new ConsoleCommand(Context, command, arguments);
}

ConsoleCommand Command(FilePath command)
{
    return new ConsoleCommand(Context, command, null);
}

public class ConsoleCommand
{
    private readonly ICakeContext context;
    public readonly FilePath Command;
    public readonly string Arguments;

    public ConsoleCommand(ICakeContext context, FilePath command, string arguments)
    {
        this.context = context;
        Command = command;
        Arguments = arguments;
    }

    // Run the command and report an error on failure
    public void Run()
    {
        context.Verbose(Command + " " + Arguments);
        var result = context.StartProcess(Command, Arguments);
        if(result != 0)
            throw new Exception(string.Format("\"{0}\" exited with result: {1}", Command, result));
    }

    // Run the command, return the output and report an error on failure
    public IEnumerable<string> Read()
    {
        context.Verbose("Read: " + Command + " " + Arguments);
        var process = context.StartAndReturnProcess(Command, new ProcessSettings()
            {
                Arguments = Arguments,
                RedirectStandardOutput = true,
            });
        process.WaitForExit();
        var result = process.GetExitCode();
        if(result != 0)
            throw new Exception("Exited with result: "+result);
        return process.GetStandardOutput();
    }

    // Run the command, return both the exit code and output
    public CommandResult Test()
    {
        context.Verbose("Test: " + Command + " " + Arguments);
        var process = context.StartAndReturnProcess(Command, new ProcessSettings()
            {
                Arguments = Arguments,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            });
        process.WaitForExit();
        return new CommandResult(context, process.GetExitCode(), process.GetStandardOutput(), process.GetStandardError());
    }
}

public class CommandResult
{
    private readonly ICakeContext context;
    public readonly int ExitCode;
    public readonly IReadOnlyList<string> Output;
    public readonly IReadOnlyList<string> ErrorOutput;

    public CommandResult(ICakeContext context, int exitCode, IEnumerable<string> output, IEnumerable<string> errorOutput)
    {
        this.context = context;
        ExitCode = exitCode;
        Output = output.ToList().AsReadOnly();
        ErrorOutput = errorOutput.ToList().AsReadOnly();
    }

    public void WriteFile(FilePath file)
    {
        var lines = new [] { ExitCode.ToString()}
            .Append(Output.Count.ToString())
            .Concat(Output);

        if(ErrorOutput.Any())
        {
            lines = lines
                .Append(ErrorOutput.Count.ToString())
                .Concat(ErrorOutput);
        }
        context.FileWriteLines(file, lines.ToArray());
    }
}

// Can't be a static field because we need access to `Context`
CommandResult DefaultResult()
{
    return new CommandResult(Context, 0, Enumerable.Empty<string>(), Enumerable.Empty<string>());
}

// Can't be a static method because we need access to `Context`
CommandResult ReadResultFile(FilePath file)
{
    Verbose("  Reading result file");
    var lines = FileReadLines(file);
    if(lines.Length < 2)
    {
        Error("{0} file should have at least 2 lines, has {1}", file, lines.Length);
        throw new Exception();
    }
    Verbose("    Reading exitCode");
    int exitCode = -1;
    if(!int.TryParse(lines[0], out exitCode))
    {
        Error("First line of {0} file '{1}' should be expected exit code", file, lines[0]);
        throw new Exception();
    }
    Verbose("    Reading outputLines");
    int outputLines = -1;
    if(!int.TryParse(lines[1], out outputLines))
    {
        Error("Second line of {0} file '{1}' should be number of output lines", file, lines[1]);
        throw new Exception();
    }
    Verbose("    Reading errorLines");
    var errorCountLine = 2+outputLines;
    int errorLines = 0;
    if(lines.Length > errorCountLine)
    {
        Verbose("    Has error lines");
        Verbose("      errorCountLine={0}", errorCountLine);
        Verbose("      lines.Length={0}", lines.Length);
        if(!int.TryParse(lines[errorCountLine], out errorLines))
        {
            Error("Line {0} of {1} file '{2}' should be number of error lines", errorCountLine, file, lines[errorCountLine]);
            throw new Exception();
        }
    }
    Verbose("    Returning Result");
    return new CommandResult(Context, exitCode, lines.Skip(2).Take(outputLines), lines.Skip(errorCountLine+1).Take(errorLines));
}
