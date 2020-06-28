#ifndef TOWER_H
#define TOWER_H
#include <QObject>
#include<QPoint>
#include<QPixmap>
class Tower : public QObject
{
    Q_OBJECT
public:
    Tower(QPoint pos,QString pixfilename);
    void draw(QPainter*painter);
    void setHasTower(bool truth);
    QPoint getpos() const;
    bool hasTower() const;
    void setlevel(int l);
    int get_level() const;
private:
    QPoint pos;
    QPixmap pixmap;
    bool hastower=false;
    QPoint firepos;
    int level=0;
    static const QSize ms_fixedSize;
};

#endif // TOWER_H

