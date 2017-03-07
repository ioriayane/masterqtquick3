import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import OriginalStyle 1.0              // [1]

ApplicationWindow {
  id: root
  visible: true
  width: 500
  height: 400
  title: qsTr("Orignal Style Example(dynamic)")

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex
    Page1 {
    }
    Item {
      Label {
        text: qsTr("Second page")
        anchors.centerIn: parent
      }
    }
  }

  footer: TabBar {
    id: tabBar
    currentIndex: swipeView.currentIndex
    TabButton {
      OriginalStyle.theme: OriginalStyle.Blue // [2]
      text: qsTr("First")
    }
    TabButton {
      OriginalStyle.theme: OriginalStyle.Blue // [3]
      text: qsTr("Second")
    }
  }
}
