import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import OriginalStyle 1.0
import QtQuick.Controls.Material 2.1

ApplicationWindow {
  id: root
  visible: true
  width: 500
  height: 400
  title: qsTr("Orignal Style Example")

  OriginalStyle.theme: OriginalStyle.Blue
  Material.theme: Material.Light

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex

    OriginalStyle.theme: OriginalStyle.Red
    Material.theme: Material.Dark
    Page1 {
      button1.onClicked: {
        console.debug("root:" + root.OriginalStyle.theme)
        console.debug("swipeView:" + swipeView.OriginalStyle.theme)
//        console.debug("current:" + OriginalStyle.theme)
        //テーマチェンジ
//        root.OriginalStyle.theme = OriginalStyle.Red
//        dialog.show()
        pop.open()
      }
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

  ApplicationWindow {
    id: dialog
    visible: false
    property int t: -1//OriginalStyle.theme
    OriginalStyle.theme: OriginalStyle.Red
    Button {
      text: "click"
      onClicked: {
        console.debug("theme:" + OriginalStyle.theme + ":" + dialog.t)
        console.log("material:" + Material.theme)
      }
    }
  }
  Popup {
    id: pop
    Button {
      onClicked: pop2.open()
    }
    Popup {
      id: pop2
      x:100
      y:100
      width: 350
      height: 300
      modal: true
      property int t: OriginalStyle.theme
      OriginalStyle.theme: OriginalStyle.Red
      Button {
        width: 100
        objectName: "popup->button"
        text: "click"
        onClicked: {
          console.debug("theme:" + OriginalStyle.theme + ":" + pop2.t)
          console.log("material:" + Material.theme)
        }
      }
    }
  }
}
