include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

add_executable(exercise_9_2 exercise_9_2.cpp)
add_executable(exercise_9_3 exercise_9_3.cpp
                data_types/Probability.cpp)
