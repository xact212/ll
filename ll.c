#include <stdio.h>
#include <stdlib.h>
#include "ll.h"


node* buildNode(int val, node* next) {
    struct node* newNode = malloc(sizeof(node));
    newNode->val = val;
    newNode->next = next;
    return newNode;
}

ll* buildll() {
    ll* newll = malloc(sizeof(ll));
    newll->head = NULL;
    newll->len = 0;
    return newll;
}

void appendNode(ll* ll, int val) {
    if (ll->head == NULL) {
        ll->head = buildNode(val, NULL);
        ll->len++;
        return;
    }
    else {
        node* curr = ll->head;
        while(curr->next != NULL) //get to end of ll 
            curr = curr->next;
        curr->next = buildNode(val, NULL);
        ll->len++;
    }
    
}

void printll(ll* ll) {
    printf("ll is %i long\n", ll->len);
    node* curr = ll->head;
    while (curr != NULL) {
        printf("%i->", curr->val);
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

void deletell(ll* ll) {
    node* curr = ll->head;
    node* prev = NULL;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        ll->len--;
        node* temp = prev;
        free(temp);
    }
    free(curr);
    ll->head = NULL;
}

void insertNode(ll* ll, int val, int index) {
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
            prev->next = buildNode(val, curr);
            return;
        }
        prev = curr;
        curr = curr->next;
        count++;
    }
}

