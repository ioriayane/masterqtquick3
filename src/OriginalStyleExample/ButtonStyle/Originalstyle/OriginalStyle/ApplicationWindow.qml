import QtQuick 2.8
import QtQuick.Templates 2.1 as T

T.ApplicationWindow {
  background: Rectangle {
    id: bg
    color: "#e2c095"
  }
  overlay.modal: Rectangle {
      color: "#8f28282a"
  }
  overlay.modeless: Rectangle {
      color: "#2f28282a"
  }
}
