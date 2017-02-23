import QtQuick 2.8
import QtQuick.Templates 2.1 as T

T.TabBar {
  id: root
  implicitWidth: 200
  implicitHeight: contentItem.implicitHeight

  contentItem: ListView {
      implicitWidth: contentWidth
      implicitHeight: currentItem.implicitHeight

      model: root.contentModel
      currentIndex: root.currentIndex

      spacing: root.spacing
      orientation: ListView.Horizontal
  }
  background: Rectangle {
      color: "#eeeeee"
  }
}
