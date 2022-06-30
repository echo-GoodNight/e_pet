#ifndef KITCHEN_H
#define KITCHEN_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>

#include <define.h>
#include <pet.h>
#include <playroom.h>
#include <bathroom.h>

#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPainter>
#include <QUrl>
#include <QFile>
#include <QTextStream>
#include <QMimeData>
#include <QDrag>

#include <fstream>
#include <iostream>

namespace Ui {
class kitchen;
}

class kitchen : public QMainWindow
{
    Q_OBJECT

public:
    explicit kitchen(Pet* ssspet=nullptr,QWidget *parent = nullptr);
    ~kitchen();
    void paintEvent(QPaintEvent *);

    int greedy_action=false;
    int has_eaten=false;
    void mousePressEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::kitchen *ui;

    //宠物的数值显示
    QLabel *moodLabel,*healthLabel,*hungerLabel,*activeLabel;
    //界面操作
    QPushButton *backBt,*bedBt;
    //宠物
    Pet* pet=new Pet;
   int petx=1000;  //x坐标
   int pety=600;  //y坐标

   int happyAction=true;
   int sickOrHungerAction=false;


   //食品有无 显示
   int no_chicken_leg;
   int no_sausage;
   int no_vegetable;
   //食品初始坐标
   const int chicken_leg_x=300;
   const int chicken_leg_y=400;
   const int sausage_x=600;
   const int sausage_y=400;
   const int vegetable_x=900;
   const int vegetable_y=400;
};

#endif // KITCHEN_H
