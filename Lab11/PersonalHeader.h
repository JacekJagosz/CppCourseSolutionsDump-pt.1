#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "PersonLibrary.h"

void PersonalHeader(char* m_person[]){
	// variables to store date and time components
	int hours, minutes, seconds, day, month, year;

	// time_t is arithmetic time type
	time_t now;
	
	// Obtain current time
	// time() returns the current time of the system as a time_t value
	time(&now);

	// localtime converts a time_t value to calendar time and 
	// returns a pointer to a tm structure with its members 
	// filled with the corresponding values
	struct tm *local = localtime(&now);

    day = local->tm_mday;        	// get day of month (1 to 31)
    month = local->tm_mon + 1;   	// get month of year (0 to 11)
    year = local->tm_year + 1900;	// get year since 1900
    const char* separator = "------------------------------------------";
    puts(separator);
	printf("[Autor] %s %s\n",GetPersonName(m_person), GetPersonSurname(m_person));
	printf(" [Date] %02d/%02d/%d\n", day, month, year);
	puts(separator);

}