#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "durumege_Durum_Ege_hw4_myclass.h"

using namespace std;

//for given instructions in hw4 pdf
struct cellStruct{
    char ch;
    bool flag;
};

//for memory heap, we should delete the matrix
void delMatrix(cellStruct ** matrix, int rows) {
    for (int i = 0; i < rows; i++){
        delete [] matrix[i];
    }
    delete [] matrix;
}

int main() {

    int rows, cols;
    cout << "Please enter the number of rows: ";
    cin >> rows;

    cout << "Please enter the number of cols: ";
    cin >> cols;

    //getting .txt file's name
    string filename;
    cout << "Please enter the name of the input file that contains the matrix: ";
    cin >> filename;

    ifstream file;
    file.open(filename);

    //first input check
    while (file.fail()) {
        cout << "File cannot be opened." << endl;
        cout << "Please enter the name of the input file again: ";
        cin >> filename;

        file.open(filename);
    }

    cout << endl;
    string line;

    //creating 2d array with pointers
    cellStruct ** matrix;
    matrix = new cellStruct* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new cellStruct[cols];
    }
    int r = 0;
    int c = 0;
    //reading file and filling 2d array (matrix)
    while(getline(file, line)) {
        istringstream iss(line);
        char ch;
        while (iss >> ch) {
            matrix[r][c].ch = ch;
            c++;
        }
        r++;
        c = 0;
    }

    //getting string of bits input
    string bits;
    cout << "Please enter a string of bits to search (CTRL+Z to quit): ";

    //first check (0,0) position
    while (cin >> bits) {
        cin >> bits;
        if (matrix[0][0].ch != bits[0]) {
            cout << "The bit string " << bits[0] << " could not be found." << endl;
        }
    }




    //matrix check code
    /*int a, b;
    for (a = 0; a < rows; a++) {
        for (b= 0 ; b< cols ; b++)
            cout << matrix[a][b].ch;
        cout << endl;
    }*/

    //we should close the file when we finish our work
    file.close();
    return 0;
}