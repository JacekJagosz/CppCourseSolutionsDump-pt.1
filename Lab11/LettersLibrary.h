//
// Created by brachwal on 23.04.2020.
//

#ifndef LETTERS_LIBRARY
#define LETTERS_LIBRARY

#include "string.h"
#include "stdlib.h"
#include <stdio.h>
#include <ctype.h>

#define BUFOR_SIZE 100

// Deklaracje wyprzedzajace
int Included(char m_tab[], char m_char_of_interest);


// -----------------------------------------------------------------------------
// Set certain value to all elements / reset
void InitializeCounterTab1D(int m_tab[], int m_size, int m_value){
  printf("[INFO]:: InitializeCounterTab1D: for given size of %d and value %d\n",m_size,m_value);
  for (int i = 0; i < m_size; ++i)
    *m_tab++ = m_value;
}

// -----------------------------------------------------------------------------
void InitializeLettersTab1D(char m_tab[], int m_size){
  printf("[INFO]:: InitializeLettersTab1D: for given size of %d\n",m_size);
  for (int i = 0; i < m_size; ++i)
    m_tab[i] = 0;
}

// -----------------------------------------------------------------------------
// just for testing
void InputLettersTab1D(char m_tab[], const char* m_characters){
  printf("[INFO]:: InitializeLettersTab1D: for given string %s\n",m_characters);
  int current_char_idx = 0;
  char current_char = m_characters[current_char_idx];
  int nCharacters = strlen(m_tab);
  //printf("[DEBUG]:: nCharacters %d \n",nCharacters);

  while (current_char){
    if(Included(m_tab,current_char)==-1){ // -1 is the code for not existing entry
      m_tab[nCharacters]=tolower(current_char);
      //printf("[DEBUG]:: adding %c \n",m_tab[nCharacters]);
      m_tab[++nCharacters] = 0; // ascii code of NULL, keep this at the end, same as for strings
    }
    current_char = m_characters[++current_char_idx];
  }
}

// -----------------------------------------------------------------------------
//
void CountLetters(char m_letters[], int m_counters[], const char* m_characters){
  printf("[INFO]:: CountLetters: for given string %s\n",m_characters);
  int current_char_idx = 0;
  while (m_characters[current_char_idx]){
    char current_character = tolower(m_characters[current_char_idx]);
    int index = Included(m_letters,current_character);
    if (index==-1){
      puts("[WARNING]::CountLetters:: It seems that letters container was not initialized for given string to count:");
      printf("[INFO]:: Letters container: %s\n", m_letters);
      printf("[INFO]:: Letter to count: %c\n", current_character);
    }
    m_counters[index]+=1;
    current_char_idx++;
  }
}

// -----------------------------------------------------------------------------
//
void PrintLettersCounter(char m_letters[], int m_counters[]){
  printf("[INFO]:: PrintLettersCounter\n");
  int size = strlen(m_letters);
  for(int i=0;i<size;i++)
    printf("'%c' :: %d\n", m_letters[i], m_counters[i]);
}

// -----------------------------------------------------------------------------
// return index if found
int Included(char m_tab[], char m_char_of_interest){
  int index = 0;
  while(m_tab[index]!=0){
    if (m_tab[index] == m_char_of_interest)
      return index;
    index++;
  }
  return -1; // code for not existing value
}

// -----------------------------------------------------------------------------
// just for testing
void PrintCounterTab1D(int m_tab[], int m_size){
  puts("[INFO]:: PrintCounterTab1D:");
  for (int i = 0; i < m_size; ++i)
    printf("Counter[%2d] = %d\n",i,*m_tab++);
}

// -----------------------------------------------------------------------------
// just for testing
void PrintLettersTab1D(char m_tab[]){
  puts("[INFO]:: PrintLettersTab1D:");
  puts(m_tab);
}

#endif // LETTERS_LIBRARY