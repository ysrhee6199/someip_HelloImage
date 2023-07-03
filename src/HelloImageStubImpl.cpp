// HelloWorldStubImpl.cpp
#include "HelloImageStubImpl.hpp"

HelloImageStubImpl::HelloImageStubImpl() { }
HelloImageStubImpl::~HelloImageStubImpl() { }

void HelloImageStubImpl::sendImage(const std::shared_ptr<CommonAPI::ClientId> _client,
	std::string _name, sendImageReply_t _reply) {
	cv::Mat image = cv::imread("image.jpg");
	if (image.empty()) {
        std::cerr << "Failed to load image." << std::endl;
        return;
    }
	// 이미지를 바이트 벡터로 인코딩
    std::vector<uchar> encoded_image;
    if (!cv::imencode(".jpg", image, encoded_image)) {
        std::cerr << "Failed to encode image." << std::endl;
        return;
    }

    _reply(encoded_image);
};

