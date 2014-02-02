import QtQuick 2.0
import Custom 1.0

Item {
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
        text: qsTr("Раунд %1".arg(gameController.round))
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
        text: {
            switch(gameController.phase){
            case GameController.Night:
                qsTr("Ночь")
                break;
            case GameController.Results:
                qsTr("Утро")
                break;
            case GameController.Linch:
                qsTr("День")
                break;
            default:
                qsTr("ФАТАЛ ЕРРОР")
            }
        }
        color: "whitesmoke"
        font.pixelSize: 25 //TODO calculate font size
        font.family: "Times New Roman"
        font.bold: true
        z: 2
    }
    Text {
        id: subPhase
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: phase.bottom
        anchors.topMargin: 10
        text: {
            if(gameController.phase !== GameController.Linch){
                qsTr("Ходит %1".arg(gameController.selectedRole))
            }else{
                qsTr("Выборы")
            }
        }
        color: "whitesmoke"
        font.pixelSize: 20 //TODO calculate font size
        font.family: "Times New Roman"
        font.bold: true
        z: 2
    }
    Rectangle{
        anchors.top: subPhase.bottom
        anchors.bottom: settings.top
        width: parent.width
        anchors.horizontalCenter: parent.horizontalCenter
        z: 2
        color: "transparent"
        Column{
            spacing: 10
            anchors.centerIn: parent;
            Repeater{
                model: gameController.actions
                delegate: Button{
                    anchors.horizontalCenter: parent.horizontalCenter
                    text: modelData
                    onClicked: {
                        gameController.menuClick(index)
                    }
                }
            }
        }
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
