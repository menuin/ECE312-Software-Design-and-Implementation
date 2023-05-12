// String ADT <Project3.cpp>
// EE 312 Project 3 submission by
// Eunmin Kim
// ek22822
// Slip days used: <0>
// Spring 2023
// Copy and paste this file at the top of all your submitted source code files.
// Do not turn this in by itself.


#include <assert.h>     //to provide assert()
#include <stdbool.h>    //to provide "bool" datatype (true or false)
#include <stdlib.h>     //dynamic allocation functions
#include <stdint.h>     //integer datatype with precise explicit width
#include <string.h>     //utility functions for string management
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    int length = strlen(src);
    UTString *s = (UTString*)malloc(sizeof(UTString));
    s->length = length;
    s->capacity = length;
    char *str = (char*)malloc(sizeof(char)*(length+5)); // room for string, null character(1byte), and check(4byte)
    s->string = str;
    for (int i=0;i<length;i++){
        str[i] = src[i];
    }
    str[length] = '\0';
    CHECK(s) = SIGNATURE;

    return s;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    assert(isOurs(s));
    return s->length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    assert(isOurs(s));
    char* str = s->string;
    int capacity = s->capacity;
    int added_length = 0;
    for (int i = s->length;i<capacity;i++){
        if (suffix[i-s->length] != '\0'){
            str[i] = suffix[i-s->length];
            added_length++;
        } else {
            break;
        }
    }
    s->length += added_length;
    str[s->length] = '\0';
    s->string = str;
    CHECK(s) = SIGNATURE;
    return s;
}

/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    assert(isOurs(dst));
    char* str = dst->string;
    int dst_capacity = dst->capacity;
    int src_length = strlen(src);
    int new_length = 0;
    for (int i=0;i<dst_capacity;i++){
        if (i<src_length){
            str[i] = src[i];
            new_length++;
        }
        else {
            str[i] = '\0';
        }
    }
    str[new_length] = '\0';
    dst->string = str;
    dst->length = new_length;
    CHECK(dst) = SIGNATURE;

    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    if (s->capacity < new_capacity){
        char* str = s->string;
        int str_length = s->length;
        char* new_str = (char*)malloc(sizeof(char)*(new_capacity+5));
        for (int i=0;i<str_length;i++){
            new_str[i] = str[i];
        }
        new_str[str_length] = '\0';
        s->string = new_str;
        s->capacity = new_capacity;
        CHECK(s) = SIGNATURE;
        free(str);
    }
    return s;
}
