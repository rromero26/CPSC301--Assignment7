#include "linkedlist.h"
#include <fstream>
//-----------------------------------------------------------------------------
linkedlist::linkedlist() {                       // CONSTRUCTOR
    this->head = NULL;
}

linkedlist::~linkedlist() {                      //DESTRUCTOR LinkedList
    node *cursor = head;

    while( cursor != NULL){
      node *nextPtr = cursor->next;
      delete cursor;
      cursor = nextPtr;
    }

    head = NULL;
}
//-----------------------------------------------------------------------------
int linkedlist::count() {
    node *temp = head;
    int counter = 0;

    while(temp != NULL){
      counter++;
      temp = temp->next;
      }

    return counter;
}

int linkedlist::sum() {
    node *temp = head;
    int total = 0;

    while(temp != NULL){
      total = total + temp->data;
      temp = temp->next;
      }

    return total;
}

double linkedlist::average() {
    int mySum = sum();
    int myCount = count();
    double myAvg = (double)mySum / (double)myCount;

    return myAvg;
}
//-----------------------------------------------------------------------------
void linkedlist::addToFront(int n) {
    node *newNode;
    newNode = new node;
    newNode->data = n;
    newNode->next = head;

    head = newNode;
}

void linkedlist::writeInorder(string & file) {   //Write in whatver order linklist is in
    node *cursor = head;

    fstream myFile;
    myFile.open(file);

    while (cursor != NULL){
      myFile << cursor->data << " ";
      cursor = cursor-> next;
    }

    myFile << endl;
    myFile.close();
}

void linkedlist::writeReversed(string & file) {

    node *cursor = head;
    node *prevPtr = NULL, *nextPtr = NULL;

    while(cursor != NULL){                    //Reverses LinkedList
      nextPtr = cursor->next;
      cursor->next = prevPtr;
      prevPtr = cursor;
      cursor = nextPtr;
    }
    head = prevPtr;

                                                //PRINT reversed LinkedList
    fstream myFile;
    myFile.open(file, ofstream::app);
    cursor = head;
    while (cursor != NULL){
      myFile << cursor->data << " ";
      cursor = cursor-> next;
    }

    myFile.close();


}

void addSort(int val){
  node *newNode = new node;               //create new node for when adding to linklist
  newNode->data = val;                    //gives it value pass in
  newNode->next = NULL;                   //initial ptr = null, will be change by end of function
  node *temp = head;

  if (temp == NULL || temp->data >= val){   //if linklist empty, add to front
    newNode->next = head;
    head = newNode;
    return;
  }
  else if(temp->next != NULL && temp->next->data >= val){
    node *tempNode = head->next;
    newNode->next = tempNode;
    head->next = newNode;
    return;

  }
  else{                                   //majority cases here
    node *left;                           //create left and right nodes that traverse linkedlist
    node *right = head;                   //once condition met, will save NEWNODE between appropriate nodes

    while(right!= NULL && right->next->data <= val){
      left = right;
      right = right->next;
    }

    left->next = newNode;
    newNode->next = right;
    return;
  }
}
