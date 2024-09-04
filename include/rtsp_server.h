#ifndef RTSP_SERVER_H
#define RTSP_SERVER_H

#include <iostream>
#include <string>
#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>

using namespace std;

// 장치, 해상도, 포트 등 서버에 연결된 카메라 설정을 저장하는 구조체
struct ServerSetting
{
    string device_ = "/dev/video0";
    string width_ = "640";
    string hegiht_ = "480";
    string port_ = "8554";
    string path_ = "/stream";
};

// RTSP 서버 클래스
class RTSPServer
{
// public:
//     RTSPServer(const string& device, const string& width, const string& height, const string& port, const string& path)
//     ~RTSPServer();

//     RTSPServer::std::string getServerIP(const string& connection_method);
    
// }

// // RTSP 서버 방식과 주소를 리턴하는 함수
// string get_server_ip(const std::string& interface);



// private:
//     GstRTSPServer* server_;
//     RTSPFactory* factory_;
};

// class RTSPFactory : public GstRTSPMediaFactory {
// public:
//     RTSPFactory(const std::string& device, const std::string& width, const std::string& height);
// protected:
//     GstElement* create_element(const char* url) override;
// private:
//     std::string device_;
//     std::string width_;
//     std::string height_;
// };

#endif