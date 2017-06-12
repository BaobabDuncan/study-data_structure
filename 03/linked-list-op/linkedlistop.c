//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "linkedlistop.h"


void iterateLinkedList(LinkedList *pList) {
    if (NULL == pList) return;
    printf("iterateLinkedList\n");
    for (int i = 0; i < getLinkedListLength(pList); i++) {
        printf("%d ", getElement(pList, i)->data);
    }
    printf("\n");
}

void concatLinkedList(LinkedList *pListA, LinkedList *pListB) {
    int last_index_a = getLinkedListLength(pListA);
    for (int i = 0; i < getLinkedListLength(pListB); i++) {
        addElement(pListA, last_index_a, *getElement(pListB, i));
        last_index_a++;
    }
    clearLinkedList(pListB);
}

void reverseLinkedList(LinkedList *pList){
    if (NULL == pList) return;
    ListNode *pNode = NULL, *pCurrentNode = NULL, *pPrevNode = NULL;
    pNode = pList->headerNode.pLink;
    while(pNode != NULL) {
        pPrevNode = pCurrentNode;
        pCurrentNode = pNode;
        pNode = pNode->pLink;
        pCurrentNode->pLink = pPrevNode;
    }
    pList->headerNode.pLink = pCurrentNode;
}
