

# client/server - gstreamer packages

These steps must be followed for client side and server side.

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

These steps must be followed for the client side

https://github.com/detrout/qt-gstreamer
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
Demo :

```
