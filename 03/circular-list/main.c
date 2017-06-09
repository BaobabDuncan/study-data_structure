#include <stdio.h>
#include <stdbool.h>
#include "circularlist.h"

int main() {
    printf("circular list\n");
    CircularList *pList;
    CircularListNode node;
    CircularListNode *pNode;

    pList = createCircularList();
    node.data = 5;
    addElement(pList, 0, node);
    displayCircularList(pList);
    node.data = 4;
    addElement(pList, 0, node);
    displayCircularList(pList);
    node.data = 3;
    addElement(pList, 0, node);
    displayCircularList(pList);
    node.data = 2;
    addElement(pList, 0, node);
    displayCircularList(pList);
    node.data = 10;
    addElement(pList, 4, node);
    displayCircularList(pList);
    node.data = 1;
    addElement(pList, 5, node);
    displayCircularList(pList);

    pNode = getElement(pList, 5);
    printf("pNode->data = %d, pNode->pLink->data = %d\n", pNode->data, pNode->pLink->data);

    removeElement(pList, 0);
    displayCircularList(pList);

    clearCircularList(pList);
    deleteCircularList(pList);
    displayCircularList(pList);
    return 0;
}