import QtQuick 2.8
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2

Item {
  id: root
  signal choiced(string name)

  ColumnLayout {
    spacing: 10
    anchors.centerIn: parent

    ExclusiveGroup {
      id: choiceReligious
    }
    RadioButton {
      id: radioButton
      text: qsTr("Another world")
      exclusiveGroup: choiceReligious
      checked: true
    }
    RadioButton {
      id: radioButton1
      text: qsTr("Heaven")
      exclusiveGroup: choiceReligious
    }
    Button {
      text: qsTr("Go")
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      onClicked: root.choiced(choiceReligious.current.text)
    }
  }
}
