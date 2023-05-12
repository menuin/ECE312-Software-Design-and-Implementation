#include <stdio.h>

void printMultTableInt(int n);
void printMultTableFrac(int n);

int main(void){

    // You can change this to test your code
    int size = 10;

    printMultTableInt(size);
    printMultTableFrac(size);

    return 0;

}

// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            printf("%d ",i*j);
        }
        printf("\n");
    }
    // WRITE CODE FOR PART A HERE

}

// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n){
    for (int i=1;i<n+1;i++){
        for (int j=1;j<n+1;j++){
            printf("%.2f ",(1.0/i)*(1.0/j));
        }
        printf("\n");
    }
    // WRITE CODE FOR PART B HERE

}
