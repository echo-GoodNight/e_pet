#ifndef MYKITCHENBUTTON_H
#define MYKITCHENBUTTON_H

#include <QWidget>
#include <QPushButton>
class mykitchenbutton : public QPushButton
{
    Q_OBJECT
public:
    explicit mykitchenbutton(QWidget *parent = nullptr);

    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
signals:

};

#endif // MYKITCHENBUTTON_H
