import argparse

def run_target():
    parser = argparse.ArgumentParser(description='A make like build system')
    parser.add_argument('targets', nargs='*',
                    help='the target(s) to build')
    # TODO add --watch argument that starts watching the target afterward
    args = parser.parse_args()
    print('Build Target {0}'.format(args.targets))


