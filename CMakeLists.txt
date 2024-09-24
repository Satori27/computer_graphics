cmake_minimum_required(VERSION  3.13 FATAL_ERROR)

set(PROJECT_NAME Bayes)

project(${PROJECT_NAME})

add_executable(
    ${PROJECT_NAME} main.cpp
    Renderer/ShaderProgram.cpp
    Renderer/ShaderProgram.h
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME} glfw)


add_subdirectory(external/glad)

target_link_libraries(${PROJECT_NAME} glad)