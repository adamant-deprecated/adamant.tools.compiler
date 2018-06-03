from build.functions import *
import os

env = Environment(tools = ['clang', 'default'],
        CCFLAGS = '-std=c11')
# env = Environment(tools = ['clang'],
#             CCFLAGS = '-std=c11')
            # I don't get SCons path shit, just use the shell path
            # ENV = {'PATH' : os.environ['PATH']})

PhonyTarget('force-clean', Delete(Dir('target'))) # TODO doesn't fully delete the repo

building_commit = Command('target/building-commit.sha1', [], building_commit_hash)
AlwaysBuild(building_commit)

parent_commit = Command('target/parent-commit.sha1', building_commit, parent_commit_hash)

translated_repo = Command(Dir('target/translated-repo'), [], clone_translated)

checkout_translated = Command('target/checkout-commit.sha1', [parent_commit, translated_repo], checkout_previous_translated)
AlwaysBuild(checkout_translated)

VariantDir('target/previous', 'target/translated-repo')

previous = env.Program('target/previous/adamantc',
        Glob("target/previous/translated/current/*.c"))
Requires(previous, checkout_translated)

# Install(Dir('target/previous'),
#         Glob("target/translated-repo/translated/current/*.c")
#         + Glob("target/translated-repo/translated/current/*.c"))

build = Alias('build', previous)
Default(build)

# VariantDir('target/bin/previous/bootstrap', 'src/bootstrap',  duplicate=0)
# VariantDir('target/bin/previous/runtime', 'src/runtime',  duplicate=0)

# env = Environment(CC = 'clang', CCFLAGS = '-std=c11')

# runtime_lib = StaticLibrary('target/bin/previous/runtime/runtime',
#                             Glob('target/bin/previous/runtime/*.c'))
# Program('target/bin/previous/bootstrap/adamantc',
#         Glob('target/bin/previous/bootstrap/*.c')
#         + Glob('target/bin/previous/bootstrap/core/*.c')
#         + Glob('target/bin/previous/bootstrap/std/*.c')
#         + Glob('target/bin/previous/bootstrap/syntax/*.c'),
#         CPPPATH = ['target/bin/previous/runtime',
#             'target/bin/previous/bootstrap/core',
#             'target/bin/previous/bootstrap/std',
#             'target/bin/previous/bootstrap/syntax',
#             ],
#         LIBS=runtime_lib)
