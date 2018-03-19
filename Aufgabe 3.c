/*
	Name: maycat
	Copyright: 9760129
	Author: 9760129
	Date: 22.02.18 14:03
	Description: 
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>


int mycat (int argc, char *argv[])
{
	FILE *f_point;
	f_point = fopen (argv[1],"r");
	
	if (argc == 0) //Abfangen, falls keine Parameter eingegeben wurden
	{
		Printf("Bitte Startparameter eingeben!");
	}
	if (argv[1] == "-h")
	{
		//Optionen
	}
	else if (argv[1] == "-n") // Zeilen nummerieren
	{
		
	}
	else if(argv[1] == "-E") //Abfangen von Parameter -E
	{
		printf("test");
		f_point = fopen (argv[1],"r");
//		fprintf(f_point,);
				
	}
}
