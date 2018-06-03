from git import Repo
from SCons.Script import *
import os

repo = Repo('.')

def building_commit_hash(target, source, env):
    # Checks if there are any modified uncommited files or untracked files
    if repo.head.commit.diff(None) or repo.untracked_files:
        print '  Uncommitted changes, NO current commit'
        commit_hash = "<none>"
    else:
        print '  NO uncommitted changes, building current commit'
        commit_hash = repo.head.commit.hexsha

    for file in target: # Passed as a list of SCons.Node.FS.File
        with open(str(file), "w") as f:
            f.write(commit_hash)
    return None

def parent_commit_hash(target, source, env):
    current_commit_hash = sha_hash = source[0].get_contents()
    if current_commit_hash == "<none>":
        parent_commit = repo.head.commit
    else:
        parent_commit = repo.commit(current_commit_hash).parents[0] # TODO What if this is a merge commit?

    for file in target: # Passed as a list of SCons.Node.FS.File
        with open(str(file), "w") as f:
            f.write(parent_commit.hexsha)
    return None

def clone_translated(target, source, env):
    path = str(target[0])
    try:
        Repo(path).git_dir
    except:
        Repo.clone_from('https://github.com/adamant/adamant.tools.compiler.translated.git', path)
    return None

def checkout_previous_translated(target, source, env):
    sha_hash = source[0].get_contents()
    print '  Starting from '+sha_hash
    source_repo = Repo(str(source[1]))
    source_repo.git.fetch('--tags')
    source_commit = repo.commit(sha_hash)
    while True:
        try:
            tag = source_repo.tag('refs/tags/translated/'+source_commit.hexsha)
            break
        except ValueError:
            print ' No source for commit ' + source_commit.hexsha
            source_commit = source_commit.parents[0] # TODO What if this is a merge commit?

    print '  Checking out ' + tag.commit.hexsha
    source_repo.head.reference = tag.commit
    source_repo.head.reset(index=True, working_tree=True)
    for file in target: # Passed as a list of SCons.Node.FS.File
        with open(str(file), "w") as f:
            f.write(tag.commit.hexsha)
    return None


def PhonyTarget(target, action):
        phony = Environment(ENV = os.environ,
                            BUILDERS = { 'phony' : Builder(action = action) })
        AlwaysBuild(phony.phony(target = target, source = 'SConstruct'))
