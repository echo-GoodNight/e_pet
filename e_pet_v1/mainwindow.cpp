#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bg("://resource/mainwindow/08922f55a496de1e173c235f3170b17.jpg");//设置背景 按照窗口大小
    ui->background->setPixmap(bg.scaled(1600,1024));
    setWindowTitle("PetMachine");


    QPixmap lb1(":/resource/petimage/happy_dog.png");
    QPixmap lb2(":/resource/petimage/hungry_dog.png");
    QPixmap lb3(":/resource/petimage/normal_dog.png");
    QPixmap lb4(":/resource/petimage/unhappy_dog.png");
    ui->label  ->setPixmap(lb1.scaled(400,400,Qt::KeepAspectRatio));
    ui->label_2->setPixmap(lb2.scaled(400,400,Qt::KeepAspectRatio));
    ui->label_3->setPixmap(lb3.scaled(400,400,Qt::KeepAspectRatio));
    ui->label_4->setPixmap(lb4.scaled(400,400,Qt::KeepAspectRatio));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    playroom* p=new playroom(new QWidget(),false);
    p->show();
    hide();
}
void MainWindow::on_pushButton_2_clicked()
{
    playroom* p=new playroom(new QWidget(),true);
    p->show();
    hide();
}
void MainWindow::on_pushButton_3_clicked()
{
    hide();
}
