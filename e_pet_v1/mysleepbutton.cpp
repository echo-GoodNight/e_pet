#include "mysleepbutton.h"

mysleepbutton::mysleepbutton(QWidget *parent) : QPushButton(parent)
{

}

void mysleepbutton::enterEvent(QEvent *event){
    this->setCursor(QCursor(QPixmap(":/resource/playroom/zzz.png"),-1,-1));
}
void mysleepbutton::leaveEvent(QEvent *event){
    this->setCursor(QCursor(QPixmap(":/resource/basic/mouse.png"),-1,-1));
}
//void dog_sleep(){
//    sleepMove=!sleepMove;
//}
//void dog_awake(){
//    sleepMove=!sleepMove;
//}
