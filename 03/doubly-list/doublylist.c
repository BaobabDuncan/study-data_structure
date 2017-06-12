//
// Created by sanguk on 12/06/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"


DoublyList* createDoublyList(){
    DoublyList *pResult = NULL;
    pResult = (DoublyList *)malloc(sizeof(DoublyList));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(DoublyList));
    pResult->headerNode.pLLink = &(pResult->headerNode);
    pResult->headerNode.pRLink = &(pResult->headerNode);
    return pResult;
}

int addElement(DoublyList* pList, int position, DoublyListNode element){
    int result = FALSE;
    if (NULL == pList) return result;
    DoublyListNode *pPreNode, *pNewNode;

    pNewNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
    if (NULL == pNewNode) return result;
    *pNewNode = element;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pRLink;
    }
    pNewNode->pLLink = pPreNode;
    pNewNode->pRLink = pPreNode->pRLink;
    pPreNode->pRLink = pNewNode;
    pNewNode->pRLink->pLLink = pNewNode;
    pList->currentElementCount++;
    result = TRUE;
    return result;

}

int removeElement(DoublyList* pList, int position){
    int result = FALSE;
    if (NULL == pList) return result;
    DoublyListNode *pPreNode, *pDelNode;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pRLink;
    }
    pDelNode = pPreNode->pRLink;

    pPreNode->pRLink = pDelNode->pRLink;
    pDelNode->pRLink->pLLink = pPreNode;
    free(pDelNode);
    pList->currentElementCount--;
    result = TRUE;
    return result;

}

void deleteDoublyList(DoublyList* pList){
    if (NULL == pList) return;
    clearDoublyList(pList);
    free(pList);
}

void clearDoublyList(DoublyList* pList){
    if (NULL == pList) return;
    while(getDoublyListLength(pList) > 0){
        removeElement(pList, 0);
    }
}

int getDoublyListLength(DoublyList* pList){
    if (NULL == pList) return 0;
    return pList->currentElementCount;
}

DoublyListNode* getElement(DoublyList* pList, int position){
    if (NULL == pList) return NULL;
    DoublyListNode *pNode;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++){
        pNode = pNode->pRLink;
    }
    return pNode;

}

void displayDoublyList(DoublyList* pList){
    printf("displayDoublyList\n");
    for (int i = 0; i < getDoublyListLength(pList); i++){
        printf("%d ", getElement(pList, i)->data);
    }
    printf("\n");
}