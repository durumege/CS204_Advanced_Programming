//
// Created by Ege Durum on 7.5.2021.
//

#ifndef HW6_BOARD_H
#define HW6_BOARD_H

#include <string>

using namespace std;

template<class Typ>
struct node {
    Typ face; //face value
    bool isClose; //card is open or not

    node ()
    {}

    node (const Typ & f, bool i)
            : face(f), isClose(i)
    { }
};

template<class Typ>
class Board {
    public:
        Board(const int row,const int col); //parametric constructor
        ~Board(); //destructor
        void readBoardFromFile(ifstream & file); //readBoardFromFile
        void displayBoard(); //displayBoard
        void closeCard(const int row,const int col); //closeCard
        void openCard(const int row,const int col); //openCard that i need 
        int getRow()const; //getRow
        int getColumn()const; //getCol
        Typ returnVal(int row,int col); //returns face value
        bool isOpen(const int row, const int col); //checks if point is open or not before
    private:
        node <Typ> ** matrix; //matrix declaration
        int rowSize; //for getting row size
        int colSize; //for getting column size
};


#include "durumege_Durum_Ege_hw6_BoardClass.cpp" //part of the solution 2
#endif //HW6_BOARD_H
