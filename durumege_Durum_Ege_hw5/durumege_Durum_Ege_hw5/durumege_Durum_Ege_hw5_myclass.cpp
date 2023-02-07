#include <iostream>
#include <string>
#include <sstream>
#include "durumege_Durum_Ege_hw5_myclass.h"

using namespace std;

//default constructor
Wallet:: Wallet() {
    dyn_array = NULL;
    size = 0;
}

//deep copy constructor
Wallet::Wallet(const Wallet & copy) {
    size = copy.size;

    dyn_array = new Money [size];

    for (int i = 0; i < size; i++) {
        dyn_array[i] = copy.dyn_array[i];
    }
}

//destructor
Wallet::~Wallet() {
    if (dyn_array != NULL) {
        delete [] dyn_array;

        dyn_array = NULL;
        size = 0;
    }
}

int Wallet::Size() const {
    return size;
}

Money *Wallet::Array() const {
    return dyn_array;
}

//overloading parts
//operator << (overloading)
ostream & operator << (ostream & os, const Wallet & wa) {

    ostringstream ostr;

    ostr.fill('0');

    int size = wa.Size();

    Money*tem;
    tem = wa.Array();

    for (int i = 0; i < size; i++) {
        ostr << tem[i].currency << " " << tem[i].amount << "-";
    }

    os << ostr.str();

    return os;
}

const Wallet & Wallet::operator + (const Money & a) {

}

//operator += (overloading)
const Wallet & Wallet::operator += (const Wallet & wa) {
    Wallet cuzdan;
    cuzdan.dyn_array = this -> dyn_array;
    cuzdan.size = this -> size;
    cuzdan = cuzdan + wa;
    this ->dyn_array = cuzdan.dyn_array;
    this -> size = cuzdan.size;

    return *this;
}

//operator = (overloading)
const Wallet & Wallet::operator = (const Wallet & rhs) {
    if (this != &rhs) {
        dyn_array =
    }
    return *this;
}

//operator == (overloading)
const Wallet & Wallet::operator == (const Wallet & rhs) {
    if (this != &rhs) {
        dyn_array =
    }
    return *this;
}

//operator <= (overloading)
bool operator <= (const Wallet &lhs, const Wallet &rhs) {

}

//operator >= (overloading)
bool operator >= (const Wallet &lhs, const Wallet &rhs) {

}

//operator - (overloading)
bool operator - (const Wallet &lhs, const Wallet &rhs) {

}

//operator + (overloading)
bool operator + (const Wallet &lhs, const Wallet &rhs) {

}

//this is like template i could not fill it correctly
