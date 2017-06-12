#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

void displayArrayQueue(ArrayQueue *pQueue) {
    int i = 0;
    if (pQueue != NULL) {
        printf("maxElementCount: %d, currentElementCount: %d\n",
               pQueue->maxElementCount,
               pQueue->currentElementCount);
        for (i = pQueue->front + 1; i <= pQueue->rear; i++) {
            printf("[%d]-[%c]\n", i, pQueue->pElement[i].data);
        }
    }
}

int enqueueAQChar(ArrayQueue *pQueue, char data) {
    ArrayQueueNode node;
    node.data = data;
    enqueueAQ(pQueue, node);
}

int main(int argc, char *argv[]) {
    ArrayQueue *pQueue = NULL;
    ArrayQueueNode *pNode = NULL;

    pQueue = createArrayQueue(4);
    if (pQueue != NULL) {

        enqueueAQChar(pQueue, 'A');
        enqueueAQChar(pQueue, 'B');
        enqueueAQChar(pQueue, 'C');
        enqueueAQChar(pQueue, 'D');
        displayArrayQueue(pQueue);

        pNode = dequeueAQ(pQueue);
        if (pNode != NULL) {
            printf("Dequeue Value-[%c]\n",
                   pNode->data);
            free( pNode );
        }
        displayArrayQueue(pQueue);

        pNode = peekAQ(pQueue);
        if (pNode != NULL) {
            printf("Peek Value-[%c]\n",
                   pNode->data);
        }
        displayArrayQueue(pQueue);

        enqueueAQChar(pQueue, 'E');

        displayArrayQueue(pQueue);

        pNode = dequeueAQ(pQueue);
        if (pNode != NULL) {
            printf("Dequeue Value-[%c]\n",
                   pNode->data);
            free( pNode );
        }

        displayArrayQueue(pQueue);

        enqueueAQChar(pQueue, 'F');

        displayArrayQueue(pQueue);

        deleteArrayQueue(pQueue);

        displayArrayQueue(pQueue);
    }
    return 0;
}