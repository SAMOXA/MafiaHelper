import QtQuick 2.0

Rectangle {
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
        z: 1
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
        onPressAndHold: {
            console.log("LOLOO")
        }
    }
    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/resources/image/gameField/bg.jpg"
        fillMode: Image.Tile
    }
}
