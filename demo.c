#include "ll.h"

int main() {
    ll* mainll = buildll();
    printll(mainll);
    appendNode(mainll, 4);
    appendNode(mainll, 3);
    appendNode(mainll, 6);
    appendNode(mainll, 8);
    appendNode(mainll, 7);
    printll(mainll);
    removeNode(mainll, 2);
    printll(mainll);
    insertNode(mainll, 5, 2);
    printll(mainll);
    deletell(mainll);
    printll(mainll);
}