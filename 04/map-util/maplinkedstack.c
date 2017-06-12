//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mapdef.h"
#include "maplinkedstack.h"

LinkedStack *createLinkedStack() {
    LinkedStack *pStack = (LinkedStack *) malloc(sizeof(LinkedStack));
    if (pStack == NULL) return NULL;
    memset(pStack, 0, sizeof(LinkedStack));
    return pStack;
}

int pushLS(LinkedStack *pStack, StackNode element) {
    int ret = FALSE;
    StackNode *pNewNode;
    if (NULL == pStack) return ret;
    pNewNode = (StackNode *) malloc(sizeof(StackNode));
    if (pNewNode == NULL) return ret;
    *pNewNode = element;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    ret = TRUE;
    return ret;
}

StackNode *popLS(LinkedStack *pStack) {
    StackNode *pNode;
    if (NULL == pStack) return NULL;
    if (TRUE == isLinkedStackEmpty(pStack)) return NULL;
    pNode = pStack->pTopElement;
    pStack->pTopElement = pNode->pLink;
    pNode->pLink = NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode *peekLS(LinkedStack *pStack) {
    if (NULL == pStack) return NULL;
    if (TRUE == isLinkedStackEmpty(pStack)) return NULL;
    return pStack->pTopElement;
}

void deleteLinkedStack(LinkedStack *pStack) {
    StackNode *pNode;
    if (NULL == pStack) return;
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
    if (NULL == pStack) return ret;
    if (pStack->currentElementCount == 0) {
        ret = TRUE;
    }
    return ret;
}
