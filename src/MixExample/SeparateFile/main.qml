import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

ApplicationWindow {
  visible: true
  width: 500
  height: 400
  title: qsTr("Mix Example(separate file)")

  SwipeView {
    id: swipeView
    anchors.fill: parent

    RowLayout {
      //Controls 1で作られたエレメント
      Controls1 {
        Layout.fillHeight: true
        Layout.fillWidth: true
        onChoiced: {
          swipeView.currentIndex = 1
          joinedLabel.text = "Welcome to %1!".arg(name)
        }
      }
      //Controls 2で作られたエレメント
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
