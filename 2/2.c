#include <stdio.h>

int main(){
    int getal1, getal2;
    char operator;

    printf("Getal 1: ");
    scanf("%d", &getal1);

    printf("Getal 2: ");
    scanf("%d", &getal2);

    getchar();

    printf("Operator: ");
    scanf("%c", &operator);

    //printf("Getal 1: %d \nGetal 2: %d \nOperator: %c \n", getal1, getal2, operator);

    if (operator == '-'){
        getal1 -= getal2;
    }
    else if (operator == '+'){
        getal1 += getal2;
    }
    else if (operator == '*'){
        getal1 *= getal2;
    }
    else if (operator == '/'){
        getal1 /= getal2;
    }

    printf("%d \n", getal1);

    return 0;
}