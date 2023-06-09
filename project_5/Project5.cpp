// Set <Project5.cpp>
// EE 312 Project 5 submission by
// Eunmin Kim
// ek22822
// Slip days used: <0>
// Spring 2023
// Copy-Paste the above lines at the top of your submitted files.


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */



/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}
bool binary_search(int* list, int len, int target){
    int start = 0;
    int end = len-1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (list[mid] == target){
            return true;
        }
        else if (list[mid] > target){
            end = mid-1;
        }
        else if (list[mid] < target){
            start = mid + 1;
        }
    }
    return false;
}
/* return true if x is an element of self */
bool isMemberSet(const Set* self, int x) {
    int len = self->len;
    return binary_search(self->elements, len, x);
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elemnts[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
void insertSet(Set* self, int x) {
    if (!isMemberSet(self, x)){
        int old_len = self->len;
        int *new_elements = (int*)malloc(sizeof(int)*(old_len+1));
        int insert_index = 0;
        for (int i =0; i<old_len; i++){
            if (self->elements[i] < x){
                insert_index = i+1;
            }
        }
        for (int i=0;i<insert_index;i++){
            new_elements[i] = self->elements[i];
        }
        new_elements[insert_index] = x;
        for (int i=insert_index;i<old_len;i++){
            new_elements[i+1] = self->elements[i];
        }
        self->len = old_len+1;
        free(self->elements);
        self->elements = new_elements;
    }
}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
int get_index(Set* self, int x){
    for (int i=0; i<self->len;i++){
        if (self->elements[i] == x){
            return i;
        }
    }
    return 0;
}
void removeSet(Set* self, int x) {
    if(isMemberSet(self, x)){
        int index = get_index(self, x);
        for (int i=index;i<self->len-1;i++){
            self->elements[i] = self->elements[i+1];
        }
        self->elements[self->len-1] = '\0';
        self->len--;
    }
}

/* done for you already */
void displaySet(const Set* self) {
    int k;

    printf("{");

    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    if (self->len != other->len){
        return false;
    }
    for (int i = 0; i<self->len; i++){
        if (self->elements[i] != other->elements[i]){
            return false;
        }
    }
    return true;
}

/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    if (isEmptySet(self)){
        return true;
    }
    if (self->len > other->len){
        return false;
    }
    int self_index = 0;
    for (int i=0;i<other->len;i++){
        if (self->elements[self_index] == other->elements[i]){
            self_index++;
        }
        if (self_index == self->len){
            return true;
        }
    }
    return false;
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    if (isEmptySet(self) || isEqualToSet(self, other)){
        return;
    }
    int* new_list = (int*)malloc(sizeof(int)*self->len);
    int other_index = 0;
    int index = 0;
    int i;
    for (i=0;i<self->len;i++){
        if (other_index >= other->len){
            break;
        }
        if (self->elements[i] == other->elements[other_index]){
            new_list[index] = self->elements[i];
            index++;
            other_index++;
        }
        else if (self->elements[i] > other->elements[other_index]){
            other_index++;
            i--;
        }

    }

    free(self->elements);
    self->elements = new_list;
    self->len = index;
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    if (isEmptySet(self) || isEmptySet(other)){
        return;
    }
    int* new_list = (int*)malloc(sizeof(int)*self->len);
    int other_index = 0;
    int index = 0;
    int i;
    for (i=0;i<self->len;i++){
        if (other_index >= other->len){
            break;
        }
        if (self->elements[i] == other->elements[other_index]) {
            other_index++;
        }
        else if (self->elements[i] < other->elements[other_index]){
            new_list[index] = self->elements[i];
            index++;
        }
        else {
            other_index++;
            i--;
        }
    }
    while (i < self->len){
        new_list[index] = self->elements[i];
        i++;
        index++;
    }
    free(self->elements);
    self->elements = new_list;
    self->len = index;
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    int* new_list = (int*)malloc(sizeof(int)*(self->len + other->len));

    int self_index = 0;
    int other_index = 0;
    int index = 0;
    while (self_index < self->len && other_index < other->len){
        if (self->elements[self_index] == other->elements[other_index]){
            new_list[index] = self->elements[self_index];
            index++;
            self_index++;
            other_index++;
        }
        else if (self->elements[self_index] > other->elements[other_index]){
            new_list[index] = other->elements[other_index];
            index++;
            other_index++;
        }
        else {
            new_list[index] = self->elements[self_index];
            index++;
            self_index++;
        }
    }

    while (self_index < self->len){
        new_list[index] = self->elements[self_index];
        index++;
        self_index++;
    }
    while (other_index < other->len){
        new_list[index] = other->elements[other_index];
        index++;
        other_index++;
    }
    free(self->elements);
    self->elements = new_list;
    self->len = index;
}
