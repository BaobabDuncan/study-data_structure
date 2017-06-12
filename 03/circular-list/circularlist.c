//
// Created by sanguk on 05/06/2017.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "circularlist.h"

CircularList* createCircularList(){
    CircularList *pResult;
    pResult = (CircularList *)malloc(sizeof(CircularList));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(pResult));
    return pResult;
}

void deleteCircularList(CircularList* pList){
    if (pList == NULL) return;
    clearCircularList(pList);
    free(pList);
}

bool addElement(CircularList* pList, int position, CircularListNode element){
    if (pList == NULL) return false;
    CircularListNode *pPreNode;
    CircularListNode *pNewNode;
    pNewNode = (CircularListNode *)malloc(sizeof(CircularListNode));
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    *pNewNode = element;

    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;

    pList->currentElementCount++;
    if (position == 0){
        pPreNode = &(pList->headerNode);
        for (int i = 0; i < getCircularListLength(pList); i++){
            pPreNode = pPreNode->pLink;
        }
        pPreNode->pLink = pNewNode;
    }
    return true;
}

bool removeElement(CircularList* pList, int position){
    if (pList == NULL) return false;
    CircularListNode *pPreNode;
    CircularListNode *pDelNode;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;

    free(pDelNode);
    pList->currentElementCount--;

    return true;
}

void clearCircularList(CircularList* pList){
    if (pList==NULL) return;
    while (getCircularListLength(pList) > 0){
        removeElement(pList, 0);
    }
}

int getCircularListLength(CircularList* pList){
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

CircularListNode* getElement(CircularList* pList, int position){
    CircularListNode *pNode;
    if (pList == NULL) return NULL;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++){
        pNode= pNode->pLink;
    }
    return pNode;
}

void displayCircularList(CircularList* pList){
    printf("displayCircularList\n");
    CircularListNode *pNode;
    for (int i = 0; i < getCircularListLength(pList); i++){
        pNode = getElement(pList, i);
        printf("%d ", pNode->data);
    }
    printf("first node = %d", pNode->pLink->data);
    printf("\n");
}
