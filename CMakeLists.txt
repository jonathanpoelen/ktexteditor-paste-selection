project(kdevpasteselection)

cmake_minimum_required(VERSION 2.8.12)
# apt install cmake-extras
find_package (ECM 0.0.9 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${ECM_MODULE_PATH})

include(KDECompilerSettings NO_POLICY_SCOPE)
#include(ECMAddTests)
include(KDEInstallDirs)
include(KDECMakeSettings)

set(QT_MIN_VERSION "5.4.0")
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED Widgets)
#find_package(Qt5 REQUIRED Core Widgets Test)

set(KF5_DEP_VERSION "5.15.0") # pifometrie...
find_package(KF5 ${KF5_DEP_VERSION} REQUIRED COMPONENTS
  I18n
  IconThemes
  Service
  TextEditor
  XmlGui
)

find_package(KDevPlatform ${KDEVPLATFORM_VERSION} REQUIRED)

set(CMAKE_CXX_STANDARD 14)

set(kdevpasteselection_PART_SRCS
  pasteselectionplugin.cpp
)

qt5_add_resources(kdevpasteselection_PART_SRCS kdevpasteselection.qrc)
kdevplatform_add_plugin(
  kdevpasteselection
  JSON kdevpasteselection.json
  SOURCES ${kdevpasteselection_PART_SRCS}
)
target_link_libraries(kdevpasteselection
  KDev::Interfaces
)

# install(
#   TARGETS kdevpasteselection
#   DESTINATION ${PLUGIN_INSTALL_DIR}/kdevplatform/${KDEV_PLUGIN_VERSION}
#   PERMISSIONS OWNER_WRITE OWNER_READ GROUP_READ WORLD_READ
# )

feature_summary(WHAT ALL FATAL_ON_MISSING_REQUIRED_PACKAGES)
