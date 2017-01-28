import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1

Item {
    id: root
    signal choiced(string name)

    RowLayout {
        anchors.centerIn: parent

        ButtonGroup {
            id: choiceReligious
            buttons: choiceColumn.children
        }

        ColumnLayout {
            id: choiceColumn
            RadioButton {
                id: aqusisRadioButton
                text: qsTr("Aqusis religious")
                checked: true
            }
            RadioButton {
                id: elisRadioButton
                text: qsTr("Elis religious")
            }
        }

        Button {
            text: qsTr("Join")
            onClicked: root.choiced(choiceReligious.checkedButton.text)
        }
    }
}
