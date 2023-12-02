/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef ARROWITEM_H
#define ARROWITEM_H

#include <QGraphicsItem>
#include <QGraphicsPathItem>
#include <QPointF>

/**
 * @brief The ArrowItem class is an arrow shaped QGraphicsItem
 * This QGraphicsItem can be added to a QGraphicsScene
 * @see [Qt Graphics View Framework](https://doc.qt.io/qt-6/graphicsview.html)
 * @see [QGraphicsPathItem](https://doc.qt.io/qt-6/qgraphicspathitem.html)
 */
class ArrowItem : public QGraphicsPathItem
{
public:
    /**
     * @brief ArrowItem Constructor
     * @param x The origin point X coordinate
     * @param y The origin point Y coordinate
     * @param parent Optional QGraphicsItem parent
     * 
     * This constructor initializes the length of the arrow to 1
     * and the angle to 0, without updating the painter path.
     * The arrow item is selectable, and the transformation point
     * will be initialized with the origin point.
     */
    ArrowItem(qreal x, qreal y, QGraphicsItem *parent = nullptr);

    /**
     * @brief ArrowItem Constructor
     * @param origin The origin point
     * @param parent Optional QGraphicsItem parent
     * 
     * This constructor initializes the length of the arrow to 1
     * and the angle to 0, without updating the painter path.
     * The arrow items is selectabl, and the transformation point
     * will be initialized with the origin point.
     */
    ArrowItem(QPointF origin, QGraphicsItem *parent = nullptr);

    /**
     * @brief ArrowItem Constructor
     * @param x The origin point X coordinate
     * @param y The origin point Y coordinate
     * @param length The arrow length
     * @param angle The arrow orientation angle in degrees
     * @param parent Optional QGraphicsItem parent
     * 
     * This constructor automatically updates the paiter path.
     */
    ArrowItem(qreal x, qreal y, qreal length, qreal angle, QGraphicsItem *parent = nullptr);

    /**
     * @brief ArrowItem Constructor
     * @param origin The origin point
     * @param length The arrow length
     * @param angle The arrow orientation angle in degrees
     * @param parent Optional QGraphicsItem parent
     * 
     * This constructor automatically updates the paiter path.
     */
    ArrowItem(QPointF origin, qreal length, qreal angle, QGraphicsItem *parent = nullptr);

    /**
     * @brief ArrowItem Constructor
     * @param origin The origin point
     * @param tip The arrow tip point
     * @param parent Optional QGraphicsItem parent
     * 
     * This constructor initializes the length of the arrow as the distance from 
     * the origin point to the tip point, as the orientation angle in degrees.
     * This constructor automatically updates the paiter path.
     */
    ArrowItem(QPointF origin, QPointF tip, QGraphicsItem *parent = nullptr);

    /**
     * @brief updatePath updates the painter path on the QGraphicsPathItem
     * @see https://doc.qt.io/qt-6/qgraphicspathitem.html#setPath
     */
    void updatePath();

    /**
     * @brief origin returns the origin point
     * @return the arrow's origin point
     */
    QPointF origin() const;

    /**
     * @brief setOrigin sets the origin point
     * @param newOrigin QPointF the new origin point
     * You need to call updatePath() after calling this method
     */
    void setOrigin(QPointF newOrigin);

    /**
     * @brief length returns the length of the arrow
     * @return the arrow's length
     */
    qreal length() const;

    /**
     * @brief setLength returns the length of the arrow
     * @param newLength the new length
     * You need to call updatePath() after calling this method
     */
    void setLength(qreal newLength);

    /**
     * @brief angle returns the orientation angle of the arrow in degrees
     * @return the orientation angle of the arrow in degrees
     */
    qreal angle() const;

    /**
     * @brief setAngle sets the orientation angle of the arrow in degrees
     * @param newAngle the new orientation angle of the arrow in degrees
     * You need to call updatePath() after calling this method
     */
    void setAngle(qreal newAngle);

private:
    QPointF m_origin;
    qreal m_length;
    qreal m_angle;
    QPointF m_tip;
};

#endif // ARROWITEM_H
