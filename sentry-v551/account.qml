import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick.Layouts 1.2

ApplicationWindow {
    id: applicationWindow
    visible: true
    visibility: "FullScreen"
//    width: 640 //width: Screen.width
//    height: 480 //height: Screen.height
    title: qsTr("Hello World")
//    flags: Qt.WA_TranslucentBackground | Qt.FramelessWindowHint
//    color: Qt.rgba(0.9, 0.9, 0.9, 0.9)
    property alias textField1: textField1
    property alias textField: textField //color: "transparent"
//    menuBar: MenuBar {
//        Menu {
//            title: qsTr("File")
//            MenuItem {
//                text: qsTr("&Open")
//                onTriggered: console.log("Open action triggered");
//            }
//            MenuItem {
//                text: qsTr("Exit")
//                onTriggered: Qt.quit();
//            }
//        }
//    }

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();
//        }
//    }

    signal qmlSetName(string account, string password)
    signal qmlUpdateName( string name )

    Button {
        id: button1
        iconSource: "qrc:/Images/Controls/Page/Arrow/Switch_Left.png"
        x: 69
        y: 228
        text: qsTr("QR Code")
        anchors.verticalCenter: parent.verticalCenter

        // todo: if source link failed, process
//        onStatesChanged: {
//            console.log("State change to " + state)
//        }
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
            applicationWindow.qmlSetName(textField.text, textField1.text)
        }
    }

    function updateMsg( data ){
//        txtName.text = data
        console.log( data );
    }

    Component.onCompleted:
    {
        applicationWindow.qmlUpdateName.connect( updateMsg );
    }
}

