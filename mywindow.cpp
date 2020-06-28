#include "mywindow.h"
#include <QMediaPlayer>
#include"Tower.h"
#include"enemy.h"
#include<QMouseEvent>
#include<QPixmap>
#include<QDebug>
#include<QObject>
#include<QTimer>
#include<cmath>
#include<QDebug>
#include<ctime>
#include <Windows.h>”
Mywindow::Mywindow(QWidget *parent) : QMainWindow(parent),timer1(nullptr),player1(nullptr),player2(nullptr),player3(nullptr)
{
    this->setFixedSize(800,600);
    addWayPoints();
    timer1 = new QTimer(this);  //
    set_enemy();
    startpoint=new QPoint(6,277);
    connect(timer1,SIGNAL(timeout()),this,SLOT(movenemy()));
    player1=new QSoundEffect(this);    //
    player1->setSource(QUrl("qrc:/coin.wav"));
    player1->setVolume(30);
    player1->setLoopCount(1);
    player2=new QSoundEffect(this);   //
    player2->setSource(QUrl("qrc:/death.wav"));
    player2->setVolume(10);
    player2->setLoopCount(1);
    player3=new QMediaPlayer(this);   //
    player3->setMedia(QUrl("qrc:/over.wav"));
    player3->setVolume(10);
}
void Mywindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pixmap(":/ground2.jpg");
    QPixmap pixmap2(":/gameover.jpg");
    painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
    foreach(Tower*tower,towerlist)
        tower->draw(&painter);
    foreach(enemy*enemy1,enemylist)
        enemy1->draw(&painter);
    QFont font("Arial",11,QFont::Bold,true);
    painter.setFont(font);
    painter.setPen(Qt::black);
    sprintf(s1,"%d",money);
    sprintf(s2,"%d",lifecount);
    painter.drawText(65,37,s1);
    painter.drawText(200,37,s2);
    if(lifecount<=0)
    {
        painter.drawPixmap(0,0,this->width(),this->height(),pixmap2);
        player3->play();

    }
}
bool Mywindow::has_tower(QPoint pos)
{
    pos.setX(pos.x()-20);
    pos.setY(pos.y()-20);
    for(int i=0;i<towerlist.size();i++)
    {
        if(fabs(pos.x()-towerlist[i]->getpos().x())<=30&&fabs(pos.y()-towerlist[i]->getpos().y())<=30)
        {
            tem=i;
            return true;
        }
    }
   return false;
}
void Mywindow::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        for(int i=0;i<towerlist.size();i++)
            {
                if((event->pos().x()-towerlist[i]->getpos().x())*(event->pos().x()-towerlist[i]->getpos().x())+(event->pos().y()-towerlist[i]->getpos().y())*(event->pos().y()-towerlist[i]->getpos().y())<=3000)
                    return;
            }
        pressPos1.setX(event->pos().x()-20);
        pressPos1.setY(event->pos().y()-20);
        set_tower1();
    }
    else if(event->button()==Qt::RightButton&&has_tower(event->pos())==true)
    {
            pressPos1.setX(event->pos().x()-20);
            pressPos1.setY(event->pos().y()-20);
            if(towerlist[tem]->get_level()==1)
            {
                towerlist.removeOne(towerlist[tem]);
                set_tower2();
            }
            else
            {
                towerlist.removeOne(towerlist[tem]);
                set_tower3();
            }

    }
    else if(event->button()==Qt::MidButton&&has_tower(event->pos())==true)
    {
        towerlist.removeOne(towerlist[tem]);
        money=money+50;
        player1->play();
    }
}
bool Mywindow::canBuyTower()
{
    if(money>=50)
        return true;
    else {
       return false;
    }
}
void Mywindow::set_tower1()
{
    money=money-100;
    Tower*a_new_tower=new Tower(pressPos1,":/tower11.png");
    if(canBuyTower()==true&&a_new_tower->hasTower()==false)
    {
        towerlist.push_back(a_new_tower);
        a_new_tower->setHasTower(true);
        a_new_tower->setlevel(1);
        update();
    }

}
void Mywindow::set_tower2()
{
    money=money-200;
    Tower*a_new_tower=new Tower(pressPos1,":/tower22.png");
    if(canBuyTower()==true&&a_new_tower->hasTower()==false)
    {
        towerlist.push_back(a_new_tower);
        a_new_tower->setHasTower(true);
        a_new_tower->setlevel(2);
        update();
    }
}
void Mywindow::set_tower3()
{
    money=money-300;
    Tower*a_new_tower=new Tower(pressPos1,":/tower33.png");
    if(canBuyTower()==true&&a_new_tower->hasTower()==false)
    {
        towerlist.push_back(a_new_tower);
        a_new_tower->setHasTower(true);
        a_new_tower->setlevel(3);
        update();
    }

}
void Mywindow::set_enemy()
{
    qsrand(time(NULL));
    int n=qrand()%5;
    if(n%2==0)
    {
        enemy*a_new_enemy=new enemy(*startpoint,":/monster2.png",80);
        enemylist.push_back(a_new_enemy);
    }
    else
    {
        enemy*a_new_enemy=new enemy(*startpoint,":/monster1.png",100);
        enemylist.push_back(a_new_enemy);
    }
    update();
}
void Mywindow::addWayPoints()
{

    QPoint*Waypoint1=new QPoint(6,277);
    waylist.push_back(Waypoint1);

    QPoint*Waypoint2=new QPoint(187,278);
    waylist.push_back(Waypoint2);

    QPoint*Waypoint3=new QPoint(187,379);
    waylist.push_back(Waypoint3);

    QPoint*Waypoint4=new QPoint(530,382);
    waylist.push_back(Waypoint4);

    QPoint*Waypoint5=new QPoint(530,277);
    waylist.push_back(Waypoint5);

    QPoint*Waypoint6=new QPoint(744,274);
    waylist.push_back(Waypoint6);
}
void Mywindow::movenemy()
{
    for(int i=0;i<enemylist.size();i++)
    {
        enemylist[i]->move();
        for(int j=0;j<towerlist.size();j++)
            {
                enemylist[i]->getfired(towerlist[j]);
                if(enemylist[i]->live()==false)
               {
                    money=money+30;
                    player1->play();
                    enemylist.removeOne(enemylist[i]);
                }
            }
        if(enemylist[i]->getpos().x()>=744&&enemylist[i]->live()==true&&lifecount>=0)
        {
            lifecount=lifecount-1;
            player2->play();
            enemylist.removeOne(enemylist[i]);

        }
    }
    update();
    count++;
    if(count%100==0)
        set_enemy();
    qDebug()<<"movenemy";
}
void Mywindow::start_timer()
{
    timer1->start(30);
}


