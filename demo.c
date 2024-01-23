#include "ll.h"

int main() {
    ll* mainll = buildll();
    printll(mainll, "int");
    int myNum1 = 4;
    int myNum2 = 2; 
    int myNum3 = 4; 
    int myNum4 = 7; 
    int myNum5 = 6; 
    int myNum6 = 8; 
    int myNum7 = 99; 
    appendNode(mainll, &myNum1);
    appendNode(mainll, &myNum2);
    appendNode(mainll, &myNum3);
    appendNode(mainll, &myNum4);
    appendNode(mainll, &myNum5);
    appendNode(mainll, &myNum6);
    appendNode(mainll, &myNum7);
    printll(mainll, "int");
    removeNode(mainll, 4);
    printll(mainll, "int");
    int myNum8 = 54;
    insertNode(mainll, &myNum8, 5);
    printll(mainll, "int");
    deletell(mainll, 0x00000000);
}