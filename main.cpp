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
      std::array<float, 10000> Results;
      for (size_t Index{0}; Index < Results.size(); ++Index)
      {
            Results[Index] = Index;
      }
      for (short Idx{0}; Idx < 10; ++Idx)
      {
            for (size_t Index{0}; Index < Results.size(); ++Index)
            {
                  Results[Index] = Index;
            }
            const auto CurrentTime1{chrono::system_clock::now()};
            if (aClient.GetReply(Results) != 0)
            {
                  std::cout << "wtf\n";
            }
            const auto CurrentTime2{chrono::system_clock::now()};
            //<< "Elements recieved - " << Results.size() << "\n" <<
            std::cout << std::chrono::duration<double>((CurrentTime2 - CurrentTime1)).count()
                      << " - time spend \n" ;
            Sleep(1000);
      }
      for (size_t Idx{Results.size() - 10}; Idx < Results.size(); ++Idx)
      {
            std::cout << Results[Idx] << "\n";
      }
      std::cout.flush();
      return 0;
}
