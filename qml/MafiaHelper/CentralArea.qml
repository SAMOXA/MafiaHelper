import QtQuick 2.0
import Custom 1.0

Item {
    PathView{
        id: view
        anchors.fill: parent
        z: 1
        //rotation: 90
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
            startX: view.cx; startY: view.cy + view.ry
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
            PathCubic { // first quadrant arc
                control1X: view.cx + view.rx; control1Y: view.cy + view.my
                control2X: view.cx + view.mx; control2Y: view.cy + view.ry
                x: view.cx; y: view.cy + view.ry
            }
        }
        model: gameController.players
        delegate: Player{
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
            //rotation: -90
            onSwap:{
                gameController.setSwap(parent.pid);
            }
            Connections{
                target: modelData
                onModeChanged:{
                    switch(modelData.mode){
                    case PlayerCpp.None:
                        x = modelData.restoreX()
                        y = modelData.restoreY()
                        scale = modelData.restoreScale()
                        selected = false;
                        break;
                    case PlayerCpp.Selected:
                        modelData.saveScale(scale)
                        modelData.saveCoords(x, y)
                        scale = scale + scale/100 * 20
                        break;
                    case PlayerCpp.Centered:
                        modelData.saveScale(scale)
                        modelData.saveCoords(x, y)
                        x = centralAreaCenter.x - width/2
                        y = centralAreaCenter.y - height/2
                        z = 10
                        selected = true;
                        scale = 2
                        break;
                    }
                }
                onStatusChanged: {
                    switch(modelData.status){
                    case PlayerCpp.Alive:
                        killed = false
                        silence = false
                        wasKilled = false
                        break;
                    case PlayerCpp.WasKilled:
                        killed = false
                        silence = false
                        wasKilled = true
                        break;
                    case PlayerCpp.Killed:
                        killed = true
                        silence = false
                        wasKilled = false
                        break;
                    case PlayerCpp.Silenced:
                        silence = true
                        break;
                    }
                }
            }
            MouseArea{
                anchors.fill: parent
                onPressAndHold: {
                    console.log("LongClick")
                    gameController.longClick(parent.pid);
                }
                onClicked: {
                    console.log("Click")
                    gameController.click(parent.pid);
                }
            }
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
