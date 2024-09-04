# rmmod uvcvideo
# modprobe uvcvideo nodrop=1

# g++ -o rtsp_server src/main.cpp `pkg-config --cflags --libs gstreamer-1.0 gstreamer-rtsp-server-1.0`
cd build
chmod +x rtsp_server
./rtsp_server
