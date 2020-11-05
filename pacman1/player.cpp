#include "player.h"

player::player(int data[][26])
{
    QPixmap playerImage("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
    playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
    playerImage = playerImage.scaledToWidth(49);
    playerImage = playerImage.scaledToHeight(49);
    setPixmap(playerImage);
    row = 7;
    column = 1;
    score = "0";
    setPos(50 + 50 * column, 50 + 50 * row );

    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 26; j++){
            this->data[i][j] = data[i][j];
        }
    }
}
void player::setRow(int row){
    this->row = row;
}
void player::setColumn(int column){
    this->column = column;
}
int player::getRow(){
    return row;
}
int player::getColumn(){
    return column;
}
QString player::getScore(){
    return score;
}
void player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Up && data[row - 1][column] != -1){
        row--;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_back.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
    }
    if(event->key() == Qt::Key_Down && data[row + 1][column] != -1){
        row++;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
    }
    if(event->key() == Qt::Key_Right && data[row][column + 1] != -1){
        column++;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_right.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
    }
    if(event->key() == Qt::Key_Left && data[row][column - 1] != -1){
        column--;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_left.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
    }

    setPos(50+50*column, 50+50*row);

    //detecting collision
    int score2 = 0;
    QGraphicsTextItem* score_label = scene()->addText(score);
    QList<QGraphicsItem*> items = collidingItems();
    for(int i = 0; i < items.size(); i++){
        if(typeid (*items[i]) == typeid (food)){
            scene()->removeItem(items[i]);
            score2 = score.toInt();
            score2 = score2 + 100;
            score = score2;
            score_label->setPos(50,100);

        }

    }
}
