#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"

int main() {
    printf("linked list\n");
    LinkedList *pList;
    LinkedListNode node;

    pList = createLinkedList();
    node.data = 10;
    addElement(pList, 0, node);
    node.data = 9;
    addElement(pList, 0, node);
    node.data = 8;
    addElement(pList, 0, node);
    node.data = 7;
    addElement(pList, 0, node);
    node.data = 32;
    addElement(pList, 3, node);
    node.data = 78;
    addElement(pList, 1, node);

    displayLinkedList(pList);
    removeElement(pList, 2);
    displayLinkedList(pList);

    clearLinkedList(pList);
    deleteLinkedList(pList);
    displayLinkedList(pList);
    return 0;
}