cmake_minimum_required(VERSION 3.10)

project(Climaft)

add_executable(
    Climaft
    src/main.cpp
    src/mesh.cpp
    deps/glad/src/glad.c
)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Build the GLFW example programs" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Build the GLFW test programs" FORCE)
set(GLFW_INSTALL OFF "Generate installation target" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "Build example apps" FORCE)

add_subdirectory(deps/glfw)
include_directories(deps/glfw/include)
include_directories(deps/glad/include)
include_directories(deps/glm)

target_link_libraries(Climaft opengl32)

target_link_libraries(Climaft glfw ${GLFW_LIBRARIES})

add_custom_command(TARGET Climaft POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Climaft>/res)