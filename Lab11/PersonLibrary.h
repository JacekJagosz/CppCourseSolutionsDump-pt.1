#ifndef PERSON_LIBRARY
#define PERSON_LIBRARY

#include "LettersLibrary.h"
#include <string.h>


// -----------------------------------------------------------------------------
//
int GetPersonNLetters(char* m_osoba[]){
	return strlen(m_osoba[0]) + strlen(m_osoba[1]);
}

// -----------------------------------------------------------------------------
//
char* GetPersonName(char* m_osoba[]){
	return m_osoba[0];
}

// -----------------------------------------------------------------------------
//
char* GetPersonSurname(char* m_osoba[]){
	return m_osoba[1];
}

// -----------------------------------------------------------------------------
//
void PersonLettersStatistic(char* m_osoba[]){

	char Letters[BUFOR_SIZE];
	int LCounter[BUFOR_SIZE];

	InitializeCounterTab1D(LCounter,GetPersonNLetters(m_osoba),0);

	// We have to initialize static array of char's with zeros!
	InitializeLettersTab1D(Letters,GetPersonNLetters(m_osoba));
    
    InputLettersTab1D(Letters,GetPersonName(m_osoba));
	InputLettersTab1D(Letters,GetPersonSurname(m_osoba));

	CountLetters(Letters,LCounter,GetPersonName(m_osoba));
	CountLetters(Letters,LCounter,GetPersonSurname(m_osoba));

	PrintLettersCounter(Letters,LCounter);
}

#endif // PERSON_LIBRARY