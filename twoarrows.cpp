/**
 * Copyright (c) 2023, Pedro López-Cabanillas
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <QApplication>
#include <QColor>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "arrowitem.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QGraphicsScene scene;
    QGraphicsView view(&scene);

    scene.setBackgroundBrush(QColorConstants::Svg::lightcyan);
    scene.setSceneRect(-400, -400, 800, 450);

    auto arrow1 = new ArrowItem(0, 0, 500, -45);
    scene.addItem(arrow1);
    qDebug() << "Arrow1. origin:" << arrow1->origin() << "length:" << arrow1->length()
             << "orientation:" << arrow1->angle();

    auto arrow2 = new ArrowItem(QPointF{-354, -354}, QPointF{0, 0});
    scene.addItem(arrow2);
    qDebug() << "Arrow2. origin:" << arrow2->origin() << "length:" << arrow2->length()
             << "orientation:" << arrow2->angle();

    view.resize(820, 470);
    view.show();
    return app.exec();
}
