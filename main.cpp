#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include "linkedlist.h"
#include <fstream>
using namespace std;

void readFile(linkedlist & myList, string & file) {
    fstream myFile;
    myFile.open(file);

    if(!myFile){                                      //check if file open correctly
      cout << "Error, could not open file." << endl;
      exit(1);
    }

    int tempVal = 0;
    while(myFile >> tempVal){
      myList.addToFront(tempVal);
    }
    myFile.close();
}


// ------------------------- MAIN -----------------------------

int main() {
    linkedlist myLList = linkedlist();                  //SHOULD create linkedlist
    string userFile;
    cout << "Enter file name." << endl;
    cin >> userFile;                            //SHOULD get string of file.txt

    readFile(myLList, userFile);             //SHOULD store linkedlist (random order)

    cout << "The average of LinkedList is: " << myLList.average() << endl;

    myLList.writeInorder(userFile);         //SHOULD write into file in order

    cout << "SUCCESS: data written, in order, back into file" << endl;

    myLList.writeReversed(userFile);        //SHOULD write into file in reverse order

    cout << "SUCCESS: data written, in reverse order, back into file" << endl;

    delete myLList;

    return 0;
}
