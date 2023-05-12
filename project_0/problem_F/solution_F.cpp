//
// Created by Menuin on 2023-01-22.
//
#include <stdio.h>

int gcd(int x, int y){
    int gcd;
    for (int i=1;i<=y;i++){
        if (x%i==0 && y%i==0){
            gcd = i;
        }
    }
    return gcd;
}
int main(void){
    printf("GCD of 48 and 18 is: %d\n",gcd(48,18));
    printf("GCD of 144 and 60 is: %d\n",gcd(144,60));
    printf("GCD of 65 and 12 is: %d\n",gcd(65,12));
    printf("GCD of 179 and 7 is: %d\n",gcd(149,7));
}
