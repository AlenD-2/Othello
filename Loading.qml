import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    anchors.fill: parent
    color: "green"

    Image {
        source: "/img/image/Menu Background.png"
        anchors.fill: parent
    }

    RowLayout{
        anchors.centerIn: parent
        spacing: 200

        ColumnLayout{
            spacing: 30
            Item{
                width: childrenRect.width
                height: childrenRect.height
                Layout.alignment: Qt.AlignHCenter
                Text{
                    id: txt1
                    text: othelloModel.playersName[0]
                    visible: text !== ""
                    anchors.centerIn: parent
                    font.pointSize: 32
                    color: "white"
                }

                BusyIndicator{
                    id: busy1
                    width: 100
                    height: width
                    visible: txt1.text === ""
                }
            }
        }

        ColumnLayout{
            spacing: 30
            Item{
                width: childrenRect.width
                height: childrenRect.height
                Layout.alignment: Qt.AlignHCenter
                Text{
                    id: txt2
                    text: othelloModel.playersName[1]
                    visible: text !== ""
                    anchors.centerIn: parent
                    font.pointSize: 32
                    color: "white"
                }
                BusyIndicator{
                    id: busy2
                    width: 100
                    height: width
                    visible: txt2.text === ""
                }
            }
        }
    }

    SpinBox{
        id: delaySpin
        height: 30
        width: 70
        anchors{
            bottom: startBtn.top
            horizontalCenter: startBtn.horizontalCenter
            bottomMargin: 30
        }
        value: 1000
        from: 0
        to: 10000
        stepSize: 100
        editable: true
    }

    Button{
        id: startBtn
        text: "Start"
        width: 100
        height: 60
        anchors{
            bottom: parent.bottom
            horizontalCenter: parent.horizontalCenter
            bottomMargin: 50
        }
        enabled: txt2.text !== "" && txt1.text !== ""
        onClicked: {
            loader.source = "GamePage.qml"
            othelloModel.setAiDelay(delaySpin.value)
            root.aiDelayValue = (delaySpin.value > 100)? (delaySpin.value-100) : 0
            othelloModel.nextTurn()
        }
    }
}
