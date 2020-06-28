#ifndef WAYPOINT_H
#define WAYPOINT_H
#include<QPoint>
#include<QPainter>
class Waypoint
{
public:
    Waypoint(QPoint pos);
    Waypoint();
    Waypoint*nextWayPoint() const;
    const QPoint pos() const;
    void draw(QPainter*painter) const;
    void setNextWayPoint(Waypoint*nextPoint);
    QPoint m_pos;
    Waypoint*m_nextWayPoint;
};

#endif // WAYPOINT_H
