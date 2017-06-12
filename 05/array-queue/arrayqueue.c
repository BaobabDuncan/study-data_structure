//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue.h"


ArrayQueue *createArrayQueue(int maxElementCount) {
    ArrayQueue *pResult = (ArrayQueue *) malloc(sizeof(ArrayQueue));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(ArrayQueue));
    pResult->pElement = (ArrayQueueNode *) malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if (NULL == pResult->pElement) {
        free(pResult);
        return NULL;
    }
    pResult->front = -1;
    pResult->rear = -1;
    pResult->maxElementCount = maxElementCount;
    return pResult;
}

int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element) {
    int ret = FALSE;
    if (pQueue == NULL) return ret;
    if (TRUE == isArrayQueueFull(pQueue)) return ret;
    pQueue->rear++;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    return ret;
}

ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue){
    ArrayQueueNode *pNode;
    if (pQueue == NULL) return pNode;
    if (TRUE == isArrayQueueEmpty(pQueue)) return pNode;
    pNode = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
    if (NULL == pNode) return pNode;
    pQueue->front++;
    pNode->data = pQueue->pElement[pQueue->front].data;
    pQueue->currentElementCount--;
    return pNode;
}

ArrayQueueNode *peekAQ(ArrayQueue *pQueue){
    ArrayQueueNode *pNode;
    if (pQueue == NULL) return pNode;
    if (TRUE == isArrayQueueEmpty(pQueue)) return pNode;
    return &(pQueue->pElement[pQueue->front + 1]);
}

void deleteArrayQueue(ArrayQueue *pQueue){
    ArrayQueueNode *pNode;
    if (pQueue == NULL) return;
    while (FALSE == isArrayQueueEmpty(pQueue)){
        pNode = dequeueAQ(pQueue);
        free(pNode);
    }
    free(pQueue);
}

int isArrayQueueFull(ArrayQueue *pQueue) {
    int ret = FALSE;
    if (pQueue == NULL) return ret;
    if (pQueue->currentElementCount == pQueue->maxElementCount) {
        ret = TRUE;
    }
    return ret;
}

int isArrayQueueEmpty(ArrayQueue *pQueue) {
    int ret = FALSE;
    if (pQueue == NULL) return ret;
    if (0 == pQueue->currentElementCount) {
        ret = TRUE;
    }
    return ret;
}