#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Funkcja inicjalizuje "len" kolejnych elementow tablicy wartoscia "wartosc"
 * tabPtr - wskaznik do 1 elementu tablicy który chcemy zmienic
 * size - ilosc elementow ktore chcemy zmienic
 * wartosc - wartosc na ktora chemy zmienic
 */
void InitializeTab1D(int *tabPtr, int size, int wartosc){
	for (int i=0; i<size; i++){
		*(tabPtr++)=wartosc;
	}
	return;
}

/* Wypisywanie co 100 wartosc z tablicy typu int
 * drugi argument to rozmiar tablicy
 */
void Print100VarTab1D(int *tabPtr, int size){
	for (int i=0; i<size; i+=100){
		printf("%d-element ma wartość: %d\n", i, *(tabPtr+i));
	}
	return;
}

/* Wyliczanie średnia harmoniczna znaków tablicy typu const int
 */
double HarmonicStaticCharAverageTab1D(char const *tabPtr){
	unsigned int len = strlen(tabPtr);
	double odwroconaSuma = 0;
	for (unsigned int i=0; i < len; i++){
		odwroconaSuma += 1./(*(tabPtr+i));
	}
	return len/odwroconaSuma;
}

/* Kopiowanie zawartości tablicy typu const char do tablicy typu char
 * UWAGA! tablica/ciag znaków musi byc zakonczony znakiem konca ciagu '\0' (jak string)
 */
void CopyCharTab1D(char *tabPtr,char const *origin){
	do{
		*(tabPtr++)=*(origin++);
	}while (*origin != '\0');
	return;
}

/* Odwracanie kolejnosci ciagu znaków w tablicy typu char
 * UWAGA! tablica/ciag znaków musi byc zakonczony znakiem konca ciagu '\0' (jak string)
 */
void InverseCharTab1D(char *tabPtr){
	int len=strlen(tabPtr);
	for (int i=0; i < (len-1)/2; i++){
		char temp = *(tabPtr+i);
		*(tabPtr+i) = *(tabPtr + len - i -1 );
		*(tabPtr + len - i -1) = temp;
	}
	return;
}
