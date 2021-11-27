cmake_minimum_required(VERSION 2.8.4)

file(GLOB_RECURSE COMMON_SOURCES *.cpp *.cxx *.cc)

# 将指定的源文件生成链接文件，然后添加到工程
# 添加动态库，关键词为shared，名字为lib_common_dynamic.so
add_library(lib_common_dynamic SHARED ${COMMON_SOURCES})
# 添加静态库，关键词为static，名字为lib_common_static.a
add_library(lib_common_static STATIC ${COMMON_SOURCES})

# 按照一般的习惯，静态库名字跟动态库名字应该是一致的，只是扩展名不同；
# 即：静态库名为 lib_common.a； lib_common.so ；
# 所以，希望在输出时，不是"lib_common_dynamic"，而是以"lib_common"的名字显示，故设置如下
set_target_properties(lib_common_dynamic PROPERTIES OUTPUT_NAME "lib_common")

# 按照规则，动态库是应该包含一个版本号的
# VERSION指代动态库版本，SOVERSION指代API版本。
set_target_properties(lib_common_dynamic PROPERTIES VERSION 1.2 SOVERSION 1)
# 希望在输出时，不是"lib_common_static"，而是以"lib_common"的名字显示，故设置如下
set_target_properties(lib_common_static PROPERTIES OUTPUT_NAME "lib_common")

# install(TARGETS MyLib
#         LIBRARY DESTINATION lib  # 动态库安装路径
#         ARCHIVE DESTINATION lib  # 静态库安装路径
#         RUNTIME DESTINATION bin  # 可执行文件安装路径
#         PUBLIC_HEADER DESTINATION include  # 头文件安装路径
#         )
# LIBRARY, ARCHIVE, RUNTIME, PUBLIC_HEADER是可选的，可以根据需要进行选择。
# DESTINATION后面的路径可以自行制定，根目录默认为CMAKE_INSTALL_PREFIX，可以试用set方法进行指定，
# 如果使用默认值的话，Unix系统的默认值为 /usr/local
# 比如linux系统下若LIBRARY的安装路径指定为lib，即为/usr/local/lib。

set(CMAKE_INSTALL_PREFIX ${ROOT_DIR})
install(TARGETS lib_common_static lib_common_dynamic
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
# # 这里可以把include_common.cpp 拷贝到 ${CMAKE_INSTALL_PREFIX}/tmp
# # 这里对于我们来说没必要，因为.h文件已经在include里面了，这里仅作为例子，因此直接注释了
# install(FILES include_common.cpp DESTINATION tmp)