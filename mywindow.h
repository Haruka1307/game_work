#ifndef MYWINDOW_H
#define MYWINDOW_H
#include"Tower.h"
#include <QMainWindow>
#include<QList>
#include <QMediaPlayer>
#include<QPainter>
#include<QPixmap>
#include <QTextEdit>
#include<QPoint>
#include<QDebug>
#include<QTimer>
#include<QSoundEffect>
#include"enemy.h"
class Mywindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit Mywindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void playmusic();
    void mousePressEvent(QMouseEvent*event);
    bool canBuyTower();
    void set_tower1();
    void set_tower2();
    void set_tower3();
    bool has_tower(QPoint pos);
    void set_enemy();
    void addWayPoints();
    void start_timer();
    int tem=0;
public slots:
    void movenemy();
private:
    QList<Tower*>towerlist;
    QList<enemy*>enemylist;
    QList<QPoint*>waylist;
    QPoint pressPos1;
    QPoint*startpoint;
    QPoint pressPos2;
    QTimer* timer1;
    int count=0;
    int lifecount=10;
    int money=1000;
    char s1[100]={0};
    char s2[100]={0};
   QSoundEffect*player1;
   QSoundEffect*player2;
   QMediaPlayer*player3;

};

#endif // MYWINDOW_H
