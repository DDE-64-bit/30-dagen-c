#include <stdio.h>

int main(){
    int x = 10;
    int *pX = &x;

    printf("x: %d \n", x);

    *pX = 20;

    printf("x: %d \n", x);

    return 0;
}
