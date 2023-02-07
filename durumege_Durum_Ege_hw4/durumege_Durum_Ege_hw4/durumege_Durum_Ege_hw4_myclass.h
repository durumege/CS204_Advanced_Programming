//
// Created by Ege Durum on 8.4.2021.
//

#ifndef _DURUMEGE_DURUM_EGE_HW4_MYCLASS_H
#define _DURUMEGE_DURUM_EGE_HW4_MYCLASS_H

using namespace std;

/* Begin: code taken and updated from DynIntStack.cpp */
struct StackNode
{
    string co;
    StackNode *next;
};

class DynIntStack
{
private:
    StackNode *top;

public:
    DynIntStack(void);
    ~DynIntStack();
    void push(string);
    void pop(string &);
    bool isEmpty(void);
};
/* End: code taken and updated from DynIntStack.cpp */

#endif 
