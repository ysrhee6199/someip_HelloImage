// HelloImageClient.cpp
#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloImageProxy.hpp>
#include <opencv2/opencv.hpp>


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
    myProxy->sendImage("Bob", callStatus, returnImage);

    cv::Mat decoded_image = cv::imdecode(returnImage, cv::IMREAD_COLOR);
     if (decoded_image.empty()) {
        std::cerr << "Failed to decode image." << std::endl;
        return 1;
    }
    std::cout << "Got message@@'" << "'\n";
    cv::namedWindow("Decoded Image");
    cv::imshow("Decoded Image", decoded_image);
    cv::waitKey(0);
    return 0;
}
