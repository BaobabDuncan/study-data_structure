//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"


LinkedStack* createLinkedStack(){
    LinkedStack *pResult = NULL;
    pResult = (LinkedStack *)malloc(sizeof(LinkedStack));
    memset(pResult, 0, sizeof(LinkedStack));
    return pResult;
}

int pushLS(LinkedStack* pStack, StackNode element){
    int ret = FALSE;
    if (NULL == pStack) return ret;
    StackNode *pNewNode = NULL, *pPreNode;
    pNewNode = (StackNode *)malloc(sizeof(StackNode));
    if (NULL == pNewNode) return ret;
    *pNewNode = element;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    ret = TRUE;
    return ret;
}

StackNode* popLS(LinkedStack* pStack){
    StackNode *pNode = NULL;
    if (NULL == pStack) return NULL;
    if (TRUE == isLinkedStackEmpty(pStack)) return NULL;
    pNode = pStack->pTopElement;
    pStack->pTopElement = pNode->pLink;
    pNode->pLink = NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode* peekLS(LinkedStack* pStack){
    StackNode *pNode = NULL;
    if (NULL == pStack) return NULL;
    if (TRUE == isLinkedStackEmpty(pStack)) return NULL;
    pNode = pStack->pTopElement;
    return pNode;
}

void deleteLinkedStack(LinkedStack* pStack){
    if (NULL == pStack) return;
    StackNode *pDelNode = NULL;
    while(isLinkedStackEmpty(pStack) == FALSE){
        pDelNode = popLS(pStack);
        free(pDelNode);
    }
    free(pStack);
}

int isLinkedStackFull(LinkedStack* pStack){
    return FALSE;
}

int isLinkedStackEmpty(LinkedStack* pStack){
    int ret = FALSE;
    if (NULL == pStack) return ret;
    if (0 == pStack->currentElementCount) ret = TRUE;
    return ret;

}
