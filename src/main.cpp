#include <iostream>
#include <string>
#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>

using namespace std;

string getServerAddress(const string& connection_method)
{
    char buffer[128];
    string command = "ifconfig " + connection_method + " | grep 'inet ' | awk '{print $2}'";
    string result = "";
    FILE* pipe = popen(command.c_str(), "r");
    
    if (!pipe)
    {
        return "ERROR";
    }
        
    
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        result += buffer;
    }
    
    pclose(pipe);
    result.erase(result.find_last_not_of(" \n\r\t")+1);
    
    return result;
}

int main(int argc, char *argv[])
{
    gst_init(&argc, &argv);
    GstRTSPServer *server = gst_rtsp_server_new();
    GstRTSPMountPoints *mount = gst_rtsp_server_get_mount_points(server);
    GstRTSPMediaFactory *factory = gst_rtsp_media_factory_new();

    cout << "Init RTSP server Done!!!" << endl;

    gst_rtsp_server_set_service(server, "8554");    // 포트 설정

    string pipeline_command = "v4l2src device=/dev/video0 ! videoconvert ! video/x-raw,format=I420,width=640,height=480 ! x264enc speed-preset=ultrafast tune=zerolatency ! rtph264pay name=pay0 pt=96";
    gst_rtsp_media_factory_set_launch(factory, pipeline_command.c_str());

    cout << "Init GStreamer Pipeline Done!!!" << endl;

    gst_rtsp_mount_points_add_factory(mount, "/test", factory);
    gst_rtsp_server_attach(server, NULL);

    // IP 주소 출력
    string wlan0_ip = getServerAddress("wlan0");
    string eth0_ip = getServerAddress("eth0");

    cout << "Running RTSP server at";

    if (!wlan0_ip.empty() && wlan0_ip != "ERROR") {
        cout << " - wlan0: rtsp://" << wlan0_ip << ":8554/test" << endl;
    }
    
    if (!eth0_ip.empty() && eth0_ip != "ERROR") {
        cout << " - eth0: rtsp://" << eth0_ip << ":8554/test" << endl;
    }

    cout << "Main_loop start!!!" << endl;

    GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    cout << "main Loop end..." << endl;

    return 0;
}
