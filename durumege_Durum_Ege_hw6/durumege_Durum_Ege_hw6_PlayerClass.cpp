//
// Created by Ege Durum on 8.5.2021.
//
#include <iostream>
#include "durumege_Durum_Ege_hw6_PlayerClass.h"

using namespace std;

//this increment the current score of the player by 1
template <class Typ>
void Player<Typ>::increaseNumberOfSuccess() {
    score += 1;
}

//must return score which is a private data member in our player header file
template <class Typ>
int Player<Typ>::getNumberOfSuccess() const {
    return score;
}

//this checks a move is valid or not
template <class Typ>
bool Player<Typ>::validMove(const int row, const int col) {
    
    //checks if inputs exceed limits of the board or not
    if(row >= 0 && row < board.getRow() && col >= 0 && col < board.getColumn()){
		if (board.isOpen(row, col) {
			return true;
		}
    }
    return false;
}

//it makes the card open (corresponding card)
template <class Typ>
Typ Player<Typ>::openCard(const int row, const int col) { //return type is templated
    board.openCard(row, col);
    return board.returnVal(row, col); //returns the value of the card
}