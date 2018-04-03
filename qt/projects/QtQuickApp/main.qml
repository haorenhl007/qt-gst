import QtQuick 2.7
import QtQuick.Window 2.2

//Window {
//Rectangle {

//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")

//    color: Qt.rgba(0.5, 0.5, 0.5, 0.9)
//    color: "transparent"
//    MouseArea {
//        id: dragRegion
//        anchors.fill: parent
//        property point clickPos: "0,0"
//        onPressed: {
//            clickPos = Qt.point(mouse.x, mouse.y)
//        }
//        onPositionChanged: {
//            var delta = Qt.point(mouse.x - clickPos.x, mouse.y - clickPos.y)
//            mainwindow.setX(mainwindow.x + delta.x)
//            mainwindow.setY(mainwindow.y + delta.y)
//        }
//    }

//    MainForm {
//        anchors.fill: parent
//        Rectangle {
//            anchors.fill: parent
//            color: "transparent"
//            border.width: 1
//        }

//        MouseArea.onClicked: {
//            Qt.quit();
//        }
//    }

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();//console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
//        }
//    }

//    TextEdit {
//        id: textEdit
//        text: qsTr("Enter some text...")
//        verticalAlignment: Text.AlignVCenter
//        anchors.top: parent.top
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.topMargin: 20
//        Rectangle {
//            anchors.fill: parent
//            anchors.margins: -10
//            color: "transparent"
//            border.width: 1
//        }
//    }

//    Rectangle {
//        width: 100
//        height: 50
//        anchors.centerIn: parent
//        color: "transparent"

//        border.color: "#F00"
//        border.width: 5
//        radius: 10
//    }
//}

//Window {
Rectangle {
    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")
//    color: Qt.rgba(0.5, 0.5, 0.5, 0.9)
//    color: "transparent"

    Rectangle {
        color: "steelblue"
        width: 40; height: 40
    }
    Rectangle {
        color: "transparent"
        y: 40; width: 40; height: 40
    }
    Rectangle {
        color: "#FF0000"
        y: 80; width: 40; height: 40
    }
    Rectangle {
        color: "#800000FF"
        y: 120; width: 40; height: 40
    }
    Rectangle {
        color: "#00000000"    // ARGB fully transparent
        y: 160
        width: 40; height: 40
    }
    Text {
        color: "red"
        // prints "1 0 0 1"
        Component.onCompleted: console.log(color.r, color.g, color.b, color.a)
    }
}
