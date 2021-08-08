// Suma punktów 35
// 
// I. Zadanie (20 pkt).
//    Proszę tak przerobić funkcję PersonalHeader() aby wynikiem jej działania
//    był odpowiedni wydruk (wg poniższego przykładu):
//    ---------------------------------
// 	  Date : 03/03/2020 (14:34 pm)
//    Imie i Nazwisko
//    ---------------------------------
//    
// 	  Oczywiście za imie i nazwiko są podstawione Pani/a dane.
//
// II. Zadanie (15 pkt).
//    Proszę napisać funkcję Round() która jako argument będzie przyjmować
//    liczbę typu float oraz zwracać liczbę całkowitą będącą zaokrągleniem
//	  przekazanago argumentu z dokładnością do 0.5
// 	  Z wykorzystaniem tej funkcji, oraz pętli for (10 iteracji) proszę uzyskać
//	  wydruk taki sam jaki jest zapisany w pliku log
//	  Uwaga: Implementacja wywołania tego wydruku nie może być dłuższa niż dwa 
//    wiersze instrukcji!!!!
//
//	Uwaga: ostateczny program ma w wyniku drukować zarówno wynik działania
//  	   funkcji PersonalHeader() oraz for + Round
//  Uwaga: naturalnie, godzina z wywoływania Państwa programu będzie
// 		   różna od tej zapisanej w pliku round.log



#include <stdio.h>
#include "PersonalHeader.h"

/////////////////////////////////////////////////////////////////
//  implement me.
int Round(float);

/////////////////////////////////////////////////////////////////
// MAIN FUNCTION
int main() {
	PersonalHeader("Jacek","Jagosz");
  	for (float i=0 ; i < 1; i+=0.1){
		
		printf("%.2f %05d\n", i, Round(i));
	}
	/* Oczywiście można też tak:
	for (int i=0 ; i < 10; i++){
		float f= 0.1 * i;
		printf("%.2f %05d\n", f, Round(f));
	}*/
  	return 0;
}


/////////////////////////////////////////////////////////////////
// implement me.
int Round(float d){
	return (d+0.5);
}
