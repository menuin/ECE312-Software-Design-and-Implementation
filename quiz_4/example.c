//
// Created by Yuki Liu on 9/24/20.
//
#include <stdio.h>

int checkValidity(int a, int b, int c)
{
    // check condition
    if (a + b <= c || a + c <= b || b + c <= a) {
        return 1;
    }else {
        return 0;
    }
}

// Driver function
int main()
{
//    int a = 1, b = 10, c = 15;
    // statement coverage test
    printf("%d", checkValidity(1, 10, 15));
    printf("%d", checkValidity(1, 1, 1));

    // branch coverage test
    printf("%d", checkValidity(1, 10, 15));
    printf("%d", checkValidity(1, 1, 1));

    // condition coverage test
    printf("%d", checkValidity(1,1,3));
    printf("%d", checkValidity(1,1,2));
    printf("%d", checkValidity(1,2,1));
    printf("%d", checkValidity(1,3,1));
    printf("%d", checkValidity(3,1,1));
    printf("%d", checkValidity(2,1,1));

}