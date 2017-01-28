import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 550
    height: 400
    title: qsTr("Mix Example(separate files)")

    SwipeView {
        id: swipeView
        anchors.fill: parent

        RowLayout {
//            spacing: 0
            //            anchors.fill: parent
            Controls1 {
                Layout.fillHeight: true
                Layout.fillWidth: true
                onChoiced: {
                    swipeView.currentIndex = 1
                    joinedLabel.text = "Welcome to %1!".arg(name)
                }
            }
            Controls2 {
                Layout.fillHeight: true
                Layout.fillWidth: true
                onChoiced: {
                    swipeView.currentIndex = 1
                    joinedLabel.text = "Welcome to %1!".arg(name)
                }
            }
        }

        Item {
            Label {
                id: joinedLabel
                anchors.centerIn: parent
                //                anchors.centerIn: parent
            }
            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: height
                text: qsTr("Let me pass this time.")
                onClicked: swipeView.currentIndex = 0
            }
        }
    }
    PageIndicator {
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        currentIndex: swipeView.currentIndex
        count: swipeView.count
    }
}
