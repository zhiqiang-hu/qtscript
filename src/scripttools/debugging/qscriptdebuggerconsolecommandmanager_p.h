/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtSCriptTools module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSCRIPTDEBUGGERCONSOLECOMMANDMANAGER_P_H
#define QSCRIPTDEBUGGERCONSOLECOMMANDMANAGER_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <QtCore/qobjectdefs.h>
#include <QtCore/qscopedpointer.h>
#include <QtCore/qmap.h>
#include <QtCore/qlist.h>

#include "qscriptdebuggerconsolecommandgroupdata_p.h"

QT_BEGIN_NAMESPACE

class QScriptDebuggerConsoleCommand;
class QStringList;

class QScriptDebuggerConsoleCommandManagerPrivate;
class Q_AUTOTEST_EXPORT QScriptDebuggerConsoleCommandManager
{
public:
    QScriptDebuggerConsoleCommandManager();
    ~QScriptDebuggerConsoleCommandManager();

    void addCommand(QScriptDebuggerConsoleCommand *command);
    void addCommandGroup(const QString &name,
                         const QScriptDebuggerConsoleCommandGroupData &data);

    QScriptDebuggerConsoleCommand *findCommand(const QString &name) const;
    QMap<QString, QList<QScriptDebuggerConsoleCommand*> > commands() const;
    QList<QScriptDebuggerConsoleCommand*> commandsInGroup(const QString &name) const;

    QScriptDebuggerConsoleCommandGroupData commandGroupData(const QString &name) const;
    QScriptDebuggerConsoleCommandGroupMap commandGroups() const;

    QStringList completions(const QString &prefix) const;

private:
    QScopedPointer<QScriptDebuggerConsoleCommandManagerPrivate> d_ptr;

    Q_DECLARE_PRIVATE(QScriptDebuggerConsoleCommandManager)
};

QT_END_NAMESPACE

#endif
