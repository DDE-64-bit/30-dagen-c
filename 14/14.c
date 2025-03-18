#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("graag met 2 argumenten gebruiken. \n");
        return 1;
    }

    int wachtwoord = atoi(argv[1]);

    if (wachtwoord >= 10000){
        printf("wachtwoord moet kleiner zijn dan 10.000 \n");
        return 1;
    }

    for (int i = 0; i <= wachtwoord; i++){
        printf(" * %d * \n", i);
    }

    printf("wachtwoord is: %d \n", wachtwoord);

    return 0;
}