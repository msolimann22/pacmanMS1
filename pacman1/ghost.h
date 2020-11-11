#ifndef GHOST_H
#define GHOST_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QEventLoop>
#include <QGraphicsScene>
#include "player.h"
class ghost:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap ghostImage;
    //QTimer *timer;
    int row;
    int column;
    int moveNum;
    int data[16][26];
    int counter=0;

public:
    int pacman_row, pacman_column;
    //ghost(int,int,int data[][26]);

    ghost();
    void createGhost(int, int, int, int data[][26]);
public slots:
    void move();
};

#endif // GHOST_H
