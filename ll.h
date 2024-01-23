#ifndef LL_H
#define LL_H

//cast before data dereference
typedef struct node{
    void* data;
    struct node* next;
} node;

typedef struct ll{
    node* head;
    int len;
} ll;

node* buildNode(void* data, node* next);
ll* buildll();
void appendNode(ll* ll, void* data);
void printll(ll* ll, char* dataType);
void removeNode(ll* ll, int index);
void deletell(ll* ll, void (*custFreeFunc)(void *data));
void insertNode(ll* ll, void* data, int index);

#endif