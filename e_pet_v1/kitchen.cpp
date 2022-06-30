#include "kitchen.h"
#include "ui_kitchen.h"
using namespace std;

kitchen::kitchen(Pet* ssspet,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::kitchen)
{
    ui->setupUi(this);
    setAcceptDrops(true); //默认控件不支持拖拽，需在构造函数中设置接受拖拽事件
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

    //随机出现食物 拖动喂食
    no_chicken_leg=rand()%2;
    no_sausage=rand()%2;//rand()%2
    no_vegetable=rand()%2;

    //初始化事物
    if(!no_chicken_leg){
        QLabel *chik =new QLabel(this);
        QPixmap pix1(":/resource/kitchen/chicken_leg.png");
        chik->setPixmap(pix1.scaled(150,150));
        chik->move(200,400);
        chik->resize(pix1.size());
        chik->setAttribute(Qt::WA_DeleteOnClose);
    }
    if(!no_sausage){
        QLabel *saus =new QLabel(this);
        QPixmap pix2(":/resource/kitchen/sausage.png");
        saus->setPixmap(pix2.scaled(150,150));
        saus->move(500,400);
        saus->resize(pix2.size());
        saus->setAttribute(Qt::WA_DeleteOnClose);
    }
    if(!no_vegetable){
        QLabel *vege =new QLabel(this);
        QPixmap pix3(":/resource/kitchen/vegetable.png");
        vege->setPixmap(pix3.scaled(150,150));
        vege->move(800,400);
        vege->resize(pix3.size());
        vege->setAttribute(Qt::WA_DeleteOnClose);
    }
}

void kitchen::paintEvent(QPaintEvent *){
    QPainter p(this);
    QFont font;
    font.setPointSize(10);
    p.setFont(font);
    p.setPen(QColor(25,202,173));
    //背景
    p.drawPixmap(rect(),QPixmap("://resource/kitchen/background1.webp"));//设置背景 按照窗口大小

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
    if(!greedy_action){
        if(has_eaten){
            p.drawPixmap(petx,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/petimage/normal_dog.png"));
        }
        else if(pet->getHealth()>2&&pet->getHunger()>2){
            p.drawPixmap(petx,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/petimage/happy_dog.png"));
        }else{
            p.drawPixmap(petx,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/petimage/hungry_dog.png"));
        }
    }
    else{
        p.drawPixmap(petx,pety,pet->getWidth()+200,pet->getHeight()+200,QPixmap(":/resource/petimage/greedy_dog.png"));
    }
}

void kitchen::mousePressEvent(QMouseEvent *event)//按下事件实现
{
    //1 获取当前鼠标指针所在处的部件的指针，强制转换为QLabel类型的指针
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if(!child->inherits("QLabel"))
    {
        return;
    }
    QPixmap pixmap = *child->pixmap();

    //狗开始流口水
    greedy_action=true;
    update();
    //2 自定义Mime类型数据，存储图片数据和位置信息
    QByteArray itemData;
    QDataStream dataStream(&itemData,QIODevice::WriteOnly);
    dataStream<<pixmap<<QPoint(event->pos()-child->pos());

    //3 将数据字节数组存入MimeData中，这里相当于setData作用类似<key,value>
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("myimage/png",itemData);

    //4 为了移动数据必须创建Drag类对象，然后为其添加QMimeData数据
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos()-child->pos());

    //5 在移动图片过程中为原来图片添加了一层阴影
//    child->setAttribute(Qt::WA_TranslucentBackground);
//    child->setStyleSheet("background:transparent");
//    QPixmap tempPixmap = pixmap;
//    QPainter painter;
//    painter.begin(&tempPixmap);
//    painter.fillRect(pixmap.rect(),QColor(127,127,127,127));
//    painter.end();
//    child->setPixmap(tempPixmap);

    //6 执行拖动操作，默认设置支持复制操作
    if(drag->exec(Qt::CopyAction|Qt::MoveAction,Qt::CopyAction) == Qt::MoveAction)
    {
        child->close();
    }
    else
    {
        child->show();
        child->setPixmap(pixmap);
    }

}

void kitchen::dragEnterEvent(QDragEnterEvent *event)  //进入拖拽
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction); //a.移动操作
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void kitchen::dragMoveEvent(QDragMoveEvent *event)  //移动事件
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        event->setDropAction(Qt::MoveAction); //b.移动操作
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void kitchen::dropEvent(QDropEvent *event)     //放下事件
{
    if(event->mimeData()->hasFormat("myimage/png"))
    {
        QByteArray itemData = event->mimeData()->data("myimage/png");
        QDataStream dataStream(&itemData,QIODevice::ReadOnly);
        QPixmap pixmap;
        QPoint offset;
        dataStream>>pixmap>>offset;

        QLabel *newLabel = new QLabel(this);
        newLabel->setPixmap(pixmap);
        newLabel->resize(pixmap.size());
        newLabel->move(event->pos()-offset);
        newLabel->show();
        if(event->pos().x()<=1250 && event->pos().x()>=1100 && event->pos().y()<=750 && event->pos().y()>=600){
            has_eaten=true;
            newLabel->hide();
            pet->setHunger(4);
        }
        newLabel->setAttribute(Qt::WA_DeleteOnClose);
        event->setDropAction(Qt::MoveAction); //c.移动操作
        event->accept();

    }
    else
    {
        event->ignore();
    }
    greedy_action=false;
    update();
}


kitchen::~kitchen()
{
    delete ui;
}

void kitchen::on_pushButton_clicked()
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
