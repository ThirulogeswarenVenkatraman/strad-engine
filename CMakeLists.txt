
cmake_minimum_required(VERSION 3.20.0)

project(SEngine LANGUAGES CXX)

# dependencies deps/includes
include_directories(${CMAKE_SOURCE_DIR}/deps/includes)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if(WIN32)

	add_executable(${PROJECT_NAME} Vector2d.cxx TextureManager.cxx InputHandler.cxx game.cxx main.cxx)

	target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/deps/libs)
	target_link_libraries(${PROJECT_NAME} SDL2main.lib SDL2.lib SDL2_image.lib)

endif(WIN32)
