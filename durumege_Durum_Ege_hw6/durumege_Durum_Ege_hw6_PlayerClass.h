//
// Created by Ege Durum on 7.5.2021.
//

#ifndef HW6_PLAYER_H
#define HW6_PLAYER_H
#include<iostream>
#include <string>
#include "durumege_Durum_Ege_hw6_BoardClass.h"

using namespace std;

template<class Typ>
class Player {
    public:
        Player();

        Player(Board<Typ> &myBoard)
        : board(myBoard), score(0) //since we should initialize the score of the player to zero
    { }
        Typ openCard(const int row, const int col); //openCard
        bool validMove(const int row, const int col); //validMove
        void increaseNumberOfSuccess(); //increaseNumberOfSuccess
        int getNumberOfSuccess() const; //getting number of success

	private:
		Board<Typ> &board;
		int score; //since (The player class should also keep the score (number of successful matches) of the player.)
};

#include "durumege_Durum_Ege_hw6_PlayerClass.cpp" //part of the solution 2 
#endif //HW6_PLAYER_H
