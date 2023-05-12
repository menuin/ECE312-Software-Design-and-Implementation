// SuperStrings <Project1.cpp>
// EE 312 Project 1 submission by
// Eunmin Kim
// ek22822
// Slip days used: <0>
// Spring 2023
// Copy-paste contents of this file at the top of every .c or .h file that you write or modify.


#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
#include <string.h>

/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/


bool compareStrings(char string1[], char string2[]){
  // check if string2 is superstring of string1
  int str_idx = 0;
  
  if (strlen(string2) < strlen(string1)){
    // if string2 is shorter than string1, string2 can never be superstring of string1
    return false;
  }
  
  for (int i=0;i<strlen(string2);i++){
    if (string1[str_idx] == string2[i]){
      str_idx++;
    }
    if (str_idx == strlen(string1)){
      // all letters in string1 are found in string2 which means string2 is a superstring of string1
      return true;
    }
  }
  
  return false;
  
}

int splitString(char string[], char array[5000][20]){
  // split string and store in the array
  char delimeters[] = " \t\n";
  char *next_str = strtok(string, delimeters);
 
  int i = 0;
  int str_count = 0; // store length of the array
  while (next_str != NULL){
    strcpy(array[i], next_str);
    next_str = strtok(NULL, delimeters);
    str_count++;
    i++;
  }
  return str_count;
}

void printSuperStrings(char targets [], char candidates []) {
  char strings[5000][20]; // array of strings in targets
  char superstrings[5000][20]; // array of strings in candidates
  
  int strings_len = splitString(targets, strings); // split targets
  int superstrings_len = splitString(candidates, superstrings); // split candidates
  
  for (int i=0; i<strings_len;i++){ 
    for (int j=0; j<superstrings_len;j++){
      // compare each string in the targets to candidates(superstring)
      if (compareStrings(strings[i],superstrings[j])){
        printf("%s\n",superstrings[j]); // print if superstring found
      }
    }
  }
}
