# 设置 proto 文件
set(PROTO_FILES
    person.proto
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_FILES})

add_library(proto_files ${PROTO_SRCS} ${PROTO_HDRS})

get_filename_component(PROTO_INCLUDE_DIR ${PROTO_HDRS} DIRECTORY)
target_include_directories(proto_files INTERFACE ${PROTO_INCLUDE_DIR})
find_package(absl REQUIRED CONFIG)
target_link_libraries(proto_files
    ${Protobuf_LIBRARIES}
    absl::log_internal_check_impl 
)
