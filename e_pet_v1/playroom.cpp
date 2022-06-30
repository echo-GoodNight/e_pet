#include "playroom.h"
#include "ui_playroom.h"
#include <mazegenerator.h>
#include <QDebug>
#include "pet.h"
#include <fstream>
#include <mainwindow.h>
#include <petgame.h>
using namespace std;
playroom::playroom(QWidget *parent,bool fetchornot) :
    QMainWindow(parent),
    ui(new Ui::playroom)
{
    ui->setupUi(this);
    //*********布局*************//
    moodLabel=new QLabel(this);
    moodLabel->setText("心情：");
    healthLabel=new QLabel(this);
    healthLabel->setText("健康：");
    hungerLabel=new QLabel(this);
    hungerLabel->setText("能量：");
    activeLabel=new QLabel(this);
    activeLabel->setText("活力：");

    //********样式*********//
    setWindowTitle("PetMachine");
    setFixedSize(1600,1024);
    this->centralWidget()->setMouseTracking(true);
    this->setMouseTracking(true);

    //鼠标样式
    this->setCursor(QCursor(QPixmap(":/resource/basic/mouse.png"),0,0));
    bool exi=false;
    QString filePath = "D:/State.txt";
        QFile file(filePath);
        if(file.exists())
        {
            qDebug()<<"文件存在";
            exi= true;
        }
        else
        {
            qDebug()<<"文件不存在";
            exi=false;
        }
    if (fetchornot && exi)
    {
        pet=new Pet;
        int health, hunger,active,mood,age;
        ifstream myin("D:/State.txt");
        myin >> health ;
        myin >> hunger;
        myin >> active ;
        myin >> mood ;
        myin >> age;
        pet->setHealth(health);
        pet->setActive(active);
        pet->setHunger(hunger);
        pet->setMood(mood);
        pet->setAge(age);

    }
    else
    {
        pet=new Pet;
    }


    //宠物的属性值
    moodLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(65,165,238);font-weight:bold");
    healthLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(65,165,238);font-weight:bold");
    hungerLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(65,165,238);font-weight:bold");
    activeLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(65,165,238);font-weight:bold");
    moodLabel->setFixedSize(225,40);
    healthLabel->setFixedSize(225,40);
    hungerLabel->setFixedSize(225,40);
    activeLabel->setFixedSize(225,40);
    moodLabel->move(48,10);
    healthLabel->move(48+240,10);
    hungerLabel->move(48+240*2,10);
    activeLabel->move(48+240*3,10);
    ui->label->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(65,165,238);font-weight:bold");
    ui->label_2->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(65,165,238);font-weight:bold");
    ui->agelb->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(0,0,0);font-weight:bold");
    ui->namelb->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(0,0,0);font-weight:bold");


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(aDaypassed()));
    timer->start(1000);

}

playroom::~playroom()
{
    delete ui;
}

void playroom::on_pushButton_clicked()
{    
    kitchen* p=new kitchen(pet);
    p->show();
    hide();
}

void playroom::on_pushButton_2_clicked()
{
    bathroom *p=new bathroom(pet);
    p->show();
    hide();
}

void playroom::on_bedbutton_clicked()
{
    sleepMove=!sleepMove;
    if (sleepMove){//睡觉后健康值加一
        if (pet->getHealth()<4){
            pet->setActive(pet->getActive()+1);
        }
    }
    update();
}

