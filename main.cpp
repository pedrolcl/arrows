/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "arrowitem.h"

QGraphicsEllipseItem *GenCircle(qreal centerx, qreal centery, qreal radius)
{
    QRectF rect(centerx - radius, centery - radius, 2 * radius, 2 * radius);
    return new QGraphicsEllipseItem(rect);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    scene.setBackgroundBrush(Qt::lightGray);
    scene.setSceneRect(-400, -400, 800, 800);
    scene.addItem(GenCircle(0, 0, 5));
    scene.addItem(GenCircle(0, 0, 305));
    for (int angle = 0; angle < 360; angle += 15) {
        auto arrow = new ArrowItem(5, 0, 300, angle);
        arrow->setTransformOriginPoint(0, 0);
        scene.addItem(arrow);
    }
    scene.addItem(new ArrowItem(QPointF{-350, -350}, QPointF{100, -350}));
    scene.addItem(new ArrowItem(QPointF{-350, -350}, QPointF{-350, 100}));
    scene.addItem(new ArrowItem(QPointF{350, 350}, QPointF{350, -100}));
    scene.addItem(new ArrowItem(QPointF{350, 350}, QPointF{-100, 350}));
    view.resize(820, 820);
    view.show();
    return app.exec();
}
