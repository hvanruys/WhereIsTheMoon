#include "gridscene.h"
#include <QPainter>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsView>
#include <QDebug>

void GridScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    const int gridSize = 100;

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);

    for (qreal x = left; x < rect.right(); x += gridSize)
        lines.append(QLineF(x, rect.top(), x, rect.bottom()));
    for (qreal y = top; y < rect.bottom(); y += gridSize)
        lines.append(QLineF(rect.left(), y, rect.right(), y));

    //qDebug() << lines.size();

    QPen graypen(Qt::lightGray);
    graypen.setWidth(1);

    painter->setPen(graypen);
    painter->drawLines(lines.data(), lines.size());

    painter->drawText(0, -500, "25°");
    painter->drawText(0, -400, "20°");
    painter->drawText(0, -300, "15°");
    painter->drawText(0, -200, "10°");
    painter->drawText(0, -100, "5°");
    painter->drawText(0, 0, "0°");
    painter->drawText(0, 100, "-5°");
    painter->drawText(0, 200, "-10°");
    painter->drawText(0, 300, "-15°");
    painter->drawText(0, 400, "-20°");
    painter->drawText(0, 500, "-25°");

    painter->drawText(-500, 0, "-25°");
    painter->drawText(-400, 0, "-20°");
    painter->drawText(-300, 0, "-15°");
    painter->drawText(-200, 0, "-10°");
    painter->drawText(-100, 0, "-5°");
    painter->drawText(0, 0, "0°");
    painter->drawText(100, 0, "5°");
    painter->drawText(200, 0, "10°");
    painter->drawText(300, 0, "15°");
    painter->drawText(400, 0, "20°");
    painter->drawText(500, 0, "25°");

    QPen greenpen(Qt::green);
    greenpen.setWidth(2);

    painter->setPen(greenpen);
    painter->drawLine(rect.left(), 0, rect.right(), 0);


}


