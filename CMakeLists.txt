cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++0x")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIR})

include_directories(
    src-gen-image
    ~/build-commonapi/capicxx-core-runtime/include
    ~/build-commonapi/capicxx-someip-runtime/include
    ~/build-commonapi/vsomeip/interface
)
link_directories(
    ~/build-commonapi/capicxx-core-runtime/build
    ~/build-commonapi/capicxx-someip-runtime/build
    ~/build-commonapi/vsomeip/build
)
add_executable(HelloImageClient
        src/HelloImageClient.cpp
        src-gen-image/v1/commonapi/HelloImageSomeIPProxy.cpp
        src-gen-image/v1/commonapi/HelloImageSomeIPDeployment.cpp
)
target_link_libraries(HelloImageClient CommonAPI CommonAPI-SomeIP vsomeip3  ${OpenCV_LIBRARIES})
add_executable(HelloImageService
        src/HelloImageService.cpp
        src/HelloImageStubImpl.cpp
        src-gen-image/v1/commonapi/HelloImageSomeIPStubAdapter.cpp
        src-gen-image/v1/commonapi/HelloImageSomeIPDeployment.cpp
)
target_link_libraries(HelloImageService CommonAPI CommonAPI-SomeIP vsomeip3 ${OpenCV_LIBRARIES})
