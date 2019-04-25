//begin linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

using namespace std;

struct node {
    int data;
    node * next;
};

class linkedlist {
private:
    node * head;
    int count(struct node* head); // RECURSIVE
    int sum(struct node* head); // RECURSIVE

public:
    linkedlist();
    ~linkedlist(struct *node head); // RECURSIVE
    void addToFront(int n);
    double average(struct *node head); // uses sum and count functions
    void writeInorder(string & file);
    void writeReversed(string & file);
};
#endif // end linkedlist.h
