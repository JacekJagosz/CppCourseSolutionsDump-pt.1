
// WSTĘPNIAK
// Skompiluj poniższy progam i go uruchom
//    >> Przeanalizuj program zwracając uwagę na:
//    - czym rozni sie funkcja srednia() od tej z wcześniejszych zajęć?
//    - czy są tutaj obsłużone sytuacje wyjątkowe?
// 
// ZADANIE 1 (30 pkt)
// Na podstawie funkcji SredniaCommandlineWhile()
// zaimplementuj pozostałe funkcje:
//    - SredniaCommandlineDoWhile()
//    - SredniaCommandlineFor()
//    - SredniaCommandlineSwitch()
// które będą działać zupełnie analogicznie, jednak w każdej z nich
// będzie wykorzystany inny rodzaj pętli (odpowiednio do nazwy funkcji)
//  
// ZADANIE 2 (30 pkt)
// Wprowadź do programu obsługę sytuacji wyjatkowych.
// Podpowiedź: istotne jest poprawne obsłużenie danych wprowadzanych przez
// użytkownika programu (może on wprowadzać liczby, lub znaki 'q', 'Q')
// - co jeśli wprowadzi coś innego? 
// Można / należy wykorzystać EXIT_FAILURE
//
// ZAGADNIENIA
// I. instrukcje sterujące:
//    - for, while, do-while, switch
// II. obsługa sytuacji wujątkowych, exit(), EXIT_SUCCESS, EXIT_FAILURE


#include <stdio.h>
#include <stdlib.h>
#include "ctype.h"
#include <stdbool.h>

//////////////////////////////////////////////////////////////////
// Simple command line menu for average calculation
void SredniaCommandlineWhile();
void SredniaCommandlineDoWhile();
void SredniaCommandlineFor();
void SredniaCommandlineSwitch();

//////////////////////////////////////////////////////////////////
// Aritmetic average functor (it remembers the state itself)
float Srednia(float m_liczba);

/////////////////////////////////////////////////////////////////
// MAIN FUNCTION
int main()
{
  // Aby w danym momencie pracować nad konkretna (jedną) funkcją
  // zakomentuj wszystkie pozostałe wywołania, pozostaw tylko tę
  // nad którą chcesz pracować:
  SredniaCommandlineWhile();
  // SredniaCommandlineDoWhile();
  // SredniaCommandlineFor();
  // SredniaCommandlineSwitch();

  exit(EXIT_SUCCESS);
}

/////////////////////////////////////////////////////////////////
//
void SredniaCommandlineDoWhile(){
  puts("[INFO]: SredniaCommandlineWhile zostala wywolana:");
  char input[100];  // tablica na wprowadzanie danych. Uwaga: przechowujemy je jako napis
  do {
    printf("[INFO]: podaj liczbe do sredniej (q aby zakonczyc)\n");
    scanf("%s", input);
    if(isdigit(input[0]))            // sprawdzamy czy to zostało wprowadzone jest liczbą
      Srednia(atof(input));          // konwerujemy napis na liczbę typu float 
    else if(input[0]!='q' && input[0]!='Q'){				//kolejne 3 linie sa bardzo niepotrzebne
		printf("Wprowadzono nieprawidlowa liczbe");
		exit(EXIT_FAILURE);
	}
  }while (input[0]!='q' && input[0]!='Q');
  printf("[RESULT]: srednia wprowadzonych liczb: %3.3f \n",Srednia(0));
}

/////////////////////////////////////////////////////////////////
//
void SredniaCommandlineFor(){
  puts("[INFO]: SredniaCommandlineWhile zostala wywolana:");
  char input[100];  // tablica na wprowadzanie danych. Uwaga: przechowujemy je jako napis
  for ( ; input[0]!='q' && input[0]!='Q'; ){
    printf("[INFO]: podaj liczbe do sredniej (q aby zakonczyc)\n");
    scanf("%s", input);
    if(isdigit(input[0]))            // sprawdzamy czy to zostało wprowadzone jest liczbą
      Srednia(atof(input));          // konwerujemy napis na liczbę typu float 
    else if(input[0]!='q' && input[0]!='Q'){				//kolejne 3 linie sa bardzo niepotrzebne
		printf("Wprowadzono nieprawidlowa liczbe");
		exit(EXIT_FAILURE);
	}
  }
  printf("[RESULT]: srednia wprowadzonych liczb: %3.3f \n",Srednia(0));
}

/////////////////////////////////////////////////////////////////
//
void SredniaCommandlineSwitch(){
  puts("[INFO]: SredniaCommandlineWhile zostala wywolana:");
  char input[100];  // tablica na wprowadzanie danych. Uwaga: przechowujemy je jako napis
  while (true){
	switch(input[0]){
		case 'q':
			printf("[RESULT]: srednia wprowadzonych liczb: %3.3f \n",Srednia(0));
			goto loopDone;
		case 'Q':
			printf("[RESULT]: srednia wprowadzonych liczb: %3.3f \n",Srednia(0));
			goto loopDone;
		default:
			printf("[INFO]: podaj liczbe do sredniej (q aby zakonczyc)\n");
			scanf("%s", input);
			if(isdigit(input[0]))            // sprawdzamy czy to zostało wprowadzone jest liczbą
			Srednia(atof(input));          // konwerujemy napis na liczbę typu float 
			else if(input[0]!='q' && input[0]!='Q'){				//kolejne 3 linie sa bardzo niepotrzebne
				printf("Wprowadzono nieprawidlowa liczbe");
				exit(EXIT_FAILURE);
			}
			break;
		}
  }
  loopDone:;
  
}

/////////////////////////////////////////////////////////////////
//
void SredniaCommandlineWhile(){
  puts("[INFO]: SredniaCommandlineWhile zostala wywolana:");
  char input[100];  // tablica na wprowadzanie danych. Uwaga: przechowujemy je jako napis
  while (input[0]!='q' && input[0]!='Q'){
    printf("[INFO]: podaj liczbe do sredniej (q aby zakonczyc)\n");
    scanf("%s", input);
    if(isdigit(input[0]))            // sprawdzamy czy to zostało wprowadzone jest liczbą
      Srednia(atof(input));          // konwerujemy napis na liczbę typu float 
    else if(input[0]!='q' && input[0]!='Q'){				//kolejne 3 linie sa bardzo niepotrzebne
		printf("Wprowadzono nieprawidlowa liczbe");
		exit(EXIT_FAILURE);
	}
  }
  printf("[RESULT]: srednia wprowadzonych liczb: %3.3f \n",Srednia(0));
}

/////////////////////////////////////////////////////////////////
//
float Srednia(float m_liczba){
	static float licznik;
	static int n;
  if(m_liczba==0.){
    if (n==0) { //niestety uniemozliwia zresetowanie sredniej na poczatku
		printf("Zresetowano licznik ktory juz byl rowny zero");
		exit(EXIT_FAILURE);
	}
    float srednia = licznik/n; 
    licznik = n = 0;
    return srednia;
  }
  licznik+=m_liczba;
  return licznik/++n;
}
