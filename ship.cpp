#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
using namespace std;
#include "ship.h"

Ship::Ship()
{
    setParameters(0,0,0,0,0);
}

Ship::~Ship()
{

}
void Ship::setParameters(int x, int y, int length, bool plane, int damage)
{
    setX(x);
    setY(y);
    setLength(length);
    setPlane(plane);
    setDamage(damage);
}
void Ship::setLength(int length)
{
    this->length=length;
}
void Ship::setPlane(bool plane)
{
    this->plane=plane;
}
void Ship::setDamage(int damage)
{
    this->damage=damage;
}
void Ship::setX(int x)
{
    this->x=x;
}
void Ship::setY(int y)
{
    this->y=y;
}
int Ship::getDamage()
{
    return this->damage;
}
bool Ship::getPlane()
{
    return this->plane;
}
int Ship::getX()
{
    return this->x;
}
int Ship::getY()
{
    return this->y;
}
int Ship::getLength()
{
    return this->length;
}
void Ship::increaseDamage()
{
    this->damage++;
}

