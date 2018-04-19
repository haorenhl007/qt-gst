import QtQuick 2.0
import QtQuick.Controls 1.2

import io.qmlinfo 1.0

Rectangle {
    id: mainPage
    visible: true
//    x: 0
//    y: 0
    width: 1280
    height: 720

    // property ///////////////////////////////////////////////////////////
    property alias loaderSource: pageLoader.source

    // signal ///////////////////////////////////////////////////////////
    signal sendMessage(string account, string password)
    signal updateMessage(string state)

    function updateMsg(data){
        console.log(data);
        // check accepted
        if (data.indexOf('Configure') != -1) {
            pageLoader.source = "qrc:/Configure.qml"
        }
    }

    Connections {
        target: pageLoader.item
        onMessage: {
            console.log("to: " + page)
            pageLoader.source = page
        }
        onLogin: {
            mainPage.sendMessage(account, password)
        }
    }

    Component.onCompleted: {
        mainPage.updateMessage.connect(updateMsg);
    }

    // main layout ///////////////////////////////////////////////////////////
    QmlInfo {
        id: qmlInfo
    }

    Loader {
        id: pageLoader

        anchors.fill: parent
        source: "qrc:/QrCode.qml"
    }
}
