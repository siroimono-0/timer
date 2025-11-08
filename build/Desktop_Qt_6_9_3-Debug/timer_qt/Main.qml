import QtQuick
import QtQuick.Dialogs
import QtQuick.Controls.Basic
import timer_qt 1.0

Window {

    id:win
    width: 400
    height: 300
    visible: true
    title: qsTr("Hello World")

    Timer{
        id: cpp_timer;
    }

    Rectangle{
        id: currentTime_rec
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: parent.height - 50
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        color: "#e6f3ff"  // 옅은 파스텔톤 하늘색
        radius: 5        // 테두리 둥글게

        Text{
            id: currentTime_date
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            text: " " + cpp_timer.qs_curDate;
            font.pixelSize: 20
            font.bold: true
        }

        Text{
            id: currentTime_time
            anchors.left:  currentTime_date.right
            anchors.leftMargin: 10
            anchors.verticalCenter: parent.verticalCenter

            text: " //  " + cpp_timer.qs_curTime;
            font.pixelSize: 20
            font.bold: true
        }
    }

    Item {
        id: anc_item
        anchors.top: currentTime_rec.bottom;
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 70
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
    }

    ListView{
        id: view
        model: cpp_timer.p_cppModel

        anchors.top: currentTime_rec.bottom;
        anchors.topMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 100
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10

        delegate: Rectangle {
            id: view_rec

            width: ListView.view.width - 10
            height: 40
            color: "#f5f5f5"  // 옅은 회색 (라이트 그레이보다 밝게)
            radius: 5         // 테두리 둥글게

            anchors.horizontalCenter: parent ? parent.horizontalCenter : undefined

            Text {
                id: view_text
                text: model.text
                color: "black"   // 텍스트 색상 명시적으로 지정
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 10

                font.pixelSize: 15
                font.bold: true
            }

            Button{
                id: btn_pause

                anchors.right: parent.right
                anchors.rightMargin: 60
                anchors.verticalCenter: parent.verticalCenter

                width: win.width / 10
                height: win.height / 12

                scale: btn_pause_mouse.pressed ? 0.95 : 1.0

                // 스케일 변화에 대한 애니메이션
                Behavior on scale {
                    NumberAnimation {
                        duration: 100
                        easing.type: Easing.OutQuad
                    }
                }

                background: Rectangle {
                    anchors.fill: parent
                    color: btn_pause_mouse.pressed ? "#d4c8e6" : "#e8e0f5"  // 파스텔톤 보라색
                    radius: 5         // 테두리 둥글게
                    border.color: "#c8b6e6"
                    border.width: 1
                    
                    Behavior on color {
                        ColorAnimation { duration: 100 }
                    }
                }

                Text{
                    id: btn_pause_text
                    text: "< ! >"

                    anchors.centerIn: parent

                    font.bold: true
                }

                MouseArea{
                    id: btn_pause_mouse
                    anchors.fill: parent
                    onClicked: {
                        console.log("Clicked index:", model.index);
                        cpp_timer.invok_updateStat(model.index);
                    }
                }
            }

            Button{
                id: btn_delete

                anchors.left:  btn_pause.right
                anchors.leftMargin: 10
                anchors.verticalCenter: parent.verticalCenter

                width: win.width / 10
                height: win.height / 12

                scale: btn_delete_mouse.pressed ? 0.95 : 1.0

                // 스케일 변화에 대한 애니메이션
                Behavior on scale {
                    NumberAnimation {
                        duration: 100
                        easing.type: Easing.OutQuad
                    }
                }

                background: Rectangle {
                    anchors.fill: parent
                    color: btn_delete_mouse.pressed ? "#f0c8d4" : "#f5e0e8"  // 파스텔톤 핑크색
                    radius: 5         // 테두리 둥글게
                    border.color: "#e6b6c8"
                    border.width: 1
                    
                    Behavior on color {
                        ColorAnimation { duration: 100 }
                    }
                }

                Text{
                    id: btn_delete_text
                    text: "< X >"

                    anchors.centerIn: parent

                    font.bold: true
                }

                MouseArea{
                    id: btn_delete_mouse
                    anchors.fill: parent
                    onClicked: {
                        console.log("Clicked index:", model.index);
                        cpp_timer.invok_delete(model.index);
                    }
                }
            }


        }
    }

    Dialog
    {
        id: dia_create
        title: "Create Timer"
        width: win.width / 2
        height: win.height / 2
        x : win.width / 4
        y : win.height / 4
        modal: true
        visible: false

        // 다이얼로그 내용
        Rectangle {
            anchors.fill: parent
            // color: "#f0f8f0"
            // radius: 8

            TextField {
                id: dialog_content

                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.right: parent.right
                anchors.rightMargin: 5
                y : dia_create.y - 80

                font.pixelSize: 16
                font.bold: true
                // radius: 5
                color: "#2d5a2d"
            }

            // 버튼들을 담을 Row
            Row {
                spacing: 20
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.bottom: parent.bottom
                anchors.bottomMargin: 5

                // Set 버튼
                Button {
                    id: btn_set
                    width: 80
                    height: 35

                    scale: btn_set_mouse.pressed ? 0.95 : 1.0

                    Behavior on scale {
                        NumberAnimation {
                            duration: 100
                            easing.type: Easing.OutQuad
                        }
                    }

                    background: Rectangle {
                        color: btn_set_mouse.pressed ? "#c8e6c8" : "#e8f5e8"
                        radius: 6
                        border.color: "#a8d6a8"
                        border.width: 1

                        Behavior on color {
                            ColorAnimation { duration: 100 }
                        }
                    }

                    Text {
                        text: "Set"
                        anchors.centerIn: parent
                        font.bold: true
                        color: "#2d5a2d"
                    }

                    MouseArea {
                        id: btn_set_mouse
                        anchors.fill: parent
                        onClicked: {
                            // console.log("Set button clicked")
                            cpp_timer.invok_addTimer(dialog_content.text);
                            dialog_content.clear();
                            dia_create.visible = false
                        }
                    }
                }

                // Exit 버튼
                Button {
                    id: btn_exit
                    width: 80
                    height: 35

                    scale: btn_exit_mouse.pressed ? 0.95 : 1.0

                    Behavior on scale {
                        NumberAnimation {
                            duration: 100
                            easing.type: Easing.OutQuad
                        }
                    }

                    background: Rectangle {
                        color: btn_exit_mouse.pressed ? "#f0d0d0" : "#f5e5e5"
                        radius: 6
                        border.color: "#d0a0a0"
                        border.width: 1

                        Behavior on color {
                            ColorAnimation { duration: 100 }
                        }
                    }

                    Text {
                        text: "Exit"
                        anchors.centerIn: parent
                        font.bold: true
                        color: "#5a2d2d"
                    }

                    MouseArea {
                        id: btn_exit_mouse
                        anchors.fill: parent
                        onClicked: {
                            // console.log("Exit button clicked")
                            dia_create.visible = false
                        }
                    }
                }
            }
        }
    }

    Button{
        id: btn_create

        anchors.left: anc_item.left
        anchors.top: anc_item.bottom
        anchors.topMargin: 10

        width: win.width / 4
        height: win.height / 8

        scale: btn_create_mouse.pressed ? 0.95 : 1.0

        // 스케일 변화에 대한 애니메이션
        Behavior on scale {
            NumberAnimation {
                duration: 100
                easing.type: Easing.OutQuad
            }
        }

        background: Rectangle {
            anchors.fill: parent
            color: "#e8f5e8"  // 파스텔톤 초록색
            radius: 5         // 테두리 둥글게
            border.color: "#c8e6c8"
            border.width: 1
        }

        Text{
            id: btn_create_text
            text: "Create Timer"

            anchors.centerIn: parent

            font.bold: true
        }

        MouseArea{
            id: btn_create_mouse
            anchors.fill: parent
            onClicked: {
                dia_create.visible = true;
            }
        }
    }


    Button{
        id: btn_medi

        anchors.left:  btn_create.right
        anchors.leftMargin: 10
        anchors.top: anc_item.bottom
        anchors.topMargin: 10

        width: win.width / 4
        height: win.height / 8

        scale: btn_medi_mouse.pressed ? 0.95 : 1.0

        // 스케일 변화에 대한 애니메이션
        Behavior on scale {
            NumberAnimation {
                duration: 100
                easing.type: Easing.OutQuad
            }
        }

        background: Rectangle {
            anchors.fill: parent
            color: btn_medi_mouse.pressed ? "#f0d4a8" : "#f8e6d0"  // 옅은 파스텔톤 주황색
            radius: 5         // 테두리 둥글게
            border.color: "#e6c89e"
            border.width: 1
            
            Behavior on color {
                ColorAnimation { duration: 100 }
            }
        }

        Text{
            id: btn_medi_text
            text: "Medi"

            anchors.centerIn: parent

            font.bold: true
            

        }

        MouseArea{
            id: btn_medi_mouse
            anchors.fill: parent
            onClicked: {
                cpp_timer.invok_mediFile();
                dia_medi.visible = true;
                cpp_timer.invok_mediCheckText()
            }
        }
    }

    Rectangle{
        id:rec_medi

        anchors.left:  btn_medi.right
        anchors.leftMargin: 10
        anchors.top: anc_item.bottom
        anchors.topMargin: 10


        width: win.width / 4
        height: win.height / 8

        border.width: 1
        border.color: "black"

        TextField{
            id: tf_medi
            anchors.fill: parent

            text: cpp_timer.qs_medi;
        }
    }

    Rectangle{
        id:rec_next

        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 22

        width: (win.width / 6) - 30
        height: win.height / 8

        color: "#e8f5e8"  // 파스텔톤 초록색
        radius: 5         // 테두리 둥글게
        border.color: "#c8e6c8"
        border.width: 1

        scale: rec_next_mouse.pressed ? 0.95 : 1.0

        // 스케일 변화에 대한 애니메이션
        Behavior on scale {
            NumberAnimation {
                duration: 100
                easing.type: Easing.OutQuad
            }
        }

        Text{
            id: text_next
            anchors.centerIn: parent
            text: ">>"
            font.pixelSize: 15
            font.bold: true
        }

        MouseArea{
            id: rec_next_mouse
            anchors.fill: parent

            onClicked: {
                if(cpp_timer.invok_mediNext())
                {
                    dia_medi.visible = true;
                }
            }
        }
    }

    Dialog
    {
        id: dia_medi
        title: "Medi"
        width: win.width / 2
        height: (win.height / 1.5) + 30
        x : win.width / 4
        y : (win.height / 4) - 60
        modal: true
        visible: false

        // 다이얼로그 내용
        Rectangle {
            anchors.fill: parent
            // color: "#f0f8f0"
            // radius: 8
        TextArea{
            id:  dia_medi_textArea
            text: cpp_timer.qs_mediDialog;

            x : (win.width / 4) - 110
            y : (win.height / 4) - 90

            font.pixelSize: 15
            font.bold: true
        }
        }
    }
}
