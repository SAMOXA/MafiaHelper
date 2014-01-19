import QtQuick 2.0

Rectangle {
    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/resources/image/gameField/bg.jpg"
        fillMode: Image.Tile
    }
    Rectangle{
        anchors.fill: parent;
        z: 1
        opacity: 0.7
        color: "black"
    }
    Text {
        id: round
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: 10
        text: qsTr("Раунд 4")
        color: "whitesmoke"
        font.pixelSize: 30 //TODO calculate font size
        font.family: "Times New Roman"
        font.bold: true
        z: 2
    }
    Text {
        id: phase
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: round.bottom
        anchors.topMargin: 10
        text: qsTr("Ночь")
        color: "whitesmoke"
        font.pixelSize: 25 //TODO calculate font size
        font.family: "Times New Roman"
        font.bold: true
        z: 2
    }
    Text {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: phase.bottom
        anchors.topMargin: 10
        text: qsTr("Ход доктора")
        color: "whitesmoke"
        font.pixelSize: 20 //TODO calculate font size
        font.family: "Times New Roman"
        font.bold: true
        z: 2
    }

    Rectangle{
        id: settings
        anchors.bottom: parent.bottom
        width: parent.width
        color: "whitesmoke"
        height: 70
        opacity: 0.5
        z: 2
    }
    Text {
        anchors.centerIn: settings
        text: qsTr("Настройки")
        color: "white"
        font.pixelSize: 20 //TODO calculate font size
        font.family: "Times New Roman"
        font.bold: true
        z: 3
    }
}
