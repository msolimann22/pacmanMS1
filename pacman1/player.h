#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include "food.h"
#include <QObject>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsScene>
class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap playerImage;
    int row;
    int column;
    int data[16][26];
    QString score;
public:
    player(int [][26]);
    void setRow(int);
    void setColumn(int);
    int getRow();
    int getColumn();
    QString getScore();
public:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
