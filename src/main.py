import argparse
import subprocess
import re
import gi
gi.require_version('Gst', '1.0')
gi.require_version('GstRtspServer', '1.0')
from gi.repository import Gst, GstRtspServer, GObject, GLib

def get_ip_address(interface):
    """Return the IPv4 address of the specified network interface."""
    try:
        ifconfig_result = subprocess.check_output(f"ifconfig {interface}", shell=True).decode('utf-8')
        ip_address = re.search(r'inet\s+(\d+\.\d+\.\d+\.\d+)', ifconfig_result)
        if ip_address:
            return ip_address.group(1)
        else:
            return None
    except subprocess.CalledProcessError:
        return None

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--d', type=str, default="/dev/video0")
    parser.add_argument('--w', type=str, default="640")
    parser.add_argument('--h', type=str, default="480")
    parser.add_argument('--p', type=str, default="8554")
    parser.add_argument('--n', type=str, default="/test")
    args = parser.parse_args()

    # Check the network interfaces
    eth0_ip = get_ip_address("eth0")
    wlan0_ip = get_ip_address("wlan0")

    if eth0_ip:
        print(f"Running on Ethernet (eth0) with IP address: {eth0_ip}")
    elif wlan0_ip:
        print(f"Running on WiFi (wlan0) with IP address: {wlan0_ip}")
    else:
        print("No valid network interface found. Exiting.")
        exit(1)

    loop = GLib.MainLoop()
    GObject.threads_init()
    Gst.init(None)

    print(f"Starting RTSP server on port {args.p} with path {args.n}")
    print(f"Using video device: {args.d}, width: {args.w}, height: {args.h}")

    class RTSPFactory(GstRtspServer.RTSPMediaFactory):
        def __init__(self, device, width, height, **properties):
            super(RTSPFactory, self).__init__(**properties)
            self.device = device
            self.width = width
            self.height = height
            print(f"RTSPFactory initialized with device={device}, width={width}, height={height}")
        
        def do_create_element(self, url):
            pipeline = f"v4l2src device={self.device} ! videoconvert ! video/x-raw,format=I420,width={self.width},height={self.height} ! x264enc speed-preset=ultrafast tune=zerolatency ! rtph264pay name=pay0 pt=96"
            print(f"Creating GStreamer pipeline: {pipeline}")
            return Gst.parse_launch(pipeline)

    class GstServer():
        def __init__(self, port, path, device, width, height):
            print(f"Initializing GstServer with port={port}, path={path}")
            self.rtspServer = GstRtspServer.RTSPServer()
            self.rtspServer.set_service(port)   # RTSP port
            factory = RTSPFactory(device=device, width=width, height=height)
            factory.set_shared(True)
            mount = self.rtspServer.get_mount_points()
            mount.add_factory(path, factory)   # RTSP URL sub string
            self.rtspServer.attach(None)
            print("RTSP server attached and running...")

    rtspServer = GstServer(port=args.p, path=args.n, device=args.d, width=args.w, height=args.h)
    print("Entering main loop...")
    loop.run()
    print("Main loop ended.")
