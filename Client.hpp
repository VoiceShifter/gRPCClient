#ifndef CLIENT_HPP
#define CLIENT_HPP
# include <grpcpp/channel.h>
# include <grpcpp/grpcpp.h>
# include <grpcpp/create_channel.h>

#include "proto/Message.grpc.pb.h"
class Client final : public Processing::Service
{
private:
      std::unique_ptr<Processing::Stub> stub_;
public:
      Client(std::shared_ptr<grpc::Channel> channel);
      signed int GetReply(const signed int Message);
};

#endif // CLIENT_HPP
