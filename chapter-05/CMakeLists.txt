include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

add_executable(ch-05-FunctionOverloading ch-05-FunctionOverloading.cpp)
add_executable(ch-05-ex-01-solution ch-05-ex-01-solution.cpp)
add_executable(ch-05-ex-02-solution ch-05-ex-02-solution.cpp)
add_executable(ch-05-ex-03-solution ch-05-ex-03-solution.cpp)
add_executable(ch-05-ex-04-solution ch-05-ex-04-solution.cpp)
add_executable(ch-05-ex-05-solution ch-05-ex-05-solution.cpp ArrayUtil.cpp)
add_executable(ch-05-ex-06-solution ch-05-ex-06-solution.cpp ArrayUtil.cpp)
add_executable(ch-05-ex-07-solution ch-05-ex-07-solution.cpp ArrayUtil.cpp)
add_executable(ch-05-ex-08-solution ch-05-ex-08-solution.cpp ArrayUtil.cpp)
add_executable(ch-05-ex-10-solution ch-05-ex-10-solution.cpp ArrayUtil.cpp Gauss.cpp)

file(COPY A.dat B.dat v1.dat v2.dat M1.dat M2.dat Agauss.dat bgauss.dat
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
