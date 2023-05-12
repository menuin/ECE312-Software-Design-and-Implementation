//
// Created by Menuin on 2023-04-19.
//

#include "DB.h"
#include <iostream>
#include <string>
#include "UTString.h"

using namespace std;

DB::DB(void){
    head = NULL;
    size = 0;
};

bool DB::isAvailable(UTString var){
    Node *crnt = head;
    while (crnt != NULL){
        if (crnt->var == var){
            return true;
        }
        crnt = crnt->next;
    }
    return false;
}

void DB::addNode(UTString var, int val){
    Node *node = new Node;
    node->var = var;
    node->val = val;
    node->next = head;
    head = node;
    size++;
}

void DB::setNode(UTString var, int val){
    Node *crnt = head;
    while (crnt != NULL){
        if (crnt->var == var){
            crnt->var = var;
            return;
        }
        crnt = crnt->next;
    }
    return;
}