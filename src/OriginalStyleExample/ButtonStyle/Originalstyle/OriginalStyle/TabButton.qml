import QtQuick 2.8
import QtQuick.Templates 2.1 as T
import QtQuick.Layouts 1.2

T.TabButton {
  id: root
  //サイズ
  implicitWidth: padding + layout.spacing
                 + mark.contentWidth + text.contentWidth * 1.5
  implicitHeight: padding + text.contentHeight * 2.5
  padding: 10

  contentItem: RowLayout {
    id: layout
    Text {
      id: mark
      color: "#ff4444"
      text: ">"
      font.bold: true
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
    border.color: "#222222"
    border.width: 1
    color: root.hovered ? "#ff666666" : "#ee666666"
  }
}
