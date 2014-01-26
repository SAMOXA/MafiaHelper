import QtQuick 2.0

Item {
    PathView{
        id: view
        anchors.fill: parent
        z: 1
        rotation: 90
        interactive: false;
        property int pathMargin: 60
        property real rx: ry//view.width / 2 - pathMargin
        property real ry: view.height / 2 - pathMargin
        property real magic: 0.551784
        property real mx: rx * magic
        property real my: ry * magic
        property real cx: view.width / 2
        property real cy: view.height / 2
        property string mode: "Idle"
        property var selectedItem: null
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
        model: gameController.players
        delegate: Player{
            QtObject{
                id: internal
                property real xCor
                property real yCor
                property real scaleFactor
            }
            name: modelData.name
            pid: modelData.id
            role: modelData.role
            position: index
            imageSource: "qrc:/resources/image/temp.jpg"
            scale: {
                if(gameController.getPlayersCount()>8){
                    0.7*(8/gameController.getPlayersCount())
                }else{
                    0.7
                }
            }
            z: 1
            rotation: -90
            MouseArea{
                anchors.fill: parent
                onPressAndHold: {
                    if(view.mode == "Idle"){
                        internal.xCor = parent.x;
                        internal.yCor = parent.y;
                        internal.scaleFactor = parent.scale
                        mapToItem(view.parent, view.cx, view.cy)
                        parent.x = mapToItem(view.parent, x, y).x;
                        parent.y = mapToItem(view.parent, x, y).y;
                        parent.scale = 2;
                        view.mode = "Centered"
                        view.selectedItem = parent;
                    }
                }
                onClicked: {
                    if(view.mode == "Idle"){
                        internal.scaleFactor = parent.scale
                        parent.scale = parent.scale + parent.scale/100 * 20
                        view.mode = "Selected"
                        view.selectedItem = parent
                        return
                    }
                    if(view.mode == "Selected"){
                        if(view.selectedItem.pid !== parent.pid){
                            view.selectedItem.scale = view.selectedItem.scale/120 * 100
                            view.mode = "Idle"
                            var tPos = view.selectedItem.position
                            view.selectedItem = null
                            gameController.changeOrder(tPos, parent.position)
                        }else{
                            parent.scale = internal.scaleFactor
                            view.mode = "Idle"
                            view.selectedItem = null
                        }
                        return
                    }
                    if(view.mode == "Centered"){
                        if(view.selectedItem.pid === parent.pid){
                            parent.x = internal.xCor;
                            parent.y = internal.yCor;
                            parent.scale = internal.scaleFactor;
                            view.mode = "Idle"
                            view.selectedItem = null
                            return
                        }
                    }
                }
            }
        }
        Connections{
            target: gameController
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
