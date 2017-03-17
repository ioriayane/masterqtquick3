import QtQuick 2.8
import QtQuick.Templates 2.1 as T
import QtQuick.Layouts 1.2

T.TabButton {
  id: root
  //サイズ
  implicitWidth: padding + layout.spacing
                 + mark.width + text.contentWidth * 1.5
  implicitHeight: padding + text.contentHeight * 2.5
  padding: 10

  //前景（ボタン上に配置する文字など）
  contentItem: RowLayout {
    id: layout
    Rectangle {
      id: mark
      width: height
      height: text.contentHeight
      radius: width / 2
      color: "#f08200"
      Text {
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        color: "#5d150a"
        text: ">"
        font.bold: true
        font.pointSize: text.font.pointSize - 1
      }
    }
    Text {
      id: text
      Layout.fillWidth: true
      horizontalAlignment: Text.AlignHCenter
      text: root.text
      color: root.hovered ? "#ff4444" : "#ffffff"
    }
  }
  //背景（ボタンっぽい形など）
  background: Rectangle {
    id: rect
    border.color: "#5d150a"
    border.width: 2
    color: "#5d150a"
    Rectangle {
      id: inrect
      anchors.fill: parent
      anchors.margins: parent.border.width*2
      border.color: "#ddc29a"
      border.width: 1
      color: root.pressed ? "#811d0e" : "#5d150a"
    }
  }
}
