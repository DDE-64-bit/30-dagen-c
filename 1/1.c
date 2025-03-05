#include <stdio.h>

int main(){
    char invoer[51];

    printf("Invoer: ");
    fgets(invoer, sizeof(invoer), stdin);

    printf("%s", invoer);
}