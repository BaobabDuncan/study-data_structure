#include <stdio.h>
#include "doublylist.h"

int main() {
    int i = 0;
    int arrayCount = 0;
    DoublyList *pList = NULL;
    DoublyListNode *pValue = NULL;
    DoublyListNode node = {0,};

    pList = createDoublyList(6);
    if (pList != NULL)
    {
        node.data = 45;
        addElement(pList, 0, node);
        node.data = 3;
        addElement(pList, 1, node);
        node.data = 5;
        addElement(pList, 2, node);
        node.data = 8;
        addElement(pList, 3, node);
        node.data = 10;
        addElement(pList, 4, node);
        node.data = 2;
        addElement(pList, 0, node);
        node.data = 98;
        addElement(pList, 3, node);
        displayDoublyList(pList);

        removeElement(pList, 0);
        displayDoublyList(pList);

        removeElement(pList, 5);
        displayDoublyList(pList);

        deleteDoublyList(pList);

        displayDoublyList(pList);
    }
//    printf("1234\n");
    return 0;
}