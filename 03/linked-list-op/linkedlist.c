//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


LinkedList *createLinkedList() {
    LinkedList *pResult = NULL;
    pResult = (LinkedList *) malloc(sizeof(LinkedList));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(LinkedList));
    return pResult;
}

int addElement(LinkedList *pList, int position, ListNode element) {
    if (NULL == pList) return FALSE;
    ListNode *pNewNode, *pPreNode;
    pNewNode = (ListNode *) malloc(sizeof(ListNode));
    if (NULL == pNewNode) return FALSE;
    *pNewNode = element;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;

    return TRUE;
}

int removeElement(LinkedList *pList, int position){
    if (NULL == pList) return FALSE;
    ListNode *pDelNode, *pPreNode;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

ListNode *getElement(LinkedList *pList, int position){
    if (NULL == pList) return 0;
    ListNode *pNode;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++){
        pNode = pNode->pLink;
    }
    return pNode;
}

void clearLinkedList(LinkedList *pList){
    if(NULL == pList) return;
    while(getLinkedListLength(pList) > 0){
        removeElement(pList, 0);
    }
}

int getLinkedListLength(LinkedList *pList){
    if (NULL == pList) return 0;
    return pList->currentElementCount;
}

void deleteLinkedList(LinkedList *pList){
    if(NULL == pList) return;
    clearLinkedList(pList);
    free(pList);
}
