#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <define.h>
#include <pet.h>
#include <QPushButton>
#include <QPixmap>
#include <kitchen.h>
#include <playroom.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
bool getFetch();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H


