//
// Created by Menuin on 2023-04-19.
//
#include <iostream>
#include "Input.cpp"
#include "Parse.h"
#include "UTString.h"
#include "DB.h"

using namespace std;
DB db;

void set(){
    read_next_token();
    UTString var(next_token());
    if (db.isAvailable(var)){
        read_next_token();
        int val = token_number_value;
        db.setNode(var, val);
    } else {
        cout << "variable " << var.c_str() << " not declared" << endl;
    }
}
void var(){
    read_next_token();
    UTString var(next_token());
    if (db.isAvailable(var)){
        cout << "variable " << var.c_str() << " incorrectly re-initialized" << endl;
        read_next_token();
        int val = token_number_value;
        db.setNode(var, val);
    } else {
        read_next_token();
        int val = token_number_value;
        db.addNode(var, val);
    }

}
void output(){

}
void text(){
    read_next_token();
    cout << next_token();
}
void run(){
    read_next_token();
    while (next_token_type != END){
        UTString keyword(next_token());
        if (keyword == "text"){
            text();
        } else if (keyword == "output"){
            output();
        } else if (keyword == "var"){
            var();
        } else if (keyword == "set"){
            set();
        } else if (keyword == "//"){
            skip_line();
        }
        read_next_token();
    }
}
int main(void){
//    cout << "Test 1" << endl;
//    set_input("TestCases/proj8/test1.blip");
//    run();
//
//    cout << "Test 2" << endl;
//    set_input("TestCases/proj8/test2.blip");
//    run();
//
//    cout << "Test 3" << endl;
//    set_input("TestCases/proj8/test3.blip");
//    run();
//
//    cout << "Test 4" << endl;
//    set_input("TestCases/proj8/test4.blip");
//    run();
    set_input("test_grader.blip");
    run();
}