CMAKE_MINIMUM_REQUIRED(VERSION 3.22 FATAL_ERROR)

project(shop-server)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 20)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

include(${CMAKE_SOURCE_DIR}/build/Crow/lib/cmake/Crow/CrowConfig.cmake)

add_executable(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC Crow::Crow)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

