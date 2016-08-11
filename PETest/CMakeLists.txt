project( RusticValley) # this is case sensitive
 SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
 find_package(PkgConfig REQUIRED)
######################################
# finds OpenGL, GLU and X11
find_package(OpenGL REQUIRED)
if(NOT OPENGL_FOUND)
    message("ERROR: OpenGL not found")
endif(NOT OPENGL_FOUND)

pkg_search_module(OPENSSL REQUIRED openssl)
if( OPENSSL_FOUND )
    include_directories(${OPENSSL_INCLUDE_DIRS})
    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
endif()


set(GL_LIBRARY GL GLU X11)
include_directories(kal ${GLIB_INCLUDE_DIR} ${GLIBCONFIG_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../../ParalyzedEngine/)
LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../ParalyzedEngine/ParalyzedEngine/build/)
add_executable(RusticValley main.cpp)
target_link_libraries(RusticValley ${OPENSSL_LIBRARIES} ${GL_LIBRARY} ${GLIB_LIBRARIES}   ParalyzedEngine  X11 GL GLU )