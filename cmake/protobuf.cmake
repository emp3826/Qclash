find_package(Protobuf REQUIRED)
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${CMAKE_SOURCE_DIR}/assets/geosite.proto)
set(QCLASH_PROTOBUF_LIBRARY
    protobuf::libprotobuf
    )
