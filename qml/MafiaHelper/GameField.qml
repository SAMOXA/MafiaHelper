import QtQuick 2.0

Rectangle {
    width: 800
    height: 480
    LeftMenu{
        id: leftMenu
        width: parent.width/100*20
        height: parent.height
    }
    CentralArea{
        id: centralArea
        width: parent.width/100*80
        height: parent.height
        anchors.left: leftMenu.right
    }
}
