#include "basicenemy.h"
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
using namespace std;
BasicEnemy::BasicEnemy()
{
   int random_number= rand()%700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/images/BasicEnemy.png"));
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);//time of respaw enemies
}

void BasicEnemy::move()
{

    setPos(x(),y()+5);

}
