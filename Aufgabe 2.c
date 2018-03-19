/*
	Name:  Aufgabe 2: Autostruct
	Copyright:9760129
	Author: 9760129
	Date: 22.02.18 13:25
	Description: 
*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
char init_car (char *marke, int *v_max, int *aut_park, int *tueren); //Funktionsprototyp zum erstellen eines Structs für ein Auto
int preis_calc (char * autos) // Funktionsprototyü zum ausrechnen des Autopreises


typedef struct car_t_struct //Struktur für die Autoeigenschaften
{
	char marke[81];
	int v_max;
	int aut_park; //automatisches parken: '0'-> nicht enthalten , '1' -> enthalten
	int tueren;
}car_t;
//car_t *car1;

int main (int argc, char *argv[])
{
	char return_car; //Rückgabewert aus ini_car
	// --- Manuelle Eingabewerte für die Funktion
	int vmax = 100;
	char marke[81];
	strcpy(marke,"VW");
	int aut_park = 1;
	int tueren = 5;
	// ---
	return_car = init_car (marke,&vmax,&aut_park,&tueren); //Rückgabewert von init_car Abfangen
	printf("%s\n%d\n%d\n%d");
	
	car_t autos[4]; //erstellen von 
	
	// Autos mit Daten bestücken
	strcpy(autos[0].marke, "Porsche");
	autos[0].v_max = 100;
	autos[0].aut_park = 0;
	autos[0].tueren = 5;
	
	strcpy(autos[1].marke, "VW");
	autos[1].v_max = 150;
	autos[1].aut_park = 1;
	autos[1].tueren = 5;
	
	strcpy(autos[2].marke, "Audi");
	autos[2].v_max = 220;
	autos[2].aut_park = 0;
	autos[2].tueren = 5;
	
	strcpy(autos[3].marke, "Mercedes");
	autos[3].v_max = 160;
	autos[3].aut_park = 1;
	autos[3].tueren = 5;
	
	// Preis ausrechnen
	

	
		
}

char init_car (char *cmarke, int *iv_max, int *iaut_park, int *itueren) //i und c vor den Variablen für die Unterscheidung zu den anderen (i und c -> Datentyp Indikator)
{
	car_t car1[1];
//	strcpy(car1->marke,cmarke);
	car1[1].v_max = *iv_max; //Übergebene Parameter in Die Struktur car1 schreiben
	car1[1].aut_park = *iaut_park;
	car1[1].tueren = *itueren;
	
	return (&car1); // Rückgabe der Struktur an int main
}

int preis_calc (char *autos) // Funktion zum ausrechen des Preises
{
	
}
