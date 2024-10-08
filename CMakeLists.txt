cmake_minimum_required(VERSION  3.13 FATAL_ERROR)

set(PROJECT_NAME Bayes)

project(${PROJECT_NAME})

add_executable(
    ${PROJECT_NAME} main.cpp
    Renderer/ShaderProgram.cpp
    Renderer/ShaderProgram.h
    Renderer/Texture2D.cpp
    Renderer/Texture2D.h
    
    Resourses/stb_image.h
    Resourses/ResourseManager.cpp
    Resourses/ResourseManager.h

)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

add_subdirectory(external/glfw)

target_link_libraries(${PROJECT_NAME} glfw)


add_subdirectory(external/glad)

target_link_libraries(${PROJECT_NAME} glad)


add_subdirectory(external/glm)

target_link_libraries(${PROJECT_NAME} glm)


set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:${PROJECT_NAME}>/res)