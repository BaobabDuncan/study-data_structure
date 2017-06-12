
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlistop.h"

int main() {
    int i = 0, arrayCount = 0;
    LinkedList *pListA = NULL, *pListB = NULL;
    ListNode node;

    pListA = createLinkedList();
    pListB = createLinkedList();
    if (pListA != NULL && pListB != NULL) {
        node.data = 1;
        addElement(pListA, 0, node);
        node.data = 2;
        addElement(pListA, 1, node);
        node.data = 3;
        addElement(pListA, 2, node);
        node.data = 4;
        addElement(pListB, 0, node);
        node.data = 5;
        addElement(pListB, 1, node);

        iterateLinkedList(pListA);
        iterateLinkedList(pListB);

        concatLinkedList(pListA, pListB);

        printf("After concatLinkedList()\n");
        iterateLinkedList(pListA);
        iterateLinkedList(pListB);

        reverseLinkedList(pListA);
        printf("After reverseLinkedList()\n");
        iterateLinkedList(pListA);


        deleteLinkedList(pListA);
        deleteLinkedList(pListB);


    }
    return 0;
}