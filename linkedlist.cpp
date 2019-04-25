#include "linkedlist.h"

linkedlist::linkedlist() {
    this->head = nullptr;
    this-> count() = 0;
    this-> sum() = 0;
}

linkedlist::~linkedlist(struct node *head) {
    if(head == NULL)
        {return;}
    ~linkedlist (head->next);
    delete head;
}

int linkedlist::count(struct node* head) {
    if (head == NULL)
        {return 0;}
    return 1 + count(head->next);
}

void linkedlist::addToFront(int n) {
    //
}

double linkedlist::average(struct *node head) {
    // uses sum and count functions
}

int linkedlist::sum(struct node *head) {
    if(head == NULL)
        {return 0;}
    return head->data + sum(head->next);
}

void linkedlist::writeInorder(string & file) {
    //
}

void linkedlist::writeReversed(string & file) {
    // RECURSIVE
}
