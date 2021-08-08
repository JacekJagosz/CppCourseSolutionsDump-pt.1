#ifndef DPERSON_LIBRARY
#define DPERSON_LIBRARY

#include "stdlib.h"
// ----------------------------------------------------------------------------
void DInitializePerson(char*** m_person){
  *m_person = malloc(2 * sizeof(char*));
  **m_person = NULL;
  *((*m_person)+1) = NULL;
}

// -----------------------------------------------------------------------------
void DSetName(char*** m_person, const char* m_name){
  **m_person = malloc(strlen(m_name)+1);
  strcpy(*m_person[0],m_name);
}

// -----------------------------------------------------------------------------
void DSetSurname(char*** m_person, const char* m_name){
  (*m_person)[1] = malloc(strlen(m_name)+1);
  strcpy(*(*m_person+1),m_name);
}

// -----------------------------------------------------------------------------
void DDeletePerson(char*** m_person){
  free(**m_person);
  free(*(*m_person+1));
  free(*m_person);
}

#endif // DPERSON_LIBRARY