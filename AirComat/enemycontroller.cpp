#include "enemycontroller.h"
#include <QFont>
#include <QDebug>
EnemyController::EnemyController(QGraphicsTextItem *parent)
    :liveBossEnemy(200),numBasicEnemies(50),QGraphicsTextItem(parent)
{

    setPlainText(QString("HealthEnemy:")+QString::number(this->liveBossEnemy));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
    setPos(200,200);
}
void EnemyController::enemyNumDecrease()
{
    this->numBasicEnemies--;
}

void EnemyController::bossLiveDecrease()
{
    this->liveBossEnemy--;
    setPlainText(QString("HealthEnemy:")+QString::number(this->liveBossEnemy));

}

int EnemyController::getEnemyNum()
{
    return this->numBasicEnemies;
}

int EnemyController::getBossLive()
{
    return this->liveBossEnemy;
}
//this function return velocity  bullet for enemy
int EnemyController::getVelBoth()
{
    if(getEnemyNum()>40)
        return 50;
    else if(getEnemyNum()>30)
        return 40;
    else if(getEnemyNum()>20)
        return 30;
    else if(getEnemyNum()>10)
        return 20;
    else
        return 15;

}

