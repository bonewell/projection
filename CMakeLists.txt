cmake_minimum_required(VERSION 3.5)

project(projection LANGUAGES CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_executable(${PROJECT_NAME}
    main.cpp
    polyline.cpp
    projection.cpp
    vector.cpp
)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

enable_testing()

set(UNIT_TEST ${PROJECT_NAME}_unittest)
add_executable(${UNIT_TEST}
    polyline.cpp
    projection.cpp
    projection_test.cpp
    vector.cpp
    vector_test.cpp
)
target_compile_features(${UNIT_TEST} PRIVATE cxx_std_17)
target_link_libraries(${UNIT_TEST}
  CONAN_PKG::gtest
)
add_test(NAME ${UNIT_TEST} COMMAND ${UNIT_TEST})
