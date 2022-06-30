#ifndef MYPLAYINGBUTTON_H
#define MYPLAYINGBUTTON_H

#include <QWidget>
#include <QPushButton>
class myplayingbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit myplayingbutton(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
//    void dog_sleep();
//    void dog_awake();

signals:

};


#endif // MYPLAYINGBUTTON_H
