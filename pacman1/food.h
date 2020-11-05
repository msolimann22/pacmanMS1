#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QTextStream>
#include <QGraphicsScene>

class food:public QGraphicsPixmapItem
{
private:
    int row;
    int column;
    QPixmap foodImage;
public:
    food();
    void setRow(int);
    void setColumn(int);
    void createFood(int, int);
    //int getRow();
    //int getColumn();
};

#endif // FOOD_H
