import QtQuick 2.0

Rectangle  {
    id: container;
    SystemPalette { id: myPalette; colorGroup: SystemPalette.Active }
    property string text: "Button";
    property real additionalWidth: 20;
    property real additionalHeight: 5;
    signal clicked;

    width: buttonLabel.width + additionalWidth;
    height: buttonLabel.height + additionalHeight;
    border{
        width: 1;
        color: Qt.darker(myPalette.button);
    }
    smooth: true
    radius: 8
    // color the button with a gradient
    gradient: Gradient  {
        GradientStop  {
            position: 0.0
            color:  {
                if (mouseArea.pressed)
                    return myPalette.dark
                else
                    return myPalette.light
            }
        }
        GradientStop  { position: 1.0; color: myPalette.button }
    }

    MouseArea  {
        id: mouseArea
        anchors.fill: parent
        onClicked: container.clicked();
    }

    Text  {
        id: buttonLabel
        anchors.centerIn: container
        color: myPalette.buttonText
        text: container.text
        font.pixelSize: 20;
    }
}
