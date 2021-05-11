#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "menu.h"
#include "game.h"
Menu::Menu()
{
    printMenu();
}
Menu::~Menu()
{

}
void Menu:: printMenu()
{
    srand(time(0));
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    int choice;
    do
    {
        system("cls");
    cout<<"GRA W STATKI"<<endl;
    cout<<"----------"<<endl;
    cout<<"MENU GLOWNE:"<<endl;
    cout<<"1.ZAGRAJ"<<endl;
    cout<<"2.O GRZE"<<endl;
    cout<<"3.ZAKONCZ"<<endl;
    cout<<"WYBIERZ OPCJE: ";
        cin>>choice;
        switch(choice)
        {
          case 1:
              {
                SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
                Game game;
                printMenu();
              }
              break;
          case 2:
              {
              SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
              about();
              SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
              }
              break;
          case 3:
              {

              }
              break;
        }

    }while(choice<1 || choice >3);
}
void Menu::about()
{
    system("cls");

    cout<<"TWORCA TEJ GRY JEST MACIEJ STAWOWCZYK"<<endl;
    cout<<"MILEJ GRY!"<<endl<<endl;
    cout<<"WCISNIJ DOWOLNY PRZYCISK, ABY POWROCIC DO MENU"<<endl;
    getch();

    printMenu();
}

