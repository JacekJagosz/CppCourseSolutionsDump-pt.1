#include "LettersLibrary.h"

char* PersonName(char* Osoba[]);
char* PersonSurname(char* Osoba[]);
int PersonNLetters(char* Osoba[]);

void PersonLetterCounter(char* Osoba[2]){
	int NumbersTab[14]; //zamiast 14 mogl zostac uzyty sizeof(), ale wtedy wartosc nie byla by znana podczas kompilacji
	InitializeCounterTab1D(NumbersTab, PersonNLetters(Osoba), 0);
	char LettersTab[14];
	InitializeLettersTab1D(LettersTab, PersonName(Osoba));
	InitializeLettersTab1D(LettersTab, PersonSurname(Osoba));
	CountLetters(LettersTab, NumbersTab, PersonName(Osoba));
	CountLetters(LettersTab, NumbersTab, PersonSurname(Osoba));
	PrintLettersCounter(LettersTab, NumbersTab);
	
	return;
}
int PersonNLetters(char* Osoba[]){
	 return strlen(PersonName(Osoba))+strlen(PersonSurname(Osoba));
 }
char* PersonName(char* Osoba[]){
	 return Osoba[0];
 }

char* PersonSurname(char* Osoba[]){
	 return Osoba[1];
 }
