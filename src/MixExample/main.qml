import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls 1.4 as Controls
import QtQuick.Layouts 1.1

ApplicationWindow {
    visible: true
    width: 500
    height: 400
    title: qsTr("Mix Example")

    GridLayout {
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        anchors.fill: parent
        columns: 2

        Controls.Button {
            id: button
            text: qsTr("Button(Controls 1)")
        }
        Button {
            id: button1
            text: qsTr("Button(Controls 2)")
        }

        Controls.CheckBox {
            id: checkBox
            text: qsTr("Check Box")
        }
        CheckBox {
            id: checkBox1
            text: qsTr("Check Box")
        }

        Controls.TableView {
            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.columnSpan: 2
            Controls.TableViewColumn {
                role: "charactor"
                title: "Charactor"
                width: 100
            }
            Controls.TableViewColumn {
                role: "actress"
                title: "Actress"
                width: 200
            }
            model: castModel
        }
    }

    ListModel {
        id: castModel
        ListElement {
            charactor: "Aqua"
            actress: "Sora Amamiya"
        }
        ListElement {
            charactor: "Megumin"
            actress: "Rie Takahashi"
        }
        ListElement {
            charactor: "Darkness"
            actress: "Ai Kayano"
        }
    }
}
