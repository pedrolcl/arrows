/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "arrowitem.h"

ArrowItem::ArrowItem(qreal x, qreal y, QGraphicsItem *parent)
    : QGraphicsPathItem(parent)
    , m_origin{x, y}
    , m_length{1}
    , m_angle{0}
    , m_tip{x + m_length, y}
{
    setFlag(QGraphicsItem::ItemIsSelectable);
    setTransformOriginPoint(m_origin);
}

ArrowItem::ArrowItem(QPointF origin, QGraphicsItem *parent)
    : ArrowItem(origin.rx(), origin.ry(), parent)
{}

ArrowItem::ArrowItem(qreal x, qreal y, qreal length, qreal angle, QGraphicsItem *parent)
    : ArrowItem(x, y, parent)
{
    m_length = length;
    m_angle = angle;
    m_tip = QPointF{x + m_length, y};
    setRotation(m_angle);
    updatePath();
}

ArrowItem::ArrowItem(QPointF origin, qreal length, qreal angle, QGraphicsItem *parent)
    : ArrowItem(origin.rx(), origin.ry(), parent)
{
    m_length = length;
    m_angle = angle;
    m_tip = QPointF{origin.rx() + m_length, origin.ry()};
    setRotation(m_angle);
    updatePath();
}

ArrowItem::ArrowItem(QPointF origin, QPointF tip, QGraphicsItem *parent)
    : ArrowItem(origin.rx(), origin.ry(), parent)
{
    QLineF line(origin, tip);
    m_length = line.length();
    m_angle = std::remainder(360.0 - line.angle(), 360.0);
    line.setAngle(0);
    m_tip = line.p2();
    setRotation(m_angle);
    updatePath();
}

void ArrowItem::updatePath()
{
    const qreal headsize = m_length / 10.0;
    QPainterPath path;
    path.moveTo(m_origin);
    path.lineTo(m_tip);
    path.moveTo(m_tip.rx() - headsize, m_tip.ry() - headsize / 2);
    path.lineTo(m_tip);
    path.lineTo(m_tip.rx() - headsize, m_tip.ry() + headsize / 2);
    setPath(path);
}

QPointF ArrowItem::origin() const
{
    return m_origin;
}

void ArrowItem::setOrigin(QPointF newOrigin)
{
    m_origin = newOrigin;
}

qreal ArrowItem::length() const
{
    return m_length;
}

void ArrowItem::setLength(qreal newLength)
{
    m_length = newLength;
}

qreal ArrowItem::angle() const
{
    return m_angle;
}

void ArrowItem::setAngle(qreal newAngle)
{
    m_angle = newAngle;
}
