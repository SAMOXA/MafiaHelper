import QtQuick 2.0
import Custom 1.0

Rectangle {
    width: 800
    height: 480
    id: main;
    GameController{
        id: gameController
        Component.onCompleted: {
            cppSideInit()
        }
    }

    PageStack{

    }
}
