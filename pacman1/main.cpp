#include "mainwindow.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include "player.h"
//#include <QBrush>
int main(int argc, char *argv[])
{
    //Create the view and scene
    QApplication a(argc, argv);
    QGraphicsView view;
    view.setFixedSize(1400,900);
    view.setBackgroundBrush(QBrush(Qt::black));
    QGraphicsScene scene;
    view.setScene(&scene);

    //Read board data from text file
    QFile board("D:/QT/pacman1/Text File Data/board.txt");
    board.open(QIODevice::ReadOnly);
    int boardData[16][26];
    QTextStream board_stream(&board);
    for(int i = 0; i < 16; i++){
        QString temp;
        for(int j = 0; j < 26; j++){
            board_stream >> temp;
            boardData[i][j] = temp.toInt();
        }
    }
    //draw the board graphics
    QPixmap bricksImage("D:/QT/pacman1/Assets/Terrain/bricks1.png");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);
    QPixmap waterImage("D:/QT/pacman1/Assets/Terrain/water2.png");
    waterImage = waterImage.scaledToWidth(50);
    waterImage = waterImage.scaledToHeight(50);
    QGraphicsPixmapItem boardImages[16][26];
    QString temp;
    for(int i = 0; i < 16; i++){

        for(int j = 0; j < 26; j++){
            if(boardData[i][j] == -1){
                boardImages[i][j].setPixmap(bricksImage);
            }
            else{
                boardImages[i][j].setPixmap(waterImage);
            }
            boardImages[i][j].setPos(50 * j + 50, 50 * i + 50);
            scene.addItem(&boardImages[i][j]);
        }
    }

    //Create Food
    //QPixmap foodImage("D:/QT/pacman1/Assets/Items/rare candy.png");
    //foodImage = foodImage.scaledToWidth(50);
    //foodImage = foodImage.scaledToHeight(50);

    food* Allfood = new food[150];
    QFile food_folder("D:/QT/pacman1/Text File Data/food.txt");
    food_folder.open(QIODevice::ReadOnly);
    int boardData2[16][26];
    QTextStream food_stream(&food_folder);
    for(int i = 0; i < 16; i++){
        QString temp;
        for(int j = 0; j < 26; j++){
            food_stream >> temp;
            boardData2[i][j] = temp.toInt();
        }

    }


    int k = 0;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 26; j++){
             if(boardData2[i][j] == -2){

               Allfood[k].createFood(i,j);
               scene.addItem(&Allfood[k]);
               k++;
            }
        }

    }

    // Create the player obj
    player player1(boardData);
    scene.addItem(&player1);
    player1.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    player1.setFocus();

    //QGraphicsTextItem *score_label = scene.addText(player1.getScore());
    //score_label->setScale(100);
    //score_label->setPos(50, 100);

    view.show();
    return a.exec();
}
