#include "healht.h"
#include <QFont>
#include "game.h"
#include <QDebug>
extern Game *game;
//constructor of health of player
Healht::Healht(QGraphicsTextItem *parent)
    :QGraphicsTextItem(parent),vida(100)
{
    setPlainText(QString("Health:")+QString::number(this->vida));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}
void Healht::decrease(int n)
{
    //if score is > 10 add 50 to live of player
    this->vida-=n;
    setPlainText(QString("Health:")+QString::number(this->vida));
    setPos(0,20);
}

void Healht::showDecrease()
{
    setPlainText(QString::number(-10));
    setPos(game->player->x(),game->player->y());

}

void Healht::healthIncrease()
{
    //if score is > 10 add 50 to live of player
    this->vida+=25;
    setPlainText(QString("Health:")+QString::number(this->vida));
}

