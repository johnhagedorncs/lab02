// intlist.cpp
// Implements class IntList
// John Hagedorn 10/19/23

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    first = NULL;                   //initializes empty list
    
    if (source.first == NULL) {     //checks for empty list
        return;
    }
    first = new Node;
    first->info = source.first->info;   //create new node
    first->next = NULL;                 //for first element

    Node* sourceNode = source.first;
    Node* thisNode = first;

    while (sourceNode->next != NULL) {      //iterate through list
        sourceNode = sourceNode->next;      //create deep copy
        thisNode->next = new Node;
        thisNode = thisNode->next;
        thisNode->info = sourceNode->info;
        thisNode->next = NULL;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = first;
    while (curr != NULL) {
        Node* next = curr->next;
        delete curr;
        curr = next;
    }
    first = NULL;       //lets reader know list is empty
}

// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node* curr = first;
    while (curr != NULL) {
        Node* next = curr->next;
        sum = sum + curr->info;
        curr = next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = first;
    while (curr != NULL) {
        Node* next = curr->next;
        if (curr->info == value) {
            return true;
        }
        curr = next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max;
    Node* curr = first;
    if (curr == NULL) {
        return 0;
    }
    while (curr != NULL) {
        Node* next = curr->next;
        if (curr->info > max) {
            max = curr->info;
            curr = next;
        }
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double avg = 0.0;
    int numVals = 0;
    int sum = 0;
    Node* curr = first;
    if (curr == NULL) {
        return 0.0;
    }
    while (curr != NULL) {
        numVals = numVals + 1;
        sum = sum + curr->info;
        Node* next = curr->next;
        curr = next;
    }
    avg = static_cast<double>(sum) / numVals;   //float division
    return avg;
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = first;
    first = newNode;
}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this;
    }
    while (first != NULL) {
        Node* tempNode = first->next;
        delete first;
        first = tempNode;
    }
    if (source.first != NULL) {
        first = new Node;
        first->info = source.first->info;
        first->next = NULL;
        
        Node* sourceNode = source.first;
        Node* thisNode = first;

        while (sourceNode->next != NULL) {
            sourceNode = sourceNode->next;
            thisNode->next = new Node;
            thisNode = thisNode->next;
            thisNode->info = sourceNode->info;
            thisNode->next = NULL;
        }
    } else {
        first = NULL;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
