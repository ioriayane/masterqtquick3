import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.2

Item {
  id: root
  signal choiced(string name)

  ButtonGroup {
    id: choiceReligious
    buttons: choiceColumn.children
  }

  ColumnLayout {
    id: choiceColumn
    anchors.centerIn: parent
    RadioButton {
      id: aqusisRadioButton
      text: qsTr("Aqusis religious")
      checked: true
    }
    RadioButton {
      id: elisRadioButton
      text: qsTr("Elis religious")
    }
    Button {
      text: qsTr("Join")
      Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
      onClicked: root.choiced(choiceReligious.checkedButton.text)
    }
  }
}
