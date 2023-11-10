cmake_minimum_required(VERSION 3.5)

project(lab_2)

find_package(OpenGL REQUIRED)
set(OpenGL_GL_PREFERENCE "LEGACY")

include_directories( ${OPENGL_INCLUDE_DIRS} )

# set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
# set( GLFW_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory(glfw)

set(SOURCE main.cpp)
     
add_executable(${PROJECT_NAME} ${SOURCE} )
target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw )