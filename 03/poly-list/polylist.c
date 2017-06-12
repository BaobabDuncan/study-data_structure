//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#include "polylist.h"

int addPolyNodeLast(LinkedList* pList, float coef, int degree){
    ListNode node;
    node.coef = coef;
    node.degree = degree;
    addElement(pList, getLinkedListLength(pList), node);
}

LinkedList* polyAdd(LinkedList* pListA, LinkedList* pListB){
    LinkedList *pResult = NULL;
    ListNode *pNodeA = NULL, *pNodeB = NULL;
    if (pListA == NULL || pListB == NULL) return NULL;
    pResult = createLinkedList();
    pNodeA = pListA->headerNode.pLink;
    pNodeB = pListB->headerNode.pLink;
    while(pNodeA != NULL && pNodeB != NULL)
    {
        int degreeA = pNodeA->degree;
        int degreeB = pNodeB->degree;
        if (degreeA == degreeB){
            addPolyNodeLast(pResult, pNodeA->coef + pNodeB->coef, degreeA);
            pNodeA = pNodeA->pLink;
            pNodeB = pNodeB->pLink;
        } else if (degreeA > degreeB){
            addPolyNodeLast(pResult, pNodeA->coef, degreeA);
            pNodeA = pNodeA->pLink;
        } else {
            addPolyNodeLast(pResult, pNodeB->coef, degreeB);
            pNodeB = pNodeB->pLink;
        }
    }
    while(pNodeA != NULL) {
        addPolyNodeLast(pResult, pNodeA->coef, pNodeA->degree);
        pNodeA = pNodeA->pLink;
    }
    while(pNodeB != NULL) {
        addPolyNodeLast(pResult, pNodeB->coef, pNodeB->degree);
        pNodeB = pNodeB->pLink;
    }
    return pResult;
}

void displayPolyList(LinkedList* pList){
    printf("displayPolyList \n");
    if (pList == NULL) return;
    ListNode *pNode;
    for (int i = 0; i < getLinkedListLength(pList); i++){
        pNode = getElement(pList, i);
        printf("%4.1fx^%d", pNode->coef, pNode->degree);
        if (i == pList->currentElementCount - 1) {
            printf("\n");
        }
        else {
            printf(" + ");
        }
    }
}
