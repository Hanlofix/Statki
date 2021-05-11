#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
using namespace std;
#include "board.h"
#include "ship.h"

Board::Board()
{

    field_array=new char *[board_length];
    for(int i=0; i<board_length; i++)
    field_array[i]=new char[board_length];
    createBoard();
}

Board::~Board()
{
    for(int i=0; i<board_length; i++)
        delete [] field_array[i];
    delete [] field_array;
}
void Board::printBoard()
{
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<endl;
    int n=2;
    for(int x=0; x<board_length-1; x++)
    {
        if(x==0)cout<<"x\\y ";
        else (x!=10)?(cout<<setw(n)<<x):(cout<<setw(n+1)<<x);//ZEBY SIE 10 NIE SKLEILO Z POPRZEDNIA LICZBA
    }
    cout<<endl;
    for(int i=0; i<board_length; i++)
    {    if(i==0 || i==board_length-1)cout<<' ';
         else(i!=10)?(cout<<setw(n)<<i):(cout<<setw(n-1)<<i);//ZEBY SIE 10 NIE SKLEILO Z PLANSZA
        for(int j=0; j<board_length; j++)
        {
            if(field_array[i][j]==field_look)
            {SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_INTENSITY);}//JEEEEJJJ KOLORKI JUHUUUUU :)
            else if(field_array[i][j]==hit_look)
            {SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);}
            else if(field_array[i][j]==ship_look)
            {SetConsoleTextAttribute(hOut,FOREGROUND_GREEN | FOREGROUND_INTENSITY);}
            else if(field_array[i][j]==miss_look)
            {SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED );}
           cout<<setw(n)<<field_array[i][j];
           SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        }
        cout<<endl;
    }
}
void Board::printOppositeBoard()
{
     HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<endl;
    int n=2;

    for(int i=0; i<board_length; i++)
    {    if(i==0 || i==board_length-1)cout<<' ';
         else(i!=10)?(cout<<setw(n)<<i):(cout<<setw(n-1)<<i);
        for(int j=0; j<board_length; j++)
        {
           if(field_array[i][j]==field_look)
            {SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_INTENSITY);}
            else if(field_array[i][j]==hit_look)
            {SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);}
            else if(field_array[i][j]==ship_look)
            {SetConsoleTextAttribute(hOut,FOREGROUND_GREEN | FOREGROUND_INTENSITY);}
            else if(field_array[i][j]==miss_look)
            {SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED );}
           cout<<setw(n)<<field_array[i][j];
           SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
        }
        cout<<endl;
    }
    for(int x=0; x<board_length-1; x++)
    {
        if(x==0)cout<<"x/y ";
        else (x!=10)?(cout<<setw(n)<<x):(cout<<setw(n+1)<<x);
    }
    cout<<endl;
}
void Board::createBoard()
{
    for(int i=0; i<board_length; i++)
    {
        for(int j=0; j<board_length; j++)
        {
            if(i==0 || j==0 || i==board_length-1 || j==board_length-1)
                field_array[i][j]=' ';
            else
                field_array[i][j]=field_look;
        }
    }
}
bool Board::checkField(Ship* ship)
{
    int x=ship->getX();
    int y=ship->getY();
    int length=ship->getLength();
    bool plane=ship->getPlane();
    bool is_field_clear=false;

if(length>1)//JAK DOCHODZI DO JEDNOMASZTOWCA W LISCIE TO SIE ZACZYNA CIAC PONIEWAZ WGL SIE PETLA FOR NIE WYKONA
{
  if(plane==false)//DLA PIONOWYCH STATKOW
  {
        for(int i=length; i>1; i--)
    {
        if(field_array[x+i][y-1]==ship_look || field_array[x+i][y]==ship_look || field_array[x+i][y+1]==ship_look )
       {
            is_field_clear=true;
            break;//OPTYMALIZACJA
       }
    }
  }
  else//DLA POZIOMYCH STATKOW
  {
    for(int i=length; i>1; i--)
    {
        if(field_array[x-1][y+i]==ship_look || field_array[x][y+i]==ship_look || field_array[x+1][y+i]==ship_look )
       {
            is_field_clear=true;
            break;//OPTYMALIZACJA
       }
    }
  }
}

    if(field_array[x-1][y-1]==ship_look || field_array[x-1][y]==ship_look || field_array[x-1][y+1]==ship_look ||
       field_array[x][y]==ship_look || field_array[x][y-1]==ship_look || field_array[x][y+1]==ship_look ||
       field_array[x+1][y]==ship_look || field_array[x+1][y+1]==ship_look || field_array[x+1][y-1]==ship_look)//SPRAWDZAMY OBSZAR WOKOL PIERWOTNEJ WSPOLRZEDNEJ
       {
           is_field_clear=true;
       }

    return is_field_clear;
}

char** Board:: getFieldArray()
{
    return field_array;
}
char Board::getShipLook()
{
    return ship_look;
}
char Board::getHitLook()
{
    return hit_look;
}
char Board::getFieldLook()
{
    return field_look;
}
int Board::getBoardLength()
{
    return board_length;
}
char Board::getMissLook()
{
    return miss_look;
}
