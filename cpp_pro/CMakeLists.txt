# cmake最低版本要求
cmake_minimum_required(VERSION 3.0)
# 工程名
project(cpp_pro)
# c++标准
set(CMAKE_CXX_STANDARD 11)

# 设置使得可以看见细致的编译选项
set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_COLOR_MAKEFILE on)

# CMAKE_CURRENT_SOURCE_DIR 是当前处理的 CMakeLists.txt 所在的路径
set(ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(COMMON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(COMMON_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libsrc)
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 编译选项 可以通过 cmake .. -DBUILD_UNIT_TEST=ON 来打开
option(BUILD_UNIT_TEST "Build unit test" OFF)

# CMAKE_C_FLAGS	设置 C 编译选项 也可以通过指令 ADD_DEFINITIONS() 添加
# CMAKE_CXX_FLAGS 设置 C++编译选项 也可以通过指令 ADD_DEFINITIONS() 添加
if(BUILD_UNIT_TEST)
    # add_compile_options(--coverage)
    # set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage -lgcov")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c++11 -lgtest -lgtest_main -lpthread -fprofile-arcs -ftest-coverage -lgcov")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lgtest -lgtest_main -lpthread -fprofile-arcs -ftest-coverage -lgcov")
endif()

# include_directories 将指定目录添加到编译器的.h文件搜索路径之下
# 相当于 g++ 选项中的 -I 参数的作用
# include_directories放到这里，保证公共库大家都能用到
include_directories(${COMMON_INCLUDE_DIR})

# add_subdirectory() 添加一个文件夹进行编译，该文件夹下的 CMakeLists.txt 负责编译该文件夹下的源码
add_subdirectory(src)
add_subdirectory(libsrc)
