# List v1.0.0:

> ## Introduction
> 
> This library is just an entrinement project but can be used easily because this library symplifies list creation in some function call, it is scalable and can contain almost any type of data.
> #### Information of creator:
> ```YAML
> Author:   Enzo BOITTE
> Email:    developers@apiged.fr 
> Language: French
> ```
> 
> #### Function of library:
> ```c
> void   L_Init (TList *list)                           ; //Initialise     list
> 
> int    L_Add  (TList *list, void *vValue)             ; //Append data to end list
> int    L_Set  (TList *list, void *vValue, long vAt)   ; //Modify data at position
> int    L_Ins  (TList *list, void *vValue, long vAt)   ; //Insert data at position
> void * L_Get  (TList *list, long vAt)                 ; //Get    data at position
> int    L_Del  (TList *list, long vAt)                 ; //Delete data at position
>
> long   L_Len  (TList *list)                           ; //Get size of list
> ```

> ## Presentation
> 
> Include the library `List.h`and create your variable and for finish call the init function `L_Init`:
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   return 0;
> }
> ```
> 
> If you want to add data in your list, call the function `L_Add`
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   L_Add((TList *) &myList, (void *) 1);
>   L_Add((TList *) &myList, (void *) "helloworld !");
> 
>   return 0;
> }
> ```
> 
> If you want to get data at position in your list, call the function `L_Get`
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   ...
> 
>   long        number  = (long)         L_Get((TList*) &myList, 0);
>   const char *str     = (const char *) L_Get((TList*) &myList, 1);
> 
>   return 0;
> }
> ```
> 
> If you want to remove data at position in your list, call the function `L_Del`
> 
> (when the function returns 1 there is an error otherwise it returns 0.)
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   ...
> 
>   if(L_Del((TList *) &myList, 0) > 0) printf("error");
> 
>   return 0;
> }
> ```
>
> If you want to set data at position (for modified data) in your list, call the function `L_Set`
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   ...
> 
>   L_Set((TList *) &myList, "test", 1);
> 
>   return 0;
> }
> ```
>
> If you want to insert data at position (between two data) in your list, call the function `L_Ins`
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   ...
> 
>   L_Ins((TList *) &myList, "test", 1); //after position 0 and before position 1, the data in position 1 changes to position 2.
> 
>   return 0;
> }
> ```
> 
> And for finish if you want to get size of your list, call the function `L_Len`
> ```c
> #include "List.h"
>
> int main() {
>   TList *myList = NULL; L_Init((TList *) &myList);
> 
>   ...
> 
>   long len = (long) L_Len((TList *) &myList);
>   printf("size of list: %ld\n", len);
> 
>   return 0;
> }
> ```
