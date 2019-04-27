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

    fstream myFile;
    myFile.open(file);

    bool isSorted = false;
    while (isSorted == false){
      node *cursor = head;
      bool sorted = false;
      while(sorted = false){
        node *temp1 = head;
        node *temp2 = head;
        node *temp3 = head;
        sorted = true;

        do{
          node *next = temp1->next;
          if(temp1->data  >  next->data){
            temp2 = temp1;
            temp3 = next;
            sorted = false;
          }
          temp1 = temp1->next;
        } while(temp1->next != NULL);
        if(cursor != NULL){
          cursor->next = temp3;
        }

        cursor = temp3;
        if(cursor == head){
          head = cursor->next;
        }
        temp2->next = temp3->next;
        cursor->next = NULL;
      }
      cursor->next = head;
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
