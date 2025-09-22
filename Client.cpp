#include "Client.hpp"


Client::Client(std::shared_ptr<grpc::Channel> channel) : stub_{Processing::NewStub(channel)}
{

}

signed int Client::GetReply(const signed int Message)
{
      aMessage Request, Reply;
      Request.set_first(Message);
      grpc::ClientContext ctx;

      grpc::Status Status{stub_->Compute(&ctx, Request, &Reply)};
      if (Status.ok())
      {
            return Reply.first();
      }
      else
      {
            std::cout << "Error of grpc\n";
            return -1;
      }
}
