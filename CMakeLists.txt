cmake_minimum_required(VERSION 3.10) 
project(TanksGame)
option(BUILD_TESTS "Build tests" OFF)
set(CMAKE_CXX_STANDARD 23)

# ======================
# Dependencies
# ======================

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

# STB Image
add_library(stb STATIC vendor/stbi/stb_image.cpp)
target_include_directories(stb PUBLIC vendor/stbi)


# ======================
# Game executable
# ======================

file(GLOB_RECURSE SOURCE_FILES 
    src/engine/core/*.cc src/engine/core/*.h
    src/engine/scene/*.cc src/engine/scene/*.h
    src/game/entities/*.cc src/game/entities/*.h
    src/engine/graphics/OpenGL/*.cc src/engine/graphics/OpenGL/*.h
    src/*.cc src/*.h
)

add_executable(TanksGame ${SOURCE_FILES})
target_link_libraries(TanksGame PRIVATE glm::glm glfw glad stb)
target_include_directories(TanksGame PRIVATE
    vendor/glm
    vendor/glad/include
    vendor/entt/include
    vendor/stbi
)

# ======================
# Tests
# ======================

if(BUILD_TESTS)

    # GoogleTest
    include(FetchContent)
    FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/refs/heads/main.zip
    )
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)
    enable_testing()

    file(GLOB TEST_FILES tests/*.cc)
    file(GLOB_RECURSE ENGINE_FILES
        src/engine/core/*.cc src/engine/core/*.h
        src/engine/scene/*.cc src/engine/scene/*.h
        src/game/entities/*.cc src/game/entities/*.h
        src/engine/graphics/*.cc
    )
    add_executable(TanksTests ${TEST_FILES} ${ENGINE_FILES})
    target_link_libraries(TanksTests
        PRIVATE
        glm::glm
        glfw
        glad
        stb  # Добавьте stb и для тестов
        gtest
        gtest_main
    )
    target_include_directories(TanksTests PRIVATE
        src
        vendor/glm
        vendor/glad/include
        vendor/entt/include
        vendor/stbi  # Добавьте stbi и для тестов
    )

    include(GoogleTest)
    gtest_discover_tests(TanksTests)
endif()