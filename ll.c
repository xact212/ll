#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "ll.h"

node* buildNode(void* data, node* next) {
    struct node* newNode = malloc(sizeof(node));
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

ll* buildll() {
    ll* newll = malloc(sizeof(ll));
    newll->head = NULL;
    newll->len = 0;
    return newll;
}

void appendNode(ll* ll, void* data) {
    if (ll->head == NULL) {
        ll->head = buildNode(data, NULL);
        ll->len++;
        return;
    }
    else {
        node* curr = ll->head;
        while(curr->next != NULL) //get to end of ll 
            curr = curr->next;
        curr->next = buildNode(data, NULL);
        ll->len++;
    }
    
}

void printll(ll* linkl, char* dataType) {
    bool isString = !strcmp(dataType, "string"); //precompute comparisons, invert because returns zero if equal
    bool isll = !strcmp(dataType, "ll");

    printf("ll is %i long\n", linkl->len);
    node* curr = linkl->head;
    while (curr != NULL) {
        if (isString) //default assume int, have to specify for string or other type
            printf("%s->", (*(char***)curr->data));
        else if (isll)
            printf("%i->", (*(ll**)curr->data)->len);
        else
            printf("%i->",  *(int*)curr->data);
        curr = curr->next;
    }
    puts("NULL\n");
}

void removeNode(ll* ll, int index) {
    if (index >= ll->len || index < 0) {
        puts("trying to delete node out of range of index, aborting node deletion");
        return;
    }
    node* curr = ll->head;
    node* prev = NULL;
    int count = 0;
    while (curr != NULL) {
        if (count == index) {
            prev->next = curr->next;
            ll->len--;
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
        count++;
    }
}

void deletell(ll* ll, void (*custFreeFunc)(void *data)) {
    bool freeFuncDefined = custFreeFunc != NULL;
    node* curr = ll->head;
    node* prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        ll->len--;
        node* temp = prev;
        if (freeFuncDefined) {
            custFreeFunc(temp->data); //callee not expected to free current node, just the data
            free(temp);
        }
        else {
            free(temp);
        }
    }
    free(curr);
    free(ll);
}

void insertNode(ll* ll, void* data, int index) {
    if (index >= ll->len || index < 0) {
        puts("trying to insert node out of range of index, aborting node insertion");
        return;
    }
    node* curr = ll->head;
    node* prev = NULL;
    int count = 0;
    while (curr != NULL) {
        if (count == index) {
            ll->len++;
            prev->next = buildNode(data, curr);
            return;
        }
        prev = curr;
        curr = curr->next;
        count++;
    }
}
