//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"

ArrayStack *createArrayStack(int maxElementCount){
    ArrayStack *pResult = NULL;
    pResult = (ArrayStack *) malloc(sizeof(ArrayStack));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(ArrayStack));
    pResult->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode) * maxElementCount);
    if (NULL == pResult->pElement) {
        free(pResult);
        return NULL;
    }
    pResult->maxElementCount = maxElementCount;
    return pResult;
}

int pushAS(ArrayStack *pStack, ArrayStackNode element){
    if (NULL == pStack) return FALSE;
    if (TRUE == isArrayStackFull(pStack)) return FALSE;
    pStack->pElement[pStack->currentElementCount] = element;
    pStack->currentElementCount++;
    return TRUE;
}

ArrayStackNode *popAS(ArrayStack *pStack){
    ArrayStackNode *pNode = NULL;
    if (NULL == pStack) return NULL;
    if (TRUE == isArrayStackEmpty(pStack)) return NULL;
    pNode = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
    *pNode = pStack->pElement[pStack->currentElementCount - 1];
    pStack->currentElementCount--;
    return pNode;
}

ArrayStackNode *peekAS(ArrayStack *pStack){
    ArrayStackNode *pNode = NULL;
    if (NULL == pStack) return NULL;
    if (TRUE == isArrayStackEmpty(pStack)) return NULL;
    pNode = &(pStack->pElement[pStack->currentElementCount - 1]);
    return pNode;
}

void deleteArrayStack(ArrayStack *pStack){
    ArrayStackNode *pNode;
    while(pStack->currentElementCount > 0){
        pNode = popAS(pStack);
        free(pNode);
    }
    free(pStack);
}

int isArrayStackFull(ArrayStack *pStack){
    int ret = FALSE;
    if (NULL == pStack) return ret;
    if (pStack->currentElementCount == pStack->maxElementCount){
        ret = TRUE;
    }
    return ret;
}

int isArrayStackEmpty(ArrayStack *pStack){
    int ret = FALSE;
    if (NULL == pStack) return ret;
    if (pStack->currentElementCount == 0){
        ret = TRUE;
    }
    return ret;
}
