#ifndef _DURUMEGE_DURUM_EGE_HW5_MYCLASS_H
#define _DURUMEGE_DURUM_EGE_HW5_MYCLASS_H

using namespace std;

//Money struct
struct Money {
    string currency;
    double amount;
};

//our class Wallet
class Wallet {
private:
    Money *dyn_array;
    int size;

public:
    Wallet(); //default constructor
    Wallet(const Wallet &); //deep copy constructor
    ~Wallet(); //destructor

    int Wallet::Size() const;
    Money *Wallet::Array() const;

    //member functions operator
    const Wallet & operator +=(const Wallet & wa);
    const Wallet & operator = (const Wallet & rhs);
    const Wallet & operator == (const Wallet & rhs);
    const Wallet & operator + (const Money & a);
};


//free functions
ostream &  operator << (ostream & os, const Wallet & wa); //ostringstream

bool operator + (const Wallet & lhs, const Wallet & rhs);
bool operator - (const Wallet & lhs, const Wallet & rhs);
bool operator <=  (const Wallet& lhs, const Wallet& rhs);
bool operator >=  (const Wallet& lhs, const Wallet& rhs);

#endif 




