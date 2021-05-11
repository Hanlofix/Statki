#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <conio.h>
using namespace std;
#include "game.h"
#include "board.h"
#include "ship.h"
#include "menu.h"
Game::Game()
{
    system("cls");//ODSWIEZAMY EKRAN
    ships_player=newSetOfShips();//WSKAZNIK DO LISTY STATKOW GRACZA
    ships_computer=newSetOfShips();//WSKAZNIK DO LISTY STATKOW KOMPUTERA
    board_player=new Board;//WSKAZNIK DO PLANSZY GRACZA
    board_computer=new Board;//WSKAZNIK DO PLANSZY KOMPUTERA
    hit_board=new Board;//WSKAZNIK DO PLANSZY DO STRZELANIA
    setShipsComputer(board_computer,ships_computer);//KOMPUTER USTAWIA STATKI
    setShipsPlayer(board_player,ships_player);//GRACZ USTAWIA STATKI
    gameLoop(board_computer,board_player,ships_computer,ships_player);//GRAMY!!
}
//---------------------------------------------------------------------------------
Game::~Game()
{
    deleteSetOfShips(ships_player);
    deleteSetOfShips(ships_computer);
    delete board_player;
    delete board_computer;
    delete hit_board;
}
//---------------------------------------------------------------------------------
Ship* Game::newSetOfShips()//FUNKCJA TWORZ¥CA LISTE JEDNOKIERUNKOW¥ STATKÓW DLA POJEDYNCZEGO GRACZA
{
    Ship *head=NULL,*tail=NULL;
    int k=0;//<-ILOSC STATKÓW
    while(k<10)
    {
        Ship* ship = new Ship;//NOWY STATEK
        ship->next=NULL;//KONCOWY ELEMENT LISTY
        if(k==0)
            ship->setLength(4);//CZTEROMASZTOWCE
        else if(k>0 && k<3)
            ship->setLength(3);//TRZYMASZTOWCE
        else if(k>=3 && k<6)
            ship->setLength(2);//DWUMASZTOWCE
        else
            ship->setLength(1);//JEDNOMASZTOWCE

        if(head==NULL)
        {
            head=ship;
            tail=head;
        }
        else
        {

            tail->next=ship;
            tail=tail->next;
        }
        k++;
    }
    return head;
}
//----------------------------------------------------------------------------------
void Game::deleteSetOfShips(Ship*& head)//USUWA LISTE JEDNOKIERUNKOWA STATKOW DLA POJEDYNCZEGO GRACZA
{
    if(head==NULL)
        return;
    while(head!=NULL)
    {
        Ship* help=head;
        head=head->next;
        delete help;
    }
}
//------------------------------------------------------------------------------------
void Game::setShipsPlayer(Board *board_player,Ship *ships_player)
{
    char** field=board_player->getFieldArray();//WSKAZNIK DO PLANSZY
    Ship* help=ships_player;// WSKAZNIK NA PIERWSZY STATEK Z LISTY JEDNOKIERUNKOWEJ
    while(help!=NULL)
    {//USTAWIAMY STATEK
        int x,y,plane;
    system("cls");
    cout<<"JESTES TERAZ W TRYBIE USTAWIANIA"<<endl;
    cout<<"USTAWIANIE "<<help->getLength()<<"-MASZTOWCA"<<endl;
    board_player->printBoard();

    if(help->getLength()>1)//JAK BEDZIE JEDNOMASZTOWIEC TO BEZ SENSU SIE PYTAC JAKA MA BYC ORIENTACJA STATKU
    {
    cout<<"STATEK MA BYC POZIOMO CZY PIONOWO?"<<endl;
    cout<<"0.PIONOWO | 1.POZIOMO:";
    cin>>plane;
    help->setPlane(plane);
    }
    else
    {
        plane=rand()%2;
        help->setPlane(plane);
    }
    if(help->getPlane()==false)// STATEK JEST PIONOWO
    {
        do{
            x=0;y=0;
            while(x<1 || x>(board_player->getBoardLength()-help->getLength()-1) )//WARUNEK NA ROZMIAR PLANSZY ORAZ STATKU
        {
            system("cls");
            cout<<"JESTES TERAZ W TRYBIE USTAWIANIA"<<endl;
            cout<<"USTAWIANIE "<<help->getLength()<<"-MASZTOWCA"<<endl;//ILUMASZTOWIEC AKTUALNIE JEST USTAWIANY
            board_player->printBoard();
            cout<<"PODAJ WSPOLRZEDNA X:";
            cin>>x;
        }
        help->setX(x);//USTAWIAMY PIERWSZA WSPOLRZEDNA STATKU NA OSI X
        while(y<1 || y>10)//WARUNEK NA ROZMIAR PLANSZY
        {
            system("cls");
            cout<<"JESTES TERAZ W TRYBIE USTAWIANIA"<<endl;
            cout<<"USTAWIANIE "<<help->getLength()<<"-MASZTOWCA"<<endl;
            board_player->printBoard();
            cout<<"PODAJ WSPOLRZEDNA Y:";
            cin>>y;
        }
        help->setY(y);//USTAWIAMY PIERWSZA WSPOLRZEDNA STATKU NA OSI Y
        }while(board_player->checkField(help));//WARUNEK NA OBECNOSC INNYCH STATKOW NA PLANSZY

        for(int i=x; i<x+help->getLength(); i++)
        field[i][y]=board_player->getShipLook();//STATEK JEST PRZENOSZONY NA PLANSZE
    }
    else// STATEK JEST POZIOMO
    {
       do{
        x=0;y=0;
        while(x<1 || x>10)
        {
            system("cls");
            cout<<"JESTES TERAZ W TRYBIE USTAWIANIA"<<endl;
            cout<<"USTAWIANIE "<<help->getLength()<<"-MASZTOWCA"<<endl;
            board_player->printBoard();
            cout<<"PODAJ WSPOLRZEDNA X:";
            cin>>x;
        }
        help->setX(x);
        while(y<1 || y>(board_player->getBoardLength()-help->getLength()-1))
        {
            system("cls");
            cout<<"JESTES TERAZ W TRYBIE USTAWIANIA"<<endl;
            cout<<"USTAWIANIE "<<help->getLength()<<"-MASZTOWCA"<<endl;
            board_player->printBoard();
            cout<<"PODAJ WSPOLRZEDNA Y:";
            cin>>y;
        }
        help->setY(y);
        }while(board_player->checkField(help));//WARUNEK NA OBECNOSC INNYCH STATKOW NA PLANSZY

        for(int i=y; i<y+help->getLength(); i++)
        field[x][i]=board_player->getShipLook();
    }

    help=help->next;//PRZECHODZIMY DO NASTEPNEGO STATKU Z LISTY
  }
}
//---------------------------------------------------------------------------------
void Game::setShipsComputer(Board *board_computer,Ship* ships_computer)
{
    int x,y;
    char** field=board_computer->getFieldArray();//WSKAZNIK DO PLANSZY
    Ship* help=ships_computer;// WSKAZNIK NA PIERWSZY STATEK Z LISTY JEDNOKIERUNKOWEJ
    while(help!=NULL)
    {
    help->setPlane(rand()%2);
    if(help->getPlane()==false)// STATEK JEST PIONOWO
    {
        do{
            x=1+rand()%(board_computer->getBoardLength()-(help->getLength()+1));
        help->setX(x);//USTAWIAMY PIERWSZA WSPOLRZEDNA STATKU NA OSI X
            y=1+rand()%10;
        help->setY(y);//USTAWIAMY PIERWSZA WSPOLRZEDNA STATKU NA OSI Y
        }while(board_computer->checkField(help));//WARUNEK NA OBECNOSC INNYCH STATKOW NA PLANSZY

        for(int i=x; i<x+help->getLength(); i++)
        field[i][y]=board_computer->getShipLook();//STATEK JEST PRZENOSZONY NA PLANSZE
    }
    else// STATEK JEST POZIOMO
    {
       do{
            x=1+rand()%10;
        help->setX(x);//USTAWIAMY PIERWSZA WSPOLRZEDNA STATKU NA OSI X
            y=1+rand()%(board_computer->getBoardLength()-(help->getLength()+1));
        help->setY(y);//USTAWIAMY PIERWSZA WSPOLRZEDNA STATKU NA OSI Y
        }while(board_computer->checkField(help));//WARUNEK NA OBECNOSC INNYCH STATKOW NA PLANSZY

        for(int i=y; i<y+help->getLength(); i++)
        field[x][i]=board_computer->getShipLook();
    }
    help=help->next;//PRZECHODZIMY DO NASTEPNEGO STATKU Z LISTY
  }
}
//---------------------------------------------------------------------------------
void Game::gameLoop(Board *board_computer,Board *board_player,Ship* ships_computer,Ship *ships_player)
{
    HANDLE hout;
    hout=GetStdHandle(STD_OUTPUT_HANDLE);

    bool player_won=false;
    bool computer_won=false;
    while(player_won==false && computer_won==false)//TAK DLA BEZPIECZENSTWA
    {
        makeMovePlayer(board_computer,hit_board,ships_computer);
        player_won=checkGameEnd(ships_computer);
        if(player_won)
        {
            SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout<<endl<<"GRATULACJE!! WYGRALES!!"<<endl;
            getch();
            break;
        }
        cout<<"RUCH KOMPUTERA"<<endl;
        makeMoveComputer(board_player,ships_player);
        computer_won=checkGameEnd(ships_player);
        if(computer_won)
        {
            SetConsoleTextAttribute(hout, FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout<<endl<<"NIESTETY PRZEGRALES. TYM RAZEM KOMPUTER OKAZAL SIE LEPSZY :("<<endl;
            getch();
            break;
        }
    }
}
//---------------------------------------------------------------------------------
void Game::makeMovePlayer(Board *board_computer,Board* hit_board,Ship* ships_computer)
{
    int x,y;
    bool hit_bool=false;
    Ship* help=ships_computer;
    char** hit_field=hit_board->getFieldArray();
    char** computer_field=board_computer->getFieldArray();

    do{//WSPOLRZEDNE DO STRZALU
      do{
        printGame();//DRUKUJEMY PLANSZE GRACZA ORAZ PLANSZE DO STRZELANIA
        cout<<"GDZIE CHCESZ STRZELIC?"<<endl;
        cout<<"X:";
        cin>>x;
        }while(x<1 || x>10);//WARUNEK NA ROZMIAR PLANSZY

      do{
        printGame();//DRUKUJEMY PLANSZE GRACZA ORAZ PLANSZE DO STRZELANIA
        cout<<"GDZIE CHCESZ STRZELIC?"<<endl;
        cout<<"X:"<<x<<endl;
        cout<<"Y:";
        cin>>y;
        }while(y<1 || y>10);//WARUNEK NA ROZMIAR PLANSZY

        if(hit_field[x][y]==hit_board->getHitLook() || hit_field[x][y]==hit_board->getMissLook())//CZY KTOS STRZELIL DRUGI RAZ
        {
          cout<<"TUTAJ JUZ STRZELALES!"<<endl;
          cout<<"SPROBUJ JESZCZE RAZ!"<<endl;//JEZELI KTOS DRUGI RAZ STRZELI W TO SAMO MIEJSCE TO GRA GO O TYM POINFORMUJE
          getch();
        }
       }while(hit_field[x][y]==hit_board->getHitLook() || hit_field[x][y]==hit_board->getMissLook());//WYKLUCZAMY DWUKROTNE STRZELANIE W TO SAMO MIEJSCE

    while(help!=NULL)//TERAZ SPRAWDZAMY CZY TRAFILISMY STATEK KOMPUTERA(DLA KAZDEGO STATKU Z LISTY OSOBNO)
    {
        if(help->getPlane()==false)// STATEK JEST PIONOWO
        {
            for(int i=help->getX(); i<help->getX()+help->getLength(); i++)
            {
                if(y==help->getY() && x==i)//PRZECHODZIMY PRZEZ CALA DLUGOSC STATKU I SPRAWDZAMY CZY WSPOLRZEDNE SIE ZGADZAJA
                {
                    hit_field[i][y]=hit_board->getHitLook();//POKAZUJEMY EFEKT STRZALU NA HIT BOARDZIE
                    computer_field[i][y]=hit_field[i][y];
                    help->increaseDamage();//PODWYZSZAMY ZNISZCZENIE TRAFIONEMU STATKOWI
                    hit_bool=true;
                    break;
                }
            }
        }
        else// STATEK JEST POZIOMO
        {
            for(int i=help->getY(); i<help->getY()+help->getLength(); i++)
            {
                if(x==help->getX() && y==i)//PRZECHODZIMY PRZEZ CALA DLUGOSC STATKU I SPRAWDZAMY CZY WSPOLRZEDNE SIE ZGADZAJA
                {
                    hit_field[x][i]=hit_board->getHitLook();
                    computer_field[x][i]=hit_field[x][i];
                    help->increaseDamage();
                    hit_bool=true;
                    break;
                }
            }
        }
     help=help->next;
    }
    if(hit_bool==false)
    {
        hit_field[x][y]=hit_board->getMissLook();//NA PLANSZY WYSWIETLA SIE PUDLO
    }
    printGame();
}
//---------------------------------------------------------------------------------
void Game::makeMoveComputer(Board *board_player,Ship *ships_player)
{
    Sleep(800);
    int x,y;
    bool hit_bool=false;
    Ship* help=ships_player;
    char** player_field=board_player->getFieldArray();

    do{//WSPOLRZEDNE DO STRZALU(RANDOMOWE W TYM PRZYPADKU OCZYWISCIE) JESZCZE
            x=1+rand()%10;
            y=1+rand()%10;
    }while(player_field[x][y]==board_player->getHitLook() || player_field[x][y]==board_player->getMissLook());//WYKLUCZAMY DWUKROTNE STRZELANIE W TO SAMO MIEJSCE

    while(help!=NULL)//TERAZ SPRAWDZAMY CZY TRAFILISMY STATEK GRACZA
    {
        if(help->getPlane()==false)//STATEK JEST PIONOWO
        {
            for(int i=help->getX(); i<help->getX()+help->getLength(); i++)
            {
                if(y==help->getY() && x==i)//PRZECHODZIMY PRZEZ CALA DLUGOSC STATKU I SPRAWDZAMY CZY WSPOLRZEDNE SIE ZGADZAJA
                {
                    player_field[i][y]=board_player->getHitLook();//POKAZUJEMY EFEKT STRZALU NA HIT BOARDZIE
                    help->increaseDamage();//PODWYZSZAMY ZNISZCZENIE TRAFIONEMU STATKOWI
                    hit_bool=true;
                    break;//OPTYMALIZACJA
                }
            }
        }
        else// STATEK JEST POZIOMO
        {
            for(int i=help->getY(); i<help->getY()+help->getLength(); i++)
            {
                if(x==help->getX() && y==i)//PRZECHODZIMY PRZEZ CALA DLUGOSC STATKU I SPRAWDZAMY CZY WSPOLRZEDNE SIE ZGADZAJA
                {
                    player_field[x][i]=board_player->getHitLook();
                    help->increaseDamage();
                    hit_bool=true;
                    break;//OPTYMALIZACJA
                }
            }
        }
     help=help->next;
    }
    if(hit_bool==false)
    {
        player_field[x][y]=board_player->getMissLook();//NA PLANSZY WYSWIETLA SIE PUDLO
    }
    printGame();
}
//---------------------------------------------------------------------------------
bool Game::checkGameEnd(Ship* ships)
{
    int how_many_pieces=20;//LACZNIE STATKI MAJA 20 POJEDYNCZYCH ELEMENTOW
    int count=0;
    Ship* help=ships;
    while(help!=0)
    {
        count+=help->getDamage();//LICZYMY JAKIE OBRAZENIA MA GRACZ LUB KOMPUTER
        help=help->next;
    }
    if(count==how_many_pieces)
    {
        return true;//JEJ WYGRANA! :)
    }
    else return false;//UUU PRZEGRANA :/

}
//----------------------------------------------------------------------------------------------
void Game::printGame()
{
    HANDLE hOut;
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"       TWOJA PLANSZA"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    board_player->printBoard();
    cout<<"--------------------------";
    hit_board->printOppositeBoard();
    cout<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout<<"     PLANSZA KOMPUTERA"<<endl;
    SetConsoleTextAttribute(hOut,FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
    cout<<endl;

}
