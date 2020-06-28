#include "Tower.h"
#include<QPoint>
#include<QPixmap>
#include<QPainter>
#include <Windows.h>
Tower::Tower(QPoint pos,QString pixfilename):QObject(0),pixmap(pixfilename),pos(pos){};
void Tower::draw(QPainter *painter)
{
    pixmap=pixmap.scaled(70,70,Qt::KeepAspectRatio,Qt::SmoothTransformation);
    painter->drawPixmap(pos,pixmap);
    painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
    painter->drawEllipse(pos.x()-20,pos.y()-20,110,110);
}
void Tower::setHasTower(bool m)
{
    hastower=m;
}
bool Tower::hasTower() const
{
    return hastower;
}
const QSize Tower::ms_fixedSize(44,44);
QPoint Tower::getpos() const
{
    return pos;
}
void Tower::setlevel(int l)
{
    level=l;
}
int Tower::get_level() const
{
    return level;
}
