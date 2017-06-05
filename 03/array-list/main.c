#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main() {

    ArrayList *pList = createArrayList(5);
    ArrayListNode node;
    if (pList!=NULL){
        node.data = 4;
        addElement(pList, 0, node);
        node.data = 3;
        addElement(pList, 1, node);
        node.data = 5;
        addElement(pList, 0, node);
        node.data = 6;
        addElement(pList, 1, node);
        displayArrayList(pList);
        removeElement(pList, 0);
        removeElement(pList, 2);
        displayArrayList(pList);
        clearArrayList(pList);
        displayArrayList(pList);
        deleteArrayList(pList);
        displayArrayList(pList);
    }
    return 0;
}