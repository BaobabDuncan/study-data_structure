//
// Created by sanguk on 05/06/2017.
//

#ifndef _LINKED_LIST_
#define _LINKED_LIST_

typedef struct LinkedListNodeType{
    int data;
    struct LinkedListNodeType *pLink;
}LinkedListNode;

typedef struct LinkedListType {
    int currentElementCount;
    LinkedListNode headerNode;
}LinkedList;

LinkedList* createLinkedList();
bool addElement(LinkedList* pList, int position, LinkedListNode element);
bool removeElement(LinkedList* pList, int position);
LinkedListNode* getElement(LinkedList* pList, int position);
void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
void displayLinkedList(LinkedList* pList);


#endif //_LINKED_LIST_
