//hw3 :(

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct SubSeqNode
{
    int value;
    SubSeqNode * next;

    SubSeqNode() {
        next = NULL;
    }

    //constructor
    SubSeqNode (int va,SubSeqNode *ne)
            :value(va), next(ne)
    {

    }
};


struct SubSeqHeadNode
{
    int size; // number of elements in the subsequence
    SubSeqNode * sHead; // head of the subsequence list
    SubSeqHeadNode * next;
    SubSeqHeadNode() {
        next = NULL;
    }

    //constructor
    SubSeqHeadNode (int si,SubSeqHeadNode *ne)
            :size(si), next(ne)
    {

    }

};

/* Begin: code taken and updated from durumege_Durum_Ege_hw2.cpp and updated*/
//this is for checking string numbers is empty or not!
bool isEmpty (string num) {
    bool result = true;
    if (num.length() == 0) {
        result = true;
    }
    for (unsigned int i = 0; i < num.length(); i++) {
        if (!(num[i] == '\t') && !(num[i] == ' ') && !(num[i] == '\n')) {
            result = false;
        }
    }
    return result;
}
/* End: code taken and updated from durumege_Durum_Ege_hw2.cpp and updated*/


int main() {
    string numbers;

    cout << "Please enter the numbers in a line: ";
    getline(cin, numbers);
    istringstream iss(numbers);
    int num;


    /* Begin: code taken and updated from durumege_Durum_Ege_hw2.cpp and updated*/
    //if it is empty, program will terminate
    if (isEmpty(numbers)) {
        cout << endl;
        cout << "FINAL CONTENT" << endl << "List is empty!" << endl;
        return 0;
    }
    /* End: code taken and updated from durumege_Durum_Ege_hw2.cpp and updated*/

    SubSeqHeadNode *head = new SubSeqHeadNode();
    SubSeqHeadNode *temp;

    temp = head;

    while (iss >> num) {
        if (num > 0) {
            SubSeqHeadNode *add = new SubSeqHeadNode(num, NULL);
            temp -> next = add;
            temp = temp -> next;
        }
    }

    //i could not do it i tried so many things but could not
    //i am sorry :/
    //only sample run 6 is working :( (which was empty input case)

    return 0;
}

//created by Ege DURUM