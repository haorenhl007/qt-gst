import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.2

Item {
//    objectName: accoutPage
    id: accountPage
    width: 1920
    height: 1080

    property alias textField1: textField1
    property alias textField: textField

    // PageLoader using
    signal message(string page)

    // MQTT using
    signal qmlSetName(string account, string password)
    signal qmlUpdateName( string name )

//    Button {
//        id: button1
//        iconSource: "qrc:/Images/Controls/Page/Arrow/Switch_Left.png"
//        x: 69
//        y: 228
//        text: qsTr("QR Code")
//        anchors.verticalCenter: parent.verticalCenter

        // todo: if source link failed, process
//        onStatesChanged: {
//            console.log("State change to " + state)
//        }
//        onClicked: {
//            accountPage.message("QRCode.qml");
//        }
//    }
    Image {
        id: switchLeft
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.verticalCenter: parent.verticalCenter
        source: "qrc:/Images/Controls/Page/Arrow/Switch_Left.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                accountPage.message("QRCode.qml")
            }
        }
    }

    RowLayout {
        id: rowLayout
        y: 46
//        width: 100
//        height: 100
        anchors.left: rowLayout1.left
        anchors.leftMargin: 0
        anchors.bottom: rowLayout1.top
        anchors.bottomMargin: 0
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Label {
            text: qsTr("Account")
            //                anchors.verticalCenterOffset: -14
            //                anchors.horizontalCenterOffset: -81
            //                anchors.centerIn: parent
        }

        TextField {
            id: textField
            text: "input"
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }
    }

    RowLayout {
        id: rowLayout1
        y: 66
//        width: 100
//        height: 100
        anchors.bottom: rowLayout2.top
        anchors.bottomMargin: 0
        anchors.left: rowLayout2.left
        anchors.leftMargin: 0
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        Label {
            text: qsTr("Password")
            //                anchors.verticalCenterOffset: 26
            //                anchors.horizontalCenterOffset: -81
            //                anchors.centerIn: parent
        }

        TextField {
            id: textField1
            text: "input"
            Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
            placeholderText: qsTr("Text Field")
        }
    }

    RowLayout {
        id: rowLayout2
        x: 237
        y: 100
//        width: 100
//        height: 100
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter


        CheckBox {
            id: checkBox
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
        //        Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter

        onClicked: {
            accountPage.qmlSetName(textField.text, textField1.text)
        }
    }

    function updateMsg( data ){
//        txtName.text = data
        console.log( data );
    }

    Component.onCompleted:
    {
        accountPage.qmlUpdateName.connect( updateMsg );
    }
}
