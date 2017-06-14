//
// Created by sanguk on 13/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simdef.h"
#include "simlinkedqueue.h"


LinkedQueue *createLinkedQueue(){
    LinkedQueue *pResult = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(LinkedQueue));
    return pResult;
}

int enqueueLQ(LinkedQueue *pQueue, QueueNode element){
    int ret = FALSE;
    if (NULL == pQueue) return ret;
    QueueNode *pNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (NULL == pNode) return ret;
    *pNode = element;
    pNode->pLink = NULL;
    if (TRUE == isLinkedQueueEmpty(pQueue)){
        pQueue->pFrontNode = pNode;
        pQueue->pRearNode = pNode;
    } else {
        pQueue->pRearNode->pLink = pNode;
        pQueue->pRearNode = pNode;
    }
    pQueue->currentElementCount++;
    ret = TRUE;
    return ret;
}

QueueNode *dequeueLQ(LinkedQueue *pQueue){
    if (NULL == pQueue) return NULL;
    if (TRUE == isLinkedQueueEmpty(pQueue)) return NULL;
    QueueNode *pNode;
    pNode = pQueue->pFrontNode;
    pQueue->pFrontNode = pQueue->pFrontNode->pLink;
    pNode->pLink = NULL;
    pQueue->currentElementCount--;
    if (isLinkedQueueEmpty(pQueue) == TRUE) {
        pQueue->pRearNode = NULL;
    }
    return pQueue->pFrontNode;
}

QueueNode *peekLQ(LinkedQueue *pQueue){
    if (NULL == pQueue) return NULL;
    if (TRUE == isLinkedQueueEmpty(pQueue)) return NULL;
    return pQueue->pFrontNode;
}

void deleteLinkedQueue(LinkedQueue *pQueue){
    if (NULL == pQueue) return;
    while(FALSE == isLinkedQueueEmpty(pQueue)){
        dequeueLQ(pQueue);
    }
    free(pQueue);
}

int isLinkedQueueFull(LinkedQueue *pQueue){
    return FALSE;
}

int isLinkedQueueEmpty(LinkedQueue *pQueue){
    int ret = FALSE;
    if (NULL == pQueue) return ret;
    if (0 == pQueue->currentElementCount){
        ret = TRUE;
    }
    return ret;
}
