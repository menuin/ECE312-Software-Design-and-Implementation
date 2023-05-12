// CRM <Project4.cpp>
// EE 312 Project 4 submission by
// Eunmin Kim
// ek22822
// Slip days used: <0>
// Spring 2023
// Copy-Paste the above lines at the top of your submitted files.


#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;
int num_bottles = 0;
int num_diapers = 0;
int num_rattles = 0;
/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */
String bottles = StringCreate("Bottles");
String diapers = StringCreate("Diapers");
String rattles = StringCreate("Rattles");

/* clear the inventory and reset the customer database to empty */
void reset(void) {
	// clear inventory
    num_bottles = 0;
    num_diapers = 0;
    num_rattles = 0;
    // reset the customer database
    for (int i=0; i<num_customers;i++){
        customers[i].bottles = 0;
        customers[i].diapers = 0;
        customers[i].rattles = 0;
        StringDestroy(&customers[i].name);
    }
    num_customers = 0;
}
int findCustomer(String *customer){ // find customer index from customer database
    for (int i=0;i<num_customers;i++){
        if (StringIsEqualTo(customer, &customers[i].name)){
            return i;
        }
    }
    return -1;
}
void checkRattles(){
    int max_rattles = 0;
    int customer_idx = -1;
    for (int i=0;i<num_customers;i++){
        if(customers[i].rattles > max_rattles){
            max_rattles = customers[i].rattles;
            customer_idx = i;
        }
    }

    if (max_rattles == 0 ){
        printf("no one has purchased any Rattles\n");
    } else {
        StringPrint(&customers[customer_idx].name);
        printf(" has purchased the most Rattles (%d)\n", max_rattles);
    }
}
void checkDiapers(){
    int max_diapers = 0;
    int customer_idx = -1;
    for (int i=0;i<num_customers;i++){
        if(customers[i].diapers > max_diapers){
            max_diapers = customers[i].diapers;
            customer_idx = i;
        }
    }

    if (max_diapers == 0 ){
        printf("no one has purchased any Diapers\n");
    } else {
        StringPrint(&customers[customer_idx].name);
        printf(" has purchased the most Diapers (%d)\n", max_diapers);
    }
}
void checkBottles(){
    int max_bottles = 0;
    int customer_idx = -1;
    for (int i=0;i<num_customers;i++){
        if(customers[i].bottles > max_bottles){
            max_bottles = customers[i].bottles;
            customer_idx = i;
        }
    }

    if (max_bottles == 0 ){
        printf("no one has purchased any Bottles\n");
    } else {
        StringPrint(&customers[customer_idx].name);
        printf(" has purchased the most Bottles (%d)\n", max_bottles);
    }
}
void processSummarize() {
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n", num_bottles, num_diapers, num_rattles);
    printf("we have had a total of %d different customers\n",num_customers);

    checkBottles();
    checkDiapers();
    checkRattles();
}

void processPurchase() {
    String customer;
    String item;
    int amount;
    int customer_idx;

    readString(&customer);
    readString(&item);
    readNum(&amount);

    if (StringIsEqualTo(&item, &bottles) && num_bottles < amount ){
        printf("Sorry ");
        StringPrint(&customer);
        printf(", we only have %d Bottles\n", num_bottles);
        StringDestroy(&customer);
        StringDestroy(&item);
        return;
    } else if (StringIsEqualTo(&item, &diapers) && num_diapers < amount){
        printf("Sorry ");
        StringPrint(&customer);
        printf(", we only have %d Diapers\n", num_diapers);
        StringDestroy(&customer);
        StringDestroy(&item);
        return;
    } else if (StringIsEqualTo(&item,&rattles) && num_rattles < amount){
        printf("Sorry ");
        StringPrint(&customer);
        printf(", we only have %d Rattles\n", num_rattles);
        StringDestroy(&customer);
        StringDestroy(&item);
        return;
    }

    customer_idx = findCustomer(&customer);
    if (customer_idx == -1){
        num_customers++;
        customers[num_customers-1].name = customer;
        customer_idx = num_customers-1;
    } else {
      StringDestroy(&customer);
    }
    

    if (StringIsEqualTo(&item, &bottles)) {
        customers[customer_idx].bottles += amount;
        num_bottles -= amount;
    } else if (StringIsEqualTo(&item, &diapers)){
        customers[customer_idx].diapers += amount;
        num_diapers -= amount;
    } else if (StringIsEqualTo(&item, &rattles)){
        customers[customer_idx].rattles += amount;
        num_rattles -= amount;
    }

    
    StringDestroy(&item);

    return;
}

void processInventory() {
    String item;
    int amount;

    readString(&item);
    readNum(&amount);

    if (StringIsEqualTo(&item, &bottles)){
        num_bottles += amount;
    } else if (StringIsEqualTo(&item, &diapers)){
        num_diapers += amount;
    } else if (StringIsEqualTo(&item, &rattles)){
        num_rattles += amount;
    }

    StringDestroy(&item);
    return;
}
