// *************************************************************************
//
// Copyright 2012-2012 Nikolai Marchenko  .
//
// This file is part of the BreezeUML Uml Toolkit.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// e-mail : enmarantispam@gmail.com
//
// *************************************************************************
#include "Factories/EdgeToolBarCreation.h"
#include "CustomWidgets/MultiPurposeDragArea.h"
#include "CustomWidgets/EdgeMenuToolBar.h"
#include <QPushButton>
#include <QIcon>
#include <QHBoxLayout>
#include <QLabel>

static int defaultButtonSize = 20;
EdgeMenuToolBar* CreateLimitedDialogMenu()
{
    EdgeMenuToolBar* toolbar = new EdgeMenuToolBar();

    QPushButton* okayElement = new QPushButton();
    okayElement->setIcon(QIcon(":\\root\\icons\\accept.png"));
    okayElement->setName("OkayElement");
    okayElement->setBaseSize(defaultButtonSize,defaultButtonSize);

    QPushButton* cancelElement = new QPushButton();
    cancelElement->setIcon(QIcon(":\\root\\icons\\reject.png"));
    cancelElement->setName("CancelElement");
    cancelElement->setBaseSize(defaultButtonSize,defaultButtonSize);

    toolbar->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    toolbar->setMinimumHeight(defaultButtonSize);
    toolbar->setMinimumWidth(defaultButtonSize);
    toolbar->resize(toolbar->sizeHint());
    toolbar->setWindowFlags(Qt::FramelessWindowHint);

    toolbar->addWidget(cancelElement);
    toolbar->addWidget(okayElement);
    return toolbar;
}

EdgeMenuToolBar* CreateClassDialogMenu()
{
    EdgeMenuToolBar* toolbar = new EdgeMenuToolBar();


    MultiPurposeDragArea* dragArea = new MultiPurposeDragArea();
    dragArea->setName("DragArea");
    dragArea->setBaseSize(defaultButtonSize,defaultButtonSize);
    dragArea->setMinimumHeight(defaultButtonSize);
    dragArea->setMinimumWidth(defaultButtonSize);
    QHBoxLayout* layout = new QHBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    QLabel* label = new QLabel();
    label->setPixmap(QIcon(":\\root\\icons\\mouse_control.png").pixmap());
            //setIcon(QIcon(":\\root\\icons\\mouse_control.png"));
    layout->addWidget(label);
    dragArea->setLayout(layout);


    QPushButton* okayElement = new QPushButton();
    okayElement->setIcon(QIcon(":\\root\\icons\\accept.png"));
    okayElement->setName("OkayElement");
    okayElement->setBaseSize(defaultButtonSize,defaultButtonSize);

    QPushButton* nextElement = new QPushButton();
    nextElement->setIcon(QIcon(":\\root\\icons\\up.png"));
    nextElement->setName("NextElement");
    nextElement->setBaseSize(defaultButtonSize,defaultButtonSize);

    QPushButton* previousElement = new QPushButton();
    previousElement->setIcon(QIcon(":\\root\\icons\\down.png"));
    previousElement->setName("PreviousElement");
    previousElement->setBaseSize(defaultButtonSize,defaultButtonSize);

    QPushButton* cancelElement = new QPushButton();
    cancelElement->setIcon(QIcon(":\\root\\icons\\reject.png"));
    cancelElement->setName("CancelElement");
    cancelElement->setBaseSize(defaultButtonSize,defaultButtonSize);

    toolbar->setSizePolicy(QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding));
    toolbar->setMinimumHeight(defaultButtonSize);
    toolbar->setMinimumWidth(defaultButtonSize);
    toolbar->resize(toolbar->sizeHint());
    toolbar->setWindowFlags(Qt::FramelessWindowHint);

    toolbar->addWidget(cancelElement);
    toolbar->addWidget(dragArea);
    toolbar->addWidget(nextElement);
    toolbar->addWidget(previousElement);
    toolbar->addWidget(okayElement);
    return toolbar;
}
