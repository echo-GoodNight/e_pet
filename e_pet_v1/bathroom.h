#ifndef BATHROOM_H
#define BATHROOM_H

#include <QMainWindow>
#include <QPushButton>
#include <QPixmap>
#include <define.h>
#include <pet.h>
#include <kitchen.h>
#include <playroom.h>
#include <QMouseEvent>
namespace Ui {
class bathroom;
}

class bathroom : public QMainWindow
{
    Q_OBJECT

public:
    explicit bathroom(Pet* ssspet=nullptr,QWidget *parent = nullptr);
    ~bathroom();
    void paintEvent(QPaintEvent *);

    int is_dirty=true;
    int is_brushed=false;
    int rlcnt=0;
    int in_right=0;
    // 鼠标显示设置
    int is_using_what=0;//0 for nothing 1 for brush 2 for shower

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);


private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();

private:
    Ui::bathroom *ui;

    //宠物的数值显示
    QLabel *moodLabel,*healthLabel,*hungerLabel,*activeLabel;
    //界面操作
    QPushButton *backBt,*bedBt;
    //宠物
    Pet* pet=new Pet;
   int petx=800;  //x坐标
   int pety=300;  //y坐标

   int happyAction=true;
   int sickOrHungerAction=false;
};

#endif // BATHROOM_H
