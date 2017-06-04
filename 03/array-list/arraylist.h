//
// Created by Administrator on 2017-06-04.
//

#ifndef _ARRAY_LIST_
#define _ARRAY_LIST_

typedef struct ArrayListNodeType{
    int data;
}ArrayListNode;

typedef struct ArrayListType{
    int maxElementCount;
    int currentElementCount;
    ArrayListNode *pElement;
}ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addElement(ArrayList* pList, int position, ArrayListNode element);
int removeElement(ArrayList* pList, int position);
ArrayListNode* getElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);


#endif //_ARRAY_LIST_

#ifndef _COMMON_
#define _COMMON_

#define TRUE 1
#define FALSE 0

#endif //_COMMON_

