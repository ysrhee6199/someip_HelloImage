// HelloWorldStubImpl.hpp
#ifndef HELLOWORLDSTUBIMPL_H_
#define HELLOWORLDSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/HelloImageStubDefault.hpp>
#include <opencv2/opencv.hpp>



class HelloImageStubImpl: public v1_0::commonapi::HelloImageStubDefault {
public:
    HelloImageStubImpl();
    virtual ~HelloImageStubImpl();
    virtual void sendImage(const std::shared_ptr<CommonAPI::ClientId> _client,
    	std::string _name, sendImageReply_t _return);
};
#endif /* HELLOWORLDSTUBIMPL_H_ */
