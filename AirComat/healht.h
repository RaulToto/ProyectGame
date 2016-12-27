/**
  * @file health.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title class player
  */
#ifndef HEALHT_H
#define HEALHT_H
#include <QGraphicsTextItem>
//#include "game.h"

class Healht:public QGraphicsTextItem
{
public:
    Healht(QGraphicsTextItem *parent=0);
    /**
     * @brief decrease decrease live function
     * @param n n is a number for decrease live
     */
    void decrease(int n);
    /**
     * @brief getHealth
     * @return return player live
     */
    int getHealth()
    {
        return vida;
    }
private:
    /**
     * @brief vida is a number for representation player live
     */
    int vida;

};

#endif // HEALHT_H
