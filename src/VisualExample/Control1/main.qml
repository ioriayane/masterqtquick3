import QtQuick 2.8
import QtQuick.Controls 1.5
import QtQuick.Layouts 1.2

ApplicationWindow {
    visible: true
    width: 500
    height: 400
    title: qsTr("Visual Example")

    GridLayout {
        id: gridLayout1
        anchors.rightMargin: 10
        anchors.leftMargin: 10
        anchors.bottomMargin: 10
        anchors.topMargin: 10
        columns: 2
        anchors.fill: parent

        RowLayout {
            Layout.columnSpan: 2
            Layout.fillWidth: true

            TextField {
                id: textField1
                text: "Text Field"
                Layout.fillWidth: true
                placeholderText: qsTr("Text Field")
            }

            Button {
                id: button1
                text: qsTr("Button")
            }
        }

        ColumnLayout {
            id: columnLayout3
            width: 100
            height: 100
            spacing: 15

            GroupBox {
                id: groupBox1
                Layout.fillHeight: true
                Layout.fillWidth: true
                title: qsTr("Group Box")

                ColumnLayout {
                    id: columnLayout1
                    anchors.fill: parent

                    CheckBox {
                        id: checkBox1
                        text: qsTr("Check Box")
                    }

                    CheckBox {
                        id: checkBox2
                        text: qsTr("Check Box")
                        checked: true
                    }
                }
            }

            GroupBox {
                id: groupBox2
                Layout.fillHeight: true
                Layout.fillWidth: true
                title: qsTr("Group Box")

                ColumnLayout {
                    id: columnLayout2
                    anchors.fill: parent

                    RadioButton {
                        id: radioButton1
                        text: qsTr("Radio Button")
                        checked: true
                    }

                    RadioButton {
                        id: radioButton3
                        text: qsTr("Radio Button")
                    }

                    RadioButton {
                        id: radioButton2
                        text: qsTr("Radio Button")
                    }
                }
            }
        }

        ColumnLayout {
            id: columnLayout4
            spacing: 15

            Item {
                id: item1
                width: 10
                height: 20
            }

            ProgressBar {
                id: progressBar1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                value: 0.5
            }

            Slider {
                id: slider1
                value: 0.5
            }

            BusyIndicator {
                id: busyIndicator1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            }

            RowLayout {
                id: rowLayout1
                Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                spacing: 10

                Switch {
                    id: switch1
                    checked: true
                }

                Switch {
                    id: switch2
                }
            }

            Item {
                id: item2
                width: 10
                height: 10
                Layout.fillHeight: true
            }
        }
    }
}
