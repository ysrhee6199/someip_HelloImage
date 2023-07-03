/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/HelloImageSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createHelloImageSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< HelloImageSomeIPProxy>(_address, _connection);
}

void initializeHelloImageSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.HelloImage:v1_0:test",
        0x1234, 0x5678, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.HelloImage:v1_0",
        &createHelloImageSomeIPProxy);
}

INITIALIZER(registerHelloImageSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeHelloImageSomeIPProxy);
}

HelloImageSomeIPProxy::HelloImageSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection)
{
}

HelloImageSomeIPProxy::~HelloImageSomeIPProxy() {
    completed_.set_value();
}



void HelloImageSomeIPProxy::sendImage(std::string _name, CommonAPI::CallStatus &_internalCallStatus, std::vector< uint8_t > &_image, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_name(_name, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::Deployable< std::vector< uint8_t >, CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >> deploy_image(static_cast< CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >* >(nullptr));
    CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::vector< uint8_t >,
                CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >
            >
        >
    >::callMethodWithReply(
        *this,
        CommonAPI::SomeIP::method_id_t(0x7b),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_name,
        _internalCallStatus,
        deploy_image);
    _image = deploy_image.getValue();
}

std::future<CommonAPI::CallStatus> HelloImageSomeIPProxy::sendImageAsync(const std::string &_name, SendImageAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< std::string, CommonAPI::SomeIP::StringDeployment> deploy_name(_name, static_cast< CommonAPI::SomeIP::StringDeployment* >(nullptr));
    CommonAPI::Deployable< std::vector< uint8_t >, CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >> deploy_image(static_cast< CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >* >(nullptr));
    return CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::string,
                CommonAPI::SomeIP::StringDeployment
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                std::vector< uint8_t >,
                CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> >
            >
        >
    >::callMethodAsync(
        *this,
        CommonAPI::SomeIP::method_id_t(0x7b),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_name,
        [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< std::vector< uint8_t >, CommonAPI::SomeIP::ArrayDeployment< CommonAPI::SomeIP::IntegerDeployment<uint8_t> > > _image) {
            if (_callback)
                _callback(_internalCallStatus, _image.getValue());
        },
        std::make_tuple(deploy_image));
}

void HelloImageSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> HelloImageSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1
