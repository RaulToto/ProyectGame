#include "game.h"
#include "healht.h"
#include "basicenemy.h"
#include "button.h"
#include <QDebug>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QImage>
using namespace std;
//game constructor
Game::Game(QWidget *parent)
{
    //create the scene---------------------------------------
    scene= new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);//make the scene 800X600
    setBackgroundBrush(QBrush(QImage(":/images/images/Background.png")));

    setScene(scene);
    //difine size of scene-----------------------------------
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);//size of scene

}
//function start game
void Game::start()
{
    //clear at scene;
    scene->clear();
    //crete player--------------------------------------------
    player= new Player();
    player->setPos(400,500);//pos of player in start game
    //make a setFocusable-------------------------------------
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add player at to scene----------------------------------
    scene->addItem(player);

    //create a score------------------------------------------
    score= new Score();
    scene->addItem(score);

    //create a health-----------------------------------------
    healht = new Healht();
    healht->setPos(score->pos().x(),score->pos().y()+20);
    scene->addItem(healht);
    //spawn de enmies-----------------------------------------
    enemyController = new EnemyController();
    enemyController->setPos(score->pos().x(),score->pos().y()+50);
    enemyController->setPos(score->pos().x(),score->pos().y()+50);
    scene->addItem(enemyController);
    //create a  boss enemy-------------------------------------------
    bossEnemy= new BossEnemy();

    QTimer *timer= new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000);

    //show();
}
//display main menu with start game
void Game::displayMainMenu(){
    // create the title text
    backGround= new BackGround();
    scene->addItem(backGround);
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Air Combat"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}

//gameover function
void Game::gameOver()
{
    Button* gameOverButton = new Button(QString("Game Over"));
    int qxPos = this->width()/2 - gameOverButton->boundingRect().width()/2;
    int qyPos = 250;
    gameOverButton->setPos(qxPos,qyPos);
    connect(gameOverButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(gameOverButton);
}
//win function
void Game::youWin()
{
    Button* winButton = new Button(QString("CONGRATULATIONS YOU WIN"));
    int qxPos = this->width()/2 - winButton->boundingRect().width()/2;
    int qyPos = 250;
    winButton->setPos(qxPos,qyPos);
    connect(winButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(winButton);
}
