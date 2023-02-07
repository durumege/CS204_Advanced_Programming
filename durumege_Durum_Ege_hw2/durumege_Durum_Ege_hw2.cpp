//hw2

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//to store data
struct node {
    int value;
    node * next;

    node() {
        next = NULL;
    }

    //constructor
    node (int va,node *ne)
            :value(va), next(ne)
    {

    }
};

//to check existence
/* Begin: code taken from linkedList.cpp */
bool SearchList(node *head, int searchValue)
{
    while (head != NULL)
    {
        if(head -> value == searchValue) //If the node with the given ID is found
            return true;
        head = head->next;
    }
    //If the code proceeds from here, it means that the whole list is traversed
    //and a node with ID == searchValue could not be found.
    return false;
}
/* End: code taken from linkedList.cpp */


//for order mode "A"
/* Begin: code taken from ptrfunc.cpp */
node * AddInOrder1(node * head, int newkey)
// pre: list is sorted
// post: add newkey to list, keep list sorted, return head of new list with newkey in it
{
    node *  ptr = head;   // loop variable

    //if new node should be first, handle this case and return
    //in this case, we return the address of new node since it is new head
    if (head == NULL || newkey < head->value)
    {
        head -> value = newkey;
        head -> next = NULL;

        return head;
    }

    node * prev; //to point to the previous node
    while (ptr != NULL && ptr -> value < newkey)
    {
        prev = ptr;     //hold onto previous node so we do not pass too far
        ptr = ptr->next;

    } // postcondition: new node to be inserted between prev and ptr

    ptr = NULL;

    //now insert node with newkey
    prev->next = new node(newkey,ptr);

    return head;
}
/* End: code taken and updated from ptrfunc.cpp */

//for order mode "B"
/* Begin: code taken from ptrfunc.cpp */
node * AddInOrder2(node * head, int newkey)
// pre: list is sorted
// post: add newkey to list, keep list sorted, return head of new list with newkey in it
{
    node *  ptr = head;   // loop variable

    //if new node should be first, handle this case and return
    //in this case, we return the address of new node since it is new head
    if (head == NULL || newkey > head->value)
    {
        head -> value = newkey;
        head -> next = NULL;
        return head;
    }

    node * prev; //to point to the previous node
    while (ptr != NULL && ptr -> value > newkey)
    {
        prev = ptr;     //hold onto previous node so we do not pass too far
        ptr = ptr->next;

    } // postcondition: new node to be inserted between prev and ptr


    ptr = NULL;

    //now insert node with newkey
    prev->next = new node(newkey,ptr);


    return head;
}
/* End: code taken and updated from ptrfunc.cpp */


//to see LinkedList
/* Begin: code taken from ptrfunc.cpp */
void DisplayList (node * head)
{
    cout << "List content: ";
    node * ptr = head;
    while (ptr != NULL)
    {
        cout << ptr ->value << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
/* End: code taken from ptrfunc.cpp */

//at the end of the program, we should clear our list
/* Begin: code taken and updated from linkedList.cpp and updated*/
void ClearList(node *head)
{
    cout << endl;
    cout << "All the nodes are deleted at the end of the program: ";
    node *ptr;

    while(head != NULL)
    {
        ptr=head;
        cout << ptr ->value << " ";
        head=head->next;
        delete ptr;
    }
	cout << endl;
}
/* End: code taken and updated from linkedList.cpp */


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


int main() {

    string ans;
    cout << "Please enter the order mode (A/D): ";
    cin >> ans;

    //first input check
    while ((ans != "A") && (ans != "D")) {
        cout << "Please enter the order mode again (A/D): ";
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> ans;
    }

    cout << "Please enter the numbers in a line: ";
    string numbers;

    //creating LinkedList with pointer and new node!
    node *head = new node();
    node *temp;
    temp = head;

    //taking integers with getline
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, numbers);
    istringstream iss(numbers);
    int first;
    int num;
    iss >> first;

    //if it is empty, program will terminate
    if (isEmpty(numbers)) {
        cout << endl;
        cout << "The list is empty at the end of the program and nothing is deleted" << endl;
        return 0;
    }

    //first number will fill in LinkedList
    cout << endl;
    cout << "Next number: " << first << endl;
    temp -> value = first;


    if (head != NULL) {
        cout << "Deleted nodes: None" << endl;
    }

    cout << "Appended: " << first << endl;
    DisplayList(head);

    //process for all integers using inputstringstream
    while (iss >> num) {
        node * deletedNodes = new node();
        cout << endl;
        cout << "Next number: " << num << endl;
        if (SearchList(head, num) == true) {
            cout << num << " is already in the list!" << endl;
        }
        else {

            if (ans == "A") {
                if (temp -> value < num) { //if number is greater than List's value
                    node *add = new node(num, NULL);
                    temp -> next = add;
                    temp = temp -> next;

                    cout << "Appended: " << num << endl;
                }
                else if (temp -> value > num) {
                    AddInOrder1(head, num);
                    cout << "Appended: " << num << endl;
                    /*while ((temp -> next != NULL) && (temp -> value > num)) { //if number is smaller than List's value
                        node *del;
                        del = temp;
                        temp -> next = del -> next;

                        delete del;
                    }*/
                }
                cout << "Deleted nodes: ";

                /*while(delFollow != NULL) {
                    cout << delFollow -> value << " ";
                    delFollow = delFollow -> next;
                }
                if (delFollow == NULL) {
                    cout << "None" << endl;
                }*/
                cout << endl;
            }
            else if (ans == "D"){
                if (temp -> value > num) { //if number is smaller than List's value
                    node *add = new node(num, NULL);
                    temp -> next = add;
                    temp = temp -> next;

                    cout << "Appended: " << num << endl;
                } else if (temp -> value < num) { //if number is greater than List's value
                    AddInOrder2(head, num);
                    cout << "Appended: " << num << endl;
                    /*while ((temp -> next != NULL) && (temp -> value < num)) {
                        node *del;
                        del = temp;
                        temp -> next = del -> next;

                        delete del;
                    }*/
                }
                cout << "Deleted nodes: ";

                /*while(delFollow != NULL) {
                    cout << delFollow -> value << " ";
                    delFollow = delFollow -> next;
                }
                if (delFollow == NULL) {
                    cout << "None" << endl;
                } */
                cout << endl;
            }
        }
        DisplayList(head);
		
    }

	ClearList(head);

    return 0;
}


//created by Ege Durum
//26437
