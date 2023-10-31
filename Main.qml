import QtQuick
import QtQuick.Window
import QtQuick.Controls

import OthelloModel 1.0

Window {
    id: root
    width: 640
    height: 700
    visible: true
    visibility: Window.Maximized
    title: qsTr("Othello")

    property int aiDelayValue: 1000
    property int empty: 0
    property int white: 1
    property int black: 2
    property int noWinner: -1

    OthelloModel{
        id: othelloModel
    }

    Loader{
        id: loader
        anchors.fill: parent
        source: "MainMenu.qml"
    }
}
