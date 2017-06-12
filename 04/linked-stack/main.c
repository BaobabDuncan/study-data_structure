#include <stdio.h>
#include <stdlib.h>
#include "linkedstack.h"

void displayLinkedStack(LinkedStack *pStack)
{
    printf("displayLinkedStack\n");
    if (NULL == pStack) return;
    StackNode *pNode;
    pNode = pStack->pTopElement;
    while(pNode !=NULL){
        printf("[%c] ", pNode->data);
        pNode = pNode->pLink;
    }
    printf("\n");
}

int main() {
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;

    pStack = createLinkedStack();
    if (pStack != NULL) {
        StackNode node1 = {'A'};
        StackNode node2 = {'B'};
        StackNode node3 = {'C'};
        StackNode node4 = {'D'};

        pushLS(pStack, node1);
        pushLS(pStack, node2);
        pushLS(pStack, node3);
        pushLS(pStack, node4);
        displayLinkedStack(pStack);

        pNode = popLS(pStack);
        if (pNode != NULL)
        {
            printf("Pop-[%c]\n", pNode->data);
            free(pNode);
        }

        displayLinkedStack(pStack);


        pNode = peekLS(pStack);
        if (pNode != NULL) {
            printf("Peek-[%c]\n", pNode->data);
        }

        displayLinkedStack(pStack);

        deleteLinkedStack(pStack);

        displayLinkedStack(pStack);
    }
    return 0;
}