//
// Created by sanguk on 13/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkeddeque.h"


LinkedDeque *createLinkedDeque() {
    LinkedDeque *pResult = (LinkedDeque *) malloc(sizeof(LinkedDeque));
    if (NULL == pResult) return NULL;
    memset(pResult, 0, sizeof(LinkedDeque));
    return pResult;
}

int insertFrontLD(LinkedDeque *pDeque, DequeNode element) {
    int ret = FALSE;
    if (NULL == pDeque) return ret;
    DequeNode *pNode = (DequeNode *) malloc(sizeof(DequeNode));
    if (NULL == pNode) return ret;
    *pNode = element;
    pNode->pLLink = NULL;
    pNode->pRLink = NULL;
    if (TRUE == isLinkedDequeEmpty(pDeque)) {
        pDeque->pFrontNode = pNode;
        pDeque->pRearNode = pNode;
    } else {
        pDeque->pFrontNode->pLLink = pNode;
        pNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode = pNode;
    }
    pDeque->currentElementCount++;
    return ret;
}

int insertRearLD(LinkedDeque *pDeque, DequeNode element) {
    int ret = FALSE;
    if (NULL == pDeque) return ret;
    DequeNode *pNode = (DequeNode *) malloc(sizeof(DequeNode));
    if (NULL == pNode) return ret;
    *pNode = element;
    pNode->pLLink = NULL;
    pNode->pRLink = NULL;
    if (TRUE == isLinkedDequeEmpty(pDeque)) {
        pDeque->pFrontNode = pNode;
        pDeque->pRearNode = pNode;
    } else {
        pDeque->pRearNode->pRLink = pNode;
        pNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode = pNode;
    }
    pDeque->currentElementCount++;
    return ret;
}

DequeNode *deleteFrontLD(LinkedDeque *pDeque) {
    if (NULL == pDeque) return NULL;
    if (TRUE == isLinkedDequeEmpty(pDeque)) return NULL;
    DequeNode *pNode;
    pNode = pDeque->pFrontNode;
    pDeque->pFrontNode = pNode->pRLink;
    pNode->pRLink = NULL;
    pDeque->currentElementCount--;
    if (isLinkedDequeEmpty(pDeque) == TRUE) {
        pDeque->pRearNode = NULL;
    } else {
        pDeque->pFrontNode->pLLink = NULL;
    }
    return pNode;
}

DequeNode *deleteRearLD(LinkedDeque *pDeque) {
    if (NULL == pDeque) return NULL;
    if (TRUE == isLinkedDequeEmpty(pDeque)) return NULL;
    DequeNode *pNode;
    pNode = pDeque->pRearNode;
    pDeque->pRearNode = pNode->pLLink;
    pNode->pLLink = NULL;
    pDeque->currentElementCount--;
    if (isLinkedDequeEmpty(pDeque) == TRUE) {
        pDeque->pFrontNode = NULL;
    } else {
        pDeque->pRearNode->pRLink = NULL;
    }
    return pNode;
}

DequeNode *peekFrontLD(LinkedDeque *pDeque) {
    if (NULL == pDeque) return NULL;
    if (TRUE == isLinkedDequeEmpty(pDeque)) return NULL;
    return pDeque->pFrontNode;
}

DequeNode *peekRearLD(LinkedDeque *pDeque) {
    if (NULL == pDeque) return NULL;
    if (TRUE == isLinkedDequeEmpty(pDeque)) return NULL;
    return pDeque->pRearNode;
}

void deleteLinkedDeque(LinkedDeque *pDeque) {
    DequeNode *pNode;
    if (NULL == pDeque) return;
    while (FALSE == isLinkedDequeEmpty(pDeque)) {
        pNode = deleteRearLD(pDeque);
        free(pNode);
    }
    free(pDeque);
}

int isLinkedDequeFull(LinkedDeque *pDeque) {
    return FALSE;
}

int isLinkedDequeEmpty(LinkedDeque *pDeque) {
    int ret = FALSE;
    if (NULL == pDeque) return ret;
    if (0 == pDeque->currentElementCount) {
        ret = TRUE;
    }
    return ret;
}