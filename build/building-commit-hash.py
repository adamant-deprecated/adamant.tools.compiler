#!/usr/local/bin/python3

import argparse
from git import Repo

def main():
    parser = argparse.ArgumentParser(description='get the commit hash currently being built')
    parser.add_argument('output')
    args = parser.parse_args()
    output_path = args.output
    repo = Repo('.')
    if repo.head.commit.diff(None) or repo.untracked_files:
        print('  Uncommitted changes, NO current commit')
        commit_hash = "<none>"
    else:
        print('  NO uncommitted changes, building current commit')
        commit_hash = repo.head.commit.hexsha

    with open(output_path, "w") as f:
        f.write(commit_hash)


if __name__ == "__main__":
    main()
