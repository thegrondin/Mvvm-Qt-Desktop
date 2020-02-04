import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    TextInput {
        id: textInput
        x: 116
        y: 77
        width: 80
        height: 20
        text: qsTr(model.firstname)
        font.pixelSize: 12
    }

    TextInput {
        id: textInput2
        x: 116
        y: 110
        width: 80
        height: 20
        text: qsTr(model.lastname)
        font.pixelSize: 12
    }

    TextInput {
        id: textInput3
        x: 116
        y: 130
        width: 80
        height: 20
        text: model.age
        font.pixelSize: 12
    }


    Button {
        x: 244
        y: 361
        width: 113
        height: 37
        anchors.verticalCenterOffset: 140
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        onClicked: model.executeBtn()
    }

}

/*

   TextBox {
        id: destinationTbx
        x: 200
        y: 277
        width: 348
        height: 27;
        anchors.verticalCenterOffset: 50
        anchors.horizontalCenterOffset: 75
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: model.destinationValue
    }
*/
