import QtQuick 2.0
import QtQuick.Controls 1.3

Item {
    Image {
        id: image
        x: 8
        y: 8
        width: 100
        height: 100
        source: "qrc:/qtquickplugin/images/template_image.png"
    }

    Button {
        id: button
        x: 18
        y: 137
        text: qsTr("Button")
    }

    Button {
        id: button1
        x: 18
        y: 183
        text: qsTr("Button")
    }

    Button {
        id: button2
        x: 18
        y: 228
        text: qsTr("Button")
    }

    Button {
        id: button3
        x: 18
        y: 365
        text: qsTr("Button")
    }

    Button {
        id: button4
        x: 18
        y: 411
        text: qsTr("Button")
    }

}
