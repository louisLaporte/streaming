#-------------------------------------------------
#
# Project created by QtCreator 2015-08-25T18:47:31
#
#-------------------------------------------------
#
#
#

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

contains(QT_VERSION, ^5\\..*) {
  PKGCONFIG += Qt5GStreamer-1.0 Qt5GStreamerUi-1.0

}



TEMPLATE = app

# produce nice compilation output
#CONFIG += silent

# Tell qmake to use pkg-config to find QtGStreamer.
CONFIG +=  debug link_pkgconfig

SCRIPT_GET_DATA=./script/get_data.sh
message($$SCRIPT_GET_DATA)

exists($${SCRIPT_GET_DATA})
{
system(mkdir ./DATA)
message("get_data.sh exists")
system(chmod +x $$SCRIPT_GET_DATA)
system(./script/get_data.sh)
}

SOURCES += main.cpp\
        mainwindow.cpp \
        streameditor.cpp \
#        gstreamervideowidget.cpp \
    videowidget.cpp

HEADERS  += mainwindow.h \
    streameditor.h \
#    gstreamervideowidget.h \
    videowidget.h

FORMS    += mainwindow.ui \
    streameditor.ui \
#    gstreamervideowidget.ui \
    videowidget.ui

DISTFILES += \
    TODO \
    DATA/CONVERTER.txt \
    DATA/DECODER.txt \
    DATA/DEPAYLOADER.txt \
    DATA/ENCODER.txt \
    DATA/PARSER.txt \
    DATA/PAYLOADER.txt \
    DATA/SINK.txt \
    DATA/SOURCE.txt


unix {
debug:TARGET = ./bin/drono_streaming
debug:OBJECTS_DIR = ./build/.obj
debug:MOC_DIR = ./build/.moc
debug:RCC_DIR = ./build/.rcc
debug:UI_DIR = ./build/.ui
}


