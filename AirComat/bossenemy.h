/**
  * @file bossenemy.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title class BossEnemy
  * @brief this class is toa representation a boss enemy if you killed a boss enemy you win the game
  */
#ifndef BOSSENEMY_H
#define BOSSENEMY_H
#include "enemy.h"
#include <QObject>
#include <QGraphicsPixmapItem>

class BossEnemy:public QObject,public QGraphicsPixmapItem,public Enemy
{
    Q_OBJECT
public:
    BossEnemy();
    //void enemyBullet();
public slots:
    void move();
};

#endif // BOSSENEMY_H
