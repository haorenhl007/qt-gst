import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: item1

    // todo: full screen

    Label {
        id: label
        x: 201
        text: qsTr("Scan code with your phone to login")
        anchors.top: image.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
        id: button
        x: 454
        y: 228
        text: qsTr("Account/Password")
        anchors.right: parent.right
        anchors.rightMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        iconSource: "qrc:/Images/Controls/Page/Arrow/Switch_Right.png"
    }

    Image {
        id: image
        x: 270
        y: 190
        width: 100
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

}
