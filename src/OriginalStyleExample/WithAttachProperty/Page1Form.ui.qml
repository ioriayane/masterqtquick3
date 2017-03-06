import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import OriginalStyle 1.0          // [1]

Item {
  property alias textField1: textField1
  property alias button1: button1

  RowLayout {
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.topMargin: 20
    anchors.top: parent.top

    TextField {
      id: textField1
      OriginalStyle.theme: OriginalStyle.Blue // [2]
      placeholderText: qsTr("Text Field")
    }
    Button {
      id: button1
      OriginalStyle.theme: OriginalStyle.Blue // [3]
      text: qsTr("Press Me")
    }
  }
}
