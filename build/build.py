#!/usr/bin/python3

import sys

if (sys.version_info < (3, 0)):
    print('Python Verion >=3.0 required')
    exit(1)

import colorama, argparse
from termcolor import colored
from make import start_step
from build_steps import *

colorama.init()

def main():
    parser = argparse.ArgumentParser(description='A make like build system')
    parser.add_argument('targets', nargs='*',
                    help='the target(s) to build')
    # TODO add --watch argument that starts watching the target afterward
    args = parser.parse_args()
    step = start_step('Total Build')
    if not args.targets:
        args.targets.append('build')
    for target in args.targets:
        print(colored('Building target: {0}'.format(target), 'blue'))
        if target == 'build':
            build()
        elif target == 'build-previous':
            build_previous()
        elif target == 'clean':
            clean()
        else:
            print(colored('Unknown build target "{0}"'.format(target), 'red'))
    end_step(step)

if __name__ == "__main__":
    main()
