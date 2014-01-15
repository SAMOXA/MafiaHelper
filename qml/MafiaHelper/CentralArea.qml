import QtQuick 2.0

Rectangle {
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
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
}
