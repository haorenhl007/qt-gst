import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    // PageLoader using
    signal message(string page)

    ComSidebar {
    }

    StackView {

        ComLive {

        }

        ComPlayback {

        }

        ComEvent {

        }

        ComSetting {

        }

        anchors.left: sideBar.right
    }
}
