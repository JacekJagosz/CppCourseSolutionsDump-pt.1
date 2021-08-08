// ZADANIE 3 (40 pkt)
// Napisz program liczący pierwiastek kwadratowy metodą Newtona
// - opis algorytmu znajduje się poniżej
// - zaimplementuj odpowiednio dwie funkcje które realizują ten algorytm,
//   które będą wykorzystywać pętle: do while oraz while, czyli:
//      - SqRootNewtonWhile(float x)
//      - SqRootNewtonDoWhile(float x)
// - Dodaj odpowiedni licznik, aby sprawdzić ile iteracji jest wykonywanych
// - Wynik działania programu jest zapisany w pliku SqRootNewton.log

// ZAGADNIENIA
// - isntrukcje sterujace w programie
// - zadanie algorytmiczne

//////////////////////////////////////////////////////////////////////
// METODA NEWTONA NA OBLICZANIE PIERWIASTKA KWADRATOWEGO            //
// 1. pierwiastek (x)                                               //
// 2. stała określająca dokładność: epsilon = 0.0001f               //
// 3. punkt począstkowy (połowa wartości) wynik = x / 2;            //
// 4. wykonujemy tyle iteracji, aby otrzymać rozsądne przybliżenie: //
//    powtarzaj: wynik = (wynik + x / wynik) / 2                    //
//    dopóki: dopóty (abs(x - wynik*wynik) < epsilon )              //
// 5. zwróc wynik                                                   //
// uwaga: funckja abs() zwraca wartość bezwględną przekazanego arg  //
//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h> // aby mieć możliwość skorzystać z abs()

/////////////////////////////////////////////////////////////////
//
float EPSILON = 0.00001f; // zmienna globalna do określenia dokładnosci obliczeń

/////////////////////////////////////////////////////////////////
//
float SqRootNewtonWhile(float m_liczba);
float SqRootNewtonDoWhile(float m_liczba);

/////////////////////////////////////////////////////////////////
// MAIN FUNCTION
int main()
{
    float x = 1043.234;
    puts("[INFO]:: Metoda SqRootNewtonWhile");
    printf("[INFO]:: Pierwiastek z %.3f to %0.5f\n",x, SqRootNewtonWhile(x));
    puts("");
    puts("[INFO]:: Metoda SqRootNewtonDoWhile");
    printf("[INFO]:: Pierwiastek z %.3f to %0.5f\n",x, SqRootNewtonDoWhile(x));

    return 0;
}

/////////////////////////////////////////////////////////////////
//
float SqRootNewtonWhile(float m_liczba){
    float wynik = m_liczba / 2;
    int powtorzenia = 0;
    while(abs( m_liczba - wynik*wynik ) >= EPSILON ){
		wynik = (wynik + m_liczba / wynik) / 2;
		powtorzenia++;
	}
	printf("[SqRootNewtonWhile]:: #%d interacji\n", powtorzenia);
    return wynik;
}

/////////////////////////////////////////////////////////////////
//
float SqRootNewtonDoWhile(float m_liczba){
    float wynik = m_liczba / 2;
    int powtorzenia = 0;
    do{
		wynik = (wynik + m_liczba / wynik) / 2;
		powtorzenia++;
	}while(abs( m_liczba - wynik*wynik ) >= EPSILON );
	printf("[SqRootNewtonDoWhile]:: #%d interacji\n", powtorzenia);
    return wynik;
}
