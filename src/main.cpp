#include <rtsp_server.h>

int main(int argc, char *argv[])
{
    // gst 초기화
    gst_init(&argc, &argv);

    // 전달인자 적용
    ServerSetting server_setting;
    parse_arguments

    
    for (int i = 1; i < argc; ++i)
    {
        string arg = argv[i];
        if (arg == "-d" && i + 1 < argc)
        {
            device = argv[++i];
        }
        else if (arg == "-w" && i + 1 < argc)
        {
            width = argv[++i];
        }
        else if (arg == "-h" && i + 1 < argc)
        {
            height = argv[++i];
        }
        else if (arg == "-p" && i + 1 < argc)
        {
            port = argv[++i];
        }
        else if (arg == "-n" && i + 1 < argc)
        {
            path = argv[++i];
        }
        else
        {
            cerr << "잘못된 인자" << arg << endl;
            return 1;
        }
    }
    // 유무선 셋팅 확인
    // get_server_ip();

    // RTSP 서버 오픈
    // 파이프라인 설정
    // 스트리밍 루프문
    // gst_rtsp_server_set_service(server, "8556");    // 포트 설정

//     string pipeline_command = "v4l2src device=/dev/video3 ! videoconvert ! video/x-raw,format=I420,width=640,height=480 ! x264enc speed-preset=ultrafast tune=zerolatency ! rtph264pay name=pay0 pt=96";
//     gst_rtsp_media_factory_set_launch(factory, pipeline_command.c_str());

    cout << "build test" << endl;

//     gst_rtsp_mount_points_add_factory(mount, "/test", factory);
//     gst_rtsp_server_attach(server, NULL);

//     // IP 주소 출력
//     string wlan0_ip = getServerAddress("wlan0");
//     string eth0_ip = getServerAddress("eth0");

//     cout << "Running RTSP server at";

//     if (!wlan0_ip.empty() && wlan0_ip != "ERROR") {
//         cout << " - wlan0: rtsp://" << wlan0_ip << ":8555/testA" << endl;
//     }

//     if (!eth0_ip.empty() && eth0_ip != "ERROR") {
//         cout << " - eth0: rtsp://" << eth0_ip << ":8555/testA" << endl;
//     }


//     cout << "Main_loop start!!!" << endl;

//     GMainLoop *loop = g_main_loop_new(NULL, FALSE);
//     g_main_loop_run(loop);

//     cout << "main Loop end..." << endl;

    return 0;
}