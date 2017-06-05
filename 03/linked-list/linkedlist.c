//
// Created by sanguk on 05/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "linkedlist.h"

LinkedList* createLinkedList(){
    LinkedList *pResult;
    pResult = (LinkedList *)malloc(sizeof(LinkedList));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(LinkedList));
    return pResult;
}

bool addElement(LinkedList* pList, int position, LinkedListNode element){
    if (pList==NULL) return false;
    LinkedListNode *pPreNode;
    LinkedListNode *pNewNode;
    pNewNode = (LinkedListNode *)malloc(sizeof(LinkedListNode));
    if (pNewNode == NULL) return false;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    *pNewNode = element;
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    return true;
}

bool removeElement(LinkedList* pList, int position){
    if (pList==NULL) return false;
    LinkedListNode *pDelNode;
    LinkedListNode *pPreNode;
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

LinkedListNode* getElement(LinkedList* pList, int position){
    LinkedListNode *pNode;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++){
        pNode = pNode->pLink;
    }
    return pNode;
}

void clearLinkedList(LinkedList* pList){
    if (pList == NULL) return;
    while (getLinkedListLength(pList) > 0){
        removeElement(pList, 0);
    }
}

int getLinkedListLength(LinkedList* pList){
    if(pList == NULL) return 0;
    return pList->currentElementCount;
}
void deleteLinkedList(LinkedList* pList){
    if (pList == NULL) return;
    clearLinkedList(pList);
    free(pList);
}

void displayLinkedList(LinkedList* pList){
    printf("displayLinkedList\n");
    for (int i = 0; i < getLinkedListLength(pList); i++){
        printf("%d ",getElement(pList, i)->data);
    }
    printf("\n");
}