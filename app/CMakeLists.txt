cmake_minimum_required(VERSION 3.5)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/labels/stackLabel/stacklabel.h
        src/labels/stackLabel/stacklabel.cpp
        src/labels/resultLabel/resultlabel.h
        src/labels/resultLabel/resultlabel.cpp
        src/buttons/optionButton/optionbutton.h
        src/buttons/optionButton/optionbutton.cpp
        src/buttons/operatorButton/operatorbutton.h
        src/buttons/operatorButton/operatorbutton.cpp
        src/buttons/numberButton/numberbutton.h
        src/buttons/numberButton/numberbutton.cpp
        resources.qrc
        src/centralWidget/centralwidget.h
        src/centralWidget/centralwidget.cpp
)

if(APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE ${PROJECT_SOURCES})

    set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_INFO_PLIST ${CMAKE_SOURCE_DIR}/cmake/MacOSInfo.plist)
else()
    add_executable(${PROJECT_NAME}
        ${PROJECT_SOURCES}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS calculator
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
