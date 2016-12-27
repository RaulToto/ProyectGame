/**
  * @file score.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title class player
  */
#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score:public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=0);
    void increase();
    /**
     * @brief getScore
     * @return return score
     */
    int getScore()
    {
        return score;
    }
    /**
     * @brief setScore
     * @param n is new val for score
     */
    void setScore(int n)
    {
        this->score=n;
    }


private:
    int score;
};

#endif // SCORE_H
