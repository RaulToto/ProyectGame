/**
  * @file enemy.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title abstract class enemy
  * @brief
  */
#ifndef ENEMY_H
#define ENEMY_H
#include <QObject>
class Enemy
{
public:
    Enemy();
public slots:
    virtual void move()=0;
};

#endif // ENEMY_H
