if(NOT QCLASH_PLATFORM_LIBS_BIN_PREFIX)
    set(QCLASH_PLATFORM_LIBS_BIN_PREFIX ${QCLASH_PLATFORM_LIBS_PREFIX}/tools)
endif()

list(APPEND CMAKE_PROGRAM_PATH
    ${QCLASH_PLATFORM_LIBS_BIN_PREFIX}/
    ${QCLASH_PLATFORM_LIBS_BIN_PREFIX}/grpc/
    ${QCLASH_PLATFORM_LIBS_BIN_PREFIX}/protobuf/
    ${QCLASH_PLATFORM_LIBS_BIN_PREFIX}/openssl/
    )

message("CMAKE_PROGRAM_PATH=${CMAKE_PROGRAM_PATH}")

list(APPEND CMAKE_PREFIX_PATH ${QCLASH_PLATFORM_LIBS_PREFIX})
link_directories(${QCLASH_PLATFORM_LIBS_PREFIX}/lib)
list(APPEND CMAKE_FIND_ROOT_PATH ${QCLASH_PLATFORM_LIBS_PREFIX})
