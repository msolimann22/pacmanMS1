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
    QTimer *timer;
    QEventLoop loop;
    QList<QGraphicsItem*> items1;
    int row;
    int column;
    int initial_row;
    int initual_column;
    int id;
    int data[16][26];
public:
    ghost();
    int getInitialRow();
    int getInitialColumn();
    int getId();
    void fear();
    void removeFear();
    void createGhost(int, int, int, int data[][26]);
public slots:
    void move();
};

#endif // GHOST_H
