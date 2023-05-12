// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Eunmin Kim
// ek22822
// Slip days used: <0>
// Spring 2023
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    for (int i=0;i<this->length;i++){
        if (this->data[i].name == name){
            return this->data[i];
        }
    }
    if (this->length < this->capacity){

    } else { // not enough capacity
        this->capacity = this->capacity * 2;
        Customer* temp = new Customer[this->capacity];
        for (int i=0;i<this->length;i++){
            temp[i] = this->data[i];
        }
        delete[] this->data;
        this->data = temp;
    }
    Customer c(name);
    this->data[this->length] = c;
    this->length++;
    return this->data[this->length-1];
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    for (int i=0;i<this->length;i++){
        if (this->data[i].name == name){
            return true;
        }
    }
    return false;
}
