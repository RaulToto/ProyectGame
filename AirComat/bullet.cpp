#include "bullet.h"
#include "game.h"
#include "basicenemy.h"
#include "bossenemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
//extern variable
extern Game *game;
Bullet::Bullet(int speed)
    :vel(speed)
{
    //draw the bullet
    if (speed>0)
    {
        setPixmap(QPixmap(":/images/images/Missle.png"));
        setTransformOriginPoint(50,50);
        setRotation(180);
        QTimer *timer1 = new QTimer();
        connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
        //bullet velocity of enemy
        timer1->start(game->enemyController->getVelBoth());
    }
    else
    {
        setPixmap(QPixmap(":/images/images/Bullet.png"));
        //connect
        QTimer *timer = new QTimer();
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        //bullet velocity of player
        timer->start(10);
    }
}
void Bullet::move()
{
    //if bullet collides with enemy ,destroy both
    QList<QGraphicsItem *> colliding_items=collidingItems();
    //if bullet updown
    if(this->vel<0){


        for (int i = 0, n = colliding_items.size();i<n; ++i) {
            if(typeid(*(colliding_items[i]))==typeid(BasicEnemy))
            {
                game->score->increase();
                game->enemyController->enemyNumDecrease();
                qDebug() << game->enemyController->getEnemyNum();
                //remove them bhot
                scene()->removeItem(colliding_items[i]);
                scene()->removeItem(this);
                //delete them
                delete colliding_items[i];
                delete this;
                return ;

            }

        }


    }
    //if bullet getdwn
    if(this->vel>0)
    {
        for (int i = 0, n = colliding_items.size();i<n; ++i) {
            if(typeid(*(colliding_items[i]))==typeid(Player))
            { 
                //if (game->enemyController->getEnemyNum()>0)
                    //game->healht->decrease(1);
                //else if(game->enemyController->getBossLive()>0)
                game->healht->decrease(3);

            }
            if (game->healht->getHealth()<1)
            {
                scene()->clear();
                game->gameOver();
            }
        }
    }
    //with bullet collides with boss enemy
    if(game->enemyController->getBossLive()>0)
    {
        for (int i = 0, n = colliding_items.size();i<n; ++i) {
            if(typeid(*(colliding_items[i]))==typeid(BossEnemy))
            {
                game->enemyController->bossLiveDecrease();
                //remove them bhot
                qDebug()<< game->enemyController->getBossLive();

                scene()->removeItem(this);
                delete this;
                //scene()->removeItem(colliding_items[i]);
                //scene()->removeItem(this);

            }

        }

    }

    //move bullet up destroy bullet
    setPos(x(),y()+this->vel);
    if(pos().y()<0 or pos().y() >600)
    {
        scene()->removeItem(this);
        delete this;
        //qDebug() <<"pos" << pos().x() ;

    }

}
