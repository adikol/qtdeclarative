/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the QtQml module of the Qt Toolkit.
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

#ifndef QQMLCOMPONENT_P_H
#define QQMLCOMPONENT_P_H

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

#include "qqmlcomponent.h"

#include <private/qv8_p.h>
#include "qqmlengine_p.h"
#include "qqmltypeloader_p.h"
#include <private/qbitfield_p.h>
#include "qqmlvme_p.h"
#include "qqmlerror.h"
#include "qqml.h"
#include <private/qqmlprofilerservice_p.h>

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QList>

#include <private/qobject_p.h>

QT_BEGIN_NAMESPACE

class QV8Engine;

class QQmlComponent;
class QQmlEngine;
class QQmlCompiledData;

class QQmlComponentAttached;
class Q_QML_PRIVATE_EXPORT QQmlComponentPrivate : public QObjectPrivate, public QQmlTypeData::TypeDataCallback
{
    Q_DECLARE_PUBLIC(QQmlComponent)
        
public:
    QQmlComponentPrivate() : typeData(0), progress(0.), start(-1), cc(0), engine(0), creationContext(0), profiler(0) {}

    QObject *beginCreate(QQmlContextData *);
    void completeCreate();
    void initializeObjectWithInitialProperties(v8::Handle<v8::Object> qmlGlobal, v8::Handle<v8::Object> valuemap, QObject *toCreate);

    QQmlTypeData *typeData;
    virtual void typeDataReady(QQmlTypeData *);
    virtual void typeDataProgress(QQmlTypeData *, qreal);
    
    void fromTypeData(QQmlTypeData *data);

    QUrl url;
    qreal progress;

    int start;
    QQmlCompiledData *cc;

    struct ConstructionState {
        ConstructionState() : completePending(false) {}

        QQmlVME vme;
        QList<QQmlError> errors;
        bool completePending;
    };
    ConstructionState state;

    static void beginDeferred(QQmlEnginePrivate *enginePriv, QObject *object, 
                              ConstructionState *state);
    static void complete(QQmlEnginePrivate *enginePriv, ConstructionState *state);

    QQmlEngine *engine;
    QQmlGuardedContextData creationContext;
    QQmlObjectCreatingProfiler *profiler;

    void clear();

    static QQmlComponentPrivate *get(QQmlComponent *c) {
        return static_cast<QQmlComponentPrivate *>(QObjectPrivate::get(c));
    }
};

QT_END_NAMESPACE

#endif // QQMLCOMPONENT_P_H
