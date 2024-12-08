import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls  2.0
import com.example 1.0

Window {
    id:main
    width: 640
    height: 480
    visible: true
    title: qsTr("Dynamic Rectangle")

    Column {
        anchors.centerIn: parent
        spacing: 10


        ListView {
            id:model1
            width: parent.width
            height: 300
            model: myModel

            delegate: Rectangle {
                width: ListView.view.width
                height: 40
                border.color: "black"
                border.width: 1
                anchors.left:main.left

                Row {
                    spacing: 10
                    anchors.centerIn: parent

                    Text {
                        text: "ID: " + model.id
                        font.bold: true
                    }

                    Text {
                        text: "Name: " + model.name
                    }
                }
            }
        }
        // for model 2
        ListView {
            id:model2
            width: parent.width
            height: 300
            model: customM
            anchors.right:main.right

            delegate: Rectangle {
                width: ListView.view.width
                height: 40
                border.color: "black"
                border.width: 1

                Row {
                    spacing: 10
                    anchors.centerIn: parent

                    Text {
                        text: "ID: " + model.id
                        font.bold: true
                    }

                    Text {
                        text: "Name: " + model.name
                    }
                }
            }
        }

        Button {
            text: "Add Item"
            onClicked: myModel.addItem(Math.floor(Math.random() * 100), "Item " + (myModel.count + 1))
        }
        Button {
            text: "Add Item 2"
            onClicked: myModel2.addItem(Math.floor(Math.random() * 100), "Item " + (myModel2.count + 1))
        }

        Button {
            text: "Remove Last Item from model2"
            onClicked: {
                // console.log(myModel.rowCount()+" "+myModel.count)
                if (myModel2.rowCount() > 0)
                    myModel2.removeItem(myModel2.rowCount() - 1)
            }
        }
        Button {
            text: "Remove Last Item"
            onClicked: {
                // console.log(myModel.rowCount()+" "+myModel.count)
                if (myModel.rowCount() > 0)
                    myModel.removeItem(myModel.rowCount() - 1)
            }
        }
    }

    // CustomModel {
    //     id: myModel
    // }

    // CustomModel {
    //     id: myModel2
    // }




    // // Container for dynamically created items
    // Rectangle {
    //     id: container
    //     anchors.fill: parent
    //     color: "#f0f0f0"

    //     Button {
    //         id: addButton
    //         text: "Add Rectangle"
    //         width: 120
    //         height: 40
    //         anchors.top: parent.top
    //         anchors.horizontalCenter: parent.horizontalCenter
    //         anchors.topMargin: 20

    //         onClicked: {
    //             addRectangle()
    //             // container.children.for((e)=>{ console.log(e)})
    //             console.log(container.children[0].toString())
    //         }
    //     }
    // }

    function addRectangle() {
        var component = Qt.createComponent("RectangleComponent.qml");
        if (component.status === Component.Ready) {
            var dynamicRect = component.createObject(container);
            if (dynamicRect === null) {
                console.log("Error creating object");
            }
        } else {
            console.log("Error loading component:", component.errorString());
        }
    }
}
