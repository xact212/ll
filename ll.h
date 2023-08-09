#ifndef LL_H
#define LL_H

typedef struct node{
    int val;
    struct node* next;
} node;

typedef struct ll{
    node* head;
    int len;
} ll;

node* buildNode(int val, node* next);
ll* buildll();
void appendNode(ll* ll, int val);
void printll(ll* ll);
void removeNode(ll* ll, int index);
void deletell(ll* ll);
void insertNode(ll* ll, int val, int index);

#endif