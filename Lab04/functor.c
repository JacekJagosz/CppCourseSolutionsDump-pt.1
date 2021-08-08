// ZAGADNIENIA
// 0. Zmienna statyczna, inkrementacja, dekrementacja
// 1. Idea sytuacji wyjątkowych w programie, możliwe rozwiązania, debugowanie
//    (--> Materiały uzupełniajace)
//
// ZADANIE (40 pkt)
// 1. Skompiluj poniższy progam i go uruchom
//      - czy działa on poprawnie?
//      - podpowiedź: chodzi o liczenie średniej arytmetycznej.
// 2. Napraw działanie poniższego programu - debugowanie 
// 3. Zaimplementuj funkcjonalność resetowania functora,
//    np. poprzez wyłowanie Average(0);
// 4. Wynik działania końcowego programu podany jest w pliku
//    functor.log
//    - proszę zrócić uwagę na formatowanie wyjścia!
//    - jeśli zacommitowane rozwiązanie będzie się różnić = 0 pkt
//
// ---------------------------------------------------------------
// Osoba wykonująca ćwiczenie:
// Imie: Jacek
// Nazwisko: Jagosz
// ---------------------------------------------------------------


#include <stdio.h>

//////////////////////////////////////////////////////////////////
// Aritmetic average functor (it remembers the state itself)
float Average(float m_liczba);

/////////////////////////////////////////////////////////////////
// MAIN FUNCTION  
int main() {
  printf("current average value = %05.2f \n", Average(0.5));
  Average(0); // TODO: reset;
  printf("current average value = %05.3f \n", Average(0.5));
  printf("current average value = %05.3f \n", Average(2.5));
  printf("current average value = %05.3f \n", Average(6.0));
  printf("current average value = %05.3f \n", Average(0));
  return 0;
}

/////////////////////////////////////////////////////////////////
//
float Average(float m_liczba){
	static float srednia;
	static int n;
	if(m_liczba == 0){
		srednia = n = 0;
		return 0;
	}
	//srednia*=n;
	srednia+=m_liczba;
	return srednia/++n;
}
