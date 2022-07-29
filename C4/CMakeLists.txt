cmake_minimum_required(VERSION 3.22)
project(C4)

set(CMAKE_CXX_STANDARD 11)

# 获取cpp文件相对于当前工作路径的相对路径，即文件名
# 工作路径${CMAKE_CURRENT_SOURCE_DIR}就是CMakeList.txt所在的文件夹
file(GLOB files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)
# 遍历每个文件名#
# hello
foreach (ff ${files})
    # 将去掉后缀的文件名存入exe变量（executable的缩写，不是代表.exe）
    string(REGEX REPLACE "(.+).cpp$" "\\1" exe ${ff})
    # 分别生成add_executable(<name> <source>)命令
    add_executable(${exe} ${ff} )
endforeach ()
