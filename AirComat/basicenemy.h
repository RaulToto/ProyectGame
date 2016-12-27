/**
  * @file basicenemy.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title basic enemy
  * @brief this class is to representation of basic enemy if you killed basic enemy you score increase
  * if you score is more of 10 your live increase in 50
  */
#ifndef BASICENEMY_H
#define BASICENEMY_H
#include "enemy.h"
#include <QObject>
#include <QGraphicsPixmapItem>

class BasicEnemy:public QObject,public QGraphicsPixmapItem,public Enemy
{
    Q_OBJECT
public:
    BasicEnemy();
    //void enemyBullet();
public slots:
    void move();
};

#endif // BASICENEMY_H
