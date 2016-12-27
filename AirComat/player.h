/**
  * @file player.h
  * @version 1.0
  * @date 25/12/16
  * @author Raul Edgar Quispe Totocayo
  * @title class player
  */
#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
class Player:public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    /**
     * @brief keyPressEvent
     * @param event if you press a key
     */
    void keyPressEvent(QKeyEvent *event);

public slots:
    /**
     * @brief spawn is a slot
     */
    void spawn();
};

#endif // PLAYER_H
