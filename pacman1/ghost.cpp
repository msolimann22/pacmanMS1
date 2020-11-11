#include "ghost.h"
#include <cstdlib>
#include <ctime>

void ghost::move(){
//    int pacman_column, pacman_row;
//    pacman_row = pacman.getRow(), pacman_column = pacman.getColumn();
    QTimer* timer = new QTimer(this);
    QEventLoop loop;

    srand(time(0));
    int moveNum = rand()%4;
    if (moveNum==0 && data[row - 1][column] != -1)  // up
           row--;
    else if (moveNum==1 && data[row + 1][column] != -1)  // down
        row++;
    else if (moveNum==2 && data[row][column + 1] != -1)  // right
             column++;
    else if (moveNum==3 && data[row][column - 1] != -1)  // left
             column--;

//    if(row != pacman_row && data[row - 1][column] != -1){
    setPos(50+50*column, 50+50*row);

    connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer->start(300);
    loop.exec();
    move();
    //delete timer;






}

ghost::ghost()
{

}
void ghost::createGhost(int row, int column, int type, int data[][26]){
    if(type == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/ghost1 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
            for(int i = 0; i < 16; i++)
                for(int j = 0; j < 26; j++)
                    this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
    }
    else if(type == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/ghost2 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
    }
    else if(type == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/ghost3 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
    }
    else if(type == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/ghost4 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
    }
}
