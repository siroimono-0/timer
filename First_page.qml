import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls.Basic
import timer_qt 1.0

Page {
    id: page_main

    Timer {
        id: cpp_timer
    }

    Rectangle {
        id: currentTime_rec
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10
        height: 40
        color: "#e6f3ff"
        radius: 5

        Text {
            id: currentTime_date
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            anchors.leftMargin: 10
            text: " " + cpp_timer.qs_curDate
            font.pixelSize: 20
            font.bold: true
        }

        Text {
            id: currentTime_time
            anchors.left: currentTime_date.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter
            text: " // " + cpp_timer.qs_curTime
            font.pixelSize: 20
            font.bold: true
        }
    }

    ListView {
        id: view
        model: cpp_timer.p_cppModel
        anchors.top: currentTime_rec.bottom
        anchors.topMargin: 10
        anchors.bottom: btn_create.top
        anchors.bottomMargin: 10
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 10

        delegate: Rectangle {
            width: ListView.view.width - 10
            height: 40
            color: "#f5f5f5"
            radius: 5
            anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined

            Text {
                text: model.text
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10
                font.pixelSize: 15
                font.bold: true
            }

            // 삭제 / 일시정지 버튼 (생략 가능)
            Button {
                id: btn_pause
                text: "< ! >"
                anchors.right: parent.right
                anchors.rightMargin: 60
                anchors.verticalCenter: parent.verticalCenter
                onClicked: cpp_timer.invok_updateStat(model.index)
            }

            Button {
                id: btn_delete
                text: "< X >"
                anchors.right: parent.right
                anchors.rightMargin: 10
                anchors.verticalCenter: parent.verticalCenter
                onClicked: cpp_timer.invok_delete(model.index)
            }
        }
    }

    Dialog {
        id: dia_create
        title: "Create Timer"
        width: parent.width / 2
        height: parent.height / 2
        x: parent.width / 4
        y: parent.height / 4
        modal: true
        visible: false

        Rectangle {
            anchors.fill: parent
            TextField {
                id: dialog_content
                anchors.centerIn: parent
                anchors.verticalCenterOffset: -30
                font.pixelSize: 16
                font.bold: true
            }

            Row {
                spacing: 20
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5

                Button {
                    text: "Set"
                    onClicked: {
                        cpp_timer.invok_addTimer(dialog_content.text)
                        dialog_content.clear()
                        dia_create.visible = false
                    }
                }

                Button {
                    text: "Exit"
                    onClicked: dia_create.visible = false
                }
            }
        }
    }

    Row {
        id: bottom_btn_row
        spacing: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        anchors.horizontalCenter: parent.horizontalCenter

        Button {
            id: btn_create
            text: "Create Timer"
            onClicked: dia_create.visible = true
        }

        Button {
            id: btn_medi
            text: "Medi"
            onClicked: {
                // ✅ StackView 전환 예시
                stk.push("SecondPage.qml")
            }
        }
    }
}




