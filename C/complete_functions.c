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
LinList_p LinListInsertLast(LinList_p* anchor,LinList_p newcell);
LinList_p LinListExtractLast(LinList_p* anchor);
LinList_p LinListFind(LinList_p anchor,char* payload);
LinList_p LinListRevert(LinList_p* anchor, LinList_p prev);
LinList_p LinListSort(LinList_p* anchor);
LinList_p LinListUselessRevert(LinList_p* anchor);
LinList_p LinListExtract(LinList_p* anchor,LinList_p cell);
LinList_p LinListInsertFirst2(LinList_p* anchor, LinList_p newcell);
LinList_p LinListInsert(LinList_p* anchor, LinList_p cell);
void printList(LinList_p anchor);
int n = 0;

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
    //LinListFree(&newanchor);
    //LinListFree(&anchor);
    anchor = LinListRevert(&anchor,NULL);
    //LinList_p = anchor;
    anchor = LinListSort(&anchor);

    {
        printf("asdasd");
    }
    //char* teststr = "7\n";
    //LinList_p newcellll = LinListAllocCell(teststr);
    //anchor = LinListInsertLast(&anchor,newcellll);
    //char* teststtr = "19";
    //LinList_p newcelllla = LinListAllocCell(teststtr);
    //anchor = LinListInsertLast(&anchor,newcelllla);
	//newcellll = LinListExtractLast(&anchor);
    //printf("\n newcellll payload:%s",newcellll->payload);
    //newcelllla =  LinListExtract(&anchor,newcelllla);
    //printf("Revert: %s",(*anchor)->payload);
    //printf("%s",anchor->payload);
    // LinList_p tmp = LinListAllocCell((*anchor).payload);
    // //extrahieren - doppelter pointer auf anchor uebergeben
    // //              element wird enfernt und zurueckgegeben
    // tmp = LinListExtractLast(&anchor); //anchor oder &newanchor
    // //anchor wird schon bei extract weiter gesetzt
    // anchor = LinListInsertFirst(&anchor,tmp);
    char* teststr = "2\n";
    //LinList_p testing = LinListFind(anchor,teststr);
    //printf("%s",testing->payload);
    // tmp = LinListAllocCell((*anchor).payload);
    // //extrahieren - doppelter pointer auf anchor uebergeben
    // //              element wird enfernt und zurueckgegeben
    // tmp = LinListExtractLast(&anchor); //anchor oder &newanchor
    // //anchor wird schon bei extract weiter gesetzt
    // anchor = LinListInsertFirst(&anchor,tmp);
    
    printList(anchor);    

	//anchor = *anch_adr;
	//newcellll = LinListExtractLast(&anchor);
    //newcellll = LinListFind(anchor,teststr);
    //}
}

void printList(LinList_p anchor){
    printf("\nAUSGABE\n");
	while(anchor != NULL){
		printf("%s",anchor->payload);
		anchor = anchor->next;
	} 
}

LinList_p LinListAllocCell(char* payload){
    LinList_p newcell = malloc(sizeof(LinListCell));
    newcell->payload = strdup(payload);
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
				LinListFreeCell(rest);
        //free(rest);
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

// "append"
LinList_p LinListInsertLast(LinList_p* anchor,LinList_p newcell){
	LinList_p tmp = *anchor;
    while(*anchor != NULL && (*anchor)->next != NULL){ //bis zum letzten listenelement springen
        anchor = &(*anchor)->next;
    }
    (*anchor)->next = newcell;
    return tmp;
}

LinList_p LinListExtractLast(LinList_p* anchor){
    //neue zelle zeigt nun auf die zelle
    if(*anchor == NULL){
        return NULL;
    }
    if((*anchor)->next == NULL){ //wenn liste nur ein element hat
        *anchor = NULL;
    }
    while(*anchor != NULL & (*anchor)->next != NULL){ //springe bis letztes element
        anchor = &(*anchor)->next;
    }   //anchor beinhaltet jetzt die adresse von der letzten zelle.
    LinList_p junk = *anchor;
    junk->next = NULL; //nextpointer auf 0 setzten
	//remove element
	*anchor = NULL;
    return junk;
}

LinList_p LinListFind(LinList_p anchor, char* payload){
    while(anchor != NULL && strcmp(strdup((*anchor).payload), payload) != 0){ //pointer nicht null und das element
        //printf("%d \n",strcmp(strdup((*anchor).payload), payload));
        //printf("test");
        anchor = anchor->next;
        
    }
    if(anchor != NULL){
        printf("Found: %s",(*anchor).payload);
        return anchor;
    }
    else{
        return NULL;
    } 
}

LinList_p LinListUselessRevert(LinList_p* anchor){
    if(n == 5){
        return *anchor;
    }
    n++;
    printf("Revert: %s",(*anchor)->payload);
    LinList_p tmp = LinListAllocCell((*anchor)->payload);
    tmp = LinListExtractLast(anchor);
    *anchor = LinListInsertFirst(anchor,tmp);
    printf("beginning: %s",(*anchor)->payload);
    return LinListUselessRevert(anchor);
}

LinList_p LinListRevert(LinList_p* anchor,LinList_p prev){ 
    if((*anchor)->next == NULL){
        (*anchor)->next = prev;
        return *anchor;
    }
    else{
        LinList_p tmp = (*anchor)->next;
        (*anchor)->next = prev;
        return LinListRevert(&tmp,*anchor);
    }
}

LinList_p LinListInsert(LinList_p* anchor, LinList_p cell){
    LinList_p* test = anchor;
    LinList_p* tmp = anchor;
    LinList_p prev = NULL;
    while(*test != NULL){
        if(strcmp((*test)->payload,cell->payload) > 0){
            break;
        }
        else{
            prev = *test;
        }
		test = &(*test)->next;
	}
    LinList_p tmp2 = prev->next;
    prev->next = cell;
    cell->next = tmp2;
    return *tmp;
}

LinList_p LinListSort(LinList_p* anchor){
    LinList_p tmp = NULL;
	LinList_p head = *anchor;
    LinList_p abcd = NULL;	
	while(*anchor != NULL&& (*anchor)->next !=NULL){
        tmp = (*anchor)->next;
        if(strcmp((*anchor)->payload,tmp->payload) > 0){
			abcd = LinListExtract(&head,*anchor);
            abcd = LinListInsert(&head,abcd);
            return LinListSort(&head);
		}
		anchor = &(*anchor)->next;
	}
    return head;
}

LinList_p LinListExtract(LinList_p* anchor,LinList_p cell){
    if(*anchor == NULL){
        printf("liste ist leer");
        return NULL;
    }
    if((*anchor)->next == NULL){ //wenn liste nur ein element hat
        if(*anchor == cell){
            return NULL;
        }
        else{
            printf("element nicht in der liste enthalten");
            return *anchor;
        }
    }
    if(*anchor == cell){
        LinList_p ret = LinListExtractFirst(anchor);
        return ret;
    }
    
    while(*anchor != NULL && (*anchor)->next != cell){ //springe bis letztes element
        anchor = &(*anchor)->next;
    }  
    LinList_p tmp = *anchor;
    if((*anchor)->next == cell){ //zelle gefunden

        tmp->next = cell->next;
        cell->next = NULL;
        return cell;
    }
    else{ //keine zelle gefunden
        return NULL;
    }
}
