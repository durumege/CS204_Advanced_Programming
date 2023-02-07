//hw1

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include "durumege_Durum_Ege_hw1_strutils.h"

using namespace std;

//for printing and checking my matrix
void print(const vector<vector<char>> &matrix)
{
	for (unsigned int j = 0; j < matrix.size(); j++)
	{
		for (unsigned int k = 0; k < matrix[0].size(); k++)
		{
			cout << matrix[j][k] << "\t";
		}
		cout << endl;
	}
}
//collecting all information about file within this struct
struct data{
    string word;
    int s_row;
    int s_col;
    string direction, ori;
};
//to follow and get which coordinates filled
struct coordinate {
    int rowxx, colxx;
};
//right with orientation CW
bool r1 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((col +1 <= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;

    } else if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;

    }else if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;

    }else if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    return result;
}
//right with orientation CCW
bool r2 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    else if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    else if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;

    }
    else if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    return result;
}
//left with orientation CW
bool l1 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;
    }
    else if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    else if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    else if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    return result;
}
//left with orientation CCW
bool l2 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;
    }
    else if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    else if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    else if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    return result;
}
//up with orientation CW
bool u1 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    else if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    else if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    else if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;
    }
    return result;
}
//up with orientation CCW
bool u2 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    else if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;
    }
    else if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    else if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    return result;
}
//down with orientation CW
bool d1 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    else if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;
    }
    else if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    else if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    return result;
}
//down with orientation CCW
bool d2 (int &row, int&col, int &count, vector<vector<char>> &vec, char ch) {
    bool result = false; //assume
	int size1 = vec[0].size();
	int size2 = vec.size();
    if ((row < size2-1) && (vec[row+1][col]== '-')) { //down
        vec[row+1][col] = ch;
        row++;
        result = true;
    }
    else if ((col +1<= size1-1) && (vec[row][col+1] == '-')) { //right
        vec[row][col+1] = ch;
        col++;
        result = true;
    }
    else if ((row != 0) && (vec[row-1][col]== '-')) { //up
        vec[row-1][col] = ch;
        row--;
        result = true;
    }
    else if ((col != 0) && (vec[row][col-1]== '-')) { //left
        vec[row][col-1] = ch;
        col--;
        result = true;
    }
    return result;
}
//created this for deleting words which could not be put into the matrix!
void vectDelete(vector<coordinate> &a, vector<vector<char>> &b){
    for (unsigned int i = 0; i < a.size(); i++) {
        int row, column;
        row = a[i].rowxx;
        column = a[i].colxx;
        b[row][column] = '-';
    }
}

