include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(quadrature_test quadrature_test.cpp
                MidpointRule.cpp SimpsonRule.cpp)

add_executable(composite_test composite_test.cpp
        MidpointRule.cpp SimpsonRule.cpp
        CompositeIntegrator.cpp IntegrationGrid.cpp)
