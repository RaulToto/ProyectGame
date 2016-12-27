#include "player.h"
#include "bullet.h"
#include "game.h"
#include "basicenemy.h"
#include "bossenemy.h"
#include <QKeyEvent>
#include <QDebug>
extern Game *game;
int velocidad = 20;
Player::Player()
{
    //create a pixmap
    setPixmap(QPixmap(":/images/images/Player.png"));

}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left || event->key()=='A' )
    {
        if(pos().x()>0)
        setPos(x()-velocidad,y());
    }
    else if(event->key()==Qt::Key_Right || event->key()=='D')
    {
        if(pos().x()+100<800)
        setPos(x()+velocidad,y());
    }

    else if (event->key()==Qt::Key_Space || event->key()=='X')
    {
        Bullet *bullet = new Bullet(-10);
        bullet->setPos(x(),y());
        scene()->addItem(bullet);

        Bullet *bullet1= new Bullet(-10);
        bullet1->setPos(x()+100,y());
        scene()->addItem(bullet1);

    }
}//end keyPresevent

void Player::spawn()
{
    //create a enemy
    //create enemy and bullet with enemy number >0
    if (game->enemyController->getEnemyNum()>0){
        game->basicEnemy= new BasicEnemy();
        scene()->addItem(game->basicEnemy);
        Bullet *bullet = new Bullet(+10);
        bullet->setPos(game->basicEnemy->pos().x(),game->basicEnemy->pos().y()+70);
        scene()->addItem(bullet);
        //add bossenemy to scene
        if (game->enemyController->getEnemyNum()<3)
        {
            scene()->addItem(game->bossEnemy);
            //qDebug() << "add bosss" ;
        }
    }
    //if numEnemy < 0  create bullets for bossEnemy
    else
    {

        Bullet *bullet = new Bullet(+30);
        bullet->setPos(game->bossEnemy->pos().x()-100,game->bossEnemy->pos().y()+70);
        scene()->addItem(bullet);


        Bullet *bullet1 = new Bullet(+30);
        bullet1->setPos(game->bossEnemy->pos().x()+50,game->bossEnemy->pos().y()+70);
        scene()->addItem(bullet1);
        //if boos live <1 the game finish and call to functin you win
        if(game->enemyController->getBossLive()<1)
        {
            scene()->clear();
            game->youWin();
        }
     }

}//end spawn
