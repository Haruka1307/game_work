#include "enemy.h"
#include<QObject>
#include<QTime>
#include<QPainter>
#include<math.h>
#include<QDebug>
enemy::enemy(QPoint m_pos,QString pixfilename,double HP):m_pos(m_pos),m_sprite(pixfilename),m_maxHP(HP),tower(nullptr)
{

}
void enemy::move()
{
    int n=1;
    if(m_maxHP==100)
        n=2;
    if(m_pos.x()<187)
        m_pos.setX(m_pos.x()+n);
    else if((m_pos.x()==187||m_pos.x()==188)&&m_pos.y()>=277&&m_pos.y()<379)
        m_pos.setY(m_pos.y()+n);
    else if(m_pos.y()>=379&&m_pos.x()>=187&&m_pos.x()<530)
        m_pos.setX(m_pos.x()+n);
    else if(m_pos.x()==530&&m_pos.y()<=379&&m_pos.y()>=277)
        m_pos.setY(m_pos.y()-n);
    else
        m_pos.setX(m_pos.x()+n);

}
void enemy::draw(QPainter *painter)
{
    m_sprite=m_sprite.scaled(70,70,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    painter->drawPixmap(m_pos,m_sprite);
    painter->setPen(QPen(Qt::white,2));
    painter->drawRect(m_pos.x()+8,m_pos.y()-10,50,5);
    painter->fillRect(m_pos.x()+8,m_pos.y()-10,m_currentHP/2,5,Qt::red);
}
QPoint enemy::getpos() const
{
    return m_pos;

}
void enemy::getfired(Tower*tower)
{
    double deltx=tower->getpos().x()+20-m_pos.x();
    double delty=tower->getpos().y()+20-m_pos.y();
    double dis=sqrt(deltx*deltx+delty*delty);
    if(dis<=radius)
    {
        if(tower->get_level()==1)
        {
            m_currentHP=m_currentHP-5;
        }
        else if(tower->get_level()==2)
        {
             m_currentHP=m_currentHP-10;
        }
        else
        {
            m_currentHP=m_currentHP-20;
        }
    }
}
bool enemy::live()
{
    if(m_currentHP==0)
    {
        life=false;
        return false;
    }
}


