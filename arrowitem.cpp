/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <QtMath>

#include "arrowitem.h"

ArrowItem::ArrowItem(qreal x, qreal y, qreal length, qreal angle, QGraphicsItem *parent)
    : QGraphicsPathItem(parent)
    , m_origin{QPointF{x, y}}
    , m_length{length}
    , m_angle{angle}
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    updatePath();
}

void ArrowItem::updatePath()
{
    const qreal arrowsize = m_length / 10.0;
    QPointF tip(m_origin.rx() + m_length, m_origin.ry());

    QPainterPath path;
    path.moveTo(m_origin);
    path.lineTo(tip);
    path.moveTo(tip.rx() - arrowsize, tip.ry() - arrowsize / 2);
    path.lineTo(tip);
    path.lineTo(tip.rx() - arrowsize, tip.ry() + arrowsize / 2);
    setPath(path);

    setTransformOriginPoint(0, 0);
    setTransform(QTransform().rotate(m_angle), false);
}
