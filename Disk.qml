import QtQuick

Flipable {
    id: flipable

    property bool doFlip: false
    property bool flipped: false
    property int frontCol: 1

    front: Rectangle{
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        color: (frontCol === white)? "black" : "white"
        radius: width/2
    }
    back: Rectangle{
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        color: (frontCol === white)? "white" : "black"
        radius: width/2
    }

    transform: Rotation {
        id: rotation
        origin.x: flipable.width/2
        origin.y: flipable.height/2
        axis.x: 0; axis.y: 1; axis.z: 0     // set axis.y to 1 to rotate around y-axis
        angle: 0    // the default angle
    }

    states: State {
        name: "back"
        PropertyChanges { target: rotation; angle: 180 }
        when: flipable.flipped
    }

    transitions: Transition {
        NumberAnimation {
            target: rotation;
            property: "angle";
            duration: root.aiDelayValue
            easing.type: Easing.OutQuart
        }
    }

    onDoFlipChanged: {
        if(doFlip)
            flipable.flipped = !flipable.flipped
    }

}
