#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 500

int main( int argc, char *argv[] ){
	FILE *in = stdin;
	char buffer[255];

	if(argc > 2){
		printf("too many arguments");
		exit(EXIT_FAILURE);
	}
	if(argc == 2){
		in = fopen(argv[1], "r");
		if(!in){			// if the in cannot access 
			printf("cannot access pointer");
			exit(EXIT_FAILURE);
		}
	}
	while (fgets(buffer, sizeof(buffer), in)){
		//long l = strtol(buffer,NULL,10) * 2;			
		int l = atoi(buffer) * 2;			
		printf("%d\n",l);
	}
	
	
	if(in != stdin){
		fclose(in);
	}
}
