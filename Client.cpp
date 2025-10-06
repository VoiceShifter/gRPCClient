#include "Client.hpp"


Client::Client(std::shared_ptr<grpc::Channel> channel) : stub_{Processing::NewStub(channel)}
{

}

