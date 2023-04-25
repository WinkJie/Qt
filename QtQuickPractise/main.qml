import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.1

Window {
    visible: true
    width: 640
    height: 480
    title: "Complex Code Example"

    property int counter: 0
    property bool flag: false

    Rectangle {
        id: rect1
        x: 100
        y: 100
        width: 100
        height: 100
        radius: 10
        border.color: red
        border.width: 4

        color: "red"
        Text {
            id: namesize
            text: qsTr("flag is "+flag)
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                rect1.color = "white";
                counter++;
                flag=!flag;
                console.log("Clicked! Counter is now " + counter);
            }
        }
    }

    Rectangle {
        id: rect2
        x: 300
        y: 100
        width: 100
        height: 100
        color: "green"
        Text {
            text: "Counter: " + counter
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                if(flag)
                {
                    console.log("flag is:"+flag);
                }
                else
                {
                    console.info("flag is not:"+flag);
                }
                rect2.color = "yellow"
            }
        }
    }


    Button {
        id: button1
        text: "Reset Counter"
        x: 100
        y: 250
        background: Rectangle {
                color: "#007aff"   // 蓝色
            }
        onClicked: {
            counter = 0;
        }
    }

    TextInput {
        id: textInput1
        x: 300
        y: 250
        width: 200
        //placeholderText: "Enter your name"
        onAccepted: {
            console.log("Hello, " + textInput1.text + "!");
        }
    }
}

//Window {
//    visible: true
//    width: 640
//    height: 480
//    title: qsTr("Hello World")

//}
