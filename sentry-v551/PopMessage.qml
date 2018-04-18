import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: item1
    visible: false
    width: 1920
    height: 1080

    Label {
        id: label
        x: 294
        y: 245
        text: qsTr("Your Account do not match this Sentry.")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }

}
