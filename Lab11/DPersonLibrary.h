#ifndef DPERSON_LIBRARY
#define DPERSON_LIBRARY

#include "stdlib.h"

// ----------------------------------------------------------------------------
void DInitializePerson(char*** m_person){
	return *m_person = calloc(2, sizeof(char*));
}

// -----------------------------------------------------------------------------
void DSetName(char*** m_person, const char* m_name){
	//(*m_person)[0] = m_name;
	(*m_person)[0] = malloc((strlen(m_name)+1) * sizeof(char));
	strcpy((*m_person)[0], m_name);
	return;
	}

// -----------------------------------------------------------------------------
void DSetSurname(char*** m_person, const char* m_name){
	//*(*m_person+1) = m_name;
	(*m_person)[1] = malloc((strlen(m_name)+1) * sizeof(char));
	int i=0;
	do{
		((*m_person)[1])[i]=m_name[i];
	}while(m_name[i++]);
	return;
	}

// -----------------------------------------------------------------------------
void DDeletePerson(char*** m_person){
	free((*m_person)[0]);
	free((*m_person)[1]);
	return free(*m_person);
	}

#endif // DPERSON_LIBRARY
