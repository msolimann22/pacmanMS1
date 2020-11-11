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
    score = 0;
    //scene()->addText(score_text);
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
int player::getScore(){
    return score;
}
void player::keyPressEvent(QKeyEvent *event){
    timer = new QTimer(this);
    QEventLoop loop;
    if(event->key() == Qt::Key_Up && data[row - 1][column] != -1){
        row--;
        playerImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_back.png");
        playerImage = playerImage.scaledToWidth(49);
        playerImage = playerImage.scaledToHeight(49);
        setPixmap(playerImage);
        //QEventLoop loop;
        //connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));

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
    if(data[row][column] == -2){
        row = 7, column = 24;

    }
    if(data[row][column] == -3){
        row = 7, column = 0;

    }
    setPos(50+50*column, 50+50*row);




    //detecting collision

    QString score_text;
    QList<QGraphicsItem*> items = collidingItems();
    for(int i = 0; i < items.size(); i++){
        if(typeid (*items[i]) == typeid (food)){
            scene()->removeItem(items[i]);
            food* food1 = dynamic_cast<food*>(items[i]);
            //food* food1 = static_cast<food>(items[i]);
            if(food1->getIsSuper()){
                score += 70;

            }
            else
                score += 30;
            updateScore(score_label);

        }
        if(typeid (*items[i]) == typeid (ghost)){
            // Upon coliding with ghost
            if(lives != 0){
              removeLive(lives-1);
              lives--;
              row = 7;
              column = 1;
              setPos(50 + 50 * row, 50 + 50 * column );

            }


        }
    }
    try {
        connect(timer, SIGNAL(timeout()), &loop, SLOT(quit()));
        timer->start(100);
        loop.exec();
        keyPressEvent(event);
    } catch (std::exception& e) {
        score_label->setPlainText(e.what());
        score_label->update();
    }
    delete timer;

}
void player::makeSuper(){
    isSuper = true;

}

void player::updateScore(QGraphicsTextItem* score_label){
    //this->score_label = score_label;
    score_label->setPlainText(QString::number(score));
    score_label->update();
}
void player::setScoreLabel(QGraphicsTextItem* score_label){
    this->score_label = score_label;
}
void player::removeLive(int index){
    scene()->removeItem(&livesObj[index]);
    //scene()->removeItem(&lives[index]);
}
void player::setLivesObj(){
    livesImage.load("D:/QT/pacman1/Assets/Sprite1/sprite_front.png");
    livesImage = livesImage.scaledToWidth(50);
    livesImage = livesImage.scaledToHeight(50);
    for(int i = 0; i < lives; i++){
        livesObj[i].setPixmap(livesImage);
        livesObj[i].setPos(550 + ((i + 1) * 50) , 1);
        scene()->addItem(&livesObj[i]);
    }
}
int player::getLives(){
    return lives;
}

