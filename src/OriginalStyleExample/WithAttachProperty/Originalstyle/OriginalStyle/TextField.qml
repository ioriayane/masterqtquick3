import QtQuick 2.8
import QtQuick.Templates 2.1 as T
import QtQuick.Layouts 1.2
import OriginalStyle 1.0

T.TextField {
  id: root
  implicitWidth: leftPadding + rightPadding + 120
  implicitHeight: topPadding + bottomPadding + contentHeight
  padding: 10
  verticalAlignment: TextInput.AlignVCenter
  color: OriginalStyle.basicColor
  //カーソル
  cursorDelegate: Rectangle {
    id: cursor
    color: OriginalStyle.basicColor
    width: 1
    visible: root.activeFocus && root.selectionStart === root.selectionEnd
    //点滅のタイマー
    Timer {
      id: timer
      running: root.activeFocus
      repeat: true
      interval: Qt.styleHints.cursorFlashTime / 2
      onTriggered: (cursor.opacity = !cursor.opacity) ? 1 : 0
      onRunningChanged: cursor.opacity = 1
    }
  }
  //未入力時のガイド文字列
  Text {
    id: text
    anchors.fill: parent
    anchors.margins: parent.padding
    elide: Text.ElideRight
    text: root.placeholderText
    font: root.font
    horizontalAlignment: root.horizontalAlignment
    verticalAlignment: root.verticalAlignment
    color: "#ffffff"
    visible: root.length == 0
  }
  //背景（という下線）
  background: Item {
    implicitWidth: 120
    Rectangle {
      anchors.left: parent.left
      anchors.right: parent.right
      anchors.bottom: parent.bottom
      height: root.activeFocus ? 2 : 1
      radius: 1
      color: OriginalStyle.basicColor
    }
  }
}
