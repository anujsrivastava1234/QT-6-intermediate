import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("QML Datatypes Demo")

    property string mString: "Hello"
    property int mInt: 45
    property bool isFemale: false
    property url mUrl: "https://doc.qt.io/"
    property var anArray: [1,2,3,"four","five",(function(){return "six"})]
    property var aFunction: (function(){return "Seven"})

    Rectangle{
        width: 200
        height: 100 + mInt
        anchors.centerIn: parent
        color: "yellow"

        Text {
            id: textId
            text: mUrl
            anchors.centerIn: parent
            font.bold: isFemale
        }

        Component.onCompleted: {
            console.log("The value of the string property is : "+mString);
            console.log("The value of mInt is : "+mInt);

            if(isFemale){
                console.log("You may wear a dress");
            }else {
                console.log("You may wear a suit")
            }

            //destructing the function -> for method
            for(var i=0;i<anArray.length;i++)
            {
                if(i===5)
                {
                    console.log(anArray[i]())
                }else {
                    console.log(anArray[i])
                }
            }

            //destructinng the function -> forEach
            anArray.forEach(function(value,index){
                if(index===5){
                    console.log(value())
                }else {
                    console.log(value)
                }
            })

            console.log("The value of aFunction : "+aFunction())
        }

    }
}
