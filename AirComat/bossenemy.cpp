#include "game.h"
#include "bossenemy.h"
#include <QGraphicsScene>
#include <QDebug>
#include <QTimer>
#include <QList>
#include <typeinfo>
//lib c++11
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <stdlib.h>
extern Game *game;
using namespace std;
BossEnemy::BossEnemy()
{
    int random_number= rand()%700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/images/BossEnemy.png"));
    QTimer *timer1= new QTimer();
    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(1000);//time of respaw enemies
    //scene()->addItem(this);
}

void BossEnemy::move()
{

    int random_number= rand()%100;
    setPos(game->player->x()+random_number,game->player->y()-500);

}
