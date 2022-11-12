#include <stdio.h>
#include "../src/List.h"

int main() {
    TList *myList = NULL; L_Init((TList *) &myList);

    L_Add((TList *) &myList, (void *) 1);
    L_Add((TList *) &myList, (void *) 20);
    L_Add((TList *) &myList, (void *) "3");
    L_Add((TList *) &myList, (void *) "4");

    //void *result = (void *) L_Get((TList*) &myList, 3);

    const char *str = (const char *) L_Get((TList*) &myList, 3);

    if(L_Del((TList *) &myList, 0) > 0) printf("error");
    L_Set((TList *) &myList, "4: sdf", 2);
    L_Ins((TList *) &myList, "1: enzo", 0);

    str = (const char *) L_Get((TList*) &myList, 0);
    printf("%s\n", str);


    long test = (long) L_Get((TList*) &myList, 1);
    printf("%ld\n", test);


    str = (const char *) L_Get((TList*) &myList, 2);
    printf("%s\n", str);
    str = (const char *) L_Get((TList*) &myList, 3);
    printf("%s\n", str);

    long len = (long) L_Len((TList *) &myList);
    printf("\n\nsize of list: %ld\n", len);
    return 0;
}
