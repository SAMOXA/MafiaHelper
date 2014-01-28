import QtQuick 2.0
import "textGenerator.js" as Logic

Item {
    id: root
    property real elementWidth
    property real elementHeight
    property int offset: 0
    property real spacing: 5
    property real textOpacity: 0.8
    property bool randomSize: true
    property bool beginFromUpperCase: true
    Repeater{
        model: Logic.generateText(root.width, root.height, elementWidth, elementHeight, offset, spacing, beginFromUpperCase)
        delegate: Item{
            y: Math.round(index*(elementHeight+spacing))
            Row{
                Repeater{
                    model: modelData
                    delegate: Rectangle {
                        opacity: root.textOpacity
                        y: {
                            if(modelData === 2){
                                0
                            }else{
                                Math.round(elementHeight/100*50)
                            }
                        }
                        color: {
                            if(modelData === 0){
                                "white"
                            }else{
                                "black"
                            }
                        }
                        width: {
                            if(modelData < 0){
                                elementWidth + Math.abs(modelData)
                            }else{
                                elementWidth
                            }
                        }
                        height: {
                            if(modelData === 2){
                                elementHeight + Math.round(elementHeight/100*50)
                            }else{
                                elementHeight
                            }
                        }
                    }
                }
            }
        }
    }
}
