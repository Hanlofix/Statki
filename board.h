#ifndef BOARD_H
#define BOARD_H
/*
TEN MODUL ODPOWIADA ZA:
-TWORZENIE PLANSZY
-DRUKOWANIE PLANSZY NA KONSOLI
*/
#include "ship.h"
class Board
{
    public:
        Board();
        virtual ~Board();
        void printBoard();//DRUKUJE PLANSZE
        void printOppositeBoard();
        void createBoard();//TWORZY PLANSZE
        char** getFieldArray();//ZWRACA WSKAZNIK NA PIERWSZE POLE PLASZY
        char getShipLook();//ZWRACA ZNAK STATKU
        char getHitLook();//ZWRACA ZNAK TRAFIENIA
        char getFieldLook();//ZWRACA ZNAK TLA PLANSZY
        int getBoardLength();
        bool checkField(Ship* ship);
        char getMissLook();

    protected:
    private:
        int board_length=12;
        char field_look='#';
        char ship_look='O';
        char hit_look='X';
        char miss_look='M';
        char **field_array;
};

#endif // BOARD_H
