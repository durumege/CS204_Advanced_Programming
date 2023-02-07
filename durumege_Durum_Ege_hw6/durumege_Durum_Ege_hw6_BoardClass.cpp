//
// Created by Ege Durum on 8.5.2021.
//
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include "durumege_Durum_Ege_hw6_BoardClass.h"

using namespace std;

template<class Typ>
Board<Typ>::Board(const int row, const int col) {
    //for creating matrix with given first 2 integers of the file i need to get row and
	// column data
	colSize = col;
    rowSize = row;
    //constructing board matrix using dynamic memory allocation
    matrix = new node<Typ>*[rowSize];
    for (int i = 0; i < rowSize; i++) {
        matrix[i] = new node<Typ> [colSize];
    }
}

template<class Typ>
Board<Typ>::~Board() { //destructor implementation
    for(int i = 0; i < rowSize; i++) {
        delete [] matrix[i];
    }
    delete [] matrix; //for cleaning heap
}


template<class Typ>
bool Board<Typ>::isOpen(const int row, const int col) { //checks is open or not (one of the input checks that we needed 
    
    if(matrix[row][col].isClose == 1){
        return true;
    }
    return false;
}


template<class Typ>
void Board<Typ>::displayBoard() {
    //displaying board and initialize it with 'X' 
	for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            if(matrix[i][j].isClose == 1){
                cout << 'X' << ' ';
            }
            else{
                cout << matrix[i][j].face << ' ';
            }
        }
        cout << endl;
    }
}

template<class Typ>
void Board<Typ>::closeCard(const int row, const int col) { //closing particular point 
    matrix[row][col].isClose = 1;
}

template<class Typ>
void Board<Typ>::openCard(const int row, const int col) { //opening particular point 
    matrix[row][col].isClose = 0;
}

template<class Typ>
int Board<Typ>::getRow() const { //getting row data
    return rowSize;
}

template<class Typ>
int Board<Typ>::getColumn() const { //getting column data
    return colSize;
}


template<class Typ>
Typ Board<Typ>::returnVal(int row, int col) { //getting face 
    return matrix[row][col].face;
}

template<class Typ>
void Board<Typ>::readBoardFromFile(ifstream & file) {
    //reading file 
    //initial row must be 0 
    int iRow = 0;
	string line;
    while (getline(file, line)) {
        istringstream rows (line);
        Typ val;
		//initial column must be 0
        int iCol = 0;
        while (rows >> val) {
		//filling matrix 		
			matrix[iRow][iCol].face = val;
			matrix[iRow][iCol].isClose = 1;
			iCol++;
        }
		iRow++;
	}
}