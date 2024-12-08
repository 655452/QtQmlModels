import QtQuick 2.12

Rectangle {
    id:popUp
    color: "lightblue"
    border.color: "blue"
    border.width: 2
    radius: 10
    anchors.left:addButton.right
    implicitHeight: 200
    implicitWidth: 200

    MouseArea {
        anchors.fill: parent
        onClicked: {
            parent.destroy(); // Destroy the rectangle when clicked
        }
    }

    Component.onCompleted: {
        console.log(popUp)
    }
    Component.onDestruction:  {
        console.log("component destroyed")
    }
}
