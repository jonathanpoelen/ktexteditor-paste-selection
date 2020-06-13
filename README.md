ktexteditor-paste-selection
===========================

Keyboard shortcut to paste selection in KDevelop5.

## Dependencies

- `cmake`
- `extra-cmake-modules`
- `gettext`
- `kdelibs5-dev` or `kdelibs5-devel`
<!-- - kdevplatform-dev -->

```
sudo apt install cmake extra-cmake-modules gettext kdelibs5-dev
```

## Install

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install
```

Note: It may be necessary to add `-DPLUGIN_INSTALL_DIR=${your_path}` with `cmake`. For example `/usr/lib/qt/plugins/` or `/usr/lib/x86_64-linux-gnu/qt5/plugins/`.
