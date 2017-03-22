import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.0
import OriginalStyle 1.0
import Qt.labs.settings 1.0                           // [1]

ApplicationWindow {
  id: root
  visible: true
  width: 500
  height: 400
  title: qsTr("Choose Style Example")

//  OriginalStyle.theme: OriginalStyle.Blue

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex

    Page1 {
    }

    Item {
      //設定の保存
      Settings {
        id: settings
        property string styleName: "Default"              // [2]
      }
      //ラジオボタンの選択状態管理
      ButtonGroup {
        id: selectStyle
        buttons: column.children
        onClicked: settings.styleName = button.styleName  // [3]
      }
      //スタイルの選択
      ColumnLayout {
        id: column
        anchors.centerIn: parent
        RadioButton {
          checked: settings.styleName === styleName
          text: qsTr("Default")
          property string styleName: "Default"             // [4]
        }
        RadioButton {
          checked: settings.styleName === styleName
          text: qsTr("Material")
          property string styleName: "Material"
        }
        RadioButton {
          checked: settings.styleName === styleName
          text: qsTr("Universal")
          property string styleName: "Universal"
        }
        RadioButton {
          checked: settings.styleName === styleName
          text: qsTr("Original")
          property string styleName: ":/OriginalStyle"
        }
      }
    }
  }

  footer: TabBar {
    id: tabBar
    currentIndex: swipeView.currentIndex
    TabButton {
      text: qsTr("First")
    }
    TabButton {
      text: qsTr("Second")
    }
  }
}
