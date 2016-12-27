/**
  * @file enemycontroller.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title class enemycontroller
  * @brief this class is for controller enemy for exmaple to control your live or number enemies
  */
#ifndef ENEMYCONTROLLER_H
#define ENEMYCONTROLLER_H

#include <QGraphicsTextItem>
class EnemyController:public QGraphicsTextItem
{
public:
    EnemyController(QGraphicsTextItem *parent=0);
    void enemyNumDecrease();
    void bossLiveDecrease();
    int getEnemyNum();
    int getBossLive();
    int getVelBoth();
private:
    int numBasicEnemies;
    int liveBossEnemy;


};

#endif // ENEMYCONTROLLER_H
