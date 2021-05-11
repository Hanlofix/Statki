#ifndef SHIP_H
#define SHIP_H
/*
TEN MODUL JEST ODPOWIEDZIALNY ZA:
-TWORZENIE STATKÓW
*/
class Ship
{
    public:
        Ship();
        virtual ~Ship();
        void setParameters(int x, int y, int length, bool plane, int damage);
        void setLength(int length);
        void setPlane(bool plane);
        void setDamage(int damage);
        void setX(int x);
        void setY(int y);
        int getDamage();
        bool getPlane();
        int getX();
        int getY();
        int getLength();
        void increaseDamage();
        Ship* next;
    protected:
    private:
        int x;
        int y;
        int length;//FROM 1 TO 4
        bool plane;// 0 FOR VERTICAL(PIONOWY) OR 1 FOR HORIZONTAL(POZIOMY)
        int damage;


};


#endif // SHIP_H
