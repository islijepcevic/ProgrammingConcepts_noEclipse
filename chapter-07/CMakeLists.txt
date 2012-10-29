include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# The next lines represent a list of all the executables in the folder (chapter)
# There is typically one executable per exercise.
# As you solve exercises, you need to add them here.
# The syntax is add_executable(executable_name source_file_name)

add_executable(exercise_7_1 exercise_7_1.cpp exercise1/student.cpp exercise1/graduate_student.cpp exercise1/phd_student.cpp)

add_executable(abstract_person exercise2/abstract_person.cpp)

#add_executable(abstract_person_nopublic exercise2/abstract_person_nopublic.cpp) 
# COMPILE ERROR (AND NEEDS TO BE TO SHOW THE PRINCIPLE OF PRIVATE INHERITANCE)

add_executable(abstract_person_novirtual exercise2/abstract_person_novirtual)
add_executable(abstract_person_instance exercise2/abstract_person_instance)

#add_executable(abstract_person_pure_novirtual exercise2/abstract_person_pure_novirtual) # error expected

#add_executable(abstract_person_abstract_instance exercise2/abstract_person_abstract_instance) # expected error

#add_executable(exercise_7_3 exercise_7_3.cpp)
