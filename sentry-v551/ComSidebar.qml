import QtQuick 2.0
import QtQuick.Controls 1.3

Item {

    id: comSidebar
    // PageLoader using
    signal message(string page)

    Image {
        id: image
        x: 8
        y: 8
        width: 100
        height: 100
//        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Button {
        id: button
        x: 18
        y: 137
        text: qsTr("Live")
        onClicked: {
            comSidebar.message("ComLive.qml")
        }
    }

    Button {
        id: button1
        x: 18
        y: 183
        text: qsTr("Playback")
        onClicked: {
            comSidebar.message("ComPlayback.qml")
        }
    }

    Button {
        id: button2
        x: 18
        y: 228
        text: qsTr("Event")
        onClicked: {
            comSidebar.message("ComEvent.qml")
        }
    }

    Button {
        id: button3
        x: 18
        y: 365
        text: qsTr("Setting")
        onClicked: {
            comSidebar.message("ComSetting.qml")
        }
    }

    Button {
        id: button4
        x: 18
        y: 411
        text: qsTr("Logout")
        onClicked: {
            comSidebar.message("Account.qml")
        }
    }

    Component.onCompleted: {
        print("ComSidebar Component.onCompleted")
        comSidebar.message("signal sent");
    }
}
