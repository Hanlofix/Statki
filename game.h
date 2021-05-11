#ifndef GAME_H
#define GAME_H
/*
TEN MODUL ODPOWIADA ZA:
-USTAWIANIE STATKÓW NA PLANSZY
-ROZPOCZECIE GRY(GRACZ ZACZYNA)
-LOSOWE WYBIERANIE USTAWIENIA STATKÓW NA PLANSZY KOMPUTERA
-ODDAWANIE STRZA£ÓW PRZEZ KOMPUTER I PRZEZ GRACZA
-SPRAWDZANIE I AKTUALIZACJA ODNIESIONYCH STRAT
-ZWRACANIE AKTUALNEGO STANU GRY(KOGO JEST AKTUALNIE RUCH, TRAFIENIA ITP.)
-ZWRACANIE ZWYCIEZCY
*/
#include "board.h"
#include "ship.h"
class Game
{
    public:
        Game();
        virtual ~Game();
        Ship* newSetOfShips();
        void deleteSetOfShips(Ship*& head);
        void setShipsPlayer(Board *board_player,Ship *ships_player);//USTAWIA STATKI GRACZA
        void setShipsComputer(Board *board_computer,Ship* ships_computer);//USTAWIA STATKI KOMPUTERA
        void gameLoop(Board *board_computer,Board *board_player,Ship* ships_computer,Ship *ships_player);
        void makeMovePlayer(Board *board_computer,Board* hit_board,Ship* ships_computer);
        void makeMoveComputer(Board *board_player,Ship *ships_player);
        bool checkGameEnd(Ship *ships);
        void printGame();

    protected:
    private:
        Ship* ships_player;//WSKAZNIK DO LISTY STATKOW GRACZA
        Ship* ships_computer;//WSKAZNIK DO LISTY STATKOW KOMPUTERA
        Board* board_player;//WSKAZNIK DO PLANSZY GRACZA
        Board* board_computer;//WSKAZNIK DO PLANSZY KOMPUTER
        Board* hit_board;
};

#endif // GAME_H
