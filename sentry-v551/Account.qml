import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.2

Item {
    id: accountPage
    width: 1920
    height: 1080

    // property ///////////////////////////////////////////////////////////
//    property alias textField1: password
//    property alias textField: account

    // signal ///////////////////////////////////////////////////////////
    signal message(string page)
    signal login(string account, string password)

    // main layout ///////////////////////////////////////////////////////////
    Image {
        id: switchLeft
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/Images/Controls/Page/Arrow/Switch_Left.png"
        Text {
//            id: name
//            text: qsTr("QR Code")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                accountPage.message("QrCode.qml")
            }
        }
    }

    RowLayout {
        id: rowLayout
        y: 46
        anchors.left: rowLayout1.left
        anchors.leftMargin: 0
        anchors.bottom: rowLayout1.top
        anchors.bottomMargin: 0
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Label {
            text: qsTr("Account")
        }

        TextField {
            id: account
            text: "input"
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }
    }

    RowLayout {
        id: rowLayout1
        y: 66
        anchors.bottom: rowLayout2.top
        anchors.bottomMargin: 0
        anchors.left: rowLayout2.left
        anchors.leftMargin: 0
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Label {
            text: qsTr("Password")
        }

        TextField {
            id: password
            text: "input"
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }
    }

    RowLayout {
        id: rowLayout2
        x: 237
        y: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter


        CheckBox {
            id: checkBox
            style: CheckBoxStyle {
                
            }
        }
        Label {
            id: label
            text: qsTr("Remember Password")
        }
    }

    Button {
        id: button
        x: 280
        y: 17
        text: qsTr("Login")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: rowLayout2.bottom

        onClicked: {
            accountPage.login(account.text, password.text)
        }
    }
}
