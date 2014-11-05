ktexteditor-paste-selection
===========================

Katepart plugin (Kwrite, Kate, Kdevelop, ...) that adds keyboard shortcut for paste selection


Dependencies
------------

Debian and derived:
 - kdelibs5-dev

Other distros:
 - kdelibs5-devel


Install
-------

```sh
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$(kde4-config --prefix) -DQT_QMAKE_EXECUTABLE=/usr/bin/qmake-qt4
make
sudo make install
```

or

```sh
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$(kde4-config --localprefix) -DQT_QMAKE_EXECUTABLE=/usr/bin/qmake-qt4
make
make install
```
