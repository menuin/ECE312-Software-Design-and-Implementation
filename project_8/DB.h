//
// Created by Menuin on 2023-04-19.
//

#ifndef PROJECT_8_DB_H
#define PROJECT_8_DB_H

#include <iostream>
#include <string>
#include "UTString.h"

using namespace std;

 struct Node {
    int val;
    UTString var;
    Node* next;
};

class DB {
private:
    Node *head;
    int size;


public:
    DB(void);
    bool isAvailable(UTString var);
    Node* findVar(UTString var);
    void addNode(UTString var, int val);
    void setNode(UTString var, int val);
};

#endif //PROJECT_8_DB_H

