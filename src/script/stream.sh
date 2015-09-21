#!/bin/bash

function usage
{

    cat <<_EOF_
USAGE   
	$basename $0 [-v] [OPTION] | [-h]

DESCRIPTION
	-v | --verbose		Enable verbode output
	-h | --help		Display help message
	-i | --host		Set the hostname 
	-p | --port		Set the port to use 
	-c | --protocol		UDP or TCP
	-s | --side		Client or server
_EOF_
}

function bad_argument
{
echo "Invalid argument"
echo "try $0 -h" 

}

##### Main
while [[ $# -gt 0 ]]
do
key="$1"

case $key in
    -h|--help)
    usage
    exit 1 # past argument
    ;;
    -c|--protocol)
    PROTOCOL=$2
    shift # past argument
    ;;
    -s|--side)
    SIDE=$2
    shift # past argument
    ;;
    -i|--host)
    HOST="$2"
    shift # past argument
    ;;
    -p|--port)
    PORT="$2"
    shift # past argument
    ;;
    --default)
    ;;
    *)
    bad_argument  
    # unknown option
    ;;
esac
shift # past argument or value
done

function communication()
{
#UDP CLIENT
if  [ "$PROTOCOL" = "UDP" ] && [ "$SIDE" = "client" ]  ; then
	echo -e "protocol : $PROTOCOL\nside : $SIDE"
	
	COMMAND="
	gst-launch-1.0 udpsrc port=$PORT 
	!  application/x-rtp, encoding-name=H264,payload=96 \
	! rtph264depay ! h264parse ! avdec_h264 ! autovideosink
	"
	echo -e "\e[1;32m$COMMAND\e[1;0m"
	$COMMAND

elif  [ "$PROTOCOL" = "UDP" ] && [ "$SIDE" = "server" ]  ; then
	echo -e " protocol : $PROTOCOL\nside : $SIDE"
	
	COMMAND="
	gst-launch-1.0 v4l2src \
	! video/x-raw,width=640,height=480 \
	! x264enc tune=zerolatency byte-stream=true  bitrate=3000 threads=2 \
	! h264parse config-interval=1 \
	! rtph264pay \
	! udpsink host=$HOST port=$PORT
	"
	echo -e "\e[1;32m$COMMAND\e[1;0m"
	$COMMAND

elif  [ "$PROTOCOL" = "TCP" ] && [ "$SIDE" = "client" ] ; then
	echo -e "bbb protocol : $PROTOCOL\nside : $SIDE"

	COMMAND=" 
	gst-launch-1.0 -vvv -e tcpclientsrc host=$HOST port=$PORT \
	! gdpdepay \
	! rtph264depay \
	! avdec_h264 \
	! videoconvert ! xvimagesink sync=false
	"
	echo -e "\e[1;32m$COMMAND\e[1;0m"
	$COMMAND

elif  [ "$PROTOCOL" = "TCP" ] && [ "$SIDE" = "server" ] ; then
	COMMAND="
	gst-launch-1.0 v4l2src device=/dev/video0 ! videoconvert  \
	! tee name=t \
	! queue \
	! x264enc tune=zerolatency ! h264parse \
	! rtph264pay  config-interval=1 pt=96 \
	! gdppay \
	! tcpserversink host=$HOST port=$PORT t. \
	! queue \
	! xvimagesink 
	"
	
	echo -e "\e[1;32m$COMMAND\e[1;0m"
	$COMMAND
fi

}

communication $PROTOCOL $SIDE

