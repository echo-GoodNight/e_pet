#ifndef PETGAME_H
#define PETGAME_H

#include <QWidget>
#include <catchdog.h>
#include <QPainter>
#include <playroom.h>
QT_BEGIN_NAMESPACE
namespace Ui { class petgame; }
QT_END_NAMESPACE

class petgame : public QWidget
{
    Q_OBJECT

public:
    petgame(QWidget *parent = nullptr);
    ~petgame();
    void keyPressEvent(QKeyEvent* event);
    void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_3_clicked();

private:
    Ui::petgame *ui;
    QPainter* pMap;
    catchdog* pCatch;
};
void GameOverdo();

#endif // PETGAME_H
