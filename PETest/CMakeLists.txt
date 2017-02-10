
cmake_minimum_required(VERSION 3.6)
project( PETest) # this is case sensitive
 SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x")
 find_package(PkgConfig REQUIRED)
######################################
# finds OpenGL, GLU and X11
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Freetype REQUIRED)
find_package(Lua REQUIRED)

SET(SOIL_NAMES SOIL Soil soil)
FIND_LIBRARY(SOIL_LIBRARY NAMES ${SOIL_NAMES} )
MARK_AS_ADVANCED( SOIL_LIBRARY SOIL_INCLUDE_DIR )
SET(SOIL_INCLUDE_DIRS "${SOIL_INCLUDE_DIR}")
SET(SOIL_LIBRARIES "${SOIL_LIBRARY}")

pkg_search_module(OPENSSL REQUIRED openssl)
if( OPENSSL_FOUND )
    include_directories(${OPENSSL_INCLUDE_DIRS})
    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
endif()

set(SOURCE
   ${SOURCE}
   ${CMAKE_CURRENT_SOURCE_DIR}/../../ParalyzedEngine/ParalyzedEngine/
   )
 
#Engine not in libs directory
include_directories( ${LUA_INCLUDE_DIRS} ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${SOIL_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIRS}  ${CMAKE_CURRENT_SOURCE_DIR}/../../ParalyzedEngine/)


#LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../../ParalyzedEngine/ParalyzedEngine/build/)
add_executable(${PROJECT_NAME} main.cpp camera.cpp GameObjects/Bush.cpp ${SOURCE}/ParalyzedEngine.c ${SOURCE}/Window.c  ${SOURCE}/SpriteRenderer.c  ${SOURCE}/Network/WebClient.c ${SOURCE}/Network/TCPClient.c ${SOURCE}/Shaders/ShaderProgram.c  ${SOURCE}/Texture.c ${SOURCE}/TextRenderer.c ${SOURCE}/PEDictionary.cpp ${SOURCE}/JSON/JSONParser.cpp ${SOURCE}/Map/Map.cpp ${SOURCE}/Model.cpp ${SOURCE}/Memory/PEalloc/PEalloc.cpp ${SOURCE}/GameObjects/PEProp.cpp ${SOURCE}/LUA/PELuaFunctions.cpp ${SOURCE}/GameObjects/PEGameObject.cpp)
 
 
target_link_libraries(${PROJECT_NAME}   X11 GLEW ${LUA_LIBRARY} ${SOIL_LIBRARY} ${OPENSSL_LIBRARIES} ${OPENGL_LIBRARIES} ${FREETYPE_LIBRARY})
