#include "waypoint.h"
Waypoint::Waypoint(){};
Waypoint::Waypoint(QPoint pos):m_pos(pos),m_nextWayPoint(NULL)
{

}
void Waypoint::setNextWayPoint(Waypoint *nextPoint)
{
    m_nextWayPoint=nextPoint;
}
Waypoint*Waypoint::nextWayPoint() const
{
    return m_nextWayPoint;
}
const QPoint Waypoint::pos() const
{
    return m_pos;
}
