ktexteditor-paste-selection
===========================

Keyboard shortcut to paste selection in KDevelop5.

## Dependencies

- cmake
- cmake-extras
- kdelibs5-dev or kdelibs5-devel
<!-- - kdevplatform-dev -->
- clang++ or g++ with c++14 support

```
sudo apt install cmake cmake-extras kdelibs5-dev
```

## Install

```
mkdir build
cd build
cmake -DPLUGIN_INSTALL_DIR=/usr/lib/x86_64-linux-gnu/qt5/plugins/ -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```
