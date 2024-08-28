# rmmod uvcvideo
# modprobe uvcvideo nodrop=1

chmod +x src/main.py
python3 src/main.py --d /dev/video2 --w 640 --h 480 --p 8555 --n /stream
