import QtQuick 2.0
import QtGraphicalEffects 1.0

Item{
    property string name
    property string role
    property int pid
    property string imageSource
    property string borderColor: "gray"
    property int position
    property bool selected: false
    property bool killed: false
    property bool silence: false
    property bool wasKilled: false
    signal swap;
    width: {
        if(vName.width > 90){
            vName.width+10
        }else{
            100
        }
    }
    height: 180
    Rectangle{
        anchors.fill: parent
        opacity: {
            if(selected === true){
                0.9
            }else{
                0.5
            }
        }
        color:{
            if(silence === true){
                "blue"
                return
            }
            if(wasKilled === true){
                "red"
                return
            }
            "black"
        }
        radius: 7
        border.color: borderColor
        border.width: 2
        z: -1
    }

    Image {
        id: img
        anchors.top: parent.top
        anchors.topMargin: 3
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        source: imageSource
        fillMode: Image.PreserveAspectFit
        height: 130
    }
    Item{
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.top: img.bottom
        anchors.topMargin: 2
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        Column{
            anchors.fill: parent
            Text {
                id: vName
                anchors.horizontalCenter: parent.horizontalCenter
                text: name
                font.pointSize: 15
                font.bold: true
                color: "whitesmoke"
                MouseArea{
                    anchors.fill: parent;
                    onClicked: {
                        swap();
                    }
                }
            }
            Text {
                anchors.horizontalCenter: parent.horizontalCenter
                text: role
                font.pointSize: 13
                font.bold: true
                color: "whitesmoke"
                MouseArea{
                    anchors.fill: parent;
                    onClicked: {
                        swap();
                    }
                }
            }
        }
    }
    Colorize{
        anchors.fill: parent
        source: parent
        saturation: 0
        hue: 0
        lightness: 0
        visible: killed
    }
}
