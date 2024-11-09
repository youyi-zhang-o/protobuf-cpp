# 设置 CMake 最低版本
cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(MyProtoProject VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.0")
# 查找 protobuf
find_package(Protobuf REQUIRED)
# 在CMakeLists.txt顶部

include_directories(${Protobuf_INCLUDE_DIRS})

# 添加 proto 和 src 子目录
add_subdirectory(proto)
add_subdirectory(src)