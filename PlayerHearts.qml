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
