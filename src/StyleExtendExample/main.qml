import QtQuick 2.8
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.2
import QtQuick.Controls.Material 2.1

ApplicationWindow {
  visible: true
  width: 500
  height: 400
  title: qsTr("Style Extend Example")


  ProgressBarEx {
    id: progress
    anchors.centerIn: parent
  }

  NumberAnimation {
    target: progress
    property: "value"
    duration: 5000
    from: progress.from
    to: progress.to
    running: true
    loops: Animation.Infinite
  }
}
