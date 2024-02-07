import QtQuick
import QtQuick.Layouts

Item {
    width: childrenRect.width
    height: childrenRect.height

    property int heartsSize: 50
    property int remainHearts: 3

    Column{
        spacing: 5
        Image{
            source: "/img/image/heart"
            width: heartsSize
            height: heartsSize
            opacity: (remainHearts>=3)? 1:0.1
        }
        Image{
            source: "/img/image/heart"
            width: heartsSize
            height: heartsSize
            opacity: (remainHearts>=2)? 1:0.1
        }
        Image{
            source: "/img/image/heart"
            width: heartsSize
            height: heartsSize
            opacity: (remainHearts>=1)? 1:0.1
        }
    }
}


//Rectangle {
//    color: "lightBlue"
//    radius: 10

//    property string player1Name: ""
//    property string player2Name: ""
//    property string player1Time: "0:00"
//    property string player2Time: "0:00"

//    property int txtSize: 20

//    ColumnLayout{
//        anchors.fill: parent
//        anchors.margins: 20

//        ColumnLayout{
//            spacing: 20
//            RowLayout{
//                Text{
//                    text: player1Name
//                    Layout.fillWidth: true
//                    font.pointSize: txtSize
//                }
//                Text{
//                    text: player1Time
//                    font.pointSize: txtSize
//                }
//            }
//            RowLayout{
//                Rectangle{
//                    height: 20
//                    Layout.fillWidth: true
//                    radius: 10
//                    color: othelloModel.player1Chance < 1? "gray" : "white"
//                }
//                Rectangle{
//                    height: 20
//                    Layout.fillWidth: true
//                    radius: 10
//                    color: othelloModel.player1Chance < 2? "gray" : "white"
//                }
//                Rectangle{
//                    height: 20
//                    Layout.fillWidth: true
//                    radius: 10
//                    color: othelloModel.player1Chance < 3? "gray" : "white"
//                }
//            }
//        }
//        ColumnLayout{
//            spacing: 20
//            RowLayout{
//                Layout.fillWidth: true
//                Text{
//                    text: player2Name
//                    Layout.fillWidth: true
//                    font.pointSize: txtSize
//                }
//                Text{
//                    text: player2Time
//                    font.pointSize: txtSize
//                }
//            }
//            RowLayout{
//                Rectangle{
//                    height: 20
//                    Layout.fillWidth: true
//                    radius: 10
//                    color: othelloModel.player2Chance < 1? "gray" : "white"
//                }
//                Rectangle{
//                    height: 20
//                    Layout.fillWidth: true
//                    radius: 10
//                    color: othelloModel.player2Chance < 2? "gray" : "white"
//                }
//                Rectangle{
//                    height: 20
//                    Layout.fillWidth: true
//                    radius: 10
//                    color: othelloModel.player2Chance < 3? "gray" : "white"
//                }
//            }
//        }
//    }
//}
