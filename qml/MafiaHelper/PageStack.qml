import QtQuick 2.0

Rectangle{
    id: pageStack;
    anchors.fill: parent;
    property string  currentPage : pageStackBackend.popPage();
    //TODO Non savable pages in one loader
//    Loader {
//        id: mainLoader;
//        active: true;
//        asynchronous: true;
//        anchors.fill: parent;
//        visible: (currentPage === modelData);
//        source: "%1.qml".arg(modelData)
//        onVisibleChanged:      { loadIfNotLoaded(); }
//        Component.onCompleted: { loadIfNotLoaded(); }
//        function loadIfNotLoaded () {
//            if (visible && !active) {
//                active = true;
//            }
//        }
//    }
    Repeater {
        model: pageStackBackend.getPageToSave();
        delegate: Loader {
            active: false;
            asynchronous: true;
            anchors.fill: parent;
            visible: (currentPage === modelData);
            source: "%1.qml".arg(modelData)
            onVisibleChanged:      { loadIfNotLoaded(); }
            Component.onCompleted: {
                loadIfNotLoaded();
            }
            function loadIfNotLoaded () {
                if (visible && !active) {
                    active = true;
                }
            }
        }
    }
}
