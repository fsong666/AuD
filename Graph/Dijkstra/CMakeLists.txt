# “Write once, run everywhere”
cmake_minimum_required (VERSION 2.8)
# Target names reserved by one or more CMake generators are not allowed.
# Among others these include “all”, “help” and “test”. 不能使用 test,all,help作为目标名字
SET( PROJNAME myTest)
SET( SRC_LIST test.cpp)
project (${PROJNAME} CXX)

add_compile_options(
    -std=c++11
    -O0
    -g
    -pedantic
    -Wall
    -Wextra
    -Werror
    -Wno-unused-function
)

# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)
INCLUDE_DIRECTORIES( 
	../include/
)

add_subdirectory(dijk)

# PATH 是 CMakeLists.txt 
# ~/dir$ cmake PATH 会在dir目录下生成MakeFile 
add_executable(${PROJNAME} ${SRC_LIST})

target_link_libraries(${PROJNAME} DIJK)
