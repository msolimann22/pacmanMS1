#ifndef PLAYER_H
#define PLAYER_H

#include "food.h"
#include "ghost.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>
#include <QList>
#include <QGraphicsScene>
#include <QTimer>
#include <QEventLoop>
#include <stdexcept>
class player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QPixmap playerImage, livesImage;
    QGraphicsTextItem* score_label;
    QGraphicsPixmapItem livesObj[3];
    QTimer *timer;
    int row;
    int column;
    int data[16][26];
    int score = 0;
    int lives = 3;
    bool isSuper = false;
//    QString score_text = "0";
public:
    player(int [][26]);
    void setRow(int);
    void setColumn(int);
    void setScoreLabel(QGraphicsTextItem*);
    void updateScore(QGraphicsTextItem*);
    void setLivesObj();
    void removeLive(int);
    void makeSuper();
    int getRow();
    int getColumn();
    int getScore();
    int getLives();

public slots:
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
