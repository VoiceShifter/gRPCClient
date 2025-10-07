cmake_minimum_required(VERSION 3.16)
list(APPEND CMAKE_PREFIX_PATH "F:/Libs/grpc_old810")
project(gRPCClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gRPCClient main.cpp
    Client.hpp Client.cpp proto/Message.grpc.pb.cc proto/Message.grpc.pb.h proto/Message.pb.cc proto/Message.pb.h proto/Message.proto)
find_package(Protobuf)
find_package(gRPC)
message(STATUS "Using gRPC ${gRPC_VERSION}")
include(GNUInstallDirs)
install(TARGETS gRPCClient
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE gRPC::grpc++ gRPC::grpc gRPC::grpcpp_channelz protobuf::libprotobuf)
