/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QPointF>

class ArrowItem : public QGraphicsPathItem
{
public:
    ArrowItem(qreal x, qreal y, QGraphicsItem *parent = nullptr);
    ArrowItem(QPointF origin, QGraphicsItem *parent = nullptr);
    ArrowItem(qreal x, qreal y, qreal length, qreal angle, QGraphicsItem *parent = nullptr);
    ArrowItem(QPointF origin, qreal length, qreal angle, QGraphicsItem *parent = nullptr);
    ArrowItem(QPointF origin, QPointF tip, QGraphicsItem *parent = nullptr);

    void updatePath();

    QPointF origin() const;
    void setOrigin(QPointF newOrigin);

    qreal length() const;
    void setLength(qreal newLength);

    qreal angle() const;
    void setAngle(qreal newAngle);

private:
    QPointF m_origin;
    qreal m_length;
    qreal m_angle;
    QPointF m_tip;
};

#endif // ARROWITEM_H
