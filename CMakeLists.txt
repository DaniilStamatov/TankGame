cmake_minimum_required(VERSION 3.10) 

project(TanksGame)

set(CMAKE_CXX_STANDARD 23)
# GLM
add_subdirectory(vendor/glm)

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(vendor/glfw)

# GLAD
add_library(glad STATIC vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

file(GLOB_RECURSE SOURCE_FILES 
src/engine/core/*.cc src/engine/core/*.h
src/game/entities/*.cc src/game/entities/*.h
src/*.cc src/*.h)
add_executable(TanksGame ${SOURCE_FILES})
target_link_libraries(TanksGame glm::glm glfw glad)

target_include_directories(TanksGame PRIVATE
    vendor/glm
    vendor/glad/include
)