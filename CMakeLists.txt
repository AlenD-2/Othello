cmake_minimum_required(VERSION 3.16)

project(Othello VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appOthello
    main.cpp
    OthelloBoard.h OthelloBoard.cpp
    OthelloModel.h OthelloModel.cpp
    Player.h Player.cpp
    OthelloLogic.h OthelloLogic.cpp
    PlayersModel.h PlayersModel.cpp
)

qt_add_qml_module(appOthello
    URI Othello
    VERSION 1.0
    QML_FILES Main.qml MainMenu.qml Board.qml
)

set_target_properties(appOthello PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appOthello
    PRIVATE Qt6::Quick
)

install(TARGETS appOthello
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
