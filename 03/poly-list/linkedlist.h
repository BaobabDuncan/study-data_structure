//
// Created by sanguk on 12/06/2017.
//

#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct ListNodeType
{
    float coef;
    int degree;
    struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
    int currentElementCount;
    ListNode headerNode;
} LinkedList;

LinkedList* createLinkedList();
int addElement(LinkedList* pList, int position, ListNode element);
int removeElement(LinkedList* pList, int position);
ListNode* getElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);
#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE		1
#define FALSE		0

#endif
