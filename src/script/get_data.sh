#!/bin/bash

#for pay
gst-inspect-1.0 | grep " pay" |  awk '{print $2}' | sed 's/://' >./DATA/PAYLOADER.txt

#for depay
gst-inspect-1.0 | grep "depay" | awk '{print $2}' | sed 's/://' >./DATA/DEPAYLOADER.txt

#for encoder
gst-inspect-1.0 | grep "encoder" | grep -i -v -E "audio|text"|\
awk '{print $2}' | sed 's/://' > ./DATA/ENCODER.txt

#for decoder
gst-inspect-1.0 | grep "decoder"  | grep -i -v -E "audio|text" |\
awk '{print $2}' | sed 's/://' > ./DATA/DECODER.txt

#for parser
gst-inspect-1.0 | grep -i parse | grep -i -v -E "audio|subtitle|midi|text" |\
awk '{print $2}' | sed 's/://' > ./DATA/PARSER.txt

#for parser
gst-inspect-1.0 | grep -i convert | grep -i -v -E "audio" |\
awk '{print $2}' | sed 's/://' > ./DATA/CONVERTER.txt

#for sink
gst-inspect-1.0 | grep sink | grep -v -i -E "audio" |\
awk '{print $2}' | sed 's/://' > ./DATA/SINK.txt

#for source
gst-inspect-1.0 | grep src | grep -v -i -E "audio" |\
awk '{print $2}' | sed 's/://' > ./DATA/SOURCE.txt
