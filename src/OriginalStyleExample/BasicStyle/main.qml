import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0

ApplicationWindow {
  visible: true
  width: 500
  height: 400
  title: qsTr("Orignal Style Example(static)")

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
      text: qsTr("First")
    }
    TabButton {
      text: qsTr("Second")
    }
  }
}
