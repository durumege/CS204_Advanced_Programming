//
// Created by Ege Durum on 8.4.2021.
//
#include <iostream>
#include <string>
#include "durumege_Durum_Ege_hw4_myclass.h"

using namespace std;

/* Begin: code taken and updated from DynIntStack.cpp */
DynIntStack::DynIntStack()
{
    top = NULL;
}

bool DynIntStack::isEmpty(void)
{
    bool status;

    if (top == NULL)
        status = true;
    else
        status = false;

    return status;
}

void DynIntStack::push(string num)
{
    StackNode *newNode;

    // Allocate a new node & store Num
    newNode = new StackNode;
    newNode->co = num;

    // If there are no nodes in the list
    // make newNode the first node
    if (isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else	// Otherwise, insert NewNode before top
    {
        newNode->next = top;
        top = newNode;
    }
}

void DynIntStack::pop(string &num)
{
    StackNode *temp;

    if (isEmpty())
    {
        cout << "The stack is empty.\n";
    }
    else	// pop value off top of stack
    {
        num = top->co;
        temp = top->next;
        delete top;
        top = temp;
    }
}
/* End: code taken and updated from DynIntStack.cpp */