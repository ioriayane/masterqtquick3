import QtQuick 2.8
import QtQuick.Templates 2.1 as T

T.TabBar {
  id: root
  implicitHeight: contentItem.implicitHeight

  contentItem: ListView {
    implicitWidth: contentWidth
    implicitHeight: currentItem.implicitHeight

    model: root.contentModel
    currentIndex: root.currentIndex

    orientation: ListView.Horizontal
    highlightMoveDuration: 250
    highlightResizeDuration: 0
    highlightFollowsCurrentItem: true

    highlight: Item {
      z: 10
      Rectangle {
        anchors.fill: parent
        anchors.margins: 1
        border.color: "#ddc29a"
        border.width: 1
        color: "#00ffffff"
      }
    }
  }
}
