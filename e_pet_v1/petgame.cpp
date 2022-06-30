#include "petgame.h"
#include "ui_petgame.h"

petgame::petgame(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::petgame)
{
    ui->setupUi(this);
    setFixedSize(1600,1024);
    pCatch = new catchdog;
    pMap = new QPainter(this);
    setWindowTitle("petgame");
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);

}
bool GameOver =false;

petgame::~petgame()
{
    delete ui;
}

void petgame::keyPressEvent(QKeyEvent *event)
{
    pCatch->keyDown(event);
    if (GameOver) this->close();
}

void petgame::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    pMap->begin(this);
    pCatch->drawMap(pMap);
    pMap->end();
    update();
}
void GameOverdo()
{
    GameOver=true;
};

void petgame::on_pushButton_3_clicked()
{
    playroom* p=new playroom(this,true);
    p->show();
    hide();
}
