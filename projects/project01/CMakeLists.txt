include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

# Don't forget to add CsrMatrix.cpp here and the new ConjugateGradient class
add_executable(project-01-solution project-01-solution.cpp
               Vector.cpp
               DenseMatrix.cpp
               CsrMatrix.cpp
               Laplacian2DMatrixGenerator.cpp
               WallClock.cpp
               ConjugateGradient.cpp)
