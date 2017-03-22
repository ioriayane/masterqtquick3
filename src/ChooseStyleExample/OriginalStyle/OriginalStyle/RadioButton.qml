import QtQuick 2.8
import QtQuick.Templates 2.1 as T
import OriginalStyle 1.0

T.RadioButton {
  id: root
  implicitWidth: leftPadding + rightPadding + indicator.implicitWidth
                 + spacing + contentItem.contentWidth * 1.2
  implicitHeight: topPadding + bottomPadding + Math.max(indicator.implicitHeight
                                                        , contentItem.implicitHeight)
  padding: 10
  spacing: 5

  indicator: Rectangle {
    x: root.leftPadding
    y: root.topPadding + (root.availableHeight - height) / 2
    implicitWidth: 20
    implicitHeight: 20
    radius: width / 2
    border.color: root.OriginalStyle.basicColor
    border.width: 2
    color: "#00ffffff"
    Rectangle {
      anchors.fill: parent
      anchors.margins: 4
      radius: width / 2
      color: root.checked ? root.OriginalStyle.basicColor : "#00000000"
    }
  }
  contentItem: Text {
    anchors.left: indicator.right
    anchors.leftMargin: root.spacing
    anchors.top: indicator.top
    anchors.bottom: indicator.bottom
    text: root.text
    font: root.font
    color: root.enabled ? "#222222" : "#ffffff"
    horizontalAlignment: Text.AlignLeft
    verticalAlignment: Text.AlignVCenter
  }
}
