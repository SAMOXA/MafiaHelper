import QtQuick 2.0

Item{
    property string name
    property string role
    property int pid
    property string imageSource
    property string borderColor: "gray"
    width: {
        if(vName.width > 90){
            vName.width+10
        }else{
            100
        }
    }
    height: 160
    Rectangle{
        anchors.fill: parent
        opacity: 0.5
        color: "black"
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
        Text {
            id: vName
            anchors.centerIn: parent
            text: name
            font.pointSize: 15
            font.bold: true
            color: "whitesmoke"
        }
    }
}
