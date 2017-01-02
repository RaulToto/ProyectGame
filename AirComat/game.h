/**
  * @file game.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title class game
  */
#ifndef GAME_H
#define GAME_H
//file includes
#include "score.h"
#include "bossenemy.h"
#include "basicenemy.h"
#include "player.h"
#include "bullet.h"
#include "healht.h"
#include "enemycontroller.h"
#include "background.h"
#include "gift.h"
//qt includes
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWidget>
#include <QGraphicsTextItem>
class Game:public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent=0);
    /**
     * @brief displayMainMenu show this function with game start
     */
    void displayMainMenu();
    /**
     * @brief gameOver function for finish game
     */
    void gameOver();
    /**
     * @brief youWin function for finish game
     */
    void youWin();

    //----------objects
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Healht *healht;
    BasicEnemy *basicEnemy;
    EnemyController *enemyController;
    BossEnemy *bossEnemy;
    BackGround *backGround;
    //Gift *gift;
    //factory methots
    Bullet *bulletFactory(int x);
    BasicEnemy *basicEnemyFactory();
public slots:
    /**
     * @brief start is a slot connect with signal clicked
     */
    void start();
};

#endif // GAME_H
