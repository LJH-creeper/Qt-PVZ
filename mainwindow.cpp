#include "mainwindow.h"
#include "shop.h"
#include "shovel.h"
#include "mower.h"
#include "button.h"
#include "map.h"
#include "zombie.h"
#include "basiczombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "screenzombie.h"
#include "footballzombie.h"
#include <QPixmap>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //场景
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150,0,900,600); //场景原点和大小
    scene->setItemIndexMethod(QGraphicsScene::NoIndex); //降低查询性能，减少内存

    //背景音乐
    sound = new QSound(":/sound/Grazy Dave.wav");
    //循环播放
    sound->setLoops(QSound::Infinite);
    sound->play();

    //商店
    Shop* shop = new Shop;
    shop->setPos(520,45);
    scene->addItem(shop);

    //铲子
    Shovel* shovel = new Shovel;
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    //小推车
    for(int i=0;i<5;i++){
        Mower* mower = new Mower;
        mower->setPos(210, 130 + 98 * i);
        scene->addItem(mower);
    }

    //timer
    timer = new QTimer;
    connect(timer,&QTimer::timeout,scene,&QGraphicsScene::advance);
    timer->start(33);

    //暂停按钮
    Button* button = new Button(sound,timer);
    button->setPos(970,20);
    scene->addItem(button);

    //map
    Map* map = new Map;
    map->setPos(618,326);
    scene->addItem(map);

    //zombie
    connect(timer, &QTimer::timeout, this, &MainWindow::addZombie);

    //失败弹窗
    connect(timer, &QTimer::timeout, this, &MainWindow::zombieWin);

    //视图
    view = new QGraphicsView(scene,this);
    view->setFixedSize(902,602);
    //开启反锯齿
    view->setRenderHint(QPainter::Antialiasing, true);
    view->setBackgroundBrush(QPixmap(":/img/Background.jpg"));
    //视图会缓存背景,提高渲染性能
    view->setCacheMode(QGraphicsView::CacheBackground);
    //只重绘那些实际发生变化的区域,提高渲染性能
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->show();

}

MainWindow::~MainWindow() {}

void MainWindow::addZombie()
{
    static int count = 0;
    static int maxtime = 20 * 1000 / 33;
    static int time = maxtime / 2;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        count++;
        //随机僵尸
        int type = QRandomGenerator::global()->bounded(100);
        //随机路
        int i = QRandomGenerator::global()->bounded(5);
        //创建僵尸
        // Zombie* zombie = new BasicZombie;
        Zombie* zombie = nullptr;
        if (type < 40)
            zombie = new BasicZombie;
        else if (type < 70)
            zombie = new ConeZombie;
        else if (type < 80)
            zombie = new BucketZombie;
        else if (type < 90)
            zombie = new ScreenZombie;
        else
            zombie = new FootballZombie;
        zombie->setPos(1028, 130 + 98 * i);
        scene->addItem(zombie);
        qDebug()<<time;
    }
    //随时间增加出怪速度
    if(time > 10){
        if(count / 5 > 0){
            count = 0;
            time /= 2;
            qDebug()<<time;
        }
    }
}
//僵尸胜利
void MainWindow::zombieWin()
{
    static int time = 1 * 1000 / 33;
    static int counter = 0;
    if (++counter >= time)
    {
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        for (QGraphicsItem *item : items)
            if (item->type() == Zombie::Type && item->x() < 200)
            {
                scene->addPixmap(QPixmap(":/img/ZombiesWon.png"))->setPos(336, 92);
                scene->advance();
                timer->stop();
                sound->stop();
                return;
            }
    }
}


