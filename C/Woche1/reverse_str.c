#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXITEMS 10000

int main( int argc, char *argv[] ){
	FILE *in = stdin;
	char buffer[255];
	char* list[MAXITEMS];

	if(argc > 2){
		printf("too many arguments");
		exit(EXIT_FAILURE);
	}
	if(argc == 2){
		in = fopen(argv[1], "r");
		if(!in){			// if the filepointer cannot access 
			printf("cannot access pointer");
			exit(EXIT_FAILURE);
		}
	}
	int i = 0;			
	while (fgets(buffer, sizeof(buffer), in)){ //stop when buffer is empty
		list[i] = malloc(strlen(buffer)); //dynamically asign storage for list entry
		strcpy(list[i], buffer); 
		i++;
	}
	//list[i]= '\0';
	for(int j = i-1;j >= 0; j--){
		printf("%s",list[j]);
		free(list[j]);
	}
		
	if(in != stdin){
		fclose(in);
	}

}