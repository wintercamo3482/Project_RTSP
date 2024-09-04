#include <rtsp_server.h>

void parse_arguments(int argc, char* argv[], ServerSetting &settings) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "-d" && i + 1 < argc) {
            settings.device_ = argv[++i];
        } else if (arg == "-w" && i + 1 < argc) {
            settings.width_ = argv[++i];
        } else if (arg == "-h" && i + 1 < argc) {
            settings.hegiht_ = argv[++i];
        } else if (arg == "-p" && i + 1 < argc) {
            settings.port_ = argv[++i];
        } else if (arg == "-n" && i + 1 < argc) {
            settings.path_ = argv[++i];
        } else {
            std::cerr << "Unknown argument: " << arg << std::endl;
            exit(1);
        }
    }
}

// RTSPServer::RTSPServer(const string& device, const string& width, const string& height, const string& port, const string& path)
// {

//     std::cout << "Initialize RTSP server at " << endl;
//     server_ = gst_rtsp_server_new();
    
//     GstRTSPServer *server = gst_rtsp_server_new();
//     GstRTSPMountPoints *mount = gst_rtsp_server_get_mount_points(server);
//     GstRTSPMediaFactory *factory = gst_rtsp_media_factory_new();
// }

// {
//         g_object_set(server_, "service", port.c_str(), NULL);

//         GstRTSPMediaFactory* factory = gst_rtsp_media_factory_new();
//         std::string pipeline = "v4l2src device=" + device + " ! videoconvert ! video/x-raw,format=I420,width=" + width + ",height=" + height + " ! x264enc speed-preset=ultrafast tune=zerolatency ! rtph264pay name=pay0 pt=96";
//         gst_rtsp_media_factory_set_launch(factory, pipeline.c_str());
//         gst_rtsp_media_factory_set_shared(factory, TRUE);

//         GstRTSPMountPoints* mount = gst_rtsp_server_get_mount_points(server_);
//         gst_rtsp_mount_points_add_factory(mount, path.c_str(), factory);
//         g_object_unref(mount);

//         gst_rtsp_server_attach(server_, NULL);
//         std::cout << "RTSP server attached and running..." << std::endl;
//     }

// //         server_ = gst_rtsp_server_new();
// //         g_object_set(server_, "service", port.c_str(), NULL);

// //         factory_ = new RTSPFactory(device, width, height);
// //         gst_rtsp_media_factory_set_shared(factory_, TRUE);

// //         GstRTSPMountPoints* mount = gst_rtsp_server_get_mount_points(server_);
// //         gst_rtsp_mount_points_add_factory(mount, path.c_str(), GST_RTSP_MEDIA_FACTORY(factory_));
// //         g_object_unref(mount);

// //         gst_rtsp_server_attach(server_, NULL);
// //         std::cout << "RTSP server attached and running..." << std::endl;
// //     }

// // private:
// //     GstRTSPServer* server_;
// //     RTSPFactory* factory_;
// // };



// RTSPServer::~RTSPServer()
// {
//     delete factory_;
// }


// string get_server_ip(const string& connection_method)
// {
//     char buffer[128];
//     string command = "ifconfig " + connection_method + " | grep 'inet ' | awk '{print $2}'";
//     string result = "";
//     FILE* pipe = popen(command.c_str(), "r");
    
//     if (!pipe)
//         return "ERROR";
    
//     while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
//     {
//         result += buffer;
//     }
    
//     pclose(pipe);
//     result.erase(result.find_last_not_of(" \n\r\t")+1);
    
//     return result;
// }





//     ~GstServer() {
//         g_object_unref(server_);
//     }

// private:
//     GstRTSPServer* server_;
// };

// std::string get_ip_address(const std::string& interface) {
//     char buffer[128];
//     std::string result = "";
//     std::string command = "ifconfig " + interface;

//     FILE* pipe = popen(command.c_str(), "r");
//     if (!pipe) return "ERROR";
//     while (!feof(pipe)) {
//         if (fgets(buffer, 128, pipe) != nullptr)
//             result += buffer;
//     }
//     pclose(pipe);

//     std::regex ip_regex("inet\\s+(\\d+\\.\\d+\\.\\d+\\.\\d+)");
//     std::smatch ip_match;
//     if (std::regex_search(result, ip_match, ip_regex)) {
//         return ip_match[1];
//     }
//     return "";
// }
