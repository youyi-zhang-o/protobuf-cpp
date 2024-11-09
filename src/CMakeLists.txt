# 添加源文件
set(SOURCE_FILES
    main.cpp
)
# 链接到你的目标
# 可执行文件链接到 proto 文件库
add_executable(MyExecutable ${SOURCE_FILES})
# message(FATAL_ERROR ${Protobuf_LIBRARIES})
target_link_libraries(MyExecutable proto_files)