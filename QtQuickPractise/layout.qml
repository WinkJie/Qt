import QtQuick 2.0

//Rectangle{
Rectangle
{
    width: 400
    height: 300
    Rectangle
    {
        anchors.centerIn: parent
        width: 100
        height: 50
        //        Text
        //        {
        //            text: "测试一下，这个控件"
        //            anchors.top:parent
        //            color: "blue"
        //        }
    }
    Rectangle
    {
        anchors.top:parent.top
        anchors.right: parent.right
        width: 150
        height: 50
    }
}
//}