void playroom::paintEvent(QPaintEvent *){

    QPainter p(this);
    QFont font;
    font.setPointSize(10);
    p.setFont(font);
    p.setPen(QColor(25,202,173));
    //背景
    p.drawPixmap(rect(),QPixmap(":/resource/playroom/background_hd.png"));

    //显示心情值
    int mood=pet->getMood();
//    qDebug() << "Mood : " << mood ;
    for(int i=0;i<mood;i++){
        p.drawPixmap(117+i*32,15,30,38,QPixmap(":/resource/basic/mood.png"));
    }
    //显示健康(生命)值
    int health=pet->getHealth();
    for(int i=0;i<health;i++){
        p.drawPixmap(357+i*32,15,30,38,QPixmap(":/resource/basic/health.png"));
    }
    //显示饥饿值
    int hunger=pet->getHunger();
    for(int i=0;i<hunger;i++){
        p.drawPixmap(597+i*32,15,30,38,QPixmap(":/resource/basic/hunger.png"));
    }
    //显示活力值
    int active=pet->getActive();
    for(int i=0;i<active;i++){
        p.drawPixmap(837+i*32,15,30,38,QPixmap(":/resource/basic/active.png"));
    }
    p.drawPixmap(1100,30,300,200,QPixmap("://resource/playroom/board.png"));

    //显示宠物
    if(!sleepMove){
        if(pet->getHealth()>2&&pet->getHunger()>2){
            if(rightMove)
            {
            p.drawPixmap(petx,pety,pet->getWidth(),pet->getHeight(),QPixmap(":/resource/petimage/happy_dog_r.png"));
            }
            else
            {
            p.drawPixmap(petx,pety,pet->getWidth(),pet->getHeight(),QPixmap(":/resource/petimage/happy_dog.png"));
            }

        }else{
            p.drawPixmap(petx,pety,pet->getWidth(),pet->getHeight(),QPixmap(":/resource/petimage/hungry_dog.png"));
        }
    }
    else{
            p.drawPixmap(1100,600,pet->getWidth(),pet->getHeight(),QPixmap(":/resource/petimage/sleeping_dog.png"));
    }

    QString strage=QString::number(pet->getAge(),10);
    ui->agelb->setText(strage);
    ui->namelb->setText(pet->getName());

}

void playroom::on_pushButton_3_clicked()
{
    int health=pet->getHealth();
    int hunger=pet->getHunger();
    int active=pet->getActive();
    int mood=pet->getMood();
    int age=pet->getAge();
    ofstream myout("D:/State.txt");
    myout << health <<endl;
    myout << hunger <<endl;
    myout << active <<endl;
    myout << mood <<endl;
    myout << age << endl;

    MainWindow *p=new MainWindow();
    p->show();
    hide();
    //这里需要储存狗子状态

}

//*******控制宠物移动********//
void playroom::keyPressEvent(QKeyEvent *e){
    if(!sleepMove){
          if(e->key()==Qt::Key_W){  //向上走
                upMove=true;
                if(pety>=650&&pety<=height()-pet->getHeight()){
                    pety-=MOVESPEED;
                    if(pety<650){
                        pety=650;
                    }
                }
          }else if(e->key()==Qt::Key_S){ //向下走
              downMove=true;
              if(pety>=650&&pety<=height()-100){
                  pety+=MOVESPEED;
                  if(pety>height()-pet->getHeight()){
                      pety=height()-pet->getHeight();
                  }
              }
//               qDebug()<<"Down";
          }else if(e->key()==Qt::Key_D){  //向右走
                   rightMove=true;
                   leftMove=false;
                  if(petx>=0&&petx<=width()-pet->getWidth()){
                      petx+=MOVESPEED;
                      if(petx>width()-pet->getWidth()){
                         petx=width()-pet->getWidth();
                      }
                   }
          }else if(e->key()==Qt::Key_A){  //向左走
              leftMove=true;
              rightMove=false;
              if(petx>=0&&petx<=width()-pet->getWidth()){
                  petx-=MOVESPEED;
                  if(petx<0){
                      petx=0;
                  }
              }
          }else{
              upMove=false;
              downMove=false;
              rightMove=false;
              leftMove=false;
          }
          //重绘
          update();//不要放在绘图事件中，不然会很卡
//          qDebug()<<petx<<" "<<pety<<endl;
    }
}

void playroom::keyReleaseEvent(QKeyEvent* e){
    if(!e->isAutoRepeat()){
        upMove=false;
        downMove=false;
    }
}

void playroom::aDaypassed(){//一天过去 重新计时 年龄长大一岁
    pet->setAge(pet->getAge()+1);//每隔十岁更新一下状态
    if (pet->getAge()%10==0){
        pet->setActive(pet->getActive()-1);
        pet->setHunger(pet->getHunger()-1);
        pet->setMood(pet->getAge()%3+1);
    }


    update();
    timer->start(1000);
}

void playroom::on_pushButton_4_clicked()
{
    pet->setMood(4);//玩游戏回复心情和活力
    pet->setActive(pet->getActive()+1);

    int health=pet->getHealth();
    int hunger=pet->getHunger();
    int active=pet->getActive();
    int mood=pet->getMood();
    int age=pet->getAge();
    ofstream myout("D:/State.txt");
    myout << health <<endl;
    myout << hunger <<endl;
    myout << active <<endl;
    myout << mood <<endl;
    myout << age << endl;//存储状态

    mazegenerator();
    petgame* p=new petgame();
    p->show();
    hide();
}
