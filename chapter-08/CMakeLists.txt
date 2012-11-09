include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

add_executable(exercise_8_1 exercise_8_1.cpp)
add_executable(exercise_8_2 exercise_8_2.cpp)
add_executable(exercise_8_3 exercise_8_3.cpp exercise3/ComplexNumber.cpp)

add_executable(ch-08-ex-01-solution ch-08-ex-01-solution.cpp)
add_executable(ch-08-ex-02-solution ch-08-ex-02-solution.cpp)
add_executable(ch-08-ex-03-solution ch-08-ex-03-solution.cpp ComplexNumber.cpp)
add_executable(ch-08-ex-04-solution ch-08-ex-04-solution.cpp Point2d.cpp)
