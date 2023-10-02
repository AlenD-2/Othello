import QtQuick

Rectangle{
    id: passTurnRect
    width: 340
    height: 150
    opacity: 0.85
    anchors.centerIn: parent
    visible: false
    border.width: 2

    property bool passFlag: false
    onPassFlagChanged: {
        if(passFlag)
        {
            passAnime.start()
        }
    }

    Text{
        id: gameOverTxt
        text: "Turn Pass!"
        font.pointSize: 32
        font.bold: true
        anchors{
            top: parent.top
            topMargin: 10
            horizontalCenter: parent.horizontalCenter
        }
    }


    SequentialAnimation{
        id: passAnime
        onStarted: {
            passTurnRect.visible = true
        }
        onFinished: {
            passTurnRect.visible = false
            othelloModel.nextTurn()
        }
        NumberAnimation {
            target: passTurnRect
            property: "opacity"
            from: 0
            to: 0.85
            duration: 1000
            easing.type: Easing.OutCubic
        }
        NumberAnimation {
            target: passTurnRect
            property: "opacity"
            from: 0.85
            to: 0
            duration: 1000
            easing.type: Easing.InCubic
        }
    }

}
