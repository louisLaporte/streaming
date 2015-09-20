

#Raspberry pi / Desktop - gstreamer packages

These steps must be followed for the Raspberry AND the Desktop.

##Fedora


#### Configuring RPMFusion

* Add the new repository for your package manager

```
 sudo dnf install --nogpgcheck http://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-22.noarch.rpm
```

* Updating your package manager

```
 sudo dnf update
```
####Install Multimedia Codecs/Plugins
```
sudo dnf install gstreamer1* gstreamer gstreamer-libav
```


##	Debian
#### Configuring Apt
To install "add-apt-repository" :
```
sudo apt-get install software-properties-common
```
```
 sudo apt-get install python-software-properties
```
* Now add the new repository for your package manager

```
sudo add-apt-repository ppa:gstreamer-developers/ppa
```
* Updating your package manager

```
sudo apt-get update
```
####Install Multimedia Codecs/Plugins

```
sudo apt-get install gstreamer1.0* gstreamer
```
#qt-gstreamer

Follow the steps :

https://github.com/detrout/qt-gstreamer
'''
bind to /lib64
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
'''
### Section 2.3 qt-gstreamer

```
2.3 Procedure
-------------

The build procedure is simple:

$ mkdir build && cd build
$ cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
$ make
$ make install
```
###Examples - VoIP
If you have trouble to compile with Qt add this lines in  voip.pro

be careful for lgstqt5videosink check the path or move it in $QT_GSTREAMER/bin/lib64

see below
```
QT_GSTREAMER=[YOUR_GSTREAMER_PATH]

CONFIG += $QT_GSTREAMER/bin/lib64/pckconfig

LIBS+= -L$QT_GSTREAMER/bin/lib64\
                                -lQt5GStreamerQuick-1.0\
                                -lQt5GLib-2.0\
                                -lQt5GStreamerUi-1.0\
                                -lQt5GStreamerUtils-1.0\
                                -lQt5GStreamer-1.0


LIBS+=- L$QT_GSTREAMER/bin/lib64_2\
                                -lgstqt5videosink

INCLUDEPATH+="$QT_GSTREAMER/bin/include/Qt5GStreamer/"

```
