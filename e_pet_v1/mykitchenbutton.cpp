#include "mykitchenbutton.h"

mykitchenbutton::mykitchenbutton(QWidget *parent) : QPushButton(parent)
{

}

void mykitchenbutton::enterEvent(QEvent *event){
    this->setCursor(QCursor(QPixmap(":/resource/basic/food.png"),-1,-1));
}
void mykitchenbutton::leaveEvent(QEvent *event){
    this->setCursor(QCursor(QPixmap(":/resource/basic/mouse.png"),-1,-1));
}
