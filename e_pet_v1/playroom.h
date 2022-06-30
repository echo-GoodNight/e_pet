#ifndef PLAYROOM_H
#define PLAYROOM_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QPoint>
#include <QCursor>
#include <qpainter.h>
#include <define.h>
#include <pet.h>
#include <kitchen.h>
#include <bathroom.h>
#include <mainwindow.h>

namespace Ui {
class playroom;
}

class playroom : public QMainWindow
{
    Q_OBJECT

public:
    explicit playroom(QWidget *parent = nullptr, bool fetchornot = false);
    ~playroom();
    void paintEvent(QPaintEvent*);
    Pet* pet;

protected:

    void keyPressEvent(QKeyEvent *e);
//    void mouseMoveEvent(QMouseEvent* event);
    void keyReleaseEvent(QKeyEvent*);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_bedbutton_clicked();

    void aDaypassed();

    void on_pushButton_4_clicked();

private:
    Ui::playroom *ui;

    //宠物的数值显示
    QLabel *moodLabel,*healthLabel,*hungerLabel,*activeLabel;
    //宠物
    int petx=700;  //x坐标
    int pety=700;  //y坐标

    int happyAction=true;
    int sickOrHungerAction=false;

    int upAction=24;   //向上移动
    int downAction=44;  //向下移动
    int leftAction=50;  //向左移动
    int rightAction=50;  //向右移动
    int sleepAction=60; //睡觉

    bool upMove=false;
    bool downMove=false;
    bool leftMove=false;
    bool rightMove=false;
    bool sleepMove=false;
    QString appearance="Yangpa";

    QTimer* timer;

};

#endif // PLAYROOM_H
