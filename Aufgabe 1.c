/*
	Name: Aufgabe 1: IP-Adresse in Integer
	Copyright: 9760129
	Author: 9760129
	Date: 22.02.18 12:46
	Description: 
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
int ip_str2int (char*); // Wandelt IP-Adresse (string) in  eine INT-Zahl um

int main (int argc, char *argv[])
{
	char st_ip_adress[20]; //IP-Adresse als String
	long lo_ip_adress; //IP-Adresse als long
	printf("IP-Adresse eingeben: ");
	fflush(stdin);
	gets(st_ip_adress); // einlesen der IP-adresse
	lo_ip_adress = ip_str2int(st_ip_adress); //aufrufen Funktion und speichern in variable lo_ip_adress (IP als Int)
return 0;	
}

int ip_str2int (char* st_ip)
{
	int i; //Zähvariable in FOR-Schleifen
	int ip_return = 0; //Rückgabewert an int_main
	int buffer = 0; //zwischenergebnis zwischen den Punkten in der IP-Adresse
//	char part[5];
	int zw_ergebnis = 0; 
	int part_count = 0; //Anzeige der derzeitigen Position in der IP-Adresse
	
	
	while (*st_ip != '\0' || *st_ip != '\n')
	{
		if (*st_ip == '.') // wenn ein Punkt gelesen wird, buffer zusammeaddieren und zum Rückgabewert hinzufügen
		{
			ip_return = ip_return + buffer;
			buffer = 0;
		}
		else // falls eine Zahl gelesen wird, diese in Buffer schreiben
		{
		zw_ergebnis = *st_ip * 10; // * 10, da der "Wert" der Zahlen in der Ip-Adresse immer um ein vielfaches steigt-> sonst kein richtiges Endergebnis
		buffer = buffer + zw_ergebnis;
		}
//		part_count++;
	}
//	printf("%s",st_ip);
//	printf("%c",part[0]);
	return (ip_return); // RÜckgabe der Ip-Adresse
}
