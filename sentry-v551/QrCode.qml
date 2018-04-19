import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    id: qrcodePage
    width: 1920
    height: 1080

    // property ///////////////////////////////////////////////////////////

    // signal ///////////////////////////////////////////////////////////
    signal message(string page)
    signal login(string account, string password)

    // main layout ///////////////////////////////////////////////////////////
    Label {
        id: label
        x: 201
        text: qsTr("Scan code with your phone to login")
        anchors.top: image.bottom
        anchors.topMargin: 30
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Image {
        id: switchRight
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/Images/Controls/Page/Arrow/Switch_Right.png"
        Text {
//            id: name
//            text: qsTr("Account/Password")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                qrcodePage.message("Account.qml");
            }
        }
    }

    Image {
        id: image
        x: 270
        y: 190
        width: 100
        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/testQRcode.png"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                qrcodePage.login("qrcode", "qrcode")
            }
        }
    }
}
