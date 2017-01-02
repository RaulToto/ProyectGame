#ifndef GIFT_H
#define GIFT_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Gift:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Gift();
    //void enemyBullet();
public slots:
    void move();
};

#endif // GIFT_H
