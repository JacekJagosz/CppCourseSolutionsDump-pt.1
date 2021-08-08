// Suma punktów 35
//
// I. Zadanie (5 pkt)
//    Zaimplementuj funkcję Average() która będzie zwracać wartość sredniej
//    arytmetycznej dla dwóch przekazanych argumentów
//  
// II. Zadanie (15 pkt)
//    Utwórz 20 elementowa tablice liczb float, wg naspępujacych kroków
//    1. deklaracja oraz inicjalizacja: dwa ostatnie elementy wynoszą odpowiednio
//      15.5 oraz 99.9, pozostałe elementy wynoszą 0; 
//    2. wydruk tablicy na ekran
//    3. zmień elementy równe 0 iterując się po tablicy od końca (dokładnie od 3 elemtnu od końca)
//       a nowa wartość bieżącego elementu to średnia jego dwóch następnych sąsiadów:
//       a[i] = ( a[i+1] + a[i+2] ) / 2
//    4. wydruk tablicy na ekran
// 
//
// III. Zadanie (15 pkt)
//     Napisz funkcje, ktora porowna dwie liczby przekazane jako argumenty, oraz porównując
//     je ze sobą będzie zwracać większą wartość oraz zachowywać pomiędzy kolejnymi wywołaniami
//     największą dotychczas przekazaną wartość.  Dzieki temu można bedzie ją wykorzystać 
//     do szukania minimum z tablicy. Np. GetMaximum(a,b).
//     Wykorzystaj funkcję GetMaximum do znalezienia wartości maksymalnej tablicy z zadania II,
//     iterując się od końca tablicy!
//
//
//    UWAGA: wynik działania programu jest zapisany w pliku realarray.log

/////////////////////////////////////////////////////////////////////////////////////
// Preprocesor
#include "PersonalHeader.h" // zwróć uwagę że nie ma innych #include !!! Dlaczego?

#define SIZE 20

/////////////////////////////////////////////////////////////////////////////////////
float GetMaximum(float m_a, float m_b);

/////////////////////////////////////////////////////////////////////////////////////
float Average(float m_a, float m_b);

/////////////////////////////////////////////////////////////////////////////////////
// Main program
int main(void) {
	PersonalHeader("Jacek","Jagosz");
	float tLiczbowa[SIZE] = { [SIZE-2]=15.5, [SIZE-1]=99.9};
	
	puts("Moja tablica");
	for (int i=0; i<SIZE; i++){
		printf("%6.3f ", tLiczbowa[i]);
	}
	
	puts("\nMoja tablica (po zmianie)");
	for (int i=SIZE-3; i>=0; i--){
		tLiczbowa[i] = Average(tLiczbowa[i+1], tLiczbowa[i+2]);
	}
	for (int i=0; i<SIZE; i++){
		printf("%6.3f ", tLiczbowa[i]);
	}
	puts("\nSearching for maximum");
	for (int i=SIZE-2; i>=0; i--){
		printf("Local maximum %6.3f\n", GetMaximum(tLiczbowa[i], tLiczbowa[i+1]));
	}
	printf("Global maximum %6.3f\n", GetMaximum(0,0)); // sposób na wyciagnięcie wartości maximum z wszystkich wywołąń funkcji

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
float GetMaximum(float m_a, float m_b){
	static float gMax;
	if (m_a == m_b && m_a == 0)
		return gMax;
	float temp = m_a > m_b ? m_a : m_b;
	if (temp > gMax) gMax = temp;
	return temp;
}

/////////////////////////////////////////////////////////////////////////////////////
float Average(float m_a, float m_b){
	return ((m_a + m_b)/2);
}
