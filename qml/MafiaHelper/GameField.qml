import QtQuick 2.0

Rectangle {
    anchors.fill: parent;

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
