#include "List.h"

#include <stdio.h>
#include <stdlib.h>

void L_Init(TList *list) {
    list = (TList*) malloc(sizeof(TList));
    list->vHead = NULL;
}

int L_Add(TList *list, void *vValue) {
    TList_Node *vCurrent = (TList_Node *) list->vHead, *tempPrev = NULL, *node = (TList_Node *)malloc(sizeof(TList_Node));

    node->vValue    = (void *)  vValue    ;
    node->vNext     =           NULL      ;
    node->vPrev     =           NULL      ;

    if(list->vHead != NULL) {
        for (; vCurrent->vNext != NULL; tempPrev = vCurrent, vCurrent = vCurrent->vNext);
        vCurrent->vNext     = (TList_Node *) node       ;
        vCurrent->vPrev     = (TList_Node *) tempPrev   ;
        node    ->vPrev     = vCurrent                  ;
    } else list->vHead = (TList_Node *) node;

    return 0;
}

int L_Set(TList *list, void *vValue, long vAt) {
    TList_Node *vCurrent = (TList_Node *) list->vHead;

    if(vCurrent == NULL) return 1;

    if(vAt != 0) {
        long i = 0;
        do {
            if(vCurrent->vNext != NULL) vCurrent = vCurrent->vNext; else return 1;
            i++;
        } while (i != vAt);
    }
    vCurrent->vValue = (void *) vValue;

    return 0;
}

int L_Ins(TList *list, void *vValue, long vAt) {
    TList_Node *vCurrent = (TList_Node *) list->vHead, *tempPrev = (TList_Node *) vCurrent, *node = (TList_Node *)malloc(sizeof(TList_Node));

    if(vCurrent == NULL) return 1;

    node->vValue    = (void *)  vValue    ;
    node->vNext     =           NULL      ;
    node->vPrev     =           NULL      ;

    if (vAt != 0) {
        long i = 0;
        do {
            if(vCurrent->vNext != NULL) tempPrev = vCurrent, vCurrent = vCurrent->vNext; else return 1;
            i++;
        } while (i != vAt);

        node->vNext         = (TList_Node *) vCurrent       ;
        node->vPrev         = (TList_Node *) tempPrev       ;

        tempPrev->vNext     = (TList_Node *) node           ;
        vCurrent->vPrev     = (TList_Node *) node           ;
    } else node->vNext = (TList_Node *) list->vHead, list->vHead = (TList_Node *) node;

    return 0;
}

void *L_Get(TList *list, long vAt) {
    TList_Node *vCurrent = (TList_Node *) list->vHead;

    if(vCurrent == NULL) return (void *) NULL;

    if(vCurrent->vNext != NULL && vAt != 0) {
        long i = 0;
        do {
            if(vCurrent->vNext != NULL) vCurrent = vCurrent->vNext; else return (void *) NULL;
            i++;
        } while (i != vAt);

        return (void *) vCurrent->vValue;
    } else if(vAt == 0) return (void *) vCurrent->vValue;

    return (void *) NULL;
}

int L_Del(TList *list, long vAt) {
    TList_Node *vCurrent = (TList_Node *) list->vHead, *temp = (TList_Node *) vCurrent;

    if(vCurrent == NULL) return 1;

    if(vAt != 0) {
        long i = 0;
        do {
            if(vCurrent->vNext != NULL) {
                temp = (TList_Node *) vCurrent;
                vCurrent = vCurrent->vNext;
            } else return 1;
            i++;
        } while (i != vAt);
        temp->vNext = (TList_Node *) vCurrent->vNext;
    } else list->vHead = (TList_Node *) vCurrent->vNext;

    free((TList_Node *) vCurrent);
    return 0;
}

long L_Len(TList *list) {
    TList_Node *vCurrent = (TList_Node *) list->vHead;
    long i = 1;

    if(vCurrent != NULL) {
        for (; vCurrent->vNext != NULL; i++, vCurrent = vCurrent->vNext);
    } else i = 0;
    return i;
}