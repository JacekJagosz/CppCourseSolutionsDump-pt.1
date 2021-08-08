#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PersonalHeader(const char n_name[], const char n_surname[]){
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

    hours = local->tm_hour;      	// get hours since midnight (0-23)
    minutes = local->tm_min;     	// get minutes passed after the hour (0-59)
    seconds = local->tm_sec;     	// get seconds passed after minute (0-59)

    day = local->tm_mday;        	// get day of month (1 to 31)
    month = local->tm_mon + 1;   	// get month of year (0 to 11)
    year = local->tm_year + 1900;	// get year since 1900
	
	printf("---------------------------------\n");
	// print current date
	printf("Date : %02d/%02d/%d", day, month, year);
	
	// print local time
	if (hours < 12)	// before midday
		printf(" (%02d:%02d am)\n", hours, minutes);

	else	// after midday
		//printf("Time is : %02d:%02d:%02d pm\n", hours - 12, minutes, seconds);
		printf(" (%02d:%02d pm)\n", hours - 12, minutes);

	printf("%s %s\n", n_name, n_surname);
	printf("---------------------------------\n");

}
