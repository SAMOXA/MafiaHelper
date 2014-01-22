import QtQuick 2.0

Item {
    PathView{
        id: view
        anchors.fill: parent
        z: 1
        rotation: 90
        property int pathMargin: 50
        property real rx: ry//view.width / 2 - pathMargin
        property real ry: view.height / 2 - pathMargin
        property real magic: 0.551784
        property real mx: rx * magic
        property real my: ry * magic
        property real cx: view.width / 2
        property real cy: view.height / 2
        path: Path {
            startX: view.cx + view.rx; startY: view.cy
            PathCubic { // first quadrant arc
                control1X: view.cx + view.rx; control1Y: view.cy + view.my
                control2X: view.cx + view.mx; control2Y: view.cy + view.ry
                x: view.cx; y: view.cy + view.ry
            }
            PathCubic { // second quadrant arc
                control1X: view.cx - view.mx; control1Y: view.cy + view.ry
                control2X: view.cx - view.rx; control2Y: view.cy + view.my
                x: view.cx - view.rx; y: view.cy
            }
            PathCubic { // third quadrant arc
                control1X: view.cx - view.rx; control1Y: view.cy - view.my
                control2X: view.cx - view.mx; control2Y: view.cy - view.ry
                x: view.cx; y: view.cy - view.ry
            }
            PathCubic { // forth quadrant arc
                control1X: view.cx + view.mx; control1Y: view.cy - view.ry
                control2X: view.cx + view.rx; control2Y: view.cy - view.my
                x: view.cx + view.rx; y: view.cy
            }
        }
        model: gameControllerBackend.getPlayers()
        delegate: Player{
            name: modelData.name
            pid: modelData.id
            role: modelData.role
            imageSource: "qrc:/resources/image/players/0.png"
            scale: 0.5
            z: 1
            rotation: -90
        }
    }

    Rectangle{
        id: centralAreaCenter
        anchors.centerIn: parent
        width: 2
        height: 2
        color: "red"
        z: 1
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
        onPressAndHold: {

        }
    }
    Image {
        id: bg
        anchors.fill: parent
        source: "qrc:/resources/image/gameField/bg.jpg"
        fillMode: Image.Tile
    }
}
