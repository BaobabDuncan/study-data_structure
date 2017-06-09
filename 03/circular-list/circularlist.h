//
// Created by sanguk on 05/06/2017.
//

#ifndef _CIRCULAR_LIST_
#define _CIRCULAR_LIST_

typedef struct CircularListNodeType{
    int data;
    struct CircularListNodeType *pLink;
}CircularListNode;

typedef struct CircularListType {
    int currentElementCount;
    CircularListNode headerNode;
}CircularList;


CircularList* createCircularList();
void deleteCircularList(CircularList* pList);
bool addElement(CircularList* pList, int position, CircularListNode element);
bool removeElement(CircularList* pList, int position);
void clearCircularList(CircularList* pList);
int getCircularListLength(CircularList* pList);
CircularListNode* getElement(CircularList* pList, int position);
void displayCircularList(CircularList* pList);


#endif //_CIRCULAR_LIST_
