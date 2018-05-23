#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct linlist{
    char *payload;
    struct linlist *next;
}linlist_cell, *linlist_p ;

linlist_p anchor;
linlist_p *anchor_adr = &anchor;

void linlist_free_cell(linlist_p junk);
void linlist_free(linlist_p *junk);
linlist_p linlist_alloc_cell(char* payload);
linlist_p linlist_insert_first(linlist_p *anchor, linlist_p newcell);
linlist_p linlist_extract_first(linlist_p *anchor);


int main() {
    linlist_p i;

    char buffer[255];
    char reverse_buffer[255][255];
    FILE *in = stdin;
    printf("REVERSE INPUT\n");

    while (fgets(buffer, 255, in))
    {
        linlist_p newcell = linlist_alloc_cell(buffer);
        linlist_insert_first(anchor_adr,newcell);
    }
    printf("\nNORMAL OUTPUT\n");
    int j = 0;
    for (i = anchor; i != NULL; i = i->next)
    {
        fprintf(stdout, "%s", i->payload);
        strcpy(reverse_buffer[j], i->payload);
        j++;
    }
    printf("REVERSE OUTPUT\n");
    j--;
    for (j; j >= 0; j--)
    {
        fprintf(stdout, "%s", reverse_buffer[j]);
    }

    linlist_free(&anchor);
}


void linlist_free_cell(linlist_p junk)
{
    //free(junk->payload);
    //free(junk->next);
    free(junk);
}

void linlist_free(linlist_p *junk){

    if ((*junk)->next == NULL)
    {
        //printf("if: %s",(*junk)->payload);
        free(*junk);
        return;
    }
    else
    {
        //printf("else: %s",(*junk)->payload);
        linlist_free(&((*junk)->next));
        free(*junk);
    }
}

linlist_p linlist_alloc_cell(char* payload)
{
    linlist_p newcell = malloc(sizeof(linlist_p));
    char *value;
    //printf("%c\n",*payload);
    newcell->payload = strdup(payload);
    newcell->next = NULL;
    return (newcell);

}
linlist_p linlist_insert_first(linlist_p *anchor, linlist_p newcell)
{
    newcell->next = *anchor;
    *anchor = newcell;
    return(*anchor);

}
linlist_p linlist_extract_first(linlist_p *anchor)
{
    if (*anchor == NULL)
    {
        return NULL;
    }
    else
    {
        linlist_p *return_var;
        return_var = anchor;
        *anchor = (*anchor)->next;
        return (*return_var);
    }

}