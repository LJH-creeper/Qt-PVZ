#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addZombie();
    void zombieWin();
private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    QTimer* timer;
    QSound* sound;


};
#endif // MAINWINDOW_H
