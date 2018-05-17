#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lin_list{
    char* payload;
    struct lin_list* next;
}LinListCell, *LinList_p;

LinList_p LinListAllocCell(char* payload);
void LinListFreeCell(LinList_p junk);
void LinListFree(LinList_p* junk);
LinList_p LinListInsertFirst(LinList_p* anchor, LinList_p newcell);
LinList_p LinListExtractFirst(LinList_p* anchor);


int main(int argc, char* argv[]){
    // init doublepointer and anchor
    LinList_p* anch_adr = NULL;
    LinList_p anchor = NULL;
    LinList_p newanchor = NULL;

    anch_adr = &anchor; 

    FILE* in = stdin;
    char buffer[255];
    if(argc > 2){
        printf("not enough arguments");
        exit(EXIT_FAILURE);
    }
    if(argc == 2){
        in = fopen(argv[1],"r");
        if(!in){
            printf("cannot open file");
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < 5; i++){
       fgets(buffer,sizeof(buffer),in);
       LinList_p newcell = LinListAllocCell(buffer);
       anchor = LinListInsertFirst(&anchor,newcell);
    }
    
    for(int i = 0; i < 3; i++){
    printf("REVERSE PRINT\n");
    while(anchor != NULL){
        printf("%s",anchor->payload);
        LinList_p tmp = LinListAllocCell(anchor->payload);
        newanchor = LinListInsertFirst(&newanchor,tmp);
        tmp = LinListExtractFirst(&anchor);
        LinListFreeCell(tmp);
    }

    printf("NORMAL PRINT\n");
    while(newanchor != NULL){
        printf("%s",newanchor->payload);
        LinList_p tmp = LinListAllocCell(newanchor->payload);
        anchor = LinListInsertFirst(&anchor,tmp);
        tmp = LinListExtractFirst(&newanchor);
        LinListFreeCell(tmp);
    }
    //LinListFree(&newanchor);
    //LinListFree(&anchor);
    }
}

LinList_p LinListAllocCell(char* payload){
    LinList_p newcell = malloc(sizeof(LinListCell));
    char* value = strdup(payload);
    
    newcell->payload = value;
    newcell->next = NULL;
    return newcell;
}

void LinListFreeCell(LinList_p junk){
    free(junk->payload);
    free(junk);
}

//not working
void LinListFree(LinList_p* junk){
    while((*junk)->next != NULL){
        //printf("String: %s \n",(*junk)->payload);
        LinList_p rest = *junk;
        junk = &(*junk)->next;
        free(rest);
    }
    *junk = NULL;
}

LinList_p LinListInsertFirst(LinList_p* anchor, LinList_p newcell){
    newcell->next = *anchor;
   *anchor = newcell;
   return *anchor;
}
LinList_p LinListExtractFirst(LinList_p* anchor){
    if(*anchor == NULL){
       return NULL;
   }
   LinList_p ret = *anchor;
   *anchor = ret->next;
   ret->next = NULL;
   return ret;
}