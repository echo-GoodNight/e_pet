#include "myplayingbutton.h"

myplayingbutton::myplayingbutton(QWidget *parent) : QPushButton(parent)
{

}

void myplayingbutton::enterEvent(QEvent *event){
    this->setCursor(QCursor(QPixmap(":/resource/basic/walking.png"),-1,-1));
}
void myplayingbutton::leaveEvent(QEvent *event){
    this->setCursor(QCursor(QPixmap(":/resource/basic/mouse.png"),-1,-1));
}
