#include "gift.h"
#include "game.h"
#include "player.h"
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
Gift::Gift()
{
    int random_number= rand()%700;
    setPos(random_number,0);

    setPixmap(QPixmap(":/images/images/Health.png"));
    QTimer *timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(30);//time of respaw enemies
}

void Gift::move()
{


    setPos(x(),y()+5);
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for (int i = 0, n = colliding_items.size();i<n; ++i) {
        if(typeid(*(colliding_items[i]))==typeid(Player))
        {
            //qDebug() <<"ingrease live";
            game->healht->healthIncrease();
            //remove them bhot
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them
            //delete colliding_items[i];
            delete this;
            return ;

        }

    }
    if(pos().y()>600)
    {
        scene()->removeItem(this);
        delete this;
    }


}