int main() {

    //getting .txt file's name
    string filename;
    cout << "Please enter the name of the file: ";
    cin >> filename;

    ifstream input;
    input.open(filename);

    //first input check
    while (input.fail()) {
        cout << "File name is incorrect, please enter again: ";
        cin >> filename;

        input.open(filename);
    }

    //first of all, taking row and col numbers
    string line;
    getline(input, line);
    int ro = line.find(' ');
    string rows = line.substr(0, ro);
    int row = atoi(rows);
    string cols = line.substr(ro);
    int col = atoi(cols);

    //checking row and column numbers are positive or not!
    if ((row <= 0) || (col <= 0)) {
        cout << "Invalid number for row and/or column!" << endl;
        return 0;
    }

    vector<data> vec; //empty vector for data

    //empty 2D matrix with init-value (-)
    vector<vector<char>> matrix(row, vector<char>(col, '-'));


    //reading .txt file and input checks
    while (getline(input, line)) {
        stringstream ss(line);
        string values;
        int counter = 0;
        while (ss >> values) {
            counter++;
        }
        if (counter != 5) { //orientation number must be 5 !!!
            cout << "Invalid line! Number of values is different than 5." << endl;
        } else {
            string word, ori;
            string direction;
            int start_row, start_col;
            istringstream ss2(line);
            ss2 >> word >> start_row >> start_col >> direction >> ori;
            if ((start_row < 0) || (start_row >= row) || (start_col < 0) ||
                (start_col >= col)) { //for row and col numbers
                cout << "Starting point is out of range! Point: " << start_row << "," << start_col << endl;
            } else if (!((direction == "r") || (direction == "u") || (direction == "d") ||
                         (direction == "l"))) { //for direction
                cout << "Invalid input for direction! Direction: " << direction << endl;
            } else if (!((ori == "CW") || (ori == "CCW"))) { //for orientation
                cout << "Invalid input for orientation! Orientation: " << ori << endl;
            } else {

                //storing data into an empty vector before filling the matrix
                data vect;
                vect.word = word;
                vect.s_row = start_row;
                vect.s_col = start_col;
                vect.direction = direction;
                vect.ori = ori;
                vec.push_back(vect);

                //storing coordinates of filled characters
                vector <coordinate> co;
                coordinate cor;
                cor.rowxx = start_row;
                cor.colxx = start_col;
                co.push_back(cor);

                //filling matrix process
                int count = 0; //for following word's characters
                int w = word.length();
                if (matrix[start_row][start_col] == '-') {
                    matrix[start_row][start_col] = word[0]; //for the first coordinates
                    count++;
                    int breakpoint = 0;
                    for (int i = 1; i < w; i++) {
                        if (direction == "r") {
                            if (ori == "CW") {
                                if (r1(start_row, start_col, count, matrix, word[i])) { //right
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            } else if (ori == "CCW") {
                                if (r2(start_row, start_col, count, matrix, word[i])) { //right
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            }
                        } else if (direction == "l") {
                            if (ori == "CW") {
                                if (l1(start_row, start_col, count, matrix, word[i])) { //left
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            } else if (ori == "CCW") {
                                if (l2(start_row, start_col, count, matrix, word[i])) { //left
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            }
                        } else if (direction == "u") {
                            if (ori == "CW") {
                                if (u1(start_row, start_col, count, matrix, word[i])) { //up
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            } else if (ori == "CCW") {
                                if (u2(start_row, start_col, count, matrix, word[i])) { //up
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            }

                        } else if (direction == "d") {
                            if (ori == "CW") {
                                if (d1(start_row, start_col, count, matrix, word[i])) { //down
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }

                            } else if (ori == "CCW") {
                                if (d2(start_row, start_col, count, matrix, word[i])) { //down
                                    count++;
                                    cor.rowxx = start_row;
                                    cor.colxx = start_col;
                                    co.push_back(cor);
                                } else {
                                    breakpoint++;
                                    break;
                                }
                            }
                        }
                    }
                    if (count == w) { //exit loop if all word's characters filled into matrix
                        cout << "\"" << word << "\"" << " was put into the matrix with given starting point: "
                             << vect.s_row << "," << vect.s_col
                             << endl << "direction: " << direction << "\t orientation: " << ori << endl;
                        print(matrix);
                        cout << endl;
                    }
                    else if (breakpoint > 0) { //if code encountered any break; then, delete all filled characters
                        vectDelete(co, matrix);
                        cout << "\"" << word << "\""
                             << " could not be put into the matrix with given starting point: " << vect.s_row
                             << ","
                             << vect.s_col
                             << endl << "direction: " << direction << "\t orientation: " << ori << endl;
                        print(matrix);
                        cout << endl;
                    }
                } else { //if first points are not dash (-) or available, then could not be put into the matrix
                    cout << "\"" << word << "\""
                         << " could not be put into the matrix with given starting point: "
                         << vect.s_row << "," << vect.s_col
                         << endl << "direction: " << direction << "\t orientation: " << ori << endl;
                    print(matrix);
                    cout << endl;
                }
            }
        }
    }
    //do not forget to close file for memory
    input.close();
    return 0;
}

//vector checking code
/*for (unsigned int i=0; i < vec.size(); i++) {
    cout << vec[i].word << " " << vec[i].s_row << " " << vec[i].s_col << " " << vec[i].direction << " " <<
         vec[i].ori << " " << endl;
}*/

//created by Ege Durum
//26437

