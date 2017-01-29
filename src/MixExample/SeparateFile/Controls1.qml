import QtQuick 2.8
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.1

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
      text: qsTr("Aqusis religious")
      exclusiveGroup: choiceReligious
      checked: true
    }
    RadioButton {
      id: radioButton1
      text: qsTr("Elis religious")
      exclusiveGroup: choiceReligious
    }
    Button {
      text: qsTr("Join")
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      onClicked: root.choiced(choiceReligious.current.text)
    }
  }
}
