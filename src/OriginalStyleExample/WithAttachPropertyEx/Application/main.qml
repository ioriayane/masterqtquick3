import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import OriginalStyle 1.0

ApplicationWindow {
  id: root
  visible: true
  width: 500
  height: 400
  title: qsTr("Orignal Style Example")

  OriginalStyle.theme: 1

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex

    Page1 {
      OriginalStyle.theme: 2
      property int theme: OriginalStyle.theme
      button1.onClicked: console.log("theme:" + theme)
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
