import QtQuick 2.0
import QtQuick.Controls 1.2

ApplicationWindow {
    id: mainPage
    visible: true
    visibility: "FullScreen"

    property bool isFirst: false;

//    function pageSwitch() {
//        if (isFirst) {
//            pageLoader.source = "account.qml"
//        } else {
//            pageLoader.source = "qrcode.qml"
//        }
//        isFirst = !isFirst;
//    }

//    MouseArea {
//        anchors.fill: parent
//        onClicked: pageSwitch();
//    }

    Loader {
        objectName: "pageLoader"
        id: pageLoader
        source: "qrc:/QRCode.qml"
//        sourceComponent: rect
//        focus: true
    }
    Connections {
        target: pageLoader.item
        onMessage: {
            console.log(page)
            pageLoader.source = page
        }
    }

    Rectangle {
        id: flowTest
        width: 30
        height: 30
        visible: true
//        color: parent.color
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        MouseArea {
            anchors.fill: parent
            onClicked: {
                pageLoader.source = "Configure.qml"
            }
        }
    }
}
