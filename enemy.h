#ifndef ENEMY_H
#define ENEMY_H
#include<QPixmap>
#include <QObject>
#include"tower.h"
class enemy
{
public:
    enemy(QPoint m_pos,QString pixfilename,double HP);
    void draw(QPainter*painter);
    void move();
    QPoint getpos() const;
    void getfired(Tower*tower);
    bool live();
private:
    double m_walkingspeed;
    double m_active;
    double m_currentHP=100.00;
    double m_maxHP;
    bool life;
    QPoint m_pos;
    QPixmap m_sprite;
    double radius=50;
    Tower*tower;
};
#endif // ENEMY_H
