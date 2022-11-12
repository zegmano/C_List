#ifndef LIST_LIST_H
#define LIST_LIST_H

typedef struct  List_Node   {
    void                *vValue ;

    struct List_Node    *vNext  ;
    struct List_Node    *vPrev  ;
} TList_Node;

typedef struct  List        {
    struct List_Node    *vHead  ;
} TList;

void   L_Init   (TList *list)                           ; //Initialise     list

int    L_Add    (TList *list, void *vValue)             ; //Append data to end list
int    L_Set    (TList *list, void *vValue, long vAt)   ; //Modify data at position
int    L_Ins    (TList *list, void *vValue, long vAt)   ; //Insert data at position
void * L_Get    (TList *list, long vAt)                 ; //Get    data at position
int    L_Del    (TList *list, long vAt)                 ; //Delete data at position

long   L_Len    (TList *list)                           ; //Get size of list

#endif
