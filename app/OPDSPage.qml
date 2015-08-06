/**
  * This file is part of OVU.
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program. If not, see <http://www.gnu.org/licenses/>.
  *
  * Copyright (C) 2015 Mikhail Ivchenko <ematirov@gmail.com>
  *
  **/

import QtQuick 2.0
import Ubuntu.Components 1.2
import OVU 1.0

Page {
    id: root
    title: view.title

    property alias source: view.source

    function setError(error) {
        title = error;
        errorLabel.text = error;
        errorContainer.visible = true;
    }

    signal newPageRequested(url source)

    Flickable{
        anchors.fill: parent

        OPDSView {
            id: view
            anchors.fill: parent
            onErrorHappened: setError(error)
            onNewPageRequested: root.newPageRequested(source)
        }

        Item {
            id: errorContainer
            anchors.fill: parent
            visible: false
            Label {
                id: errorLabel
                anchors.centerIn: parent
            }
        }
    }
}
