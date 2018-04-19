import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    id: configurePage

    // property ///////////////////////////////////////////////////////////
    property int speed: 0

    // signal ///////////////////////////////////////////////////////////

    // main layout ///////////////////////////////////////////////////////////

    ComSidebar {
        anchors.left: parent.left
        anchors.leftMargin: 0
        //            anchors.fill: parent.height
    }

//    Component {
//        id: rightView
//    }

    Loader {
        id: pageLoader
        anchors.right: parent.right
        anchors.rightMargin: 0
        source: "qrc:/ComLive.qml"
        //            sourceComponent: rightView
        focus: true
    }

    Binding {
        property: "speed"
        value: speed
    }

    Connections {
        target: pageLoader.item
        onMessage: {
            console.log("to: " + page)
            pageLoader.source = page
        }

        Component.onCompleted: print("Connections Component.onCompleted")
    }
}
