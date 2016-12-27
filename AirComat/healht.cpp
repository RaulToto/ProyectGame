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
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}
void Healht::decrease(int n)
{
    //if score is > 10 add 50 to live of player
    if(game->score->getScore()>=10)
    {
        qDebug() <<"ingrease live";
        this->vida+=50;
        game->score->setScore(0);
    }
    this->vida-=n;

    setPlainText(QString("Health:")+QString::number(this->vida));
}

