//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprlinkedstack.h"

LinkedStack *createLinkedStack() {
    LinkedStack *pResult = (LinkedStack *) malloc(sizeof(LinkedStack));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(LinkedStack));
    return pResult;
}

int pushLS(LinkedStack *pStack, StackNode element){
    int ret = FALSE;
    if (NULL == pStack) return ret;
    StackNode *pNewNode;
    pNewNode = (StackNode *)malloc(sizeof(StackNode));
    if (pNewNode == NULL) return ret;
    *pNewNode = element;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    ret = TRUE;
    return ret;
}

StackNode *popLS(LinkedStack *pStack){
    if (NULL == pStack) return NULL;
    if (TRUE == isLinkedStackEmpty(pStack)) return NULL;
    StackNode *pNode;
    pNode = pStack->pTopElement;
    pStack->pTopElement = pNode->pLink;
    pNode->pLink = NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode *peekLS(LinkedStack *pStack){
    if (NULL == pStack) return NULL;
    if (TRUE == isLinkedStackEmpty(pStack)) return NULL;
    return pStack->pTopElement;
}

void deleteLinkedStack(LinkedStack *pStack){
    if (NULL == pStack) return;
    StackNode *pNode;
    while (isLinkedStackEmpty(pStack) == FALSE){
        pNode = popLS(pStack);
        free(pNode);
    }
    free(pStack);
}

int isLinkedStackFull(LinkedStack *pStack) {
    return FALSE;
}

int isLinkedStackEmpty(LinkedStack *pStack) {
    int ret = FALSE;
    if (NULL == pStack) return ret;
    if (0 == pStack->currentElementCount) {
        ret = TRUE;
    }
    return ret;
}
