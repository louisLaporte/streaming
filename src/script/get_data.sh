#!/bin/bash

#payloader file creation
gst-inspect-1.0 | grep " pay" |  awk '{print $2}' | sed 's/://' >./DATA/PAYLOADER.txt

#depayloader file creation
gst-inspect-1.0 | grep "depay" | awk '{print $2}' | sed 's/://' >./DATA/DEPAYLOADER.txt

#encoder file creation
gst-inspect-1.0 | grep "encoder" | grep -i -v -E "audio|text"|\
awk '{print $2}' | sed 's/://' > ./DATA/ENCODER.txt

#decoder file creation
gst-inspect-1.0 | grep "decoder"  | grep -i -v -E "audio|text" |\
awk '{print $2}' | sed 's/://' > ./DATA/DECODER.txt

#parser file creation
gst-inspect-1.0 | grep -i parse | grep -i -v -E "audio|subtitle|midi|text" |\
awk '{print $2}' | sed 's/://' > ./DATA/PARSER.txt

#converter file creation
gst-inspect-1.0 | grep -i convert | grep -i -v -E "audio" |\
awk '{print $2}' | sed 's/://' > ./DATA/CONVERTER.txt

#sink file creation
gst-inspect-1.0 | grep sink | grep -v -i -E "audio" |\
awk '{print $2}' | sed 's/://' > ./DATA/SINK.txt

#source file creation
gst-inspect-1.0 | grep src | grep -v -i -E "audio" |\
awk '{print $2}' | sed 's/://' > ./DATA/SOURCE.txt
