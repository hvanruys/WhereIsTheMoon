#ifndef GRIDSCENE_H
#define GRIDSCENE_H

#include <QGraphicsScene>

class GridScene : public QGraphicsScene
{

public:
    GridScene(qreal x, qreal y, qreal w, qreal h, int myscale)
        : QGraphicsScene(x, y, w, h)
    { scale = myscale; }
    QVarLengthArray<QLineF, 100> lines;
private:
    int scale;
protected:
    void drawBackground(QPainter *painter, const QRectF &rect);

};

#endif // GRIDSCENE_H
