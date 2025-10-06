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
      template<class T, size_t Size>
      signed int GetReply(std::array<T, Size>& ToSend)
      {
            aMessage Request, Reply;
            for (size_t Idx{0}; Idx < ToSend.size(); ++Idx)
            {
                  Request.add_first(ToSend[Idx]);
            }
            grpc::ClientContext ctx;
            grpc::Status Status{stub_->Compute(&ctx, Request, &Reply)};

            if (Status.ok())
            {
                  std::cout << "All good\n";
                  for (size_t Idx{0}; Idx < Reply.first_size(); ++Idx)
                  {
                        ToSend[Idx] = Reply.first(Idx);
                  }
                  return 0;
            }
            else
            {
                  std::cout << Status.error_code() << " " << Status.error_details() << " " << Status.error_message();
                  std::cout << "Error of grpc\n";
                  return -1;
            }
      }
};

#endif // CLIENT_HPP
