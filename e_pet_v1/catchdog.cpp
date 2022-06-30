#include<catchdog.h>
#include<fstream>
#include<iostream>
#include<petgame.h>
#include<QDebug>
using namespace std;

catchdog::catchdog()
{
    initMap();
}
void catchdog::initMap()
{
    //10 is for the dog
    // 0 is for the empty
    // 1 is for the wall
    // 3 is for the food
    // 4 is for the washing tool
    // 5 is for the medicine
    ifstream myin;
    myin.open("D:/map.txt");
    for (int i=1 ;i<=16;i++)
    for (int j=1 ;j<=25;j++)
    {

         myin >> map[i][j];
    }
    myin.close();




}
void catchdog::drawMap(QPainter* pDraw)
{
    QString imgURL;
    for (int i=1 ; i<=16 ; i++)
    {
        for (int j=1; j<=25; j++)
        {
            switch (map[i][j])
            {
            case 0:
                imgURL=":/resource/gameimg/0.bmp";
                break;
            case 10:
                imgURL=":/resource/gameimg/10.bmp";

                break;
            case 1:
                imgURL=":/resource/gameimg/1.bmp";
                break;
            case 3:
                imgURL=":/resource/gameimg/3.bmp";
                break;
            case 4:
                imgURL=":/resource/gameimg/4.bmp";
                break;
            case 5:
                imgURL=":/resource/gameimg/5.bmp";
                break;

            }
            QImage img(imgURL);
            pDraw->drawImage(QRect(((j-1)*img.width()),((i-1)*img.height()),img.width(),img.height()),img);
        }

    }
}
void catchdog::Go(int ox,int oy, int x , int y)
{
    if (x < 1 || x>16 || y<1 || y > 25)return;
    switch (map[x][y])
    {
        case 0://empty
            map[x][y]=10;
            map[ox][oy]=0;
        break;

        case 1://wall

        break;

        case 3://food
            map[x][y]=10;
            map[ox][oy]=0;

        break;

        case 4://washing tool
            map[x][y]=10;
            map[ox][oy]=0;

        break;

        case 5://medicine
            map[x][y]=10;
            map[ox][oy]=0;

        break;
    }


}
void catchdog::Break(int x,int y)
{

    if (x < 1 || x>16 || y<1 || y > 25 || map[x][y]!=1)return;
    map[x][y]=0;
}

void catchdog::keyDown(QKeyEvent* event)
{
    int i = getRow();
    int j = getCols();

    switch (event->key()) {
        case Qt::Key_W:
        case Qt::Key_Up:
            Go(i,j,i-1,j);
        break;

        case Qt::Key_S:
        case Qt::Key_Down:
            Go(i,j,i+1,j);
        break;

        case Qt::Key_D:
        case Qt::Key_Right:
            Go(i,j,i,j+1);
        break;

        case Qt::Key_A:
        case Qt::Key_Left:
            Go(i,j,i,j-1);
        break;
        case Qt::Key_Space:
            Break(i-1,j);
            Break(i+1,j);
            Break(i,j+1);
            Break(i,j-1);
        break;
        case Qt::Key_Escape :
            GameOverdo();

        break;

    }
}
int catchdog::getRow()
{
    for (int i=1 ; i<=16; i++)
    {
        for (int j=1; j<=25 ; j++)
        {
            if (map[i][j]==10)
            {
                return i;
            }
        }
    }
    return -1;
}
int catchdog::getCols()
{
    for (int i=1 ; i<=16; i++)
    {
        for (int j=1; j<=25 ; j++)
        {
            if (map[i][j]==10)
            {
                return j;
            }
        }
    }
    return -1;
}
bool catchdog::gameOver()
{
    return false;
}
