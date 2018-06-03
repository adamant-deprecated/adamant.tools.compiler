import os, shutil, stat
from datetime import datetime
import pathlib
from termcolor import colored

def clean_directory(path):
    for the_file in os.listdir(path):
        file_path = os.path.join(path, the_file)
        try:
            if os.path.isfile(file_path):
                os.unlink(file_path)
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path, onerror = on_rm_error)
        except Exception as e:
            print(e)

def on_rm_error(func, path, exc_info):
    # path contains the path of the file that couldn't be removed
    # let's just assume that it's read-only and unlink it.
    os.chmod(path, stat.S_IWRITE)
    os.unlink(path)

def ensure_directory_exists(path):
    pathlib.Path(path).mkdir(parents=True, exist_ok=True)

def start_step(name):
    return Step(name)

def end_step(step):
    return print(colored('{} took (hh:mm:ss.ms) {} '.format(step.name, datetime.now() - step.start), 'green'))

class Step:
    def __init__(self, name):
        self.name = name
        self.start = datetime.now()
        print('Starting {0}...'.format(name))
