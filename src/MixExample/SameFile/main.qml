import QtQuick 2.7
import QtQuick.Controls 2.1
import QtQuick.Controls 1.4 as Controls
import QtQuick.Layouts 1.1

ApplicationWindow {
  visible: true
  width: 500
  height: 400
  title: qsTr("Mix Example(same file)")

  ColumnLayout {
    anchors.rightMargin: 10
    anchors.leftMargin: 10
    anchors.bottomMargin: 10
    anchors.topMargin: 10
    anchors.fill: parent

    //基本はControls 2で作成
    GroupBox {
      Layout.fillWidth: true
      title: qsTr("Command")
      RowLayout {
        anchors.fill: parent
        TextField {
          Layout.fillWidth: true
          placeholderText: qsTr("Charactor name")
        }
        TextField {
          Layout.fillWidth: true
          placeholderText: qsTr("Actress name")
        }
        Button {
          Layout.maximumWidth: 100
          text: qsTr("Add")
        }
      }
    }

    //必要なエレメントだけControls 1で作成
    Controls.TableView {
      Layout.fillHeight: true
      Layout.fillWidth: true
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
