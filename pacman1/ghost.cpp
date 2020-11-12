#include "ghost.h"
#include <cstdlib>
#include <ctime>

void ghost::move(){

    int moveNum = rand()%4;
    if (moveNum==0 && data[row - 1][column] != -1){
                row--;
                srand(time(NULL));

    }
    else if (moveNum==1 && data[row + 1][column] != -1){
                        row++;
                        srand(time(NULL));

           }

    else if (moveNum==2 && data[row][column + 1] != -1){
            column++;
            srand(time(NULL));

        }

    else if (moveNum==3 && data[row][column - 1] != -1){
                     column--;
                     srand(time(NULL));

    }

    setPos(50+50*column, 50+50*row);

    QTimer::singleShot(220, this, SLOT(move()));

}



int ghost::getInitialRow(){
    return initial_row;
}
int ghost::getInitialColumn(){
    return initual_column;
}
int ghost::getId(){
    return id;
}
ghost::ghost()
{

}
void ghost::removeFear(){
    if(id == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost1/normal/ghost1 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost2/normal/ghost2 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost3/normal/ghost3 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost4/normal/ghost4 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
}
void ghost::fear(){
    if(id == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost1/feared/ghost1 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost2/feared/ghost2 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost3/feared/ghost3 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
    if(id == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost4/feared/ghost4 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
    }
}
void ghost::createGhost(int row, int column, int type, int data[][26]){
    if(type == 1){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost1/normal/ghost1 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
            for(int i = 0; i < 16; i++)
                for(int j = 0; j < 26; j++)
                    this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
    else if(type == 2){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost2/normal/ghost2 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
    else if(type == 3){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost3/normal/ghost3 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
    else if(type == 4){
        ghostImage.load("D:/QT/pacman1/Assets/Ghosts/Ghost4/normal/ghost4 - front.png");
        ghostImage = ghostImage.scaledToWidth(50);
        ghostImage = ghostImage.scaledToHeight(50);
        setPixmap(ghostImage);
        this->row = row;
        this->column = column;
        initial_row = row;
        initual_column = column;
        id = type;
        srand(time(NULL));
        for(int i = 0; i < 16; i++)
            for(int j = 0; j < 26; j++)
                this->data[i][j] = data[i][j];
        setPos(50 + 50 * column, 50 + 50 * row );
        move();
    }
}
