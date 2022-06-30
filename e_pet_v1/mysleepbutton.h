#ifndef MYSLEEPBUTTON_H
#define MYSLEEPBUTTON_H

#include <QWidget>
#include <QPushButton>
class mysleepbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mysleepbutton(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
//    void dog_sleep();
//    void dog_awake();

signals:

};

#endif // MYSLEEPBUTTON_H
