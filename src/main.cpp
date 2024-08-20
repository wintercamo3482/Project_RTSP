#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>

int main(int argc, char *argv[])
{
    gst_init(&argc, &argv);

    GstRTSPServer *server = gst_rtsp_server_new();
    GstRTSPMountPoints *mount = gst_rtsp_server_get_mount_points(server);
    GstRTSPMediaFactory *factory = gst_rtsp_media_factory_new();

    gst_rtsp_server_set_service(server, "8554");
    gst_rtsp_media_factory_set_launch(factory, "v4l2src device=/dev/video8 ! videoconvert ! video/x-raw,format=I420,width=640,height=480 ! x264enc speed-preset=ultrafast tune=zerolatency ! rtph264pay name=pay0 pt=96");


    gst_rtsp_mount_points_add_factory(mount, "/test", factory);

    gst_rtsp_server_attach(server, NULL);

    GMainLoop *loop = g_main_loop_new(NULL, FALSE);
    g_main_loop_run(loop);

    return 0;
}
