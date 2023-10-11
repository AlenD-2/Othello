import QtQuick

Item {
    id: timer
    property int initTime: 90
    property bool pauseTimer: false

    onPauseTimerChanged: {
        if(pauseTimer)
            timerAnime.pause()
        else
            timerAnime.resume()
    }

    Text{
        id: timerTxt
        text: initTime
    }

    NumberAnimation {
        id: timerAnime
        loops: Animation.Infinite
        running: true
        target: timerTxt
        property: "text"
        from: 90
        to: 0
        duration: initTime*1000
    }
}
