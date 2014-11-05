project(ktexteditor_pasteselection)

find_package(KDE4 REQUIRED)
include(KDE4Defaults)
include_directories(${KDE4_INCLUDES} ${QT_INCLUDES})
add_definitions(${QT_DEFINITIONS} ${KDE4_DEFINITIONS})

set(ktexteditor_pasteselection_SRCS pasteselectionplugin.cpp)

kde4_add_plugin(ktexteditor_pasteselection ${ktexteditor_pasteselection_SRCS})

target_link_libraries(ktexteditor_pasteselection ${KDE4_KDEUI_LIBS} ${KDE4_KTEXTEDITOR_LIBS})

install(TARGETS ktexteditor_pasteselection DESTINATION ${PLUGIN_INSTALL_DIR})

install(FILES pasteselectionui.rc DESTINATION ${DATA_INSTALL_DIR}/ktexteditor_pasteselection)

install(FILES ktexteditor_pasteselection.desktop DESTINATION ${SERVICES_INSTALL_DIR})
 
