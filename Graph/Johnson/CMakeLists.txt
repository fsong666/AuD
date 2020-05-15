cmake_minimum_required(VERSION 2.8)
set(PROJNAME tests)
project(${PROJNAME} LANGUAGES  CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_SOURCE_DIR ./)

project(${PROJNAME} CXX)
aux_source_directory(. SRCS)
aux_source_directory(../Dijkstra/dijk OTHER_SRCS)

INCLUDE_DIRECTORIES( 
    ../include/
    ../Dijkstra/dijk/
)
add_compile_options(
	-std=c++11
	-O0
	-g
	-pedantic
#	-Wall
	-Wextra
	-Werror
#	-Wno-unused-function
)


add_executable(${PROJNAME} ${SRCS} ${OTHER_SRCS})