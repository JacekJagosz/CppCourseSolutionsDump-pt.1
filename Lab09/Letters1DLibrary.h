#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void InitializeCounterTab1D(int *tabPtr, int size, int wartosc){
	for (int i=0; i<size; i++){
		*(tabPtr++)=wartosc;
	}
	return;
}

void PrintIntTab1D(int *tabPtr, int size){
	for (int i=0; i<size; i++){
		printf("%d-element ma wartość: %d\n", i, *(tabPtr+i));
	}
	return;
}

void InitializeLettersTab1D(char *TabWynikowa, const char *TabOryg){
	//printf("%d, %d\n",sizeof(TabWynikowa), sizeof(TabOryg));
	char *Wyn = TabWynikowa;
	
	while(*TabOryg){
		Wyn = TabWynikowa;
		printf("%c",*TabOryg);
		int PowtarzaSie=0;
		while(*Wyn++){
			//putchar(*(Wyn));
			if(*Wyn == (tolower(*TabOryg))){
				PowtarzaSie=1;
				puts("Tak");
				//break 2;
			}
			putchar((tolower(*TabOryg)));
			//Wyn++;
		}
		if(PowtarzaSie == 0){
			*(Wyn-1)=(tolower(*TabOryg));
			printf("%ld\n", Wyn-TabWynikowa);
			*(Wyn)='\0';
		}
		TabOryg++;
	}
	return;
}

void CountLetters(char *Letters, int *LCounter, const char *TabOryg){
	while(*Letters){
		const char *Oryg = TabOryg;
		while(*Oryg){
			if(*Letters == (tolower(*Oryg)))
				(*LCounter)++;
			Oryg++;
		}
		
		Letters++;
		LCounter++;
	}
	return;
}

void PrintLettersCounter(char *Letters, int *LCounter){
	int i=0;
	while(*(Letters+i)){
		printf("%c :: %d\n", *(Letters+i), *(LCounter+i));
		i++;
	}
	return;
}
