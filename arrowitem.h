/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QGraphicsPathItem>

class ArrowItem : public QGraphicsPathItem
{
public:
    ArrowItem(qreal x, qreal y, qreal length, qreal angle, QGraphicsItem *parent = nullptr);
    void updatePath();

private:
    QPointF m_origin;
    qreal m_length;
    qreal m_angle;
};

#endif // ARROWITEM_H
