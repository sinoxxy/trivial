#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 1000
int main(int argc, char *argv[] ) {
	if(argc < 2){
		 printf("not enought arguments");
		exit(EXIT_FAILURE);
	}
	else if(argc == 2){ //print stdin
		for(int i=0; i < strtol(argv[1],NULL,10) ;i++){ //array argv umformen
			int number =(rand() % MAXNUM );
			printf("%d \n",number);
		}
	}
	else if(argc == 3){ //write into file
		FILE* fp;

		fp = fopen(argv[2],"w");
		if(fp == NULL){
			printf("failed to open argv[2]");
		}
		else{
			for(int i=0; i < strtol(argv[1],NULL,10) ;i++){
				int number =(rand() % MAXNUM );
				fprintf(fp,"%d",number);
  	          	fputs("\n",fp);
			}
		}
		fclose(fp);
	}
}
