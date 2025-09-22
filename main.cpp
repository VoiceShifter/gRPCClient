#include "Client.hpp"
#include <iostream>
# include <grpc++/server.h>
# include <grpcpp/channel.h>
# include <grpcpp/grpcpp.h>
# include <grpcpp/create_channel.h>
# include <chrono>
using namespace std;


int main()
{
      auto Channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
      Client aClient(Channel);
      std::array<signed int, 1000> Results;
      const auto CurrentTime1{chrono::system_clock::now()};
      for (ushort Index{0}; Index < 1000; ++Index)
      {
            Results[Index] = aClient.GetReply(Index);
      }
      const auto CurrentTime2{chrono::system_clock::now()};
      std::cout << std::chrono::duration<double>(CurrentTime2 - CurrentTime1).count() << " - time spend to calculate\n";
      for (const auto it : Results)
      {
            std:: cout << it << '\n';
      }
      return 0;
}
