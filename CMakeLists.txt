
cmake_minimum_required(VERSION 3.20.0)

project(strad-engine LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(RAD_SRC main.cxx logic.cxx includes/game.cxx includes/vector2d.cxx 
includes/InputHandler.cxx includes/TextureManager.cxx)

if(WIN32 AND MSVC)
	find_package(SDL2 CONFIG REQUIRED)
    find_package(sdl2-image CONFIG REQUIRED)
	add_executable(${CMAKE_PROJECT_NAME} ${RAD_SRC})

	target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_image)
endif(WIN32 AND MSVC)
