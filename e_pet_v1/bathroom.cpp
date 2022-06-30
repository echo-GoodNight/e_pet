#include "bathroom.h"
#include "ui_bathroom.h"
#include <fstream>
using namespace std;

bathroom::bathroom(Pet* ssspet,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::bathroom)
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

    if (ssspet)
    {
    pet=ssspet;
    }
    else
    {
    pet=new Pet;
    }


    //宠物的属性值
    moodLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(128,20,238);font-weight:bold");
    healthLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(128,20,238);font-weight:bold");
    hungerLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(128,20,238);font-weight:bold");
    activeLabel->setStyleSheet("font: 25px/1.5 '华文彩云',Helvetica,Arial,sans-serif;color:rgb(128,20,238);font-weight:bold");
    moodLabel->setFixedSize(225,40);
    healthLabel->setFixedSize(225,40);
    hungerLabel->setFixedSize(225,40);
    activeLabel->setFixedSize(225,40);
    moodLabel->move(48,10);
    healthLabel->move(48+240,10);
    hungerLabel->move(48+240*2,10);
    activeLabel->move(48+240*3,10);

    ui->pushButton_2->setIcon(QIcon(":/resource/bathroom/brush.png"));
    ui->pushButton_2->setIconSize(QSize(150,150));
    ui->pushButton_2->setFlat(true);
    ui->pushButton_3->setIcon(QIcon(":/resource/bathroom/shower_head.png"));
    ui->pushButton_3->setIconSize(QSize(150,214));
    ui->pushButton_3->setFlat(true);
    ui->pushButton_4->setFlat(true);
}

void bathroom::paintEvent(QPaintEvent *){
    QPainter p(this);
    QFont font;
    font.setPointSize(10);
    p.setFont(font);
    p.setPen(QColor(25,202,173));
    //背景
    p.drawPixmap(rect(),QPixmap("://resource/bathroom/bathroom.jpg"));//设置背景 按照窗口大小

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

    //显示宠物
    if(is_dirty){
        if(is_brushed){
            p.drawPixmap(petx-50,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/bathroom/bubble.png"));
            p.drawPixmap(petx+50,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/bathroom/bubble.png"));
        }
        p.drawPixmap(petx,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/petimage/dirty_dog.png"));
    }
    else{
        p.drawPixmap(petx+60,pety+10,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/petimage/cleaned_dog.png"));
    }
}

void bathroom::on_pushButton_2_clicked(){
    if(is_using_what==1){
        is_using_what=0;
        this->setCursor(QCursor(QPixmap(":/resource/basic/mouse.png"),0,0));
        update();
    }
    else{
        is_using_what=1;
        this->setCursor(QCursor(QPixmap(":/resource/bathroom/brush.png").scaled(200,200),-1,-1));
        update();
    }
}

void bathroom::on_pushButton_3_clicked(){
    if(is_using_what==2){
        is_using_what=0;
        this->setCursor(QCursor(QPixmap(":/resource/basic/mouse.png"),0,0));
        update();
    }
    else{
        is_using_what=2;
        this->setCursor(QCursor(QPixmap(":/resource/bathroom/shower_head.png").scaled(200,200),-1,-1));
        update();
    }
}

void bathroom::on_pushButton_4_clicked(){
    if(is_using_what==2){
        if(is_brushed){
            is_brushed=false;// 去除泡沫
            is_dirty=false;// 狗已经干净了
            pet->setMood(4);
            pet->setActive(3);
        }
        update();
    }
}

void bathroom::mousePressEvent(QMouseEvent *event){
    rlcnt=0;
    in_right=0;
}

void bathroom::mouseMoveEvent(QMouseEvent *event){
    this->setMouseTracking(true);      //设置为不按下鼠标键触发moveEvent
    QPoint mousepos = event->pos();
    if(is_using_what==1){
        if(is_brushed){ rlcnt=7;}
        else if(rlcnt>6)
        {
            is_brushed=true;
            update();
        }
        else
        {
            if(in_right && mousepos.x() > 0 && mousepos.x() < 800){
                in_right=0;
                rlcnt+=1;
            }
            else if(!in_right && mousepos.x() > 1000 && mousepos.x() < 1600){
                in_right=1;
                rlcnt+=1;
            }
        }
    }

}

void bathroom::mouseReleaseEvent(QMouseEvent *event){
    rlcnt=0;
    in_right=0;
}
bathroom::~bathroom()
{
    delete ui;
}

void bathroom::on_pushButton_clicked()
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

    playroom* p=new playroom(this,true);
    p->show();
    hide();
}
