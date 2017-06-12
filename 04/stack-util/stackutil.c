//
// Created by sanguk on 12/06/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"
#include "stackutil.h"

char *reverseString(char *pSource) {
    LinkedStack *pStack = NULL;
    char *pReturn = NULL;
    pStack = createLinkedStack();
    StackNode node, *pNode;
    for (int i = 0; i < strlen(pSource); i++) {
        node.data = pSource[i];
        pushLS(pStack, node);
    }
    pReturn = (char *) malloc(sizeof(pSource));
    int i = 0;
    while (isLinkedStackEmpty(pStack) == FALSE) {
        pNode = popLS(pStack);
        pReturn[i] = pNode->data;
        free(pNode);
        i++;
    }
    deleteLinkedStack(pStack);
    return pReturn;
}

int checkBracketMatching(char *pSource) {
    int ret = TRUE;
    LinkedStack *pStack = createLinkedStack();
    StackNode node, *pNode;
    for (int i = 0; i < strlen(pSource); i++) {
        printf("%c ", pSource[i]);
        if (pSource[i] == '(' || pSource[i] == '{') {
            node.data = pSource[i];
            pushLS(pStack, node);
        } else if (pSource[i] == ')') {
            pNode = peekLS(pStack);
            if (pNode == NULL) {
                ret = FALSE;
                break;
            } else if (pNode->data != '(') {
                ret = FALSE;
                break;
            }
            pNode = popLS(pStack);
            free(pNode);
        } else if (pSource[i] == '}') {
            pNode = peekLS(pStack);
            if (pNode == NULL) {
                ret = FALSE;
                break;
            } else if (pNode->data != '{') {
                ret = FALSE;
                break;
            }
            pNode = popLS(pStack);
            free(pNode);
        }
    }
    if (isLinkedStackEmpty(pStack) == FALSE) {
        ret = FALSE;
    }
    free(pStack);
    return ret;
}