import QtQuick 2.0

Rectangle {
    anchors.fill: parent;
    property variant menuItems;
    property variant delegate;
    QtObject {
        id: internal
        property var menuItems: [
            "Начать игру",
            "Настройки",
            "Выход"
        ]
    }
    Image {
        anchors.centerIn: parent
        id: newspaper
        source: "qrc:/resources/image/mainMenu/480.jpg"
        z: 1
        Text {
            anchors.horizontalCenter: parent.horizontalCenter
            y: 99 //TODO Calculate offset
            text: Qt.formatDateTime(new Date(), "НЬЮ-ЙОРК, dddd, MMMM, dd, yyyy")
            font.pixelSize: 13 //TODO calculate font size
            font.family: "Times New Roman"
            font.italic: true
            font.capitalization: Font.AllUppercase;
        }
        Text {
            id: caption;
            anchors.horizontalCenter: parent.horizontalCenter
            y: 135 //TODO calculate offset
            text: qsTr("Мафия объявляет городу войну!!!")
            font.pixelSize: 33 //TODO calculate font size
            font.family: "Times New Roman"
            font.italic: true
            font.bold: true
        }
        Column{
            id: subtitle
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.horizontalCenterOffset: width/2 + 3 //TODO Calculate offset
            y: 185 //TODO calculate offset
            Text {
                text: qsTr("Либо мы их, либо")
                font.pixelSize: 16; font.family: "Times New Roman"
                font.italic: true; font.bold: true
            }
            Text {
                text: qsTr("они нас, хватит")
                font.pixelSize: 16; font.family: "Times New Roman"
                font.italic: true; font.bold: true
            }
            Text {
                text: qsTr("это терпеть.")
                font.pixelSize: 16; font.family: "Times New Roman"
                font.italic: true; font.bold: true
            }
            Text {
                text: qsTr(" - Мэр города")
                font.pixelSize: 16; font.family: "Times New Roman"
                font.italic: true; font.bold: true
            }
        }
        RectText {
            width: subtitle.width
            anchors.top: subtitle.bottom; anchors.topMargin: 15
            anchors.bottom: newspaper.bottom; anchors.bottomMargin: 10
            anchors.left: subtitle.left
            elementWidth: 6
            elementHeight: 6
        }
        RectText {
            width: subtitle.width
            anchors.top: caption.bottom; anchors.topMargin: 7
            anchors.left: subtitle.right; anchors.leftMargin: 10
            anchors.bottom: newspaper.bottom; anchors.bottomMargin: 10;
            elementWidth: 6
            elementHeight: 6
            offset: 300
            beginFromUpperCase: false
        }
        Item{
            id: menu
            anchors.top: caption.bottom; anchors.topMargin: 7
            anchors.left: parent.left; anchors.leftMargin: 10
            anchors.bottom: parent.bottom; anchors.bottomMargin: 10
            anchors.right: subtitle.left; anchors.rightMargin: 10
            Column{
                anchors.centerIn: parent;
                spacing: 10
                Repeater {
                    model: internal.menuItems;
                    delegate: Text {
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 30; font.family: "Times New Roman"
                        font.italic: true; font.bold: true
                        text: modelData
                    }
                }
            }
            z: 2
        }
    }
    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/resources/image/bg.jpg"
        fillMode: Image.Tile
    }
}
