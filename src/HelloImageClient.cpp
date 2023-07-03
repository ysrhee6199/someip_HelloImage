// HelloImageClient.cpp
#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloImageProxy.hpp>

using namespace v1_0::commonapi;

int main() {
    std::shared_ptr < CommonAPI::Runtime > runtime = CommonAPI::Runtime::get();
    std::shared_ptr<HelloImageProxy<>> myProxy =
    	runtime->buildProxy<HelloImageProxy>("local", "test");

    std::cout << "Checking availability!" << std::endl;
    while (!myProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;
    std::vector<unsigned char> returnImage;
    myProxy->sayHello("Bob", callStatus, returnMessage);
    std::cout << "Got message: '" << returnMessage << "'\n";
    return 0;
}
