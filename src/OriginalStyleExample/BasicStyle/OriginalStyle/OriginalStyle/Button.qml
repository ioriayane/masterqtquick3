import QtQuick 2.8
import QtQuick.Templates 2.1 as T     // [1]
import QtQuick.Layouts 1.2

T.Button {                            // [2]
  id: root
  //サイズ                               // [3]
  implicitWidth: padding + layout.spacing
                 + mark.width + text.contentWidth * 1.5
  implicitHeight: topPadding + bottomPadding + contentItem.implicitHeight
  padding: 10

  //前景（ボタン上に配置する文字など）           // [4]
  contentItem: RowLayout {
    id: layout
    //文字の左の○印
    Rectangle {
      id: mark
      width: height
      height: text.contentHeight
      radius: width / 2
      color: !root.enabled ? "#888888" : "#f08200"
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
    //ボタンのテキスト
    Text {
      id: text
      Layout.fillWidth: true
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      elide: Text.ElideRight
      color: !root.enabled ? "#888888" : (root.hovered ? "#ff4444" : "#ffffff")
      text: root.text
      font: root.font                 // [5]
    }
  }
  //背景（ボタンっぽい形など）                 // [6]
  background: Rectangle {
    id: rect
    border.color: "#ddc29a"
    border.width: 2
    color: "#5d150a"
    //2重の枠線を引くために入れ子
    Rectangle {
      anchors.fill: parent
      anchors.margins: parent.border.width*2
      border.color: "#ddc29a"
      border.width: 1
      color: !root.enabled ? "#5e3931" : (root.pressed ? "#811d0e" : "#5d150a")
    }
  }
}
