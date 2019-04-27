#include <iostream>
#include <string>
#include "linkedlist.cpp"
#include <fstream>
using namespace std;

void readFile(linkedlist & myList, string & file) {
    fstream myFile;
    myFile.open(file);

    if(!myFile){                                      //check if file open correctly
      cout << "Error, could not open file." << endl;
      exit(1);
    }

    int tempVal;
    while(myFile >> tempVal){
      addSort(tempVal);                     //adds onto linklist in order
      //linkedlist function in order
    }
    myFile.close();
}


// ------------------------- MAIN -----------------------------

int main() {
    linkedlist();                  //SHOULD create linkedlist
    string userFile;
    cout << "Enter file name." << endl;
    cin >> userFile;                            //SHOULD get string of file.txt

    readFile(userFile);             //SHOULD store and sort linkedlist in order

    cout << "The average of LinkedList is: " << average() << endl;

    writeInorder(userFile);         //SHOULD write into file in order (since stored in order)

    cout << "SUCCESS: data written, in order, back into file" << endl;

    writeReversed(userFile);        //SHOULD write into file in reverse order

    cout << "SUCCESS: data written, in reverse order, back into file"

    ~linkedlist();

    return 0;
}
