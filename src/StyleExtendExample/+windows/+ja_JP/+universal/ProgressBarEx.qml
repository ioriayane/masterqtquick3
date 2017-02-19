import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.2

ColumnLayout {
  property alias from: progress.from
  property alias to: progress.to
  property alias value: progress.value

  spacing: 1
  Label {
    text: "Windows ja_JP Universal %1%".arg(Math.round(progress.position*100))
    Layout.alignment: Qt.AlignRight | Qt.AlignVCenter
  }
  ProgressBar {
    id: progress
    Layout.fillWidth: true
  }
}
