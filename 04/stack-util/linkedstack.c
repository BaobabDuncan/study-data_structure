//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"


LinkedStack *createLinkedStack() {
    LinkedStack *pResult = NULL;
    pResult = (LinkedStack *) malloc(sizeof(LinkedStack));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(LinkedStack));
    return pResult;
}

int pushLS(LinkedStack *pStack, StackNode element) {
    int ret = FALSE;
    if (pStack == NULL) return ret;
    StackNode *pNode;
    pNode = (StackNode *) malloc(sizeof(StackNode));
    if (pNode == NULL) return ret;
    *pNode = element;
    pNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNode;
    pStack->currentElementCount++;
    return ret;
}

StackNode *popLS(LinkedStack *pStack) {
    if (pStack == NULL) return NULL;
    if (isLinkedStackEmpty(pStack) == TRUE) return NULL;
    StackNode *pNode;
    pNode = pStack->pTopElement;
    pStack->pTopElement = pNode->pLink;
    pNode->pLink == NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode *peekLS(LinkedStack *pStack) {
    if (pStack == NULL) return NULL;
    if (isLinkedStackEmpty(pStack) == TRUE) return NULL;
    return pStack->pTopElement;
}

void deleteLinkedStack(LinkedStack *pStack) {
    if (pStack == NULL) return;
    StackNode *pNode;
    while (isLinkedStackEmpty(pStack) == FALSE) {
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
    if (pStack == NULL) return ret;
    if (pStack->currentElementCount == 0) {
        ret = TRUE;
    }
    return ret;
}
