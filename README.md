ProgrammingConcepts
===================

Programming Concepts in Scientific Computing


Command line instructions:
--------------------------

1) first time:

$ cd ./build/opt

$ ./do-configure.sh

2) for every new source:
modify CMakeLists.txt in belonging directory: add line;
add_executable(executable_name source_name.cpp)

from root of repo run:

$ make all


Git pulling
-----------

commit (last time)

git pull --rebase origin_deparis

get rid of conflicts

save, add to index, commit

push
