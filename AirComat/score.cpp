#include "score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent)
    :QGraphicsTextItem(parent)
{
    //initialize the score to 0
    this->score=0;

    // draw the text
    setPlainText(QString("Score:")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));

}

void Score::increase()
{
    //increase the score
    this->score++;
    //update score in the scene
    setPlainText(QString("Score:")+QString::number(score));

}
