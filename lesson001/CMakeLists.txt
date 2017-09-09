cmake_minimum_required(VERSION 2.8)
project(hello_opengl)

#####################################################
# GLUT
#####################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
	message(ERROR, "GLUT is not found.")
endif(NOT GLUT_FOUND)

#####################################################
# OPEN GL
#####################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
	message(ERROR "OpenGL is not found")
endif(NOT OPENGL_FOUND)

add_executable(hello_opengl appMain.cpp)

target_link_libraries(hello_opengl 
	${OPENGL_LIBRARIES}
	${GLUT_LIBRARY})
	
