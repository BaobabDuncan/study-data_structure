#include <stdio.h>
#include <stdlib.h>
#include "arraystack.h"

void displayArrayStack(ArrayStack *pStack){
    printf("displayArrayStack\n");
    for (int i = pStack->currentElementCount - 1; i >= 0; i--){
        printf("%c ", pStack->pElement[i].data);
    }
    printf("\n");

}

int main(){
    ArrayStack *pStack = NULL;
    ArrayStackNode *pNode = NULL;

    pStack = createArrayStack(6);
    if (pStack != NULL) {
        ArrayStackNode node1 = {'A'};
        ArrayStackNode node2 = {'B'};
        ArrayStackNode node3 = {'C'};
        ArrayStackNode node4 = {'D'};

        pushAS(pStack, node1);
        pushAS(pStack, node2);
        pushAS(pStack, node3);
        pushAS(pStack, node4);
        displayArrayStack(pStack);

        pNode = popAS(pStack);
        if (pNode != NULL) {
            printf("Pop [%c]\n", pNode->data);
            free(pNode);
        }
        displayArrayStack(pStack);

        pNode = peekAS(pStack);
        if (pNode != NULL) {
            printf("Peek [%c]\n", pNode->data);
        }

        displayArrayStack(pStack);

        deleteArrayStack(pStack);

        displayArrayStack(pStack);
    }
    return 0;
}