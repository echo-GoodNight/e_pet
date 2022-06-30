#ifndef CATCHDOG_H
#define CATCHDOG_H
#include<QPainter>
#include<QEvent>
#include<QKeyEvent>
#include<QString>
#include<QImage>
#include<QRect>
class catchdog{
public:
    catchdog();
    void initMap();
    void drawMap(QPainter* pDraw);
    void keyDown(QKeyEvent* event);
    int getRow();
    int getCols();
    void Break(int x, int y);
    bool gameOver();
    void Go(int ox, int oy, int x, int y);
    int map[17][25];
};




#endif // CATCHDOG_H
