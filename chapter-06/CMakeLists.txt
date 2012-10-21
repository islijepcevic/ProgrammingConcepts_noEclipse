include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

add_executable(ch-06-ex-01-solution ch-06-ex-01-solution.cpp
               ComplexMatrix3x3.cpp ComplexNumber.cpp)
add_executable(ch-06-ex-02-solution ch-06-ex-02-solution.cpp
               DoubleMatrix2x2.cpp)
add_executable(test_complex_numbers test_complex_numbers.cpp
               ComplexNumber.cpp)
               