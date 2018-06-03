#!/usr/bin/python3

import sys

if (sys.version_info < (3, 0)):
    print('Python Verion >=3.0 required')
    exit(1)

from make import *



if __name__ == "__main__":
    run_target()
