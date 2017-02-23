import QtQuick 2.8
import QtQuick.Templates 2.1 as T

T.ApplicationWindow {
  background: Rectangle {
      gradient: Gradient {
          GradientStop { position: 0; color: "#ffffff" }
          GradientStop { position: 1; color: "#c1bbf9" }
      }
  }
  overlay.modal: Rectangle {
      color: "#8f28282a"
  }
  overlay.modeless: Rectangle {
      color: "#2f28282a"
  }
}
