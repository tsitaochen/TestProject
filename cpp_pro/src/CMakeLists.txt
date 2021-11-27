project(test_main)
# file(GLOB variable [RELATIVE path] [globbingexpressions]...)
# GLOB_RECURSE 会向下搜索产生一个由所有匹配globbing表达式的文件组成的列表，并将其保存到变量variable中
file(GLOB_RECURSE SOURCES *.cpp *.cxx *.cc)
# 使用指定的源文件来生成目标可执行文件
add_executable(${PROJECT_NAME} ${SOURCES})
# 这里放只有这里需要的include
include_directories(${SOURCE_DIR}/include)
# 设置要链接的库文件的名称
target_link_libraries(${PROJECT_NAME} PRIVATE lib_common_dynamic)
# 动态和静态的都可以链接
# target_link_libraries(${PROJECT_NAME} PRIVATE lib_common_static)