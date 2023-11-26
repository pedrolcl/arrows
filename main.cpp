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
    scene.addItem(GenCircle(0, 0, 385));
    for (int angle = 0; angle < 360; angle += 15) {
        scene.addItem(new ArrowItem(5, 0, 380, angle));
    }
    view.resize(820, 820);
    view.show();
    return app.exec();
}
