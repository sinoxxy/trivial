/*
	Name: Aufgabe1.c
	Copyright: bk
	Author: Bastian Krug 
	Matrikelnummer: 7010891
	Date: 22.02.18 12:35
	Description: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ip_str2int (char *);

/*
Funktion main():  
�bergabeparameter: -------
R�ckgabeparameter: Integer
*/
int main(void)
{
	char ipString[20];
	int ipInt;
	
	printf("Geben sie die IP-Adresse ein:");
	fflush(stdin);
	gets(ipString);
	
	ipInt = ip_str2int(ipString);
	printf("\nIP als Dezimalzahl: %d",ipInt);
	printf("\nIP als Hexadezimalzahl: %X",ipInt);
	return(0);
}

/*
Funktion ip_str2int(): Konvertiert IP(String) in zugeh�rigen Integerwert  
�bergabeparameter: IP als String
R�ckgabeparameter: IP als Integer
*/
int ip_str2int (char *ipString)
{
	int ipInt = 0;
	
    return(ipInt);
}
