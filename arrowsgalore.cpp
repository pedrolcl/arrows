/**
 * Copyright (c) 2023-2024, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "arrowitem.h"

void addSceneArrow(QGraphicsScene &scene, ArrowItem *arrow)
{
    arrow->setToolTip(arrow->toString());
    scene.addItem(arrow);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);
    // returns the circumscribed square for a circle's center and radius
    auto gen_rect = [](qreal center_x, qreal center_y, qreal radius) {
        return QRectF(center_x - radius, center_y - radius, 2 * radius, 2 * radius);
    };
    scene.setBackgroundBrush(Qt::lightGray);
    scene.setSceneRect(-400, -400, 800, 800);
    scene.addEllipse(gen_rect(0, 0, 5));   // small central circle
    scene.addEllipse(gen_rect(0, 0, 305)); // outer circle
    // adding 24 arrows
    for (int angle = 0; angle < 360; angle += 15) {
        auto arrow = new ArrowItem(5, 0, 300, angle);
        arrow->setTransformOriginPoint(0, 0);
        addSceneArrow(scene, arrow);
    }
    // adding 4 arrows
    addSceneArrow(scene, new ArrowItem(QPointF{-350, -350}, QPointF{100, -350}));
    addSceneArrow(scene, new ArrowItem(QPointF{-350, -350}, QPointF{-350, 100}));
    addSceneArrow(scene, new ArrowItem(QPointF{350, 350}, QPointF{350, -100}));
    addSceneArrow(scene, new ArrowItem(QPointF{350, 350}, QPointF{-100, 350}));
    view.resize(820, 820);
    view.show();
    return app.exec();
}
