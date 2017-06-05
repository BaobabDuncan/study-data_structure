//
// Created by Administrator on 2017-06-04.
//
#include <stdio.h>
#include <stdlib.h>
#include "arraylist.h"


ArrayList *createArrayList(int maxElementCount) {
    ArrayList *pResult = NULL;
    pResult = (ArrayList *) malloc(sizeof(ArrayList));
    if (pResult == NULL) return NULL;
    pResult->pElement = (ArrayListNode *) malloc(sizeof(ArrayListNode) * maxElementCount);
    if (pResult->pElement == NULL) {
        free(pResult);
        return NULL;
    }
    pResult->currentElementCount = 0;
    pResult->maxElementCount = maxElementCount;
    return pResult;
}

void deleteArrayList(ArrayList *pList){
    if (pList==NULL) return;
    if (pList->pElement!=NULL){
        free(pList->pElement);
    }
    free(pList);
}

int isArrayListFull(ArrayList *pList) {
    int result = FALSE;
    if (pList != NULL) {
        if (getArrayListLength(pList) == pList->maxElementCount) {
            result = TRUE;
        }
    }
    return result;
}

int addElement(ArrayList *pList, int position, ArrayListNode element) {
    int result = FALSE;
    if (pList == NULL) return result;
    if (isArrayListFull(pList) == TRUE) return result;
    for (int i = getArrayListLength(pList) - 1; i >= position; i--) {
        pList->pElement[i + 1] = pList->pElement[i];
    }
    pList->pElement[position] = element;
    pList->currentElementCount++;
    return result;
}

int removeElement(ArrayList *pList, int position){
    int result = FALSE;
    if(pList==NULL) return result;
    for (int i = position + 1; i < getArrayListLength(pList); i++){
        pList->pElement[i - 1] = pList->pElement[i];
    }
    pList->currentElementCount--;
    return result;
}

ArrayListNode *getElement(ArrayList *pList, int position){
    ArrayListNode *pNode = NULL;
    if (pList==NULL) return pNode;
    pNode = (ArrayListNode *)malloc(sizeof(ArrayListNode));
    if (pNode==NULL) return pNode;
    *pNode = pList->pElement[position];
    return pNode;
}

void displayArrayList(ArrayList *pList) {
    if (pList == NULL) return;
    for (int i = 0; i < getArrayListLength(pList); i++) {
        printf("%d ", getElement(pList, i)->data);
    }
    printf("\n");
}

void clearArrayList(ArrayList *pList){
    if (pList!=NULL){
        pList->currentElementCount = 0;
    }
}

int getArrayListLength(ArrayList *pList) {
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}
